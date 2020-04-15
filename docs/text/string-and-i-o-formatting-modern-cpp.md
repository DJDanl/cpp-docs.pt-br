---
title: Cadeia de caracteres e formatação de E/S (C++ moderno)
description: Opções para I/O de seqüência formatado disponível no C++moderno.
ms.date: 05/30/2019
ms.topic: conceptual
ms.assetid: 3954e8de-a59b-4175-89c9-4ee842ab89ed
ms.openlocfilehash: a3fc93b0baf414759eb50c787c4057fb85dcb370
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375782"
---
# <a name="string-and-io-formatting-modern-c"></a>Cadeia de caracteres e formatação de E/S (C++ moderno)

C++ [ \<iostream>](../standard-library/iostream.md) classes, funções e operadores suportam I/O formatado de string. Por exemplo, o código a `cout` seguir mostra como definir para formatar um inteiro para a saída em hexadecimal. Primeiro, ele salva o estado atual para redefini-lo depois, `cout`porque uma vez que o estado de formato é passado para , ele permanece assim até mudar. Não se aplica apenas à única linha de código.

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

Esta abordagem é tipo segura e extensível, mas também é complexa e verbosa.

## <a name="alternative-format-options"></a>Opções de formato alternativo

Como alternativa, você `Boost.Format` pode usar a partir das bibliotecas Boost C++, mesmo que não seja padrão. Você pode baixar qualquer biblioteca Boost do site [do Boost.](https://www.boost.org/)

Algumas vantagens são: `Boost.Format`

- Seguro: Digite-safe e lança uma exceção para erros, por exemplo, a especificação de poucos ou muitos itens.

- Extensível: Funciona para qualquer tipo que possa ser transmitido.

- Conveniente: PADRÃO POSIX e strings de formato similar.

Embora `Boost.Format` seja construído em instalações [ \<de>c++ iostream,](../standard-library/iostream-programming.md) que são seguras e extensíveis, elas não são otimizadas para o desempenho. Quando você precisar de otimização de desempenho, considere C [printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md) e [sprintf](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md), que são rápidos e fáceis de usar. No entanto, eles não são extensíveis ou seguros contra vulnerabilidades. (Existem versões seguras, mas elas incorrem em uma pequena penalidade de desempenho. Para mais informações, consulte [printf_s, _printf_s_l, wprintf_s, _wprintf_s_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md) e [sprintf_s, _sprintf_s_l, swprintf_s, _swprintf_s_l](../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md)).

O código a seguir demonstra alguns dos recursos de formatação boost.

```cpp
    string s = str( format("%2% %2% %1%\n") % "world" % "hello" );
    // s contains "hello hello world"

    for( auto i = 0; i < names.size(); ++i )
        cout << format("%1% %2% %|40t|%3%\n") % first[i] % last[i] % tel[i];
    // Georges Benjamin Clemenceau             +33 (0) 123 456 789
    // Jean de Lattre de Tassigny              +33 (0) 987 654 321
```

## <a name="see-also"></a>Confira também

[Bem-vindo de volta ao C++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência de linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
[\<iostream>](../standard-library/iostream.md)<br/>
[\<limita>](../standard-library/limits.md)<br/>
[\<iomanip>](../standard-library/iomanip.md)
