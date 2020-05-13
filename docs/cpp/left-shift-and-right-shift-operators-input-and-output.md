---
title: Operadores SHIFT esquerda e SHIFT direita (&gt; &gt; e &lt; &lt;)
ms.date: 08/13/2018
f1_keywords:
- <<
- '>>'
helpviewer_keywords:
- << operator [C++], with specific objects
- left shift operators [C++]
- right shift operators [C++]
- bitwise-shift operators [C++]
- '>> operator'
- shift operators [C++]
- operators [C++], shift
ms.assetid: 25fa0cbb-5fdd-4657-8745-b35f7d8f1606
ms.openlocfilehash: 2020c2dbbf8ff91ee692366f55c836be0b3dddb0
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825909"
---
# <a name="left-shift-and-right-shift-operators-gtgt-and-ltlt"></a>Operadores SHIFT esquerda e SHIFT direita (&gt; &gt; e &lt; &lt;)

Os operadores de alternância de bits bit a passo são o**&gt;** operador de deslocamento à direita (), que move o bit da *expressão Shift* para o lado direito e o**&lt;** operador esquerdo-SHIFT (), que move os bits da *expressão Shift* para a esquerda. <sup>1</sup>

## <a name="syntax"></a>Sintaxe

> `<<` *expressão aditiva* de *expressão Shift* -Expression\
> *shift-expression* `>>` *additive-expression*

## <a name="remarks"></a>Comentários

> [!IMPORTANT]
> As seguintes descrições e exemplos são válidos no Windows para arquiteturas x86 e x64. A implementação dos operadores de deslocamento para a esquerda e para a direita é significativamente diferente no Windows para dispositivos ARM. Para obter mais informações, consulte a seção "mover operadores" da postagem no blog do [Hello ARM](https://blogs.msdn.com/b/vcblog/archive/2012/10/25/hello-arm-exploring-undefined-unspecified-and-implementation-defined-behavior-in-c.aspx) .

## <a name="left-shifts"></a>Deslocamentos para a esquerda

O operador Left-Shift faz com que os bits na *expressão Shift* sejam deslocados para a esquerda pelo número de posições especificadas pela *expressão aditiva*. As posições de bits que foram liberadas pela operação de deslocamento são preenchidas com zeros. Um deslocamento para a esquerda é um deslocamento lógico (os bits que são deslocados da extremidade são descartados, incluindo o bit de sinal). Para obter mais informações sobre os tipos de turnos de bits, consulte [turnos de bits](https://en.wikipedia.org/wiki/Bitwise_shift).

O exemplo a seguir mostra operações de deslocamento para a esquerda usando números sem sinal. O exemplo a seguir mostra o que está acontecendo com os bit representando o valor como um conjunto de bits. Para obter mais informações, consulte [classe conjunto](../standard-library/bitset-class.md).

```cpp
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    unsigned short short1 = 4;
    bitset<16> bitset1{short1};   // the bitset representation of 4
    cout << bitset1 << endl;  // 0b00000000'00000100

    unsigned short short2 = short1 << 1;     // 4 left-shifted by 1 = 8
    bitset<16> bitset2{short2};
    cout << bitset2 << endl;  // 0b00000000'00001000

    unsigned short short3 = short1 << 2;     // 4 left-shifted by 2 = 16
    bitset<16> bitset3{short3};
    cout << bitset3 << endl;  // 0b00000000'00010000
}
```

Se você deslocar um número com sinal para a esquerda de forma que o bit de sinal seja afetado, o resultado será indefinido. O exemplo a seguir mostra o que acontece quando um 1 bit é deslocado para a posição do bit de sinal.

```cpp
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    short short1 = 16384;
    bitset<16> bitset1(short1);
    cout << bitset1 << endl;  // 0b01000000'00000000

    short short3 = short1 << 1;
    bitset<16> bitset3(short3);  // 16384 left-shifted by 1 = -32768
    cout << bitset3 << endl;  // 0b10000000'00000000

    short short4 = short1 << 14;
    bitset<16> bitset4(short4);  // 4 left-shifted by 14 = 0
    cout << bitset4 << endl;  // 0b00000000'00000000
}
```

## <a name="right-shifts"></a>Deslocamentos para a direita

O operador right-shift faz com que o padrão de bit na *expressão Shift* seja deslocado para a direita pelo número de posições especificadas pela *expressão aditiva*. Para números sem sinal, as posições de bits que foram liberadas pela operação de deslocamento são preenchidas com zeros. Para números com sinal, o bit de sinal é usado para preencher as posições de bit vagas. Ou seja, se o número for positivo, 0 será usado, e se o número for negativo, 1 será usado.

> [!IMPORTANT]
> O resultado do deslocamento de um número negativo para a direita dependerá da implementação. Embora o compilador do Microsoft C++ use o bit de sinal para preencher as posições de bits vagas, não há nenhuma garantia de que outras implementações também façam isso.

Este exemplo mostra operações de deslocamento para a direita usando números sem sinal:

```cpp
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    unsigned short short11 = 1024;
    bitset<16> bitset11{short11};
    cout << bitset11 << endl;     // 0b00000100'00000000

    unsigned short short12 = short11 >> 1;  // 512
    bitset<16> bitset12{short12};
    cout << bitset12 << endl;     // 0b00000010'00000000

    unsigned short short13 = short11 >> 10;  // 1
    bitset<16> bitset13{short13};
    cout << bitset13 << endl;     // 0b00000000'00000001

    unsigned short short14 = short11 >> 11;  // 0
    bitset<16> bitset14{short14};
    cout << bitset14 << endl;     // 0b00000000'00000000
}
```

O próximo exemplo mostra operações de deslocamento para a direita com números positivos com sinal.

```cpp
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    short short1 = 1024;
    bitset<16> bitset1(short1);
    cout << bitset1 << endl;     // 0b00000100'00000000

    short short2 = short1 >> 1;  // 512
    bitset<16> bitset2(short2);
    cout << bitset2 << endl;     // 0b00000010'00000000

    short short3 = short1 >> 11;  // 0
    bitset<16> bitset3(short3);
    cout << bitset3 << endl;     // 0b00000000'00000000
}
```

O próximo exemplo mostra operações de deslocamento para a direita com inteiros negativos com sinal.

```cpp
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    short neg1 = -16;
    bitset<16> bn1(neg1);
    cout << bn1 << endl;  // 0b11111111'11110000

    short neg2 = neg1 >> 1; // -8
    bitset<16> bn2(neg2);
    cout << bn2 << endl;  // 0b11111111'11111000

    short neg3 = neg1 >> 2; // -4
    bitset<16> bn3(neg3);
    cout << bn3 << endl;  // 0b11111111'11111100

    short neg4 = neg1 >> 4; // -1
    bitset<16> bn4(neg4);
    cout << bn4 << endl;  // 0b11111111'11111111

    short neg5 = neg1 >> 5; // -1
    bitset<16> bn5(neg5);
    cout << bn5 << endl;  // 0b11111111'11111111
}
```

## <a name="shifts-and-promotions"></a>Deslocamentos e promoções

As expressões em ambos os lados do operador shift devem ser tipos integrais. As promoções integrais são executadas de acordo com as regras descritas nas [conversões padrão](standard-conversions.md). O tipo do resultado é o mesmo que o tipo da *expressão Shift*promovida.

No exemplo a seguir, uma variável do tipo **Char** é promovida para um **int**.

```cpp
#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    char char1 = 'a';

    auto promoted1 = char1 << 1;   // 194
    cout << typeid(promoted1).name() << endl;  // int

    auto promoted2 = char1 << 10;  // 99328
    cout << typeid(promoted2).name() << endl;  // int
}
```

## <a name="additional-details"></a>Detalhes adicionais

O resultado de uma operação de deslocamento será indefinido se a *expressão aditiva* for negativa ou se a *expressão aditiva* for maior ou igual ao número de bits na *expressão Shift*(promovida). Nenhuma operação de deslocamento será executada se *a expressão aditiva* for 0.

```cpp
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    unsigned int int1 = 4;
    bitset<32> b1{int1};
    cout << b1 << endl;    // 0b00000000'00000000'00000000'00000100

    unsigned int int2 = int1 << -3;  // C4293: '<<' : shift count negative or too big, undefined behavior
    unsigned int int3 = int1 >> -3;  // C4293: '>>' : shift count negative or too big, undefined behavior
    unsigned int int4 = int1 << 32;  // C4293: '<<' : shift count negative or too big, undefined behavior
    unsigned int int5 = int1 >> 32;  // C4293: '>>' : shift count negative or too big, undefined behavior
    unsigned int int6 = int1 << 0;
    bitset<32> b6{int6};
    cout << b6 << endl;    // 0b00000000'00000000'00000000'00000100 (no change)
}
```

## <a name="footnotes"></a>Notas de rodapé

<sup>1</sup> a seguir está a descrição dos operadores de mudança na Especificação ISO 11 do C++ (INCITS/ISO/IEC 14882-2011 [2012]), Sections 5.8.2 e 5.8.3.

O valor de `E1 << E2` é `E1` deslocado para a esquerda nas posições do bit `E2`; os bits vagos são preenchidos por zero. Se `E1` tiver um tipo não assinado, o valor do resultado será **E1 × 2**<sup>**E2**</sup>, módulo reduzido um mais do que o valor máximo representável no tipo de resultado. Caso contrário, `E1` se o tiver um tipo assinado e um valor não negativo, e **E1 × 2**<sup>**E2**</sup> for representável no tipo não assinado correspondente do tipo de resultado, esse valor, convertido no tipo de resultado, será o valor resultante; caso contrário, o comportamento será indefinido.

O valor de `E1 >> E2` é `E1` é deslocado para a direita nas posições do bit `E2`. Se `E1` o tiver um tipo não assinado ou se `E1` tiver um tipo assinado e um valor não negativo, o valor do resultado será a parte integral do quociente de **E1/2**<sup>**E2**</sup>. Se `E1` tiver um tipo com sinal e um valor negativo, o valor resultante será definido pela implementação.

## <a name="see-also"></a>Confira também

[Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)<br/>
[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)
