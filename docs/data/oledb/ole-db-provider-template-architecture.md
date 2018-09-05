---
title: Arquitetura do modelo de provedor do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB [C++], object model
- architecture [C++], OLE DB Provider
- OLE DB provider templates, object model
ms.assetid: 639304a3-f9e0-44dc-8d0c-0ebd2455b363
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ebebb7f69239b62cf276e955fd6e54ef0cf37ea4
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43684284"
---
# <a name="ole-db-provider-template-architecture"></a>Arquitetura de modelo do provedor de banco de dados OLE
## <a name="data-sources-and-sessions"></a>Origens de dados e sessões  
 A arquitetura do provedor OLE DB inclui um objeto de fonte de dados e uma ou mais sessões. O objeto de fonte de dados é o objeto inicial que deve criar uma instância de cada provedor. Quando um aplicativo de consumidor precisa de dados, ele conjunta cria o objeto de fonte de dados para iniciar o provedor. O objeto de fonte de dados cria um objeto de sessão (usando o `IDBCreateSession` interface) por meio do qual o consumidor conecta-se ao objeto de fonte de dados. Programadores ODBC podem pensar que o objeto de fonte de dados como sendo o equivalente para o `HENV` e o objeto de sessão como equivalente ao `HDBC`.  
  
 ![Arquitetura de provedor](../../data/oledb/media/vc4twb1.gif "vc4twb1")  
  
 Junto com os arquivos de origem criados pelo OLE DB Provider assistente, os modelos OLE DB implementam um objeto de fonte de dados. Uma sessão é um objeto que corresponde ao OLE DB `TSession`.  
  
## <a name="mandatory-and-optional-interfaces"></a>Interfaces obrigatórias e opcionais  
 Os modelos de provedor do OLE DB oferecem implementações pré-empacotados para todas as interfaces necessárias. As interfaces obrigatórias e opcionais são definidas por OLE DB para vários tipos de objetos:  
  
-   [Fonte de dados](../../data/oledb/data-source-object-interfaces.md)  
  
-   [Sessão](../../data/oledb/session-object-interfaces.md)  
  
-   [Rowset](../../data/oledb/rowset-object-interfaces.md)  
  
-   [Comando](../../data/oledb/command-object-interfaces.md)  
  
-   [Transação](../../data/oledb/transaction-object-interfaces.md)  
  
 Observe que os modelos de provedor do OLE DB não implementam os objetos de armazenamento e de linha.  
  
 A tabela a seguir lista as interfaces obrigatórias e opcionais para os objetos listados acima, acordo com o [OLE DB 2.6 documentação do SDK](/previous-versions/windows/desktop/ms722784\(v=vs.85\)).  
  
|Componente|Interface|Comentário|  
|---------------|---------------|-------------|  
|[Fonte de dados](../../data/oledb/data-source-object-interfaces.md) ([CDataSource](../../data/oledb/cdatasource-class.md))|[obrigatório] `IDBCreateSession`<br /><br /> [obrigatório] `IDBInitialize`<br /><br /> [obrigatório] `IDBProperties`<br /><br /> [obrigatório] `IPersist`<br /><br /> [opcional] `IConnectionPointContainer`<br /><br /> [opcional] `IDBAsynchStatus`<br /><br /> [opcional] `IDBDataSourceAdmin`<br /><br /> [opcional] `IDBInfo`<br /><br /> [opcional] `IPersistFile`<br /><br /> [opcional] `ISupportErrorInfo`|Conexão do consumidor para o provedor. O objeto é usado para especificar as propriedades em que a conexão, como nome de fonte de dados, a senha e a ID de usuário. O objeto também pode ser usado para administrar uma fonte de dados (criar, atualizar, excluir, tabelas e assim por diante).|  
|[Sessão](../../data/oledb/session-object-interfaces.md) ([CSession](../../data/oledb/cdataconnection-operator-csession-amp.md))|[obrigatório] `IGetDataSource`<br /><br /> [obrigatório] `IOpenRowset`<br /><br /> [obrigatório] `ISessionProperties`<br /><br /> [opcional] `IAlterIndex`<br /><br /> [opcional] `IAlterTable`<br /><br /> [opcional] `IBindResource`<br /><br /> [opcional] `ICreateRow`<br /><br /> [opcional] `IDBCreateCommand`<br /><br /> [opcional] `IDBSchemaRowset`<br /><br /> [opcional] `IIndexDefinition`<br /><br /> [opcional] `ISupportErrorInfo`<br /><br /> [opcional] `ITableCreation`<br /><br /> [opcional] `ITableDefinition`<br /><br /> [opcional] `ITableDefinitionWithConstraints`<br /><br /> [opcional] `ITransaction`<br /><br /> [opcional] `ITransactionJoin`<br /><br /> [opcional] `ITransactionLocal`<br /><br /> [opcional] `ITransactionObject`|O objeto de sessão representa uma única conversa entre um consumidor e provedor. Ele é um pouco semelhante ao ODBC `HSTMT` em que pode haver muitas sessões simultâneas do Active Directory.<br /><br /> O objeto de sessão é o link principal para obter a funcionalidade de OLE DB. Para obter um comando, a transação ou o objeto de conjunto de linhas, percorrer o objeto de sessão.|  
|[Rowset](../../data/oledb/rowset-object-interfaces.md) ([CRowset](../../data/oledb/crowset-class.md))|[obrigatório] `IAccessor`<br /><br /> [obrigatório] `IColumnsInfo`<br /><br /> [obrigatório] `IConvertType`<br /><br /> [obrigatório] `IRowset`<br /><br /> [obrigatório] `IRowsetInfo`<br /><br /> [opcional] `IChapteredRowset`<br /><br /> [opcional] `IColumnsInfo2`<br /><br /> [opcional] `IColumnsRowset`<br /><br /> [opcional] `IConnectionPointContainer`<br /><br /> [opcional] `IDBAsynchStatus`<br /><br /> [opcional] `IGetRow`<br /><br /> [opcional] `IRowsetChange`<br /><br /> [opcional] `IRowsetChapterMember`<br /><br /> [opcional] `IRowsetCurrentIndex`<br /><br /> [opcional] `IRowsetFind`<br /><br /> [opcional] `IRowsetIdentity`<br /><br /> [opcional] `IRowsetIndex`<br /><br /> [opcional] `IRowsetLocate`<br /><br /> [opcional] `IRowsetRefresh`<br /><br /> [opcional] `IRowsetScroll`<br /><br /> [opcional] `IRowsetUpdate`<br /><br /> [opcional] `IRowsetView`<br /><br /> [opcional] `ISupportErrorInfo`<br /><br /> [opcional] `IRowsetBookmark`|O objeto de conjunto de linhas representa os dados da fonte de dados. O objeto é responsável pelas associações de dados e todas as operações básicas (atualização, fetch, movimentação e outros) nos dados. Você sempre tem um objeto de conjunto de linhas para conter e manipular dados.|  
|[Comando](../../data/oledb/command-object-interfaces.md) ([CCommand](ccommand-class.md))|[obrigatório] `IAccessor`<br /><br /> [obrigatório] `IColumnsInfo`<br /><br /> [obrigatório] `ICommand`<br /><br /> [obrigatório] `ICommandProperties`<br /><br /> [obrigatório] `ICommandText`<br /><br /> [obrigatório] `IConvertType`<br /><br /> [opcional] `IColumnsRowset`<br /><br /> [opcional] `ICommandPersist`<br /><br /> [opcional] `ICommandPrepare`<br /><br /> [opcional] `ICommandWithParameters`<br /><br /> [opcional] `ISupportErrorInfo`<br /><br /> [opcional] `ICommandStream`|O objeto de comando manipula operações nos dados, como consultas. Ele pode lidar com as instruções com parâmetros ou sem parâmetros.<br /><br /> O objeto de comando também é responsável por gerenciar associações de parâmetros e colunas de saída. Uma associação é uma estrutura que contém informações sobre como uma coluna, em um conjunto de linhas deve ser recuperada. Ele contém informações como status, tipo de dados, comprimento e ordinal.|  
|[Transação](../../data/oledb/transaction-object-interfaces.md) (opcional)|[obrigatório] `IConnectionPointContainer`<br /><br /> [obrigatório] `ITransaction`<br /><br /> [opcional] `ISupportErrorInfo`|O objeto de transação define uma unidade atômica de trabalho em uma fonte de dados e determina como as unidades de trabalho se relacionam entre si. Esse objeto não é compatível diretamente pelos modelos de provedor do OLE DB (ou seja, você cria seu próprio objeto).|  
  
 Para mais informações, consulte os seguintes tópicos:  
  
-   [Mapas de propriedade](../../data/oledb/property-maps.md)  
  
-   [O registro do usuário](../../data/oledb/user-record.md)  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Interfaces OLE DB](/previous-versions/windows/desktop/ms709709\(v=vs.85\))