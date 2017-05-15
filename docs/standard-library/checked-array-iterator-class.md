---
title: Classe checked_array_iterator | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- iterator/checked_array_iterator
- checked_array_iterator
- iterator/stdext::checked_array_iterator::difference_type
- iterator/stdext::checked_array_iterator::pointer
- iterator/stdext::checked_array_iterator::reference
- iterator/stdext::checked_array_iterator::base
dev_langs:
- C++
helpviewer_keywords:
- checked_array_iterator, syntax
- checked_array_iterator class
- checked_array_iterator
ms.assetid: 7f07185e-d588-4ae3-9c4f-84ec4aa25a28
caps.latest.revision: 28
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: a53cc2a5bb7bd50e41e9e01d3953465706554017
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="checkedarrayiterator-class"></a>Classe checked_array_iterator
A classe `checked_array_iterator` permite que você transforme uma matriz ou um ponteiro em um iterador verificado. Use essa classe como um wrapper (usando a função [make_checked_array_iterator](../standard-library/iterator-functions.md#make_checked_array_iterator)) para matrizes ou ponteiros brutos como uma maneira direcionada de fornecer verificação e gerenciar avisos de ponteiros não verificados, em vez de silenciar esses avisos globalmente. Se necessário, você pode usar a versão não verificada da classe, [unchecked_array_iterator](../standard-library/unchecked-array-iterator-class.md).  
  
> [!NOTE]
>  Essa classe é uma extensão da Microsoft da Biblioteca Padrão C++. O código implementado usando essa função não é portátil para ambientes de criação do C++ Standard que não oferecem suporte a essa extensão da Microsoft. Para ver um exemplo que demonstra como escrever código que não exige uso dessa classe, veja o segundo exemplo abaixo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class _Iterator>  
class checked_array_iterator;
```  
  
## <a name="remarks"></a>Comentários  
 Essa classe é definida no namespace [stdext](../standard-library/stdext-namespace.md).  
  
 Para obter mais informações e o código de exemplo sobre o recurso de iterador verificado, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como definir e usar um iterador de matriz verificado.  
  
 Se o destino não for grande o suficiente para armazenar todos os elementos que estão sendo copiados, como seria se você tivesse alterado a linha:  
  
```cpp  
copy(a, a + 5, checked_array_iterator<int*>(b, 5));
```  
  
 para  
  
```cpp  
copy(a, a + 5, checked_array_iterator<int*>(b, 4));
```  
  
 Ocorrerá um erro de tempo de execução.  
  
```cpp  
// compile with: /EHsc /W4 /MTd  
#include <algorithm>  
#include <iostream>  
  
using namespace std;  
using namespace stdext;  
  
int main() {  
   int a[]={0, 1, 2, 3, 4};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b, 5));  
  
   cout << "(";  
   for (int i = 0 ; i < 5 ; i++)  
      cout << " " << b[i];  
   cout << " )" << endl;  
  
   // constructor example  
   checked_array_iterator<int*> checked_out_iter(b, 5);  
   copy(a, a + 5, checked_out_iter);  
  
   cout << "(";  
   for (int i = 0 ; i < 5 ; i++)  
      cout << " " << b[i];  
   cout << " )" << endl;  
}  
\* Output:   
( 0 1 2 3 4 )  
( 0 1 2 3 4 )  
*\  
```  
  
## <a name="example"></a>Exemplo  
 Para evitar a necessidade da classe `checked_array_iterator` ao usar algoritmos da Biblioteca Padrão C++, pense em usar um `vector`, em vez de uma matriz dinamicamente alocada. O exemplo a seguir demonstra como fazer isso.  
  
```cpp  
// compile with: /EHsc /W4 /MTd  
  
#include <algorithm>  
#include <iostream>  
#include <vector>  
  
using namespace std;  
  
int main()  
{  
    std::vector<int> v(10);  
    int *arr = new int[10];  
    for (int i = 0; i < 10; ++i)  
    {  
        v[i] = i;  
        arr[i] = i;  
    }  
  
    // std::copy(v.begin(), v.end(), arr); will result in  
    // warning C4996. To avoid this warning while using int *,  
    // use the Microsoft extension checked_array_iterator.  
    std::copy(v.begin(), v.end(),  
              stdext::checked_array_iterator<int *>(arr, 10));  
  
    // Instead of using stdext::checked_array_iterator and int *,  
    // consider using std::vector to encapsulate the array. This will  
    // result in no warnings, and the code will be portable.  
    std::vector<int> arr2(10);    // Similar to int *arr = new int[10];  
    std::copy(v.begin(), v.end(), arr2.begin());  
  
    for (int j = 0; j < arr2.size(); ++j)  
    {  
        cout << " " << arr2[j];  
    }  
    cout << endl;  
  
    return 0;  
}  
\* Output:   
 0 1 2 3 4 5 6 7 8 9  
*\  
```  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[checked_array_iterator](#checked_array_iterator)|Constrói um `checked_array_iterator` padrão ou um `checked_array_iterator` de um iterador subjacente.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[difference_type](#difference_type)|Um tipo que fornece a diferença entre dois `checked_array_iterator`s que se referem a elementos no mesmo contêiner.|  
|[pointer](#pointer)|Um tipo que fornece um ponteiro para um elemento tratado por um `checked_array_iterator`.|  
|[reference](#reference)|Um tipo que fornece uma referência a um elemento tratado por um `checked_array_iterator`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[base](#base)|Recupera o iterador subjacente de seu `checked_array_iterator`.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator==](#op_eq_eq)|Testa a igualdade de dois `checked_array_iterator`s.|  
|[operator!=](#op_neq)|Testa a desigualdade de dois `checked_array_iterator`s.|  
|[operator<](#op_lt)|Testa se o `checked_array_iterator` à esquerda do operador é menor que o `checked_array_iterator` à direita.|  
|[operator>](#op_gt)|Testa se o `checked_array_iterator` à esquerda do operador é maior que o `checked_array_iterator` à direita.|  
|[operator<=](#op_lt_eq)|Testa se o `checked_array_iterator` à esquerda do operador é menor ou igual ao `checked_array_iterator` à direita.|  
|[operator>=](#op_gt_eq)|Testa se o `checked_array_iterator` à esquerda do operador é maior ou igual ao `checked_array_iterator` à direita.|  
|[operator*](#op_star)|Retorna o elemento tratado por um `checked_array_iterator`.|  
|[operator->](#operator-_gt)|Retorna um ponteiro para o elemento tratado pelo `checked_array_iterator`.|  
|[operator++](#op_add_add)|Incrementa o `checked_array_iterator` até o próximo elemento.|  
|[operator--](#operator--)|Decrementa o `checked_array_iterator` para o elemento anterior.|  
|[operator+=](#op_add_eq)|Adiciona um deslocamento especificado para um `checked_array_iterator`.|  
|[operator+](#op_add)|Adiciona um deslocamento a um iterador e retorna o novo `checked_array_iterator` que trata o elemento inserido na nova posição de deslocamento.|  
|[operator-=](#operator-_eq)|Decrementa um deslocamento especificado de um `checked_array_iterator`.|  
|[operator-](#operator-)|Decrementa um deslocamento de um iterador e retorna o novo `checked_array_iterator` que trata o elemento inserido na nova posição de deslocamento.|  
|[operator&#91;&#93;](#op_at)|Retorna uma referência a um deslocamento do elemento tratado por um `checked_array_iterator` por um número especificado de posições.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<iterator>  
  
 **Namespace:** stdext  
  
##  <a name="base"></a>  checked_array_iterator::base  
 Recupera o iterador subjacente de seu `checked_array_iterator`.  
  
```
_Iterator base() const;
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_base.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main() {  
   using namespace std;  
  
   int V1[10];  
  
   for (int i = 0; i < 10 ; i++)  
      V1[i] = i;  
  
   int* bpos;  
  
   stdext::checked_array_iterator<int*> rpos(V1, 10);  
   rpos++;  
  
   bpos = rpos.base ( );  
   cout << "The iterator underlying rpos is bpos & it points to: "   
        << *bpos << "." << endl;  
}  
\* Output:   
The iterator underlying rpos is bpos & it points to: 1.  
*\  
```  
  
##  <a name="checked_array_iterator"></a>  checked_array_iterator::checked_array_iterator  
 Constrói um `checked_array_iterator` padrão ou um `checked_array _iterator` de um iterador subjacente.  
  
```
checked_array_iterator();

checked_array_iterator(
    ITerator ptr,
    size_t size,
    size_t index = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptr`  
 Um ponteiro para a matriz.  
  
 `size`  
 O tamanho da matriz.  
  
 `index`  
 (Opcional) Um elemento na matriz para inicializar o iterador.  Por padrão, o iterador é inicializado para o primeiro elemento na matriz.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_ctor.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <iostream>   
  
using namespace std;  
using namespace stdext;  
  
int main() {  
   int a[] = {0, 1, 2, 3, 4};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   for (int i = 0 ; i < 5 ; i++)  
      cout << b[i] << " ";  
   cout << endl;  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
   copy (a, a + 5, checked_output_iterator);  
   for (int i = 0 ; i < 5 ; i++)  
      cout << b[i] << " ";  
   cout << endl;  
  
   checked_array_iterator<int*> checked_output_iterator2(b,5,3);  
   cout << *checked_output_iterator2 << endl;  
}  
\* Output:   
0 1 2 3 4   
0 1 2 3 4   
3  
*\  
```  
  
##  <a name="difference_type"></a>  checked_array_iterator::difference_type  
 Um tipo que fornece a diferença entre dois `checked_array_iterator`s que se referem a elementos no mesmo contêiner.  
  
```
typedef typename iterator_traits<_Iterator>::difference_type difference_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo de diferença `checked_array_iterator` é o mesmo que o tipo de diferença do iterador.  
  
 Consulte um exemplo de código em [checked_array_iterator::operator[]](#op_at).  
  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
##  <a name="op_eq_eq"></a>  checked_array_iterator::operator==  
 Testa a igualdade de dois `checked_array_iterator`s.  
  
```
bool operator==(const checked_array_iterator<_Iterator>& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O `checked_array_iterator` com relação ao qual verificar quanto à igualdade.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_opeq.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <iostream>   
  
using namespace std;  
using namespace stdext;  
  
int main() {  
   int a[] = {0, 1, 2, 3, 4};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
   checked_array_iterator<int*> checked_output_iterator2(b,5);  
  
   if (checked_output_iterator2 == checked_output_iterator)  
      cout << "checked_array_iterators are equal" << endl;  
   else  
      cout << "checked_array_iterators are not equal" << endl;  
  
   copy (a, a + 5, checked_output_iterator);  
   checked_output_iterator++;  
  
   if (checked_output_iterator2 == checked_output_iterator)  
      cout << "checked_array_iterators are equal" << endl;  
   else  
      cout << "checked_array_iterators are not equal" << endl;  
}  
\* Output:   
checked_array_iterators are equal  
checked_array_iterators are not equal  
*\  
```  
  
##  <a name="op_neq"></a>  checked_array_iterator::operator!=  
 Testa a desigualdade de dois `checked_array_iterator`s.  
  
```
bool operator!=(const checked_array_iterator<_Iterator>& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O `checked_array_iterator` com relação ao qual verificar quanto à desigualdade.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_opneq.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <iostream>   
  
using namespace std;  
using namespace stdext;  
  
int main() {  
   int a[] = {0, 1, 2, 3, 4};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
   checked_array_iterator<int*> checked_output_iterator2(b,5);  
  
   if (checked_output_iterator2 != checked_output_iterator)  
      cout << "checked_array_iterators are not equal" << endl;  
   else  
      cout << "checked_array_iterators are equal" << endl;  
  
   copy (a, a + 5, checked_output_iterator);  
   checked_output_iterator++;  
  
   if (checked_output_iterator2 != checked_output_iterator)  
      cout << "checked_array_iterators are not equal" << endl;  
   else  
      cout << "checked_array_iterators are equal" << endl;  
}  
\* Output:   
checked_array_iterators are equal  
checked_array_iterators are not equal  
*\  
```  
  
##  <a name="op_lt"></a>  checked_array_iterator::operator&lt;  
 Testa se o `checked_array_iterator` à esquerda do operador é menor que o `checked_array_iterator` à direita.  
  
```
bool operator<(const checked_array_iterator<_Iterator>& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O `checked_array_iterator` com relação ao qual verificar quanto à desigualdade.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_oplt.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <iostream>   
  
using namespace std;  
using namespace stdext;  
  
int main() {  
   int a[] = {0, 1, 2, 3, 4};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
   checked_array_iterator<int*> checked_output_iterator2(b,5);  
  
   if (checked_output_iterator2 < checked_output_iterator)  
      cout << "checked_output_iterator2 is less than checked_output_iterator" << endl;  
   else  
      cout << "checked_output_iterator2 is not less than checked_output_iterator" << endl;  
  
   copy (a, a + 5, checked_output_iterator);  
   checked_output_iterator++;  
  
   if (checked_output_iterator2 < checked_output_iterator)  
      cout << "checked_output_iterator2 is less than checked_output_iterator" << endl;  
   else  
      cout << "checked_output_iterator2 is not less than checked_output_iterator" << endl;  
}  
\* Output:   
checked_output_iterator2 is not less than checked_output_iterator  
checked_output_iterator2 is less than checked_output_iterator  
*\  
```  
  
##  <a name="op_gt"></a>  checked_array_iterator::operator&gt;  
 Testa se o `checked_array_iterator` à esquerda do operador é maior que o `checked_array_iterator` à direita.  
  
```
bool operator>(const checked_array_iterator<_Iterator>& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O `checked_array_iterator` com o qual comparar.  
  
### <a name="remarks"></a>Comentários  
 Consulte um exemplo de código em [checked_array_iterator::operator&lt;](#op_lt).  
  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
##  <a name="lt_eq"></a>  checked_array_iterator::operator&lt;=  
 Testa se o `checked_array_iterator` à esquerda do operador é menor ou igual ao `checked_array_iterator` à direita.  
  
```
bool operator<=(const checked_array_iterator<_Iterator>& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O `checked_array_iterator` com o qual comparar.  
  
### <a name="remarks"></a>Comentários  
 Consulte um exemplo de código em [checked_array_iterator::operator&gt;=](#op_gt_eq).  
  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
##  <a name="gt_eq"></a>  checked_array_iterator::operator&gt;=  
 Testa se o `checked_array_iterator` à esquerda do operador é maior ou igual ao `checked_array_iterator` à direita.  
  
```
bool operator>=(const checked_array_iterator<_Iterator>& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O `checked_array_iterator` com o qual comparar.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_opgteq.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <iostream>   
  
using namespace std;  
using namespace stdext;  
  
int main() {  
   int a[] = {0, 1, 2, 3, 4};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
   checked_array_iterator<int*> checked_output_iterator2(b,5);  
  
   if (checked_output_iterator2 >= checked_output_iterator)  
      cout << "checked_output_iterator2 is greater than or equal to checked_output_iterator" << endl;  
   else  
      cout << "checked_output_iterator2 is less than checked_output_iterator" << endl;  
  
   copy (a, a + 5, checked_output_iterator);  
   checked_output_iterator++;  
  
   if (checked_output_iterator2 >= checked_output_iterator)  
      cout << "checked_output_iterator2 is greater than or equal to checked_output_iterator" << endl;  
   else  
      cout << "checked_output_iterator2 is less than checked_output_iterator" << endl;  
}  
\* Output:   
checked_output_iterator2 is greater than or equal to checked_output_iterator  
checked_output_iterator2 is less than checked_output_iterator  
*\  
```  
  
##  <a name="op_star"></a>  checked_array_iterator::operator*  
 Retorna o elemento tratado por um `checked_array_iterator`.  
  
```
reference operator*() const;
```  
  
### <a name="return-value"></a>Valor retornado  
 O valor do elemento abordado por `checked_array_iterator`.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterator_pointer.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <algorithm>  
#include <vector>  
#include <utility>  
#include <iostream>  
  
using namespace std;  
using namespace stdext;  
  
int main() {  
   int a[] = {0, 1, 2, 3, 4};  
   int b[5];  
   pair<int, int> c[1];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   for (int i = 0 ; i < 5 ; i++)  
      cout << b[i] << endl;  
  
    c[0].first = 10;  
    c[0].second = 20;  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
   checked_array_iterator<int*>::pointer p = &(*checked_output_iterator);  
   checked_array_iterator<pair<int, int>*> chk_c(c, 1);  
   checked_array_iterator<pair<int, int>*>::pointer p_c = &(*chk_c);  
  
   cout << "b[0] = " << *p << endl;  
   cout << "c[0].first = " << p_c->first << endl;  
}  
\* Output:   
0  
1  
2  
3  
4  
b[0] = 0  
c[0].first = 10  
*\  
```  
  
##  <a name="checked_array_iterator__operator-_gt"></a>  checked_array_iterator::operator-&gt;  
 Retorna um ponteiro para o elemento tratado pelo `checked_array_iterator`.  
  
```
pointer operator->() const;
```  
  
### <a name="return-value"></a>Valor retornado  
 Um ponteiro para o elemento tratado pelo `checked_array_iterator`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [checked_array_iterator::pointer](#pointer) para obter um exemplo de código.  
  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
##  <a name="op_add_add"></a>  checked_array_iterator::operator++  
 Incrementa o `checked_array_iterator` até o próximo elemento.  
  
```
checked_array_iterator& operator++();

checked_array_iterator<_Iterator> operator++(int);
```  
  
### <a name="return-value"></a>Valor retornado  
 O primeiro operador retorna o `checked_array_iterator` pré-incrementado e o segundo, o operador pós-incrementado, retorna uma cópia do `checked_array_iterator` incrementado.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_op_plus_plus.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main() {  
   using namespace stdext;  
   using namespace std;  
   int a[] = {6, 3, 77, 199, 222};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
  
   cout << *checked_output_iterator << endl;  
   ++checked_output_iterator;  
   cout << *checked_output_iterator << endl;  
   checked_output_iterator++;  
   cout << *checked_output_iterator << endl;  
}  
\* Output:   
6  
3  
77  
*\  
```  
  
##  <a name="checked_array_iterator__operator--"></a>  checked_array_iterator::operator--  
 Decrementa o `checked_array_iterator` para o elemento anterior.  
  
```
checked_array_iterator<_Iterator>& operator--();

checked_array_iterator<_Iterator> operator--(int);
```  
  
### <a name="return-value"></a>Valor retornado  
 O primeiro operador retorna o `checked_array_iterator` pré-decrementado e o segundo, o operador pós-decrementado, retorna uma cópia do `checked_array_iterator` decrementado.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_op_minus_minus.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main() {  
   using namespace stdext;  
   using namespace std;  
   int a[] = {6, 3, 77, 199, 222};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
  
   cout << *checked_output_iterator << endl;  
   checked_output_iterator++;  
   cout << *checked_output_iterator << endl;  
   checked_output_iterator--;  
   cout << *checked_output_iterator << endl;  
}  
\* Output:   
6  
3  
6  
*\  
```  
  
##  <a name="op_add_eq"></a>  checked_array_iterator::operator+=  
 Adiciona um deslocamento especificado para um `checked_array_iterator`.  
  
```
checked_array_iterator<_Iterator>& operator+=(difference_type _Off);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 O deslocamento pelo qual incrementar o iterador.  
  
### <a name="return-value"></a>Valor retornado  
 Uma referência ao elemento tratado pelo `checked_array_iterator`.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_op_plus_eq.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main() {  
   using namespace stdext;  
   using namespace std;  
   int a[] = {6, 3, 77, 199, 222};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
  
   cout << *checked_output_iterator << endl;  
   checked_output_iterator += 3;  
   cout << *checked_output_iterator << endl;  
}  
\* Output:   
6  
199  
*\  
```  
  
##  <a name="op_add"></a>  checked_array_iterator::operator+  
 Adiciona um deslocamento a um iterador e retorna o novo `checked_array_iterator` que trata o elemento inserido na nova posição de deslocamento.  
  
```
checked_array_iterator<_Iterator> operator+(difference_type _Off) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 O deslocamento a ser adicionado a `checked_array_iterator`.  
  
### <a name="return-value"></a>Valor retornado  
 Um `checked_array_iterator` que trata o elemento de deslocamento.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_op_plus.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main() {  
   using namespace stdext;  
   using namespace std;  
   int a[] = {6, 3, 77, 199, 222};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
  
   cout << *checked_output_iterator << endl;  
   checked_output_iterator = checked_output_iterator + 3;  
   cout << *checked_output_iterator << endl;  
}  
\* Output:   
6  
199  
*\  
```  
  
##  <a name="checked_array_iterator__operator-_eq"></a>  checked_array_iterator::operator-=  
 Decrementa um deslocamento especificado de um `checked_array_iterator`.  
  
```
checked_array_iterator<_Iterator>& operator-=(difference_type _Off);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 O deslocamento pelo qual incrementar o iterador.  
  
### <a name="return-value"></a>Valor retornado  
 Uma referência ao elemento tratado pelo `checked_array_iterator`.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_op_minus_eq.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main() {  
   using namespace stdext;  
   using namespace std;  
   int a[] = {6, 3, 77, 199, 222};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b,5));  
  
   checked_array_iterator<int*> checked_output_iterator(b,5);  
  
   checked_output_iterator += 3;  
   cout << *checked_output_iterator << endl;  
   checked_output_iterator -= 2;  
   cout << *checked_output_iterator << endl;  
}  
\* Output:   
199  
3  
*\  
```  
  
##  <a name="checked_array_iterator__operator-"></a>  checked_array_iterator::operator-  
 Decrementa um deslocamento de um iterador e retorna o novo `checked_array_iterator` que trata o elemento inserido na nova posição de deslocamento.  
  
```
checked_array_iterator<_Iterator> operator-(difference_type _Off) const;

difference_type operator-(const checked_array_iterator& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 O deslocamento a ser decrementado do `checked_array_iterator`.  
  
### <a name="return-value"></a>Valor retornado  
 Um `checked_array_iterator` que trata o elemento de deslocamento.  
  
### <a name="remarks"></a>Comentários  
 Consulte um exemplo de código em [checked_array_iterator::operator-](#operator-).  
  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
##  <a name="op_at"></a>  checked_array_iterator::operator[]  
 Retorna uma referência a um deslocamento do elemento tratado por um `checked_array_iterator` por um número especificado de posições.  
  
```
reference operator[](difference_type _Off) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 O deslocamento do endereço `checked_array_iterator`.  
  
### <a name="return-value"></a>Valor retornado  
 A referência ao deslocamento de elemento.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// checked_array_iterators_op_diff.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
  
int main() {  
   using namespace std;     
   int V1[10];  
  
   for (int i = 0; i < 10 ; i++)  
      V1[i] = i;  
  
   // Declare a difference type for a parameter  
   stdext::checked_array_iterator<int*>::difference_type diff = 2;  
  
   stdext::checked_array_iterator<int*> VChkIter(V1, 10);  
  
   stdext::checked_array_iterator<int*>::reference refrpos = VChkIter [diff];  
  
   cout << refrpos + 1 << endl;  
}  
\* Output:   
3  
*\  
```  
  
##  <a name="pointer"></a>  checked_array_iterator::pointer  
 Um tipo que fornece um ponteiro para um elemento tratado por um `checked_array_iterator`.  
  
```
typedef typename iterator_traits<_Iterator>::pointer pointer;
```  
  
### <a name="remarks"></a>Comentários  
 Consulte um exemplo de código em [checked_array_iterator::operator*](#op_star).  
  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
##  <a name="reference"></a>  checked_array_iterator::reference  
 Um tipo que fornece uma referência a um elemento tratado por um `checked_array_iterator`.  
  
```
typedef typename iterator_traits<_Iterator>::reference reference;
```  
  
### <a name="remarks"></a>Comentários  
 Consulte um exemplo de código em [checked_array_iterator::operator[]](#op_at).  
  
 Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).  
  
## <a name="see-also"></a>Consulte também  
 [\<iterator>](../standard-library/iterator.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




