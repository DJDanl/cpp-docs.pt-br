---
title: Classe CAtlPreviewCtrlImpl
ms.date: 11/04/2016
f1_keywords:
- CAtlPreviewCtrlImpl
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::CAtlPreviewCtrlImpl
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::Create
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::Destroy
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::Focus
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::OnPaint
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::Redraw
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::SetHost
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::SetPreviewVisuals
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::SetRect
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::DoPaint
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::m_plf
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::m_clrBack
- ATLPREVIEWCTRLIMPL/ATL::CAtlPreviewCtrlImpl::m_clrText
helpviewer_keywords:
- CAtlPreviewCtrlImpl class
ms.assetid: 39b3299e-07e4-4abc-9b6e-b54bfa3b0802
ms.openlocfilehash: 1ccd01bc4d48dc088538f4799b595cce3fb910ba
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321362"
---
# <a name="catlpreviewctrlimpl-class"></a>Classe CAtlPreviewCtrlImpl

Esta classe é uma implementação ATL de uma janela que é colocada em uma janela de host fornecida pela Shell for Rich Preview.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAtlPreviewCtrlImpl : public CWindowImpl<CAtlPreviewCtrlImpl>, public IPreviewCtrl;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::~CAtlPreviewCtrlImpl](#dtor)|Destrói um objeto de controle de visualização.|
|[CAtlPreviewCtrlImpl::CAtlPreviewCtrlImpl](#catlpreviewctrlimpl)|Constrói um objeto de controle de visualização.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::Create](#create)|Chamado por um manipulador Rich Preview para criar a janela do Windows.|
|[CAtlPreviewCtrlImpl::Destroy](#destroy)|Chamado por um manipulador Rich Preview quando ele precisa destruir este controle.|
|[CAtlPreviewCtrlImpl::Focus](#focus)|Define o foco de entrada para esse controle.|
|[CAtlPreviewCtrlImpl::OnPaint](#onpaint)|Lida com a mensagem WM_PAINT.|
|[CAtlPreviewCtrlImpl::Redraw](#redraw)|Diz a este controle para redesenhar.|
|[CAtlPreviewCtrlImpl::SetHost](#sethost)|Define um novo pai para este controle.|
|[CAtlPreviewCtrlImpl::SetPreviewVisuals](#setpreviewvisuals)|Chamado por um manipulador Rich Preview quando ele precisa definir visuais de conteúdo de visualização rico.|
|[CAtlPreviewCtrlImpl::SetRect](#setrect)|Define um novo retângulo delimitador para este controle.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::DoPaint](#dopaint)|Chamado pela estrutura para renderizar a visualização.|

### <a name="protected-constants"></a>Constantes protegidas

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::m_plf](#m_plf)|Fonte usada para exibir texto na janela de visualização.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::m_clrBack](#m_clrback)|Cor de fundo da janela de visualização.|
|[CAtlPreviewCtrlImpl::m_clrText](#m_clrtext)|Cor de texto da janela de visualização.|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`TBase`

`ATL::CMessageMap`

`ATL::CWindowImplRoot<TBase>`

`ATL::CWindowImplBaseT<TBase,TWinTraits>`

[ATL::CWindowImpl\<CAtlPreviewCtrlImpl>](../../atl/reference/cwindowimpl-class.md)

`IPreviewCtrl`

`ATL::CAtlPreviewCtrlImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpreviewctrlimpl.h

## <a name="catlpreviewctrlimplcatlpreviewctrlimpl"></a><a name="catlpreviewctrlimpl"></a>CAtlPreviewCtrlImpl::CAtlPreviewCtrlImpl

Constrói um objeto de controle de visualização.

```
CAtlPreviewCtrlImpl(void) : m_clrText(0),
   m_clrBack(RGB(255, 255, 255)), m_plf(NULL);
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplcatlpreviewctrlimpl"></a><a name="dtor"></a>CAtlPreviewCtrlImpl::~CAtlPreviewCtrlImpl

Destrói um objeto de controle de visualização.

```
virtual ~CAtlPreviewCtrlImpl(void);
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplcreate"></a><a name="create"></a>CAtlPreviewCtrlImpl::Create

Chamado por um manipulador Rich Preview para criar a janela do Windows.

```
virtual BOOL Create(HWND hWndParent, const RECT* prc);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
Uma alça para a janela de host fornecida pela Shell for Rich Preview.

*Prc*<br/>
Especifica o tamanho e a posição iniciais da janela.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimpldestroy"></a><a name="destroy"></a>CAtlPreviewCtrlImpl::Destroy

Chamado por um manipulador Rich Preview quando ele precisa destruir este controle.

```
virtual void Destroy();
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimpldopaint"></a><a name="dopaint"></a>CAtlPreviewCtrlImpl::DoPaint

Chamado pela estrutura para renderizar a visualização.

```
virtual void DoPaint(HDC hdc);
```

### <a name="parameters"></a>Parâmetros

*Hdc*<br/>
Uma alça para um contexto de dispositivo para pintura.

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplfocus"></a><a name="focus"></a>CAtlPreviewCtrlImpl::Focus

Define o foco de entrada para esse controle.

```
virtual void Focus();
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplm_clrback"></a><a name="m_clrback"></a>CAtlPreviewCtrlImpl::m_clrBack

Cor de fundo da janela de visualização.

```
COLORREF m_clrBack;
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplm_clrtext"></a><a name="m_clrtext"></a>CAtlPreviewCtrlImpl::m_clrText

Cor de texto da janela de visualização.

```
COLORREF m_clrText;
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplm_plf"></a><a name="m_plf"></a>CAtlPreviewCtrlImpl::m_plf

Fonte usada para exibir texto na janela de visualização.

```
const LOGFONTW* m_plf;
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplonpaint"></a><a name="onpaint"></a>CAtlPreviewCtrlImpl::OnPaint

Lida com a mensagem WM_PAINT.

```
LRESULT OnPaint(
    UINT nMsg,
    WPARAM wParam,
    LPARAM lParam,
    BOOL& bHandled);
```

### <a name="parameters"></a>Parâmetros

*nMsg*<br/>
Pronto para WM_PAINT.

*wParam*<br/>
Este parâmetro não é usado.

*lParam*<br/>
Este parâmetro não é usado.

*Bhandled*<br/>
Quando esta função retorna, ela contém TRUE.

### <a name="return-value"></a>Valor retornado

Sempre retorna 0.

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplredraw"></a><a name="redraw"></a>CAtlPreviewCtrlImpl::Redraw

Diz a este controle para redesenhar.

```
virtual void Redraw();
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplsethost"></a><a name="sethost"></a>CAtlPreviewCtrlImpl::SetHost

Define um novo pai para este controle.

```
virtual void SetHost(HWND hWndParent);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
Uma alça para a nova janela dos pais.

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplsetpreviewvisuals"></a><a name="setpreviewvisuals"></a>CAtlPreviewCtrlImpl::SetPreviewVisuals

Chamado por um manipulador Rich Preview quando ele precisa definir visuais de conteúdo de visualização rico.

```
virtual void SetPreviewVisuals(
    COLORREF clrBack,
    COLORREF clrText,
    const LOGFONTW* plf);
```

### <a name="parameters"></a>Parâmetros

*clrBack*<br/>
Cor de fundo da janela de visualização.

*clrText*<br/>
Cor de texto da janela de visualização.

*plf*<br/>
Fonte usada para exibir texto na janela de visualização.

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplsetrect"></a><a name="setrect"></a>CAtlPreviewCtrlImpl::SetRect

Define um novo retângulo delimitador para este controle.

```
virtual void SetRect(const RECT* prc, BOOL bRedraw);
```

### <a name="parameters"></a>Parâmetros

*Prc*<br/>
Especifica o novo tamanho e a posição do controle de visualização.

*Bredraw*<br/>
Especifica se o controle deve ser redesenhado.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)
