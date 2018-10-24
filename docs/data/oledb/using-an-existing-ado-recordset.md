---
title: Usando um conjunto de registros ADO existente | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ADO recordsets [C++]
- OLE DB consumer templates, ADO recordsets
- recordsets [C++], using in OLE DB
ms.assetid: a9b1de8a-d379-49b1-a26e-578741e9f6a8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4dd8c62e376b3e160dcc0b6a5da9e2eb0b28cf8c
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49989951"
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