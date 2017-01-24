---
title: "Fonte de dados: determinando o esquema da fonte de dados (ODBC) | Microsoft Docs"
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
  - "fonte de dados [C++], determinando esquema"
  - "Fonte de dados ODBC [C++], esquema"
  - "esquemas [C++], fontes de dados"
ms.assetid: 17284acb-eb10-4f27-9944-ad1d973c0b05
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fonte de dados: determinando o esquema da fonte de dados (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Para configurar os membros de dados nos objetos de `CRecordset` , você precisa saber o esquema da fonte de dados ao qual você está se conectando.  Determinar o esquema de uma fonte de dados envolve obter uma lista de tabelas na fonte de dados, uma lista das colunas em cada tabela, o tipo de dados de cada coluna, e a existência de quaisquer índices.  
  
## Consulte também  
 [Fonte de dados \(ODBC\)](../../data/odbc/data-source-odbc.md)   
 [Fonte de dados: gerenciando conexões \(ODBC\)](../../data/odbc/data-source-managing-connections-odbc.md)