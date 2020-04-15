---
title: Classe CHtmlEditView
ms.date: 11/04/2016
f1_keywords:
- CHtmlEditView
- AFXHTML/CHtmlEditView
- AFXHTML/CHtmlEditView::CHtmlEditView
- AFXHTML/CHtmlEditView::Create
- AFXHTML/CHtmlEditView::GetDHtmlDocument
- AFXHTML/CHtmlEditView::GetStartDocument
helpviewer_keywords:
- CHtmlEditView [MFC], CHtmlEditView
- CHtmlEditView [MFC], Create
- CHtmlEditView [MFC], GetDHtmlDocument
- CHtmlEditView [MFC], GetStartDocument
ms.assetid: 166c8ba8-3fb5-4dd7-a9ea-5bca662d00f6
ms.openlocfilehash: 1254a3412846cdebd1d9accb91d27d0afbc4ef8d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352074"
---
# <a name="chtmleditview-class"></a>Classe CHtmlEditView

Fornece a funcionalidade da plataforma de edição do WebBrowser no contexto da arquitetura de documentos/exibição do MFC.

## <a name="syntax"></a>Sintaxe

```
class CHtmlEditView : public CHtmlView, public CHtmlEditCtrlBase<CHtmlEditView>
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[chtmleditview::Chtmleditview](#chtmleditview)|Constrói um objeto `CHtmlEditView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[ChtmleditView::Criar](#create)|Cria um novo objeto de janela.|
|[chtmleditview::getdhtmlDocument](#getdhtmldocument)|Retorna `IHTMLDocument2` a interface no documento atual.|
|[Chtmleditview::getStartDocument](#getstartdocument)|Recupera o nome do documento padrão para esta exibição.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

[CFormView](../../mfc/reference/cformview-class.md)

[Chtmleditctrlbase](../../mfc/reference/chtmleditctrlbase-class.md)

[Chtmlview](../../mfc/reference/chtmlview-class.md)

`CHtmlEditView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxhtml.h

## <a name="chtmleditviewchtmleditview"></a><a name="chtmleditview"></a>chtmleditview::Chtmleditview

Constrói um objeto `CHtmlEditView`.

```
CHtmlEditView();
```

## <a name="chtmleditviewcreate"></a><a name="create"></a>ChtmleditView::Criar

Cria um novo objeto de janela.

```
virtual BOOL Create(
    LPCTSTR lpszClassName,
    LPCTSTR lpszWindowName,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID,
    CCreateContext* pContext = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lpszclassname*<br/>
Aponta para uma seqüência de caracteres com término nulo que nomeia a classe Windows. O nome da classe pode ser qualquer nome registrado na função `RegisterClass` global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) ou na função Windows. Se NULL, usa os atributos [CFrameWnd](../../mfc/reference/cframewnd-class.md) padrão predefinidos.

*lpszWindowName*<br/>
Aponta para uma seqüência de caracteres com término nulo que representa o nome da janela.

*Dwstyle*<br/>
Especifica os atributos de estilo da janela. Por padrão, os estilos WS_VISIBLE e WS_CHILD do Windows são definidos.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) especificando o tamanho e a posição da janela. O valor *rectDefault* permite que o Windows especifique o tamanho e a posição da nova janela.

*Pparentwnd*<br/>
Um ponteiro para a janela pai do controle.

*nID*<br/>
O número de ida da vista. Por padrão, defina para AFX_IDW_PANE_FIRST.

*pContext*<br/>
Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md). NULL por padrão.

### <a name="remarks"></a>Comentários

Este método também chamará o `Navigate` método do WebBrowser contido para carregar um documento padrão (consulte [CHtmlEditView::GetStartDocument](#getstartdocument)).

## <a name="chtmleditviewgetdhtmldocument"></a><a name="getdhtmldocument"></a>chtmleditview::getdhtmlDocument

Retorna `IHTMLDocument2` a interface no documento atual.

```
BOOL GetDHtmlDocument(IHTMLDocument2** ppDocument) const;
```

### <a name="parameters"></a>Parâmetros

*ppDocument*<br/>
A interface [IHTMLDocument2.](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752574\(v=vs.85\))

## <a name="chtmleditviewgetstartdocument"></a><a name="getstartdocument"></a>Chtmleditview::getStartDocument

Recupera o nome do documento padrão para esta exibição.

```
virtual LPCTSTR GetStartDocument();
```

## <a name="see-also"></a>Confira também

[Amostra de HTMLEdit](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
