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
ms.openlocfilehash: d47ecf45a7bbfc563be0c05cd15ee84d430f502f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377356"
---
# <a name="cmfctoolbarscustomizedialog-class"></a>Classe CMFCToolBarsCustomizeDialog

Uma caixa de diálogo de guia modeless [(CPropertySheet Class)](../../mfc/reference/cpropertysheet-class.md)que permite ao usuário personalizar as barras de ferramentas, menus, atalhos de teclado, ferramentas definidas pelo usuário e estilo visual em um aplicativo. Normalmente, o usuário acessa esta caixa de diálogo selecionando **Personalizar** no menu **Ferramentas.**

A caixa **de** diálogo Personalizar tem seis guias: **Comandos,** **Barras de Ferramentas,** **Ferramentas,** **Teclado,** **Menu**e **Opções.**

## <a name="syntax"></a>Sintaxe

```
class CMFCToolBarsCustomizeDialog : public CPropertySheet
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarsCustomCustomDialog::CMFCBarsBarsPersonalizemdiálogo](#cmfctoolbarscustomizedialog)|Constrói um objeto `CMFCToolBarsCustomizeDialog`.|
|`CMFCToolBarsCustomizeDialog::~CMFCToolBarsCustomizeDialog`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarsCustomCustomDialog::Addbutton](#addbutton)|Insere um botão de barra de ferramentas na lista de comandos na página **Comandos**|
|[CMFCToolBarsCustomcustomdialog::Addmenu](#addmenu)|Carrega um menu dos recursos e chama [CMFCToolBarsPersonalize-seDiálogo::AddMenuCommands](#addmenucommands) para adicionar esse menu à lista de comandos na página **Comandos.**|
|[CMFCBarsCustomCustomDeDiálogo::AddMenuCommands](#addmenucommands)|Carrega um menu dos recursos e chama [CMFCToolBarsPersonalize-seDiálogo::AddMenuCommands](#addmenucommands) para adicionar esse menu à lista de comandos na página **Comandos.**|
|[CMFCToolBarsCustomCustomdialog::Addtoolbar](#addtoolbar)|Carrega uma barra de ferramentas dos recursos. Em seguida, para cada comando no menu chama o [método CMFCToolBarsCustomizeDialog::AddButton](#addbutton) method to insert a button inthe lista de comandos na página **Comandos** na categoria especificada.|
|[CMFCToolBarsCustomCustomDialog::Create](#create)|Exibe a caixa de diálogo **Personalização.**|
|`CMFCToolBarsCustomizeDialog::EnableTools`|Reservado para uso futuro.|
|[CMFCBarsCustomDeDiálogo::AtivarBarras de ferramentas definidas pelo usuário](#enableuserdefinedtoolbars)|Ativa ou desativa a criação de novas barras de ferramentas usando a caixa de diálogo **Personalizar.**|
|[CMFCBarsCustomCustomDeDiálogo::FillAllCommandsList](#fillallcommandslist)|Preenche o objeto `CListBox` fornecido com os comandos na categoria **Todos os Comandos.**|
|[CMFCBarsCustomCustomDeDiálogo::PreenchimentoCategoriasComboBox](#fillcategoriescombobox)|Preenche o objeto `CComboBox` fornecido com o nome de cada categoria de comando na caixa de diálogo **Personalizar.**|
|[CMFCBarsCustomCustomDeDiálogo::PreenchimentoCategoriasListBox](#fillcategorieslistbox)|Preenche o objeto `CListBox` fornecido com o nome de cada categoria de comando na caixa de diálogo **Personalizar.**|
|[CMFCToolBarsCustomCustomDialog::GetCommandName](#getcommandname)|Recupera o nome associado ao ID de comando dado.|
|[CMFCToolBarsCustomcustomdialog::getcountincategory](#getcountincategory)|Recupera o número de itens na lista fornecida que possuem um determinado rótulo de texto.|
|[CMFCToolBarsCustomcustomdialog::GetFlags](#getflags)|Recupera o conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.|
|`CMFCToolBarsCustomizeDialog::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCBarsCustomCustomDeMarca::OnEditToolbarMenuImage](#onedittoolbarmenuimage)|Inicia um editor de imagens para que o usuário possa personalizar um botão de barra de ferramentas ou um ícone de item do menu.|
|[CMFCBarsCustomCustomDialog::OnInitDialog](#oninitdialog)|Substitui-se para aumentar a inicialização da folha de propriedades. (Substitui [cpropertysheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog).)|
|[CMFCBarsCustomCustomDialog::PostNcDestroy](#postncdestroy)|Chamado pela estrutura depois que a janela foi destruída. (Substitui `CPropertySheet::PostNcDestroy`.)|
|[CMFCToolBarsCustomCustomCaixa::Remover botão](#removebutton)|Remove o botão com o ID de comando especificado da categoria especificada ou de todas as categorias.|
|[CMFCBarrasdeferramentasMarcaçãoDemarcação::Renomenomecategory](#renamecategory)|Renomeie uma categoria na caixa de lista de categorias na guia **Comandos.**|
|[CMFCFerramentasdeferramentasDiálogo::Substituir botão](#replacebutton)|Substitui um botão na lista de comandos na guia **Comandos** por um novo objeto de botão da barra de ferramentas.|
|[CMFCToolBarsCustomCustomDialog::setUsercategory](#setusercategory)|Adiciona uma categoria à lista de categorias que serão exibidas na guia **Comandos.**|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCBarsCustomCustomDialog::CheckToolsValidity](#checktoolsvalidity)|Chamado pela estrutura para determinar se a lista de ferramentas definidas pelo usuário é válida.|
|[CMFCToolBarsCustomcustomdialog::Onafterchangetool](#onafterchangetool)|Chamado pela estrutura quando as propriedades de uma ferramenta definida pelo usuário mudam.|
|[CMFCBarsCustomCustomDediálogo::OnAssignKey](#onassignkey)|Determina se um atalho de teclado especificado pode ser atribuído a uma ação.|
|[CMFCToolBarsCustomcustomdialog::OnbeforeChangetool](#onbeforechangetool)|Determina se uma ferramenta definida pelo usuário pode ser alterada.|
|[CMFCBarsCustomCustomDialog::OnInitToolsPage](#oninittoolspage)|Chamado pela estrutura quando o usuário escolhe a guia **Ferramentas** é solicitado.|

## <a name="remarks"></a>Comentários

Para exibir a caixa de `CMFCToolBarsCustomizeDialog` diálogo **Personalizar,** crie um objeto e chame o [CMFCToolBarsPersonalizeOmétodo::Criar](#create) método.

Enquanto a caixa de diálogo **Personalizar** estiver ativa, o aplicativo funciona em um modo especial que limita o usuário a tarefas de personalização.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCToolBarsCustomizeDialog` usar vários métodos na classe. O exemplo mostra como substituir um botão de barra de ferramentas na caixa de lista de comandos na página **Comandos,** habilitar a criação de novas barras de ferramentas usando a caixa de diálogo **Personalizar** e exibir a caixa de diálogo **Personalização.** Este trecho de código faz parte da [amostra ie demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_IEDemo#4](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cpropertysheet](../../mfc/reference/cpropertysheet-class.md)

`CMFCToolBarsCustomizeDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxToolBarsCustomizeDialog.h

## <a name="cmfctoolbarscustomizedialogaddbutton"></a><a name="addbutton"></a>CMFCToolBarsCustomCustomDialog::Addbutton

Insere um botão de barra de ferramentas na lista de comandos na página **Comandos.**

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

*uiCategoryId*<br/>
[em] Especifica o ID da categoria para inserir o botão.

*botão*<br/>
[em] Especifica o botão a ser inserido.

*iInsertBefore*<br/>
[em] Especifica o índice baseado em zero de um botão de barra de ferramentas antes do qual o botão é inserido.

*lpszCategoria*<br/>
[em] Especifica a string de categoria para inserir o botão.

### <a name="remarks"></a>Comentários

O `AddButton` método ignora botões que possuem os IDs de comando padrão (como ID_FILE_MRU_FILE1), comandos que não são permitidos (ver [CMFCToolBar::IsCommandAllowed)](../../mfc/reference/cmfctoolbar-class.md#iscommandpermitted)e botões manequim.

Este método cria um novo objeto `button` do mesmo tipo que (geralmente um [CMFCToolBarButton Class](../../mfc/reference/cmfctoolbarbutton-class.md)) usando a classe de tempo de execução do botão. Em seguida, ele chama [CMFCToolBarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom) para copiar os membros de dados do botão e insere a cópia na categoria especificada.

Quando o novo botão é inserido, ele recebe a `OnAddToCustomizePage` notificação.

Se `iInsertBefore` for -1, o botão é anexado à lista de categorias; caso contrário, ele é inserido antes do item com o índice especificado.

### <a name="example"></a>Exemplo

O exemplo a seguir `AddButton` demonstra como `CMFCToolBarsCustomizeDialog` usar o método da classe. Este trecho de código faz parte da [amostra de controle deslizante](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Slider#1](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_2.cpp)]

## <a name="cmfctoolbarscustomizedialogaddmenu"></a><a name="addmenu"></a>CMFCToolBarsCustomcustomdialog::Addmenu

Carrega um menu dos recursos e chama [CMFCToolBarsPersonalize-seDiálogo::AddMenuCommands](#addmenucommands) para adicionar esse menu à lista de comandos na página **Comandos.**

```
BOOL AddMenu(UINT uiMenuResId);
```

### <a name="parameters"></a>Parâmetros

*uiMenuResId*<br/>
[em] Especifica o ID de recurso de um menu a ser carregado.

### <a name="return-value"></a>Valor retornado

TRUE se um menu foi adicionado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Na chamada `AddMenuCommands`para *, bPopup* é FALSE. Como resultado, esse método não adiciona itens de menu que contêm submenus à lista de comandos. Este método adiciona os itens do menu nos submenus à lista de comandos.

## <a name="cmfctoolbarscustomizedialogaddmenucommands"></a><a name="addmenucommands"></a>CMFCBarsCustomCustomDeDiálogo::AddMenuCommands

Adiciona itens à lista de comandos na página **Comandos** para representar todos os itens do menu especificado.

```
void AddMenuCommands(
    const CMenu* pMenu,
    BOOL bPopup,
    LPCTSTR lpszCategory=NULL,
    LPCTSTR lpszMenuPath=NULL);
```

### <a name="parameters"></a>Parâmetros

*pMenu*<br/>
[em] Um ponteiro para o objeto CMenu para adicionar.

*bPopup*<br/>
[em] Especifica se deve inserir os itens do menu popup na lista de comandos.

*lpszCategoria*<br/>
[em] O nome da categoria para inserir o menu.

*lpszMenuPath*<br/>
[em] Um prefixo que é adicionado ao nome quando o comando é mostrado na lista **Todas as Categorias.**

### <a name="remarks"></a>Comentários

O `AddMenuCommands` método faz loops sobre todos os itens do menu de *pMenu*. Para cada item do menu que não contém um submenu, este método cria um objeto [CMFCToolBarButton Class](../../mfc/reference/cmfctoolbarbutton-class.md) e chama o [CMFCToolBarsPersonalize-se::AddButton](#addbutton) method to addthe item as a toolbar button to the lista de comandos na página **Comandos.** Separadores são ignorados nesse processo.

Se *bPopup* for TRUE, para cada item de menu que contenha um submenu este método criará um `AddButton`objeto [CMFCToolBarMenuButton Class](../../mfc/reference/cmfctoolbarmenubutton-class.md) e o inserirá na lista de comandos chamando . Caso contrário, os itens do menu que contêm submenus não são exibidos na lista de comandos. Em ambos os `AddMenuCommands` casos, quando encontra um item do menu com um submenu, ele se chama recursivamente, passando um ponteiro para o submenu como o parâmetro *pMenu* e anexando o rótulo do submenu para *lpszMenuPath*.

## <a name="cmfctoolbarscustomizedialogaddtoolbar"></a><a name="addtoolbar"></a>CMFCToolBarsCustomCustomdialog::Addtoolbar

Carrega uma barra de ferramentas dos recursos. Em seguida, para cada comando no menu chama o [método CMFCToolBarsCustomizeDialog::AddButton](#addbutton) method to insert a button inthe lista de comandos na página **Comandos** na categoria especificada.

```
BOOL AddToolBar(
    UINT uiCategoryId,
    UINT uiToolbarResId);

BOOL AddToolBar(
    LPCTSTR lpszCategory,
    UINT uiToolbarResId);
```

### <a name="parameters"></a>Parâmetros

*uiCategoryId*<br/>
[em] Especifica o ID de recurso da categoria para adicionar a barra de ferramentas.

*uiToolbarResId*<br/>
[em] Especifica o ID de recurso de uma barra de ferramentas cujos comandos estão inseridos na lista de comandos.

*lpszCategoria*<br/>
[em] Especifica o nome da categoria para adicionar a barra de ferramentas.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método for bem sucedido; caso contrário, FALSO.

### <a name="example"></a>Exemplo

O exemplo a seguir `AddToolBar` demonstra como `CMFCToolBarsCustomizeDialog` usar o método na classe. Este trecho de código faz parte da amostra do [Word Pad](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_WordPad#11](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_3.cpp)]

### <a name="remarks"></a>Comentários

O controle usado para representar cada comando é um objeto [CMFCToolBarButton Class.](../../mfc/reference/cmfctoolbarbutton-class.md) Depois de adicionar a barra de ferramentas, você pode substituir o botão por um controle de um tipo derivado chamando [CMFCToolBarsPersonalize-seDiálogo::SubstituirBotão](#replacebutton).

## <a name="cmfctoolbarscustomizedialogchecktoolsvalidity"></a><a name="checktoolsvalidity"></a>CMFCBarsCustomCustomDialog::CheckToolsValidity

Verifica a validade da lista de ferramentas do usuário.

```
virtual BOOL CheckToolsValidity(const CObList& lstTools);
```

### <a name="parameters"></a>Parâmetros

*LstTools*<br/>
[em] A lista de ferramentas definidas pelo usuário para verificar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a lista de ferramentas definidas pelo usuário for válida; caso contrário, FALSO. A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

A estrutura chama esse método para verificar a validade de objetos que representam ferramentas definidas pelo usuário retornadas pelo [CMFCToolBarsPersonalize-seDiálogo::CheckToolsValidity](#checktoolsvalidity).

Anular o `CheckToolsValidity` método em uma `CMFCToolBarsCustomizeDialog` classe derivada se você quiser validar as ferramentas do usuário antes que o usuário feche a caixa de diálogo. Se este método retornar FALSO quando o usuário clicar no botão **Fechar** no canto superior direito da caixa de diálogo ou no botão rotulado **Fechar** no canto inferior direito da caixa de diálogo, a caixa de diálogo exibe a guia **Ferramentas** em vez de fechar. Se este método retornar FALSO quando o usuário clicar em uma guia para navegar para longe da guia **Ferramentas,** a navegação não ocorrerá. Você deve exibir uma caixa de mensagem apropriada para informar o usuário sobre o problema que causou a falha na validação.

## <a name="cmfctoolbarscustomizedialogcmfctoolbarscustomizedialog"></a><a name="cmfctoolbarscustomizedialog"></a>CMFCToolBarsCustomCustomDialog::CMFCBarsBarsPersonalizemdiálogo

Constrói um objeto `CMFCToolBarsCustomizeDialog`.

```
CMFCToolBarsCustomizeDialog(
    CFrameWnd* pWndParentFrame,
    BOOL bAutoSetFromMenus = FALSE,
    UINT uiFlags = (AFX_CUSTOMIZE_MENU_SHADOWS | AFX_CUSTOMIZE_TEXT_LABELS | AFX_CUSTOMIZE_MENU_ANIMATIONS | AFX_CUSTOMIZE_NOHELP),
    CList <CRuntimeClass*, CRuntimeClass*>* p listCustomPages = NULL);
```

### <a name="parameters"></a>Parâmetros

*pWndParentframe*<br/>
[em] Um ponteiro para o quadro dos pais. Este parâmetro não deve ser NULO.

*bMenus autoautosetfrom*<br/>
[em] Um valor booleano que especifica se deve adicionar os comandos de menu de todos os menus à lista de comandos na página **Comandos.** Se este parâmetro for TRUE, os comandos do menu serão adicionados. Caso contrário, os comandos do menu não são adicionados.

*uiFlags*<br/>
[em] Uma combinação de bandeiras que afetam o comportamento da caixa de diálogo. Este parâmetro pode ser um ou mais dos seguintes valores:

- AFX_CUSTOMIZE_MENU_SHADOWS

- AFX_CUSTOMIZE_TEXT_LABELS

- AFX_CUSTOMIZE_MENU_ANIMATIONS

- AFX_CUSTOMIZE_NOHELP

- AFX_CUSTOMIZE_CONTEXT_HELP

- AFX_CUSTOMIZE_NOTOOLS

- AFX_CUSTOMIZE_MENUAMPERS

- AFX_CUSTOMIZE_NO_LARGE_ICONS

*plistCustomPages*<br/>
[em] Um ponteiro para `CRuntimeClass` uma lista de objetos que especificam páginas personalizadas adicionais.

### <a name="remarks"></a>Comentários

O parâmetro *plistCustomPages* refere-se `CRuntimeClass` à lista de objetos que especificam páginas personalizadas adicionais. O construtor adiciona mais páginas à caixa de diálogo usando o método [CRuntimeClass::CreateObject.](../../mfc/reference/cruntimeclass-structure.md#createobject) Consulte a amostra Páginas personalizadas para obter um exemplo que adiciona mais páginas à caixa de diálogo **Personalizar.**

Para obter mais informações sobre os valores que você pode passar no parâmetro *uiFlags,* consulte [CMFCToolBarsPersonalize-seDiálogo::GetFlags](#getflags).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCToolBarsCustomizeDialog` construir um objeto da classe. Este trecho de código faz parte da [amostra Páginas Personalizadas](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_CustomPages#3](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_4.cpp)]

## <a name="cmfctoolbarscustomizedialogcreate"></a><a name="create"></a>CMFCToolBarsCustomCustomDialog::Create

Exibe a caixa de diálogo **Personalização.**

```
virtual BOOL Create();
```

### <a name="return-value"></a>Valor retornado

TRUE se a folha de propriedade de personalização for criada com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chame `Create` o método somente depois de inicializar totalmente a classe.

## <a name="cmfctoolbarscustomizedialogenableuserdefinedtoolbars"></a><a name="enableuserdefinedtoolbars"></a>CMFCBarsCustomDeDiálogo::AtivarBarras de ferramentas definidas pelo usuário

Ativa ou desativa a criação de novas barras de ferramentas usando a caixa de diálogo **Personalizar.**

```
void EnableUserDefinedToolbars(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para habilitar as barras de ferramentas definidas pelo usuário; FALSE para desativar as barras de ferramentas.

### <a name="remarks"></a>Comentários

Se *bEnable* for TRUE, os botões **Novo**, **Renome** e **Exclusão** serão exibidos na página **Barras de Ferramentas.**

Por padrão, ou se *bEnable* for FALSE, esses botões não são exibidos e o usuário não pode definir novas barras de ferramentas.

## <a name="cmfctoolbarscustomizedialogfillallcommandslist"></a><a name="fillallcommandslist"></a>CMFCBarsCustomCustomDeDiálogo::FillAllCommandsList

Preenche o objeto `CListBox` fornecido com os comandos na categoria **Todos os Comandos.**

```
virtual void FillAllCommandsList(CListBox& wndListOfCommands) const;
```

### <a name="parameters"></a>Parâmetros

*wndListOfCommands*<br/>
[fora] Uma referência `CListBox` ao objeto a ser preenchido.

### <a name="remarks"></a>Comentários

A categoria **Todos os Comandos** contém os comandos de todas as categorias. O [método CMFCToolBarsPersonalize-se::O](#addbutton) método AddButton adiciona o comando associado ao botão fornecido à categoria Todos os **Comandos** para você.

Este método limpa o conteúdo `CListBox` do objeto fornecido antes de povoá-lo com os comandos na categoria **Todos os Comandos.**

A `CMFCMousePropertyPage` classe usa esse método para preencher a caixa de lista de eventos de dois cliques.

## <a name="cmfctoolbarscustomizedialogfillcategoriescombobox"></a><a name="fillcategoriescombobox"></a>CMFCBarsCustomCustomDeDiálogo::PreenchimentoCategoriasComboBox

Preenche o objeto `CComboBox` fornecido com o nome de cada categoria de comando na caixa de diálogo **Personalizar.**

```
void FillCategoriesComboBox(
    CComboBox& wndCategory,
    BOOL bAddEmpty = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

*wndCategory*<br/>
[fora] Uma referência `CComboBox` ao objeto a ser preenchido.

*bAddEmpty*<br/>
[em] Um valor booleano que especifica se deve adicionar categorias à caixa de combinação que não possuem comandos. Se este parâmetro for TRUE, categorias vazias serão adicionadas à caixa de combinação. Caso contrário, categorias vazias não são adicionadas.

### <a name="remarks"></a>Comentários

Este método é como o [cmfcToolBarsPersonalizeOtipo::FillCategoriesListBox](#fillcategorieslistbox) método, exceto que este método funciona com um `CComboBox` objeto.

Este método não limpa o `CComboBox` conteúdo do objeto antes de povoá-lo. Ele garante que a categoria **Todos os Comandos** é o item final na caixa de combinação.

Você pode adicionar novas categorias de comando usando o [método CMFCToolBarsCustomizeCustomDialog::AddButton](#addbutton) method. Você pode alterar o nome de uma categoria existente usando o [CMFCToolBarsPersonalize-seDiálogo::Renomenomecategoria](#renamecategory) método.

As `CMFCToolBarsKeyboardPropertyPage` `CMFCKeyMapDialog` classes e as classes usam esse método para categorizar mapeamentos de teclado.

## <a name="cmfctoolbarscustomizedialogfillcategorieslistbox"></a><a name="fillcategorieslistbox"></a>CMFCBarsCustomCustomDeDiálogo::PreenchimentoCategoriasListBox

Preenche o objeto `CListBox` fornecido com o nome de cada categoria de comando na caixa de diálogo **Personalizar.**

```
void FillCategoriesListBox(
    CListBox& wndCategory,
    BOOL bAddEmpty = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

*wndCategory*<br/>
[fora] Uma referência `CListBox` ao objeto a ser preenchido.

*bAddEmpty*<br/>
[em] Um valor booleano que especifica se deve adicionar categorias à caixa de lista que não tem comandos. Se este parâmetro for TRUE, categorias vazias serão adicionadas à caixa de lista. Caso contrário, categorias vazias não são adicionadas.

### <a name="remarks"></a>Comentários

Este método é como o [CMFCToolBarsPersonalizeOtipo::FillCategoriesComboBox](#fillcategoriescombobox) método, exceto que este método funciona com um `CListBox` objeto.

Este método não limpa o `CListBox` conteúdo do objeto antes de povoá-lo. Ele garante que a categoria **Todos os Comandos** é o item final na caixa de lista.

Você pode adicionar novas categorias de comando usando o [método CMFCToolBarsCustomizeCustomDialog::AddButton](#addbutton) method. Você pode alterar o nome de uma categoria existente usando o [CMFCToolBarsPersonalize-seDiálogo::Renomenomecategoria](#renamecategory) método.

A `CMFCToolBarsCommandsPropertyPage` classe usa este método para mostrar a lista de comandos associados a cada categoria de comando.

## <a name="cmfctoolbarscustomizedialoggetcommandname"></a><a name="getcommandname"></a>CMFCToolBarsCustomCustomDialog::GetCommandName

Recupera o nome associado ao ID de comando dado.

```
LPCTSTR GetCommandName(UINT uiCmd) const;
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] A id do comando para recuperar.

### <a name="return-value"></a>Valor retornado

O nome que está associado ao ID de comando dado, ou NULL se o comando não existir.

## <a name="cmfctoolbarscustomizedialoggetcountincategory"></a><a name="getcountincategory"></a>CMFCToolBarsCustomcustomdialog::getcountincategory

Recupera o número de itens na lista fornecida que possuem um determinado rótulo de texto.

```
int GetCountInCategory(
    LPCTSTR lpszItemName,
    const CObList& lstCommands) const;
```

### <a name="parameters"></a>Parâmetros

*lpszItemName*<br/>
[em] O rótulo de texto para combinar.

*lstCommands*<br/>
[em] Uma referência a uma `CMFCToolBarButton` lista que contém objetos.

### <a name="return-value"></a>Valor retornado

O número de itens na lista fornecida cujo rótulo de texto é igual *a lpszItemName*.

### <a name="remarks"></a>Comentários

Cada elemento na lista de objetos `CMFCToolBarButton`fornecidos deve ser do tipo . Este método compara *lpszItemName* com o [CMFCToolBarButton::m_strText](../../mfc/reference/cmfctoolbarbutton-class.md#m_strtext) membro de dados.

## <a name="cmfctoolbarscustomizedialoggetflags"></a><a name="getflags"></a>CMFCToolBarsCustomcustomdialog::GetFlags

Recupera o conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.

```
UINT GetFlags() const;
```

### <a name="return-value"></a>Valor retornado

O conjunto de bandeiras que afetam o comportamento da caixa de diálogo.

### <a name="remarks"></a>Comentários

Este método recupera o valor do parâmetro *uiFlags* que é passado para o construtor. O valor de retorno pode ser um ou mais dos seguintes valores:

|||
|-|-|
|AFX_CUSTOMIZE_MENU_SHADOWS|Permite que o usuário especifique a aparência da sombra do menu.  |
|AFX_CUSTOMIZE_TEXT_LABELS|Permite que o usuário especifique se os rótulos de texto são mostrados abaixo das imagens do botão da barra de ferramentas.  |
|AFX_CUSTOMIZE_MENU_ANIMATIONS|Permite que o usuário especifique o estilo de animação do menu.  |
|AFX_CUSTOMIZE_NOHELP|Remove o botão de ajuda da caixa de diálogo de personalização.  |
|AFX_CUSTOMIZE_CONTEXT_HELP|Permite o estilo visual WS_EX_CONTEXTHELP.  |
|AFX_CUSTOMIZE_NOTOOLS|Remove a página **Ferramentas** da caixa de diálogo de personalização. Este sinalizador é válido se `CUserToolsManager` o aplicativo usar a classe.  |
|AFX_CUSTOMIZE_MENUAMPERS|Permite que as legendas de botão **&** contenham o caractere ampersand ( )  |
|AFX_CUSTOMIZE_NO_LARGE_ICONS|Remove a opção **Ícones Grandes** da caixa de diálogo de personalização.  |

Para obter mais informações sobre o estilo visual WS_EX_CONTEXTHELP, consulte [Estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles).

## <a name="cmfctoolbarscustomizedialogonafterchangetool"></a><a name="onafterchangetool"></a>CMFCToolBarsCustomcustomdialog::Onafterchangetool

Responde a uma alteração em uma ferramenta de usuário imediatamente após sua ocorrência.

```
virtual void OnAfterChangeTool(CUserTool* pSelTool);
```

### <a name="parameters"></a>Parâmetros

*pSelTool*<br/>
[dentro, fora] Um ponteiro para o objeto da ferramenta do usuário que foi alterado.

### <a name="remarks"></a>Comentários

Esse método é chamado pela framework quando um usuário altera as propriedades de uma ferramenta definida pelo usuário. A implementação padrão não faz nada. Substituir esse método em uma `CMFCToolBarsCustomizeDialog` classe derivada de realizar o processamento após a alteração de uma ferramenta do usuário ocorrer.

## <a name="cmfctoolbarscustomizedialogonassignkey"></a><a name="onassignkey"></a>CMFCBarsCustomCustomDediálogo::OnAssignKey

Valida atalhos de teclado à medida que um usuário os define.

```
virtual BOOL OnAssignKey(ACCEL* pAccel);
```

### <a name="parameters"></a>Parâmetros

*pAccel*<br/>
[dentro, fora] Ponteiro para o assigment de teclado proposto que é expresso como uma estrutura [ACCEL.](/windows/win32/api/winuser/ns-winuser-accel)

### <a name="return-value"></a>Valor retornado

TRUE se a chave pode ser atribuída ou FALSA se a chave não puder ser atribuída. A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Substituir esse método em uma classe derivada para executar processamento extra quando um usuário atribui um novo atalho de teclado ou para validar atalhos de teclado à medida que o usuário os define. Para evitar que um atalho seja atribuído, retorne FALSE. Você também deve exibir uma caixa de mensagem ou informar o usuário da razão pela qual o atalho do teclado foi rejeitado.

## <a name="cmfctoolbarscustomizedialogonbeforechangetool"></a><a name="onbeforechangetool"></a>CMFCToolBarsCustomcustomdialog::OnbeforeChangetool

Realiza processamento personalizado quando uma alteração em uma ferramenta de usuário quando o usuário está prestes a aplicar uma alteração.

```
virtual void OnBeforeChangeTool(CUserTool* pSelTool);
```

### <a name="parameters"></a>Parâmetros

*pSelTool*<br/>
[dentro, fora] Um ponteiro para o objeto da ferramenta do usuário que está prestes a ser substituído.

### <a name="remarks"></a>Comentários

Esse método é chamado pela estrutura quando as propriedades de uma ferramenta definida pelo usuário estão prestes a mudar. A implementação padrão não faz nada. Substituir o `OnBeforeChangeTool` método em uma `CMFCToolBarsCustomizeDialog` classe derivada de se você quiser realizar o processamento antes que uma alteração em uma ferramenta do usuário ocorra, como liberar recursos que *o pSelTool* usa.

## <a name="cmfctoolbarscustomizedialogonedittoolbarmenuimage"></a><a name="onedittoolbarmenuimage"></a>CMFCBarsCustomCustomDeMarca::OnEditToolbarMenuImage

Inicia um editor de imagens para que o usuário possa personalizar um botão de barra de ferramentas ou um ícone de item do menu.

```
virtual BOOL OnEditToolbarMenuImage(
    CWnd* pWndParent,
    CBitmap& bitmap,
    int nBitsPerPixel);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Um ponteiro para a janela dos pais.

*Bitmap*<br/>
[em] Uma referência a um objeto bitmap a ser editado.

*nBitsPerPixel*<br/>
[em] Resolução de cores do Bitmap, em bits por pixel.

### <a name="return-value"></a>Valor retornado

VERDADE se uma mudança está sendo cometida; caso contrário, FALSO. A implementação padrão exibe uma caixa de diálogo e retorna TRUE se o usuário clicar em **OK**ou FALSE se o usuário clicar em **Cancelar** ou no botão **Fechar.**

### <a name="remarks"></a>Comentários

Esse método é chamado pela framework quando o usuário executa o editor de imagens. A implementação padrão exibe a caixa de diálogo [CMFCImageEditorSala](../../mfc/reference/cmfcimageeditordialog-class.md) de diálogo. Substituir `OnEditToolbarMenuImage` em uma classe derivada para usar um editor de imagem personalizado.

## <a name="cmfctoolbarscustomizedialogoninitdialog"></a><a name="oninitdialog"></a>CMFCBarsCustomCustomDialog::OnInitDialog

Substitui-se para aumentar a inicialização da folha de propriedades.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor retornado

O resultado da chamada [cPropertySheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog) método.

### <a name="remarks"></a>Comentários

Este método amplia a implementação da classe base, [CPropertySheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog), exibindo o botão **Fechar,** certificando-se de que a caixa de diálogo se encaixa no tamanho da tela atual e movendo o botão **Ajuda** para o canto inferior esquerdo da caixa de diálogo.

## <a name="cmfctoolbarscustomizedialogoninittoolspage"></a><a name="oninittoolspage"></a>CMFCBarsCustomCustomDialog::OnInitToolsPage

Lida com a notificação da estrutura de que a página **Ferramentas** está prestes a ser inicializada.

```
virtual void OnInitToolsPage();
```

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada. Anular este método em uma classe derivada para processar esta notificação.

## <a name="cmfctoolbarscustomizedialogpostncdestroy"></a><a name="postncdestroy"></a>CMFCBarsCustomCustomDialog::PostNcDestroy

Chamado pela estrutura depois que a janela foi destruída.

```
virtual void PostNcDestroy();
```

### <a name="remarks"></a>Comentários

Este método amplia a `CPropertySheet::PostNcDestroy`implementação da classe base, restaurando a aplicação ao modo anterior.

O [CMFCToolBarsPersonalize-se::Criar](#create) método coloca o aplicativo em um modo especial que limita o usuário a tarefas de personalização.

## <a name="cmfctoolbarscustomizedialogremovebutton"></a><a name="removebutton"></a>CMFCToolBarsCustomCustomCaixa::Remover botão

Remove o botão com o ID de comando especificado da categoria especificada ou de todas as categorias.

```
int RemoveButton(
    UINT uiCategoryId,
    UINT uiCmdId);

int RemoveButton(
    LPCTSTR lpszCategory,
    UINT uiCmdId);
```

### <a name="parameters"></a>Parâmetros

*uiCategoryId*<br/>
[em] Especifica o ID da categoria a partir do qual remover o botão.

*uiCmdId*<br/>
[em] Especifica o ID de comando do botão.

*lpszCategoria*<br/>
[em] Especifica o nome da categoria a partir da qual remover o botão.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do botão removido ou -1 se o ID de comando especificado não foi encontrado na categoria especificada. Se *uiCategoryId* for -1, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

Para remover um botão de todas as categorias, chame a primeira sobrecarga deste método e defina *uiCategoryId* para -1.

## <a name="cmfctoolbarscustomizedialogrenamecategory"></a><a name="renamecategory"></a>CMFCBarrasdeferramentasMarcaçãoDemarcação::Renomenomecategory

Renomeie uma categoria na caixa de lista de categorias na página **Comandos.**

```
BOOL RenameCategory(
    LPCTSTR lpszCategoryOld,
    LPCTSTR lpszCategoryNew);
```

### <a name="parameters"></a>Parâmetros

*lpszCategoryOld*<br/>
[em] O nome da categoria para mudar.

*lpszCategoryNew*<br/>
[em] O nome da nova categoria.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

O nome da categoria deve ser único.

## <a name="cmfctoolbarscustomizedialogreplacebutton"></a><a name="replacebutton"></a>CMFCFerramentasdeferramentasDiálogo::Substituir botão

Substitui um botão de barra de ferramentas na caixa de lista de comandos na página **Comandos.**

```
void ReplaceButton(
    UINT uiCmd,
    const CMFCToolBarButton& button);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] Especifica o comando do botão a ser substituído.

*botão*<br/>
[em] Uma **referência const** ao objeto do botão da barra de ferramentas que substitui o botão antigo.

### <a name="remarks"></a>Comentários

Quando [CMFCToolBarsPersonalize-seDiálogo::AddMenu,](#addmenu) [CMFCToolBarsPersonalize-seDiálogo::AddMenuCommands](#addmenucommands)ou [CMFCBarsPersonalize-seDiálogo::AddToolBar](#addtoolbar) adiciona um comando à página **Comandos,** esse comando está na forma de um objeto [CMFCToolBarButton Class](../../mfc/reference/cmfctoolbarbutton-class.md) (ou um objeto [CMFCToolBarMenuButton Class](../../mfc/reference/cmfctoolbarmenubutton-class.md) para um item de menu que contém um submenu adicionado por `AddMenuCommands`). A estrutura também chama esses três métodos para adicionar comandos automaticamente. Se você quiser que um comando seja representado `ReplaceButton` por um tipo derivado, ligue e passe em um botão do tipo derivado.

### <a name="example"></a>Exemplo

O exemplo a seguir `ReplaceButton` demonstra como `CMFCToolBarsCustomizeDialog` usar o método na classe. Este trecho de código faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#34](../../mfc/codesnippet/cpp/cmfctoolbarscustomizedialog-class_5.cpp)]

## <a name="cmfctoolbarscustomizedialogsetusercategory"></a><a name="setusercategory"></a>CMFCToolBarsCustomCustomDialog::setUsercategory

Especifica qual categoria na lista de categorias na página **Comandos** é a categoria de usuário. Você deve chamar esta função antes de chamar [CMFCToolBarsPersonalize-seDiálogo::Criar](#create).

```
BOOL SetUserCategory(LPCTSTR lpszCategory);
```

### <a name="parameters"></a>Parâmetros

*lpszCategoria*<br/>
[em] O nome da categoria.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método for bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

A configuração da categoria do usuário não é usada atualmente pelo framework.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CPropertySheet](../../mfc/reference/cpropertysheet-class.md)
