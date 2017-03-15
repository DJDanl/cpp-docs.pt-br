---
title: "Refer&#234;ncia dos modelos de consumidor de banco de dados OLE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc-attr.db_param"
  - "vc-attr.db_column"
  - "vc-attr.db_accessor"
  - "vc-attr.db_command"
  - "vc-attr.db_table"
  - "vc.templates.ole"
  - "vc-attr.db_source"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Modelos de consumidor OLE DB, Classes "
ms.assetid: cfc7f698-1a0e-4a09-a4d3-ccb99e6654fe
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Refer&#234;ncia dos modelos de consumidor de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os modelos do consumidor OLE DB contêm as seguintes classes.  Material de referência também inclui tópicos em [macros para modelos do consumidor OLE DB](../Topic/Macros%20and%20Global%20Functions%20for%20OLE%20DB%20Consumer%20Templates.md).  
  
## Classes de sessão  
 [CDataConnection](../../data/oledb/cdataconnection-class.md)  
 Gerencia a conexão com a fonte de dados.  Esta é uma classe útil para criar clientes como encapsula objetos necessários para a fonte de dados \(e\) e qualquer sessão de trabalho que você precisa fazer ao conectar\-se a uma fonte de dados.  
  
 [CDataSource](../Topic/CDataSource%20Class.md)  
 Corresponde a um objeto de fonte de dados OLE DB, representando uma conexão por meio de um provedor com uma fonte de dados.  Uma ou mais sessões do base de dados, cada um representado por um objeto de `CSession` , podem ocorrer em uma única conexão.  
  
 [CEnumerator](../../data/oledb/cenumerator-class.md)  
 Corresponde a um objeto de enumerador do OLE DB, que recupera informações de conjunto de linhas em fontes de dados disponíveis.  
  
 [CEnumeratorAccessor](../../data/oledb/cenumeratoraccessor-class.md)  
 Usado por `CEnumerator` para acessar os dados do conjunto de linhas do enumerador.  Esse conjunto de linhas consiste em fontes de dados e nos enumeradores visíveis do enumerador atual.  
  
 [CSession](../../data/oledb/csession-class.md)  
 Representa uma única sessão de acesso ao base de dados.  Uma ou mais sessões podem ser associadas com cada objeto de `CDataSource` .  
  
## Classes de acessador  
 [CAccessor](../Topic/CAccessor%20Class.md)  
 Usado para os registros que são estatisticamente associados a uma fonte de dados.  Use essa classe do acessador quando você conhece a estrutura da fonte de dados.  
  
 [CAccessorBase](../../data/oledb/caccessorbase-class.md)  
 Classe base para todas as classes do acessador.  
  
 [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)  
 Um acessador que pode ser criado em tempo de execução, com base nas informações de coluna do conjunto de linhas.  Use essa classe para recuperar dados se você não souber a estrutura da fonte de dados.  
  
 [CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)  
 Um acessador que pode ser usado quando os tipos de comando são desconhecidos.  Obtém as informações de parâmetro ao chamar a interface de `ICommandWithParameters` , se o provedor oferece suporte à interface.  
  
 [CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)  
 Permite acessar uma fonte de dados quando você não tem conhecimento da estrutura subjacente da base de dados.  
  
 [CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)  
 Semelhante a `CDynamicStringAccessor` exceto pelo fato dessa classe solicita os dados acessados no repositório de dados como dados de cadeia de caracteres ANSI.  
  
 [CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)  
 Semelhante a `CDynamicStringAccessor` exceto pelo fato dessa classe solicita os dados acessados no repositório de dados como dados de cadeia de caracteres UNICODE.  
  
 [CManualAccessor](../Topic/CManualAccessor%20Class.md)  
 Um acessador com os métodos para tratar colunas e parâmetros do comando.  Com essa classe, você pode usar qualquer tipo de dados como o provedor pode converter o tipo.  
  
 [CNoAccessor](../Topic/CNoAccessor%20Class.md)  
 Pode ser usado como um argumento de modelo quando você não quiser que a classe para oferecer suporte a parâmetros ou colunas de saída.  
  
 [CXMLAccessor](../../data/oledb/cxmlaccessor-class.md)  
 Semelhante a `CDynamicStringAccessor` exceto pelo fato dessa classe converte todos os dados acessados no repositório de dados marcados como dados \(\) em formato XML.  
  
## Classes do conjunto de linhas  
 [CAccessorRowset](../Topic/CAccessorRowset%20Class.md)  
 Encapsula um conjunto de linhas e os acessadores associados.  
  
 [CArrayRowset](../../data/oledb/carrayrowset-class.md)  
 Usado para acessar os elementos de um conjunto de linhas usando a sintaxe da matriz.  
  
 [CBulkRowset](../Topic/CBulkRowset%20Class.md)  
 Usado para buscar e manipular linhas em massa recuperando a vários identificadores de linha com uma única chamada.  
  
 [CNoRowset](../../data/oledb/cnorowset-class.md)  
 Pode ser usado como um argumento de modelo se o comando não retorna um conjunto de linhas.  
  
 [CRestrictions](../Topic/CRestrictions%20Class.md)  
 Usado para especificar restrições para conjuntos de linhas de esquema.  
  
 [CRowset](../Topic/CRowset%20Class.md)  
 Usado para manipular, defina, e recuperar dados do conjunto de linhas.  
  
 [CStreamRowset](../../data/oledb/cstreamrowset-class.md)  
 Retorna um objeto de `ISequentialStream` em vez de um conjunto de linhas; você usa o método de **Ler** para recuperar dados em formato XML. \(O SQL Server 2000 faz a formatação; observe que esse recurso funciona apenas com o SQL Server 2000.\)  
  
 [IRowsetNotifyImpl](../Topic/IRowsetNotifyImpl%20Class.md)  
 Fornece uma implementação fictícia para `IRowsetNotify`, com funções vazias para os métodos `OnFieldChange`, `OnRowChange`, e `OnRowsetChange`de `IRowsetNotify` .  
  
 [Classes do conjunto de linhas de esquema e classes de Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md)  
  
 Os modelos OLE DB fornece um conjunto de classes que correspondem aos conjuntos de linhas de esquema OLE DB.  
  
## Classes de comando  
 [CCommand](../../data/oledb/ccommand-class.md)  
 Usado para definir e executar um comando de base do OLE DB.  Para abrir apenas um conjunto de linhas simples, use `CTable` em vez disso.  
  
 [CMultipleResults](../../data/oledb/cmultipleresults-class.md)  
 Usado como um argumento do modelo para o modelo de `CCommand` quando você quiser que o comando tratar vários conjuntos de resultados.  
  
 [CNoAccessor](../Topic/CNoAccessor%20Class.md)  
 Usado como um argumento do modelo para classes de modelo, como `CCommand` e `CTable`, que possuem um argumento da classe do acessador.  Use `CNoAccessor` se você não quiser que a classe para oferecer suporte a parâmetros ou colunas de saída.  
  
 [CNoMultipleResults](../../data/oledb/cnomultipleresults-class.md)  
 Usado como um argumento do modelo para o modelo de `CCommand` quando você quiser que o comando tratar um único conjunto de linhas.  `CNoMultipleResults` é o valor padrão para o argumento do modelo.  
  
 [CNoRowset](../../data/oledb/cnorowset-class.md)  
 Usado como um argumento do modelo para `CCommand` ou `CTable` se o comando ou tabela não retornam um conjunto de linhas.  
  
 [CTable](../../data/oledb/ctable-class.md)  
 Usado para acessar um conjunto de linhas simples sem parâmetros.  
  
## Classes de propriedade  
 [CDBPropIDSet](../../data/oledb/cdbpropidset-class.md)  
 Usado para passar uma matriz de IDs de propriedade para o consumidor deseja informações da propriedade.  As propriedades pertencem a um conjunto de propriedades.  
  
 [CDBPropSet](../Topic/CDBPropSet%20Class.md)  
 Usado para definir propriedades em um provedor.  
  
## A classe do medidor  
 [CBookmark](../../data/oledb/cbookmark-class.md)  
 Usado como um índice para acessar dados em um conjunto de linhas.  
  
## Classe de erro  
 [CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)  
 Usado para recuperar informações de erro OLE DB.  
  
## Consulte também  
 [Referência dos modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-reference.md)   
 [Modelos de banco de dados OLE](../Topic/OLE%20DB%20Templates.md)