---
title: Estrutura _ATL_BASE_MODULE70 | Microsoft Docs
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
ms.openlocfilehash: d48d863cdbe8e5528824b3ffbad10e1117277e0c
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37885334"
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
 O `hInstance` para esse módulo (exe ou dll).  
  
 `m_hInstResource`  
 Identificador de recurso de instância padrão.  
  
 `m_bNT5orWin98`  
 Informações de versão do sistema operacional. Usado internamente pelo ATL.  
  
 `dwAtlBuildVer`  
 Armazena a versão do ATL. No momento 0x0700.  
  
 `pguidVer`  
 GUID interno do ATL.  
  
 `m_csResource`  
 Usado para sincronizar o acesso para o `m_rgResourceInstance` matriz. Usado internamente pelo ATL.  
  
 `m_rgResourceInstance`  
 Matriz usada para pesquisar recursos em todas as instâncias de recursos que reconhece ATL. Usado internamente pelo ATL.  
  
## <a name="remarks"></a>Comentários  
 [_ATL_BASE_MODULE](atl-typedefs.md#_atl_base_module) é definido como um typedef de _ATL_BASE_MODULE70.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
## <a name="see-also"></a>Consulte também  
 [Classes e structs](../../atl/reference/atl-classes.md)





