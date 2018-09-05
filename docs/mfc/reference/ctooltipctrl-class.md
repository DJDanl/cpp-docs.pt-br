---
title: Classe CToolTipCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 06f0b78938534f685f14757ca16e5ad2574412f2
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43684801"
---
# <a name="ctooltipctrl-class"></a>Classe CToolTipCtrl
Encapsula a funcionalidade de um "controle dica de ferramenta," uma pequena janela pop-up que exibe uma única linha de texto que descreve a finalidade de uma ferramenta em um aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CToolTipCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CToolTipCtrl::CToolTipCtrl](#ctooltipctrl)|Constrói um objeto `CToolTipCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CToolTipCtrl::Activate](#activate)|Ativa e desativa o controle de dica de ferramenta.|  
|[CToolTipCtrl::AddTool](#addtool)|Registra uma ferramenta com o controle da dica de ferramenta.|  
|[CToolTipCtrl::AdjustRect](#adjustrect)|Converte entre o texto de um controle dica de ferramenta exibe o retângulo e seu retângulo da janela.|  
|[CToolTipCtrl::Create](#create)|Cria um controle de dica de ferramenta e anexa-o para um `CToolTipCtrl` objeto.|  
|[CToolTipCtrl::CreateEx](#createex)|Cria um controle de dica de ferramenta com os estilos estendidos do Windows especificados e anexa-o para um `CToolTipCtrl` objeto.|  
|[CToolTipCtrl::DelTool](#deltool)|Remove uma ferramenta de controle de dica de ferramenta.|  
|[CToolTipCtrl::GetBubbleSize](#getbubblesize)|Recupera o tamanho de dica de ferramenta.|  
|[CToolTipCtrl::GetCurrentTool](#getcurrenttool)|Recupera informações, como o tamanho, posição e texto da janela de dica de ferramenta exibe o controle de dica de ferramenta atual.|  
|[CToolTipCtrl::GetDelayTime](#getdelaytime)|Recupera a configuração inicial, pop-up e reshow durações que estão atualmente definidas para uma ferramenta de controle da dica.|  
|[CToolTipCtrl::GetMargin](#getmargin)|Recupera a parte superior, esquerda, inferior e direita as margens que são definidas para uma janela de dica de ferramenta.|  
|[CToolTipCtrl::GetMaxTipWidth](#getmaxtipwidth)|Recupera a largura máxima para uma janela de dica de ferramenta.|  
|[CToolTipCtrl::GetText](#gettext)|Recupera o texto que mantém o controle de uma dica de ferramenta para uma ferramenta.|  
|[CToolTipCtrl::GetTipBkColor](#gettipbkcolor)|Recupera a cor de plano de fundo em uma janela de dica de ferramenta.|  
|[CToolTipCtrl::GetTipTextColor](#gettiptextcolor)|Recupera a cor do texto em uma janela de dica de ferramenta.|  
|[CToolTipCtrl::GetTitle](#gettitle)|Recupera o título do controle de dica de ferramenta atual.|  
|[CToolTipCtrl::GetToolCount](#gettoolcount)|Recupera uma contagem das ferramentas mantido por um controle de dica de ferramenta.|  
|[CToolTipCtrl::GetToolInfo](#gettoolinfo)|Recupera as informações sobre uma ferramenta que mantém um controle de dica de ferramenta.|  
|[CToolTipCtrl::HitTest](#hittest)|Testa um ponto para determinar se ele está dentro do retângulo delimitador da ferramenta determinado. Nesse caso, recupera informações sobre a ferramenta.|  
|[CToolTipCtrl::Pop](#pop)|Remove uma janela de dica de ferramenta exibido da exibição.|  
|[CToolTipCtrl::Popup](#popup)|Faz com que o controle de dica de ferramenta atual exibir nas coordenadas da última mensagem de mouse.|  
|[CToolTipCtrl::RelayEvent](#relayevent)|Passa uma mensagem de mouse para um controle de dica de ferramenta para processamento.|  
|[CToolTipCtrl::SetDelayTime](#setdelaytime)|Define a versão inicial, pop-up e reshow durações para um controle de dica de ferramenta.|  
|[CToolTipCtrl::SetMargin](#setmargin)|Define a parte superior, esquerda, inferior e direita as margens para uma janela de dica de ferramenta.|  
|[CToolTipCtrl::SetMaxTipWidth](#setmaxtipwidth)|Define a largura máxima para uma janela de dica de ferramenta.|  
|[CToolTipCtrl::SetTipBkColor](#settipbkcolor)|Define a cor do plano de fundo em uma janela de dica de ferramenta.|  
|[CToolTipCtrl::SetTipTextColor](#settiptextcolor)|Define a cor do texto em uma janela de dica de ferramenta.|  
|[CToolTipCtrl::SetTitle](#settitle)|Adiciona uma cadeia de caracteres de título e o ícone padrão para uma dica de ferramenta.|  
|[CToolTipCtrl::SetToolInfo](#settoolinfo)|Define as informações de que uma dica de ferramenta mantém para uma ferramenta.|  
|[CToolTipCtrl::SetToolRect](#settoolrect)|Define um novo retângulo delimitador para uma ferramenta.|  
|[CToolTipCtrl::SetWindowTheme](#setwindowtheme)|Define o estilo visual da janela de dica de ferramenta.|  
|[CToolTipCtrl::Update](#update)|Força a ferramenta atual a ser redesenhado.|  
|[CToolTipCtrl::UpdateTipText](#updatetiptext)|Define o texto de dica de ferramenta para uma ferramenta.|  
  
## <a name="remarks"></a>Comentários  
 "tool" é qualquer janela, como uma janela filho, controle ou uma área retangular definida pelo aplicativo dentro de uma área da janela cliente. Uma dica de ferramenta está oculta a maioria das vezes, que aparecem somente quando o usuário coloca o cursor em uma ferramenta e deixa-lo lá para aproximadamente metade em segundo lugar. A dica de ferramenta aparece perto do cursor e desaparece quando o usuário clica em um botão do mouse ou mover o cursor para fora a ferramenta.  
  
 `CToolTipCtrl` fornece a funcionalidade para controlar o tempo inicial e a duração da dica de ferramenta, as larguras de margem ao redor do texto da dica de ferramenta, a largura da janela de dica de ferramenta em si e a cor do plano de fundo e texto da dica de ferramenta. Um controle de dica de ferramenta única pode fornecer informações para mais de uma ferramenta.  
  
 O `CToolTipCtrl` classe fornece a funcionalidade do controle de dica de ferramenta comuns do Windows. Esse controle (e, portanto, o `CToolTipCtrl` classe) está disponível somente para programas executados no Windows 95/98 e Windows NT versões 3.51 e posterior.  
  
 Para obter mais informações sobre como habilitar dicas de ferramenta, consulte [dicas de ferramenta no Windows derivadas de CFrameWnd](../../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md).  
  
 Para obter mais informações sobre como usar `CToolTipCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CToolTipCtrl](../../mfc/using-ctooltipctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CToolTipCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn. h  
  
##  <a name="activate"></a>  CToolTipCtrl::Activate  
 Chame essa função para ativar ou desativar um controle de dica de ferramenta.  
  
```  
void Activate(BOOL bActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bActivate*  
 Especifica se o controle da dica de ferramenta deve ser ativada ou desativada.  
  
### <a name="remarks"></a>Comentários  
 Se *bActivate* for TRUE, o controle é ativado; se FALSE, ela será desativada.  
  
 Quando um controle de dica de ferramenta está ativo, as informações de dica de ferramenta é exibida quando o cursor estiver em uma ferramenta que está registrada com o controle; Quando ele estiver inativo, as informações de dica de ferramenta não aparecer, mesmo quando o cursor estiver em uma ferramenta.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).  
  
##  <a name="addtool"></a>  CToolTipCtrl::AddTool  
 Registra uma ferramenta com o controle da dica de ferramenta.  
  
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
 *Apropriei*  
 Ponteiro para a janela que contém a ferramenta.  
  
 *nIDText*  
 ID do recurso de cadeia de caracteres que contém o texto para a ferramenta.  
  
 *lpRectTool*  
 Ponteiro para um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém as coordenadas da ferramenta do retângulo delimitador. As coordenadas são relativas ao canto superior esquerdo da área de cliente da janela identificada pelo *Apropriei*.  
  
 *nIDTool*  
 ID da ferramenta.  
  
 *lpszText*  
 Ponteiro para o texto para a ferramenta. Se este parâmetro conterá o valor LPSTR_TEXTCALLBACK, mensagens de notificação TTN_NEEDTEXT vão para o pai da janela que *Apropriei* aponta.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O *lpRectTool* e *nIDTool* parâmetros devem ser válidos, ou se *lpRectTool* é NULL, *nIDTool* deve ser 0.  
  
 Um controle de dica de ferramenta pode ser associado a mais de uma ferramenta. Chame essa função para registrar uma ferramenta com o controle da dica de ferramenta, para que as informações armazenadas na dica de ferramenta são exibidas quando o cursor estiver sobre a ferramenta.  
  
> [!NOTE]
>  Não é possível definir uma dica de ferramenta para um controle estático usando `AddTool`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).  
  
##  <a name="adjustrect"></a>  CToolTipCtrl::AdjustRect  
 Converte entre texto um controle de dica de ferramenta do exibe o retângulo e seu retângulo da janela.  
  
```  
BOOL AdjustRect(
    LPRECT lprc,  
    BOOL bLarger = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lprc*  
 Ponteiro para um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém um retângulo de janela de dica de ferramenta ou um retângulo de exibição de texto.  
  
 *bLarger*  
 Se for TRUE, *lprc* é usado para especificar um retângulo de exibição de texto, e ele recebe o retângulo de janela correspondente. Se for FALSE, *lprc* é usado para especificar um retângulo de janela, e ele recebe o retângulo de exibição de texto correspondente.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o retângulo é ajustado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro calcula o retângulo de exibição de texto de um controle dica de ferramenta do seu retângulo da janela ou o retângulo de janela de dica de ferramenta necessário para exibir um retângulo de exibição de texto especificado.  
  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_ADJUSTRECT](/windows/desktop/Controls/ttm-adjustrect), conforme descrito no SDK do Windows.  
  
##  <a name="create"></a>  CToolTipCtrl::Create  
 Cria um controle de dica de ferramenta e anexa-o para um `CToolTipCtrl` objeto.  
  
```  
virtual BOOL Create(CWnd* pParentWnd, DWORD dwStyle = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pParentWnd*  
 Especifica a janela do pai do controle de dica de ferramenta, geralmente um `CDialog`. Ele não deve ser NULL.  
  
 *dwStyle*  
 Especifica o estilo do controle de dica de ferramenta. Consulte a **comentários** seção para obter mais informações.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `CToolTipCtrl` objeto é criado com êxito; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você constrói um `CToolTipCtrl` em duas etapas. Primeiro, chame o construtor para construir o `CToolTipCtrl` do objeto e, em seguida, chame `Create` para criar o controle da dica de ferramenta e anexá-lo para o `CToolTipCtrl` objeto.  
  
 O *dwStyle* parâmetro pode ser qualquer combinação de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles). Além disso, um controle de dica de ferramenta tem dois estilos específicos da classe: TTS_ALWAYSTIP e TTS_NOPREFIX.  
  
|Estilo|Significado|  
|-----------|-------------|  
|TTS_ALWAYSTIP|Especifica que a dica de ferramenta será exibida quando o cursor estiver em uma ferramenta, independentemente se a janela do proprietário do controle de dica de ferramenta está ativo ou inativo. Sem esse estilo, o controle da dica de ferramenta é exibida quando a janela do proprietário da ferramenta está ativa, mas não quando ela está inativa.|  
|TTS_NOPREFIX|Esse estilo impede que o sistema retirando o caractere de uma cadeia de caracteres "e" comercial (&). Se um controle de dica de ferramenta não tem o estilo TTS_NOPREFIX, o sistema retira automaticamente os caracteres de e comercial, permitindo que um aplicativo para usar a mesma cadeia de caracteres como item de menu e como texto em um controle de dica de ferramenta.|  
  
 Um controle de dica de ferramenta tem os estilos de janela WS_POPUP e WS_EX_TOOLWINDOW, independentemente de você especificá-las ao criar o controle.  
  
 Para criar um controle de dica de ferramenta com estilos estendidos do windows, chame [CToolTipCtrl::CreateEx](#createex) em vez de `Create`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).  
  
##  <a name="createex"></a>  CToolTipCtrl::CreateEx  
 Cria um controle (uma janela filho) e associá-la com o `CToolTipCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    CWnd* pParentWnd,  
    DWORD dwStyle = 0,  
    DWORD dwStyleEx = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pParentWnd*  
 Um ponteiro para a janela que é o pai do controle.  
  
 *dwStyle*  
 Especifica o estilo do controle de dica de ferramenta. Consulte a **Remarks** seção [criar](#create) para obter mais informações.  
  
 *dwStyleEx*  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o *dwExStyle* parâmetro para [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Caso contrário, 0 diferente de zero se for bem-sucedido.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de `Create` para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.  
  
##  <a name="ctooltipctrl"></a>  CToolTipCtrl::CToolTipCtrl  
 Constrói um objeto `CToolTipCtrl`.  
  
```  
CToolTipCtrl();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar `Create` depois de construir o objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#74](../../mfc/codesnippet/cpp/ctooltipctrl-class_1.h)]  
  
##  <a name="deltool"></a>  CToolTipCtrl::DelTool  
 Remove a ferramenta especificada por *Apropriei* e *nIDTool* da coleção de ferramentas com suporte por um controle de dica de ferramenta.  
  
```  
void DelTool(
    CWnd* pWnd,  
    UINT_PTR nIDTool = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Apropriei*  
 Ponteiro para a janela que contém a ferramenta.  
  
 *nIDTool*  
 ID da ferramenta.  
  
##  <a name="getbubblesize"></a>  CToolTipCtrl::GetBubbleSize  
 Recupera o tamanho de dica de ferramenta.  
  
```  
CSize GetBubbleSize(LPTOOLINFO lpToolInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpToolInfo*  
 Um ponteiro para a dica de ferramenta [TOOLINFO](/windows/desktop/api/commctrl/ns-commctrl-tagtoolinfoa) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho da dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_GETBUBBLESIZE](/windows/desktop/Controls/ttm-getbubblesize), conforme descrito no SDK do Windows.  
  
##  <a name="getcurrenttool"></a>  CToolTipCtrl::GetCurrentTool  
 Recupera informações, como o tamanho, posição e texto da janela de dica de ferramenta exibido pelo controle de dica de ferramenta atual.  
  
```  
BOOL GetCurrentTool(LPTOOLINFO lpToolInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] *lpToolInfo*|Ponteiro para um [TOOLINFO](/windows/desktop/api/commctrl/ns-commctrl-tagtoolinfoa) estrutura que recebe informações sobre a janela de dica de ferramenta atual.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se as informações são recuperadas com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TTM_GETCURRENTTOOL](/windows/desktop/Controls/ttm-getcurrenttool) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir recupera informações sobre a janela de dica de ferramenta atual.  
  
 [!code-cpp[NVC_MFC_CToolBarCtrl_s1#6](../../mfc/reference/codesnippet/cpp/ctooltipctrl-class_2.cpp)]  
  
##  <a name="getdelaytime"></a>  CToolTipCtrl::GetDelayTime  
 Recupera a versão inicial, pop-up e reshow durações definidas atualmente para um controle de dica de ferramenta.  
  
```  
int GetDelayTime(DWORD dwDuration) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwDuration*  
 Sinalizador que especifica qual valor de duração será recuperado. Esse parâmetro pode ser um dos seguintes valores:  
  
- Recuperar TTDT_AUTOPOP o período de tempo a janela de dica de ferramenta permanece visível se o ponteiro estiver parado dentro do retângulo delimitador de uma ferramenta.  
  
- Recuperar TTDT_INITIAL o período de tempo que o ponteiro deve permanecer parado dentro do retângulo delimitador de uma ferramenta antes da janela de dica de ferramenta é exibida.  
  
- O período de tempo que leva para as janelas de dica de ferramenta subsequentes sejam exibidos como o ponteiro TTDT_RESHOW recuperar move de uma ferramenta para outra.  
  
### <a name="return-value"></a>Valor de retorno  
 O tempo de atraso especificado, em milissegundos  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_GETDELAYTIME](/windows/desktop/Controls/ttm-getdelaytime), conforme descrito no SDK do Windows.  
  
##  <a name="getmargin"></a>  CToolTipCtrl::GetMargin  
 Recupera a parte superior, esquerda, inferior e direita margens definidas para uma janela de dica de ferramenta.  
  
```  
void GetMargin(LPRECT lprc) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lprc*  
 Endereço de um `RECT` estrutura que receberá as informações de margem. Os membros de [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura não pode definir um retângulo delimitador. Para fins desta mensagem, os membros da estrutura são interpretados da seguinte maneira:  
  
|Membro|Representação|  
|------------|--------------------|  
|`top`|Distância entre a borda superior e a parte superior do texto de dica de ferramenta, em pixels.|  
|`left`|Distância entre a borda esquerda e a extremidade esquerda do texto da dica, em pixels.|  
|`bottom`|Distância entre a borda inferior e inferior do texto da dica, em pixels.|  
|`right`|Distância entre a borda direita e a extremidade direita do texto da dica, em pixels.|  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_GETMARGIN](/windows/desktop/Controls/ttm-getmargin), conforme descrito no SDK do Windows.  
  
##  <a name="getmaxtipwidth"></a>  CToolTipCtrl::GetMaxTipWidth  
 Recupera a largura máxima para uma janela de dica de ferramenta.  
  
```  
int GetMaxTipWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura máxima para uma janela de dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_GETMAXTIPWIDTH](/windows/desktop/Controls/ttm-getmaxtipwidth), conforme descrito no SDK do Windows.  
  
##  <a name="gettext"></a>  CToolTipCtrl::GetText  
 Recupera o texto que mantém o controle de uma dica de ferramenta para uma ferramenta.  
  
```  
void GetText(
    CString& str,  
    CWnd* pWnd,  
    UINT_PTR nIDTool = 0) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *str*  
 Referência a um `CString` objeto que recebe o texto da ferramenta.  
  
 *Apropriei*  
 Ponteiro para a janela que contém a ferramenta.  
  
 *nIDTool*  
 ID da ferramenta.  
  
### <a name="remarks"></a>Comentários  
 O *Apropriei* e *nIDTool* parâmetros identificam a ferramenta. Se essa ferramenta foi registrada anteriormente com o controle da dica de ferramenta por meio de uma chamada anterior a `CToolTipCtrl::AddTool`, o objeto referenciado pela *str* parâmetro receberá o texto da ferramenta.  
  
##  <a name="gettipbkcolor"></a>  CToolTipCtrl::GetTipBkColor  
 Recupera a cor de plano de fundo em uma janela de dica de ferramenta.  
  
```  
COLORREF GetTipBkColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [COLORREF](/windows/desktop/gdi/colorref) valor que representa a cor do plano de fundo.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_GETTIPBKCOLOR](/windows/desktop/Controls/ttm-gettipbkcolor), conforme descrito no SDK do Windows.  
  
##  <a name="gettiptextcolor"></a>  CToolTipCtrl::GetTipTextColor  
 Recupera a cor do texto em uma janela de dica de ferramenta.  
  
```  
COLORREF GetTipTextColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [COLORREF](/windows/desktop/gdi/colorref) valor que representa a cor do texto.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_GETTIPTEXTCOLOR](/windows/desktop/Controls/ttm-gettiptextcolor), conforme descrito no SDK do Windows.  
  
##  <a name="gettitle"></a>  CToolTipCtrl::GetTitle  
 Recupera o título do controle de dica de ferramenta atual.  
  
```  
void GetTitle(PTTGETTITLE pttgt) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] *pttgt*|Ponteiro para um [TTGETTITLE](/windows/desktop/api/commctrl/ns-commctrl-_ttgettitle) estrutura que contém informações sobre o controle de dica de ferramenta. Quando este método retorna, o *pszTitle* membro a [TTGETTITLE](/windows/desktop/api/commctrl/ns-commctrl-_ttgettitle) estrutura aponta para o texto do título.|  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TTM_GETTITLE](/windows/desktop/Controls/ttm-gettitle) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="gettoolcount"></a>  CToolTipCtrl::GetToolCount  
 Recupera uma contagem das ferramentas registrado com o controle da dica de ferramenta.  
  
```  
int GetToolCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma contagem de ferramentas registrado com o controle da dica de ferramenta.  
  
##  <a name="gettoolinfo"></a>  CToolTipCtrl::GetToolInfo  
 Recupera as informações sobre uma ferramenta que mantém um controle de dica de ferramenta.  
  
```  
BOOL GetToolInfo(
    CToolInfo& ToolInfo,  
    CWnd* pWnd,  
    UINT_PTR nIDTool = 0) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *ToolInfo*  
 Referência a um `TOOLINFO` objeto que recebe o texto da ferramenta.  
  
 *Apropriei*  
 Ponteiro para a janela que contém a ferramenta.  
  
 *nIDTool*  
 ID da ferramenta.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `hwnd` e `uId` membros da [TOOLINFO](/windows/desktop/api/commctrl/ns-commctrl-tagtoolinfoa) estrutura referenciada por *CToolInfo* identificar a ferramenta. Se essa ferramenta foi registrada com o controle da dica de ferramenta por meio de uma chamada anterior a `AddTool`, o `TOOLINFO` estrutura é preenchida com informações sobre a ferramenta.  
  
##  <a name="hittest"></a>  CToolTipCtrl::HitTest  
 Testa um ponto para determinar se ele está dentro do retângulo delimitador da ferramenta determinado e, nesse caso, recuperar informações sobre a ferramenta.  
  
```  
BOOL HitTest(
    CWnd* pWnd,  
    CPoint pt,  
    LPTOOLINFO lpToolInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Apropriei*  
 Ponteiro para a janela que contém a ferramenta.  
  
 *pt*  
 Ponteiro para um `CPoint` objeto que contém as coordenadas do ponto a ser testado.  
  
 *lpToolInfo*  
 Ponteiro para [TOOLINFO](/windows/desktop/api/commctrl/ns-commctrl-tagtoolinfoa) estrutura que contém informações sobre a ferramenta.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o ponto especificado pelas informações de teste de clique está dentro do retângulo delimitador da ferramenta; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se essa função retorna um valor diferente de zero, a estrutura apontada por *lpToolInfo* é preenchido com informações sobre a ferramenta cujo retângulo se encontra o ponto.  
  
 O `TTHITTESTINFO` estrutura é definida da seguinte maneira:  
  
 `typedef struct _TT_HITTESTINFO { // tthti`  
  
 `HWND hwnd;   // handle of tool or window with tool`  
  
 `POINT pt;    // client coordinates of point to test`  
  
 `TOOLINFO ti; // receives information about the tool`  
  
 `} TTHITTESTINFO, FAR * LPHITTESTINFO;`  
  
 `hwnd`  
 Especifica o identificador da ferramenta.  
  
 `pt`  
 Especifica as coordenadas de um ponto, se o ponto está na ferramenta de retângulo delimitador.  
  
 `ti`  
 Informações sobre a ferramenta. Para obter mais informações sobre o `TOOLINFO` estrutura, consulte [CToolTipCtrl::GetToolInfo](#gettoolinfo).  
  
##  <a name="pop"></a>  CToolTipCtrl::Pop  
 Remove uma janela de dica de ferramenta exibido da exibição.  
  
```  
void Pop();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_POP](/windows/desktop/Controls/ttm-pop), conforme descrito no SDK do Windows.  
  
##  <a name="popup"></a>  CToolTipCtrl::Popup  
 Faz com que o controle de dica de ferramenta atual exibir nas coordenadas da última mensagem de mouse.  
  
```  
void Popup();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TTM_POPUP](/windows/desktop/Controls/ttm-popup) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir exibe uma janela de dica de ferramenta.  
  
 [!code-cpp[NVC_MFC_CToolBarCtrl_s1#7](../../mfc/reference/codesnippet/cpp/ctooltipctrl-class_3.cpp)]  
  
##  <a name="relayevent"></a>  CToolTipCtrl::RelayEvent  
 Passa uma mensagem de mouse para um controle de dica de ferramenta para processamento.  
  
```  
void RelayEvent(LPMSG lpMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpMsg*  
 Ponteiro para um [MSG](https://msdn.microsoft.com/library/windows/desktop/ms644958) estrutura que contém a mensagem de retransmissão.  
  
### <a name="remarks"></a>Comentários  
 Um controle de dica de ferramenta processa apenas as mensagens seguintes, que são enviadas pelo `RelayEvent`:  
  
|WM_LBUTTONDOWN|WM_MOUSEMOVE|  
|---------------------|-------------------|  
|WM_LBUTTONUP|WM_RBUTTONDOWN|  
|WM_MBUTTONDOWN|WM_RBUTTONUP|  
|WM_MBUTTONUP||  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).  
  
##  <a name="setdelaytime"></a>  CToolTipCtrl::SetDelayTime  
 Define o tempo de atraso para um controle de dica de ferramenta.  
  
```  
void SetDelayTime(UINT nDelay);

 
void SetDelayTime(
    DWORD dwDuration,  
    int iTime);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nDelay*  
 Especifica o novo tempo de atraso, em milissegundos.  
  
 *dwDuration*  
 Sinalizador que especifica qual valor de duração será recuperado. Ver [CToolTipCtrl::GetDelayTime](#getdelaytime) para obter uma descrição dos valores válidos.  
  
 *iTime*  
 O tempo de atraso especificado, em milissegundos.  
  
### <a name="remarks"></a>Comentários  
 O tempo de atraso é o período de tempo que o cursor deve permanecer em uma ferramenta antes da janela de dica de ferramenta é exibida. O tempo de atraso padrão é 500 milissegundos.  
  
##  <a name="setmargin"></a>  CToolTipCtrl::SetMargin  
 Define a parte superior, esquerda, inferior e direita as margens para uma janela de dica de ferramenta.  
  
```  
void SetMargin(LPRECT lprc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lprc*  
 Endereço de um `RECT` estrutura que contém as informações de margem a ser definido. Os membros do `RECT` estrutura não pode definir um retângulo delimitador. Ver [CToolTipCtrl::GetMargin](#getmargin) para obter uma descrição das informações de margem.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_SETMARGIN](/windows/desktop/Controls/ttm-setmargin), conforme descrito no SDK do Windows.  
  
##  <a name="setmaxtipwidth"></a>  CToolTipCtrl::SetMaxTipWidth  
 Define a largura máxima para uma janela de dica de ferramenta.  
  
```  
int SetMaxTipWidth(int iWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 *iWidth*  
 A largura de janela dica de ferramenta máximo a ser definido.  
  
### <a name="return-value"></a>Valor de retorno  
 A largura máxima de dica anterior.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_SETMAXTIPWIDTH](/windows/desktop/Controls/ttm-setmaxtipwidth), conforme descrito no SDK do Windows.  
  
##  <a name="settipbkcolor"></a>  CToolTipCtrl::SetTipBkColor  
 Define a cor do plano de fundo em uma janela de dica de ferramenta.  
  
```  
void SetTipBkColor(COLORREF clr);
```  
  
### <a name="parameters"></a>Parâmetros  
 *CLR*  
 A nova cor de plano de fundo.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_SETTIPBKCOLOR](/windows/desktop/Controls/ttm-settipbkcolor), conforme descrito no SDK do Windows.  
  
##  <a name="settiptextcolor"></a>  CToolTipCtrl::SetTipTextColor  
 Define a cor do texto em uma janela de dica de ferramenta.  
  
```  
void SetTipTextColor(COLORREF clr);
```  
  
### <a name="parameters"></a>Parâmetros  
 *CLR*  
 A nova cor do texto.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_SETTIPTEXTCOLOR](/windows/desktop/Controls/ttm-settiptextcolor), conforme descrito no SDK do Windows.  
  
##  <a name="settitle"></a>  CToolTipCtrl::SetTitle  
 Adiciona uma cadeia de caracteres de título e o ícone padrão para uma dica de ferramenta.  
  
```  
BOOL SetTitle(
    UINT uIcon,  
    LPCTSTR lpstrTitle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *uIcon*  
 Ver *ícone* na [TTM_SETTITLE](/windows/desktop/Controls/ttm-settitle) no SDK do Windows.  
  
 *lpstrTitle*  
 Ponteiro para a cadeia de caracteres do título.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TTM_SETTITLE](/windows/desktop/Controls/ttm-settitle), conforme descrito no SDK do Windows.  
  
##  <a name="settoolinfo"></a>  CToolTipCtrl::SetToolInfo  
 Define as informações de que uma dica de ferramenta mantém para uma ferramenta.  
  
```  
void SetToolInfo(LPTOOLINFO lpToolInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpToolInfo*  
 Um ponteiro para um [TOOLINFO](/windows/desktop/api/commctrl/ns-commctrl-tagtoolinfoa) estrutura que especifica as informações para definir.  
  
##  <a name="settoolrect"></a>  CToolTipCtrl::SetToolRect  
 Define um novo retângulo delimitador para uma ferramenta.  
  
```  
void SetToolRect(
    CWnd* pWnd,  
    UINT_PTR nIDTool,  
    LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Apropriei*  
 Ponteiro para a janela que contém a ferramenta.  
  
 *nIDTool*  
 ID da ferramenta.  
  
 *lpRect*  
 Ponteiro para um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura especificando o novo retângulo delimitador.  
  
##  <a name="setwindowtheme"></a>  CToolTipCtrl::SetWindowTheme  
 Define o estilo visual da janela de dica de ferramenta.  
  
```  
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pszSubAppName*  
 Um ponteiro para uma cadeia de caracteres Unicode que contém o estilo visual a ser definido.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno não é usado.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade dos [TTM_SETWINDOWTHEME](/windows/desktop/Controls/ttm-setwindowtheme) da mensagem, conforme descrito no SDK do Windows.  
  
##  <a name="update"></a>  CToolTipCtrl::Update  
 Força a ferramenta atual a ser redesenhado.  
  
```  
void Update();
```  
  
##  <a name="updatetiptext"></a>  CToolTipCtrl::UpdateTipText  
 Atualiza o texto de dica de ferramenta para ferramentas desse controle.  
  
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
  
### <a name="parameters"></a>Parâmetros  
 *lpszText*  
 Ponteiro para o texto para a ferramenta.  
  
 *Apropriei*  
 Ponteiro para a janela que contém a ferramenta.  
  
 *nIDTool*  
 ID da ferramenta.  
  
 *nIDText*  
 ID do recurso de cadeia de caracteres que contém o texto para a ferramenta.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CToolBar](../../mfc/reference/ctoolbar-class.md)
