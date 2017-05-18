---
title: Classe istreambuf_iterator | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- istreambuf_iterator
- streambuf/std::istreambuf_iterator
- iterator/std::istreambuf_iterator::char_type
- iterator/std::istreambuf_iterator::int_type
- iterator/std::istreambuf_iterator::istream_type
- iterator/std::istreambuf_iterator::streambuf_type
- iterator/std::istreambuf_iterator::traits_type
- iterator/std::istreambuf_iterator::equal
dev_langs:
- C++
helpviewer_keywords:
- istreambuf_iterator class
ms.assetid: 39002da2-61a6-48a5-9d0c-5df8271f6038
caps.latest.revision: 19
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
ms.openlocfilehash: 942f61a053e77bf3d677f51cc30d39b5f4c76db6
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="istreambufiterator-class"></a>Classe istreambuf_iterator
A classe de modelo istreambuf_iterator descreve um objeto de iterador de entrada que extrai elementos de caractere de um buffer de fluxo de entrada, que acessa por meio de um objeto que armazena, do tipo ponteiro para `basic_streambuf`\< **CharType**, **Traits**>.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class CharType class Traits = char_traits <CharType>>  
class istreambuf_iterator 
: public iterator<input_iterator_tag, CharType, typename Traits ::off_type, CharType*, CharType&>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `CharType`  
 O tipo que representa o tipo de caractere para istreambuf_iterator.  
  
 `Traits`  
 O tipo que representa o tipo de caractere para istreambuf_iterator. Esse argumento é opcional e o valor padrão é `char_traits`\< *CharType>.*  
  
## <a name="remarks"></a>Comentários  
 A classe istreambuf_iterator deve atender aos requisitos de um iterador de entrada.  
  
 Após construir ou incrementar um objeto da classe istreambuf_iterator com um ponteiro armazenado não nulo, o objeto tenta, efetivamente, extrair e armazenar um objeto do tipo **CharType** do fluxo de entrada associado. A extração pode ser atrasada, no entanto, até que o objeto seja de fato desreferenciado ou copiado. Se a extração falhar, o objeto substitui eficientemente o ponteiro armazenado por um ponteiro nulo, criando um indicador de fim de sequência.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[istreambuf_iterator](#istreambuf_iterator)|Constrói uma `istreambuf_iterator` que é inicializada para ler caracteres do fluxo de entrada.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#char_type)|Um tipo que é fornecido para o tipo de caractere do `ostreambuf_iterator`.|  
|[int_type](#int_type)|Um tipo que fornece um tipo de inteiro para uma `istreambuf_iterator`.|  
|[istream_type](#istream_type)|Um tipo que é fornecido para o tipo de fluxo da `istream_iterator`.|  
|[streambuf_type](#streambuf_type)|Um tipo que é fornecido para o tipo de fluxo da `istreambuf_iterator`.|  
|[traits_type](../standard-library/istream-iterator-class.md#traits_type)|Um tipo que fornece o tipo de característica do caractere da `istream_iterator`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[equal](#equal)|Testa a igualdade entre dois iteradores do buffer de fluxo de entrada.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator*](#op_star)|O operador de desreferenciamento retorna o próximo caractere no fluxo.|  
|[operator++](#op_add_add)|Ou retorna o próximo caracteres do fluxo de entrada, ou copia o objeto antes de incrementá-lo e retorna a cópia.|  
|[operator->](#operator-_gt)|Retorna o valor de um membro, se houver.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<iterator>  
  
 **Namespace:** std  
  
##  <a name="char_type"></a>  istreambuf_iterator::char_type  
 Um tipo que é fornecido para o tipo de caractere do `ostreambuf_iterator`.  
  
```
typedef CharType char_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **CharType**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// istreambuf_iterator_char_type.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
#include <algorithm>  
  
int main( )  
{  
   using namespace std;  
  
   typedef istreambuf_iterator<char>::char_type CHT1;  
   typedef istreambuf_iterator<char>::traits_type CHTR1;  
  
   cout << "(Try the example: 'So many dots to be done'\n"  
        << " then an Enter key to insert into the output,\n"  
        << " & use a ctrl-Z Enter key combination to exit): ";  
  
   // istreambuf_iterator for input stream  
   istreambuf_iterator< CHT1, CHTR1> charInBuf ( cin );  
   ostreambuf_iterator<char> charOut ( cout );  
  
   // Used in conjunction with replace_copy algorithm  
   // to insert into output stream and replace spaces  
   // with dot-separators  
   replace_copy ( charInBuf , istreambuf_iterator<char>( ),  
        charOut , ' ' , '.' );  
}  
```  
  
##  <a name="equal"></a>  istreambuf_iterator::equal  
 Testa a equivalência entre dois iteradores do buffer de fluxo de entrada.  
  
```
bool equal(const istreambuf_iterator<CharType, Traits>& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O iterador com relação ao qual verificar quanto à igualdade.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os dois `istreambuf_iterator`s forem iteradores de final do fluxo ou se nenhum deles for um iterador de final do fluxo; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 Um intervalo é definido pelo `istreambuf_iterator` para a posição atual e pelo iterador de final de fluxo, mas como todos os iteradores que não são de final de fluxo são equivalentes segundo a função membro **equal**, não é possível definir subintervalos usando `istreambuf_iterator`s. Os operadores `==` e `!=` têm a mesma semântica.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// istreambuf_iterator_equal.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   cout << "(Try the example: 'Hello world!'\n"  
        << " then an Enter key to insert into the output,\n"  
        << " & use a ctrl-Z Enter key combination to exit): ";  
  
   istreambuf_iterator<char> charReadIn1 ( cin );  
   istreambuf_iterator<char> charReadIn2 ( cin );  
  
   bool b1 = charReadIn1.equal ( charReadIn2 );  
  
   if (b1)  
      cout << "The iterators are equal." << endl;  
   else  
      cout << "The iterators are not equal." << endl;  
}  
```  
  
##  <a name="int_type"></a>  istreambuf_iterator::int_type  
 Um tipo que fornece um tipo de inteiro para uma `istreambuf_iterator`.  
  
```
typedef typename traits_type::int_type int_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo de **Traits::int_type**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// istreambuf_iterator_int_type.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   istreambuf_iterator<char>::int_type inttype1 = 100;  
   cout << "The inttype1 = " << inttype1 << "." << endl;  
}  
\* Output:   
The inttype1 = 100.  
*\  
```  
  
##  <a name="istream_type"></a>  istreambuf_iterator::istream_type  
 Um tipo que é fornecido para o tipo de fluxo da `istreambuf_iterator`.  
  
```
typedef basic_istream<CharType, Traits> istream_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo de `basic_istream`\< **CharType**, **Traits**>.  
  
### <a name="example"></a>Exemplo  
  Consulte [istreambuf_iterator](#istreambuf_iterator) para obter um exemplo de como declarar e usar `istream_type`.  
  
##  <a name="istreambuf_iterator"></a>  istreambuf_iterator::istreambuf_iterator  
 Constrói istreambuf_iterator que é inicializado para ler caracteres do fluxo de entrada.  
  
```
istreambuf_iterator(streambuf_type* strbuf = 0) throw();
istreambuf_iterator(istream_type& _Istr) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `strbuf`  
 O buffer do fluxo de entrada ao qual o `istreambuf_iterator` está sendo anexado.  
  
 `_Istr`  
 O fluxo de entrada ao qual o `istreambuf_iterator` está sendo anexado.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa o ponteiro do buffer de fluxo de entrada com `strbuf`. O segundo construtor inicializa o ponteiro do buffer de fluxo de entrada com `_Istr`. `rdbuf` e eventualmente tenta extrair e armazenar um objeto do tipo **CharType**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// istreambuf_iterator_istreambuf_iterator.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <algorithm>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   // Following declarations will not compile:  
   istreambuf_iterator<char>::istream_type &istrm = cin;  
   istreambuf_iterator<char>::streambuf_type *strmbf = cin.rdbuf( );  
  
   cout << "(Try the example: 'Oh what a world!'\n"  
      << " then an Enter key to insert into the output,\n"  
      << " & use a ctrl-Z Enter key combination to exit): ";  
   istreambuf_iterator<char> charReadIn ( cin );  
   ostreambuf_iterator<char> charOut ( cout );  
  
   // Used in conjunction with replace_copy algorithm  
   // to insert into output stream and replace spaces  
   // with hyphen-separators  
   replace_copy ( charReadIn , istreambuf_iterator<char>( ),  
      charOut , ' ' , '-' );  
}  
```  
  
##  <a name="op_star"></a>  istreambuf_iterator::operator*  
 O operador de desreferenciamento retorna o próximo caractere no fluxo.  
  
```
CharType operator*() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O caractere seguinte no fluxo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// istreambuf_iterator_operator_deref.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   cout << "Type string of characters & enter to output it,\n"  
      << " with stream buffer iterators,(try: 'I'll be back.')\n"  
      << " repeat as many times as desired,\n"   
      << " then keystroke ctrl-Z Enter to exit program: ";  
   istreambuf_iterator<char> inpos ( cin );  
   istreambuf_iterator<char> endpos;  
   ostreambuf_iterator<char> outpos ( cout );  
   while ( inpos != endpos )  
   {  
 *outpos = *inpos;   //Put value of outpos equal to inpos  
      ++inpos;  
      ++outpos;  
   }  
}  
```  
  
##  <a name="op_add_add"></a>  istreambuf_iterator::operator++  
 Ou retorna o próximo caracteres do fluxo de entrada, ou copia o objeto antes de incrementá-lo e retorna a cópia.  
  
```
istreambuf_iterator<CharType, Traits>& operator++();
istreambuf_iterator<CharType, Traits> operator++(int);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `istreambuf_iterator` ou uma referência a um `istreambuf_iterator`.  
  
### <a name="remarks"></a>Comentários  
 O primeiro operador eventualmente tenta extrair e armazenar um objeto do tipo **CharType** do fluxo de entrada associado. O segundo operador faz uma cópia do objeto, incrementa o objeto e, em seguida, retorna a cópia.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// istreambuf_iterator_operator_incr.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
  
   cout << "Type string of characters & enter to output it,\n"  
      << " with stream buffer iterators,(try: 'I'll be back.')\n"  
      << " repeat as many times as desired,\n"   
      << " then keystroke ctrl-Z Enter to exit program: ";  
   istreambuf_iterator<char> inpos ( cin );  
   istreambuf_iterator<char> endpos;  
   ostreambuf_iterator<char> outpos ( cout );  
   while ( inpos != endpos )  
   {  
 *outpos = *inpos;  
      ++inpos;   //Increment istreambuf_iterator  
      ++outpos;  
   }  
}  
```  
  
##  <a name="istreambuf_iterator__operator-_gt"></a>  istreambuf_iterator::operator-&gt;  
 Retorna o valor de um membro, se houver.  
  
```
const Elem* operator->() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O operador retorna **&\*\*this**.  
  
##  <a name="streambuf_type"></a>  istreambuf_iterator::streambuf_type  
 Um tipo fornece o tipo de fluxo do istreambuf_iterator.  
  
```
typedef basic_streambuf<CharType, Traits> streambuf_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo de `basic_streambuf`\< **CharType**, **Traits**>.  
  
### <a name="example"></a>Exemplo  
  Consulte [istreambuf_iterator](#istreambuf_iterator) para ver um exemplo de como declarar e usar **istreambuf_type**.  
  
##  <a name="traits_type"></a>  istreambuf_iterator::traits_type  
 Um tipo que fornece o tipo de característica do caractere da `istream_iterator`.  
  
```
typedef Traits traits_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo **Traits**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// istreambuf_iterator_traits_type.cpp  
// compile with: /EHsc  
#include <iterator>  
#include <vector>  
#include <iostream>  
#include <algorithm>  
  
int main( )  
{  
   using namespace std;  
  
   typedef istreambuf_iterator<char>::char_type CHT1;  
   typedef istreambuf_iterator<char>::traits_type CHTR1;  
  
   cout << "(Try the example: 'So many dots to be done'\n"  
        << " then an Enter key to insert into the output,\n"  
        << " & use a ctrl-Z Enter key combination to exit): ";  
  
   // istreambuf_iterator for input stream  
   istreambuf_iterator< CHT1, CHTR1> charInBuf ( cin );  
   ostreambuf_iterator<char> charOut ( cout );  
  
   // Used in conjunction with replace_copy algorithm  
   // to insert into output stream and replace spaces  
   // with dot-separators  
   replace_copy ( charInBuf , istreambuf_iterator<char>( ),  
        charOut , ' ' , '.' );  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Struct iterator](../standard-library/iterator-struct.md)   
 [\<iterator>](../standard-library/iterator.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




