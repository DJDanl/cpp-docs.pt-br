---
title: Recomendações para escolher entre funções e macros
ms.date: 11/04/2016
f1_keywords:
- c.functions
helpviewer_keywords:
- functions [CRT], vs. macros
- macros, vs. functions
ms.assetid: 18a633d6-cf1c-470c-a649-fa7677473e2b
ms.openlocfilehash: 234fcd8a0439240bc7585414254c5687dcb8f21b
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57749302"
---
# <a name="recommendations-for-choosing-between-functions-and-macros"></a>Recomendações para escolher entre funções e macros

A maioria das rotinas de biblioteca em tempo de execução da Microsoft são funções compiladas ou montadas, mas algumas rotinas são implementadas como macros. Quando um arquivo de cabeçalho declara uma função e uma versão de macro de uma rotina, a definição de macro tem precedência, porque ele sempre aparece depois da declaração de função. Quando você invoca uma rotina que é implementada como uma função e uma macro, você pode forçar o compilador a usar a versão da função de duas maneiras:

- Coloque o nome da rotina entre parênteses.

    ```C
    #include <ctype.h>
    a = _toupper(a);    // Use macro version of toupper.
    a = (_toupper)(a);  // Force compiler to use
                        // function version of toupper.
    ```

- "Indefina" a definição da macro com a diretiva `#undef`:

    ```C
    #include <ctype.h>
    #undef _toupper
    ```

Se você precisa escolher entre uma função e uma implementação de macro de uma rotina de biblioteca, considere as seguintes desvantagens:

- **Velocidade versus tamanho** O principal benefício do uso de macros é o tempo de execução mais rápido. Durante o pré-processamento, uma macro é expandida (substituída pela sua definição) embutida cada vez que for usada. Uma definição de função ocorre apenas uma vez, independentemente de quantas vezes ele é chamada. Macros podem aumentar o tamanho do código, mas não têm a sobrecarga associada às chamadas de função.

- **Função de avaliação** Uma função avalia para um endereço; uma macro, não. Assim, não é possível usar um nome de macro em contextos que exigem um ponteiro. Por exemplo, você pode declarar um ponteiro para uma função, mas não um ponteiro para uma macro.

- **Verificação de tipo** Ao declarar uma função, o compilador pode verificar os tipos de argumento. Como você não pode declarar uma macro, o compilador não pode verificar tipos de argumento de macro; embora ele possa verificar o número de argumentos que você passar para uma macro.

## <a name="see-also"></a>Consulte também

[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
