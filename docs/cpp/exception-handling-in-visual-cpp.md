---
title: "Tratamento de exce&#231;&#245;es no Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave try-catch [C++], tratamento de exceção"
ms.assetid: a6aa08de-669d-4ce8-9ec3-ec20d1354fcf
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tratamento de exce&#231;&#245;es no Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma exceção é uma condição de erro, possivelmente fora do controle do programa, que impede que o programa continue sua execução normal.  Determinadas operações, incluindo a criação do objetos, a entrada\/saída de arquivos e as chamadas de função feitas de outros módulos, são todas possíveis fontes de exceções até mesmo quando seu programa é executado corretamente.  O código robusto antecipar e trata exceções.  
  
 Para detectar erros lógicos dentro de um único programa ou módulo, use asserções em vez de exceções \(consulte [Usando asserções](../Topic/C-C++%20Assertions.md)\).  
  
 O Visual C\+\+ dá suporte a três tipos de tratamento de exceções:  
  
-   [Tratamento de exceções em C\+\+](../cpp/cpp-exception-handling.md)  
  
     Para a maioria dos programas em C\+\+, você deve usar o tratamento de exceções do C\+\+, que é fortemente tipado e assegura que os destruidores de objeto sejam chamados durante o desenrolamento de pilha.  
  
-   [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)  
  
     O Windows fornece seu próprio mecanismo de exceção, chamado SEH.  Ele não é recomendável para a programação em C\+\+ ou MFC.  Use o SEH apenas em programas que não sejam em MFC ou C.  
  
-   [Exceções do MFC:](../mfc/exception-handling-in-mfc.md)  
  
     A partir da versão 3.0, o MFC usa as exceções do C\+\+, mas ainda dá suporte a macros de tratamento de exceções antigas, que têm formato semelhante ao das exceções do C\+\+.  Embora essas macros não sejam recomendadas para novos programas, ainda há suporte a elas para garantir a compatibilidade com versões anteriores.  Em programas que já usam as macros, você também pode usar livremente as exceções do C\+\+.  Durante o pré\-processamento, as macros são avaliadas como as palavras\-chave de tratamento de exceções definidas na implementação do Visual C\+\+ da linguagem C\+\+ a partir da versão 2.0 do Visual C\+\+.  Você pode manter as macros de exceção existentes em vigor quando você começar a usar exceções do C\+\+.  
  
 Use a opção de compilador [\/EH](../build/reference/eh-exception-handling-model.md) para especificar o tipo de tratamento de exceções a ser usado em um projeto; o tratamento de exceções do C\+\+ é o padrão.  Não combine os mecanismos de tratamento de erro, por exemplo, não use exceções do C\+\+ com manipulação de exceções estruturada.  Usar manipulação de exceções C\+\+ torna seu código mais portável e permite que você manipule exceções de qualquer tipo.  Para obter mais informações sobre as desvantagens da manipulação de exceções estruturada, consulte [Manipulação de exceções estruturada](../cpp/structured-exception-handling-c-cpp.md).  Para obter orientações sobre a combinação de macros do MFC e exceções do C\+\+, consulte [Exceções: usando macros MFC e exceções do C\+\+](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md).  
  
 Para obter informações sobre o tratamento de exceções em aplicativos do CLR, consulte [Exception Handling](../windows/exception-handling-cpp-component-extensions.md).  
  
 Para obter informações sobre o tratamento de exceções em processadores x64, consulte [Tratamento de exceções \(x64\)](../build/exception-handling-x64.md).  
  
## Consulte também  
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)