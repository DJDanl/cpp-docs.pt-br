---
title: "Arquitetura de modelo do provedor de banco de dados OLE | Microsoft Docs"
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
  - "arquitetura [C++], Provedor OLE DB"
  - "OLE DB [C++], modelo de objeto"
  - "modelos de provedor do OLE DB, modelo de objeto"
ms.assetid: 639304a3-f9e0-44dc-8d0c-0ebd2455b363
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquitetura de modelo do provedor de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Fontes de dados e sessões  
 A arquitetura do provedor OLE DB inclui um objeto de fonte de dados e uma ou mais sessões.  O objeto de fonte de dados é o objeto inicial que cada provedor deve criar uma instância.  Quando um aplicativo do consumidor precisa de dados, ou cria o objeto de fonte de dados para iniciar o provedor.  O objeto de fonte de dados cria um objeto de sessão \(usando a interface de **IDBCreateSession** \) pelos quais o consumidor se conecta ao objeto de fonte de dados.  Os desenvolvedores de ODBC podem pensar no objeto de fonte de dados como sendo equivalentes a **HENV** e do objeto de sessão como equivalente a **HDBC**.  
  
 ![Gráfico da arquitetura do provedor](../../data/oledb/media/vc4twb1.png "vc4TWB1")  
  
 Junto com os arquivos de origem criados pelo assistente do provedor OLE DB, os modelos OLE DB implementam um objeto de fonte de dados.  Uma sessão é um objeto OLE DB que corresponde a **TSession**.  
  
## Interfaces obrigatórias e opcionais  
 O provedor OLE DB que os modelos apresentam o pré\-embalou implementações de todas as interfaces necessárias.  As interfaces obrigatórias e opcionais estão definidas pelo OLE DB para vários tipos de objetos:  
  
-   [Fonte de dados](../../data/oledb/data-source-object-interfaces.md)  
  
-   [Session](../../data/oledb/session-object-interfaces.md)  
  
-   [Conjunto de linhas](../Topic/Rowset%20Object%20Interfaces.md)  
  
-   [Comando](../../data/oledb/command-object-interfaces.md)  
  
-   [Transação](../../data/oledb/transaction-object-interfaces.md)  
  
 Observe que os modelos do provedor OLE DB não implementam os objetos de linha e de armazenamento.  
  
 A tabela a seguir lista as interfaces obrigatórias e opcionais para os objetos listados acima, de acordo com [Documentação de OLE DB SDK 2,6](https://msdn.microsoft.com/en-us/library/ms722784.aspx).  
  
|Componente|Interface|Comment|  
|----------------|---------------|-------------|  
|[Fonte de dados](../../data/oledb/data-source-object-interfaces.md) \([CDataSource](../Topic/CDataSource%20Class.md)\)|obrigatório **IDBCreateSession**\[\]<br /><br /> obrigatório **IDBInitialize**\[\]<br /><br /> obrigatório `IDBProperties`\[\]<br /><br /> obrigatório `IPersist`\[\]<br /><br /> **IConnectionPointContainer**\[opcional\]<br /><br /> **IDBAsynchStatus**\[opcional\]<br /><br /> **IDBDataSourceAdmin**\[opcional\]<br /><br /> **IDBInfo**\[opcional\]<br /><br /> `IPersistFile`\[opcional\]<br /><br /> **ISupportErrorInfo**\[opcional\]|Conexão do consumidor do provedor.  O objeto é usado para especificar propriedades na conexão como a ID do usuário, senha, e o nome da fonte de dados.  O objeto também pode ser usado para administrar uma fonte de dados \(criar, atualizar, excluir, tabelas, e assim por diante\).|  
|[Sessão](../../data/oledb/session-object-interfaces.md) \([CSession](../../data/oledb/cdataconnection-operator-csession-amp.md)\)|obrigatório **IGetDataSource**\[\]<br /><br /> obrigatório `IOpenRowset`\[\]<br /><br /> obrigatório **ISessionProperties**\[\]<br /><br /> **IAlterIndex**\[opcional\]<br /><br /> **IAlterTable**\[opcional\]<br /><br /> **IBindResource**\[opcional\]<br /><br /> **ICreateRow**\[opcional\]<br /><br /> **IDBCreateCommand**\[opcional\]<br /><br /> **IDBSchemaRowset**\[opcional\]<br /><br /> **IIndexDefinition**\[opcional\]<br /><br /> **ISupportErrorInfo**\[opcional\]<br /><br /> **ITableCreation**\[opcional\]<br /><br /> **ITableDefinition**\[opcional\]<br /><br /> **ITableDefinitionWithConstraints**\[opcional\]<br /><br /> **ITransaction**\[opcional\]<br /><br /> **ITransactionJoin**\[opcional\]<br /><br /> **ITransactionLocal**\[opcional\]<br /><br /> **ITransactionObject**\[opcional\]|O objeto de sessão representa uma única conversa entre um consumidor e um provedor.  É um pouco semelhante ao ODBC **HSTMT** no que pode haver muitas sessões simultâneas ativas.<br /><br /> O objeto de sessão é o link primário para obter à funcionalidade OLE DB.  Para obter a um comando, transações, ou objeto de conjunto de linhas, você deve passar pelo objeto de sessão.|  
|[Conjunto de linhas](../Topic/Rowset%20Object%20Interfaces.md) \([CRowset](../Topic/CRowset%20Class.md)\)|obrigatório `IAccessor`\[\]<br /><br /> obrigatório `IColumnsInfo`\[\]<br /><br /> obrigatório **IConvertType**\[\]<br /><br /> obrigatório `IRowset`\[\]<br /><br /> obrigatório `IRowsetInfo`\[\]<br /><br /> **IChapteredRowset**\[opcional\]<br /><br /> **IColumnsInfo2**\[opcional\]<br /><br /> **IColumnsRowset**\[opcional\]<br /><br /> **IConnectionPointContainer**\[opcional\]<br /><br /> **IDBAsynchStatus**\[opcional\]<br /><br /> **IGetRow**\[opcional\]<br /><br /> `IRowsetChange`\[opcional\]<br /><br /> **IRowsetChapterMember**\[opcional\]<br /><br /> **IRowsetCurrentIndex**\[opcional\]<br /><br /> **IRowsetFind**\[opcional\]<br /><br /> **IRowsetIdentity**\[opcional\]<br /><br /> **IRowsetIndex**\[opcional\]<br /><br /> `IRowsetLocate`\[opcional\]<br /><br /> **IRowsetRefresh**\[opcional\]<br /><br /> `IRowsetScroll`\[opcional\]<br /><br /> `IRowsetUpdate`\[opcional\]<br /><br /> **IRowsetView**\[opcional\]<br /><br /> **ISupportErrorInfo**\[opcional\]<br /><br /> **IRowsetBookmark**\[opcional\]|O objeto de conjunto de linhas representa os dados da fonte de dados.  O objeto é responsável pelas associações desses dados e todas as operações básicas \(atualização, busca, mover, entre outros\) nos dados.  Você sempre tem um objeto de conjunto de linhas contenha e manipular dados.|  
|[Comando](../../data/oledb/command-object-interfaces.md) \([CCommand](http://msdn.microsoft.com/pt-br/52bef5da-c1a0-4223-b4e6-9e464b6db409)\)|obrigatório `IAccessor`\[\]<br /><br /> obrigatório `IColumnsInfo`\[\]<br /><br /> obrigatório `ICommand`\[\]<br /><br /> obrigatório **ICommandProperties**\[\]<br /><br /> obrigatório `ICommandText`\[\]<br /><br /> obrigatório **IConvertType**\[\]<br /><br /> **IColumnsRowset**\[opcional\]<br /><br /> **ICommandPersist**\[opcional\]<br /><br /> **ICommandPrepare**\[opcional\]<br /><br /> `ICommandWithParameters`\[opcional\]<br /><br /> **ISupportErrorInfo**\[opcional\]<br /><br /> **ICommandStream**\[opcional\]|As operações de identificadores de objeto de comando em dados como consultas.  Pode tratar instruções com parâmetros ou não com parâmetros.<br /><br /> O objeto de comando também é responsável para tratar associações de parâmetros e colunas de saída.  Uma associação é uma estrutura que contém informações sobre como uma coluna, um conjunto de linhas, deve ser recuperada.  Contém informações como o ordinal, o tipo de dados, comprimento, e o status.|  
|[Transação](../../data/oledb/transaction-object-interfaces.md) \(opcional\)|obrigatório **IConnectionPointContainer**\[\]<br /><br /> obrigatório **ITransaction**\[\]<br /><br /> **ISupportErrorInfo**\[opcional\]|O objeto de transação define uma unidade atômica de trabalho em uma fonte de dados e determina como as unidades de trabalho relacionam\-se entre si.  Esse objeto não tem suporte diretamente pelos modelos do provedor OLE DB \(isto é, você criar seu próprio objeto\).|  
  
 Para obter mais informações, consulte os seguintes tópicos:  
  
-   [Mapas da propriedade](../../data/oledb/property-maps.md)  
  
-   [O registro de usuário](../../data/oledb/user-record.md)  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [OLE DB Interfaces](https://msdn.microsoft.com/en-us/library/ms709709.aspx)