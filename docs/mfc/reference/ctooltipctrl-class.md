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
ms.openlocfilehash: 53a5a5b6871680f9758d140174dcceae6c53f568
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752191"
---
# <a name="ctooltipctrl-class"></a>Classe CToolTipCtrl

Encapsula a funcionalidade de um "controle de ponta de ferramenta", uma pequena janela pop-up que exibe uma única linha de texto descrevendo o propósito de uma ferramenta em um aplicativo.

## <a name="syntax"></a>Sintaxe

```
class CToolTipCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CToolTipCtrl::CToolTipCtrl](#ctooltipctrl)|Constrói um objeto `CToolTipCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CToolTipCtrl::Ativar](#activate)|Ativa e desativa o controle de ponta da ferramenta.|
|[CToolTipCtrl::AddTool](#addtool)|Registra uma ferramenta com o controle de ponta da ferramenta.|
|[CToolTipCtrl::AdjustRect](#adjustrect)|Converte-se entre o retângulo de exibição de texto do controle de ponta da ferramenta e o retângulo da janela.|
|[CToolTipCtrl::Criar](#create)|Cria um controle de ponta de `CToolTipCtrl` ferramenta e o prende a um objeto.|
|[CToolTipCtrl::CreateEx](#createex)|Cria um controle de ponta de ferramenta com os `CToolTipCtrl` estilos estendidos do Windows especificados e o anexa a um objeto.|
|[CToolTipCtrl::DelTool](#deltool)|Remove uma ferramenta do controle de ponta da ferramenta.|
|[CToolTipCtrl::GetBubbleSize](#getbubblesize)|Recupera o tamanho da ponta da ferramenta.|
|[CToolTipCtrl::GetCurrentTool](#getcurrenttool)|Recupera informações, como tamanho, posição e texto, da janela de dica de ferramenta que o controle atual da dica de ferramenta exibe.|
|[CToolTipCtrl::GetDelayTime](#getdelaytime)|Recupera as durações iniciais, pop-up e reshow que estão atualmente definidas para um controle de ponta de ferramenta.|
|[CToolTipCtrl::GetMargin](#getmargin)|Recupera as margens superior, esquerda, inferior e direita que estão definidas para uma janela de ponta de ferramenta.|
|[CToolTipCtrl::GetMaxTipWidth](#getmaxtipwidth)|Recupera a largura máxima para uma janela de ponta de ferramenta.|
|[CToolTipCtrl::GetText](#gettext)|Recupera o texto que um controle de ponta de ferramenta mantém para uma ferramenta.|
|[CToolTipCtrl::GetTipBkColor](#gettipbkcolor)|Recupera a cor de fundo em uma janela de ponta de ferramenta.|
|[CToolTipCtrl::GetTipTextColor](#gettiptextcolor)|Recupera a cor do texto em uma janela de ponta de ferramenta.|
|[CToolTipCtrl::GetTitle](#gettitle)|Recupera o título do controle atual da ponta de ferramenta.|
|[CToolTipCtrl::GetToolCount](#gettoolcount)|Recupera uma contagem das ferramentas mantidas por um controle de ponta de ferramenta.|
|[CToolTipCtrl::GetToolInfo](#gettoolinfo)|Recupera as informações que um controle de ponta de ferramenta mantém sobre uma ferramenta.|
|[CToolTipCtrl::HitTest](#hittest)|Teste um ponto para determinar se está dentro do retângulo delimitador da ferramenta dada. Se assim for, recupera informações sobre a ferramenta.|
|[CToolTipCtrl::Pop](#pop)|Remove uma janela de ponta de ferramenta exibida da vista.|
|[CToolTipCtrl::Popup](#popup)|Faz com que o controle ToolTip atual seja exibido nas coordenadas da última mensagem do mouse.|
|[CToolTipCtrl::RelayEvent](#relayevent)|Passa uma mensagem de mouse para um controle de ponta de ferramenta para processamento.|
|[CToolTipCtrl::SetDelayTime](#setdelaytime)|Define as durações iniciais, pop-up e reshow para um controle de ponta de ferramenta.|
|[CToolTipCtrl::SetMargin](#setmargin)|Coloque as margens superior, esquerda, inferior e direita para uma janela de ponta de ferramenta.|
|[CToolTipCtrl::SetMaxTipWidth](#setmaxtipwidth)|Define a largura máxima para uma janela de ponta de ferramenta.|
|[CToolTipCtrl::SetTipBkColor](#settipbkcolor)|Define a cor de fundo em uma janela de ponta de ferramenta.|
|[CToolTipCtrl::SetTipTextColor](#settiptextcolor)|Define a cor do texto em uma janela de ponta de ferramenta.|
|[CToolTipCtrl::SetTitle](#settitle)|Adiciona um ícone padrão e uma seqüência de títulos a uma dica de ferramenta.|
|[CToolTipCtrl::SetToolInfo](#settoolinfo)|Define as informações que uma dica de ferramenta mantém para uma ferramenta.|
|[CToolTipCtrl::SetToolRect](#settoolrect)|Define um novo retângulo delimitador para uma ferramenta.|
|[CToolTipCtrl::SetWindowTheme](#setwindowtheme)|Define o estilo visual da janela de ponta da ferramenta.|
|[CToolTipCtrl::Atualização](#update)|Força a ferramenta atual a ser redesenhada.|
|[CToolTipCtrl::UpdateTipText](#updatetiptext)|Define o texto da ponta da ferramenta como uma ferramenta.|

## <a name="remarks"></a>Comentários

Uma "ferramenta" é uma janela, como uma janela ou controle de crianças, ou uma área retangular definida por aplicativo dentro da área cliente de uma janela. Uma dica de ferramenta fica escondida na maior parte do tempo, aparecendo apenas quando o usuário coloca o cursor em uma ferramenta e o deixa lá por aproximadamente meio segundo. A ponta da ferramenta aparece perto do cursor e desaparece quando o usuário clica em um botão do mouse ou move o cursor para fora da ferramenta.

`CToolTipCtrl`fornece a funcionalidade para controlar o tempo inicial e a duração da ponta da ferramenta, as larguras de margem ao redor do texto da ponta da ferramenta, a largura da própria janela da ponta da ferramenta e a cor de fundo e texto da ponta da ferramenta. Um único controle de ponta de ferramenta pode fornecer informações para mais de uma ferramenta.

A `CToolTipCtrl` classe fornece a funcionalidade do controle de ponta de ferramenta comum do Windows. Este controle (e, `CToolTipCtrl` portanto, a classe) está disponível apenas para programas em execução nas versões Windows 95/98 e Windows NT 3.51 e posteriores.

Para obter mais informações sobre como ativar dicas de ferramentas, consulte [Dicas de ferramentas no Windows não derivadas de CFrameWnd](../../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md).

Para obter mais `CToolTipCtrl`informações sobre como usar, consulte [Controles](../../mfc/controls-mfc.md) e [Usando CToolTipCtrl](../../mfc/using-ctooltipctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CToolTipCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="ctooltipctrlactivate"></a><a name="activate"></a>CToolTipCtrl::Ativar

Chame esta função para ativar ou desativar um controle de ponta de ferramenta.

```cpp
void Activate(BOOL bActivate);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
Especifica se o controle da ponta da ferramenta deve ser ativado ou desativado.

### <a name="remarks"></a>Comentários

Se *bActivate* for TRUE, o controle será ativado; se FALSO, ele é desativado.

Quando um controle de ponta de ferramenta está ativo, as informações da ponta da ferramenta aparecem quando o cursor está em uma ferramenta que está registrada no controle; quando está inativa, as informações da ponta da ferramenta não aparecem, mesmo quando o cursor está em uma ferramenta.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

## <a name="ctooltipctrladdtool"></a><a name="addtool"></a>CToolTipCtrl::AddTool

Registra uma ferramenta com o controle de ponta da ferramenta.

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

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*nIDText*<br/>
ID do recurso string que contém o texto para a ferramenta.

*lpRectTool*<br/>
Ponteiro para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) contendo coordenadas do retângulo delimitador da ferramenta. As coordenadas são relativas ao canto superior esquerdo da área do cliente da janela identificada por *pWnd*.

*Nidtool*<br/>
ID da ferramenta.

*lpszText*<br/>
Pointer para o texto para a ferramenta. Se este parâmetro contiver o valor LPSTR_TEXTCALLBACK, TTN_NEEDTEXT mensagens de notificação irão para o pai da janela que *pWnd* aponta.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os parâmetros *lpRectTool* e *nIDTool* devem ser válidos ou se *o lpRectTool* for NULL, *nIDTool* deve ser 0.

Um controle de ponta de ferramenta pode ser associado a mais de uma ferramenta. Chame esta função para registrar uma ferramenta com o controle de ponta da ferramenta, de modo que as informações armazenadas na ponta da ferramenta são exibidas quando o cursor estiver na ferramenta.

> [!NOTE]
> Não é possível definir uma ponta `AddTool`de ferramenta para um controle estático usando .

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

## <a name="ctooltipctrladjustrect"></a><a name="adjustrect"></a>CToolTipCtrl::AdjustRect

Converte-se entre o retângulo de exibição de texto de um controle de ferramenta e seu retângulo de janela.

```
BOOL AdjustRect(
    LPRECT lprc,
    BOOL bLarger = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Lprc*<br/>
Pointer para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) que contém um retângulo de janela de ponta de ferramenta ou um retângulo de exibição de texto.

*Blarger*<br/>
Se TRUE, *lprc* é usado para especificar um retângulo de exibição de texto e ele recebe o retângulo da janela correspondente. Se FALSE, *lprc* é usado para especificar um retângulo de janela e recebe o retângulo de exibição de texto correspondente.

### <a name="return-value"></a>Valor retornado

Não zero se o retângulo for ajustado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro calcula o retângulo de exibição de texto de um controle de ponta de ferramenta a partir do retângulo da janela ou o retângulo da janela da ferramenta necessário para exibir um retângulo de exibição de texto especificado.

Esta função de membro implementa o comportamento da [TTM_ADJUSTRECT](/windows/win32/Controls/ttm-adjustrect)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlcreate"></a><a name="create"></a>CToolTipCtrl::Criar

Cria um controle de ponta de `CToolTipCtrl` ferramenta e o prende a um objeto.

```
virtual BOOL Create(CWnd* pParentWnd, DWORD dwStyle = 0);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Especifica a janela pai do controle de `CDialog`ponta da ferramenta, geralmente um . Não deve ser NULO.

*Dwstyle*<br/>
Especifica o estilo do controle de ponta da ferramenta. Consulte a seção **Observações** para obter mais informações.

### <a name="return-value"></a>Valor retornado

Não zero `CToolTipCtrl` se o objeto for criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CToolTipCtrl` um em dois passos. Primeiro, chame o construtor `CToolTipCtrl` para construir o `Create` objeto e, em seguida, `CToolTipCtrl` ligue para criar o controle da ponta da ferramenta e anexe-o ao objeto.

O parâmetro *dwStyle* pode ser qualquer combinação de Estilos de [janela](../../mfc/reference/styles-used-by-mfc.md#window-styles). Além disso, um controle de ponta de ferramenta tem dois estilos específicos de classe: TTS_ALWAYSTIP e TTS_NOPREFIX.

|Estilo|Significado|
|-----------|-------------|
|TTS_ALWAYSTIP|Especifica que a ponta da ferramenta aparecerá quando o cursor estiver em uma ferramenta, independentemente de a janela do proprietário do controle de ponta da ferramenta estar ativa ou inativa. Sem esse estilo, o controle de ponta da ferramenta aparece quando a janela do proprietário da ferramenta está ativa, mas não quando está inativa.|
|Tts_noprefix|Este estilo impede que o sistema retire o caractere ampersand (&) de uma seqüência. Se um controle de ponta de ferramenta não tiver o estilo TTS_NOPREFIX, o sistema tira automaticamente ampersand caracteres, permitindo que um aplicativo use a mesma string que um item do menu e como texto em um controle de ponta de ferramenta.|

Um controle de ponta de ferramenta tem os estilos de janela WS_POPUP e WS_EX_TOOLWINDOW, independentemente de você especá-los ao criar o controle.

Para criar um controle de ponta de ferramenta com estilos de windows `Create`estendidos, chame [CToolTipCtrl::CreateEx](#createex) em vez de .

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

## <a name="ctooltipctrlcreateex"></a><a name="createex"></a>CToolTipCtrl::CreateEx

Cria um controle (uma janela filho) `CToolTipCtrl` e associa-o ao objeto.

```
virtual BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwStyle = 0,
    DWORD dwStyleEx = 0);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*Dwstyle*<br/>
Especifica o estilo do controle de ponta da ferramenta. Consulte a seção **Observações** do [Criar](#create) para obter mais informações.

*dwStyleEx*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido caso contrário 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em `Create` vez de aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

## <a name="ctooltipctrlctooltipctrl"></a><a name="ctooltipctrl"></a>CToolTipCtrl::CToolTipCtrl

Constrói um objeto `CToolTipCtrl`.

```
CToolTipCtrl();
```

### <a name="remarks"></a>Comentários

Você deve `Create` ligar depois de construir o objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#74](../../mfc/codesnippet/cpp/ctooltipctrl-class_1.h)]

## <a name="ctooltipctrldeltool"></a><a name="deltool"></a>CToolTipCtrl::DelTool

Remove a ferramenta especificada por *pWnd* e *nIDTool* da coleção de ferramentas suportadas por um controle de ponta da ferramenta.

```cpp
void DelTool(
    CWnd* pWnd,
    UINT_PTR nIDTool = 0);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*Nidtool*<br/>
ID da ferramenta.

## <a name="ctooltipctrlgetbubblesize"></a><a name="getbubblesize"></a>CToolTipCtrl::GetBubbleSize

Recupera o tamanho da ponta da ferramenta.

```
CSize GetBubbleSize(LPTOOLINFO lpToolInfo) const;
```

### <a name="parameters"></a>Parâmetros

*lpToolInfo*<br/>
Um ponteiro para a estrutura [TOOLINFO](/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) da dica da ferramenta.

### <a name="return-value"></a>Valor retornado

O tamanho da ponta da ferramenta.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TTM_GETBUBBLESIZE](/windows/win32/Controls/ttm-getbubblesize)de mensagem Win32, conforme descrito no SDK do Windows.

## <a name="ctooltipctrlgetcurrenttool"></a><a name="getcurrenttool"></a>CToolTipCtrl::GetCurrentTool

Recupera informações, como tamanho, posição e texto, da janela da dica de ferramenta exibida pelo controle atual da dica de ferramenta.

```
BOOL GetCurrentTool(LPTOOLINFO lpToolInfo) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*lpToolInfo*|[fora] Pointer para uma estrutura [TOOLINFO](/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) que recebe informações sobre a janela atual da dica de ferramenta.|

### <a name="return-value"></a>Valor retornado

VERDADE se as informações forem recuperadas com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [TTM_GETCURRENTTOOL,](/windows/win32/Controls/ttm-getcurrenttool) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera informações sobre a janela atual da dica de ferramenta.

[!code-cpp[NVC_MFC_CToolBarCtrl_s1#6](../../mfc/reference/codesnippet/cpp/ctooltipctrl-class_2.cpp)]

## <a name="ctooltipctrlgetdelaytime"></a><a name="getdelaytime"></a>CToolTipCtrl::GetDelayTime

Recupera as durações iniciais, pop-up e reshow atualmente definidas para um controle de ponta de ferramenta.

```
int GetDelayTime(DWORD dwDuration) const;
```

### <a name="parameters"></a>Parâmetros

*dwDuração*<br/>
Sinalizador que especifica qual valor de duração será recuperado. Este parâmetro pode ser um dos seguintes valores:

- TTDT_AUTOPOP Recuperar o tempo em que a janela de ponta da ferramenta permanece visível se o ponteiro estiver parado no retângulo delimitador de uma ferramenta.

- TTDT_INITIAL Recuperar o tempo que o ponteiro deve permanecer parado no retângulo delimitador de uma ferramenta antes que a janela de ponta da ferramenta apareça.

- TTDT_RESHOW Recupere o tempo necessário para que as janelas de ponta da ferramenta subseqüentes apareçam à medida que o ponteiro se move de uma ferramenta para outra.

### <a name="return-value"></a>Valor retornado

O tempo de atraso especificado, em milissegundos

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TTM_GETDELAYTIME](/windows/win32/Controls/ttm-getdelaytime)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlgetmargin"></a><a name="getmargin"></a>CToolTipCtrl::GetMargin

Recupera as margens superior, esquerda, inferior e direita definidas para uma janela de ponta de ferramenta.

```cpp
void GetMargin(LPRECT lprc) const;
```

### <a name="parameters"></a>Parâmetros

*Lprc*<br/>
Endereço de `RECT` uma estrutura que receberá as informações da margem. Os membros da estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) não definem um retângulo delimitador. Para efeitos desta mensagem, os membros da estrutura são interpretados da seguinte forma:

|Membro|Representação|
|------------|--------------------|
|`top`|Distância entre a borda superior e o texto da ponta da ferramenta, em pixels.|
|`left`|Distância entre a borda esquerda e a extremidade esquerda do texto da ponta, em pixels.|
|`bottom`|Distância entre a borda inferior e a parte inferior do texto da ponta, em pixels.|
|`right`|Distância entre a borda direita e a extremidade direita do texto da ponta, em pixels.|

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TTM_GETMARGIN](/windows/win32/Controls/ttm-getmargin)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlgetmaxtipwidth"></a><a name="getmaxtipwidth"></a>CToolTipCtrl::GetMaxTipWidth

Recupera a largura máxima para uma janela de ponta de ferramenta.

```
int GetMaxTipWidth() const;
```

### <a name="return-value"></a>Valor retornado

A largura máxima para uma janela de ponta de ferramenta.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/ttm-getmaxtipwidth)Win32 TTM_GETMAXTIPWIDTH , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlgettext"></a><a name="gettext"></a>CToolTipCtrl::GetText

Recupera o texto que um controle de ponta de ferramenta mantém para uma ferramenta.

```cpp
void GetText(
    CString& str,
    CWnd* pWnd,
    UINT_PTR nIDTool = 0) const;
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
Referência a `CString` um objeto que recebe o texto da ferramenta.

*Pwnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*Nidtool*<br/>
ID da ferramenta.

### <a name="remarks"></a>Comentários

Os *parâmetros pWnd* e *nIDTool* identificam a ferramenta. Se essa ferramenta tiver sido previamente registrada no controle `CToolTipCtrl::AddTool`da ponta da ferramenta através de uma chamada anterior para , o objeto referenciado pelo parâmetro *str* é atribuído ao texto da ferramenta.

## <a name="ctooltipctrlgettipbkcolor"></a><a name="gettipbkcolor"></a>CToolTipCtrl::GetTipBkColor

Recupera a cor de fundo em uma janela de ponta de ferramenta.

```
COLORREF GetTipBkColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor [COLORREF](/windows/win32/gdi/colorref) que representa a cor de fundo.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TTM_GETTIPBKCOLOR](/windows/win32/Controls/ttm-gettipbkcolor)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlgettiptextcolor"></a><a name="gettiptextcolor"></a>CToolTipCtrl::GetTipTextColor

Recupera a cor do texto em uma janela de ponta de ferramenta.

```
COLORREF GetTipTextColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor [COLORREF](/windows/win32/gdi/colorref) que representa a cor do texto.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/ttm-gettiptextcolor)Win32 TTM_GETTIPTEXTCOLOR , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlgettitle"></a><a name="gettitle"></a>CToolTipCtrl::GetTitle

Recupera o título do controle atual da ponta de ferramenta.

```cpp
void GetTitle(PTTGETTITLE pttgt) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pttgt*|[fora] Pointer para uma estrutura [TTGETTITLE](/windows/win32/api/commctrl/ns-commctrl-ttgettitle) que contém informações sobre o controle ToolTip. Quando este método retorna, o membro *pszTitle* da estrutura [TTGETTITLE](/windows/win32/api/commctrl/ns-commctrl-ttgettitle) aponta para o texto do título.|

### <a name="remarks"></a>Comentários

Este método envia a mensagem [TTM_GETTITLE,](/windows/win32/Controls/ttm-gettitle) que é descrita no SDK do Windows.

## <a name="ctooltipctrlgettoolcount"></a><a name="gettoolcount"></a>CToolTipCtrl::GetToolCount

Recupera uma contagem das ferramentas registradas com o controle de ponta da ferramenta.

```
int GetToolCount() const;
```

### <a name="return-value"></a>Valor retornado

Uma contagem de ferramentas registradas com o controle de ponta da ferramenta.

## <a name="ctooltipctrlgettoolinfo"></a><a name="gettoolinfo"></a>CToolTipCtrl::GetToolInfo

Recupera as informações que um controle de ponta de ferramenta mantém sobre uma ferramenta.

```
BOOL GetToolInfo(
    CToolInfo& ToolInfo,
    CWnd* pWnd,
    UINT_PTR nIDTool = 0) const;
```

### <a name="parameters"></a>Parâmetros

*Toolinfo*<br/>
Referência a `TOOLINFO` um objeto que recebe o texto da ferramenta.

*Pwnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*Nidtool*<br/>
ID da ferramenta.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os `hwnd` `uId` membros da estrutura [TOOLINFO](/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) referenciada pelo *CToolInfo* identificam a ferramenta. Se essa ferramenta tiver sido registrada com o controle `AddTool`de `TOOLINFO` ponta da ferramenta através de uma chamada anterior para , a estrutura está preenchida com informações sobre a ferramenta.

## <a name="ctooltipctrlhittest"></a><a name="hittest"></a>CToolTipCtrl::HitTest

Teste um ponto para determinar se ele está dentro do retângulo delimitador da ferramenta dada e, se for o caso, recuperar informações sobre a ferramenta.

```
BOOL HitTest(
    CWnd* pWnd,
    CPoint pt,
    LPTOOLINFO lpToolInfo) const;
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*pt*<br/>
Ponteiro para `CPoint` um objeto contendo as coordenadas do ponto a ser testado.

*lpToolInfo*<br/>
Pointer para [toolinfo](/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) estrutura que contém informações sobre a ferramenta.

### <a name="return-value"></a>Valor retornado

Não zero se o ponto especificado pelas informações de teste de hit estiver dentro do retângulo delimitador da ferramenta; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se essa função retornar um valor não zero, a estrutura apontada pelo *lpToolInfo* será preenchida com informações sobre a ferramenta dentro de cujo retângulo o ponto está.

A `TTHITTESTINFO` estrutura é definida da seguinte forma:

```cpp
typedef struct _TT_HITTESTINFO { // tthti
    HWND hwnd;   // handle of tool or window with tool
    POINT pt;    // client coordinates of point to test
    TOOLINFO ti; // receives information about the tool
} TTHITTESTINFO, FAR * LPHITTESTINFO;
```

- `hwnd`

   Especifica o cabo da ferramenta.

- `pt`

   Especifica as coordenadas de um ponto se o ponto estiver no retângulo delimitador da ferramenta.

- `ti`

   Informações sobre a ferramenta. Para obter mais `TOOLINFO` informações sobre a estrutura, consulte [CToolTipCtrl::GetToolInfo](#gettoolinfo).

## <a name="ctooltipctrlpop"></a><a name="pop"></a>CToolTipCtrl::Pop

Remove uma janela de ponta de ferramenta exibida da vista.

```cpp
void Pop();
```

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TTM_POP](/windows/win32/Controls/ttm-pop)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlpopup"></a><a name="popup"></a>CToolTipCtrl::Popup

Faz com que o controle atual da dica de ferramenta seja exibido nas coordenadas da última mensagem do mouse.

```cpp
void Popup();
```

### <a name="remarks"></a>Comentários

Este método envia a mensagem [TTM_POPUP,](/windows/win32/Controls/ttm-popup) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir exibe uma janela de dica de ferramenta.

[!code-cpp[NVC_MFC_CToolBarCtrl_s1#7](../../mfc/reference/codesnippet/cpp/ctooltipctrl-class_3.cpp)]

## <a name="ctooltipctrlrelayevent"></a><a name="relayevent"></a>CToolTipCtrl::RelayEvent

Passa uma mensagem de mouse para um controle de ponta de ferramenta para processamento.

```cpp
void RelayEvent(LPMSG lpMsg);
```

### <a name="parameters"></a>Parâmetros

*Lpmsg*<br/>
Pointer para uma estrutura [MSG](/windows/win32/api/winuser/ns-winuser-msg) que contém a mensagem a ser retransmitida.

### <a name="remarks"></a>Comentários

Um controle de ponta de ferramenta processa apenas `RelayEvent`as seguintes mensagens, que são enviadas a ela por :

|WM_LBUTTONDOWN|Wm_mousemove|
|---------------------|-------------------|
|Wm_lbuttonup|Wm_rbuttondown|
|WM_MBUTTONDOWN|WM_RBUTTONUP|
|WM_MBUTTONUP||

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

## <a name="ctooltipctrlsetdelaytime"></a><a name="setdelaytime"></a>CToolTipCtrl::SetDelayTime

Define o tempo de atraso para um controle de ponta de ferramenta.

```cpp
void SetDelayTime(UINT nDelay);

void SetDelayTime(
    DWORD dwDuration,
    int iTime);
```

### <a name="parameters"></a>Parâmetros

*nAtraso*<br/>
Especifica o novo tempo de atraso, em milissegundos.

*dwDuração*<br/>
Sinalizador que especifica qual valor de duração será recuperado. Consulte [CToolTipCtrl::GetDelayTime](#getdelaytime) para obter uma descrição dos valores válidos.

*iTime*<br/>
O tempo de atraso especificado, em milissegundos.

### <a name="remarks"></a>Comentários

O tempo de atraso é o tempo que o cursor deve permanecer em uma ferramenta antes que a janela de ponta da ferramenta apareça. O tempo de atraso padrão é de 500 milissegundos.

## <a name="ctooltipctrlsetmargin"></a><a name="setmargin"></a>CToolTipCtrl::SetMargin

Coloque as margens superior, esquerda, inferior e direita para uma janela de ponta de ferramenta.

```cpp
void SetMargin(LPRECT lprc);
```

### <a name="parameters"></a>Parâmetros

*Lprc*<br/>
Endereço de `RECT` uma estrutura que contém as informações de margem a serem definidas. Os membros `RECT` da estrutura não definem um retângulo delimitador. Consulte [CToolTipCtrl::GetMargin](#getmargin) para obter uma descrição das informações de margem.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TTM_SETMARGIN](/windows/win32/Controls/ttm-setmargin)de mensagem Win32, conforme descrito no SDK do Windows.

## <a name="ctooltipctrlsetmaxtipwidth"></a><a name="setmaxtipwidth"></a>CToolTipCtrl::SetMaxTipWidth

Define a largura máxima para uma janela de ponta de ferramenta.

```
int SetMaxTipWidth(int iWidth);
```

### <a name="parameters"></a>Parâmetros

*iWidth*<br/>
A largura máxima da janela da ponta da ferramenta a ser definida.

### <a name="return-value"></a>Valor retornado

A largura máxima da ponta anterior.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TTM_SETMAXTIPWIDTH](/windows/win32/Controls/ttm-setmaxtipwidth)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlsettipbkcolor"></a><a name="settipbkcolor"></a>CToolTipCtrl::SetTipBkColor

Define a cor de fundo em uma janela de ponta de ferramenta.

```cpp
void SetTipBkColor(COLORREF clr);
```

### <a name="parameters"></a>Parâmetros

*Clr*<br/>
A nova cor de fundo.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/ttm-settipbkcolor)TTM_SETTIPBKCOLOR do Win32 , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlsettiptextcolor"></a><a name="settiptextcolor"></a>CToolTipCtrl::SetTipTextColor

Define a cor do texto em uma janela de ponta de ferramenta.

```cpp
void SetTipTextColor(COLORREF clr);
```

### <a name="parameters"></a>Parâmetros

*Clr*<br/>
A nova cor do texto.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/ttm-settiptextcolor)Win32 TTM_SETTIPTEXTCOLOR , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlsettitle"></a><a name="settitle"></a>CToolTipCtrl::SetTitle

Adiciona um ícone padrão e uma seqüência de títulos a uma dica de ferramenta.

```
BOOL SetTitle(
    UINT uIcon,
    LPCTSTR lpstrTitle);
```

### <a name="parameters"></a>Parâmetros

*uIcon*<br/>
Veja *o ícone* em [TTM_SETTITLE](/windows/win32/Controls/ttm-settitle) no SDK do Windows.

*lpstrTitle*<br/>
Ponteiro para a seqüência de título.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/ttm-settitle)Win32 TTM_SETTITLE , conforme descrito no SDK do Windows.

## <a name="ctooltipctrlsettoolinfo"></a><a name="settoolinfo"></a>CToolTipCtrl::SetToolInfo

Define as informações que uma dica de ferramenta mantém para uma ferramenta.

```cpp
void SetToolInfo(LPTOOLINFO lpToolInfo);
```

### <a name="parameters"></a>Parâmetros

*lpToolInfo*<br/>
Um ponteiro para uma estrutura [TOOLINFO](/windows/win32/api/commctrl/ns-commctrl-tttoolinfoa) que especifica as informações a serem definidas.

## <a name="ctooltipctrlsettoolrect"></a><a name="settoolrect"></a>CToolTipCtrl::SetToolRect

Define um novo retângulo delimitador para uma ferramenta.

```cpp
void SetToolRect(
    CWnd* pWnd,
    UINT_PTR nIDTool,
    LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*Nidtool*<br/>
ID da ferramenta.

*Lprect*<br/>
Ponteiro para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) especificando o novo retângulo delimitador.

## <a name="ctooltipctrlsetwindowtheme"></a><a name="setwindowtheme"></a>CToolTipCtrl::SetWindowTheme

Define o estilo visual da janela de ponta da ferramenta.

```
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```

### <a name="parameters"></a>Parâmetros

*pszSubAppName*<br/>
Um ponteiro para uma seqüência Unicode que contém o estilo visual a definir.

### <a name="return-value"></a>Valor retornado

O valor de retorno não é usado.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem [TTM_SETWINDOWTHEME,](/windows/win32/Controls/ttm-setwindowtheme) conforme descrito no SDK do Windows.

## <a name="ctooltipctrlupdate"></a><a name="update"></a>CToolTipCtrl::Atualização

Força a ferramenta atual a ser redesenhada.

```cpp
void Update();
```

## <a name="ctooltipctrlupdatetiptext"></a><a name="updatetiptext"></a>CToolTipCtrl::UpdateTipText

Atualiza o texto da dica da ferramenta para as ferramentas deste controle.

```cpp
void UpdateTipText(
    LPCTSTR lpszText,
    CWnd* pWnd,
    UINT_PTR nIDTool = 0);

void UpdateTipText(
    UINT nIDText,
    CWnd* pWnd,
    UINT_PTR nIDTool = 0);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Pointer para o texto para a ferramenta.

*Pwnd*<br/>
Ponteiro para a janela que contém a ferramenta.

*Nidtool*<br/>
ID da ferramenta.

*nIDText*<br/>
ID do recurso string que contém o texto para a ferramenta.

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CToolBar](../../mfc/reference/ctoolbar-class.md)
