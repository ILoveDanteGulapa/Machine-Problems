#include <iostream>
#include <string>
using namespace std;

int main()
{
    double GPA[10][3] = {
    {1.00, 95.57, 100}, {1.250, 91.12, 95.56}, 
    {1.50, 86.88, 91.11}, {1.75, 82.23, 86.67}, 
    {2.00, 77.79, 82.22}, {2.25, 73.34, 77.78}, 
    {2.50, 68.90, 73.33}, {2.75, 64.45, 68.89}, 
    {3.00, 60.00, 64.44}, {5.00, 0.00, 59.99}
    };
    
    int numS;
    cout << "Enter number of students: ";
    cin >> numS;
    
    string studennt[numS];
    double grades[numS][4];
    
    string sorted_studentName[numS];
    double sorted_gpa[numS];
    
    string studentWithGrades[numS][2];
    double ex[4];
    double s[4];
    double m[2];
    double e[4];
    
    string fname, lname = "";
    
    for(int i = 0; i < numS; i++){
        cout << "Enter first name: ";
        getline(cin >> ws, fname);
        
        cout << "Enter last name: ";
        getline(cin >> ws, lname);
        
        studennt[i] = fname + " " + lname;
        
        sorted_studentName[i] = studennt[i];
        
        for(int j = 0; j < 4; j++){
			 cout << "Enter Experiment "  << j + 1 << ": ";
             cin >> ex[j];
        }
           for(int j = 0; j < 4; j++){
			 cout << "Enter Skills Test "  << j + 1 << ": ";
             cin >> s[j];
        }    
            for(int j = 0; j < 2; j++){
			 cout << "Enter Machine Problem "  << j + 1 << ": ";
             cin >> m[j];
        }
        
        for(int z = 0; z < 2; z++){
            if(z == 0){
                cout << "Prelims \n";
            }
            
            else{
               cout << "Finals \n"; 
            }
            
            for(int y = 0; y < 2; y++){
                double we = 0.0, pe = 0.0;
               if(y == 0){
                    cout << "Enter Written Exam: ";
                    cin >> we;
                    if(we > 30){
                    //   cout << "Written exam has 30 items only!";
                       e[y] = 30;
                    }
                    else{
                        e[y] = we;
                    }
                    // cin >> e[y];
               }
               else{
                 cout << "Enter Practical Exam: ";
                 cin >> pe;
                 if(pe > 70){
                    //   cout << "Practical exam has 70 items only!";
                       e[y] = 70;
                    }
                    else{
                        e[y] = pe;
                    }
                //  cin >> e[y];
               }
            
        }
        }

          for(int x = 0; x < 4; x++){
			 if(x == 0){
			     for(int ix = 0; ix < 4; ix++)
			        grades[i][x] += (ex[ix] / 100.0) * 5; // total 20%
			 }
			 else if(x == 1){
			      for(int sx = 0; sx < 4; sx++)
			        grades[i][x] += (s[sx] / 100.0) * 5; // total 20%
		     }
		     else if(x == 2){
			     for(int xx = 0; xx < 2; xx++)
			        grades[i][x] += (m[xx] / 100) * 10; // total 20%
		     }
		      else{
			      grades[i][x] = (((e[0] + e[1])) + ((e[2] + e[3])) / 200) * 0.40; // total 40%
		     }
        }
           
    }
    
    // display each students scores with names 
    
    double total = 0, experiment = 0, skillTest = 0, machineProblem = 0, exam = 0;
    cout << endl << " --- Student's grade results --- " << endl;
    for(int x =0; x < numS; x++){
        cout << endl << "Student name: " << studennt[x] << endl;
        
        for(int z = 0; z < 4; z++){
            if(z == 0){
                experiment = (grades[x][z]); // (grades[x][z] / 400.0) * 20.0;
            }
            if(z == 1){
               skillTest = (grades[x][z]); //(grades[x][z] / 400.0) * 20.0;
            }
            if(z == 2){
                machineProblem = (grades[x][z]); //(grades[x][z] / 200.0) * 10.0;
            }
            else
              exam = (grades[x][z]);
        } 
        // For logging my inputs
        // cout << "experiment: " << experiment << endl;
        // cout << "skillTest: " << skillTest << endl;
        // cout << "machineProblem: " << machineProblem << endl;
        // cout << "exam: " << exam << endl;
            
        total = experiment + skillTest + machineProblem + exam;
        
        cout << "Raw Grade: " << total << endl;
        
        double gpa;
        for(int Z = 0; Z < 10; Z++){
            if(total >= GPA[Z][1] && total <= GPA[Z][2]){
                gpa = GPA[Z][0];
                sorted_gpa[x] = gpa;
                cout << "GPA: " << gpa << endl; 
                
                 if(!(gpa < 1) &&  gpa <= 3.00 ){
                    cout << "Passed" << endl;
                 }  
                 else if(gpa > 3){
                    cout << "Failed" << endl;
                 }
                 else{
                    cout << "Failed" << endl; 
                 }
                
                 break;
            }
        }
    }
    
    cout << "Top Students:" << endl;
    
    // top students
    double temp;
    string sTemp;
    for(int i=0; i<numS; i++)
    {
        for(int j=i+1; j<numS; j++)
        {
            if(sorted_gpa[j] < sorted_gpa[i])
            {
                temp = sorted_gpa[i];
               sTemp = sorted_studentName[i];
                
                sorted_gpa[i] = sorted_gpa[j];
                sorted_studentName[i] = sorted_studentName[j];
                
                sorted_gpa[j] = temp;
                sorted_studentName[j] = sTemp;
            }
        }
    }
    
    for(int i=0; i<numS; i++){
        cout << (i+1) << ". " << sorted_studentName[i] << " - " << sorted_gpa[i] << endl;
        if(i == 9){
            break;
        }
    }
    
        
    return 0;
}
