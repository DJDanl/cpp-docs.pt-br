---
title: Misturando exceções C (estruturadas) e C++
ms.date: 08/14/2018
helpviewer_keywords:
- exceptions [C++], mixed C and C++
- C++ exception handling, mixed-language
- structured exception handling [C++], mixed C and C++
- catch keyword [C++], mixed
- try-catch keyword [C++], mixed-language
ms.assetid: a149154e-36dd-4d1a-980b-efde2a563a56
ms.openlocfilehash: 72ddde9bc284a005c77694d599a8e9a3908cb2d0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233685"
---
# <a name="mixing-c-structured-and-c-exceptions"></a>Misturando exceções C (estruturadas) e C++

Se você quiser escrever código portátil, o uso de SEH (manipulação de exceção estruturada) em um programa C++ não é recomendado. No entanto, às vezes você pode querer compilar usando [/EHA](../build/reference/eh-exception-handling-model.md) e misturar exceções estruturadas e código-fonte C++ e precisa de algum recurso para lidar com os dois tipos de exceções. Como um manipulador de exceção estruturado não tem nenhum conceito de objetos ou exceções tipadas, ele não pode tratar exceções geradas pelo código C++. No entanto, os **`catch`** manipuladores C++ podem lidar com exceções estruturadas. A sintaxe de manipulação de exceção do C++ ( **`try`** , **`throw`** , **`catch`** ) não é aceita pelo compilador C, mas a sintaxe de manipulação de exceção estruturada (**__try**, **`__except`** , **`__finally`** ) é suportada pelo compilador do C++.

Consulte [_set_se_translator](../c-runtime-library/reference/set-se-translator.md) para obter informações sobre como lidar com exceções estruturadas como exceções do C++.

Se você misturar exceções estruturadas e C++, esteja atento a esses possíveis problemas:

- As exceções C++ e as exceções estruturadas não podem ser combinadas na mesma função.

- Manipuladores de terminação ( **`__finally`** blocos) são sempre executados, mesmo durante o desenrolamento após a geração de uma exceção.

- A manipulação de exceção do C++ pode capturar e preservar a semântica de liberação em todos os módulos compilados com as opções do compilador [/eh](../build/reference/eh-exception-handling-model.md) , que habilitam a semântica de desenrolamento.

- Pode haver algumas situações nas quais as funções de destruidor não sejam chamadas de todos os objetos. Por exemplo, se uma exceção estruturada ocorrer durante a tentativa de fazer uma chamada de função por meio de um ponteiro de função não inicializado, e essa função usar os objetos de parâmetros que foram construídos antes da chamada, os destruidores desses objetos não serão chamados durante o desenrolamento de pilha.

## <a name="next-steps"></a>Próximas etapas

- [Usando setjmp ou longjmp em programas C++](../cpp/using-setjmp-longjmp.md)

  Veja mais informações sobre o uso de `setjmp` e `longjmp` em programas em C++.

- [Tratar exceções estruturadas no C++](../cpp/exception-handling-differences.md)

  Veja exemplos de como você pode usar o C++ para lidar com exceções estruturadas.

## <a name="see-also"></a>Confira também

[Práticas recomendadas do C++ moderno para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md)
