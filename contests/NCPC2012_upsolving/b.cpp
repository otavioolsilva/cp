#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n, v1[MAXN], v2[MAXN];

int merge(int arr[], int temp[], int left, int mid, int right){
	int cont = 0, i = left, j = mid, k = left;

	while((i <= mid-1) && (j <= right)){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];

			cont += mid-i;
		}
	}

	while(i <= mid-1)
		temp[k++] = arr[i++];

	while(j <= right)
		temp[k++] = arr[j++];

	for(i = left; i <= right; i++)
		arr[i] = temp[i];

	return cont;
}

int _inversionCount(int arr[], int temp[], int left, int right){
	int cont = 0, mid;

	if(left < right){
		mid = (right+left)/2;

		cont += _inversionCount(arr, temp, left, mid);
		cont += _inversionCount(arr, temp, mid+1, right);

		cont += merge(arr, temp, left, mid+1, right);
	}

	return cont;
}

int inversionCount(int arr[]){
	int temp[n];
	return _inversionCount(arr, temp, 0, n-1);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v1[i];
	for(int i = 0; i < n; i++)
		cin >> v2[i];

	int invcont1, invcont2;

	invcont1 = inversionCount(v1);
	invcont2 = inversionCount(v2);

	if((invcont1&1) == (invcont2&1)) cout << "Possible\n";
	else cout << "Impossible\n";

	return 0;
}