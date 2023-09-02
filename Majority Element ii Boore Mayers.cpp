vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int ele1=INT_MIN,ele2=INT_MIN;

        for(auto x:nums){
            if(cnt1==0 and x!=ele2){
                cnt1++;
                ele1=x;
            }else if(cnt2==0 and x!=ele1){
                cnt2++;
                ele2=x;
            }else if(x==ele1){
                cnt1++;
            }else if(x==ele2){
                cnt2++;
            }else{
                cnt1--,cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(auto x:nums){
            if(ele1==x)
            cnt1++;
            if(ele2==x)
            cnt2++;
        }

        vector<int> ans;
        int mini = (int)(nums.size()/3) +1;
        if(cnt1>=mini)
        ans.push_back(ele1);
        if(cnt2>=mini )
        ans.push_back(ele2);
        cout<<ele1<<" "<<ele2;
        return ans;
    }
