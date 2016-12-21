---
title: "TN047: relaxando requisitos de transa&#231;&#227;o de banco de dados | Microsoft Docs"
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
  - "vc.data"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "TN047"
ms.assetid: f93c51cf-a8c0-43d0-aa47-7bcb8333d693
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN047: relaxando requisitos de transa&#231;&#227;o de banco de dados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Observação sobre essa tecnologia, que discutiu os requisitos de transação das classes da base de dados de MFC ODBC, é agora obsoleta.  Antes de MFC 4,2, as classes de base de dados era necessário que os cursores sejam preservados em clusters de registros depois de uma operação de **CommitTrans** ou de **Reverter** .  Se o driver ODBC do e um DBMS não oferecia suporte a esse nível de suporte de cursor, as classes da base de dados não habilitado transações.  
  
 Começando com o MFC 4,2, as classes da base de dados relaxaram a limitação de exigir a preservação de cursor.  As transações serão habilitadas se o driver as oferece suporte.  No entanto, agora você deve verificar o efeito de uma operação de **CommitTrans** ou de **Reverter** em clusters de registros abertos.  Consulte as funções de membro [CDatabase::GetCursorCommitBehavior](../Topic/CDatabase::GetCursorCommitBehavior.md) e [CDatabase::GetCursorRollbackBehavior](../Topic/CDatabase::GetCursorRollbackBehavior.md) para obter mais informações.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)