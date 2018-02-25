---
title: "Referência de modelos de consumidor OLE DB | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc-attr.db_param
- vc-attr.db_column
- vc-attr.db_accessor
- vc-attr.db_command
- vc-attr.db_table
- vc.templates.ole
- vc-attr.db_source
dev_langs:
- C++
helpviewer_keywords:
- OLE DB consumer templates, classes
ms.assetid: cfc7f698-1a0e-4a09-a4d3-ccb99e6654fe
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 29f833f6a598b9028506fb11d163be49212bd998
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ole-db-consumer-templates-reference"></a>Referência dos modelos de consumidor de banco de dados OLE
O OLE DB modelos de consumidor contém as classes a seguir. O material de referência também inclui tópicos sobre o [macros para modelos OLE DB consumidor](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md).  
  
## <a name="session-classes"></a>Classes de sessão  
 [CDataConnection](../../data/oledb/cdataconnection-class.md)  
 Gerencia a conexão com a fonte de dados. Esta é uma classe útil para criar clientes porque ele encapsula os objetos necessários (fonte de dados e sessão) e parte do trabalho que você precisa fazer ao se conectar a uma fonte de dados.  
  
 [CDataSource](../../data/oledb/cdatasource-class.md)  
 Corresponde a um objeto de fonte de dados OLE DB, que representa uma conexão por meio de um provedor para uma fonte de dados. Uma ou mais sessões banco de dados, cada representado por um `CSession` de objeto, podem ocorrer em uma única conexão.  
  
 [CEnumerator](../../data/oledb/cenumerator-class.md)  
 Corresponde a um objeto de enumerador de OLE DB, que recupera informações de conjunto de linhas sobre fontes de dados disponíveis.  
  
 [CEnumeratorAccessor](../../data/oledb/cenumeratoraccessor-class.md)  
 Usado por `CEnumerator` para acessar os dados do conjunto de linhas do enumerador. Esse conjunto de linhas consiste nas fontes de dados e enumeradores visíveis do enumerador atual.  
  
 [CSession](../../data/oledb/csession-class.md)  
 Representa uma sessão de acesso único banco de dados. Uma ou mais sessões podem ser associadas a cada `CDataSource` objeto.  
  
## <a name="accessor-classes"></a>Classes de acessador  
 [CAccessor](../../data/oledb/caccessor-class.md)  
 Usado para registros estaticamente associados a uma fonte de dados. Use essa classe de acessador quando você conhece a estrutura da fonte de dados.  
  
 [CAccessorBase](../../data/oledb/caccessorbase-class.md)  
 Classe base para todas as classes de acessador.  
  
 [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)  
 Um acessador que pode ser criado em tempo de execução, com base nas informações de coluna do conjunto de linhas. Use essa classe para recuperar dados, se você não souber a estrutura da fonte de dados.  
  
 [CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)  
 Um acessador que pode ser usado quando os tipos de comando desconhecidos. Obtém as informações de parâmetro ao chamar o `ICommandWithParameters` interface, se o provedor oferece suporte à interface.  
  
 [CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)  
 Permite que você acesse uma fonte de dados quando você não têm nenhum conhecimento da estrutura subjacente do banco de dados.  
  
 [CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)  
 Semelhante ao `CDynamicStringAccessor` exceto que essa classe solicita dados acessados a partir do repositório de dados como dados de cadeia de caracteres ANSI.  
  
 [CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)  
 Semelhante ao `CDynamicStringAccessor` exceto que essa classe solicita dados acessados a partir do repositório de dados como dados de cadeia de caracteres UNICODE.  
  
 [CManualAccessor](../../data/oledb/cmanualaccessor-class.md)  
 Um acessador com métodos para manipular colunas e parâmetros de comando. Com essa classe, você pode usar qualquer tipo de dados como o provedor pode converter o tipo.  
  
 [CNoAccessor](../../data/oledb/cnoaccessor-class.md)  
 Pode ser usado como um argumento de modelo quando você não deseja que a classe para dar suporte a parâmetros ou colunas de saída.  
  
 [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md)  
 Semelhante ao `CDynamicStringAccessor` exceto que essa classe converte todos os dados acessados do armazenamento de dados como XML formatado dados (marcados).  
  
## <a name="rowset-classes"></a>Classes de conjunto de linhas  
 [CAccessorRowset](../../data/oledb/caccessorrowset-class.md)  
 Encapsula um conjunto de linhas e de seus acessadores associados.  
  
 [CArrayRowset](../../data/oledb/carrayrowset-class.md)  
 Usado para acessar elementos de um conjunto de linhas usando a sintaxe de matriz.  
  
 [CBulkRowset](../../data/oledb/cbulkrowset-class.md)  
 Usado para buscar e manipular linhas em massa recuperando vários identificadores de linha com uma única chamada.  
  
 [CNoRowset](../../data/oledb/cnorowset-class.md)  
 Pode ser usado como um argumento de modelo se o comando não retornar um conjunto de linhas.  
  
 [CRestrictions](../../data/oledb/crestrictions-class.md)  
 Usado para especificar restrições para conjuntos de linhas de esquema.  
  
 [CRowset](../../data/oledb/crowset-class.md)  
 Usado para manipular, definir e recuperar dados do conjunto de linhas.  
  
 [CStreamRowset](../../data/oledb/cstreamrowset-class.md)  
 Retorna um `ISequentialStream` do objeto, em vez de um conjunto de linhas; se você usar o **leitura** método para recuperar dados em formato XML. (SQL Server 2000 tem a formatação, o Observe que esse recurso funciona com o SQL Server 2000 somente).  
  
 [IRowsetNotifyImpl](../../data/oledb/irowsetnotifyimpl-class.md)  
 Fornece uma implementação fictícia para `IRowsetNotify`, com funções vazias para o `IRowsetNotify` métodos `OnFieldChange`, `OnRowChange`, e `OnRowsetChange`.  
  
 [Classes typedef e classes de conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)  
  
 Os modelos OLE DB fornecem um conjunto de classes que correspondem aos conjuntos de linhas de esquema OLE DB.  
  
## <a name="command-classes"></a>Classes de comando  
 [CCommand](../../data/oledb/ccommand-class.md)  
 Usado para definir e executar um comando de OLE DB baseada em parâmetro. Para abrir apenas um conjunto de linhas simple, use `CTable` em vez disso.  
  
 [CMultipleResults](../../data/oledb/cmultipleresults-class.md)  
 Usado como um argumento de modelo para o `CCommand` modelo quando desejar que o comando para lidar com vários conjuntos de resultados.  
  
 [CNoAccessor](../../data/oledb/cnoaccessor-class.md)  
 Usada como um argumento de modelo para classes de modelo, como `CCommand` e `CTable`, que usam um argumento de classe de acessador. Use `CNoAccessor` se você não quiser que a classe para dar suporte a parâmetros ou colunas de saída.  
  
 [CNoMultipleResults](../../data/oledb/cnomultipleresults-class.md)  
 Usado como um argumento de modelo para o `CCommand` modelo quando desejar que o comando para lidar com um único conjunto de linhas. `CNoMultipleResults` é o valor padrão para o argumento de modelo.  
  
 [CNoRowset](../../data/oledb/cnorowset-class.md)  
 Usado como um argumento de template para `CCommand` ou `CTable` se o comando ou a tabela não retornar um conjunto de linhas.  
  
 [CTable](../../data/oledb/ctable-class.md)  
 Usado para acessar um conjunto de linhas simple sem parâmetros.  
  
## <a name="property-classes"></a>Classes de propriedade  
 [CDBPropIDSet](../../data/oledb/cdbpropidset-class.md)  
 Usado para passar uma matriz de IDs de propriedade para o qual o consumidor deseja informações de propriedade. As propriedades pertencem ao conjunto de uma propriedade.  
  
 [CDBPropSet](../../data/oledb/cdbpropset-class.md)  
 Usado para definir propriedades em um provedor.  
  
## <a name="bookmark-class"></a>Classe de indicador  
 [CBookmark](../../data/oledb/cbookmark-class.md)  
 Usado como um índice para acessar dados em um conjunto de linhas.  
  
## <a name="error-class"></a>Classe de erro  
 [CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)  
 Usado para recuperar informações de erro OLE DB.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-reference.md)   
 [Modelos do OLE DB](../../data/oledb/ole-db-templates.md)