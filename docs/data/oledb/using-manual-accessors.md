---
title: Usando acessadores manuais
ms.date: 10/24/2018
helpviewer_keywords:
- command handling, OLE DB Templates
- manual accessors
- accessors [C++], manual
ms.assetid: 29f00a89-0240-482b-8413-4120b9644672
ms.openlocfilehash: a6c0e5236702229a61a828344ba5d0d288898aee
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209314"
---
# <a name="using-manual-accessors"></a>Usando acessadores manuais

Há quatro coisas a fazer ao manipular um comando desconhecido:

- Determinar os parâmetros

- Executar o comando

- Determinar as colunas de saída

- Veja se há vários conjuntos de linhas de retorno

Para fazer essas coisas com os modelos de consumidor OLE DB, use a classe `CManualAccessor` e siga estas etapas:

1. Abra um objeto `CCommand` com `CManualAccessor` como um parâmetro de modelo.

    ```cpp
    CCommand<CManualAccessor, CRowset, CMultipleResults> rs;
    ```

1. Consulte a sessão para obter a interface de `IDBSchemaRowset` e use o conjunto de linhas de parâmetros de procedimento. Se a interface `IDBSchemaRowset` não estiver disponível, consulte a interface `ICommandWithParameters`. Chame `GetParameterInfo` para obter informações. Se nenhuma das interfaces estiver disponível, você poderá pressupor que não há parâmetros.

1. Para cada parâmetro, chame `AddParameterEntry` para adicionar os parâmetros e defini-los.

1. Abra o conjunto de linhas, mas defina o parâmetro bind como **false**.

1. Chame `GetColumnInfo` para recuperar as colunas de saída. Use `AddBindEntry` para adicionar a coluna de saída à associação.

1. Chame `GetNextResult` para determinar se mais conjuntos de linhas estão disponíveis. Repita as etapas de 2 a 5.

Para obter um exemplo de um acessador manual, consulte `CDBListView::CallProcedure` no exemplo [DBViewer](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Consumer) .

## <a name="see-also"></a>Confira também

[Usando acessadores](../../data/oledb/using-accessors.md)
