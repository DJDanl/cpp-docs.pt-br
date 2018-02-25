---
title: BEGIN_PROPERTY_SET_EX | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- BEGIN_PROPERTY_SET_EX
dev_langs:
- C++
helpviewer_keywords:
- BEGIN_PROPERTY_SET_EX macro
ms.assetid: c95e7fab-edce-47b8-b282-200e53a2ea8a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 46f20308e037942ef3259d930fa89a3e08dca93d
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="beginpropertysetex"></a>BEGIN_PROPERTY_SET_EX
Mapa do conjunto de marcas de que início de uma propriedade definido em uma propriedade.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
BEGIN_PROPERTY_SET_EX(guid  
, flags )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `guid`  
 [in] A propriedade GUID.  
  
 `flags`  
 [in] **UPROPSET_HIDDEN** para quaisquer conjuntos de propriedades que você não deseja expor, ou **UPROPSET_PASSTHROUGH** para um provedor expõe propriedades definidas fora do escopo do provedor.  
  
## <a name="example"></a>Exemplo  
 Consulte [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros para modelos de provedor do OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)