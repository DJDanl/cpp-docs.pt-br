---
title: "Fonte de dados (ODBC) | Microsoft Docs"
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
  - "Classe CDatabase, conexões de fonte de dados"
  - "configurando fontes de dados ODBC"
  - "Fontes de dados ODBC"
  - "Fontes de dados ODBC, configurando"
  - "Fontes de dados ODBC, representado por CDatabase"
ms.assetid: b246721f-b9e1-49bd-a6c7-f348b8c3d537
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fonte de dados (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Em termos de base de dados, uma fonte de dados é um conjunto específico de dados, as informações necessárias para acessar os dados, e o local da fonte de dados, que pode ser descrita usando um nome da fonte de dados.  Para trabalhar com a classe [CDatabase](../../mfc/reference/cdatabase-class.md), a fonte de dados deve ser uma que você tiver configurado pelo administrador de ODBC.  Exemplos de fontes de dados incluem uma execução remota de base de dados do Microsoft SQL Server por meio de uma rede ou de um arquivo do Microsoft Access em um diretório local.  De seu aplicativo, você pode acessar qualquer fonte de dados para que você tenha um driver ODBC.  
  
 Você pode ter uma ou mais fontes de dados ativos em seu aplicativo ao mesmo tempo, cada um representado por um objeto de `CDatabase` .  Você também pode ter várias conexões simultâneas a qualquer fonte de dados.  Você pode se conectar a remoto bem como a fontes de dados locais, dependendo dos drivers você instalou e os recursos dos drivers ODBC.  Para obter mais informações sobre as fontes de dados e o administrador ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md) e [Administrador ODBC](../../data/odbc/odbc-administrator.md).  
  
 Os tópicos seguintes explicam mais informações sobre fontes de dados:  
  
-   [Fonte de dados: Gerenciando conexões \(ODBC\)](../../data/odbc/data-source-managing-connections-odbc.md)  
  
-   [Fonte de dados: Determinando o esquema da fonte de dados \(ODBC\)](../../data/odbc/data-source-determining-the-schema-of-the-data-source-odbc.md)  
  
## Consulte também  
 [Conectividade de banco de dados aberto \(ODBC\)](../Topic/Open%20Database%20Connectivity%20\(ODBC\).md)