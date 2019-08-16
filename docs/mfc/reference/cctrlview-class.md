---
title: Classe CCtrlView
ms.date: 11/04/2016
f1_keywords:
- CCtrlView
- AFXWIN/CCtrlView
- AFXWIN/CCtrlView::CCtrlView
- AFXWIN/CCtrlView::OnDraw
- AFXWIN/CCtrlView::PreCreateWindow
- AFXWIN/CCtrlView::m_dwDefaultStyle
- AFXWIN/CCtrlView::m_strClass
helpviewer_keywords:
- CCtrlView [MFC], CCtrlView
- CCtrlView [MFC], OnDraw
- CCtrlView [MFC], PreCreateWindow
- CCtrlView [MFC], m_dwDefaultStyle
- CCtrlView [MFC], m_strClass
ms.assetid: ff488596-1e71-451f-8fec-b0831a7b44e0
ms.openlocfilehash: 334f139b81afeb06d57cbd128abe9e413b1fd0e7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507155"
---
# <a name="cctrlview-class"></a>Classe CCtrlView

Adapta a arquitetura de exibição de documento para os controles comuns com suporte no Windows 98 e nas versões 3,51 e posteriores do Windows NT.

## <a name="syntax"></a>Sintaxe

```
class CCtrlView : public CView
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CCtrlView::CCtrlView](#cctrlview)|Constrói um objeto `CCtrlView`.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CCtrlView:: OnDraw](#ondraw)|Chamado pelo Framework para desenhar usando o contexto de dispositivo especificado.|
|[CCtrlView::PreCreateWindow](#precreatewindow)|Chamado antes da criação da janela do Windows anexada a `CCtrlView` este objeto.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CCtrlView::m_dwDefaultStyle](#m_dwdefaultstyle)|Contém o estilo padrão para a classe View.|
|[CCtrlView::m_strClass](#m_strclass)|Contém o nome da classe do Windows para a classe View.|

## <a name="remarks"></a>Comentários

A classe `CCtrlView` e seus derivados, [CEditView](../../mfc/reference/ceditview-class.md), [CListView](../../mfc/reference/clistview-class.md), [CTreeView](../../mfc/reference/ctreeview-class.md)e [CRichEditView](../../mfc/reference/cricheditview-class.md), adaptam a arquitetura de exibição de documento para os novos controles comuns com suporte no Windows 95/98 e no Windows NT versões 3,51 e posterior. Para obter mais informações sobre a arquitetura de exibição de documento, consulte [arquitetura de documento/exibição](../../mfc/document-view-architecture.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cvisualização](../../mfc/reference/cview-class.md)

`CCtrlView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cctrlview"></a>CCtrlView::CCtrlView

Constrói um objeto `CCtrlView`.

```
CCtrlView(
    LPCTSTR lpszClass,
    DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*lpszClass*<br/>
Nome da classe do Windows da classe View.

*dwStyle*<br/>
Estilo da classe de exibição.

### <a name="remarks"></a>Comentários

A estrutura chama o Construtor quando uma nova janela de quadro é criada ou uma janela é dividida. Substitua [cvisualização:: OnInitialUpdate](../../mfc/reference/cview-class.md#oninitialupdate) para inicializar a exibição depois que o documento for anexado. Chame [CWnd:: Create](../../mfc/reference/cwnd-class.md#create) ou [CWnd:: CreateEx](../../mfc/reference/cwnd-class.md#createex) para criar o objeto do Windows.

##  <a name="m_strclass"></a>CCtrlView::m_strClass

Contém o nome da classe do Windows para a classe View.

```
CString m_strClass;
```

##  <a name="m_dwdefaultstyle"></a>  CCtrlView::m_dwDefaultStyle

Contém o estilo padrão para a classe View.

```
DWORD m_dwDefaultStyle;
```

### <a name="remarks"></a>Comentários

Esse estilo é aplicado quando uma janela é criada.

##  <a name="ondraw"></a>CCtrlView:: OnDraw

Chamado pelo Framework para desenhar o conteúdo do `CCtrlView` objeto usando o contexto de dispositivo especificado.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para o contexto do dispositivo no qual o desenho ocorre.

### <a name="remarks"></a>Comentários

`OnDraw`é normalmente chamado para exibição de tela, passando um contexto de dispositivo de tela especificado pelo *PDC*.

##  <a name="precreatewindow"></a>CCtrlView::P recreatewindow

Chamado antes da criação da janela do Windows anexada a `CWnd` este objeto.

```
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
```

### <a name="parameters"></a>Parâmetros

*cs*<br/>
Uma estrutura [CREATESTRUCT](/windows/win32/api/winuser/ns-winuser-createstructw).

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a criação da janela continuar; 0 para indicar falha na criação.

### <a name="remarks"></a>Comentários

Nunca chame essa função diretamente.

A implementação padrão dessa função verifica um nome de classe de janela nula e substitui um padrão apropriado. Substitua essa função de membro para modificar `CREATESTRUCT` a estrutura antes de a janela ser criada.

Cada classe derivada de `CCtrlView` adiciona sua própria funcionalidade à sua substituição de `PreCreateWindow`. Por design, essas derivações do `PreCreateWindow` não são documentadas. Para determinar os estilos apropriados para cada classe e as interdependências entre os estilos, você pode examinar o código-fonte do MFC para a classe base do seu aplicativo. Se você optar por substituir `PreCreateWindow`, poderá determinar se os estilos usados na classe base do seu aplicativo fornecem a funcionalidade necessária usando as informações coletadas do código-fonte do MFC.

Para obter mais informações sobre como alterar estilos de janela, consulte [alterando os estilos de uma janela criada pelo MFC](../../mfc/changing-the-styles-of-a-window-created-by-mfc.md).

## <a name="see-also"></a>Consulte também

[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CTreeView](../../mfc/reference/ctreeview-class.md)<br/>
[Classe CListView](../../mfc/reference/clistview-class.md)<br/>
[Classe CRichEditView](../../mfc/reference/cricheditview-class.md)
