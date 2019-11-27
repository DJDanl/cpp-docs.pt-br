---
title: Misturando C (estruturado C++ ) e exceções
ms.date: 08/14/2018
helpviewer_keywords:
- exceptions [C++], mixed C and C++
- C++ exception handling, mixed-language
- structured exception handling [C++], mixed C and C++
- catch keyword [C++], mixed
- try-catch keyword [C++], mixed-language
ms.assetid: a149154e-36dd-4d1a-980b-efde2a563a56
ms.openlocfilehash: e49731f1c81057002eaae2bef16cda4a5cf86f8d
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246454"
---
# <a name="mixing-c-structured-and-c-exceptions"></a>Misturando C (estruturado C++ ) e exceções

Se você quiser escrever código portátil, o uso de SEH (manipulação de exceção estruturada) em C++ um programa não é recomendado. No entanto, às vezes você pode querer compilar usando [/EHA](../build/reference/eh-exception-handling-model.md) e misturar exceções C++ estruturadas e código-fonte e precisa de algum recurso para lidar com os dois tipos de exceções. Como um manipulador de exceção estruturado não tem nenhum conceito de objetos ou exceções tipadas, ele não C++ pode tratar exceções lançadas pelo código. No entanto, C++ os manipuladores **Catch** podem lidar com exceções estruturadas. C++a sintaxe de tratamento de exceção (**try**, **throw**, **Catch**) não é aceita pelo compilador C, mas a sintaxe de manipulação de C++ exceção estruturada ( **__try**, **__except** **__finally**) é suportada pelo compilador.

Consulte [_set_se_translator](../c-runtime-library/reference/set-se-translator.md) para obter informações sobre como tratar exceções estruturadas C++ como exceções.

Se você misturar estruturas e C++ exceções, esteja atento a esses possíveis problemas:

- As exceções C++ e as exceções estruturadas não podem ser combinadas na mesma função.

- Os manipuladores de terminação (blocos de **__finally** ) são sempre executados, mesmo durante o desenrolamento após a geração de uma exceção.

- C++a manipulação de exceção pode capturar e preservar a semântica de desenrolamento em todos os módulos compilados com as opções do compilador [/eh](../build/reference/eh-exception-handling-model.md) , que habilitam a semântica de desenrolamento.

- Pode haver algumas situações nas quais as funções de destruidor não sejam chamadas de todos os objetos. Por exemplo, se uma exceção estruturada ocorrer durante a tentativa de fazer uma chamada de função por meio de um ponteiro de função não inicializado, e essa função usar os objetos de parâmetros que foram construídos antes da chamada, os destruidores desses objetos não serão chamados durante o desenrolamento de pilha.

## <a name="next-steps"></a>{1&gt;{2&gt;Próximas etapas&lt;2}&lt;1}

- [Usando setjmp ou longjmp em C++ programas](../cpp/using-setjmp-longjmp.md)

  Veja mais informações sobre o uso de `setjmp` e `longjmp` em C++ programas.

- [Tratar exceções estruturadas no C++](../cpp/exception-handling-differences.md)

  Veja exemplos das maneiras que você pode usar C++ para lidar com exceções estruturadas.

## <a name="see-also"></a>Consulte também

[Práticas C++ recomendadas modernas para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md)
