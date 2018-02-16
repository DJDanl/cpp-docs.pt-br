---
title: BLOB_NAME_STATUS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- BLOB_NAME_STATUS
dev_langs:
- C++
helpviewer_keywords:
- BLOB_NAME_STATUS macro
ms.assetid: 4564e4a0-8e5e-436a-bd1e-012d2a1b8642
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ea0afe904df6f645d5f7ab8ed122d4cde56bf299
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="blobnamestatus"></a>BLOB_NAME_STATUS
Usado com `BEGIN_COLUMN_MAP` e `END_COLUMN_MAP` para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/en-us/library/ms711511.aspx)). Semelhante ao [BLOB_NAME](../../data/oledb/blob-name.md), exceto que essa macro também obtém o status da coluna de dados BLOB.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
BLOB_NAME_STATUS(pszName, IID, flags, data  
, status )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pszName`  
 [in] Um ponteiro para o nome da coluna. O nome deve ser uma cadeia de caracteres Unicode. Você pode fazer isso colocando um 'L' na frente do nome, por exemplo: `L"MyColumn"`.  
  
 *IID*  
 [in] GUID da interface como **IDD_ISequentialStream**, usado para recuperar o BLOB.  
  
 `flags`  
 [in] Sinalizadores de modo de armazenamento, conforme definido pelo modelo de armazenamento estruturado OLE (por exemplo, **STGM_READ**).  
  
 `data`  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *status*  
 [out] O status do campo BLOB.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md)   
 [END_COLUMN_MAP](../../data/oledb/end-column-map.md)   
 [COLUMN_ENTRY](../../data/oledb/column-entry.md)   
 [BLOB_NAME](../../data/oledb/blob-name.md)   
 [BLOB_NAME_LENGTH](../../data/oledb/blob-name-length.md)   
 [BLOB_NAME_LENGTH_STATUS](../../data/oledb/blob-name-length-status.md)