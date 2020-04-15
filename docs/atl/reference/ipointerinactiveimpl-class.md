---
title: Classe IPointerInactiveImpl
ms.date: 11/04/2016
f1_keywords:
- IPointerInactiveImpl
- ATLCTL/ATL::IPointerInactiveImpl
- ATLCTL/ATL::IPointerInactiveImpl::GetActivationPolicy
- ATLCTL/ATL::IPointerInactiveImpl::OnInactiveMouseMove
- ATLCTL/ATL::IPointerInactiveImpl::OnInactiveSetCursor
helpviewer_keywords:
- IPointerInactive ATL implementation
- inactive objects
- IPointerInactiveImpl class
ms.assetid: e1fe9ea6-d38a-4527-9112-eb344771e0b7
ms.openlocfilehash: 229b8c6803aa7b3817cb3d95474bde0502829f8b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326443"
---
# <a name="ipointerinactiveimpl-class"></a>Classe IPointerInactiveImpl

Esta classe `IUnknown` implementa e os métodos de interface [IPointerInactive.](/windows/win32/api/ocidl/nn-ocidl-ipointerinactive)

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IPointerInactiveImpl
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPointerInactiveImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IPointerInactiveImpl::GetActivationPolicy](#getactivationpolicy)|Recupera a política de ativação atual para o objeto. A implementação da ATL retorna E_NOTIMPL.|
|[IPointerInactiveImpl::OnInactiveMouseMove](#oninactivemousemove)|Notifica o objeto que o ponteiro do mouse se moveu sobre ele, indicando que o objeto pode disparar eventos do mouse. A implementação da ATL retorna E_NOTIMPL.|
|[IPointerInactiveImpl::OnInactiveSetCursor](#oninactivesetcursor)|Define o ponteiro do mouse para o objeto inativo. A implementação da ATL retorna E_NOTIMPL.|

## <a name="remarks"></a>Comentários

Um objeto inativo é aquele que é simplesmente carregado ou executado. Ao contrário de um objeto ativo, um objeto inativo não pode receber mensagens de mouse e teclado do Windows. Assim, os objetos inativos usam menos recursos e são tipicamente mais eficientes.

A interface [IPointerInactive](/windows/win32/api/ocidl/nn-ocidl-ipointerinactive) permite que um objeto suporte um nível mínimo de interação do mouse enquanto permanece inativo. Essa funcionalidade é particularmente útil para controles.

A `IPointerInactiveImpl` classe `IPointerInactive` implementa os métodos simplesmente retornando E_NOTIMPL. No entanto, `IUnknown` ele implementa enviando informações para o dispositivo de despejo em compilações de depuração.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPointerInactive`

`IPointerInactiveImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="ipointerinactiveimplgetactivationpolicy"></a><a name="getactivationpolicy"></a>IPointerInactiveImpl::GetActivationPolicy

Recupera a política de ativação atual para o objeto.

```
HRESULT GetActivationPolicy(DWORD* pdwPolicy);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IPointerInactive::GetActivationPolicy](/windows/win32/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy) no Windows SDK.

## <a name="ipointerinactiveimploninactivemousemove"></a><a name="oninactivemousemove"></a>IPointerInactiveImpl::OnInactiveMouseMove

Notifica o objeto que o ponteiro do mouse se moveu sobre ele, indicando que o objeto pode disparar eventos do mouse.

```
HRESULT OnInactiveMouseMove(
    LPCRECT pRectBounds,
    long x,
    long y,
    DWORD dwMouseMsg);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IPointerInactive::OnInactiveMouseMove](/windows/win32/api/ocidl/nf-ocidl-ipointerinactive-oninactivemousemove) no Windows SDK.

## <a name="ipointerinactiveimploninactivesetcursor"></a><a name="oninactivesetcursor"></a>IPointerInactiveImpl::OnInactiveSetCursor

Define o ponteiro do mouse para o objeto inativo.

```
HRESULT OnInactiveSetCursor(
    LPCRECT pRectBounds,
    long x,
    long y,
    DWORD dwMouseMsg,
    BOOL fSetAlways);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IPointerInactive::OnInactiveSetCursor](/windows/win32/api/ocidl/nf-ocidl-ipointerinactive-oninactivesetcursor) no Windows SDK.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
