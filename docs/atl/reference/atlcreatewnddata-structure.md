---
title: Estrutura de _AtlCreateWndData | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 66388c12def72a9da5b5aeb7e4713ca61c23a6e0
ms.sourcegitcommit: 19a108b4b30e93a9ad5394844c798490cb3e2945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2018
ms.locfileid: "34255789"
---
# <a name="atlcreatewnddata-structure"></a>_AtlCreateWndData Structure
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
 [Classes e estruturas](../../atl/reference/atl-classes.md)





