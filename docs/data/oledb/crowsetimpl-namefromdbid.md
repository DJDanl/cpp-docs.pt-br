---
title: 'Crowsetimpl:: Namefromdbid | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CRowsetImpl.NameFromDBID
- CRowsetImpl::NameFromDBID
dev_langs:
- C++
helpviewer_keywords:
- NameFromDBID method
ms.assetid: 6aa5b074-90c7-4434-adfd-c64c13e76c78
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 54ee345d4bf97c6f77398e62d1cb31614868a568
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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