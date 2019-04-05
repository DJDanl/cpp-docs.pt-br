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
ms.openlocfilehash: e1dd6fff9fa4f03dbf93510da26c78c73e86c6ab
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58780958"
---
# <a name="cmfctoolbarscustomizedialog-class"></a>Classe CMFCToolBarsCustomizeDialog

Uma caixa de diálogo de guia sem-modo ( [classe CPropertySheet](../../mfc/reference/cpropertysheet-class.md)) que permite ao usuário personalizar as barras de ferramentas, menus, atalhos de teclado, ferramentas definidas pelo usuário e o estilo visual em um aplicativo. Normalmente, o usuário acessa esta caixa de diálogo, selecionando **personalizar** da **ferramentas** menu.

O **personalizar** caixa de diálogo tem seis guias: **Comandos**, **barras de ferramentas**, **ferramentas**, **teclado**, **Menu**, e **opções**.

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
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::AddButton](#addbutton)|Insere um botão de barra de ferramentas na lista de comandos na **comandos** página|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::AddMenu](#addmenu)|Carrega um menu de recursos e chamadas [CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands) para adicionar esse menu para a lista de comandos na **comandos** página.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands)|Carrega um menu de recursos e chamadas [CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands) para adicionar esse menu para a lista de comandos na **comandos** página.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::AddToolBar](#addtoolbar)|Carrega uma barra de ferramentas de recursos. Em seguida, para cada comando no menu chamadas a [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método para inserir um botão na lista de comandos na **comandos** página sob a categoria especificada.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::Create](#create)|Exibe a **personalização** caixa de diálogo.|
|`CMFCToolBarsCustomizeDialog::EnableTools`|Reservado para uso futuro.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::EnableUserDefinedToolbars](#enableuserdefinedtoolbars)|Habilita ou desabilita a criação de novas barras de ferramentas usando o **personalizar** caixa de diálogo.|
|[CMFCToolBarsCustomizeDialog::FillAllCommandsList](#fillallcommandslist)|Popula fornecido `CListBox` objeto com os comandos a **todos os comandos** categoria.|
|[CMFCToolBarsCustomizeDialog::FillCategoriesComboBox](#fillcategoriescombobox)|Popula fornecido `CComboBox` objeto com o nome de cada categoria de comando na **personalizar** caixa de diálogo.|
|[CMFCToolBarsCustomizeDialog::FillCategoriesListBox](#fillcategorieslistbox)|Popula fornecido `CListBox` objeto com o nome de cada categoria de comando na **personalizar** caixa de diálogo.|
|[CMFCToolBarsCustomizeDialog::GetCommandName](#getcommandname)|Recupera o nome que está associado com a ID do comando fornecido.|
|[CMFCToolBarsCustomizeDialog::GetCountInCategory](#getcountincategory)|Recupera o número de itens na lista fornecida que têm um rótulo de texto especificado.|
|[CMFCToolBarsCustomizeDialog::GetFlags](#getflags)|Recupera o conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.|
|`CMFCToolBarsCustomizeDialog::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::OnEditToolbarMenuImage](#onedittoolbarmenuimage)|Inicia um editor de imagens para que um usuário pode personalizar um ícone de item de menu ou botão da barra de ferramentas.|
|[CMFCToolBarsCustomizeDialog::OnInitDialog](#oninitdialog)|Substituições para aumentar a inicialização de folha de propriedade. (Substitui [CPropertySheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog).)|
|[CMFCToolBarsCustomizeDialog::PostNcDestroy](#postncdestroy)|Chamado pelo framework depois que a janela foi destruída. (Substitui `CPropertySheet::PostNcDestroy`.)|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::RemoveButton](#removebutton)|Remove o botão com a ID de comando especificado de categoria especificada, ou de todas as categorias.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::RenameCategory](#renamecategory)|Renomeia uma categoria na caixa de listagem das categorias sobre o **comandos** guia.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::ReplaceButton](#replacebutton)|Substitui um botão na lista de comandos do **comandos** guia com um novo objeto de botão de barra de ferramentas.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::SetUserCategory](#setusercategory)|Adiciona uma categoria à lista de categorias que serão exibidos na **comandos** guia.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::CheckToolsValidity](#checktoolsvalidity)|Chamado pelo framework para determinar se a lista de ferramentas definidas pelo usuário é válida.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::OnAfterChangeTool](#onafterchangetool)|Chamado pelo framework quando alterar as propriedades de uma ferramenta definida pelo usuário.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::OnAssignKey](#onassignkey)|Determina se um atalho de teclado especificado pode ser atribuído a uma ação.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::OnBeforeChangeTool](#onbeforechangetool)|Determina se uma ferramenta definida pelo usuário pode ser alterada.|
|`CMFCToolBarsCustomizeDialog::` [CMFCToolBarsCustomizeDialog::OnInitToolsPage](#oninittoolspage)|Chamado pelo framework quando o usuário escolhe o **ferramentas** guia é solicitada.|

## <a name="remarks"></a>Comentários

Para exibir o **personalizar** diálogo caixa, crie um `CMFCToolBarsCustomizeDialog` objeto e chame o [CMFCToolBarsCustomizeDialog::Create](#create) método.

Enquanto o **personalizar** caixa de diálogo estiver ativa, o aplicativo funciona em um modo especial que limita o usuário para tarefas de personalização.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos no `CMFCToolBarsCustomizeDialog` classe. O exemplo mostra como substituir um botão de barra de ferramentas na caixa de listagem de comandos na **comandos** página, habilite a criação de novas barras de ferramentas usando o **personalizar** caixa de diálogo e exibir o  **Personalização** caixa de diálogo. Este trecho de código faz parte do [amostra de demonstração do IE](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_IEDemo#4](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CPropertySheet](../../mfc/reference/cpropertysheet-class.md)

`CMFCToolBarsCustomizeDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxToolBarsCustomizeDialog.h

##  <a name="addbutton"></a>  CMFCToolBarsCustomizeDialog::AddButton

Insere um botão de barra de ferramentas na lista de comandos na **comandos** página.

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
[in] Especifica a ID da categoria para inserir o botão.

*Botão*<br/>
[in] Especifica o botão a ser inserido.

*iInsertBefore*<br/>
[in] Especifica o índice baseado em zero de um botão de barra de ferramentas antes que o botão é inserido.

*lpszCategory*<br/>
[in] Especifica a cadeia de caracteres da categoria para inserir o botão.

### <a name="remarks"></a>Comentários

O `AddButton` método ignora os botões que têm as IDs de comando padrão (como ID_FILE_MRU_FILE1), comandos que não são permitidos (consulte [CMFCToolBar::IsCommandPermitted](../../mfc/reference/cmfctoolbar-class.md#iscommandpermitted)) e fictício botões.

Esse método cria um novo objeto do mesmo tipo que `button` (normalmente, um [classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)) usando a classe de tempo de execução do botão. Em seguida, ele chama [CMFCToolBarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom) para copiar os membros de dados do botão e insere a cópia na categoria especificada.

Quando o botão novo é inserido, ele recebe o `OnAddToCustomizePage` notificação.

Se `iInsertBefore` é -1, o botão é acrescentado à lista de categorias; caso contrário, ele é inserido antes do item com o índice especificado.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `AddButton` método da `CMFCToolBarsCustomizeDialog` classe. Este trecho de código é parte do [exemplo de controle deslizante](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_Slider#1](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_2.cpp)]

##  <a name="addmenu"></a>  CMFCToolBarsCustomizeDialog::AddMenu

Carrega um menu de recursos e chamadas [CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands) para adicionar esse menu para a lista de comandos na **comandos** página.

```
BOOL AddMenu(UINT uiMenuResId);
```

### <a name="parameters"></a>Parâmetros

*uiMenuResId*<br/>
[in] Especifica a ID do recurso de um menu para carregar.

### <a name="return-value"></a>Valor de retorno

TRUE se um menu foi adicionado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Na chamada para `AddMenuCommands`, *bPopup* é FALSE. Como resultado, esse método não adiciona itens de menu que contêm os submenus para a lista de comandos. Esse método adiciona os itens de menu nos submenus à lista de comandos.

##  <a name="addmenucommands"></a>  CMFCToolBarsCustomizeDialog::AddMenuCommands

Adiciona itens à lista de comandos na **comandos** página para representar todos os itens de menu especificado.

```
void AddMenuCommands(
    const CMenu* pMenu,
    BOOL bPopup,
    LPCTSTR lpszCategory=NULL,
    LPCTSTR lpszMenuPath=NULL);
```

### <a name="parameters"></a>Parâmetros

*pMenu*<br/>
[in] Um ponteiro para o objeto CMenu para adicionar.

*bPopup*<br/>
[in] Especifica se deve inserir os itens de menu pop-up à lista de comandos.

*lpszCategory*<br/>
[in] O nome da categoria para inserir no menu.

*lpszMenuPath*<br/>
[in] Um prefixo que é adicionado ao nome quando o comando é mostrado na **todas as categorias** lista.

### <a name="remarks"></a>Comentários

O `AddMenuCommands` loops de método em todos os itens de menu de *pMenu*. Para cada item de menu que não contém um submenu, esse método cria uma [classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) objeto e chama o [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método para adicionar o item de menu como uma barra de ferramentas botão para a lista de comandos do **comandos** página. Separadores são ignorados nesse processo.

Se *bPopup* for TRUE, para cada item de menu que contém um submenu esse método cria uma [classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md) do objeto e o insere na lista de comandos chamando `AddButton`. Caso contrário, os itens de menu que contêm seus submenus não são exibidos na lista de comandos. Em ambos os casos, quando `AddMenuCommands` encontrar um item de menu com um submenu chama a mesma recursivamente, passando um ponteiro para o submenu como o *pMenu* parâmetro e acrescentando o rótulo do submenu para *lpszMenuPath*.

##  <a name="addtoolbar"></a>  CMFCToolBarsCustomizeDialog::AddToolBar

Carrega uma barra de ferramentas de recursos. Em seguida, para cada comando no menu chamadas a [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método para inserir um botão na lista de comandos na **comandos** página sob a categoria especificada.

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
[in] Especifica a ID do recurso da categoria para adicionar a barra de ferramentas.

*uiToolbarResId*<br/>
[in] Especifica a ID do recurso de uma barra de ferramentas cujos comandos são inseridos na lista de comandos.

*lpszCategory*<br/>
[in] Especifica o nome da categoria à qual adicionar a barra de ferramentas.

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido; Caso contrário, FALSE.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `AddToolBar` método no `CMFCToolBarsCustomizeDialog` classe. Este trecho de código é parte do [exemplo de Word Pad](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_WordPad#11](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_3.cpp)]

### <a name="remarks"></a>Comentários

O controle que é usado para representar cada comando é um [classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) objeto. Depois de adicionar a barra de ferramentas, você pode substituir o botão com um controle de um tipo derivado, chamando [CMFCToolBarsCustomizeDialog::ReplaceButton](#replacebutton).

##  <a name="checktoolsvalidity"></a>  CMFCToolBarsCustomizeDialog::CheckToolsValidity

Verifica a validade da lista de ferramentas do usuário.

```
virtual BOOL CheckToolsValidity(const CObList& lstTools);
```

### <a name="parameters"></a>Parâmetros

*lstTools*<br/>
[in] A lista de ferramentas definidas pelo usuário para verificar.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a lista de ferramentas definidas pelo usuário é válida. Caso contrário, FALSE. A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

O framework chama esse método para verificar a validade de objetos que representam as ferramentas definidas pelo usuário retornadas por [CMFCToolBarsCustomizeDialog::CheckToolsValidity](#checktoolsvalidity).

Substituir a `CheckToolsValidity` método em uma classe derivada de `CMFCToolBarsCustomizeDialog` se você deseja validar as ferramentas do usuário antes do usuário fecha a caixa de diálogo. Se esse método retorna Falso quando o usuário clica em qualquer um de **feche** botão no canto superior direito da caixa de diálogo ou no botão rotulado como **fechar** no canto inferior direito da caixa de diálogo, na caixa de diálogo Exibe a **ferramentas** guia, em vez de fechamento. Se esse método retorna Falso quando o usuário clica em uma guia para navegar para fora dos **ferramentas** guia, a navegação não ocorrerá. Você deve exibir uma caixa de mensagem apropriado para informar ao usuário sobre o problema que causou a falha na validação.

##  <a name="cmfctoolbarscustomizedialog"></a>  CMFCToolBarsCustomizeDialog::CMFCToolBarsCustomizeDialog

Constrói um objeto `CMFCToolBarsCustomizeDialog`.

```
CMFCToolBarsCustomizeDialog(
    CFrameWnd* pWndParentFrame,
    BOOL bAutoSetFromMenus = FALSE,
    UINT uiFlags = (AFX_CUSTOMIZE_MENU_SHADOWS | AFX_CUSTOMIZE_TEXT_LABELS | AFX_CUSTOMIZE_MENU_ANIMATIONS | AFX_CUSTOMIZE_NOHELP),
    CList <CRuntimeClass*, CRuntimeClass*>* p listCustomPages = NULL);
```

### <a name="parameters"></a>Parâmetros

*pWndParentFrame*<br/>
[in] Um ponteiro para o quadro principal. Esse parâmetro não deve ser NULL.

*bAutoSetFromMenus*<br/>
[in] Um valor booliano que especifica se deve adicionar os comandos de menu de todos os menus para a lista de comandos na **comandos** página. Se esse parâmetro for TRUE, os comandos de menu serão adicionados. Caso contrário, os comandos de menu não são adicionados.

*uiFlags*<br/>
[in] Uma combinação de sinalizadores que afetam o comportamento da caixa de diálogo. Esse parâmetro pode ser um ou mais dos seguintes valores:

- AFX_CUSTOMIZE_MENU_SHADOWS

- AFX_CUSTOMIZE_TEXT_LABELS

- AFX_CUSTOMIZE_MENU_ANIMATIONS

- AFX_CUSTOMIZE_NOHELP

- AFX_CUSTOMIZE_CONTEXT_HELP

- AFX_CUSTOMIZE_NOTOOLS

- AFX_CUSTOMIZE_MENUAMPERS

- AFX_CUSTOMIZE_NO_LARGE_ICONS

*plistCustomPages*<br/>
[in] Um ponteiro para uma lista de `CRuntimeClass` objetos que especificam as páginas personalizadas adicionais.

### <a name="remarks"></a>Comentários

O *plistCustomPages* parâmetro refere-se à lista de `CRuntimeClass` objetos que especificam as páginas personalizadas adicionais. O construtor adiciona mais páginas à caixa de diálogo usando o [CRuntimeClass::CreateObject](../../mfc/reference/cruntimeclass-structure.md#createobject) método. Consulte o exemplo CustomPages para obter um exemplo que adiciona mais páginas para o **personalizar** caixa de diálogo.

Para obter mais informações sobre os valores que você pode passar o *uiFlags* parâmetro, consulte [CMFCToolBarsCustomizeDialog::GetFlags](#getflags).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto do `CMFCToolBarsCustomizeDialog` classe. Este trecho de código é parte do [exemplo de páginas personalizadas](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_CustomPages#3](../../mfc/reference/codesnippet/cpp/cmfctoolbarscustomizedialog-class_4.cpp)]

##  <a name="create"></a>  CMFCToolBarsCustomizeDialog::Create

Exibe a **personalização** caixa de diálogo.

```
virtual BOOL Create();
```

### <a name="return-value"></a>Valor de retorno

TRUE se a folha de propriedades de personalização é criada com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chamar o `Create` método somente depois que você inicializa a classe completamente.

##  <a name="enableuserdefinedtoolbars"></a>  CMFCToolBarsCustomizeDialog::EnableUserDefinedToolbars

Habilita ou desabilita a criação de novas barras de ferramentas usando o **personalizar** caixa de diálogo.

```
void EnableUserDefinedToolbars(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
[in] TRUE para habilitar as barras de ferramentas definidas pelo usuário; FALSE para desabilitar as barras de ferramentas.

### <a name="remarks"></a>Comentários

Se *bAtivar* for TRUE, o **New**, **Renomear** e **excluir** botões são exibidos no **barras de ferramentas** página.

Por padrão, ou se *bAtivar* for falso, esses botões não são exibidos e o usuário não é possível definir novas barras de ferramentas.

##  <a name="fillallcommandslist"></a>  CMFCToolBarsCustomizeDialog::FillAllCommandsList

Popula fornecido `CListBox` objeto com os comandos a **todos os comandos** categoria.

```
virtual void FillAllCommandsList(CListBox& wndListOfCommands) const;
```

### <a name="parameters"></a>Parâmetros

*wndListOfCommands*<br/>
[out] Uma referência para o `CListBox` objeto a ser preenchido.

### <a name="remarks"></a>Comentários

O **todos os comandos** categoria contém os comandos de todas as categorias. O [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método adiciona o comando que está associado com o botão fornecido para o **todos os comandos** categoria para você.

Esse método limpa o conteúdo fornecidos `CListBox` objeto populá-lo com os comandos antes do **todos os comandos** categoria.

O `CMFCMousePropertyPage` classe usa esse método para preencher a caixa de listagem de eventos de clique duplo.

##  <a name="fillcategoriescombobox"></a>  CMFCToolBarsCustomizeDialog::FillCategoriesComboBox

Popula fornecido `CComboBox` objeto com o nome de cada categoria de comando na **personalizar** caixa de diálogo.

```
void FillCategoriesComboBox(
    CComboBox& wndCategory,
    BOOL bAddEmpty = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

*wndCategory*<br/>
[out] Uma referência para o `CComboBox` objeto a ser preenchido.

*bAddEmpty*<br/>
[in] Um valor booliano que especifica se deve adicionar categorias para a caixa de combinação que não têm comandos. Se esse parâmetro for TRUE, vazias categorias são adicionadas à caixa de combinação. Caso contrário, as categorias vazias não são adicionadas.

### <a name="remarks"></a>Comentários

Esse método é como o [CMFCToolBarsCustomizeDialog::FillCategoriesListBox](#fillcategorieslistbox) método, exceto que esse método funciona com um `CComboBox` objeto.

Esse método não limpa o conteúdo do `CComboBox` objeto antes populá-lo. Ele garante que o **todos os comandos** categoria é o item final na caixa de combinação.

Você pode adicionar novas categorias de comando usando o [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método. Você pode alterar o nome de uma categoria existente usando o [CMFCToolBarsCustomizeDialog::RenameCategory](#renamecategory) método.

O `CMFCToolBarsKeyboardPropertyPage` e `CMFCKeyMapDialog` classes usam esse método para categorizar os mapeamentos de teclado.

##  <a name="fillcategorieslistbox"></a>  CMFCToolBarsCustomizeDialog::FillCategoriesListBox

Popula fornecido `CListBox` objeto com o nome de cada categoria de comando na **personalizar** caixa de diálogo.

```
void FillCategoriesListBox(
    CListBox& wndCategory,
    BOOL bAddEmpty = TRUE) const;
```

### <a name="parameters"></a>Parâmetros

*wndCategory*<br/>
[out] Uma referência para o `CListBox` objeto a ser preenchido.

*bAddEmpty*<br/>
[in] Um valor booliano que especifica se deve adicionar categorias para a caixa de listagem que não têm comandos. Se esse parâmetro for TRUE, vazias categorias são adicionadas à caixa de listagem. Caso contrário, as categorias vazias não são adicionadas.

### <a name="remarks"></a>Comentários

Esse método é como o [CMFCToolBarsCustomizeDialog::FillCategoriesComboBox](#fillcategoriescombobox) método, exceto que esse método funciona com um `CListBox` objeto.

Esse método não limpa o conteúdo do `CListBox` objeto antes populá-lo. Ele garante que o **todos os comandos** categoria é o item final na caixa de listagem.

Você pode adicionar novas categorias de comando usando o [CMFCToolBarsCustomizeDialog::AddButton](#addbutton) método. Você pode alterar o nome de uma categoria existente usando o [CMFCToolBarsCustomizeDialog::RenameCategory](#renamecategory) método.

O `CMFCToolBarsCommandsPropertyPage` classe usa esse método para mostrar a lista de comandos que está associada com cada categoria de comando.

##  <a name="getcommandname"></a>  CMFCToolBarsCustomizeDialog::GetCommandName

Recupera o nome que está associado com a ID do comando fornecido.

```
LPCTSTR GetCommandName(UINT uiCmd) const;
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
[in] A ID do comando para recuperar.

### <a name="return-value"></a>Valor de retorno

O nome que está associado com a ID de comando especificada ou nulo se o comando não existe.

##  <a name="getcountincategory"></a>  CMFCToolBarsCustomizeDialog::GetCountInCategory

Recupera o número de itens na lista fornecida que têm um rótulo de texto especificado.

```
int GetCountInCategory(
    LPCTSTR lpszItemName,
    const CObList& lstCommands) const;
```

### <a name="parameters"></a>Parâmetros

*lpszItemName*<br/>
[in] O rótulo de texto para correspondência.

*lstCommands*<br/>
[in] Uma referência a uma lista que contém `CMFCToolBarButton` objetos.

### <a name="return-value"></a>Valor de retorno

O número de itens fornecidos lista cuja rótulo de texto é igual a *lpszItemName*.

### <a name="remarks"></a>Comentários

Cada elemento na lista de objeto fornecido deve ser do tipo `CMFCToolBarButton`. Esse método compara *lpszItemName* com o [CMFCToolBarButton::m_strText](../../mfc/reference/cmfctoolbarbutton-class.md#m_strtext) membro de dados.

##  <a name="getflags"></a>  CMFCToolBarsCustomizeDialog::GetFlags

Recupera o conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.

```
UINT GetFlags() const;
```

### <a name="return-value"></a>Valor de retorno

O conjunto de sinalizadores que afetam o comportamento da caixa de diálogo.

### <a name="remarks"></a>Comentários

Esse método recupera o valor de *uiFlags* parâmetro que é passado para o construtor. O valor de retorno pode ser um ou mais dos seguintes valores:

|||
|-|-|
|AFX_CUSTOMIZE_MENU_SHADOWS|Permite ao usuário especificar a aparência de sombra do menu.  |
|AFX_CUSTOMIZE_TEXT_LABELS|Permite ao usuário especificar se os rótulos de texto são mostrados abaixo as imagens de botão de barra de ferramentas.  |
|AFX_CUSTOMIZE_MENU_ANIMATIONS|Permite que o usuário especifique o estilo de animação do menu.  |
|AFX_CUSTOMIZE_NOHELP|Remove o botão de Ajuda da caixa de diálogo de personalização.  |
|AFX_CUSTOMIZE_CONTEXT_HELP|Permite que o estilo visual de WS_EX_CONTEXTHELP.  |
|AFX_CUSTOMIZE_NOTOOLS|Remove o **ferramentas** página da caixa de diálogo de personalização. Esse sinalizador é válido se seu aplicativo usa o `CUserToolsManager` classe.  |
|AFX_CUSTOMIZE_MENUAMPERS|Permite que as legendas do botão conter o e comercial ( **&**) caracteres.  |
|AFX_CUSTOMIZE_NO_LARGE_ICONS|Remove o **ícones grandes** opção da caixa de diálogo de personalização.  |

Para obter mais informações sobre o estilo visual de WS_EX_CONTEXTHELP, consulte [estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles).

##  <a name="onafterchangetool"></a>  CMFCToolBarsCustomizeDialog::OnAfterChangeTool

Responde a uma alteração em uma ferramenta de usuário imediatamente depois que ele ocorre.

```
virtual void OnAfterChangeTool(CUserTool* pSelTool);
```

### <a name="parameters"></a>Parâmetros

*pSelTool*<br/>
[no, out] Um ponteiro para o objeto de ferramenta do usuário que foi alterado.

### <a name="remarks"></a>Comentários

Este método é chamado pelo framework quando um usuário altera as propriedades de uma ferramenta definida pelo usuário. A implementação padrão não faz nada. Substitua este método em uma classe derivada de `CMFCToolBarsCustomizeDialog` para executar o processamento depois que ocorre uma alteração em uma ferramenta de usuário.

##  <a name="onassignkey"></a>  CMFCToolBarsCustomizeDialog::OnAssignKey

Valida os atalhos de teclado como um usuário define-los.

```
virtual BOOL OnAssignKey(ACCEL* pAccel);
```

### <a name="parameters"></a>Parâmetros

*pAccel*<br/>
[no, out] Ponteiro para a atribuição de teclado proposta é expresso como uma [ACELERAÇÃO](/windows/desktop/api/winuser/ns-winuser-tagaccel) struct.

### <a name="return-value"></a>Valor de retorno

TRUE se a chave pode ser atribuído, ou FALSE se a chave não pode ser atribuída. A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para executar processamento extra, quando um usuário atribui um novo atalho de teclado, ou validar os atalhos de teclado, como o usuário define-los. Para impedir que um atalho que está sendo atribuída, retorne FALSE. Você deve também exibem uma caixa de mensagem ou caso contrário, informar ao usuário sobre o motivo pelo qual o atalho de teclado foi rejeitado.

##  <a name="onbeforechangetool"></a>  CMFCToolBarsCustomizeDialog::OnBeforeChangeTool

Executa o processamento personalizado quando uma alteração em uma ferramenta de usuário quando o usuário está prestes a aplicar uma alteração.

```
virtual void OnBeforeChangeTool(CUserTool* pSelTool);
```

### <a name="parameters"></a>Parâmetros

*pSelTool*<br/>
[no, out] Um ponteiro para o objeto de ferramenta do usuário que está prestes a ser substituído.

### <a name="remarks"></a>Comentários

Este método é chamado pelo framework quando as propriedades de uma ferramenta definida pelo usuário está prestes a ser alterada. A implementação padrão não faz nada. Substituir a `OnBeforeChangeTool` método em uma classe derivada de `CMFCToolBarsCustomizeDialog` se você quiser executar o processamento antes que ocorra uma alteração em uma ferramenta de usuário, como a liberação de recursos que *pSelTool* usa.

##  <a name="onedittoolbarmenuimage"></a>  CMFCToolBarsCustomizeDialog::OnEditToolbarMenuImage

Inicia um editor de imagens para que um usuário pode personalizar um ícone de item de menu ou botão da barra de ferramentas.

```
virtual BOOL OnEditToolbarMenuImage(
    CWnd* pWndParent,
    CBitmap& bitmap,
    int nBitsPerPixel);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[in] Um ponteiro para a janela pai.

*bitmap*<br/>
[in] Uma referência a um objeto de bitmap a ser editado.

*nBitsPerPixel*<br/>
[in] Resolução de cor, em bits por pixel de bitmap.

### <a name="return-value"></a>Valor de retorno

TRUE se uma alteração está sendo confirmada; Caso contrário, FALSE. A implementação padrão exibe uma caixa de diálogo e retorna verdadeiro se o usuário clica **Okey**, ou FALSE se o usuário clicar **Cancelar** ou o **fechar** botão.

### <a name="remarks"></a>Comentários

Este método é chamado pelo framework quando o usuário executa o editor de imagens. As exibições de implementação do padrão [classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md) caixa de diálogo. Substituir `OnEditToolbarMenuImage` em uma classe derivada usar um editor de imagem personalizada.

##  <a name="oninitdialog"></a>  CMFCToolBarsCustomizeDialog::OnInitDialog

Substituições para aumentar a inicialização de folha de propriedade.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor de retorno

O resultado da chamada a [CPropertySheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog) método.

### <a name="remarks"></a>Comentários

Este método estende a implementação de classe base [CPropertySheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog), exibindo o **fechar** botão, certificando-se de que a caixa de diálogo se ajusta o tamanho da tela atual e movendo a **Ajudar** botão para o canto inferior esquerdo da caixa de diálogo.

##  <a name="oninittoolspage"></a>  CMFCToolBarsCustomizeDialog::OnInitToolsPage

Lida com a notificação do framework que o **ferramentas** página está prestes a ser inicializado.

```
virtual void OnInitToolsPage();
```

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada. Substitua este método em uma classe derivada para processar essa notificação.

##  <a name="postncdestroy"></a>  CMFCToolBarsCustomizeDialog::PostNcDestroy

Chamado pelo framework depois que a janela foi destruída.

```
virtual void PostNcDestroy();
```

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base, `CPropertySheet::PostNcDestroy`, restaurando o aplicativo para o modo anterior.

O [CMFCToolBarsCustomizeDialog::Create](#create) método coloca o aplicativo em um modo especial que limita o usuário para tarefas de personalização.

##  <a name="removebutton"></a>  CMFCToolBarsCustomizeDialog::RemoveButton

Remove o botão com a ID de comando especificado de categoria especificada, ou de todas as categorias.

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
[in] Especifica a ID da categoria da qual remover o botão.

*uiCmdId*<br/>
[in] Especifica a ID de comando do botão.

*lpszCategory*<br/>
[in] Especifica o nome da categoria da qual remover o botão.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do botão removido ou -1 se a ID de comando especificado não foi encontrada na categoria especificada. Se *uiCategoryId* é -1, o valor retornado será 0.

### <a name="remarks"></a>Comentários

Para remover um botão de todas as categorias, chame a primeira sobrecarga desse método e o conjunto *uiCategoryId* como -1.

##  <a name="renamecategory"></a>  CMFCToolBarsCustomizeDialog::RenameCategory

Renomeia uma categoria na caixa de listagem das categorias sobre o **comandos** página.

```
BOOL RenameCategory(
    LPCTSTR lpszCategoryOld,
    LPCTSTR lpszCategoryNew);
```

### <a name="parameters"></a>Parâmetros

*lpszCategoryOld*<br/>
[in] O nome da categoria para alterar.

*lpszCategoryNew*<br/>
[in] O novo nome de categoria.

### <a name="return-value"></a>Valor de retorno

TRUE se o método foi bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O nome da categoria deve ser exclusivo.

##  <a name="replacebutton"></a>  CMFCToolBarsCustomizeDialog::ReplaceButton

Substitui um botão de barra de ferramentas na caixa de listagem de comandos do **comandos** página.

```
void ReplaceButton(
    UINT uiCmd,
    const CMFCToolBarButton& button);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
[in] Especifica o comando do botão a ser substituído.

*Botão*<br/>
[in] Um **const** referência para o objeto de botão de barra de ferramentas que substitui o antigo botão.

### <a name="remarks"></a>Comentários

Quando [CMFCToolBarsCustomizeDialog::AddMenu](#addmenu), [CMFCToolBarsCustomizeDialog::AddMenuCommands](#addmenucommands), ou [CMFCToolBarsCustomizeDialog::AddToolBar](#addtoolbar) adiciona um comando para o **comandos** página, que o comando está na forma de uma [classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) objeto (ou uma [classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md) objeto para um menu item que contém um submenu adicionado pelo `AddMenuCommands`). A estrutura também chama esses três métodos para adicionar comandos automaticamente. Se você quiser um comando para ser representado por um tipo derivado, chamar `ReplaceButton` e passar em um botão do tipo derivado.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `ReplaceButton` método no `CMFCToolBarsCustomizeDialog` classe. Este trecho de código faz parte do [amostra de demonstração do Visual Studio](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#34](../../mfc/codesnippet/cpp/cmfctoolbarscustomizedialog-class_5.cpp)]

##  <a name="setusercategory"></a>  CMFCToolBarsCustomizeDialog::SetUserCategory

Especifica qual categoria na lista de categorias na **comandos** página é a categoria de usuário. Você deve chamar essa função antes de chamar [CMFCToolBarsCustomizeDialog::Create](#create).

```
BOOL SetUserCategory(LPCTSTR lpszCategory);
```

### <a name="parameters"></a>Parâmetros

*lpszCategory*<br/>
[in] O nome da categoria.

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A configuração de categoria de usuário não é usada atualmente pela estrutura.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CPropertySheet](../../mfc/reference/cpropertysheet-class.md)
