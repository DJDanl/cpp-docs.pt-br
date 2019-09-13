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
ms.openlocfilehash: 8fffdfc002b25fdcd72dcbbf53e7e6c321f55296
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502515"
---
# <a name="csliderctrl-class"></a>Classe CSliderCtrl

Fornece a funcionalidade do controle Slider comum do Windows.

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
|[CSliderCtrl::ClearTics](#cleartics)|Remove as marcas de escala atuais de um controle deslizante.|
|[CSliderCtrl::Create](#create)|Cria um controle deslizante e o anexa a um `CSliderCtrl` objeto.|
|[CSliderCtrl::CreateEx](#createex)|Cria um controle deslizante com os estilos estendidos do Windows especificados e o anexa `CSliderCtrl` a um objeto.|
|[CSliderCtrl::GetBuddy](#getbuddy)|Recupera o identificador para uma janela de controle deslizante do Buddy em um determinado local.|
|[CSliderCtrl::GetChannelRect](#getchannelrect)|Recupera o tamanho do canal do controle deslizante.|
|[CSliderCtrl::GetLineSize](#getlinesize)|Recupera o tamanho da linha de um controle deslizante.|
|[CSliderCtrl::GetNumTics](#getnumtics)|Recupera o número de marcas de escala em um controle deslizante.|
|[CSliderCtrl::GetPageSize](#getpagesize)|Recupera o tamanho da página de um controle deslizante.|
|[CSliderCtrl::GetPos](#getpos)|Recupera a posição atual do controle deslizante.|
|[CSliderCtrl::GetRange](#getrange)|Recupera as posições mínima e máxima para um controle deslizante.|
|[CSliderCtrl::GetRangeMax](#getrangemax)|Recupera a posição máxima de um controle deslizante.|
|[CSliderCtrl::GetRangeMin](#getrangemin)|Recupera a posição mínima de um controle deslizante.|
|[CSliderCtrl::GetSelection](#getselection)|Recupera o intervalo da seleção atual.|
|[CSliderCtrl::GetThumbLength](#getthumblength)|Recupera o comprimento do controle deslizante no controle TrackBar atual.|
|[CSliderCtrl::GetThumbRect](#getthumbrect)|Recupera o tamanho do Thumb do controle deslizante.|
|[CSliderCtrl::GetTic](#gettic)|Recupera a posição da marca de escala especificada.|
|[CSliderCtrl::GetTicArray](#getticarray)|Recupera a matriz de posições de marca de escala para um controle deslizante.|
|[CSliderCtrl::GetTicPos](#getticpos)|Recupera a posição da marca de escala especificada em coordenadas do cliente.|
|[CSliderCtrl::GetToolTips](#gettooltips)|Recupera o identificador para o controle ToolTip atribuído ao controle Slider, se houver.|
|[CSliderCtrl::SetBuddy](#setbuddy)|Atribui uma janela como a janela Buddy para um controle deslizante.|
|[CSliderCtrl::SetLineSize](#setlinesize)|Define o tamanho da linha de um controle deslizante.|
|[CSliderCtrl::SetPageSize](#setpagesize)|Define o tamanho da página de um controle deslizante.|
|[CSliderCtrl::SetPos](#setpos)|Define a posição atual do controle deslizante.|
|[CSliderCtrl::SetRange](#setrange)|Define as posições mínima e máxima para um controle deslizante.|
|[CSliderCtrl::SetRangeMax](#setrangemax)|Define a posição máxima para um controle deslizante.|
|[CSliderCtrl::SetRangeMin](#setrangemin)|Define a posição mínima para um controle deslizante.|
|[CSliderCtrl::SetSelection](#setselection)|Define o intervalo da seleção atual.|
|[CSliderCtrl::SetThumbLength](#setthumblength)|Define o comprimento do controle deslizante no controle TrackBar atual.|
|[CSliderCtrl::SetTic](#settic)|Define a posição da marca de escala especificada.|
|[CSliderCtrl::SetTicFreq](#setticfreq)|Define a frequência das marcas de escala por incremento de controle Slider.|
|[CSliderCtrl::SetTipSide](#settipside)|Posiciona um controle ToolTip usado por um controle TrackBar.|
|[CSliderCtrl::SetToolTips](#settooltips)|Atribui um controle ToolTip a um controle Slider.|

## <a name="remarks"></a>Comentários

Um "controle deslizante" (também conhecido como TrackBar) é uma janela que contém um controle deslizante e marcas de escala opcionais. Quando o usuário move o controle deslizante, usando o mouse ou as teclas de direção, o controle envia mensagens de notificação para indicar a alteração.

Os controles deslizantes são úteis quando você deseja que o usuário selecione um valor discreto ou um conjunto de valores consecutivos em um intervalo. Por exemplo, você pode usar um controle deslizante para permitir que o usuário defina a taxa de repetição do teclado movendo o controle deslizante para uma determinada marca de escala.

Esse controle (e, portanto `CSliderCtrl` , a classe) está disponível somente para programas em execução no Windows 95/98 e no Windows NT versão 3,51 e posterior.

O controle deslizante se move em incrementos que você especifica ao criá-lo. Por exemplo, se você especificar que o controle deslizante deve ter um intervalo de cinco, o controle deslizante só poderá ocupar seis posições: uma posição no lado esquerdo do controle deslizante e uma posição para cada incremento no intervalo. Normalmente, cada uma dessas posições é identificada por uma marca de escala.

Você cria um controle deslizante usando o construtor e `Create` a função de `CSliderCtrl`membro de. Depois de criar um controle deslizante, você pode usar funções de membro `CSliderCtrl` no para alterar muitas de suas propriedades. As alterações que você pode fazer incluem definir as posições mínima e máxima para o controle deslizante, marcas de escala de desenho, definir um intervalo de seleção e reposicionar o controle deslizante.

Para obter mais informações sobre `CSliderCtrl`como usar o, consulte [controles](../../mfc/controls-mfc.md) e [usando CSliderCtrl](../../mfc/using-csliderctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CSliderCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="clearsel"></a>  CSliderCtrl::ClearSel

Limpa a seleção atual em um controle deslizante.

```
void ClearSel(BOOL bRedraw = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bRedraw*<br/>
Sinalizador de redesenho. Se esse parâmetro for TRUE, o controle deslizante será redesenhado depois que a seleção for desmarcada; caso contrário, o controle deslizante não será redesenhado.

##  <a name="cleartics"></a>  CSliderCtrl::ClearTics

Remove as marcas de escala atuais de um controle deslizante.

```
void ClearTics(BOOL bRedraw = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bRedraw*<br/>
Sinalizador de redesenho. Se esse parâmetro for TRUE, o controle deslizante será redesenhado depois que as marcas de escala forem limpas; caso contrário, o controle deslizante não será redesenhado.

##  <a name="create"></a>  CSliderCtrl::Create

Cria um controle deslizante e o anexa a um `CSliderCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle deslizante. Aplique qualquer combinação de [estilos de controle deslizante](/windows/win32/Controls/trackbar-control-styles), descrita na SDK do Windows, ao controle.

*rect*<br/>
Especifica o tamanho e a posição do controle deslizante. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) .

*pParentWnd*<br/>
Especifica a janela pai do controle deslizante, geralmente `CDialog`um. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle deslizante.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a inicialização tiver sido bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um `CSliderCtrl` em duas etapas. Primeiro, chame o construtor e, em seguida `Create`, chame, que cria o controle deslizante e o anexa `CSliderCtrl` ao objeto.

Dependendo dos valores definidos para *dwStyle*, o controle deslizante pode ter uma orientação vertical ou horizontal. Ele pode ter marcas de escala em qualquer lado, ambos os lados ou nenhum deles. Ele também pode ser usado para especificar um intervalo de valores consecutivos.

Para aplicar os estilos de janela estendidos ao controle Slider, chame [CreateEx](#createex) em vez de `Create`.

##  <a name="createex"></a>  CSliderCtrl::CreateEx

Cria um controle (uma janela filho) e o `CSliderCtrl` associa ao objeto.

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
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*dwStyle*<br/>
Especifica o estilo do controle deslizante. Aplique qualquer combinação de [estilos de controle deslizante](/windows/win32/Controls/trackbar-control-styles), descrita na SDK do Windows, ao controle.

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

##  <a name="csliderctrl"></a>  CSliderCtrl::CSliderCtrl

Constrói um objeto `CSliderCtrl`.

```
CSliderCtrl();
```

##  <a name="getbuddy"></a>  CSliderCtrl::GetBuddy

Recupera o identificador para uma janela de controle deslizante do Buddy em um determinado local.

```
CWnd* GetBuddy(BOOL fLocation = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

*fLocation*<br/>
Um valor booliano que indica qual dos dois identificadores da janela Buddy deve ser recuperado. Pode ser um dos seguintes valores:

- VERDADEIRO recupera o identificador para o amigo à esquerda do controle deslizante. Se o controle deslizante usar o estilo TBS_VERT, a mensagem recuperará o colega acima do controle deslizante.

- FALSE recupera o identificador para o colega à direita do controle deslizante. Se o controle deslizante usar o estilo TBS_VERT, a mensagem recuperará o colega abaixo do controle deslizante.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela Buddy no local especificado por *FLOCATION*, ou NULL se não existir nenhuma janela Buddy nesse local.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [TBM_GETBUDDY](/windows/win32/Controls/tbm-getbuddy)do Win32, conforme descrito na SDK do Windows. Para obter uma descrição dos estilos de controle deslizante, consulte [TrackBar Control Styles](/windows/win32/Controls/trackbar-control-styles) in the SDK do Windows.

##  <a name="getchannelrect"></a>  CSliderCtrl::GetChannelRect

Recupera o tamanho e a posição do retângulo delimitador para o canal de um controle deslizante.

```
void GetChannelRect(LPRECT lprc) const;
```

### <a name="parameters"></a>Parâmetros

*lprc*<br/>
Um ponteiro para um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que contém o tamanho e a posição do retângulo delimitador do canal quando a função retorna.

### <a name="remarks"></a>Comentários

O canal é a área sobre a qual o controle deslizante se move e que contém o realce quando um intervalo é selecionado.

##  <a name="getlinesize"></a>  CSliderCtrl::GetLineSize

Recupera o tamanho da linha para um controle deslizante.

```
int GetLineSize() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho de uma linha para o controle deslizante.

### <a name="remarks"></a>Comentários

O tamanho da linha afeta o quanto o controle deslizante se move para as notificações TB_LINEUP e TB_LINEDOWN. A configuração padrão para o tamanho da linha é 1.

##  <a name="getnumtics"></a>  CSliderCtrl::GetNumTics

Recupera o número de marcas de escala em um controle deslizante.

```
UINT GetNumTics() const;
```

### <a name="return-value"></a>Valor de retorno

O número de marcas de escala no controle deslizante.

##  <a name="getpagesize"></a>  CSliderCtrl::GetPageSize

Recupera o tamanho da página para um controle deslizante.

```
int GetPageSize() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho de uma página para o controle deslizante.

### <a name="remarks"></a>Comentários

O tamanho da página afeta o quanto o controle deslizante se move para as notificações TB_PAGEUP e TB_PAGEDOWN.

##  <a name="getpos"></a>  CSliderCtrl::GetPos

Recupera a posição atual do controle deslizante em um controle deslizante.

```
int GetPos() const;
```

### <a name="return-value"></a>Valor de retorno

A posição atual.

##  <a name="getrange"></a>  CSliderCtrl::GetRange

Recupera as posições máximas e mínimas para o controle deslizante em um controle deslizante.

```
void GetRange(
    int& nMin,
    int& nMax) const;
```

### <a name="parameters"></a>Parâmetros

*nMin*<br/>
Referência a um inteiro que recebe a posição mínima.

*nMax*<br/>
Referência a um inteiro que recebe a posição máxima.

### <a name="remarks"></a>Comentários

Essa função copia os valores para os inteiros referenciados por *nmín* e *nmáx*.

##  <a name="getrangemax"></a>  CSliderCtrl::GetRangeMax

Recupera a posição máxima do controle deslizante em um controle deslizante.

```
int GetRangeMax() const;
```

### <a name="return-value"></a>Valor de retorno

A posição máxima do controle.

##  <a name="getrangemin"></a>  CSliderCtrl::GetRangeMin

Recupera a posição mínima do controle deslizante em um controle deslizante.

```
int GetRangeMin() const;
```

### <a name="return-value"></a>Valor de retorno

A posição mínima do controle.

##  <a name="getselection"></a>  CSliderCtrl::GetSelection

Recupera as posições inicial e final da seleção atual em um controle deslizante.

```
void GetSelection(
    int& nMin,
    int& nMax) const;
```

### <a name="parameters"></a>Parâmetros

*nMin*<br/>
Referência a um inteiro que recebe a posição inicial da seleção atual.

*nMax*<br/>
Referência a um inteiro que recebe a posição final da seleção atual.

##  <a name="getthumblength"></a>  CSliderCtrl::GetThumbLength

Recupera o comprimento do controle deslizante no controle TrackBar atual.

```
int GetThumbLength() const;
```

### <a name="return-value"></a>Valor de retorno

O comprimento do controle deslizante, em pixels.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [TBM_GETTHUMBLENGTH](/windows/win32/Controls/tbm-getthumblength) , que é descrita na SDK do Windows.

##  <a name="getthumbrect"></a>  CSliderCtrl::GetThumbRect

Recupera o tamanho e a posição do retângulo delimitador do controle deslizante (Thumb) em um controle deslizante.

```
void GetThumbRect(LPRECT lprc) const;
```

### <a name="parameters"></a>Parâmetros

*lprc*<br/>
Um ponteiro para um `CRect` objeto que contém o retângulo delimitador para o controle deslizante quando a função retorna.

##  <a name="gettic"></a>  CSliderCtrl::GetTic

Recupera a posição de uma marca de escala em um controle deslizante.

```
int GetTic(int nTic) const;
```

### <a name="parameters"></a>Parâmetros

*nTic*<br/>
Índice com base em zero que identifica uma marca de escala.

### <a name="return-value"></a>Valor de retorno

A posição da marca de escala especificada ou-1 se *NTIC* não especificar um índice válido.

##  <a name="getticarray"></a>  CSliderCtrl::GetTicArray

Recupera o endereço da matriz que contém as posições das marcas de escala para um controle deslizante.

```
DWORD* GetTicArray() const;
```

### <a name="return-value"></a>Valor de retorno

O endereço da matriz que contém as posições da marca de escala para o controle deslizante.

##  <a name="getticpos"></a>  CSliderCtrl::GetTicPos

Recupera a posição física atual de uma marca de escala em um controle deslizante.

```
int GetTicPos(int nTic) const;
```

### <a name="parameters"></a>Parâmetros

*nTic*<br/>
Índice com base em zero que identifica uma marca de escala.

### <a name="return-value"></a>Valor de retorno

A posição física, em coordenadas do cliente, da marca de escala especificada ou-1 se *NTIC* não especificar um índice válido.

##  <a name="gettooltips"></a>  CSliderCtrl::GetToolTips

Recupera o identificador para o controle ToolTip atribuído ao controle Slider, se houver.

```
CToolTipCtrl* GetToolTips() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) ou NULL se as dicas de ferramentas não estiverem em uso. Se o controle deslizante não usar o estilo TBS_TOOLTIPS, o valor de retorno será NULL.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [TBM_GETTOOLTIPS](/windows/win32/Controls/tbm-gettooltips)do Win32, conforme descrito na SDK do Windows. Observe que essa função de membro retorna `CToolTipCtrl` um objeto em vez de um identificador para um controle.

Para obter uma descrição dos estilos de controle deslizante, consulte [TrackBar Control Styles](/windows/win32/Controls/trackbar-control-styles) in the SDK do Windows.

##  <a name="setbuddy"></a>CSliderCtrl:: SetBuddy

Atribui uma janela como a janela Buddy para um controle deslizante.

```
CWnd* SetBuddy(
    CWnd* pWndBuddy,
    BOOL fLocation = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pWndBuddy*<br/>
Um ponteiro para um `CWnd` objeto que será definido como o colega do controle deslizante.

*fLocation*<br/>
Valor que especifica o local no qual exibir a janela do Buddy. Esse valor pode ser um dos seguintes:

- VERDADEIRO o colega será exibido à esquerda do TrackBar se o controle TrackBar usar o estilo TBS_HORZ. Se o TrackBar usar o estilo TBS_VERT, o Buddy aparecerá acima do controle TrackBar.

- FALSO o colega será exibido à direita de TrackBar se o controle TrackBar usar o estilo TBS_HORZ. Se o TrackBar usar o estilo TBS_VERT, o colega aparecerá abaixo do controle TrackBar.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que foi atribuído anteriormente ao controle Slider nesse local.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [TBM_SETBUDDY](/windows/win32/Controls/tbm-setbuddy)do Win32, conforme descrito na SDK do Windows. Observe que essa função de membro usa ponteiros para `CWnd` objetos, em vez de identificadores de janela para seu valor de retorno e parâmetro.

Para obter uma descrição dos estilos de controle deslizante, consulte [TrackBar Control Styles](/windows/win32/Controls/trackbar-control-styles) in the SDK do Windows.

##  <a name="setlinesize"></a>  CSliderCtrl::SetLineSize

Define o tamanho da linha para um controle deslizante.

```
int SetLineSize(int nSize);
```

### <a name="parameters"></a>Parâmetros

*nSize*<br/>
O novo tamanho da linha do controle deslizante.

### <a name="return-value"></a>Valor de retorno

O tamanho da linha anterior.

### <a name="remarks"></a>Comentários

O tamanho da linha afeta o quanto o controle deslizante se move para as notificações TB_LINEUP e TB_LINEDOWN.

##  <a name="setpagesize"></a>  CSliderCtrl::SetPageSize

Define o tamanho da página para um controle deslizante.

```
int SetPageSize(int nSize);
```

### <a name="parameters"></a>Parâmetros

*nSize*<br/>
O novo tamanho de página do controle deslizante.

### <a name="return-value"></a>Valor de retorno

O tamanho da página anterior.

### <a name="remarks"></a>Comentários

O tamanho da página afeta o quanto o controle deslizante se move para as notificações TB_PAGEUP e TB_PAGEDOWN.

##  <a name="setpos"></a>  CSliderCtrl::SetPos

Define a posição atual do controle deslizante em um controle deslizante.

```
void SetPos(int nPos);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Especifica a nova posição do controle deslizante.

##  <a name="setrange"></a>  CSliderCtrl::SetRange

Define o intervalo (posições mínimas e máximas) para o controle deslizante em um controle deslizante.

```
void SetRange(
    int nMin,
    int nMax,
    BOOL bRedraw = FALSE);
```

### <a name="parameters"></a>Parâmetros

*nMin*<br/>
Posição mínima do controle deslizante.

*nMax*<br/>
Posição máxima do controle deslizante.

*bRedraw*<br/>
O sinalizador de redesenho. Se esse parâmetro for TRUE, o controle deslizante será redesenhado depois que o intervalo for definido; caso contrário, o controle deslizante não será redesenhado.

##  <a name="setrangemax"></a>  CSliderCtrl::SetRangeMax

Define o intervalo máximo para o controle deslizante em um controle deslizante.

```
void SetRangeMax(
    int nMax,
    BOOL bRedraw = FALSE);
```

### <a name="parameters"></a>Parâmetros

*nMax*<br/>
Posição máxima do controle deslizante.

*bRedraw*<br/>
O sinalizador de redesenho. Se esse parâmetro for TRUE, o controle deslizante será redesenhado depois que o intervalo for definido; caso contrário, o controle deslizante não será redesenhado.

##  <a name="setrangemin"></a>  CSliderCtrl::SetRangeMin

Define o intervalo mínimo para o controle deslizante em um controle deslizante.

```
void SetRangeMin(
    int nMin,
    BOOL bRedraw = FALSE);
```

### <a name="parameters"></a>Parâmetros

*nMin*<br/>
Posição mínima do controle deslizante.

*bRedraw*<br/>
O sinalizador de redesenho. Se esse parâmetro for TRUE, o controle deslizante será redesenhado depois que o intervalo for definido; caso contrário, o controle deslizante não será redesenhado.

##  <a name="setselection"></a>  CSliderCtrl::SetSelection

Define as posições inicial e final da seleção atual em um controle deslizante.

```
void SetSelection(
    int nMin,
    int nMax);
```

### <a name="parameters"></a>Parâmetros

*nMin*<br/>
Posição inicial do controle deslizante.

*nMax*<br/>
Posição final do controle deslizante.

##  <a name="setthumblength"></a>  CSliderCtrl::SetThumbLength

Define o comprimento do controle deslizante no controle TrackBar atual.

```
void SetThumbLength(int nLength);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nLength*|no Comprimento do controle deslizante, em pixels.|

### <a name="remarks"></a>Comentários

Esse método requer que o controle TrackBar seja definido como [TBS_FIXEDLENGTH](/windows/win32/Controls/trackbar-control-styles) Style.

Esse método envia a mensagem [TBM_SETTHUMBLENGTH](/windows/win32/Controls/tbm-setthumblength) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a `m_sliderCtrl`variável,, que é usada para acessar o controle TrackBar atual. O exemplo também define uma variável, `thumbLength`, que é usada para armazenar o comprimento padrão do componente thumb do controle TrackBar. Essas variáveis são usadas no exemplo a seguir.

[!code-cpp[NVC_MFC_CSliderCtrl_s1#1](../../mfc/reference/codesnippet/cpp/csliderctrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o componente thumb do controle TrackBar como duas vezes seu comprimento padrão.

[!code-cpp[NVC_MFC_CSliderCtrl_s1#2](../../mfc/reference/codesnippet/cpp/csliderctrl-class_2.cpp)]

##  <a name="settic"></a>  CSliderCtrl::SetTic

Define a posição de uma marca de escala em um controle deslizante.

```
BOOL SetTic(int nTic);
```

### <a name="parameters"></a>Parâmetros

*nTic*<br/>
Posição da marca de escala. Esse parâmetro deve especificar um valor positivo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a marca de escala estiver definida; caso contrário, 0.

##  <a name="setticfreq"></a>  CSliderCtrl::SetTicFreq

Define a frequência com que as marcas de escala são exibidas em um controle deslizante.

```
void SetTicFreq(int nFreq);
```

### <a name="parameters"></a>Parâmetros

*nFreq*<br/>
Frequência das marcas de escala.

### <a name="remarks"></a>Comentários

Por exemplo, se a frequência for definida como 2, uma marca de escala será exibida para cada incremento no intervalo do controle deslizante. A configuração padrão para a frequência é 1 (ou seja, cada incremento no intervalo é associado a uma marca de escala).

Você deve criar o controle com o estilo TBS_AUTOTICKS para usar essa função. Para obter mais informações, consulte [CSliderCtrl:: Create](#create).

##  <a name="settipside"></a>  CSliderCtrl::SetTipSide

Posiciona um controle ToolTip usado por um controle TrackBar.

```
int SetTipSide(int nLocation);
```

### <a name="parameters"></a>Parâmetros

*nLocation*<br/>
Valor que representa o local no qual exibir o controle ToolTip. Para obter uma lista de valores possíveis, consulte a mensagem do Win32 [TBM_SETTIPSIDE](/windows/win32/Controls/tbm-settipside), conforme descrito na SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Um valor que representa o local anterior do controle ToolTip. O valor de retorno é igual a um dos valores possíveis para *nLocal*.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem TBM_SETTIPSIDE do Win32, conforme descrito na SDK do Windows. Controles deslizantes que usam as dicas de ferramenta de exibição de estilo TBS_TOOLTIPS. Para obter uma descrição dos estilos de controle deslizante, consulte [TrackBar Control Styles](/windows/win32/Controls/trackbar-control-styles) in the SDK do Windows.

##  <a name="settooltips"></a>  CSliderCtrl::SetToolTips

Atribui um controle ToolTip a um controle Slider.

```
void SetToolTips(CToolTipCtrl* pWndTip);
```

### <a name="parameters"></a>Parâmetros

*pWndTip*<br/>
Um ponteiro para um objeto [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) que contém as dicas de ferramenta a serem usadas com o controle deslizante.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [TBM_SETTOOLTIPS](/windows/win32/Controls/tbm-settooltips)do Win32, conforme descrito na SDK do Windows. Quando um controle deslizante é criado com o estilo TBS_TOOLTIPS, ele cria um controle ToolTip padrão que aparece ao lado do controle deslizante, exibindo a posição atual do controle deslizante. Para obter uma descrição dos estilos de controle deslizante, consulte [TrackBar Control Styles](/windows/win32/Controls/trackbar-control-styles) in the SDK do Windows.

## <a name="see-also"></a>Consulte também

[Exemplo de CMNCTRL2 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CProgressCtrl](../../mfc/reference/cprogressctrl-class.md)
