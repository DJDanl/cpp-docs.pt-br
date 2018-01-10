---
title: Estrutura de _AtlCreateWndData | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::_AtlCreateWndData
- ATL._AtlCreateWndData
- _AtlCreateWndData
dev_langs: C++
helpviewer_keywords:
- _AtlCreateWndData structure
- AtlCreateWndData structure
ms.assetid: 76ed5382-bfbf-4b8b-8a29-912688dfd2ae
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 99fc06e44f24b176482a6ff0b08ceed45b0f4f17
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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





