---
title: Determinando qual tipo de acessador a ser usado
ms.date: 10/24/2018
helpviewer_keywords:
- rowsets [C++], data types
- accessors [C++], types
ms.assetid: 22483dd2-f4e0-4dcb-8e4d-cd43a9c1a3db
ms.openlocfilehash: 98234852d0577e581135980d6b8e525aeead5dc2
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59031855"
---
# <a name="determining-which-type-of-accessor-to-use"></a>Determinando qual tipo de acessador a ser usado

Você pode determinar os tipos de dados em um conjunto de linhas em tempo de compilação ou tempo de execução.

Se você precisar determinar tipos de dados em tempo de compilação, use um acessador estática (como `CAccessor`). Você pode determinar os tipos de dados manualmente ou usando o **ATL OLE DB Assistente de consumidor**.

Se você precisar determinar os tipos de dados em tempo de execução, use dinâmico (`CDynamicAccessor` ou seus filhos) ou o acessador manual (`CManualAccessor`). Nesses casos, você pode chamar `GetColumnInfo` no conjunto de linhas para retornar as informações de associação de coluna da qual você pode determinar os tipos.

A tabela a seguir lista os tipos dos acessadores fornecidos nos modelos do consumidor. Cada acessador tem vantagens e desvantagens. Dependendo da sua situação, um tipo de acessador deve atender às suas necessidades.

|Classe de acessador|Associação|Parâmetro|Comentário|
|--------------------|-------------|---------------|-------------|
|`CAccessor`|Crie um registro de usuário com macros COLUMN_ENTRY. As macros de associar um membro de dados no registro para o acessador. Quando o conjunto de linhas é criado, as colunas não podem ser desligadas.|Sim, usando uma entrada de macro PARAM_MAP. Uma vez associado, parâmetros não podem ser desligados.|Acessador mais rápido devido à pequena quantidade de código.|
|`CDynamicAccessor`|Automático.|Nº|É útil se você não souber o tipo de dados em um conjunto de linhas.|
|`CDynamicParameterAccessor`|Automático, mas pode ser [substituído](../../data/oledb/overriding-a-dynamic-accessor.md).|Sim, se o provedor oferece suporte a `ICommandWithParameters`. Os parâmetros associados automaticamente.|Mais lento do que `CDynamicAccessor` , mas útil para chamar procedimentos armazenados genéricos.|
|`CDynamicStringAccessor[A,W]`|Automático.|Nº|Recupera os dados acessados do armazenamento de dados como dados de cadeia de caracteres.|
|`CManualAccessor`|Manual usando `AddBindEntry`.|Manualmente usando `AddParameterEntry`.|Fast; parâmetros e colunas associadas a apenas uma vez. Você determinar o tipo de dados a serem usados. (Consulte [DBVIEWER](https://github.com/Microsoft/VCSamples) exemplo para obter um exemplo.) Requer mais código que `CDynamicAccessor` ou `CAccessor`. É mais semelhante a chamar diretamente o banco de dados OLE.|
|`CXMLAccessor`|Automático.|Nº|Recupera os dados acessados do armazenamento de dados como dados de cadeia de caracteres e formatos de dados marcados como XML.|

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)