---
title: Estrutura de _ATL_BASE_MODULE70 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 15
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 347e7bf7cd9173fb2815f44fc052ec23ab4055a6
ms.openlocfilehash: 7456d441d7b3fb74f404f29c893c492feab10ed9
ms.lasthandoff: 02/25/2017

---
# <a name="atlbasemodule70-structure"></a>Estrutura _ATL_BASE_MODULE70
Usado por qualquer projeto que usa o ATL.  
  
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
 Armazena a versão do ATL. 0x0700 no momento.  
  
 **pguidVer**  
 GUID interno da ATL.  
  
 **m_csResource**  
 Usado para sincronizar o acesso a **m_rgResourceInstance** matriz. Usado internamente pelo ATL.  
  
 **m_rgResourceInstance**  
 Matriz usada para pesquisar recursos em todas as instâncias do recurso que reconheça ATL. Usado internamente pelo ATL.  
  
## <a name="remarks"></a>Comentários  
 [_ATL_BASE_MODULE](atl-typedefs.md#_atl_base_module) é definido como um typedef de `_ATL_BASE_MODULE70`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas](../../atl/reference/atl-structures.md)






