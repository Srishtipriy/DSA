class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();
        visited = vector<bool>(n, false);

        // open rooms from 0th room
        dfs(rooms, 0);

        // check all rooms 
        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }

        return true;
    }
    vector<bool> visited;

    void dfs(vector<vector<int>>& rooms, int idx){    
        // mark visit
        visited[idx] = true;

        /* for every key in this room */
        for(int i = 0; i < rooms[idx].size(); i++){
            if(!visited[rooms[idx][i]]) // if the next room is not open yet
                dfs(rooms, rooms[idx][i]); // go to the next room
        }

    }

};