---
title: Classe CMFCToolBarEditBoxButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCToolBarEditBoxButton
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::CMFCToolBarEditBoxButton
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::CanBeStretched
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::CopyFrom
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::GetByCmd
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::GetContentsAll
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::GetContextMenuID
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::GetEditBorder
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::GetHwnd
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::GetInvalidateRect
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::HaveHotBorder
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::IsFlatMode
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::NotifyCommand
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::OnAddToCustomizePage
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::OnChangeParentWnd
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::OnClick
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::OnCtlColor
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::OnGlobalFontsChanged
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::OnMove
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::OnShow
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::OnSize
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::OnUpdateToolTip
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::SetContextMenuID
- AFXTOOLBAREDITBOXBUTTON/CMFCToolBarEditBoxButton::SetFlatMode
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBarEditBoxButton [MFC], CMFCToolBarEditBoxButton
- CMFCToolBarEditBoxButton [MFC], CanBeStretched
- CMFCToolBarEditBoxButton [MFC], CopyFrom
- CMFCToolBarEditBoxButton [MFC], GetByCmd
- CMFCToolBarEditBoxButton [MFC], GetContentsAll
- CMFCToolBarEditBoxButton [MFC], GetContextMenuID
- CMFCToolBarEditBoxButton [MFC], GetEditBorder
- CMFCToolBarEditBoxButton [MFC], GetHwnd
- CMFCToolBarEditBoxButton [MFC], GetInvalidateRect
- CMFCToolBarEditBoxButton [MFC], HaveHotBorder
- CMFCToolBarEditBoxButton [MFC], IsFlatMode
- CMFCToolBarEditBoxButton [MFC], NotifyCommand
- CMFCToolBarEditBoxButton [MFC], OnAddToCustomizePage
- CMFCToolBarEditBoxButton [MFC], OnChangeParentWnd
- CMFCToolBarEditBoxButton [MFC], OnClick
- CMFCToolBarEditBoxButton [MFC], OnCtlColor
- CMFCToolBarEditBoxButton [MFC], OnGlobalFontsChanged
- CMFCToolBarEditBoxButton [MFC], OnMove
- CMFCToolBarEditBoxButton [MFC], OnShow
- CMFCToolBarEditBoxButton [MFC], OnSize
- CMFCToolBarEditBoxButton [MFC], OnUpdateToolTip
- CMFCToolBarEditBoxButton [MFC], SetContextMenuID
- CMFCToolBarEditBoxButton [MFC], SetFlatMode
ms.assetid: b21d9b67-6bf7-4ca9-bd62-b237756e0ab3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0bddd7274feb9ecde268a94d7e9a6e857c906650
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33376812"
---
# <a name="cmfctoolbareditboxbutton-class"></a>Classe CMFCToolBarEditBoxButton
Um botão de barra de ferramentas que contém um controle de edição ( [CEdit classe](../../mfc/reference/cedit-class.md)).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBarEditBoxButton : public CMFCToolBarButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarEditBoxButton::CMFCToolBarEditBoxButton](#cmfctoolbareditboxbutton)|Constrói um objeto `CMFCToolBarEditBoxButton`.|  
|`CMFCToolBarEditBoxButton::~CMFCToolBarEditBoxButton`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarEditBoxButton::CanBeStretched](#canbestretched)|Especifica se um usuário pode ampliar o botão durante a personalização. (Substitui [CMFCToolBarButton::CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched).)|  
|[CMFCToolBarEditBoxButton::CopyFrom](#copyfrom)|Copia as propriedades de outro botão da barra de ferramentas para o botão atual. (Substitui [CMFCToolBarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|  
|`CMFCToolBarEditBoxButton::` [CMFCToolBarEditBoxButton::CreateEdit](#createedit)|Cria um novo controle de edição no botão.|  
|`CMFCToolBarEditBoxButton::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|[CMFCToolBarEditBoxButton::GetByCmd](#getbycmd)|Recupera o primeiro `CMFCToolBarEditBoxButton` objeto no aplicativo que possui a ID de comando especificado.|  
|[CMFCToolBarEditBoxButton::GetContentsAll](#getcontentsall)|Recupera o texto do primeiro controle de edição caixa de ferramentas que possui a ID de comando especificado.|  
|[CMFCToolBarEditBoxButton::GetContextMenuID](#getcontextmenuid)|Recupera a ID de recurso de menu de atalho que está associado com o botão.|  
|[CMFCToolBarEditBoxButton::GetEditBorder](#geteditborder)|Recupera o retângulo delimitador da parte de edição do botão Editar.|  
|`CMFCToolBarEditBoxButton::` [CMFCToolBarEditBoxButton::GetEditBox](#geteditbox)|Retorna um ponteiro para o controle de edição é inserido no botão.|  
|[CMFCToolBarEditBoxButton::GetHwnd](#gethwnd)|Recupera o identificador de janela que está associado com o botão da barra de ferramentas. (Substitui [CMFCToolBarButton::GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd).)|  
|[CMFCToolBarEditBoxButton::GetInvalidateRect](#getinvalidaterect)|Recupera a região da área cliente do botão que deve ser redesenhado. (Substitui [CMFCToolBarButton::GetInvalidateRect](../../mfc/reference/cmfctoolbarbutton-class.md#getinvalidaterect).)|  
|`CMFCToolBarEditBoxButton::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCToolBarEditBoxButton::HaveHotBorder](#havehotborder)|Determina se uma borda do botão é exibida quando um usuário clica no botão. (Substitui [CMFCToolBarButton::HaveHotBorder](../../mfc/reference/cmfctoolbarbutton-class.md#havehotborder).)|  
|[CMFCToolBarEditBoxButton::IsFlatMode](#isflatmode)|Determina se os botões da caixa de edição têm um estilo simples.|  
|[CMFCToolBarEditBoxButton::NotifyCommand](#notifycommand)|Especifica se o botão processa o [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem. (Substitui [CMFCToolBarButton::NotifyCommand](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand).)|  
|[CMFCToolBarEditBoxButton::OnAddToCustomizePage](#onaddtocustomizepage)|Chamado pelo framework quando o botão é adicionado a um **personalizar** caixa de diálogo. (Substitui [CMFCToolBarButton::OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage).)|  
|`CMFCToolBarEditBoxButton::OnCalculateSize`|Chamado pelo framework para calcular o tamanho do botão para o contexto de dispositivo especificado e o estado de encaixe. (Substitui [CMFCToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|  
|[CMFCToolBarEditBoxButton::OnChangeParentWnd](#onchangeparentwnd)|Chamado pelo framework quando o botão é inserido em uma nova barra de ferramentas. (Substitui [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|  
|[CMFCToolBarEditBoxButton::OnClick](#onclick)|Chamado pelo framework quando o usuário clica no botão do mouse. (Substitui [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|  
|[CMFCToolBarEditBoxButton::OnCtlColor](#onctlcolor)|Chamado pelo framework quando a barra de ferramentas do pai manipula um `WM_CTLCOLOR` mensagem. (Substitui [CMFCToolBarButton::OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor).)|  
|`CMFCToolBarEditBoxButton::OnDraw`|Chamado pelo framework para desenhar o botão usando as opções e estilos especificados. (Substitui [CMFCToolBarButton::OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|  
|`CMFCToolBarEditBoxButton::OnDrawOnCustomizeList`|Chamado pelo framework para desenhar o botão no **comandos** painel do **personalizar** caixa de diálogo. (Substitui [CMFCToolBarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|  
|[CMFCToolBarEditBoxButton::OnGlobalFontsChanged](#onglobalfontschanged)|Chamado pelo framework quando a fonte global foi alterada. (Substitui [CMFCToolBarButton::OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged).)|  
|[CMFCToolBarEditBoxButton::OnMove](#onmove)|Chamado pelo framework quando move a barra de ferramentas do pai. (Substitui [CMFCToolBarButton::OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove).)|  
|[CMFCToolBarEditBoxButton::OnShow](#onshow)|Chamado pelo framework quando o botão ficará visível ou invisível. (Substitui [CMFCToolBarButton::OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow).)|  
|[CMFCToolBarEditBoxButton::OnSize](#onsize)|Chamado pelo framework quando a barra de ferramentas do pai altera seu tamanho ou posição e essa alteração faz com que o botão Alterar o tamanho. (Substitui [CMFCToolBarButton::OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize).)|  
|[CMFCToolBarEditBoxButton::OnUpdateToolTip](#onupdatetooltip)|Chamado pelo framework quando a barra de ferramentas do pai atualiza seu texto de dica de ferramenta. (Substitui [CMFCToolBarButton::OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip).)|  
|`CMFCToolBarEditBoxButton::Serialize`|Lê esse objeto de um arquivo ou grava em um arquivo morto. (Substitui [CMFCToolBarButton::Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|  
|`CMFCToolBarEditBoxButton::SetACCData`|Popula fornecido `CAccessibilityData` objeto com dados de acessibilidade do botão da barra de ferramentas. (Substitui [CMFCToolBarButton::SetACCData](../../mfc/reference/cmfctoolbarbutton-class.md#setaccdata).)|  
|`CMFCToolBarEditBoxButton::` [CMFCToolBarEditBoxButton::SetContents](#setcontents)|Define o texto no controle de edição do botão.|  
|`CMFCToolBarEditBoxButton::` [CMFCToolBarEditBoxButton::SetContentsAll](#setcontentsall)|Localiza o botão de controle de edição que tem uma ID de comando especificado e define o texto no controle de edição do botão.|  
|[CMFCToolBarEditBoxButton::SetContextMenuID](#setcontextmenuid)|Especifica a ID de recurso do menu de atalho que está associado com o botão.|  
|[CMFCToolBarEditBoxButton::SetFlatMode](#setflatmode)|Especifica a aparência de estilo plano dos botões da caixa de edição no aplicativo.|  
|`CMFCToolBarEditBoxButton::` [CMFCToolBarEditBoxButton::SetStyle](#setstyle)|Especifica o estilo do botão. (Substitui [CMFCToolBarButton::SetStyle](../../mfc/reference/cmfctoolbarbutton-class.md#setstyle).)|  
  
## <a name="remarks"></a>Comentários  
 Para adicionar um botão da caixa de edição para uma barra de ferramentas, siga estas etapas:  
  
 1. Reserve uma ID de recurso fictício do botão no recurso pai da barra de ferramentas.  
  
 2. Construir um `CMFCToolBarEditBoxButton` objeto.  
  
 3. No manipulador de mensagens que processa o `AFX_WM_RESETTOOLBAR` mensagem, substitua o botão fictício com o novo botão de caixa de combinação usando [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).  
  
 Para obter mais informações, consulte [passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCToolBarEditBoxButton` classe. O exemplo mostra como especificar que um usuário pode ampliar o botão durante a personalização, especificar que uma borda do botão é exibida quando um usuário clica no botão, definir o texto no controle de caixa de texto, especifique a aparência de estilo plano dos botões da caixa de edição de Apli CAL e especifique o estilo de uma barra de ferramentas controle de caixa de edição.  
  
 [!code-cpp[NVC_MFC_RibbonApp#40](../../mfc/reference/codesnippet/cpp/cmfctoolbareditboxbutton-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 `CMFCToolBarEditBoxButton` 
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbareditboxbutton.h  
  
##  <a name="canbestretched"></a>  CMFCToolBarEditBoxButton::CanBeStretched  
 Especifica se um usuário pode ampliar o botão durante a personalização.  
  
```  
virtual BOOL CanBeStretched() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Este método retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, a estrutura não permite ao usuário para alongar um botão de barra de ferramentas durante a personalização. Este método estende a implementação da classe base ( [CMFCToolBarButton::CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched)), permitindo que o usuário Alongar um botão de barra de ferramentas de caixa de edição durante a personalização.  
  
##  <a name="cmfctoolbareditboxbutton"></a>  CMFCToolBarEditBoxButton::CMFCToolBarEditBoxButton  
 Constrói um [CMFCToolBarEditBoxButton](../../mfc/reference/cmfctoolbareditboxbutton-class.md) objeto.  
  
```  
CMFCToolBarEditBoxButton(
    UINT uiID,  
    int iImage,  
    DWORD dwStyle=ES_AUTOHSCROLL,  
    int iWidth=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiID`  
 Especifica a ID do controle.  
  
 [in] `iImage`  
 Especifica o índice de base zero de uma imagem da barra de ferramentas. A imagem está localizada no [CMFCToolBarImages classe](../../mfc/reference/cmfctoolbarimages-class.md) o objeto [CMFCToolBar classe](../../mfc/reference/cmfctoolbar-class.md) classe mantém.  
  
 [in] `dwStyle`  
 Especifica o estilo de controle de edição.  
  
 [in] `iWidth`  
 Especifica a largura em pixels do controle de edição.  
  
### <a name="remarks"></a>Comentários  
 O construtor padrão define o estilo de controle de edição para a seguinte combinação:  
  
 `WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL`  
  
 A largura padrão do controle é 150 pixels.  
  
##  <a name="copyfrom"></a>  CMFCToolBarEditBoxButton::CopyFrom  
 Copia as propriedades de outro botão da barra de ferramentas para o botão atual.  
  
```  
virtual void CopyFrom(const CMFCToolBarButton& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
 Uma referência para o botão de origem da qual copiar.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para copiar outro botão da barra de ferramentas para este botão de barra de ferramentas. `src` deve ser do tipo `CMFCToolBarEditBoxButton`.  
  
##  <a name="createedit"></a>  CMFCToolBarEditBoxButton::CreateEdit  
 Cria um novo controle de edição no botão.  
  
```  
virtual CEdit* CreateEdit(
    CWnd* pWndParent,  
    const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] pWndParent`  
 Especifica a janela pai do controle de edição. Ele não deve ser NULL.  
  
 `[in] rect`  
 Especifica o tamanho e a posição do controle de edição.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o controle de edição recém-criada; é `NULL` se a falha de criação do controle e o anexo.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CMFCToolBarEditBoxButton` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chamar `CreateEdit`, que cria o controle de edição do Windows e a anexa ao `CMFCToolBarEditBoxButton` objeto.  
  
##  <a name="getbycmd"></a>  CMFCToolBarEditBoxButton::GetByCmd  
 Recupera o primeiro `CMFCToolBarEditBoxButton` objeto no aplicativo que possui a ID de comando especificado.  
  
```  
static CMFCToolBarEditBoxButton* __stdcall GetByCmd(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID do botão de comando para recuperar.  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira `CMFCToolBarEditBoxButton` objeto no aplicativo que tem a ID de comando especificado, ou `NULL` se esse objeto não existe.  
  
### <a name="remarks"></a>Comentários  
 Esse método de utilitário compartilhados é usado pelos métodos como [CMFCToolBarEditBoxButton::SetContentsAll](#setcontentsall) e [CMFCToolBarEditBoxButton::GetContentsAll](#getcontentsall) para definir ou obter o texto da barra de ferramentas de edição caixa primeiro controle que possui a ID de comando especificado.  
  
##  <a name="getcontentsall"></a>  CMFCToolBarEditBoxButton::GetContentsAll  
 Recupera o texto do primeiro controle de edição caixa de ferramentas que possui a ID de comando especificado.  
  
```  
static CString __stdcall GetContentsAll(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de comando do botão do qual recuperar o conteúdo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém o texto do primeiro controle de edição caixa de ferramentas que possui a ID de comando especificado.  
  
### <a name="remarks"></a>Comentários  
 Este método retorna a cadeia de caracteres vazia se nenhum `CMFCToolBarEditBoxButton` objetos têm a ID de comando especificado.  
  
##  <a name="getcontextmenuid"></a>  CMFCToolBarEditBoxButton::GetContextMenuID  
 Recupera a ID de recurso de menu de atalho que está associado com o botão.  
  
```  
UINT GetContextMenuID();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de recurso do menu de atalho que está associado com o botão ou 0 se o botão de menu de atalho associado não.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa a ID de recurso para criar o menu de atalho quando o usuário clica no botão.  
  
##  <a name="geteditborder"></a>  CMFCToolBarEditBoxButton::GetEditBorder  
 Recupera o retângulo delimitador da parte de edição do botão Editar.  
  
```  
virtual void GetEditBorder(CRect& rectBorder);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rectBorder`  
 Uma referência para o `CRect` objeto que recebe o retângulo delimitador.  
  
### <a name="remarks"></a>Comentários  
 Esse método recupera o retângulo delimitador do controle de edição em coordenadas do cliente. Ele expande o tamanho do retângulo em cada direção de um pixel.  
  
 O [CMFCVisualManager::OnDrawEditBorder](../../mfc/reference/cmfcvisualmanager-class.md#ondraweditborder) método chama este método quando ele desenha a borda ao redor de um `CMFCToolBarEditBoxButton` objeto.  
  
##  <a name="geteditbox"></a>  CMFCToolBarEditBoxButton::GetEditBox  
 Retorna um ponteiro para o [CEdit classe](../../mfc/reference/cedit-class.md) controle que é inserido no botão.  
  
```  
CEdit* GetEditBox() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CEdit classe](../../mfc/reference/cedit-class.md) controle que contém o botão. É `NULL` se o `CEdit` controle ainda não foi criado.  
  
### <a name="remarks"></a>Comentários  
 Você cria o `CEdit` controle chamando [CMFCToolBarEditBoxButton::CreateEdit](#createedit).  
  
##  <a name="gethwnd"></a>  CMFCToolBarEditBoxButton::GetHwnd  
 Recupera o identificador de janela que está associado com o botão da barra de ferramentas.  
  
```  
virtual HWND GetHwnd();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de janela que está associado com o botão.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui o [CMFCToolBarButton::GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd) método retornando o identificador de janela da parte de controle de edição do botão Editar.  
  
##  <a name="getinvalidaterect"></a>  CMFCToolBarEditBoxButton::GetInvalidateRect  
 Recupera a região da área cliente do botão que deve ser redesenhado.  
  
```  
virtual const CRect GetInvalidateRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CRect` objeto que especifica a região que deve ser redesenhada.  
  
### <a name="remarks"></a>Comentários  
 Este método estende a implementação da classe base, [CMFCToolBarButton::GetInvalidateRect](../../mfc/reference/cmfctoolbarbutton-class.md#getinvalidaterect), incluindo na região a área do rótulo de texto.  
  
##  <a name="havehotborder"></a>  CMFCToolBarEditBoxButton::HaveHotBorder  
 Determina se uma borda do botão é exibida quando um usuário clica no botão.  
  
```  
virtual BOOL HaveHotBorder() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um botão exibir sua borda quando selecionada. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Este método estende a implementação da classe base, [CMFCToolBarButton::HaveHotBorder](../../mfc/reference/cmfctoolbarbutton-class.md#havehotborder), retornando um valor diferente de zero se o controle está visível.  
  
##  <a name="isflatmode"></a>  CMFCToolBarEditBoxButton::IsFlatMode  
 Determina se os botões da caixa de edição têm um estilo simples.  
  
```  
static BOOL __stdcall IsFlatMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se os botões têm um estilo simples; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, os botões da caixa de edição tem um estilo simples. Use o [CMFCToolBarEditBoxButton::SetFlatMode](#setflatmode) método para alterar a aparência de estilo plano para o seu aplicativo.  
  
##  <a name="notifycommand"></a>  CMFCToolBarEditBoxButton::NotifyCommand  
 Especifica se o botão processa o [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem.  
  
```  
virtual BOOL NotifyCommand(int iNotifyCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iNotifyCode`  
 A mensagem de notificação que está associada com o comando.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o botão processa o `WM_COMMAND` mensagem, ou `FALSE` para indicar que a mensagem deve ser tratada pela barra de ferramentas do pai.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele está prestes a enviar um [WM_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) mensagem para a janela pai.  
  
 Este método estende a implementação da classe base ( [CMFCToolBarButton::NotifyCommand](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand)) processando o [EN_UPDATE](http://msdn.microsoft.com/library/windows/desktop/bb761687) notificação. Para cada caixa de edição com a mesma ID de comando como esse objeto, ele define o rótulo de texto para o rótulo de texto do objeto.  
  
##  <a name="onaddtocustomizepage"></a>  CMFCToolBarEditBoxButton::OnAddToCustomizePage  
 Chamado pelo framework quando o botão é adicionado a um **personalizar** caixa de diálogo.  
  
```  
virtual void OnAddToCustomizePage();
```  
  
### <a name="remarks"></a>Comentários  
 Este método estende a implementação da classe base ( [CMFCToolBarButton::OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage)), copiando as propriedades de controle de caixa de edição em qualquer barra de ferramentas que tem a mesma ID de comando como este objeto. Esse método não fará nada se nenhuma barra de ferramentas tem um controle de caixa de edição que tem a mesma ID de comando como este objeto.  
  
 Para obter mais informações sobre o **personalizar** caixa de diálogo, consulte [CMFCToolBarsCustomizeDialog classe](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).  
  
##  <a name="onchangeparentwnd"></a>  CMFCToolBarEditBoxButton::OnChangeParentWnd  
 Chamado pelo framework quando o botão é inserido em uma nova barra de ferramentas.  
  
```  
virtual void OnChangeParentWnd(CWnd* pWndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Um ponteiro para a nova janela pai.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe base ( [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)) recriando interno `CEdit` objeto.  
  
##  <a name="onclick"></a>  CMFCToolBarEditBoxButton::OnClick  
 Chamado pelo framework quando o usuário clica no botão do mouse.  
  
```  
virtual BOOL OnClick(
    CWnd* pWnd,  
    BOOL bDelay = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Não utilizado.  
  
 [in] `bDelay`  
 Não utilizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão processa a mensagem de clique; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe base ( [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick)), retornando um valor diferente de zero se interno `CEdit` objeto está visível.  
  
##  <a name="onctlcolor"></a>  CMFCToolBarEditBoxButton::OnCtlColor  
 Chamado pelo framework quando a barra de ferramentas do pai manipula um `WM_CTLCOLOR` mensagem.  
  
```  
virtual HBRUSH OnCtlColor(
    CDC* pDC,  
    UINT nCtlColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão.  
  
 [in] `nCtlColor`  
 Não utilizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o pincel de janela global.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe base ( [CMFCToolBarButton::OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor)) definindo as cores de texto e plano de fundo do contexto do dispositivo fornecido ao texto global e cores de plano de fundo, respectivamente.  
  
 Para obter mais informações sobre as opções globais que estão disponíveis para seu aplicativo, consulte [estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md).  
  
##  <a name="onglobalfontschanged"></a>  CMFCToolBarEditBoxButton::OnGlobalFontsChanged  
 Chamado pelo framework quando a fonte global foi alterada.  
  
```  
virtual void OnGlobalFontsChanged();
```  
  
### <a name="remarks"></a>Comentários  
 Este método estende a implementação da classe base ( [CMFCToolBarButton::OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged)) alterando a fonte do controle da fonte global.  
  
 Para obter mais informações sobre as opções globais que estão disponíveis para seu aplicativo, consulte [estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md).  
  
##  <a name="onmove"></a>  CMFCToolBarEditBoxButton::OnMove  
 Chamado pelo framework quando move a barra de ferramentas do pai.  
  
```  
virtual void OnMove();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe padrão ( [CMFCToolBarButton::OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove)) ao atualizar a posição da interno `CEdit` objeto  
  
##  <a name="onshow"></a>  CMFCToolBarEditBoxButton::OnShow  
 Chamado pelo framework quando o botão ficará visível ou invisível.  
  
```  
virtual void OnShow(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 Especifica se o botão é visível. Se esse parâmetro for `TRUE`, o botão é visível. Caso contrário, o botão não estiver visível.  
  
### <a name="remarks"></a>Comentários  
 Este método estende a implementação da classe base ( [CMFCToolBarButton::OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow)), exibindo o botão se `bShow` é `TRUE`. Caso contrário, esse método oculta o botão.  
  
##  <a name="onsize"></a>  CMFCToolBarEditBoxButton::OnSize  
 Chamado pelo framework quando a barra de ferramentas do pai altera seu tamanho ou posição e essa alteração faz com que o botão Alterar o tamanho.  
  
```  
virtual void OnSize(int iSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iSize`  
 A nova largura do botão, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método substitui a implementação da classe padrão, [CMFCToolBarButton::OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize), atualizando o tamanho e posição de interno `CEdit` objeto.  
  
##  <a name="onupdatetooltip"></a>  CMFCToolBarEditBoxButton::OnUpdateToolTip  
 Chamado pelo framework quando a barra de ferramentas do pai atualiza seu texto de dica de ferramenta.  
  
```  
virtual BOOL OnUpdateToolTip(
    CWnd* pWndParent,  
    int iButtonIndex,  
    CToolTipCtrl& wndToolTip,  
    CString& str);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Não utilizado.  
  
 [in] `iButtonIndex`  
 Não utilizado.  
  
 [in] `wndToolTip`  
 O controle que exibe o texto de dica de ferramenta.  
  
 [out] `str`  
 Um `CString` objeto que recebe o texto de dica de ferramenta atualizada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método atualiza o texto de dica de ferramenta. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Este método estende a implementação da classe base ( [CMFCToolBarButton::OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip)), exibindo o texto de dica de ferramenta que está associado com a parte de edição do botão. Se o interno `CEdit` objeto `NULL` ou o identificador de janela do `CEdit` objeto não identifica uma janela existente, este método não faz nada e retorna `FALSE`.  
  
##  <a name="setcontents"></a>  CMFCToolBarEditBoxButton::SetContents  
 Define o texto no controle de caixa de texto.  
  
```  
virtual void SetContents(const CString& sContents);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] sContents`  
 Especifica o novo texto a ser definido.  
  
##  <a name="setcontentsall"></a>  CMFCToolBarEditBoxButton::SetContentsAll  
 Localiza um [CMFCToolBarEditBoxButton](../../mfc/reference/cmfctoolbareditboxbutton-class.md) objeto que tem uma ID de comando especificado e define o texto especificado na sua caixa de texto.  
  
```  
static BOOL SetContentsAll(
    UINT uiCmd,  
    const CString& strContents);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 Especifica a ID de comando do controle para o qual o texto será alterado.  
  
 [in] `strContents`  
 Especifica o novo texto a ser definido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o texto foi definido; 0 se o `CMFCToolBarEditBoxButton` controle com a ID de comando especificado não existe.  
  
##  <a name="setcontextmenuid"></a>  CMFCToolBarEditBoxButton::SetContextMenuID  
 Especifica a ID de recurso do menu de atalho que está associado com o botão.  
  
```  
void SetContextMenuID(UINT uiResID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de recurso do menu de atalho.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa a ID de recurso para criar o menu de atalho quando o usuário clica no botão de barra de ferramentas.  
  
##  <a name="setflatmode"></a>  CMFCToolBarEditBoxButton::SetFlatMode  
 Especifica a aparência de estilo plano dos botões da caixa de edição no aplicativo.  
  
```  
static void __stdcall SetFlatMode(BOOL bFlat = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bFlat`  
 O estilo de simples para os botões da caixa de edição. Se esse parâmetro for `TRUE`, a aparência de estilo plano está habilitada; caso contrário, a aparência de estilo plano está desabilitada.  
  
### <a name="remarks"></a>Comentários  
 O estilo de padrão simples para os botões da caixa de edição é `TRUE`. Use o [CMFCToolBarEditBoxButton::IsFlatMode](#isflatmode) método para recuperar a aparência de estilo plano para o seu aplicativo.  
  
##  <a name="setstyle"></a>  CMFCToolBarEditBoxButton::SetStyle  
 Especifica o estilo de uma barra de ferramentas de controle de caixa de edição.  
  
```  
virtual void SetStyle(UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nStyle`  
 Um novo estilo para definir.  
  
### <a name="remarks"></a>Comentários  
 Esse método define [CMFCToolBarButton::m_nStyle](../../mfc/reference/cmfctoolbarbutton-class.md#m_nstyle) para `nStyle` também desabilita a caixa de texto quando o aplicativo está no modo de personalizar e permite que ele quando o aplicativo não está no modo de personalizar (consulte [CMFCToolBar: : SetCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#setcustomizemode) e [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)). Consulte [estilos de controle de barra de ferramentas](../../mfc/reference/toolbar-control-styles.md) para obter uma lista de sinalizadores de estilo válido.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)   
 [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)   
 [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)



