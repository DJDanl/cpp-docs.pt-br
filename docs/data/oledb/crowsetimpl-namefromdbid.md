---
title: CRowsetImpl::NameFromDBID | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CRowsetImpl.NameFromDBID
- CRowsetImpl::NameFromDBID
dev_langs:
- C++
helpviewer_keywords:
- NameFromDBID method
ms.assetid: 6aa5b074-90c7-4434-adfd-c64c13e76c78
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 451c5d0474cbd5d72e650648ebd99eb9f2277a66
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="crowsetimplnamefromdbid"></a>CRowsetImpl::NameFromDBID
Extrai uma cadeia de caracteres de um **DBID** e copiá-lo para o `bstr` passado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT CRowsetBaseImpl::NameFromDBID(DBID* pDBID,  
   CComBSTR& bstr,  
   bool bIndex);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pDBID*  
 [in] Um ponteiro para o **DBID** do qual extrair uma cadeia de caracteres.  
  
 `bstr`  
 [in] Um [CComBSTR](../../atl/reference/ccombstr-class.md) referência para colocar uma cópia de **DBID** cadeia de caracteres.  
  
 `bIndex`  
 [in] **true** se um índice **DBID**; **false** se uma tabela **DBID**.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`. Dependendo se o **DBID** é uma tabela ou um índice (indicado por `bIndex`), o método será devolva **DB_E_NOINDEX** ou **DB_E_NOTABLE**.  
  
## <a name="remarks"></a>Comentários  
 Este método é chamado pelo `CRowsetImpl` implementações de [ValidateCommandID](../../data/oledb/crowsetimpl-validatecommandid.md) e [GetCommandFromID](../../data/oledb/crowsetimpl-getcommandfromid.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowsetImpl](../../data/oledb/crowsetimpl-class.md)