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
ms.openlocfilehash: 776892d71e2cb0f5d57512754cd7fa12730eb044
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367439"
---
# <a name="crebarctrl-class"></a>Classe CReBarCtrl

Encapsula a funcionalidade de um controle de vergalhões, que é um recipiente para uma janela infantil.

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
|[CReBarCtrl::BeginDrag](#begindrag)|Coloca o controle do vergalhão no modo de arrastar e soltar.|
|[CReBarCtrl::Criar](#create)|Cria o controle do vergalhão e o prende ao `CReBarCtrl` objeto.|
|[CReBarCtrl::CreateEx](#createex)|Cria um controle de vergalhões com os estilos `CReBarCtrl` estendidos do Windows especificados e o anexa a um objeto.|
|[CReBarCtrl::DeleteBand](#deleteband)|Exclui uma banda de um controle de vergalhões.|
|[CReBarCtrl::DragMove](#dragmove)|Atualiza a posição de arrastar no controle `BeginDrag`do vergalhão após uma chamada para .|
|[CReBarCtrl::EndDrag](#enddrag)|Encerra a operação de arrastar e soltar do controle de vergalhões.|
|[CReBarCtrl::GetBandBorders](#getbandborders)|Recupera as fronteiras de uma banda.|
|[CReBarCtrl::GetBandCount](#getbandcount)|Recupera a contagem de bandas atualmente no controle do vergalhão.|
|[CReBarCtrl::GetBandInfo](#getbandinfo)|Recupera informações sobre uma banda especificada em um controle de vergalhões.|
|[CReBarCtrl::GetBandMargins](#getbandmargins)|Recupera as margens de uma banda.|
|[CReBarCtrl::GetBarHeight](#getbarheight)|Recupera a altura do controle do vergalhão.|
|[CReBarCtrl::GetBarInfo](#getbarinfo)|Recupera informações sobre o controle do vergalhão e a lista de imagens que ele usa.|
|[CReBarCtrl::GetBkColor](#getbkcolor)|Recupera a cor de fundo padrão do controle de vergalhões.|
|[CReBarCtrl::GetColorScheme](#getcolorscheme)|Recupera a estrutura [COLORSCHEME](/windows/win32/api/commctrl/ns-commctrl-colorscheme) associada ao controle do vergalhão.|
|[CReBarCtrl::GetDropTarget](#getdroptarget)|Recupera o ponteiro de `IDropTarget` interface do controle de vergalhões.|
|[CReBarCtrl::GetExtendedStyle](#getextendedstyle)|Obtém o estilo estendido do controle de vergalhões atual.|
|[CReBarCtrl::GetImageList](#getimagelist)|Recupera a lista de imagens associada a um controle de vergalhões.|
|[CReBarCtrl::GetPalette](#getpalette)|Recupera a paleta atual do controle do vergalhão.|
|[CReBarCtrl::GetRect](#getrect)|Recupera o retângulo delimitador para uma determinada banda em um controle de vergalhões.|
|[CReBarCtrl::GetRowCount](#getrowcount)|Recupera o número de linhas de banda em um controle de vergalhões.|
|[CReBarCtrl::GetRowHeight](#getrowheight)|Recupera a altura de uma linha especificada em um controle de vergalhões.|
|[CReBarCtrl::GetTextColor](#gettextcolor)|Recupera a cor de texto padrão do controle de vergalhões.|
|[CReBarCtrl::GetToolTips](#gettooltips)|Recupera a pega para qualquer controle de ponta de ferramenta associado ao controle do vergalhão.|
|[CReBarCtrl::HitTest](#hittest)|Determina qual parte de uma banda de vergalhões está em um dado ponto na tela, se uma faixa de vergalhões existe nesse ponto.|
|[CReBarCtrl::IDToIndex](#idtoindex)|Converte um identificador de banda (ID) em um índice de banda em um controle de vergalhões.|
|[CReBarCtrl::InsertBand](#insertband)|Insere uma nova banda em um controle de vergalhões.|
|[CReBarCtrl::MaximizeBand](#maximizeband)|Redimensiona uma banda em um controle de vergalhões para o seu maior tamanho.|
|[CReBarCtrl::MinimizeBand](#minimizeband)|Redimensiona uma banda em um controle de vergalhões para o menor tamanho.|
|[CReBarCtrl::MoveBand](#moveband)|Move uma banda de um índice para outro.|
|[CReBarCtrl::PushChevron](#pushchevron)|Programáticamente empurra um chevron.|
|[CReBarCtrl::RestoreBand](#restoreband)|Redimensiona uma banda em um controle de vergalhões para o seu tamanho ideal.|
|[CReBarCtrl::SetBandInfo](#setbandinfo)|Define características de uma banda existente em um controle de vergalhões.|
|[CReBarCtrl::SetBandWidth](#setbandwidth)|Define a largura da banda encaixada especificada no controle atual do vergalhão.|
|[CReBarCtrl::SetBarInfo](#setbarinfo)|Define as características de um controle de vergalhões.|
|[CReBarCtrl::SetBkColor](#setbkcolor)|Define a cor de fundo padrão do controle de vergalhões.|
|[CReBarCtrl::SetColorScheme](#setcolorscheme)|Define o esquema de cores para os botões em um controle de vergalhões.|
|[CReBarCtrl::SetExtendedStyle](#setextendedstyle)|Define os estilos estendidos para o controle atual do vergalhão.|
|[CReBarCtrl::SetImageList](#setimagelist)|Define a lista de imagens de um controle de vergalhões.|
|[CReBarCtrl::SetOwner](#setowner)|Define a janela do proprietário do controle de vergalhões.|
|[CReBarCtrl::SetPalette](#setpalette)|Define a paleta atual do controle do vergalhão.|
|[CReBarCtrl::SetTextColor](#settextcolor)|Define a cor de texto padrão do controle de vergalhões.|
|[CReBarCtrl::SetToolTips](#settooltips)|Associa um controle de ponta de ferramenta com o controle do vergalhão.|
|[CReBarCtrl::SetWindowTheme](#setwindowtheme)|Define o estilo visual do controle do vergalhão.|
|[CReBarCtrl::ShowBand](#showband)|Mostra ou esconde uma determinada banda em um controle de vergalhões.|
|[CReBarCtrl::SizeToRect](#sizetorect)|Encaixa-se um controle de vergalhões em um retângulo especificado.|

## <a name="remarks"></a>Comentários

O aplicativo no qual reside o controle do vergalhão atribui a janela da criança contida pelo controle do vergalhão à banda do vergalhão. A janela da criança é geralmente outro controle comum.

Os controles de barra galantes contêm uma ou mais bandas. Cada banda pode conter uma combinação de uma barra de aperto, um bitmap, uma etiqueta de texto e uma janela de criança. A banda pode conter apenas um desses itens.

O controle do vergalhão pode exibir a janela do filho sobre um bitmap de fundo especificado. Todas as bandas de controle de vergalhões podem ser redimensionadas, exceto aquelas que usam o estilo RBBS_FIXEDSIZE. À medida que você reposiciona ou redimensiona uma banda de controle de vergalhões, o controle do vergalhão gerencia o tamanho e a posição da janela filho atribuída a essa banda. Para redimensionar ou alterar a ordem das bandas dentro do controle, clique e arraste a barra de aperto de uma banda.

A ilustração a seguir mostra um controle de vergalhões que tem três bandas:

- A banda 0 contém um controle de barra de ferramentas plana e transparente.

- A banda 1 contém botões de estada padrão transparente e transparente.

- A banda 2 contém uma caixa de combinação e quatro botões padrão.

   ![Exemplo de um menu de barras](../../mfc/reference/media/vc4scc1.gif "Exemplo de um menu de barras")

## <a name="rebar-control"></a>Controle de vergalhões

Suporte aos controles de vergalhões:

- Listas de imagens.

- Manipulação de mensagens.

- Funcionalidade de desenho personalizado.

- Uma variedade de estilos de controle, além de estilos de janela padrão. Para obter uma lista desses estilos, consulte Estilos de controle de [barras](/windows/win32/Controls/rebar-control-styles) no SDK do Windows.

Para obter mais informações, consulte [Usando CReBarCtrl](../../mfc/using-crebarctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CReBarCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="crebarctrlbegindrag"></a><a name="begindrag"></a>CReBarCtrl::BeginDrag

Implementa o comportamento da mensagem Win32 [RB_BEGINDRAG,](/windows/win32/Controls/rb-begindrag)conforme descrito no SDK do Windows.

```
void BeginDrag(
    UINT uBand,
    DWORD dwPos = (DWORD)-1);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da banda que a operação de arrastar e soltar afetará.

*dwPos*<br/>
Um valor DWORD que contém as coordenadas iniciais do mouse. A coordenada horizontal está contida no LOWORD e a coordenada vertical está contida no HIWORD. Se você passar (DWORD)-1, o controle de vergalhões usará a posição `GetMessage` do `PeekMessage`mouse da última vez que o segmento do controle for chamado ou .

## <a name="crebarctrlcreate"></a><a name="create"></a>CReBarCtrl::Criar

Cria o controle do vergalhão e o prende ao `CReBarCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica a combinação de estilos de controle de vergalhões aplicados ao controle. Consulte [Estilos de controle](/windows/win32/Controls/rebar-control-styles) de barras no SDK do Windows para obter uma lista de estilos suportados.

*Rect*<br/>
Uma referência a um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou estrutura [RECT,](/previous-versions/dd162897\(v=vs.85\)) que é a posição e o tamanho do controle do vergalhão.

*Pparentwnd*<br/>
Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle do vergalhão. Não deve ser NULO.

*nID*<br/>
Especifica o ID de controle do controle do vergalhão.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto foi criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Crie um controle de vergalhões em duas etapas:

1. Chame [CReBarCtrl](#crebarctrl) para `CReBarCtrl` construir um objeto.

1. Ligue para esta função de membro, que cria o `CReBarCtrl` controle de vergalhões do Windows e a anexa ao objeto.

Quando você `Create`chama, os controles comuns são inicializados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#3](../../mfc/reference/codesnippet/cpp/crebarctrl-class_1.cpp)]

## <a name="crebarctrlcreateex"></a><a name="createex"></a>CReBarCtrl::CreateEx

Cria um controle (uma janela filho) `CReBarCtrl` e o associa ao objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwexstyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Dwstyle*<br/>
Especifica a combinação de estilos de controle de vergalhões aplicados ao controle. Para obter uma lista de estilos suportados, consulte Estilos de controle de [barras](/windows/win32/Controls/rebar-control-styles) no SDK do Windows.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) descrevendo o tamanho e a posição da janela a ser criada, em coordenadas de cliente de *pParentWnd*.

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A id da janela infantil do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

## <a name="crebarctrlcrebarctrl"></a><a name="crebarctrl"></a>CReBarCtrl::CReBarCtrl

Cria um objeto `CReBarCtrl`.

```
CReBarCtrl();
```

### <a name="example"></a>Exemplo

  Veja o exemplo de [CReBarCtrl::Create](#create).

## <a name="crebarctrldeleteband"></a><a name="deleteband"></a>CReBarCtrl::DeleteBand

Implementa o comportamento da mensagem Win32 [RB_DELETEBAND](/windows/win32/Controls/rb-deleteband), conforme descrito no SDK do Windows.

```
BOOL DeleteBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da banda a ser excluído.

### <a name="return-value"></a>Valor retornado

Não zero se a banda for excluída com sucesso; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#4](../../mfc/reference/codesnippet/cpp/crebarctrl-class_2.cpp)]

## <a name="crebarctrldragmove"></a><a name="dragmove"></a>CReBarCtrl::DragMove

Implementa o comportamento da mensagem Win32 [RB_DRAGMOVE](/windows/win32/Controls/rb-dragmove), conforme descrito no SDK do Windows.

```
void DragMove(DWORD dwPos = (DWORD)-1);
```

### <a name="parameters"></a>Parâmetros

*dwPos*<br/>
Um valor DWORD que contém as novas coordenadas do mouse. A coordenada horizontal está contida no LOWORD e a coordenada vertical está contida no HIWORD. Se você passar (DWORD)-1, o controle de vergalhões usará a posição `GetMessage` do `PeekMessage`mouse da última vez que o segmento do controle for chamado ou .

## <a name="crebarctrlenddrag"></a><a name="enddrag"></a>CReBarCtrl::EndDrag

Implementa o comportamento da [mensagem](/windows/win32/Controls/rb-enddrag)Win32 RB_ENDDRAG , conforme descrito no SDK do Windows.

```
void EndDrag();
```

## <a name="crebarctrlgetbandborders"></a><a name="getbandborders"></a>CReBarCtrl::GetBandBorders

Implementa o comportamento da mensagem Win32 [RB_GETBANDBORDERS,](/windows/win32/Controls/rb-getbandborders)conforme descrito no SDK do Windows.

```
void GetBandBorders(
    UINT uBand,
    LPRECT prc) const;
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da banda para a qual as fronteiras serão recuperadas.

*Prc*<br/>
Um ponteiro para uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) que receberá as bordas da banda. Se o controle do vergalhão tiver o estilo RBS_BANDBORDERS, cada membro desta estrutura receberá o número de pixels, no lado correspondente da banda, que constituem a borda. Se o controle do vergalhão não tiver o estilo RBS_BANDBORDERS, apenas o membro esquerdo desta estrutura recebe informações válidas. Para obter uma descrição dos estilos de controle de verbar, consulte Estilos de controle de [barras](/windows/win32/Controls/rebar-control-styles) no SDK do Windows.

## <a name="crebarctrlgetbandcount"></a><a name="getbandcount"></a>CReBarCtrl::GetBandCount

Implementa o comportamento da mensagem Win32 [RB_GETBANDCOUNT](/windows/win32/Controls/rb-getbandcount), conforme descrito no SDK do Windows.

```
UINT GetBandCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de bandas atribuídas ao controle.

## <a name="crebarctrlgetbandinfo"></a><a name="getbandinfo"></a>CReBarCtrl::GetBandInfo

Implementa o comportamento da mensagem Win32 [RB_GETBANDINFO](/windows/win32/Controls/rb-getbandinfo) conforme descrito no SDK do Windows.

```
BOOL GetBandInfo(
    UINT uBand,
    REBARBANDINFO* prbbi) const;
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da banda para a qual as informações serão recuperadas.

*prbbi*<br/>
Um ponteiro para uma estrutura [REBARBANDINFO](/windows/win32/api/commctrl/ns-commctrl-rebarbandinfow) para receber as informações da banda. Você deve `cbSize` definir o membro `sizeof(REBARBANDINFO)` desta `fMask` estrutura e definir o membro para os itens que deseja recuperar antes de enviar esta mensagem.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

## <a name="crebarctrlgetbandmargins"></a><a name="getbandmargins"></a>CReBarCtrl::GetBandMargins

Recupera as margens da banda.

```
void GetBandMargins(PMARGINS pMargins);
```

### <a name="parameters"></a>Parâmetros

*margens pMargens*<br/>
Um ponteiro para uma estrutura [MARGINS](/windows/win32/api/uxtheme/ns-uxtheme-margins)que receberá as informações.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem [RB_GETBANDMARGINS,](/windows/win32/Controls/rb-getbandmargins) conforme descrito no SDK do Windows.

## <a name="crebarctrlgetbarheight"></a><a name="getbarheight"></a>CReBarCtrl::GetBarHeight

Recupera a altura da barra de vergalhões.

```
UINT GetBarHeight() const;
```

### <a name="return-value"></a>Valor retornado

Valor que representa a altura, em pixels, do controle.

## <a name="crebarctrlgetbarinfo"></a><a name="getbarinfo"></a>CReBarCtrl::GetBarInfo

Implementa o comportamento da [mensagem](/windows/win32/Controls/rb-getbarinfo)Win32 RB_GETBARINFO , conforme descrito no SDK do Windows.

```
BOOL GetBarInfo(REBARINFO* prbi) const;
```

### <a name="parameters"></a>Parâmetros

*prbi*<br/>
Um ponteiro para uma estrutura [REBARINFO](/windows/win32/api/commctrl/ns-commctrl-rebarinfo) que receberá as informações de controle do vergalhão. Você deve definir o membro *cbSize* desta estrutura para `sizeof(REBARINFO)` antes de enviar esta mensagem.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

## <a name="crebarctrlgetbkcolor"></a><a name="getbkcolor"></a>CReBarCtrl::GetBkColor

Implementa o comportamento da [mensagem](/windows/win32/Controls/rb-getbkcolor)Win32 RB_GETBKCOLOR , conforme descrito no SDK do Windows.

```
COLORREF GetBkColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor COLORREF que representa a cor de fundo padrão atual.

## <a name="crebarctrlgetcolorscheme"></a><a name="getcolorscheme"></a>CReBarCtrl::GetColorScheme

Recupera a estrutura [COLORSCHEME](/windows/win32/api/commctrl/ns-commctrl-colorscheme) para o controle do vergalhão.

```
BOOL GetColorScheme(COLORSCHEME* lpcs);
```

### <a name="parameters"></a>Parâmetros

*lpcs*<br/>
Um ponteiro para uma estrutura [COLORSCHEME,](/windows/win32/api/commctrl/ns-commctrl-colorscheme) conforme descrito no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

A `COLORSCHEME` estrutura inclui a cor de destaque do botão e a cor da sombra do botão.

## <a name="crebarctrlgetdroptarget"></a><a name="getdroptarget"></a>CReBarCtrl::GetDropTarget

Implementa o comportamento da mensagem Win32 [RB_GETDROPTARGET,](/windows/win32/Controls/rb-getdroptarget)conforme descrito no SDK do Windows.

```
IDropTarget* GetDropTarget() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma interface [IDropTarget.](/windows/win32/api/oleidl/nn-oleidl-idroptarget)

## <a name="crebarctrlgetextendedstyle"></a><a name="getextendedstyle"></a>CReBarCtrl::GetExtendedStyle

Obtém os estilos estendidos do controle de vergalhões atual.

```
DWORD GetExtendedStyle() const;
```

### <a name="return-value"></a>Valor retornado

Uma combinação bitwise (OR) de bandeiras que indicam os estilos estendidos. As possíveis bandeiras são RBS_EX_SPLITTER e RBS_EX_TRANSPARENT. Para obter mais informações, consulte o parâmetro *dwMask* do método [CReBarCtrl::SetExtendedStyle.](#setextendedstyle)

### <a name="remarks"></a>Comentários

Este método envia a mensagem [RB_GETEXTENDEDSTYLE,](/windows/win32/Controls/rb-dragmove) que é descrita no SDK do Windows.

## <a name="crebarctrlgetimagelist"></a><a name="getimagelist"></a>CReBarCtrl::GetImageList

Obtém `CImageList` o objeto associado a um controle de vergalhões.

```
CImageList* GetImageList() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList.](../../mfc/reference/cimagelist-class.md) Retorna NULL se nenhuma lista de imagens for definida para o controle.

### <a name="remarks"></a>Comentários

Esta função de membro usa informações de tamanho e máscara armazenadas na estrutura [REBARINFO,](/windows/win32/api/commctrl/ns-commctrl-rebarinfo) conforme descrito no SDK do Windows.

## <a name="crebarctrlgetpalette"></a><a name="getpalette"></a>CReBarCtrl::GetPalette

Recupera a paleta atual do controle do vergalhão.

```
CPalette* GetPalette() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CPalette](../../mfc/reference/cpalette-class.md) especificando a paleta atual do controle de vergalhões.

### <a name="remarks"></a>Comentários

Observe que esta função `CPalette` de membro usa um objeto como seu valor de retorno, em vez de um HPALETTE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#5](../../mfc/reference/codesnippet/cpp/crebarctrl-class_3.cpp)]

## <a name="crebarctrlgetrect"></a><a name="getrect"></a>CReBarCtrl::GetRect

Implementa o comportamento da mensagem Win32 [RB_GETRECT,](/windows/win32/Controls/rb-getrect)conforme descrito no SDK do Windows.

```
BOOL GetRect(
    UINT uBand,
    LPRECT prc) const;
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero de uma banda no controle do vergalhão.

*Prc*<br/>
Um ponteiro para uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) que receberá os limites da banda de vergalhões.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#6](../../mfc/reference/codesnippet/cpp/crebarctrl-class_4.cpp)]

## <a name="crebarctrlgetrowcount"></a><a name="getrowcount"></a>CReBarCtrl::GetRowCount

Implementa o comportamento da [mensagem](/windows/win32/Controls/rb-getrowcount)Win32 RB_GETROWCOUNT , conforme descrito no SDK do Windows.

```
UINT GetRowCount() const;
```

### <a name="return-value"></a>Valor retornado

Um valor UINT que representa o número de linhas de banda no controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#7](../../mfc/reference/codesnippet/cpp/crebarctrl-class_5.cpp)]

## <a name="crebarctrlgetrowheight"></a><a name="getrowheight"></a>CReBarCtrl::GetRowHeight

Implementa o comportamento da mensagem Win32 [RB_GETROWHEIGHT,](/windows/win32/Controls/rb-getrowheight)conforme descrito no SDK do Windows.

```
UINT GetRowHeight(UINT uRow) const;
```

### <a name="parameters"></a>Parâmetros

*uRow*<br/>
Índice baseado em zero da banda que terá sua altura recuperada.

### <a name="return-value"></a>Valor retornado

Um valor UINT que representa a altura da linha, em pixels.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#8](../../mfc/reference/codesnippet/cpp/crebarctrl-class_6.cpp)]

## <a name="crebarctrlgettextcolor"></a><a name="gettextcolor"></a>CReBarCtrl::GetTextColor

Implementa o comportamento da [mensagem](/windows/win32/Controls/rb-gettextcolor)Win32 RB_GETTEXTCOLOR , conforme descrito no SDK do Windows.

```
COLORREF GetTextColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor COLORREF que representa a cor de texto padrão atual.

## <a name="crebarctrlgettooltips"></a><a name="gettooltips"></a>CReBarCtrl::GetToolTips

Implementa o comportamento da mensagem Win32 [RB_GETTOOLTIPS,](/windows/win32/Controls/rb-gettooltips)conforme descrito no SDK do Windows.

```
CToolTipCtrl* GetToolTips() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CToolTipCtrl.](../../mfc/reference/ctooltipctrl-class.md)

### <a name="remarks"></a>Comentários

Observe que a implementação do MFC retorna `GetToolTips` um ponteiro para um `CToolTipCtrl`, em vez de um HWND.

## <a name="crebarctrlhittest"></a><a name="hittest"></a>CReBarCtrl::HitTest

Implementa o comportamento da mensagem Win32 [RB_HITTEST,](/windows/win32/Controls/rb-hittest)conforme descrito no SDK do Windows.

```
int HitTest(RBHITTESTINFO* prbht);
```

### <a name="parameters"></a>Parâmetros

*prbht*<br/>
Um ponteiro para uma estrutura [RBHITTESTINFO.](/windows/win32/api/commctrl/ns-commctrl-rbhittestinfo) Antes de enviar `pt` a mensagem, o membro desta estrutura deve ser inicializado ao ponto que será testado, nas coordenadas do cliente.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero da banda no ponto dado, ou -1 se nenhuma faixa de vergalhões estava no ponto.

## <a name="crebarctrlidtoindex"></a><a name="idtoindex"></a>CReBarCtrl::IDToIndex

Implementa o comportamento da mensagem Win32 [RB_IDTOINDEX](/windows/win32/controls/rb-idtoindex), conforme descrito no SDK do Windows.

```
int IDToIndex(UINT uBandID) const;
```

### <a name="parameters"></a>Parâmetros

*uBandID*<br/>
O identificador definido pelo aplicativo da banda `wID` especificada, passado no membro da estrutura [REBARBANDINFO](/windows/win32/api/commctrl/ns-commctrl-rebarbandinfow) quando a banda é inserida.

### <a name="return-value"></a>Valor retornado

O índice de banda baseado em zero se bem sucedido, ou -1 de outra forma. Se houver índices de banda duplicada, o primeiro é devolvido.

## <a name="crebarctrlinsertband"></a><a name="insertband"></a>CReBarCtrl::InsertBand

Implementa o comportamento da mensagem Win32 [RB_INSERTBAND,](/windows/win32/Controls/rb-insertband)conforme descrito no SDK do Windows.

```
BOOL InsertBand(
    UINT uIndex,
    REBARBANDINFO* prbbi);
```

### <a name="parameters"></a>Parâmetros

*uIndex*<br/>
Índice baseado em zero do local onde a banda será inserida. Se você definir este parâmetro para -1, o controle adicionará a nova banda no último local.

*prbbi*<br/>
Um ponteiro para uma estrutura [REBARBANDINFO](/windows/win32/api/commctrl/ns-commctrl-rebarbandinfow) que define a banda a ser inserida. Você deve definir o membro *cbSize* desta estrutura para `sizeof(REBARBANDINFO)` antes de chamar esta função.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#9](../../mfc/reference/codesnippet/cpp/crebarctrl-class_7.cpp)]

## <a name="crebarctrlmaximizeband"></a><a name="maximizeband"></a>CReBarCtrl::MaximizeBand

Redimensiona uma banda em um controle de vergalhões para o seu maior tamanho.

```
void MaximizeBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da banda a ser maximizado.

### <a name="remarks"></a>Comentários

Implementa o comportamento da mensagem `fIdeal` Win32 [RB_MAXIMIZEBAND](/windows/win32/Controls/rb-maximizeband) com set para 0, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#10](../../mfc/reference/codesnippet/cpp/crebarctrl-class_8.cpp)]

## <a name="crebarctrlminimizeband"></a><a name="minimizeband"></a>CReBarCtrl::MinimizeBand

Redimensiona uma banda em um controle de vergalhões para o menor tamanho.

```
void MinimizeBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da banda a ser minimizado.

### <a name="remarks"></a>Comentários

Implementa o comportamento da mensagem Win32 [RB_MINIMIZEBAND](/windows/win32/Controls/rb-minimizeband), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#11](../../mfc/reference/codesnippet/cpp/crebarctrl-class_9.cpp)]

## <a name="crebarctrlmoveband"></a><a name="moveband"></a>CReBarCtrl::MoveBand

Implementa o comportamento da mensagem Win32 [RB_MOVEBAND,](/windows/win32/Controls/rb-moveband)conforme descrito no SDK do Windows.

```
BOOL MoveBand(
    UINT uFrom,
    UINT uTo);
```

### <a name="parameters"></a>Parâmetros

*uFrom*<br/>
Índice baseado em zero da banda a ser movido.

*Uto*<br/>
Índice baseado em zero da nova posição da banda. Este valor de parâmetro nunca deve ser maior do que o número de bandas menos uma. Para obter o número de bandas, ligue para [GetBandCount](#getbandcount).

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

## <a name="crebarctrlpushchevron"></a><a name="pushchevron"></a>CReBarCtrl::PushChevron

Implementa o comportamento da mensagem Win32 [RB_PUSHCHEVRON,](/windows/win32/Controls/rb-pushchevron)conforme descrito no SDK do Windows.

```
void PushChevron(
    UINT uBand,
    LPARAM lAppValue);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da banda cujo chevron deve ser empurrado.

*lAppValue*<br/>
Um aplicativo definiu o valor de 32 bits. Consulte *o iAppValue* em [RB_PUSHCHEVRON](/windows/win32/Controls/rb-pushchevron) no SDK do Windows.

## <a name="crebarctrlrestoreband"></a><a name="restoreband"></a>CReBarCtrl::RestoreBand

Redimensiona uma banda em um controle de vergalhões para o seu tamanho ideal.

```
void RestoreBand(UINT uBand);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da banda a ser maximizado.

### <a name="remarks"></a>Comentários

Implementa o comportamento da [mensagem](/windows/win32/Controls/rb-maximizeband) `fIdeal` Win32 RB_MAXIMIZEBAND com definido como 1, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#12](../../mfc/reference/codesnippet/cpp/crebarctrl-class_10.cpp)]

## <a name="crebarctrlsetbandinfo"></a><a name="setbandinfo"></a>CReBarCtrl::SetBandInfo

Implementa o comportamento da mensagem Win32 [RB_SETBANDINFO,](/windows/win32/Controls/rb-setbandinfo)conforme descrito no SDK do Windows.

```
BOOL SetBandInfo(
    UINT uBand,
    REBARBANDINFO* prbbi);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero da banda para receber as novas configurações.

*prbbi*<br/>
Pointer para uma estrutura [REBARBANDINFO](/windows/win32/api/commctrl/ns-commctrl-rebarbandinfow) que define a banda a ser inserida. Você deve `cbSize` definir o membro `sizeof(REBARBANDINFO)` desta estrutura para antes de enviar esta mensagem.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#13](../../mfc/reference/codesnippet/cpp/crebarctrl-class_11.cpp)]

## <a name="crebarctrlsetbandwidth"></a><a name="setbandwidth"></a>CReBarCtrl::SetBandWidth

Define a largura da banda encaixada especificada no controle atual do vergalhão.

```
BOOL SetBandWidth(
    UINT uBand,
    int cxWidth);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*uBand*|[em] Índice baseado em zero de uma banda de vergalhões.|
|*cxWidth*|[em] Nova largura da banda de vergalhões, em pixels.|

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [RB_SETBANDWIDTH,](/windows/win32/Controls/rb-setbandwidth) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_rebar`seguir define a variável, que é usada para acessar o controle de vergalhões atual. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CReBarCtrl_s1#1](../../mfc/reference/codesnippet/cpp/crebarctrl-class_12.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define cada banda de vergalhões com a mesma largura.

[!code-cpp[NVC_MFC_CReBarCtrl_s1#2](../../mfc/reference/codesnippet/cpp/crebarctrl-class_13.cpp)]

## <a name="crebarctrlsetbarinfo"></a><a name="setbarinfo"></a>CReBarCtrl::SetBarInfo

Implementa o comportamento da [RB_SETBARINFO](/windows/win32/Controls/rb-setbarinfo)de mensagens Win32, conforme descrito no SDK do Windows.

```
BOOL SetBarInfo(REBARINFO* prbi);
```

### <a name="parameters"></a>Parâmetros

*prbi*<br/>
Um ponteiro para uma estrutura [REBARINFO](/windows/win32/api/commctrl/ns-commctrl-rebarinfo) que contém as informações a serem definidas. Você deve `cbSize` definir o membro `sizeof(REBARINFO)` desta estrutura para antes de enviar esta mensagem

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CReBarCtrl#14](../../mfc/reference/codesnippet/cpp/crebarctrl-class_14.cpp)]

## <a name="crebarctrlsetbkcolor"></a><a name="setbkcolor"></a>CReBarCtrl::SetBkColor

Implementa o comportamento da mensagem Win32 [RB_SETBKCOLOR](/windows/win32/Controls/rb-setbkcolor), conforme descrito no SDK do Windows.

```
COLORREF SetBkColor(COLORREF clr);
```

### <a name="parameters"></a>Parâmetros

*Clr*<br/>
O valor COLORREF que representa a nova cor de fundo padrão.

### <a name="return-value"></a>Valor retornado

Um valor [COLORREF](/windows/win32/gdi/colorref) que representa a cor de fundo padrão anterior.

### <a name="remarks"></a>Comentários

Consulte este tópico para obter mais informações sobre quando definir a cor de fundo e como definir o padrão.

## <a name="crebarctrlsetcolorscheme"></a><a name="setcolorscheme"></a>CReBarCtrl::SetColorScheme

Define o esquema de cores para os botões em um controle de vergalhões.

```
void SetColorScheme(const COLORSCHEME* lpcs);
```

### <a name="parameters"></a>Parâmetros

*lpcs*<br/>
Um ponteiro para uma estrutura [COLORSCHEME,](/windows/win32/api/commctrl/ns-commctrl-colorscheme) conforme descrito no SDK do Windows.

### <a name="remarks"></a>Comentários

A `COLORSCHEME` estrutura inclui tanto a cor de destaque do botão quanto a cor da sombra do botão.

## <a name="crebarctrlsetextendedstyle"></a><a name="setextendedstyle"></a>CReBarCtrl::SetExtendedStyle

Define os estilos estendidos para o controle atual do vergalhão.

```
DWORD SetExtendedStyle(
    DWORD dwMask,
    DWORD dwStyleEx);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Dwmask*|[em] Uma combinação bitwise (OR) de sinalizadores que especificam quais sinalizadores no parâmetro *dwStyleEx* se aplicam. Use um ou mais dos seguintes valores:<br /><br /> RBS_EX_SPLITTER: Por padrão, mostre o divisor na parte inferior no modo horizontal e à direita no modo vertical.<br /><br /> RBS_EX_TRANSPARENT: Encaminhe a mensagem [WM_ERASEBKGND](/windows/win32/winmsg/wm-erasebkgnd) para a janela dos pais.|
|*dwStyleEx*|[em] Uma combinação bitwise (OR) de sinalizadores que especificam os estilos a serem aplicados. Para definir um estilo, especifique o mesmo sinalizador usado no parâmetro *dwMask.* Para redefinir um estilo, especifique zero binário.|

### <a name="return-value"></a>Valor retornado

O estilo estendido anterior.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [RB_SETEXTENDEDSTYLE,](/windows/win32/Controls/rb-setextendedstyle) que é descrita no SDK do Windows.

## <a name="crebarctrlsetimagelist"></a><a name="setimagelist"></a>CReBarCtrl::SetImageList

Atribui uma lista de imagens a um controle de vergalhões.

```
BOOL SetImageList(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*pImageList*<br/>
Um ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) contendo a lista de imagens a ser atribuído ao controle de vergalhões.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

## <a name="crebarctrlsetowner"></a><a name="setowner"></a>CReBarCtrl::SetOwner

Implementa o comportamento da [mensagem](/windows/win32/Controls/rb-setparent)RB_SETPARENT do Win32, conforme descrito no SDK do Windows.

```
CWnd* SetOwner(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Um ponteiro `CWnd` para um objeto para definir como o proprietário do controle do vergalhão.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é o atual proprietário do controle de vergalhões.

### <a name="remarks"></a>Comentários

Observe que esta função de `CWnd` membro usa ponteiros para objetos para o proprietário atual e selecionado do controle do vergalhão, em vez de alças para janelas.

> [!NOTE]
> Esta função de membro não altera o pai real que foi definido quando o controle foi criado; em vez disso, envia mensagens de notificação para a janela especificada.

## <a name="crebarctrlsetpalette"></a><a name="setpalette"></a>CReBarCtrl::SetPalette

Implementa o comportamento da [mensagem](/windows/win32/Controls/rb-setpalette)Win32 RB_SETPALETTE , conforme descrito no SDK do Windows.

```
CPalette* SetPalette(HPALETTE hPal);
```

### <a name="parameters"></a>Parâmetros

*hPal*<br/>
Um HPALETTE que especifica a nova paleta que o controle do vergalhão usará.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CPalette](../../mfc/reference/cpalette-class.md) especificando a paleta anterior do controle de vergalhões.

### <a name="remarks"></a>Comentários

Observe que esta função `CPalette` de membro usa um objeto como seu valor de retorno, em vez de um HPALETTE.

## <a name="crebarctrlsettextcolor"></a><a name="settextcolor"></a>CReBarCtrl::SetTextColor

Implementa o comportamento da mensagem Win32 [RB_SETTEXTCOLOR,](/windows/win32/Controls/rb-settextcolor)conforme descrito no SDK do Windows.

```
COLORREF SetTextColor(COLORREF clr);
```

### <a name="parameters"></a>Parâmetros

*Clr*<br/>
Um valor COLORREF que representa a `CReBarCtrl` nova cor de texto no objeto.

### <a name="return-value"></a>Valor retornado

O valor [COLORREF](/windows/win32/gdi/colorref) representando a cor `CReBarCtrl` de texto anterior associada ao objeto.

### <a name="remarks"></a>Comentários

Ele é fornecido para suportar a flexibilidade da cor do texto em um controle de vergalhões.

## <a name="crebarctrlsettooltips"></a><a name="settooltips"></a>CReBarCtrl::SetToolTips

Associa um controle de ponta de ferramenta com um controle de vergalhões.

```
void SetToolTips(CToolTipCtrl* pToolTip);
```

### <a name="parameters"></a>Parâmetros

*ponta de ferramenta*<br/>
Um ponteiro para um objeto [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md)

### <a name="remarks"></a>Comentários

Você deve `CToolTipCtrl` destruir o objeto quando acabar com ele.

## <a name="crebarctrlsetwindowtheme"></a><a name="setwindowtheme"></a>CReBarCtrl::SetWindowTheme

Define o estilo visual do controle do vergalhão.

```
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

### <a name="parameters"></a>Parâmetros

*pszSubAppName*<br/>
Um ponteiro para uma seqüência Unicode que contém o estilo visual do vergalhão a definir.

### <a name="return-value"></a>Valor retornado

O valor de retorno não é usado.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem [RB_SETWINDOWTHEME,](/windows/win32/Controls/rb-setwindowtheme) conforme descrito no SDK do Windows.

## <a name="crebarctrlshowband"></a><a name="showband"></a>CReBarCtrl::ShowBand

Implementa o comportamento da [mensagem](/windows/win32/Controls/rb-showband)RB_SHOWBAND Do Tipo Win32, conforme descrito no SDK do Windows.

```
BOOL ShowBand(
    UINT uBand,
    BOOL fShow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*uBand*<br/>
Índice baseado em zero de uma banda no controle do vergalhão.

*fShow*<br/>
Indica se a banda deve ser mostrada ou escondida. Se esse valor for TRUE, a banda será mostrada. Caso contrário, a banda estará escondida.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

## <a name="crebarctrlsizetorect"></a><a name="sizetorect"></a>CReBarCtrl::SizeToRect

Implementa o comportamento da mensagem Win32 [RB_SIZETORECT,](/windows/win32/Controls/rb-sizetorect)conforme descrito no SDK do Windows.

```
BOOL SizeToRect(CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Uma referência a um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que especifica o retângulo para o que o controle do vergalhão deve ser dimensionado.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Observe que esta função `CRect` membro usa um objeto `RECT` como parâmetro, em vez de uma estrutura.

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
