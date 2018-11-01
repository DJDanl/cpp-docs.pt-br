---
title: Classe CMFCPropertyGridToolTipCtrl
ms.date: 11/04/2016
f1_keywords:
- CMFCPropertyGridToolTipCtrl
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::Create
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::Deactivate
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::GetLastRect
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::Hide
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::SetTextMargin
- AFXPROPERTYGRIDTOOLTIPCTRL/CMFCPropertyGridToolTipCtrl::Track
helpviewer_keywords:
- CMFCPropertyGridToolTipCtrl [MFC], CMFCPropertyGridToolTipCtrl
- CMFCPropertyGridToolTipCtrl [MFC], Create
- CMFCPropertyGridToolTipCtrl [MFC], Deactivate
- CMFCPropertyGridToolTipCtrl [MFC], GetLastRect
- CMFCPropertyGridToolTipCtrl [MFC], Hide
- CMFCPropertyGridToolTipCtrl [MFC], SetTextMargin
- CMFCPropertyGridToolTipCtrl [MFC], Track
ms.assetid: 84b436e5-6695-4da0-9569-1a875e087711
ms.openlocfilehash: a7262416fa3555993ea237dd2f6b82b73ed9949c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50429088"
---
# <a name="cmfcpropertygridtooltipctrl-class"></a>Classe CMFCPropertyGridToolTipCtrl

Implementa uma dica de ferramenta de controle que o [classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) usa para exibir dicas de ferramenta.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyGridToolTipCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl](#cmfcpropertygridtooltipctrl)|Constrói um objeto `CMFCPropertyGridToolTipCtrl`.|
|`CMFCPropertyGridToolTipCtrl::~CMFCPropertyGridToolTipCtrl`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCPropertyGridToolTipCtrl::Create](#create)|Cria uma janela para o controle de dica de ferramenta.|
|[CMFCPropertyGridToolTipCtrl::Deactivate](#deactivate)|Desativa e oculta o controle de dica de ferramenta.|
|[CMFCPropertyGridToolTipCtrl::GetLastRect](#getlastrect)|Retorna as coordenadas da última posição do controle de dica de ferramenta.|
|[CMFCPropertyGridToolTipCtrl::Hide](#hide)|Oculta o controle de dica de ferramenta.|
|`CMFCPropertyGridToolTipCtrl::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para converter as mensagens da janela antes de serem expedidas para o [TranslateMessage](/windows/desktop/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/desktop/api/winuser/nf-winuser-dispatchmessage) funções do Windows. (Substitui [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCPropertyGridToolTipCtrl::SetTextMargin](#settextmargin)|Define o espaçamento entre o texto de dica de ferramenta e a borda da janela de dica de ferramenta.|
|[CMFCPropertyGridToolTipCtrl::Track](#track)|Exibe o controle de dica de ferramenta.|

## <a name="remarks"></a>Comentários

Dicas de ferramenta são exibidas quando o ponteiro permanece em um nome de propriedade. O [CMFCPropertyGridToolTipCtrl](../../mfc/reference/cmfcpropertygridtooltipctrl-class.md) classe exibe uma dica de ferramenta para que ele seja facilmente legível pelo usuário. Normalmente, a posição de uma dica de ferramenta é determinada pela posição do ponteiro. Ao usar essa classe, a dica de ferramenta aparece sobre o nome da propriedade e se parece com a extensão de propriedade natural, para que o nome da propriedade está completamente visível.

MFC cria esse controle e usa-o no automaticamente a [classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto do `CMFCPropertyGridToolTipCtrl` classe e como exibir o controle de dica de ferramenta.

[!code-cpp[NVC_MFC_RibbonApp#23](../../mfc/reference/codesnippet/cpp/cmfcpropertygridtooltipctrl-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CMFCPropertyGridToolTipCtrl](../../mfc/reference/cmfcpropertygridtooltipctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertygridtooltipctrl.h

##  <a name="cmfcpropertygridtooltipctrl"></a>  CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl

Constrói um objeto `CMFCPropertyGridToolTipCtrl`.

```
CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl();
```

##  <a name="create"></a>  CMFCPropertyGridToolTipCtrl::Create

Cria uma janela para o controle de dica de ferramenta.

```
BOOL Create(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[in] Um ponteiro para a janela pai.

### <a name="return-value"></a>Valor de retorno

TRUE se a janela foi criada com êxito; Caso contrário, FALSE.

##  <a name="deactivate"></a>  CMFCPropertyGridToolTipCtrl::Deactivate

Desativa e oculta o controle de dica de ferramenta.

```
void Deactivate();
```

### <a name="remarks"></a>Comentários

Esse método define a última posição e o texto para valores vazios, para que as futuras chamadas para [CMFCPropertyGridToolTipCtrl::Track](#track) exibir a dica de ferramenta.

##  <a name="getlastrect"></a>  CMFCPropertyGridToolTipCtrl::GetLastRect

Retorna as coordenadas da última posição do controle de dica de ferramenta.

```
void GetLastRect(CRect& rect) const;
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[out] Contém a última posição do controle de dica de ferramenta.

##  <a name="hide"></a>  CMFCPropertyGridToolTipCtrl::Hide

Oculta o controle de dica de ferramenta.

```
void Hide();
```

##  <a name="settextmargin"></a>  CMFCPropertyGridToolTipCtrl::SetTextMargin

Define o espaçamento entre o texto de dica de ferramenta e a borda da janela de dica de ferramenta.

```
void SetTextMargin(int nTextMargin);
```

### <a name="parameters"></a>Parâmetros

*nTextMargin*<br/>
[in] Especifica o espaçamento entre o texto de dica de ferramenta de controle e a borda da janela de dica de ferramenta. O valor padrão é 10 pixels.

##  <a name="track"></a>  CMFCPropertyGridToolTipCtrl::Track

Exibe o controle de dica de ferramenta.

```
void Track(
    CRect rect,
    const CString& strText);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[in] Especifica a posição e o tamanho do controle de dica de ferramenta.

*strText*<br/>
[in] Especifica o texto a ser mostrado na dica de ferramenta.

### <a name="remarks"></a>Comentários

Esse método exibe o controle de dica de ferramenta na posição e tamanho especificado pelo *rect*. Se a posição, tamanho e texto não foram alterados desde a última vez em que esse método foi chamado, esse método não terá efeito.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
