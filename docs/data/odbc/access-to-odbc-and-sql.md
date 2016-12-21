---
title: "Acesso a ODBC e SQL | Microsoft Docs"
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
  - "Chamadas à API [C++], chamando DAO ou ODBC diretamente"
  - "API do Windows [C++], chamando a partir de MFC"
  - "Funções API de ODBC [C++]"
  - "Funções de API de ODBC [C++], chamando a partir de MFC"
  - "SQL [C++], chamar funções da API do ODBC"
  - "Funções de API, ODBC [C++]"
ms.assetid: 5613d7dc-00b7-4646-99ae-1116c05c52b4
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acesso a ODBC e SQL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A biblioteca Microsoft Foundation Class encapsula muitas chamadas de API do Windows e ainda permite que você chamar qualquer função de API do Windows diretamente. As classes de banco de dados oferecem a mesma flexibilidade com relação a API ODBC. Embora as classes de banco de dados protegem você de grande parte da complexidade do ODBC, você pode chamar funções de API ODBC diretamente de qualquer lugar em seu programa.  
  
 Da mesma forma, as classes de banco de dados protegem você de ter que trabalhar com [SQL](../../data/odbc/sql.md), mas você pode usar SQL diretamente, se desejar. Você pode personalizar objetos de conjunto de registros passando uma instrução SQL personalizada \(ou partes de configuração da instrução padrão\) quando você abre o conjunto de registros. Você também pode fazer chamadas SQL diretamente usando o [ExecuteSQL](../Topic/CDatabase::ExecuteSQL.md) a função de membro da classe [CDatabase](../../mfc/reference/cdatabase-class.md).  
  
 Para obter mais informações, consulte [ODBC: chamando o funções dos API ODBC diretamente](../../data/odbc/odbc-calling-odbc-api-functions-directly.md) e [SQL: tornando direto SQL chamadas \(ODBC\)](../../data/odbc/sql-making-direct-sql-calls-odbc.md).  
  
## Consulte também  
 [ODBC e MFC](../../data/odbc/odbc-and-mfc.md)