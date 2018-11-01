---
title: Referência dos modelos de consumidor de banco de dados OLE
ms.date: 11/04/2016
f1_keywords:
- vc-attr.db_param
- vc-attr.db_column
- vc-attr.db_accessor
- vc-attr.db_command
- vc-attr.db_table
- vc.templates.ole
- vc-attr.db_source
helpviewer_keywords:
- OLE DB consumer templates, classes
ms.assetid: cfc7f698-1a0e-4a09-a4d3-ccb99e6654fe
ms.openlocfilehash: a476fefa4338e73bf6eaf70fa16a5328a427b56d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50649235"
---
# <a name="ole-db-consumer-templates-reference"></a>Referência dos modelos de consumidor de banco de dados OLE

O OLE DB modelos de consumidor contêm as classes a seguir. O material de referência também inclui tópicos sobre o [macros para OLE DB modelos de consumidor](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md).

## <a name="session-classes"></a>Classes de sessão

[CDataConnection](../../data/oledb/cdataconnection-class.md)<br/>
Gerencia a conexão com a fonte de dados. Essa é uma classe útil para a criação de clientes porque ele encapsula os objetos necessários (fonte de dados e de sessão) e parte do trabalho que você precisa fazer ao se conectar a uma fonte de dados.

[CDataSource](../../data/oledb/cdatasource-class.md)<br/>
Corresponde a um objeto de fonte de dados OLE DB, que representa uma conexão por meio de um provedor para uma fonte de dados. Um ou mais sessões banco de dados, cada um representado por um `CSession` de objeto, podem ocorrer em uma única conexão.

[CEnumerator](../../data/oledb/cenumerator-class.md)<br/>
Corresponde a um objeto de enumerador OLE DB, que recupera informações de conjunto de linhas sobre fontes de dados disponíveis.

[CEnumeratorAccessor](../../data/oledb/cenumeratoraccessor-class.md)<br/>
Usado pelo `CEnumerator` para acessar os dados do conjunto de linhas do enumerador. Esse conjunto de linhas consiste nas fontes de dados e enumeradores visíveis do enumerador atual.

[CSession](../../data/oledb/csession-class.md)<br/>
Representa uma sessão de acesso do banco de dados individual. Uma ou mais sessões podem ser associadas com cada `CDataSource` objeto.

## <a name="accessor-classes"></a>Classes de acessador

[CAccessor](../../data/oledb/caccessor-class.md)<br/>
Usado para registros que são vinculados estaticamente a uma fonte de dados. Use essa classe de acessador quando você conhece a estrutura da fonte de dados.

[CAccessorBase](../../data/oledb/caccessorbase-class.md)<br/>
Classe base para todas as classes de acessador.

[CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
Um acessador que pode ser criado em tempo de execução com base nas informações de coluna do conjunto de linhas. Use essa classe para recuperar dados, se você não souber a estrutura da fonte de dados.

[CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)<br/>
Um acessador que pode ser usado quando os tipos de comando são desconhecidos. Obtém as informações de parâmetro ao chamar o `ICommandWithParameters` da interface, se o provedor oferece suporte à interface.

[CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)<br/>
Permite que você acessar uma fonte de dados quando você não possui conhecimento da estrutura de base do banco de dados.

[CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)<br/>
Semelhante ao `CDynamicStringAccessor` , exceto que essa classe solicita dados acessados do armazenamento de dados como dados de cadeia de caracteres ANSI.

[CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)<br/>
Semelhante ao `CDynamicStringAccessor` , exceto que essa classe solicita dados acessados do armazenamento de dados como dados de cadeia de caracteres UNICODE.

[CManualAccessor](../../data/oledb/cmanualaccessor-class.md)<br/>
Um acessador com métodos para manipular colunas e parâmetros de comando. Com essa classe, você pode usar qualquer tipo de dados desde que o provedor pode converter o tipo.

[CNoAccessor](../../data/oledb/cnoaccessor-class.md)<br/>
Pode ser usado como um argumento de modelo quando você não deseja que a classe para dar suporte a parâmetros ou colunas de saída.

[CXMLAccessor](../../data/oledb/cxmlaccessor-class.md)<br/>
Semelhante ao `CDynamicStringAccessor` , exceto que essa classe converte todos os dados acessados do armazenamento de dados como XML formatado (marcados) dados.

## <a name="rowset-classes"></a>Classes de conjunto de linhas

[CAccessorRowset](../../data/oledb/caccessorrowset-class.md)<br/>
Encapsula um conjunto de linhas e de seus acessadores associados.

[CArrayRowset](../../data/oledb/carrayrowset-class.md)<br/>
Usado para acessar os elementos de um conjunto de linhas usando a sintaxe de matriz.

[CBulkRowset](../../data/oledb/cbulkrowset-class.md)<br/>
Usado para buscar e manipular linhas em massa recuperando vários identificadores de linha com uma única chamada.

[CNoRowset](../../data/oledb/cnorowset-class.md)<br/>
Pode ser usado como um argumento de modelo, se o comando não retornar um conjunto de linhas.

[cRestrictions](../../data/oledb/crestrictions-class.md)<br/>
Usado para especificar restrições para conjuntos de linhas de esquema.

[CRowset](../../data/oledb/crowset-class.md)<br/>
Usado para manipular, definir e recuperar dados do conjunto de linhas.

[CStreamRowset](../../data/oledb/cstreamrowset-class.md)<br/>
Retorna um `ISequentialStream` do objeto em vez de um conjunto de linhas; em seguida, você use o `Read` método para recuperar dados em formato XML. (SQL Server 2000 faz a formatação; Observe que esse recurso funciona com o SQL Server 2000 somente).

[IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md)<br/>
Fornece uma implementação fictícia para `IRowsetNotify`, com funções vazias para o `IRowsetNotify` métodos `OnFieldChange`, `OnRowChange`, e `OnRowsetChange`.

[Classes typedef e classes de conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)

Os modelos OLE DB fornecem um conjunto de classes que correspondem aos conjuntos de linhas de esquema OLE DB.

## <a name="command-classes"></a>Classes de comando

[CCommand](../../data/oledb/ccommand-class.md)<br/>
Usado para definir e executar um comando de OLE DB com base no parâmetro. Para simplesmente abrir um conjunto de linhas simple, use `CTable` em vez disso.

[CMultipleResults](../../data/oledb/cmultipleresults-class.md)<br/>
Usado como um argumento de modelo para o `CCommand` modelo quando desejar que o comando para lidar com vários conjuntos de resultados.

[CNoAccessor](../../data/oledb/cnoaccessor-class.md)<br/>
Usada como um argumento de modelo para classes de modelo, como `CCommand` e `CTable`, que aceitam um argumento de classe de acessador. Use `CNoAccessor` se você não quiser que a classe para dar suporte a parâmetros ou colunas de saída.

[CNoMultipleResults](../../data/oledb/cnomultipleresults-class.md)<br/>
Usado como um argumento de modelo para o `CCommand` modelo quando desejar que o comando para lidar com um único conjunto de linhas. `CNoMultipleResults` é o valor padrão para o argumento de modelo.

[CNoRowset](../../data/oledb/cnorowset-class.md)<br/>
Usado como um argumento de modelo para `CCommand` ou `CTable` se o comando ou a tabela não retornar um conjunto de linhas.

[CTable](../../data/oledb/ctable-class.md)<br/>
Usado para acessar um conjunto de linhas simple sem parâmetros.

## <a name="property-classes"></a>Classes de propriedades

[CDBPropIDSet](../../data/oledb/cdbpropidset-class.md)<br/>
Usado para passar uma matriz de IDs de propriedade para o qual o consumidor deseja informações de propriedade. As propriedades pertencem ao conjunto de uma propriedade.

[CDBPropSet](../../data/oledb/cdbpropset-class.md)<br/>
Usado para definir propriedades em um provedor.

## <a name="bookmark-class"></a>Classe de indicador

[CBookmark](../../data/oledb/cbookmark-class.md)<br/>
Usado como um índice para acessar dados em um conjunto de linhas.

## <a name="error-class"></a>Classe de erro

[CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)<br/>
Usado para recuperar informações de erro OLE DB.

## <a name="see-also"></a>Consulte também

[Referência dos modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-reference.md)<br/>
[Modelos do OLE DB](../../data/oledb/ole-db-templates.md)