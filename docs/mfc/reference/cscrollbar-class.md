---
title: Classe CScrollBar | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CScrollBar class
- SCROLLBAR window class
- scroll bars
- Windows common controls [C++], CScrollBar
- controls [MFC], scroll bar
ms.assetid: f3735ca5-73ea-46dc-918b-4d824c9fe47f
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 84b59f041f1a6cf73843c303e1a6b71adffc2101
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CScrollBar::Create](#create)|Cria a barra de rolagem do Windows e anexa-o para o `CScrollBar` objeto.|  
|[CScrollBar::EnableScrollBar](#enablescrollbar)|Habilita ou desabilita uma ou ambas as setas de uma barra de rolagem.|  
|[CScrollBar::GetScrollBarInfo](#getscrollbarinfo)|Recupera informações sobre a barra de rolagem uma `SCROLLBARINFO` estrutura.|  
|[CScrollBar::GetScrollInfo](#getscrollinfo)|Recupera informações sobre a barra de rolagem.|  
|[CScrollBar::GetScrollLimit](#getscrolllimit)|Recupera o limite da barra de rolagem|  
|[CScrollBar::GetScrollPos](#getscrollpos)|Recupera a posição atual de uma caixa de rolagem.|  
|[CScrollBar::GetScrollRange](#getscrollrange)|Recupera as posições de barra de rolagem mínimo e máximo atual para a barra de rolagem determinado.|  
|[CScrollBar::SetScrollInfo](#setscrollinfo)|Define informações sobre a barra de rolagem.|  
|[CScrollBar::SetScrollPos](#setscrollpos)|Define a posição atual de uma caixa de rolagem.|  
|[CScrollBar::SetScrollRange](#setscrollrange)|Define os valores mínimo e máximo de posição para a barra de rolagem determinado.|  
|[CScrollBar::ShowScrollBar](#showscrollbar)|Mostra ou oculta uma barra de rolagem.|  
  
## <a name="remarks"></a>Comentários  
 Você pode criar um controle de barra de rolagem em duas etapas. Primeiro, chame o construtor `CScrollBar` para construir o `CScrollBar` do objeto, em seguida, chame o [criar](#create) a função de membro para criar o controle de barra de rolagem do Windows e anexá-lo a `CScrollBar` objeto.  
  
 Se você criar um `CScrollBar` objeto dentro de uma caixa de diálogo (por meio de um recurso de caixa de diálogo), o `CScrollBar` é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um `CScrollBar` do objeto em uma janela, você também precisa destruí-lo.  
  
 Se você criar o `CScrollBar` do objeto na pilha, ele será destruído automaticamente. Se você criar o `CScrollBar` objeto no heap usando o **novo** função, você deve chamar **excluir** no objeto para destruí-lo quando o usuário termina a barra de rolagem do Windows.  
  
 Se você alocar qualquer memória no `CScrollBar` de objeto, substituir o `CScrollBar` destruidor descartar as alocações.  
  
 Para obter informações relacionadas sobre o uso de `CScrollBar`, consulte [controles](../../mfc/controls-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CScrollBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="create"></a>CScrollBar::Create  
 Cria a barra de rolagem do Windows e anexa-o para o `CScrollBar` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica a rolagem estilo da barra. Aplique qualquer combinação de [estilos de barra de rolagem](../../mfc/reference/scroll-bar-styles.md) para a barra de rolagem.  
  
 `rect`  
 Especifica o tamanho da barra de rolagem e a posição. Pode ser um `RECT` estrutura ou um `CRect` objeto.  
  
 `pParentWnd`  
 Especifica a rolagem janela do pai da barra, geralmente um `CDialog` objeto. Ele não deve ser **nulo**.  
  
 `nID`  
 ID do controle da barra de rolagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CScrollBar` objeto em duas etapas. Primeiro, chame o construtor, que constrói a `CScrollBar` objeto; em seguida, chame **criar**, que cria e inicializa a barra de rolagem do Windows associada e anexa-o para o `CScrollBar` objeto.  
  
 Aplique o seguinte [estilos de janela](../../mfc/reference/window-styles.md) para uma barra de rolagem:  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** geral  
  
- **WS_DISABLED** raramente  
  
- **WS_GROUP** para agrupar controles  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CScrollBar n º&1;](../../mfc/reference/codesnippet/cpp/cscrollbar-class_1.cpp)]  
  
##  <a name="cscrollbar"></a>CScrollBar::CScrollBar  
 Constrói um objeto `CScrollBar`.  
  
```  
CScrollBar();
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar o objeto, chame o **criar** função de membro para criar e inicializar a barra de rolagem do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CScrollBar n º&2;](../../mfc/reference/codesnippet/cpp/cscrollbar-class_2.h)]  
  
##  <a name="enablescrollbar"></a>CScrollBar::EnableScrollBar  
 Habilita ou desabilita uma ou ambas as setas de uma barra de rolagem.  
  
```  
BOOL EnableScrollBar(UINT nArrowFlags = ESB_ENABLE_BOTH);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nArrowFlags`  
 Especifica se as setas de rolagem estão habilitadas ou desabilitadas e quais setas estão habilitadas ou desabilitadas. Esse parâmetro pode ser um dos seguintes valores:  
  
- **ESB_ENABLE_BOTH** permite que ambas as setas de uma barra de rolagem.  
  
- **ESB_DISABLE_LTUP** desabilita a seta para a esquerda de uma barra de rolagem horizontal ou na seta para cima de uma barra de rolagem vertical.  
  
- **ESB_DISABLE_RTDN** desabilita a seta à direita de uma barra de rolagem horizontal ou na seta para baixo da barra de rolagem vertical.  
  
- **ESB_DISABLE_BOTH** desabilita ambas as setas de uma barra de rolagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se as setas estão habilitadas ou desabilitadas conforme especificado; Caso contrário, 0, que indica que as setas já estão no estado solicitado ou que ocorreu um erro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CScrollBar::SetScrollRange](#setscrollrange).  
  
##  <a name="getscrollbarinfo"></a>CScrollBar::GetScrollBarInfo  
 Recupera as informações que o **SCROLLBARINFO** estrutura mantém sobre uma barra de rolagem.  
  
```  
BOOL GetScrollBarInfo(PSCROLLBARINFO pScrollInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pScrollInfo*  
 Um ponteiro para o [SCROLLBARINFO](http://msdn.microsoft.com/library/windows/desktop/bb787535) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade do [SBM_SCROLLBARINFO](http://msdn.microsoft.com/library/windows/desktop/bb787545) mensagem, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getscrollinfo"></a>CScrollBar::GetScrollInfo  
 Recupera as informações que o `SCROLLINFO` estrutura mantém sobre uma barra de rolagem.  
  
```  
BOOL GetScrollInfo(
    LPSCROLLINFO lpScrollInfo,  
    UINT nMask = SIF_ALL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpScrollInfo`  
 Um ponteiro para um [SCROLLINFO](http://msdn.microsoft.com/library/windows/desktop/bb787537) estrutura. Consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre essa estrutura.  
  
 `nMask`  
 Especifica os parâmetros da barra de rolagem para recuperar. Uso típico, SIF_ALL, especifica uma combinação de SIF_PAGE, SIF_POS, SIF_TRACKPOS e SIF_RANGE. Consulte `SCROLLINFO` para obter mais informações sobre os valores de nMask.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a mensagem recuperada quaisquer valores, o retorno será **TRUE**. Caso contrário, ele será **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 `GetScrollInfo`permite que aplicativos usem as posições de rolagem de 32 bits.  
  
 O [SCROLLINFO](http://msdn.microsoft.com/library/windows/desktop/bb787537) estrutura contém informações sobre uma barra, incluindo o mínimo e máximo de rolagem posições, o tamanho da página e a posição da caixa de rolagem (thumb) de rolagem. Consulte o `SCROLLINFO` tópico estrutura o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre como alterar os padrões de estrutura.  
  
 O Windows MFC mensagem manipuladores que indicam a posição da barra de rolagem, [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll) e [CWnd::OnVScroll](../../mfc/reference/cwnd-class.md#onvscroll), fornecer apenas 16 bits de dados de posição. `GetScrollInfo`e `SetScrollInfo` fornecem 32 bits de dados de posição da barra de rolagem. Assim, um aplicativo pode chamar `GetScrollInfo` ao processar uma `CWnd::OnHScroll` ou `CWnd::OnVScroll` para obter dados de posição de barra de rolagem de 32 bits.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).  
  
##  <a name="getscrolllimit"></a>CScrollBar::GetScrollLimit  
 Recupera o posição da barra de rolagem de rolagem no máximo.  
  
```  
int GetScrollLimit();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica a posição de máximo de uma barra de rolagem se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).  
  
##  <a name="getscrollpos"></a>CScrollBar::GetScrollPos  
 Recupera a posição atual de uma caixa de rolagem.  
  
```  
int GetScrollPos() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica a posição atual da caixa de rolagem, se for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A posição atual é um valor relativo depende o intervalo de rolagem atual. Por exemplo, se o intervalo de rolagem é de 100 a 200 e a caixa de rolagem está no meio de barra, a posição atual é 150.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).  
  
##  <a name="getscrollrange"></a>CScrollBar::GetScrollRange  
 Copia as posições de barra de rolagem mínimo e máximo atual para a barra de rolagem determinada para os locais especificados por `lpMinPos` e `lpMaxPos`.  
  
```  
void GetScrollRange(
    LPINT lpMinPos,  
    LPINT lpMaxPos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMinPos`  
 Aponta para a variável de inteiro que receberá a posição mínima.  
  
 `lpMaxPos`  
 Aponta para a variável de inteiro que receberá a posição máxima.  
  
### <a name="remarks"></a>Comentários  
 O intervalo padrão para um controle de barra de rolagem está vazio (ambos os valores são 0).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::OnHScroll](../../mfc/reference/cwnd-class.md#onhscroll).  
  
##  <a name="setscrollinfo"></a>CScrollBar::SetScrollInfo  
 Define as informações que o `SCROLLINFO` estrutura mantém sobre uma barra de rolagem.  
  
```  
BOOL SetScrollInfo(
    LPSCROLLINFO lpScrollInfo,  
    BOOL bRedraw = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpScrollInfo`  
 Um ponteiro para um [SCROLLINFO](http://msdn.microsoft.com/library/windows/desktop/bb787537) estrutura.  
  
 `bRedraw`  
 Especifica se a barra de rolagem deve ser redesenhada para refletir as novas informações. Se `bRedraw` é **TRUE**, a barra de rolagem é redesenhada. Se for **FALSE**, ele não é redesenhado. A barra de rolagem é redesenhada por padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o retorno será **TRUE**. Caso contrário, ele será **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Você deve fornecer os valores necessários para o `SCROLLINFO` estrutura parâmetros, incluindo os valores de sinalizador.  
  
 O `SCROLLINFO` estrutura contém informações sobre uma barra, incluindo o mínimo e máximo de rolagem posições, o tamanho da página e a posição da caixa de rolagem (thumb) de rolagem. Consulte o [SCROLLINFO](http://msdn.microsoft.com/library/windows/desktop/bb787537) tópico estrutura o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre como alterar os padrões de estrutura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CScrollBar n º&3;](../../mfc/reference/codesnippet/cpp/cscrollbar-class_3.cpp)]  
  
##  <a name="setscrollpos"></a>CScrollBar::SetScrollPos  
 Define a posição atual de uma caixa de rolagem especificado por `nPos` e, se especificado, redesenha a barra de rolagem para refletir a nova posição.  
  
```  
int SetScrollPos(
    int nPos,  
    BOOL bRedraw = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 Especifica a nova posição da caixa de rolagem. Ele deve estar dentro do intervalo de rolagem.  
  
 `bRedraw`  
 Especifica se a barra de rolagem deve ser redesenhada para refletir a nova posição. Se `bRedraw` é **TRUE**, a barra de rolagem é redesenhada. Se for **FALSE**, ele não é redesenhado. A barra de rolagem é redesenhada por padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica a posição anterior da caixa de rolagem, se for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Definir `bRedraw` para **FALSE** sempre que a barra de rolagem será redesenhada por uma chamada subsequente para outra função para evitar que a barra de rolagem redesenhada duas vezes em um breve intervalo.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CScrollBar::SetScrollRange](#setscrollrange).  
  
##  <a name="setscrollrange"></a>CScrollBar::SetScrollRange  
 Define os valores mínimo e máximo de posição para a barra de rolagem determinado.  
  
```  
void SetScrollRange(
    int nMinPos,  
    int nMaxPos,  
    BOOL bRedraw = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMinPos`  
 Especifica o mínimo de posição de rolagem.  
  
 `nMaxPos`  
 Especifica o máximo de posição de rolagem.  
  
 `bRedraw`  
 Especifica se a barra de rolagem deve ser redesenhada para refletir a alteração. Se `bRedraw` é **TRUE**, a barra de rolagem é redesenhada; se **FALSE**, ele não é redesenhado. Ela é redesenhada por padrão.  
  
### <a name="remarks"></a>Comentários  
 Definir `nMinPos` e `nMaxPos` como 0 para ocultar as barras de rolagem padrão.  
  
 Não chame essa função para ocultar uma barra de rolagem ao processar uma mensagem de notificação da barra de rolagem.  
  
 Se uma chamada para `SetScrollRange` imediatamente após uma chamada para o `SetScrollPos` definir função de membro, `bRedraw` na `SetScrollPos` como 0 para impedir que a barra de rolagem sendo redesenhadas duas vezes.  
  
 A diferença entre os valores especificados pelo `nMinPos` e `nMaxPos` não deve ser maior que 32.767. O intervalo padrão para um controle de barra de rolagem está vazio (ambos `nMinPos` e `nMaxPos` são 0).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CScrollBar n º&4;](../../mfc/reference/codesnippet/cpp/cscrollbar-class_4.cpp)]  
  
##  <a name="showscrollbar"></a>CScrollBar::ShowScrollBar  
 Mostra ou oculta uma barra de rolagem.  
  
```  
void ShowScrollBar(BOOL bShow = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bShow`  
 Especifica se a barra de rolagem é mostrada ou ocultada. Se esse parâmetro for **TRUE**, a barra de rolagem é mostrada; caso contrário, ele é oculto.  
  
### <a name="remarks"></a>Comentários  
 Um aplicativo não deve chamar essa função para ocultar uma barra de rolagem ao processar uma mensagem de notificação da barra de rolagem.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CScrollBar::Create](#create).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CButton](../../mfc/reference/cbutton-class.md)   
 [Classe CComboBox](../../mfc/reference/ccombobox-class.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)   
 [Classe CStatic](../../mfc/reference/cstatic-class.md)   
 [Classe CDialog](../../mfc/reference/cdialog-class.md)

