---
title: BLOB_ENTRY_LENGTH_STATUS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- BLOB_ENTRY_LENGTH_STATUS
dev_langs:
- C++
helpviewer_keywords:
- BLOB_ENTRY_LENGTH_STATUS macro
ms.assetid: 09da67de-421b-4853-9a26-760e38324502
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 437441bd99f3b9cb4c554bd17a91c236f68ec1fe
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="blobentrylengthstatus"></a>BLOB_ENTRY_LENGTH_STATUS
Usado com `BEGIN_COLUMN_MAP` e `END_COLUMN_MAP` para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/en-us/library/ms711511.aspx)). Semelhante ao [BLOB_ENTRY](../../data/oledb/blob-entry.md), exceto que essa macro também obtém o comprimento e o status da coluna de BLOB.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_ENTRY_LENGTH_STATUS(  
    nOrdinal,  
    IID,  
    flags,  
    data,
    length,
    status )  
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
  
 *length*  
 [out] O comprimento (real) em bytes da coluna de BLOB.  
  
 *status*  
 [out] O status da coluna de dados BLOB.  
  
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
 [BLOB_ENTRY_STATUS](../../data/oledb/blob-entry-status.md)