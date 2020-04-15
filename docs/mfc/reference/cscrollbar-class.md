---
title: Classe CScrollBar
ms.date: 11/04/2016
f1_keywords:
- CScrollBar
- AFXWIN/CScrollBar
- AFXWIN/CScrollBar::CScrollBar
- AFXWIN/CScrollBar::Create
- AFXWIN/CScrollBar::EnableScrollBar
- AFXWIN/CScrollBar::GetScrollBarInfo
- AFXWIN/CScrollBar::GetScrollInfo
- AFXWIN/CScrollBar::GetScrollLimit
- AFXWIN/CScrollBar::GetScrollPos
- AFXWIN/CScrollBar::GetScrollRange
- AFXWIN/CScrollBar::SetScrollInfo
- AFXWIN/CScrollBar::SetScrollPos
- AFXWIN/CScrollBar::SetScrollRange
- AFXWIN/CScrollBar::ShowScrollBar
helpviewer_keywords:
- CScrollBar [MFC], CScrollBar
- CScrollBar [MFC], Create
- CScrollBar [MFC], EnableScrollBar
- CScrollBar [MFC], GetScrollBarInfo
- CScrollBar [MFC], GetScrollInfo
- CScrollBar [MFC], GetScrollLimit
- CScrollBar [MFC], GetScrollPos
- CScrollBar [MFC], GetScrollRange
- CScrollBar [MFC], SetScrollInfo
- CScrollBar [MFC], SetScrollPos
- CScrollBar [MFC], SetScrollRange
- CScrollBar [MFC], ShowScrollBar
ms.assetid: f3735ca5-73ea-46dc-918b-4d824c9fe47f
ms.openlocfilehash: 761d7e9db650c6d95e916c85bd7456d9b1c647c5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318528"
---
# <a name="cscrollbar-class"></a>Classe CScrollBar

Fornece a funcionalidade de um controle de barra de rolagem do Windows.

## <a name="syntax"></a>Sintaxe

```
class CScrollBar : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CScrollBar::CScrollBar](#cscrollbar)|Constrói um objeto `CScrollBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CScrollBar::Criar](#create)|Cria a barra de rolagem `CScrollBar` do Windows e a anexa ao objeto.|
|[CScrollBar::HabilitarBarra de rolagem](#enablescrollbar)|Ativa ou desativa uma ou ambas as setas de uma barra de rolagem.|
|[CScrollBar::GetScrollBarInfo](#getscrollbarinfo)|Recupera informações sobre a barra `SCROLLBARINFO` de rolagem usando uma estrutura.|
|[CScrollBar::GetScrollInfo](#getscrollinfo)|Recupera informações sobre a barra de rolagem.|
|[CScrollBar::GetScrollLimit](#getscrolllimit)|Recupera o limite da barra de rolagem|
|[CScrollBar::GetScrollPos](#getscrollpos)|Recupera a posição atual de uma caixa de rolagem.|
|[CScrollBar::GetScrollRange](#getscrollrange)|Recupera as posições atuais de barra de rolagem mínima e máxima para a barra de rolagem dada.|
|[CScrollBar::SetScrollInfo](#setscrollinfo)|Define informações sobre a barra de rolagem.|
|[CScrollBar::SetScrollPos](#setscrollpos)|Define a posição atual de uma caixa de rolagem.|
|[CScrollBar::SetScrollRange](#setscrollrange)|Define valores mínimos e máximos de posição para a barra de rolagem dada.|
|[CScrollBar::ShowScrollBar](#showscrollbar)|Mostra ou esconde uma barra de rolagem.|

## <a name="remarks"></a>Comentários

Você cria um controle de barra de rolagem em dois passos. Primeiro, chame o `CScrollBar` construtor `CScrollBar` para construir o objeto, em seguida, chame a função [Criar](#create) membro para criar o controle de barra de rolagem do Windows e anexá-lo ao `CScrollBar` objeto.

Se você `CScrollBar` criar um objeto dentro de uma `CScrollBar` caixa de diálogo (através de um recurso de diálogo), o usuário será automaticamente destruído quando o usuário fechar a caixa de diálogo.

Se você `CScrollBar` criar um objeto dentro de uma janela, você também pode precisar destruí-lo.

Se você `CScrollBar` criar o objeto na pilha, ele será destruído automaticamente. Se você `CScrollBar` criar o objeto no heap usando a **nova** função, você deve chamar **excluir** no objeto para destruí-lo quando o usuário terminar a barra de rolagem do Windows.

Se você alocar `CScrollBar` qualquer memória no `CScrollBar` objeto, anule o destruidor para descartar as alocações.

Para obter informações `CScrollBar` [relacionadas](../../mfc/controls-mfc.md)sobre o uso, consulte Controles .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CScrollBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cscrollbarcreate"></a><a name="create"></a>CScrollBar::Criar

Cria a barra de rolagem `CScrollBar` do Windows e a anexa ao objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo da barra de rolagem. Aplique qualquer combinação de [estilos de barra de rolagem](../../mfc/reference/styles-used-by-mfc.md#scroll-bar-styles) na barra de rolagem.

*Rect*<br/>
Especifica o tamanho e a posição da barra de rolagem. Pode ser `RECT` uma estrutura `CRect` ou um objeto.

*Pparentwnd*<br/>
Especifica a janela pai da barra `CDialog` de rolagem, geralmente um objeto. Não deve ser NULO.

*nID*<br/>
A barra de rolagem é a id de controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CScrollBar` um objeto em dois passos. Primeiro, chamar o construtor, que `CScrollBar` constrói o objeto; em `Create`seguida, chamar , que cria e inicializa a `CScrollBar` barra de rolagem do Windows associada e anexa-a ao objeto.

Aplique os [seguintes estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) em uma barra de rolagem:

- WS_CHILD Sempre

- WS_VISIBLE Normalmente

- WS_DISABLED raramente

- WS_GROUP Para controles de grupo

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CScrollBar#1](../../mfc/reference/codesnippet/cpp/cscrollbar-class_1.cpp)]

## <a name="cscrollbarcscrollbar"></a><a name="cscrollbar"></a>CScrollBar::CScrollBar

Constrói um objeto `CScrollBar`.

```
CScrollBar();
```

### <a name="remarks"></a>Comentários

Depois de construir o `Create` objeto, chame a função de membro para criar e inicializar a barra de rolagem do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CScrollBar#2](../../mfc/reference/codesnippet/cpp/cscrollbar-class_2.h)]

## <a name="cscrollbarenablescrollbar"></a><a name="enablescrollbar"></a>CScrollBar::HabilitarBarra de rolagem

Ativa ou desativa uma ou ambas as setas de uma barra de rolagem.

```
BOOL EnableScrollBar(UINT nArrowFlags = ESB_ENABLE_BOTH);
```

### <a name="parameters"></a>Parâmetros

*nArrowFlags*<br/>
Especifica se as setas de rolagem estão ativadas ou desativadas e quais setas estão ativadas ou desativadas. Este parâmetro pode ser um dos seguintes valores:

- ESB_ENABLE_BOTH Habilita as duas setas de uma barra de rolagem.

- ESB_DISABLE_LTUP Desativa a seta esquerda de uma barra de rolagem horizontal ou a seta para cima de uma barra de rolagem vertical.

- ESB_DISABLE_RTDN Desativa a seta direita de uma barra de rolagem horizontal ou a seta para baixo de uma barra de rolagem vertical.

- ESB_DISABLE_BOTH desativa ambas as setas de uma barra de rolagem.

### <a name="return-value"></a>Valor retornado

Não zero se as setas estiverem habilitadas ou desativadas conforme especificado; caso contrário 0, o que indica que as setas já estão no estado solicitado ou que ocorreu um erro.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CScrollBar::SetScrollRange](#setscrollrange).

## <a name="cscrollbargetscrollbarinfo"></a><a name="getscrollbarinfo"></a>CScrollBar::GetScrollBarInfo

Recupera as informações `SCROLLBARINFO` que a estrutura mantém sobre uma barra de rolagem.

```
BOOL GetScrollBarInfo(PSCROLLBARINFO pScrollInfo) const;
```

### <a name="parameters"></a>Parâmetros

*pScrollInfo*<br/>
Um ponteiro para a estrutura [SCROLLBARINFO.](/windows/win32/api/winuser/ns-winuser-scrollbarinfo)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem [SBM_SCROLLBARINFO,](/windows/win32/Controls/sbm-getscrollbarinfo) conforme descrito no SDK do Windows.

## <a name="cscrollbargetscrollinfo"></a><a name="getscrollinfo"></a>CScrollBar::GetScrollInfo

Recupera as informações `SCROLLINFO` que a estrutura mantém sobre uma barra de rolagem.

```
BOOL GetScrollInfo(
    LPSCROLLINFO lpScrollInfo,
    UINT nMask = SIF_ALL);
```

### <a name="parameters"></a>Parâmetros

*lpScrollInfo*<br/>
Um ponteiro para uma estrutura [SCROLLINFO.](/windows/win32/api/winuser/ns-winuser-scrollinfo) Consulte o Windows SDK para obter mais informações sobre essa estrutura.

*Nmask*<br/>
Especifica os parâmetros da barra de rolagem para recuperar. O uso típico, SIF_ALL, especifica uma combinação de SIF_PAGE, SIF_POS, SIF_TRACKPOS e SIF_RANGE. Consulte `SCROLLINFO` mais informações sobre os valores nMask.

### <a name="return-value"></a>Valor retornado

Se a mensagem recuperar quaisquer valores, o retorno será VERDADEIRO. Caso contrário, é FALSO.

### <a name="remarks"></a>Comentários

`GetScrollInfo`permite que os aplicativos usem posições de rolagem de 32 bits.

A estrutura [SCROLLINFO](/windows/win32/api/winuser/ns-winuser-scrollinfo) contém informações sobre uma barra de rolagem, incluindo as posições de rolagem mínima e máxima, o tamanho da página e a posição da caixa de rolagem (o polegar). Consulte `SCROLLINFO` o tópico de estrutura no SDK do Windows para obter mais informações sobre a alteração dos padrões da estrutura.

Os manipuladores de mensagens do MFC Windows que indicam a posição da barra de rolagem[CWnd::OnHScroll e [CWnd::OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll), fornecem apenas 16 bits de dados de posição. `GetScrollInfo`e `SetScrollInfo` fornecer 32 bits de dados de posição da barra de rolagem. Assim, um aplicativo `GetScrollInfo` pode ligar `CWnd::OnHScroll` `CWnd::OnVScroll` durante o processamento ou para obter dados de posição de barra de rolagem de 32 bits.

### <a name="example"></a>Exemplo

  Veja o exemplo [de CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).

## <a name="cscrollbargetscrolllimit"></a><a name="getscrolllimit"></a>CScrollBar::GetScrollLimit

Recupera a posição máxima de rolagem da barra de rolagem.

```
int GetScrollLimit();
```

### <a name="return-value"></a>Valor retornado

Especifica a posição máxima de uma barra de rolagem se for bem sucedida; caso contrário, 0.

### <a name="example"></a>Exemplo

  Veja o exemplo [de CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).

## <a name="cscrollbargetscrollpos"></a><a name="getscrollpos"></a>CScrollBar::GetScrollPos

Recupera a posição atual de uma caixa de rolagem.

```
int GetScrollPos() const;
```

### <a name="return-value"></a>Valor retornado

Especifica a posição atual da caixa de rolagem se for bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A posição atual é um valor relativo que depende da faixa de rolagem atual. Por exemplo, se a faixa de rolagem for de 100 a 200 e a caixa de rolagem estiver no meio da barra, a posição atual é de 150.

### <a name="example"></a>Exemplo

  Veja o exemplo [de CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).

## <a name="cscrollbargetscrollrange"></a><a name="getscrollrange"></a>CScrollBar::GetScrollRange

Copia as posições atuais de barra de rolagem mínima e máxima para a barra de rolagem dada para os locais especificados por *lpMinPos* e *lpMaxPos*.

```
void GetScrollRange(
    LPINT lpMinPos,
    LPINT lpMaxPos) const;
```

### <a name="parameters"></a>Parâmetros

*lpMinPos*<br/>
Aponta para a variável inteiro que deve receber a posição mínima.

*lpMaxPos*<br/>
Aponta para a variável inteiro que deve receber a posição máxima.

### <a name="remarks"></a>Comentários

O intervalo padrão para um controle de barra de rolagem está vazio (ambos os valores são 0).

### <a name="example"></a>Exemplo

  Veja o exemplo [de CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).

## <a name="cscrollbarsetscrollinfo"></a><a name="setscrollinfo"></a>CScrollBar::SetScrollInfo

Define as informações `SCROLLINFO` que a estrutura mantém sobre uma barra de rolagem.

```
BOOL SetScrollInfo(
    LPSCROLLINFO lpScrollInfo,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpScrollInfo*<br/>
Um ponteiro para uma estrutura [SCROLLINFO.](/windows/win32/api/winuser/ns-winuser-scrollinfo)

*Bredraw*<br/>
Especifica se a barra de rolagem deve ser redesenhada para refletir as novas informações. Se *bRedraw* for TRUE, a barra de rolagem será redesenhada. Se for FALSO, não será redesenhado. A barra de rolagem é redesenhada por padrão.

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, o retorno é VERDADEIRO. Caso contrário, é FALSO.

### <a name="remarks"></a>Comentários

Você deve fornecer os `SCROLLINFO` valores exigidos pelos parâmetros da estrutura, incluindo os valores da bandeira.

A `SCROLLINFO` estrutura contém informações sobre uma barra de rolagem, incluindo as posições de rolagem mínima e máxima, o tamanho da página e a posição da caixa de rolagem (o polegar). Consulte o tópico de estrutura [SCROLLINFO](/windows/win32/api/winuser/ns-winuser-scrollinfo) no SDK do Windows para obter mais informações sobre a alteração dos padrões da estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CScrollBar#3](../../mfc/reference/codesnippet/cpp/cscrollbar-class_3.cpp)]

## <a name="cscrollbarsetscrollpos"></a><a name="setscrollpos"></a>CScrollBar::SetScrollPos

Define a posição atual de uma caixa de rolagem à especificada pelos *nPos* e, se especificada, redesenha a barra de rolagem para refletir a nova posição.

```
int SetScrollPos(
    int nPos,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
Especifica a nova posição para a caixa de rolagem. Deve estar dentro da faixa de rolagem.

*Bredraw*<br/>
Especifica se a barra de rolagem deve ser redesenhada para refletir a nova posição. Se *bRedraw* for TRUE, a barra de rolagem será redesenhada. Se for FALSO, não será redesenhado. A barra de rolagem é redesenhada por padrão.

### <a name="return-value"></a>Valor retornado

Especifica a posição anterior da caixa de rolagem se for bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Defina *bRedraw* para FALSE sempre que a barra de rolagem for redesenhada por uma chamada subseqüente para outra função para evitar que a barra de rolagem seja redesenhada duas vezes em um curto intervalo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CScrollBar::SetScrollRange](#setscrollrange).

## <a name="cscrollbarsetscrollrange"></a><a name="setscrollrange"></a>CScrollBar::SetScrollRange

Define valores mínimos e máximos de posição para a barra de rolagem dada.

```
void SetScrollRange(
    int nMinPos,
    int nMaxPos,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Nminpos*<br/>
Especifica a posição mínima de rolagem.

*Nmaxpos*<br/>
Especifica a posição máxima de rolagem.

*Bredraw*<br/>
Especifica se a barra de rolagem deve ser redesenhada para refletir a alteração. Se *bRedraw* for TRUE, a barra de rolagem será redesenhada; se FALSO, não é redesenhado. É redesenhado por padrão.

### <a name="remarks"></a>Comentários

Defina *nMinPos* e *nMaxPos* a 0 para ocultar barras de rolagem padrão.

Não chame esta função para ocultar uma barra de rolagem durante o processamento de uma mensagem de notificação de barra de rolagem.

Se uma `SetScrollRange` chamada seguir imediatamente uma `SetScrollPos` chamada para a função `SetScrollPos` de membro, defina *bRedraw* em 0 para evitar que a barra de rolagem seja redesenhada duas vezes.

A diferença entre os valores especificados por *nMinPos* e *nMaxPos* não deve ser superior a 32.767. O intervalo padrão para um controle de barra de rolagem está vazio (tanto *nMinPos* quanto *nMaxPos* são 0).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CScrollBar#4](../../mfc/reference/codesnippet/cpp/cscrollbar-class_4.cpp)]

## <a name="cscrollbarshowscrollbar"></a><a name="showscrollbar"></a>CScrollBar::ShowScrollBar

Mostra ou esconde uma barra de rolagem.

```
void ShowScrollBar(BOOL bShow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
Especifica se a barra de rolagem é mostrada ou oculta. Se este parâmetro for TRUE, a barra de rolagem será mostrada; caso contrário, está escondido.

### <a name="remarks"></a>Comentários

Um aplicativo não deve chamar essa função para ocultar uma barra de rolagem durante o processamento de uma mensagem de notificação de barra de rolagem.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CScrollBar::Create](#create).

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Classe CStatic](../../mfc/reference/cstatic-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
