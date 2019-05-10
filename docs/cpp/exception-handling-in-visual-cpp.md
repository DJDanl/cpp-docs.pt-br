---
title: Tratamento de exceção no MSVC
ms.date: 05/07/2019
helpviewer_keywords:
- try-catch keyword [C++], exception handling
ms.assetid: a6aa08de-669d-4ce8-9ec3-ec20d1354fcf
ms.openlocfilehash: 47443f1b7021aac7755d77f797a4f7b7410281f8
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65222068"
---
# <a name="exception-handling-in-msvc"></a>Tratamento de exceção no MSVC

Uma exceção é uma condição de erro, possivelmente fora do controle do programa, que impede que o programa continue sua execução normal. Determinadas operações, incluindo a criação do objetos, a entrada/saída de arquivos e as chamadas de função feitas de outros módulos, são todas possíveis fontes de exceções até mesmo quando seu programa é executado corretamente. O código robusto antecipar e trata exceções.

Para detectar erros lógicos dentro de um único programa ou módulo, use asserções em vez de exceções (consulte [asserções usando](/visualstudio/debugger/c-cpp-assertions)).

O Microsoft C++ compilador (MSVC) dá suporte a três tipos de tratamento de exceções:

- [Tratamento de exceções C++](../cpp/cpp-exception-handling.md)

   Para a maioria dos programas em C++, você deve usar o tratamento de exceções do C++, que é fortemente tipado e assegura que os destruidores de objeto sejam chamados durante o desenrolamento de pilha.

- [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)

   O Windows fornece seu próprio mecanismo de exceção, chamado SEH. Ele não é recomendável para a programação em C++ ou MFC. Use o SEH apenas em programas C não - MFC.

- [Exceções do MFC](../mfc/exception-handling-in-mfc.md)

   A partir da versão 3.0, o MFC usa as exceções do C++, mas ainda dá suporte a macros de tratamento de exceções antigas, que têm formato semelhante ao das exceções do C++. Embora essas macros não sejam recomendadas para novos programas, ainda há suporte a elas para garantir a compatibilidade com versões anteriores. Em programas que já usam as macros, você também pode usar livremente as exceções do C++. Durante o pré-processamento, as macros são avaliadas as palavras-chave definidas na implementação do MSVC de manipulação de exceção de C++ idioma a partir do Visual C++ versão 2.0. Você pode manter as macros de exceção existentes em vigor quando você começar a usar exceções do C++.

Use o [/EH](../build/reference/eh-exception-handling-model.md) opção do compilador para especificar o tipo de tratamento de exceções para usar em um projeto; Tratamento de exceções C++ é o padrão. Não combine os mecanismos de tratamento de erro, por exemplo, não use exceções do C++ com manipulação de exceções estruturada. Usar manipulação de exceções C++ torna seu código mais portável e permite que você manipule exceções de qualquer tipo. Para obter mais informações sobre as desvantagens da manipulação de exceção estruturada, consulte [Structured Exception Handling](../cpp/structured-exception-handling-c-cpp.md). Para obter conselhos sobre mesclando macros MFC e exceções do C++, consulte [exceções: Usando Macros MFC e exceções do C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md).

Para obter informações sobre o tratamento de exceções em aplicativos do CLR, consulte [Exception Handling (C++/CLI e C++/CX)](../extensions/exception-handling-cpp-component-extensions.md).

Para obter informações sobre o tratamento de exceções em x64 processadores, consulte [x64 tratamento de exceção](../build/exception-handling-x64.md).

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)