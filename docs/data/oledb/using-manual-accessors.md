---
title: Usando acessadores manuais | Microsoft Docs
ms.custom: ''
ms.date: 10/24/2018
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- command handling, OLE DB Templates
- manual accessors
- accessors [C++], manual
ms.assetid: 29f00a89-0240-482b-8413-4120b9644672
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d9b65b70473ca415c0f5f48d003faea179ebf27a
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50054977"
---
# <a name="using-manual-accessors"></a>Usando acessadores manuais

Há quatro coisas a fazer ao lidar com um comando desconhecido:

- Determinar os parâmetros

- Execute o comando

- Determinar as colunas de saída

- Verificar se há vários conjuntos de linhas de retornados

Para fazer essas coisas com o OLE DB modelos de consumidor, use o `CManualAccessor` de classe e siga estas etapas:

1. Abra uma `CCommand` do objeto com `CManualAccessor` como um parâmetro de modelo.

    ```cpp
    CCommand<CManualAccessor, CRowset, CMultipleResults> rs;
    ```

1. Consultar a sessão para o `IDBSchemaRowset` de interface e usar o conjunto de linhas de parâmetros de procedimento. Se o `IDBSchemaRowset` interface não estiver disponível, consultar o `ICommandWithParameters` interface. Chamar `GetParameterInfo` para obter informações. Se nenhuma interface estiver disponível, você pode presumir que não existem parâmetros.

1. Para cada parâmetro, chame `AddParameterEntry` para adicionar os parâmetros e defini-las.

1. Abra o conjunto de linhas, mas defina o parâmetro de associação como **falsos**.

1. Chamar `GetColumnInfo` para recuperar as colunas de saída. Use `AddBindEntry` para adicionar a coluna de saída para a associação.

1. Chamar `GetNextResult` para determinar se mais conjuntos de linhas estão disponíveis. Repita as etapas 2 a 5.

Para obter um exemplo de um acessador manual, consulte `CDBListView::CallProcedure` no [DBVIEWER](https://github.com/Microsoft/VCSamples) exemplo.

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)