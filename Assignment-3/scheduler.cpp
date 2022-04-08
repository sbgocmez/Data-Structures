#include <iostream>
#include <string>

#include <fstream>
#include <algorithm>

#include "data_structs.h"

/*  @Author
    Student Name: Sakine Büşra Göçmez
    Student ID: 150190064
    Date: 1.8.2020
*/

int which_is_next(Queue a, Queue b, Queue c, int current_time, bool sc_active)
{
    // eger priority 1 in ilk subtaski bekleme listesindeyse
    if (!a.isEmpty() && a.siradaki_elemanin_gelisi <= current_time) {
        
        return 0;
    }
    // eger beklemede priority 1 yoksa
    else
    {
        // hem priority 2 hem priority 3 bekleme listesindeyse
        if (!b.isEmpty() && !c.isEmpty() && b.siradaki_elemanin_gelisi <= current_time && c.siradaki_elemanin_gelisi <= current_time) {
            return (sc_active == true) ? 2 : 1;
        }
        // yalniz priority 2 bekleme listesindeyse
        else if (!b.isEmpty() && b.siradaki_elemanin_gelisi <= current_time) {
            return 1;
        }
        // yalniz priority 3 bekleme listesindeyse
        else if (!c.isEmpty() && c.siradaki_elemanin_gelisi <= current_time) {
            return 2;
        }
    }
    return -1;
}

int beklemede_degil_ama_ilk_bu_gelecek(Queue a, Queue b, Queue c)
{
    int return_val;
    if (!a.isEmpty() && !b.isEmpty() && !c.isEmpty()) // her ucu de listede
        return_val = min(min(a.siradaki_elemanin_gelisi, b.siradaki_elemanin_gelisi), c.siradaki_elemanin_gelisi);
    else if (a.isEmpty() && !b.isEmpty() && !c.isEmpty()) // b ve c listede
        return_val = min(b.siradaki_elemanin_gelisi, c.siradaki_elemanin_gelisi);
    else if (!a.isEmpty() && !b.isEmpty() && c.isEmpty()) //a ve b listede
        return_val = min(a.siradaki_elemanin_gelisi, b.siradaki_elemanin_gelisi);
    else if (!a.isEmpty() && b.isEmpty() && !c.isEmpty()) // a ve c listede
        return_val = min(a.siradaki_elemanin_gelisi, c.siradaki_elemanin_gelisi);
    else if (a.isEmpty() && b.isEmpty() && !c.isEmpty()) // yalniz c listede
        return_val = c.siradaki_elemanin_gelisi;
    else if (a.isEmpty() && !b.isEmpty() && c.isEmpty()) // yalniz b listede
        return_val = b.siradaki_elemanin_gelisi;
    else if (!a.isEmpty() && b.isEmpty() && c.isEmpty()) // yalniz c listede
        return_val = a.siradaki_elemanin_gelisi;

    if (return_val == a.siradaki_elemanin_gelisi)
        return 0;
    else if (return_val == b.siradaki_elemanin_gelisi)
        return 1;
    else if (return_val == c.siradaki_elemanin_gelisi)
        return 2;
    return -1;
}

void update_sc_active(Queue p3, int current_time, specialCondition* sc)
{
    // bekleme listesinde pri 3 yoksa ve aktifse
    if (p3.isEmpty() || p3.siradaki_elemanin_gelisi > current_time)
    {
        //cout << "beklemede 3 yok " << endl;
        // sc aktifse
        if (sc->is_active)
        {
            //if (sc->num_of_two == 2) // 1 se dokunmuyoruz
                sc->num_of_two = 0;

            sc->is_active = false;
        }
        return;
    }
    // listede pri 3 varsa
    //
    if (sc->num_of_two % 2 == 0 && !sc->is_active && sc->num_of_two != 0)
    {
        //cout << "hell " << endl;
        sc->num_of_two = 0;
        sc->is_active = true;
        //cout << "true yaptim " << endl;
    }
}

int main(int argc, char* argv[])
{
    ifstream file;
    file.open(argv[1]);
    string line;

    MultiQueue os;
    os.init();

    while (file.is_open() && !file.eof())
    {
        while (getline(file, line))
        {
            int i = 0;
            Process* p = new Process;
            Subtask* s = new Subtask;
            while (line.size() != 0 && !file.eof())
            {
                if (i == 0)
                {
                    p->name = line.substr(0, line.find(' '));
                    p->priority = stoi(line.substr(line.find(' ') + 1, line.find('\n')));
                    p->task_stack.init();
                }
                else if (i == 1)
                {
                    p->arrival_time = stoi(line.substr(0, line.find(' ')));
                    p->task_count = stoi(line.substr(line.find(' ') + 1, line.find('\n')));
                }
                else
                {
                    s->name = line.substr(0, line.find(' '));
                    s->duration = stoi(line.substr(line.find(' ') + 1, '\n'));
                    p->task_stack.push(s);
                }
             
                getline(file, line);
                i++;

            }
            if (file.eof()) {
                s->name = line.substr(0, line.find(' '));
                s->duration = stoi(line.substr(line.find(' ') + 1));
                p->task_stack.push(s);
            }
            os.queue(p);
         
        }
        file.close();
    }

    for (int i = 0; i < 3; i++)
        os.queues[i].isEmpty() ? os.queues[i].siradaki_elemanin_gelisi = -1 : os.queues[i].siradaki_elemanin_gelisi = os.queues[i].head->arrival_time;

    int time = 0, lateness = 0, islemdeki_index = 0;
    // bool sc_active = false;
    Process* p;
    Subtask* s;
    int beklenen_sure_bitimler_toplami = 0;
    specialCondition* sc = new specialCondition;
    sc->is_active = false;
    sc->num_of_two = 0;

    for (int i = 0; i < 3; i++)
        beklenen_sure_bitimler_toplami += os.queues[i].processlerin_beklenen_bitme_sureleri_toplami();

    while (!os.isEmpty())
    {
        update_sc_active(os.queues[2], time, sc);
        islemdeki_index = which_is_next(os.queues[0], os.queues[1], os.queues[2], time, sc->is_active);
        if (islemdeki_index < 0) // bekleme listesinde kimse yoksa
        {
            islemdeki_index = beklemede_degil_ama_ilk_bu_gelecek(os.queues[0], os.queues[1], os.queues[2]);
            time = os.queues[islemdeki_index].siradaki_elemanin_gelisi;
        }
        p = os.queues[islemdeki_index].head;
        if (islemdeki_index == 0) // priority 1 se
        {
            while (p->task_count > 0) // priority 1 se o processin tamamini yapacagiz
            {
                s = p->task_stack.pop();
                cout << p->name << " " << s->name << endl;
                time += s->duration;
                p->clock = time;
                if (p->task_count == 1)
                {
                    lateness += p->clock;
                    
                }
                p->task_count--;
            }
            // ilk processle isimiz bitti, dequeue yaparak hem processi sildik, hem de stack close yaptik.
            os.queues[islemdeki_index].dequeue()->task_stack.close();
            if (!os.queues[islemdeki_index].isEmpty())
                os.queues[islemdeki_index].siradaki_elemanin_gelisi = os.queues[islemdeki_index].head->arrival_time;
        }
        // priority 2 veya 3 e geldiysem
        else
        {
            if (p->task_count == 0)
                os.queues[islemdeki_index].dequeue()->task_stack.close();
            else if (p->task_count > 0)
            {
                s = p->task_stack.pop();
                cout << p->name << " " << s->name << endl;
                time += s->duration;
                p->clock = time;
                if (p->task_count == 1)
                {
                    lateness += p->clock;
                    
                }
                p->task_count--;
                if (islemdeki_index == 1) {
                    sc->num_of_two++;
               
                }
                else {
                    sc->num_of_two = 0;
                    sc->is_active = false;
                }
                    //sc->num_of_two++;
             
            }
            if (!os.queues[islemdeki_index].isEmpty())
                os.queues[islemdeki_index].siradaki_elemanin_gelisi = os.queues[islemdeki_index].head->arrival_time;
        }
        // bu priorityli queue bos degilse siradakinin time ını guncelliyoruz.
        
     
    }
    
    cout << "Cumulative Lateness: " << lateness - beklenen_sure_bitimler_toplami << endl;
    os.close();
    return EXIT_SUCCESS;
}