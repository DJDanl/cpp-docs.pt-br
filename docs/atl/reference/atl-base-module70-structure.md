---
title: Estrutura de _ATL_BASE_MODULE70 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- ATL::_ATL_BASE_MODULE70
- ATL._ATL_BASE_MODULE70
- _ATL_BASE_MODULE70
dev_langs:
- C++
helpviewer_keywords:
- ATL_BASE_MODULE70 structure
- _ATL_BASE_MODULE70 structure
ms.assetid: 4539282f-15b8-4d7c-aafa-a85dc56f4980
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 484fc4a68d0421cb12e901b2d56f30e95f6cb79b
ms.sourcegitcommit: 19a108b4b30e93a9ad5394844c798490cb3e2945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2018
ms.locfileid: "34256412"
---
# <a name="atlbasemodule70-structure"></a>Estrutura _ATL_BASE_MODULE70
Usado por qualquer projeto que usa ATL.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct _ATL_BASE_MODULE70 {
    UINT cbSize;
    HINSTANCE m_hInst;
    HINSTANCE m_hInstResource;
    bool m_bNT5orWin98;
    DWORD dwAtlBuildVer;
    GUID* pguidVer;
    CRITICAL_SECTION m_csResource;
    CSimpleArray<HINSTANCE> m_rgResourceInstance;
};
```  
  
## <a name="members"></a>Membros  
 `cbSize`  
 O tamanho da estrutura, usado para controle de versão.  
  
 `m_hInst`  
 O **hInstance** para este módulo (exe ou dll).  
  
 `m_hInstResource`  
 Identificador de recurso de instância padrão.  
  
 **m_bNT5orWin98**  
 Informações de versão do sistema operacional. Usado internamente pelo ATL.  
  
 **dwAtlBuildVer**  
 Armazena a versão do ATL No momento 0x0700.  
  
 **pguidVer**  
 GUID de interno da ATL.  
  
 **m_csResource**  
 Usado para sincronizar o acesso a **m_rgResourceInstance** matriz. Usado internamente pelo ATL.  
  
 **m_rgResourceInstance**  
 Matriz usado para procurar recursos em todas as instâncias de recursos que reconhece ATL. Usado internamente pelo ATL.  
  
## <a name="remarks"></a>Comentários  
 [_ATL_BASE_MODULE](atl-typedefs.md#_atl_base_module) é definido como um typedef de `_ATL_BASE_MODULE70`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
## <a name="see-also"></a>Consulte também  
 [Classes e estruturas](../../atl/reference/atl-classes.md)





