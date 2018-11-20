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
ms.openlocfilehash: 1168375606ef86061269454aa361a076efa331a4
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52176400"
---
# <a name="cmfcpropertysheet-class"></a>Classe CMFCPropertySheet

O `CMFCPropertySheet` classe dá suporte a uma folha de propriedades em que cada página de propriedades é indicada por uma guia de página, um botão de barra de ferramentas, um nó de controle de árvore ou um item de lista.

## <a name="syntax"></a>Sintaxe

```
class CMFCPropertySheet : public CPropertySheet
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertySheet::CMFCPropertySheet](#cmfcpropertysheet)|Constrói um objeto `CMFCPropertySheet`.|
|`CMFCPropertySheet::~CMFCPropertySheet`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCPropertySheet::AddPage](#addpage)|Adiciona uma página para a folha de propriedades.|
|[CMFCPropertySheet::AddPageToTree](#addpagetotree)|Adiciona uma nova página de propriedade ao controle de árvore.|
|[CMFCPropertySheet::AddTreeCategory](#addtreecategory)|Adiciona um novo nó ao controle de árvore.|
|[CMFCPropertySheet::EnablePageHeader](#enablepageheader)|Reserva espaço na parte superior de cada página para desenhar um cabeçalho personalizado.|
|[CMFCPropertySheet::GetHeaderHeight](#getheaderheight)|Recupera a altura do cabeçalho atual.|
|[CMFCPropertySheet::GetLook](#getlook)|Recupera um valor de enumeração que especifica a aparência da folha de propriedades atual.|
|[CMFCPropertySheet::GetNavBarWidth](#getnavbarwidth)|Repete a largura da barra de navegação, em pixels.|
|[CMFCPropertySheet::GetTab](#gettab)|Recupera o objeto de controle de guia interna que suporta o controle de planilha de propriedade atuais.|
|`CMFCPropertySheet::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCPropertySheet::InitNavigationControl](#initnavigationcontrol)|Inicializa a aparência do controle de planilha de propriedade atual.|
|[CMFCPropertySheet::OnActivatePage](#onactivatepage)|Chamado pelo framework quando uma página de propriedades está habilitada.|
|[CMFCPropertySheet::OnDrawPageHeader](#ondrawpageheader)|Chamado pelo framework para desenhar um cabeçalho de página de propriedade personalizada.|
|`CMFCPropertySheet::OnInitDialog`|Manipula o [WM_INITDIALOG](/windows/desktop/dlgbox/wm-initdialog) mensagem. (Substitui [CPropertySheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog).)|
|[CMFCPropertySheet::OnRemoveTreePage](#onremovetreepage)|Chamado pelo framework para remover uma página de propriedades de um controle de árvore.|
|`CMFCPropertySheet::PreTranslateMessage`|Converte as mensagens da janela antes de serem expedidas para o [TranslateMessage](/windows/desktop/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/desktop/api/winuser/nf-winuser-dispatchmessage) funções do Windows. (Substitui `CPropertySheet::PreTranslateMessage`.)|
|[CMFCPropertySheet::RemoveCategory](#removecategory)|Remove um nó de controle de árvore.|
|[CMFCPropertySheet::RemovePage](#removepage)|Remove uma página de propriedades da folha de propriedades.|
|[CMFCPropertySheet::SetIconsList](#seticonslist)|Especifica a lista de imagens que são usados no controle de navegação do painel de tarefas do Outlook.|
|[CMFCPropertySheet::SetLook](#setlook)|Especifica a aparência da folha de propriedades.|

## <a name="remarks"></a>Comentários

O `CMFCPropertySheet` classe representa as folhas de propriedades, também conhecido como caixas de diálogo de guia. O `CMFCPropertySheet` classe pode exibir uma página de propriedades em uma variedade de formas.

Execute as seguintes etapas para usar o `CMFCPropertySheet` classe em seu aplicativo:

1. Derive uma classe do `CMFCPropertySheet` de classe e nomeie a classe, por exemplo, CMyPropertySheet.

1. Construir uma [CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md) objeto para cada página de propriedades.

1. Chame o [CMFCPropertySheet::SetLook](#setlook) método no construtor CMyPropertySheet. Um parâmetro do método Especifica que páginas de propriedades deverão ser exibidas como guias na parte superior ou esquerda da folha de propriedades; guias no estilo de uma folha de propriedades do Microsoft OneNote; botões em um controle de barra de ferramentas do Microsoft Outlook; nós em um controle de árvore; ou como uma lista de itens no lado esquerdo da folha de propriedades.

1. Se você criar uma folha de propriedades no estilo de uma barra de ferramentas do Microsoft Outlook, chame o [CMFCPropertySheet::SetIconsList](#seticonslist) método a ser associado a uma lista de imagens junto com as páginas de propriedades.

1. Chame o [CMFCPropertySheet::AddPage](#addpage) método para cada página de propriedades.

1. Criar uma `CMFCPropertySheet` controlar e chamar seu `DoModal` método.

## <a name="illustrations"></a>Ilustrações

A ilustração a seguir ilustra uma folha de propriedades está no estilo de uma barra de ferramentas do Microsoft Outlook incorporado. A barra de ferramentas do Outlook aparece no lado esquerdo da folha de propriedades.

![Controles de cor CMFCPropertySheet](../../mfc/reference/media/cmfcpropertysheet_color.png "CMFCPropertySheet controles de cor")

A ilustração a seguir mostra uma folha de propriedades que contém um [classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) objeto. Esse objeto é uma folha de propriedades no estilo de uma folha de propriedades de controles comuns padrão.

![Controles de lista e a propriedade CMFCPropertySheet](../../mfc/reference/media/cmfcpropertysheet_list.png "controles de lista e a propriedade CMFCPropertySheet")

A ilustração a seguir ilustra uma folha de propriedades está no estilo de um controle de árvore.

![Propriedade árvore](../../mfc/reference/media/proptree.png "árvore de propriedade")

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CPropertySheet](../../mfc/reference/cpropertysheet-class.md)

[CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertysheet.h

##  <a name="addpage"></a>  CMFCPropertySheet::AddPage

Adiciona uma página para a folha de propriedades.

```
void AddPage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*Página*<br/>
[in] Ponteiro para um objeto de página. Esse parâmetro não pode ser NULL.

### <a name="remarks"></a>Comentários

Esse método adiciona a página de propriedade especificada como a guia mais à direita na folha de propriedades. Portanto, use esse método para adicionar páginas em ordem da esquerda para a direita.

Se a folha de propriedades está no estilo do Microsoft Outlook, o framework exibe uma lista de botões de navegação à esquerda da folha de propriedades. Depois que esse método adiciona uma página de propriedades, ele adiciona um botão correspondente à lista. Para exibir uma página de propriedades, clique no botão correspondente. Para obter mais informações sobre estilos de folhas de propriedades, consulte [CMFCPropertySheet::SetLook](#setlook).

##  <a name="addpagetotree"></a>  CMFCPropertySheet::AddPageToTree

Adiciona uma nova página de propriedade ao controle de árvore.

```
void AddPageToTree(
    CMFCPropertySheetCategoryInfo* pCategory,
    CMFCPropertyPage* pPage,
    int nIconNum=-1,
    int nSelIconNum=-1);
```

### <a name="parameters"></a>Parâmetros

*pCategory*<br/>
[in] Ponteiro para um nó de árvore pai ou nulo para associar a página especificada com o nó de nível superior. Chame o [CMFCPropertySheet::AddTreeCategory](#addtreecategory) método para obter esse ponteiro.

*Página*<br/>
[in] Ponteiro para um objeto de página de propriedade.

*nIconNum*<br/>
[in] Índice baseado em zero de um ícone ou -1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página não estiver selecionada. O valor padrão é -1.

*nSelIconNum*<br/>
[in] Índice baseado em zero de um ícone ou -1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página está selecionada. O valor padrão é -1.

### <a name="remarks"></a>Comentários

Esse método adiciona uma página de propriedades como uma folha de um controle de árvore. Para adicionar uma página de propriedades, crie uma `CMFCPropertySheet` do objeto, chame o [CMFCPropertySheet::SetLook](#setlook) método com o *parecer* parâmetro definido como `CMFCPropertySheet::PropSheetLook_Tree`e, em seguida, usar esse método para adicionar a página de propriedade .

##  <a name="addtreecategory"></a>  CMFCPropertySheet::AddTreeCategory

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
[in] O nome do nó.

*nIconNum*<br/>
[in] Índice baseado em zero de um ícone ou -1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página não estiver selecionada. O valor padrão é -1.

*nSelectedIconNum*<br/>
[in] Índice baseado em zero de um ícone ou -1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página está selecionada. O valor padrão é -1.

*pParentCategory*<br/>
[in] Ponteiro para um nó de árvore pai ou nulo para associar a página especificada com o nó de nível superior. Defina esse parâmetro com o [CMFCPropertySheet::AddTreeCategory](#addtreecategory) método.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o novo nó no controle de árvore.

### <a name="remarks"></a>Comentários

Use esse método para adicionar um novo nó, que também é conhecido como uma categoria, para o controle de árvore. Para adicionar um nó, crie uma `CMFCPropertySheet` do objeto, chame o [CMFCPropertySheet::SetLook](#setlook) método com o *parecer* parâmetro definido como `CMFCPropertySheet::PropSheetLook_Tree`e, em seguida, usar esse método para adicionar o nó.

Use o valor de retorno desse método nas chamadas subsequentes para [CMFCPropertySheet::AddPageToTree](#addpagetotree) e [CMFCPropertySheet::AddTreeCategory](#addtreecategory).

##  <a name="cmfcpropertysheet"></a>  CMFCPropertySheet::CMFCPropertySheet

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
[in] Uma cadeia de caracteres que contém a legenda da folha de propriedade. Não pode ser NULL.

*nIDCaption*<br/>
[in] Uma ID de recurso que contém a legenda da folha de propriedade.

*pParentWnd*<br/>
[in] Ponteiro para a janela pai da folha de propriedades, ou nulo se a janela pai é a janela principal do aplicativo. O valor padrão é NULL.

*iSelectPage*<br/>
[in] O índice baseado em zero da página de propriedades principais. O valor padrão é 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte os parâmetros para o [CPropertySheet::CPropertySheet](../../mfc/reference/cpropertysheet-class.md#cpropertysheet) construtor.

##  <a name="enablepageheader"></a>  CMFCPropertySheet::EnablePageHeader

Reserva espaço na parte superior de cada página para desenhar um cabeçalho personalizado.

```
void EnablePageHeader(int nHeaderHeight);
```

### <a name="parameters"></a>Parâmetros

*nHeaderHeight*<br/>
[in] A altura do cabeçalho, em pixels.

### <a name="remarks"></a>Comentários

Para usar o valor da *nHeaderHeight* substituição de parâmetro para desenhar um cabeçalho personalizado, o [CMFCPropertySheet::OnDrawPageHeader](#ondrawpageheader) método.

##  <a name="getheaderheight"></a>  CMFCPropertySheet::GetHeaderHeight

Recupera a altura do cabeçalho atual.

```
int GetHeaderHeight() const;
```

### <a name="return-value"></a>Valor de retorno

A altura do cabeçalho, em pixels.

### <a name="remarks"></a>Comentários

Chame o [CMFCPropertySheet::EnablePageHeader](#enablepageheader) método antes de chamar esse método.

##  <a name="getlook"></a>  CMFCPropertySheet::GetLook

Recupera um valor de enumeração que especifica a aparência da folha de propriedades atual.

```
PropSheetLook GetLook() const;
```

### <a name="return-value"></a>Valor de retorno

Um dos valores de enumeração que especifica a aparência da folha de propriedades. Para obter uma lista de valores possíveis, consulte a tabela de enumeração na seção de comentários [CMFCPropertySheet::SetLook](#setlook).

##  <a name="getnavbarwidth"></a>  CMFCPropertySheet::GetNavBarWidth

Obtém a largura da barra de navegação.

```
int GetNavBarWidth() const;
```

### <a name="return-value"></a>Valor de retorno

A largura da barra de navegação, em pixels.

##  <a name="gettab"></a>  CMFCPropertySheet::GetTab

Recupera o objeto de controle de guia interna que suporta o controle de planilha de propriedade atuais.

```
CMFCTabCtrl& GetTab() const;
```

### <a name="return-value"></a>Valor de retorno

Um objeto de controle de guia interna.

### <a name="remarks"></a>Comentários

Você pode definir uma folha de propriedades para que ele apareça em estilos diferentes, como um controle de árvore, uma lista de botões de navegação ou um conjunto de páginas com guias.

Antes de chamar esse método, chame o [CMFCPropertySheet::SetLook](#setlook) método para definir a aparência do controle de folha de propriedades. Em seguida, chame o [CMFCPropertySheet::InitNavigationControl](#initnavigationcontrol) método para inicializar o objeto de controle de guia interna. Use esse método para recuperar o objeto de controle de guia e, em seguida, usar esse objeto para trabalhar com as guias na folha de propriedades.

Esse método declara no modo de depuração, se o controle de planilha de propriedade não está definido como aparecem no estilo do Microsoft OneNote.

##  <a name="initnavigationcontrol"></a>  CMFCPropertySheet::InitNavigationControl

Inicializa a aparência do controle de planilha de propriedade atual.

```
virtual CWnd* InitNavigationControl();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela de controle de folha de propriedades.

### <a name="remarks"></a>Comentários

Um controle de planilha de propriedade pode aparecer em várias formas diferentes, como um conjunto de páginas com guias, um controle de árvore ou uma lista de botões de navegação. Use o [CMFCPropertySheet::SetLook](#setlook) método para especificar a aparência do controle de folha de propriedades.

##  <a name="onactivatepage"></a>  CMFCPropertySheet::OnActivatePage

Chamado pelo framework quando uma página de propriedades está habilitada.

```
virtual void OnActivatePage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*Página*<br/>
[in] Ponteiro para um objeto de página de propriedade que representa a página de propriedade enabled.

### <a name="remarks"></a>Comentários

Por padrão, esse método garante que a página de propriedade enabled é colocada na exibição. Se o estilo da folha de propriedades atual contiver um painel do Microsoft Outlook, esse método define o botão correspondente do Outlook para o estado de ativação.

##  <a name="ondrawpageheader"></a>  CMFCPropertySheet::OnDrawPageHeader

Chamado pelo framework para desenhar o cabeçalho de uma página de propriedade personalizada.

```
virtual void OnDrawPageHeader(
    CDC* pDC,
    int nPage,
    CRect rectHeader);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Ponteiro para um contexto de dispositivo.

*nPage*<br/>
[in] O número de página de propriedade com base em zero.

*rectHeader*<br/>
[in] Um retângulo delimitador que especifica o local desenhar o cabeçalho.

### <a name="remarks"></a>Comentários

Por padrão, esse método não fará nada. Se você substituir esse método, chame o [CMFCPropertySheet::EnablePageHeader](#enablepageheader) método antes que a estrutura chama esse método.

##  <a name="onremovetreepage"></a>  CMFCPropertySheet::OnRemoveTreePage

Chamado pelo framework para remover uma página de propriedades de um controle de árvore.

```
virtual BOOL OnRemoveTreePage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*Página*<br/>
[in] Ponteiro para um objeto de página de propriedade que representa a página de propriedade a ser removido.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

##  <a name="removecategory"></a>  CMFCPropertySheet::RemoveCategory

Remove um nó de controle de árvore.

```
void RemoveCategory(CMFCPropertySheetCategoryInfo* pCategory);
```

### <a name="parameters"></a>Parâmetros

*pCategory*<br/>
[in] Ponteiro para uma categoria (nó) a ser removido.

### <a name="remarks"></a>Comentários

Use esse método para remover um nó, que também é conhecido como uma categoria de um controle de árvore. Use o [CMFCPropertySheet::AddTreeCategory](#addtreecategory) método para adicionar um nó a um controle de árvore.

##  <a name="removepage"></a>  CMFCPropertySheet::RemovePage

Remove uma página de propriedades da folha de propriedades.

```
void RemovePage(CPropertyPage* pPage);
void RemovePage(int nPage);
```

### <a name="parameters"></a>Parâmetros

*Página*<br/>
[in] Ponteiro para objeto de página de propriedade que representa a página de propriedade a ser removido. Não pode ser NULL.

*nPage*<br/>
[in] Índice baseado em zero da página a ser removido.

### <a name="remarks"></a>Comentários

Esse método remove a página de propriedade especificada e destrói sua janela associada. A página de propriedades do objeto que o *página* parâmetro especifica não será destruído até que o [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md) janela é fechada.

##  <a name="seticonslist"></a>  CMFCPropertySheet::SetIconsList

Especifica a lista de imagens que são usados no controle de navegação do painel de tarefas do Outlook.

```
BOOL SetIconsList(
    UINT uiImageListResID,
    int cx,
    COLORREF clrTransparent=RGB(255, 0, 255));
void SetIconsList(HIMAGELIST hIcons);
```

### <a name="parameters"></a>Parâmetros

*uiImageListResID*<br/>
[in] A ID de recurso de uma lista de imagens.

*CX*<br/>
[in] A largura, em pixels, dos ícones na lista de imagens.

*clrTransparent*<br/>
[in] A cor da imagem transparente. As partes da imagem que têm essa cor será transparentes. O valor padrão é a cor magenta RGB(255,0,255).

*hIcons*<br/>
[in] Um identificador para uma lista de imagens existente.

### <a name="return-value"></a>Valor de retorno

No primeiro método de sobrecarga sintaxe, TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se a folha de propriedades está no estilo do Microsoft Outlook, o framework exibe uma lista de botões de navegação, chamado de controle de painel do Outlook, à esquerda da folha de propriedades. Use esse método para definir a lista de imagens a ser usado pelo controle de painel do Outlook.

Para obter mais informações sobre os métodos que oferecem suporte a esse método, consulte [CImageList::Create](../../mfc/reference/cimagelist-class.md#create) e [CImageList::Add](../../mfc/reference/cimagelist-class.md#add). Para obter mais informações sobre como definir o estilo de uma folha de propriedades, consulte [CMFCPropertySheet::SetLook](#setlook).

##  <a name="setlook"></a>  CMFCPropertySheet::SetLook

Especifica a aparência da folha de propriedades.

```
void SetLook(
    PropSheetLook look,
    int nNavControlWidth=100);
```

### <a name="parameters"></a>Parâmetros

*aparência*<br/>
[in] Um dos valores de enumeração que especifica a aparência da folha de propriedades. O estilo padrão para uma folha de propriedades é `CMFCPropertySheet::PropSheetLook_Tabs`. Para obter mais informações, consulte a tabela na seção Comentários deste tópico.

*nNavControlWidth*<br/>
[in] A largura do controle de navegação, em pixels. O valor padrão é 100.

### <a name="remarks"></a>Comentários

Para exibir uma folha de propriedades em um estilo diferente do padrão, chame esse método antes de criar a janela de folha de propriedades.

A tabela a seguir lista os valores de enumeração que podem ser especificados na *parecer* parâmetro.

|Valor|Descrição|
|-----------|-----------------|
|`CMFCPropertySheet::PropSheetLook_Tabs`|(Padrão) Exibe uma guia para cada página de propriedades. As guias são exibidas na parte superior da folha de propriedades e são empilhadas se houver mais guias cabem em uma única linha.|
|`CMFCPropertySheet::PropSheetLook_OutlookBar`|Exibe uma lista de botões de navegação no estilo da barra do Outlook do Microsoft, no lado esquerdo da folha de propriedades. Cada botão na lista corresponde a uma página de propriedades. A estrutura exibe setas de rolagem, se houver mais botões que cabem na área visível da lista.|
|`CMFCPropertySheet::PropSheetLook_Tree`|Exibe um controle de árvore no lado esquerdo da folha de propriedades. Cada nó pai ou filho do controle de árvore corresponde a uma página de propriedades. O framework exibe setas de rolagem, se houver mais nós que cabem na área visível do controle de árvore.|
|`CMFCPropertySheet::PropSheetLook_OneNoteTabs`|Exibe uma guia, no estilo do Microsoft OneNote para cada página de propriedades. O framework exibe as guias na parte superior da folha de propriedades e setas de rolagem se há mais guias que serão ajustadas em uma única linha.|
|`CMFCPropertySheet::PropSheetLook_List`|Exibe uma lista no lado esquerdo da folha de propriedades. Cada item da lista corresponde a uma página de propriedades. O framework exibe setas de rolagem, se houver mais itens de lista cabem na área visível da lista.|

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)
