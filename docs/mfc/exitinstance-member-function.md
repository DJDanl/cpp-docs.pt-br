---
title: "Fun&#231;&#227;o de membro ExitInstance | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CWinApp::ExitInstance"
  - "CWinApp.ExitInstance"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CWinApp, ExitInstance"
  - "Método ExitInstance"
  - "programas [C++], encerrando"
ms.assetid: 5bb597bd-8dab-4d49-8bcf-9c45aa8be4a2
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o de membro ExitInstance
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A função de membro de [ExitInstance](../Topic/CWinApp::ExitInstance.md) da classe [CWinApp](../mfc/reference/cwinapp-class.md) é chamada cada vez que uma cópia do seu aplicativo termina, normalmente no resultado do usuário que encerra o aplicativo.  
  
 Substituir `ExitInstance` se você precisar do processamento especial de limpeza, como liberar recursos de \(GDI\) de graphics device interface ou desalocar memória usada durante a execução do programa.  A limpeza de itens padrão como documentos e exibições, porém, é fornecida pela estrutura, com outras funções substituível fazendo o específico especial de limpeza 2 esses objetos.  
  
## Consulte também  
 [CWinApp: a classe do aplicativo](../Topic/CWinApp:%20The%20Application%20Class.md)