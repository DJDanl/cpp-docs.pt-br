---
title: Classe CStatusBar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
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
dev_langs: C++
helpviewer_keywords:
- CStatusBar [MFC], CStatusBar
- CStatusBar [MFC], CommandToIndex
- CStatusBar [MFC], Create
- CStatusBar [MFC], CreateEx
- CStatusBar [MFC], DrawItem
- CStatusBar [MFC], GetItemID
- CStatusBar [MFC], GetItemRect
- CStatusBar [MFC], GetPaneInfo
- CStatusBar [MFC], GetPaneStyle
- CStatusBar [MFC], GetPaneText
- CStatusBar [MFC], GetStatusBarCtrl
- CStatusBar [MFC], SetIndicators
- CStatusBar [MFC], SetPaneInfo
- CStatusBar [MFC], SetPaneStyle
- CStatusBar [MFC], SetPaneText
ms.assetid: a3bde3db-e71c-4881-a3ca-1d5481c345ba
caps.latest.revision: "24"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c373f21762c1bf7f21d2a775453bab74c735891d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cstatusbar-class"></a>Classe CStatusBar
Uma barra de controle com uma linha de painéis de saída de texto ou "indicadores".  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CStatusBar : public CControlBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStatusBar::CStatusBar](#cstatusbar)|Constrói um objeto `CStatusBar`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStatusBar::CommandToIndex](#commandtoindex)|Obtém o índice para uma ID de indicador de determinado.|  
|[CStatusBar::Create](#create)|Cria a barra de status, anexa-o para o `CStatusBar` de objeto e define a altura da fonte e a barra inicial.|  
|[CStatusBar::CreateEx](#createex)|Cria um `CStatusBar` objeto com estilos adicionais para o item inserido `CStatusBarCtrl` objeto.|  
|[CStatusBar::DrawItem](#drawitem)|Chamado quando um aspecto visual de um alterações de controle de barra de status de desenho do proprietário.|  
|[CStatusBar::GetItemID](#getitemid)|Obtém a ID de indicador para um determinado índice.|  
|[CStatusBar::GetItemRect](#getitemrect)|Obtém a exibição retângulo para um determinado índice.|  
|[CStatusBar::GetPaneInfo](#getpaneinfo)|Obtém a ID do indicador, estilo e largura para um determinado índice.|  
|[CStatusBar::GetPaneStyle](#getpanestyle)|Obtém o estilo do indicador para um determinado índice.|  
|[CStatusBar::GetPaneText](#getpanetext)|Obtém o texto do indicador para um determinado índice.|  
|[CStatusBar::GetStatusBarCtrl](#getstatusbarctrl)|Permite acesso direto ao controle comum subjacente.|  
|[CStatusBar::SetIndicators](#setindicators)|Define as IDs de indicador.|  
|[CStatusBar::SetPaneInfo](#setpaneinfo)|Define a ID do indicador, estilo e largura para um determinado índice.|  
|[CStatusBar::SetPaneStyle](#setpanestyle)|Define o estilo do indicador para um determinado índice.|  
|[CStatusBar::SetPaneText](#setpanetext)|Define o texto do indicador para um determinado índice.|  
  
## <a name="remarks"></a>Comentários  
 Os painéis de saída são usados como linhas de mensagem e indicadores de status. Exemplos incluem as linhas de mensagem de Ajuda do menu que explicam rapidamente o comando de menu selecionado e os indicadores que mostram o status de SCROLL LOCK, NUM LOCK e outras chaves.  
  
 [CStatusBar::GetStatusBarCtrl](#getstatusbarctrl), uma função de membro novo MFC 4.0, permite aproveitar o suporte para personalização e funcionalidades adicionais da barra de status do controle comum do Windows. `CStatusBar`funções de membro lhe oferece a maioria da funcionalidade de controles comuns do Windows; No entanto, quando você chama `GetStatusBarCtrl`, você pode fornecer as barras de status ainda mais as características de uma barra de status do Windows 95/98. Quando você chama `GetStatusBarCtrl`, ela retornará uma referência a um `CStatusBarCtrl` objeto. Consulte [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) para obter mais informações sobre a criação de barras de ferramentas usando controles comuns do Windows. Para obter mais informações sobre controles comuns, consulte [controles comuns](http://msdn.microsoft.com/library/windows/desktop/bb775493) no SDK do Windows.  
  
 O framework armazena informações sobre o indicador em uma matriz com o indicador mais à esquerda na posição 0. Quando você cria uma barra de status, você pode usar uma matriz de cadeia de caracteres IDs que a estrutura associa os indicadores correspondentes. Você pode usar uma ID de cadeia de caracteres ou um índice para acessar um indicador.  
  
 Por padrão, o primeiro indicador é "Elástico": ocupe o comprimento da barra de status não usado por outros painéis de indicador, para que outros painéis sejam alinhado à direita.  
  
 Para criar uma barra de status, siga estas etapas:  
  
1.  Construir o `CStatusBar` objeto.  
  
2.  Chamar o [criar](#create) (ou [CreateEx](#createex)) função para criar a janela de barra de status e anexá-lo para o `CStatusBar` objeto.  
  
3.  Chamar [SetIndicators](#setindicators) para associar uma ID de cadeia de caracteres de cada indicador.  
  
 Há três maneiras de atualizar o texto em um painel da barra de status:  
  
1.  Chamar [CWnd::SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext) para atualizar o texto no painel somente 0.  
  
2.  Chamar [CCmdUI::SetText](../../mfc/reference/ccmdui-class.md#settext) na barra de status `ON_UPDATE_COMMAND_UI` manipulador.  
  
3.  Chamar [SetPaneText](#setpanetext) para atualizar o texto de qualquer painel.  
  
 Chamar [SetPaneStyle](#setpanestyle) para atualizar o estilo de um painel da barra de status.  
  
 Para obter mais informações sobre como usar `CStatusBar`, consulte o artigo [implementação da barra de Status no MFC](../../mfc/status-bar-implementation-in-mfc.md) e [31 de observação técnica: barras de controle](../../mfc/tn031-control-bars.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CStatusBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="commandtoindex"></a>CStatusBar::CommandToIndex  
 Obtém o índice do indicador para uma ID especificada.  
  
```  
int CommandToIndex(UINT nIDFind) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDFind`  
 ID do indicador cujo índice é a serem recuperados de cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do indicador se bem-sucedido; -1 se não for bem-sucedido.  
  
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
 O estilo de barra de status. Além do padrão do Windows [estilos](../../mfc/reference/styles-used-by-mfc.md#window-styles), há suporte para esses estilos.  
  
- `CBRS_TOP`Barra de controle está na parte superior da janela do quadro.  
  
- `CBRS_BOTTOM`Barra de controle está na parte inferior da janela do quadro.  
  
- `CBRS_NOALIGN`Barra de controle é reposicionado de forma não quando o pai for redimensionado.  
  
 `nID`  
 ID de janela filho. da barra de ferramentas  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Também define a fonte inicial e define o status da altura da barra em um valor padrão.  
  
##  <a name="createex"></a>CStatusBar::CreateEx  
 Chamar essa função para criar uma barra (uma janela filho) de status e associá-lo com o `CStatusBar` objeto.  
  
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
 Estilos adicionais para a criação do item inserido [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) objeto. O padrão especifica uma barra de status sem uma alça de dimensionamento ou uma dica de ferramenta suporte. Estilos de barra de status com suporte são:  
  
- **SBARS_SIZEGRIP** o controle de barra de status inclui uma alça de dimensionamento na extremidade direita da barra de status. Uma alça de dimensionamento é semelhante a uma borda de dimensionamento; é uma área retangular que o usuário pode clicar e arrastar para redimensionar a janela pai.  
  
- **SBT_TOOLTIPS** a barra de status dá suporte a dicas de ferramenta.  
  
 Para obter detalhes sobre esses estilos, consulte [configurações do CStatusBarCtrl](../../mfc/settings-for-the-cstatusbarctrl.md).  
  
 `dwStyle`  
 O estilo de barra de status. O padrão especifica a criação de uma barra de status visíveis na parte inferior da janela do quadro. Aplique qualquer combinação de estilos de controle listados da barra de status [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e [CDialogBar::Create](../../mfc/reference/cdialogbar-class.md#create). No entanto, esse parâmetro sempre deve incluir os estilos WS_CHILD e WS_VISIBLE.  
  
 `nID`  
 ID da janela filho da barra de status.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função também define a fonte inicial e define o status da altura da barra em um valor padrão.  
  
 Use `CreateEx`, em vez de [criar](#create), quando determinados estilos precisam estar presente durante a criação do controle da barra de status incorporada. Por exemplo, definir `dwCtrlStyle` para **SBT_TOOLTIPS** para exibir dicas de ferramenta em um objeto de barra de status.  
  
##  <a name="cstatusbar"></a>CStatusBar::CStatusBar  
 Constrói uma `CStatusBar` objeto, cria uma fonte de barra de status padrão, se necessário e define as características da fonte para os valores padrão.  
  
```  
CStatusBar();
```  
  
##  <a name="drawitem"></a>CStatusBar::DrawItem  
 Essa função de membro é chamada pelo framework quando um aspecto visual de uma alteração de barra de status desenhados pelo proprietário.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro para um [DRAWITEMSTRUCT](http://msdn.microsoft.com/library/windows/desktop/bb775802) estrutura que contém informações sobre o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 O **itemAction** membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CStatusBar` objeto. O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no `lpDrawItemStruct` antes do encerramento desta função de membro.  
  
##  <a name="getitemid"></a>CStatusBar::GetItemID  
 Retorna a ID do indicador especificado pelo `nIndex`.  
  
```  
UINT GetItemID(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do indicador cuja ID é a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID do indicador especificado pelo `nIndex`.  
  
##  <a name="getitemrect"></a>CStatusBar::GetItemRect  
 Copia as coordenadas do indicador especificado por `nIndex` para a estrutura apontada pelo `lpRect`.  
  
```  
void GetItemRect(
    int nIndex,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do indicador cujas coordenadas do retângulo devem ser recuperados.  
  
 `lpRect`  
 Aponta para um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) que receberá as coordenadas do indicador especificado pelo objeto `nIndex`.  
  
### <a name="remarks"></a>Comentários  
 As coordenadas são em pixels em relação ao canto superior esquerdo da barra de status.  
  
##  <a name="getpaneinfo"></a>CStatusBar::GetPaneInfo  
 Conjuntos de `nID`, `nStyle`, e `cxWidth` para a ID, o estilo e a largura do painel indicador no local especificado por `nIndex`.  
  
```  
void GetPaneInfo(
    int nIndex,  
    UINT& nID,  
    UINT& nStyle,  
    int& cxWidth) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do painel são cujas informações a serem recuperados.  
  
 `nID`  
 Referência a um **UINT** que é definido como a ID do painel.  
  
 `nStyle`  
 Referência a um **UINT** que é definido para o estilo do painel.  
  
 `cxWidth`  
 Referência a um número inteiro que é definida como a largura do painel.  
  
##  <a name="getpanestyle"></a>CStatusBar::GetPaneStyle  
 Chame essa função de membro para recuperar o estilo do painel da barra de status.  
  
```  
UINT GetPaneStyle(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do painel é cujo estilo a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 O estilo do painel barra de status especificado pelo `nIndex`.  
  
### <a name="remarks"></a>Comentários  
 Estilo do painel determina como o painel será exibido.  
  
 Para obter uma lista de estilos disponíveis para barras de status, consulte [criar](#create).  
  
##  <a name="getpanetext"></a>CStatusBar::GetPaneText  
 Chame essa função de membro para recuperar o texto que aparece em um painel da barra de status.  
  
```  
CString GetPaneText(int nIndex) const;  void GetPaneText(int nIndex, CString& rString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do painel cujo texto está para ser recuperado.  
  
 `rString`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o texto a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém o texto do painel.  
  
### <a name="remarks"></a>Comentários  
 O segundo formulário desse membro da função preenchimentos um `CString` objeto com o texto de cadeia de caracteres.  
  
##  <a name="getstatusbarctrl"></a>CStatusBar::GetStatusBarCtrl  
 Essa função de membro permite acesso direto ao controle comum subjacente.  
  
```  
CStatusBarCtrl& GetStatusBarCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Contém uma referência a um [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Use `GetStatusBarCtrl` para tirar proveito da funcionalidade de controle comum da barra de status do Windows e para aproveitar o suporte [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) permite a personalização da barra de status. Por exemplo, usando o controle comum, você pode especificar um estilo que inclui uma alça de dimensionamento na barra de status, ou você pode especificar um estilo para exibir a barra de status na parte superior da área cliente da janela pai.  
  
 Para obter mais informações sobre controles comuns, consulte [controles comuns](http://msdn.microsoft.com/library/windows/desktop/bb775493) no SDK do Windows.  
  
##  <a name="setindicators"></a>CStatusBar::SetIndicators  
 Define a ID do indicador, cada para o valor especificado pelo elemento correspondente da matriz `lpIDArray`, carrega o recurso de cadeia de caracteres especificado por cada ID e define o texto do indicador para a cadeia de caracteres.  
  
```  
BOOL SetIndicators(
    const UINT* lpIDArray,  
    int nIDCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpIDArray`  
 Ponteiro para uma matriz de IDs.  
  
 `nIDCount`  
 Número de elementos na matriz apontada pelo `lpIDArray`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="setpaneinfo"></a>CStatusBar::SetPaneInfo  
 Define o painel do indicador especificado para uma nova ID, estilo e largura.  
  
```  
void SetPaneInfo(
    int nIndex,  
    UINT nID,  
    UINT nStyle,  
    int cxWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do painel indicador cujo estilo será definido.  
  
 `nID`  
 Nova ID para o painel do indicador.  
  
 `nStyle`  
 Novo estilo para o painel do indicador.  
  
 `cxWidth`  
 Nova largura para o painel do indicador.  
  
### <a name="remarks"></a>Comentários  
 Há suporte para os seguintes estilos de indicador:  
  
- **SBPS_NOBORDERS** nenhuma borda 3D ao redor do painel.  
  
- **SBPS_POPOUT** inversa da borda para que o texto "exibido."  
  
- **SBPS_DISABLED** não desenhar o texto.  
  
- **SBPS_STRETCH** painel de ampliação para preencher o espaço não utilizado. Somente um painel por barra de status pode ter esse estilo.  
  
- **SBPS_NORMAL** nenhum stretch, bordas ou pop-out.  
  
##  <a name="setpanestyle"></a>CStatusBar::SetPaneStyle  
 Chame essa função de membro para definir o estilo do painel da barra de status.  
  
```  
void SetPaneStyle(
    int nIndex,  
    UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do painel cujo estilo será definido.  
  
 `nStyle`  
 Estilo do painel cujo estilo será definido.  
  
### <a name="remarks"></a>Comentários  
 Estilo do painel determina como o painel será exibido.  
  
 Para obter uma lista de estilos disponíveis para barras de status, consulte [SetPaneInfo](#setpaneinfo).  
  
##  <a name="setpanetext"></a>CStatusBar::SetPaneText  
 Chamar essa função de membro para definir o texto do painel para a cadeia de caracteres apontada por `lpszNewText`.  
  
```  
BOOL SetPaneText(
    int nIndex,  
    LPCTSTR lpszNewText,  
    BOOL bUpdate = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do painel cujo texto será definido.  
  
 `lpszNewText`  
 Ponteiro para o novo texto de painel.  
  
 *b Update*  
 Se **TRUE**, o painel é invalidado depois que o texto é definido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar `SetPaneText`, você deve adicionar um manipulador de atualização de interface do usuário para exibir o novo texto na barra de status.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#176](../../mfc/codesnippet/cpp/cstatusbar-class_1.cpp)]  
  
 [!code-cpp[NVC_MFCDocView#177](../../mfc/codesnippet/cpp/cstatusbar-class_2.cpp)]  
  
 [!code-cpp[NVC_MFCDocView#178](../../mfc/codesnippet/cpp/cstatusbar-class_3.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLBARS](../../visual-cpp-samples.md)   
 [DLGCBR32 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)
