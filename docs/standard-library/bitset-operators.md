---
title: Operadores &lt;bitset&gt;
ms.date: 11/04/2016
f1_keywords:
- bitset/std::operator&amp;
- bitset/std::operator&gt;&gt;
- bitset/std::operator&lt;&lt;
- bitset/std::operator^
- bitset/std::operator|
ms.assetid: 84fe6a13-6f6e-4cdc-bf8f-6f65ab1134d4
helpviewer_keywords:
- std::operator&amp; (bitset)
- std::operator&gt;&gt; (bitset)
- std::operator&lt;&lt; (bitset)
ms.openlocfilehash: cd1dfc035fde06c4be0f90e1bd11b231d64ab811
ms.sourcegitcommit: 4b0928a1a497648d0d327579c8262f25ed20d02e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2019
ms.locfileid: "72890140"
---
# <a name="ltbitsetgt-operators"></a>Operadores &lt;bitset&gt;

## <a name="op_amp">Operador </a>&amp;

Executa um `AND` bit a bit entre dois bitsets.

```cpp
template <size_t size>
bitset<size>
operator&(
    const bitset<size>& left,
    const bitset<size>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
O primeiro dos dois bitsets cujos respectivos elementos devem ser combinados com o `AND` bit a bit.

\ *à direita*
A segunda das duas valarrays cujos respectivos elementos devem ser combinados com o `AND` bit a bit.

### <a name="return-value"></a>Valor retornado

Um conjunto cujos elementos são o resultado da execução da operação `AND` nos elementos correspondentes da *esquerda* e da *direita*.

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

## <a name="op_lt_lt"></a>&lt; de&lt;do operador

Insere uma representação de texto da sequência de bits no fluxo de saída.

```
template <class CharType, class Traits, size_t N>
basic_ostream<CharType, Traits>& operator<<(
    basic_ostream<CharType, Traits>& ostr,
    const bitset<N>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
Um objeto do tipo **bitset\<N>** que deve ser inserido no fluxo de saída como uma cadeia de caracteres.

### <a name="return-value"></a>Valor retornado

Uma representação de texto da sequência de bits em `ostr`.

### <a name="remarks"></a>Comentários

A função de modelo sobrecarrega `operator<<`, permitindo que um conjunto seja escrito sem primeiro convertê-lo em uma cadeia de caracteres. A função de modelo é executada efetivamente:

`ostr << right.`[to_string](bitset-class.md)`<CharType, Traits, allocator<CharType>>()`

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

## <a name="op_gt_gt"></a>&gt; de&gt;do operador

Lê uma cadeia de caracteres de bit em um bitset.

```
template <class CharType, class Traits, size_t Bits>
basic_istream<CharType, Traits>& operator>> (
    basic_istream<CharType, Traits>& i_str,
    bitset<N>& right);
```

### <a name="parameters"></a>Parâmetros

\ *i_str*
A cadeia de caracteres que é inserida no fluxo de entrada a ser inserido no bitset.

\ *à direita*
O bitset que está recebendo os bits do fluxo de entrada.

### <a name="return-value"></a>Valor retornado

A função template retorna a cadeia de caracteres *i_str*.

### <a name="remarks"></a>Comentários

A função de modelo sobrecarrega `operator>>` para armazenar no conjunto *direito* do valor `bitset(str)`, em que `str` é um objeto do tipo [basic_string](basic-string-class.md)`< CharType, Traits, allocator< CharType > >&` extraído de *i_str*.

A função de modelo extrai elementos de *i_str* e os insere no conjunto até:

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

## <a name="op_xor"></a>operador ^

Executa um `EXCLUSIVE-OR` bit a bit entre dois bitsets.

```cpp
template <size_t size>
bitset<size>
operator^(
    const bitset<size>& left,
    const bitset<size>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
O primeiro dos dois bitsets cujos respectivos elementos devem ser combinados com o `EXCLUSIVE-OR` bit a bit.

\ *à direita*
A segunda das duas valarrays cujos respectivos elementos devem ser combinados com o `EXCLUSIVE-OR` bit a bit.

### <a name="return-value"></a>Valor retornado

Um conjunto cujos elementos são o resultado da execução da operação `EXCLUSIVE-OR` nos elementos correspondentes da *esquerda* e da *direita*.

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

## <a name="op_or"></a>operador&#124;

Executa um `OR` bit a bit entre dois bitsets.

```cpp
template <size_t size>
bitset<size>
operator|(
    const bitset<size>& left,
    const bitset<size>& right);
```

### <a name="parameters"></a>Parâmetros

\ *à esquerda*
O primeiro dos dois bitsets cujos respectivos elementos devem ser combinados com o `OR` bit a bit.

\ *à direita*
A segunda das duas valarrays cujos respectivos elementos devem ser combinados com o `OR` bit a bit.

### <a name="return-value"></a>Valor retornado

Um conjunto cujos elementos são o resultado da execução da operação `OR` nos elementos correspondentes da *esquerda* e da *direita*.

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
