---
title: Classe CReBar
ms.date: 11/19/2018
f1_keywords:
- CReBar
- AFXEXT/CReBar
- AFXEXT/CReBar::AddBar
- AFXEXT/CReBar::Create
- AFXEXT/CReBar::GetReBarCtrl
helpviewer_keywords:
- CReBar [MFC], AddBar
- CReBar [MFC], Create
- CReBar [MFC], GetReBarCtrl
ms.assetid: c1ad2720-1d33-4106-8e4e-80aa84f93559
ms.openlocfilehash: 434232e8f99bf914b00379db53d4b4a37d24fe36
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502789"
---
# <a name="crebar-class"></a>Classe CReBar

Uma barra de controle que fornece informações de layout, persistência e estado para controles Rebar.

## <a name="syntax"></a>Sintaxe

```
class CReBar : public CControlBar
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CReBar::AddBar](#addbar)|Adiciona uma banda a um Rebar.|
|[CReBar:: criar](#create)|Cria o controle rebar e o `CReBar` anexa ao objeto.|
|[CReBar::GetReBarCtrl](#getrebarctrl)|Permite acesso direto ao controle comum subjacente.|

## <a name="remarks"></a>Comentários

Um objeto rebar pode conter uma variedade de janelas filhas, geralmente outros controles, incluindo caixas de edição, barras de ferramentas e caixas de listagem. Um objeto rebar pode exibir suas janelas filhas em um bitmap especificado. Seu aplicativo pode redimensionar automaticamente o rebar ou o usuário pode redimensionar manualmente o rebar clicando ou arrastando sua barra de garra.

![Exemplo de RebarMenu](../../mfc/reference/media/vc4sc61.gif "Exemplo de RebarMenu")

## <a name="rebar-control"></a>Controle rebar

Um objeto rebar se comporta de forma semelhante a um objeto Toolbar. Um rebar usa o mecanismo de clicar e arrastar para redimensionar suas faixas. Um controle rebar pode conter uma ou mais bandas, sendo que cada banda tem qualquer combinação de uma barra de garra, um bitmap, um rótulo de texto e uma janela filho. No entanto, as faixas não podem conter mais de uma janela filho.

`CReBar`usa a classe [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) para fornecer sua implementação. Você pode acessar o controle rebar por meio do [GetReBarCtrl](#getrebarctrl) para aproveitar as opções de personalização do controle. Para obter mais informações sobre controles Rebar, `CReBarCtrl`consulte. Para obter mais informações sobre como usar controles Rebar, consulte [usando CReBarCtrl](../../mfc/using-crebarctrl.md).

> [!CAUTION]
>  Os objetos de controle rebar e rebar não dão suporte ao encaixe da barra de controle do MFC. Se `CRebar::EnableDocking` for chamado, seu aplicativo será declarado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CControlBar](../../mfc/reference/ccontrolbar-class.md)

`CReBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext. h

##  <a name="addbar"></a>  CReBar::AddBar

Chame essa função de membro para adicionar uma banda ao Rebar.

```
BOOL AddBar(
    CWnd* pBar,
    LPCTSTR pszText = NULL,
    CBitmap* pbmp = NULL,
    DWORD dwStyle = RBBS_GRIPPERALWAYS | RBBS_FIXEDBMP);

BOOL AddBar(
    CWnd* pBar,
    COLORREF clrFore,
    COLORREF clrBack,
    LPCTSTR pszText = NULL,
    DWORD dwStyle = RBBS_GRIPPERALWAYS);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
Um ponteiro para um `CWnd` objeto que é a janela filho a ser inserida no Rebar. O objeto referenciado deve ter um WS_CHILD.

*lpszText*<br/>
Um ponteiro para uma cadeia de caracteres que contém o texto a ser exibido no Rebar. NULL por padrão. O texto contido em *lpszText* não faz parte da janela filho; Ele está no próprio próprio Rebar.

*pbmp*<br/>
Um ponteiro para um `CBitmap` objeto a ser exibido no plano de fundo do rebar. NULL por padrão.

*dwStyle*<br/>
Um DWORD que contém o estilo a ser aplicado ao Rebar. Consulte a `fStyle` descrição da função no [REBARBANDINFO](/windows/win32/api/commctrl/ns-commctrl-rebarbandinfow) de estrutura do Win32 para obter uma lista completa de estilos de banda.

*clrFore*<br/>
Um valor COLORREF que representa a cor de primeiro plano do rebar.

*clrBack*<br/>
Um valor COLORREF que representa a cor do plano de fundo do rebar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#1](../../mfc/reference/codesnippet/cpp/crebar-class_1.cpp)]

##  <a name="create"></a>  CReBar::Create

Chame essa função de membro para criar um Rebar.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = RBS_BANDBORDERS,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_TOP,
    UINT nID = AFX_IDW_REBAR);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Ponteiro para o `CWnd` objeto cuja janela do Windows é o pai da barra de status. Normalmente, a janela do quadro.

*dwCtrlStyle*<br/>
O estilo de controle rebar. Por padrão, RBS_BANDBORDERS, que exibe linhas estreitas para separar as faixas adjacentes dentro do controle rebar. Consulte [estilos de controle rebar](/windows/win32/Controls/rebar-control-styles) no SDK do Windows para obter uma lista de estilos.

*dwStyle*<br/>
Os estilos de janela do rebar.

*nID*<br/>
A ID da janela filho do rebar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CReBar:: AddBar](#addbar).

##  <a name="getrebarctrl"></a>  CReBar::GetReBarCtrl

Essa função de membro permite o acesso direto ao controle comum subjacente.

```
CReBarCtrl& GetReBarCtrl() const;
```

### <a name="return-value"></a>Valor de retorno

Uma referência a um objeto [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) .

### <a name="remarks"></a>Comentários

Chame essa função de membro para aproveitar a funcionalidade do controle comum do Windows rebar na personalização de seu rebar. Quando você chama `GetReBarCtrl`, ele retorna um objeto de referência para `CReBarCtrl` o objeto para que você possa usar qualquer conjunto de funções de membro.

Para obter mais informações sobre `CReBarCtrl` como usar o para personalizar seu rebar, consulte [usando o CReBarCtrl](../../mfc/using-crebarctrl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#2](../../mfc/reference/codesnippet/cpp/crebar-class_2.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de MFCIE do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
