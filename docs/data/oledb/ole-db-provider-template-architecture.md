---
title: Arquitetura de modelo do provedor de banco de dados OLE
ms.date: 11/19/2018
helpviewer_keywords:
- OLE DB [C++], object model
- architecture [C++], OLE DB Provider
- OLE DB provider templates, object model
ms.assetid: 639304a3-f9e0-44dc-8d0c-0ebd2455b363
ms.openlocfilehash: 89e07f95853c3611b7cceaef3f247c220c630add
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509551"
---
# <a name="ole-db-provider-template-architecture"></a>Arquitetura de modelo do provedor de banco de dados OLE

## <a name="data-sources-and-sessions"></a>Origens de dados e sessões

A arquitetura do provedor de OLE DB inclui um objeto de fonte de dados e uma ou mais sessões. O objeto de fonte de dados é o objeto inicial que cada provedor deve instanciar. Quando um aplicativo de consumidor precisa de dados, ele cocria o objeto de fonte de dados para iniciar o provedor. O objeto de fonte de dados cria um objeto de sessão (usando a `IDBCreateSession` interface) por meio do qual o consumidor se conecta ao objeto de fonte de dados. Os programadores ODBC podem considerar o objeto de fonte de dados como sendo equivalente ao `HENV` e ao objeto de sessão como equivalente ao `HDBC` .

![Arquitetura do provedor](../../data/oledb/media/vc4twb1.gif "Arquitetura do provedor")

Junto com os arquivos de origem criados pelo **Assistente de provedor de OLE DB**, os modelos de OLE DB implementam um objeto de fonte de dados. Uma sessão é um objeto que corresponde à OLE DB `TSession` .

## <a name="mandatory-and-optional-interfaces"></a>Interfaces obrigatórias e opcionais

Os modelos de provedor de OLE DB fornecem implementações predefinidos para todas as interfaces necessárias. As interfaces obrigatórias e opcionais são definidas por OLE DB para vários tipos de objetos:

- [Fonte de dados](../../data/oledb/data-source-object-interfaces.md)

- [Sessão](../../data/oledb/session-object-interfaces.md)

- [Conjunto de linhas](../../data/oledb/rowset-object-interfaces.md)

- [Comando](../../data/oledb/command-object-interfaces.md)

- [Transação](../../data/oledb/transaction-object-interfaces.md)

Os modelos de provedor de OLE DB não implementam os objetos de linha e de armazenamento.

A tabela a seguir lista as interfaces obrigatórias e opcionais para os objetos listados acima, de acordo com a [documentação do SDK do OLE DB 2,6](/previous-versions/windows/desktop/ms722784(v=vs.85)).

|Componente|Interface|Comentário|
|---------------|---------------|-------------|
|[Fonte de dados](../../data/oledb/data-source-object-interfaces.md) ([CDataSource](../../data/oledb/cdatasource-class.md))|obrigatório `IDBCreateSession`<br /><br /> obrigatório `IDBInitialize`<br /><br /> obrigatório `IDBProperties`<br /><br /> obrigatório `IPersist`<br /><br /> adicional `IConnectionPointContainer`<br /><br /> adicional `IDBAsynchStatus`<br /><br /> adicional `IDBDataSourceAdmin`<br /><br /> adicional `IDBInfo`<br /><br /> adicional `IPersistFile`<br /><br /> adicional `ISupportErrorInfo`|Conexão do consumidor para o provedor. O objeto é usado para especificar propriedades na conexão, como ID de usuário, senha e nome da fonte de dados. O objeto também pode ser usado para administrar uma fonte de dados (criar, atualizar, excluir, tabelas e assim por diante).|
|[Sessão](../../data/oledb/session-object-interfaces.md) ([CSession](./cdataconnection-class.md#op_csession_amp))|obrigatório `IGetDataSource`<br /><br /> obrigatório `IOpenRowset`<br /><br /> obrigatório `ISessionProperties`<br /><br /> adicional `IAlterIndex`<br /><br /> adicional `IAlterTable`<br /><br /> adicional `IBindResource`<br /><br /> adicional `ICreateRow`<br /><br /> adicional `IDBCreateCommand`<br /><br /> adicional `IDBSchemaRowset`<br /><br /> adicional `IIndexDefinition`<br /><br /> adicional `ISupportErrorInfo`<br /><br /> adicional `ITableCreation`<br /><br /> adicional `ITableDefinition`<br /><br /> adicional `ITableDefinitionWithConstraints`<br /><br /> adicional `ITransaction`<br /><br /> adicional `ITransactionJoin`<br /><br /> adicional `ITransactionLocal`<br /><br /> adicional `ITransactionObject`|O objeto de sessão é uma única conversa entre um consumidor e um provedor. É semelhante ao ODBC, pois `HSTMT` pode haver muitas sessões simultâneas ativas.<br /><br /> O objeto de sessão é o link principal para obter OLE DB funcionalidade. Para obter um comando, uma transação ou um objeto de conjunto de linhas, você passa pelo objeto de sessão.|
|[Conjunto de linhas](../../data/oledb/rowset-object-interfaces.md) ([CRowset](../../data/oledb/crowset-class.md))|obrigatório `IAccessor`<br /><br /> obrigatório `IColumnsInfo`<br /><br /> obrigatório `IConvertType`<br /><br /> obrigatório `IRowset`<br /><br /> obrigatório `IRowsetInfo`<br /><br /> adicional `IChapteredRowset`<br /><br /> adicional `IColumnsInfo2`<br /><br /> adicional `IColumnsRowset`<br /><br /> adicional `IConnectionPointContainer`<br /><br /> adicional `IDBAsynchStatus`<br /><br /> adicional `IGetRow`<br /><br /> adicional `IRowsetChange`<br /><br /> adicional `IRowsetChapterMember`<br /><br /> adicional `IRowsetCurrentIndex`<br /><br /> adicional `IRowsetFind`<br /><br /> adicional `IRowsetIdentity`<br /><br /> adicional `IRowsetIndex`<br /><br /> adicional `IRowsetLocate`<br /><br /> adicional `IRowsetRefresh`<br /><br /> adicional `IRowsetScroll`<br /><br /> adicional `IRowsetUpdate`<br /><br /> adicional `IRowsetView`<br /><br /> adicional `ISupportErrorInfo`<br /><br /> adicional `IRowsetBookmark`|O objeto Rowset é os dados da fonte de dados. O objeto é usado para as associações desses dados e quaisquer operações básicas (atualização, busca, movimentação e outros) nos dados. Você sempre tem um objeto de conjunto de linhas para manter e manipular dados.|
|[Comando](../../data/oledb/command-object-interfaces.md) ([CCommand](ccommand-class.md))|obrigatório `IAccessor`<br /><br /> obrigatório `IColumnsInfo`<br /><br /> obrigatório `ICommand`<br /><br /> obrigatório `ICommandProperties`<br /><br /> obrigatório `ICommandText`<br /><br /> obrigatório `IConvertType`<br /><br /> adicional `IColumnsRowset`<br /><br /> adicional `ICommandPersist`<br /><br /> adicional `ICommandPrepare`<br /><br /> adicional `ICommandWithParameters`<br /><br /> adicional `ISupportErrorInfo`<br /><br /> adicional `ICommandStream`|O objeto Command manipula operações em dados como consultas. Ele pode manipular instruções parametrizadas ou não parametrizadas.<br /><br /> O objeto Command também é responsável por manipular associações para parâmetros e colunas de saída. Uma associação é uma estrutura que contém informações sobre como uma coluna, em um conjunto de linhas, deve ser recuperada. Ele contém informações como ordinal, tipo de dados, comprimento e status.|
|[Transação](../../data/oledb/transaction-object-interfaces.md) (opcional)|obrigatório `IConnectionPointContainer`<br /><br /> obrigatório `ITransaction`<br /><br /> adicional `ISupportErrorInfo`|O objeto de transação define uma unidade atômica de trabalho em uma fonte de dados e determina como essas unidades de trabalho se relacionam entre si. Esse objeto não tem suporte direto dos modelos de provedor de OLE DB (ou seja, você cria seu próprio objeto).|

Para obter mais informações, consulte estes tópicos:

- [Mapas de propriedades](../../data/oledb/property-maps.md)

- [O registro de usuário](../../data/oledb/user-record.md)

## <a name="see-also"></a>Consulte também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Interfaces OLE DB](/previous-versions/windows/desktop/ms709709(v=vs.85))<br/>
