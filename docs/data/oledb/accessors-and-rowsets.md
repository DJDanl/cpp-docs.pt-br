---
title: Acessadores e conjuntos de linhas | Microsoft Docs
ms.custom: ''
ms.date: 10/22/2018
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
ms.openlocfilehash: c3247cd3b5844df76b8a115a3f28a76874db2a16
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49990172"
---
# <a name="accessors-and-rowsets"></a>Acessadores e conjuntos de linhas

Para definir e recuperar dados, modelos OLE DB é usar um acessador e um conjunto de linhas por meio de [CAccessorRowset](../../data/oledb/caccessorrowset-class.md) classe. Essa classe pode manipular vários acessadores de tipos diferentes.  
  
## <a name="accessor-types"></a>Tipos de acessador  

Todos os acessadores derivam [CAccessorBase](../../data/oledb/caccessorbase-class.md). `CAccessorBase` fornece o parâmetro e a associação de coluna.  
  
A figura a seguir mostra os tipos de acessador.  
  
![Tipos de acessador](../../data/oledb/media/vcaccessortypes.gif "vcaccessortypes")  
Classes de acessador  
  
- [CAccessor](../../data/oledb/caccessor-class.md) usa esse acessador quando você conhece a estrutura da fonte de banco de dados em tempo de design. `CAccessor` vincula estaticamente um registro de banco de dados, que contém o buffer, à fonte de dados.  
  
- [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) usa esse acessador quando você não souber a estrutura do banco de dados em tempo de design. `CDynamicAccessor` chamadas `IColumnsInfo::GetColumnInfo` para obter as informações de coluna do banco de dados. Ele cria e gerencia um acessador e o buffer.  
  
- [CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md) usar esse acessador para lidar com tipos de comando desconhecido. Quando você prepara os comandos `CDynamicParameterAccessor` Obtenha informações de parâmetro do `ICommandWithParameters` interface, se o provedor oferece suporte a `ICommandWithParameters`.  
  
- [CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md), [CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md), e [CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md) usam essas classes quando você não tem nenhum conhecimento sobre o esquema de banco de dados. `CDynamicStringAccessorA` recupera dados como cadeias de caracteres ANSI; `CDynamicStringAccessorW` recupera dados como cadeias de caracteres Unicode.  
  
- [CManualAccessor](../../data/oledb/cmanualaccessor-class.md) com essa classe, você pode usar quaisquer tipos de dados que você deseja se o provedor pode converter o tipo. Ele lida com colunas de resultados e parâmetros de comando.  
  
A tabela a seguir resume o suporte aos tipos de acessador de modelo OLE DB.  
  
|Tipo de acessador|Dinâmico|Identificadores de param. autom.|buffer|Vários acessadores|  
|-------------------|-------------|--------------------|------------|------------------------|  
|`CAccessor`|Não|Sim|User|Sim|  
|`CDynamicAccessor`|Sim|Não|Modelos de banco de dados OLE|Não|  
|`CDynamicParameterAccessor`|Sim|Sim|Modelos de banco de dados OLE|Não|  
|`CDynamicStringAccessor[A,W]`|Sim|Não|Modelos de banco de dados OLE|Não|  
|`CManualAccessor`|Sim|Sim|User|Sim|  
  
## <a name="rowset-types"></a>Tipos de conjunto de linhas  

Os modelos OLE DB dão suporte a três tipos de conjuntos de linhas (consulte a figura anterior): único de conjuntos de linhas (implementado por [CRowset](../../data/oledb/crowset-class.md)), em massa de conjuntos de linhas (implementado por [CBulkRowset](../../data/oledb/cbulkrowset-class.md)) e os conjuntos de linhas (implementados de matriz por [CArrayRowset](../../data/oledb/carrayrowset-class.md)). Busca de conjuntos de linhas únicos lidar com uma única linha quando `MoveNext` é chamado. Conjuntos de linhas em massa podem buscar vários identificadores de linha. Conjuntos de linhas de matriz são conjuntos de linhas que podem ser acessados usando a sintaxe de matriz.  
  
A figura a seguir mostra os tipos de conjunto de linhas.  
  
![Gráfico de RowsetType](../../data/oledb/media/vcrowsettypes.gif "vcrowsettypes")  
Classes de conjunto de linhas  
  
[Conjuntos de linhas de esquema](../../data/oledb/obtaining-metadata-with-schema-rowsets.md) não acessar os dados nos dados de repositório, mas em vez disso, acessar informações sobre o armazenamento de dados, chamada de metadados. Conjuntos de linhas de esquema normalmente são usados em situações nas quais a estrutura de banco de dados não é conhecida em tempo de compilação e deve ser obtida em tempo de execução.  
  
## <a name="see-also"></a>Consulte também  

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)