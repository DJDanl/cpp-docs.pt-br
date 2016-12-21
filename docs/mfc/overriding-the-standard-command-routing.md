---
title: "Substituindo o roteamento de comando padr&#227;o | Microsoft Docs"
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
  - "tratamento de comandos, roteando comandos"
  - "roteamento de comando, substituição"
  - "MFC, roteamento de comando"
  - "substituição, roteamento de comando padrão"
ms.assetid: 872b698a-7432-40c4-9008-68721e8effa5
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Substituindo o roteamento de comando padr&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em casos raros quando você deve implementar algumas variações da estrutura padrão que roteia, você pode substituí\-la.  A exibição é alterar o roteamento em uma ou mais classes substituindo `OnCmdMsg` nessas classes.  Faça isso:  
  
-   Na classe de quebra a ordem passar a um objeto não padrão.  
  
-   O novo objeto não padrão ou em destinos de comando pode transferir comandos por sua vez como.  
  
 Se você inserir um novo objeto no roteamento, a sua classe deve ser uma classe de comando\- destino.  Nas versões substituindo de `OnCmdMsg`, certifique\-se de chamar a versão que está sendo substituído.  Consulte a função de membro de [OnCmdMsg](../Topic/CCmdTarget::OnCmdMsg.md) da classe `CCmdTarget`*na referência de MFC* e nas versões em classes como `CView` e **CDocument** no código\-fonte fornecido para exemplos.  
  
## Consulte também  
 [Como o Framework chama um identificador](../mfc/how-the-framework-calls-a-handler.md)