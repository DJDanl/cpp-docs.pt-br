---
title: "Macros e globais de banco de dados | Microsoft Docs"
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
  - "globais de banco de dados [C++]"
  - "macros de banco de dados [C++]"
  - "funções de banco de dados globais [C++]"
  - "funções globais [C++], funções de banco de dados"
  - "macros [C++], Banco de dados MFC"
ms.assetid: 5b9b9e61-1cf9-4345-9f29-3807dd466488
caps.latest.revision: 13
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Macros e globais de banco de dados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Macros e globais os listados a seguir se aplicam aos aplicativos de base de dados com base em.  Não são usados com aplicativos baseados DAO\-.  
  
 Antes de MFC 4,2, macros `AFX_SQL_ASYNC` e `AFX_SQL_SYNC` deram a operações assíncronas uma oportunidade de gerar tempo para outros processos.  Começando com o MFC 4,2, a implementação desses macros foi alterado porque classes de MFC ODBC usam apenas operações síncronas.  `AFX_ODBC_CALL` macro é novo MFC a 4,2.  
  
### Macros da base de dados  
  
|||  
|-|-|  
|[AFX\_ODBC\_CALL](../Topic/AFX_ODBC_CALL.md)|Chama uma função de API ODBC que retorna `SQL_STILL_EXECUTING`.  `AFX_ODBC_CALL` chamará a função repetidamente até que não retorna `SQL_STILL_EXECUTING`.|  
|[AFX\_SQL\_ASYNC](../Topic/AFX_SQL_ASYNC.md)|Chama `AFX_ODBC_CALL`.|  
|[AFX\_SQL\_SYNCHRONIZATION](../Topic/AFX_SQL_SYNC.md)|Chama uma função de API ODBC que não retorna `SQL_STILL_EXECUTING`.|  
  
### Base de dados Globais  
  
|||  
|-|-|  
|[AfxGetHENV](../Topic/AfxGetHENV.md)|Recupera um identificador para o ambiente ODBC usado atualmente por MFC.  Você pode usar esse identificador em chamadas diretos de ODBC.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)