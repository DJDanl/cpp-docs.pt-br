---
title: Classe CSliderCtrl
ms.date: 11/04/2016
f1_keywords:
- CSliderCtrl
- AFXCMN/CSliderCtrl
- AFXCMN/CSliderCtrl::CSliderCtrl
- AFXCMN/CSliderCtrl::ClearSel
- AFXCMN/CSliderCtrl::ClearTics
- AFXCMN/CSliderCtrl::Create
- AFXCMN/CSliderCtrl::CreateEx
- AFXCMN/CSliderCtrl::GetBuddy
- AFXCMN/CSliderCtrl::GetChannelRect
- AFXCMN/CSliderCtrl::GetLineSize
- AFXCMN/CSliderCtrl::GetNumTics
- AFXCMN/CSliderCtrl::GetPageSize
- AFXCMN/CSliderCtrl::GetPos
- AFXCMN/CSliderCtrl::GetRange
- AFXCMN/CSliderCtrl::GetRangeMax
- AFXCMN/CSliderCtrl::GetRangeMin
- AFXCMN/CSliderCtrl::GetSelection
- AFXCMN/CSliderCtrl::GetThumbLength
- AFXCMN/CSliderCtrl::GetThumbRect
- AFXCMN/CSliderCtrl::GetTic
- AFXCMN/CSliderCtrl::GetTicArray
- AFXCMN/CSliderCtrl::GetTicPos
- AFXCMN/CSliderCtrl::GetToolTips
- AFXCMN/CSliderCtrl::SetBuddy
- AFXCMN/CSliderCtrl::SetLineSize
- AFXCMN/CSliderCtrl::SetPageSize
- AFXCMN/CSliderCtrl::SetPos
- AFXCMN/CSliderCtrl::SetRange
- AFXCMN/CSliderCtrl::SetRangeMax
- AFXCMN/CSliderCtrl::SetRangeMin
- AFXCMN/CSliderCtrl::SetSelection
- AFXCMN/CSliderCtrl::SetThumbLength
- AFXCMN/CSliderCtrl::SetTic
- AFXCMN/CSliderCtrl::SetTicFreq
- AFXCMN/CSliderCtrl::SetTipSide
- AFXCMN/CSliderCtrl::SetToolTips
helpviewer_keywords:
- CSliderCtrl [MFC], CSliderCtrl
- CSliderCtrl [MFC], ClearSel
- CSliderCtrl [MFC], ClearTics
- CSliderCtrl [MFC], Create
- CSliderCtrl [MFC], CreateEx
- CSliderCtrl [MFC], GetBuddy
- CSliderCtrl [MFC], GetChannelRect
- CSliderCtrl [MFC], GetLineSize
- CSliderCtrl [MFC], GetNumTics
- CSliderCtrl [MFC], GetPageSize
- CSliderCtrl [MFC], GetPos
- CSliderCtrl [MFC], GetRange
- CSliderCtrl [MFC], GetRangeMax
- CSliderCtrl [MFC], GetRangeMin
- CSliderCtrl [MFC], GetSelection
- CSliderCtrl [MFC], GetThumbLength
- CSliderCtrl [MFC], GetThumbRect
- CSliderCtrl [MFC], GetTic
- CSliderCtrl [MFC], GetTicArray
- CSliderCtrl [MFC], GetTicPos
- CSliderCtrl [MFC], GetToolTips
- CSliderCtrl [MFC], SetBuddy
- CSliderCtrl [MFC], SetLineSize
- CSliderCtrl [MFC], SetPageSize
- CSliderCtrl [MFC], SetPos
- CSliderCtrl [MFC], SetRange
- CSliderCtrl [MFC], SetRangeMax
- CSliderCtrl [MFC], SetRangeMin
- CSliderCtrl [MFC], SetSelection
- CSliderCtrl [MFC], SetThumbLength
- CSliderCtrl [MFC], SetTic
- CSliderCtrl [MFC], SetTicFreq
- CSliderCtrl [MFC], SetTipSide
- CSliderCtrl [MFC], SetToolTips
ms.assetid: dd12b084-4eda-4550-a810-8f3cfb06b871
ms.openlocfilehash: 24e1cb18f979d1144f15cf6ffedc6cace5f5361e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318223"
---
# <a name="csliderctrl-class"></a>Classe CSliderCtrl

Fornece a funcionalidade do controle deslizante comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CSliderCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSliderCtrl::CSliderCtrl](#csliderctrl)|Constrói um objeto `CSliderCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSliderCtrl::ClearSel](#clearsel)|Limpa a seleção atual em um controle deslizante.|
|[CSliderCtrl::ClearTics](#cleartics)|Remove as marcas de tique-taque atuais de um controle deslizante.|
|[CSliderCtrl::Criar](#create)|Cria um controle deslizante e o `CSliderCtrl` prende a um objeto.|
|[CSliderCtrl::CreateEx](#createex)|Cria um controle deslizante com os estilos estendidos do `CSliderCtrl` Windows especificados e o anexa a um objeto.|
|[CSliderCtrl::GetBuddy](#getbuddy)|Recupera a alça para uma janela de controle deslizante em um determinado local.|
|[CSliderCtrl::GetChannelRect](#getchannelrect)|Recupera o tamanho do canal do controle deslizante.|
|[CSliderCtrl::GetLineSize](#getlinesize)|Recupera o tamanho da linha de um controle deslizante.|
|[CSliderCtrl::GetNumTics](#getnumtics)|Recupera o número de marcas de tique-taque em um controle deslizante.|
|[CSliderCtrl::GetPageSize](#getpagesize)|Recupera o tamanho da página de um controle deslizante.|
|[CSliderCtrl::GetPos](#getpos)|Recupera a posição atual do controle deslizante.|
|[CSliderCtrl::GetRange](#getrange)|Recupera as posições mínimas e máximas para um controle deslizante.|
|[CSliderCtrl::GetRangeMax](#getrangemax)|Recupera a posição máxima para um controle deslizante.|
|[CSliderCtrl::GetRangeMin](#getrangemin)|Recupera a posição mínima para um controle deslizante.|
|[CSliderCtrl::GetSelection](#getselection)|Recupera o intervalo da seleção atual.|
|[CSliderCtrl::GetThumbLength](#getthumblength)|Recupera o comprimento do controle deslizante no controle atual da barra de trilhos.|
|[CSliderCtrl::GetThumbRect](#getthumbrect)|Recupera o tamanho do polegar do controle deslizante.|
|[CSliderCtrl::GetTic](#gettic)|Recupera a posição da marca de tique-taque especificada.|
|[CSliderCtrl::GetTicArray](#getticarray)|Recupera a matriz de posições de marca ção para um controle deslizante.|
|[CSliderCtrl::GetTicPos](#getticpos)|Recupera a posição da marca de tique especificada, nas coordenadas do cliente.|
|[CSliderCtrl::GetToolTips](#gettooltips)|Recupera a pega para o controle da ponta de ferramenta atribuído ao controle do controle deslizante, se houver.|
|[CSliderCtrl::SetBuddy](#setbuddy)|Atribui uma janela como a janela do amigo para um controle deslizante.|
|[CSliderCtrl::SetLineSize](#setlinesize)|Define o tamanho da linha de um controle deslizante.|
|[CSliderCtrl::SetPageSize](#setpagesize)|Define o tamanho da página de um controle deslizante.|
|[CSliderCtrl::SetPos](#setpos)|Define a posição atual do controle deslizante.|
|[CSliderCtrl::SetRange](#setrange)|Define as posições mínimas e máximas para um controle deslizante.|
|[CSliderCtrl::SetRangeMax](#setrangemax)|Define a posição máxima para um controle deslizante.|
|[CSliderCtrl::SetRangeMin](#setrangemin)|Define a posição mínima para um controle deslizante.|
|[CSliderCtrl::SetSelection](#setselection)|Define o intervalo da seleção atual.|
|[CSliderCtrl::SetThumbLength](#setthumblength)|Define o comprimento do controle deslizante no controle atual da barra de trilhos.|
|[CSliderCtrl::SetTic](#settic)|Define a posição da marca de tique-taque especificada.|
|[CSliderCtrl::SetTicFreq](#setticfreq)|Define a freqüência de marcas de tique-taque por incremento de controle deslizante.|
|[CSliderCtrl::SetTipSide](#settipside)|Posiciona um controle de ponta de ferramenta usado por um controle de barra de trilhos.|
|[CSliderCtrl::SetToolTips](#settooltips)|Atribui um controle de ponta de ferramenta a um controle deslizante.|

## <a name="remarks"></a>Comentários

Um "controle deslizante" (também conhecido como trackbar) é uma janela que contém um controle deslizante e marcas de tique-taque opcionais. Quando o usuário move o controle deslizante, usando o mouse ou as teclas de direção, o controle envia mensagens de notificação para indicar a alteração.

Os controles deslizantes são úteis quando você deseja que o usuário selecione um valor discreto ou um conjunto de valores consecutivos em uma faixa. Por exemplo, você pode usar um controle deslizante para permitir que o usuário defina a taxa de repetição do teclado movendo o controle deslizante para uma determinada marca de tique-taque.

Este controle (e, `CSliderCtrl` portanto, a classe) está disponível apenas para programas em execução sob windows 95/98 e Windows NT versão 3.51 e posterior.

O controle deslizante se move em incrementos que você especifica quando o cria. Por exemplo, se você especificar que o controle deslizante deve ter um intervalo de cinco, o controle deslizante só pode ocupar seis posições: uma posição no lado esquerdo do controle deslizante e uma posição para cada incremento na faixa. Normalmente, cada uma dessas posições é identificada por uma marca de tique-taque.

Você cria um controle deslizante usando `Create` o construtor `CSliderCtrl`e a função membro de . Depois de criar um controle deslizante, você pode `CSliderCtrl` usar funções de membro para alterar muitas de suas propriedades. As alterações que você pode fazer incluem a definição das posições mínima seleção e máxima para o controle deslizante, desenho de marcas de tique-taque, definição de um intervalo de seleção e reposicionamento do controle deslizante.

Para obter mais `CSliderCtrl`informações sobre como usar, consulte [Controles](../../mfc/controls-mfc.md) e [Usando CSliderCtrl](../../mfc/using-csliderctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CSliderCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="csliderctrlclearsel"></a><a name="clearsel"></a>CSliderCtrl::ClearSel

Limpa a seleção atual em um controle deslizante.

```
void ClearSel(BOOL bRedraw = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Bredraw*<br/>
Redesenhar bandeira. Se este parâmetro for TRUE, o controle deslizante será redesenhado após a seleção ser liberada; caso contrário, o controle deslizante não é redesenhado.

## <a name="csliderctrlcleartics"></a><a name="cleartics"></a>CSliderCtrl::ClearTics

Remove as marcas de tique-taque atuais de um controle deslizante.

```
void ClearTics(BOOL bRedraw = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Bredraw*<br/>
Redesenhar bandeira. Se este parâmetro for VERDADEIRO, o controle deslizante será redesenhado após a marca de tique-taque ser limpa; caso contrário, o controle deslizante não é redesenhado.

## <a name="csliderctrlcreate"></a><a name="create"></a>CSliderCtrl::Criar

Cria um controle deslizante e o `CSliderCtrl` prende a um objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo do controle deslizante. Aplique qualquer combinação de estilos de [controle de controle deslizante,](/windows/win32/Controls/trackbar-control-styles)descritos no Windows SDK, ao controle.

*Rect*<br/>
Especifica o tamanho e a posição do controle deslizante. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT.](/previous-versions/dd162897\(v=vs.85\))

*Pparentwnd*<br/>
Especifica a janela pai do controle de `CDialog`controle deslizante, geralmente um . Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle deslizante.

### <a name="return-value"></a>Valor retornado

Não zero se a inicialização foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CSliderCtrl` um em dois passos. Primeiro, chame o construtor e, em seguida, chame, `Create`que cria `CSliderCtrl` o controle deslizante e o anexa ao objeto.

Dependendo dos valores definidos para *dwStyle,* o controle deslizante pode ter uma orientação vertical ou horizontal. Pode ter marcas de carrapato em ambos os lados, ambos os lados, ou nenhum dos dois. Ele também pode ser usado para especificar uma série de valores consecutivos.

Para aplicar estilos de janela estendidos ao controle `Create`de controle deslizante, chame [CreateEx](#createex) em vez de .

## <a name="csliderctrlcreateex"></a><a name="createex"></a>CSliderCtrl::CreateEx

Cria um controle (uma janela filho) `CSliderCtrl` e o associa ao objeto.

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
Especifica o estilo do controle deslizante. Aplique qualquer combinação de estilos de [controle de controle deslizante,](/windows/win32/Controls/trackbar-control-styles)descritos no Windows SDK, ao controle.

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

## <a name="csliderctrlcsliderctrl"></a><a name="csliderctrl"></a>CSliderCtrl::CSliderCtrl

Constrói um objeto `CSliderCtrl`.

```
CSliderCtrl();
```

## <a name="csliderctrlgetbuddy"></a><a name="getbuddy"></a>CSliderCtrl::GetBuddy

Recupera a alça para uma janela de controle deslizante em um determinado local.

```
CWnd* GetBuddy(BOOL fLocation = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

*fLocalização*<br/>
Um valor booleano que indica qual das duas alças de janela de amigo para recuperar. Pode ser um dos seguintes valores:

- TRUE Recupera a alça para o amigo à esquerda do controle deslizante. Se o controle deslizante usar o estilo TBS_VERT, a mensagem recuperará o amigo acima do controle deslizante.

- FALSE Recupera a alça para o amigo à direita do controle deslizante. Se o controle deslizante usar o estilo TBS_VERT, a mensagem recuperará o amigo abaixo do controle deslizante.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela do amigo no local especificado por *fLocation*ou NULL se não existir nenhuma janela de amigo naquele local.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TBM_GETBUDDY](/windows/win32/Controls/tbm-getbuddy)de mensagem Win32 , conforme descrito no SDK do Windows. Para obter uma descrição dos estilos de controle de controle de slider, consulte Estilos de controle da [barra de controle](/windows/win32/Controls/trackbar-control-styles) no SDK do Windows.

## <a name="csliderctrlgetchannelrect"></a><a name="getchannelrect"></a>CSliderCtrl::GetChannelRect

Recupera o tamanho e a posição do retângulo delimitador para o canal de controle deslizante.

```
void GetChannelRect(LPRECT lprc) const;
```

### <a name="parameters"></a>Parâmetros

*Lprc*<br/>
Um ponteiro para um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que contenha o tamanho e a posição do retângulo delimitador do canal quando a função retorna.

### <a name="remarks"></a>Comentários

O canal é a área sobre a qual o controle deslizante se move e que contém o destaque quando um intervalo é selecionado.

## <a name="csliderctrlgetlinesize"></a><a name="getlinesize"></a>CSliderCtrl::GetLineSize

Recupera o tamanho da linha para um controle deslizante.

```
int GetLineSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho de uma linha para o controle deslizante.

### <a name="remarks"></a>Comentários

O tamanho da linha afeta o quanto o controle deslizante se move para as notificações de TB_LINEUP e TB_LINEDOWN. A configuração padrão para o tamanho da linha é 1.

## <a name="csliderctrlgetnumtics"></a><a name="getnumtics"></a>CSliderCtrl::GetNumTics

Recupera o número de marcas de tique-taque em um controle deslizante.

```
UINT GetNumTics() const;
```

### <a name="return-value"></a>Valor retornado

O número de marcas de tique-taque no controle deslizante.

## <a name="csliderctrlgetpagesize"></a><a name="getpagesize"></a>CSliderCtrl::GetPageSize

Recupera o tamanho da página para um controle deslizante.

```
int GetPageSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho de uma página para o controle deslizante.

### <a name="remarks"></a>Comentários

O tamanho da página afeta o quanto o controle deslizante se move para as notificações de TB_PAGEUP e TB_PAGEDOWN.

## <a name="csliderctrlgetpos"></a><a name="getpos"></a>CSliderCtrl::GetPos

Recupera a posição atual do controle deslizante em um controle deslizante.

```
int GetPos() const;
```

### <a name="return-value"></a>Valor retornado

A posição atual.

## <a name="csliderctrlgetrange"></a><a name="getrange"></a>CSliderCtrl::GetRange

Recupera as posições máxima e mínima para o controle deslizante em um controle deslizante.

```
void GetRange(
    int& nMin,
    int& nMax) const;
```

### <a name="parameters"></a>Parâmetros

*Nmin*<br/>
Referência a um inteiro que recebe a posição mínima.

*Nmax*<br/>
Referência a um inteiro que recebe a posição máxima.

### <a name="remarks"></a>Comentários

Esta função copia os valores nos inteiros referenciados por *nMin* e *nMax*.

## <a name="csliderctrlgetrangemax"></a><a name="getrangemax"></a>CSliderCtrl::GetRangeMax

Recupera a posição máxima para o controle deslizante em um controle deslizante.

```
int GetRangeMax() const;
```

### <a name="return-value"></a>Valor retornado

A posição máxima do controle.

## <a name="csliderctrlgetrangemin"></a><a name="getrangemin"></a>CSliderCtrl::GetRangeMin

Recupera a posição mínima para o controle deslizante em um controle deslizante.

```
int GetRangeMin() const;
```

### <a name="return-value"></a>Valor retornado

A posição mínima do controle.

## <a name="csliderctrlgetselection"></a><a name="getselection"></a>CSliderCtrl::GetSelection

Recupera as posições de partida e final da seleção atual em um controle deslizante.

```
void GetSelection(
    int& nMin,
    int& nMax) const;
```

### <a name="parameters"></a>Parâmetros

*Nmin*<br/>
Referência a um inteiro que recebe a posição inicial da seleção atual.

*Nmax*<br/>
Referência a um inteiro que recebe a posição final da seleção atual.

## <a name="csliderctrlgetthumblength"></a><a name="getthumblength"></a>CSliderCtrl::GetThumbLength

Recupera o comprimento do controle deslizante no controle atual da barra de trilhos.

```
int GetThumbLength() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento do controle deslizante, em pixels.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [TBM_GETTHUMBLENGTH,](/windows/win32/Controls/tbm-getthumblength) que é descrita no SDK do Windows.

## <a name="csliderctrlgetthumbrect"></a><a name="getthumbrect"></a>CSliderCtrl::GetThumbRect

Recupera o tamanho e a posição do retângulo delimitador para o controle deslizante (polegar) em um controle deslizante.

```
void GetThumbRect(LPRECT lprc) const;
```

### <a name="parameters"></a>Parâmetros

*Lprc*<br/>
Um ponteiro `CRect` para um objeto que contém o retângulo delimitador para o controle deslizante quando a função retorna.

## <a name="csliderctrlgettic"></a><a name="gettic"></a>CSliderCtrl::GetTic

Recupera a posição de uma marca de tique-taque em um controle deslizante.

```
int GetTic(int nTic) const;
```

### <a name="parameters"></a>Parâmetros

*Ntic*<br/>
Índice baseado em zero identificando uma marca de tique-taque.

### <a name="return-value"></a>Valor retornado

A posição da marca de tique especificada ou - 1 se *nTic* não especificar um índice válido.

## <a name="csliderctrlgetticarray"></a><a name="getticarray"></a>CSliderCtrl::GetTicArray

Recupera o endereço da matriz contendo as posições das marcas de tique-taque para um controle deslizante.

```
DWORD* GetTicArray() const;
```

### <a name="return-value"></a>Valor retornado

O endereço da matriz contendo posições de marca de marca de marcação para o controle do controle deslizante.

## <a name="csliderctrlgetticpos"></a><a name="getticpos"></a>CSliderCtrl::GetTicPos

Recupera a posição física atual de uma marca de tique-taque em um controle deslizante.

```
int GetTicPos(int nTic) const;
```

### <a name="parameters"></a>Parâmetros

*Ntic*<br/>
Índice baseado em zero identificando uma marca de tique-taque.

### <a name="return-value"></a>Valor retornado

A posição física, nas coordenadas do cliente, da marca de tique especificada ou - 1 se *nTic* não especificar um índice válido.

## <a name="csliderctrlgettooltips"></a><a name="gettooltips"></a>CSliderCtrl::GetToolTips

Recupera a pega para o controle da ponta de ferramenta atribuído ao controle do controle deslizante, se houver.

```
CToolTipCtrl* GetToolTips() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) ou NULL se as dicas de ferramentas não estiverem em uso. Se o controle deslizante não usar o estilo TBS_TOOLTIPS, o valor de retorno será NULA.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/tbm-gettooltips)TBM_GETTOOLTIPS do Win32, conforme descrito no SDK do Windows. Observe que esta função `CToolTipCtrl` membro retorna um objeto em vez de uma alça para um controle.

Para obter uma descrição dos estilos de controle de controle de slider, consulte Estilos de controle da [barra de controle](/windows/win32/Controls/trackbar-control-styles) no SDK do Windows.

## <a name="csliderctrlsetbuddy"></a><a name="setbuddy"></a>CSliderCtrl::SetBuddy

Atribui uma janela como a janela do amigo para um controle deslizante.

```
CWnd* SetBuddy(
    CWnd* pWndBuddy,
    BOOL fLocation = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pWndBuddy*<br/>
Um ponteiro `CWnd` para um objeto que será definido como amigo do controle deslizante.

*fLocalização*<br/>
Valor especificando o local para exibir a janela do amigo. Este valor pode ser um dos seguintes:

- VERDADE O amigo aparecerá à esquerda da barra de faixa se o controle da barra de faixa usar o estilo TBS_HORZ. Se a barra de faixa usar o estilo TBS_VERT, o amigo aparecerá acima do controle da barra de faixa.

- FALSO O amigo aparecerá à direita da barra de faixa se o controle da barra de faixa usar o estilo TBS_HORZ. Se a barra de faixa usar o estilo TBS_VERT, o amigo aparecerá abaixo do controle da barra de faixa.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que foi previamente atribuído ao controle deslizante naquele local.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TBM_SETBUDDY](/windows/win32/Controls/tbm-setbuddy)de mensagem Win32 , conforme descrito no SDK do Windows. Observe que esta função membro `CWnd` usa ponteiros para objetos, em vez de alças de janela para o seu valor de retorno e parâmetro.

Para obter uma descrição dos estilos de controle de controle de slider, consulte Estilos de controle da [barra de controle](/windows/win32/Controls/trackbar-control-styles) no SDK do Windows.

## <a name="csliderctrlsetlinesize"></a><a name="setlinesize"></a>CSliderCtrl::SetLineSize

Define o tamanho da linha para um controle deslizante.

```
int SetLineSize(int nSize);
```

### <a name="parameters"></a>Parâmetros

*Nsize*<br/>
O novo tamanho de linha do controle deslizante.

### <a name="return-value"></a>Valor retornado

O tamanho da linha anterior.

### <a name="remarks"></a>Comentários

O tamanho da linha afeta o quanto o controle deslizante se move para as notificações de TB_LINEUP e TB_LINEDOWN.

## <a name="csliderctrlsetpagesize"></a><a name="setpagesize"></a>CSliderCtrl::SetPageSize

Define o tamanho da página para um controle deslizante.

```
int SetPageSize(int nSize);
```

### <a name="parameters"></a>Parâmetros

*Nsize*<br/>
O novo tamanho da página do controle deslizante.

### <a name="return-value"></a>Valor retornado

O tamanho da página anterior.

### <a name="remarks"></a>Comentários

O tamanho da página afeta o quanto o controle deslizante se move para as notificações de TB_PAGEUP e TB_PAGEDOWN.

## <a name="csliderctrlsetpos"></a><a name="setpos"></a>CSliderCtrl::SetPos

Define a posição atual do controle deslizante em um controle deslizante.

```
void SetPos(int nPos);
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
Especifica a nova posição de controle deslizante.

## <a name="csliderctrlsetrange"></a><a name="setrange"></a>CSliderCtrl::SetRange

Define o intervalo (posições mínimas e máximas) para o controle deslizante em um controle deslizante.

```
void SetRange(
    int nMin,
    int nMax,
    BOOL bRedraw = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Nmin*<br/>
Posição mínima para o controle deslizante.

*Nmax*<br/>
Posição máxima para o controle deslizante.

*Bredraw*<br/>
O redesenho da bandeira. Se este parâmetro for TRUE, o controle deslizante será redesenhado após o intervalo ser definido; caso contrário, o controle deslizante não é redesenhado.

## <a name="csliderctrlsetrangemax"></a><a name="setrangemax"></a>CSliderCtrl::SetRangeMax

Define o intervalo máximo para o controle deslizante em um controle deslizante.

```
void SetRangeMax(
    int nMax,
    BOOL bRedraw = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Nmax*<br/>
Posição máxima para o controle deslizante.

*Bredraw*<br/>
O redesenho da bandeira. Se este parâmetro for TRUE, o controle deslizante será redesenhado após o intervalo ser definido; caso contrário, o controle deslizante não é redesenhado.

## <a name="csliderctrlsetrangemin"></a><a name="setrangemin"></a>CSliderCtrl::SetRangeMin

Define o intervalo mínimo para o controle deslizante em um controle deslizante.

```
void SetRangeMin(
    int nMin,
    BOOL bRedraw = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Nmin*<br/>
Posição mínima para o controle deslizante.

*Bredraw*<br/>
O redesenho da bandeira. Se este parâmetro for TRUE, o controle deslizante será redesenhado após o intervalo ser definido; caso contrário, o controle deslizante não é redesenhado.

## <a name="csliderctrlsetselection"></a><a name="setselection"></a>CSliderCtrl::SetSelection

Define as posições de inicialização e final para a seleção atual em um controle deslizante.

```
void SetSelection(
    int nMin,
    int nMax);
```

### <a name="parameters"></a>Parâmetros

*Nmin*<br/>
Posição inicial para o controle deslizante.

*Nmax*<br/>
Posição final para o controle deslizante.

## <a name="csliderctrlsetthumblength"></a><a name="setthumblength"></a>CSliderCtrl::SetThumbLength

Define o comprimento do controle deslizante no controle atual da barra de trilhos.

```
void SetThumbLength(int nLength);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Nlength*|[em] Comprimento do controle deslizante, em pixels.|

### <a name="remarks"></a>Comentários

Este método requer que o controle da barra de faixa seja definido como [TBS_FIXEDLENGTH](/windows/win32/Controls/trackbar-control-styles) estilo.

Este método envia a mensagem [TBM_SETTHUMBLENGTH,](/windows/win32/Controls/tbm-setthumblength) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_sliderCtrl`seguir define a variável, que é usada para acessar o controle atual da barra de faixa. O exemplo também define `thumbLength`uma variável, que é usada para armazenar o comprimento padrão do componente polegar do controle da barra de faixa. Essas variáveis são usadas no próximo exemplo.

[!code-cpp[NVC_MFC_CSliderCtrl_s1#1](../../mfc/reference/codesnippet/cpp/csliderctrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o componente de polegar do controle da barra de faixa para o dobro do comprimento padrão.

[!code-cpp[NVC_MFC_CSliderCtrl_s1#2](../../mfc/reference/codesnippet/cpp/csliderctrl-class_2.cpp)]

## <a name="csliderctrlsettic"></a><a name="settic"></a>CSliderCtrl::SetTic

Define a posição de uma marca de tique-taque em um controle deslizante.

```
BOOL SetTic(int nTic);
```

### <a name="parameters"></a>Parâmetros

*Ntic*<br/>
Posição da marca de tique-taque. Este parâmetro deve especificar um valor positivo.

### <a name="return-value"></a>Valor retornado

Não zero se a marca de tique-taque estiver definida; caso contrário, 0.

## <a name="csliderctrlsetticfreq"></a><a name="setticfreq"></a>CSliderCtrl::SetTicFreq

Define a freqüência com que as marcas de tique-taque são exibidas em um controle deslizante.

```
void SetTicFreq(int nFreq);
```

### <a name="parameters"></a>Parâmetros

*nfreq*<br/>
Frequência das marcas de carrapato.

### <a name="remarks"></a>Comentários

Por exemplo, se a freqüência estiver definida como 2, uma marca de tique-taque será exibida para todos os outros incrementos no intervalo do controle deslizante. A configuração padrão para a freqüência é 1 (ou seja, cada incremento na faixa está associado a uma marca de tique).

Você deve criar o controle com o estilo TBS_AUTOTICKS para usar esta função. Para obter mais informações, consulte [CSliderCtrl::Create](#create).

## <a name="csliderctrlsettipside"></a><a name="settipside"></a>CSliderCtrl::SetTipSide

Posiciona um controle de ponta de ferramenta usado por um controle de barra de trilhos.

```
int SetTipSide(int nLocation);
```

### <a name="parameters"></a>Parâmetros

*nLocalização*<br/>
Valor representando o local para exibir o controle da ponta de ferramenta. Para obter uma lista de valores possíveis, consulte a [mensagem](/windows/win32/Controls/tbm-settipside)TBM_SETTIPSIDE do Win32 , conforme descrito no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Um valor que representa a localização anterior do controle da dica de ferramenta. O valor de retorno é igual a um dos valores possíveis para *nLocation*.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da mensagem Win32 TBM_SETTIPSIDE, conforme descrito no SDK do Windows. Controles deslizantes que usam as dicas de ferramentas de exibição de estilo TBS_TOOLTIPS. Para obter uma descrição dos estilos de controle de controle de slider, consulte Estilos de controle da [barra de controle](/windows/win32/Controls/trackbar-control-styles) no SDK do Windows.

## <a name="csliderctrlsettooltips"></a><a name="settooltips"></a>CSliderCtrl::SetToolTips

Atribui um controle de ponta de ferramenta a um controle deslizante.

```
void SetToolTips(CToolTipCtrl* pWndTip);
```

### <a name="parameters"></a>Parâmetros

*pWndTip*<br/>
Um ponteiro para um objeto [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) contendo as pontas das ferramentas para usar com o controle deslizante.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/tbm-settooltips)Win32 TBM_SETTOOLTIPS , conforme descrito no SDK do Windows. Quando um controle deslizante é criado com o estilo TBS_TOOLTIPS, ele cria um controle de ponta de ferramenta padrão que aparece ao lado do controle deslizante, exibindo a posição atual do controle deslizante. Para obter uma descrição dos estilos de controle de controle de slider, consulte Estilos de controle da [barra de controle](/windows/win32/Controls/trackbar-control-styles) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Amostra de MFC CMNCTRL2](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CProgressCtrl](../../mfc/reference/cprogressctrl-class.md)
