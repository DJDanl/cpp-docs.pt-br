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
ms.openlocfilehash: fc5d6d99c326fba7020e8c5040c3bf28d09f8f0a
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754122"
---
# <a name="cmfcpropertygridtooltipctrl-class"></a>Classe CMFCPropertyGridToolTipCtrl

Implementa um controle de ponta de ferramenta que a [Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) usa para exibir dicas de ferramentas.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertyGridToolTipCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl](#cmfcpropertygridtooltipctrl)|Constrói um objeto `CMFCPropertyGridToolTipCtrl`.|
|`CMFCPropertyGridToolTipCtrl::~CMFCPropertyGridToolTipCtrl`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|||
|-|-|
|Nome|Descrição|
|[CMFCPropertyGridToolTipCtrl::Create](#create)|Cria uma janela para o controle da ponta de ferramenta.|
|[CMFCPropertyGridToolTipCtrl::Deactivate](#deactivate)|Desativa e oculta o controle da ponta de ferramenta.|
|[CMFCPropertyGridToolTipCtrl::GetLastRect](#getlastrect)|Retorna as coordenadas da última posição do controle da ponta de ferramenta.|
|[CMFCPropertyGridToolTipCtrl::Hide](#hide)|Esconde o controle da ponta de ferramenta.|
|`CMFCPropertyGridToolTipCtrl::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para traduzir mensagens de janela antes de serem enviadas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows. (Substitui [cwnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCPropertyGridToolTipctrl::SetTextMargin](#settextmargin)|Define o espaçamento entre o texto da dica de ferramenta e a borda da janela da ponta de ferramenta.|
|[CMFCPropertyGridToolTipCtrl::Track](#track)|Exibe o controle da ponta da ferramenta.|

## <a name="remarks"></a>Comentários

As dicas de ferramentas são exibidas quando o ponteiro repousa sobre um nome de propriedade. A classe [CMFCPropertyGridToolTipCtrl](../../mfc/reference/cmfcpropertygridtooltipctrl-class.md) exibe uma dica de ferramenta para que seja facilmente legível pelo usuário. Normalmente, a posição de uma ponta de ferramenta é determinada pela posição do ponteiro. Ao usar esta classe, a dica de ferramenta aparece sobre o nome da propriedade e se assemelha à extensão da propriedade natural, de modo que o nome da propriedade seja totalmente visível.

O MFC cria automaticamente esse controle e o usa na [Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCPropertyGridToolTipCtrl` construir um objeto da classe e como exibir o controle da dica de ferramenta.

[!code-cpp[NVC_MFC_RibbonApp#23](../../mfc/reference/codesnippet/cpp/cmfcpropertygridtooltipctrl-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cmfcpropertygridtooltipctrl](../../mfc/reference/cmfcpropertygridtooltipctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertygridtooltipctrl.h

## <a name="cmfcpropertygridtooltipctrlcmfcpropertygridtooltipctrl"></a><a name="cmfcpropertygridtooltipctrl"></a>CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl

Constrói um objeto `CMFCPropertyGridToolTipCtrl`.

```
CMFCPropertyGridToolTipCtrl::CMFCPropertyGridToolTipCtrl();
```

## <a name="cmfcpropertygridtooltipctrlcreate"></a><a name="create"></a>CMFCPropertyGridToolTipCtrl::Create

Cria uma janela para o controle da ponta de ferramenta.

```
BOOL Create(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Um ponteiro para a janela dos pais.

### <a name="return-value"></a>Valor retornado

TRUE se a janela foi criada com sucesso; caso contrário, FALSE.

## <a name="cmfcpropertygridtooltipctrldeactivate"></a><a name="deactivate"></a>CMFCPropertyGridToolTipCtrl::Deactivate

Desativa e oculta o controle da ponta de ferramenta.

```cpp
void Deactivate();
```

### <a name="remarks"></a>Comentários

Este método define a última posição e o texto como valores vazios, de modo que as chamadas futuras para [CMFCPropertyGridToolTipCtrl::Track](#track) exibam a dica de ferramenta.

## <a name="cmfcpropertygridtooltipctrlgetlastrect"></a><a name="getlastrect"></a>CMFCPropertyGridToolTipCtrl::GetLastRect

Retorna as coordenadas da última posição do controle da ponta de ferramenta.

```cpp
void GetLastRect(CRect& rect) const;
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[fora] Contém a última posição do controle da ponta de ferramenta.

## <a name="cmfcpropertygridtooltipctrlhide"></a><a name="hide"></a>CMFCPropertyGridToolTipCtrl::Hide

Esconde o controle da ponta de ferramenta.

```cpp
void Hide();
```

## <a name="cmfcpropertygridtooltipctrlsettextmargin"></a><a name="settextmargin"></a>CMFCPropertyGridToolTipctrl::SetTextMargin

Define o espaçamento entre o texto da dica de ferramenta e a borda da janela da ponta de ferramenta.

```cpp
void SetTextMargin(int nTextMargin);
```

### <a name="parameters"></a>Parâmetros

*nTextMargin*<br/>
[em] Especifica o espaçamento entre o texto de controle da dica de ferramenta e a borda da janela da dica de ferramenta. O valor padrão é de 10 pixels.

## <a name="cmfcpropertygridtooltipctrltrack"></a><a name="track"></a>CMFCPropertyGridToolTipCtrl::Track

Exibe o controle da ponta da ferramenta.

```cpp
void Track(
    CRect rect,
    const CString& strText);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] Especifica a posição e o tamanho do controle da ponta de ferramenta.

*strText*<br/>
[em] Especifica o texto a ser mostrado na dica de ferramenta.

### <a name="remarks"></a>Comentários

Este método exibe o controle da ponta de ferramenta na posição e tamanho especificados pelo *rect*. Se a posição, o tamanho e o texto não mudaram desde a última vez que este método foi chamado, este método não terá efeito.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
