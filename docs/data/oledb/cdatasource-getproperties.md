---
title: 'Cdatasource:: GetProperties | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDataSource::GetProperties
- ATL.CDataSource.GetProperties
- CDataSource.GetProperties
- ATL::CDataSource::GetProperties
- GetProperties
dev_langs:
- C++
helpviewer_keywords:
- GetProperties method
ms.assetid: ffaecc17-9fe7-449e-94d6-43d31ad06cfc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e519504777a1ff9f2927d74340bec73e1b157e6d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33095125"
---
# <a name="cdatasourcegetproperties"></a>CDataSource::GetProperties
Retorna as informações de propriedade solicitadas para o objeto de fonte de dados conectada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
HRESULT GetProperties(ULONG ulPropIDSets,   
   constDBPROPIDSET* pPropIDSet,   
   ULONG* pulPropertySets,   
   DBPROPSET** ppPropsets) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IDBProperties::GetProperties](https://msdn.microsoft.com/en-us/library/ms714344.aspx) no *referência do programador de OLE DB* no SDK do Windows.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Para obter uma única propriedade, use [GetProperty](../../data/oledb/cdatasource-getproperty.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataSource](../../data/oledb/cdatasource-class.md)