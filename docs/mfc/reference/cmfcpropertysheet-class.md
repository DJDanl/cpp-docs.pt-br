---
title: Classe CMFCPropertySheet
ms.date: 11/19/2018
f1_keywords:
- CMFCPropertySheet
- AFXPROPERTYSHEET/CMFCPropertySheet
- AFXPROPERTYSHEET/CMFCPropertySheet::CMFCPropertySheet
- AFXPROPERTYSHEET/CMFCPropertySheet::AddPage
- AFXPROPERTYSHEET/CMFCPropertySheet::AddPageToTree
- AFXPROPERTYSHEET/CMFCPropertySheet::AddTreeCategory
- AFXPROPERTYSHEET/CMFCPropertySheet::EnablePageHeader
- AFXPROPERTYSHEET/CMFCPropertySheet::GetHeaderHeight
- AFXPROPERTYSHEET/CMFCPropertySheet::GetLook
- AFXPROPERTYSHEET/CMFCPropertySheet::GetNavBarWidth
- AFXPROPERTYSHEET/CMFCPropertySheet::GetTab
- AFXPROPERTYSHEET/CMFCPropertySheet::InitNavigationControl
- AFXPROPERTYSHEET/CMFCPropertySheet::OnActivatePage
- AFXPROPERTYSHEET/CMFCPropertySheet::OnDrawPageHeader
- AFXPROPERTYSHEET/CMFCPropertySheet::OnRemoveTreePage
- AFXPROPERTYSHEET/CMFCPropertySheet::RemoveCategory
- AFXPROPERTYSHEET/CMFCPropertySheet::RemovePage
- AFXPROPERTYSHEET/CMFCPropertySheet::SetIconsList
- AFXPROPERTYSHEET/CMFCPropertySheet::SetLook
helpviewer_keywords:
- CMFCPropertySheet [MFC], CMFCPropertySheet
- CMFCPropertySheet [MFC], AddPage
- CMFCPropertySheet [MFC], AddPageToTree
- CMFCPropertySheet [MFC], AddTreeCategory
- CMFCPropertySheet [MFC], EnablePageHeader
- CMFCPropertySheet [MFC], GetHeaderHeight
- CMFCPropertySheet [MFC], GetLook
- CMFCPropertySheet [MFC], GetNavBarWidth
- CMFCPropertySheet [MFC], GetTab
- CMFCPropertySheet [MFC], InitNavigationControl
- CMFCPropertySheet [MFC], OnActivatePage
- CMFCPropertySheet [MFC], OnDrawPageHeader
- CMFCPropertySheet [MFC], OnRemoveTreePage
- CMFCPropertySheet [MFC], RemoveCategory
- CMFCPropertySheet [MFC], RemovePage
- CMFCPropertySheet [MFC], SetIconsList
- CMFCPropertySheet [MFC], SetLook
ms.assetid: 01d93573-9698-440f-a6a4-5bebbee879dc
ms.openlocfilehash: f7c9d2b472a443d8bf556d0b12dfe202ea8607a1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505080"
---
# <a name="cmfcpropertysheet-class"></a>Classe CMFCPropertySheet

A `CMFCPropertySheet` classe oferece suporte a uma folha de propriedades em que cada página de propriedades é denotada por uma guia de página, um botão da barra de ferramentas, um nó de controle de árvore ou um item de lista.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertySheet : public CPropertySheet
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertySheet::CMFCPropertySheet](#cmfcpropertysheet)|Constrói um objeto `CMFCPropertySheet`.|
|`CMFCPropertySheet::~CMFCPropertySheet`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertySheet:: AddPage](#addpage)|Adiciona uma página à folha de propriedades.|
|[CMFCPropertySheet::AddPageToTree](#addpagetotree)|Adiciona uma nova página de propriedades ao controle de árvore.|
|[CMFCPropertySheet::AddTreeCategory](#addtreecategory)|Adiciona um novo nó ao controle de árvore.|
|[CMFCPropertySheet::EnablePageHeader](#enablepageheader)|Reserva espaço na parte superior de cada página para desenhar um cabeçalho personalizado.|
|[CMFCPropertySheet::GetHeaderHeight](#getheaderheight)|Recupera a altura do cabeçalho atual.|
|[CMFCPropertySheet::GetLook](#getlook)|Recupera um valor de enumeração que especifica a aparência da folha de propriedades atual.|
|[CMFCPropertySheet::GetNavBarWidth](#getnavbarwidth)|Repete a largura da barra de navegação em pixels.|
|[CMFCPropertySheet::GetTab](#gettab)|Recupera o objeto de controle de guia interno que dá suporte ao controle de folha de propriedades atual.|
|`CMFCPropertySheet::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCPropertySheet::InitNavigationControl](#initnavigationcontrol)|Inicializa a aparência do controle da folha de propriedades atual.|
|[CMFCPropertySheet::OnActivatePage](#onactivatepage)|Chamado pelo Framework quando uma página de propriedades é habilitada.|
|[CMFCPropertySheet::OnDrawPageHeader](#ondrawpageheader)|Chamado pelo Framework para desenhar um cabeçalho de página de propriedade personalizada.|
|`CMFCPropertySheet::OnInitDialog`|Manipula a mensagem [WM_INITDIALOG](/windows/win32/dlgbox/wm-initdialog) . (Substitui [CPropertySheet:: OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog).)|
|[CMFCPropertySheet::OnRemoveTreePage](#onremovetreepage)|Chamado pelo Framework para remover uma página de propriedades de um controle de árvore.|
|`CMFCPropertySheet::PreTranslateMessage`|Traduz mensagens de janela antes de serem expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) . (Substitui `CPropertySheet::PreTranslateMessage`.)|
|[CMFCPropertySheet::RemoveCategory](#removecategory)|Remove um nó do controle de árvore.|
|[CMFCPropertySheet:: RemovePage](#removepage)|Remove uma página de propriedades da folha de propriedades.|
|[CMFCPropertySheet:: setíconeslist](#seticonslist)|Especifica a lista de imagens que são usadas no controle de navegação do painel do Outlook.|
|[CMFCPropertySheet:: SetLook](#setlook)|Especifica a aparência da folha de propriedades.|

## <a name="remarks"></a>Comentários

A `CMFCPropertySheet` classe representa folhas de propriedades, também conhecidas como caixas de diálogo de tabulação. A `CMFCPropertySheet` classe pode exibir uma página de propriedades de várias maneiras.

Execute as seguintes etapas para usar a `CMFCPropertySheet` classe em seu aplicativo:

1. Derive uma classe da `CMFCPropertySheet` classe e nomeie a classe, por exemplo, CMyPropertySheet.

1. Construa um objeto [CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md) para cada página de propriedades.

1. Chame o método [CMFCPropertySheet:: SetLook](#setlook) no Construtor CMyPropertySheet. Um parâmetro desse método especifica que as páginas de propriedades devem ser exibidas como guias ao longo da parte superior ou esquerda da folha de propriedades; guias no estilo de uma folha de propriedades do Microsoft OneNote; botões em um controle da barra de ferramentas do Microsoft Outlook; Nós em um controle de árvore; ou como uma lista de itens no lado esquerdo da folha de propriedades.

1. Se você criar uma folha de propriedades no estilo de uma barra de ferramentas do Microsoft Outlook, chame o método [CMFCPropertySheet::](#seticonslist) setíconeslist para associar uma lista de imagens ao conjunto de páginas de propriedades.

1. Chame o método [CMFCPropertySheet:: AddPage](#addpage) para cada página de propriedades.

1. Crie um `CMFCPropertySheet` controle e chame seu `DoModal` método.

## <a name="illustrations"></a>Ilustrações

A ilustração a seguir descreve uma folha de propriedades que está no estilo de uma barra de ferramentas do Microsoft Outlook incorporada. A barra de ferramentas do Outlook aparece no lado esquerdo da folha de propriedades.

![Controles de cor CMFCPropertySheet](../../mfc/reference/media/cmfcpropertysheet_color.png "Controles de cor CMFCPropertySheet")

A ilustração a seguir descreve uma folha de propriedades que contém um objeto de [classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) . Esse objeto é uma folha de propriedades no estilo de uma folha de propriedades de controles comuns padrão.

![Controles de propriedade e lista de CMFCPropertySheet](../../mfc/reference/media/cmfcpropertysheet_list.png "Controles de propriedade e lista de CMFCPropertySheet")

A ilustração a seguir descreve uma folha de propriedades que está no estilo de um controle de árvore.

![Árvore de propriedades](../../mfc/reference/media/proptree.png "Árvore de propriedades")

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CPropertySheet](../../mfc/reference/cpropertysheet-class.md)

[CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertysheet. h

##  <a name="addpage"></a>CMFCPropertySheet:: AddPage

Adiciona uma página à folha de propriedades.

```
void AddPage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
no Ponteiro para um objeto Page. Este parâmetro não pode ser nulo.

### <a name="remarks"></a>Comentários

Esse método adiciona a página de propriedades especificada como a guia mais à direita na folha de propriedades. Portanto, use esse método para adicionar páginas na ordem da esquerda para a direita.

Se a folha de propriedades estiver no estilo do Microsoft Outlook, a estrutura exibirá uma lista de botões de navegação à esquerda da folha de propriedades. Depois que esse método adiciona uma página de propriedades, ele adiciona um botão correspondente à lista. Para exibir uma página de propriedades, clique no botão correspondente. Para obter mais informações sobre estilos de folhas de propriedades, consulte [CMFCPropertySheet:: SetLook](#setlook).

##  <a name="addpagetotree"></a>CMFCPropertySheet::AddPageToTree

Adiciona uma nova página de propriedades ao controle de árvore.

```
void AddPageToTree(
    CMFCPropertySheetCategoryInfo* pCategory,
    CMFCPropertyPage* pPage,
    int nIconNum=-1,
    int nSelIconNum=-1);
```

### <a name="parameters"></a>Parâmetros

*pCategory*<br/>
no Ponteiro para um nó de árvore pai ou nulo para associar a página especificada ao nó de nível superior. Chame o método [CMFCPropertySheet:: AddTreeCategory](#addtreecategory) para obter esse ponteiro.

*pPage*<br/>
no Ponteiro para um objeto da página de propriedades.

*nIconNum*<br/>
no Índice de base zero de um ícone ou-1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedades controle de árvore quando a página não está selecionada. O valor padrão é -1.

*nSelIconNum*<br/>
no Índice de base zero de um ícone ou-1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedades controle de árvore quando a página é selecionada. O valor padrão é -1.

### <a name="remarks"></a>Comentários

Esse método adiciona uma página de propriedades como uma folha de um controle de árvore. Para adicionar uma página de propriedades, crie `CMFCPropertySheet` um objeto, chame o método [CMFCPropertySheet:: SetLook](#setlook) com o parâmetro *look* definido `CMFCPropertySheet::PropSheetLook_Tree`como e, em seguida, use esse método para adicionar a página de propriedades.

##  <a name="addtreecategory"></a>CMFCPropertySheet::AddTreeCategory

Adiciona um novo nó ao controle de árvore.

```
CMFCPropertySheetCategoryInfo* AddTreeCategory(
    LPCTSTR lpszLabel,
    int nIconNum=-1,
    int nSelectedIconNum=-1,
    const CMFCPropertySheetCategoryInfo* pParentCategory=NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
no O nome do nó.

*nIconNum*<br/>
no Índice de base zero de um ícone ou-1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedades controle de árvore quando a página não está selecionada. O valor padrão é -1.

*nSelectedIconNum*<br/>
no Índice de base zero de um ícone ou-1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedades controle de árvore quando a página é selecionada. O valor padrão é -1.

*pParentCategory*<br/>
no Ponteiro para um nó de árvore pai ou nulo para associar a página especificada ao nó de nível superior. Defina esse parâmetro com o método [CMFCPropertySheet:: AddTreeCategory](#addtreecategory) .

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o novo nó no controle de árvore.

### <a name="remarks"></a>Comentários

Use esse método para adicionar um novo nó, que também é conhecido como uma categoria, ao controle de árvore. Para adicionar um nó, crie um `CMFCPropertySheet` objeto, chame o método [CMFCPropertySheet:: SetLook](#setlook) com o parâmetro *look* definido como `CMFCPropertySheet::PropSheetLook_Tree`e, em seguida, use esse método para adicionar o nó.

Use o valor de retorno desse método em chamadas subsequentes para [CMFCPropertySheet:: AddPageToTree](#addpagetotree) e [CMFCPropertySheet:: AddTreeCategory](#addtreecategory).

##  <a name="cmfcpropertysheet"></a>CMFCPropertySheet::CMFCPropertySheet

Constrói um objeto `CMFCPropertySheet`.

```
CMFCPropertySheet(
    UINT nIDCaption,
    CWnd* pParentWnd=NULL,
    UINT iSelectPage=0);

CMFCPropertySheet(
    LPCTSTR pszCaption,
    CWnd* pParentWnd=NULL,
    UINT iSelectPage=0);
```

### <a name="parameters"></a>Parâmetros

*pszCaption*<br/>
no Uma cadeia de caracteres que contém a legenda da folha de propriedades. Não pode ser NULL.

*nIDCaption*<br/>
no Uma ID de recurso que contém a legenda da folha de propriedades.

*pParentWnd*<br/>
no Ponteiro para a janela pai da folha de propriedades, ou NULL se a janela pai for a janela principal do aplicativo. O valor padrão é NULL.

*iSelectPage*<br/>
no O índice de base zero da página de propriedades superior. O valor padrão é 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte os parâmetros para o construtor [CPropertySheet:: CPropertySheet](../../mfc/reference/cpropertysheet-class.md#cpropertysheet) .

##  <a name="enablepageheader"></a>CMFCPropertySheet::EnablePageHeader

Reserva espaço na parte superior de cada página para desenhar um cabeçalho personalizado.

```
void EnablePageHeader(int nHeaderHeight);
```

### <a name="parameters"></a>Parâmetros

*nHeaderHeight*<br/>
no A altura do cabeçalho, em pixels.

### <a name="remarks"></a>Comentários

Para usar o valor do parâmetro *nHeaderHeight* para desenhar um cabeçalho personalizado, substitua o método [CMFCPropertySheet:: OnDrawPageHeader](#ondrawpageheader) .

##  <a name="getheaderheight"></a>CMFCPropertySheet::GetHeaderHeight

Recupera a altura do cabeçalho atual.

```
int GetHeaderHeight() const;
```

### <a name="return-value"></a>Valor de retorno

A altura do cabeçalho, em pixels.

### <a name="remarks"></a>Comentários

Chame o método [CMFCPropertySheet:: EnablePageHeader](#enablepageheader) antes de chamar esse método.

##  <a name="getlook"></a>CMFCPropertySheet:: getlook

Recupera um valor de enumeração que especifica a aparência da folha de propriedades atual.

```
PropSheetLook GetLook() const;
```

### <a name="return-value"></a>Valor de retorno

Um dos valores de enumeração que especifica a aparência da folha de propriedades. Para obter uma lista de valores possíveis, consulte a tabela de enumeração na seção comentários de [CMFCPropertySheet:: SetLook](#setlook).

##  <a name="getnavbarwidth"></a>CMFCPropertySheet::GetNavBarWidth

Obtém a largura da barra de navegação.

```
int GetNavBarWidth() const;
```

### <a name="return-value"></a>Valor de retorno

A largura da barra de navegação em pixels.

##  <a name="gettab"></a>CMFCPropertySheet::GetTab

Recupera o objeto de controle de guia interno que dá suporte ao controle de folha de propriedades atual.

```
CMFCTabCtrl& GetTab() const;
```

### <a name="return-value"></a>Valor de retorno

Um objeto de controle de guia interno.

### <a name="remarks"></a>Comentários

Você pode definir uma folha de propriedades para que ela apareça em diferentes estilos, como um controle de árvore, uma lista de botões de navegação ou um conjunto de páginas com guias.

Antes de chamar esse método, chame o método [CMFCPropertySheet:: SetLook](#setlook) para definir a aparência do controle de folha de propriedades. Em seguida, chame o método [CMFCPropertySheet:: InitNavigationControl](#initnavigationcontrol) para inicializar o objeto de controle de guia interno. Use esse método para recuperar o objeto de controle de guia e, em seguida, use esse objeto para trabalhar com as guias na folha de propriedades.

Esse método é declarado no modo de depuração se o controle de folha de propriedades não estiver definido para aparecer no estilo do Microsoft OneNote.

##  <a name="initnavigationcontrol"></a>CMFCPropertySheet::InitNavigationControl

Inicializa a aparência do controle da folha de propriedades atual.

```
virtual CWnd* InitNavigationControl();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela do controle de folha de propriedades.

### <a name="remarks"></a>Comentários

Um controle de folha de propriedades pode aparecer em várias formas diferentes, como um conjunto de páginas com guias, um controle de árvore ou uma lista de botões de navegação. Use o método [CMFCPropertySheet:: SetLook](#setlook) para especificar a aparência do controle de folha de propriedades.

##  <a name="onactivatepage"></a>CMFCPropertySheet::OnActivatePage

Chamado pelo Framework quando uma página de propriedades é habilitada.

```
virtual void OnActivatePage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
no Ponteiro para um objeto da página de propriedades que representa a página de propriedades habilitada.

### <a name="remarks"></a>Comentários

Por padrão, esse método garante que a página de propriedades habilitada seja rolada para a exibição. Se o estilo da folha de propriedades atual contiver um painel do Microsoft Outlook, esse método definirá o botão correspondente do Outlook para o estado selecionado.

##  <a name="ondrawpageheader"></a>CMFCPropertySheet::OnDrawPageHeader

Chamado pelo Framework para desenhar o cabeçalho de uma página de propriedades Personalizada.

```
virtual void OnDrawPageHeader(
    CDC* pDC,
    int nPage,
    CRect rectHeader);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para um contexto de dispositivo.

*nPage*<br/>
no O número da página de propriedades com base em zero.

*rectHeader*<br/>
no Um retângulo delimitador que especifica onde desenhar o cabeçalho.

### <a name="remarks"></a>Comentários

Por padrão, esse método não faz nada. Se você substituir esse método, chame o método [CMFCPropertySheet:: EnablePageHeader](#enablepageheader) antes que a estrutura Chame esse método.

##  <a name="onremovetreepage"></a>CMFCPropertySheet::OnRemoveTreePage

Chamado pelo Framework para remover uma página de propriedades de um controle de árvore.

```
virtual BOOL OnRemoveTreePage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
no Ponteiro para um objeto da página de propriedades que representa a página de propriedades a ser removida.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

##  <a name="removecategory"></a>CMFCPropertySheet::RemoveCategory

Remove um nó do controle de árvore.

```
void RemoveCategory(CMFCPropertySheetCategoryInfo* pCategory);
```

### <a name="parameters"></a>Parâmetros

*pCategory*<br/>
no Ponteiro para uma categoria (nó) a ser removida.

### <a name="remarks"></a>Comentários

Use este método para remover um nó, que também é conhecido como uma categoria, de um controle de árvore. Use o método [CMFCPropertySheet:: AddTreeCategory](#addtreecategory) para adicionar um nó a um controle de árvore.

##  <a name="removepage"></a>CMFCPropertySheet:: RemovePage

Remove uma página de propriedades da folha de propriedades.

```
void RemovePage(CPropertyPage* pPage);
void RemovePage(int nPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
no Ponteiro para objeto da página de propriedades que representa a página de propriedades a ser removida. Não pode ser NULL.

*nPage*<br/>
no Índice de base zero da página a ser removida.

### <a name="remarks"></a>Comentários

Esse método remove a página de propriedades especificada e destrói sua janela associada. O objeto da página de propriedades que o parâmetro *pPage* especifica não é destruído até que a janela [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md) seja fechada.

##  <a name="seticonslist"></a>CMFCPropertySheet:: setíconeslist

Especifica a lista de imagens que são usadas no controle de navegação do painel do Outlook.

```
BOOL SetIconsList(
    UINT uiImageListResID,
    int cx,
    COLORREF clrTransparent=RGB(255, 0, 255));
void SetIconsList(HIMAGELIST hIcons);
```

### <a name="parameters"></a>Parâmetros

*uiImageListResID*<br/>
no A ID de recurso de uma lista de imagens.

*cx*<br/>
no A largura, em pixels, dos ícones na lista de imagens.

*clrTransparent*<br/>
no A cor da imagem transparente. As partes da imagem que são essa cor serão transparentes. O valor padrão é a cor magenta, RGB (255, 0255).

*hIcons*<br/>
no Um identificador para uma lista de imagens existente.

### <a name="return-value"></a>Valor de retorno

Na primeira sintaxe de sobrecarga de método, TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se a folha de propriedades estiver no estilo do Microsoft Outlook, a estrutura exibirá uma lista de botões de navegação, chamada de controle do painel do Outlook, à esquerda da folha de propriedades. Use este método para definir a lista de imagens a ser usada pelo controle do painel do Outlook.

Para obter mais informações sobre os métodos que dão suporte a esse método, consulte [CImageList:: Create](../../mfc/reference/cimagelist-class.md#create) e [CImageList:: Add](../../mfc/reference/cimagelist-class.md#add). Para obter mais informações sobre como definir o estilo de uma folha de propriedades, consulte [CMFCPropertySheet:: SetLook](#setlook).

##  <a name="setlook"></a>CMFCPropertySheet:: SetLook

Especifica a aparência da folha de propriedades.

```
void SetLook(
    PropSheetLook look,
    int nNavControlWidth=100);
```

### <a name="parameters"></a>Parâmetros

*look*<br/>
no Um dos valores de enumeração que especifica a aparência da folha de propriedades. O estilo padrão para uma folha de propriedades `CMFCPropertySheet::PropSheetLook_Tabs`é. Para obter mais informações, consulte a tabela na seção comentários deste tópico.

*nNavControlWidth*<br/>
no A largura do controle de navegação, em pixels. O valor padrão é 100.

### <a name="remarks"></a>Comentários

Para exibir uma folha de propriedades em um estilo diferente do padrão, chame esse método antes de criar a janela da folha de propriedades.

A tabela a seguir lista os valores de enumeração que podem ser especificados no parâmetro *look* .

|Valor|Descrição|
|-----------|-----------------|
|`CMFCPropertySheet::PropSheetLook_Tabs`|Os Exibe uma guia para cada página de propriedades. As guias são exibidas na parte superior da folha de propriedades e são empilhadas se houver mais guias do que caberão em uma única linha.|
|`CMFCPropertySheet::PropSheetLook_OutlookBar`|Exibe uma lista de botões de navegação, no estilo da barra do Microsoft Outlook, no lado esquerdo da folha de propriedades. Cada botão na lista corresponde a uma página de propriedades. A estrutura exibirá setas de rolagem se houver mais botões do que couber na área visível da lista.|
|`CMFCPropertySheet::PropSheetLook_Tree`|Exibe um controle de árvore no lado esquerdo da folha de propriedades. Cada nó pai ou filho do controle de árvore corresponde a uma página de propriedades. A estrutura exibirá setas de rolagem se houver mais nós do que caberá na área visível do controle de árvore.|
|`CMFCPropertySheet::PropSheetLook_OneNoteTabs`|Exibe uma guia, no estilo do Microsoft OneNote, para cada página de propriedades. A estrutura exibe as guias na parte superior da folha de propriedades e setas de rolagem se houver mais guias do que caberá em uma única linha.|
|`CMFCPropertySheet::PropSheetLook_List`|Exibe uma lista no lado esquerdo da folha de propriedades. Cada item de lista corresponde a uma página de propriedades. A estrutura exibirá setas de rolagem se houver mais itens de lista do que caberá na área visível da lista.|

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)
