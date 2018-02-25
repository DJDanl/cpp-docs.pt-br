---
title: Classe ostream_iterator | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- iterator/std::ostream_iterator
- iterator/std::ostream_iterator::char_type
- iterator/std::ostream_iterator::ostream_type
- iterator/std::ostream_iterator::traits_type
dev_langs:
- C++
helpviewer_keywords:
- std::ostream_iterator [C++]
- std::ostream_iterator [C++], char_type
- std::ostream_iterator [C++], ostream_type
- std::ostream_iterator [C++], traits_type
ms.assetid: 24d842d3-9f45-4bf6-a697-62f5968f5a03
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c857ef1dc58bf1494e340382fbb56081374eaaab
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ostreamiterator-class"></a>Classe ostream_iterator
A classe de modelo ostream_iterator descreve um objeto de iterador de saída que grava elementos sucessivos no fluxo de saída com a extração **operator <<**.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Type class CharType = char class Traits = char_traits <CharType>>  
class ostream_iterator
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Tipo*  
 O tipo de objeto a ser inserido no fluxo de saída.  
  
 `CharType`  
 O tipo que representa o tipo de caractere para `ostream_iterator`. Esse argumento é opcional e o valor padrão é `char`.  
  
 `Traits`  
 O tipo que representa o tipo de caractere para `ostream_iterator`. Esse argumento é opcional e o valor padrão é `char_traits`\< *CharType>.*  
  
 A classe ostream_iterator deve atender aos requisitos de um iterador de saída. Os algoritmos podem ser gravados diretamente nos fluxos de saída usando um `ostream_iterator`.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[ostream_iterator](#ostream_iterator)|Constrói uma `ostream_iterator` que é inicializada e delimitada a gravar no fluxo de saída.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#char_type)|Um tipo que é fornecido para o tipo de caractere do `ostream_iterator`.|  
|[ostream_type](#ostream_type)|Um tipo que é fornecido para o tipo de fluxo da `ostream_iterator`.|  
|[traits_type](#traits_type)|Um tipo que fornece o tipo de característica do caractere da `ostream_iterator`.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator*](#op_star)|Operador de desreferenciamento usado para implementar a expressão do iterador de saída * `i` = `x`.|  
|[operator++](#op_add_add)|Um operador de incremento não funcional que retorna uma `ostream_iterator` para o mesmo objeto que foi tratado antes de a operação ser chamada.|  
|[operator=](#op_eq)|O operador de atribuição usado para implementar a expressão do iterador de saída * `i` = `x` para gravação em um fluxo de saída.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<iterator>  
  
 **Namespace:** std  
  
##  <a name="char_type"></a>  ostream_iterator::char_type  
 Um tipo que é fornecido para o tipo de caractere do iterador.  
  
```
typedef CharType char_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **CharType**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ostream_iterator_char_type.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   typedef ostream_iterator<int>::char_type CHT1;  
   typedef ostream_iterator<int>::traits_type CHTR1;  
  
   // ostream_iterator for stream cout  
   // with new line delimiter:  
    ostream_iterator<int, CHT1, CHTR1> intOut ( cout , "\n" );  
  
   // Standard iterator interface for writing  
   // elements to the output stream:  
   cout << "The integers written to the output stream\n"  
        << "by intOut are:" << endl;  
 *intOut = 10;  
 *intOut = 20;  
 *intOut = 30;  
}  
\* Output:   
The integers written to the output stream  
by intOut are:  
10  
20  
30  
*\  
```  
  
##  <a name="op_star"></a>  ostream_iterator::operator*  
 Operador de desreferenciamento usado para implementar a expressão do iterador de saída \* *ii* = *x*.  
  
```
ostream_iterator<Type, CharType, Traits>& operator*();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao `ostream_iterator`.  
  
### <a name="remarks"></a>Comentários  
 Os requisitos para um iterador de saída que `ostream_iterator` deve satisfazer exigem somente que a expressão \* *ii* = *t* seja válida e que ela não diga nada sobre o **operator** ou o `operator=` por conta própria. O operador de membro nesta implementação retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ostream_iterator_op_deref.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // ostream_iterator for stream cout  
   // with new line delimiter  
   ostream_iterator<int> intOut ( cout , "\n" );  
  
   // Standard iterator interface for writing  
   // elements to the output stream  
   cout << "Elements written to output stream:" << endl;  
 *intOut = 10;  
   intOut++;      // No effect on iterator position  
 *intOut = 20;  
 *intOut = 30;  
}  
\* Output:   
Elements written to output stream:  
10  
20  
30  
*\  
```  
  
##  <a name="op_add_add"></a>  ostream_iterator::operator++  
 Um operador de incremento não funcional que retorna uma `ostream_iterator` para o mesmo objeto que foi tratado antes de a operação ser chamada.  
  
```
ostream_iterator<Type, CharType, Traits>& operator++();
ostream_iterator<Type, CharType, Traits> operator++(int);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao `ostream_iterator`.  
  
### <a name="remarks"></a>Comentários  
 Ambos esses operadores de membros retornam **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ostream_iterator_op_incr.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // ostream_iterator for stream cout  
   // with new line delimiter  
   ostream_iterator<int> intOut ( cout , "\n" );  
  
   // standard iterator interface for writing  
   // elements to the output stream  
   cout << "Elements written to output stream:" << endl;  
 *intOut = 10;  
   intOut++;      // No effect on iterator position  
 *intOut = 20;  
 *intOut = 30;  
}  
\* Output:   
Elements written to output stream:  
10  
20  
30  
*\  
```  
  
##  <a name="op_eq"></a>  ostream_iterator::operator=  
 O operador de atribuição usado para implementar a expressão output_iterator * `i` = `x` para gravação em um fluxo de saída.  
  
```
ostream_iterator<Type, CharType, Traits>& operator=(const Type& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `val`  
 O valor do objeto do tipo `Type` a ser inserido no fluxo de saída.  
  
### <a name="return-value"></a>Valor de retorno  
 O operador insere `val` no fluxo de saída associado ao objeto, seguido pelo delimitador especificado no [construtor ostream_iterator](#ostream_iterator) (se houver) e, em seguida, retorna uma referência para o `ostream_iterator`.  
  
### <a name="remarks"></a>Comentários  
 Os requisitos para um iterador de saída que `ostream_iterator` deve satisfazer exigem somente que a expressão * `ii` = `t` seja válida e que ela não diga nada sobre o operator ou operator= por conta própria. Esse operador de membro retorna `*this`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ostream_iterator_op_assign.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // ostream_iterator for stream cout  
   // with new line delimiter  
   ostream_iterator<int> intOut ( cout , "\n" );  
  
   // Standard iterator interface for writing  
   // elements to the output stream  
   cout << "Elements written to output stream:" << endl;  
 *intOut = 10;  
   intOut++;      // No effect on iterator position  
 *intOut = 20;  
 *intOut = 30;  
}  
\* Output:   
Elements written to output stream:  
10  
20  
30  
*\  
```  
  
##  <a name="ostream_iterator"></a>  ostream_iterator::ostream_iterator  
 Constrói uma `ostream_iterator` que é inicializada e delimitada a gravar no fluxo de saída.  
  
```
ostream_iterator(
    ostream_type& _Ostr);

ostream_iterator(
    ostream_type& _Ostr,
    const CharType* _Delimiter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Ostr`  
 O fluxo de saída do tipo [ostream_iterator::ostream_type](#ostream_type) a ser iterado.  
  
 `_Delimiter`  
 O delimitador que é inserido no fluxo de saída entre os valores.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa o ponteiro de fluxo de saída com `&_Ostr`. O ponteiro de cadeia de caracteres delimitador designa uma cadeia de caracteres vazia.  
  
 O segundo construtor inicializa o ponteiro de fluxo de saída com `&_Ostr` e o ponteiro de cadeia de caracteres delimitador com `_Delimiter`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ostream_iterator_ostream_iterator.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // ostream_iterator for stream cout  
   ostream_iterator<int> intOut ( cout , "\n" );  
 *intOut = 10;  
   intOut++;  
 *intOut = 20;  
   intOut++;  
  
   int i;  
   vector<int> vec;  
   for ( i = 1 ; i < 7 ; ++i )  
   {  
      vec.push_back (  i );  
   }  
  
   // Write elements to standard output stream  
   cout << "Elements output without delimiter: ";  
   copy ( vec.begin ( ), vec.end ( ),  
          ostream_iterator<int> ( cout ) );  
   cout << endl;  
  
   // Write elements with delimiter " : " to output stream  
   cout << "Elements output with delimiter: ";  
   copy ( vec.begin ( ), vec.end ( ),  
          ostream_iterator<int> ( cout, " : " ) );  
   cout << endl;  
}  
\* Output:   
10  
20  
Elements output without delimiter: 123456  
Elements output with delimiter: 1 : 2 : 3 : 4 : 5 : 6 :   
*\  
```  
  
##  <a name="ostream_type"></a>  ostream_iterator::ostream_type  
 Um tipo que é fornecido para o tipo de fluxo do iterador.  
  
```
typedef basic_ostream<CharType, Traits> ostream_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo de [basic_ostream](../standard-library/basic-ostream-class.md)< `CharType`, `Traits`>, uma classe de fluxo da hierarquia iostream que define os objetos que podem ser usados para gravação.  
  
### <a name="example"></a>Exemplo  
  Consulte [ostream_iterator](#ostream_iterator) para ver um exemplo de como declarar e usar `ostream_type`.  
  
##  <a name="traits_type"></a>  ostream_iterator::traits_type  
 Um tipo que fornece o tipo de característica do caractere do iterador.  
  
```
typedef Traits traits_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **Traits**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ostream_iterator_traits_type.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // The following not OK, but are just the default values:  
   typedef ostream_iterator<int>::char_type CHT1;  
   typedef ostream_iterator<int>::traits_type CHTR1;  
  
   // ostream_iterator for stream cout  
   // with new line delimiter:  
    ostream_iterator<int, CHT1, CHTR1> intOut ( cout , "\n" );  
  
   // Standard iterator interface for writing  
   // elements to the output stream:  
   cout << "The integers written to output stream\n"  
        << "by intOut are:" << endl;  
 *intOut = 1;  
 *intOut = 10;  
 *intOut = 100;  
}  
\* Output:   
The integers written to output stream  
by intOut are:  
1  
10  
100  
*\  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<iterator>](../standard-library/iterator.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



