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
ms.openlocfilehash: f77f1c265920bd160da790647ef754c55e6dbda3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369353"
---
# <a name="cctrlview-class"></a>Classe CCtrlView

Adapta a arquitetura de visualização de documentos aos controles comuns suportados pelas versões 3.51 do Windows 98 e Windows NT e posteriores.

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
|[CCtrlView::OnDraw](#ondraw)|Chamado pela estrutura para desenhar usando o contexto do dispositivo especificado.|
|[CCtrlView::PreCriarjanela](#precreatewindow)|Chamado antes da criação da janela `CCtrlView` do Windows anexada a este objeto.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CCtrlView::m_dwDefaultStyle](#m_dwdefaultstyle)|Contém o estilo padrão para a classe de exibição.|
|[CCtrlView::m_strClass](#m_strclass)|Contém o nome da classe Windows para a classe de exibição.|

## <a name="remarks"></a>Comentários

A `CCtrlView` classe e seus derivados, [CEditView,](../../mfc/reference/ceditview-class.md) [CListView,](../../mfc/reference/clistview-class.md) [CTreeView](../../mfc/reference/ctreeview-class.md)e [CRichEditView,](../../mfc/reference/cricheditview-class.md)adaptam a arquitetura de exibição de documentos aos novos controles comuns suportados pelas versões 3.51 do Windows 95/98 e Windows NT 3.51 e posteriores. Para obter mais informações sobre a arquitetura de exibição de documentos, consulte [Arquitetura de documentos/exibição](../../mfc/document-view-architecture.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

`CCtrlView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cctrlviewcctrlview"></a><a name="cctrlview"></a>CCtrlView::CCtrlView

Constrói um objeto `CCtrlView`.

```
CCtrlView(
    LPCTSTR lpszClass,
    DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*lpszClass*<br/>
Nome da classe do Windows da classe de exibição.

*Dwstyle*<br/>
Estilo da aula de vista.

### <a name="remarks"></a>Comentários

A estrutura chama o construtor quando uma nova janela de quadro é criada ou uma janela é dividida. Anular [CView::OnInitialUpdate](../../mfc/reference/cview-class.md#oninitialupdate) para inicializar a exibição depois que o documento é anexado. Ligue [para CWnd::Create](../../mfc/reference/cwnd-class.md#create) ou [CWnd::CreateEx](../../mfc/reference/cwnd-class.md#createex) para criar o objeto Do Windows.

## <a name="cctrlviewm_strclass"></a><a name="m_strclass"></a>CCtrlView::m_strClass

Contém o nome da classe Windows para a classe de exibição.

```
CString m_strClass;
```

## <a name="cctrlviewm_dwdefaultstyle"></a><a name="m_dwdefaultstyle"></a>CCtrlView::m_dwDefaultStyle

Contém o estilo padrão para a classe de exibição.

```
DWORD m_dwDefaultStyle;
```

### <a name="remarks"></a>Comentários

Este estilo é aplicado quando uma janela é criada.

## <a name="cctrlviewondraw"></a><a name="ondraw"></a>CCtrlView::OnDraw

Chamado pela estrutura para desenhar `CCtrlView` o conteúdo do objeto usando o contexto do dispositivo especificado.

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para o contexto do dispositivo no qual ocorre o desenho.

### <a name="remarks"></a>Comentários

`OnDraw`é tipicamente chamado para exibição de tela, passando um contexto de dispositivo de tela especificado pelo *pDC*.

## <a name="cctrlviewprecreatewindow"></a><a name="precreatewindow"></a>CCtrlView::PreCriarjanela

Chamado antes da criação da janela `CWnd` do Windows anexada a este objeto.

```
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
```

### <a name="parameters"></a>Parâmetros

*Cs*<br/>
Uma [estrutura CRIATRUTE.](/windows/win32/api/winuser/ns-winuser-createstructw)

### <a name="return-value"></a>Valor retornado

Não zero se a criação da janela continuar; 0 para indicar falha na criação.

### <a name="remarks"></a>Comentários

Nunca chame essa função diretamente.

A implementação padrão desta função verifica o nome da classe da janela NULL e substitui um padrão apropriado. Substituir esta função de `CREATESTRUCT` membro para modificar a estrutura antes que a janela seja criada.

Cada classe derivada adiciona `CCtrlView` sua própria funcionalidade `PreCreateWindow`à sua substituição de . Pelo projeto, essas `PreCreateWindow` derivações não estão documentadas. Para determinar os estilos apropriados para cada classe e as interdependências entre os estilos, você pode examinar o código fonte do MFC para a classe base do aplicativo. Se você optar `PreCreateWindow`por substituir, você pode determinar se os estilos usados na classe base do aplicativo fornecem a funcionalidade necessária usando informações coletadas a partir do código-fonte do MFC.

Para obter mais informações sobre a alteração de estilos de janela, consulte a [Alteração dos Estilos de uma Janela Criada pelo MFC](../../mfc/changing-the-styles-of-a-window-created-by-mfc.md).

## <a name="see-also"></a>Confira também

[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CtreeView](../../mfc/reference/ctreeview-class.md)<br/>
[Classe CListView](../../mfc/reference/clistview-class.md)<br/>
[Classe CRichEditView](../../mfc/reference/cricheditview-class.md)
