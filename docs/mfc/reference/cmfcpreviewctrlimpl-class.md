---
title: Classe CMFCPreviewCtrlImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 29632784248d624f184550f0c598d05cd26b85cf
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50079539"
---
# <a name="cmfcpreviewctrlimpl-class"></a>Classe CMFCPreviewCtrlImpl

Essa classe implementa uma janela que é colocada em uma janela host fornecida pelo Shell para visualização avançada.

## <a name="syntax"></a>Sintaxe

```
class CMFCPreviewCtrlImpl : public CWnd;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPreviewCtrlImpl:: ~ CMFCPreviewCtrlImpl](#dtor)|Destructs um objeto de controle de versão prévia.|
|[CMFCPreviewCtrlImpl::CMFCPreviewCtrlImpl](#cmfcpreviewctrlimpl)|Constrói um objeto de controle de versão prévia.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPreviewCtrlImpl::Create](#create)|Sobrecarregado. Chamado por um manipulador de visualização avançada para criar a janela do Windows.|
|[CMFCPreviewCtrlImpl::Destroy](#destroy)|Chamado por um manipulador de visualização avançada quando ele precisa destruir esse controle.|
|[CMFCPreviewCtrlImpl::Focus](#focus)|Define o foco de entrada para esse controle.|
|[CMFCPreviewCtrlImpl::GetDocument](#getdocument)|Retorna um documento conectado a esse controle de versão prévia.|
|[CMFCPreviewCtrlImpl::Redraw](#redraw)|Informa a esse controle seja redesenhada.|
|[CMFCPreviewCtrlImpl::SetDocument](#setdocument)|Chamado pelo Gerenciador de visualização para criar uma relação entre a implementação de documento e o controle de versão prévia.|
|[CMFCPreviewCtrlImpl::SetHost](#sethost)|Define um novo pai para este controle.|
|[CMFCPreviewCtrlImpl::SetPreviewVisuals](#setpreviewvisuals)|Chamado por um manipulador de visualização avançada quando ele precisa definir os visuais de uma visualização avançada conteúdo.|
|[CMFCPreviewCtrlImpl::SetRect](#setrect)|Define um novo retângulo delimitador para este controle.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPreviewCtrlImpl::DoPaint](#dopaint)|Chamado pelo framework para renderizar a visualização.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPreviewCtrlImpl::m_clrBackColor](#m_clrbackcolor)|Cor do plano de fundo da janela visualização.|
|[CMFCPreviewCtrlImpl::m_clrTextColor](#m_clrtextcolor)|Cor do texto da janela visualização.|
|[CMFCPreviewCtrlImpl::m_font](#m_font)|Fonte usada para exibir texto na janela de visualização.|
|[CMFCPreviewCtrlImpl::m_pDocument](#m_pdocument)|Um ponteiro para um documento cujo conteúdo é visualizado no controle.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CMFCPreviewCtrlImpl](../../mfc/reference/cmfcpreviewctrlimpl-class.md)

## <a name="cmfcpreviewctrlimpl"></a> CMFCPreviewCtrlImpl::CMFCPreviewCtrlImpl

Constrói um objeto de controle de versão prévia.

### <a name="syntax"></a>Sintaxe

CMFCPreviewCtrlImpl();

## <a name="create"></a> CMFCPreviewCtrlImpl::Create

Sobrecarregado. Chamado por um manipulador de visualização avançada para criar a janela do Windows.

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

*hWndParent*<br/>
Um identificador para a janela de host fornecido pelo Shell para visualização avançada.

*República Popular da China*<br/>
Especifica o tamanho inicial e a posição da janela.

*pContext*<br/>
Um ponteiro para um contexto de criação.

### <a name="return-value"></a>Valor de retorno

TRUE se a criação for bem-sucedida; Caso contrário, FALSE.

## <a name="destroy"></a> CMFCPreviewCtrlImpl::Destroy

Chamado por um manipulador de visualização avançada quando ele precisa destruir esse controle.

### <a name="syntax"></a>Sintaxe

```
virtual void Destroy();
```

## <a name="dopaint"></a> CMFCPreviewCtrlImpl::DoPaint

Chamado pelo framework para renderizar a visualização.

### <a name="syntax"></a>Sintaxe

```
virtual void DoPaint(
   CPaintDC* pDC
);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para um contexto de dispositivo para pintura.

## <a name="focus"></a> CMFCPreviewCtrlImpl::Focus

Define o foco de entrada para esse controle.

### <a name="syntax"></a>Sintaxe

```
virtual void Focus();
```

## <a name="getdocument"></a> CMFCPreviewCtrlImpl::GetDocument

Retorna um documento conectado a esse controle de versão prévia.

### <a name="syntax"></a>Sintaxe

```
ATL::IDocument* GetDocument();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um documento, cujo conteúdo é visualizado no controle.

## <a name="m_clrbackcolor"></a> CMFCPreviewCtrlImpl::m_clrBackColor

Cor do plano de fundo da janela de visualização.

### <a name="syntax"></a>Sintaxe

```
COLORREF m_clrBackColor;
```

## <a name="m_clrtextcolor"></a> CMFCPreviewCtrlImpl::m_clrTextColor

Cor do texto da janela de visualização.

### <a name="syntax"></a>Sintaxe

```
COLORREF m_clrTextColor;
```

## <a name="m_font"></a> Fonte de CMFCPreviewCtrlImpl::m_font usada para exibir o texto na janela de visualização.

### <a name="syntax"></a>Sintaxe

```
CFont m_font;
```

## <a name="m_pdocument"></a> CMFCPreviewCtrlImpl::m_pDocument

Um ponteiro para um documento cujo conteúdo é visualizado no controle.

### <a name="syntax"></a>Sintaxe

```
ATL::IDocument* m_pDocument;
```

## <a name="redraw"></a> CMFCPreviewCtrlImpl::Redraw

Informa a esse controle seja redesenhada.

### <a name="syntax"></a>Sintaxe

```
virtual void Redraw();
```

## <a name="setdocument"></a> CMFCPreviewCtrlImpl::SetDocument

Chamado pelo Gerenciador de visualização para criar uma relação entre a implementação de documento e o controle de versão prévia.

### <a name="syntax"></a>Sintaxe

```
void SetDocument(
   IDocument* pDocument
);
```

### <a name="parameters"></a>Parâmetros

*pDocument*<br/>
Um ponteiro para a implementação do documento.

## <a name="sethost"></a> CMFCPreviewCtrlImpl::SetHost

Define um novo pai para este controle.

### <a name="syntax"></a>Sintaxe

```
virtual void SetHost(
   HWND hWndParent
);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
Um identificador para a nova janela pai.

## <a name="setpreviewvisuals"></a> CMFCPreviewCtrlImpl::SetPreviewVisuals

Chamado por um manipulador de visualização avançada quando ele precisa definir os visuais de uma visualização avançada conteúdo.

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
Cor do plano de fundo da janela visualização.

*clrText*<br/>
Cor do texto da janela visualização.

*plf*<br/>
Fonte usada para exibir texto na janela de visualização.

##  <a name="setrect"></a> CMFCPreviewCtrlImpl::SetRect

Define um novo retângulo delimitador para este controle.

### <a name="syntax"></a>Sintaxe

```
virtual void SetRect(
   const RECT* prc,
   BOOL bRedraw
);
```

### <a name="parameters"></a>Parâmetros

*República Popular da China*<br/>
Especifica o novo tamanho e posição do controle de versão prévia.

*bRedraw*<br/>
Especifica se o controle deve ser redesenhado.

### <a name="remarks"></a>Comentários

Normalmente, um novo retângulo delimitador é definido quando o controle de host é redimensionado.

## <a name="dtor"></a> CMFCPreviewCtrlImpl:: ~ CMFCPreviewCtrlImpl

Destructs um objeto de controle de versão prévia.

### <a name="syntax"></a>Sintaxe

```
virtual ~CMFCPreviewCtrlImpl();
```

