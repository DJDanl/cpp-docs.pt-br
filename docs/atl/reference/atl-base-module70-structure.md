---
title: Estrutura _ATL_BASE_MODULE70
ms.date: 11/04/2016
f1_keywords:
- ATL::_ATL_BASE_MODULE70
- ATL._ATL_BASE_MODULE70
- _ATL_BASE_MODULE70
helpviewer_keywords:
- ATL_BASE_MODULE70 structure
- _ATL_BASE_MODULE70 structure
ms.assetid: 4539282f-15b8-4d7c-aafa-a85dc56f4980
ms.openlocfilehash: 806ed86076d8b27662bcd9a328d43cabf5df5c86
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50667539"
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

`cbSize`<br/>
O tamanho da estrutura, usado para controle de versão.

`m_hInst`<br/>
O `hInstance` para esse módulo (exe ou dll).

`m_hInstResource`<br/>
Identificador de recurso de instância padrão.

`m_bNT5orWin98`<br/>
Informações de versão do sistema operacional. Usado internamente pelo ATL.

`dwAtlBuildVer`<br/>
Armazena a versão do ATL. No momento 0x0700.

`pguidVer`<br/>
GUID interno do ATL.

`m_csResource`<br/>
Usado para sincronizar o acesso para o `m_rgResourceInstance` matriz. Usado internamente pelo ATL.

`m_rgResourceInstance`<br/>
Matriz usada para pesquisar recursos em todas as instâncias de recursos que reconhece ATL. Usado internamente pelo ATL.

## <a name="remarks"></a>Comentários

[_ATL_BASE_MODULE](atl-typedefs.md#_atl_base_module) é definido como um typedef de _ATL_BASE_MODULE70.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

## <a name="see-also"></a>Consulte também

[Classes e structs](../../atl/reference/atl-classes.md)

