---
title: Asserção e mensagens fornecidas pelo usuário (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- user-supplied messages [C++], run time
- user-supplied messages [C++], preprocessor time
- '#error%2C assert%2C static_assert [C++]'
- user-supplied messages [C++], compile time
ms.assetid: ebf7d885-61c8-4233-b0ae-1c9a38e0f385
ms.openlocfilehash: d76f0c2f7dc5a4202bff3f93e097a1c186f4601a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190554"
---
# <a name="assertion-and-user-supplied-messages-c"></a>Asserção e mensagens fornecidas pelo usuário (C++)

O C++ idioma dá suporte a três mecanismos de tratamento de erros que ajudam você a depurar seu aplicativo: a [diretiva #error](../preprocessor/hash-error-directive-c-cpp.md), a palavra-chave [static_assert](../cpp/static-assert.md) e a [macro Assert, _assert _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md) macro. Todos os três mecanismos emitem mensagens de erro e dois também testam asserções de software. Uma asserção de software especifica uma condição que você espera ser verdadeira (true) em um ponto específico de seu programa. Se uma asserção de tempo de compilação falhar, o compilador emite uma mensagem de diagnóstico e um erro de compilação. Se uma asserção de tempo de execução falhar, o sistema operacional emite uma mensagem de diagnóstico e fecha seu aplicativo.

## <a name="remarks"></a>Comentários

O tempo de vida do seu aplicativo consiste de uma fase de pré-processamento, compilação e de tempo de execução. Cada mecanismo de tratamento de erro acessa as informações de depuração disponíveis durante uma dessas fases. Para depurar efetivamente, selecione o mecanismo que fornece as informações adequadas sobre essa fase:

- A [diretiva de #error](../preprocessor/hash-error-directive-c-cpp.md) está em vigor no tempo de pré-processamento. Ela incondicionalmente emite uma mensagem especificada pelo usuário e causa a falha da compilação com um erro. A mensagem pode conter texto que é manipulado pelas políticas do pré-processador, mas nenhuma expressão resultante é avaliada.

- A declaração de [static_assert](../cpp/static-assert.md) está em vigor no momento da compilação. Ela testa uma asserção de software que é representada por uma expressão integral especificada pelo usuário que possa ser convertida em Booliano. Se a expressão for avaliada como zero (false), o compilador emitirá uma mensagem especificada pelo usuário e a compilação falhará com um erro.

   A declaração `static_assert` é especialmente útil para depuração de modelos porque os argumentos de modelo podem ser incluídos na expressão especificada pelo usuário.

- A [macro Assert, _assert, _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md) macro está em vigor no tempo de execução. Ela avalia uma expressão especificada pelo usuário e se o resultado for zero, o sistema emitirá uma mensagem de diagnóstico e fechará seu aplicativo. Muitas outras macros, como[_ASSERT](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) e _ASSERTE, se assemelham a essa macro, mas executam mensagens de diagnóstico diferentes definidas pelo sistema ou definidas pelo usuário.

## <a name="see-also"></a>Confira também

[Diretiva #error (C/C++)](../preprocessor/hash-error-directive-c-cpp.md)<br/>
[assert Macro, _assert, _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md)<br/>
[Macros _ASSERT, _ASSERTE, _ASSERT_EXPR](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)<br/>
[static_assert](../cpp/static-assert.md)<br/>
[Macro _STATIC_ASSERT](../c-runtime-library/reference/static-assert-macro.md)<br/>
[Modelos](../cpp/templates-cpp.md)
