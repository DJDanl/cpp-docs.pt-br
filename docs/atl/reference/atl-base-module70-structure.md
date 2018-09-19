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
ms.openlocfilehash: a8ee35df4b6ee792cd91f1b294259544e8944509
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46089041"
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

