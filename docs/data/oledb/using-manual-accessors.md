---
title: Usando acessadores manuais
ms.date: 10/24/2018
helpviewer_keywords:
- command handling, OLE DB Templates
- manual accessors
- accessors [C++], manual
ms.assetid: 29f00a89-0240-482b-8413-4120b9644672
ms.openlocfilehash: b76c6a2d0af404bc526fee8f511320a58ffd86ec
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218280"
---
# <a name="using-manual-accessors"></a>Usando acessadores manuais

Há quatro coisas a fazer ao manipular um comando desconhecido:

- Determinar os parâmetros

- Executar o comando

- Determinar as colunas de saída

- Veja se há vários conjuntos de linhas de retorno

Para fazer essas coisas com os modelos de consumidor OLE DB, use a `CManualAccessor` classe e siga estas etapas:

1. Abra um `CCommand` objeto com `CManualAccessor` como um parâmetro de modelo.

    ```cpp
    CCommand<CManualAccessor, CRowset, CMultipleResults> rs;
    ```

1. Consulte a sessão para a `IDBSchemaRowset` interface e use o conjunto de linhas de parâmetros de procedimento. Se a `IDBSchemaRowset` interface não estiver disponível, consulte a `ICommandWithParameters` interface. Ligue `GetParameterInfo` para obter informações. Se nenhuma das interfaces estiver disponível, você poderá pressupor que não há parâmetros.

1. Para cada parâmetro, chame `AddParameterEntry` para adicionar os parâmetros e defini-los.

1. Abra o conjunto de linhas, mas defina o parâmetro bind como **`false`** .

1. Chame `GetColumnInfo` para recuperar as colunas de saída. Use `AddBindEntry` para adicionar a coluna de saída à associação.

1. Chame `GetNextResult` para determinar se mais conjuntos de linhas estão disponíveis. Repita as etapas de 2 a 5.

Para obter um exemplo de um acessador manual, consulte `CDBListView::CallProcedure` no exemplo [DBViewer](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Consumer) .

## <a name="see-also"></a>Confira também

[Usando acessadores](../../data/oledb/using-accessors.md)
