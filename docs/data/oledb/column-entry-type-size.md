---
title: COLUMN_ENTRY_TYPE_SIZE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- COLUMN_ENTRY_TYPE_SIZE
dev_langs:
- C++
helpviewer_keywords:
- COLUMN_ENTRY_TYPE_SIZE macro
ms.assetid: d8b169e8-af22-464b-8cb3-eaa346f7a739
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1acb969015acda4213532cac3e185bf97a3ac31d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33097166"
---
# <a name="columnentrytypesize"></a>COLUMN_ENTRY_TYPE_SIZE
Representa uma associação para a coluna específica no banco de dados. Dá suporte a `type` e `size` parâmetros.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_TYPE_SIZE(nOrdinal, wType, nLength, data)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nOrdinal`  
 [in] O número da coluna.  
  
 `wType`  
 [in] Tipo de dados de entrada da coluna.  
  
 `nLength`  
 [in] Tamanho da entrada de coluna em bytes.  
  
 `data`  
 [in] O membro de dados correspondente no registro do usuário.  
  
## <a name="remarks"></a>Comentários  
 Essa macro é uma variante especializada do [COLUMN_ENTRY](../../data/oledb/column-entry.md) macro que fornece um meio de especificar o tamanho dos dados e o tipo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md)   
 [END_COLUMN_MAP](../../data/oledb/end-column-map.md)