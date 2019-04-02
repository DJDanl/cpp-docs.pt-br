---
title: Tratamento de exceções no Visual C++
ms.date: 11/04/2016
helpviewer_keywords:
- try-catch keyword [C++], exception handling
ms.assetid: a6aa08de-669d-4ce8-9ec3-ec20d1354fcf
ms.openlocfilehash: 506ead1b6e96f59717a92b6b0c48db0270b1822f
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58779515"
---
# <a name="exception-handling-in-visual-c"></a>Tratamento de exceções no Visual C++

Uma exceção é uma condição de erro, possivelmente fora do controle do programa, que impede que o programa continue sua execução normal. Determinadas operações, incluindo a criação do objetos, a entrada/saída de arquivos e as chamadas de função feitas de outros módulos, são todas possíveis fontes de exceções até mesmo quando seu programa é executado corretamente. O código robusto antecipar e trata exceções.

Para detectar erros lógicos dentro de um único programa ou módulo, use asserções em vez de exceções (consulte [asserções usando](/visualstudio/debugger/c-cpp-assertions)).

O Visual C++ dá suporte a três tipos de tratamento de exceções:

- [Tratamento de exceções C++](../cpp/cpp-exception-handling.md)

   Para a maioria dos programas em C++, você deve usar o tratamento de exceções do C++, que é fortemente tipado e assegura que os destruidores de objeto sejam chamados durante o desenrolamento de pilha.

- [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)

   O Windows fornece seu próprio mecanismo de exceção, chamado SEH. Ele não é recomendável para a programação em C++ ou MFC. Use o SEH apenas em programas C não - MFC.

- [Exceções do MFC](../mfc/exception-handling-in-mfc.md)

   A partir da versão 3.0, o MFC usa as exceções do C++, mas ainda dá suporte a macros de tratamento de exceções antigas, que têm formato semelhante ao das exceções do C++. Embora essas macros não sejam recomendadas para novos programas, ainda há suporte a elas para garantir a compatibilidade com versões anteriores. Em programas que já usam as macros, você também pode usar livremente as exceções do C++. Durante o pré-processamento, as macros são avaliadas como as palavras-chave de tratamento de exceções definidas na implementação do Visual C++ da linguagem C++ a partir da versão 2.0 do Visual C++. Você pode manter as macros de exceção existentes em vigor quando você começar a usar exceções do C++.

Use o [/EH](../build/reference/eh-exception-handling-model.md) opção do compilador para especificar o tipo de tratamento de exceções para usar em um projeto; Tratamento de exceções C++ é o padrão. Não combine os mecanismos de tratamento de erro, por exemplo, não use exceções do C++ com manipulação de exceções estruturada. Usar manipulação de exceções C++ torna seu código mais portável e permite que você manipule exceções de qualquer tipo. Para obter mais informações sobre as desvantagens da manipulação de exceção estruturada, consulte [Structured Exception Handling](../cpp/structured-exception-handling-c-cpp.md). Para obter conselhos sobre mesclando macros MFC e exceções do C++, consulte [exceções: Usando Macros MFC e exceções do C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md).

Para obter informações sobre o tratamento de exceções em aplicativos do CLR, consulte [tratamento de exceções (C + + c++ /CLI e c++ /CLI CX)](../extensions/exception-handling-cpp-component-extensions.md).

Para obter informações sobre o tratamento de exceções em x64 processadores, consulte [x64 tratamento de exceção](../build/exception-handling-x64.md).

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)