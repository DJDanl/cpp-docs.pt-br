---
title: Estrutura de _AtlCreateWndData | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::_AtlCreateWndData
- ATL._AtlCreateWndData
- _AtlCreateWndData
dev_langs:
- C++
helpviewer_keywords:
- _AtlCreateWndData structure
- AtlCreateWndData structure
ms.assetid: 76ed5382-bfbf-4b8b-8a29-912688dfd2ae
caps.latest.revision: 15
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: c55726a1728185f699afbac4ba68a6dc0f70c2bf
ms.openlocfilehash: a5b0811e88188bb29ef3153f739804cbdac66083
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="atlcreatewnddata-structure"></a>Estrutura _AtlCreateWndData
Essa estrutura contém dados de instância de classe no código de janelas em ATL.  
  
## <a name="syntax"></a>Sintaxe  
  
```
    struct _AtlCreateWndData{
    void* m_pThis;
    DWORD m_dwThreadID;
    _AtlCreateWndData* m_pNext;
};
```  
  
## <a name="members"></a>Membros  
 **m_pThis**  
 O **isso** ponteiro usado para obter acesso à instância de classe em procedimentos de janela.  
  
 `m_dwThreadID`  
 A ID do thread da instância da classe atual.  
  
 **m_pNext**  
 Ponteiro para o próximo `_AtlCreateWndData` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)






