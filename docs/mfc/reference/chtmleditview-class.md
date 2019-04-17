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
ms.openlocfilehash: 8267a5272d2d542c4679bf30aa9d3ad8b933d81d
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58767192"
---
# <a name="chtmleditview-class"></a>Classe CHtmlEditView

Fornece a funcionalidade da plataforma de edição WebBrowser no contexto da arquitetura de documento/exibição do MFC.

## <a name="syntax"></a>Sintaxe

```
class CHtmlEditView : public CHtmlView, public CHtmlEditCtrlBase<CHtmlEditView>
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHtmlEditView::CHtmlEditView](#chtmleditview)|Constrói um objeto `CHtmlEditView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHtmlEditView::Create](#create)|Cria um novo objeto de janela.|
|[CHtmlEditView::GetDHtmlDocument](#getdhtmldocument)|Retorna o `IHTMLDocument2` interface no documento atual.|
|[CHtmlEditView::GetStartDocument](#getstartdocument)|Recupera o nome do documento padrão para esta exibição.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[CScrollView](../../mfc/reference/cscrollview-class.md)

[CFormView](../../mfc/reference/cformview-class.md)

[CHtmlEditCtrlBase](../../mfc/reference/chtmleditctrlbase-class.md)

[CHtmlView](../../mfc/reference/chtmlview-class.md)

`CHtmlEditView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxhtml.h

##  <a name="chtmleditview"></a>  CHtmlEditView::CHtmlEditView

Constrói um objeto `CHtmlEditView`.

```
CHtmlEditView();
```

##  <a name="create"></a>  CHtmlEditView::Create

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

*lpszClassName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe Windows. O nome de classe pode ser qualquer nome registrado com o [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função global ou o `RegisterClass` função do Windows. Se for NULL, usa o padrão predefinido [CFrameWnd](../../mfc/reference/cframewnd-class.md) atributos.

*lpszWindowName*<br/>
Aponta para uma cadeia de caracteres com terminação nula que representa o nome da janela.

*dwStyle*<br/>
Especifica os atributos de estilo de janela. Por padrão, os estilos WS_VISIBLE e WS_CHILD Windows são definidos.

*rect*<br/>
Uma referência a um [RECT](/previous-versions/dd162897\(v=vs.85\)) especificando o tamanho e posição da janela de estrutura. O *rectDefault* valor permite que o Windows especificar o tamanho e posição da nova janela.

*pParentWnd*<br/>
Um ponteiro para a janela pai do controle.

*nID*<br/>
O número de identificação do modo de exibição. Por padrão, definido como AFX_IDW_PANE_FIRST.

*pContext*<br/>
Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md). NULL por padrão.

### <a name="remarks"></a>Comentários

Esse método também chamará o WebBrowser independente `Navigate` método para carregar um documento padrão (consulte [CHtmlEditView::GetStartDocument](#getstartdocument)).

##  <a name="getdhtmldocument"></a>  CHtmlEditView::GetDHtmlDocument

Retorna o `IHTMLDocument2` interface no documento atual.

```
BOOL GetDHtmlDocument(IHTMLDocument2** ppDocument) const;
```

### <a name="parameters"></a>Parâmetros

*ppDocument*<br/>
O [IHTMLDocument2](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752574\(v=vs.85\)) interface.

##  <a name="getstartdocument"></a>  CHtmlEditView::GetStartDocument

Recupera o nome do documento padrão para esta exibição.

```
virtual LPCTSTR GetStartDocument();
```

## <a name="see-also"></a>Consulte também

[Exemplo de HTMLEdit](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
