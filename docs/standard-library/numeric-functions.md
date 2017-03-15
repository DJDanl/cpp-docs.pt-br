---
title: "Funções &lt;numeric&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: a4b0449a-c80c-4a1d-8d9f-d7fcd0058f8b
caps.latest.revision: 13
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 88c311b28caa80d4c4292888be501feae797ce27
ms.lasthandoff: 02/25/2017

---
# <a name="ltnumericgt-functions"></a>Funções &lt;numeric&gt;
||||  
|-|-|-|  
|[accumulate](#accumulate)|[adjacent_difference](#adjacent_difference)|[inner_product](#inner_product)|  
|[iota](#iota)|[partial_sum](#partial_sum)|  
  
##  <a name="a-nameaccumulatea--accumulate"></a><a name="accumulate"></a>  accumulate  
 Calcula a soma de todos os elementos em um intervalo especificado, incluindo qualquer valor inicial ao calcular somas parciais sucessivas ou calcula o resultado de resultados parciais sucessivos obtidos usando uma operação binária especificada diferente da soma.  
  
```  
template <class InputIterator, class Type>  
Type accumulate(InputIterator first, InputIterator last, Type val);

template <class InputIterator, class Type, class BinaryOperation>  
Type accumulate(
    InputIterator first, 
    InputIterator last, 
    Type val, 
    BinaryOperation binary_op);
```  
  
### <a name="parameters"></a>Parâmetros   
 ` first`  
 Um iterador de entrada que trata o primeiro elemento no intervalo para ser somado ou combinado de acordo com uma operação binária especificada.  
  
 ` last`  
 Um iterador de entrada que trata o último elemento no intervalo para ser somado ou combinado, de acordo com uma operação binária especificada que está uma posição além do elemento final de fato incluído no acúmulo iterado.  
  
 ` val`  
 Um valor inicial para o qual cada elemento por sua vez é adicionado ou combinado de acordo com uma operação binária especificada.  
  
 `binary_op`  
 A operação binária que deve ser aplicada a cada elemento no intervalo especificado e o resultado de suas aplicações anteriores.  
  
### <a name="return-value"></a>Valor de retorno  
 A soma de ` val` e todos os elementos no intervalo especificado para a primeira função de modelo ou, para a segunda função de modelo, o resultado da aplicação de operação binária especificada, em vez da operação de soma, para ( *PartialResult, \*Iter*), em que *PartialResult* é o resultado de aplicações anteriores da operação e `Iter` é um iterador apontando para um elemento no intervalo.  
  
### <a name="remarks"></a>Comentários  
 O valor inicial garante que haverá um resultado bem definido quando o intervalo estiver vazio. Nesse caso, ` val` é retornado. A operação binária não precisa ser associativa ou comutativa. O resultado é inicializado com o valor inicial ` val` e, então, o *resultado* = `binary_op` ( *resultado*, **\***`Iter`) é calculado iterativamente pelo intervalo, em que `Iter` é um iterador apontando para o elemento sucessivo no intervalo. O intervalo deve ser válido e a complexidade deve ser linear com o tamanho do intervalo. O tipo de retorno do operador binário deve ser conversível para **Type** para garantir o fechamento durante a iteração.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_accum.cpp  
// compile with: /EHsc  
#include <vector>  
#include <numeric>  
#include <functional>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   vector <int> v1, v2(20);  
   vector <int>::iterator iter1, iter2;  
  
   int i;  
   for (i = 1; i < 21; i++)  
   {  
      v1.push_back(i);  
   }  
  
   cout << "The original vector v1 is:\n ( " ;  
   for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)  
      cout << *iter1 << " ";  
   cout << ")." << endl;  
  
   // The first member function for the accumulated sum  
   int total;  
   total = accumulate(v1.begin(), v1.end(), 0);  
  
   cout << "The sum of the integers from 1 to 20 is: "  
        << total << "." << endl;  
  
   // Constructing a vector of partial sums  
   int j = 0, partotal;  
   for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)  
   {  
      partotal = accumulate(v1.begin(), iter1 + 1, 0);  
      v2[j] = partotal;  
      j++;  
   }  
  
   cout << "The vector of partial sums is:\n ( " ;  
   for (iter2 = v2.begin(); iter2 != v2.end(); iter2++)  
      cout << *iter2 << " ";  
   cout << ")." << endl << endl;  
  
   // The second member function for the accumulated product  
   vector <int> v3, v4(10);  
   vector <int>::iterator iter3, iter4;  
  
   int s;  
   for (s = 1; s < 11; s++)  
   {  
      v3.push_back(s);  
   }  
  
   cout << "The original vector v3 is:\n ( " ;  
   for (iter3 = v3.begin(); iter3 != v3.end(); iter3++)  
      cout << *iter3 << " ";  
   cout << ")." << endl;  
  
   int ptotal;  
   ptotal = accumulate(v3.begin(), v3.end(), 1, multiplies<int>());  
  
   cout << "The product of the integers from 1 to 10 is: "  
        << ptotal << "." << endl;  
  
   // Constructing a vector of partial products  
   int k = 0, ppartotal;  
   for (iter3 = v3.begin(); iter3 != v3.end(); iter3++) {  
      ppartotal = accumulate(v3.begin(), iter3 + 1, 1, multiplies<int>());  
      v4[k] = ppartotal;  
      k++;  
   }  
  
   cout << "The vector of partial products is:\n ( " ;  
   for (iter4 = v4.begin(); iter4 != v4.end(); iter4++)  
      cout << *iter4 << " ";  
   cout << ")." << endl;  
}  
```  
  
```Output  
The original vector v1 is:  
 ( 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ).  
The sum of the integers from 1 to 20 is: 210.  
The vector of partial sums is:  
 ( 1 3 6 10 15 21 28 36 45 55 66 78 91 105 120 136 153 171 190 210 ).  
  
The original vector v3 is:  
 ( 1 2 3 4 5 6 7 8 9 10 ).  
The product of the integers from 1 to 10 is: 3628800.  
The vector of partial products is:  
 ( 1 2 6 24 120 720 5040 40320 362880 3628800 ).  
```  
  
##  <a name="a-nameadjacentdifferencea--adjacentdifference"></a><a name="adjacent_difference"></a>  adjacent_difference  
 Calcula as diferenças sucessivas entre cada elemento e seu predecessor em um intervalo de entrada e gera os resultados em um intervalo de destino ou calcula o resultado de um procedimento generalizado, em que a operação de diferença é substituída por outra operação binária especificada.  
  
```  
template <class InputIterator, class OutIterator>  
OutputIterator adjacent_difference(
    InputIterator first, 
    InputIterator last, 
    OutputIterator result);

template <class InputIterator, class OutIterator, class BinaryOperation>  
OutputIterator adjacent_difference(
    InputIterator first, 
    InputIterator last, 
    OutputIterator result, 
    BinaryOperation binary_op);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` first`  
 Um iterador de entrada que trata o primeiro elemento no intervalo de entrada cujos elementos deverão ser diferenciados com seus respectivos antecessores ou onde o par de valores deverá ser operado por qualquer outra operação binária especificada.  
  
 ` last`  
 Um iterador de entrada que trata o último elemento no intervalo de entrada cujos elementos deverão ser diferenciados com seus respectivos antecessores ou onde o par de valores deverá ser operado por qualquer outra operação binária especificada.  
  
 `result`  
 Um iterador de saída que trata o primeiro elemento em um intervalo de destino onde a série de diferenças ou os resultados da operação especificada deverão ser armazenados.  
  
 `binary_op`  
 A operação binária que deverá ser aplicada na operação generalizada substituindo a operação de subtração no procedimento de diferenciação.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída que trata a extremidade do intervalo de destino: `result` + ( ` last` - ` first`).  
  
### <a name="remarks"></a>Comentários  
 O iterador de saída _ *result* tem permissão para ser o mesmo iterador que o iterador de entrada * first,* de modo que `adjacent_difference`s podem ser calculados no lugar.  
  
 Para uma sequência de valores *a*1, *a*2, *a*3, em um intervalo de entrada, a primeira função de modelo armazena **partial_difference**s sucessivas *a*1, *a*2 - *a*1, a3 – *a*2, no intervalo de destino.  
  
 Para uma sequência de valores *a*1, *a*2, *a*3, em um intervalo de entrada, a segunda função de modelo armazena **partial_difference**s sucessivas *a*1, *a*2 `binary_op` *a*1, *a*3 `binary_op` *a*2, no intervalo de destino.  
  
 A operação binária `binary_op` não precisa obrigatoriamente ser associativa ou comutativa, pois a ordem das operações aplicada é totalmente especificada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_adj_diff.cpp  
// compile with: /EHsc  
#include <vector>  
#include <list>  
#include <numeric>  
#include <functional>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
  
   vector<int> V1( 10 ), V2( 10 );  
   vector<int>::iterator VIter1, VIter2, VIterend, VIterend2;  
  
   list <int> L1;  
   list <int>::iterator LIter1, LIterend, LIterend2;  
  
   int t;  
   for ( t = 1 ; t <= 10 ; t++ )  
   {  
      L1.push_back( t * t );  
   }  
  
   cout << "The input list L1 is:\n ( " ;  
   for ( LIter1 = L1.begin( ) ; LIter1 != L1.end( ) ; LIter1++ )  
      cout << *LIter1 << " ";  
   cout << ")." << endl;  
  
   // The first member function for the adjacent_differences of  
   // elements in a list output to a vector  
   VIterend = adjacent_difference ( L1.begin ( ) , L1.end ( ) ,   
      V1.begin ( ) );  
  
   cout << "Output vector containing adjacent_differences is:\n ( " ;  
   for ( VIter1 = V1.begin( ) ; VIter1 != VIterend ; VIter1++ )  
      cout << *VIter1 << " ";  
   cout << ")." << endl;  
  
   // The second member function used to compute  
   // the adjacent products of the elements in a list  
   VIterend2 = adjacent_difference ( L1.begin ( ) , L1.end ( ) , V2.begin ( ) ,   
      multiplies<int>( ) );  
  
   cout << "The output vector with the adjacent products is:\n ( " ;  
   for ( VIter2 = V2.begin( ) ; VIter2 != VIterend2 ; VIter2++ )  
      cout << *VIter2 << " ";  
   cout << ")." << endl;  
  
   // Computation of adjacent_differences in place  
   LIterend2 = adjacent_difference ( L1.begin ( ) , L1.end ( ) , L1.begin ( ) );  
   cout << "In place output adjacent_differences in list L1 is:\n ( " ;  
   for ( LIter1 = L1.begin( ) ; LIter1 != LIterend2 ; LIter1++ )  
      cout << *LIter1 << " ";  
   cout << ")." << endl;  
}  
```  
  
##  <a name="a-nameinnerproducta--innerproduct"></a><a name="inner_product"></a>  inner_product  
 Calcula a soma do produto em relação ao elemento de dois intervalos e a adiciona a um valor inicial especificado ou calcula o resultado de um procedimento generalizado, em que as operações binárias de produto e a soma são substituídas por outras operações binárias especificadas.  
  
```  
template <class InputIterator1, class InputIterator2, class Type>  
Type inner_product(
    InputIterator1   first1, 
    InputIterator1   last1, 
    InputIterator2   first2, 
    Type             val);

template <class InputIterator1, class InputIterator2, class Type, class BinaryOperation1, class BinaryOperation2>  
Type inner_product(
    InputIterator1   first1, 
    InputIterator1   last1, 
    InputIterator2   first2, 
    Type             val, 
    BinaryOperation1  binary_op1, 
    BinaryOperation2  binary_op2);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` first1`  
 Um iterador de entrada que trata o primeiro elemento no primeiro intervalo cujo produto interno ou produto interno generalizado com o segundo intervalo deverá ser calculado.  
  
 ` last1`  
 Um iterador de entrada que trata o último elemento no primeiro intervalo cujo produto interno ou produto interno generalizado com o segundo intervalo deverá ser calculado.  
  
 ` first2`  
 Um iterador de entrada que trata o primeiro elemento no segundo intervalo cujo produto interno ou produto interno generalizado com o primeiro intervalo deverá ser calculado.  
  
 ` val`  
 Um valor inicial para o qual deve ser adicionado o produto interno ou o produto interno generalizado entre os intervalos.  
  
 *binary_op1*  
 A operação binária que substitui a operação de produto interna da soma aplicada aos produtos em relação ao elemento na generalização do produto interno.  
  
 *binary_op2*  
 A operação binária que substitui a operação em relação ao elemento do produto interno da multiplicação na generalização do produto interno.  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira função membro retorna a soma dos produtos em relação ao elemento e adiciona a ela o valor inicial especificado. Então, para intervalos de valores *a*i e *b*i, ela retornará:  
  
 ` val` + ( *a*1 \* *b*1 ) + ( *a*2 \* *b*2 ) +  
  
 ao substituir ` val` iterativamente por ` val` + (\* *a*i \* \* *b*i ).  
  
 A segunda função membro retorna:  
  
 ` val` _ *Binary_op1* ( *a*1 \_ *Binary_op2* *b*1 ) \_ *Binary_op1* ( *a*2 \_ *Binary_op2* *b*2 ) \_ *Binary_op1*  
  
 ao substituir ` val` iterativamente por ` val` _ *Binary_op1* (\* *a*i \_ *Binary_op2* \* *b*i ).  
  
### <a name="remarks"></a>Comentários  
 O valor inicial garante que haverá um resultado bem definido quando o intervalo estiver vazio. Nesse caso, ` val` é retornado. As operações binárias não precisam ser associativas ou comutativas. O intervalo deve ser válido e a complexidade deve ser linear com o tamanho do intervalo. O tipo de retorno do operador binário deve ser conversível para **Type** para garantir o fechamento durante a iteração.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_inner_prod.cpp  
// compile with: /EHsc  
#include <vector>  
#include <list>  
#include <numeric>  
#include <functional>  
#include <iostream>  
  
int main()  
{  
   using namespace std;  
  
   vector <int> v1, v2(7), v3(7);  
   vector <int>::iterator iter1, iter2, iter3;  
  
   int i;  
   for (i = 1; i <= 7; i++)  
   {  
      v1.push_back(i);  
   }  
  
   cout << "The original vector v1 is:\n ( " ;  
   for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)  
      cout << *iter1 << " ";  
   cout << ")." << endl;  
  
   list <int> l1, l2(7);  
   list <int>::iterator lIter1, lIter2;  
  
   int t;  
   for (t = 1; t <= 7; t++)  
   {  
      l1.push_back(t);  
   }  
  
   cout << "The original list l1 is:\n ( " ;  
   for (lIter1 = l1.begin(); lIter1 != l1.end(); lIter1++)  
      cout << *lIter1 << " ";  
   cout << ")." << endl;  
  
   // The first member function for the inner product  
   int inprod;  
   inprod = inner_product(v1.begin(), v1.end(), l1.begin(), 0);  
  
   cout << "The inner_product of the vector v1 and the list l1 is: "  
        << inprod << "." << endl;  
  
   // Constructing a vector of partial inner_products between v1 & l1  
   int j = 0, parinprod;  
   for (iter1 = v1.begin(); iter1 != v1.end(); iter1++) {  
      parinprod = inner_product(v1.begin(), iter1 + 1, l1.begin(), 0);  
      v2[j] = parinprod;  
      j++;  
   }  
  
   cout << "Vector of partial inner_products between v1 & l1 is:\n ( " ;  
   for (iter2 = v2.begin(); iter2 != v2.end(); iter2++)  
      cout << *iter2 << " ";  
   cout << ")." << endl << endl;  
  
   // The second member function used to compute  
   // the product of the element-wise sums  
   int inprod2;  
   inprod2 = inner_product (v1.begin(), v1.end(),  
      l1.begin(), 1, multiplies<int>(), plus<int>());  
  
   cout << "The sum of the element-wise products of v1 and l1 is: "  
        << inprod2 << "." << endl;  
  
   // Constructing a vector of partial sums of element-wise products  
   int k = 0, parinprod2;  
   for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)  
   {  
      parinprod2 =  
         inner_product(v1.begin(), iter1 + 1, l1.begin(), 1,  
         multiplies<int>(), plus<int>());  
      v3[k] = parinprod2;  
      k++;  
   }  
  
   cout << "Vector of partial sums of element-wise products is:\n ( " ;  
   for (iter3 = v3.begin(); iter3 != v3.end(); iter3++)  
      cout << *iter3 << " ";  
   cout << ")." << endl << endl;  
}  
```  
  
##  <a name="a-nameiotaa--iota"></a><a name="iota"></a>  iota  
 Armazena um valor inicial, começando com o primeiro elemento e preenchendo com incrementos sucessivos do valor (` value++`) em cada um dos elementos no intervalo `[ first,  last)`.  
  
```  
template <class ForwardIterator, class Type>  
void iota(ForwardIterator first, ForwardIterator last, Type value);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` first`  
 Um iterador de entrada que trata o primeiro elemento no intervalo a ser preenchido.  
  
 ` last`  
 Um iterador de entrada que trata o último elemento no intervalo a ser preenchido.  
  
 ` value`  
 O valor inicial para armazenar no primeiro elemento e incrementar sucessivamente para elementos subsequentes.  
  
### <a name="remarks"></a>Comentários  
  
### <a name="example"></a>Exemplo  
  O exemplo a seguir demonstra alguns usos para a função `iota` ao preencher uma [lista](../standard-library/list.md) de inteiros e, em seguida, preencher um [vetor](../standard-library/vector.md) com o `list` para que a função [random_shuffle](../standard-library/algorithm-functions.md#random_shuffle) possa ser usada.  
  
```cpp  
// compile by using: cl /EHsc /nologo /W4 /MTd  
#include <algorithm>  
#include <numeric>  
#include <list>  
#include <vector>  
#include <iostream>  
  
using namespace std;  
  
int main(void)  
{  
    list <int> intList(10);  
    vector <list<int>::iterator> intVec(intList.size());  
  
    // Fill the list  
    iota(intList.begin(), intList.end(), 0);  
  
    // Fill the vector with the list so we can shuffle it  
    iota(intVec.begin(), intVec.end(), intList.begin());  
  
    random_shuffle(intVec.begin(), intVec.end());  
  
    // Output results  
    cout << "Contents of the integer list: " << endl;  
    for (auto i: intList) {  
        cout << i << ' ';  
    }  
    cout << endl << endl;  
  
    cout << "Contents of the integer list, shuffled by using a vector: " << endl;  
    for (auto i: intVec) {  
        cout << *i << ' ';  
    }  
    cout << endl;  
}  
```  
  
##  <a name="a-namepartialsuma--partialsum"></a><a name="partial_sum"></a>  partial_sum  
 Calcula uma série de somas em um intervalo de entrada, do primeiro ao *i*-ésimo elemento e armazena o resultado de cada soma no *i*-ésimo elemento de um intervalo de destino ou calcula o resultado de um procedimento generalizado, em que a operação de soma é substituída por outra operação binária especificada.  
  
```  
template <class InputIterator, class OutIt>  
OutputIterator partial_sum(
    InputIterator first, 
    InputIterator last, 
    OutputIterator result);

template <class InputIterator, class OutIt, class Fn2>  
OutputIterator partial_sum(
    InputIterator first, 
    InputIterator last, 
    OutputIterator result, 
    BinaryOperation binary_op);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` first`  
 Um iterador de entrada que trata o primeiro elemento no intervalo para ser parcialmente somado ou combinado de acordo com uma operação binária especificada.  
  
 ` last`  
 Um iterador de entrada que trata o último elemento no intervalo para ser parcialmente somado ou combinado, de acordo com uma operação binária especificada que está uma posição além do elemento final de fato incluído no acúmulo iterado.  
  
 `result`  
 Um iterador de saída que trata o primeiro elemento em um intervalo de destino onde a série de somas parciais ou os resultados da operação especificada deverão ser armazenados.  
  
 `binary_op`  
 A operação binária que deverá ser aplicada na operação generalizada substituindo a operação de soma no procedimento de soma parcial.    
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador de saída que trata a extremidade do intervalo de destino: `result` + ( ` last` - ` first`),  
  
### <a name="remarks"></a>Comentários  
 O iterador de saída `result` tem permissão para ser o mesmo iterador que o iterador de entrada ` first`, de modo que as somas parciais podem ser calculadas adequadamente.  
  
 Para uma sequência de valores *a*1, *a*2, *a*3, em um intervalo de entrada, a primeira função de modelo armazena somas parciais sucessivas no intervalo de destino, em que o *i*-ésimo elemento é fornecido por (  ( ( *a*1 + *a*2) + *a*3) *a*i).  
  
 Para uma sequência de valores *a*1, *a*2, *a*3, em um intervalo de entrada, a segunda função de modelo armazena somas parciais sucessivas no intervalo de destino, em que o i-ésimo elemento é fornecido por (  ( ( *a*1`binary_op` *a*2 ) `binary_op` *a*3 ) *a*i).  
  
 A operação binária `binary_op` não precisa obrigatoriamente ser associativa ou comutativa, pois a ordem das operações aplicada é totalmente especificada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// numeric_partial_sum.cpp  
// compile with: /EHsc  
#include <vector>  
#include <list>  
#include <numeric>  
#include <functional>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;     
   vector<int> V1( 10 ), V2( 10 );  
   vector<int>::iterator VIter1, VIter2, VIterend, VIterend2;  
  
   list <int> L1;  
   list <int>::iterator LIter1, LIterend;  
  
   int t;  
   for ( t = 1 ; t <= 10 ; t++ )  
   {  
      L1.push_back( t );  
   }  
  
   cout << "The input list L1 is:\n ( " ;  
   for ( LIter1 = L1.begin( ) ; LIter1 != L1.end( ) ; LIter1++ )  
      cout << *LIter1 << " ";  
   cout << ")." << endl;  
  
   // The first member function for the partial sums of  
   // elements in a list output to a vector  
   VIterend = partial_sum ( L1.begin ( ) , L1.end ( ) ,   
      V1.begin ( ) );  
  
   cout << "The output vector containing the partial sums is:\n ( " ;  
   for ( VIter1 = V1.begin( ) ; VIter1 != VIterend ; VIter1++ )  
      cout << *VIter1 << " ";  
   cout << ")." << endl;  
  
   // The second member function used to compute  
   // the partial product of the elements in a list  
   VIterend2 = partial_sum ( L1.begin ( ) , L1.end ( ) , V2.begin ( ) ,   
      multiplies<int>( ) );  
  
   cout << "The output vector with the partial products is:\n ( " ;  
   for ( VIter2 = V2.begin( ) ; VIter2 != VIterend2 ; VIter2++ )  
      cout << *VIter2 << " ";  
   cout << ")." << endl;  
  
   // Computation of partial sums in place  
   LIterend = partial_sum ( L1.begin ( ) , L1.end ( ) , L1.begin ( ) );  
   cout << "The in place output partial_sum list L1 is:\n ( " ;  
   for ( LIter1 = L1.begin( ) ; LIter1 != LIterend ; LIter1++ )  
      cout << *LIter1 << " ";  
   cout << ")." << endl;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<numeric>](../standard-library/numeric.md)


