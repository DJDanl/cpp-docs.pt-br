---
title: Determinando qual tipo de acessador a ser usado
ms.date: 05/09/2019
helpviewer_keywords:
- rowsets [C++], data types
- accessors [C++], types
ms.assetid: 22483dd2-f4e0-4dcb-8e4d-cd43a9c1a3db
ms.openlocfilehash: d729e2cf5b08ae227d0cc2e4d5ab7f8ac865cdc4
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079652"
---
# <a name="determining-which-type-of-accessor-to-use"></a>Determinando qual tipo de acessador a ser usado

Os tipos de dados em um conjunto de linhas podem ser determinados no tempo de compilação ou de execução.

Se precisar determinar tipos de dados no tempo de compilação, use um acessador estático (como `CAccessor`).

Se precisar determinar os tipos de dados no tempo de execução, use um acessador dinâmico (`CDynamicAccessor` ou seus filhos) ou manual (`CManualAccessor`). Nesses casos, é possível chamar `GetColumnInfo` no conjunto de linhas para retornar as informações de associação de coluna, das quais pode determinar os tipos.

A tabela a seguir lista os tipos dos acessadores fornecidos nos modelos de consumidor. Cada acessador possui vantagens e desvantagens. Dependendo da situação, um tipo de acessador deve atender às suas necessidades.

|Classe de acessador|Associação|Parâmetro|Comentário|
|--------------------|-------------|---------------|-------------|
|`CAccessor`|Crie um registro de usuário com macros COLUMN_ENTRY. As macros associam um membro de dados do registro ao acessador. Quando o conjunto de linhas é criado, as colunas não podem ser desvinculadas.|Sim, usando uma entrada de macro PARAM_MAP. Uma vez associados, os parâmetros não podem ser desvinculados.|Acessador mais rápido devido à pequena quantidade de código.|
|`CDynamicAccessor`|Automático.|Não.|É útil se você não souber o tipo de dados em um conjunto de linhas.|
|`CDynamicParameterAccessor`|Automático, mas pode ser [substituído](../../data/oledb/overriding-a-dynamic-accessor.md).|Sim, se o provedor for compatível com a `ICommandWithParameters`. Os parâmetros são associados automaticamente.|Mais lento do que `CDynamicAccessor`, mas útil para chamar procedimentos armazenados genéricos.|
|`CDynamicStringAccessor[A,W]`|Automático.|Não.|Recupera os dados acessados do armazenamento como dados de cadeia de caracteres.|
|`CManualAccessor`|Manual ao usar `AddBindEntry`.|Manualmente ao usar `AddParameterEntry`.|Rápido; parâmetros e colunas associados apenas uma vez. Você determina o tipo de dados a usar. (Consulte o exemplo de [DBViewer](https://github.com/Microsoft/VCSamples) para obter um exemplo.) Requer mais código do que `CDynamicAccessor` ou `CAccessor`. É como chamar diretamente o OLE DB.|
|`CXMLAccessor`|Automático.|Não.|Recupera os dados acessados do armazenamento como dados de cadeia de caracteres e os formata como dados marcados com XML.|

## <a name="see-also"></a>Confira também

[Usando acessadores](../../data/oledb/using-accessors.md)