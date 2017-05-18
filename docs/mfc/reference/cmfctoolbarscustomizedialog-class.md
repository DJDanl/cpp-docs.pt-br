---
title: Classe CMFCToolBarsCustomizeDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCToolBarsCustomizeDialog
- AFXTOOLBARSCUSTOMIZEDIALOG/CMFCToolBarsCustomizeDialog
- AFXTOOLBARSCUSTOMIZEDIALOG/CMFCToolBarsCustomizeDialog::CMFCToolBarsCustomizeDialog
- AFXTOOLBARSCUSTOMIZEDIALOG/CMFCToolBarsCustomizeDialog::FillAllCommandsList
- AFXTOOLBARSCUSTOMIZEDIALOG/CMFCToolBarsCustomizeDialog::FillCategoriesComboBox
- AFXTOOLBARSCUSTOMIZEDIALOG/CMFCToolBarsCustomizeDialog::FillCategoriesListBox
- AFXTOOLBARSCUSTOMIZEDIALOG/CMFCToolBarsCustomizeDialog::GetCommandName
- AFXTOOLBARSCUSTOMIZEDIALOG/CMFCToolBarsCustomizeDialog::GetCountInCategory
- AFXTOOLBARSCUSTOMIZEDIALOG/CMFCToolBarsCustomizeDialog::GetFlags
- AFXTOOLBARSCUSTOMIZEDIALOG/CMFCToolBarsCustomizeDialog::OnInitDialog
- AFXTOOLBARSCUSTOMIZEDIALOG/CMFCToolBarsCustomizeDialog::PostNcDestroy
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBarsCustomizeDialog class
ms.assetid: 78e2cddd-4f13-4097-afc3-1ad646a113f1
caps.latest.revision: 28
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
ms.openlocfilehash: 069498d958dd5d9c3befc2a179c67636ce0ac9ae
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfctoolbarscustomizedialog-class"></a>Classe CMFCToolBarsCustomizeDialog
Uma caixa de diálogo sem janela restrita guia ( [classe CPropertySheet](../../mfc/reference/cpropertysheet-class.md)) que permite ao usuário personalizar barras de ferramentas, menus, atalhos de teclado, ferramentas definidas pelo usuário e estilo visual em um aplicativo. Normalmente, o usuário acessa esta caixa de diálogo selecionando **personalizar** do **ferramentas** menu.  
  
 O **personalizar** caixa de diálogo tem seis guias: **comandos**, **barras de ferramentas**, **ferramentas**, **teclado**, **Menu**, e **opções**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBarsCustomizeDialog : public CPropertySheet  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarsCustomizeDialog::CMFCToolBarsCustomizeDialog](#cmfctoolbarscustomizedialog)|Constrói um objeto `CMFCToolBarsCustomizeDialog`.|  
|`CMFCToolBarsCustomizeDialog::~CMFCToolBarsCustomizeDialog`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::AddButton](#addbutton)|Insere um botão de barra de ferramentas na lista de comandos no **comandos** página|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::AddMenu](#addmenu)|Carrega um menu de recursos e chamadas [CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands) Adicionar menu à lista de comandos no **comandos** página.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands)|Carrega um menu de recursos e chamadas [CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands) Adicionar menu à lista de comandos no **comandos** página.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::AddToolBar](#addtoolbar)|Carrega uma barra de ferramentas de recursos. Em seguida, para cada comando do menu de chamadas a [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método para inserir um botão na lista de comandos de **comandos** página sob a categoria especificada.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::Create](#create)|Exibe o **personalização** caixa de diálogo.|  
|`CMFCToolBarsCustomizeDialog::EnableTools`|Reservado para uso futuro.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::EnableUserDefinedToolbars](#enableuserdefinedtoolbars)|Habilita ou desabilita criando novas barras de ferramentas usando o **personalizar** caixa de diálogo.|  
|[CMFCToolBarsCustomizeDialog::FillAllCommandsList](#fillallcommandslist)|Preenche o fornecido `CListBox` objeto com os comandos de **todos os comandos** categoria.|  
|[CMFCToolBarsCustomizeDialog::FillCategoriesComboBox](#fillcategoriescombobox)|Preenche o fornecido `CComboBox` objeto com o nome de cada categoria de comando na **personalizar** caixa de diálogo.|  
|[CMFCToolBarsCustomizeDialog::FillCategoriesListBox](#fillcategorieslistbox)|Preenche o fornecido `CListBox` objeto com o nome de cada categoria de comando na **personalizar** caixa de diálogo.|  
|[CMFCToolBarsCustomizeDialog::GetCommandName](#getcommandname)|Recupera o nome que está associado com a ID do comando especificado.|  
|[CMFCToolBarsCustomizeDialog::GetCountInCategory](#getcountincategory)|Recupera o número de itens na lista fornecida com um rótulo de texto especificado.|  
|[CMFCToolBarsCustomizeDialog::GetFlags](#getflags)|Recupera o conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.|  
|`CMFCToolBarsCustomizeDialog::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::OnEditToolbarMenuImage](#onedittoolbarmenuimage)|Inicia um editor de imagens para que um usuário pode personalizar um ícone de item de menu ou botão da barra de ferramentas.|  
|[CMFCToolBarsCustomizeDialog::OnInitDialog](#oninitdialog)|Substituições para aumentar a inicialização da folha de propriedade. (Substitui [CPropertySheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog).)|  
|[CMFCToolBarsCustomizeDialog::PostNcDestroy](#postncdestroy)|Chamado pela estrutura depois que a janela foi destruída. (Substitui `CPropertySheet::PostNcDestroy`.)|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::RemoveButton](#removebutton)|Remove o botão com a ID de comando especificado de categoria especificada ou de todas as categorias.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::RenameCategory](#renamecategory)|Renomeia uma categoria na caixa de listagem das categorias no **comandos** guia.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::ReplaceButton](#replacebutton)|Substitui um botão na lista de comandos do **comandos** guia com um novo objeto de botão de barra de ferramentas.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::SetUserCategory](#setusercategory)|Adiciona uma categoria à lista de categorias que serão exibidos na **comandos** guia.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::CheckToolsValidity](#checktoolsvalidity)|Chamado pela estrutura para determinar se a lista de ferramentas definidas pelo usuário é válida.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::OnAfterChangeTool](#onafterchangetool)|Chamado pela estrutura quando alteram as propriedades de uma ferramenta definida pelo usuário.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::OnAssignKey](#onassignkey)|Determina se um atalho de teclado especificado pode ser atribuído a uma ação.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::OnBeforeChangeTool](#onbeforechangetool)|Determina se uma ferramenta definida pelo usuário pode ser alterada.|  
|`CMFCToolBarsCustomizeDialog::`[CMFCToolBarsCustomizeDialog::OnInitToolsPage](#oninittoolspage)|Chamado pela estrutura quando o usuário escolhe o **ferramentas** guia é solicitada.|  
  
## <a name="remarks"></a>Comentários  
 Para exibir o **personalizar** caixa de diálogo caixa, crie um `CMFCToolBarsCustomizeDialog` objeto e chamar o [CMFCToolBarsCustomizeDialog::Create](#create) método.  
  
 Enquanto o **personalizar** caixa de diálogo estiver ativa, o aplicativo funciona em um modo especial que limita a tarefas de personalização do usuário.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCToolBarsCustomizeDialog` classe. O exemplo mostra como substituir um botão da barra de ferramentas na caixa de listagem de comandos no **comandos** página, habilite a criação de novas barras de ferramentas usando o **personalizar** caixa de diálogo e exibir o **personalização** caixa de diálogo. Este trecho de código é parte do [exemplo IE demonstração](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo n º&4;](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CPropertySheet](../../mfc/reference/cpropertysheet-class.md)  
  
 `CMFCToolBarsCustomizeDialog`   
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxToolBarsCustomizeDialog.h  
  
##  <a name="addbutton"></a>CMFCToolBarsCustomizeDialog::AddButton  
 Insere um botão de barra de ferramentas na lista de comandos no **comandos** página.  
  
```  
void AddButton(
    UINT uiCategoryId,  
    const CMFCToolBarButton& button,  
    int iInsertBefore=-1);

void AddButton(
    LPCTSTR lpszCategory,  
    const CMFCToolBarButton& button,  
    int iInsertBefore=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCategoryId`  
 Especifica a ID da categoria para inserir o botão.  
  
 [in] `button`  
 Especifica o botão Inserir.  
  
 [in] `iInsertBefore`  
 Especifica o índice com base em zero de um botão da barra de ferramentas antes que o botão é inserido.  
  
 [in] `lpszCategory`  
 Especifica a cadeia de caracteres de categoria para inserir o botão.  
  
### <a name="remarks"></a>Comentários  
 O `AddButton` método ignora botões que têm as IDs de comando padrão (como ID_FILE_MRU_FILE1), comandos que não são permitidos (consulte [CMFCToolBar::IsCommandPermitted](../../mfc/reference/cmfctoolbar-class.md#iscommandpermitted)) e fictício botões.  
  
 Esse método cria um novo objeto do mesmo tipo como `button` (geralmente um [CMFCToolBarButton classe](../../mfc/reference/cmfctoolbarbutton-class.md)) usando a classe de tempo de execução do botão. Depois, ele chama [CMFCToolBarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom) para copiar os membros de dados de botão e insere a cópia na categoria especificada.  
  
 Quando o botão novo é inserido, ele recebe o `OnAddToCustomizePage` notificação.  
  
 Se `iInsertBefore` é -1, o botão é acrescentado à lista de categorias; caso contrário, ele é inserido antes do item com o índice especificado.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `AddButton` método o `CMFCToolBarsCustomizeDialog` classe. Este trecho de código é parte do [exemplo de controle deslizante](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_Slider n º&1;](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_2.cpp)]  
  
##  <a name="addmenu"></a>CMFCToolBarsCustomizeDialog::AddMenu  
 Carrega um menu de recursos e chamadas [CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands) Adicionar menu à lista de comandos no **comandos** página.  
  
```  
BOOL AddMenu(UINT uiMenuResId);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiMenuResId`  
 Especifica a ID de recurso de um menu para carregar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se um menu foi adicionado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Na chamada para `AddMenuCommands`, `bPopup` é `FALSE`. Como resultado, esse método não adiciona itens de menu que contiverem submenus para a lista de comandos. Esse método adiciona os itens de menu em submenus à lista de comandos.  
  
##  <a name="addmenucommands"></a>CMFCToolBarsCustomizeDialog::AddMenuCommands  
 Adiciona itens à lista de comandos de **comandos** página para representar todos os itens no menu especificado.  
  
```  
void AddMenuCommands(
    const CMenu* pMenu,  
    BOOL bPopup,  
    LPCTSTR lpszCategory=NULL,  
    LPCTSTR lpszMenuPath=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenu`  
 Um ponteiro para o objeto CMenu para adicionar.  
  
 [in] `bPopup`  
 Especifica se deseja inserir os itens de menu pop-up para a lista de comandos.  
  
 [in] `lpszCategory`  
 O nome da categoria para inserir no menu.  
  
 [in] `lpszMenuPath`  
 Um prefixo que é adicionado ao nome quando o comando é mostrado no **todas as categorias** lista.  
  
### <a name="remarks"></a>Comentários  
 O `AddMenuCommands` método loops de todos os itens de menu do `pMenu`. Para cada item de menu que não contenha um submenu, esse método cria um [CMFCToolBarButton classe](../../mfc/reference/cmfctoolbarbutton-class.md) objeto e chama o [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) para adicionar o item de menu como um botão da barra de ferramentas para a lista de comandos no **comandos** página. Separadores são ignorados nesse processo.  
  
 Se `bPopup` é `TRUE`, para cada item de menu que contém um submenu esse método cria um [CMFCToolBarMenuButton classe](../../mfc/reference/cmfctoolbarmenubutton-class.md) do objeto e o insere na lista de comandos chamando `AddButton`. Caso contrário, os itens de menu que contiverem submenus não são exibidos na lista de comandos. Em ambos os casos, quando `AddMenuCommands` encontrar um item de menu com um submenu chama a mesma recursivamente, transmitindo um ponteiro para o submenu como o `pMenu` parâmetro e acrescentando o rótulo do submenu para `lpszMenuPath`.  
  
##  <a name="addtoolbar"></a>CMFCToolBarsCustomizeDialog::AddToolBar  
 Carrega uma barra de ferramentas de recursos. Em seguida, para cada comando do menu de chamadas a [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método para inserir um botão na lista de comandos de **comandos** página sob a categoria especificada.  
  
```  
BOOL AddToolBar(
    UINT uiCategoryId,  
    UINT uiToolbarResId);

BOOL AddToolBar(
    LPCTSTR lpszCategory,  
    UINT uiToolbarResId);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCategoryId`  
 Especifica a ID de recurso da categoria para adicionar a barra de ferramentas.  
  
 [in] `uiToolbarResId`  
 Especifica a ID de recurso da barra de ferramentas cujos comandos são inseridos na lista de comandos.  
  
 [in] `lpszCategory`  
 Especifica o nome da categoria à qual adicionar a barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método for bem-sucedido; Caso contrário, `FALSE`.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `AddToolBar` método o `CMFCToolBarsCustomizeDialog` classe. Este trecho de código é parte do [exemplo Word Pad](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad n º&11;](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_3.cpp)]  
  
### <a name="remarks"></a>Comentários  
 O controle que é usado para representar cada comando é uma [CMFCToolBarButton classe](../../mfc/reference/cmfctoolbarbutton-class.md) objeto. Depois de adicionar a barra de ferramentas, você pode substituir o botão com um controle de um tipo derivado chamando [CMFCToolBarsCustomizeDialog::ReplaceButton](#replacebutton).  
  
##  <a name="checktoolsvalidity"></a>CMFCToolBarsCustomizeDialog::CheckToolsValidity  
 Verifica a validade da lista de ferramentas do usuário.  
  
```  
virtual BOOL CheckToolsValidity(const CObList& lstTools);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lstTools`  
 A lista de ferramentas definidas pelo usuário para verificar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se a lista de ferramentas definidas pelo usuário for válido; caso contrário `FALSE`. A implementação padrão sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para verificar a validade dos objetos que representam ferramentas definidas pelo usuário retornadas por [CMFCToolBarsCustomizeDialog::CheckToolsValidity](#checktoolsvalidity).  
  
 Substituir o `CheckToolsValidity` método em uma classe derivada de `CMFCToolBarsCustomizeDialog` se você deseja validar as ferramentas do usuário antes do usuário fecha a caixa de diálogo. Se esse método retornar `FALSE` quando o usuário clica o **fechar** botão no canto superior direito da caixa de diálogo ou no botão **fechar** no canto inferior direito da caixa de diálogo, a caixa de diálogo exibe o **ferramentas** guia, em vez de fechamento. Se esse método retornar `FALSE` quando o usuário clica em uma guia para navegar para fora do **ferramentas** guia Painel de navegação não ocorrerá. Você deve exibir uma caixa de mensagem apropriado para informar ao usuário sobre o problema que causou a falha na validação.  
  
##  <a name="cmfctoolbarscustomizedialog"></a>CMFCToolBarsCustomizeDialog::CMFCToolBarsCustomizeDialog  
 Constrói um objeto `CMFCToolBarsCustomizeDialog`.  
  
```  
CMFCToolBarsCustomizeDialog(
    CFrameWnd* pWndParentFrame,  
    BOOL bAutoSetFromMenus = FALSE,  
    UINT uiFlags = (AFX_CUSTOMIZE_MENU_SHADOWS | AFX_CUSTOMIZE_TEXT_LABELS | AFX_CUSTOMIZE_MENU_ANIMATIONS | AFX_CUSTOMIZE_NOHELP),  
    CList <CRuntimeClass*, CRuntimeClass*>* p listCustomPages = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParentFrame`  
 Um ponteiro para o quadro principal. Esse parâmetro não deve ser `NULL`.  
  
 [in] `bAutoSetFromMenus`  
 Um valor booleano que especifica se deve adicionar os comandos de menu de todos os menus para a lista de comandos no **comandos** página. Se esse parâmetro for `TRUE`, os comandos de menu são adicionados. Caso contrário, os comandos de menu não são adicionados.  
  
 [in] `uiFlags`  
 Uma combinação de sinalizadores que afetam o comportamento da caixa de diálogo. Esse parâmetro pode ser um ou mais dos seguintes valores:  
  
- `AFX_CUSTOMIZE_MENU_SHADOWS`  
  
- `AFX_CUSTOMIZE_TEXT_LABELS`  
  
- `AFX_CUSTOMIZE_MENU_ANIMATIONS`  
  
- `AFX_CUSTOMIZE_NOHELP`  
  
- `AFX_CUSTOMIZE_CONTEXT_HELP`  
  
- `AFX_CUSTOMIZE_NOTOOLS`  
  
- `AFX_CUSTOMIZE_MENUAMPERS`  
  
- `AFX_CUSTOMIZE_NO_LARGE_ICONS`  
  
 [in] `plistCustomPages`  
 Um ponteiro para uma lista de `CRuntimeClass` objetos que especificam páginas personalizadas adicionais.  
  
### <a name="remarks"></a>Comentários  
 O `plistCustomPages` parâmetro refere-se à lista de `CRuntimeClass` objetos que especificam páginas personalizadas adicionais. O construtor adiciona mais páginas à caixa de diálogo usando o [CRuntimeClass::CreateObject](../../mfc/reference/cruntimeclass-structure.md#createobject) método. Consulte o exemplo CustomPages para obter um exemplo que adiciona mais páginas para o **personalizar** caixa de diálogo.  
  
 Para obter mais informações sobre os valores que você pode passar o `uiFlags` parâmetro, consulte [CMFCToolBarsCustomizeDialog::GetFlags](#getflags).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCToolBarsCustomizeDialog` classe. Este trecho de código é parte do [exemplo páginas personalizadas](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_CustomPages n º&3;](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_4.cpp)]  
  
##  <a name="create"></a>CMFCToolBarsCustomizeDialog::Create  
 Exibe o **personalização** caixa de diálogo.  
  
```  
virtual BOOL Create();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a folha de propriedades de personalização é criada com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chamar o `Create` método somente depois que você inicializar a classe completamente.  
  
##  <a name="enableuserdefinedtoolbars"></a>CMFCToolBarsCustomizeDialog::EnableUserDefinedToolbars  
 Habilita ou desabilita criando novas barras de ferramentas usando o **personalizar** caixa de diálogo.  
  
```  
void EnableUserDefinedToolbars(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar as barras de ferramentas definidas pelo usuário; `FALSE` para desabilitar as barras de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Se `bEnable` é `TRUE`, o **novo**, **Renomear** e **excluir** botões são exibidos na **barras de ferramentas** página.  
  
 Por padrão, ou se `bEnable` é `FALSE`, esses botões não são exibidos e o usuário não pode definir novas barras de ferramentas.  
  
##  <a name="fillallcommandslist"></a>CMFCToolBarsCustomizeDialog::FillAllCommandsList  
 Preenche o fornecido `CListBox` objeto com os comandos de **todos os comandos** categoria.  
  
```  
virtual void FillAllCommandsList(CListBox& wndListOfCommands) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `wndListOfCommands`  
 Uma referência para o `CListBox` objeto a ser preenchido.  
  
### <a name="remarks"></a>Comentários  
 O **todos os comandos** categoria contém os comandos de todas as categorias. O [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método adiciona o comando que está associado com o botão fornecido para o **todos os comandos** categoria para você.  
  
 Esse método limpa o conteúdo da fornecidas `CListBox` objeto antes populá-lo com os comandos de **todos os comandos** categoria.  
  
 O `CMFCMousePropertyPage` classe usa esse método para preencher a caixa de listagem de evento de clique duplo.  
  
##  <a name="fillcategoriescombobox"></a>CMFCToolBarsCustomizeDialog::FillCategoriesComboBox  
 Preenche o fornecido `CComboBox` objeto com o nome de cada categoria de comando na **personalizar** caixa de diálogo.  
  
```  
void FillCategoriesComboBox(
    CComboBox& wndCategory,  
    BOOL bAddEmpty = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `wndCategory`  
 Uma referência para o `CComboBox` objeto a ser preenchido.  
  
 [in] `bAddEmpty`  
 Um valor booleano que especifica se deseja adicionar categorias a caixa de combinação que não possuem comandos. Se esse parâmetro for `TRUE`, categorias vazias são adicionadas à caixa de combinação. Caso contrário, as categorias vazias não são adicionadas.  
  
### <a name="remarks"></a>Comentários  
 Esse método é como o [CMFCToolBarsCustomizeDialog::FillCategoriesListBox](#fillcategorieslistbox) método exceto pelo fato desse método funciona com um `CComboBox` objeto.  
  
 Este método não limpa o conteúdo da `CComboBox` objeto antes de preencher a ele. Ele garante que o **todos os comandos** categoria é o item final na caixa de combinação.  
  
 Você pode adicionar novas categorias de comando usando o [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método. Você pode alterar o nome de uma categoria existente usando o [CMFCToolBarsCustomizeDialog::RenameCategory](#renamecategory) método.  
  
 O `CMFCToolBarsKeyboardPropertyPage` e `CMFCKeyMapDialog` classes usam esse método para categorizar os mapeamentos de teclado.  
  
##  <a name="fillcategorieslistbox"></a>CMFCToolBarsCustomizeDialog::FillCategoriesListBox  
 Preenche o fornecido `CListBox` objeto com o nome de cada categoria de comando na **personalizar** caixa de diálogo.  
  
```  
void FillCategoriesListBox(
    CListBox& wndCategory,  
    BOOL bAddEmpty = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `wndCategory`  
 Uma referência para o `CListBox` objeto a ser preenchido.  
  
 [in] `bAddEmpty`  
 Um valor booleano que especifica se deseja adicionar categorias a caixa de listagem que não possuem comandos. Se esse parâmetro for `TRUE`, categorias vazias são adicionadas à caixa de listagem. Caso contrário, as categorias vazias não são adicionadas.  
  
### <a name="remarks"></a>Comentários  
 Esse método é como o [CMFCToolBarsCustomizeDialog::FillCategoriesComboBox](#fillcategoriescombobox) método exceto pelo fato desse método funciona com um `CListBox` objeto.  
  
 Este método não limpa o conteúdo da `CListBox` objeto antes de preencher a ele. Ele garante que o **todos os comandos** categoria é o item final na caixa de listagem.  
  
 Você pode adicionar novas categorias de comando usando o [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método. Você pode alterar o nome de uma categoria existente usando o [CMFCToolBarsCustomizeDialog::RenameCategory](#renamecategory) método.  
  
 O `CMFCToolBarsCommandsPropertyPage` classe usa esse método para mostrar a lista de comandos que está associada a cada categoria de comando.  
  
##  <a name="getcommandname"></a>CMFCToolBarsCustomizeDialog::GetCommandName  
 Recupera o nome que está associado com a ID do comando especificado.  
  
```  
LPCTSTR GetCommandName(UINT uiCmd) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID do comando para recuperar.  
  
### <a name="return-value"></a>Valor de retorno  
 O nome que está associado com a ID de comando especificado, ou `NULL` se o comando não existe.  
  
##  <a name="getcountincategory"></a>CMFCToolBarsCustomizeDialog::GetCountInCategory  
 Recupera o número de itens na lista fornecida com um rótulo de texto especificado.  
  
```  
int GetCountInCategory(
    LPCTSTR lpszItemName,  
    const CObList& lstCommands) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszItemName`  
 O rótulo de texto para corresponder.  
  
 [in] `lstCommands`  
 Uma referência a uma lista que contém `CMFCToolBarButton` objetos.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens fornecidos lista cuja rótulo de texto é igual a `lpszItemName`.  
  
### <a name="remarks"></a>Comentários  
 Cada elemento na lista de objeto fornecido deve ser do tipo `CMFCToolBarButton`. Este método compara `lpszItemName` com o [CMFCToolBarButton::m_strText](../../mfc/reference/cmfctoolbarbutton-class.md#m_strtext) membro de dados.  
  
##  <a name="getflags"></a>CMFCToolBarsCustomizeDialog::GetFlags  
 Recupera o conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.  
  
```  
UINT GetFlags() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Esse método recupera o valor da `uiFlags` parâmetro que é passado para o construtor. O valor de retorno pode ser um ou mais dos seguintes valores:  
  
 `AFX_CUSTOMIZE_MENU_SHADOWS`  
 Permite que o usuário especifique a aparência de sombra do menu.  
  
 `AFX_CUSTOMIZE_TEXT_LABELS`  
 Permite ao usuário especificar se os rótulos de texto são mostrados abaixo as imagens do botão da barra de ferramentas.  
  
 `AFX_CUSTOMIZE_MENU_ANIMATIONS`  
 Permite que o usuário especifique o estilo de animação de menu.  
  
 `AFX_CUSTOMIZE_NOHELP`  
 Remove o botão Ajuda na caixa de diálogo de personalização.  
  
 `AFX_CUSTOMIZE_CONTEXT_HELP`  
 Permite que o `WS_EX_CONTEXTHELP` estilo visual.  
  
 `AFX_CUSTOMIZE_NOTOOLS`  
 Remove o **ferramentas** página da caixa de diálogo de personalização. Esse sinalizador é válido se seu aplicativo usa o `CUserToolsManager` classe.  
  
 `AFX_CUSTOMIZE_MENUAMPERS`  
 Permite que as legendas do botão conter o e comercial ( ** & **) caracteres.  
  
 `AFX_CUSTOMIZE_NO_LARGE_ICONS`  
 Remove o **ícones grandes** opção na caixa de diálogo de personalização.  
  
 Para obter mais informações sobre o `WS_EX_CONTEXTHELP` estilo visual, consulte [estilos de janela estendidos](../../mfc/reference/extended-window-styles.md).  
  
##  <a name="onafterchangetool"></a>CMFCToolBarsCustomizeDialog::OnAfterChangeTool  
 Responde a uma alteração em uma ferramenta de usuário imediatamente depois que ele ocorre.  
  
```  
virtual void OnAfterChangeTool(CUserTool* pSelTool);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `pSelTool`  
 Um ponteiro para o objeto de ferramenta do usuário foi alterado.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela estrutura quando um usuário altera as propriedades de uma ferramenta definida pelo usuário. A implementação padrão não faz nada. Substitua esse método em uma classe derivada de `CMFCToolBarsCustomizeDialog` para executar o processamento depois que ocorrer uma alteração em uma ferramenta de usuário.  
  
##  <a name="onassignkey"></a>CMFCToolBarsCustomizeDialog::OnAssignKey  
 Valida os atalhos de teclado, como um usuário define.  
  
```  
virtual BOOL OnAssignKey(ACCEL* pAccel);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `pAccel`  
 Ponteiro para a atribuição de teclado proposta é expresso como uma [ACELERAÇÃO](http://msdn.microsoft.com/library/windows/desktop/ms646340) struct.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a chave pode ser atribuída, ou `FALSE` se a chave não pode ser atribuída. A implementação padrão sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para realizar processamento extra quando um usuário atribui um novo atalho de teclado, ou validar os atalhos de teclado do usuário define. Para impedir que um atalho que está sendo atribuído, retorne `FALSE`. Você deve também exibir uma caixa de mensagem ou caso contrário, informar ao usuário sobre o motivo pelo qual o atalho de teclado foi rejeitado.  
  
##  <a name="onbeforechangetool"></a>CMFCToolBarsCustomizeDialog::OnBeforeChangeTool  
 Executa personalizado processamento quando uma alteração em uma ferramenta de usuário quando o usuário está prestes a aplicar uma alteração.  
  
```  
virtual void OnBeforeChangeTool(CUserTool* pSelTool);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `pSelTool`  
 Um ponteiro para o objeto de ferramenta do usuário que está prestes a ser substituído.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pela estrutura quando as propriedades de uma ferramenta definida pelo usuário está prestes a alterar. A implementação padrão não faz nada. Substituir o `OnBeforeChangeTool` método em uma classe derivada de `CMFCToolBarsCustomizeDialog` se você deseja executar antes que ocorra uma alteração em uma ferramenta de usuário, como liberar recursos de processamento que `pSelTool` usa.  
  
##  <a name="onedittoolbarmenuimage"></a>CMFCToolBarsCustomizeDialog::OnEditToolbarMenuImage  
 Inicia um editor de imagens para que um usuário pode personalizar um ícone de item de menu ou botão da barra de ferramentas.  
  
```  
virtual BOOL OnEditToolbarMenuImage(
    CWnd* pWndParent,  
    CBitmap& bitmap,  
    int nBitsPerPixel);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Um ponteiro para a janela pai.  
  
 [in] `bitmap`  
 Uma referência a um objeto de bitmap a ser editada.  
  
 [in] `nBitsPerPixel`  
 Bitmap resolução de cor, em bits por pixel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se uma alteração está sendo confirmada; Caso contrário, `FALSE`. A implementação padrão exibe uma caixa de diálogo e retorna `TRUE` se o usuário clicar **Okey**, ou `FALSE` se o usuário clicar **Cancelar** ou **fechar** botão.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pela estrutura quando o usuário executa o editor de imagem. Exibição de implementação do padrão [CMFCImageEditorDialog classe](../../mfc/reference/cmfcimageeditordialog-class.md) caixa de diálogo. Substituir `OnEditToolbarMenuImage` em uma classe derivada usando um editor de imagem personalizada.  
  
##  <a name="oninitdialog"></a>CMFCToolBarsCustomizeDialog::OnInitDialog  
 Substituições para aumentar a inicialização da folha de propriedade.  
  
```  
virtual BOOL OnInitDialog();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado da chamada de [CPropertySheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog) método.  
  
### <a name="remarks"></a>Comentários  
 Esse método estende a implementação da classe base, [CPropertySheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog), exibindo o **fechar** botão, certificando-se de que a caixa de diálogo se ajusta o tamanho atual da tela e movendo o **ajuda** botão no canto inferior esquerdo da caixa de diálogo.  
  
##  <a name="oninittoolspage"></a>CMFCToolBarsCustomizeDialog::OnInitToolsPage  
 Lida com a notificação do framework que o **ferramentas** página está prestes a ser inicializado.  
  
```  
virtual void OnInitToolsPage();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada. Substitua esse método em uma classe derivada para processar essa notificação.  
  
##  <a name="postncdestroy"></a>CMFCToolBarsCustomizeDialog::PostNcDestroy  
 Chamado pela estrutura depois que a janela foi destruída.  
  
```  
virtual void PostNcDestroy();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método estende a implementação da classe base, `CPropertySheet::PostNcDestroy`, restaurando o aplicativo para o modo anterior.  
  
 O [CMFCToolBarsCustomizeDialog::Create](#create) método coloca o aplicativo em um modo especial que limita a tarefas de personalização do usuário.  
  
##  <a name="removebutton"></a>CMFCToolBarsCustomizeDialog::RemoveButton  
 Remove o botão com a ID de comando especificado de categoria especificada ou de todas as categorias.  
  
```  
int RemoveButton(
    UINT uiCategoryId,  
    UINT uiCmdId);

int RemoveButton(
    LPCTSTR lpszCategory,  
    UINT uiCmdId);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCategoryId`  
 Especifica a ID da categoria da qual o botão Remover.  
  
 [in] `uiCmdId`  
 Especifica a ID de comando do botão.  
  
 [in] `lpszCategory`  
 Especifica o nome da categoria da qual o botão Remover.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do botão removido ou -1 se a ID do comando especificado não foi encontrada na categoria especificada. Se `uiCategoryId` é -1, o valor de retorno é 0.  
  
### <a name="remarks"></a>Comentários  
 Para remover um botão de todas as categorias, chame a primeira sobrecarga desse método e o conjunto `uiCategoryId` como -1.  
  
##  <a name="renamecategory"></a>CMFCToolBarsCustomizeDialog::RenameCategory  
 Renomeia uma categoria na caixa de listagem das categorias no **comandos** página.  
  
```  
BOOL RenameCategory(
    LPCTSTR lpszCategoryOld,  
    LPCTSTR lpszCategoryNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszCategoryOld`  
 O nome da categoria para alterar.  
  
 [in] `lpszCategoryNew`  
 O novo nome de categoria.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método teve êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O nome da categoria deve ser exclusivo.  
  
##  <a name="replacebutton"></a>CMFCToolBarsCustomizeDialog::ReplaceButton  
 Substitui um botão da barra de ferramentas na caixa de lista de comandos do **comandos** página.  
  
```  
void ReplaceButton(
    UINT uiCmd,  
    const CMFCToolBarButton& button);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 Especifica o comando do botão a ser substituído.  
  
 [in] `button`  
 Um `const` referência ao objeto de botão da barra de ferramentas que substitui o antigo botão.  
  
### <a name="remarks"></a>Comentários  
 Quando [CMFCToolBarsCustomizeDialog::AddMenu](#addmenu), [CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands), ou [CMFCToolBarsCustomizeDialog::AddToolBar](#addtoolbar) adiciona um comando para o **comandos** página, que o comando está na forma de um [CMFCToolBarButton classe](../../mfc/reference/cmfctoolbarbutton-class.md) objeto (ou um [CMFCToolBarMenuButton classe](../../mfc/reference/cmfctoolbarmenubutton-class.md) objeto para um item de menu que contém um submenu adicionado por `AddMenuCommands`). A estrutura também chama esses três métodos para adicionar comandos automaticamente. Se desejar que um comando para ser representado por um tipo derivado, chamar `ReplaceButton` e passar em um botão do tipo derivado.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `ReplaceButton` método o `CMFCToolBarsCustomizeDialog` classe. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&#34;](../../mfc/codesnippet/cpp/cmfctoolbarscustomizedialog-class_5.cpp)]  
  
##  <a name="setusercategory"></a>CMFCToolBarsCustomizeDialog::SetUserCategory  
 Especifica qual categoria na lista de categorias no **comandos** página é a categoria de usuário. Você deve chamar essa função antes de chamar [CMFCToolBarsCustomizeDialog::Create](#create).  
  
```  
BOOL SetUserCategory(LPCTSTR lpszCategory);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszCategory`  
 O nome da categoria.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método for bem-sucedido; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A configuração de categoria de usuário não é usada atualmente pela estrutura.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CPropertySheet](../../mfc/reference/cpropertysheet-class.md)

