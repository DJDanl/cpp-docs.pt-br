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
ms.openlocfilehash: cd0c1ed85969d50548cf6b2be1d5677ed62110bc
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502566"
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
|[CScrollBar::Create](#create)|Cria a barra de rolagem do Windows e a anexa `CScrollBar` ao objeto.|
|[CScrollBar::EnableScrollBar](#enablescrollbar)|Habilita ou desabilita uma ou ambas as setas de uma barra de rolagem.|
|[CScrollBar::GetScrollBarInfo](#getscrollbarinfo)|Recupera informações sobre a barra de rolagem `SCROLLBARINFO` usando uma estrutura.|
|[CScrollBar::GetScrollInfo](#getscrollinfo)|Recupera informações sobre a barra de rolagem.|
|[CScrollBar::GetScrollLimit](#getscrolllimit)|Recupera o limite da barra de rolagem|
|[CScrollBar::GetScrollPos](#getscrollpos)|Recupera a posição atual de uma caixa de rolagem.|
|[CScrollBar::GetScrollRange](#getscrollrange)|Recupera as posições de barra de rolagem mínima e máxima atuais para a barra de rolagem fornecida.|
|[CScrollBar::SetScrollInfo](#setscrollinfo)|Define informações sobre a barra de rolagem.|
|[CScrollBar::SetScrollPos](#setscrollpos)|Define a posição atual de uma caixa de rolagem.|
|[CScrollBar::SetScrollRange](#setscrollrange)|Define valores de posição mínimo e máximo para a barra de rolagem fornecida.|
|[CScrollBar::ShowScrollBar](#showscrollbar)|Mostra ou oculta uma barra de rolagem.|

## <a name="remarks"></a>Comentários

Você cria um controle de barra de rolagem em duas etapas. Primeiro, chame o construtor `CScrollBar` para construir o `CScrollBar` objeto e, em seguida, chame a função [criar](#create) membro para criar o controle de `CScrollBar` barra de rolagem do Windows e anexá-lo ao objeto.

Se você criar um `CScrollBar` objeto dentro de uma caixa de diálogo (por meio de um recurso `CScrollBar` de caixa de diálogo), o será automaticamente destruído quando o usuário fechar a caixa de diálogo.

Se você criar um `CScrollBar` objeto em uma janela, talvez também precise destruí-lo.

Se você criar o `CScrollBar` objeto na pilha, ele será destruído automaticamente. Se você criar o `CScrollBar` objeto no heap usando a **nova** função, deverá chamar **delete** no objeto para destruí-lo quando o usuário terminar a barra de rolagem do Windows.

Se você alocar qualquer memória no `CScrollBar` objeto, substitua o `CScrollBar` destruidor para descartar as alocações.

Para obter informações relacionadas sobre `CScrollBar`como usar o, consulte [controles](../../mfc/controls-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CScrollBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="create"></a>  CScrollBar::Create

Cria a barra de rolagem do Windows e a anexa `CScrollBar` ao objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo da barra de rolagem. Aplique qualquer combinação de [estilos de barra](../../mfc/reference/styles-used-by-mfc.md#scroll-bar-styles) de rolagem à barra de rolagem.

*rect*<br/>
Especifica o tamanho e a posição da barra de rolagem. Pode ser uma `RECT` estrutura ou um `CRect` objeto.

*pParentWnd*<br/>
Especifica a janela pai da barra de rolagem, `CDialog` geralmente um objeto. Ele não deve ser nulo.

*nID*<br/>
A ID de controle da barra de rolagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um `CScrollBar` objeto em duas etapas. Primeiro, chame o construtor, que constrói o `CScrollBar` objeto; em seguida, chame `Create`, que cria e inicializa a barra de rolagem do Windows associada e o `CScrollBar` anexa ao objeto.

Aplique os seguintes [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a uma barra de rolagem:

- WS_CHILD sempre

- WS_VISIBLE geralmente

- WS_DISABLED raramente

- WS_GROUP para controles de grupo

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CScrollBar#1](../../mfc/reference/codesnippet/cpp/cscrollbar-class_1.cpp)]

##  <a name="cscrollbar"></a>CScrollBar::CScrollBar

Constrói um objeto `CScrollBar`.

```
CScrollBar();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto, chame a `Create` função membro para criar e inicializar a barra de rolagem do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CScrollBar#2](../../mfc/reference/codesnippet/cpp/cscrollbar-class_2.h)]

##  <a name="enablescrollbar"></a>  CScrollBar::EnableScrollBar

Habilita ou desabilita uma ou ambas as setas de uma barra de rolagem.

```
BOOL EnableScrollBar(UINT nArrowFlags = ESB_ENABLE_BOTH);
```

### <a name="parameters"></a>Parâmetros

*nArrowFlags*<br/>
Especifica se as setas de rolagem estão habilitadas ou desabilitadas e quais setas estão habilitadas ou desabilitadas. Esse parâmetro pode ser um dos seguintes valores:

- ESB_ENABLE_BOTH habilita ambas as setas de uma barra de rolagem.

- ESB_DISABLE_LTUP desabilita a seta para a esquerda de uma barra de rolagem horizontal ou a seta para cima de uma barra de rolagem vertical.

- ESB_DISABLE_RTDN desabilita a seta para a direita de uma barra de rolagem horizontal ou a seta para baixo de uma barra de rolagem vertical.

- ESB_DISABLE_BOTH desabilita ambas as setas de uma barra de rolagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se as setas estiverem habilitadas ou desabilitadas conforme especificado; caso contrário, 0, que indica que as setas já estão no estado solicitado ou que ocorreu um erro.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CScrollBar:: SetScrollRange](#setscrollrange).

##  <a name="getscrollbarinfo"></a>  CScrollBar::GetScrollBarInfo

Recupera as informações que a `SCROLLBARINFO` estrutura mantém sobre uma barra de rolagem.

```
BOOL GetScrollBarInfo(PSCROLLBARINFO pScrollInfo) const;
```

### <a name="parameters"></a>Parâmetros

*pScrollInfo*<br/>
Um ponteiro para a estrutura [SCROLLBARINFO](/windows/win32/api/winuser/ns-winuser-scrollbarinfo) .

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da mensagem [SBM_SCROLLBARINFO](/windows/win32/Controls/sbm-getscrollbarinfo) , conforme descrito na SDK do Windows.

##  <a name="getscrollinfo"></a>  CScrollBar::GetScrollInfo

Recupera as informações que a `SCROLLINFO` estrutura mantém sobre uma barra de rolagem.

```
BOOL GetScrollInfo(
    LPSCROLLINFO lpScrollInfo,
    UINT nMask = SIF_ALL);
```

### <a name="parameters"></a>Parâmetros

*lpScrollInfo*<br/>
Um ponteiro para uma estrutura [SCROLLINFO](/windows/win32/api/winuser/ns-winuser-scrollinfo) . Consulte a SDK do Windows para obter mais informações sobre essa estrutura.

*nMask*<br/>
Especifica os parâmetros da barra de rolagem a serem recuperados. O uso típico, SIF_ALL, especifica uma combinação de SIF_PAGE, SIF_POS, SIF_TRACKPOS e SIF_RANGE. Consulte `SCROLLINFO` para obter mais informações sobre os valores de nMask.

### <a name="return-value"></a>Valor de retorno

Se a mensagem tiver recuperado quaisquer valores, o retorno será TRUE. Caso contrário, será FALSE.

### <a name="remarks"></a>Comentários

`GetScrollInfo`permite que os aplicativos usem as posições de rolagem de 32 bits.

A estrutura [SCROLLINFO](/windows/win32/api/winuser/ns-winuser-scrollinfo) contém informações sobre uma barra de rolagem, incluindo as posições mínima e máxima de rolagem, o tamanho da página e a posição da caixa de rolagem (o polegar). Consulte o `SCROLLINFO` tópico estrutura na SDK do Windows para obter mais informações sobre como alterar os padrões de estrutura.

Os manipuladores de mensagens do Windows do MFC que indicam a posição da barra de rolagem, [CWnd:: OnHScroll e [CWnd:: OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll), fornecem apenas 16 bits de dados de posição. `GetScrollInfo`e `SetScrollInfo` forneça 32 bits de dados de posição da barra de rolagem. Assim, um aplicativo pode chamar `GetScrollInfo` durante o `CWnd::OnHScroll` processamento ou `CWnd::OnVScroll` para obter dados de posição da barra de rolagem de 32 bits.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CWnd:: OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).

##  <a name="getscrolllimit"></a>  CScrollBar::GetScrollLimit

Recupera a posição máxima da rolagem da barra de rolagem.

```
int GetScrollLimit();
```

### <a name="return-value"></a>Valor de retorno

Especifica a posição máxima de uma barra de rolagem se for bem-sucedida; caso contrário, 0.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CWnd:: OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).

##  <a name="getscrollpos"></a>  CScrollBar::GetScrollPos

Recupera a posição atual de uma caixa de rolagem.

```
int GetScrollPos() const;
```

### <a name="return-value"></a>Valor de retorno

Especifica a posição atual da caixa de rolagem se for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A posição atual é um valor relativo que depende do intervalo de rolagem atual. Por exemplo, se o intervalo de rolagem for de 100 a 200 e a caixa de rolagem estiver no meio da barra, a posição atual será 150.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CWnd:: OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).

##  <a name="getscrollrange"></a>  CScrollBar::GetScrollRange

Copia as posições de barra de rolagem mínima e máxima atuais para a barra de rolagem fornecida para os locais especificados por *lpMinPos* e *lpMaxPos*.

```
void GetScrollRange(
    LPINT lpMinPos,
    LPINT lpMaxPos) const;
```

### <a name="parameters"></a>Parâmetros

*lpMinPos*<br/>
Aponta para a variável de inteiro que deve receber a posição mínima.

*lpMaxPos*<br/>
Aponta para a variável de inteiro que deve receber a posição máxima.

### <a name="remarks"></a>Comentários

O intervalo padrão para um controle de barra de rolagem está vazio (ambos os valores são 0).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CWnd:: OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).

##  <a name="setscrollinfo"></a>  CScrollBar::SetScrollInfo

Define as informações que a `SCROLLINFO` estrutura mantém sobre uma barra de rolagem.

```
BOOL SetScrollInfo(
    LPSCROLLINFO lpScrollInfo,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpScrollInfo*<br/>
Um ponteiro para uma estrutura [SCROLLINFO](/windows/win32/api/winuser/ns-winuser-scrollinfo) .

*bRedraw*<br/>
Especifica se a barra de rolagem deve ser redesenhada para refletir as novas informações. Se *bRedraw* for true, a barra de rolagem será redesenhada. Se for FALSE, ele não será redesenhado. A barra de rolagem é redesenhada por padrão.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o retorno será TRUE. Caso contrário, será FALSE.

### <a name="remarks"></a>Comentários

Você deve fornecer os valores exigidos pelos `SCROLLINFO` parâmetros de estrutura, incluindo os valores de sinalizador.

A `SCROLLINFO` estrutura contém informações sobre uma barra de rolagem, incluindo as posições mínima e máxima de rolagem, o tamanho da página e a posição da caixa de rolagem (o polegar). Consulte o tópico estrutura [SCROLLINFO](/windows/win32/api/winuser/ns-winuser-scrollinfo) na SDK do Windows para obter mais informações sobre como alterar os padrões de estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CScrollBar#3](../../mfc/reference/codesnippet/cpp/cscrollbar-class_3.cpp)]

##  <a name="setscrollpos"></a>  CScrollBar::SetScrollPos

Define a posição atual de uma caixa de rolagem para aquela especificada por *nPos* e, se especificado, redesenha a barra de rolagem para refletir a nova posição.

```
int SetScrollPos(
    int nPos,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Especifica a nova posição da caixa de rolagem. Ele deve estar dentro do intervalo de rolagem.

*bRedraw*<br/>
Especifica se a barra de rolagem deve ser redesenhada para refletir a nova posição. Se *bRedraw* for true, a barra de rolagem será redesenhada. Se for FALSE, ele não será redesenhado. A barra de rolagem é redesenhada por padrão.

### <a name="return-value"></a>Valor de retorno

Especifica a posição anterior da caixa de rolagem se for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Defina *bRedraw* como false sempre que a barra de rolagem for redesenhada por uma chamada subsequente para outra função para evitar que a barra de rolagem seja redesenhada duas vezes em um curto intervalo.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CScrollBar:: SetScrollRange](#setscrollrange).

##  <a name="setscrollrange"></a>  CScrollBar::SetScrollRange

Define valores de posição mínimo e máximo para a barra de rolagem fornecida.

```
void SetScrollRange(
    int nMinPos,
    int nMaxPos,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nMinPos*<br/>
Especifica a posição de rolagem mínima.

*nMaxPos*<br/>
Especifica a posição máxima da rolagem.

*bRedraw*<br/>
Especifica se a barra de rolagem deve ser redesenhada para refletir a alteração. Se *bRedraw* for true, a barra de rolagem será redesenhada; Se for FALSE, ele não será redesenhado. Ele é redesenhado por padrão.

### <a name="remarks"></a>Comentários

Defina *nMinPos* e *nMaxPos* como 0 para ocultar barras de rolagem padrão.

Não chame essa função para ocultar uma barra de rolagem durante o processamento de uma mensagem de notificação de barra de rolagem.

Se uma chamada para `SetScrollRange` imediatamente seguir uma chamada para a `SetScrollPos` `SetScrollPos` função de membro, defina *bRedraw* como 0 para impedir que a barra de rolagem seja redesenhada duas vezes.

A diferença entre os valores especificados por *nMinPos* e *nMaxPos* não deve ser maior que 32.767. O intervalo padrão para um controle de barra de rolagem está vazio ( *nMinPos* e *nMaxPos* são 0).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CScrollBar#4](../../mfc/reference/codesnippet/cpp/cscrollbar-class_4.cpp)]

##  <a name="showscrollbar"></a>  CScrollBar::ShowScrollBar

Mostra ou oculta uma barra de rolagem.

```
void ShowScrollBar(BOOL bShow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bShow*<br/>
Especifica se a barra de rolagem é mostrada ou oculta. Se esse parâmetro for TRUE, a barra de rolagem será mostrada; caso contrário, ele ficará oculto.

### <a name="remarks"></a>Comentários

Um aplicativo não deve chamar essa função para ocultar uma barra de rolagem durante o processamento de uma mensagem de notificação de barra de rolagem.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CScrollBar:: Create](#create).

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Classe CStatic](../../mfc/reference/cstatic-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
