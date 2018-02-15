---
title: COLUMN_NAME_STATUS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- COLUMN_NAME_STATUS
dev_langs:
- C++
helpviewer_keywords:
- COLUMN_NAME_STATUS macro
ms.assetid: a6204755-6739-4116-b414-9b8fa7ab6549
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3527b530218e1f5d41181d4e716f0dbb88125e6e
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="columnnamestatus"></a>COLUMN_NAME_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no conjunto de linhas. Semelhante ao [COLUMN_NAME](../../data/oledb/column-name.md), exceto que essa macro também usa o status da coluna.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_NAME_STATUS(pszName, data, status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pszName`  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um 'L' na frente do nome, por exemplo: `L"MyColumn"`.  
  
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
 [COLUMN_NAME_PS](../../data/oledb/column-name-ps.md)   
 [COLUMN_NAME_PS_LENGTH](../../data/oledb/column-name-ps-length.md)   
 [COLUMN_NAME_PS_STATUS](../../data/oledb/column-name-ps-status.md)   
 [COLUMN_NAME_PS_LENGTH_STATUS](../../data/oledb/column-name-ps-length-status.md)   
 [COLUMN_NAME_TYPE](../../data/oledb/column-name-type.md)   
 [COLUMN_NAME_TYPE_PS](../../data/oledb/column-name-type-ps.md)   
 [COLUMN_NAME_TYPE_SIZE](../../data/oledb/column-name-type-size.md)   
 [COLUMN_NAME_TYPE_STATUS](../../data/oledb/column-name-type-status.md)