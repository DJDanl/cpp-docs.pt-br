---
title: "Modelos de consumidor de banco de dados OLE (C++) | Microsoft Docs"
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
  - "bancos de dados [C++], modelos OLE DB"
  - "Consumidores OLE DB [C++], acesso a dados"
  - "Modelos de consumidor OLE DB [C++]"
  - "bancos de dados [C++], os consumidores"
ms.assetid: d3e42612-0bc0-4d65-9c32-0e8a7b219e82
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modelos de consumidor de banco de dados OLE (C++)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O OLE DB modelos de consumidor dar suporte à especificação de versão 2.6 do OLE DB. \(Os modelos de consumidor de banco de dados OLE sejam testados em OLE DB 2.6, mas não oferecem suporte a todas as interfaces na especificação.\) Os modelos de consumidor minimizar a quantidade de código que você deve escrever para implementar um consumidor OLE DB. Os modelos fornecem:  
  
-   Fácil acesso a recursos de OLE DB e facilita a integração com ATL e MFC.  
  
-   Um modelo de associação fácil para parâmetros de banco de dados e colunas.  
  
-   Tipos de dados de C\/C\+\+ nativos para programação de OLE DB.  
  
 Para usar os modelos OLE DB, você deve estar familiarizado com modelos C\+\+, COM e as interfaces do OLE DB. Se você não estiver familiarizado com o OLE DB, consulte [referência do programador de DB OLE](https://msdn.microsoft.com/en-us/library/ms718124.aspx).  
  
 Os modelos OLE DB oferecer suporte a modelo de objeto OLE DB existente em vez de adicionar um novo modelo de objeto. As classes de camada superior de modelos OLE DB consumidor paralela componentes definidos na especificação do OLE DB. O design dos modelos OLE DB consumidor inclui recursos avançados, como vários acessadores em um conjunto de linhas. O uso de modelos e várias heranças torna a biblioteca pequeno e flexível.  
  
## Como acessam os dados consumidores do OLE DB  
 Os consumidores usam vários tipos de objetos, que são descritos nos tópicos a seguir:  
  
-   [Origens de dados e sessões](../../data/oledb/data-sources-and-sessions.md)  
  
-   [Acessadores e conjuntos de linhas](../../data/oledb/accessors-and-rowsets.md)  
  
-   [Comandos e tabelas](../../data/oledb/commands-and-tables.md)  
  
-   [Registros de usuário](../../data/oledb/user-records.md)  
  
 Antes do consumidor nada, você primeiro selecionar um provedor OLE DB apropriado para o tipo de banco de dados que você precisa de acesso \(por exemplo, SQL, Oracle, ODBC e MSDS\). Para fazer isso, você geralmente usa um enumerador \(consulte [CEnumerator](../../data/oledb/cenumerator-class.md) conforme mencionado no [fontes de dados e sessões](../../data/oledb/data-sources-and-sessions.md)\).  
  
 O [o objeto de fonte de dados](../../data/oledb/data-sources-and-sessions.md) fornece as informações de conexão necessárias para se conectar à fonte de dados selecionado. O objeto de fonte de dados também contém informações de autenticação \(como nomes de logon e senhas\), que é usado para fornecer aos usuários permissão para acessar a fonte de dados. O objeto de fonte de dados faz uma conexão com o banco de dados e, em seguida, cria um ou mais objetos de sessão. Cada [objeto session](../../data/oledb/data-sources-and-sessions.md) gerencia suas próprias interações com o banco de dados \(ou seja, consultar e recuperar dados\) e executa essas transações, independentemente de outras sessões existentes.  
  
 A sessão cria os objetos de conjunto de linhas e comando. O [objeto command](../../data/oledb/commands-and-tables.md) permite aos usuários interagir com o banco de dados, por exemplo, usando comandos SQL. O [objeto rowset](../../data/oledb/accessors-and-rowsets.md) é um conjunto de dados por meio do qual você pode navegar e no qual você pode [atualizar, excluir e inserir linhas](../../data/oledb/updating-rowsets.md).  
  
 Um consumidor OLE DB associa colunas nas tabelas de banco de dados com variáveis locais; Para fazer isso, ele usa um [acessador](../../data/oledb/accessors-and-rowsets.md), que contém um mapa de como os dados são armazenados dentro do consumidor. O mapa consiste em um conjunto de associações entre colunas da tabela e buffers de locais \(variáveis\) no aplicativo do consumidor.  
  
 Um conceito importante quando se trabalha com os consumidores é que você declare duas classes em um consumidor: o [classe de comando \(ou tabela\)](../../data/oledb/commands-and-tables.md) e [classe de registro de usuário](../../data/oledb/user-records.md). Você pode acessar o conjunto de linhas por meio da classe de comando \(ou tabela\), que herda de uma classe de acesso e uma classe de conjunto de linhas. A classe de registro de usuário contém o mapa de associação do conjunto de linhas descrito anteriormente.  
  
 Para obter mais informações, consulte os seguintes tópicos:  
  
-   [Criando um consumidor de banco de dados OLE](../../data/oledb/creating-an-ole-db-consumer.md)  
  
-   [OLE DB consumidor comuns \(exemplos\)](../../data/oledb/working-with-ole-db-consumer-templates.md)  
  
## Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Acesso a dados](../Topic/Data%20Access%20in%20Visual%20C++.md)   
 [Documentação do SDK do OLE DB](https://msdn.microsoft.com/en-us/library/ms722784.aspx)   
 [Referência do programador do OLE DB](https://msdn.microsoft.com/en-us/library/ms713643.aspx)