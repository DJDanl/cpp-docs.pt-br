---
title: Classe CHwndRenderTarget
ms.date: 11/04/2016
f1_keywords:
- CHwndRenderTarget
- AFXRENDERTARGET/CHwndRenderTarget
- AFXRENDERTARGET/CHwndRenderTarget::CHwndRenderTarget
- AFXRENDERTARGET/CHwndRenderTarget::Attach
- AFXRENDERTARGET/CHwndRenderTarget::CheckWindowState
- AFXRENDERTARGET/CHwndRenderTarget::Create
- AFXRENDERTARGET/CHwndRenderTarget::Detach
- AFXRENDERTARGET/CHwndRenderTarget::GetHwnd
- AFXRENDERTARGET/CHwndRenderTarget::GetHwndRenderTarget
- AFXRENDERTARGET/CHwndRenderTarget::ReCreate
- AFXRENDERTARGET/CHwndRenderTarget::Resize
- AFXRENDERTARGET/CHwndRenderTarget::m_pHwndRenderTarget
helpviewer_keywords:
- CHwndRenderTarget [MFC], CHwndRenderTarget
- CHwndRenderTarget [MFC], Attach
- CHwndRenderTarget [MFC], CheckWindowState
- CHwndRenderTarget [MFC], Create
- CHwndRenderTarget [MFC], Detach
- CHwndRenderTarget [MFC], GetHwnd
- CHwndRenderTarget [MFC], GetHwndRenderTarget
- CHwndRenderTarget [MFC], ReCreate
- CHwndRenderTarget [MFC], Resize
- CHwndRenderTarget [MFC], m_pHwndRenderTarget
ms.assetid: aa65b69f-7202-46ea-af81-ef325da0b840
ms.openlocfilehash: 24cf4127c2f429f66143af3a0f49625f23a4e6ee
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372459"
---
# <a name="chwndrendertarget-class"></a>Classe CHwndRenderTarget

Um invólucro para ID2D1HwndRenderTarget.

## <a name="syntax"></a>Sintaxe

```
class CHwndRenderTarget : public CRenderTarget;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHwndRenderTarget::CHwndRenderTarget](#chwndrendertarget)|Constrói um objeto CHwndRenderTarget a partir de HWND.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHwndRenderTarget::Anexo](#attach)|Anexa a interface de destino de renderização existente ao objeto|
|[CHwndRenderTarget::CheckWindowState](#checkwindowstate)|Indica se o HWND associado a este alvo de renderização está ocluído.|
|[CHwndRenderTarget::Criar](#create)|Cria um destino de renderização associado à janela|
|[CHwndRenderTarget::Detach](#detach)|Desapegos renderizam interface de destino do objeto|
|[CHwndRenderTarget::GetHwnd](#gethwnd)|Retorna o HWND associado a este destino de renderização.|
|[CHwndRenderTarget::GetHwndRenderTarget](#gethwndrendertarget)|Retorna interface ID2D1HwndRenderTarget.|
|[CHwndRenderTarget::Recriar](#recreate)|Recria um destino de renderização associado à janela|
|[CHwndRenderTarget::Redimensionar](#resize)|Altera o tamanho do destino de renderização para o tamanho de pixel especificado|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHwndRenderTarget::operador ID2D1HwndRenderTarget*](#operator_id2d1hwndrendertarget_star)|Retorna interface ID2D1HwndRenderTarget.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CHwndRenderTarget::m_pHwndRenderTarget](#m_phwndrendertarget)|Um ponteiro para um objeto ID2D1HwndRenderTarget.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CRenderTarget](../../mfc/reference/crendertarget-class.md)

[CHwndRenderTarget](../../mfc/reference/chwndrendertarget-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="chwndrendertargetattach"></a><a name="attach"></a>CHwndRenderTarget::Anexo

Anexa a interface de destino de renderização existente ao objeto

```
void Attach(ID2D1HwndRenderTarget* pTarget);
```

### <a name="parameters"></a>Parâmetros

*Ptarget*<br/>
Interface de destino de renderização existente. Não pode ser NULO

## <a name="chwndrendertargetcheckwindowstate"></a><a name="checkwindowstate"></a>CHwndRenderTarget::CheckWindowState

Indica se o HWND associado a este alvo de renderização está ocluído.

```
D2D1_WINDOW_STATE CheckWindowState() const;
```

### <a name="return-value"></a>Valor retornado

Um valor que indica se o HWND associado a este destino de renderização está ocluído.

## <a name="chwndrendertargetchwndrendertarget"></a><a name="chwndrendertarget"></a>CHwndRenderTarget::CHwndRenderTarget

Constrói um objeto CHwndRenderTarget a partir de HWND.

```
CHwndRenderTarget(HWND hwnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hwnd*<br/>
O HWND associado a este alvo de renderização

## <a name="chwndrendertargetcreate"></a><a name="create"></a>CHwndRenderTarget::Criar

Cria um destino de renderização associado à janela

```
BOOL Create(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
O HWND associado a este alvo de renderização

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO

## <a name="chwndrendertargetdetach"></a><a name="detach"></a>CHwndRenderTarget::Detach

Desapegos renderizam interface de destino do objeto

```
ID2D1HwndRenderTarget* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de destino de renderização separada.

## <a name="chwndrendertargetgethwnd"></a><a name="gethwnd"></a>CHwndRenderTarget::GetHwnd

Retorna o HWND associado a este destino de renderização.

```
HWND GetHwnd() const;
```

### <a name="return-value"></a>Valor retornado

O HWND associado a este alvo de renderização.

## <a name="chwndrendertargetgethwndrendertarget"></a><a name="gethwndrendertarget"></a>CHwndRenderTarget::GetHwndRenderTarget

Retorna interface ID2D1HwndRenderTarget.

```
ID2D1HwndRenderTarget* GetHwndRenderTarget();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1HwndRenderTarget ou NULL se o objeto ainda não estiver inicializado.

## <a name="chwndrendertargetm_phwndrendertarget"></a><a name="m_phwndrendertarget"></a>CHwndRenderTarget::m_pHwndRenderTarget

Um ponteiro para um objeto ID2D1HwndRenderTarget.

```
ID2D1HwndRenderTarget* m_pHwndRenderTarget;
```

## <a name="chwndrendertargetoperator-id2d1hwndrendertarget"></a><a name="operator_id2d1hwndrendertarget_star"></a>CHwndRenderTarget::operador ID2D1HwndRenderTarget*

Retorna interface ID2D1HwndRenderTarget.

```
operator ID2D1HwndRenderTarget*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1HwndRenderTarget ou NULL se o objeto ainda não estiver inicializado.

## <a name="chwndrendertargetrecreate"></a><a name="recreate"></a>CHwndRenderTarget::Recriar

Recria um destino de renderização associado à janela

```
BOOL ReCreate(HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
O HWND associado a este alvo de renderização

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="chwndrendertargetresize"></a><a name="resize"></a>CHwndRenderTarget::Redimensionar

Altera o tamanho do destino de renderização para o tamanho de pixel especificado

```
BOOL Resize(const CD2DSizeU& size);
```

### <a name="parameters"></a>Parâmetros

*Tamanho*<br/>
O novo tamanho do destino de renderização em pixels do dispositivo

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
