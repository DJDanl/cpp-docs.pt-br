---
title: Classe CMFCDropDownToolbarButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCDropDownToolbarButton
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::CMFCDropDownToolbarButton
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::CopyFrom
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::DropDownToolbar
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::ExportToMenuButton
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::GetDropDownToolBar
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::IsDropDown
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::IsExtraSize
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnCalculateSize
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnChangeParentWnd
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnClick
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnClickUp
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnContextHelp
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnCustomizeMenu
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnDraw
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnDrawOnCustomizeList
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::Serialize
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::SetDefaultCommand
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::m_uiShowBarDelay
dev_langs:
- C++
helpviewer_keywords:
- CMFCDropDownToolbarButton class
- OnCancelMode method
ms.assetid: bc9d69e6-bd3e-4c15-9368-e80a504a0ba7
caps.latest.revision: 31
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
ms.openlocfilehash: 24398ddb605489bf9677bd493a1bc1f490d583b9
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcdropdowntoolbarbutton-class"></a>Classe CMFCDropDownToolbarButton
Um tipo de botão de barra de ferramentas que se comporta como um botão normal quando ele for clicado. No entanto, ele abre uma lista suspensa de barra de ferramentas ( [CMFCDropDownToolBar classe](../../mfc/reference/cmfcdropdowntoolbar-class.md) se o usuário pressiona e mantém o botão pressionado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDropDownToolbarButton : public CMFCToolBarButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCDropDownToolbarButton::CMFCDropDownToolbarButton](#cmfcdropdowntoolbarbutton)|Constrói um objeto `CMFCDropDownToolbarButton`.|  
|`CMFCDropDownToolbarButton::~CMFCDropDownToolbarButton`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCDropDownToolbarButton::CopyFrom](#copyfrom)|Copia as propriedades de outro botão de barra de ferramentas para o botão atual. (Substitui [CMFCToolBarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|  
|`CMFCDropDownToolbarButton::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|[CMFCDropDownToolbarButton::DropDownToolbar](#dropdowntoolbar)|Abre uma lista suspensa de barra de ferramentas.|  
|[CMFCDropDownToolbarButton::ExportToMenuButton](#exporttomenubutton)|Copia o texto do botão da barra de ferramentas para um menu. (Substitui [CMFCToolBarButton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton).)|  
|[CMFCDropDownToolbarButton::GetDropDownToolBar](#getdropdowntoolbar)|Recupera a barra de ferramentas lista suspensa é associada ao botão.|  
|`CMFCDropDownToolbarButton::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCDropDownToolbarButton::IsDropDown](#isdropdown)|Determina se a barra de ferramentas lista suspensa é aberta no momento.|  
|[CMFCDropDownToolbarButton::IsExtraSize](#isextrasize)|Determina se o botão pode ser exibido com uma borda estendida. (Substitui [CMFCToolBarButton::IsExtraSize](../../mfc/reference/cmfctoolbarbutton-class.md#isextrasize).)|  
|[CMFCDropDownToolbarButton::OnCalculateSize](#oncalculatesize)|Chamado pela estrutura para calcular o tamanho do botão para o contexto de dispositivo especificado e o estado de encaixe. (Substitui [CMFCToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|  
|`CMFCDropDownToolbarButton::OnCancelMode`|Chamado pela estrutura para lidar com a [WM_CANCELMODE](http://msdn.microsoft.com/library/windows/desktop/ms632615) mensagem. (Substitui `CMCToolBarButton::OnCancelMode`.)|  
|[CMFCDropDownToolbarButton::OnChangeParentWnd](#onchangeparentwnd)|Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas. (Substitui [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|  
|[CMFCDropDownToolbarButton::OnClick](#onclick)|Chamado pela estrutura quando o usuário clica no botão do mouse. (Substitui [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|  
|[CMFCDropDownToolbarButton::OnClickUp](#onclickup)|Chamado pela estrutura quando o usuário libera o botão do mouse. (Substitui [CMFCToolBarButton::OnClickUp](../../mfc/reference/cmfctoolbarbutton-class.md#onclickup).)|  
|[CMFCDropDownToolbarButton::OnContextHelp](#oncontexthelp)|Chamado pela estrutura quando a barra de ferramentas do pai manipula um `WM_HELPHITTEST` mensagem. (Substitui [CMFCToolBarButton::OnContextHelp](../../mfc/reference/cmfctoolbarbutton-class.md#oncontexthelp).)|  
|[CMFCDropDownToolbarButton::OnCustomizeMenu](#oncustomizemenu)|Modifica o menu fornecido quando o aplicativo exibe um menu de atalho da barra de ferramentas do pai. (Substitui [CMFCToolBarButton::OnCustomizeMenu](../../mfc/reference/cmfctoolbarbutton-class.md#oncustomizemenu).)|  
|[CMFCDropDownToolbarButton::OnDraw](#ondraw)|Chamado pela estrutura para desenhar o botão usando as opções e estilos especificados. (Substitui [CMFCToolBarButton::OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|  
|[CMFCDropDownToolbarButton::OnDrawOnCustomizeList](#ondrawoncustomizelist)|Chamado pela estrutura para desenhar o botão no **comandos** painel do **personalizar** caixa de diálogo. (Substitui [CMFCToolBarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|  
|[CMFCDropDownToolbarButton::Serialize](#serialize)|Lê esse objeto de um arquivo ou grava em um arquivo morto. (Substitui [CMFCToolBarButton::Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|  
|[CMFCDropDownToolbarButton::SetDefaultCommand](#setdefaultcommand)|Define o comando padrão que a estrutura usa quando um usuário clica no botão.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCDropDownToolbarButton::m_uiShowBarDelay](#m_uishowbardelay)|Especifica o período de tempo que um usuário deve pressionado o botão do mouse para a barra de ferramentas lista suspensa aparece.|  
  
## <a name="remarks"></a>Comentários  
 Um `CMFCDropDownToolBarButton` difere de um botão comum tem uma pequena seta no canto inferior direito do botão. Depois que o usuário seleciona um botão na barra de ferramentas lista suspensa, o framework exibe seu ícone no botão da barra de ferramentas de nível superior (o botão com a pequena seta no canto inferior direito).  
  
 Para obter informações sobre como implementar uma barra de ferramentas da lista suspensa, consulte [CMFCDropDownToolBar classe](../../mfc/reference/cmfcdropdowntoolbar-class.md).  
  
 O `CMFCDropDownToolBarButton` objeto pode ser exportado para um [CMFCToolBarMenuButton classe](../../mfc/reference/cmfctoolbarmenubutton-class.md) de objeto e exibido como um botão de menu com um menu pop-up.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdropdowntoolbar.h  
  
##  <a name="copyfrom"></a>CMFCDropDownToolbarButton::CopyFrom  
 Copia as propriedades de outro botão de barra de ferramentas para o botão atual.  
  
```  
virtual void CopyFrom(const CMFCToolBarButton& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
 Uma referência para o botão de origem da qual copiar.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para copiar outro botão da barra de ferramentas para este botão de barra de ferramentas. `src`deve ser do tipo `CMFCDropDownToolbarButton`.  
  
##  <a name="cmfcdropdowntoolbarbutton"></a>CMFCDropDownToolbarButton::CMFCDropDownToolbarButton  
 Constrói um objeto `CMFCDropDownToolbarButton`.  
  
```  
CMFCDropDownToolbarButton();

 
CMFCDropDownToolbarButton(
    LPCTSTR lpszName,  
    CMFCDropDownToolBar* pToolBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 O texto padrão do botão.  
  
 [in] `pToolBar`  
 Um ponteiro para o `CMFCDropDownToolBar` objeto que é exibido quando o usuário pressiona o botão.  
  
### <a name="remarks"></a>Comentários  
 A segunda sobrecarga do construtor copia para o botão suspenso no primeiro botão da barra de ferramentas que `pToolBar` especifica.  
  
 Normalmente, um botão suspenso utiliza o texto do botão usado mais recentemente na barra de ferramentas que `pToolBar` especifica. Ele usa o texto especificado por `lpszName` quando o botão é convertido em um botão de menu ou é exibido no **comandos** guia do **personalizar** caixa de diálogo. Para obter mais informações sobre o **personalizar** caixa de diálogo, consulte [CMFCToolBarsCustomizeDialog classe](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCDropDownToolbarButton` classe. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&#31;](../../mfc/codesnippet/cpp/cmfcdropdowntoolbarbutton-class_1.cpp)]  
  
##  <a name="dropdowntoolbar"></a>CMFCDropDownToolbarButton::DropDownToolbar  
 Abre uma lista suspensa de barra de ferramentas.  
  
```  
BOOL DropDownToolbar(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 A janela pai do quadro, o menu suspenso ou `NULL` para usar a janela pai do botão da barra de ferramentas da lista suspensa.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O [CMFCDropDownToolbarButton::OnClick](#onclick) método chama esse método para abrir a barra de ferramentas da lista suspensa quando o usuário pressiona e mantém o botão pressionado.  
  
 Este métodos cria a barra de ferramentas da lista suspensa, usando o [CMFCDropDownFrame::Create](../../mfc/reference/cmfcdropdownframe-class.md#create) método. Se a barra de ferramentas do pai é encaixada verticalmente, esse método posiciona a barra de ferramentas da lista suspensa para o lado esquerdo ou direito da barra de ferramentas pai, dependendo do ajuste. Caso contrário, esse método posiciona a barra de ferramentas lista suspensa sob a barra de ferramentas do pai.  
  
 Esse método falhará se `pWnd` é `NULL` e o botão suspenso não tem uma janela pai.  
  
##  <a name="exporttomenubutton"></a>CMFCDropDownToolbarButton::ExportToMenuButton  
 Copia o texto do botão da barra de ferramentas para um menu.  
  
```  
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `menuButton`  
 Uma referência para o botão de menu de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Este método chama a implementação da classe base ( [CMFCToolBarButton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)) e, em seguida, anexa ao botão de menu de destino um menu pop-up que contém cada item de menu da barra de ferramentas no botão. Esse método não anexa submenus no menu pop-up.  
  
 Esse método falhará se a barra de ferramentas do pai, `m_pToolBar`, é `NULL` ou retorna a implementação da classe base `FALSE`.  
  
##  <a name="getdropdowntoolbar"></a>CMFCDropDownToolbarButton::GetDropDownToolBar  
 Recupera a barra de ferramentas lista suspensa é associada ao botão.  
  
```  
CMFCToolBar* GetDropDownToolBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Barra de ferramentas lista suspensa que está associado com o botão.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna o `m_pToolBar` membro de dados.  
  
##  <a name="isdropdown"></a>CMFCDropDownToolbarButton::IsDropDown  
 Determina se a barra de ferramentas lista suspensa é aberta no momento.  
  
```  
BOOL IsDropDown() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a barra de ferramentas lista suspensa está atualmente aberta. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework abre a barra de ferramentas lista suspensa usando o [CMFCDropDownToolbarButton::DropDownToolbar](#dropdowntoolbar) método. O framework fecha a barra de ferramentas da lista suspensa quando o usuário pressiona o botão esquerdo do mouse na área não-cliente da barra de ferramentas lista suspensa.  
  
##  <a name="isextrasize"></a>CMFCDropDownToolbarButton::IsExtraSize  
 Determina se o botão pode ser exibido com uma borda estendida.  
  
```  
virtual BOOL IsExtraSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão da barra de ferramentas pode ser exibido com uma borda estendida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre bordas estendidas, consulte [CMFCToolBarButton::IsExtraSize](../../mfc/reference/cmfctoolbarbutton-class.md#isextrasize).  
  
##  <a name="m_uishowbardelay"></a>CMFCDropDownToolbarButton::m_uiShowBarDelay  
 Especifica o período de tempo que um usuário deve pressionado o botão do mouse para a barra de ferramentas lista suspensa aparece.  
  
```  
static UINT m_uiShowBarDelay;  
```  
  
### <a name="remarks"></a>Comentários  
 O tempo de atraso é medido em milissegundos. O valor padrão é 500. Você pode definir outra Atraso alterando o valor desse membro de dados compartilhados.  
  
##  <a name="oncalculatesize"></a>CMFCDropDownToolbarButton::OnCalculateSize  
 Chamado pela estrutura para calcular o tamanho do botão para o contexto de dispositivo especificado e o estado de encaixe.  
  
```  
virtual SIZE OnCalculateSize(
    CDC* pDC,  
    const CSize& sizeDefault,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão.  
  
 [in] `sizeDefault`  
 O tamanho padrão do botão.  
  
 [in] `bHorz`  
 O estado de encaixe da barra de ferramentas do pai. Esse parâmetro é `TRUE` se a barra de ferramentas está ancorada horizontalmente ou estiver flutuando, ou `FALSE` se a barra de ferramentas é encaixada verticalmente.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `SIZE` estrutura que contém as dimensões do botão, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método estende a implementação da classe base ( [CMFCToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize)), adicionando a largura da seta suspensa para a dimensão horizontal do tamanho do botão.  
  
##  <a name="onchangeparentwnd"></a>CMFCDropDownToolbarButton::OnChangeParentWnd  
 Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas.  
  
```  
virtual void OnChangeParentWnd(CWnd* pWndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 A nova janela pai.  
  
### <a name="remarks"></a>Comentários  
 Este método substitui a implementação da classe base ( [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)), limpando o rótulo de texto ( [CMFCToolBarButton::m_strText](../../mfc/reference/cmfctoolbarbutton-class.md#m_strtext)) e configuração de [CMFCToolBarButton::m_bText](../../mfc/reference/cmfctoolbarbutton-class.md#m_btext) e [CMFCToolBarButton::m_bUserButton](../../mfc/reference/cmfctoolbarbutton-class.md#m_buserbutton) membros de dados `FALSE`.  
  
##  <a name="onclick"></a>CMFCDropDownToolbarButton::OnClick  
 Chamado pela estrutura quando o usuário clica no botão do mouse.  
  
```  
virtual BOOL OnClick(
    CWnd* pWnd,  
    BOOL bDelay = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 A janela pai do botão da barra de ferramentas.  
  
 [in] `bDelay`  
 `TRUE`Se a mensagem deve ser tratada com um atraso.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão processa a mensagem de clique. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método estende a implementação da classe base, [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick), atualizando o estado da barra de ferramentas lista suspensa.  
  
 Quando um usuário clica no botão de barra de ferramentas, esse método cria um temporizador que aguarda o período de tempo especificado pelo [CMFCDropDownToolbarButton::m_uiShowBarDelay](#m_uishowbardelay) membro de dados e, em seguida, abre a lista suspensa de barra de ferramentas usando o [CMFCDropDownToolbarButton::DropDownToolbar](#dropdowntoolbar) método. Este método fecha a barra de ferramentas da lista suspensa na segunda vez que o usuário clica no botão da barra de ferramentas.  
  
##  <a name="onclickup"></a>CMFCDropDownToolbarButton::OnClickUp  
 Chamado pela estrutura quando o usuário libera o botão do mouse.  
  
```  
virtual BOOL OnClickUp();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão processa a mensagem de clique. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método estende a implementação da classe base, [CMFCToolBarButton::OnClickUp](../../mfc/reference/cmfctoolbarbutton-class.md#onclickup), atualizando o estado da barra de ferramentas lista suspensa.  
  
 Esse método para o temporizador de barra de ferramentas da lista suspensa se ele está ativo. Se ele estiver aberto, ele fecha a barra de ferramentas da lista suspensa.  
  
 Para obter mais informações sobre a lista suspensa da barra de ferramentas e o timer de lista suspensa da barra de ferramentas, consulte [CMFCDropDownToolbarButton::OnClick](#onclick).  
  
##  <a name="oncontexthelp"></a>CMFCDropDownToolbarButton::OnContextHelp  
 Chamado pela estrutura quando a barra de ferramentas do pai manipula um `WM_HELPHITTEST` mensagem.  
  
```  
virtual BOOL OnContextHelp(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 A janela pai do botão da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão processa a mensagem de Ajuda. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método estende a implementação da classe base ( [CMFCToolBarButton::OnContextHelp](../../mfc/reference/cmfctoolbarbutton-class.md#oncontexthelp)) chamando o [CMFCDropDownToolbarButton::OnClick](#onclick) método `bDelay` definida como `FALSE`. Esse método retorna o valor retornado por [CMFCDropDownToolbarButton::OnClick](#onclick).  
  
 Para obter mais informações sobre o `WM_HELPHITTEST message, see` [TN028: suporte de ajuda sensível ao contexto](../../mfc/tn028-context-sensitive-help-support.md).  
  
##  <a name="oncustomizemenu"></a>CMFCDropDownToolbarButton::OnCustomizeMenu  
 Modifica o menu fornecido quando o aplicativo exibe um menu de atalho da barra de ferramentas do pai.  
  
```  
virtual BOOL OnCustomizeMenu(CMenu* pMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenu`  
 Menu para personalizar.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método estende a implementação da classe base ( [CMFCToolBarButton::OnCustomizeMenu](../../mfc/reference/cmfctoolbarbutton-class.md#oncustomizemenu)), desativando os seguintes itens de menu:  
  
- **Copiar imagem de botão**  
  
- **Aparência do botão**  
  
- **Imagem**  
  
- **Texto**  
  
- **Imagem e texto**  
  
 Substitua este método para modificar o menu de atalho que exibe a estrutura no modo de personalização.  
  
##  <a name="ondraw"></a>CMFCDropDownToolbarButton::OnDraw  
 Chamado pela estrutura para desenhar o botão usando as opções e estilos especificados.  
  
```  
virtual void OnDraw(
    CDC* pDC,  
    const CRect& rect,  
    CMFCToolBarImages* pImages,  
    BOOL bHorz = TRUE,  
    BOOL bCustomizeMode = FALSE,  
    BOOL bHighlight = FALSE,  
    BOOL bDrawBorder = TRUE,  
    BOOL bGrayDisabledButtons = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão.  
  
 [in] `rect`  
 O retângulo delimitador do botão.  
  
 [in] `pImages`  
 A coleção de imagens da barra de ferramentas que está associada ao botão.  
  
 [in] `bHorz`  
 O estado de encaixe da barra de ferramentas do pai. Esse parâmetro é `TRUE` quando o botão está ancorado horizontalmente e `FALSE` quando o botão é encaixado verticalmente.  
  
 [in] `bCustomizeMode`  
 Especifica se a barra de ferramentas está no modo de personalização. Esse parâmetro é `TRUE` quando a barra de ferramentas estiver no modo de personalização e `FALSE` quando ela não estiver no modo de personalização.  
  
 [in] `bHighlight`  
 Especifica se o botão é realçado. Esse parâmetro é `TRUE` quando o botão é realçado e `FALSE` quando o botão não esteja realçado.  
  
 [in] `bDrawBorder`  
 Especifica se o botão deve exibir sua borda. Esse parâmetro é `TRUE` quando o botão deve exibir sua borda e `FALSE` quando o botão não deve exibir sua borda.  
  
 [in] `bGrayDisabledButtons`  
 Especifica se deseja sombrear botões desabilitados ou usar a coleção de imagens desabilitado. Esse parâmetro é `TRUE` quando botões desabilitados devem ser sombreado e `FALSE` quando este método deve usar a coleção de imagens desabilitado.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para personalizar o desenho de botão da barra de ferramentas.  
  
##  <a name="ondrawoncustomizelist"></a>CMFCDropDownToolbarButton::OnDrawOnCustomizeList  
 Chamado pela estrutura para desenhar o botão no **comandos** painel do **personalizar** caixa de diálogo.  
  
```  
virtual int OnDrawOnCustomizeList(
    CDC* pDC,  
    const CRect& rect,  
    BOOL bSelected);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 O contexto de dispositivo que exibe o botão.  
  
 [in] `rect`  
 O retângulo delimitador do botão.  
  
 [in] `bSelected`  
 Se o botão está selecionado. Se esse parâmetro for `TRUE`, o botão é selecionado. Se esse parâmetro for `FALSE`, o botão não estiver selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 A largura, em pixels, do botão no contexto do dispositivo especificado.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela caixa de diálogo de personalização ( **comandos** guia) quando o botão é necessário para exibir próprio na caixa de listagem de desenho proprietário.  
  
 Esse método estende a implementação da classe base ( [CMFCToolBarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist)) alterando o rótulo de texto do botão para o nome do botão (ou seja, para o valor da `lpszName` parâmetro passado para o construtor).  
  
##  <a name="serialize"></a>CMFCDropDownToolbarButton::Serialize  
 Lê esse objeto de um arquivo ou grava em um arquivo morto.  
  
```  
virtual void Serialize(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ar`  
 O `CArchive` objeto do qual ou para a qual serializar.  
  
### <a name="remarks"></a>Comentários  
 Esse método estende a implementação da classe base ( [CMFCToolBarButton::Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize)) ao serializar a ID de recurso da barra de ferramentas do pai. Quando estiver carregando o arquivo morto ( [CArchive::IsLoading](../../mfc/reference/carchive-class.md#isloading) retorna um valor diferente de zero), esse método define o `m_pToolBar` membro de dados na barra de ferramentas que contém a ID de recurso serializado.  
  
##  <a name="setdefaultcommand"></a>CMFCDropDownToolbarButton::SetDefaultCommand  
 Define o comando padrão que a estrutura usa quando um usuário clica no botão.  
  
```  
void SetDefaultCommand(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID do comando padrão.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para especificar um comando padrão que a estrutura é executado quando o usuário clica no botão. Um item com a ID de comando especificada por `uiCmd` deve estar localizado na barra de ferramentas lista suspensa pai.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md)   
 [Passo a passo: Colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)




