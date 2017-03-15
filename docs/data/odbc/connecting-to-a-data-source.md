---
title: "Conectando a uma fonte de dados | Microsoft Docs"
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
  - "conexões [C++], fonte de dados"
  - "fonte de dados [C++], conectando a"
  - "conexões de banco de dados [C++], Classes MFC ODBC"
  - "conexões de banco de dados [C++], ODBC"
  - "bancos de dados [C++], conectando a"
  - "Conexões ODBC [C++], usando"
  - "Fonte de dados ODBC [C++], conexões"
ms.assetid: ef6c8c98-5979-43a8-9fb5-5bb06fc59f36
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conectando a uma fonte de dados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma fonte de dados ODBC é um conjunto específico de dados, as informações necessárias para acessar os dados, e o local da fonte de dados, que pode ser descrita usando um nome da fonte de dados.  O ponto de vista do programa, a fonte de dados incluir os dados, o DBMS, a rede \(se houver\), e ODBC.  
  
 Para acessar os dados fornecidos por uma fonte de dados, o programa deve primeiro estabelecer uma conexão com a fonte de dados.  Todo o acesso a dados é gerenciado naquela conexão.  
  
 As conexões de fonte de dados são encapsuladas pela classe [CDatabase](../../mfc/reference/cdatabase-class.md).  Quando um objeto de `CDatabase` é conectado a uma fonte de dados, você pode:  
  
-   Construir [conjuntos de registros](../Topic/CRecordset%20Class.md), registros que selecionam entre tabelas ou consultas.  
  
-   Gerenciar [transações](../../data/odbc/transaction-odbc.md), processamento em lotes atualizações para que todos são confirmados à fonte de dados imediatamente \(ou à transação inteira será revertida para que a fonte de dados inalterada\) — se a fonte de dados oferece suporte ao nível requerido de transações.  
  
-   Executar instruções diretamente de [SQL](../../data/odbc/sql.md) .  
  
 Quando você conclui trabalhar com uma conexão de fonte de dados, você fecha o objeto de `CDatabase` e destrua\-o ou reutilizá\-la para uma nova conexão.  Para obter mais informações sobre as conexões de fonte de dados, consulte [Fonte de dados \(ODBC\)](../../data/odbc/data-source-odbc.md).  
  
## Consulte também  
 [ODBC e MFC](../../data/odbc/odbc-and-mfc.md)