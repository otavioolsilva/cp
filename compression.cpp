// Coordinate compression - O(n*log(n))

void compression(int n, int arr[]){
  vector<int> aux(arr, arr+n); 
  sort(aux.begin(), aux.end());
  aux = vector<int>(aux.begin(), unique(aux.begin(), aux.end()));

  for(int i = 0; i < n; i++)
    arr[i] = lower_bound(aux.begin(), aux.end(), arr[i]) - aux.begin() + 1;
}

