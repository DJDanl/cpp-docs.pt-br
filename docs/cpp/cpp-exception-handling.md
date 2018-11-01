---
title: Tratamento de exceções C++
ms.date: 11/04/2016
helpviewer_keywords:
- C++ exception handling
- Visual C++, exception handling
ms.assetid: 65f80b44-9d0f-4d17-b910-07205a5c5c40
ms.openlocfilehash: b4eaab7d5bb352cccc612dd950572464b82b67e8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50614741"
---
# <a name="c-exception-handling"></a>Tratamento de exceções C++

A linguagem C++ fornece suporte interno para lançamento e captura de exceções. Ao programar em C++, você quase sempre deve usar o suporte interno à exceção C++, conforme descrito nesta seção.

Para habilitar no seu código de tratamento de exceções de C++, use [/EHsc](../build/reference/eh-exception-handling-model.md).

## <a name="in-this-section"></a>Nesta seção

Esta discussão sobre tratamento de exceções C++ inclui:

- [O try, catch e instruções throw](../cpp/try-throw-and-catch-statements-cpp.md)

- [Como os blocos catch são avaliados](../cpp/how-catch-blocks-are-evaluated-cpp.md)

- [Exceções e desenrolamento de pilha](../cpp/exceptions-and-stack-unwinding-in-cpp.md)

- [Especificações de exceção](../cpp/exception-specifications-throw-cpp.md)

- [noexcept](../cpp/noexcept-cpp.md)

- [Exceções C++ não tratadas](../cpp/unhandled-cpp-exceptions.md)

- [Combinação de exceções C (estruturadas) e C++](../cpp/mixing-c-structured-and-cpp-exceptions.md)

## <a name="support-for-earlier-mfc-exceptions"></a>Suporte às exceções antigas do MFC

A partir da versão 4.0, a MFC começou a usar o mecanismo de tratamento de exceções de C++. Embora você seja encorajado a usar o tratamento de exceções C++ no novo código, o MFC versão 4.0 e posterior mantêm as macros das versões anteriores do MFC para que o código antigo não seja quebrado. As macros e o novo mecanismo também podem ser combinados. Para informações sobre a combinação de macros e tratamento de exceções C++ e sobre como converter código antigo para usar o novo mecanismo, consulte os artigos [exceções: usando Macros MFC e exceções do C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md) e [exceções: Convertendo de MFC Macros de exceção](../mfc/exceptions-converting-from-mfc-exception-macros.md). As macros de exceção mais antigas do MFC, se você ainda as usa, são avaliadas para palavras-chave de exceção C++. Ver [exceções: alterações em Macros de exceção na versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)