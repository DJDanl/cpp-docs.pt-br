---
title: Classe ostreambuf_iterator
ms.date: 11/04/2016
f1_keywords:
- streambuf/std::ostreambuf_iterator
- iterator/std::ostreambuf_iterator::char_type
- iterator/std::ostreambuf_iterator::ostream_type
- iterator/std::ostreambuf_iterator::streambuf_type
- iterator/std::ostreambuf_iterator::traits_type
- iterator/std::ostreambuf_iterator::failed
helpviewer_keywords:
- std::ostreambuf_iterator [C++]
- std::ostreambuf_iterator [C++], char_type
- std::ostreambuf_iterator [C++], ostream_type
- std::ostreambuf_iterator [C++], streambuf_type
- std::ostreambuf_iterator [C++], traits_type
- std::ostreambuf_iterator [C++], failed
ms.assetid: dad1e624-2f45-4e94-8887-a885e95f9071
ms.openlocfilehash: be4421a7646756da5687ebc9b98f18daf4845809
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687211"
---
# <a name="ostreambuf_iterator-class"></a>Classe ostreambuf_iterator

O modelo de classe ostreambuf_iterator descreve um objeto de iterador de saída que grava elementos de caractere sucessivos no fluxo de saída com o operador de extração **> >** . As `ostreambuf_iterator`s são diferentes da [Classe ostream_iterator](../standard-library/ostream-iterator-class.md) por terem caracteres em vez de um tipo genérico no tipo de objeto que está sendo inserido no fluxo de saída.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType = char class Traits = char_traits <CharType>>
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *CharType*
O tipo que representa o tipo de caractere para ostreambuf_iterator. Esse argumento é opcional e o valor padrão é **Char**.

@No__t_1 de *características*
O tipo que representa o tipo de caractere para ostreambuf_iterator. Esse argumento é opcional e o valor padrão é `char_traits`\< *CharType>.*

## <a name="remarks"></a>Comentários

A classe ostreambuf_iterator deve atender aos requisitos de um iterador de saída. Os algoritmos podem ser gravados diretamente nos fluxos de saída usando um `ostreambuf_iterator`. A classe fornece um iterador de fluxo de nível baixo que permite acesso ao fluxo de E/S bruto (não formatado) na forma de caracteres e a capacidade de ignorar o buffer e as conversões de caracteres associadas aos iteradores de fluxo de nível alto.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[ostreambuf_iterator](#ostreambuf_iterator_ostreambuf_iterator)|Constrói uma `ostreambuf_iterator` que é inicializada para gravar caracteres no fluxo de saída.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que é fornecido para o tipo de caractere do `ostreambuf_iterator`.|
|[ostream_type](#ostreambuf_iterator_ostream_type)|Um tipo que é fornecido para o tipo de fluxo da `ostream_iterator`.|
|[streambuf_type](#streambuf_type)|Um tipo que é fornecido para o tipo de fluxo da `ostreambuf_iterator`.|
|[traits_type](#traits_type)|Um tipo que fornece o tipo de característica do caractere da `ostream_iterator`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[failed](#failed)|Testa a falha de uma inserção no buffer do fluxo de saída.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator*](#op_star)|Operador de desreferenciamento usado para implementar a expressão do iterador de saída \* `i`  =  `x`.|
|[operator++](#op_add_add)|Um operador de incremento não funcional que retorna uma `ostreambuf_iterator` para o mesmo objeto que foi tratado antes de a operação ser chamada.|
|[operator=](#op_eq)|O operador insere um caractere no buffer do fluxo associado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<iterator>

**Namespace:** std

## <a name="char_type"></a>  ostreambuf_iterator::char_type

Um tipo que é fornecido para o tipo de caractere do `ostreambuf_iterator`.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `CharType`.

### <a name="example"></a>Exemplo

```cpp
// ostreambuf_iterator_char_type.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   typedef ostreambuf_iterator<char>::char_type CHT1;
   typedef ostreambuf_iterator<char>::traits_type CHTR1;

   // ostreambuf_iterator for stream cout
   // with new line delimiter:
    ostreambuf_iterator< CHT1, CHTR1> charOutBuf ( cout );

   // Standard iterator interface for writing
   // elements to the output streambuf:
   cout << "The characters written to the output stream\n"
        << " by charOutBuf are: ";
*charOutBuf = 'O';
   charOutBuf++;
*charOutBuf = 'U';
   charOutBuf++;
*charOutBuf = 'T';
   charOutBuf++;
   cout << "." << endl;
}
/* Output:
The characters written to the output stream
by charOutBuf are: OUT.
*/
```

## <a name="failed"></a>  ostreambuf_iterator::failed

Testa a falha de uma inserção no buffer do fluxo de saída.

```cpp
bool failed() const throw();
```

### <a name="return-value"></a>Valor retornado

**true** se nenhuma inserção no buffer de fluxo de saída falhou anteriormente; caso contrário, **false**.

### <a name="remarks"></a>Comentários

A função de membro retorna **true** se, em qualquer uso anterior do membro `operator=`, a chamada para **subf**_-> `sputc` retornou **eof**.

### <a name="example"></a>Exemplo

```cpp
// ostreambuf_iterator_failed.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   // ostreambuf_iterator for stream cout
   ostreambuf_iterator<char> charOut ( cout );

*charOut = 'a';
   charOut ++;
*charOut  = 'b';
   charOut ++;
*charOut = 'c';
   cout << " are characters output individually." << endl;

   bool b1 = charOut.failed ( );
   if (b1)
       cout << "At least one insertion failed." << endl;
   else
       cout << "No insertions failed." << endl;
}
/* Output:
abc are characters output individually.
No insertions failed.
*/
```

## <a name="op_star"></a>operador ostreambuf_iterator:: Operator \*

Um operador de desreferenciamento não funcional usado para implementar a expressão do iterador de saída \* *i* = *x*.

```cpp
ostreambuf_iterator<CharType, Traits>& operator*();
```

### <a name="return-value"></a>Valor retornado

O objeto do iterador ostreambuf.

### <a name="remarks"></a>Comentários

Este operador funciona apenas na expressão do iterador de saída \* *i* = *x* para gerar caracteres de saída para o buffer de fluxo. Aplicado a um iterador ostreambuf, ele retorna o iterador; **\*iter** retorna **iter**,

### <a name="example"></a>Exemplo

```cpp
// ostreambuf_iterator_op_deref.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   // ostreambuf_iterator for stream cout
   // with new line delimiter
   ostreambuf_iterator<char> charOutBuf ( cout );

   // Standard iterator interface for writing
   // elements to the output stream
   cout << "Elements written to output stream:" << endl;
*charOutBuf = 'O';
   charOutBuf++;   // no effect on iterator position
*charOutBuf = 'U';
*charOutBuf = 'T';
}
/* Output:
Elements written to output stream:
OUT
*/
```

## <a name="op_add_add"></a>  ostreambuf_iterator::operator++

Um operador de incremento não funcional que retorna um iterador ostream para o mesmo caractere que foi tratado antes de a operação ser chamada.

```cpp
ostreambuf_iterator<CharType, Traits>& operator++();
ostreambuf_iterator<CharType, Traits>& operator++(int);
```

### <a name="return-value"></a>Valor retornado

Uma referência ao caractere originalmente resolvido ou a um objeto definido pela implementação que pode ser convertido em `ostreambuf_iterator`\< **CharType**, **Traits**>.

### <a name="remarks"></a>Comentários

O operador usado para implementar a expressão do iterador de saída \* *i* = *x*.

### <a name="example"></a>Exemplo

```cpp
// ostreambuf_iterator_op_incr.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   // ostreambuf_iterator for stream cout
   // with new line delimiter
   ostreambuf_iterator<char> charOutBuf ( cout );

   // Standard iterator interface for writing
   // elements to the output stream
   cout << "Elements written to output stream:" << endl;
*charOutBuf = 'O';
   charOutBuf++;      // No effect on iterator position
*charOutBuf = 'U';
*charOutBuf = 'T';
}
/* Output:
Elements written to output stream:
OUT
*/
```

## <a name="op_eq"></a>  ostreambuf_iterator::operator=

O operador insere um caractere no buffer do fluxo associado.

```cpp
ostreambuf_iterator<CharType, Traits>& operator=(CharType _Char);
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *_Char*
O caractere a ser inserido no buffer de fluxo.

### <a name="return-value"></a>Valor retornado

Uma referência para o caractere inserido no buffer de fluxo.

### <a name="remarks"></a>Comentários

O operador de atribuição usado para implementar a expressão do iterador de saída \* *i* = *x* para gravação em um fluxo de saída.

### <a name="example"></a>Exemplo

```cpp
// ostreambuf_iterator_op_assign.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   // ostreambuf_iterator for stream cout
   // with new line delimiter
   ostreambuf_iterator<char> charOutBuf ( cout );

   // Standard iterator interface for writing
   // elements to the output stream
   cout << "Elements written to output stream:" << endl;
*charOutBuf = 'O';
   charOutBuf++;      // No effect on iterator position
*charOutBuf = 'U';
*charOutBuf = 'T';
}
/* Output:
Elements written to output stream:
OUT
*/
```

## <a name="ostreambuf_iterator_ostreambuf_iterator"></a>  ostreambuf_iterator::ostreambuf_iterator

Constrói uma `ostreambuf_iterator` que é inicializada para gravar caracteres no fluxo de saída.

```cpp
ostreambuf_iterator(streambuf_type* strbuf) throw();
ostreambuf_iterator(ostream_type& Ostr) throw();
```

### <a name="parameters"></a>Parâmetros

\ *strbuf*
O objeto de streambuf de saída usado para inicializar o ponteiro de buffer do fluxo de saída.

@No__t_1 *OSTR*
O objeto do fluxo de saída usado para inicializar o ponteiro de buffer do fluxo de saída.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa o ponteiro Stream-buffer de saída com *strbuf*.

O segundo construtor inicializa o ponteiro do buffer de fluxo de saída com `Ostr`. `rdbuf` O ponteiro armazenado não deve ser um ponteiro nulo.

### <a name="example"></a>Exemplo

```cpp
// ostreambuf_iteratorOstreambuf_iterator.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   // ostreambuf_iterator for stream cout
   ostreambuf_iterator<char> charOut ( cout );

*charOut = 'O';
   charOut ++;
*charOut  = 'U';
   charOut ++;
*charOut = 'T';
   cout << " are characters output individually." << endl;

   ostreambuf_iterator<char> strOut ( cout );
   string str = "These characters are being written to the output stream.\n ";
   copy ( str.begin ( ), str. end ( ), strOut );
}
/* Output:
OUT are characters output individually.
These characters are being written to the output stream.
*/
```

## <a name="ostreambuf_iterator_ostream_type"></a>  ostreambuf_iterator::ostream_type

Um tipo que é fornecido para o tipo de fluxo da `ostream_iterator`.

```cpp
typedef basicOstream<CharType, Traits> ostream_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de `basicOstream`\< **CharType**, **Traits**>

### <a name="example"></a>Exemplo

Consulte [ostreambuf_iterator](#ostreambuf_iterator_ostreambuf_iterator) para ver um exemplo de como declarar e usar `ostream_type`.

## <a name="streambuf_type"></a>  ostreambuf_iterator::streambuf_type

Um tipo que é fornecido para o tipo de fluxo da `ostreambuf_iterator`.

```cpp
typedef basic_streambuf<CharType, Traits> streambuf_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para `basic_streambuf` \< **CharType**, **características**>, uma classe de fluxo para buffers de e/s que se torna `streambuf` quando especializado para **caracteres de tipo de**caractere.

### <a name="example"></a>Exemplo

Consulte [ostreambuf_iterator](#ostreambuf_iterator_ostreambuf_iterator) para ver um exemplo de como declarar e usar `streambuf_type`.

## <a name="traits_type"></a>  ostreambuf_iterator::traits_type

Um tipo que fornece o tipo de característica do caractere da `ostream_iterator`.

```cpp
typedef Traits traits_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Traits`.

### <a name="example"></a>Exemplo

```cpp
// ostreambuf_iterator_traits_type.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   typedef ostreambuf_iterator<char>::char_type CHT1;
   typedef ostreambuf_iterator<char>::traits_type CHTR1;

   // ostreambuf_iterator for stream cout
   // with new line delimiter:
    ostreambuf_iterator< CHT1, CHTR1> charOutBuf ( cout );

   // Standard iterator interface for writing
   // elements to the output streambuf:
   cout << "The characters written to the output stream\n"
        << " by charOutBuf are: ";
*charOutBuf = 'O';
   charOutBuf++;
*charOutBuf = 'U';
   charOutBuf++;
*charOutBuf = 'T';
   charOutBuf++;
   cout << "." << endl;
}
/* Output:
The characters written to the output stream
by charOutBuf are: OUT.
*/
```

## <a name="see-also"></a>Consulte também

[\<iterator>](../standard-library/iterator.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
