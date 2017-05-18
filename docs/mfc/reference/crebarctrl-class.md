---
title: Classe CReBarCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- rebar controls, control bar
- rebar controls, CReBarCtrl class
- CReBarCtrl class
ms.assetid: 154570d7-e48c-425d-8c7e-c64542bcb4cc
caps.latest.revision: 23
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
ms.openlocfilehash: c1da4de2897c74e9cb25bc060033f4bd43159174
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CReBarCtrl::BeginDrag](#begindrag)|Coloca o controle rebar em modo de arrastar e soltar.|  
|[CReBarCtrl::Create](#create)|Cria um controle rebar e anexa-o para o `CReBarCtrl` objeto.|  
|[CReBarCtrl::CreateEx](#createex)|Cria um controle rebar com os estilos estendidos do Windows especificados e a anexa a um `CReBarCtrl` objeto.|  
|[CReBarCtrl::DeleteBand](#deleteband)|Exclui uma faixa de um controle rebar.|  
|[CReBarCtrl::DragMove](#dragmove)|Atualiza a posição de arrastar no controle rebar após uma chamada para `BeginDrag`.|  
|[CReBarCtrl::EndDrag](#enddrag)|Encerra a operação de arrastar e soltar do controle rebar.|  
|[CReBarCtrl::GetBandBorders](#getbandborders)|Recupera as bordas de uma faixa.|  
|[CReBarCtrl::GetBandCount](#getbandcount)|Recupera a contagem de faixas atualmente no controle rebar.|  
|[CReBarCtrl::GetBandInfo](#getbandinfo)|Recupera informações sobre uma faixa especificada em um controle rebar.|  
|[CReBarCtrl::GetBandMargins](#getbandmargins)|Recupera as margens de uma faixa.|  
|[CReBarCtrl::GetBarHeight](#getbarheight)|Recupera a altura do controle rebar.|  
|[CReBarCtrl::GetBarInfo](#getbarinfo)|Recupera informações sobre o controle rebar e usa a lista de imagens.|  
|[CReBarCtrl::GetBkColor](#getbkcolor)|Recupera a cor de plano de fundo de um controle rebar padrão.|  
|[CReBarCtrl::GetColorScheme](#getcolorscheme)|Recupera o [COLORSCHEME](http://msdn.microsoft.com/library/windows/desktop/bb775502) estrutura associada ao controle rebar.|  
|[CReBarCtrl::GetDropTarget](#getdroptarget)|Recupera um controle rebar `IDropTarget` ponteiro de interface.|  
|[CReBarCtrl::GetExtendedStyle](#getextendedstyle)|Obtém o estilo estendido do controle rebar atual.|  
|[CReBarCtrl::GetImageList](#getimagelist)|Recupera a lista de imagens associada a um controle rebar.|  
|[CReBarCtrl::GetPalette](#getpalette)|Recupera a paleta atual do controle rebar.|  
|[CReBarCtrl::GetRect](#getrect)|Recupera o retângulo delimitador para uma determinada faixa em um controle rebar.|  
|[CReBarCtrl::GetRowCount](#getrowcount)|Recupera o número de linhas de banda em um controle rebar.|  
|[CReBarCtrl::GetRowHeight](#getrowheight)|Recupera a altura de uma linha especificada em um controle rebar.|  
|[CReBarCtrl::GetTextColor](#gettextcolor)|Recupera a cor do texto de um controle rebar padrão.|  
|[CReBarCtrl::GetToolTips](#gettooltips)|Recupera o identificador para qualquer controle da dica de ferramenta associado ao controle rebar.|  
|[CReBarCtrl::HitTest](#hittest)|Determina qual parte de uma faixa rebar está em um determinado ponto na tela, se uma faixa rebar existir nesse ponto.|  
|[CReBarCtrl::IDToIndex](#idtoindex)|Converte um identificador (ID) de banda em um índice de banda em um controle rebar.|  
|[CReBarCtrl::InsertBand](#insertband)|Insere uma nova faixa em um controle rebar.|  
|[CReBarCtrl::MaximizeBand](#maximizeband)|Redimensiona uma faixa em um controle rebar ao seu tamanho máximo.|  
|[CReBarCtrl::MinimizeBand](#minimizeband)|Redimensiona uma faixa em um controle rebar ao tamanho menor.|  
|[CReBarCtrl::MoveBand](#moveband)|Move uma faixa de um índice para outro.|  
|[CReBarCtrl::PushChevron](#pushchevron)|Envia programaticamente uma divisa.|  
|[CReBarCtrl::RestoreBand](#restoreband)|Redimensiona uma faixa em um controle rebar ao seu tamanho ideal.|  
|[CReBarCtrl::SetBandInfo](#setbandinfo)|Define as características de uma banda existente em um controle rebar.|  
|[CReBarCtrl::SetBandWidth](#setbandwidth)|Define a largura da faixa especificada encaixada no controle rebar atual.|  
|[CReBarCtrl::SetBarInfo](#setbarinfo)|Define as características de um controle rebar.|  
|[CReBarCtrl::SetBkColor](#setbkcolor)|Define a cor de plano de fundo de um controle rebar padrão.|  
|[CReBarCtrl::SetColorScheme](#setcolorscheme)|Define o esquema de cores para os botões em um controle rebar.|  
|[CReBarCtrl::SetExtendedStyle](#setextendedstyle)|Define os estilos estendidos para o controle rebar atual.|  
|[CReBarCtrl::SetImageList](#setimagelist)|Define a lista de imagens de um controle rebar.|  
|[CReBarCtrl::SetOwner](#setowner)|Define a janela do proprietário de um controle rebar.|  
|[CReBarCtrl::SetPalette](#setpalette)|Define a paleta atual do controle rebar.|  
|[CReBarCtrl::SetTextColor](#settextcolor)|Define a cor do texto de um controle rebar padrão.|  
|[CReBarCtrl::SetToolTips](#settooltips)|Associa um controle de dica de ferramenta com o controle rebar.|  
|[CReBarCtrl::SetWindowTheme](#setwindowtheme)|Define o estilo visual do controle rebar.|  
|[CReBarCtrl::ShowBand](#showband)|Mostra ou oculta uma determinada faixa em um controle rebar.|  
|[CReBarCtrl::SizeToRect](#sizetorect)|Se encaixa em um controle rebar a um retângulo especificado.|  
  
## <a name="remarks"></a>Comentários  
 O aplicativo no qual reside o controle rebar atribui a janela filho contida pelo controle rebar para a faixa rebar. A janela filho é geralmente outro controle comum.  
  
 Controles rebar contêm uma ou mais faixas. Cada faixa pode conter uma combinação de uma barra dupla, um bitmap, um rótulo de texto e uma janela filho. A faixa pode conter apenas um de cada um desses itens.  
  
 O controle rebar pode exibir a janela filho em um bitmap de plano de fundo especificada. Todas as faixas de controle rebar podem ser redimensionadas, exceto aqueles que usam o **RBBS_FIXEDSIZE** estilo. Como você reposicionar ou redimensiona uma faixa do controle rebar, o controle rebar gerencia o tamanho e a posição da janela filho atribuída a essa faixa. Para redimensionar ou alterar a ordem das faixas no controle, clique e arraste a barra de garra da banda.  
  
 A ilustração a seguir mostra um controle rebar que tem três faixas:  
  
-   Banda 0 contém um controle de barra de ferramentas simples e transparente.  
  
-   Faixa 1 contém os dois botões transparente suspenso padrão e transparente.  
  
-   Banda 2 contém uma caixa de combinação e quatro botões padrão.  
  
     ![Exemplo de um menu Rebar](../../mfc/reference/media/vc4scc1.gif "vc4scc1")  
  
## <a name="rebar-control"></a>Controle rebar  
 Rebar suporte de controles:  
  
-   Listas de imagens.  
  
-   Tratamento de mensagens.  
  
-   Funcionalidade de desenho personalizado.  
  
-   Uma variedade de estilos de controle além dos estilos de janela padrão. Para obter uma lista desses estilos, consulte [estilos de controle Rebar](http://msdn.microsoft.com/library/windows/desktop/bb774377) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações, consulte [CReBarCtrl usando](../../mfc/using-crebarctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CReBarCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="begindrag"></a>CReBarCtrl::BeginDrag  
 Implementa o comportamento da mensagem Win32 [RB_BEGINDRAG](http://msdn.microsoft.com/library/windows/desktop/bb774429), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
void BeginDrag(
    UINT uBand,  
    DWORD dwPos = (DWORD)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero da faixa que afeta a operação de arrastar e soltar.  
  
 `dwPos`  
 Um `DWORD` valor que contém as coordenadas iniciais do mouse. A coordenada horizontal está contida na LOWORD e a coordenada vertical está contida no HIWORD. Se você passar `(DWORD)-1`, o controle rebar usará a posição do mouse na última vez em thread do controle chamado **GetMessage** ou **PeekMessage**.  
  
##  <a name="create"></a>CReBarCtrl::Create  
 Cria um controle rebar e anexa-o para o `CReBarCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica a combinação de estilos de controle rebar aplicado ao controle. Consulte [estilos de controle Rebar](http://msdn.microsoft.com/library/windows/desktop/bb774377) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de estilos com suporte.  
  
 `rect`  
 Uma referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura, que é a posição e o tamanho do controle rebar.  
  
 `pParentWnd`  
 Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle rebar. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID do controle do controle rebar  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto foi criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Crie um controle rebar em duas etapas:  
  
1.  Chamar [CReBarCtrl](#crebarctrl) para construir uma `CReBarCtrl` objeto.  
  
2.  Chame essa função de membro, que cria um controle rebar do Windows e anexa-o para o `CReBarCtrl` objeto.  
  
 Quando você chama **criar**, os controles comuns são inicializados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl n º&3;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_1.cpp)]  
  
##  <a name="createex"></a>CReBarCtrl::CreateEx  
 Cria um controle (uma janela filho) e o associa a `CReBarCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExStyle`  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o `dwExStyle` parâmetro [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwStyle`  
 Especifica a combinação de estilos de controle rebar aplicado ao controle. Para obter uma lista de estilos com suporte, consulte [estilos de controle Rebar](http://msdn.microsoft.com/library/windows/desktop/bb774377) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e a posição da janela deve ser criada, nas coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Um ponteiro para a janela que é o pai do controle.  
  
 `nID`  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido Windows **WS_EX_**.  
  
##  <a name="crebarctrl"></a>CReBarCtrl::CReBarCtrl  
 Cria um objeto `CReBarCtrl`.  
  
```  
CReBarCtrl();
```  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CReBarCtrl::Create](#create).  
  
##  <a name="deleteband"></a>CReBarCtrl::DeleteBand  
 Implementa o comportamento da mensagem Win32 [RB_DELETEBAND](http://msdn.microsoft.com/library/windows/desktop/bb774431), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
BOOL DeleteBand(UINT uBand);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero da faixa deve ser excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a banda excluído com êxito; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl n º&4;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_2.cpp)]  
  
##  <a name="dragmove"></a>CReBarCtrl::DragMove  
 Implementa o comportamento da mensagem Win32 [RB_DRAGMOVE](https://msdn.microsoft.com/library/bb774433.aspx), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
void DragMove(DWORD dwPos = (DWORD)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwPos`  
 Um `DWORD` valor que contém as novas coordenadas do mouse. A coordenada horizontal está contida na LOWORD e a coordenada vertical está contida no HIWORD. Se você passar `(DWORD)-1`, o controle rebar usará a posição do mouse na última vez em thread do controle chamado **GetMessage** ou **PeekMessage**.  
  
##  <a name="enddrag"></a>CReBarCtrl::EndDrag  
 Implementa o comportamento da mensagem Win32 [RB_ENDDRAG](http://msdn.microsoft.com/library/windows/desktop/bb774435), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
void EndDrag();
```  
  
##  <a name="getbandborders"></a>CReBarCtrl::GetBandBorders  
 Implementa o comportamento da mensagem Win32 [RB_GETBANDBORDERS](http://msdn.microsoft.com/library/windows/desktop/bb774437), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
void GetBandBorders(
    UINT uBand,  
    LPRECT prc) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero da faixa para a qual as bordas serão recuperadas.  
  
 `prc`  
 Um ponteiro para um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que receberá as bordas de banda. Se o controle rebar tem o **RBS_BANDBORDERS** estilo, cada membro dessa estrutura receberá o número de pixels, no lado do correspondente da faixa, que constituem a borda. Se não tiver um controle rebar o **RBS_BANDBORDERS** de estilo, somente o membro esquerdo dessa estrutura recebe informações válidas. Para obter uma descrição dos estilos de controle rebar, consulte [estilos de controle Rebar](http://msdn.microsoft.com/library/windows/desktop/bb774377) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getbandcount"></a>CReBarCtrl::GetBandCount  
 Implementa o comportamento da mensagem Win32 [RB_GETBANDCOUNT](http://msdn.microsoft.com/library/windows/desktop/bb774439), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
UINT GetBandCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de faixas atribuído ao controle.  
  
##  <a name="getbandinfo"></a>CReBarCtrl::GetBandInfo  
 Implementa o comportamento da mensagem Win32 [RB_GETBANDINFO](http://msdn.microsoft.com/library/windows/desktop/bb774451) conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
BOOL GetBandInfo(
    UINT uBand,  
    REBARBANDINFO* prbbi) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero da faixa para o qual as informações serão recuperadas.  
  
 `prbbi`  
 Um ponteiro para um [REBARBANDINFO](http://msdn.microsoft.com/library/windows/desktop/bb774393) estrutura para receber as informações de faixa. Você deve definir o `cbSize` membro dessa estrutura para `sizeof(REBARBANDINFO)` e defina o **fMask** membro para os itens que você deseja recuperar antes de enviar esta mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
##  <a name="getbandmargins"></a>CReBarCtrl::GetBandMargins  
 Recupera as margens da faixa.  
  
```  
void GetBandMargins(PMARGINS pMargins);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pMargins*  
 Um ponteiro para um [MARGENS](http://msdn.microsoft.com/library/windows/desktop/bb773244)estrutura que receberá as informações.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade do [RB_GETBANDMARGINS](http://msdn.microsoft.com/library/windows/desktop/bb774453) mensagem, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getbarheight"></a>CReBarCtrl::GetBarHeight  
 Recupera a altura da barra de ferramentas rebar.  
  
```  
UINT GetBarHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Valor que representa a altura, em pixels, do controle.  
  
##  <a name="getbarinfo"></a>CReBarCtrl::GetBarInfo  
 Implementa o comportamento da mensagem Win32 [RB_GETBARINFO](http://msdn.microsoft.com/library/windows/desktop/bb774457), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
BOOL GetBarInfo(REBARINFO* prbi) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `prbi`  
 Um ponteiro para um [REBARINFO](http://msdn.microsoft.com/library/windows/desktop/bb774395) estrutura que receberá as informações de controle rebar. Você deve definir o `cbSize` membro dessa estrutura para `sizeof(REBARINFO)` antes de enviar esta mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
##  <a name="getbkcolor"></a>CReBarCtrl::GetBkColor  
 Implementa o comportamento da mensagem Win32 [RB_GETBKCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb774459), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
COLORREF GetBkColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **COLORREF** valor que representam a cor de plano de fundo padrão atual.  
  
##  <a name="getcolorscheme"></a>CReBarCtrl::GetColorScheme  
 Recupera o [COLORSCHEME](http://msdn.microsoft.com/library/windows/desktop/bb775502) estrutura do controle rebar.  
  
```  
BOOL GetColorScheme(COLORSCHEME* lpcs);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpcs`  
 Um ponteiro para um [COLORSCHEME](http://msdn.microsoft.com/library/windows/desktop/bb775502) estrutura, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 O **COLORSCHEME** estrutura inclui a cor de realce do botão e a cor da sombra de botão.  
  
##  <a name="getdroptarget"></a>CReBarCtrl::GetDropTarget  
 Implementa o comportamento da mensagem Win32 [RB_GETDROPTARGET](http://msdn.microsoft.com/library/windows/desktop/bb774463), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
IDropTarget* GetDropTarget() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679) interface.  
  
##  <a name="getextendedstyle"></a>CReBarCtrl::GetExtendedStyle  
 Obtém os estilos estendidos do controle rebar atual.  
  
```  
DWORD GetExtendedStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação bit a bit (OR) de sinalizadores que indicam os estilos estendidos. Os possíveis sinalizadores são `RBS_EX_SPLITTER` e `RBS_EX_TRANSPARENT`. Para obter mais informações, consulte o `dwMask` parâmetro o [CReBarCtrl::SetExtendedStyle](#setextendedstyle) método.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [RB_GETEXTENDEDSTYLE](http://msdn.microsoft.com/library/windows/desktop/bb774433) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getimagelist"></a>CReBarCtrl::GetImageList  
 Obtém o `CImageList` objeto associado a um controle rebar.  
  
```  
CImageList* GetImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto. Retorna **nulo** se nenhuma lista de imagens é definida para o controle.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro usa informações de tamanho e a máscara armazenadas na [REBARINFO](http://msdn.microsoft.com/library/windows/desktop/bb774395) estrutura, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getpalette"></a>CReBarCtrl::GetPalette  
 Recupera a paleta atual do controle rebar.  
  
```  
CPalette* GetPalette() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CPalette](../../mfc/reference/cpalette-class.md) objeto que especifica a paleta atual do controle rebar.  
  
### <a name="remarks"></a>Comentários  
 Observe que essa função de membro usa um `CPalette` objeto como valor de retorno, em vez de um `HPALETTE`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl n º&5;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_3.cpp)]  
  
##  <a name="getrect"></a>CReBarCtrl::GetRect  
 Implementa o comportamento da mensagem Win32 [RB_GETRECT](http://msdn.microsoft.com/library/windows/desktop/bb774469), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
BOOL GetRect(
    UINT uBand,  
    LPRECT prc) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero de uma faixa em um controle rebar.  
  
 `prc`  
 Um ponteiro para um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que receberá os limites da faixa rebar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl n º&6;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_4.cpp)]  
  
##  <a name="getrowcount"></a>CReBarCtrl::GetRowCount  
 Implementa o comportamento da mensagem Win32 [RB_GETROWCOUNT](http://msdn.microsoft.com/library/windows/desktop/bb774471), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
UINT GetRowCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **UINT** valor que representa o número de linhas de banda no controle.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl&#7;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_5.cpp)]  
  
##  <a name="getrowheight"></a>CReBarCtrl::GetRowHeight  
 Implementa o comportamento da mensagem Win32 [RB_GETROWHEIGHT](http://msdn.microsoft.com/library/windows/desktop/bb774473), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
UINT GetRowHeight(UINT uRow) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *uRow*  
 Índice baseado em zero da faixa que terá sua altura recuperada.  
  
### <a name="return-value"></a>Valor de retorno  
 A **UINT** valor que representa a altura da linha, em pixels.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl n º&8;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_6.cpp)]  
  
##  <a name="gettextcolor"></a>CReBarCtrl::GetTextColor  
 Implementa o comportamento da mensagem Win32 [RB_GETTEXTCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb774475), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
COLORREF GetTextColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **COLORREF** valor que representam a cor do texto padrão.  
  
##  <a name="gettooltips"></a>CReBarCtrl::GetToolTips  
 Implementa o comportamento da mensagem Win32 [RB_GETTOOLTIPS](http://msdn.microsoft.com/library/windows/desktop/bb774477), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
CToolTipCtrl* GetToolTips() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Observe que a implementação do MFC de `GetToolTips` retorna um ponteiro para um `CToolTipCtrl`, em vez de um `HWND`.  
  
##  <a name="hittest"></a>CReBarCtrl::HitTest  
 Implementa o comportamento da mensagem Win32 [RB_HITTEST](http://msdn.microsoft.com/library/windows/desktop/bb774494), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
int HitTest(RBHITTESTINFO* prbht);
```  
  
### <a name="parameters"></a>Parâmetros  
 *prbht*  
 Um ponteiro para um [RBHITTESTINFO](http://msdn.microsoft.com/library/windows/desktop/bb774391) estrutura. Antes de enviar a mensagem, o **pt** membro dessa estrutura deve ser inicializado até o ponto que será testado nas coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da faixa em determinado ponto, ou -1 se nenhuma banda rebar foi no ponto.  
  
##  <a name="idtoindex"></a>CReBarCtrl::IDToIndex  
 Implementa o comportamento da mensagem Win32 [RB_IDTOINDEX](http://msdn.microsoft.com/library/windows/desktop/bb774496), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
int IDToIndex(UINT uBandID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *uBandID*  
 O identificador da faixa especificada, definido pelo aplicativo passado a **wID** membro do [REBARBANDINFO](http://msdn.microsoft.com/library/windows/desktop/bb774393) estrutura quando a faixa é inserida.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de banda com base em zero se tiver êxito, ou -1 caso contrário. Se existem índices duplicados de banda, o primeiro deles é retornado.  
  
##  <a name="insertband"></a>CReBarCtrl::InsertBand  
 Implementa o comportamento da mensagem Win32 [RB_INSERTBAND](http://msdn.microsoft.com/library/windows/desktop/bb774498), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
BOOL InsertBand(
    UINT uIndex,  
    REBARBANDINFO* prbbi);
```  
  
### <a name="parameters"></a>Parâmetros  
 *uIndex*  
 Índice baseado em zero do local onde a faixa será inserida. Se você definir esse parâmetro como -1, o controle irá adicionar a nova faixa no último local.  
  
 `prbbi`  
 Um ponteiro para um [REBARBANDINFO](http://msdn.microsoft.com/library/windows/desktop/bb774393) estrutura que define a banda a ser inserido. Você deve definir o `cbSize` membro dessa estrutura para `sizeof(REBARBANDINFO)` antes de chamar essa função.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl n º&9;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_7.cpp)]  
  
##  <a name="maximizeband"></a>CReBarCtrl::MaximizeBand  
 Redimensiona uma faixa em um controle rebar ao seu tamanho máximo.  
  
```  
void MaximizeBand(UINT uBand);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero da faixa para ser maximizada.  
  
### <a name="remarks"></a>Comentários  
 Implementa o comportamento da mensagem Win32 [RB_MAXIMIZEBAND](http://msdn.microsoft.com/library/windows/desktop/bb774500) com `fIdeal` definido como 0, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl n º&10;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_8.cpp)]  
  
##  <a name="minimizeband"></a>CReBarCtrl::MinimizeBand  
 Redimensiona uma faixa em um controle rebar ao tamanho menor.  
  
```  
void MinimizeBand(UINT uBand);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero da faixa a ser minimizada.  
  
### <a name="remarks"></a>Comentários  
 Implementa o comportamento da mensagem Win32 [RB_MINIMIZEBAND](http://msdn.microsoft.com/library/windows/desktop/bb774502), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl n º&11;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_9.cpp)]  
  
##  <a name="moveband"></a>CReBarCtrl::MoveBand  
 Implementa o comportamento da mensagem Win32 [RB_MOVEBAND](http://msdn.microsoft.com/library/windows/desktop/bb774504), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
BOOL MoveBand(
    UINT uFrom,  
    UINT uTo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *uFrom*  
 Índice baseado em zero da faixa a ser movido.  
  
 *Automática*  
 Índice baseado em zero da nova posição de banda. Esse valor de parâmetro nunca deve ser maior que o número de faixas menos um. Para obter o número de faixas, chame [GetBandCount](#getbandcount).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
##  <a name="pushchevron"></a>CReBarCtrl::PushChevron  
 Implementa o comportamento da mensagem Win32 [RB_PUSHCHEVRON](http://msdn.microsoft.com/library/windows/desktop/bb774506), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
void PushChevron(
    UINT uBand,  
    LPARAM lAppValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero da faixa cuja divisa tiver de ser transferido.  
  
 `lAppValue`  
 Um aplicativo definido pelo valor de 32 bits. Consulte `lAppValue` na [RB_PUSHCHEVRON](http://msdn.microsoft.com/library/windows/desktop/bb774506) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="restoreband"></a>CReBarCtrl::RestoreBand  
 Redimensiona uma faixa em um controle rebar ao seu tamanho ideal.  
  
```  
void RestoreBand(UINT uBand);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero da faixa para ser maximizada.  
  
### <a name="remarks"></a>Comentários  
 Implementa o comportamento da mensagem Win32 [RB_MAXIMIZEBAND](http://msdn.microsoft.com/library/windows/desktop/bb774500) com `fIdeal` definido como 1, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl&#12;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_10.cpp)]  
  
##  <a name="setbandinfo"></a>CReBarCtrl::SetBandInfo  
 Implementa o comportamento da mensagem Win32 [RB_SETBANDINFO](http://msdn.microsoft.com/library/windows/desktop/bb774508), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
BOOL SetBandInfo(
    UINT uBand,  
    REBARBANDINFO* prbbi);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero da faixa para receber as novas configurações.  
  
 `prbbi`  
 Ponteiro para uma [REBARBANDINFO](http://msdn.microsoft.com/library/windows/desktop/bb774393) estrutura que define a banda a ser inserido. Você deve definir o `cbSize` membro dessa estrutura para `sizeof(REBARBANDINFO)` antes de enviar esta mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl&13;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_11.cpp)]  
  
##  <a name="setbandwidth"></a>CReBarCtrl::SetBandWidth  
 Define a largura da faixa especificada encaixada no controle rebar atual.  
  
```  
BOOL SetBandWidth(
    UINT uBand,   
    int cxWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `uBand`|Índice baseado em zero de uma faixa rebar.|  
|[in] `cxWidth`|Nova largura de banda rebar, em pixels.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método for bem-sucedido; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [RB_SETBANDWIDTH](http://msdn.microsoft.com/library/windows/desktop/bb774511) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_rebar`, que é usado para acessar o controle rebar atual. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CReBarCtrl_s1 n º&1;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_12.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define cada faixa rebar tenha a mesma largura.  
  
 [!code-cpp[NVC_MFC_CReBarCtrl_s1 n º&2;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_13.cpp)]  
  
##  <a name="setbarinfo"></a>CReBarCtrl::SetBarInfo  
 Implementa o comportamento da mensagem Win32 [RB_SETBARINFO](http://msdn.microsoft.com/library/windows/desktop/bb774513), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
BOOL SetBarInfo(REBARINFO* prbi);
```  
  
### <a name="parameters"></a>Parâmetros  
 `prbi`  
 Um ponteiro para um [REBARINFO](http://msdn.microsoft.com/library/windows/desktop/bb774395) estrutura que contém as informações a ser definido. Você deve definir o `cbSize` membro dessa estrutura para `sizeof(REBARINFO)` antes de enviar esta mensagem  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl&#14;](../../mfc/reference/codesnippet/cpp/crebarctrl-class_14.cpp)]  
  
##  <a name="setbkcolor"></a>CReBarCtrl::SetBkColor  
 Implementa o comportamento da mensagem Win32 [RB_SETBKCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb774515), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
COLORREF SetBkColor(COLORREF clr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clr`  
 O **COLORREF** valor que representa a nova cor de plano de fundo padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 A [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que representa a cor de plano de fundo padrão anterior.  
  
### <a name="remarks"></a>Comentários  
 Consulte este tópico para obter mais informações sobre quando definir a cor de plano de fundo e como definir o padrão.  
  
##  <a name="setcolorscheme"></a>CReBarCtrl::SetColorScheme  
 Define o esquema de cores para os botões em um controle rebar.  
  
```  
void SetColorScheme(const COLORSCHEME* lpcs);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpcs`  
 Um ponteiro para um [COLORSCHEME](http://msdn.microsoft.com/library/windows/desktop/bb775502) estrutura, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 O **COLORSCHEME** estrutura inclui a cor de realce do botão e a cor da sombra de botão.  
  
##  <a name="setextendedstyle"></a>CReBarCtrl::SetExtendedStyle  
 Define os estilos estendidos para o controle rebar atual.  
  
```  
DWORD SetExtendedStyle(
    DWORD dwMask,   
    DWORD dwStyleEx);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `dwMask`|Uma combinação bit a bit (OR) de sinalizadores que especificam quais sinalizadores no `dwStyleEx` parâmetro se aplica. Use um ou mais dos seguintes valores:<br /><br /> RBS_EX_SPLITTER: Por padrão, mostra o divisor na parte inferior no modo horizontal e para a direita no modo vertical.<br /><br /> RBS_EX_TRANSPARENT: Encaminhar o [WM_ERASEBKGND](http://msdn.microsoft.com/library/windows/desktop/ms648055) mensagem para a janela pai.|  
|[in] `dwStyleEx`|Uma combinação bit a bit (OR) de sinalizadores que especificam os aplicar os estilos. Para definir um estilo, especifique o mesmo sinalizador é usado no `dwMask` parâmetro. Para redefinir um estilo, especifique zero binário.|  
  
### <a name="return-value"></a>Valor de retorno  
 O estilo estendido anterior.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [RB_SETEXTENDEDSTYLE](http://msdn.microsoft.com/library/windows/desktop/bb774519) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setimagelist"></a>CReBarCtrl::SetImageList  
 Atribui uma lista de imagens para um controle rebar.  
  
```  
BOOL SetImageList(CImageList* pImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pImageList`  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto que contém a lista de imagens a ser atribuído a controle rebar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
##  <a name="setowner"></a>CReBarCtrl::SetOwner  
 Implementa o comportamento da mensagem Win32 [RB_SETPARENT](http://msdn.microsoft.com/library/windows/desktop/bb774522), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
CWnd* SetOwner(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Um ponteiro para um `CWnd` objeto para definir como o proprietário do controle rebar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é o proprietário atual do controle rebar.  
  
### <a name="remarks"></a>Comentários  
 Observe que essa função de membro usa ponteiros para `CWnd` objetos para o proprietário atual e selecionado do controle rebar, em vez de identificadores para windows.  
  
> [!NOTE]
>  Essa função de membro não altera o pai real que foi definido quando o controle foi criado; em vez disso, ele envia mensagens de notificação para a janela que você especificar.  
  
##  <a name="setpalette"></a>CReBarCtrl::SetPalette  
 Implementa o comportamento da mensagem Win32 [RB_SETPALETTE](http://msdn.microsoft.com/library/windows/desktop/bb774520), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
CPalette* SetPalette(HPALETTE hPal);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hPal*  
 Um `HPALETTE` que especifica a nova paleta que irá usar o controle rebar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CPalette](../../mfc/reference/cpalette-class.md) objeto especificando paleta anterior do controle rebar.  
  
### <a name="remarks"></a>Comentários  
 Observe que essa função de membro usa um `CPalette` objeto como valor de retorno, em vez de um `HPALETTE`.  
  
##  <a name="settextcolor"></a>CReBarCtrl::SetTextColor  
 Implementa o comportamento da mensagem Win32 [RB_SETTEXTCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb774524), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
COLORREF SetTextColor(COLORREF clr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clr`  
 A **COLORREF** valor que representa o novo texto de cor `CReBarCtrl` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 O [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que representa a cor do texto anterior associado a `CReBarCtrl` objeto.  
  
### <a name="remarks"></a>Comentários  
 Ele é fornecido para dar suporte a flexibilidade de cor do texto em um controle rebar.  
  
##  <a name="settooltips"></a>CReBarCtrl::SetToolTips  
 Associa um controle de dica de ferramenta com um controle rebar.  
  
```  
void SetToolTips(CToolTipCtrl* pToolTip);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pToolTip*  
 Um ponteiro para um [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) objeto  
  
### <a name="remarks"></a>Comentários  
 Você deve destruir o `CToolTipCtrl` objeto quando tiver terminado com ele.  
  
##  <a name="setwindowtheme"></a>CReBarCtrl::SetWindowTheme  
 Define o estilo visual do controle rebar.  
  
```  
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszSubAppName`  
 Um ponteiro para uma cadeia de caracteres Unicode que contém o estilo visual rebar definir.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno não é usado.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade do [RB_SETWINDOWTHEME](http://msdn.microsoft.com/library/windows/desktop/bb774530) mensagem, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="showband"></a>CReBarCtrl::ShowBand  
 Implementa o comportamento da mensagem Win32 [RB_SHOWBAND](http://msdn.microsoft.com/library/windows/desktop/bb774532), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
BOOL ShowBand(
    UINT uBand,  
    BOOL fShow = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uBand`  
 Índice baseado em zero de uma faixa em um controle rebar.  
  
 *fShow*  
 Indica se a faixa deve ser mostrada ou ocultada. Se esse valor for **TRUE**, a faixa será mostrada. Caso contrário, a faixa será ocultada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
##  <a name="sizetorect"></a>CReBarCtrl::SizeToRect  
 Implementa o comportamento da mensagem Win32 [RB_SIZETORECT](http://msdn.microsoft.com/library/windows/desktop/bb774534), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
```  
BOOL SizeToRect(CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Uma referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica o retângulo que o controle rebar deve ser dimensionado para.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Observe que essa função de membro usa um `CRect` objeto como um parâmetro, em vez de uma `RECT` estrutura.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)



