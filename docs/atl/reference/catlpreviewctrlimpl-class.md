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
ms.openlocfilehash: fd94d0d6fe43d80b45def3f747c7b7d558de31d4
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82167871"
---
# <a name="catlpreviewctrlimpl-class"></a>Classe CAtlPreviewCtrlImpl

Essa classe é uma implementação de ATL de uma janela que é colocada em uma janela de host fornecida pelo shell para visualização avançada.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
class CAtlPreviewCtrlImpl : public CWindowImpl<CAtlPreviewCtrlImpl>, public IPreviewCtrl;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl:: ~ CAtlPreviewCtrlImpl](#dtor)|Destrui um objeto de controle de visualização.|
|[CAtlPreviewCtrlImpl::CAtlPreviewCtrlImpl](#catlpreviewctrlimpl)|Constrói um objeto de controle de visualização.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl:: criar](#create)|Chamado por um manipulador de visualização avançado para criar a janela do Windows.|
|[CAtlPreviewCtrlImpl::D estroy](#destroy)|Chamado por um manipulador de visualização avançado quando ele precisa destruir esse controle.|
|[CAtlPreviewCtrlImpl:: Focus](#focus)|Define o foco de entrada para esse controle.|
|[CAtlPreviewCtrlImpl:: OnPaint](#onpaint)|Manipula a mensagem de WM_PAINT.|
|[CAtlPreviewCtrlImpl:: redesenhar](#redraw)|Informa este controle para redesenhar.|
|[CAtlPreviewCtrlImpl:: SetHost](#sethost)|Define um novo pai para este controle.|
|[CAtlPreviewCtrlImpl::SetPreviewVisuals](#setpreviewvisuals)|Chamado por um Gerenciador de visualização avançado quando ele precisa definir visuais de conteúdo de visualização avançada.|
|[CAtlPreviewCtrlImpl:: SetRect](#setrect)|Define um novo retângulo delimitador para este controle.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::D oPaint](#dopaint)|Chamado pelo Framework para renderizar a visualização.|

### <a name="protected-constants"></a>Constantes protegidas

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl:: m_plf](#m_plf)|Fonte usada para exibir o texto na janela de visualização.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl:: m_clrBack](#m_clrback)|Cor do plano de fundo da janela de visualização.|
|[CAtlPreviewCtrlImpl:: m_clrText](#m_clrtext)|Cor do texto da janela de visualização.|

## <a name="remarks"></a>Comentários

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`TBase`

`ATL::CMessageMap`

`ATL::CWindowImplRoot<TBase>`

`ATL::CWindowImplBaseT<TBase,TWinTraits>`

[ATL:: CWindowImpl\<CAtlPreviewCtrlImpl>](../../atl/reference/cwindowimpl-class.md)

`IPreviewCtrl`

`ATL::CAtlPreviewCtrlImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpreviewctrlimpl. h

## <a name="catlpreviewctrlimplcatlpreviewctrlimpl"></a><a name="catlpreviewctrlimpl"></a>CAtlPreviewCtrlImpl::CAtlPreviewCtrlImpl

Constrói um objeto de controle de visualização.

```cpp
CAtlPreviewCtrlImpl(void) : m_clrText(0),
   m_clrBack(RGB(255, 255, 255)), m_plf(NULL);
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplcatlpreviewctrlimpl"></a><a name="dtor"></a>CAtlPreviewCtrlImpl:: ~ CAtlPreviewCtrlImpl

Destrui um objeto de controle de visualização.

```cpp
virtual ~CAtlPreviewCtrlImpl(void);
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplcreate"></a><a name="create"></a>CAtlPreviewCtrlImpl:: criar

Chamado por um manipulador de visualização avançado para criar a janela do Windows.

```cpp
virtual BOOL Create(HWND hWndParent, const RECT* prc);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
Um identificador para a janela de host fornecida pelo shell para visualização avançada.

*popular*<br/>
Especifica o tamanho inicial e a posição da janela.

### <a name="return-value"></a>Valor retornado

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimpldestroy"></a><a name="destroy"></a>CAtlPreviewCtrlImpl::D estroy

Chamado por um manipulador de visualização avançado quando ele precisa destruir esse controle.

```cpp
virtual void Destroy();
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimpldopaint"></a><a name="dopaint"></a>CAtlPreviewCtrlImpl::D oPaint

Chamado pelo Framework para renderizar a visualização.

```cpp
virtual void DoPaint(HDC hdc);
```

### <a name="parameters"></a>Parâmetros

*HDC*<br/>
Um identificador para um contexto de dispositivo para pintura.

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplfocus"></a><a name="focus"></a>CAtlPreviewCtrlImpl:: Focus

Define o foco de entrada para esse controle.

```cpp
virtual void Focus();
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplm_clrback"></a><a name="m_clrback"></a>CAtlPreviewCtrlImpl:: m_clrBack

Cor do plano de fundo da janela de visualização.

```cpp
COLORREF m_clrBack;
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplm_clrtext"></a><a name="m_clrtext"></a>CAtlPreviewCtrlImpl:: m_clrText

Cor do texto da janela de visualização.

```cpp
COLORREF m_clrText;
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplm_plf"></a><a name="m_plf"></a>CAtlPreviewCtrlImpl:: m_plf

Fonte usada para exibir o texto na janela de visualização.

```cpp
const LOGFONTW* m_plf;
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplonpaint"></a><a name="onpaint"></a>CAtlPreviewCtrlImpl:: OnPaint

Manipula a mensagem de WM_PAINT.

```cpp
LRESULT OnPaint(
    UINT nMsg,
    WPARAM wParam,
    LPARAM lParam,
    BOOL& bHandled);
```

### <a name="parameters"></a>Parâmetros

*nMsg*<br/>
Defina como WM_PAINT.

*wParam*<br/>
Este parâmetro não é usado.

*lParam*<br/>
Este parâmetro não é usado.

*bHandled*<br/>
Quando essa função retorna, ela contém TRUE.

### <a name="return-value"></a>Valor retornado

Sempre retorna 0.

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplredraw"></a><a name="redraw"></a>CAtlPreviewCtrlImpl:: redesenhar

Informa este controle para redesenhar.

```cpp
virtual void Redraw();
```

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplsethost"></a><a name="sethost"></a>CAtlPreviewCtrlImpl:: SetHost

Define um novo pai para este controle.

```cpp
virtual void SetHost(HWND hWndParent);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
Um identificador para a nova janela pai.

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplsetpreviewvisuals"></a><a name="setpreviewvisuals"></a>CAtlPreviewCtrlImpl::SetPreviewVisuals

Chamado por um Gerenciador de visualização avançado quando ele precisa definir visuais de conteúdo de visualização avançada.

```cpp
virtual void SetPreviewVisuals(
    COLORREF clrBack,
    COLORREF clrText,
    const LOGFONTW* plf);
```

### <a name="parameters"></a>Parâmetros

*clrBack*<br/>
Cor do plano de fundo da janela de visualização.

*clrText*<br/>
Cor do texto da janela de visualização.

*plf*<br/>
Fonte usada para exibir o texto na janela de visualização.

### <a name="remarks"></a>Comentários

## <a name="catlpreviewctrlimplsetrect"></a><a name="setrect"></a>CAtlPreviewCtrlImpl:: SetRect

Define um novo retângulo delimitador para este controle.

```cpp
virtual void SetRect(const RECT* prc, BOOL bRedraw);
```

### <a name="parameters"></a>Parâmetros

*popular*<br/>
Especifica o novo tamanho e a posição do controle de visualização.

*bRedraw*<br/>
Especifica se o controle deve ser redesenhado.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)
