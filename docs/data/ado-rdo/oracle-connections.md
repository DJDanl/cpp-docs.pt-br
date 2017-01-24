---
title: "Oracle Connections | Microsoft Docs"
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
  - "conexões [C++], bancos de dados"
  - "conexões de banco de dados [C++], Oracle"
  - "bancos de dados [C++], conectando a"
  - "Oracle [C++], criando conexões"
  - "bancos de dados Oracle [C++]"
  - "bancos de dados Oracle [C++], conexões"
ms.assetid: d317e763-44aa-47c9-abe8-261d513d894f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Oracle Connections
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando você configura o Oracle ODBC DSN ou uma conexão OLE DB, você deve ter os componentes do lado do cliente do Oracle instalados.  O SQL\*Net é a camada de transporte de rede Oracle.  A maioria dos drivers ODBC Oracle, incluindo o driver do Microsoft e o mapa do provedor OLE DB Oracle, chame diretamente nessa camada do.  
  
 Depois que o SQL\*Net é configurado, observe a cadeia de conexão do.  Normalmente, isto consiste em um especificador para o nome do servidor de base de dados Oracle e o tipo de protocolo de rede \(como TCP\/IP e pipes nomeados\).  Geralmente, a cadeia de conexão do SQL\*Net é mapeada para um alias.  Nesse caso, é necessária apenas observe o alias.  Para obter informações sobre como configurar o SQL\*Net, contate o DBA da Oracle, consulte a documentação do SQL\*Net, ou consultar o arquivo de ajuda do driver ODBC do Oracle para obter um exemplo de uma cadeia de conexão.  
  
## Consulte também  
 [Criando conexões de banco de dados](../Topic/Creating%20Database%20Connections.md)