class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int>studentsChoice;
        for(int i=0;i<n;i++){
            studentsChoice.push(students[i]);
        }
        int rotation = 0;
        int i=0;
        while(!studentsChoice.empty() && rotation<studentsChoice.size()){
            if(studentsChoice.front() == sandwiches[i]){
                rotation = 0;
                i++;
                studentsChoice.pop();
            }
            else{
                rotation++;
                studentsChoice.push(studentsChoice.front());
                studentsChoice.pop();
            }
        }
        return studentsChoice.size();
    }
};