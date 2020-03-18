---
title: Classe CToolTipCtrl
ms.date: 11/04/2016
f1_keywords:
- CToolTipCtrl
- AFXCMN/CToolTipCtrl
- AFXCMN/CToolTipCtrl::CToolTipCtrl
- AFXCMN/CToolTipCtrl::Activate
- AFXCMN/CToolTipCtrl::AddTool
- AFXCMN/CToolTipCtrl::AdjustRect
- AFXCMN/CToolTipCtrl::Create
- AFXCMN/CToolTipCtrl::CreateEx
- AFXCMN/CToolTipCtrl::DelTool
- AFXCMN/CToolTipCtrl::GetBubbleSize
- AFXCMN/CToolTipCtrl::GetCurrentTool
- AFXCMN/CToolTipCtrl::GetDelayTime
- AFXCMN/CToolTipCtrl::GetMargin
- AFXCMN/CToolTipCtrl::GetMaxTipWidth
- AFXCMN/CToolTipCtrl::GetText
- AFXCMN/CToolTipCtrl::GetTipBkColor
- AFXCMN/CToolTipCtrl::GetTipTextColor
- AFXCMN/CToolTipCtrl::GetTitle
- AFXCMN/CToolTipCtrl::GetToolCount
- AFXCMN/CToolTipCtrl::GetToolInfo
- AFXCMN/CToolTipCtrl::HitTest
- AFXCMN/CToolTipCtrl::Pop
- AFXCMN/CToolTipCtrl::Popup
- AFXCMN/CToolTipCtrl::RelayEvent
- AFXCMN/CToolTipCtrl::SetDelayTime
- AFXCMN/CToolTipCtrl::SetMargin
- AFXCMN/CToolTipCtrl::SetMaxTipWidth
- AFXCMN/CToolTipCtrl::SetTipBkColor
- AFXCMN/CToolTipCtrl::SetTipTextColor
- AFXCMN/CToolTipCtrl::SetTitle
- AFXCMN/CToolTipCtrl::SetToolInfo
- AFXCMN/CToolTipCtrl::SetToolRect
- AFXCMN/CToolTipCtrl::SetWindowTheme
- AFXCMN/CToolTipCtrl::Update
- AFXCMN/CToolTipCtrl::UpdateTipText
helpviewer_keywords:
- CToolTipCtrl [MFC], CToolTipCtrl
- CToolTipCtrl [MFC], Activate
- CToolTipCtrl [MFC], AddTool
- CToolTipCtrl [MFC], AdjustRect
- CToolTipCtrl [MFC], Create
- CToolTipCtrl [MFC], CreateEx
- CToolTipCtrl [MFC], DelTool
- CToolTipCtrl [MFC], GetBubbleSize
- CToolTipCtrl [MFC], GetCurrentTool
- CToolTipCtrl [MFC], GetDelayTime
- CToolTipCtrl [MFC], GetMargin
- CToolTipCtrl [MFC], GetMaxTipWidth
- CToolTipCtrl [MFC], GetText
- CToolTipCtrl [MFC], GetTipBkColor
- CToolTipCtrl [MFC], GetTipTextColor
- CToolTipCtrl [MFC], GetTitle
- CToolTipCtrl [MFC], GetToolCount
- CToolTipCtrl [MFC], GetToolInfo
- CToolTipCtrl [MFC], HitTest
- CToolTipCtrl [MFC], Pop
- CToolTipCtrl [MFC], Popup
- CToolTipCtrl [MFC], RelayEvent
- CToolTipCtrl [MFC], SetDelayTime
- CToolTipCtrl [MFC], SetMargin
- CToolTipCtrl [MFC], SetMaxTipWidth
- CToolTipCtrl [MFC], SetTipBkColor
- CToolTipCtrl [MFC], SetTipTextColor
- CToolTipCtrl [MFC], SetTitle
- CToolTipCtrl [MFC], SetToolInfo
- CToolTipCtrl [MFC], SetToolRect
- CToolTipCtrl [MFC], SetWindowTheme
- CToolTipCtrl [MFC], Update
- CToolTipCtrl [MFC], UpdateTipText
ms.assetid: 8973f70c-b73a-46c7-908d-758f364b9a97
ms.openlocfilehash: bf32671eb3535de1bf072e24bc642145e87c84ee
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420900"
---
# <a name="ctooltipctrl-class"></a>Classe CToolTipCtrl

Encapsula a funcionalidade de um "controle de dica de ferramenta", uma pequena janela pop-up que exibe uma única linha de texto que descreve a finalidade de uma ferramenta em um aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CToolTipCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CToolTipCtrl::CToolTipCtrl](#ctooltipctrl)|Constrói um objeto `CToolTipCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CToolTipCtrl:: ativar](#activate)|Ativa e desativa o controle de dica de ferramenta.|
|[Ferramenta CToolTipCtrl::](#addtool)|Registra uma ferramenta com o controle de dica de ferramenta.|
|[CToolTipCtrl::AdjustRect](#adjustrect)|Converte entre o retângulo de exibição de texto de um controle de dica de ferramenta e seu retângulo de janela.|
|[CToolTipCtrl:: criar](#create)|Cria um controle de dica de ferramenta e anexa-o a um objeto `CToolTipCtrl`.|
|[CToolTipCtrl::CreateEx](#createex)|Cria um controle de dica de ferramenta com os estilos estendidos do Windows especificados e o anexa a um objeto `CToolTipCtrl`.|
|[CToolTipCtrl::D elTool](#deltool)|Remove uma ferramenta do controle de dica de ferramenta.|
|[CToolTipCtrl:: getbubbleize](#getbubblesize)|Recupera o tamanho da dica de ferramenta.|
|[CToolTipCtrl::GetCurrentTool](#getcurrenttool)|Recupera informações, como o tamanho, a posição e o texto, da janela de dica de ferramenta que o controle de dica de ferramenta atual exibe.|
|[CToolTipCtrl:: GetDelayTime](#getdelaytime)|Recupera as durações inicial, pop-up e Reexibir atualmente definidas para um controle de dica de ferramenta.|
|[CToolTipCtrl:: GetMargin](#getmargin)|Recupera as margens superior, esquerda, inferior e direita definidas para uma janela de dica de ferramenta.|
|[CToolTipCtrl::GetMaxTipWidth](#getmaxtipwidth)|Recupera a largura máxima de uma janela de dica de ferramenta.|
|[CToolTipCtrl:: gettext](#gettext)|Recupera o texto que um controle de dica de ferramenta mantém para uma ferramenta.|
|[CToolTipCtrl::GetTipBkColor](#gettipbkcolor)|Recupera a cor do plano de fundo em uma janela de dica de ferramenta.|
|[CToolTipCtrl::GetTipTextColor](#gettiptextcolor)|Recupera a cor do texto em uma janela de dica de ferramenta.|
|[CToolTipCtrl:: getTitle](#gettitle)|Recupera o título do controle de dica de ferramenta atual.|
|[CToolTipCtrl::GetToolCount](#gettoolcount)|Recupera uma contagem das ferramentas mantidas por um controle de dica de ferramenta.|
|[CToolTipCtrl::GetToolInfo](#gettoolinfo)|Recupera as informações que um controle de dica de ferramenta mantém sobre uma ferramenta.|
|[CToolTipCtrl:: HitTest](#hittest)|Testa um ponto para determinar se ele está dentro do retângulo delimitador da ferramenta especificada. Nesse caso, o recupera informações sobre a ferramenta.|
|[CToolTipCtrl::P op](#pop)|Remove da exibição uma janela de dica de ferramenta exibida.|
|[CToolTipCtrl::P opup](#popup)|Faz com que o controle de dica de ferramenta atual seja exibido nas coordenadas da última mensagem do mouse.|
|[CToolTipCtrl::RelayEvent](#relayevent)|Passa uma mensagem do mouse para um controle de dica de ferramenta para processamento.|
|[CToolTipCtrl:: SetDelayTime](#setdelaytime)|Define as durações inicial, pop-up e Reexibir para um controle de dica de ferramenta.|
|[CToolTipCtrl:: SetMargin](#setmargin)|Define as margens superior, esquerda, inferior e direita de uma janela de dica de ferramenta.|
|[CToolTipCtrl::SetMaxTipWidth](#setmaxtipwidth)|Define a largura máxima para uma janela de dica de ferramenta.|
|[CToolTipCtrl::SetTipBkColor](#settipbkcolor)|Define a cor do plano de fundo em uma janela de dica de ferramenta.|
|[CToolTipCtrl::SetTipTextColor](#settiptextcolor)|Define a cor do texto em uma janela de dica de ferramenta.|
|[CToolTipCtrl:: SetTitle](#settitle)|Adiciona um ícone padrão e uma cadeia de caracteres de título a uma dica de ferramenta.|
|[CToolTipCtrl::SetToolInfo](#settoolinfo)|Define as informações que uma dica de ferramenta mantém para uma ferramenta.|
|[CToolTipCtrl::SetToolRect](#settoolrect)|Define um novo retângulo delimitador para uma ferramenta.|
|[CToolTipCtrl:: SetWindowTheme](#setwindowtheme)|Define o estilo visual da janela de dica de ferramenta.|
|[CToolTipCtrl:: atualizar](#update)|Força a ferramenta atual a ser redesenhada.|
|[CToolTipCtrl::UpdateTipText](#updatetiptext)|Define o texto da dica de ferramenta para uma ferramenta.|

## <a name="remarks"></a>Comentários

Uma "ferramenta" é uma janela, como uma janela ou controle filho, ou uma área retangular definida pelo aplicativo dentro da área do cliente da janela. Uma dica de ferramenta é oculta na maior parte do tempo, aparecendo somente quando o usuário coloca o cursor em uma ferramenta e a deixa lá por aproximadamente um meio segundo. A dica de ferramenta aparece perto do cursor e desaparece quando o usuário clica em um botão do mouse ou move o cursor para fora da ferramenta.

`CToolTipCtrl` fornece a funcionalidade para controlar a hora inicial e a duração da dica de ferramenta, as larguras da margem ao redor do texto da dica de ferramenta, a largura da própria janela da dica de ferramenta e a cor do plano de fundo e do texto da dica de ferramenta. Um único controle de dica de ferramenta pode fornecer informações para mais de uma ferramenta.

A classe `CToolTipCtrl` fornece a funcionalidade do controle de dica de ferramenta comum do Windows. Esse controle (e, portanto, a classe `CToolTipCtrl`) está disponível somente para programas em execução no Windows 95/98 e no Windows NT versões 3,51 e posteriores.

Para obter mais informações sobre como habilitar dicas de ferramentas, consulte [dicas de ferramenta no Windows não derivadas de CFrameWnd](../../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md).

Para obter mais informações sobre como usar `CToolTipCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CToolTipCtrl](../../mfc/using-ctooltipctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CToolTipCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="activate"></a>CToolTipCtrl:: ativar

Chame essa função para ativar ou desativar um controle de dica de ferramenta.

```
void Activate(BOOL bActivate);
```

### <a name="parameters"></a>parâmetros

*bActivate*<br/>
Especifica se o controle de dica de ferramenta deve ser ativado ou desativado.

### <a name="remarks"></a>Comentários

Se *bActivate* for true, o controle será ativado; Se for FALSE, ele será desativado.

Quando um controle de dica de ferramenta está ativo, as informações da dica de ferramenta são exibidas quando o cursor está em uma ferramenta que é registrada com o controle; Quando ela estiver inativa, as informações da dica de ferramenta não serão exibidas, mesmo quando o cursor estiver em uma ferramenta.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CPropertySheet:: GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

##  <a name="addtool"></a>Ferramenta CToolTipCtrl::

Registra uma ferramenta com o controle de dica de ferramenta.

```
BOOL AddTool(
    CWnd* pWnd,
    UINT nIDText,
    LPCRECT lpRectTool = NULL,
    UINT_PTR nIDTool = 0);

BOOL AddTool(
    CWnd* pWnd,
    LPCTSTR lpszText = LPSTR_TEXTCALLBACK,
    LPCRECT lpRectTool = NULL,
    UINT_PTR nIDTool = 0);
```

### <a name="parameters"></a>parâmetros

*pWnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*nIDText*<br/>
ID do recurso de cadeia de caracteres que contém o texto para a ferramenta.

*lpRectTool*<br/>
Ponteiro para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que contém coordenadas do retângulo delimitador da ferramenta. As coordenadas são relativas ao canto superior esquerdo da área do cliente da janela identificada por *pWnd*.

*nIDTool*<br/>
ID da ferramenta.

*lpszText*<br/>
Ponteiro para o texto da ferramenta. Se esse parâmetro contiver o valor LPSTR_TEXTCALLBACK, TTN_NEEDTEXT mensagens de notificação irão para o pai da janela para a qual *pWnd* aponta.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os parâmetros *lpRectTool* e *nIDTool* devem ser válidos ou, se *lpRectTool* for nulo, *nIDTool* deverá ser 0.

Um controle de dica de ferramenta pode ser associado a mais de uma ferramenta. Chame essa função para registrar uma ferramenta com o controle de dica de ferramenta, para que as informações armazenadas na dica de ferramenta sejam exibidas quando o cursor estiver na ferramenta.

> [!NOTE]
>  Não é possível definir uma dica de ferramenta para um controle estático usando `AddTool`.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CPropertySheet:: GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

##  <a name="adjustrect"></a>CToolTipCtrl::AdjustRect

Converte entre o retângulo de exibição de texto de um controle de dica de ferramenta e seu retângulo de janela.

```
BOOL AdjustRect(
    LPRECT lprc,
    BOOL bLarger = TRUE);
```

### <a name="parameters"></a>parâmetros

*lprc*<br/>
Ponteiro para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que contém um retângulo de janela de dica de ferramenta ou um retângulo de exibição de texto.

*bLarger*<br/>
Se for TRUE, *lprc* será usado para especificar um retângulo de exibição de texto e receberá o retângulo de janela correspondente. Se for FALSE, *lprc* será usado para especificar um retângulo de janela e receberá o retângulo de exibição de texto correspondente.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o retângulo for ajustado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro calcula o retângulo de exibição de texto de um controle de dica de ferramenta de seu retângulo de janela ou o retângulo de janela de dica de ferramenta necessário para exibir um retângulo de exibição de texto especificado.

Essa função de membro implementa o comportamento do [TTM_ADJUSTRECT](/windows/win32/Controls/ttm-adjustrect)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="create"></a>CToolTipCtrl:: criar

Cria um controle de dica de ferramenta e anexa-o a um objeto `CToolTipCtrl`.

```
virtual BOOL Create(CWnd* pParentWnd, DWORD dwStyle = 0);
```

### <a name="parameters"></a>parâmetros

*pParentWnd*<br/>
Especifica a janela pai do controle de dica de ferramenta, geralmente um `CDialog`. Ele não deve ser nulo.

*dwStyle*<br/>
Especifica o estilo do controle de dica de ferramenta. Consulte a seção **comentários** para obter mais informações.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto de `CToolTipCtrl` for criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói uma `CToolTipCtrl` em duas etapas. Primeiro, chame o construtor para construir o objeto `CToolTipCtrl` e, em seguida, chame `Create` para criar o controle de dica de ferramenta e anexá-lo ao objeto `CToolTipCtrl`.

O parâmetro *dwStyle* pode ser qualquer combinação de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles). Além disso, um controle de dica de ferramenta tem dois estilos específicos de classe: TTS_ALWAYSTIP e TTS_NOPREFIX.

|Estilo|Significado|
|-----------|-------------|
|TTS_ALWAYSTIP|Especifica que a dica de ferramenta aparecerá quando o cursor estiver em uma ferramenta, independentemente de a janela do proprietário do controle de dica de ferramenta estar ativa ou inativa. Sem esse estilo, o controle de dica de ferramenta aparece quando a janela do proprietário da ferramenta está ativa, mas não quando está inativa.|
|TTS_NOPREFIX|Esse estilo impede que o sistema retirasse o caractere de e comercial (&) de uma cadeia de caracteres. Se um controle de dica de ferramenta não tiver o estilo de TTS_NOPREFIX, o sistema retira automaticamente os caracteres de e comercial, permitindo que um aplicativo use a mesma cadeia de caracteres como um item de menu e como texto em um controle de dica de ferramenta.|

Um controle de dica de ferramenta tem os estilos de janela WS_POPUP e WS_EX_TOOLWINDOW, independentemente de você especificá-los ao criar o controle.

Para criar um controle de dica de ferramenta com estilos estendidos do Windows, chame [CToolTipCtrl:: CreateEx](#createex) em vez de `Create`.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CPropertySheet:: GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

##  <a name="createex"></a>CToolTipCtrl::CreateEx

Cria um controle (uma janela filho) e o associa ao objeto `CToolTipCtrl`.

```
virtual BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwStyle = 0,
    DWORD dwStyleEx = 0);
```

### <a name="parameters"></a>parâmetros

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*dwStyle*<br/>
Especifica o estilo do controle de dica de ferramenta. Consulte a seção **comentários** de [criar](#create) para obter mais informações.

*dwStyleEx*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de `Create` para aplicar estilos estendidos do Windows, especificados pelo **WS_EX_** de prefácio de estilo estendido do Windows.

##  <a name="ctooltipctrl"></a>CToolTipCtrl::CToolTipCtrl

Constrói um objeto `CToolTipCtrl`.

```
CToolTipCtrl();
```

### <a name="remarks"></a>Comentários

Você deve chamar `Create` depois de construir o objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#74](../../mfc/codesnippet/cpp/ctooltipctrl-class_1.h)]

##  <a name="deltool"></a>CToolTipCtrl::D elTool

Remove a ferramenta especificada por *pWnd* e *nIDTool* da coleção de ferramentas com suporte de um controle de dica de ferramenta.

```
void DelTool(
    CWnd* pWnd,
    UINT_PTR nIDTool = 0);
```

### <a name="parameters"></a>parâmetros

*pWnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*nIDTool*<br/>
ID da ferramenta.

##  <a name="getbubblesize"></a>CToolTipCtrl:: getbubbleize

Recupera o tamanho da dica de ferramenta.

```
CSize GetBubbleSize(LPTOOLINFO lpToolInfo) const;
```

### <a name="parameters"></a>parâmetros

*lpToolInfo*<br/>
Um ponteiro para a estrutura [TOOLINFO](/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) da dica de ferramenta.

### <a name="return-value"></a>Valor retornado

O tamanho da dica de ferramenta.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_GETBUBBLESIZE](/windows/win32/Controls/ttm-getbubblesize)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="getcurrenttool"></a>CToolTipCtrl::GetCurrentTool

Recupera informações, como o tamanho, a posição e o texto, da janela de dica de ferramenta exibida pelo controle ToolTip atual.

```
BOOL GetCurrentTool(LPTOOLINFO lpToolInfo) const;
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*lpToolInfo*|fora Ponteiro para uma estrutura [TOOLINFO](/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) que recebe informações sobre a janela de dica de ferramenta atual.|

### <a name="return-value"></a>Valor retornado

TRUE se as informações forem recuperadas com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [TTM_GETCURRENTTOOL](/windows/win32/Controls/ttm-getcurrenttool) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera informações sobre a janela de dica de ferramenta atual.

[!code-cpp[NVC_MFC_CToolBarCtrl_s1#6](../../mfc/reference/codesnippet/cpp/ctooltipctrl-class_2.cpp)]

##  <a name="getdelaytime"></a>CToolTipCtrl:: GetDelayTime

Recupera as durações inicial, pop-up e remostrar atualmente definidas para um controle de dica de ferramenta.

```
int GetDelayTime(DWORD dwDuration) const;
```

### <a name="parameters"></a>parâmetros

*dwDuration*<br/>
Sinalizador que especifica qual valor de duração será recuperado. Esse parâmetro pode ser um dos seguintes valores:

- TTDT_AUTOPOP recuperar o período de tempo que a janela de dica de ferramenta permanecerá visível se o ponteiro for estático dentro do retângulo delimitador de uma ferramenta.

- TTDT_INITIAL recuperar o período de tempo que o ponteiro deve permanecer fixo dentro do retângulo delimitador de uma ferramenta antes que a janela de dica de ferramenta seja exibida.

- TTDT_RESHOW recuperar o período de tempo que leva para que janelas de dica de ferramenta subsequentes apareçam à medida que o ponteiro se move de uma ferramenta para outra.

### <a name="return-value"></a>Valor retornado

O tempo de atraso especificado, em milissegundos

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_GETDELAYTIME](/windows/win32/Controls/ttm-getdelaytime)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="getmargin"></a>CToolTipCtrl:: GetMargin

Recupera as margens superior, esquerda, inferior e direita definidas para uma janela de dica de ferramenta.

```
void GetMargin(LPRECT lprc) const;
```

### <a name="parameters"></a>parâmetros

*lprc*<br/>
Endereço de uma estrutura de `RECT` que receberá as informações de margem. Os membros da estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) não definem um retângulo delimitador. Para fins desta mensagem, os membros da estrutura são interpretados da seguinte maneira:

|Membro|Representação|
|------------|--------------------|
|`top`|Distância entre a borda superior e a parte superior do texto da dica de ferramenta, em pixels.|
|`left`|Distância entre a borda esquerda e a extremidade esquerda do texto da dica, em pixels.|
|`bottom`|Distância entre a borda inferior e a parte inferior do texto da dica, em pixels.|
|`right`|Distância entre a borda direita e a extremidade direita do texto da dica, em pixels.|

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_GETMARGIN](/windows/win32/Controls/ttm-getmargin)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="getmaxtipwidth"></a>CToolTipCtrl::GetMaxTipWidth

Recupera a largura máxima de uma janela de dica de ferramenta.

```
int GetMaxTipWidth() const;
```

### <a name="return-value"></a>Valor retornado

A largura máxima para uma janela de dica de ferramenta.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_GETMAXTIPWIDTH](/windows/win32/Controls/ttm-getmaxtipwidth)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="gettext"></a>CToolTipCtrl:: gettext

Recupera o texto que um controle de dica de ferramenta mantém para uma ferramenta.

```
void GetText(
    CString& str,
    CWnd* pWnd,
    UINT_PTR nIDTool = 0) const;
```

### <a name="parameters"></a>parâmetros

*str*<br/>
Referência a um objeto `CString` que recebe o texto da ferramenta.

*pWnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*nIDTool*<br/>
ID da ferramenta.

### <a name="remarks"></a>Comentários

Os parâmetros *pWnd* e *nIDTool* identificam a ferramenta. Se essa ferramenta tiver sido registrada anteriormente com o controle de dica de ferramenta por meio de uma chamada anterior para `CToolTipCtrl::AddTool`, o objeto referenciado pelo parâmetro *Str* será atribuído ao texto da ferramenta.

##  <a name="gettipbkcolor"></a>CToolTipCtrl::GetTipBkColor

Recupera a cor do plano de fundo em uma janela de dica de ferramenta.

```
COLORREF GetTipBkColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor [COLORREF](/windows/win32/gdi/colorref) que representa a cor do plano de fundo.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_GETTIPBKCOLOR](/windows/win32/Controls/ttm-gettipbkcolor)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="gettiptextcolor"></a>CToolTipCtrl::GetTipTextColor

Recupera a cor do texto em uma janela de dica de ferramenta.

```
COLORREF GetTipTextColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor [COLORREF](/windows/win32/gdi/colorref) que representa a cor do texto.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_GETTIPTEXTCOLOR](/windows/win32/Controls/ttm-gettiptextcolor)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="gettitle"></a>CToolTipCtrl:: getTitle

Recupera o título do controle de dica de ferramenta atual.

```
void GetTitle(PTTGETTITLE pttgt) const;
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*pttgt*|fora Ponteiro para uma estrutura [TTGETTITLE](/windows/win32/api/commctrl/ns-commctrl-ttgettitle) que contém informações sobre o controle ToolTip. Quando esse método retorna, o membro *pszTitle* da estrutura [TTGETTITLE](/windows/win32/api/commctrl/ns-commctrl-ttgettitle) aponta para o texto do título.|

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [TTM_GETTITLE](/windows/win32/Controls/ttm-gettitle) , que é descrita na SDK do Windows.

##  <a name="gettoolcount"></a>CToolTipCtrl::GetToolCount

Recupera uma contagem das ferramentas registradas com o controle de dica de ferramenta.

```
int GetToolCount() const;
```

### <a name="return-value"></a>Valor retornado

Uma contagem de ferramentas registradas com o controle de dica de ferramenta.

##  <a name="gettoolinfo"></a>CToolTipCtrl::GetToolInfo

Recupera as informações que um controle de dica de ferramenta mantém sobre uma ferramenta.

```
BOOL GetToolInfo(
    CToolInfo& ToolInfo,
    CWnd* pWnd,
    UINT_PTR nIDTool = 0) const;
```

### <a name="parameters"></a>parâmetros

*ToolInfo*<br/>
Referência a um objeto `TOOLINFO` que recebe o texto da ferramenta.

*pWnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*nIDTool*<br/>
ID da ferramenta.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os membros `hwnd` e `uId` da estrutura [TOOLINFO](/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) referenciados por *CToolInfo* identificam a ferramenta. Se essa ferramenta tiver sido registrada com o controle de dica de ferramenta por meio de uma chamada anterior para `AddTool`, a estrutura de `TOOLINFO` será preenchida com informações sobre a ferramenta.

##  <a name="hittest"></a>CToolTipCtrl:: HitTest

Testa um ponto para determinar se ele está dentro do retângulo delimitador da determinada ferramenta e, nesse caso, recuperar informações sobre a ferramenta.

```
BOOL HitTest(
    CWnd* pWnd,
    CPoint pt,
    LPTOOLINFO lpToolInfo) const;
```

### <a name="parameters"></a>parâmetros

*pWnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*pt*<br/>
Ponteiro para um objeto de `CPoint` que contém as coordenadas do ponto a ser testado.

*lpToolInfo*<br/>
Ponteiro para a estrutura [TOOLINFO](/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) que contém informações sobre a ferramenta.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o ponto especificado pelas informações do teste de clique estiver dentro do retângulo delimitador da ferramenta; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se essa função retornar um valor diferente de zero, a estrutura apontada por *lpToolInfo* será preenchida com informações sobre a ferramenta dentro de um retângulo no qual o ponto está.

A estrutura de `TTHITTESTINFO` é definida da seguinte maneira:

```cpp
typedef struct _TT_HITTESTINFO { // tthti
    HWND hwnd;   // handle of tool or window with tool
    POINT pt;    // client coordinates of point to test
    TOOLINFO ti; // receives information about the tool
} TTHITTESTINFO, FAR * LPHITTESTINFO;
```

- `hwnd`

   Especifica o identificador da ferramenta.

- `pt`

   Especifica as coordenadas de um ponto se o ponto estiver no retângulo delimitador da ferramenta.

- `ti`

   Informações sobre a ferramenta. Para obter mais informações sobre a estrutura de `TOOLINFO`, consulte [CToolTipCtrl:: GetToolInfo](#gettoolinfo).

##  <a name="pop"></a>CToolTipCtrl::P op

Remove uma janela de dica de ferramenta exibida do modo de exibição.

```
void Pop();
```

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_POP](/windows/win32/Controls/ttm-pop)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="popup"></a>CToolTipCtrl::P opup

Faz com que o controle de dica de ferramenta atual seja exibido nas coordenadas da última mensagem do mouse.

```
void Popup();
```

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [TTM_POPUP](/windows/win32/Controls/ttm-popup) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir exibe uma janela de dica de ferramenta.

[!code-cpp[NVC_MFC_CToolBarCtrl_s1#7](../../mfc/reference/codesnippet/cpp/ctooltipctrl-class_3.cpp)]

##  <a name="relayevent"></a>CToolTipCtrl::RelayEvent

Passa uma mensagem do mouse para um controle de dica de ferramenta para processamento.

```
void RelayEvent(LPMSG lpMsg);
```

### <a name="parameters"></a>parâmetros

*lpMsg*<br/>
Ponteiro para uma estrutura de [msg](/windows/win32/api/winuser/ns-winuser-msg) que contém a mensagem a ser retransmitida.

### <a name="remarks"></a>Comentários

Um controle de dica de ferramenta processa apenas as seguintes mensagens, que são enviadas a ela por `RelayEvent`:

|WM_LBUTTONDOWN|WM_MOUSEMOVE|
|---------------------|-------------------|
|WM_LBUTTONUP|WM_RBUTTONDOWN|
|WM_MBUTTONDOWN|WM_RBUTTONUP|
|WM_MBUTTONUP||

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CPropertySheet:: GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

##  <a name="setdelaytime"></a>CToolTipCtrl:: SetDelayTime

Define o tempo de atraso para um controle de dica de ferramenta.

```
void SetDelayTime(UINT nDelay);

void SetDelayTime(
    DWORD dwDuration,
    int iTime);
```

### <a name="parameters"></a>parâmetros

*nDelay*<br/>
Especifica o novo tempo de atraso, em milissegundos.

*dwDuration*<br/>
Sinalizador que especifica qual valor de duração será recuperado. Consulte [CToolTipCtrl:: GetDelayTime](#getdelaytime) para obter uma descrição dos valores válidos.

*iTime*<br/>
O tempo de atraso especificado, em milissegundos.

### <a name="remarks"></a>Comentários

O tempo de atraso é o período de tempo que o cursor deve permanecer em uma ferramenta antes que a janela de dica de ferramenta seja exibida. O tempo de atraso padrão é de 500 milissegundos.

##  <a name="setmargin"></a>CToolTipCtrl:: SetMargin

Define as margens superior, esquerda, inferior e direita de uma janela de dica de ferramenta.

```
void SetMargin(LPRECT lprc);
```

### <a name="parameters"></a>parâmetros

*lprc*<br/>
Endereço de uma estrutura de `RECT` que contém as informações de margem a serem definidas. Os membros da estrutura de `RECT` não definem um retângulo delimitador. Consulte [CToolTipCtrl:: GetMargin](#getmargin) para obter uma descrição das informações de margem.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_SETMARGIN](/windows/win32/Controls/ttm-setmargin)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="setmaxtipwidth"></a>CToolTipCtrl::SetMaxTipWidth

Define a largura máxima para uma janela de dica de ferramenta.

```
int SetMaxTipWidth(int iWidth);
```

### <a name="parameters"></a>parâmetros

*iWidth*<br/>
A largura máxima da janela da dica de ferramenta a ser definida.

### <a name="return-value"></a>Valor retornado

A largura máxima de gorjeta anterior.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_SETMAXTIPWIDTH](/windows/win32/Controls/ttm-setmaxtipwidth)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="settipbkcolor"></a>CToolTipCtrl::SetTipBkColor

Define a cor do plano de fundo em uma janela de dica de ferramenta.

```
void SetTipBkColor(COLORREF clr);
```

### <a name="parameters"></a>parâmetros

*CLR*<br/>
A nova cor do plano de fundo.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_SETTIPBKCOLOR](/windows/win32/Controls/ttm-settipbkcolor)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="settiptextcolor"></a>CToolTipCtrl::SetTipTextColor

Define a cor do texto em uma janela de dica de ferramenta.

```
void SetTipTextColor(COLORREF clr);
```

### <a name="parameters"></a>parâmetros

*CLR*<br/>
A nova cor do texto.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_SETTIPTEXTCOLOR](/windows/win32/Controls/ttm-settiptextcolor)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="settitle"></a>CToolTipCtrl:: SetTitle

Adiciona um ícone padrão e uma cadeia de caracteres de título a uma dica de ferramenta.

```
BOOL SetTitle(
    UINT uIcon,
    LPCTSTR lpstrTitle);
```

### <a name="parameters"></a>parâmetros

*uIcon*<br/>
Consulte o *ícone* em [TTM_SETTITLE](/windows/win32/Controls/ttm-settitle) na SDK do Windows.

*lpstrTitle*<br/>
Ponteiro para a cadeia de caracteres de título.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TTM_SETTITLE](/windows/win32/Controls/ttm-settitle)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="settoolinfo"></a>CToolTipCtrl::SetToolInfo

Define as informações que uma dica de ferramenta mantém para uma ferramenta.

```
void SetToolInfo(LPTOOLINFO lpToolInfo);
```

### <a name="parameters"></a>parâmetros

*lpToolInfo*<br/>
Um ponteiro para uma estrutura [TOOLINFO](/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) que especifica as informações a serem definidas.

##  <a name="settoolrect"></a>CToolTipCtrl::SetToolRect

Define um novo retângulo delimitador para uma ferramenta.

```
void SetToolRect(
    CWnd* pWnd,
    UINT_PTR nIDTool,
    LPCRECT lpRect);
```

### <a name="parameters"></a>parâmetros

*pWnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*nIDTool*<br/>
ID da ferramenta.

*lpRect*<br/>
Ponteiro para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que especifica o novo retângulo delimitador.

##  <a name="setwindowtheme"></a>CToolTipCtrl:: SetWindowTheme

Define o estilo visual da janela de dica de ferramenta.

```
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

### <a name="parameters"></a>parâmetros

*pszSubAppName*<br/>
Um ponteiro para uma cadeia de caracteres Unicode que contém o estilo visual a ser definido.

### <a name="return-value"></a>Valor retornado

O valor de retorno não é usado.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da [TTM_SETWINDOWTHEME](/windows/win32/Controls/ttm-setwindowtheme) mensagem, conforme descrito na SDK do Windows.

##  <a name="update"></a>CToolTipCtrl:: atualizar

Força a ferramenta atual a ser redesenhada.

```
void Update();
```

##  <a name="updatetiptext"></a>CToolTipCtrl::UpdateTipText

Atualiza o texto da dica de ferramenta para as ferramentas deste controle.

```
void UpdateTipText(
    LPCTSTR lpszText,
    CWnd* pWnd,
    UINT_PTR nIDTool = 0);

void UpdateTipText(
    UINT nIDText,
    CWnd* pWnd,
    UINT_PTR nIDTool = 0);
```

### <a name="parameters"></a>parâmetros

*lpszText*<br/>
Ponteiro para o texto da ferramenta.

*pWnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*nIDTool*<br/>
ID da ferramenta.

*nIDText*<br/>
ID do recurso de cadeia de caracteres que contém o texto para a ferramenta.

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CToolBar](../../mfc/reference/ctoolbar-class.md)
