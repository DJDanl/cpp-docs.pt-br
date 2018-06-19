---
title: NOME DA COLUNA | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- COLUMN_NAME
dev_langs:
- C++
helpviewer_keywords:
- COLUMN_NAME macro
ms.assetid: a213b9a0-2148-4a08-9111-d9fa8fdec462
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f60acfac21e003f6a548c5702ebb975a458a93cf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33097517"
---
# <a name="columnname"></a>COLUMN_NAME
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_ENTRY](../../data/oledb/column-entry.md), exceto que essa macro usa o nome da coluna em vez do número de coluna.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME(pszName, data)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pszName`  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um 'L' na frente do nome, por exemplo: `L"MyColumn"`.  
  
 `data`  
 [in] O membro de dados correspondente no registro do usuário.  
  
## <a name="remarks"></a>Comentários  
 O **COLUMN_NAME_\***  macros são usadas nos mesmos locais como [COLUMN_ENTRY](../../data/oledb/column-entry.md):  
  
-   Entre o [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre o [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre o [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md)   
 [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md)   
 [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md)   
 [COLUMN_NAME_EX](../../data/oledb/column-name-ex.md)   
 [COLUMN_NAME_LENGTH](../../data/oledb/column-name-length.md)   
 [COLUMN_NAME_LENGTH_STATUS](../../data/oledb/column-name-length-status.md)   
 [COLUMN_NAME_STATUS](../../data/oledb/column-name-status.md)   
 [COLUMN_NAME_PS](../../data/oledb/column-name-ps.md)   
 [COLUMN_NAME_PS_LENGTH](../../data/oledb/column-name-ps-length.md)   
 [COLUMN_NAME_PS_STATUS](../../data/oledb/column-name-ps-status.md)   
 [COLUMN_NAME_PS_LENGTH_STATUS](../../data/oledb/column-name-ps-length-status.md)   
 [COLUMN_NAME_TYPE](../../data/oledb/column-name-type.md)   
 [COLUMN_NAME_TYPE_PS](../../data/oledb/column-name-type-ps.md)   
 [COLUMN_NAME_TYPE_SIZE](../../data/oledb/column-name-type-size.md)   
 [COLUMN_NAME_TYPE_STATUS](../../data/oledb/column-name-type-status.md)