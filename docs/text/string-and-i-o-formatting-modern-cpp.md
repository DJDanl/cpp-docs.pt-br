---
title: Cadeia de caracteres e formatação de E/S (C++ moderno)
description: Opções para e/s de cadeia de caracteres formatada C++disponíveis em moderno.
ms.date: 05/30/2019
ms.topic: conceptual
ms.assetid: 3954e8de-a59b-4175-89c9-4ee842ab89ed
ms.openlocfilehash: 7ea858a8a8126d3754783edee0dd3ea5409e5f73
ms.sourcegitcommit: 6ddfb8be5e5923a4d90a2c0f93f76a27ce7ac299
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/06/2019
ms.locfileid: "74898824"
---
# <a name="string-and-io-formatting-modern-c"></a>Cadeia de caracteres e formatação de E/S (C++ moderno)

C++\<classes, funções e operadores do [iostream >](../standard-library/iostream.md) dão suporte a e/s de cadeia de caracteres formatada. Por exemplo, o código a seguir mostra como definir `cout` para formatar um inteiro para saída em hexadecimal. Primeiro, ele salva o estado atual para redefini-lo posteriormente, porque depois que o estado de formato é passado para `cout`, ele permanece dessa maneira até ser alterado. Ele não se aplica apenas a uma linha de código.

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

Essa abordagem é de tipo seguro e extensível, mas também é complexa e detalhada.

## <a name="alternative-format-options"></a>Opções de formato alternativo

Como alternativa, você pode usar `Boost.Format` das bibliotecas Boost C++ , embora não seja o padrão. Você pode baixar qualquer biblioteca de aumento do site de [aumento](https://www.boost.org/) .

Algumas vantagens do `Boost.Format` são:

- Seguro: tipo seguro e gera uma exceção para erros, por exemplo, a especificação de poucos ou muitos itens.

- Extensível: funciona para qualquer tipo que possa ser transmitido.

- Conveniente: o POSIX padrão e as cadeias de caracteres de formato semelhantes.

Embora `Boost.Format` seja criado em C++ [\<instalações de > iostream](../standard-library/iostream-programming.md) , que são seguras e extensíveis, elas não são otimizadas para desempenho. Quando você precisar de otimização de desempenho, considere C [printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md) e [sprintf](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md), que são rápidas e fáceis de usar. No entanto, elas não são extensíveis ou seguras contra vulnerabilidades. (Existem versões seguras, mas elas têm uma pequena penalidade de desempenho.) Para obter mais informações, consulte [printf_s, _printf_s_l, wprintf_s, _wprintf_s_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md) e [sprintf_s, _sprintf_s_l](../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md), swprintf_s, _swprintf_s_l).

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

[Bem-vindo de volta paraC++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)<br/>
[\<iostream>](../standard-library/iostream.md)<br/>
[\<limits>](../standard-library/limits.md)<br/>
[\<iomanip>](../standard-library/iomanip.md)
