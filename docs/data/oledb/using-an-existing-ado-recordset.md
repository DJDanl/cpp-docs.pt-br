---
title: Usando um conjunto de registros ADO existente
ms.date: 11/04/2016
helpviewer_keywords:
- ADO recordsets [C++]
- OLE DB consumer templates, ADO recordsets
- recordsets [C++], using in OLE DB
ms.assetid: a9b1de8a-d379-49b1-a26e-578741e9f6a8
ms.openlocfilehash: eb558bb319bb5ddb61d0383846099d708f99c627
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59030469"
---
# <a name="using-an-existing-ado-recordset"></a>Usando um conjunto de registros ADO existente

Para combinar modelos de consumidor OLE DB e o Active Directory Data Objects (ADO), use o ADO para abrir um conjunto de registros (correspondente a um conjunto de linhas em que os modelos de consumidor de banco de dados OLE). Quando você tem um conjunto de registros, faça o seguinte para se conectar a um conjunto de linhas do OLE DB:

1. Chame `QueryInterface` para o `IRowset` e `IAccessor` ponteiros.

    ```cpp
    IRowset* lpRowset = NULL;
    IAccessor* lpAccessor = NULL;
    lpUnk->QueryInterface(IID_IRowset, (void**)&lpRowset);
    lpUnk->QueryInterface(IID_IAccessor, (void**)&lpAccessor);
    ```

    > [!NOTE]
    > *lpUnk* aponta para o `IUnknown` objeto do conjunto de registros ADO.

1. Anexe o conjunto de linhas e o acessador às suas classes de modelo de consumidor OLE DB apropriados.

    ```cpp
    CRowset rs;
    CAccessor accessor;

    accessor.AddAccessorInfo(0ul);      // 0 is the ordinal of an ADO accessor
    rs.m_spRowset.Attach(lpRowset);      // use the Attach method of CComPtr<>
    rs.SetAccessor(accessor);
    ```

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)