---
title: Cadeia de caracteres e formatação de E/S (C++ moderno)
description: Opções de cadeia de caracteres formatada e/s disponíveis no moderno C++.
ms.date: 05/30/2019
ms.topic: conceptual
ms.assetid: 3954e8de-a59b-4175-89c9-4ee842ab89ed
ms.openlocfilehash: e22c745798109a2dbef82297c45256593823f806
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "66450508"
---
# <a name="string-and-io-formatting-modern-c"></a>Cadeia de caracteres e formatação de E/S (C++ moderno)

C++[ \<iostream >](../standard-library/iostream.md) classes, funções e operadores de suportam e/s de cadeia de caracteres formatada. Por exemplo, o código a seguir mostra como definir `cout` para formatar um número inteiro para a saída em hexadecimal. Primeiro, ele salva o estado atual para redefini-la posteriormente, pois uma vez o estado do formato é passado para `cout`, ele ficará dessa maneira até que seja alterado. Ele apenas não se aplica a uma linha de código.

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios state(nullptr);

    cout << "The answer in decimal is: " << 42 << endl;

    state.copyfmt(cout); // save current formatting
    cout << "In hex: 0x" // now load up a bunch of formatting modifiers
        << hex
        << uppercase
        << setw(8)
        << setfill('0')
        << 42            // the actual value we wanted to print out
        << endl;
    cout.copyfmt(state); // restore previous formatting
}
```

Essa abordagem é fortemente tipada e extensível, mas também é complexa e detalhada.

## <a name="alternative-format-options"></a>Opções de formato alternativo

Como alternativa, você pode usar `Boost.Format` do aumento C++ bibliotecas, mesmo que seja diferente do padrão. Você pode baixar qualquer biblioteca Boost do [Boost](https://www.boost.org/) site.

Algumas vantagens do `Boost.Format` são:

- Segurança: Segurança de tipo e lança uma exceção para erros, por exemplo, a especificação de muitos ou poucos itens.

- Extensível: Funciona para qualquer tipo que possa ser transmitido.

- Conveniente: Posix padrão e cadeias de caracteres de formato semelhantes.

Embora `Boost.Format` se baseia no C++ [ \<iostream >](../standard-library/iostream-programming.md) instalações, que são seguros e extensíveis, eles não são otimizados para desempenho. Quando você precisar de otimização do desempenho, considere a possibilidade de C [printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md) e [sprintf](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md), que são rápidos e fáceis de usar. No entanto, eles não são extensíveis nem seguros contra vulnerabilidades. (Existem versões seguras, mas eles incorrem em uma pequena penalidade de desempenho. Para obter mais informações, consulte [printf_s, printf_s_l, wprintf_s, wprintf_s_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md) e [sprintf_s, sprintf_s_l, swprintf_s, swprintf_s_l](../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md)).

O código a seguir demonstra alguns dos recursos de formatação de Boost.

```cpp
    string s = str( format("%2% %2% %1%\n") % "world" % "hello" );
    // s contains "hello hello world"

    for( auto i = 0; i < names.size(); ++i )
        cout << format("%1% %2% %|40t|%3%\n") % first[i] % last[i] % tel[i];
    // Georges Benjamin Clemenceau             +33 (0) 123 456 789
    // Jean de Lattre de Tassigny              +33 (0) 987 654 321
```

## <a name="see-also"></a>Consulte também

[Bem-vindo ao C++ (C++ moderno)](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)<br/>
[\<iostream>](../standard-library/iostream.md)<br/>
[\<limits>](../standard-library/limits.md)<br/>
[\<iomanip>](../standard-library/iomanip.md)
