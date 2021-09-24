// If the color of parent and child are same then return false else return true
// vis is bool vertor
// col is int vector
// a,vis,col are defined globally

void dfs(ll pos,ll ok){
	vis[pos]=1;
	col[pos]=ok;

	for(auto i:a[pos]){
		if(!vis[i]){
			if(dfs(i,1-ok))
				return true;
			else return false;
		}
		else if(col[pos]==col[i])
			return false;
	}

	return true;
}
