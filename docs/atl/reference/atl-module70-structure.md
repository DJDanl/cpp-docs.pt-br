---
title: Estrutura de _ATL_MODULE70 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- _ATL_MODULE70
- ATL::_ATL_MODULE70
- ATL._ATL_MODULE70
dev_langs:
- C++
helpviewer_keywords:
- ATL_MODULE70 structure
- _ATL_MODULE70 structure
ms.assetid: b059b2c8-dfd1-4ac9-b07d-39df638cc7b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3a374ee01387c576a5d1a727857badc7ef7139ad
ms.sourcegitcommit: 19a108b4b30e93a9ad5394844c798490cb3e2945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2018
ms.locfileid: "34255460"
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
  [Classes e estruturas](../../atl/reference/atl-classes.md)







