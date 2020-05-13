---
title: Classe CMFCPreviewCtrlImpl
ms.date: 11/04/2016
f1_keywords:
- CMFCPreviewCtrlImpl
- AFXWIN/CMFCPreviewCtrlImpl
- AFXWIN/CMFCPreviewCtrlImpl::CMFCPreviewCtrlImpl
- AFXWIN/CMFCPreviewCtrlImpl::Create
- AFXWIN/CMFCPreviewCtrlImpl::Destroy
- AFXWIN/CMFCPreviewCtrlImpl::Focus
- AFXWIN/CMFCPreviewCtrlImpl::GetDocument
- AFXWIN/CMFCPreviewCtrlImpl::Redraw
- AFXWIN/CMFCPreviewCtrlImpl::SetDocument
- AFXWIN/CMFCPreviewCtrlImpl::SetHost
- AFXWIN/CMFCPreviewCtrlImpl::SetPreviewVisuals
- AFXWIN/CMFCPreviewCtrlImpl::SetRect
- AFXWIN/CMFCPreviewCtrlImpl::DoPaint
- AFXWIN/CMFCPreviewCtrlImpl::m_clrBackColor
- AFXWIN/CMFCPreviewCtrlImpl::m_clrTextColor
- AFXWIN/CMFCPreviewCtrlImpl::m_font
- AFXWIN/CMFCPreviewCtrlImpl::m_pDocument
helpviewer_keywords:
- CMFCPreviewCtrlImpl [MFC], CMFCPreviewCtrlImpl
- CMFCPreviewCtrlImpl [MFC], Create
- CMFCPreviewCtrlImpl [MFC], Destroy
- CMFCPreviewCtrlImpl [MFC], Focus
- CMFCPreviewCtrlImpl [MFC], GetDocument
- CMFCPreviewCtrlImpl [MFC], Redraw
- CMFCPreviewCtrlImpl [MFC], SetDocument
- CMFCPreviewCtrlImpl [MFC], SetHost
- CMFCPreviewCtrlImpl [MFC], SetPreviewVisuals
- CMFCPreviewCtrlImpl [MFC], SetRect
- CMFCPreviewCtrlImpl [MFC], DoPaint
- CMFCPreviewCtrlImpl [MFC], m_clrBackColor
- CMFCPreviewCtrlImpl [MFC], m_clrTextColor
- CMFCPreviewCtrlImpl [MFC], m_font
- CMFCPreviewCtrlImpl [MFC], m_pDocument
ms.assetid: 06257fa0-54c9-478d-9d68-c9698c3f93ed
ms.openlocfilehash: 0c0a594a84b45ce7bf6f2c2fa5d1a547fa10eaa6
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751842"
---
# <a name="cmfcpreviewctrlimpl-class"></a>Classe CMFCPreviewCtrlImpl

Esta classe implementa uma janela que é colocada em uma janela de host fornecida pela Shell for Rich Preview.

## <a name="syntax"></a>Sintaxe

```
class CMFCPreviewCtrlImpl : public CWnd;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPreviewCtrlImpl::~CMFCPreviewCtrlImpl](#dtor)|Destrói um objeto de controle de visualização.|
|[CMFCPreviewCtrlImpl::CMFCPreviewCtrlImpl](#cmfcpreviewctrlimpl)|Constrói um objeto de controle de visualização.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPreviewCtrlImpl::Criar](#create)|Sobrecarregado. Chamado por um manipulador Rich Preview para criar a janela do Windows.|
|[CMFCPreviewCtrlImpl::Destroy](#destroy)|Chamado por um manipulador Rich Preview quando ele precisa destruir este controle.|
|[CMFCPreviewCtrlImpl::Focus](#focus)|Define o foco de entrada para esse controle.|
|[CMFCPreviewCtrlImpl::GetDocument](#getdocument)|Retorna um documento conectado a este controle de visualização.|
|[CMFCPreviewCtrlImpl::Redraw](#redraw)|Diz a este controle para redesenhar.|
|[CMFCPreviewCtrlImpl::SetDocument](#setdocument)|Chamado pelo manipulador de visualização para criar uma relação entre a implementação do documento e o controle de visualização.|
|[CMFCPreviewCtrlImpl::SetHost](#sethost)|Define um novo pai para este controle.|
|[CMFCPreviewCtrlImpl::SetPreviewVisuals](#setpreviewvisuals)|Chamado por um manipulador Rich Preview quando ele precisa definir visuais de conteúdo de visualização rico.|
|[CMFCPreviewCtrlImpl::SetRect](#setrect)|Define um novo retângulo delimitador para este controle.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPreviewCtrlImpl::DoPaint](#dopaint)|Chamado pela estrutura para renderizar a visualização.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPreviewCtrlImpl::m_clrBackColor](#m_clrbackcolor)|Cor de fundo da janela de visualização.|
|[CMFCPreviewCtrlImpl::m_clrTextColor](#m_clrtextcolor)|Cor de texto da janela de visualização.|
|[CMFCPreviewCtrlImpl::m_font](#m_font)|Fonte usada para exibir texto na janela de visualização.|
|[CMFCPreviewCtrlImpl::m_pDocument](#m_pdocument)|Um ponteiro para um documento cujo conteúdo é visualizado no controle.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CMFCPreviewCtrlImpl](../../mfc/reference/cmfcpreviewctrlimpl-class.md)

## <a name="cmfcpreviewctrlimplcmfcpreviewctrlimpl"></a><a name="cmfcpreviewctrlimpl"></a>CMFCPreviewCtrlImpl::CMFCPreviewCtrlImpl

Constrói um objeto de controle de visualização.

### <a name="syntax"></a>Sintaxe

CMFCPreviewCtrlImpl();

## <a name="cmfcpreviewctrlimplcreate"></a><a name="create"></a>CMFCPreviewCtrlImpl::Criar

Sobrecarregado. Chamado por um manipulador Rich Preview para criar a janela do Windows.

### <a name="syntax"></a>Sintaxe

```
virtual BOOL Create(
   HWND hWndParent,
   const RECT* prc
);
virtual BOOL Create(
   HWND hWndParent,
   const RECT* prc,
   CCreateContext* pContext
);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
Uma alça para a janela de host fornecida pela Shell for Rich Preview.

*Prc*<br/>
Especifica o tamanho e a posição iniciais da janela.

*pContext*<br/>
Um ponteiro para um contexto de criação.

### <a name="return-value"></a>Valor retornado

VERDADE se a criação conseguiu; caso contrário, FALSO.

## <a name="cmfcpreviewctrlimpldestroy"></a><a name="destroy"></a>CMFCPreviewCtrlImpl::Destroy

Chamado por um manipulador Rich Preview quando ele precisa destruir este controle.

### <a name="syntax"></a>Sintaxe

```
virtual void Destroy();
```

## <a name="cmfcpreviewctrlimpldopaint"></a><a name="dopaint"></a>CMFCPreviewCtrlImpl::DoPaint

Chamado pela estrutura para renderizar a visualização.

### <a name="syntax"></a>Sintaxe

```
virtual void DoPaint(
   CPaintDC* pDC
);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para um contexto de dispositivo para pintura.

## <a name="cmfcpreviewctrlimplfocus"></a><a name="focus"></a>CMFCPreviewCtrlImpl::Focus

Define o foco de entrada para esse controle.

### <a name="syntax"></a>Sintaxe

```
virtual void Focus();
```

## <a name="cmfcpreviewctrlimplgetdocument"></a><a name="getdocument"></a>CMFCPreviewCtrlImpl::GetDocument

Retorna um documento conectado a este controle de visualização.

### <a name="syntax"></a>Sintaxe

```
ATL::IDocument* GetDocument();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um documento, cujo conteúdo é visualizado no controle.

## <a name="cmfcpreviewctrlimplm_clrbackcolor"></a><a name="m_clrbackcolor"></a>CMFCPreviewCtrlImpl::m_clrBackColor

Cor de fundo da janela de visualização.

### <a name="syntax"></a>Sintaxe

```
COLORREF m_clrBackColor;
```

## <a name="cmfcpreviewctrlimplm_clrtextcolor"></a><a name="m_clrtextcolor"></a>CMFCPreviewCtrlImpl::m_clrTextColor

Cor de texto da janela de visualização.

### <a name="syntax"></a>Sintaxe

```
COLORREF m_clrTextColor;
```

## <a name="cmfcpreviewctrlimplm_font--font-used-to-display-text-in-the-preview-window"></a><a name="m_font"></a>CMFCPreviewCtrlImpl::m_font Fonte usada para exibir texto na janela de visualização.

### <a name="syntax"></a>Sintaxe

```
CFont m_font;
```

## <a name="cmfcpreviewctrlimplm_pdocument"></a><a name="m_pdocument"></a>CMFCPreviewCtrlImpl::m_pDocument

Um ponteiro para um documento cujo conteúdo é visualizado no controle.

### <a name="syntax"></a>Sintaxe

```
ATL::IDocument* m_pDocument;
```

## <a name="cmfcpreviewctrlimplredraw"></a><a name="redraw"></a>CMFCPreviewCtrlImpl::Redraw

Diz a este controle para redesenhar.

### <a name="syntax"></a>Sintaxe

```
virtual void Redraw();
```

## <a name="cmfcpreviewctrlimplsetdocument"></a><a name="setdocument"></a>CMFCPreviewCtrlImpl::SetDocument

Chamado pelo manipulador de visualização para criar uma relação entre a implementação do documento e o controle de visualização.

### <a name="syntax"></a>Sintaxe

```cpp
void SetDocument(
   IDocument* pDocument
);
```

### <a name="parameters"></a>Parâmetros

*pDocument*<br/>
Um ponteiro para a implementação do documento.

## <a name="cmfcpreviewctrlimplsethost"></a><a name="sethost"></a>CMFCPreviewCtrlImpl::SetHost

Define um novo pai para este controle.

### <a name="syntax"></a>Sintaxe

```
virtual void SetHost(
   HWND hWndParent
);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
Uma alça para a nova janela dos pais.

## <a name="cmfcpreviewctrlimplsetpreviewvisuals"></a><a name="setpreviewvisuals"></a>CMFCPreviewCtrlImpl::SetPreviewVisuals

Chamado por um manipulador Rich Preview quando ele precisa definir visuais de conteúdo de visualização rico.

### <a name="syntax"></a>Sintaxe

```
virtual void SetPreviewVisuals(
   COLORREF clrBack,
   COLORREF clrText,
   const LOGFONTW *plf
);
```

### <a name="parameters"></a>Parâmetros

*clrBack*<br/>
Cor de fundo da janela de visualização.

*clrText*<br/>
Cor de texto da janela de visualização.

*plf*<br/>
Fonte usada para exibir texto na janela de visualização.

## <a name="cmfcpreviewctrlimplsetrect"></a><a name="setrect"></a>CMFCPreviewCtrlImpl::SetRect

Define um novo retângulo delimitador para este controle.

### <a name="syntax"></a>Sintaxe

```
virtual void SetRect(
   const RECT* prc,
   BOOL bRedraw
);
```

### <a name="parameters"></a>Parâmetros

*Prc*<br/>
Especifica o novo tamanho e a posição do controle de visualização.

*Bredraw*<br/>
Especifica se o controle deve ser redesenhado.

### <a name="remarks"></a>Comentários

Normalmente, um novo retângulo delimitador é definido quando o controle do host é redimensionado.

## <a name="cmfcpreviewctrlimplcmfcpreviewctrlimpl"></a><a name="dtor"></a>CMFCPreviewCtrlImpl::~CMFCPreviewCtrlImpl

Destrói um objeto de controle de visualização.

### <a name="syntax"></a>Sintaxe

```
virtual ~CMFCPreviewCtrlImpl();
```
