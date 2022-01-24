
void reverseArray(int arr[], int q)
{
    int p[q];
 
    for (int i = 0; i < q; i++) {
        p[q - 1 - i] = arr[i];
    }
 
    for (int i = 0; i < q; i++) {
        arr[i] = p[i];
    }
}

void print(int arr[], int q)
{
    for (int i = 0; i < q; i++) {
        printf("%d ", arr[i]);
    }
}

 
int main(void)
{
    int arr[] = { 10, 11, 12, 13, 14 };
    int q = sizeof(arr)/sizeof(arr[0]);
 
    reverseArray(arr, q);
    print(arr, q);
 
    return 0;
}
