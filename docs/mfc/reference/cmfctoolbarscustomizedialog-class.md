---
title: Classe CMFCToolBarsCustomizeDialog
ms.date: 11/04/2016
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
helpviewer_keywords:
- CMFCToolBarsCustomizeDialog [MFC], CMFCToolBarsCustomizeDialog
- CMFCToolBarsCustomizeDialog [MFC], FillAllCommandsList
- CMFCToolBarsCustomizeDialog [MFC], FillCategoriesComboBox
- CMFCToolBarsCustomizeDialog [MFC], FillCategoriesListBox
- CMFCToolBarsCustomizeDialog [MFC], GetCommandName
- CMFCToolBarsCustomizeDialog [MFC], GetCountInCategory
- CMFCToolBarsCustomizeDialog [MFC], GetFlags
- CMFCToolBarsCustomizeDialog [MFC], OnInitDialog
- CMFCToolBarsCustomizeDialog [MFC], PostNcDestroy
ms.assetid: 78e2cddd-4f13-4097-afc3-1ad646a113f1
ms.openlocfilehash: a61cefa7f844062fcca42711ce6515180066b919
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839095"
---
# <a name="cmfctoolbarscustomizedialog-class"></a>Classe CMFCToolBarsCustomizeDialog

Uma caixa de diálogo de guia sem janela restrita ( [classe CPropertySheet](../../mfc/reference/cpropertysheet-class.md)) que permite que o usuário personalize as barras de ferramentas, os menus, os atalhos de teclado, as ferramentas definidas pelo usuário e o estilo visual em um aplicativo. Normalmente, o usuário acessa essa caixa de diálogo selecionando **Personalizar** no menu **ferramentas** .

A caixa de diálogo **Personalizar** tem seis guias: **comandos**, **barras de ferramentas**, **ferramentas**, **teclado**, **menu**e **Opções**.

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
|[CMFCToolBarsCustomizeDialog:: AddButton](#addbutton)|Insere um botão da barra de ferramentas na lista de comandos da página **comandos**|
|[CMFCToolBarsCustomizeDialog:: AddMenu](#addmenu)|Carrega um menu dos recursos e chama [CMFCToolBarsCustomizeDialog:: AddMenuCommands](#addmenucommands) para adicionar esse menu à lista de comandos na página **comandos** .|
|[CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands)|Carrega um menu dos recursos e chama [CMFCToolBarsCustomizeDialog:: AddMenuCommands](#addmenucommands) para adicionar esse menu à lista de comandos na página **comandos** .|
|[CMFCToolBarsCustomizeDialog:: AddToolBar](#addtoolbar)|Carrega uma barra de ferramentas dos recursos. Em seguida, para cada comando no menu, chama o método [CMFCToolBarsCustomizeDialog:: AddButton](#addbutton) para inserir um botão na lista de comandos na página **comandos** na categoria especificada.|
|[CMFCToolBarsCustomizeDialog:: criar](#create)|Exibe a caixa de diálogo **personalização** .|
|`CMFCToolBarsCustomizeDialog::EnableTools`|Reservado para uso futuro.|
|[CMFCToolBarsCustomizeDialog::EnableUserDefinedToolbars](#enableuserdefinedtoolbars)|Habilita ou desabilita a criação de novas barras de ferramentas usando a caixa de diálogo **Personalizar** .|
|[CMFCToolBarsCustomizeDialog::FillAllCommandsList](#fillallcommandslist)|Popula o objeto fornecido `CListBox` com os comandos na categoria **todos os comandos** .|
|[CMFCToolBarsCustomizeDialog::FillCategoriesComboBox](#fillcategoriescombobox)|Popula o objeto fornecido `CComboBox` com o nome de cada categoria de comando na caixa de diálogo **Personalizar** .|
|[CMFCToolBarsCustomizeDialog::FillCategoriesListBox](#fillcategorieslistbox)|Popula o objeto fornecido `CListBox` com o nome de cada categoria de comando na caixa de diálogo **Personalizar** .|
|[CMFCToolBarsCustomizeDialog:: getcommandname](#getcommandname)|Recupera o nome associado à ID de comando fornecida.|
|[CMFCToolBarsCustomizeDialog::GetCountInCategory](#getcountincategory)|Recupera o número de itens na lista fornecida que têm um determinado rótulo de texto.|
|[CMFCToolBarsCustomizeDialog:: GetFlags](#getflags)|Recupera o conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.|
|`CMFCToolBarsCustomizeDialog::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCToolBarsCustomizeDialog::OnEditToolbarMenuImage](#onedittoolbarmenuimage)|Inicia um editor de imagem para que um usuário possa personalizar um botão da barra de ferramentas ou um ícone de item de menu.|
|[CMFCToolBarsCustomizeDialog:: OnInitDialog](#oninitdialog)|Substitui para aumentar a inicialização da folha de propriedades. (Substitui [CPropertySheet:: OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog).)|
|[CMFCToolBarsCustomizeDialog::P ostNcDestroy](#postncdestroy)|Chamado pelo Framework após a destruição da janela. (Substitui `CPropertySheet::PostNcDestroy`.)|
|[CMFCToolBarsCustomizeDialog::RemoveButton](#removebutton)|Remove o botão com a ID de comando especificada da categoria especificada ou de todas as categorias.|
|[CMFCToolBarsCustomizeDialog::RenameCategory](#renamecategory)|Renomeia uma categoria na caixa de listagem de categorias na guia **comandos** .|
|[CMFCToolBarsCustomizeDialog::ReplaceButton](#replacebutton)|Substitui um botão na lista de comandos da guia **comandos** por um novo objeto de botão da barra de ferramentas.|
|[CMFCToolBarsCustomizeDialog::SetUserCategory](#setusercategory)|Adiciona uma categoria à lista de categorias que será exibida na guia **comandos** .|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarsCustomizeDialog::CheckToolsValidity](#checktoolsvalidity)|Chamado pelo Framework para determinar se a lista de ferramentas definidas pelo usuário é válida.|
|[CMFCToolBarsCustomizeDialog::OnAfterChangeTool](#onafterchangetool)|Chamado pelo Framework quando as propriedades de uma ferramenta definida pelo usuário são alteradas.|
|[CMFCToolBarsCustomizeDialog::OnAssignKey](#onassignkey)|Determina se um atalho de teclado especificado pode ser atribuído a uma ação.|
|[CMFCToolBarsCustomizeDialog::OnBeforeChangeTool](#onbeforechangetool)|Determina se uma ferramenta definida pelo usuário pode ser alterada.|
|[CMFCToolBarsCustomizeDialog::OnInitToolsPage](#oninittoolspage)|Chamado pelo Framework quando o usuário escolhe a guia **ferramentas** é solicitada.|

## <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo **Personalizar** , crie um `CMFCToolBarsCustomizeDialog` objeto e chame o método [CMFCToolBarsCustomizeDialog:: Create](#create) .

Enquanto a caixa de diálogo **Personalizar** está ativa, o aplicativo funciona em um modo especial que limita o usuário às tarefas de personalização.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos na `CMFCToolBarsCustomizeDialog` classe. O exemplo mostra como substituir um botão da barra de ferramentas na caixa de listagem de comandos na página **comandos** , habilitar a criação de novas barras de ferramentas usando a caixa de diálogo **Personalizar** e exibir a caixa de diálogo **personalização** . Este trecho de código faz parte do [exemplo de demonstração do IE](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_IEDemo#4](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CPropertySheet](../../mfc/reference/cpropertysheet-class.md)

`CMFCToolBarsCustomizeDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxToolBarsCustomizeDialog. h

## <a name="cmfctoolbarscustomizedialogaddbutton"></a><a name="addbutton"></a> CMFCToolBarsCustomizeDialog:: AddButton

Insere um botão da barra de ferramentas na lista de comandos na página **comandos** .

```cpp
void AddButton(
    UINT uiCategoryId,
    const CMFCToolBarButton& button,
    int iInsertBefore=-1);

void AddButton(
    LPCTSTR lpszCategory,
    const CMFCToolBarButton& button,
    int iInsertBefore=-1);
```

### <a name="parameters"></a>parâmetros

*uiCategoryId*<br/>
no Especifica a ID da categoria na qual inserir o botão.

*Button*<br/>
no Especifica o botão a ser inserido.

*iInsertBefore*<br/>
no Especifica o índice de base zero de um botão da barra de ferramentas antes do qual o botão é inserido.

*lpszCategory*<br/>
no Especifica a cadeia de caracteres da categoria para inserir o botão.

### <a name="remarks"></a>Comentários

O `AddButton` método ignora os botões que têm as IDs de comando padrão (como ID_FILE_MRU_FILE1), comandos que não são permitidos (consulte [CMFCToolBar:: IsCommandPermitted](../../mfc/reference/cmfctoolbar-class.md#iscommandpermitted)) e botões fictícios.

Esse método cria um novo objeto do mesmo tipo que `button` (geralmente uma [classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)) usando a classe Runtime do botão. Em seguida, ele chama [CMFCToolBarButton:: CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom) para copiar os membros de dados de Button e insere a cópia na categoria especificada.

Quando o novo botão é inserido, ele recebe a `OnAddToCustomizePage` notificação.

Se `iInsertBefore` for-1, o botão será acrescentado à lista de categorias; caso contrário, será inserido antes do item com o índice especificado.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `AddButton` método da `CMFCToolBarsCustomizeDialog` classe. Este trecho de código faz parte do [exemplo de Slider](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Slider#1](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_2.cpp)]

## <a name="cmfctoolbarscustomizedialogaddmenu"></a><a name="addmenu"></a> CMFCToolBarsCustomizeDialog:: AddMenu

Carrega um menu dos recursos e chama [CMFCToolBarsCustomizeDialog:: AddMenuCommands](#addmenucommands) para adicionar esse menu à lista de comandos na página **comandos** .

```
BOOL AddMenu(UINT uiMenuResId);
```

### <a name="parameters"></a>parâmetros

*uiMenuResId*<br/>
no Especifica a ID de recurso de um menu a ser carregado.

### <a name="return-value"></a>Valor Retornado

TRUE se um menu tiver sido adicionado com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Na chamada para `AddMenuCommands` , *BPOPUP* é false. Como resultado, esse método não adiciona itens de menu que contêm submenus à lista de comandos. Esse método adiciona os itens de menu nos submenus à lista de comandos.

## <a name="cmfctoolbarscustomizedialogaddmenucommands"></a><a name="addmenucommands"></a> CMFCToolBarsCustomizeDialog::AddMenuCommands

Adiciona itens à lista de comandos na página **comandos** para representar todos os itens no menu especificado.

```cpp
void AddMenuCommands(
    const CMenu* pMenu,
    BOOL bPopup,
    LPCTSTR lpszCategory=NULL,
    LPCTSTR lpszMenuPath=NULL);
```

### <a name="parameters"></a>parâmetros

*pMenu*<br/>
no Um ponteiro para o objeto CMenu a ser adicionado.

*bPopup*<br/>
no Especifica se os itens do menu pop-up devem ser inseridos na lista de comandos.

*lpszCategory*<br/>
no O nome da categoria para inserir o menu.

*lpszMenuPath*<br/>
no Um prefixo que é adicionado ao nome quando o comando é mostrado na lista **todas as categorias** .

### <a name="remarks"></a>Comentários

O `AddMenuCommands` método percorre todos os itens de menu de *pMenu*. Para cada item de menu que não contém um submenu, esse método cria um objeto de [classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) e chama o método [CMFCToolBarsCustomizeDialog:: AddButton](#addbutton) para adicionar o item de menu como um botão da barra de ferramentas à lista de comandos na página **comandos** . Os separadores são ignorados nesse processo.

Se *bPopup* for true, para cada item de menu que contém um submenu, esse método criará um objeto de [Classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md) e o inserirá na lista de comandos chamando `AddButton` . Caso contrário, os itens de menu que contêm submenus não são exibidos na lista de comandos. Em ambos os casos, quando o `AddMenuCommands` encontra um item de menu com um submenu, ele chama-se recursivamente, passando um ponteiro para o submenu como o parâmetro *pMenu* e acrescentando o rótulo do submenu a *lpszMenuPath*.

## <a name="cmfctoolbarscustomizedialogaddtoolbar"></a><a name="addtoolbar"></a> CMFCToolBarsCustomizeDialog:: AddToolBar

Carrega uma barra de ferramentas dos recursos. Em seguida, para cada comando no menu, chama o método [CMFCToolBarsCustomizeDialog:: AddButton](#addbutton) para inserir um botão na lista de comandos na página **comandos** na categoria especificada.

```
BOOL AddToolBar(
    UINT uiCategoryId,
    UINT uiToolbarResId);

BOOL AddToolBar(
    LPCTSTR lpszCategory,
    UINT uiToolbarResId);
```

### <a name="parameters"></a>parâmetros

*uiCategoryId*<br/>
no Especifica a ID de recurso da categoria à qual adicionar a barra de ferramentas.

*uiToolbarResId*<br/>
no Especifica a ID de recurso de uma barra de ferramentas cujos comandos são inseridos na lista de comandos.

*lpszCategory*<br/>
no Especifica o nome da categoria à qual adicionar a barra de ferramentas.

### <a name="return-value"></a>Valor Retornado

TRUE se o método for bem-sucedido; caso contrário, FALSE.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `AddToolBar` método na `CMFCToolBarsCustomizeDialog` classe. Este trecho de código faz parte do [exemplo do Word pad](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_WordPad#11](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_3.cpp)]

### <a name="remarks"></a>Comentários

O controle usado para representar cada comando é um objeto de [classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) . Depois de adicionar a barra de ferramentas, você pode substituir o botão por um controle de um tipo derivado chamando [CMFCToolBarsCustomizeDialog:: ReplaceButton](#replacebutton).

## <a name="cmfctoolbarscustomizedialogchecktoolsvalidity"></a><a name="checktoolsvalidity"></a> CMFCToolBarsCustomizeDialog::CheckToolsValidity

Verifica a validade da lista de ferramentas de usuário.

```
virtual BOOL CheckToolsValidity(const CObList& lstTools);
```

### <a name="parameters"></a>parâmetros

*lstTools*<br/>
no A lista de ferramentas definidas pelo usuário a serem verificadas.

### <a name="return-value"></a>Valor Retornado

Retornará TRUE se a lista de ferramentas definidas pelo usuário for válida; caso contrário, FALSE. A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

A estrutura chama esse método para verificar a validade dos objetos que representam as ferramentas definidas pelo usuário retornadas por [CMFCToolBarsCustomizeDialog:: CheckToolsValidity](#checktoolsvalidity).

Substitua o `CheckToolsValidity` método em uma classe derivada de `CMFCToolBarsCustomizeDialog`  se você quiser validar as ferramentas de usuário antes que o usuário feche a caixa de diálogo. Se esse método retornar FALSE quando o usuário clicar no botão **fechar** no canto superior direito da caixa de diálogo ou o botão rotulado **fechar** no canto inferior direito da caixa de diálogo, a caixa de diálogo exibirá a guia **ferramentas** em vez de fechar. Se esse método retornar FALSE quando o usuário clicar em uma guia para sair da guia **ferramentas** , a navegação não ocorrerá. Você deve exibir uma caixa de mensagem apropriada para informar ao usuário sobre o problema que causou a falha na validação.

## <a name="cmfctoolbarscustomizedialogcmfctoolbarscustomizedialog"></a><a name="cmfctoolbarscustomizedialog"></a> CMFCToolBarsCustomizeDialog::CMFCToolBarsCustomizeDialog

Constrói um objeto `CMFCToolBarsCustomizeDialog`.

```
CMFCToolBarsCustomizeDialog(
    CFrameWnd* pWndParentFrame,
    BOOL bAutoSetFromMenus = FALSE,
    UINT uiFlags = (AFX_CUSTOMIZE_MENU_SHADOWS | AFX_CUSTOMIZE_TEXT_LABELS | AFX_CUSTOMIZE_MENU_ANIMATIONS | AFX_CUSTOMIZE_NOHELP),
    CList <CRuntimeClass*, CRuntimeClass*>* p listCustomPages = NULL);
```

### <a name="parameters"></a>parâmetros

*pWndParentFrame*<br/>
no Um ponteiro para o quadro pai. Esse parâmetro não deve ser nulo.

*bAutoSetFromMenus*<br/>
no Um valor booliano que especifica se os comandos de menu devem ser adicionados de todos os menus à lista de comandos na página **comandos** . Se esse parâmetro for TRUE, os comandos de menu serão adicionados. Caso contrário, os comandos de menu não serão adicionados.

*uiFlags*<br/>
no Uma combinação de sinalizadores que afetam o comportamento da caixa de diálogo. Esse parâmetro pode ser um ou mais dos seguintes valores:

- AFX_CUSTOMIZE_MENU_SHADOWS

- AFX_CUSTOMIZE_TEXT_LABELS

- AFX_CUSTOMIZE_MENU_ANIMATIONS

- AFX_CUSTOMIZE_NOHELP

- AFX_CUSTOMIZE_CONTEXT_HELP

- AFX_CUSTOMIZE_NOTOOLS

- AFX_CUSTOMIZE_MENUAMPERS

- AFX_CUSTOMIZE_NO_LARGE_ICONS

*plistCustomPages*<br/>
no Um ponteiro para uma lista de `CRuntimeClass` objetos que especificam páginas personalizadas adicionais.

### <a name="remarks"></a>Comentários

O parâmetro *plistCustomPages* refere-se à lista de `CRuntimeClass` objetos que especificam páginas personalizadas adicionais. O construtor adiciona mais páginas à caixa de diálogo usando o método [CRuntimeClass:: CreateObject](../../mfc/reference/cruntimeclass-structure.md#createobject) . Consulte o exemplo de CustomPages para obter um exemplo que adiciona mais páginas à caixa de diálogo **Personalizar** .

Para obter mais informações sobre os valores que você pode passar no parâmetro *uiFlags* , consulte [CMFCToolBarsCustomizeDialog:: GetFlags](#getflags).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto da `CMFCToolBarsCustomizeDialog` classe. Este trecho de código faz parte do [exemplo de páginas personalizadas](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_CustomPages#3](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_4.cpp)]

## <a name="cmfctoolbarscustomizedialogcreate"></a><a name="create"></a> CMFCToolBarsCustomizeDialog:: criar

Exibe a caixa de diálogo **personalização** .

```
virtual BOOL Create();
```

### <a name="return-value"></a>Valor Retornado

TRUE se a folha de propriedades de personalização for criada com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame o `Create` método somente depois de inicializar totalmente a classe.

## <a name="cmfctoolbarscustomizedialogenableuserdefinedtoolbars"></a><a name="enableuserdefinedtoolbars"></a> CMFCToolBarsCustomizeDialog::EnableUserDefinedToolbars

Habilita ou desabilita a criação de novas barras de ferramentas usando a caixa de diálogo **Personalizar** .

```cpp
void EnableUserDefinedToolbars(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>parâmetros

*bEnable*<br/>
no TRUE para habilitar as barras de ferramentas definidas pelo usuário; FALSE para desabilitar as barras de ferramentas.

### <a name="remarks"></a>Comentários

Se *bEnable* for true, os botões **novo**, **renomear** e **excluir** serão exibidos na página **barras de ferramentas** .

Por padrão, ou se *bEnable* for false, esses botões não serão exibidos e o usuário não poderá definir novas barras de ferramentas.

## <a name="cmfctoolbarscustomizedialogfillallcommandslist"></a><a name="fillallcommandslist"></a> CMFCToolBarsCustomizeDialog::FillAllCommandsList

Popula o objeto fornecido `CListBox` com os comandos na categoria **todos os comandos** .

```
virtual void FillAllCommandsList(CListBox& wndListOfCommands) const;
```

### <a name="parameters"></a>parâmetros

*wndListOfCommands*<br/>
fora Uma referência ao `CListBox` objeto a ser populado.

### <a name="remarks"></a>Comentários

A categoria **todos os comandos** contém os comandos de todas as categorias. O método [CMFCToolBarsCustomizeDialog:: AddButton](#addbutton) adiciona o comando associado ao botão fornecido à categoria **todos os comandos** para você.

Esse método limpa o conteúdo do `CListBox` objeto fornecido antes de preenchê-lo com os comandos na categoria **todos os comandos** .

A `CMFCMousePropertyPage` classe usa esse método para preencher a caixa de listagem de eventos de clique duplo.

## <a name="cmfctoolbarscustomizedialogfillcategoriescombobox"></a><a name="fillcategoriescombobox"></a> CMFCToolBarsCustomizeDialog::FillCategoriesComboBox

Popula o objeto fornecido `CComboBox` com o nome de cada categoria de comando na caixa de diálogo **Personalizar** .

```cpp
void FillCategoriesComboBox(
    CComboBox& wndCategory,
    BOOL bAddEmpty = TRUE) const;
```

### <a name="parameters"></a>parâmetros

*wndCategory*<br/>
fora Uma referência ao `CComboBox` objeto a ser populado.

*bAddEmpty*<br/>
no Um valor booliano que especifica se as categorias devem ser adicionadas à caixa de combinação que não tem comandos. Se esse parâmetro for TRUE, as categorias vazias serão adicionadas à caixa de combinação. Caso contrário, as categorias vazias não serão adicionadas.

### <a name="remarks"></a>Comentários

Esse método é como o método [CMFCToolBarsCustomizeDialog:: FillCategoriesListBox](#fillcategorieslistbox) , exceto que esse método funciona com um `CComboBox` objeto.

Esse método não limpa o conteúdo do `CComboBox` objeto antes de preenchê-lo. Ele garante que a categoria **todos os comandos** seja o item final na caixa de combinação.

Você pode adicionar novas categorias de comando usando o método [CMFCToolBarsCustomizeDialog:: AddButton](#addbutton) . Você pode alterar o nome de uma categoria existente usando o método [CMFCToolBarsCustomizeDialog:: RenameCategory](#renamecategory) .

As `CMFCToolBarsKeyboardPropertyPage` `CMFCKeyMapDialog` classes e usam esse método para categorizar os mapeamentos de teclado.

## <a name="cmfctoolbarscustomizedialogfillcategorieslistbox"></a><a name="fillcategorieslistbox"></a> CMFCToolBarsCustomizeDialog::FillCategoriesListBox

Popula o objeto fornecido `CListBox` com o nome de cada categoria de comando na caixa de diálogo **Personalizar** .

```cpp
void FillCategoriesListBox(
    CListBox& wndCategory,
    BOOL bAddEmpty = TRUE) const;
```

### <a name="parameters"></a>parâmetros

*wndCategory*<br/>
fora Uma referência ao `CListBox` objeto a ser populado.

*bAddEmpty*<br/>
no Um valor booliano que especifica se as categorias devem ser adicionadas à caixa de listagem que não tem comandos. Se esse parâmetro for TRUE, as categorias vazias serão adicionadas à caixa de listagem. Caso contrário, as categorias vazias não serão adicionadas.

### <a name="remarks"></a>Comentários

Esse método é como o método [CMFCToolBarsCustomizeDialog:: FillCategoriesComboBox](#fillcategoriescombobox) , exceto que esse método funciona com um `CListBox` objeto.

Esse método não limpa o conteúdo do `CListBox` objeto antes de preenchê-lo. Ele garante que a categoria **todos os comandos** seja o item final na caixa de listagem.

Você pode adicionar novas categorias de comando usando o método [CMFCToolBarsCustomizeDialog:: AddButton](#addbutton) . Você pode alterar o nome de uma categoria existente usando o método [CMFCToolBarsCustomizeDialog:: RenameCategory](#renamecategory) .

A `CMFCToolBarsCommandsPropertyPage` classe usa esse método para mostrar a lista de comandos que está associada a cada categoria de comando.

## <a name="cmfctoolbarscustomizedialoggetcommandname"></a><a name="getcommandname"></a> CMFCToolBarsCustomizeDialog:: getcommandname

Recupera o nome associado à ID de comando fornecida.

```
LPCTSTR GetCommandName(UINT uiCmd) const;
```

### <a name="parameters"></a>parâmetros

*uiCmd*<br/>
no A ID do comando a ser recuperado.

### <a name="return-value"></a>Valor Retornado

O nome que está associado à ID de comando fornecida, ou NULL, se o comando não existir.

## <a name="cmfctoolbarscustomizedialoggetcountincategory"></a><a name="getcountincategory"></a> CMFCToolBarsCustomizeDialog::GetCountInCategory

Recupera o número de itens na lista fornecida que têm um determinado rótulo de texto.

```
int GetCountInCategory(
    LPCTSTR lpszItemName,
    const CObList& lstCommands) const;
```

### <a name="parameters"></a>parâmetros

*lpszItemName*<br/>
no O rótulo de texto a ser correspondido.

*lstCommands*<br/>
no Uma referência a uma lista que contém `CMFCToolBarButton` objetos.

### <a name="return-value"></a>Valor Retornado

O número de itens na lista fornecida cujo rótulo de texto é igual a *lpszItemName*.

### <a name="remarks"></a>Comentários

Cada elemento na lista de objetos fornecida deve ser do tipo `CMFCToolBarButton` . Esse método compara *lpszItemName* com o membro de dados [CMFCToolBarButton:: m_strText](../../mfc/reference/cmfctoolbarbutton-class.md#m_strtext) .

## <a name="cmfctoolbarscustomizedialoggetflags"></a><a name="getflags"></a> CMFCToolBarsCustomizeDialog:: GetFlags

Recupera o conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.

```
UINT GetFlags() const;
```

### <a name="return-value"></a>Valor Retornado

O conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.

### <a name="remarks"></a>Comentários

Esse método recupera o valor do parâmetro *uiFlags* que é passado para o construtor. O valor de retorno pode ser um ou mais dos seguintes valores:

|Nome|Descrição|
|-|-|
|AFX_CUSTOMIZE_MENU_SHADOWS|Permite que o usuário especifique a aparência da sombra do menu.  |
|AFX_CUSTOMIZE_TEXT_LABELS|Permite que o usuário especifique se os rótulos de texto são mostrados abaixo das imagens de botão da barra de ferramentas.  |
|AFX_CUSTOMIZE_MENU_ANIMATIONS|Permite que o usuário especifique o estilo de animação do menu.  |
|AFX_CUSTOMIZE_NOHELP|Remove o botão ajuda da caixa de diálogo personalização.  |
|AFX_CUSTOMIZE_CONTEXT_HELP|Habilita o WS_EX_CONTEXTHELP estilo visual.  |
|AFX_CUSTOMIZE_NOTOOLS|Remove a página **ferramentas** da caixa de diálogo personalização. Esse sinalizador será válido se o aplicativo usar a `CUserToolsManager` classe.  |
|AFX_CUSTOMIZE_MENUAMPERS|Permite que as legendas do botão contenham o caractere de e comercial ( **&** ).  |
|AFX_CUSTOMIZE_NO_LARGE_ICONS|Remove a opção **ícones grandes** da caixa de diálogo personalização.  |

Para obter mais informações sobre o estilo visual WS_EX_CONTEXTHELP, consulte [estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles).

## <a name="cmfctoolbarscustomizedialogonafterchangetool"></a><a name="onafterchangetool"></a> CMFCToolBarsCustomizeDialog::OnAfterChangeTool

Responde a uma alteração em uma ferramenta de usuário imediatamente após a ocorrência.

```
virtual void OnAfterChangeTool(CUserTool* pSelTool);
```

### <a name="parameters"></a>parâmetros

*pSelTool*<br/>
[entrada, saída] Um ponteiro para o objeto da ferramenta do usuário que foi alterado.

### <a name="remarks"></a>Comentários

Esse método é chamado pela estrutura quando um usuário altera as propriedades de uma ferramenta definida pelo usuário. A implementação padrão não faz nada. Substitua esse método em uma classe derivada de `CMFCToolBarsCustomizeDialog`  para executar o processamento depois que uma alteração em uma ferramenta de usuário ocorrer.

## <a name="cmfctoolbarscustomizedialogonassignkey"></a><a name="onassignkey"></a> CMFCToolBarsCustomizeDialog::OnAssignKey

Valida os atalhos de teclado conforme um usuário os define.

```
virtual BOOL OnAssignKey(ACCEL* pAccel);
```

### <a name="parameters"></a>parâmetros

*pAccel*<br/>
[entrada, saída] Ponteiro para o atribuição de teclado proposto que é expresso como um struct [da aceleração extra](/windows/win32/api/winuser/ns-winuser-accel) .

### <a name="return-value"></a>Valor Retornado

TRUE se a chave puder ser atribuída ou FALSE se a chave não puder ser atribuída. A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para executar processamento extra quando um usuário atribuir um novo atalho de teclado ou para validar atalhos de teclado à medida que o usuário os definir. Para impedir que um atalho seja atribuído, retorne FALSE. Você também deve exibir uma caixa de mensagem ou informar ao usuário o motivo pelo qual o atalho de teclado foi rejeitado.

## <a name="cmfctoolbarscustomizedialogonbeforechangetool"></a><a name="onbeforechangetool"></a> CMFCToolBarsCustomizeDialog::OnBeforeChangeTool

Executa o processamento personalizado quando uma alteração em uma ferramenta de usuário quando o usuário está prestes a aplicar uma alteração.

```
virtual void OnBeforeChangeTool(CUserTool* pSelTool);
```

### <a name="parameters"></a>parâmetros

*pSelTool*<br/>
[entrada, saída] Um ponteiro para o objeto da ferramenta do usuário que está prestes a ser substituído.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework quando as propriedades de uma ferramenta definida pelo usuário estão prestes a ser alteradas. A implementação padrão não faz nada. Substitua o `OnBeforeChangeTool` método em uma classe derivada de `CMFCToolBarsCustomizeDialog`  se você deseja executar o processamento antes que ocorra uma alteração em uma ferramenta de usuário, como a liberação de recursos que o *pSelTool* usa.

## <a name="cmfctoolbarscustomizedialogonedittoolbarmenuimage"></a><a name="onedittoolbarmenuimage"></a> CMFCToolBarsCustomizeDialog::OnEditToolbarMenuImage

Inicia um editor de imagem para que um usuário possa personalizar um botão da barra de ferramentas ou um ícone de item de menu.

```
virtual BOOL OnEditToolbarMenuImage(
    CWnd* pWndParent,
    CBitmap& bitmap,
    int nBitsPerPixel);
```

### <a name="parameters"></a>parâmetros

*pWndParent*<br/>
no Um ponteiro para a janela pai.

*bitmap*<br/>
no Uma referência a um objeto de bitmap a ser editado.

*nBitsPerPixel*<br/>
no Resolução de cores de bitmap, em bits por pixel.

### <a name="return-value"></a>Valor Retornado

TRUE se uma alteração estiver sendo confirmada; caso contrário, FALSE. A implementação padrão exibirá uma caixa de diálogo e retornará TRUE se o usuário clicar em **OK**ou false se o usuário clicar em **Cancelar** ou no botão **Fechar** .

### <a name="remarks"></a>Comentários

Esse método é chamado pelo Framework quando o usuário executa o editor de imagem. A implementação padrão exibe a caixa de diálogo [classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md) . Substituir `OnEditToolbarMenuImage` em uma classe derivada para usar um editor de imagem personalizado.

## <a name="cmfctoolbarscustomizedialogoninitdialog"></a><a name="oninitdialog"></a> CMFCToolBarsCustomizeDialog:: OnInitDialog

Substitui para aumentar a inicialização da folha de propriedades.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor Retornado

O resultado da chamada do método [CPropertySheet:: OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog) .

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base, [CPropertySheet:: OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog), exibindo o botão **fechar** , certificando-se de que a caixa de diálogo se ajuste ao tamanho da tela atual e movendo o botão **ajuda** para o canto inferior esquerdo da caixa de diálogo.

## <a name="cmfctoolbarscustomizedialogoninittoolspage"></a><a name="oninittoolspage"></a> CMFCToolBarsCustomizeDialog::OnInitToolsPage

Manipula a notificação da estrutura na qual a página de **ferramentas** está prestes a ser inicializada.

```
virtual void OnInitToolsPage();
```

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada. Substitua esse método em uma classe derivada para processar essa notificação.

## <a name="cmfctoolbarscustomizedialogpostncdestroy"></a><a name="postncdestroy"></a> CMFCToolBarsCustomizeDialog::P ostNcDestroy

Chamado pelo Framework após a destruição da janela.

```
virtual void PostNcDestroy();
```

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base, `CPropertySheet::PostNcDestroy` , restaurando o aplicativo para o modo anterior.

O método [CMFCToolBarsCustomizeDialog:: Create](#create) coloca o aplicativo em um modo especial que limita o usuário às tarefas de personalização.

## <a name="cmfctoolbarscustomizedialogremovebutton"></a><a name="removebutton"></a> CMFCToolBarsCustomizeDialog::RemoveButton

Remove o botão com a ID de comando especificada da categoria especificada ou de todas as categorias.

```
int RemoveButton(
    UINT uiCategoryId,
    UINT uiCmdId);

int RemoveButton(
    LPCTSTR lpszCategory,
    UINT uiCmdId);
```

### <a name="parameters"></a>parâmetros

*uiCategoryId*<br/>
no Especifica a ID da categoria da qual o botão será removido.

*uiCmdId*<br/>
no Especifica a ID de comando do botão.

*lpszCategory*<br/>
no Especifica o nome da categoria a partir da qual o botão será removido.

### <a name="return-value"></a>Valor Retornado

O índice de base zero do botão removido ou-1 se a ID de comando especificada não foi encontrada na categoria especificada. Se *uiCategoryId* for-1, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

Para remover um botão de todas as categorias, chame a primeira sobrecarga desse método e defina *uiCategoryId* como-1.

## <a name="cmfctoolbarscustomizedialogrenamecategory"></a><a name="renamecategory"></a> CMFCToolBarsCustomizeDialog::RenameCategory

Renomeia uma categoria na caixa de listagem de categorias na página **comandos** .

```
BOOL RenameCategory(
    LPCTSTR lpszCategoryOld,
    LPCTSTR lpszCategoryNew);
```

### <a name="parameters"></a>parâmetros

*lpszCategoryOld*<br/>
no O nome da categoria a ser alterada.

*lpszCategoryNew*<br/>
no O nome da nova categoria.

### <a name="return-value"></a>Valor Retornado

TRUE se o método foi bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O nome da categoria deve ser exclusivo.

## <a name="cmfctoolbarscustomizedialogreplacebutton"></a><a name="replacebutton"></a> CMFCToolBarsCustomizeDialog::ReplaceButton

Substitui um botão da barra de ferramentas na caixa de listagem de comandos na página **comandos** .

```cpp
void ReplaceButton(
    UINT uiCmd,
    const CMFCToolBarButton& button);
```

### <a name="parameters"></a>parâmetros

*uiCmd*<br/>
no Especifica o comando do botão a ser substituído.

*Button*<br/>
no Uma **`const`** referência ao objeto de botão da barra de ferramentas que substitui o botão antigo.

### <a name="remarks"></a>Comentários

Quando [CMFCToolBarsCustomizeDialog:: AddMenu](#addmenu), [CMFCToolBarsCustomizeDialog:: AddMenuCommands](#addmenucommands)ou [CMFCToolBarsCustomizeDialog:: AddToolBar](#addtoolbar) adiciona um comando à página de **comandos** , esse comando está na forma de um objeto de [classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) (ou um objeto de [Classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md) para um item de menu que contém um submenu adicionado por `AddMenuCommands` ). A estrutura também chama esses três métodos para adicionar comandos automaticamente. Se você quiser que um comando seja representado por um tipo derivado, chame `ReplaceButton` e passe um botão do tipo derivado.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `ReplaceButton` método na `CMFCToolBarsCustomizeDialog` classe. Este trecho de código faz parte do [exemplo de demonstração do Visual Studio](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#34](../../mfc/codesnippet/cpp/cmfctoolbarscustomizedialog-class_5.cpp)]

## <a name="cmfctoolbarscustomizedialogsetusercategory"></a><a name="setusercategory"></a> CMFCToolBarsCustomizeDialog::SetUserCategory

Especifica qual categoria na lista de categorias na página **comandos** é a categoria de usuário. Você deve chamar essa função antes de chamar [CMFCToolBarsCustomizeDialog:: Create](#create).

```
BOOL SetUserCategory(LPCTSTR lpszCategory);
```

### <a name="parameters"></a>parâmetros

*lpszCategory*<br/>
no O nome da categoria.

### <a name="return-value"></a>Valor Retornado

TRUE se o método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A configuração de categoria de usuário não é usada no momento pela estrutura.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CPropertySheet](../../mfc/reference/cpropertysheet-class.md)
