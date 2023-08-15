#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    if(n > m) return kthElement(arr2,arr1,m,n,k);
    int N = n+m;
    int left = k-1;
    int low = max(0,k-n),high = min(n,k-1);
    while(low <= high){
        int mid1 = (low+high) / 2;
        int mid2 = left -mid1;
        int l1 = INT_MIN,l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n)    r1 = arr1[mid1];
        if(mid2 < m)    r2 = arr2[mid2];
        if(mid1-1 >= 0) l1 = arr1[mid1-1];
        if(mid2-1 >= 0) l2 = arr2[mid2-1];
        if(l1 <= r2 && l2 <= r1){
            return min(r1,r2);
        }
        else if(l1 > r2)    high = mid1-1;
        else    low = mid1+1;
    }
    return -1;
}
int main(){
    int n = 680;
//47 ,92 150 176 214 234 243 281 312 321 338 342 361 395 400 401 410 433 449 472 480 489 519 541 556 565 588 707 718 725 736 753 756 770 800 812 855 858 874 901 908 933 937 ,982 1068 1139 1151 1159 1175 1195 1218 1238 1314 1404 1450 1454 1506 1547 1563 1646 1678 1691 1709 1721 1760 1775 1780 1797 1834 1847 1852 1856 1935 1945 1969 2015 2015 ,2032 2032 2039 2071 2074 2090 2100 2103 2156 2187 2192 2266 2274 2275 2280 2285 2288 2312 2342 2352 2361 2372 2422 2424 2427 2434 2456 2470 2477 2481 2559 2607 2609 ,2617 2627 2630 2635 2642 2659 2704 2721 2752 2756 2795 2834 2838 2871 2877 2906 2928 2963 2972 3108 3113 3119 3134 3153 3157 3188 3284 3315 3317 3329 3331 3347 3353 ,3396 3444 3466 3503 3517 3549 3558 3587 3648 3664 3686 3702 3731 3754 3764 3794 3811 3817 3818 3857 3868 3870 3871 3904 3969 4038 4046 4052 4072 4081 4141 4190 4207, 4218 4257 4308 4311 4313 4334 4360 4366 4376 4389 4445 4450 4458 4504 4513 4550 4568 4576 4609 4619 4631 4651 4682 4699 4720 4748 4754 4772 4775 4808 4840 4899 4909 ,4911 4940 4976 5011 5028 5032 5111 5130 5132 5160 5182 5233 5257 5262 5313 5340 5355 5360 5395 5426 5427 5454 5501 5577 5588 5646 5663 5672 5721 5771 5798 5805 5834, 5839, 5892 5928 5949 5990 6018 6034 6074 6119 6180 6189 6198 6257 6299 6313 6321 6329 6419 6423 6516 6549 6598 6634 6657 6664 6676 6682 6688 6696 6746 6768 6789 6808, 6909, 6921 6947 6987 7034 7040 7040 7057 7066 7067 7068 7069 7086 7115 7134 7138 7168 7173 7205 7232 7248 7263 7264 7275 7297 7353 7368 7391 7400 7419 7459 7485 7498,7516, 7540 7560 7565 7586 7653 7664 7689 7738 7741 7780 7785 7790 7794 7803 7828 7835 7835 7879 7899 7904 7914 7928 7933 7934 7983 7989 8016 8044 8083 8105 8113 8118, 8142, 8157 8219 8264 8325 8339 8341 8348 8371 8416 8436 8468 8470 8486 8507 8513 8523 8532 8541 8558 8576 8614 8621 8631 8645 8655 8662 8691 8719 8797 8857 8859 8869, 8885, 8948 8990 8992 9004 9024 9076 9101 9112 9130 9155 9197 9204 9266 9291 9311 9362 9375 9400 9432 9508 9512 9527 9579 9579 9676 9689 9706 9712 9736 9740 9742 9754, 9760, 9840 9912 9944 9980 10022 10112 10178 10216 10216 10259 10306 10328 10351 10361 10371 10441 10498 10535 10547 10668 10695 10760 10768 10782 10856 10888 10966 10996, 11028, 11069 11093 11103 11120 11121 11151 11159 11172 11185 11275 11282 11283 11297 11333 11356 11365 11368 11386 11389 11412 11420 11432 11448 11456 11480 11490 11533, 11557, 11558 11614 11615 11701 11715 11753 11765 11783 11798 11821 11837 11841 11848 11855 11929 11932 11974 11985 12017 12020 12022 12044 12066 12139 12139 12153 12157, 12162, 12164 12168 12173 12181 12190 12206 12213 12232 12263 12266 12272 12310 12325 12374 12430 12477 12513 12523 12534 12536 12536 12537 12597 12600 12634 12661 12686, 12687, 12707 12709 12737 12766 12774 12784 12944 13063 13086 13107 13198 13243 13254 13295 13317 13332 13385 13406 13451 13466 13512 13549 13596 13606 13631 13646 13693, 13736, 13846 13928 14028 14048 14058 14069 14254 14332 14364 14421 14427 14478 14517 14561 14603 14727 14758 14799 14832 14848 14873 14943 14954 14987 15021 15049 15128, 15181, 15229 15285 15307 15348 15440 15479 15560 15590 15659 15675 15799 15915 15951 15962 15984 16057 16062 16096 16096 16116 16136 16181 16288 16296 16296 16347 16369, 16376, 16392 16469 16552 16572 16623 16710 16758 16792 16848 17067 17097 17152 17156 17170 17178 17228 17343 17363 17478 17486 17505 17513 17526 17588 17814 17852 17894, 17978, 18017 18031 18043 18132 18133 18150 18159 18164 18166 18396 18484 18575 18633 18704 18734 18801 18823 18876 18900 19027 19037 19093 19099 19127 19167 19245 19267, 19390, 19402 19423 19436 19438 19447 19487 19523 19531 19584 19687 19705 19717 19752 19823 19826 19832 19872 19914 19980 
//263
//19 96 113 125 200 212 291 352 365 506 552 595 759 774 806 817 970 1090 1153 1213 1396 1431 1488 1533 1667 1670 1743 1975 2064 2113 2139 2169 2170 2486 2486 2557 2557 2580 2590 2616 2626 2724 2746 2748 2775 2775 2783 2850 2893 2915 3413 3482 3499 3531 3688 3811 3909 3915 3950 4025 4029 4032 4056 4161 4243 4245 4301 4339 4365 4414 4489 4497 4557 4628 4630 4682 4709 4747 4768 4833 4837 4851 4857 4869 4999 5020 5043 5130 5183 5216 5256 5267 5277 5388 5430 5465 5526 5565 5628 5634 5634 5774 5805 5900 5909 6018 6082 6093 6261 6511 6678 6699 6741 6834 6838 6905 7265 7345 7482 7525 7558 7672 7731 7786 7821 7913 7985 8012 8136 8146 8184 8320 8415 8418 8493 8516 8563 8603 8703 8813 8814 8861 8866 8870 8885 9011 9102 9139 9254 9305 9345 9466 9610 9660 9768 9825 9926 9958 10063 10098 10151 10266 10312 10319 10421 10440 10540 10566 10566 10647 10699 10778 10842 10855 10858 10968 10989 11036 11073 11077 11091 11107 11139 11260 11305 11311 11367 11455 11518 11570 11681 11711 11717 11755 11804 11937 11958 11982 12147 12148 12217 12223 12230 12375 12385 12502 12525 12676 12723 12884 12897 12955 13014 13109 13213 13389 13493 13504 13701 13734 13735 13845 13975 14028 14331 14360 14422 14477 14991 15118 15135 15270 15477 15782 15810 15830 16253 16678 17050 17470 17701 17790 17833 17911 17926 18195 18238 18284 18353 18651 18677 18692 18800 18810 19053 19103 19251 19375 19446 19611 19659 19736 19915 
//870


    return 0;
}