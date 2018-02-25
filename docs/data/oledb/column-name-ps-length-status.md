---
title: COLUMN_NAME_PS_LENGTH_STATUS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COLUMN_NAME_PS_LENGTH_STATUS
dev_langs:
- C++
helpviewer_keywords:
- COLUMN_NAME_PS_LENGTH_STATUS macro
ms.assetid: a1a2e2ca-f0ae-4896-8aa3-67a96c270b05
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: bc3c2582804e8774205e62211ce533b49406921f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="columnnamepslengthstatus"></a>COLUMN_NAME_PS_LENGTH_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), exceto que essa macro também usa precisão, escala, comprimento de coluna e status da coluna.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_PS_LENGTH_STATUS(pszName, nPrecision, nScale, data, length, status )  
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
  
 *Comprimento*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
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
 [COLUMN_NAME_PS_STATUS](../../data/oledb/column-name-ps-status.md)   
 [COLUMN_NAME_TYPE](../../data/oledb/column-name-type.md)   
 [COLUMN_NAME_TYPE_PS](../../data/oledb/column-name-type-ps.md)   
 [COLUMN_NAME_TYPE_SIZE](../../data/oledb/column-name-type-size.md)   
 [COLUMN_NAME_TYPE_STATUS](../../data/oledb/column-name-type-status.md)