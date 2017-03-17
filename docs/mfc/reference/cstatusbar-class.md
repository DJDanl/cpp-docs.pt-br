---
title: Classe CStatusBar | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CStatusBar
- AFXEXT/CStatusBar
- AFXEXT/CStatusBar::CStatusBar
- AFXEXT/CStatusBar::CommandToIndex
- AFXEXT/CStatusBar::Create
- AFXEXT/CStatusBar::CreateEx
- AFXEXT/CStatusBar::DrawItem
- AFXEXT/CStatusBar::GetItemID
- AFXEXT/CStatusBar::GetItemRect
- AFXEXT/CStatusBar::GetPaneInfo
- AFXEXT/CStatusBar::GetPaneStyle
- AFXEXT/CStatusBar::GetPaneText
- AFXEXT/CStatusBar::GetStatusBarCtrl
- AFXEXT/CStatusBar::SetIndicators
- AFXEXT/CStatusBar::SetPaneInfo
- AFXEXT/CStatusBar::SetPaneStyle
- AFXEXT/CStatusBar::SetPaneText
dev_langs:
- C++
helpviewer_keywords:
- indicators, status bar
- CStatusBar class
- status bars
- indicators
- status indicators
ms.assetid: a3bde3db-e71c-4881-a3ca-1d5481c345ba
caps.latest.revision: 24
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: e96070041ef5bcee0865991a14b6484082d8fc91
ms.lasthandoff: 02/25/2017

---
# <a name="cstatusbar-class"></a>Classe CStatusBar
Uma barra de controle com uma linha de painéis de saída de texto ou "indicadores".  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CStatusBar : public CControlBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStatusBar::CStatusBar](#cstatusbar)|Constrói um objeto `CStatusBar`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStatusBar::CommandToIndex](#commandtoindex)|Obtém o índice para uma ID de indicador de determinado.|  
|[CStatusBar::Create](#create)|Cria a barra de status, anexa-o para o `CStatusBar` de objeto e define a altura da fonte e a barra inicial.|  
|[CStatusBar::CreateEx](#createex)|Cria um `CStatusBar` objeto com estilos adicionais para o embedded `CStatusBarCtrl` objeto.|  
|[CStatusBar::DrawItem](#drawitem)|Chamado quando um aspecto visual de um alterações de controle de barra de status de desenho proprietário.|  
|[CStatusBar::GetItemID](#getitemid)|Obtém a ID do indicador para um determinado índice.|  
|[CStatusBar::GetItemRect](#getitemrect)|Obtém exibe o retângulo para um determinado índice.|  
|[CStatusBar::GetPaneInfo](#getpaneinfo)|Obtém a ID do indicador, estilo e largura de um determinado índice.|  
|[CStatusBar::GetPaneStyle](#getpanestyle)|Obtém o estilo do indicador para um determinado índice.|  
|[CStatusBar::GetPaneText](#getpanetext)|Obtém o texto do indicador para um determinado índice.|  
|[CStatusBar::GetStatusBarCtrl](#getstatusbarctrl)|Permite acesso direto ao controle comum subjacente.|  
|[CStatusBar::SetIndicators](#setindicators)|Define as IDs de indicador.|  
|[CStatusBar::SetPaneInfo](#setpaneinfo)|Define a ID do indicador, estilo e largura de um determinado índice.|  
|[CStatusBar::SetPaneStyle](#setpanestyle)|Define o estilo do indicador para um determinado índice.|  
|[CStatusBar::SetPaneText](#setpanetext)|Define o texto do indicador para um determinado índice.|  
  
## <a name="remarks"></a>Comentários  
 Os painéis de saída são usados como linhas de mensagem e indicadores de status. Exemplos incluem as linhas de mensagem de Ajuda do menu que explicam resumidamente o comando de menu selecionado e os indicadores que mostram o status de SCROLL LOCK, NUM LOCK e outras chaves.  
  
 [CStatusBar::GetStatusBarCtrl](#getstatusbarctrl), uma função de membro novo 4.0 MFC, permite que você tire proveito do suporte do controle do Windows comuns para personalização e funcionalidade adicional da barra de status. `CStatusBar`funções de membro oferecem a maioria da funcionalidade de controles comuns do Windows; No entanto, quando você chama `GetStatusBarCtrl`, você pode fornecer as barras de status ainda mais as características de uma barra de status do Windows 95/98. Quando você chama `GetStatusBarCtrl`, ele retornará uma referência a um `CStatusBarCtrl` objeto. Consulte [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) para obter mais informações sobre como criar barras de ferramentas usando controles comuns do Windows. Para obter mais informações sobre controles comuns, consulte [controles comuns](http://msdn.microsoft.com/library/windows/desktop/bb775493) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 O framework armazena informações sobre o indicador de uma matriz com o indicador mais à esquerda na posição 0. Quando você cria uma barra de status, você pode usar uma matriz de cadeia de caracteres de IDs que o framework associa os indicadores correspondentes. Em seguida, você pode usar uma ID de cadeia de caracteres ou um índice para acessar um indicador.  
  
 Por padrão, o primeiro indicador é "Elástico": ela ocupa o comprimento da barra de status não é usado por outros painéis indicador, para que outros painéis sejam alinhados à direita.  
  
 Para criar uma barra de status, siga estas etapas:  
  
1.  Construir o `CStatusBar` objeto.  
  
2.  Chamar o [criar](#create) (ou [CreateEx](#createex)) função para criar a janela de barra de status e anexá-lo a `CStatusBar` objeto.  
  
3.  Chamar [SetIndicators](#setindicators) para associar uma ID de cadeia de caracteres de cada indicador.  
  
 Há três maneiras de atualizar o texto em um painel da barra de status:  
  
1.  Chamar [CWnd::SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext) para atualizar o texto no painel somente 0.  
  
2.  Chamar [CCmdUI::SetText](../../mfc/reference/ccmdui-class.md#settext) na barra de status `ON_UPDATE_COMMAND_UI` manipulador.  
  
3.  Chamar [SetPaneText](#setpanetext) para atualizar o texto de qualquer painel.  
  
 Chamar [SetPaneStyle](#setpanestyle) para atualizar o estilo de um painel da barra de status.  
  
 Para obter mais informações sobre como usar o `CStatusBar`, consulte o artigo [implementação da barra de Status no MFC](../../mfc/status-bar-implementation-in-mfc.md) e [técnico 31 Observação: barras de controle](../../mfc/tn031-control-bars.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CStatusBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="commandtoindex"></a>CStatusBar::CommandToIndex  
 Obtém o índice do indicador de uma ID especificada.  
  
```  
int CommandToIndex(UINT nIDFind) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDFind`  
 Cadeia de caracteres ID do indicador cujo índice deve ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do indicador se for bem-sucedida; -1 se não for bem-sucedido.  
  
### <a name="remarks"></a>Comentários  
 O índice do primeiro indicador é 0.  
  
##  <a name="create"></a>CStatusBar::Create  
 Cria uma barra (uma janela filho) de status e o associa a `CStatusBar` objeto.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,  
    UINT nID = AFX_IDW_STATUS_BAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentWnd`  
 Ponteiro para o [CWnd](../../mfc/reference/cwnd-class.md) objeto cuja janela do Windows é o pai da barra de status.  
  
 `dwStyle`  
 O estilo de barra de status. Além do padrão do Windows [estilos](../../mfc/reference/window-styles.md), há suporte para esses estilos.  
  
- `CBRS_TOP`Barra de controle está no topo da janela do quadro.  
  
- `CBRS_BOTTOM`Barra de controle está na parte inferior da janela do quadro.  
  
- `CBRS_NOALIGN`Barra de controle não é reposicionada quando o pai for redimensionado.  
  
 `nID`  
 ID da janela filho. da barra de ferramentas  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Também define a fonte inicial e o status da altura da barra para um valor padrão.  
  
##  <a name="createex"></a>CStatusBar::CreateEx  
 Chame essa função para criar uma barra (uma janela filho) de status e associá-lo a `CStatusBar` objeto.  
  
```  
virtual BOOL CreateEx(
    CWnd* pParentWnd,  
    DWORD dwCtrlStyle = 0,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,  
    UINT nID = AFX_IDW_STATUS_BAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentWnd`  
 Ponteiro para o [CWnd](../../mfc/reference/cwnd-class.md) objeto cuja janela do Windows é o pai da barra de status.  
  
 `dwCtrlStyle`  
 Estilos adicionais para a criação de inserido [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) objeto. O padrão especifica uma barra de status sem uma alça de dimensionamento ou uma dica de ferramenta suporte. Estilos de barra de status com suporte são:  
  
- **SBARS_SIZEGRIP** o controle StatusBar inclui uma alça de dimensionamento na extremidade direita da barra de status. Uma alça de dimensionamento é semelhante a uma borda de dimensionamento; é uma área retangular que o usuário possa clicar e arrastar para redimensionar a janela pai.  
  
- **SBT_TOOLTIPS** dicas de ferramenta oferece suporte a barra de status.  
  
 Para obter detalhes sobre esses estilos, consulte [configurações do CStatusBarCtrl](../../mfc/settings-for-the-cstatusbarctrl.md).  
  
 `dwStyle`  
 O estilo de barra de status. O padrão especifica a criação de uma barra de status visíveis na parte inferior da janela do quadro. Aplique qualquer combinação de estilos de controle listado da barra de status [estilos de janela](../../mfc/reference/window-styles.md) e [CDialogBar::Create](../../mfc/reference/cdialogbar-class.md#create). No entanto, esse parâmetro sempre deve incluir os estilos WS_CHILD e WS_VISIBLE.  
  
 `nID`  
 ID da janela filho da barra de status.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função também define a fonte inicial e define o status da altura da barra para um valor padrão.  
  
 Use `CreateEx`, em vez de [criar](#create), quando determinados estilos precisam estar presente durante a criação do controle da barra de status incorporada. Por exemplo, defina `dwCtrlStyle` para **SBT_TOOLTIPS** exibi-la em um objeto de barra de status.  
  
##  <a name="cstatusbar"></a>CStatusBar::CStatusBar  
 Constrói uma `CStatusBar` objeto, cria uma fonte de barra de status padrão, se necessário e define as características da fonte para os valores padrão.  
  
```  
CStatusBar();
```  
  
##  <a name="drawitem"></a>CStatusBar::DrawItem  
 Essa função de membro é chamada pela estrutura quando um aspecto visual um desenho proprietário barra das alterações de status.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro para um [DRAWITEMSTRUCT](http://msdn.microsoft.com/library/windows/desktop/bb775802) estrutura que contém informações sobre o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 O **itemAction** membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CStatusBar` objeto. O aplicativo deve restaurar todos os objetos GDI (interface) do dispositivo gráfico selecionados para o contexto de exibição fornecidos no `lpDrawItemStruct` antes do término desta função de membro.  
  
##  <a name="getitemid"></a>CStatusBar::GetItemID  
 Retorna a ID do indicador especificado por `nIndex`.  
  
```  
UINT GetItemID(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do indicador cujo ID deve ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID do indicador especificado por `nIndex`.  
  
##  <a name="getitemrect"></a>CStatusBar::GetItemRect  
 Copia as coordenadas do indicador especificado por `nIndex` na estrutura apontada por `lpRect`.  
  
```  
void GetItemRect(
    int nIndex,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do indicador cujas coordenadas do retângulo devem ser recuperadas.  
  
 `lpRect`  
 Aponta para um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) que receberá as coordenadas do indicador especificado pelo objeto `nIndex`.  
  
### <a name="remarks"></a>Comentários  
 Coordenadas são em pixels em relação ao canto superior esquerdo da barra de status.  
  
##  <a name="getpaneinfo"></a>CStatusBar::GetPaneInfo  
 Conjuntos de `nID`, `nStyle`, e `cxWidth` o ID, o estilo e a largura do painel indicador no local especificado por `nIndex`.  
  
```  
void GetPaneInfo(
    int nIndex,  
    UINT& nID,  
    UINT& nStyle,  
    int& cxWidth) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do painel cujas informações deve ser recuperado.  
  
 `nID`  
 Referência a um **UINT** que é definida para a ID do painel.  
  
 `nStyle`  
 Referência a um **UINT** que é definido como o estilo do painel.  
  
 `cxWidth`  
 Referência a um número inteiro que é definido como a largura do painel.  
  
##  <a name="getpanestyle"></a>CStatusBar::GetPaneStyle  
 Chame essa função de membro para recuperar o estilo de painel da barra de status.  
  
```  
UINT GetPaneStyle(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do painel cujo estilo deve ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 O estilo do painel barra de status especificado por `nIndex`.  
  
### <a name="remarks"></a>Comentários  
 Estilo do painel determina como o painel será exibido.  
  
 Para obter uma lista de estilos disponíveis para barras de status, consulte [criar](#create).  
  
##  <a name="getpanetext"></a>CStatusBar::GetPaneText  
 Chame essa função de membro para recuperar o texto que aparece em um painel da barra de status.  
  
```  
CString GetPaneText(int nIndex) const;  void GetPaneText(int nIndex, CString& rString) const;  ```  
  
### Parameters  
 `nIndex`  
 Index of the pane whose text is to be retrieved.  
  
 `rString`  
 A reference to a [CString](../../atl-mfc-shared/reference/cstringt-class.md) object that contains the text to be retrieved.  
  
### Return Value  
 A `CString` object containing the pane's text.  
  
### Remarks  
 The second form of this member function fills a `CString` object with the string text.  
  
##  <a name="getstatusbarctrl"></a>  CStatusBar::GetStatusBarCtrl  
 This member function allows direct access to the underlying common control.  
  
```  
CStatusBarCtrl < / GetStatusBarCtrl() const;  
```  
  
### Return Value  
 Contains a reference to a [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) object.  
  
### Remarks  
 Use `GetStatusBarCtrl` to take advantage of the functionality of the Windows status-bar common control, and to take advantage of the support [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) provides for status-bar customization. For example, by using the common control, you can specify a style that includes a sizing grip on the status bar, or you can specify a style to have the status bar appear at the top of the parent window's client area.  
  
 For more general information about common controls, See [Common Controls](http://msdn.microsoft.com/library/windows/desktop/bb775493) in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setindicators"></a>  CStatusBar::SetIndicators  
 Sets each indicator's ID to the value specified by the corresponding element of the array `lpIDArray`, loads the string resource specified by each ID, and sets the indicator's text to the string.  
  
```  
BOOL SetIndicators (const UINT * lpIDArray,  
    int nIDCount);
```  
  
### Parameters  
 `lpIDArray`  
 Pointer to an array of IDs.  
  
 `nIDCount`  
 Number of elements in the array pointed to by `lpIDArray`.  
  
### Return Value  
 Nonzero if successful; otherwise 0.  
  
##  <a name="setpaneinfo"></a>  CStatusBar::SetPaneInfo  
 Sets the specified indicator pane to a new ID, style, and width.  
  
```  
void SetPaneInfo (int nIndex,  
    UINT nID,  
    NStyle UINT,  
    int cxWidth);
```  
  
### Parameters  
 `nIndex`  
 Index of the indicator pane whose style is to be set.  
  
 `nID`  
 New ID for the indicator pane.  
  
 `nStyle`  
 New style for the indicator pane.  
  
 `cxWidth`  
 New width for the indicator pane.  
  
### Remarks  
 The following indicator styles are supported:  
  
- **SBPS_NOBORDERS** No 3-D border around the pane.  
  
- **SBPS_POPOUT** Reverse border so that text "pops out."  
  
- **SBPS_DISABLED** Do not draw text.  
  
- **SBPS_STRETCH** Stretch pane to fill unused space. Only one pane per status bar can have this style.  
  
- **SBPS_NORMAL** No stretch, borders, or pop-out.  
  
##  <a name="setpanestyle"></a>  CStatusBar::SetPaneStyle  
 Call this member function to set the style of a status bar's pane.  
  
```  
void SetPaneStyle (int nIndex,  
    UINT nStyle);
```  
  
### Parameters  
 `nIndex`  
 Index of the pane whose style is to be set.  
  
 `nStyle`  
 Style of the pane whose style is to be set.  
  
### Remarks  
 A pane's style determines how the pane appears.  
  
 For a list of styles available for status bars, see [SetPaneInfo](#setpaneinfo).  
  
##  <a name="setpanetext"></a>  CStatusBar::SetPaneText  
 Call this member function to set the pane text to the string pointed to by `lpszNewText`.  
  
```  
BOOL SetPaneText (int nIndex,  
    LPCTSTR lpszNewText,  
    B BOOL Update = TRUE);
```  
  
### Parameters  
 `nIndex`  
 Index of the pane whose text is to be set.  
  
 `lpszNewText`  
 Pointer to the new pane text.  
  
 *bUpdate*  
 If **TRUE**, the pane is invalidated after the text is set.  
  
### Return Value  
 Nonzero if successful; otherwise 0.  
  
### Remarks  
 After you call `SetPaneText`, you must add a UI update handler to display the new text in the status bar.  
  
### Example  
 [!code-cpp[NVC_MFCDocView#176](../../mfc/codesnippet/cpp/cstatusbar-class_1.cpp)]  
  
 [!code-cpp[NVC_MFCDocView#177](../../mfc/codesnippet/cpp/cstatusbar-class_2.cpp)]  
  
 [!code-cpp[NVC_MFCDocView#178](../../mfc/codesnippet/cpp/cstatusbar-class_3.cpp)]  
  
## See Also  
 [MFC Sample CTRLBARS](../../visual-cpp-samples.md)   
 [MFC Sample DLGCBR32](../../visual-cpp-samples.md)   
 [CControlBar Class](../../mfc/reference/ccontrolbar-class.md)   
 [Hierarchy Chart](../../mfc/hierarchy-chart.md)   
 [CStatusBarCtrl Class](../../mfc/reference/cstatusbarctrl-class.md)   
 [CControlBar Class](../../mfc/reference/ccontrolbar-class.md)

