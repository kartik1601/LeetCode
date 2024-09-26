class MyCalendar {
    vector<pair<int,int>> bookings;
public:
    MyCalendar(){}
    
    bool book(int start, int end) {
        if(bookings.empty()){
            bookings.push_back(make_pair(start,end));
            return true;
        }

        for(auto& [x,y] : bookings){
            if(x<end && y>start){return false;}
        }

        bookings.push_back(make_pair(start,end));
        sort(bookings.begin(),bookings.end(),[&](auto&p1 , auto&p2){
            return p1.second <= p2.first;
        });

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */