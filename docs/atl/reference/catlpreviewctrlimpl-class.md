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
ms.openlocfilehash: 71c50771889381ad2288637c23930103b5925a2c
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283263"
---
# <a name="catlpreviewctrlimpl-class"></a>Classe CAtlPreviewCtrlImpl

Essa classe é uma implementação de ATL de uma janela que é colocada em uma janela host fornecida pelo Shell para visualização avançada.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CAtlPreviewCtrlImpl : public CWindowImpl<CAtlPreviewCtrlImpl>, public IPreviewCtrl;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::~CAtlPreviewCtrlImpl](#dtor)|Destructs um objeto de controle de versão prévia.|
|[CAtlPreviewCtrlImpl::CAtlPreviewCtrlImpl](#catlpreviewctrlimpl)|Constrói um objeto de controle de versão prévia.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::Create](#create)|Chamado por um manipulador de visualização avançada para criar a janela do Windows.|
|[CAtlPreviewCtrlImpl::Destroy](#destroy)|Chamado por um manipulador de visualização avançada quando ele precisa destruir esse controle.|
|[CAtlPreviewCtrlImpl::Focus](#focus)|Define o foco de entrada para esse controle.|
|[CAtlPreviewCtrlImpl::OnPaint](#onpaint)|Manipula a mensagem WM_PAINT.|
|[CAtlPreviewCtrlImpl::Redraw](#redraw)|Informa a esse controle seja redesenhada.|
|[CAtlPreviewCtrlImpl::SetHost](#sethost)|Define um novo pai para este controle.|
|[CAtlPreviewCtrlImpl::SetPreviewVisuals](#setpreviewvisuals)|Chamado por um manipulador de visualização avançada quando ele precisa definir os visuais de uma visualização avançada conteúdo.|
|[CAtlPreviewCtrlImpl::SetRect](#setrect)|Define um novo retângulo delimitador para este controle.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::DoPaint](#dopaint)|Chamado pelo framework para renderizar a visualização.|

### <a name="protected-constants"></a>Constantes protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::m_plf](#m_plf)|Fonte usada para exibir texto na janela de visualização.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CAtlPreviewCtrlImpl::m_clrBack](#m_clrback)|Cor do plano de fundo da janela de visualização.|
|[CAtlPreviewCtrlImpl::m_clrText](#m_clrtext)|Cor do texto da janela visualização.|

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

##  <a name="catlpreviewctrlimpl"></a>  CAtlPreviewCtrlImpl::CAtlPreviewCtrlImpl

Constrói um objeto de controle de versão prévia.

```
CAtlPreviewCtrlImpl(void) : m_clrText(0),
   m_clrBack(RGB(255, 255, 255)), m_plf(NULL);
```

### <a name="remarks"></a>Comentários

##  <a name="dtor"></a>  CAtlPreviewCtrlImpl::~CAtlPreviewCtrlImpl

Destructs um objeto de controle de versão prévia.

```
virtual ~CAtlPreviewCtrlImpl(void);
```

### <a name="remarks"></a>Comentários

##  <a name="create"></a>  CAtlPreviewCtrlImpl::Create

Chamado por um manipulador de visualização avançada para criar a janela do Windows.

```
virtual BOOL Create(HWND hWndParent, const RECT* prc);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
Um identificador para a janela de host fornecido pelo Shell para visualização avançada.

*prc*<br/>
Especifica o tamanho inicial e a posição da janela.

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="destroy"></a>  CAtlPreviewCtrlImpl::Destroy

Chamado por um manipulador de visualização avançada quando ele precisa destruir esse controle.

```
virtual void Destroy();
```

### <a name="remarks"></a>Comentários

##  <a name="dopaint"></a>  CAtlPreviewCtrlImpl::DoPaint

Chamado pelo framework para renderizar a visualização.

```
virtual void DoPaint(HDC hdc);
```

### <a name="parameters"></a>Parâmetros

*hdc*<br/>
Um identificador para um contexto de dispositivo para pintura.

### <a name="remarks"></a>Comentários

##  <a name="focus"></a>  CAtlPreviewCtrlImpl::Focus

Define o foco de entrada para esse controle.

```
virtual void Focus();
```

### <a name="remarks"></a>Comentários

##  <a name="m_clrback"></a>  CAtlPreviewCtrlImpl::m_clrBack

Cor do plano de fundo da janela de visualização.

```
COLORREF m_clrBack;
```

### <a name="remarks"></a>Comentários

##  <a name="m_clrtext"></a>  CAtlPreviewCtrlImpl::m_clrText

Cor do texto da janela de visualização.

```
COLORREF m_clrText;
```

### <a name="remarks"></a>Comentários

##  <a name="m_plf"></a>  CAtlPreviewCtrlImpl::m_plf

Fonte usada para exibir texto na janela de visualização.

```
const LOGFONTW* m_plf;
```

### <a name="remarks"></a>Comentários

##  <a name="onpaint"></a>  CAtlPreviewCtrlImpl::OnPaint

Manipula a mensagem WM_PAINT.

```
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
Quando essa função retorna, ele contém TRUE.

### <a name="return-value"></a>Valor de retorno

Sempre retorna 0.

### <a name="remarks"></a>Comentários

##  <a name="redraw"></a>  CAtlPreviewCtrlImpl::Redraw

Informa a esse controle seja redesenhada.

```
virtual void Redraw();
```

### <a name="remarks"></a>Comentários

##  <a name="sethost"></a>  CAtlPreviewCtrlImpl::SetHost

Define um novo pai para este controle.

```
virtual void SetHost(HWND hWndParent);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
Um identificador para a nova janela pai.

### <a name="remarks"></a>Comentários

##  <a name="setpreviewvisuals"></a>  CAtlPreviewCtrlImpl::SetPreviewVisuals

Chamado por um manipulador de visualização avançada quando ele precisa definir os visuais de uma visualização avançada conteúdo.

```
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
Fonte usada para exibir texto na janela de visualização.

### <a name="remarks"></a>Comentários

##  <a name="setrect"></a>  CAtlPreviewCtrlImpl::SetRect

Define um novo retângulo delimitador para este controle.

```
virtual void SetRect(const RECT* prc, BOOL bRedraw);
```

### <a name="parameters"></a>Parâmetros

*prc*<br/>
Especifica o novo tamanho e posição do controle de versão prévia.

*bRedraw*<br/>
Especifica se o controle deve ser redesenhado.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)
