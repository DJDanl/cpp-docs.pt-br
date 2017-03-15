---
title: "Origens de dados e sess&#245;es | Microsoft Docs"
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
  - "fonte de dados [C++], OLE DB"
  - "Modelos de consumidor OLE DB [C++], fontes de dados"
ms.assetid: 6ee52216-e082-4869-a1d6-ce561cfb76e5
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Origens de dados e sess&#245;es
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A figura a seguir mostra as classes que oferecem suporte à conexão e acessar uma fonte de dados.  Cada classe é baseada em uma implementação padrão do componente OLE DB.  
  
 ![Fonte de dados e Classes de sessão](../../data/oledb/media/vcdatasourcesessionclasses.png "vcDataSourceSessionClasses")  
Classes da fonte de dados e de sessão  
  
 As classes são:  
  
-   [CDataSource](../Topic/CDataSource%20Class.md) essa classe cria uma instância do objeto de fonte de dados, que cria e gerencia uma conexão a uma fonte de dados por meio de um provedor OLE DB.  A fonte de dados usa informações como o endereço da fonte de dados e as informações de autenticação na forma de uma cadeia de conexão.  
  
     Também é a notar que a classe [CEnumerator](../../data/oledb/cenumerator-class.md) auxiliar é frequentemente usada antes que qualquer conexão seja estabelecida para obter uma lista de provedores disponíveis registrados em um sistema.  Isso permite selecionar um provedor como uma fonte de dados.  Por exemplo, a caixa de diálogo de **Propriedades de associação de dados** usa essa classe para popular a lista de provedores na guia de **Provedores** .  É equivalente à função de **SQLBrowseConnect** ou de **SQLDriverConnect** .  
  
-   [CSession](../../data/oledb/csession-class.md) essa classe cria uma instância do objeto de sessão, que representa uma única sessão de acesso à fonte de dados.  Porém, você pode criar várias sessões em uma fonte de dados.  Para cada sessão, você pode criar conjuntos de linhas, comandos, e outros objetos de acesso aos dados da fonte de dados.  A sessão trata transações.  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)