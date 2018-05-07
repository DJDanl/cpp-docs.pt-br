---
title: Acessadores e conjuntos de linhas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- accessors [C++]
- OLE DB consumer templates, rowset support
- OLE DB consumer templates, accessors
- rowsets [C++], accessing
- bulk rowsets
- CAccessorRowset class, accessor types
- single rowsets
- CArrayRowset class, accessors
- CBulkRowset class, accessors
- array rowsets
- CAccessorBase class
- CRowset class, accessors and rowsets
- accessors [C++], rowsets
- rowsets [C++], supported types
ms.assetid: edc9c8b3-1a2d-4c2d-869f-7e058c631042
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 49f5415f6c75984f968b25fb709c20d80dde554f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="accessors-and-rowsets"></a>Acessadores e conjuntos de linhas
Para definir e recuperar dados, modelos OLE DB é usar um acessador e um conjunto de linhas por meio de [CAccessorRowset](../../data/oledb/caccessorrowset-class.md) classe. Essa classe pode manipular vários acessadores de tipos diferentes.  
  
## <a name="accessor-types"></a>Tipos de acessador  
 Todos os acessadores derivam [CAccessorBase](../../data/oledb/caccessorbase-class.md). `CAccessorBase` fornece o parâmetro e associação de coluna.  
  
 A figura a seguir mostra os tipos de acessador.  
  
 ![Tipos de acessador](../../data/oledb/media/vcaccessortypes.gif "vcaccessortypes")  
Classes de acessador  
  
-   [CAccessor](../../data/oledb/caccessor-class.md) usar esse acessador quando você conhece a estrutura da fonte de banco de dados em tempo de design. `CAccessor` estaticamente associa um registro de banco de dados, que contém o buffer, a fonte de dados.  
  
-   [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) usar esse acessador quando você não souber a estrutura do banco de dados em tempo de design. `CDynamicAccessor` chamadas `IColumnsInfo::GetColumnInfo` para obter as informações de coluna do banco de dados. Cria e gerencia um acessador e o buffer.  
  
-   [CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md) usam esse acessador para lidar com os tipos de comando desconhecido. Quando você prepara os comandos, `CDynamicParameterAccessor` pode obter informações de parâmetro de `ICommandWithParameters` interface, se o provedor oferece suporte a `ICommandWithParameters`.  
  
-   [CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md), [CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md), e [CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md) Use essas classes quando você não possui conhecimento do esquema do banco de dados. `CDynamicStringAccessorA` recupera dados como cadeias de caracteres ANSI; `CDynamicStringAccessorW` recupera dados como cadeias de caracteres Unicode.  
  
-   [CManualAccessor](../../data/oledb/cmanualaccessor-class.md) com essa classe, você pode usar quaisquer tipos de dados você deseja se o provedor pode converter o tipo. Ele trata colunas de resultados e parâmetros de comando.  
  
 A tabela a seguir resume o suporte aos tipos de acessador de modelo de banco de dados OLE.  
  
|Tipo de acessador|Dinâmico|Identificadores de parâmetros|Buffer|Vários acessadores|  
|-------------------|-------------|--------------------|------------|------------------------|  
|`CAccessor`|Não|Sim|User|Sim|  
|`CDynamicAccessor`|Sim|Não|Modelos de banco de dados OLE|Não|  
|`CDynamicParameterAccessor`|Sim|Sim|Modelos de banco de dados OLE|Não|  
|`CDynamicStringAccessor[A,W]`|Sim|Não|Modelos de banco de dados OLE|Não|  
|`CManualAccessor`|Sim|Sim|User|Sim|  
  
## <a name="rowset-types"></a>Tipos de conjunto de linhas  
 Os modelos OLE DB oferecer suporte a três tipos de conjuntos de linhas (consulte a Figura precedente): único conjuntos de linhas (implementado por [CRowset](../../data/oledb/crowset-class.md)), em massa de conjuntos de linhas (implementado por [CBulkRowset](../../data/oledb/cbulkrowset-class.md)) e conjuntos de linhas (implementados de matriz por [CArrayRowset](../../data/oledb/carrayrowset-class.md)). Busca de conjuntos de linhas únicos tratar de uma única linha quando `MoveNext` é chamado. Conjuntos de linhas em massa podem buscar vários identificadores de linha. Conjuntos de linhas de matriz são conjuntos de linhas que podem ser acessados usando a sintaxe de matriz.  
  
 A figura a seguir mostra os tipos de conjunto de linhas.  
  
 ![Gráfico de RowsetType](../../data/oledb/media/vcrowsettypes.gif "vcrowsettypes")  
Classes de conjunto de linhas  
  
 [Conjuntos de linhas de esquema](../../data/oledb/obtaining-metadata-with-schema-rowsets.md) não não acessar dados em dados armazenar mas em vez disso, acessar informações sobre o armazenamento de dados, chamada de metadados. Conjuntos de linhas de esquema normalmente são usados em situações nas quais a estrutura de banco de dados não é conhecida em tempo de compilação e deve ser obtida em tempo de execução.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)