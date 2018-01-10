---
title: BLOB_ENTRY | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: BLOB_ENTRY
dev_langs: C++
helpviewer_keywords: BLOB_ENTRY macro
ms.assetid: 89e40678-0869-49ed-b502-0fa2630a9081
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: bf614851612d5bbb32ef0b6431153d5240007018
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="blobentry"></a>BLOB_ENTRY
Usado com `BEGIN_COLUMN_MAP` e `END_COLUMN_MAP` para associar um objeto binário grande ([BLOB](https://msdn.microsoft.com/en-us/library/ms711511.aspx)).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
BLOB_ENTRY(  
nOrdinal  
,  
 IID  
,   
flags  
,   
data  
 )  
  
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
  
## <a name="example"></a>Exemplo  
 Consulte [como recuperar um BLOB?](../../data/oledb/retrieving-a-blob.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md)   
 [END_COLUMN_MAP](../../data/oledb/end-column-map.md)   
 [COLUMN_ENTRY](../../data/oledb/column-entry.md)   
 [BLOB_ENTRY_LENGTH](../../data/oledb/blob-entry-length.md)   
 [BLOB_ENTRY_LENGTH_STATUS](../../data/oledb/blob-entry-length-status.md)   
 [BLOB_ENTRY_STATUS](../../data/oledb/blob-entry-status.md)