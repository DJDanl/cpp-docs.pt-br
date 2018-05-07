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
ms.openlocfilehash: 36c74ec0d17c296707334930736d0cf237ecfe7e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="using-an-existing-ado-recordset"></a>Usando um conjunto de registros ADO existente
Para criar modelos de consumidor OLE DB e Active Data Objects (ADO), use o ADO para abrir um conjunto de registros (correspondente a um conjunto de linhas em que os modelos de consumidor de banco de dados OLE). Quando você tiver um conjunto de registros, faça o seguinte para conectar a um conjunto de linhas do OLE DB:  
  
1.  Chamar `QueryInterface` para o `IRowset` e `IAccessor` ponteiros.  
  
    ```  
    IRowset* lpRowset = NULL;  
    IAccessor* lpAccessor = NULL;  
    lpUnk->QueryInterface(IID_IRowset, (void**)&lpRowset);  
    lpUnk->QueryInterface(IID_IAccessor, (void**)&lpAccessor);  
    ```  
  
    > [!NOTE]
    >  *lpUnk* aponta para o **IUnknown** objeto do conjunto de registros ADO.  
  
2.  Anexe o conjunto de linhas e o acessador para suas classes de modelo de consumidor OLE DB apropriados.  
  
    ```  
    CRowset rs;  
    CAccessor accessor;  
  
    accessor.AddAccessorInfo(0ul);      // 0 is the ordinal of an ADO accessor  
    rs.m_spRowset.Attach(lpRowset);      // use the Attach method of CComPtr<>  
    rs.SetAccessor(accessor);  
    ```  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)