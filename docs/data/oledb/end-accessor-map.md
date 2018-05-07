---
title: END_ACCESSOR_MAP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- END_ACCESSOR_MAP
dev_langs:
- C++
helpviewer_keywords:
- END_ACCESSOR_MAP macro
ms.assetid: ede813c7-46c9-48a6-aa1a-8ebf38e92023
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 647e581a86564221ad409caf9addd03ae3d11fb1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="endaccessormap"></a>END_ACCESSOR_MAP
Marca o fim das entradas de mapa de acessador.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
END_ACCESSOR_MAP()  
  
```  
  
## <a name="remarks"></a>Comentários  
 Vários acessadores em um conjunto de linhas, você precisa especificar `BEGIN_ACCESSOR_MAP` e usar o `BEGIN_ACCESSOR` macro cada acessador individuais. O `BEGIN_ACCESSOR` macro é concluída com o `END_ACCESSOR` macro. O `BEGIN_ACCESSOR_MAP` macro é concluída com o `END_ACCESSOR_MAP` macro.  
  
## <a name="example"></a>Exemplo  
 Consulte [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md)   
 [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md)