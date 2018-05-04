---
title: Tratamento de exceções C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- C++ exception handling
- Visual C++, exception handling
ms.assetid: 65f80b44-9d0f-4d17-b910-07205a5c5c40
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5ce782000ac1767034d00aa3e0280b8e3820e3d7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="c-exception-handling"></a>Tratamento de exceções C++
A linguagem C++ fornece suporte interno para lançamento e captura de exceções. Ao programar em C++, você quase sempre deve usar o suporte interno à exceção C++, conforme descrito nesta seção.  
  
 Para habilitar no seu código de tratamento de exceção de C++, use [/EHsc](../build/reference/eh-exception-handling-model.md).  
  
## <a name="in-this-section"></a>Nesta seção  
 Esta discussão sobre tratamento de exceções C++ inclui:  
  
-   [O bloco try, catch e instruções throw](../cpp/try-throw-and-catch-statements-cpp.md)  
  
-   [Como os blocos catch são avaliados](../cpp/how-catch-blocks-are-evaluated-cpp.md)  
  
-   [Exceções e desenrolamento de pilha](../cpp/exceptions-and-stack-unwinding-in-cpp.md)  
  
-   [Especificações de exceção](../cpp/exception-specifications-throw-cpp.md)  
  
-   [noexcept](../cpp/noexcept-cpp.md)  
  
-   [Exceções C++ não tratadas](../cpp/unhandled-cpp-exceptions.md)  
  
-   [Combinação de exceções C (estruturadas) e C++](../cpp/mixing-c-structured-and-cpp-exceptions.md)  
  
## <a name="support-for-earlier-mfc-exceptions"></a>Suporte às exceções antigas do MFC  
 A partir da versão 4.0, MFC começou usando o mecanismo de tratamento de exceções de C++. Embora você seja encorajado a usar o tratamento de exceções C++ no novo código, o MFC versão 4.0 e posterior mantêm as macros das versões anteriores do MFC para que o código antigo não seja quebrado. As macros e o novo mecanismo também podem ser combinados. Para informações sobre mesclando macros e tratamento de exceções C++ e sobre a conversão de código antigo para o novo mecanismo de usar, consulte os artigos [exceções: usando Macros de MFC e exceções de C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md) e [exceções: Convertendo a partir de MFC Macros de exceção](../mfc/exceptions-converting-from-mfc-exception-macros.md). As macros de exceção mais antigas do MFC, se você ainda as usa, são avaliadas para palavras-chave de exceção C++. Consulte [exceções: alterações em Macros de exceção na versão 3.0](../mfc/exceptions-changes-to-exception-macros-in-version-3-0.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)