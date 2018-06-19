---
title: COLUMN_NAME_PS_STATUS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- COLUMN_NAME_PS_STATUS
dev_langs:
- C++
helpviewer_keywords:
- COLUMN_NAME_PS_STATUS macro
ms.assetid: 134e1bfe-abfa-4b64-9159-e492f31de44b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f4b2409e343ea9899994c7c391bbd3273e5fad23
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33098258"
---
# <a name="columnnamepsstatus"></a>COLUMN_NAME_PS_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), exceto que essa macro também usa o status de precisão, escala e coluna.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_PS_STATUS(pszName, nPrecision, nScale, data, status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pszName`  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um 'L' na frente do nome, por exemplo: `L"MyColumn"`.  
  
 `nPrecision`  
 [in] A precisão máxima da coluna que você deseja vincular.  
  
 `nScale`  
 [in] A escala da coluna que você deseja vincular.  
  
 `data`  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *status*  
 [in] A variável a ser associado ao status de coluna.  
  
## <a name="remarks"></a>Comentários  
 Consulte [COLUMN_NAME](../../data/oledb/column-name.md) para obter informações sobre onde o **COLUMN_NAME_\***  macros são usadas.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md)   
 [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md)   
 [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md)   
 [COLUMN_NAME](../../data/oledb/column-name.md)   
 [COLUMN_NAME_EX](../../data/oledb/column-name-ex.md)   
 [COLUMN_NAME_LENGTH](../../data/oledb/column-name-length.md)   
 [COLUMN_NAME_LENGTH_STATUS](../../data/oledb/column-name-length-status.md)   
 [COLUMN_NAME_STATUS](../../data/oledb/column-name-status.md)   
 [COLUMN_NAME_PS](../../data/oledb/column-name-ps.md)   
 [COLUMN_NAME_PS_LENGTH](../../data/oledb/column-name-ps-length.md)   
 [COLUMN_NAME_PS_LENGTH_STATUS](../../data/oledb/column-name-ps-length-status.md)   
 [COLUMN_NAME_TYPE](../../data/oledb/column-name-type.md)   
 [COLUMN_NAME_TYPE_PS](../../data/oledb/column-name-type-ps.md)   
 [COLUMN_NAME_TYPE_SIZE](../../data/oledb/column-name-type-size.md)   
 [COLUMN_NAME_TYPE_STATUS](../../data/oledb/column-name-type-status.md)