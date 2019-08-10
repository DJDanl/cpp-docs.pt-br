---
title: Classe CReBarCtrl
ms.date: 11/19/2018
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
ms.openlocfilehash: 102c06879ffaedb91f20a4b5085a10015d7a4c8b
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68916862"
---
# <a name="crebarctrl-class"></a>Classe CReBarCtrl

Encapsula a funcionalidade de um controle rebar, que é um contêiner para uma janela filho.

## <a name="syntax"></a>Sintaxe

```
class CReBarCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CReBarCtrl::CReBarCtrl](#crebarctrl)|Constrói um objeto `CReBarCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CReBarCtrl::BeginDrag](#begindrag)|Coloca o controle rebar no modo arrastar e soltar.|
|[CReBarCtrl::Create](#create)|Cria o controle rebar e o `CReBarCtrl` anexa ao objeto.|
|[CReBarCtrl::CreateEx](#createex)|Cria um controle rebar com os estilos estendidos do Windows especificados e os anexa a `CReBarCtrl` um objeto.|
|[CReBarCtrl::DeleteBand](#deleteband)|Exclui uma faixa de um controle rebar.|
|[CReBarCtrl::DragMove](#dragmove)|Atualiza a posição de arrastar no controle rebar após uma chamada para `BeginDrag`.|
|[CReBarCtrl::EndDrag](#enddrag)|Encerra a operação de arrastar e soltar do controle rebar.|
|[CReBarCtrl::GetBandBorders](#getbandborders)|Recupera as bordas de uma banda.|
|[CReBarCtrl::GetBandCount](#getbandcount)|Recupera a contagem de faixas atualmente no controle rebar.|
|[CReBarCtrl::GetBandInfo](#getbandinfo)|Recupera informações sobre uma faixa especificada em um controle rebar.|
|[CReBarCtrl::GetBandMargins](#getbandmargins)|Recupera as margens de uma banda.|
|[CReBarCtrl::GetBarHeight](#getbarheight)|Recupera a altura do controle rebar.|
|[CReBarCtrl::GetBarInfo](#getbarinfo)|Recupera informações sobre o controle rebar e a lista de imagens que ele usa.|
|[CReBarCtrl::GetBkColor](#getbkcolor)|Recupera a cor do plano de fundo padrão de um controle rebar.|
|[CReBarCtrl::GetColorScheme](#getcolorscheme)|Recupera a estrutura [ColorScheme](/windows/desktop/api/commctrl/ns-commctrl-tagcolorscheme) associada ao controle rebar.|
|[CReBarCtrl::GetDropTarget](#getdroptarget)|Recupera o ponteiro de interface `IDropTarget` de um controle rebar.|
|[CReBarCtrl::GetExtendedStyle](#getextendedstyle)|Obtém o estilo estendido do controle rebar atual.|
|[CReBarCtrl::GetImageList](#getimagelist)|Recupera a lista de imagens associada a um controle rebar.|
|[CReBarCtrl::GetPalette](#getpalette)|Recupera a paleta atual do controle rebar.|
|[CReBarCtrl::GetRect](#getrect)|Recupera o retângulo delimitador para uma determinada faixa em um controle rebar.|
|[CReBarCtrl::GetRowCount](#getrowcount)|Recupera o número de linhas de banda em um controle rebar.|
|[CReBarCtrl::GetRowHeight](#getrowheight)|Recupera a altura de uma linha especificada em um controle rebar.|
|[CReBarCtrl::GetTextColor](#gettextcolor)|Recupera a cor de texto padrão de um controle rebar.|
|[CReBarCtrl::GetToolTips](#gettooltips)|Recupera o identificador para qualquer controle de dica de ferramenta associado ao controle rebar.|
|[CReBarCtrl::HitTest](#hittest)|Determina qual parte de uma banda de rebar está em um determinado ponto na tela, se existir uma banda de rebar nesse ponto.|
|[CReBarCtrl::IDToIndex](#idtoindex)|Converte um identificador de faixa (ID) em um índice de faixa em um controle rebar.|
|[CReBarCtrl::InsertBand](#insertband)|Insere uma nova faixa em um controle rebar.|
|[CReBarCtrl::MaximizeBand](#maximizeband)|Redimensiona uma faixa em um controle rebar para seu tamanho maior.|
|[CReBarCtrl::MinimizeBand](#minimizeband)|Redimensiona uma faixa em um controle rebar para seu menor tamanho.|
|[CReBarCtrl::MoveBand](#moveband)|Move uma banda de um índice para outro.|
|[CReBarCtrl::PushChevron](#pushchevron)|Envia programaticamente uma divisa.|
|[CReBarCtrl::RestoreBand](#restoreband)|Redimensiona uma faixa em um controle rebar para seu tamanho ideal.|
|[CReBarCtrl::SetBandInfo](#setbandinfo)|Define características de uma banda existente em um controle rebar.|
|[CReBarCtrl::SetBandWidth](#setbandwidth)|Define a largura da banda encaixada especificada no controle rebar atual.|
|[CReBarCtrl::SetBarInfo](#setbarinfo)|Define as características de um controle rebar.|
|[CReBarCtrl::SetBkColor](#setbkcolor)|Define a cor do plano de fundo padrão de um controle rebar.|
|[CReBarCtrl::SetColorScheme](#setcolorscheme)|Define o esquema de cores para os botões em um controle rebar.|
|[CReBarCtrl::SetExtendedStyle](#setextendedstyle)|Define os estilos estendidos para o controle rebar atual.|
|[CReBarCtrl::SetImageList](#setimagelist)|Define a lista de imagens de um controle rebar.|
|[CReBarCtrl::SetOwner](#setowner)|Define a janela do proprietário de um controle rebar.|
|[CReBarCtrl::SetPalette](#setpalette)|Define a paleta atual do controle rebar.|
|[CReBarCtrl::SetTextColor](#settextcolor)|Define a cor de texto padrão de um controle rebar.|
|[CReBarCtrl::SetToolTips](#settooltips)|Associa um controle de dica de ferramenta ao controle rebar.|
|[CReBarCtrl::SetWindowTheme](#setwindowtheme)|Define o estilo visual do controle rebar.|
|[CReBarCtrl::ShowBand](#showband)|Mostra ou oculta uma determinada faixa em um controle rebar.|
|[CReBarCtrl::SizeToRect](#sizetorect)|Ajusta um controle rebar para um retângulo especificado.|

## <a name="remarks"></a>Comentários

O aplicativo no qual o controle rebar reside atribui a janela filho contida no controle rebar à faixa Rebar. A janela filho geralmente é outro controle comum.

Os controles Rebar contêm uma ou mais faixas. Cada banda pode conter uma combinação de uma barra de garra, um bitmap, um rótulo de texto e uma janela filho. A banda pode conter apenas um de cada um desses itens.

O controle rebar pode exibir a janela filho sobre um bitmap em segundo plano especificado. Todas as bandas de controle rebar podem ser redimensionadas, exceto aquelas que usam o estilo RBBS_FIXEDSIZE. À medida que você reposiciona ou redimensiona uma faixa de controle rebar, o controle rebar gerencia o tamanho e a posição da janela filho atribuída a essa banda. Para redimensionar ou alterar a ordem das faixas dentro do controle, clique e arraste a barra de garra de uma faixa.

A ilustração a seguir mostra um controle rebar que tem três faixas:

- A faixa 0 contém um controle de barra de ferramentas simples e transparente.

- A faixa 1 contém os botões suspensos padrão Transparent e Transparent.

- A faixa 2 contém uma caixa de combinação e quatro botões padrão.

   ![Exemplo de um menu de rebar](../../mfc/reference/media/vc4scc1.gif "Exemplo de um menu de rebar")

## <a name="rebar-control"></a>Controle rebar

Suporte a controles Rebar:

- Listas de imagens.

- Manipulação de mensagens.

- Funcionalidade de desenho Personalizada.

- Uma variedade de estilos de controle além dos estilos de janela padrão. Para obter uma lista desses estilos, consulte [estilos de controle rebar](/windows/desktop/Controls/rebar-control-styles) no SDK do Windows.

Para obter mais informações, consulte [usando CReBarCtrl](../../mfc/using-crebarctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CReBarCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="begindrag"></a>  CReBarCtrl::BeginDrag

Implementa o comportamento da mensagem [RB_BEGINDRAG](/windows/desktop/Controls/rb-begindrag)do Win32, conforme descrito na SDK do Windows.

```
void BeginDrag(
    UINT uBand,
    DWORD dwPos = (DWORD)-1);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero da banda que a operação de arrastar e soltar afetará.

*dwPos*<br/>
Um valor DWORD que contém as coordenadas de início do mouse. A coordenada horizontal está contida no LOWORD e a coordenada vertical está contida no HIWORD. Se você passar (DWORD)-1, o controle Rebar usará a posição do mouse na última vez em que o thread do controle `GetMessage` for `PeekMessage`chamado ou.

##  <a name="create"></a>  CReBarCtrl::Create

Cria o controle rebar e o `CReBarCtrl` anexa ao objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica a combinação de estilos de controle rebar aplicados ao controle. Consulte [estilos de controle rebar](/windows/desktop/Controls/rebar-control-styles) no SDK do Windows para obter uma lista de estilos com suporte.

*rect*<br/>
Uma referência a uma estrutura de objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou [Rect](/previous-versions/dd162897\(v=vs.85\)) , que é a posição e o tamanho do controle rebar.

*pParentWnd*<br/>
Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle rebar. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID de controle do controle rebar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto foi criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Crie um controle rebar em duas etapas:

1. Chame [CReBarCtrl](#crebarctrl) para construir um `CReBarCtrl` objeto.

1. Chame essa função de membro, que cria o controle rebar do Windows e o `CReBarCtrl` anexa ao objeto.

Quando você chama `Create`, os controles comuns são inicializados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#3](../../mfc/reference/codesnippet/cpp/crebarctrl-class_1.cpp)]

##  <a name="createex"></a>  CReBarCtrl::CreateEx

Cria um controle (uma janela filho) e o `CReBarCtrl` associa ao objeto.

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
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) no SDK do Windows.

*dwStyle*<br/>
Especifica a combinação de estilos de controle rebar aplicados ao controle. Para obter uma lista de estilos com suporte, consulte [estilos de controle rebar](/windows/desktop/Controls/rebar-control-styles) no SDK do Windows.

*rect*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que descreve o tamanho e a posição da janela a ser criada, nas coordenadas de cliente de *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A ID da janela filho do controle.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo estilo estendido do Windows **WS_EX_** do prefácio.

##  <a name="crebarctrl"></a>  CReBarCtrl::CReBarCtrl

Cria um objeto `CReBarCtrl`.

```
CReBarCtrl();
```

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CReBarCtrl:: Create](#create).

##  <a name="deleteband"></a>  CReBarCtrl::DeleteBand

Implementa o comportamento da mensagem [RB_DELETEBAND](/windows/desktop/Controls/rb-deleteband)do Win32, conforme descrito na SDK do Windows.

```
BOOL DeleteBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero da banda a ser excluída.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a faixa foi excluída com êxito; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#4](../../mfc/reference/codesnippet/cpp/crebarctrl-class_2.cpp)]

##  <a name="dragmove"></a>  CReBarCtrl::DragMove

Implementa o comportamento da mensagem [RB_DRAGMOVE](/windows/desktop/Controls/rb-dragmove)do Win32, conforme descrito na SDK do Windows.

```
void DragMove(DWORD dwPos = (DWORD)-1);
```

### <a name="parameters"></a>Parâmetros

*dwPos*<br/>
Um valor DWORD que contém as novas coordenadas do mouse. A coordenada horizontal está contida no LOWORD e a coordenada vertical está contida no HIWORD. Se você passar (DWORD)-1, o controle Rebar usará a posição do mouse na última vez em que o thread do controle `GetMessage` for `PeekMessage`chamado ou.

##  <a name="enddrag"></a>  CReBarCtrl::EndDrag

Implementa o comportamento da mensagem [RB_ENDDRAG](/windows/desktop/Controls/rb-enddrag)do Win32, conforme descrito na SDK do Windows.

```
void EndDrag();
```

##  <a name="getbandborders"></a>  CReBarCtrl::GetBandBorders

Implementa o comportamento da mensagem [RB_GETBANDBORDERS](/windows/desktop/Controls/rb-getbandborders)do Win32, conforme descrito na SDK do Windows.

```
void GetBandBorders(
    UINT uBand,
    LPRECT prc) const;
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero da banda para a qual as bordas serão recuperadas.

*prc*<br/>
Um ponteiro para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que receberá as bordas da faixa. Se o controle rebar tiver o estilo RBS_BANDBORDERS, cada membro dessa estrutura receberá o número de pixels, no lado correspondente da faixa, que constitui a borda. Se o controle rebar não tiver o estilo RBS_BANDBORDERS, somente o membro à esquerda dessa estrutura receberá informações válidas. Para obter uma descrição dos estilos de controle rebar, consulte [estilos de controle rebar](/windows/desktop/Controls/rebar-control-styles) no SDK do Windows.

##  <a name="getbandcount"></a>  CReBarCtrl::GetBandCount

Implementa o comportamento da mensagem [RB_GETBANDCOUNT](/windows/desktop/Controls/rb-getbandcount)do Win32, conforme descrito na SDK do Windows.

```
UINT GetBandCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de faixas atribuídas ao controle.

##  <a name="getbandinfo"></a>  CReBarCtrl::GetBandInfo

Implementa o comportamento da mensagem Win32 [RB_GETBANDINFO](/windows/desktop/Controls/rb-getbandinfo) conforme descrito no SDK do Windows.

```
BOOL GetBandInfo(
    UINT uBand,
    REBARBANDINFO* prbbi) const;
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero da banda para a qual as informações serão recuperadas.

*prbbi*<br/>
Um ponteiro para uma estrutura [REBARBANDINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarbandinfoa) para receber as informações de banda. Você deve definir o `cbSize` membro dessa estrutura como `sizeof(REBARBANDINFO)` e definir o `fMask` membro para os itens que deseja recuperar antes de enviar essa mensagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

##  <a name="getbandmargins"></a>  CReBarCtrl::GetBandMargins

Recupera as margens da banda.

```
void GetBandMargins(PMARGINS pMargins);
```

### <a name="parameters"></a>Parâmetros

*pMargins*<br/>
Um ponteiro para uma estrutura de [margens](/windows/desktop/api/uxtheme/ns-uxtheme-margins)que receberá as informações.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da mensagem [RB_GETBANDMARGINS](/windows/desktop/Controls/rb-getbandmargins) , conforme descrito na SDK do Windows.

##  <a name="getbarheight"></a>  CReBarCtrl::GetBarHeight

Recupera a altura da barra de rebar.

```
UINT GetBarHeight() const;
```

### <a name="return-value"></a>Valor de retorno

Valor que representa a altura, em pixels, do controle.

##  <a name="getbarinfo"></a>  CReBarCtrl::GetBarInfo

Implementa o comportamento da mensagem [RB_GETBARINFO](/windows/desktop/Controls/rb-getbarinfo)do Win32, conforme descrito na SDK do Windows.

```
BOOL GetBarInfo(REBARINFO* prbi) const;
```

### <a name="parameters"></a>Parâmetros

*prbi*<br/>
Um ponteiro para uma estrutura [REBARINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarinfo) que receberá as informações de controle rebar. Você deve definir o membro *cbSize* dessa estrutura como antes `sizeof(REBARINFO)` de enviar esta mensagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

##  <a name="getbkcolor"></a>  CReBarCtrl::GetBkColor

Implementa o comportamento da mensagem [RB_GETBKCOLOR](/windows/desktop/Controls/rb-getbkcolor)do Win32, conforme descrito na SDK do Windows.

```
COLORREF GetBkColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor COLORREF que representa a cor de plano de fundo padrão atual.

##  <a name="getcolorscheme"></a>  CReBarCtrl::GetColorScheme

Recupera a estrutura [ColorScheme](/windows/desktop/api/commctrl/ns-commctrl-tagcolorscheme) para o controle rebar.

```
BOOL GetColorScheme(COLORSCHEME* lpcs);
```

### <a name="parameters"></a>Parâmetros

*lpcs*<br/>
Um ponteiro para uma estrutura [ColorScheme](/windows/desktop/api/commctrl/ns-commctrl-tagcolorscheme) , conforme descrito na SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

A `COLORSCHEME` estrutura inclui a cor de realce do botão e a cor da sombra do botão.

##  <a name="getdroptarget"></a>  CReBarCtrl::GetDropTarget

Implementa o comportamento da mensagem [RB_GETDROPTARGET](/windows/desktop/Controls/rb-getdroptarget)do Win32, conforme descrito na SDK do Windows.

```
IDropTarget* GetDropTarget() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para uma interface [IDropTarget](/windows/desktop/api/oleidl/nn-oleidl-idroptarget) .

##  <a name="getextendedstyle"></a>  CReBarCtrl::GetExtendedStyle

Obtém os estilos estendidos do controle rebar atual.

```
DWORD GetExtendedStyle() const;
```

### <a name="return-value"></a>Valor de retorno

Uma combinação de bits (ou) de sinalizadores que indica os estilos estendidos. Os possíveis sinalizadores são RBS_EX_SPLITTER e RBS_EX_TRANSPARENT. Para obter mais informações, consulte o parâmetro *dwMask* do método [CReBarCtrl::](#setextendedstyle) Extended.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [RB_GETEXTENDEDSTYLE](/windows/desktop/Controls/rb-dragmove) , que é descrita na SDK do Windows.

##  <a name="getimagelist"></a>  CReBarCtrl::GetImageList

Obtém o `CImageList` objeto associado a um controle rebar.

```
CImageList* GetImageList() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) . Retornará NULL se nenhuma lista de imagens for definida para o controle.

### <a name="remarks"></a>Comentários

Essa função de membro usa informações de tamanho e máscara armazenadas na estrutura [REBARINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarinfo) , conforme descrito na SDK do Windows.

##  <a name="getpalette"></a>  CReBarCtrl::GetPalette

Recupera a paleta atual do controle rebar.

```
CPalette* GetPalette() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CPalette](../../mfc/reference/cpalette-class.md) que especifica a paleta atual do controle rebar.

### <a name="remarks"></a>Comentários

Observe que essa função de membro usa `CPalette` um objeto como seu valor de retorno, em vez de um HPALETTE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#5](../../mfc/reference/codesnippet/cpp/crebarctrl-class_3.cpp)]

##  <a name="getrect"></a>  CReBarCtrl::GetRect

Implementa o comportamento da mensagem [RB_GETRECT](/windows/desktop/Controls/rb-getrect)do Win32, conforme descrito na SDK do Windows.

```
BOOL GetRect(
    UINT uBand,
    LPRECT prc) const;
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero de uma banda no controle rebar.

*prc*<br/>
Um ponteiro para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que receberá os limites da faixa Rebar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#6](../../mfc/reference/codesnippet/cpp/crebarctrl-class_4.cpp)]

##  <a name="getrowcount"></a>  CReBarCtrl::GetRowCount

Implementa o comportamento da mensagem [RB_GETROWCOUNT](/windows/desktop/Controls/rb-getrowcount)do Win32, conforme descrito na SDK do Windows.

```
UINT GetRowCount() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor UINT que representa o número de linhas de banda no controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#7](../../mfc/reference/codesnippet/cpp/crebarctrl-class_5.cpp)]

##  <a name="getrowheight"></a>  CReBarCtrl::GetRowHeight

Implementa o comportamento da mensagem [RB_GETROWHEIGHT](/windows/desktop/Controls/rb-getrowheight)do Win32, conforme descrito na SDK do Windows.

```
UINT GetRowHeight(UINT uRow) const;
```

### <a name="parameters"></a>Parâmetros

*uRow*<br/>
Índice de base zero da banda que terá sua altura recuperada.

### <a name="return-value"></a>Valor de retorno

Um valor UINT que representa a altura da linha, em pixels.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#8](../../mfc/reference/codesnippet/cpp/crebarctrl-class_6.cpp)]

##  <a name="gettextcolor"></a>  CReBarCtrl::GetTextColor

Implementa o comportamento da mensagem [RB_GETTEXTCOLOR](/windows/desktop/Controls/rb-gettextcolor)do Win32, conforme descrito na SDK do Windows.

```
COLORREF GetTextColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de COLORREF que representa a cor de texto padrão atual.

##  <a name="gettooltips"></a>  CReBarCtrl::GetToolTips

Implementa o comportamento da mensagem [RB_GETTOOLTIPS](/windows/desktop/Controls/rb-gettooltips)do Win32, conforme descrito na SDK do Windows.

```
CToolTipCtrl* GetToolTips() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) .

### <a name="remarks"></a>Comentários

Observe que a implementação do MFC `GetToolTips` de retorna um ponteiro para `CToolTipCtrl`um, em vez de um HWND.

##  <a name="hittest"></a>  CReBarCtrl::HitTest

Implementa o comportamento da mensagem [RB_HITTEST](/windows/desktop/Controls/rb-hittest)do Win32, conforme descrito na SDK do Windows.

```
int HitTest(RBHITTESTINFO* prbht);
```

### <a name="parameters"></a>Parâmetros

*prbht*<br/>
Um ponteiro para uma estrutura [RBHITTESTINFO](/windows/desktop/api/commctrl/ns-commctrl-_rb_hittestinfo) . Antes de enviar a mensagem, `pt` o membro dessa estrutura deve ser inicializado até o ponto que será testado, em coordenadas do cliente.

### <a name="return-value"></a>Valor de retorno

O índice de base zero da banda no ponto determinado, ou-1 se nenhuma banda do rebar estava no ponto.

##  <a name="idtoindex"></a>  CReBarCtrl::IDToIndex

Implementa o comportamento da mensagem [RB_IDTOINDEX](/windows/desktop/controls/rb-idtoindex)do Win32, conforme descrito na SDK do Windows.

```
int IDToIndex(UINT uBandID) const;
```

### <a name="parameters"></a>Parâmetros

*uBandID*<br/>
O identificador definido pelo aplicativo da banda especificada, passado no `wID` membro da estrutura [REBARBANDINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarbandinfoa) quando a banda é inserida.

### <a name="return-value"></a>Valor de retorno

O índice de faixa com base em zero se for bem-sucedido ou-1 caso contrário. Se existirem índices de banda duplicados, o primeiro será retornado.

##  <a name="insertband"></a>  CReBarCtrl::InsertBand

Implementa o comportamento da mensagem [RB_INSERTBAND](/windows/desktop/Controls/rb-insertband)do Win32, conforme descrito na SDK do Windows.

```
BOOL InsertBand(
    UINT uIndex,
    REBARBANDINFO* prbbi);
```

### <a name="parameters"></a>Parâmetros

*uIndex*<br/>
Índice de base zero do local onde a banda será inserida. Se você definir esse parâmetro como-1, o controle adicionará a nova banda no último local.

*prbbi*<br/>
Um ponteiro para uma estrutura [REBARBANDINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarbandinfoa) que define a banda a ser inserida. Você deve definir o membro *cbSize* dessa estrutura como antes `sizeof(REBARBANDINFO)` de chamar essa função.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#9](../../mfc/reference/codesnippet/cpp/crebarctrl-class_7.cpp)]

##  <a name="maximizeband"></a>  CReBarCtrl::MaximizeBand

Redimensiona uma faixa em um controle rebar para seu tamanho maior.

```
void MaximizeBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero da banda a ser maximizado.

### <a name="remarks"></a>Comentários

Implementa o comportamento da mensagem Win32 [RB_MAXIMIZEBAND](/windows/desktop/Controls/rb-maximizeband) com `fIdeal` definido como 0, conforme descrito na SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#10](../../mfc/reference/codesnippet/cpp/crebarctrl-class_8.cpp)]

##  <a name="minimizeband"></a>  CReBarCtrl::MinimizeBand

Redimensiona uma faixa em um controle rebar para seu menor tamanho.

```
void MinimizeBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero da banda a ser minimizada.

### <a name="remarks"></a>Comentários

Implementa o comportamento da mensagem [RB_MINIMIZEBAND](/windows/desktop/Controls/rb-minimizeband)do Win32, conforme descrito na SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#11](../../mfc/reference/codesnippet/cpp/crebarctrl-class_9.cpp)]

##  <a name="moveband"></a>  CReBarCtrl::MoveBand

Implementa o comportamento da mensagem [RB_MOVEBAND](/windows/desktop/Controls/rb-moveband)do Win32, conforme descrito na SDK do Windows.

```
BOOL MoveBand(
    UINT uFrom,
    UINT uTo);
```

### <a name="parameters"></a>Parâmetros

*uFrom*<br/>
Índice de base zero da banda a ser movida.

*uTo*<br/>
Índice de base zero da nova posição de banda. Esse valor de parâmetro nunca deve ser maior que o número de faixas menos um. Para obter o número de bandas, chame [GetBandCount](#getbandcount).

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

##  <a name="pushchevron"></a>  CReBarCtrl::PushChevron

Implementa o comportamento da mensagem [RB_PUSHCHEVRON](/windows/desktop/Controls/rb-pushchevron)do Win32, conforme descrito na SDK do Windows.

```
void PushChevron(
    UINT uBand,
    LPARAM lAppValue);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero da faixa cuja divisa deve ser enviada por push.

*lAppValue*<br/>
Um valor de 32 bits definido pelo aplicativo. Consulte *lAppValue* em [RB_PUSHCHEVRON](/windows/desktop/Controls/rb-pushchevron) na SDK do Windows.

##  <a name="restoreband"></a>  CReBarCtrl::RestoreBand

Redimensiona uma faixa em um controle rebar para seu tamanho ideal.

```
void RestoreBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero da banda a ser maximizado.

### <a name="remarks"></a>Comentários

Implementa o comportamento da mensagem Win32 [RB_MAXIMIZEBAND](/windows/desktop/Controls/rb-maximizeband) com `fIdeal` definido como 1, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#12](../../mfc/reference/codesnippet/cpp/crebarctrl-class_10.cpp)]

##  <a name="setbandinfo"></a>  CReBarCtrl::SetBandInfo

Implementa o comportamento da mensagem [RB_SETBANDINFO](/windows/desktop/Controls/rb-setbandinfo)do Win32, conforme descrito na SDK do Windows.

```
BOOL SetBandInfo(
    UINT uBand,
    REBARBANDINFO* prbbi);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero da banda para receber as novas configurações.

*prbbi*<br/>
Ponteiro para uma estrutura [REBARBANDINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarbandinfoa) que define a banda a ser inserida. Você deve definir o `cbSize` membro desta estrutura como antes `sizeof(REBARBANDINFO)` de enviar esta mensagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

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
|*uBand*|no Índice de base zero de uma faixa Rebar.|
|*cxWidth*|no Nova largura da faixa Rebar, em pixels.|

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [RB_SETBANDWIDTH](/windows/desktop/Controls/rb-setbandwidth) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a `m_rebar`variável,, que é usada para acessar o controle rebar atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CReBarCtrl_s1#1](../../mfc/reference/codesnippet/cpp/crebarctrl-class_12.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define que cada banda de rebar tenha a mesma largura.

[!code-cpp[NVC_MFC_CReBarCtrl_s1#2](../../mfc/reference/codesnippet/cpp/crebarctrl-class_13.cpp)]

##  <a name="setbarinfo"></a>  CReBarCtrl::SetBarInfo

Implementa o comportamento da mensagem [RB_SETBARINFO](/windows/desktop/Controls/rb-setbarinfo)do Win32, conforme descrito na SDK do Windows.

```
BOOL SetBarInfo(REBARINFO* prbi);
```

### <a name="parameters"></a>Parâmetros

*prbi*<br/>
Um ponteiro para uma estrutura [REBARINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarinfo) que contém as informações a serem definidas. Você deve definir o `cbSize` membro desta estrutura como antes `sizeof(REBARINFO)` de enviar esta mensagem

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#14](../../mfc/reference/codesnippet/cpp/crebarctrl-class_14.cpp)]

##  <a name="setbkcolor"></a>  CReBarCtrl::SetBkColor

Implementa o comportamento da mensagem [RB_SETBKCOLOR](/windows/desktop/Controls/rb-setbkcolor)do Win32, conforme descrito na SDK do Windows.

```
COLORREF SetBkColor(COLORREF clr);
```

### <a name="parameters"></a>Parâmetros

*clr*<br/>
O valor COLORREF que representa a nova cor de plano de fundo padrão.

### <a name="return-value"></a>Valor de retorno

Um valor [COLORREF](/windows/desktop/gdi/colorref) que representa a cor do plano de fundo padrão anterior.

### <a name="remarks"></a>Comentários

Consulte este tópico para obter mais informações sobre quando definir a cor do plano de fundo e como definir o padrão.

##  <a name="setcolorscheme"></a>  CReBarCtrl::SetColorScheme

Define o esquema de cores para os botões em um controle rebar.

```
void SetColorScheme(const COLORSCHEME* lpcs);
```

### <a name="parameters"></a>Parâmetros

*lpcs*<br/>
Um ponteiro para uma estrutura [ColorScheme](/windows/desktop/api/commctrl/ns-commctrl-tagcolorscheme) , conforme descrito na SDK do Windows.

### <a name="remarks"></a>Comentários

A `COLORSCHEME` estrutura inclui a cor de realce do botão e a cor da sombra do botão.

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
|*dwMask*|no Uma combinação de bits (ou) de sinalizadores que especifica quais sinalizadores no parâmetro *dwStyleEx* se aplicam. Use um ou mais dos seguintes valores:<br /><br /> RBS_EX_SPLITTER: Por padrão, mostre o divisor na parte inferior no modo horizontal e à direita no modo vertical.<br /><br /> RBS_EX_TRANSPARENT: Encaminhe a mensagem [WM_ERASEBKGND](/windows/desktop/winmsg/wm-erasebkgnd) para a janela pai.|
|*dwStyleEx*|no Uma combinação de bits (ou) de sinalizadores que especifica os estilos a serem aplicados. Para definir um estilo, especifique o mesmo sinalizador que é usado no parâmetro *dwMask* . Para redefinir um estilo, especifique zero Binary.|

### <a name="return-value"></a>Valor de retorno

O estilo estendido anterior.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [RB_SETEXTENDEDSTYLE](/windows/desktop/Controls/rb-setextendedstyle) , que é descrita na SDK do Windows.

##  <a name="setimagelist"></a>  CReBarCtrl::SetImageList

Atribui uma lista de imagens a um controle rebar.

```
BOOL SetImageList(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*pImageList*<br/>
Um ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) que contém a lista de imagens a ser atribuída ao controle rebar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

##  <a name="setowner"></a>  CReBarCtrl::SetOwner

Implementa o comportamento da mensagem [RB_SETPARENT](/windows/desktop/Controls/rb-setparent)do Win32, conforme descrito na SDK do Windows.

```
CWnd* SetOwner(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para um `CWnd` objeto a ser definido como o proprietário do controle rebar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é o proprietário atual do controle rebar.

### <a name="remarks"></a>Comentários

Observe que essa função de membro usa ponteiros para `CWnd` objetos para o proprietário atual e selecionado do controle rebar, em vez de identificadores para o Windows.

> [!NOTE]
>  Essa função de membro não altera o pai real que foi definido quando o controle foi criado; em vez disso, ele envia mensagens de notificação para a janela que você especificar.

##  <a name="setpalette"></a>  CReBarCtrl::SetPalette

Implementa o comportamento da mensagem [RB_SETPALETTE](/windows/desktop/Controls/rb-setpalette)do Win32, conforme descrito na SDK do Windows.

```
CPalette* SetPalette(HPALETTE hPal);
```

### <a name="parameters"></a>Parâmetros

*hPal*<br/>
Um HPALETTE que especifica a nova paleta que será usada pelo controle rebar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CPalette](../../mfc/reference/cpalette-class.md) especificando a paleta anterior do controle rebar.

### <a name="remarks"></a>Comentários

Observe que essa função de membro usa `CPalette` um objeto como seu valor de retorno, em vez de um HPALETTE.

##  <a name="settextcolor"></a>  CReBarCtrl::SetTextColor

Implementa o comportamento da mensagem [RB_SETTEXTCOLOR](/windows/desktop/Controls/rb-settextcolor)do Win32, conforme descrito na SDK do Windows.

```
COLORREF SetTextColor(COLORREF clr);
```

### <a name="parameters"></a>Parâmetros

*clr*<br/>
Um valor COLORREF que representa a nova cor do texto no `CReBarCtrl` objeto.

### <a name="return-value"></a>Valor de retorno

O valor [COLORREF](/windows/desktop/gdi/colorref) que representa a cor do texto anterior associada `CReBarCtrl` ao objeto.

### <a name="remarks"></a>Comentários

Ele é fornecido para dar suporte à flexibilidade de cores de texto em um controle rebar.

##  <a name="settooltips"></a>  CReBarCtrl::SetToolTips

Associa um controle de dica de ferramenta a um controle rebar.

```
void SetToolTips(CToolTipCtrl* pToolTip);
```

### <a name="parameters"></a>Parâmetros

*pToolTip*<br/>
Um ponteiro para um objeto [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md)

### <a name="remarks"></a>Comentários

Você deve destruir o `CToolTipCtrl` objeto quando terminar.

##  <a name="setwindowtheme"></a>  CReBarCtrl::SetWindowTheme

Define o estilo visual do controle rebar.

```
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

### <a name="parameters"></a>Parâmetros

*pszSubAppName*<br/>
Um ponteiro para uma cadeia de caracteres Unicode que contém o estilo visual rebar a ser definido.

### <a name="return-value"></a>Valor de retorno

O valor de retorno não é usado.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da mensagem [RB_SETWINDOWTHEME](/windows/desktop/Controls/rb-setwindowtheme) , conforme descrito na SDK do Windows.

##  <a name="showband"></a>  CReBarCtrl::ShowBand

Implementa o comportamento da mensagem [RB_SHOWBAND](/windows/desktop/Controls/rb-showband)do Win32, conforme descrito na SDK do Windows.

```
BOOL ShowBand(
    UINT uBand,
    BOOL fShow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice de base zero de uma banda no controle rebar.

*fShow*<br/>
Indica se a banda deve ser mostrada ou ocultada. Se esse valor for TRUE, a banda será mostrada. Caso contrário, a banda ficará oculta.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

##  <a name="sizetorect"></a>  CReBarCtrl::SizeToRect

Implementa o comportamento da mensagem [RB_SIZETORECT](/windows/desktop/Controls/rb-sizetorect)do Win32, conforme descrito na SDK do Windows.

```
BOOL SizeToRect(CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Uma referência a um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que especifica o retângulo ao qual o controle rebar deve ser dimensionado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Observe que essa função de membro usa `CRect` um objeto como parâmetro, em vez de `RECT` uma estrutura.

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
