---
title: Classe IPointerInactiveImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IPointerInactiveImpl
- ATLCTL/ATL::IPointerInactiveImpl
- ATLCTL/ATL::IPointerInactiveImpl::GetActivationPolicy
- ATLCTL/ATL::IPointerInactiveImpl::OnInactiveMouseMove
- ATLCTL/ATL::IPointerInactiveImpl::OnInactiveSetCursor
dev_langs:
- C++
helpviewer_keywords:
- IPointerInactive ATL implementation
- inactive objects
- IPointerInactiveImpl class
ms.assetid: e1fe9ea6-d38a-4527-9112-eb344771e0b7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f44bcdedc718ce4d6459fea7f8581273e49caa10
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46097556"
---
# <a name="ipointerinactiveimpl-class"></a>Classe IPointerInactiveImpl

Essa classe implementa `IUnknown` e o [IPointerInactive](/windows/desktop/api/ocidl/nn-ocidl-ipointerinactive) métodos de interface.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IPointerInactiveImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPointerInactiveImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IPointerInactiveImpl::GetActivationPolicy](#getactivationpolicy)|Recupera a política de ativação atual para o objeto. A implementação de ATL retornará E_NOTIMPL.|
|[IPointerInactiveImpl::OnInactiveMouseMove](#oninactivemousemove)|Notifica o objeto que o ponteiro do mouse foi movido sobre ele, que indica o objeto pode disparar eventos de mouse. A implementação de ATL retornará E_NOTIMPL.|
|[IPointerInactiveImpl::OnInactiveSetCursor](#oninactivesetcursor)|Define o ponteiro do mouse para o objeto inativo. A implementação de ATL retornará E_NOTIMPL.|

## <a name="remarks"></a>Comentários

Um objeto inativo é aquele que é simplesmente carregado ou em execução. Ao contrário de um objeto do Active Directory, um objeto inativo não pode receber mensagens de mouse e teclado do Windows. Assim, os objetos inativos usam menos recursos e são geralmente mais eficientes.

O [IPointerInactive](/windows/desktop/api/ocidl/nn-ocidl-ipointerinactive) interface permite que um objeto dar suporte a um nível mínimo de interação do mouse enquanto permanecem inativos. Essa funcionalidade é particularmente útil para controles.

Classe `IPointerInactiveImpl` implementa o `IPointerInactive` métodos por simplesmente retornar E_NOTIMPL. No entanto, ele implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.

**Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPointerInactive`

`IPointerInactiveImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="getactivationpolicy"></a>  IPointerInactiveImpl::GetActivationPolicy

Recupera a política de ativação atual para o objeto.

```
HRESULT GetActivationPolicy(DWORD* pdwPolicy);
```

### <a name="return-value"></a>Valor de retorno

Retornará E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IPointerInactive::GetActivationPolicy](/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy) no Windows SDK.

##  <a name="oninactivemousemove"></a>  IPointerInactiveImpl::OnInactiveMouseMove

Notifica o objeto que o ponteiro do mouse foi movido sobre ele, que indica o objeto pode disparar eventos de mouse.

```
HRESULT OnInactiveMouseMove(
    LPCRECT pRectBounds,
    long x,
    long y,
    DWORD dwMouseMsg);
```

### <a name="return-value"></a>Valor de retorno

Retornará E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IPointerInactive::OnInactiveMouseMove](/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-oninactivemousemove) no Windows SDK.

##  <a name="oninactivesetcursor"></a>  IPointerInactiveImpl::OnInactiveSetCursor

Define o ponteiro do mouse para o objeto inativo.

```
HRESULT OnInactiveSetCursor(
    LPCRECT pRectBounds,
    long x,
    long y,
    DWORD dwMouseMsg,
    BOOL fSetAlways);
```

### <a name="return-value"></a>Valor de retorno

Retornará E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IPointerInactive::OnInactiveSetCursor](/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-oninactivesetcursor) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
