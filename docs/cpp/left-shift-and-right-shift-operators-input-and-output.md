---
title: Operadores de deslocamento de deslocamento à esquerda e direita (&gt; &gt; e &lt; &lt;) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- <<
- '>>'
dev_langs:
- C++
helpviewer_keywords:
- << operator [C++], with specific objects
- left shift operators [C++]
- right shift operators [C++]
- bitwise-shift operators [C++]
- '>> operator'
- shift operators [C++]
- operators [C++], shift
ms.assetid: 25fa0cbb-5fdd-4657-8745-b35f7d8f1606
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 50a177468795ae0e288910fa51192d9cc9a24502
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39403148"
---
# <a name="left-shift-and-right-shift-operators-gtgt-and-ltlt"></a>Operadores de deslocamento de deslocamento à esquerda e direita (&gt; &gt; e &lt; &lt;)
Os operadores shift bit a bit são o operador de deslocamento à direita (>>), que move os bits da *shift-Expression&lt;2}{3&gt;Additive* para a direita e o operador de deslocamento à esquerda (<<), que move os bits de *shift-expression* à esquerda. <sup>1</sup>  
  
## <a name="syntax"></a>Sintaxe  
  
> *SHIFT-Expression&lt;2}{3&gt;Additive* `<<` *additive-expression*  
> *SHIFT-Expression&lt;2}{3&gt;Additive* `>>` *additive-expression*  
  
## <a name="remarks"></a>Comentários  
  
> [!IMPORTANT]
> As descrições e exemplos a seguir são válidos no Windows para arquiteturas X86 e x64. A implementação de operadores shift para a esquerda e direita é significativamente diferente no Windows RT para dispositivos ARM. Para obter mais informações, consulte a seção "Operadores Shift" de [Hello ARM](http://blogs.msdn.com/b/vcblog/archive/2012/10/25/hello-arm-exploring-undefined-unspecified-and-implementation-defined-behavior-in-c.aspx) postagem de blog.  
  
## <a name="left-shifts"></a>Deslocamentos para a esquerda  
 O operador de deslocamento à esquerda faz com que os bits no *shift-Expression&lt;2}{3&gt;Additive* ser deslocados para a esquerda pelo número de posições especificado por *additive-expression*. As posições de bits que foram liberadas pela operação de deslocamento são preenchidas com zeros. Um deslocamento para a esquerda é um deslocamento lógico (os bits que são deslocados da extremidade são descartados, incluindo o bit de sinal). Para obter mais informações sobre os tipos de turnos de bit a bit, consulte [bit a bit turnos](http://en.wikipedia.org/wiki/Bitwise_shift).  
  
 O exemplo a seguir mostra operações de deslocamento para a esquerda usando números sem sinal. O exemplo a seguir mostra o que está acontecendo com os bit representando o valor como um conjunto de bits. Para obter mais informações, consulte [classe bitset](../standard-library/bitset-class.md).  
  
```cpp  
#include <iostream>  
#include <bitset>  
using namespace std;  
  
int main() {  
    unsigned short short1 = 4;      
    bitset<16> bitset1{short1};   // the bitset representation of 4  
    cout << bitset1 << endl;  // 0000000000000100  
  
    unsigned short short2 = short1 << 1;     // 4 left-shifted by 1 = 8  
    bitset<16> bitset2{short2};  
    cout << bitset2 << endl;  // 0000000000001000  
  
    unsigned short short3 = short1 << 2;     // 4 left-shifted by 2 = 16  
    bitset<16> bitset3{short3};  
    cout << bitset3 << endl;  // 0000000000010000  
}  
```  
  
 Se você deslocar um número com sinal para a esquerda de forma que o bit de sinal seja afetado, o resultado será indefinido. O exemplo a seguir mostra o que acontece no Visual C++ quando 1 bit é deslocado para a esquerda na posição de bit de sinal.  
  
```cpp  
#include <iostream>  
#include <bitset>  
using namespace std;  
  
int main() {  
    short short1 = 16384;      
    bitset<16> bitset1{short2};  
    cout << bitset1 << endl;  // 0100000000000000   
  
    short short3 = short1 << 1;  
    bitset<16> bitset3{short3};  // 16384 left-shifted by 1 = -32768  
    cout << bitset3 << endl;  // 100000000000000  
  
    short short4 = short1 << 14;  
    bitset<16> bitset4{short4};  // 4 left-shifted by 14 = 0  
    cout << bitset4 << endl;  // 000000000000000    
}  
```  
  
## <a name="right-shifts"></a>Deslocamentos para a direita  
 O operador de deslocamento para a direita faz com que o padrão de bits na *shift-Expression&lt;2}{3&gt;Additive* ser deslocados para a direita pelo número de posições especificado por *additive-expression*. Para números sem sinal, as posições de bits que foram liberadas pela operação de deslocamento são preenchidas com zeros. Para números com sinal, o bit de sinal é usado para preencher as posições de bit vagas. Ou seja, se o número for positivo, 0 será usado, e se o número for negativo, 1 será usado.  
  
> [!IMPORTANT]
> O resultado do deslocamento de um número negativo para a direita dependerá da implementação. Embora o Visual C++ use o bit de sinal para preencher as posições de bits vagas, não há garantia de que outras implementações também façam isso.  
  
 Este exemplo mostra operações de deslocamento para a direita usando números sem sinal:  
  
```cpp  
#include <iostream>  
#include <bitset>  
using namespace std;  
  
int main() {  
    unsigned short short11 = 1024;  
    bitset<16> bitset11{short11};  
    cout << bitset11 << endl;     // 0000010000000000  
  
    unsigned short short12 = short11 >> 1;  // 512  
    bitset<16> bitset12{short12};  
    cout << bitset12 << endl;     // 0000001000000000  
  
    unsigned short short13 = short11 >> 10;  // 1  
    bitset<16> bitset13{short13};  
    cout << bitset13 << endl;     // 0000000000000001  
  
    unsigned short short14 = short11 >> 11;  // 0  
    bitset<16> bitset14{short14};  
    cout << bitset14 << endl;     // 0000000000000000}  
}  
```  
  
 O próximo exemplo mostra operações de deslocamento para a direita com números positivos com sinal.  
  
```cpp  
#include <iostream>  
#include <bitset>  
using namespace std;  
  
int main() {  
    short short1 = 1024;  
    bitset<16> bitset1{short1};  
    cout << bitset1 << endl;     // 0000010000000000  
  
    short short2 = short1 >> 1;  // 512  
    bitset<16> bitset2{short2};  
    cout << bitset2 << endl;     // 0000001000000000  
  
    short short3 = short1 >> 11;  // 0  
    bitset<16> bitset3{short3};     
    cout << bitset3 << endl;     // 0000000000000000  
}  
```  
  
 O próximo exemplo mostra operações de deslocamento para a direita com inteiros negativos com sinal.  
  
```cpp  
#include <iostream>  
#include <bitset>  
using namespace std;  
  
int main() {  
    short neg1 = -16;  
    bitset<16> bn1{neg1};  
    cout << bn1 << endl;  // 1111111111110000  
  
    short neg2 = neg1 >> 1; // -8  
    bitset<16> bn2{neg2};  
    cout << bn2 << endl;  // 1111111111111000  
  
    short neg3 = neg1 >> 2; // -4  
    bitset<16> bn3{neg3};  
    cout << bn3 << endl;  // 1111111111111100  
  
    short neg4 = neg1 >> 4; // -1  
    bitset<16> bn4{neg4};      
    cout << bn4 << endl;  // 1111111111111111  
  
    short neg5 = neg1 >> 5; // -1   
    bitset<16> bn5{neg5};      
    cout << bn5 << endl;  // 1111111111111111  
}  
```  
  
## <a name="shifts-and-promotions"></a>Deslocamentos e promoções  
 As expressões em ambos os lados do operador shift devem ser tipos integrais. Promoções integrais são executadas de acordo com as regras descritas em [conversões padrão](standard-conversions.md). O tipo do resultado é o mesmo que o tipo de promovida *shift-Expression&lt;2}{3&gt;Additive*.  
  
 No exemplo a seguir, uma variável do tipo **char** é promovido para um **int**.  
  
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
 O resultado de uma operação de deslocamento é indefinido se *additive-expression* for negativo ou se *additive-expression* é maior que ou igual ao número de bits em (promovida)  *SHIFT-Expression&lt;2}{3&gt;Additive*. Nenhuma operação de deslocamento é executada se *additive-expression* é 0.  
  
```cpp  
#include <iostream>  
#include <bitset>  
using namespace std;  
  
int main() {  
    unsigned int int1 = 4;  
    bitset<32> b1{int1};  
    cout << b1 << endl;    // 00000000000000000000000000000100  
  
    unsigned int int2 = int1 << -3;  // C4293: '<<' : shift count negative or too big, undefined behavior  
    unsigned int int3 = int1 >> -3;  // C4293: '>>' : shift count negative or too big, undefined behavior  
  
    unsigned int int4 = int1 << 32;  // C4293: '<<' : shift count negative or too big, undefined behavior  
  
    unsigned int int5 = int1 >> 32;  // C4293: '>>' : shift count negative or too big, undefined behavior  
  
    unsigned int int6 = int1 << 0;  
    bitset<32> b6{int6};  
    cout << b6 << endl;    // 00000000000000000000000000000100 (no change)}  
}  
```  
  
## <a name="footnotes"></a>Notas de rodapé  
 1 Esta é a descrição dos operadores shift o ISO especificação c++11 (INCITS/ISO/IEC 14882-2011[2012]), seções 5.8.2 e 5.8.3.  
  
 O valor de `E1 << E2` é `E1` deslocado para a esquerda nas posições do bit `E2`; os bits vagos são preenchidos por zero. Se `E1` tem um tipo sem sinal, o valor do resultado é **E1 × 2**<sup>**E2**</sup>, módulo um a mais do que o valor máximo representável no tipo de resultado reduzido. Caso contrário, se `E1` tem um tipo com sinal e um valor positivo, e **E1 × 2**<sup>**E2** </sup> é representável no tipo sem sinal correspondente do tipo de resultado, em seguida, Esse valor, convertido para o tipo de resultado é o valor resultante; Caso contrário, o comportamento será indefinido.  
  
 O valor de `E1 >> E2` é `E1` é deslocado para a direita nas posições do bit `E2`. Se `E1` tem um tipo sem sinal ou se `E1` tem um tipo com sinal e um valor não negativo, o valor do resultado é a parte integral do quociente de **E1/2**<sup>**E2** </sup>. Se `E1` tiver um tipo com sinal e um valor negativo, o valor resultante será definido pela implementação.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)   
 [Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)