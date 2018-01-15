---
title: Estrutura de _ATL_MODULE70 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _ATL_MODULE70
- ATL::_ATL_MODULE70
- ATL._ATL_MODULE70
dev_langs: C++
helpviewer_keywords:
- ATL_MODULE70 structure
- _ATL_MODULE70 structure
ms.assetid: b059b2c8-dfd1-4ac9-b07d-39df638cc7b3
caps.latest.revision: "16"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c8122f733282fa819c3d789a90e60171ee006e27
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="atlmodule70-structure"></a>Estrutura _ATL_MODULE70
Contém os dados usados por cada módulo ATL.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct _ATL_MODULE70 {
    UINT cbSize;
    LONG m_nLockCnt;
    _ATL_TERMFUNC_ELEM* m_pTermFuncs;
    CComCriticalSection m_csStaticDataInitAndTypeInfo;
};
```  
  
## <a name="members"></a>Membros  
 `cbSize`  
 O tamanho da estrutura, usado para controle de versão.  
  
 `m_nLockCnt`  
 Contagem de referência determinar quanto tempo o módulo deve permanecer ativo.  
  
 **m_pTermFuncs**  
 Funções de faixas que foi registradas para ser chamado quando ATL é desligado.  
  
 **m_csStaticDataInitAndTypeInfo**  
 Usado para coordenar o acesso aos dados internos em situações multi-threaded.  
  
## <a name="remarks"></a>Comentários  
 [_ATL_MODULE](atl-typedefs.md#_atl_module) é definido como um typedef de `_ATL_MODULE70`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)







