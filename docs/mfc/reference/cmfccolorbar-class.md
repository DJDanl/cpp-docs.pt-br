---
title: Classe CMFCColorBar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCColorBar
- AFXCOLORBAR/CMFCColorBar
- AFXCOLORBAR/CMFCColorBar::CMFCColorBar
- AFXCOLORBAR/CMFCColorBar::ContextToSize
- AFXCOLORBAR/CMFCColorBar::CreateControl
- AFXCOLORBAR/CMFCColorBar::Create
- AFXCOLORBAR/CMFCColorBar::EnableAutomaticButton
- AFXCOLORBAR/CMFCColorBar::EnableOtherButton
- AFXCOLORBAR/CMFCColorBar::GetColor
- AFXCOLORBAR/CMFCColorBar::GetCommandID
- AFXCOLORBAR/CMFCColorBar::GetHighlightedColor
- AFXCOLORBAR/CMFCColorBar::GetHorzMargin
- AFXCOLORBAR/CMFCColorBar::GetVertMargin
- AFXCOLORBAR/CMFCColorBar::IsTearOff
- AFXCOLORBAR/CMFCColorBar::SetColor
- AFXCOLORBAR/CMFCColorBar::SetColorName
- AFXCOLORBAR/CMFCColorBar::SetCommandID
- AFXCOLORBAR/CMFCColorBar::SetDocumentColors
- AFXCOLORBAR/CMFCColorBar::SetHorzMargin
- AFXCOLORBAR/CMFCColorBar::SetVertMargin
- AFXCOLORBAR/CMFCColorBar::AdjustLocations
- AFXCOLORBAR/CMFCColorBar::AllowChangeTextLabels
- AFXCOLORBAR/CMFCColorBar::AllowShowOnList
- AFXCOLORBAR/CMFCColorBar::CalcSize
- AFXCOLORBAR/CMFCColorBar::CreatePalette
- AFXCOLORBAR/CMFCColorBar::GetColorGridSize
- AFXCOLORBAR/CMFCColorBar::GetExtraHeight
- AFXCOLORBAR/CMFCColorBar::InitColors
- AFXCOLORBAR/CMFCColorBar::OnKey
- AFXCOLORBAR/CMFCColorBar::OnSendCommand
- AFXCOLORBAR/CMFCColorBar::OnUpdateCmdUI
- AFXCOLORBAR/CMFCColorBar::OpenColorDialog
- AFXCOLORBAR/CMFCColorBar::Rebuild
- AFXCOLORBAR/CMFCColorBar::SelectPalette
- AFXCOLORBAR/CMFCColorBar::SetPropList
- AFXCOLORBAR/CMFCColorBar::ShowCommandMessageString
dev_langs:
- C++
helpviewer_keywords:
- CMFCColorBar [MFC], CMFCColorBar
- CMFCColorBar [MFC], ContextToSize
- CMFCColorBar [MFC], CreateControl
- CMFCColorBar [MFC], Create
- CMFCColorBar [MFC], EnableAutomaticButton
- CMFCColorBar [MFC], EnableOtherButton
- CMFCColorBar [MFC], GetColor
- CMFCColorBar [MFC], GetCommandID
- CMFCColorBar [MFC], GetHighlightedColor
- CMFCColorBar [MFC], GetHorzMargin
- CMFCColorBar [MFC], GetVertMargin
- CMFCColorBar [MFC], IsTearOff
- CMFCColorBar [MFC], SetColor
- CMFCColorBar [MFC], SetColorName
- CMFCColorBar [MFC], SetCommandID
- CMFCColorBar [MFC], SetDocumentColors
- CMFCColorBar [MFC], SetHorzMargin
- CMFCColorBar [MFC], SetVertMargin
- CMFCColorBar [MFC], AdjustLocations
- CMFCColorBar [MFC], AllowChangeTextLabels
- CMFCColorBar [MFC], AllowShowOnList
- CMFCColorBar [MFC], CalcSize
- CMFCColorBar [MFC], CreatePalette
- CMFCColorBar [MFC], GetColorGridSize
- CMFCColorBar [MFC], GetExtraHeight
- CMFCColorBar [MFC], InitColors
- CMFCColorBar [MFC], OnKey
- CMFCColorBar [MFC], OnSendCommand
- CMFCColorBar [MFC], OnUpdateCmdUI
- CMFCColorBar [MFC], OpenColorDialog
- CMFCColorBar [MFC], Rebuild
- CMFCColorBar [MFC], SelectPalette
- CMFCColorBar [MFC], SetPropList
- CMFCColorBar [MFC], ShowCommandMessageString
ms.assetid: 4756ee40-25a5-4cee-af7f-acab7993d1c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2083c26943768afff4b3b20a2ba95c709648dd50
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmfccolorbar-class"></a>Classe CMFCColorBar
O `CMFCColorBar` classe representa uma barra de controle Ancorável que pode selecionar as cores em um documento ou aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCColorBar : public CMFCPopupMenuBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorBar::CMFCColorBar](#cmfccolorbar)|Constrói um objeto `CMFCColorBar`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorBar::ContextToSize](#contexttosize)|Calcula as margens horizontais e verticais que são necessárias para conter os botões no controle de barra de cores e, em seguida, ajusta o local desses botões.|  
|[CMFCColorBar::CreateControl](#createcontrol)|Cria uma janela de controle de barra de cores, anexa-o para o `CMFCColorBar` de objeto e redimensiona o controle para conter a paleta de cores especificada.|  
|[CMFCColorBar::Create](#create)|Cria uma janela de controle de barra de cores e anexa-o para o `CMFCColorBar` objeto.|  
|[CMFCColorBar::EnableAutomaticButton](#enableautomaticbutton)|Mostra ou oculta o botão automático.|  
|[CMFCColorBar::EnableOtherButton](#enableotherbutton)|Habilita ou desabilita a exibição de uma caixa de diálogo que permite que o usuário selecione mais cores.|  
|[CMFCColorBar::GetColor](#getcolor)|Recupera a cor atualmente selecionada.|  
|[CMFCColorBar::GetCommandID](#getcommandid)|Recupera a ID de comando do controle de barra de cor atual.|  
|[CMFCColorBar::GetHighlightedColor](#gethighlightedcolor)|Recupera a cor que indica se um botão de cor tem foco. ou seja, o botão é *hot*.|  
|[CMFCColorBar::GetHorzMargin](#gethorzmargin)|Recupera a margem horizontal, que é o espaço entre à esquerda ou célula à direita de cor e o limite de área de cliente.|  
|[CMFCColorBar::GetVertMargin](#getvertmargin)|Recupera a margem vertical, que é o espaço entre a parte superior ou célula de cor inferior e o limite da área cliente.|  
|[CMFCColorBar::IsTearOff](#istearoff)|Indica se a barra de cores atual é encaixável.|  
|[CMFCColorBar::SetColor](#setcolor)|Define a cor atualmente selecionada.|  
|[CMFCColorBar::SetColorName](#setcolorname)|Define um novo nome para uma cor especificada.|  
|[CMFCColorBar::SetCommandID](#setcommandid)|Define uma nova ID de comando para um controle de barra de cores.|  
|[CMFCColorBar::SetDocumentColors](#setdocumentcolors)|Define a lista de cores que são usados no documento atual.|  
|[CMFCColorBar::SetHorzMargin](#sethorzmargin)|Define a margem horizontal, que é o espaço entre à esquerda ou célula à direita de cor e o limite de área de cliente.|  
|[CMFCColorBar::SetVertMargin](#setvertmargin)|Define a margem vertical, que é o espaço entre a célula de cor superior ou inferior e o limite de área do cliente.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorBar::AdjustLocations](#adjustlocations)|Ajusta as posições dos botões de cor no controle de barra de cores.|  
|[CMFCColorBar::AllowChangeTextLabels](#allowchangetextlabels)|Indica se o rótulo de texto dos botões de cor pode alterar.|  
|[CMFCColorBar::AllowShowOnList](#allowshowonlist)|Indica se o objeto de controle de barra de cores pode aparecer em uma lista de ferramentas durante o processo de personalização.|  
|[CMFCColorBar::CalcSize](#calcsize)|Chamado pelo framework como parte do processo de cálculo de layout.|  
|[CMFCColorBar::CreatePalette](#createpalette)|Inicializa uma paleta com as cores em uma matriz de cores especificada.|  
|[CMFCColorBar::GetColorGridSize](#getcolorgridsize)|Calcula o número de linhas e colunas na grade de um controle de barra de cores.|  
|[CMFCColorBar::GetExtraHeight](#getextraheight)|Calcula a altura adicional que requer que a barra de cores atual para exibir os elementos de interface de usuário diversos, como o **outros** botão, cores de documento e assim por diante.|  
|[CMFCColorBar::InitColors](#initcolors)|Inicializa uma matriz de cores com as cores na paleta padrão do sistema ou de uma paleta especificada.|  
|[CMFCColorBar::OnKey](#onkey)|Chamado pelo framework quando um usuário pressiona um botão do teclado.|  
|[CMFCColorBar::OnSendCommand](#onsendcommand)|Chamado pelo framework para fechar uma hierarquia de controles de pop-up.|  
|[CMFCColorBar::OnUpdateCmdUI](#onupdatecmdui)|Chamado pelo framework para habilitar ou desabilitar um item de interface do usuário de um controle de barra de cores para que o item é exibido.|  
|[CMFCColorBar::OpenColorDialog](#opencolordialog)|Abre uma caixa de diálogo de cor.|  
|[CMFCColorBar::Rebuild](#rebuild)|Redesenha completamente o controle de barra de cores.|  
|[CMFCColorBar::SelectPalette](#selectpalette)|Define a paleta lógica do contexto do dispositivo especificado para a paleta do botão pai do controle de barra de cor atual.|  
|[CMFCColorBar::SetPropList](#setproplist)|Define o `m_pWndPropList` protegido membro de dados para o ponteiro especificado para um controle de grade de propriedade.|  
|[CMFCColorBar::ShowCommandMessageString](#showcommandmessagestring)|Solicita a janela do quadro que possui o controle de barra de cores para atualizar a linha de mensagem na barra de status.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`m_bInternal`|Um campo booleano que determina se os eventos de mouse são processados. Normalmente, os eventos de mouse são processados quando esse campo é `TRUE` e modo de personalização é `FALSE`.|  
|`m_bIsEnabled`|Um booliano que indica se um controle está habilitado.|  
|`m_bIsTearOff`|Um booliano que indica se o controle de barra de cores oferece suporte de encaixe.|  
|`m_BoxSize`|Um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que especifica o tamanho de uma célula em uma grade na barra de cores.|  
|`m_bShowDocColorsWhenDocked`|Um booliano que indica se as cores do documento quando a barra de cores é encaixada. Para obter mais informações, consulte [CMFCColorBar::SetDocumentColors](#setdocumentcolors).|  
|`m_bStdColorDlg`|Um valor booleano que indica se a caixa de diálogo de cor padrão do sistema ou o [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo. Para obter mais informações, consulte [CMFCColorBar::EnableOtherButton](#enableotherbutton).|  
|`m_ColorAutomatic`|Um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) que armazena a cor automática atual. Para obter mais informações, consulte [CMFCColorBar::EnableOtherButton](#enableotherbutton).|  
|`m_ColorNames`|Um [CMap](../../mfc/reference/cmap-class.md) cores com seus nomes de objeto que associa um conjunto de RGB.|  
|`m_colors`|Um [CArray](../../mfc/reference/carray-class.md) de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valores que contém as cores que são exibidas no controle de barra de cores.|  
|`m_ColorSelected`|Um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que é a cor que o usuário atualmente selecionado do controle de barra de cores.|  
|`m_lstDocColors`|Um [CList](../../mfc/reference/clist-class.md) de [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valores que contém as cores que estão sendo usadas em um documento.|  
|`m_nCommandID`|Um inteiro sem sinal que é a ID de comando de um botão de cor.|  
|`m_nHorzMargin`|Um inteiro que é a margem horizontal entre os botões de cor em uma grade de cores.|  
|`m_nHorzOffset`|Um inteiro que é o deslocamento horizontal para o centro do botão de cor. Esse valor é significativo se o botão exibe o texto ou uma imagem, além de uma cor.|  
|`m_nNumColumns`|Um inteiro que indica o número de colunas em uma grade de controle de barra de cores de cores.|  
|`m_nNumColumnsVert`|Um inteiro que indica o número de colunas em uma grade orientação vertical de cores.|  
|`m_nNumRowsHorz`|Um inteiro que indica o número de colunas em uma grade orientação horizontal de cores.|  
|`m_nRowHeight`|Um inteiro que representa a altura de uma linha de botões de cor em uma grade de cores.|  
|`m_nVertMargin`|Um inteiro que é a margem vertical entre os botões de cor em uma grade de cores.|  
|`m_nVertOffset`|Um inteiro que é o deslocamento vertical para o centro do botão de cor. Esse valor é significativo se o botão exibe o texto ou uma imagem, além de uma cor.|  
|`m_Palette`|Um [CPalette](../../mfc/reference/cpalette-class.md) das cores que são usadas no controle de barra de cores.|  
|`m_pParentBtn`|Um ponteiro para um [CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md) objeto que é o pai do botão atual. Esse valor é significativo se o botão de cor está em uma hierarquia de controles de barra de ferramentas ou em um controle de grade de propriedade de cor.|  
|`m_pParentRibbonBtn`|Um ponteiro para um [CMFCRibbonColorButton](../../mfc/reference/cmfcribboncolorbutton-class.md) objeto na faixa de opções e é o pai do botão atual. Esse valor é significativo se o botão de cor está em uma hierarquia de controles de barra de ferramentas ou em um controle de grade de propriedade de cor.|  
|`m_pWndPropList`|Um ponteiro para um [CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) objeto.|  
|`m_strAutoColor`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido no **automáticas** botão. Para obter mais informações, consulte [CMFCColorBar::EnableAutomaticButton](#enableautomaticbutton).|  
|`m_strDocColors`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido no botão de cores do documento. Para obter mais informações, consulte [CMFCColorBar::SetDocumentColors](#setdocumentcolors).|  
|`m_strOtherColor`|Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que é o texto que é exibido no *outros* botão. Para obter mais informações, consulte [CMFCColorBar::EnableOtherButton](#enableotherbutton).|  
  
## <a name="remarks"></a>Comentários  
 Normalmente, você não criar um `CMFCColorBar` diretamente do objeto. Em vez disso, o [CMFCColorMenuButton classe](../../mfc/reference/cmfccolormenubutton-class.md) (usado em menus e barras de ferramentas) ou o [CMFCColorButton classe](../../mfc/reference/cmfccolorbutton-class.md) cria o `CMFCColorBar` objeto.  
  
 O `CMFCColorBar` classe fornece a seguinte funcionalidade:  
  
-   Ajusta automaticamente a lista de cores do documento.  
  
-   Salva e restaura o estado, junto com o estado do documento.  
  
-   Gerencia o botão "automático".  
  
-   Usa o [CMFCColorPickerCtrl classe](../../mfc/reference/cmfccolorpickerctrl-class.md) controle para selecionar uma cor personalizada.  
  
-   Oferece suporte a um estado "destacável" (se ela for criada usando o [CMFCColorMenuButton classe](../../mfc/reference/cmfccolormenubutton-class.md)).  
  
 Para incorporar o `CMFCColorBar` funcionalidade em seu aplicativo:  
  
1.  Criar um botão de menu regular e atribuí-la uma ID, por exemplo ID_CHAR_COLOR.  
  
2.  Em sua classe de janela do quadro, substituir o [CFrameWndEx::OnShowPopupMenu](../../mfc/reference/cframewndex-class.md#onshowpopupmenu) método e substituir o menu comum botão com um [CMFCColorMenuButton classe](../../mfc/reference/cmfccolormenubutton-class.md) objeto (chamando [CMFCToolBar: : ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)).  
  
3.  Definir todos os estilos e habilitar ou desabilitar os recursos do `CMFCColorBar` objeto durante [CMFCColorMenuButton classe](../../mfc/reference/cmfccolormenubutton-class.md) criação. O `CMFCColorMenuButton` objeto cria dinamicamente o `CMFCColorBar` objeto após o framework chama o `CreatePopupMenu` método.  
  
 Quando o usuário clica em um botão de controle de barra de cores, a estrutura usa o `ON_COMMAND` macro para notificar o pai do controle de barra de cores. A macro, o parâmetro de ID de comando é o valor que você atribuiu ao botão de controle barra de cores na etapa 1 (ID_CHAR_COLOR neste exemplo). Para obter mais informações, consulte o [CMFCColorMenuButton classe](../../mfc/reference/cmfccolormenubutton-class.md), [CMFCColorButton classe](../../mfc/reference/cmfccolorbutton-class.md), [CMFCColorPickerCtrl classe](../../mfc/reference/cmfccolorpickerctrl-class.md), [classe CWinAppEx é](../../mfc/reference/cframewndex-class.md), e [CMFCToolBar classe](../../mfc/reference/cmfctoolbar-class.md) classes.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como configurar uma barra de cores usando vários métodos no `CMFCColorBar` classe. Os métodos de definir as margens horizontais e verticais, habilitam outro botão, criarem uma janela de controle de barra de cores e define a cor atualmente selecionada. Este exemplo é parte do [exemplo novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls#1](../../mfc/reference/codesnippet/cpp/cmfccolorbar-class_1.h)]  
[!code-cpp[NVC_MFC_NewControls#2](../../mfc/reference/codesnippet/cpp/cmfccolorbar-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
 [CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md)  
  
 [CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcolorbar.h  
  
##  <a name="adjustlocations"></a>  CMFCColorBar::AdjustLocations  
 Ajusta as posições dos botões de cor no controle de barra de cores.  
  
```  
virtual void AdjustLocations();
```  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pelo framework durante `WM_SIZE` processamento de mensagem.  
  
##  <a name="allowchangetextlabels"></a>  CMFCColorBar::AllowChangeTextLabels  
 Indica se o rótulo de texto dos botões de cor pode alterar.  
  
```  
virtual BOOL AllowChangeTextLabels() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método sempre retorna `FALSE`, que significa que os rótulos de texto não pode ser modificado. Substitua este método para habilitar a modificação de rótulos de texto.  
  
##  <a name="allowshowonlist"></a>  CMFCColorBar::AllowShowOnList  
 Indica se o objeto de controle de barra de cores pode aparecer em uma lista de ferramentas durante o processo de personalização.  
  
```  
virtual BOOL AllowShowOnList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método sempre retorna `TRUE`, que significa que a estrutura pode exibir o controle de barra de cores durante o processo de personalização. Substitua este método para implementar um comportamento diferente.  
  
##  <a name="calcsize"></a>  CMFCColorBar::CalcSize  
 Chamado pelo framework como parte do processo de cálculo de layout.  
  
```  
virtual CSize CalcSize(BOOL bVertDock);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bVertDock`  
 `TRUE` para especificar que o controle de barra de cores é encaixado verticalmente; `FALSE` para especificar que o controle de barra de cores é ancorado na horizontal.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho da matriz de botões de cor em um controle de barra de cores.  
  
##  <a name="cmfccolorbar"></a>  CMFCColorBar::CMFCColorBar  
 Constrói um objeto `CMFCColorBar`.  
  
```  
CMFCColorBar(
    const CArray<COLORREF,COLORREF>& colors,  
    COLORREF color,  
    LPCTSTR lpszAutoColor,  
    LPCTSTR lpszOtherColor,  
    LPCTSTR lpszDocColors,  
    CList<COLORREF,COLORREF>& lstDocColors,  
    int nColumns,  
    int nRowsDockHorz,  
    int nColDockVert,  
    COLORREF colorAutomatic,  
    UINT nCommandID,  
    CMFCColorButton* pParentBtn);

 
CMFCColorBar(
    const CArray<COLORREF,COLORREF>& colors,  
    COLORREF color,  
    LPCTSTR lpszAutoColor,  
    LPCTSTR lpszOtherColor,  
    LPCTSTR lpszDocColors,  
    CList<COLORREF,COLORREF>& lstDocColors,  
    int nColumns,  
    COLORREF colorAutomatic,  
    UINT nCommandID,  
    CMFCRibbonColorButton* pParentRibbonBtn);

 
CMFCColorBar(
    CMFCColorBar& src,  
    UINT uiCommandID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `colors`  
 Uma matriz de cores exibe a estrutura do controle de barra de cores.  
  
 [in] `color`  
 A cor selecionada inicialmente.  
  
 [in] `lpszAutoColor`  
 O rótulo de texto a *automático* botão de cor (padrão), ou `NULL`.  
  
 O rótulo padrão para o botão automático é **automática**.  
  
 [in] `lpszOtherColor`  
 O rótulo de texto a *outros* botão, que exibe mais opções de cores, ou `NULL`.  
  
 O rótulo padrão para o outro botão é **mais cores...** .  
  
 [in] `lpszDocColors`  
 O rótulo de texto do botão de cores do documento. A paleta de cores do documento lista todas as cores que atualmente usa o documento.  
  
 [in] `lstDocColors`  
 Uma lista de cores que atualmente usa o documento.  
  
 [in] `nColumns`  
 O número de colunas que tem a matriz de cores.  
  
 [in] `nRowsDockHorz`  
 O número de linhas que a barra de cores tem quando ela estiver encaixada horizontalmente.  
  
 [in] `nColDockVert`  
 O número de colunas da barra de cores com quando ela estiver encaixada verticalmente.  
  
 [in] `colorAutomatic`  
 A cor padrão que se aplica a estrutura de quando você clica no botão automático.  
  
 [in] `nCommandID`  
 ID do comando de controle de barra de cores.  
  
 [in] `pParentBtn`  
 Um ponteiro para um botão de pai.  
  
 [in] `src`  
 Um existente `CMFCColorBar` objeto a ser copiado para a nova `CMFCColorBar` objeto.  
  
 [in] `uiCommandID`  
 A ID de comando.  
  
##  <a name="contexttosize"></a>  CMFCColorBar::ContextToSize  
 Calcula as margens horizontais e verticais que são necessárias para conter os botões no controle de barra de cores e ajusta o local desses botões.  
  
```  
void ContextToSize(
    BOOL bSquareButtons = TRUE,   
    BOOL bCenterButtons = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `bSquareButtons`|`TRUE` para especificar que a forma dos botões em um controle de barra de cores são quadrado; Caso contrário, `FALSE`. O valor padrão é `TRUE`.|  
|[in] `bCenterButtons`|`TRUE` para especificar que o conteúdo na frente de um botão de controle de barra de cores é centralizado; Caso contrário, `FALSE`. O valor padrão é `TRUE`.|  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="create"></a>  CMFCColorBar::Create  
 Cria uma janela de controle de barra de cores e anexa-o para o `CMFCColorBar` objeto.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwStyle,  
    UINT nID,  
    CPalette* pPalette=NULL,  
    int nColumns=0,  
    int nRowsDockHorz=0,  
    int nColDockVert=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParentWnd`  
 Ponteiro para a janela pai.  
  
 [in] `dwStyle`  
 Uma combinação bit a bit (ou) de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).  
  
 [in] `nID`  
 A ID de comando.  
  
 [in] `pPalette`  
 Ponteiro para uma paleta de cores. O padrão é `NULL`.  
  
 [in] `nColumns`  
 O número de colunas no controle de barra de cores. O padrão é 0.  
  
 [in] `nRowsDockHorz`  
 O número de linhas no controle de barra de cores quando ela estiver encaixada horizontalmente. O padrão é 0.  
  
 [in] `nColDockVert`  
 O número de colunas no controle de barra de cores quando ela estiver encaixada verticalmente. O padrão é 0.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Para construir um `CMFCColorBar` de objeto, chame o construtor da classe e em seguida, esse método. O `Create` método cria o controle do Windows e inicializa uma lista de cores.  
  
##  <a name="createcontrol"></a>  CMFCColorBar::CreateControl  
 Cria uma janela de controle de barra de cores, anexa-o para o `CMFCColorBar` de objeto e redimensionar a janela de controle para conter a paleta de cores especificada.  
  
```  
virtual BOOL CreateControl(
    CWnd* pParentWnd,  
    const CRect& rect,  
    UINT nID,  
    int nColumns=-1,  
    CPalette* pPalette=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParentWnd`  
 Ponteiro para a janela pai. Não pode ser `NULL`.  
  
 [in] `rect`  
 Um retângulo que especifica o local desenhar o controle de barra de cores.  
  
 [in] `nID`  
 A ID do controle.  
  
 [in] `nColumns`  
 O número ideal de colunas no controle de barra de cores. Esse método modifica esse número para se ajustar a paleta de cores especificada. O padrão é -1, o que significa que esse parâmetro não for especificado.  
  
 [in] `pPalette`  
 Ponteiro para uma paleta de cores, ou `NULL`. Se esse parâmetro for `NULL`, esse método calcula o tamanho do controle de barra de cores como se 20 cores foram especificadas. O padrão é `NULL`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa o `rect`, `nColumns`, e `pPalette` parâmetros para calcular o número apropriado ou linhas e colunas no controle de barra de cores e, em seguida, chama o [CMFCColorBar::Create](#create) método.  
  
##  <a name="createpalette"></a>  CMFCColorBar::CreatePalette  
 Inicializa uma paleta com as cores em uma matriz de cores especificada.  
  
```  
static BOOL CreatePalette(
    const CArray<COLORREF, COLORREF>& arColors,   
    CPalette& palette);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `arColors`|Uma matriz de cores.|  
|[in] `palette`|Uma paleta de cores.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
##  <a name="enableautomaticbutton"></a>  CMFCColorBar::EnableAutomaticButton  
 Mostra ou oculta o botão automático.  
  
```  
void EnableAutomaticButton(
    LPCTSTR lpszLabel,  
    COLORREF colorAutomatic,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszLabel`  
 O rótulo de texto a *automático* botão de cor (padrão), ou `NULL`.  
  
 O rótulo padrão para o botão automático é **automática**.  
  
 [in] `colorAutomatic`  
 A cor padrão que se aplica a estrutura de quando você clica no botão automático.  
  
 [in] `bEnable`  
 `TRUE` Para habilitar o botão automático; `FALSE` para desabilitar o botão automático. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 O rótulo de texto do botão automático será excluído se o `lpszLabel` parâmetro é `NULL` ou `bEnable` parâmetro é `FALSE`.  
  
##  <a name="enableotherbutton"></a>  CMFCColorBar::EnableOtherButton  
 Habilita ou desabilita a exibição de uma caixa de diálogo que permite que o usuário selecione mais cores.  
  
```  
void EnableOtherButton(
    LPCTSTR lpszLabel,  
    BOOL bAltColorDlg=TRUE,  
    BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszLabel`  
 O rótulo de texto a *outros* botão, que exibe mais opções de cores, ou `NULL`.  
  
 O rótulo padrão para este botão é **mais cores...** .  
  
 [in] `bAltColorDlg`  
 `TRUE` Para exibir o [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md) caixa de diálogo. `FALSE` para exibir o padrão [CColorDialog](../../mfc/reference/ccolordialog-class.md) caixa de diálogo. O valor padrão é `TRUE`.  
  
 [in] `bEnable`  
 `TRUE` Para habilitar o botão; `FALSE` para desabilitar o botão. O valor padrão é `TRUE`.  
  
##  <a name="getcolor"></a>  CMFCColorBar::GetColor  
 Recupera a cor atualmente selecionada.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor atualmente selecionada.  
  
##  <a name="getcolorgridsize"></a>  CMFCColorBar::GetColorGridSize  
 Calcula o número de linhas e colunas na grade de um controle de barra de cores.  
  
```  
CSize GetColorGridSize(BOOL bVertDock) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `bVertDock`|`TRUE` para executar o cálculo de um controle de barra de cores encaixado na vertical; Caso contrário, execute o cálculo de um controle encaixado na horizontal.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CSize](../../atl-mfc-shared/reference/csize-class.md) do objeto cuja `cx` componente contém o número de colunas e cujo `cy` componente contém o número de linhas.  
  
##  <a name="getcommandid"></a>  CMFCColorBar::GetCommandID  
 Recupera a ID de comando do controle de barra de cor atual.  
  
```  
UINT GetCommandID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma ID de comando.  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário seleciona uma cor nova, a estrutura envia a ID de comando em uma `WM_COMMAND` mensagem para notificar o pai do `CMFCColorBar` objeto.  
  
##  <a name="getextraheight"></a>  CMFCColorBar::GetExtraHeight  
 Calcula a altura adicional que requer que a barra de cores atual para exibir os elementos da interface do usuário diversos, como o **outros** cores do botão ou o documento.  
  
```  
int GetExtraHeight(int nNumColumns) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `nNumColumns`|Se o controle de barra de cores contém cores de documento, o número de colunas a serem exibidas na grade de cores do documento. Caso contrário, esse valor não é usado.|  
  
### <a name="return-value"></a>Valor de retorno  
 A altura extra calculada é necessária.  
  
##  <a name="gethighlightedcolor"></a>  CMFCColorBar::GetHighlightedColor  
 Recupera a cor que indica se um botão de cor tem foco. ou seja, o botão é *hot*.  
  
```  
COLORREF GetHighlightedColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor RGB.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gethorzmargin"></a>  CMFCColorBar::GetHorzMargin  
 Recupera a margem horizontal, que é o espaço entre à esquerda ou célula à direita de cor e o limite de área de cliente.  
  
```  
int GetHorzMargin();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A margem horizontal.  
  
##  <a name="getvertmargin"></a>  CMFCColorBar::GetVertMargin  
 Recupera a margem vertical, que é o espaço entre a parte superior ou célula de cor inferior e o limite da área cliente.  
  
```  
int GetVertMargin() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A margem vertical.  
  
##  <a name="initcolors"></a>  CMFCColorBar::InitColors  
 Inicializa uma matriz de cores com as cores em uma paleta especificada, ou com a paleta padrão do sistema.  
  
```  
static int InitColors(
    CPalette* pPalette,   
    CArray<COLORREF, COLORREF>& arColors);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `pPalette`|Um ponteiro para um objeto de paleta, ou `NULL`. Se esse parâmetro for `NULL`, esse método usa a paleta padrão do sistema operacional.|  
|[in] `arColors`|Uma matriz de cores.|  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos na matriz de cores.  
  
##  <a name="istearoff"></a>  CMFCColorBar::IsTearOff  
 Indica se a barra de cores atual é encaixável.  
  
```  
BOOL IsTearOff() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o controle de barra de cor atual for encaixável; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se o controle de barra de cores é encaixável, pode ser uma barra de controle separado e encaixado em outro local.  
  
##  <a name="onkey"></a>  CMFCColorBar::OnKey  
 Chamado pelo framework quando um usuário pressiona um botão do teclado.  
  
```  
virtual BOOL OnKey(UINT nChar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nChar`  
 O código de tecla virtual para a chave que o usuário pressionou.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se este método processa a chave especificada; Caso contrário, `FALSE`.  
  
##  <a name="onsendcommand"></a>  CMFCColorBar::OnSendCommand  
 Chamado pelo framework para fechar uma hierarquia de controles pop-up.  
  
```  
virtual BOOL OnSendCommand(const CMFCToolBarButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `pButton`|Ponteiro para um controle que reside em uma barra de ferramentas.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
##  <a name="onupdatecmdui"></a>  CMFCColorBar::OnUpdateCmdUI  
 Chamado pelo framework para habilitar ou desabilitar um item de interface do usuário de um controle de barra de cores para que o item é exibido.  
  
```  
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,  
    BOOL bDisableIfNoHndler);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pTarget`  
 Ponteiro para uma janela que contém um item de interface do usuário para atualizar.  
  
 [in] `bDisableIfNoHndler`  
 `TRUE` Para desabilitar o item de interface do usuário, se nenhum manipulador é definido em um mapa de mensagem; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Quando um usuário de seu aplicativo clica em um item de interface do usuário, o item deve saber se ele deve ser exibido como habilitado ou desabilitado. O destino da mensagem de comando fornece essas informações ao implementar um `ON_UPDATE_COMMAND_UI` manipulador de comandos. Use esse método para ajudar a processar o comando. Para obter mais informações, consulte [classe CCmdUI](../../mfc/reference/ccmdui-class.md).  
  
##  <a name="opencolordialog"></a>  CMFCColorBar::OpenColorDialog  
 Abre uma caixa de diálogo de cor.  
  
```  
virtual BOOL OpenColorDialog(
    const COLORREF colorDefault,  
    COLORREF& colorRes);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `colorDefault`  
 A cor que é selecionada por padrão quando abre a caixa de diálogo de cor.  
  
 [out] `colorRes`  
 A cor que um usuário selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o usuário selecionou uma cor. `FALSE` se o usuário cancelou a caixa de diálogo de cor.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="rebuild"></a>  CMFCColorBar::Rebuild  
 Redesenha completamente o controle de barra de cores.  
  
```  
virtual void Rebuild();
```  
  
##  <a name="selectpalette"></a>  CMFCColorBar::SelectPalette  
 Define a paleta lógica do contexto do dispositivo especificado para a paleta do botão pai do controle de barra de cor atual.  
  
```  
CPalette* SelectPalette(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `pDC`|Ponteiro para o contexto do botão pai do controle de barra de cor atual.|  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para a paleta é substituída pela paleta do botão pai do controle de barra de cores atual.  
  
##  <a name="setcolor"></a>  CMFCColorBar::SetColor  
 Define a cor atualmente selecionada.  
  
```  
void SetColor(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 Um valor de cor RGB.  
  
##  <a name="setcolorname"></a>  CMFCColorBar::SetColorName  
 Define um novo nome para uma cor especificada.  
  
```  
static void SetColorName(
    COLORREF color,  
    const CString& strName);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 O valor RGB da cor.  
  
 [in] `strName`  
 O novo nome para a cor especificada.  
  
### <a name="remarks"></a>Comentários  
 Esse método altera o nome da cor especificada em todos os `CMFCColorBar` objetos em seu aplicativo.  
  
##  <a name="setcommandid"></a>  CMFCColorBar::SetCommandID  
 Define uma nova ID de comando para um controle de barra de cores.  
  
```  
void SetCommandID(UINT nCommandID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nCommandID`  
 Uma ID de comando.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para modificar a ID de comando de um controle de barra de cores e para notificar a janela pai do controle que a ID foi alterada.  
  
##  <a name="setdocumentcolors"></a>  CMFCColorBar::SetDocumentColors  
 Define a lista de cores que são usados no documento atual.  
  
```  
void SetDocumentColors(
    LPCTSTR lpszCaption,  
    CList<COLORREF,COLORREF>& lstDocColors,  
    BOOL bShowWhenDocked=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszCaption`  
 Uma legenda que é exibida quando o controle de barra de cores não está encaixado.  
  
 [in] `lstDocColors`  
 Uma lista de cores que substitui as cores do documento atual.  
  
 [in] `bShowWhenDocked`  
 `TRUE` para mostrar as cores do documento quando o controle de barra de cores é encaixado; Caso contrário, `FALSE`. O valor padrão é `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 *Cores de documento* são as cores que estão sendo usadas em um documento. A estrutura automaticamente mantém uma lista de cores do documento, mas você pode usar esse método para modificar a lista.  
  
##  <a name="sethorzmargin"></a>  CMFCColorBar::SetHorzMargin  
 Define a margem horizontal, que é o espaço entre a esquerda ou célula à direita de cor e o limite da área cliente.  
  
```  
void SetHorzMargin(int nHorzMargin);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nHorzMargin`  
 A margem horizontal, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o [CMFCColorBar::CMFCColorBar](#cmfccolorbar) construtor define a margem horizontal como 4 pixels.  
  
##  <a name="setproplist"></a>  CMFCColorBar::SetPropList  
 Define o `m_pWndPropList` protegido membro de dados para o ponteiro especificado para um controle de grade de propriedade.  
  
```  
void SetPropList(CMFCPropertyGridCtrl* pWndList);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `pWndList`|Ponteiro para objeto de controle de grade de propriedade.|  
  
##  <a name="setvertmargin"></a>  CMFCColorBar::SetVertMargin  
 Define a margem vertical, que é o espaço entre a célula de cor superior ou inferior e o limite de área do cliente.  
  
```  
void SetVertMargin(int nVertMargin);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nVertMargin`  
 A margem vertical, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o [CMFCColorBar::CMFCColorBar](#cmfccolorbar) construtor define a margem vertical para 4 pixels.  
  
##  <a name="showcommandmessagestring"></a>  CMFCColorBar::ShowCommandMessageString  
 Solicita a janela do quadro que possui o controle de barra de cores para atualizar a linha de mensagem na barra de status.  
  
```  
virtual void ShowCommandMessageString(UINT uiCmdId);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdId`  
 Uma ID de comando. (Esse parâmetro é ignorado).  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o `WM_SETMESSAGESTRING` mensagem para o proprietário do controle de barra de cores.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)
