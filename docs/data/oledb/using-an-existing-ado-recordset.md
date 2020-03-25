---
title: Usando um conjunto de registros ADO existente
ms.date: 11/04/2016
helpviewer_keywords:
- ADO recordsets [C++]
- OLE DB consumer templates, ADO recordsets
- recordsets [C++], using in OLE DB
ms.assetid: a9b1de8a-d379-49b1-a26e-578741e9f6a8
ms.openlocfilehash: 48f6eb3bac34b37f495b9492e19b4197ed69cca3
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209346"
---
# <a name="using-an-existing-ado-recordset"></a>Usando um conjunto de registros ADO existente

Para misturar OLE DB modelos de consumidor e ADO (Active Data Objects), use o ADO para abrir um conjunto de registros (correspondente a um conjunto de linhas nos modelos de consumidor OLE DB). Quando você tiver um conjunto de registros, faça o seguinte para se conectar a um conjunto de linhas OLE DB:

1. Chame `QueryInterface` para os ponteiros de `IRowset` e `IAccessor`.

    ```cpp
    IRowset* lpRowset = NULL;
    IAccessor* lpAccessor = NULL;
    lpUnk->QueryInterface(IID_IRowset, (void**)&lpRowset);
    lpUnk->QueryInterface(IID_IAccessor, (void**)&lpAccessor);
    ```

    > [!NOTE]
    > *lpUnk* aponta para o objeto `IUnknown` do conjunto de registros ADO.

1. Anexe o acessador e o conjunto de linhas às suas classes de modelo de consumidor OLE DB apropriadas.

    ```cpp
    CRowset rs;
    CAccessor accessor;

    accessor.AddAccessorInfo(0ul);      // 0 is the ordinal of an ADO accessor
    rs.m_spRowset.Attach(lpRowset);      // use the Attach method of CComPtr<>
    rs.SetAccessor(accessor);
    ```

## <a name="see-also"></a>Confira também

[Usando acessadores](../../data/oledb/using-accessors.md)
