---
title: Asserção e mensagens fornecidas pelo usuário (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- user-supplied messages [C++], run time
- user-supplied messages [C++], preprocessor time
- '#error%2C assert%2C static_assert [C++]'
- user-supplied messages [C++], compile time
ms.assetid: ebf7d885-61c8-4233-b0ae-1c9a38e0f385
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e93798dadee3e4270d82eac84a794c6133c05c07
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32411699"
---
# <a name="assertion-and-user-supplied-messages-c"></a>Asserção e mensagens fornecidas pelo usuário (C++)
Os C++ linguagem dá suporte a três tratamento de erros mecanismos que ajudam a depurar seu aplicativo: o [#error diretiva](../preprocessor/hash-error-directive-c-cpp.md), o [static_assert](../cpp/static-assert.md) palavra-chave e o [assert Macro Assert, _ wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md) macro. Todos os três mecanismos emitem mensagens de erro e dois também testam asserções de software. Uma asserção de software especifica uma condição que você espera ser verdadeira (true) em um ponto específico de seu programa. Se uma asserção de tempo de compilação falhar, o compilador emite uma mensagem de diagnóstico e um erro de compilação. Se uma asserção de tempo de execução falhar, o sistema operacional emite uma mensagem de diagnóstico e fecha seu aplicativo.  
  
## <a name="remarks"></a>Comentários  
 O tempo de vida do seu aplicativo consiste de uma fase de pré-processamento, compilação e de tempo de execução. Cada mecanismo de tratamento de erro acessa as informações de depuração disponíveis durante uma dessas fases. Para depurar efetivamente, selecione o mecanismo que fornece as informações adequadas sobre essa fase:  
  
-   O [#error diretiva](../preprocessor/hash-error-directive-c-cpp.md) está em vigor no momento de pré-processamento. Ela incondicionalmente emite uma mensagem especificada pelo usuário e causa a falha da compilação com um erro. A mensagem pode conter texto que é manipulado pelas políticas do pré-processador, mas nenhuma expressão resultante é avaliada.  
  
-   O [static_assert](../cpp/static-assert.md) declaração está em vigor no momento da compilação. Ela testa uma asserção de software que é representada por uma expressão integral especificada pelo usuário que possa ser convertida em Booliano. Se a expressão for avaliada como zero (false), o compilador emitirá uma mensagem especificada pelo usuário e a compilação falhará com um erro.  
  
     A declaração `static_assert` é especialmente útil para depuração de modelos porque os argumentos de modelo podem ser incluídos na expressão especificada pelo usuário.  
  
-   O [assert Macro Assert, _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md) macro está em vigor em tempo de execução. Ela avalia uma expressão especificada pelo usuário e se o resultado for zero, o sistema emitirá uma mensagem de diagnóstico e fechará seu aplicativo. Muitas outras macros, como[Assert](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) e `_ASSERTE`, semelhante a esta macro mas emitir mensagens diferentes de diagnósticas definido pelo sistema ou definidos pelo usuário.  
  
## <a name="see-also"></a>Consulte também  
 [#error diretiva (C/C++)](../preprocessor/hash-error-directive-c-cpp.md)   
 [assert Macro, _assert, _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md)   
 [Macros _ASSERT, _ASSERTE, _ASSERT_EXPR](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)   
 [static_assert](../cpp/static-assert.md)   
 [Macro static_assert](../c-runtime-library/reference/static-assert-macro.md)   
 [Modelos](../cpp/templates-cpp.md)