---
title: Classe CReBarCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CReBarCtrl
- AFXCMN/CReBarCtrl
- AFXCMN/CReBarCtrl::CReBarCtrl
- AFXCMN/CReBarCtrl::BeginDrag
- AFXCMN/CReBarCtrl::Create
- AFXCMN/CReBarCtrl::CreateEx
- AFXCMN/CReBarCtrl::DeleteBand
- AFXCMN/CReBarCtrl::DragMove
- AFXCMN/CReBarCtrl::EndDrag
- AFXCMN/CReBarCtrl::GetBandBorders
- AFXCMN/CReBarCtrl::GetBandCount
- AFXCMN/CReBarCtrl::GetBandInfo
- AFXCMN/CReBarCtrl::GetBandMargins
- AFXCMN/CReBarCtrl::GetBarHeight
- AFXCMN/CReBarCtrl::GetBarInfo
- AFXCMN/CReBarCtrl::GetBkColor
- AFXCMN/CReBarCtrl::GetColorScheme
- AFXCMN/CReBarCtrl::GetDropTarget
- AFXCMN/CReBarCtrl::GetExtendedStyle
- AFXCMN/CReBarCtrl::GetImageList
- AFXCMN/CReBarCtrl::GetPalette
- AFXCMN/CReBarCtrl::GetRect
- AFXCMN/CReBarCtrl::GetRowCount
- AFXCMN/CReBarCtrl::GetRowHeight
- AFXCMN/CReBarCtrl::GetTextColor
- AFXCMN/CReBarCtrl::GetToolTips
- AFXCMN/CReBarCtrl::HitTest
- AFXCMN/CReBarCtrl::IDToIndex
- AFXCMN/CReBarCtrl::InsertBand
- AFXCMN/CReBarCtrl::MaximizeBand
- AFXCMN/CReBarCtrl::MinimizeBand
- AFXCMN/CReBarCtrl::MoveBand
- AFXCMN/CReBarCtrl::PushChevron
- AFXCMN/CReBarCtrl::RestoreBand
- AFXCMN/CReBarCtrl::SetBandInfo
- AFXCMN/CReBarCtrl::SetBandWidth
- AFXCMN/CReBarCtrl::SetBarInfo
- AFXCMN/CReBarCtrl::SetBkColor
- AFXCMN/CReBarCtrl::SetColorScheme
- AFXCMN/CReBarCtrl::SetExtendedStyle
- AFXCMN/CReBarCtrl::SetImageList
- AFXCMN/CReBarCtrl::SetOwner
- AFXCMN/CReBarCtrl::SetPalette
- AFXCMN/CReBarCtrl::SetTextColor
- AFXCMN/CReBarCtrl::SetToolTips
- AFXCMN/CReBarCtrl::SetWindowTheme
- AFXCMN/CReBarCtrl::ShowBand
- AFXCMN/CReBarCtrl::SizeToRect
dev_langs:
- C++
helpviewer_keywords:
- CReBarCtrl [MFC], CReBarCtrl
- CReBarCtrl [MFC], BeginDrag
- CReBarCtrl [MFC], Create
- CReBarCtrl [MFC], CreateEx
- CReBarCtrl [MFC], DeleteBand
- CReBarCtrl [MFC], DragMove
- CReBarCtrl [MFC], EndDrag
- CReBarCtrl [MFC], GetBandBorders
- CReBarCtrl [MFC], GetBandCount
- CReBarCtrl [MFC], GetBandInfo
- CReBarCtrl [MFC], GetBandMargins
- CReBarCtrl [MFC], GetBarHeight
- CReBarCtrl [MFC], GetBarInfo
- CReBarCtrl [MFC], GetBkColor
- CReBarCtrl [MFC], GetColorScheme
- CReBarCtrl [MFC], GetDropTarget
- CReBarCtrl [MFC], GetExtendedStyle
- CReBarCtrl [MFC], GetImageList
- CReBarCtrl [MFC], GetPalette
- CReBarCtrl [MFC], GetRect
- CReBarCtrl [MFC], GetRowCount
- CReBarCtrl [MFC], GetRowHeight
- CReBarCtrl [MFC], GetTextColor
- CReBarCtrl [MFC], GetToolTips
- CReBarCtrl [MFC], HitTest
- CReBarCtrl [MFC], IDToIndex
- CReBarCtrl [MFC], InsertBand
- CReBarCtrl [MFC], MaximizeBand
- CReBarCtrl [MFC], MinimizeBand
- CReBarCtrl [MFC], MoveBand
- CReBarCtrl [MFC], PushChevron
- CReBarCtrl [MFC], RestoreBand
- CReBarCtrl [MFC], SetBandInfo
- CReBarCtrl [MFC], SetBandWidth
- CReBarCtrl [MFC], SetBarInfo
- CReBarCtrl [MFC], SetBkColor
- CReBarCtrl [MFC], SetColorScheme
- CReBarCtrl [MFC], SetExtendedStyle
- CReBarCtrl [MFC], SetImageList
- CReBarCtrl [MFC], SetOwner
- CReBarCtrl [MFC], SetPalette
- CReBarCtrl [MFC], SetTextColor
- CReBarCtrl [MFC], SetToolTips
- CReBarCtrl [MFC], SetWindowTheme
- CReBarCtrl [MFC], ShowBand
- CReBarCtrl [MFC], SizeToRect
ms.assetid: 154570d7-e48c-425d-8c7e-c64542bcb4cc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b68f0180a581898b552715ccda4bfd0e972facd8
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46376747"
---
# <a name="crebarctrl-class"></a>Classe CReBarCtrl

Encapsula a funcionalidade de um controle rebar, que é um contêiner para uma janela filho.

## <a name="syntax"></a>Sintaxe

```
class CReBarCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CReBarCtrl::CReBarCtrl](#crebarctrl)|Constrói um objeto `CReBarCtrl`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CReBarCtrl::BeginDrag](#begindrag)|Coloca o controle rebar no modo de arrastar e soltar.|
|[CReBarCtrl::Create](#create)|Cria um controle rebar e anexa-o para o `CReBarCtrl` objeto.|
|[CReBarCtrl::CreateEx](#createex)|Cria um controle rebar com os estilos estendidos do Windows especificados e anexa-o para um `CReBarCtrl` objeto.|
|[CReBarCtrl::DeleteBand](#deleteband)|Exclui uma faixa de um controle rebar.|
|[CReBarCtrl::DragMove](#dragmove)|Atualiza a posição de arrastar no controle rebar após uma chamada para `BeginDrag`.|
|[CReBarCtrl::EndDrag](#enddrag)|Encerra a operação de arrastar e soltar do controle rebar.|
|[CReBarCtrl::GetBandBorders](#getbandborders)|Recupera as bordas de uma faixa.|
|[CReBarCtrl::GetBandCount](#getbandcount)|Recupera a contagem de faixas no momento no controle rebar.|
|[CReBarCtrl::GetBandInfo](#getbandinfo)|Recupera informações sobre uma faixa especificada em um controle rebar.|
|[CReBarCtrl::GetBandMargins](#getbandmargins)|Recupera as margens de uma faixa.|
|[CReBarCtrl::GetBarHeight](#getbarheight)|Recupera a altura do controle rebar.|
|[CReBarCtrl::GetBarInfo](#getbarinfo)|Recupera informações sobre o controle rebar e a lista de imagens que ele usa.|
|[CReBarCtrl::GetBkColor](#getbkcolor)|Recupera a cor de plano de fundo padrão do controle rebar.|
|[CReBarCtrl::GetColorScheme](#getcolorscheme)|Recupera o [COLORSCHEME](/windows/desktop/api/commctrl/ns-commctrl-tagcolorscheme) estrutura associada ao controle rebar.|
|[CReBarCtrl::GetDropTarget](#getdroptarget)|Recupera um controle rebar `IDropTarget` ponteiro de interface.|
|[CReBarCtrl::GetExtendedStyle](#getextendedstyle)|Obtém o estilo estendido do controle rebar atual.|
|[CReBarCtrl::GetImageList](#getimagelist)|Recupera a lista de imagens associada com um controle rebar.|
|[CReBarCtrl::GetPalette](#getpalette)|Recupera a paleta de atual do controle rebar.|
|[CReBarCtrl::GetRect](#getrect)|Recupera o retângulo delimitador para uma determinada faixa em um controle rebar.|
|[CReBarCtrl::GetRowCount](#getrowcount)|Recupera o número de linhas de banda em um controle rebar.|
|[CReBarCtrl::GetRowHeight](#getrowheight)|Recupera a altura de uma linha especificada em um controle rebar.|
|[CReBarCtrl::GetTextColor](#gettextcolor)|Recupera a cor do texto padrão do controle rebar.|
|[CReBarCtrl::GetToolTips](#gettooltips)|Recupera o identificador para qualquer controle de dica de ferramenta associado ao controle rebar.|
|[CReBarCtrl::HitTest](#hittest)|Determina qual parte de uma faixa de rebar está em um determinado ponto na tela, se uma faixa de rebar existir nesse ponto.|
|[CReBarCtrl::IDToIndex](#idtoindex)|Converte um identificador (ID) de banda em um índice de banda em um controle rebar.|
|[CReBarCtrl::InsertBand](#insertband)|Insere uma nova faixa em um controle rebar.|
|[CReBarCtrl::MaximizeBand](#maximizeband)|Redimensiona uma faixa em um controle rebar ao seu tamanho máximo.|
|[CReBarCtrl::MinimizeBand](#minimizeband)|Redimensiona uma faixa em um controle rebar ao seu tamanho menor.|
|[CReBarCtrl::MoveBand](#moveband)|Move uma faixa de um índice para outra.|
|[CReBarCtrl::PushChevron](#pushchevron)|Envia por push uma divisa de forma programática.|
|[CReBarCtrl::RestoreBand](#restoreband)|Redimensiona uma faixa em um controle rebar ao seu tamanho ideal.|
|[CReBarCtrl::SetBandInfo](#setbandinfo)|Define as características de uma banda existente em um controle rebar.|
|[CReBarCtrl::SetBandWidth](#setbandwidth)|Define a largura da banda encaixada especificada no controle rebar atual.|
|[CReBarCtrl::SetBarInfo](#setbarinfo)|Define as características de um controle rebar.|
|[CReBarCtrl::SetBkColor](#setbkcolor)|Define a cor de plano de fundo padrão do controle rebar.|
|[CReBarCtrl::SetColorScheme](#setcolorscheme)|Define o esquema de cores para os botões em um controle rebar.|
|[CReBarCtrl::SetExtendedStyle](#setextendedstyle)|Define os estilos estendidos para o controle rebar atual.|
|[CReBarCtrl::SetImageList](#setimagelist)|Define a lista de imagens do controle rebar.|
|[CReBarCtrl::SetOwner](#setowner)|Define a janela do proprietário do controle rebar.|
|[CReBarCtrl::SetPalette](#setpalette)|Define a paleta de atual do controle rebar.|
|[CReBarCtrl::SetTextColor](#settextcolor)|Define a cor do texto padrão do controle rebar.|
|[CReBarCtrl::SetToolTips](#settooltips)|Associa um controle de dica de ferramenta com o controle rebar.|
|[CReBarCtrl::SetWindowTheme](#setwindowtheme)|Define o estilo visual do controle rebar.|
|[CReBarCtrl::ShowBand](#showband)|Mostra ou oculta uma determinada faixa em um controle rebar.|
|[CReBarCtrl::SizeToRect](#sizetorect)|Se encaixa em um controle rebar a um retângulo especificado.|

## <a name="remarks"></a>Comentários

O aplicativo no qual reside o controle rebar atribui a janela filho contida no controle rebar para a faixa de rebar. A janela filho é geralmente outro controle comum.

Controles rebar contêm um ou mais faixas. Cada faixa pode conter uma combinação de uma barra de garra, um bitmap, um rótulo de texto e uma janela filho. A faixa pode conter apenas um de cada um desses itens.

O controle rebar pode exibir a janela filho ao longo de um bitmap da tela de fundo especificada. Todas as faixas de controle rebar podem ser redimensionadas, exceto aqueles que usam o estilo RBBS_FIXEDSIZE. Como você reposiciona ou redimensiona uma faixa de controle rebar, o controle rebar gerencia o tamanho e posição da janela filho atribuída a essa faixa. Para redimensionar ou alterar a ordem das bandas no controle, clique e arraste a barra de garra da banda.

A ilustração a seguir mostra um controle rebar que tem três faixas:

- Banda 0 contém um controle de barra de ferramentas simples e transparente.

- Faixa 1 contém os dois botões de lista suspensa transparente de padrão e transparente.

- Banda 2 contém uma caixa de combinação e quatro botões padrão.

     ![Exemplo de um menu de Rebar](../../mfc/reference/media/vc4scc1.gif "vc4scc1")

## <a name="rebar-control"></a>Controle rebar

Suporte a controles de rebar:

- Listas de imagens.

- Manipulação de mensagens.

- Funcionalidade de desenho personalizado.

- Uma variedade de estilos de controle além os estilos de janela padrão. Para obter uma lista desses estilos, consulte [estilos de controle Rebar](/windows/desktop/Controls/rebar-control-styles) no SDK do Windows.

Para obter mais informações, consulte [usando CReBarCtrl](../../mfc/using-crebarctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CReBarCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="begindrag"></a>  CReBarCtrl::BeginDrag

Implementa o comportamento da mensagem do Win32 [RB_BEGINDRAG](/windows/desktop/Controls/rb-begindrag), conforme descrito no SDK do Windows.

```
void BeginDrag(
    UINT uBand,
    DWORD dwPos = (DWORD)-1);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da faixa que afeta a operação de arrastar e soltar.

*dwPos*<br/>
Um valor DWORD que contém o início do mouse em coordenadas. A coordenada horizontal está contida no LOWORD e a coordenada vertical está contida no HIWORD. Se você passar (DWORD) -1, o controle rebar usará a posição do mouse na última vez o thread do controle chamado `GetMessage` ou `PeekMessage`.

##  <a name="create"></a>  CReBarCtrl::Create

Cria um controle rebar e anexa-o para o `CReBarCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica a combinação de estilos de controle rebar aplicado ao controle. Ver [estilos de controle Rebar](/windows/desktop/Controls/rebar-control-styles) no SDK do Windows para obter uma lista de estilos com suporte.

*Rect*<br/>
Uma referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura, que é a posição e o tamanho do controle rebar.

*pParentWnd*<br/>
Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle rebar. Ele não deve ser NULL.

*nID*<br/>
Especifica a ID do controle. do controle rebar

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto foi criado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Crie um controle rebar em duas etapas:

1. Chame [CReBarCtrl](#crebarctrl) para construir um `CReBarCtrl` objeto.

1. Chame essa função de membro, que cria um controle rebar Windows e anexa-o para o `CReBarCtrl` objeto.

Quando você chama `Create`, os controles comuns são inicializados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#3](../../mfc/reference/codesnippet/cpp/crebarctrl-class_1.cpp)]

##  <a name="createex"></a>  CReBarCtrl::CreateEx

Cria um controle (uma janela filho) e o associa a `CReBarCtrl` objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwExStyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o *dwExStyle* parâmetro para [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) no SDK do Windows.

*dwStyle*<br/>
Especifica a combinação de estilos de controle rebar aplicado ao controle. Para obter uma lista de estilos com suporte, consulte [estilos de controle Rebar](/windows/desktop/Controls/rebar-control-styles) no SDK do Windows.

*Rect*<br/>
Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e posição da janela a ser criado, em coordenadas do cliente do *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
ID da janela filho. do controle

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

##  <a name="crebarctrl"></a>  CReBarCtrl::CReBarCtrl

Cria um objeto `CReBarCtrl`.

```
CReBarCtrl();
```

### <a name="example"></a>Exemplo

  Veja o exemplo de [CReBarCtrl::Create](#create).

##  <a name="deleteband"></a>  CReBarCtrl::DeleteBand

Implementa o comportamento da mensagem do Win32 [RB_DELETEBAND](/windows/desktop/Controls/rb-deleteband), conforme descrito no SDK do Windows.

```
BOOL DeleteBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da faixa a ser excluído.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a banda foi excluída com êxito; Caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#4](../../mfc/reference/codesnippet/cpp/crebarctrl-class_2.cpp)]

##  <a name="dragmove"></a>  CReBarCtrl::DragMove

Implementa o comportamento da mensagem do Win32 [RB_DRAGMOVE](/windows/desktop/Controls/rb-dragmove), conforme descrito no SDK do Windows.

```
void DragMove(DWORD dwPos = (DWORD)-1);
```

### <a name="parameters"></a>Parâmetros

*dwPos*<br/>
Um valor DWORD que contém as novas coordenadas do mouse. A coordenada horizontal está contida no LOWORD e a coordenada vertical está contida no HIWORD. Se você passar (DWORD) -1, o controle rebar usará a posição do mouse na última vez o thread do controle chamado `GetMessage` ou `PeekMessage`.

##  <a name="enddrag"></a>  CReBarCtrl::EndDrag

Implementa o comportamento da mensagem do Win32 [RB_ENDDRAG](/windows/desktop/Controls/rb-enddrag), conforme descrito no SDK do Windows.

```
void EndDrag();
```

##  <a name="getbandborders"></a>  CReBarCtrl::GetBandBorders

Implementa o comportamento da mensagem do Win32 [RB_GETBANDBORDERS](/windows/desktop/Controls/rb-getbandborders), conforme descrito no SDK do Windows.

```
void GetBandBorders(
    UINT uBand,
    LPRECT prc) const;
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da faixa para que as bordas serão recuperadas.

*República Popular da China*<br/>
Um ponteiro para um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que receberá as bordas de banda. Se o controle rebar tem o estilo RBS_BANDBORDERS, cada membro desta estrutura receberá o número de pixels, do lado correspondente de banda, que constituem a borda. Se o controle rebar não tem o estilo RBS_BANDBORDERS, somente o membro à esquerda desta estrutura recebe informações válidas. Para obter uma descrição dos estilos de controle rebar, consulte [estilos de controle Rebar](/windows/desktop/Controls/rebar-control-styles) no SDK do Windows.

##  <a name="getbandcount"></a>  CReBarCtrl::GetBandCount

Implementa o comportamento da mensagem do Win32 [RB_GETBANDCOUNT](/windows/desktop/Controls/rb-getbandcount), conforme descrito no SDK do Windows.

```
UINT GetBandCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de faixas atribuído ao controle.

##  <a name="getbandinfo"></a>  CReBarCtrl::GetBandInfo

Implementa o comportamento da mensagem do Win32 [RB_GETBANDINFO](/windows/desktop/Controls/rb-getbandinfo) conforme descrito no SDK do Windows.

```
BOOL GetBandInfo(
    UINT uBand,
    REBARBANDINFO* prbbi) const;
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da faixa para a qual as informações serão recuperadas.

*prbbi*<br/>
Um ponteiro para um [REBARBANDINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarbandinfoa) estrutura para receber as informações de banda. Você deve definir a `cbSize` membro dessa estrutura para `sizeof(REBARBANDINFO)` e defina o `fMask` membro para os itens que você deseja recuperar antes de enviar esta mensagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

##  <a name="getbandmargins"></a>  CReBarCtrl::GetBandMargins

Recupera as margens da faixa.

```
void GetBandMargins(PMARGINS pMargins);
```

### <a name="parameters"></a>Parâmetros

*pMargins*<br/>
Um ponteiro para um [MARGENS](/windows/desktop/api/uxtheme/ns-uxtheme-_margins)estrutura que receberá as informações.

### <a name="remarks"></a>Comentários

Essa função membro emula a funcionalidade dos [RB_GETBANDMARGINS](/windows/desktop/Controls/rb-getbandmargins) da mensagem, conforme descrito no SDK do Windows.

##  <a name="getbarheight"></a>  CReBarCtrl::GetBarHeight

Recupera a altura da barra de rebar.

```
UINT GetBarHeight() const;
```

### <a name="return-value"></a>Valor de retorno

Valor que representa a altura, em pixels, do controle.

##  <a name="getbarinfo"></a>  CReBarCtrl::GetBarInfo

Implementa o comportamento da mensagem do Win32 [RB_GETBARINFO](/windows/desktop/Controls/rb-getbarinfo), conforme descrito no SDK do Windows.

```
BOOL GetBarInfo(REBARINFO* prbi) const;
```

### <a name="parameters"></a>Parâmetros

*prbi*<br/>
Um ponteiro para um [REBARINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarinfo) estrutura que receberá as informações de controle rebar. Você deve definir a *cbSize* membro dessa estrutura para `sizeof(REBARINFO)` antes de enviar esta mensagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

##  <a name="getbkcolor"></a>  CReBarCtrl::GetBkColor

Implementa o comportamento da mensagem do Win32 [RB_GETBKCOLOR](/windows/desktop/Controls/rb-getbkcolor), conforme descrito no SDK do Windows.

```
COLORREF GetBkColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor COLORREF que representam a cor de plano de fundo padrão atual.

##  <a name="getcolorscheme"></a>  CReBarCtrl::GetColorScheme

Recupera o [COLORSCHEME](/windows/desktop/api/commctrl/ns-commctrl-tagcolorscheme) estrutura para o controle rebar.

```
BOOL GetColorScheme(COLORSCHEME* lpcs);
```

### <a name="parameters"></a>Parâmetros

*denominado LPC*<br/>
Um ponteiro para um [COLORSCHEME](/windows/desktop/api/commctrl/ns-commctrl-tagcolorscheme) estrutura, conforme descrito no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

### <a name="remarks"></a>Comentários

O `COLORSCHEME` estrutura inclui a cor de realce do botão e a cor de sombra do botão.

##  <a name="getdroptarget"></a>  CReBarCtrl::GetDropTarget

Implementa o comportamento da mensagem do Win32 [RB_GETDROPTARGET](/windows/desktop/Controls/rb-getdroptarget), conforme descrito no SDK do Windows.

```
IDropTarget* GetDropTarget() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [IDropTarget](/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface.

##  <a name="getextendedstyle"></a>  CReBarCtrl::GetExtendedStyle

Obtém os estilos estendidos do controle rebar atual.

```
DWORD GetExtendedStyle() const;
```

### <a name="return-value"></a>Valor de retorno

Uma combinação bit a bit (OR) de sinalizadores que indicam os estilos estendidos. Os possíveis sinalizadores são RBS_EX_SPLITTER e RBS_EX_TRANSPARENT. Para obter mais informações, consulte o *dwMask* parâmetro do [CReBarCtrl::SetExtendedStyle](#setextendedstyle) método.

### <a name="remarks"></a>Comentários

Esse método envia o [RB_GETEXTENDEDSTYLE](/windows/desktop/Controls/rb-dragmove) mensagem, que é descrita no SDK do Windows.

##  <a name="getimagelist"></a>  CReBarCtrl::GetImageList

Obtém o `CImageList` objeto associado a um controle rebar.

```
CImageList* GetImageList() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto. Retorna NULL se nenhuma lista de imagens é definida para o controle.

### <a name="remarks"></a>Comentários

Essa função membro usa o tamanho e a máscara de informações armazenadas em do [REBARINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarinfo) estrutura, conforme descrito no SDK do Windows.

##  <a name="getpalette"></a>  CReBarCtrl::GetPalette

Recupera a paleta de atual do controle rebar.

```
CPalette* GetPalette() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CPalette](../../mfc/reference/cpalette-class.md) objeto que especifica a paleta de atual do controle rebar.

### <a name="remarks"></a>Comentários

Observe que essa função membro usa uma `CPalette` objeto como seu valor de retorno, em vez de um HPALETTE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#5](../../mfc/reference/codesnippet/cpp/crebarctrl-class_3.cpp)]

##  <a name="getrect"></a>  CReBarCtrl::GetRect

Implementa o comportamento da mensagem do Win32 [RB_GETRECT](/windows/desktop/Controls/rb-getrect), conforme descrito no SDK do Windows.

```
BOOL GetRect(
    UINT uBand,
    LPRECT prc) const;
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero de uma faixa em um controle rebar.

*República Popular da China*<br/>
Um ponteiro para um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que receberá os limites da faixa de rebar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#6](../../mfc/reference/codesnippet/cpp/crebarctrl-class_4.cpp)]

##  <a name="getrowcount"></a>  CReBarCtrl::GetRowCount

Implementa o comportamento da mensagem do Win32 [RB_GETROWCOUNT](/windows/desktop/Controls/rb-getrowcount), conforme descrito no SDK do Windows.

```
UINT GetRowCount() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor UINT que representa o número de linhas de banda no controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#7](../../mfc/reference/codesnippet/cpp/crebarctrl-class_5.cpp)]

##  <a name="getrowheight"></a>  CReBarCtrl::GetRowHeight

Implementa o comportamento da mensagem do Win32 [RB_GETROWHEIGHT](/windows/desktop/Controls/rb-getrowheight), conforme descrito no SDK do Windows.

```
UINT GetRowHeight(UINT uRow) const;
```

### <a name="parameters"></a>Parâmetros

*uRow*<br/>
Índice baseado em zero da faixa que terá sua altura recuperada.

### <a name="return-value"></a>Valor de retorno

Um valor UINT que representa a altura da linha, em pixels.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#8](../../mfc/reference/codesnippet/cpp/crebarctrl-class_6.cpp)]

##  <a name="gettextcolor"></a>  CReBarCtrl::GetTextColor

Implementa o comportamento da mensagem do Win32 [RB_GETTEXTCOLOR](/windows/desktop/Controls/rb-gettextcolor), conforme descrito no SDK do Windows.

```
COLORREF GetTextColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor COLORREF que representam a cor do texto padrão atual.

##  <a name="gettooltips"></a>  CReBarCtrl::GetToolTips

Implementa o comportamento da mensagem do Win32 [RB_GETTOOLTIPS](/windows/desktop/Controls/rb-gettooltips), conforme descrito no SDK do Windows.

```
CToolTipCtrl* GetToolTips() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) objeto.

### <a name="remarks"></a>Comentários

Observe que a implementação MFC `GetToolTips` retorna um ponteiro para um `CToolTipCtrl`, em vez de um HWND.

##  <a name="hittest"></a>  CReBarCtrl::HitTest

Implementa o comportamento da mensagem do Win32 [RB_HITTEST](/windows/desktop/Controls/rb-hittest), conforme descrito no SDK do Windows.

```
int HitTest(RBHITTESTINFO* prbht);
```

### <a name="parameters"></a>Parâmetros

*prbht*<br/>
Um ponteiro para um [RBHITTESTINFO](/windows/desktop/api/commctrl/ns-commctrl-_rb_hittestinfo) estrutura. Antes de enviar a mensagem, o `pt` membro dessa estrutura deve ser inicializado para o ponto que será testado, nas coordenadas do cliente.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero da faixa em determinado ponto, ou -1 se nenhuma faixa de rebar foi o momento.

##  <a name="idtoindex"></a>  CReBarCtrl::IDToIndex

Implementa o comportamento da mensagem do Win32 [RB_IDTOINDEX](https://msdn.microsoft.com/library/windows/desktop/bb774496), conforme descrito no SDK do Windows.

```
int IDToIndex(UINT uBandID) const;
```

### <a name="parameters"></a>Parâmetros

*uBandID*<br/>
O identificador da faixa especificada, definido pelo aplicativo passado a `wID` membro a [REBARBANDINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarbandinfoa) estrutura quando a faixa é inserida.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero de banda se for bem-sucedido ou -1 caso contrário. Se existem índices duplicados de banda, o primeiro deles será retornado.

##  <a name="insertband"></a>  CReBarCtrl::InsertBand

Implementa o comportamento da mensagem do Win32 [RB_INSERTBAND](/windows/desktop/Controls/rb-insertband), conforme descrito no SDK do Windows.

```
BOOL InsertBand(
    UINT uIndex,
    REBARBANDINFO* prbbi);
```

### <a name="parameters"></a>Parâmetros

*uIndex*<br/>
Índice baseado em zero do local em que a faixa será inserida. Se você definir esse parâmetro como -1, o controle será adicionar a nova faixa no último local.

*prbbi*<br/>
Um ponteiro para um [REBARBANDINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarbandinfoa) estrutura que define a faixa a ser inserido. Você deve definir a *cbSize* membro dessa estrutura para `sizeof(REBARBANDINFO)` antes de chamar essa função.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#9](../../mfc/reference/codesnippet/cpp/crebarctrl-class_7.cpp)]

##  <a name="maximizeband"></a>  CReBarCtrl::MaximizeBand

Redimensiona uma faixa em um controle rebar ao seu tamanho máximo.

```
void MaximizeBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da faixa para ser maximizada.

### <a name="remarks"></a>Comentários

Implementa o comportamento da mensagem do Win32 [RB_MAXIMIZEBAND](/windows/desktop/Controls/rb-maximizeband) com `fIdeal` definido como 0, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#10](../../mfc/reference/codesnippet/cpp/crebarctrl-class_8.cpp)]

##  <a name="minimizeband"></a>  CReBarCtrl::MinimizeBand

Redimensiona uma faixa em um controle rebar ao seu tamanho menor.

```
void MinimizeBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da faixa a ser minimizada.

### <a name="remarks"></a>Comentários

Implementa o comportamento da mensagem do Win32 [RB_MINIMIZEBAND](/windows/desktop/Controls/rb-minimizeband), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#11](../../mfc/reference/codesnippet/cpp/crebarctrl-class_9.cpp)]

##  <a name="moveband"></a>  CReBarCtrl::MoveBand

Implementa o comportamento da mensagem do Win32 [RB_MOVEBAND](/windows/desktop/Controls/rb-moveband), conforme descrito no SDK do Windows.

```
BOOL MoveBand(
    UINT uFrom,
    UINT uTo);
```

### <a name="parameters"></a>Parâmetros

*uFrom*<br/>
Índice baseado em zero da faixa a ser movido.

*ultar automaticamente*<br/>
Índice baseado em zero da nova posição de banda. Esse valor de parâmetro nunca deve ser maior que o número de faixas menos um. Para obter o número de faixas, chame [GetBandCount](#getbandcount).

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

##  <a name="pushchevron"></a>  CReBarCtrl::PushChevron

Implementa o comportamento da mensagem do Win32 [RB_PUSHCHEVRON](/windows/desktop/Controls/rb-pushchevron), conforme descrito no SDK do Windows.

```
void PushChevron(
    UINT uBand,
    LPARAM lAppValue);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da faixa cuja divisa deve ser enviados.

*lAppValue*<br/>
Um aplicativo definido pelo valor de 32 bits. Ver *lAppValue* na [RB_PUSHCHEVRON](/windows/desktop/Controls/rb-pushchevron) no SDK do Windows.

##  <a name="restoreband"></a>  CReBarCtrl::RestoreBand

Redimensiona uma faixa em um controle rebar ao seu tamanho ideal.

```
void RestoreBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da faixa para ser maximizada.

### <a name="remarks"></a>Comentários

Implementa o comportamento da mensagem do Win32 [RB_MAXIMIZEBAND](/windows/desktop/Controls/rb-maximizeband) com `fIdeal` definido como 1, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#12](../../mfc/reference/codesnippet/cpp/crebarctrl-class_10.cpp)]

##  <a name="setbandinfo"></a>  CReBarCtrl::SetBandInfo

Implementa o comportamento da mensagem do Win32 [RB_SETBANDINFO](/windows/desktop/Controls/rb-setbandinfo), conforme descrito no SDK do Windows.

```
BOOL SetBandInfo(
    UINT uBand,
    REBARBANDINFO* prbbi);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da faixa para receber as novas configurações.

*prbbi*<br/>
Ponteiro para um [REBARBANDINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarbandinfoa) estrutura que define a faixa a ser inserido. Você deve definir a `cbSize` membro dessa estrutura para `sizeof(REBARBANDINFO)` antes de enviar esta mensagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#13](../../mfc/reference/codesnippet/cpp/crebarctrl-class_11.cpp)]

##  <a name="setbandwidth"></a>  CReBarCtrl::SetBandWidth

Define a largura da banda encaixada especificada no controle rebar atual.

```
BOOL SetBandWidth(
    UINT uBand,
    int cxWidth);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*uBand*|[in] Índice baseado em zero de uma faixa de rebar.|
|*cxWidth*|[in] Nova largura da faixa de rebar, em pixels.|

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia o [RB_SETBANDWIDTH](/windows/desktop/Controls/rb-setbandwidth) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_rebar`, que é usado para acessar o controle rebar atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CReBarCtrl_s1#1](../../mfc/reference/codesnippet/cpp/crebarctrl-class_12.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define cada faixa de rebar tenha a mesma largura.

[!code-cpp[NVC_MFC_CReBarCtrl_s1#2](../../mfc/reference/codesnippet/cpp/crebarctrl-class_13.cpp)]

##  <a name="setbarinfo"></a>  CReBarCtrl::SetBarInfo

Implementa o comportamento da mensagem do Win32 [RB_SETBARINFO](/windows/desktop/Controls/rb-setbarinfo), conforme descrito no SDK do Windows.

```
BOOL SetBarInfo(REBARINFO* prbi);
```

### <a name="parameters"></a>Parâmetros

*prbi*<br/>
Um ponteiro para um [REBARINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarinfo) estrutura que contém as informações a ser definido. Você deve definir a `cbSize` membro dessa estrutura para `sizeof(REBARINFO)` antes de enviar esta mensagem

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#14](../../mfc/reference/codesnippet/cpp/crebarctrl-class_14.cpp)]

##  <a name="setbkcolor"></a>  CReBarCtrl::SetBkColor

Implementa o comportamento da mensagem do Win32 [RB_SETBKCOLOR](/windows/desktop/Controls/rb-setbkcolor), conforme descrito no SDK do Windows.

```
COLORREF SetBkColor(COLORREF clr);
```

### <a name="parameters"></a>Parâmetros

*CLR*<br/>
O valor COLORREF que representa a nova cor de plano de fundo padrão.

### <a name="return-value"></a>Valor de retorno

Um [COLORREF](/windows/desktop/gdi/colorref) valor que representa a cor de plano de fundo padrão anterior.

### <a name="remarks"></a>Comentários

Consulte este tópico para obter mais informações sobre quando definir a cor do plano de fundo e como definir o padrão.

##  <a name="setcolorscheme"></a>  CReBarCtrl::SetColorScheme

Define o esquema de cores para os botões em um controle rebar.

```
void SetColorScheme(const COLORSCHEME* lpcs);
```

### <a name="parameters"></a>Parâmetros

*denominado LPC*<br/>
Um ponteiro para um [COLORSCHEME](/windows/desktop/api/commctrl/ns-commctrl-tagcolorscheme) estrutura, conforme descrito no SDK do Windows.

### <a name="remarks"></a>Comentários

O `COLORSCHEME` estrutura inclui a cor de realce do botão e a cor de sombra do botão.

##  <a name="setextendedstyle"></a>  CReBarCtrl::SetExtendedStyle

Define os estilos estendidos para o controle rebar atual.

```
DWORD SetExtendedStyle(
    DWORD dwMask,
    DWORD dwStyleEx);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*dwMask*|[in] Uma combinação bit a bit (OR) de sinalizadores que especificam quais sinalizadores na *dwStyleEx* parâmetro se aplica. Use um ou mais dos seguintes valores:<br /><br /> RBS_EX_SPLITTER: Por padrão, mostra o separador na parte inferior no modo horizontal e à direita no modo vertical.<br /><br /> RBS_EX_TRANSPARENT: Encaminhar o [WM_ERASEBKGND](/windows/desktop/winmsg/wm-erasebkgnd) mensagem para a janela pai.|
|*dwStyleEx*|[in] Uma combinação bit a bit (OR) de sinalizadores que especificam os estilos a ser aplicado. Para definir um estilo, especifique o mesmo sinalizador é usado na *dwMask* parâmetro. Para redefinir um estilo, especifique zero binário.|

### <a name="return-value"></a>Valor de retorno

O estilo estendido anterior.

### <a name="remarks"></a>Comentários

Esse método envia o [RB_SETEXTENDEDSTYLE](/windows/desktop/Controls/rb-setextendedstyle) mensagem, que é descrita no SDK do Windows.

##  <a name="setimagelist"></a>  CReBarCtrl::SetImageList

Atribui uma lista de imagens para um controle rebar.

```
BOOL SetImageList(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*pImageList*<br/>
Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto que contém a lista de imagens a ser atribuído ao controle rebar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

##  <a name="setowner"></a>  CReBarCtrl::SetOwner

Implementa o comportamento da mensagem do Win32 [RB_SETPARENT](/windows/desktop/Controls/rb-setparent), conforme descrito no SDK do Windows.

```
CWnd* SetOwner(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Apropriei*<br/>
Um ponteiro para um `CWnd` objeto a ser definido como o proprietário do controle rebar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é o proprietário atual do controle rebar.

### <a name="remarks"></a>Comentários

Observe que essa função membro usa ponteiros para `CWnd` objetos para o proprietário atual e selecionado do controle rebar, em vez de identificadores para windows.

> [!NOTE]
>  Essa função de membro não altera o pai real que foi definido quando o controle foi criado; em vez disso, ele envia mensagens de notificação para a janela que você especificar.

##  <a name="setpalette"></a>  CReBarCtrl::SetPalette

Implementa o comportamento da mensagem do Win32 [RB_SETPALETTE](/windows/desktop/Controls/rb-setpalette), conforme descrito no SDK do Windows.

```
CPalette* SetPalette(HPALETTE hPal);
```

### <a name="parameters"></a>Parâmetros

*hPal*<br/>
Um HPALETTE que especifica a nova paleta que irá usar o controle rebar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CPalette](../../mfc/reference/cpalette-class.md) objeto que especifica a paleta de anterior do controle rebar.

### <a name="remarks"></a>Comentários

Observe que essa função membro usa uma `CPalette` objeto como seu valor de retorno, em vez de um HPALETTE.

##  <a name="settextcolor"></a>  CReBarCtrl::SetTextColor

Implementa o comportamento da mensagem do Win32 [RB_SETTEXTCOLOR](/windows/desktop/Controls/rb-settextcolor), conforme descrito no SDK do Windows.

```
COLORREF SetTextColor(COLORREF clr);
```

### <a name="parameters"></a>Parâmetros

*CLR*<br/>
Um valor COLORREF que representa o novo texto cor no `CReBarCtrl` objeto.

### <a name="return-value"></a>Valor de retorno

O [COLORREF](/windows/desktop/gdi/colorref) valor que representa a cor do texto anterior associado a `CReBarCtrl` objeto.

### <a name="remarks"></a>Comentários

Ele é fornecido para dar suporte a flexibilidade de cor do texto em um controle rebar.

##  <a name="settooltips"></a>  CReBarCtrl::SetToolTips

Associa um controle de dica de ferramenta com um controle rebar.

```
void SetToolTips(CToolTipCtrl* pToolTip);
```

### <a name="parameters"></a>Parâmetros

*pToolTip*<br/>
Um ponteiro para um [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) objeto

### <a name="remarks"></a>Comentários

Você deve destruir a `CToolTipCtrl` objeto quando você terminar com ele.

##  <a name="setwindowtheme"></a>  CReBarCtrl::SetWindowTheme

Define o estilo visual do controle rebar.

```
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

### <a name="parameters"></a>Parâmetros

*pszSubAppName*<br/>
Um ponteiro para uma cadeia de caracteres Unicode que contém o estilo visual de rebar definir.

### <a name="return-value"></a>Valor de retorno

O valor de retorno não é usado.

### <a name="remarks"></a>Comentários

Essa função membro emula a funcionalidade dos [RB_SETWINDOWTHEME](/windows/desktop/Controls/rb-setwindowtheme) da mensagem, conforme descrito no SDK do Windows.

##  <a name="showband"></a>  CReBarCtrl::ShowBand

Implementa o comportamento da mensagem do Win32 [RB_SHOWBAND](/windows/desktop/Controls/rb-showband), conforme descrito no SDK do Windows.

```
BOOL ShowBand(
    UINT uBand,
    BOOL fShow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero de uma faixa em um controle rebar.

*fShow*<br/>
Indica se a banda deve ser mostrada ou ocultada. Se esse valor for TRUE, a faixa será exibida. Caso contrário, a banda ficará oculta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

##  <a name="sizetorect"></a>  CReBarCtrl::SizeToRect

Implementa o comportamento da mensagem do Win32 [RB_SIZETORECT](/windows/desktop/Controls/rb-sizetorect), conforme descrito no SDK do Windows.

```
BOOL SizeToRect(CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Uma referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica o retângulo que controle rebar deve ser dimensionado para.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

### <a name="remarks"></a>Comentários

Observe que essa função membro usa uma `CRect` objeto como um parâmetro, em vez de um `RECT` estrutura.

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)


