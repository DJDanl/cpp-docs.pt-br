---
title: BLOB_ENTRY_STATUS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- BLOB_ENTRY_STATUS
dev_langs:
- C++
helpviewer_keywords:
- BLOB_ENTRY_STATUS macro
ms.assetid: 191007f4-dfcc-4ae2-a7fc-6f7899accc9f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a6429a6b227cb7c06369d1a82d36e0ad513e6d0e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33095177"
---
# <a name="blobentrystatus"></a>BLOB_ENTRY_STATUS
Usado com `BEGIN_COLUMN_MAP` ou `BEGIN_ACCESSOR_MAP` para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/en-us/library/ms711511.aspx)). Semelhante ao [BLOB_ENTRY](../../data/oledb/blob-entry.md), exceto que essa macro também obtém o status da coluna de BLOB.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_ENTRY_STATUS(nOrdinal, IID, flags, data, status)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nOrdinal`  
 [in] O número da coluna.  
  
 *IID*  
 [in] GUID da interface como **IDD_ISequentialStream**, usado para recuperar o BLOB.  
  
 `flags`  
 [in] Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, **STGM_READ**).  
  
 `data`  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *status*  
 [out] O status do campo BLOB.  
  
## <a name="example"></a>Exemplo  
 Consulte [como recuperar um BLOB?](../../data/oledb/retrieving-a-blob.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md)   
 [END_COLUMN_MAP](../../data/oledb/end-column-map.md)   
 [COLUMN_ENTRY](../../data/oledb/column-entry.md)   
 [BLOB_ENTRY](../../data/oledb/blob-entry.md)   
 [BLOB_ENTRY_LENGTH](../../data/oledb/blob-entry-length.md)   
 [BLOB_ENTRY_LENGTH_STATUS](../../data/oledb/blob-entry-length-status.md)