---
title: "Tratamento de erro e notifica&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tratamento de erros, e notificação"
ms.assetid: b621cf60-d869-451a-b05e-dc86d78addaa
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Tratamento de erro e notifica&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para obter mais informações sobre o tratamento de erros e de notificação, consulte [Compreendendo a função auxiliar](http://msdn.microsoft.com/pt-br/6279c12c-d908-4967-b0b3-cabfc3e91d3d).  
  
 Para obter mais informações sobre as funções de gancho, consulte [Definições da estrutura e da constante](../../build/reference/structure-and-constant-definitions.md).  
  
 Se seu programa usa atraso\- DLL carregados, deve tratar erros robusta desde que as falhas que ocorrem quando o programa executar controlarão a exceção sem\-tratamento.  A manipulação de falha é composta de duas partes:  
  
 Recuperação por meio de um gancho.  
 Se seu código precisa recuperar ou fornecer uma biblioteca de backup e\/ou uma rotina em caso de falha, um gancho podem ser fornecidas à função auxiliar que pode fornecer ou solucionar a situação.  O gancho rotina precisa retornar um valor apropriado, de modo que o processamento continue \(um HINSTANCE ou um FARPROC\) ou 0 para indicar que uma exceção deve ser gerada.  Também pode gerar seu próprio exceção ou **longjmp** fora do gancho.  Há ganchos de notificação e ganchos de falha.  
  
 Relatório por meio de uma exceção.  
 Se tudo o que é necessário para tratar o erro é nulo o procedimento, nenhum gancho é necessário contanto que o código do usuário pode controlar a exceção.  
  
 Os tópicos a seguir abordam o tratamento de erro e a notificação:  
  
-   [Ganchos de notificação](../../build/reference/notification-hooks.md)  
  
-   [Ganchos de falha](../Topic/Failure%20Hooks.md)  
  
-   [Exceções](../../build/reference/exceptions-c-cpp.md)  
  
## Consulte também  
 [Suporte de vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)