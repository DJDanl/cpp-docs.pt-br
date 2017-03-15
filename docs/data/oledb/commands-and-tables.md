---
title: "Comandos e tabelas | Microsoft Docs"
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
  - "Classe CAccessorRowset, classes de comando e tabela"
  - "Classe CCommand, Modelos de consumidor OLE DB"
  - "comandos [C++], Modelos de consumidor de banco de dados OLE"
  - "Classe CTable"
  - "Modelos de consumidor OLE DB, suporte a comandos"
  - "Modelos de consumidor OLE DB, suporte a tabelas"
  - "conjuntos de linhas, acessando"
  - "tabelas [C++], Modelos de consumidor de banco de dados OLE"
ms.assetid: 4bd3787b-6d26-40a9-be0c-083080537c12
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Comandos e tabelas
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os comandos e as tabelas permitem que você acesse conjuntos de linhas; ou seja, abrir os conjuntos de linhas, execute comandos, e colunas de associação.  As classes de [CCommand](../../data/oledb/ccommand-class.md) e de [CTable](../../data/oledb/ctable-class.md) cria uma instância dos objetos de comando e da tabela, respectivamente.  Essas classes derivam\-se de [CAccessorRowset](../Topic/CAccessorRowset%20Class.md) conforme mostrado na figura a seguir.  
  
 ![De VC&#95;CommandsTables](../../data/oledb/media/vccommandstables.png "vcCommandsTables")  
Classes de comando e da tabela  
  
 Na tabela anterior, `TAccessor` pode ser qualquer tipo de acessador listado em [Tipos de acessador](../../data/oledb/accessors-and-rowsets.md).  *TRowset* pode ser qualquer tipo de conjunto de linhas listado em [Tipos de conjunto de linhas](../../data/oledb/accessors-and-rowsets.md).  *TMultiple* especifica o tipo de resultado \(um único ou vários conjuntos de resultados\).  
  
 [Assistente do consumidor de ATL OLE DB](../../atl/reference/atl-ole-db-consumer-wizard.md) permite especificar se você deseja que um objeto de comando ou de tabela.  
  
-   Para fontes de dados sem comandos, você pode usar a classe de `CTable` .  Use\-a em geral dos conjuntos de linhas simples que não especifica nenhum parâmetro e não requer nenhum resultado de multiple.  Essa classe simples abre uma tabela em uma fonte de dados usando um nome da tabela que você especifica.  
  
-   Para fontes de dados que oferecem suporte a comandos, você pode usar a classe de `CCommand` em vez disso.  Para executar um comando, chame [Abrir](../../data/oledb/ccommand-open.md) nessa classe.  Como alternativa, você pode chamar `Prepare` para preparar um comando que você deseja executar mais de uma vez.  
  
     **CCommand** tem três argumentos do modelo: um tipo de acessador, um tipo de conjunto de linhas, e um tipo de resultado \(`CNoMultipleResults`, por padrão, ou `CMultipleResults`\).  Se você especificar `CMultipleResults`, a classe de `CCommand` oferece suporte à interface de **IMultipleResults** e gerencia vários conjuntos de linhas.  O exemplo de [DBVIEWER](http://msdn.microsoft.com/pt-br/07620f99-c347-4d09-9ebc-2459e8049832) mostra como tratar vários resultados.  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)