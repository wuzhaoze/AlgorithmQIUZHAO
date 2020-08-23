学习笔记
void bubbleSort(int *arr, int n)
{
    if(n <= 0 || arr == NULL){
        return ;
    }
    bool isSwap = false;
    int i, j;
    for(i = 0; i < n ; i ++) {
        for(j = 0; j < n -i -1; j++) {
            isSwap = false;
            if(arr[j] > arr[j+1]) {
                int tmp;
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
                isSwap = true;
            }
        }
        if(isSwap == false){
            printf("break.....\r\n");
            break;
        }
        dump(arr, n);
    } 
}

void insertSort(int* a, int n)
{
    if(n <= 0 || a == NULL){
        return ;
    }
    int i,j;
    for(i = 1; i<n; i++) {
        int val = a[i];
        for(j = i; j > 0; j--) {
            if(val < a[j-1]) {
                a[j] = a[j -1];
            } else {
                break;
            }
        }
        a[j] = val;
    }    
}

void selectionSort(int *a, int n)
{
    if(n <= 0 || a == NULL){
        return ;
    }
    int i,j;
    for(i = 0; i<n; i++) {
        int min = i;
        int tmp;
        for(j = i +1; j < n; j++){
            if(a[j] <a[min]) {
                min = j;
            }
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}


void merge(int32_t* arr, int32_t p, int32_t q, int32_t r)
{
    int32_t i, j,k;
    int32_t *tmp = malloc((r-p+1)*sizeof(int32_t));
    if(tmp == NULL){
        return;
    }
    memset(tmp, 0 ,(r-p+1)*sizeof(int32_t));
    for(i = p, j = q+1, k= 0; i<=q && j <= r;k++){
        if(arr[i] > arr[j]){
            tmp[k] = arr[j];
            j++;
        } else{
            tmp[k] = arr[i];
            i++;
        }
    }
    int32_t start = i;
    int32_t end = q;
    if(i == q+1){
        for(; j<=r;j++,k++){
            tmp[k] = arr[j];
        }
    } else{
        for(; i<=q;i++,k++){
            tmp[k] = arr[i];
        }
    }

    for(i = p, k= 0; i <= r; i++, k++){
        arr[i] = tmp[k];
    }
    free(tmp);
    tmp = NULL;

}
void _merge_sort(int32_t *arr, int32_t p, int32_t r)
{
    if(p >= r){
        return;
    }

    int32_t q;
    q = (p+r)/2;
    _merge_sort(arr, p, q);
    _merge_sort(arr, q+1, r);
    merge(arr,p,q,r);
}
// merger_sort(p, r) = merge(merge_sort(p, q), merge_sort(q+1, r))
void merge_sort(int32_t *arr, int32_t n)
{
    if(arr == NULL || n <0){
        return;
    }
    _merge_sort(arr, 0, n-1);
}

int32_t partition(int32_t *arr, int32_t p, int32_t r)
{
    int32_t i, j;
    int32_t tmp;
    for(i = p, j = p; j <r ; j++){
        if(arr[j]<arr[r]){
            if(i != j){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            
            i++;
        }

    }
    tmp = arr[i];
    arr[i] = arr[r];
    arr[r] = tmp;
    return i;

}
void _quick_sort(int32_t *arr, int32_t p, int32_t r)
{
    if(p>=r){
        return;
    }
    int32_t q = partition(arr, p, r);

    _quick_sort(arr, p, q-1);
    _quick_sort(arr, q+1, r);
}
// qsort(p, r) = qsort(p, q) + qsort(q+1, r)
void quick_sort(int32_t *arr, int32_t n)
{
    if(arr == NULL || n <=0){
        return;
    }
    _quick_sort(arr, 0, n -1);
}