---
title: "Inicializa&#231;&#227;o e t&#233;rmino do mecanismo de banco de dados DAO | Microsoft Docs"
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
  - "vc.mfc.macros.data"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DAO (Objetos de Acesso a Dados), inicialização"
  - "DAO (Objetos de Acesso a Dados), encerramento"
ms.assetid: a7edf31c-e7c2-4f3e-aada-63c3e48781da
caps.latest.revision: 13
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Inicializa&#231;&#227;o e t&#233;rmino do mecanismo de banco de dados DAO
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Ao usar MFC DAO objetos, o mecanismo de base de dados de DAO deve primeiro ser inicializado e depois encerrado antes que o aplicativo ou DLL encerrem.  Duas funções, `AfxDaoInit` e `AfxDaoTerm`, executam as tarefas.  
  
### Inicialização e de término DAO o Mecanismo de Base de dados  
  
|||  
|-|-|  
|[AfxDaoInit](../Topic/AfxDaoInit.md)|Inicializa o mecanismo de base de dados de DAO.|  
|[AfxDaoTerm](../Topic/AfxDaoTerm.md)|Encerra o mecanismo de base de dados de DAO.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)