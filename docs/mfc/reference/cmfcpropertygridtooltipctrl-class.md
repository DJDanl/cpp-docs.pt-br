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
ms.openlocfilehash: 82d5f021204628121be242845583797348d02120
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88840746"
---
# <a name="cmfcpropertygridtooltipctrl-class"></a>Classe CMFCPropertyGridToolTipCtrl

Implementa um controle ToolTip que a [classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) usa para exibir dicas de ferramenta.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyGridToolTipCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|-|-|
|[CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl](#cmfcpropertygridtooltipctrl)|Constrói um objeto `CMFCPropertyGridToolTipCtrl`.|
|`CMFCPropertyGridToolTipCtrl::~CMFCPropertyGridToolTipCtrl`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[CMFCPropertyGridToolTipCtrl:: criar](#create)|Cria uma janela para o controle ToolTip.|
|[CMFCPropertyGridToolTipCtrl::D eactivate](#deactivate)|Desativa e oculta o controle ToolTip.|
|[CMFCPropertyGridToolTipCtrl::GetLastRect](#getlastrect)|Retorna as coordenadas da última posição do controle ToolTip.|
|[CMFCPropertyGridToolTipCtrl:: Hide](#hide)|Oculta o controle ToolTip.|
|`CMFCPropertyGridToolTipCtrl::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para traduzir as mensagens de janela antes que elas sejam expedidas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) do Windows. (Substitui [CWnd::P retranslatemessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCPropertyGridToolTipCtrl::SetTextMargin](#settextmargin)|Define o espaçamento entre o texto da dica de ferramenta e a borda da janela de dica de ferramenta.|
|[CMFCPropertyGridToolTipCtrl:: Track](#track)|Exibe o controle ToolTip.|

## <a name="remarks"></a>Comentários

Dicas de ferramenta são exibidas quando o ponteiro é colocado em um nome de propriedade. A classe [CMFCPropertyGridToolTipCtrl](../../mfc/reference/cmfcpropertygridtooltipctrl-class.md) exibe uma dica de ferramenta para que ela seja facilmente legível pelo usuário. Normalmente, a posição de uma dica de ferramenta é determinada pela posição do ponteiro. Usando essa classe, a dica de ferramenta é exibida sobre o nome da propriedade e é semelhante à extensão de propriedade natural, para que o nome da propriedade esteja totalmente visível.

O MFC cria automaticamente esse controle e o usa na [classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto da `CMFCPropertyGridToolTipCtrl` classe e como exibir o controle ToolTip.

[!code-cpp[NVC_MFC_RibbonApp#23](../../mfc/reference/codesnippet/cpp/cmfcpropertygridtooltipctrl-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CMFCPropertyGridToolTipCtrl](../../mfc/reference/cmfcpropertygridtooltipctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertygridtooltipctrl. h

## <a name="cmfcpropertygridtooltipctrlcmfcpropertygridtooltipctrl"></a><a name="cmfcpropertygridtooltipctrl"></a> CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl

Constrói um objeto `CMFCPropertyGridToolTipCtrl`.

```
CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl();
```

## <a name="cmfcpropertygridtooltipctrlcreate"></a><a name="create"></a> CMFCPropertyGridToolTipCtrl:: criar

Cria uma janela para o controle ToolTip.

```
BOOL Create(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no Um ponteiro para a janela pai.

### <a name="return-value"></a>Valor Retornado

TRUE se a janela foi criada com êxito; caso contrário, FALSE.

## <a name="cmfcpropertygridtooltipctrldeactivate"></a><a name="deactivate"></a> CMFCPropertyGridToolTipCtrl::D eactivate

Desativa e oculta o controle ToolTip.

```cpp
void Deactivate();
```

### <a name="remarks"></a>Comentários

Esse método define a última posição e o texto como valores vazios, para que chamadas futuras para [CMFCPropertyGridToolTipCtrl:: Track](#track) exibam a dica de ferramenta.

## <a name="cmfcpropertygridtooltipctrlgetlastrect"></a><a name="getlastrect"></a> CMFCPropertyGridToolTipCtrl::GetLastRect

Retorna as coordenadas da última posição do controle ToolTip.

```cpp
void GetLastRect(CRect& rect) const;
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
fora Contém a última posição do controle ToolTip.

## <a name="cmfcpropertygridtooltipctrlhide"></a><a name="hide"></a> CMFCPropertyGridToolTipCtrl:: Hide

Oculta o controle ToolTip.

```cpp
void Hide();
```

## <a name="cmfcpropertygridtooltipctrlsettextmargin"></a><a name="settextmargin"></a> CMFCPropertyGridToolTipCtrl::SetTextMargin

Define o espaçamento entre o texto da dica de ferramenta e a borda da janela de dica de ferramenta.

```cpp
void SetTextMargin(int nTextMargin);
```

### <a name="parameters"></a>Parâmetros

*nTextMargin*<br/>
no Especifica o espaçamento entre o texto de controle de dica de ferramenta e a borda da janela de dica de ferramenta. O valor padrão é 10 pixels.

## <a name="cmfcpropertygridtooltipctrltrack"></a><a name="track"></a> CMFCPropertyGridToolTipCtrl:: Track

Exibe o controle ToolTip.

```cpp
void Track(
    CRect rect,
    const CString& strText);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
no Especifica a posição e o tamanho do controle ToolTip.

*strText*<br/>
no Especifica o texto a ser mostrado na dica de ferramenta.

### <a name="remarks"></a>Comentários

Esse método exibe o controle ToolTip na posição e no tamanho especificados por *Rect*. Se a posição, o tamanho e o texto não forem alterados desde a última vez que esse método foi chamado, esse método não terá efeito.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
