---
title: Estrutura de _ATL_BASE_MODULE70
ms.date: 11/04/2016
f1_keywords:
- ATL::_ATL_BASE_MODULE70
- ATL._ATL_BASE_MODULE70
- _ATL_BASE_MODULE70
helpviewer_keywords:
- ATL_BASE_MODULE70 structure
- _ATL_BASE_MODULE70 structure
ms.assetid: 4539282f-15b8-4d7c-aafa-a85dc56f4980
ms.openlocfilehash: 3893e4ce4fcd24f48d9e981ad24505f82dc98833
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168638"
---
# <a name="_atl_base_module70-structure"></a>Estrutura de _ATL_BASE_MODULE70

Usado por qualquer projeto que usa ATL.

## <a name="syntax"></a>Sintaxe

```cpp
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
O `hInstance` para este módulo (exe ou dll).

`m_hInstResource`<br/>
Identificador de recurso de instância padrão.

`m_bNT5orWin98`<br/>
Informações de versão do sistema operacional. Usado internamente pela ATL.

`dwAtlBuildVer`<br/>
Armazena a versão do ATL. 0x0700 no momento.

`pguidVer`<br/>
GUID interno da ATL.

`m_csResource`<br/>
Usado para sincronizar o `m_rgResourceInstance` acesso à matriz. Usado internamente pela ATL.

`m_rgResourceInstance`<br/>
Matriz usada para pesquisar recursos em todas as instâncias de recurso das quais a ATL está ciente. Usado internamente pela ATL.

## <a name="remarks"></a>Comentários

[_ATL_BASE_MODULE](atl-typedefs.md#_atl_base_module) é definido como um typedef de _ATL_BASE_MODULE70.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore. h

## <a name="see-also"></a>Confira também

[Classes e structs](../../atl/reference/atl-classes.md)
