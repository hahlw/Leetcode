/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        total_cp=capacity;
    }
    int get(int key) {
        auto find_iter=m_map.find(key);
        if(find_iter==m_map.end())return -1;
        m_list.splice(m_list.begin(),m_list,find_iter->second);
        return find_iter->second->second;
    }
    void put(int key, int value) {
        auto find_iter=m_map.find(key);
        if(find_iter!=m_map.end()){
            m_list.splice(m_list.begin(),m_list,find_iter->second);
            find_iter->second->second=value;
            return ;
        }
        if(m_map.size()==total_cp){
            int key_to_del=m_list.back().first;
            m_list.pop_back();
            m_map.erase(key_to_del);
        }
        m_list.emplace_front(key,value);
        m_map[key]=m_list.begin();
    }
private:
    int total_cp;
    unordered_map<int,list<pair<int,int>>::iterator>m_map;
    list<pair<int,int>>m_list;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

