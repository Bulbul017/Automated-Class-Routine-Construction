
/*

 * University Course Routine Generator using backtracking

 * Created by : Md Aminul Kader Bulbul

*/

#include<bits/stdc++.h>

using namespace std;

map<double,double> mtime;

stack<string> lab_courses;

stack<string> theory_courses;


int generate_class_routine(double start_time,double finish_time)
{

    if(theory_courses.empty() && lab_courses.empty()){

        printf("%.2lf - %.2lf : Free Slot\n",mtime[(start_time)],mtime[(finish_time)]);

        return 1; // Course allotment completed

    }

    while(!theory_courses.empty()){

       if(start_time+1.50<=finish_time){

          string allocated_course = theory_courses.top();

          theory_courses.pop();

          printf("%.2lf - %.2lf : ",mtime[(start_time)],mtime[(start_time+1.50)]);

          cout<<allocated_course<<endl;

          int status = generate_class_routine(start_time+1.50,finish_time);

          if(status == 2){

            if(finish_time-start_time>=3.0)break; // Labs can be allocated

            else{

                theory_courses.push(allocated_course);

                return 2;

            }
          }

       }

       else return 2; // Inconsistent state

    }

    while(!lab_courses.empty()){

       if(start_time+3.0<=finish_time){

          string allocated_course = lab_courses.top();

          lab_courses.pop();

          printf("%.2lf - %.2lf : ",mtime[(start_time)],mtime[(start_time+3.0)]);

          cout<<allocated_course<<endl;

          int status = generate_class_routine(start_time+3.0,finish_time);

          if(status == 2)break;

       }

       else return 2; // Inconsistent state

    }

}



int main()
{

    mtime[8.50]=8.30;

    mtime[9.0]=9.0;

    mtime[9.50]=10.30;

    mtime[10.0]=10.0;

    mtime[10.50]=11.30;

    mtime[11.50]=11.30;

    mtime[12.0]=1.0;

    mtime[12.1]=12.0;

    mtime[13.0]=1.0;

    mtime[2.0]=2.0;

    mtime[2.50]=3.30;

    mtime[3.50]=3.30;

    mtime[4.0]=5.0;

    mtime[5.0]=5.0;

    ifstream ip("Sheet-1.csv");

    if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string teacher_initial;

    string full_name;

    string designation;

    string department;

    string university;

    map<string,vector<string> > minit;

    map<string,vector<string> >::iterator it_teacher_indiv;

    vector<string>::iterator itinit;

    vector<string> sirs_v;

    vector<string>::iterator tid;

    int ii=0;

    while(!ip.eof()){

        getline(ip,teacher_initial,',');
        getline(ip,full_name,',');
        getline(ip,designation,',');
        getline(ip,department,',');
        getline(ip,university,'\n');

       if(ii!=0){

            sirs_v.push_back(teacher_initial);
            minit[teacher_initial].push_back(full_name);
            minit[teacher_initial].push_back(designation);
            minit[teacher_initial].push_back(department);
            minit[teacher_initial].push_back(university);


        }

        ++ii;


    }

    ip.close();

    ifstream ip2("Sheet-2.csv");

    if(!ip2.is_open()) std::cout << "ERROR: File Open" << '\n';

    string teacher_initial2;
    string course1;
    string course2;
    string course3;
    string course4;
    string course5;
    string course6;
    string course7;
    string course8;

    map<string,vector<string> > m;

    vector<string>::iterator it;

    int i=0;

    while(!ip2.eof()){

        getline(ip2,teacher_initial2,',');
        getline(ip2,course1,',');
        getline(ip2,course2,',');
        getline(ip2,course3,',');
        getline(ip2,course4,',');
        getline(ip2,course5,',');
        getline(ip2,course6,',');
        getline(ip2,course7,',');
        getline(ip2,course8,'\n');

        if(i!=0){

            m[teacher_initial2].push_back(course1);
            m[teacher_initial2].push_back(course2);
            m[teacher_initial2].push_back(course3);
            m[teacher_initial2].push_back(course4);
            m[teacher_initial2].push_back(course5);
            m[teacher_initial2].push_back(course6);
            m[teacher_initial2].push_back(course7);
            m[teacher_initial2].push_back(course8);



        }

        ++i;

    }

    ip2.close();


    ifstream ip3("Sheet-3.csv");

    if(!ip3.is_open()) std::cout << "ERROR: File Open" << '\n';

    string teacher_initial3;
    string sat;
    string sun;
    string mon;
    string tue;
    string wed;
    string thu;
    string fri;


    map<string,vector<string> > m2;

    vector<string>::iterator it2;

    int i2=0;

    while(!ip3.eof()){

        getline(ip3,teacher_initial3,',');
        getline(ip3,sat,',');
        getline(ip3,sun,',');
        getline(ip3,mon,',');
        getline(ip3,tue,',');
        getline(ip3,wed,',');
        getline(ip3,thu,',');
        getline(ip3,fri,'\n');

        if(i2!=0){

            m2[teacher_initial3].push_back(sat);
            m2[teacher_initial3].push_back(sun);
            m2[teacher_initial3].push_back(mon);
            m2[teacher_initial3].push_back(tue);
            m2[teacher_initial3].push_back(wed);
            m2[teacher_initial3].push_back(thu);
            m2[teacher_initial3].push_back(fri);


        }

        ++i2;

    }

    ip3.close();


    for(tid=sirs_v.begin();tid!=sirs_v.end();++tid){


        string teacher_init = (*tid);

        string allocated_course,allocated_course_2,allocated_course_3;

        double start_time,finish_time,start_time_2,finish_time_2;

        int day;

        map<int,string> wd;

        wd[0]="Possible Slot Arrangement : Saturday";

        wd[1]="Possible Slot Arrangement : Sunday";

        wd[2]="Possible Slot Arrangement : Monday";

        wd[3]="Possible Slot Arrangement : Tuesday";

        wd[4]="Possible Slot Arrangement : Wednesday";

        wd[5]="Possible Slot Arrangement : Thursday";

        wd[6]="Possible Slot Arrangement : Friday";

        cout<<"    Teacher's Information"<<endl;

        cout<<"-------------------------------"<<endl;

        cout<<teacher_init<<endl;

        for(itinit=minit[teacher_init].begin();itinit!=minit[teacher_init].end();++itinit){

                cout<<(*itinit)<<endl;

        }


        vector<string> courses;

        vector<string>::iterator itc;


        for(it=m[teacher_init].begin();it!=m[teacher_init].end();++it){

            string teachers_indiv_course = (*it);

            courses.push_back(teachers_indiv_course);

        }

        cout<<"***********************************"<<endl<<endl;

        day=7;

        for(it2=m2[teacher_init].begin();it2!=m2[teacher_init].end();++it2){

           string teachers_pref_time_per_day = (*it2);

           cout<<endl<<endl;

           string tmp = wd[(day%7)];

           cout<<tmp<<endl;

           cout<<"_____________________________________"<<endl<<endl;

           random_shuffle(courses.begin(),courses.end());

            for(itc=courses.begin();itc!=courses.end();++itc){

                string lec = (*itc);

                if(lec.size()==8)theory_courses.push(lec);

                else if(lec.size()==18)lab_courses.push(lec);

            }

           if(teachers_pref_time_per_day.size()==0){

                cout<<"Holiday or the teacher has no preferred time on this day"<<endl;

           }

           else if(teachers_pref_time_per_day.size()>10 && teachers_pref_time_per_day.size()<20){


             // Morning Session

             if(teachers_pref_time_per_day[0]=='8' && teachers_pref_time_per_day[2]=='3')start_time=8.50;

             if(teachers_pref_time_per_day[7]=='1' && teachers_pref_time_per_day[8]==':')finish_time=13.0;

             int res = generate_class_routine(start_time,finish_time);


             // Afternoon Session

             if(teachers_pref_time_per_day[0]=='2' && teachers_pref_time_per_day[2]=='0')start_time_2=2.00;

             if(teachers_pref_time_per_day[7]=='5' && teachers_pref_time_per_day[8]==':')finish_time_2=5.00;

             int tmp = generate_class_routine(start_time,finish_time);


           }

           else if(teachers_pref_time_per_day.size()>25){

              // Start_time -> Morning Session

              if(teachers_pref_time_per_day[0]=='8' && teachers_pref_time_per_day[2]=='3')start_time=8.50;

              else if(teachers_pref_time_per_day[0]=='9')start_time=9.0;

              else if(teachers_pref_time_per_day[0]=='1' && teachers_pref_time_per_day[1]=='0' && teachers_pref_time_per_day[3]=='0')start_time=10.0;

              else if(teachers_pref_time_per_day[0]=='1' && teachers_pref_time_per_day[1]=='0' && teachers_pref_time_per_day[3]!='0')start_time=10.50;

              else if(teachers_pref_time_per_day[0]=='1' && teachers_pref_time_per_day[1]=='1' && teachers_pref_time_per_day[3]=='0')start_time=11.0;

              else if(teachers_pref_time_per_day[0]=='1' && teachers_pref_time_per_day[1]=='1' && teachers_pref_time_per_day[3]!='0')start_time=11.50;

              else if(teachers_pref_time_per_day[0]=='1' && teachers_pref_time_per_day[1]=='2')start_time=12.1;



              // Finish_time -> Morning Session

              if(teachers_pref_time_per_day[7]=='1' && teachers_pref_time_per_day[8]=='0' && teachers_pref_time_per_day[10]=='0')finish_time=10.0;

              else if(teachers_pref_time_per_day[7]=='1' && teachers_pref_time_per_day[8]=='0' && teachers_pref_time_per_day[10]!='0')finish_time=10.50;

              else if(teachers_pref_time_per_day[7]=='1' && teachers_pref_time_per_day[8]=='1' && teachers_pref_time_per_day[10]=='0')finish_time=11.0;

              else if(teachers_pref_time_per_day[7]=='1' && teachers_pref_time_per_day[8]=='1' && teachers_pref_time_per_day[10]!='0')finish_time=11.50;

              else if(teachers_pref_time_per_day[7]=='1' && teachers_pref_time_per_day[8]=='2')finish_time=12.1;

              else if(teachers_pref_time_per_day[7]=='1' && teachers_pref_time_per_day[8]==':')finish_time=13.0;

              int res = generate_class_routine(start_time,finish_time);



              // Start_time_2  -> Afternoon Session

              if(teachers_pref_time_per_day[14]=='2' || teachers_pref_time_per_day[15]=='2')start_time_2 = 2.0;

              if(teachers_pref_time_per_day[14]=='3' || teachers_pref_time_per_day[15]=='3')start_time_2 = 3.50;

              // Finish_time_2  -> Afternoon Session

              if(teachers_pref_time_per_day[21]=='3' || teachers_pref_time_per_day[22]=='3')finish_time_2 = 3.50;

              if(teachers_pref_time_per_day[21]=='5' || teachers_pref_time_per_day[22]=='5')finish_time_2 = 5.00;

              int tmp = generate_class_routine(start_time_2,finish_time_2);

           }

           ++day;

        }


        cout<<endl<<endl<<endl;


    }


    return 0;

}
