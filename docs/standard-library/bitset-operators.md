---
title: Operadores &lt;bitset&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- bitset/std::operator&amp;
- bitset/std::operator&gt;&gt;
- bitset/std::operator&lt;&lt;
- bitset/std::operator^
- bitset/std::operator|
dev_langs:
- C++
ms.assetid: 84fe6a13-6f6e-4cdc-bf8f-6f65ab1134d4
author: corob-msft
ms.author: corob
helpviewer_keywords:
- std::operator&amp; (bitset)
- std::operator&gt;&gt; (bitset)
- std::operator&lt;&lt; (bitset)
ms.workload:
- cplusplus
ms.openlocfilehash: 3056546e5a543c0058f789e293e0a63a3d53283a
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="ltbitsetgt-operators"></a>Operadores &lt;bitset&gt;

||||
|-|-|-|
|[operator&amp;](#op_amp)|[operator&gt;&gt;](#op_gt_gt)|[operator&lt;&lt;](#op_lt_lt)|
|[operator^](#op_xor)|[operator|](#op_or)|

## <a name="op_amp"></a>  operator&amp;

Executa um `AND` bit a bit entre dois bitsets.

```cpp
template <size_t size>
bitset<size>
operator&(
    const bitset<size>& left,
    const bitset<size>& right);
```

### <a name="parameters"></a>Parâmetros

`left` O primeiro de dois bitsets cujos elementos do respectivos devem ser combinadas com o bit a bit `AND`.

`right` O segundo de dois valarrays cujos elementos do respectivos devem ser combinadas com o bit a bit `AND`.

### <a name="return-value"></a>Valor de retorno

Um bitset cujos elementos são o resultado da execução da operação `AND` nos elementos correspondentes de `left` e `right`.

### <a name="example"></a>Exemplo

```cpp
// bitset_and.cpp
// compile with: /EHsc
#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   bitset<4> b1 ( string("0101") );
   bitset<4> b2 ( string("0011") );
   bitset<4> b3 = b1 & b2;
   cout << "bitset 1: " << b1 << endl;
   cout << "bitset 2: " << b2 << endl;
   cout << "bitset 3: " << b3 << endl;
}
```

```Output
bitset 1: 0101
bitset 2: 0011
bitset 3: 0001
```

## <a name="op_lt_lt"></a>  operator&lt;&lt;

Insere uma representação de texto da sequência de bits no fluxo de saída.

```

template <class CharType, class Traits, size_t N>
basic_ostream<CharType, Traits>& operator<<(
    basic_ostream<CharType, Traits>& ostr,
    const bitset<N>& right);
```

### <a name="parameters"></a>Parâmetros

`right` Um objeto do tipo **bitset\<N >** que é inserido no fluxo de saída como uma cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Uma representação de texto da sequência de bits em **ostr**.

### <a name="remarks"></a>Comentários

As função de modelo sobrecarrega **operator<<**, permitindo que um bitset seja gravado primeiro ser convertido em uma cadeia de caracteres. A função de modelo é executada efetivamente:

**ostr** << _ *Right*. [to_string](bitset-class.md) < **CharType**, **Traits**, **allocator**\< **CharType**> > ( )

### <a name="example"></a>Exemplo

```cpp
// bitset_op_insert.cpp
// compile with: /EHsc
#include <bitset>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;

   bitset<5> b1 ( 9 );

   // bitset inserted into output stream directly
   cout << "The ordered set of bits in the bitset<5> b1(9)"
        << "\n can be output with the overloaded << as: ( "
        << b1 << " )" << endl;

   // Compare converting bitset to a string before
   // inserting it into the output steam
   string s1;
   s1 =  b1.template to_string<char,
      char_traits<char>, allocator<char> >( );
   cout << "The string returned from the bitset b1"
        << "\n by the member function to_string( ) is: "
        << s1 << "." << endl;
}
```

## <a name="op_gt_gt"></a>  operator&gt;&gt;

Lê uma cadeia de caracteres de bit em um bitset.

```

template <class CharType, class Traits, size_t Bits>
basic_istream<CharType, Traits>& operator>> (
    basic_istream<CharType, Traits>&
_Istr,
    bitset<N>&
    right);
```

### <a name="parameters"></a>Parâmetros

`_Istr` A cadeia de caracteres que é inserida no fluxo de entrada a ser inserido no bitset.

`right` Bitset que está recebendo os bits do fluxo de entrada.

### <a name="return-value"></a>Valor de retorno

A função de modelo retorna a cadeia de caracteres `_Istr`.

### <a name="remarks"></a>Comentários

A função de modelo sobrecarrega **operator>>** para armazenar no bitset_ *Right* o valor bitset( `str`), em que `str` é um objeto do tipo [basic_string](basic-string-class.md) < **CharType**, **Traits**, **allocator** \< **CharType**> > **&**  extraídos de `_Istr`.

A função de modelo extrai elementos de `_Istr` e insere-os em um bitset até:

- Todos os elementos do bit terem sido extraídos do fluxo de entrada e armazenados no bitset.

- O bitset ser preenchido com bits do fluxo de entrada.

- Ser localizado um elemento de entrada que não seja 0 nem 1.

### <a name="example"></a>Exemplo

```cpp
#include <bitset>
#include <iostream>
#include <string>

using namespace std;
int main()
{

   bitset<5> b1;
   cout << "Enter string of (0 or 1) bits for input into bitset<5>.\n"
        << "Try bit string of length less than or equal to 5,\n"
        << " (for example: 10110): ";
   cin >>  b1;

   cout << "The ordered set of bits entered from the "
        << "keyboard\n has been input into bitset<5> b1 as: ( "
        << b1 << " )" << endl;

   // Truncation due to longer string of bits than length of bitset
   bitset<2> b3;
   cout << "Enter string of bits (0 or 1) for input into bitset<2>.\n"
        << " Try bit string of length greater than 2,\n"
        << " (for example: 1011): ";
   cin >>  b3;

   cout << "The ordered set of bits entered from the "
        << "keyboard\n has been input into bitset<2> b3 as: ( "
        << b3 << " )" << endl;

   // Flushing the input stream
   char buf[100];
   cin.getline(&buf[0], 99);

   // Truncation with non-bit value
   bitset<5> b2;
   cout << "Enter a string for input into  bitset<5>.\n"
        << " that contains a character than is NOT a 0 or a 1,\n "
        << " (for example: 10k01): ";
   cin >>  b2;

   cout << "The string entered from the keyboard\n"
        << " has been input into bitset<5> b2 as: ( "
        << b2 << " )" << endl;
}
```

## <a name="op_xor"></a> operator^

Executa um `EXCLUSIVE-OR` bit a bit entre dois bitsets.

```cpp
template <size_t size>
bitset<size>
operator^(
    const bitset<size>& left,
    const bitset<size>& right);
```

### <a name="parameters"></a>Parâmetros

`left` O primeiro de dois bitsets cujos elementos do respectivos devem ser combinadas com o bit a bit `EXCLUSIVE-OR`.

`right` O segundo de dois valarrays cujos elementos do respectivos devem ser combinadas com o bit a bit `EXCLUSIVE-OR`.

### <a name="return-value"></a>Valor de retorno

Um bitset cujos elementos são o resultado da execução da operação `EXCLUSIVE-OR` nos elementos correspondentes de `left` e `right`.

### <a name="example"></a>Exemplo

```cpp
// bitset_xor.cpp
// compile with: /EHsc
#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   bitset<4> b1 ( string("0101") );
   bitset<4> b2 ( string("0011") );
   bitset<4> b3 = b1 ^ b2;
   cout << "bitset 1: " << b1 << endl;
   cout << "bitset 2: " << b2 << endl;
   cout << "bitset 3: " << b3 << endl;
}
```

```Output
bitset 1: 0101
bitset 2: 0011
bitset 3: 0110
```

## <a name="op_or"></a>  operador |

Executa um `OR` bit a bit entre dois bitsets.

```cpp
template <size_t size>
bitset<size>
operator|(
    const bitset<size>& left,
    const bitset<size>& right);
```

### <a name="parameters"></a>Parâmetros

`left` O primeiro de dois bitsets cujos elementos do respectivos devem ser combinadas com o bit a bit `OR`.

`right` O segundo de dois valarrays cujos elementos do respectivos devem ser combinadas com o bit a bit `OR`.

### <a name="return-value"></a>Valor de retorno

Um bitset cujos elementos são o resultado da execução da operação `OR` nos elementos correspondentes de `left` e `right`.

### <a name="example"></a>Exemplo

```cpp
// bitset_or.cpp
// compile with: /EHsc
#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   bitset<4> b1 ( string("0101") );
   bitset<4> b2 ( string("0011") );
   bitset<4> b3 = b1 | b2;
   cout << "bitset 1: " << b1 << endl;
   cout << "bitset 2: " << b2 << endl;
   cout << "bitset 3: " << b3 << endl;
}
```

```Output
bitset 1: 0101
bitset 2: 0011
bitset 3: 0111
```

## <a name="see-also"></a>Consulte também

[\<bitset>](../standard-library/bitset.md)<br/>
