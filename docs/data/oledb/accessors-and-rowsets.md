---
title: Acessadores e conjuntos de linhas
ms.date: 11/19/2018
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
ms.openlocfilehash: 45180b3ac2647c9f4f5d25a1322794552bd79004
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212375"
---
# <a name="accessors-and-rowsets"></a>Acessadores e conjuntos de linhas

Para definir e recuperar dados, OLE DB modelos usam um acessador e um conjunto de linhas por meio da classe [CAccessorRowset](../../data/oledb/caccessorrowset-class.md) . Essa classe pode lidar com vários acessadores de tipos diferentes.

## <a name="accessor-types"></a>Tipos de acessadores

Todos os acessadores derivam de [CAccessorBase](../../data/oledb/caccessorbase-class.md). `CAccessorBase` fornece a associação de parâmetro e coluna.

A figura a seguir mostra os tipos de acessadores.

![Tipos de acessadores](../../data/oledb/media/vcaccessortypes.gif "Tipos de acessadores")<br/>
Classes de acessador

- [CAccessor](../../data/oledb/caccessor-class.md) Use esse acessador quando souber a estrutura da origem do banco de dados em tempo de design. `CAccessor` associa estaticamente um registro de banco de dados, que contém o buffer, à fonte de dado.

- [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) Use esse acessador quando você não souber a estrutura do banco de dados em tempo de design. `CDynamicAccessor` chama `IColumnsInfo::GetColumnInfo` para obter as informações da coluna de banco de dados. Ele cria e gerencia um acessador e o buffer.

- [CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md) Use este acessador para manipular tipos de comando desconhecidos. Quando você preparar os comandos, `CDynamicParameterAccessor` poderá obter informações de parâmetro da interface `ICommandWithParameters`, se o provedor oferecer suporte a `ICommandWithParameters`.

- [CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md), [CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)e [CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md) usam essas classes quando você não tem conhecimento do esquema de banco de dados. `CDynamicStringAccessorA` recupera dados como cadeias de caracteres ANSI; `CDynamicStringAccessorW` recupera dados como cadeias de caracteres Unicode.

- [CManualAccessor](../../data/oledb/cmanualaccessor-class.md) Com essa classe, você pode usar quaisquer tipos de dados que desejar se o provedor puder converter o tipo. Ele lida com colunas de resultado e parâmetros de comando.

A tabela a seguir resume o suporte nos tipos de acessador do modelo OLE DB.

|Tipo de acessador|Dinâmico|Manipula params|Buffer|Vários acessadores|
|-------------------|-------------|--------------------|------------|------------------------|
|`CAccessor`|Não|Sim|Usuário|Sim|
|`CDynamicAccessor`|Sim|Não|Modelos de banco de dados OLE|Não|
|`CDynamicParameterAccessor`|Sim|Sim|Modelos de banco de dados OLE|Não|
|`CDynamicStringAccessor[A,W]`|Sim|Não|Modelos de banco de dados OLE|Não|
|`CManualAccessor`|Sim|Sim|Usuário|Sim|

## <a name="rowset-types"></a>Tipos de conjunto de linhas

Os modelos de OLE DB dão suporte a três tipos de conjuntos de linhas (consulte a figura anterior): conjuntos de linhas únicos (implementados por [CRowset](../../data/oledb/crowset-class.md)), conjuntos de linhas em massa (implementados por [CBulkRowset](../../data/oledb/cbulkrowset-class.md)) e conjuntos de linhas de matriz (implementados por [CArrayRowset](../../data/oledb/carrayrowset-class.md)). Conjuntos de linhas únicos buscam um único identificador de linha quando `MoveNext` é chamado. Conjuntos de linhas em massa podem buscar vários identificadores de linha. Conjuntos de linhas de matriz são conjuntos de linhas que podem ser acessados usando a sintaxe de matriz.

A figura a seguir mostra os tipos de conjunto de linhas.

![Gráfico de conjunto de linhas](../../data/oledb/media/vcrowsettypes.gif "Gráfico de RowsetType")<br/>
Classes de conjunto de linhas

[Conjuntos](../../data/oledb/obtaining-metadata-with-schema-rowsets.md) de linhas de esquema não acessam dados no armazenamento de dados, mas, em vez disso, acessam informações sobre o armazenamento de dados, chamados metadados. Conjuntos de linhas de esquema normalmente são usados em situações em que a estrutura do banco de dados não é conhecida no momento da compilação e deve ser obtida em tempo de execução.

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)
