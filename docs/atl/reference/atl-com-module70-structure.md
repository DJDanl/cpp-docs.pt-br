---
title: Estrutura de _ATL_COM_MODULE70
ms.date: 11/04/2016
f1_keywords:
- ATL::_ATL_COM_MODULE70
- ATL._ATL_COM_MODULE70
- _ATL_COM_MODULE70
helpviewer_keywords:
- _ATL_COM_MODULE70 structure
- ATL_COM_MODULE70 structure
ms.assetid: 5b0b2fd0-bdeb-4c7e-8870-78fa69ace6e6
ms.openlocfilehash: c2e9e3d6695a7fbbcc87c489edf2e96fcdffb835
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168625"
---
# <a name="_atl_com_module70-structure"></a>Estrutura de _ATL_COM_MODULE70

Usado pelo código relacionado ao COM em ATL.

## <a name="syntax"></a>Sintaxe

```cpp
struct _ATL_COM_MODULE70 {
    UINT cbSize;
    HINSTANCE m_hInstTypeLib;
    _ATL_OBJMAP_ENTRY** m_ppAutoObjMapFirst;
    _ATL_OBJMAP_ENTRY** m_ppAutoObjMapLast;
    CRITICAL_SECTION m_csObjMap;
};
```

## <a name="members"></a>Membros

`cbSize`<br/>
O tamanho da estrutura, usado para controle de versão.

`m_hInstTypeLib`<br/>
A instância de identificador para a biblioteca de tipos deste módulo.

`m_ppAutoObjMapFirst`<br/>
Endereço do elemento da matriz que indica o início das entradas de mapa do objeto para este módulo.

`m_ppAutoObjMapLast`<br/>
Endereço do elemento da matriz que indica o fim das entradas de mapa do objeto para este módulo.

`m_csObjMap`<br/>
Seção crítica para serializar o acesso às entradas do mapa de objetos. Usado internamente pela ATL.

## <a name="remarks"></a>Comentários

[_ATL_COM_MODULE](atl-typedefs.md#_atl_com_module) é definido como um typedef de _ATL_COM_MODULE70.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="see-also"></a>Confira também

[Classes e structs](../../atl/reference/atl-classes.md)
