---
title: Classe Crebar
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
ms.openlocfilehash: c1379d1ef8effea0df564da1b43769bb9a11435d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363938"
---
# <a name="crebar-class"></a>Classe Crebar

Uma barra de controle que fornece informações de layout, persistência e estado para controles de vergalhões.

## <a name="syntax"></a>Sintaxe

```
class CReBar : public CControlBar
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Crebar::Addbar](#addbar)|Adiciona uma banda a um vergalhão.|
|[CRebar::Criar](#create)|Cria o controle do vergalhão e o prende ao `CReBar` objeto.|
|[CReBar::GetReBarCtrl](#getrebarctrl)|Permite acesso direto ao controle comum subjacente.|

## <a name="remarks"></a>Comentários

Um objeto de vergalhões pode conter uma variedade de janelas de crianças, geralmente outros controles, incluindo caixas de edição, barras de ferramentas e caixas de lista. Um objeto de vergalhões pode exibir suas janelas filho sobre um bitmap especificado. Seu aplicativo pode redimensionar automaticamente a vergalhões, ou o usuário pode redimensionar manualmente a vergalhão clicando ou arrastando sua barra de aperto.

![Exemplo de RebarMenu](../../mfc/reference/media/vc4sc61.gif "Exemplo de RebarMenu")

## <a name="rebar-control"></a>Controle de barras

Um objeto de vergalhões se comporta de forma semelhante a um objeto de barra de ferramentas. Uma vergalhão usa o mecanismo de clique e arrasto para redimensionar suas bandas. Um controle de vergalhões pode conter uma ou mais bandas, com cada banda tendo qualquer combinação de uma barra de aperto, um bitmap, uma etiqueta de texto e uma janela infantil. No entanto, as bandas não podem conter mais de uma janela infantil.

`CReBar`usa a classe [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) para fornecer sua implementação. Você pode acessar o controle do vergalhão através [do GetReBarCtrl](#getrebarctrl) para aproveitar as opções de personalização do controle. Para obter mais informações sobre `CReBarCtrl`controles de vergalhões, consulte . Para obter mais informações sobre como usar controles de verbar, consulte [Usando CReBarCtrl](../../mfc/using-crebarctrl.md).

> [!CAUTION]
> Os objetos de controle de vergalhões e vergalhões não suportam o encaixe da barra de controle MFC. Se `CRebar::EnableDocking` for chamado, sua aplicação afirmará.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Ccontrolbar](../../mfc/reference/ccontrolbar-class.md)

`CReBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="crebaraddbar"></a><a name="addbar"></a>Crebar::Addbar

Chame esta função de membro para adicionar uma banda ao vergalhão.

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

*Pbar*<br/>
Um ponteiro `CWnd` para um objeto que é a janela da criança a ser inserida no vergalhão. O objeto referenciado deve ter uma WS_CHILD.

*lpszText*<br/>
Um ponteiro para uma seqüência contendo o texto para aparecer no vergalhão. NULL por padrão. O texto contido no *lpszText* não faz parte da janela infantil; está no próprio vergalhão.

*pbmp*<br/>
Um ponteiro `CBitmap` para um objeto a ser exibido no fundo do vergalhão. NULL por padrão.

*Dwstyle*<br/>
Um DWORD contendo o estilo a ser aplicado ao vergalhão. Consulte `fStyle` a descrição da função na estrutura Win32 [REBARBANDINFO](/windows/win32/api/commctrl/ns-commctrl-rebarbandinfow) para obter uma lista completa de estilos de banda.

*clrFore*<br/>
Um valor COLORREF que representa a cor do primeiro plano do vergalhão.

*clrBack*<br/>
Um valor COLORREF que representa a cor de fundo do vergalhão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#1](../../mfc/reference/codesnippet/cpp/crebar-class_1.cpp)]

## <a name="crebarcreate"></a><a name="create"></a>CRebar::Criar

Chame esta função de membro para criar um vergalhão.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = RBS_BANDBORDERS,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_TOP,
    UINT nID = AFX_IDW_REBAR);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Ponteiro para `CWnd` o objeto cuja janela do Windows é o pai da barra de status. Normalmente sua janela de moldura.

*dwCtrlStyle*<br/>
O estilo de controle do vergalhão. Por padrão, RBS_BANDBORDERS, que exibe linhas estreitas para bandas adjacentes separadas dentro do controle do vergalhão. Consulte [Estilos de controle](/windows/win32/Controls/rebar-control-styles) de barras no SDK do Windows para obter uma lista de estilos.

*Dwstyle*<br/>
Os estilos da janela do vergalhão.

*nID*<br/>
A id da janela infantil do vergalhão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CReBar::AddBar](#addbar).

## <a name="crebargetrebarctrl"></a><a name="getrebarctrl"></a>CReBar::GetReBarCtrl

Esta função de membro permite acesso direto ao controle comum subjacente.

```
CReBarCtrl& GetReBarCtrl() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência a um objeto [CReBarCtrl.](../../mfc/reference/crebarctrl-class.md)

### <a name="remarks"></a>Comentários

Ligue para esta função de membro para aproveitar a funcionalidade do controle comum do Windows na personalização do vergalhão. Quando você `GetReBarCtrl`chama, ele retorna `CReBarCtrl` um objeto de referência para o objeto para que você possa usar qualquer conjunto de funções de membro.

Para obter mais `CReBarCtrl` informações sobre como usar o vergalhão, consulte [Usando CReBarCtrl](../../mfc/using-crebarctrl.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#2](../../mfc/reference/codesnippet/cpp/crebar-class_2.cpp)]

## <a name="see-also"></a>Confira também

[MFC Amostra MFCIE](../../overview/visual-cpp-samples.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
