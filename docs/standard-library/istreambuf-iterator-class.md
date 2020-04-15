---
title: Classe istreambuf_iterator
ms.date: 11/04/2016
f1_keywords:
- streambuf/std::istreambuf_iterator
- iterator/std::istreambuf_iterator::char_type
- iterator/std::istreambuf_iterator::int_type
- iterator/std::istreambuf_iterator::istream_type
- iterator/std::istreambuf_iterator::streambuf_type
- iterator/std::istreambuf_iterator::traits_type
- iterator/std::istreambuf_iterator::equal
helpviewer_keywords:
- std::istreambuf_iterator [C++]
- std::istreambuf_iterator [C++], char_type
- std::istreambuf_iterator [C++], int_type
- std::istreambuf_iterator [C++], istream_type
- std::istreambuf_iterator [C++], streambuf_type
- std::istreambuf_iterator [C++], traits_type
- std::istreambuf_iterator [C++], equal
ms.assetid: 39002da2-61a6-48a5-9d0c-5df8271f6038
ms.openlocfilehash: 80bca2160f2e60938e9d0c85557b11a273c23264
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363058"
---
# <a name="istreambuf_iterator-class"></a>Classe istreambuf_iterator

O modelo de classe istreambuf_iterator descreve um objeto iterador de entrada que extrai elementos de caracterede `basic_streambuf` \< um buffer de fluxo de entrada, que ele acessa através de um objeto que armazena, de ponteiro de tipo para **CharType**, **Traits**>.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType class Traits = char_traits <CharType>>
class istreambuf_iterator
: public iterator<input_iterator_tag, CharType, typename Traits ::off_type, CharType*, CharType&>
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo que representa o tipo de caractere para istreambuf_iterator.

*Traços*\
O tipo que representa o tipo de caractere para istreambuf_iterator. Esse argumento é opcional e o valor padrão é `char_traits`\< *CharType>.*

## <a name="remarks"></a>Comentários

A classe istreambuf_iterator deve atender aos requisitos de um iterador de entrada.

Após construir ou incrementar um objeto da classe istreambuf_iterator com um ponteiro armazenado não nulo, o objeto tenta, efetivamente, extrair e armazenar um objeto do tipo *CharType* do fluxo de entrada associado. A extração pode ser atrasada, no entanto, até que o objeto seja de fato desreferenciado ou copiado. Se a extração falhar, o objeto substitui eficientemente o ponteiro armazenado por um ponteiro nulo, criando um indicador de fim de sequência.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[istreambuf_iterator](#istreambuf_iterator)|Constrói uma `istreambuf_iterator` que é inicializada para ler caracteres do fluxo de entrada.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que é fornecido para o tipo de caractere do `ostreambuf_iterator`.|
|[int_type](#int_type)|Um tipo que fornece um tipo de inteiro para uma `istreambuf_iterator`.|
|[istream_type](#istream_type)|Um tipo que é fornecido para o tipo de fluxo da `istream_iterator`.|
|[streambuf_type](#streambuf_type)|Um tipo que é fornecido para o tipo de fluxo da `istreambuf_iterator`.|
|[traits_type](../standard-library/istream-iterator-class.md#traits_type)|Um tipo que fornece o tipo de característica do caractere da `istream_iterator`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Igual](#equal)|Testa a igualdade entre dois iteradores do buffer de fluxo de entrada.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador*](#op_star)|O operador de desreferenciamento retorna o próximo caractere no fluxo.|
|[operador++](#op_add_add)|Ou retorna o próximo caracteres do fluxo de entrada, ou copia o objeto antes de incrementá-lo e retorna a cópia.|
|[operador->](#op_arrow)|Retorna o valor de um membro, se houver.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="istreambuf_iteratorchar_type"></a><a name="char_type"></a>istreambuf_iterator:char_type

Um tipo que é fornecido para o tipo de caractere do `ostreambuf_iterator`.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo *CharType*.

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

## <a name="istreambuf_iteratorequal"></a><a name="equal"></a>istreambuf_iterator::igual

Testa a equivalência entre dois iteradores do buffer de fluxo de entrada.

```cpp
bool equal(const istreambuf_iterator<CharType, Traits>& right) const;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O iterador com relação ao qual verificar quanto à igualdade.

### <a name="return-value"></a>Valor retornado

**true** se os dois `istreambuf_iterator`s forem iteradores de final do fluxo ou se nenhum deles for um iterador de final do fluxo; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Um intervalo é `istreambuf_iterator` definido pela posição atual e pelo iterador de fim de fluxo, mas como todos os `equal` iteradores de fluxo não-end-of `istreambuf_iterator`são equivalentes sob a função de membro, não é possível definir quaisquer subintervalos usando s. Os operadores `==` e `!=` têm a mesma semântica.

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

## <a name="istreambuf_iteratorint_type"></a><a name="int_type"></a>istreambuf_iterator:int_type

Um tipo que fornece um tipo de inteiro para uma `istreambuf_iterator`.

```cpp
typedef typename traits_type::int_type int_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `Traits::int_type`.

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
/* Output:
The inttype1 = 100.
*/
```

## <a name="istreambuf_iteratoristream_type"></a><a name="istream_type"></a>istreambuf_iterator:istream_type

Um tipo que é fornecido para o tipo de fluxo da `istreambuf_iterator`.

```cpp
typedef basic_istream<CharType, Traits> istream_type;
```

### <a name="remarks"></a>Comentários

O tipo é `basic_istream` \< um sinônimo de **CharType**, **Traits**>.

### <a name="example"></a>Exemplo

Consulte [istreambuf_iterator](#istreambuf_iterator) para obter um exemplo de como declarar e usar `istream_type`.

## <a name="istreambuf_iteratoristreambuf_iterator"></a><a name="istreambuf_iterator"></a>istreambuf_iterator:istreambuf_iterator

Constrói istreambuf_iterator que é inicializado para ler caracteres do fluxo de entrada.

```cpp
istreambuf_iterator(streambuf_type* strbuf = 0) throw();
istreambuf_iterator(istream_type& _Istr) throw();
```

### <a name="parameters"></a>Parâmetros

*strbuf*\
O buffer do fluxo de entrada ao qual o `istreambuf_iterator` está sendo anexado.

*_Istr*\
O fluxo de entrada ao qual o `istreambuf_iterator` está sendo anexado.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa o ponteiro de tampão de fluxo de entrada com *strbuf*. O segundo construtor inicializa o ponteiro de fluxo de entrada com *_Istr*. `rdbuf`, e, eventualmente, tenta extrair e `CharType`armazenar um objeto do tipo .

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

## <a name="istreambuf_iteratoroperator"></a><a name="op_star"></a>istreambuf_iterator:operador*

O operador de desreferenciamento retorna o próximo caractere no fluxo.

```cpp
CharType operator*() const;
```

### <a name="return-value"></a>Valor retornado

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

## <a name="istreambuf_iteratoroperator"></a><a name="op_add_add"></a>istreambuf_iterator:operador++

Ou retorna o próximo caracteres do fluxo de entrada, ou copia o objeto antes de incrementá-lo e retorna a cópia.

```cpp
istreambuf_iterator<CharType, Traits>& operator++();
istreambuf_iterator<CharType, Traits> operator++(int);
```

### <a name="return-value"></a>Valor retornado

Um `istreambuf_iterator` ou uma referência a um `istreambuf_iterator`.

### <a name="remarks"></a>Comentários

O primeiro operador eventualmente tenta extrair e `CharType` armazenar um objeto de tipo do fluxo de entrada associado. O segundo operador faz uma cópia do objeto, incrementa o objeto e, em seguida, retorna a cópia.

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

## <a name="istreambuf_iteratoroperator-gt"></a><a name="op_arrow"></a>istreambuf_iterator::operador-&gt;

Retorna o valor de um membro, se houver.

```cpp
const Elem* operator->() const;
```

### <a name="return-value"></a>Valor retornado

O operador devolve ** & \* \*isso.**

## <a name="istreambuf_iteratorstreambuf_type"></a><a name="streambuf_type"></a>istreambuf_iterator:streambuf_type

Um tipo fornece o tipo de fluxo do istreambuf_iterator.

```cpp
typedef basic_streambuf<CharType, Traits> streambuf_type;
```

### <a name="remarks"></a>Comentários

O tipo é `basic_streambuf` \< um sinônimo de **CharType**, **Traits**>.

### <a name="example"></a>Exemplo

Consulte [istreambuf_iterator](#istreambuf_iterator) para obter um exemplo de como declarar e usar `istreambuf_type`.

## <a name="istreambuf_iteratortraits_type"></a><a name="traits_type"></a>istreambuf_iterator:traits_type

Um tipo que fornece o tipo de característica do caractere da `istream_iterator`.

```cpp
typedef Traits traits_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo *Traits*.

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

## <a name="see-also"></a>Confira também

[Estruturador de tempo](../standard-library/iterator-struct.md)\
[\<>do tempo](../standard-library/iterator.md)\
[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
