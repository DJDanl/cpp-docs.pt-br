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
ms.openlocfilehash: 9b1bb2ce9a957b9cd9f7add983b4da7a228d7a1d
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81750064"
---
# <a name="cmfcpropertysheet-class"></a>Classe CMFCPropertySheet

A `CMFCPropertySheet` classe suporta uma folha de propriedade onde cada página de propriedade é denotada por uma guia de página, um botão de barra de ferramentas, um nó de controle de árvore ou um item da lista.

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
|[CMFCPropertySheet::AddPage](#addpage)|Adiciona uma página à folha de propriedades.|
|[CMFCPropertySheet::AddPageTotree](#addpagetotree)|Adiciona uma nova página de propriedade ao controle de árvores.|
|[CMFCPropertySheet::AddTreeCategory](#addtreecategory)|Adiciona um novo nó ao controle da árvore.|
|[CMFCPropertysheet::Ativarcabeça de página](#enablepageheader)|Reserva espaço no topo de cada página para desenhar um cabeçalho personalizado.|
|[CMFCPropertySheet::GetheaderHeight](#getheaderheight)|Recupera a altura do cabeçalho atual.|
|[CMFCPropertySheet::GetLook](#getlook)|Recupera um valor de enumeração que especifica o aparecimento da folha de propriedade atual.|
|[CMFCPropertySheet::GetNavBarWidth](#getnavbarwidth)|Retenta a largura da barra de navegação em pixels.|
|[CMFCPropertySheet::Gettab](#gettab)|Recupera o objeto de controle de guia interna que suporta o controle atual da folha de propriedades.|
|`CMFCPropertySheet::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCPropertySheet::InitNavigationControl](#initnavigationcontrol)|Inicializa a aparência do controle atual da folha de propriedades.|
|[CMFCPropertySheet::OnActivatePage](#onactivatepage)|Chamado pela estrutura quando uma página de propriedade está ativada.|
|[CMFCPropertysheet::Ondrawpageheader](#ondrawpageheader)|Chamado pela estrutura para desenhar um cabeçalho de página de propriedade personalizado.|
|`CMFCPropertySheet::OnInitDialog`|Lida com a mensagem [WM_INITDIALOG.](/windows/win32/dlgbox/wm-initdialog) (Substitui [cpropertysheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog).)|
|[CMFCPropertySheet::OnRemovetreePage](#onremovetreepage)|Chamado pela estrutura para remover uma página de propriedade de um controle de árvore.|
|`CMFCPropertySheet::PreTranslateMessage`|Traduz mensagens de janela antes de serem enviadas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows. (Substitui `CPropertySheet::PreTranslateMessage`.)|
|[CMFCPropertySheet::RemoveCategory](#removecategory)|Remove um nó do controle da árvore.|
|[CMFCPropertySheet::RemovePage](#removepage)|Remove uma página de propriedade da folha de propriedades.|
|[CMFCPropertySheet::SetIconsList](#seticonslist)|Especifica a lista de imagens usadas no controle de navegação do painel Outlook.|
|[CMFCPropertySheet::SetLook](#setlook)|Especifica a aparência da folha de propriedades.|

## <a name="remarks"></a>Comentários

A `CMFCPropertySheet` classe representa folhas de propriedade, também conhecidas como caixas de diálogo de guias. A `CMFCPropertySheet` classe pode exibir uma página de propriedade de várias maneiras.

Execute as seguintes `CMFCPropertySheet` etapas para usar a classe em seu aplicativo:

1. Obtenha uma classe `CMFCPropertySheet` da classe e nomeie a classe, por exemplo, CMyPropertySheet.

1. Construa um objeto [CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md) para cada página de propriedade.

1. Ligue para o [CMFCPropertySheet::SetLook](#setlook) no construtor CMyPropertySheet. Um parâmetro desse método especifica que as páginas de propriedade devem ser exibidas como guias ao longo da parte superior ou esquerda da folha de propriedades; guias no estilo de uma planilha de propriedade do Microsoft OneNote; botões em um controle da barra de ferramentas do Microsoft Outlook; nós em um controle de árvore; ou como uma lista de itens no lado esquerdo da folha de propriedades.

1. Se você criar uma folha de propriedade no estilo de uma barra de ferramentas do Microsoft Outlook, chame o método [CMFCPropertySheet::SetIconsList](#seticonslist) para associar uma lista de imagens junto com as páginas de propriedade.

1. Ligue para o [método CMFCPropertySheet::AddPage](#addpage) para cada página de propriedade.

1. Crie `CMFCPropertySheet` um controle `DoModal` e chame seu método.

## <a name="illustrations"></a>Ilustrações

A ilustração a seguir mostra uma folha de propriedade que está no estilo de uma barra de ferramentas do Microsoft Outlook incorporada. A barra de ferramentas do Outlook aparece no lado esquerdo da folha de propriedades.

![Controles de cor CMFCPropertySheet](../../mfc/reference/media/cmfcpropertysheet_color.png "Controles de cor CMFCPropertySheet")

A ilustração a seguir mostra uma folha de propriedade que contém um objeto [CMFCPropertyGridCtrl Class.](../../mfc/reference/cmfcpropertygridctrl-class.md) Esse objeto é uma folha de propriedade no estilo de uma folha de propriedade padrão de controles comuns.

![CMFCPropertySheet lista e controles de propriedade](../../mfc/reference/media/cmfcpropertysheet_list.png "CMFCPropertySheet lista e controles de propriedade")

A ilustração a seguir mostra uma folha de propriedade que está no estilo de um controle de árvore.

![Árvore de Propriedades](../../mfc/reference/media/proptree.png "Árvore de Propriedades")

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cpropertysheet](../../mfc/reference/cpropertysheet-class.md)

[Cmfcpropertysheet](../../mfc/reference/cmfcpropertysheet-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxpropertysheet.h

## <a name="cmfcpropertysheetaddpage"></a><a name="addpage"></a>CMFCPropertySheet::AddPage

Adiciona uma página à folha de propriedades.

```cpp
void AddPage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
[em] Ponteiro para um objeto de página. Esse parâmetro não pode ser NULL.

### <a name="remarks"></a>Comentários

Este método adiciona a página de propriedade especificada como a guia mais à direita na folha de propriedades. Portanto, use este método para adicionar páginas na ordem da esquerda para a direita.

Se a folha de propriedades estiver no estilo do Microsoft Outlook, a estrutura exibirá uma lista de botões de navegação à esquerda da folha de propriedades. Depois que este método adiciona uma página de propriedade, ele adiciona um botão correspondente à lista. Para exibir uma página de propriedade, clique no botão correspondente. Para obter mais informações sobre estilos de folhas de propriedades, consulte [CMFCPropertySheet::SetLook](#setlook).

## <a name="cmfcpropertysheetaddpagetotree"></a><a name="addpagetotree"></a>CMFCPropertySheet::AddPageTotree

Adiciona uma nova página de propriedade ao controle de árvores.

```cpp
void AddPageToTree(
    CMFCPropertySheetCategoryInfo* pCategory,
    CMFCPropertyPage* pPage,
    int nIconNum=-1,
    int nSelIconNum=-1);
```

### <a name="parameters"></a>Parâmetros

*Pcategory*<br/>
[em] Ponteiro para um nó de árvore-pai ou NULL para associar a página especificada com o nó de nível superior. Ligue para o [método CMFCPropertySheet::AddTreeCategory](#addtreecategory) para obter este ponteiro.

*pPage*<br/>
[em] Ponteiro para um objeto de página de propriedade.

*nIconNum*<br/>
[em] Índice baseado em zero de um ícone, ou -1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página não está selecionada. O valor padrão é -1.

*nSelIconNum*<br/>
[em] Índice baseado em zero de um ícone, ou -1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página é selecionada. O valor padrão é -1.

### <a name="remarks"></a>Comentários

Este método adiciona uma página de propriedade como uma folha de controle de árvore. Para adicionar uma página `CMFCPropertySheet` de propriedade, crie um objeto, chame o método [CMFCPropertySheet::SetLook](#setlook) com o parâmetro *de aparência* definido `CMFCPropertySheet::PropSheetLook_Tree`e use esse método para adicionar a página de propriedade.

## <a name="cmfcpropertysheetaddtreecategory"></a><a name="addtreecategory"></a>CMFCPropertySheet::AddTreeCategory

Adiciona um novo nó ao controle da árvore.

```
CMFCPropertySheetCategoryInfo* AddTreeCategory(
    LPCTSTR lpszLabel,
    int nIconNum=-1,
    int nSelectedIconNum=-1,
    const CMFCPropertySheetCategoryInfo* pParentCategory=NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] O nome do nó.

*nIconNum*<br/>
[em] Índice baseado em zero de um ícone, ou -1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página não está selecionada. O valor padrão é -1.

*nSelectedIconNum*<br/>
[em] Índice baseado em zero de um ícone, ou -1 se nenhum ícone for usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página é selecionada. O valor padrão é -1.

*pParentCategory*<br/>
[em] Ponteiro para um nó de árvore-pai ou NULL para associar a página especificada com o nó de nível superior. Defina este parâmetro com o método [CMFCPropertySheet::AddTreeCategory.](#addtreecategory)

### <a name="return-value"></a>Valor retornado

Um ponteiro para o novo nó no controle da árvore.

### <a name="remarks"></a>Comentários

Use este método para adicionar um novo nó, que também é chamado de categoria, ao controle de árvores. Para adicionar um nó, `CMFCPropertySheet` crie um objeto, chame o método [CMFCPropertySheet::SetLook](#setlook) com o parâmetro *de aparência* definido `CMFCPropertySheet::PropSheetLook_Tree`e use este método para adicionar o nó.

Use o valor de retorno deste método em chamadas subseqüentes para [CMFCPropertySheet::AddPageToTree](#addpagetotree) e [CMFCPropertySheet::AddTreeCategory](#addtreecategory).

## <a name="cmfcpropertysheetcmfcpropertysheet"></a><a name="cmfcpropertysheet"></a>CMFCPropertySheet::CMFCPropertySheet

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
[em] Uma seqüência que contém a legenda da folha de propriedades. Não pode ser NULL.

*nIDCaption*<br/>
[em] Um ID de recurso que contém a legenda da folha de propriedades.

*Pparentwnd*<br/>
[em] Ponteiro para a janela pai da folha de propriedades ou NULL se a janela pai for a janela principal do aplicativo. O valor padrão é NULL.

*iSelectPage*<br/>
[em] O índice baseado em zero da página principal da propriedade. O valor padrão é 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte os parâmetros do [construtor CPropertySheet::CPropertySheet.](../../mfc/reference/cpropertysheet-class.md#cpropertysheet)

## <a name="cmfcpropertysheetenablepageheader"></a><a name="enablepageheader"></a>CMFCPropertysheet::Ativarcabeça de página

Reserva espaço no topo de cada página para desenhar um cabeçalho personalizado.

```cpp
void EnablePageHeader(int nHeaderHeight);
```

### <a name="parameters"></a>Parâmetros

*nHeaderHeight*<br/>
[em] A altura do cabeçalho, em pixels.

### <a name="remarks"></a>Comentários

Para usar o valor do parâmetro *nHeaderHeight* para desenhar um cabeçalho personalizado, anule o método [CMFCPropertySheet::OnDrawPageHeader.](#ondrawpageheader)

## <a name="cmfcpropertysheetgetheaderheight"></a><a name="getheaderheight"></a>CMFCPropertySheet::GetheaderHeight

Recupera a altura do cabeçalho atual.

```
int GetHeaderHeight() const;
```

### <a name="return-value"></a>Valor retornado

A altura do cabeçalho, em pixels.

### <a name="remarks"></a>Comentários

Ligue para o [cmfcPropertySheet::EnablePageHeader](#enablepageheader) method antes de chamar este método.

## <a name="cmfcpropertysheetgetlook"></a><a name="getlook"></a>CMFCPropertySheet::GetLook

Recupera um valor de enumeração que especifica o aparecimento da folha de propriedade atual.

```
PropSheetLook GetLook() const;
```

### <a name="return-value"></a>Valor retornado

Um dos valores de enumeração que especifica o aparecimento da folha de propriedades. Para obter uma lista de valores possíveis, consulte a tabela de enumeração na seção Observações do [CMFCPropertySheet::SetLook](#setlook).

## <a name="cmfcpropertysheetgetnavbarwidth"></a><a name="getnavbarwidth"></a>CMFCPropertySheet::GetNavBarWidth

Obtém a largura da barra de navegação.

```
int GetNavBarWidth() const;
```

### <a name="return-value"></a>Valor retornado

A largura da barra de navegação em pixels.

## <a name="cmfcpropertysheetgettab"></a><a name="gettab"></a>CMFCPropertySheet::Gettab

Recupera o objeto de controle de guia interna que suporta o controle atual da folha de propriedades.

```
CMFCTabCtrl& GetTab() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto de controle de guia interno.

### <a name="remarks"></a>Comentários

Você pode definir uma folha de propriedade para que ela apareça em diferentes estilos, como um controle de árvore, uma lista de botões de navegação ou um conjunto de páginas com guias.

Antes de chamar esse método, chame o método [CMFCPropertySheet::SetLook](#setlook) para definir a aparência do controle da folha de propriedades. Em seguida, chame o método [CMFCPropertySheet::InitNavigationControl](#initnavigationcontrol) para inicializar o objeto de controle de guia saem. Use este método para recuperar o objeto de controle de guiae, em seguida, use esse objeto para trabalhar com as guias na folha de propriedades.

Este método afirma no modo de depuração se o controle da folha de propriedades não estiver definido para aparecer no estilo do Microsoft OneNote.

## <a name="cmfcpropertysheetinitnavigationcontrol"></a><a name="initnavigationcontrol"></a>CMFCPropertySheet::InitNavigationControl

Inicializa a aparência do controle atual da folha de propriedades.

```
virtual CWnd* InitNavigationControl();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela do controle da folha de propriedades.

### <a name="remarks"></a>Comentários

Um controle de folha de propriedade pode aparecer em várias formas diferentes, como um conjunto de páginas com guias, um controle de árvore ou uma lista de botões de navegação. Use o método [CMFCPropertySheet::SetLook](#setlook) para especificar a aparência do controle da folha de propriedades.

## <a name="cmfcpropertysheetonactivatepage"></a><a name="onactivatepage"></a>CMFCPropertySheet::OnActivatePage

Chamado pela estrutura quando uma página de propriedade está ativada.

```
virtual void OnActivatePage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
[em] Ponteiro para um objeto de página de propriedade que representa a página de propriedade ativada.

### <a name="remarks"></a>Comentários

Por padrão, este método garante que a página de propriedade habilitada seja rolada para exibição. Se o estilo da folha de propriedade atual contiver um painel do Microsoft Outlook, este método definirá o botão outlook correspondente para o estado verificado.

## <a name="cmfcpropertysheetondrawpageheader"></a><a name="ondrawpageheader"></a>CMFCPropertysheet::Ondrawpageheader

Chamado pela estrutura para desenhar o cabeçalho para uma página de propriedade personalizada.

```
virtual void OnDrawPageHeader(
    CDC* pDC,
    int nPage,
    CRect rectHeader);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para um contexto de dispositivo.

*Npage*<br/>
[em] O número da página de propriedade baseada em zero.

*rectHeader*<br/>
[em] Um retângulo delimitador que especifica onde desenhar o cabeçalho.

### <a name="remarks"></a>Comentários

Por padrão, este método não faz nada. Se você substituir este método, chame o método [CMFCPropertySheet::EnablePageHeader](#enablepageheader) antes que a estrutura chame esse método.

## <a name="cmfcpropertysheetonremovetreepage"></a><a name="onremovetreepage"></a>CMFCPropertySheet::OnRemovetreePage

Chamado pela estrutura para remover uma página de propriedade de um controle de árvore.

```
virtual BOOL OnRemoveTreePage(CPropertyPage* pPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
[em] Ponteiro para um objeto de página de propriedade que representa a página de propriedade a ser removida.

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

## <a name="cmfcpropertysheetremovecategory"></a><a name="removecategory"></a>CMFCPropertySheet::RemoveCategory

Remove um nó do controle da árvore.

```cpp
void RemoveCategory(CMFCPropertySheetCategoryInfo* pCategory);
```

### <a name="parameters"></a>Parâmetros

*Pcategory*<br/>
[em] Ponteiro para uma categoria (nó) para remover.

### <a name="remarks"></a>Comentários

Use este método para remover um nó, que também é referido como uma categoria, de um controle de árvore. Use o método [CMFCPropertySheet::AddTreeCategory](#addtreecategory) para adicionar um nó a um controle de árvore.

## <a name="cmfcpropertysheetremovepage"></a><a name="removepage"></a>CMFCPropertySheet::RemovePage

Remove uma página de propriedade da folha de propriedades.

```cpp
void RemovePage(CPropertyPage* pPage);
void RemovePage(int nPage);
```

### <a name="parameters"></a>Parâmetros

*pPage*<br/>
[em] Pointer to property page object that represents the property page to remove. Não pode ser NULL.

*Npage*<br/>
[em] Índice baseado em zero da página para remover.

### <a name="remarks"></a>Comentários

Este método remove a página de propriedade especificada e destrói sua janela associada. O objeto de página de propriedade que o parâmetro *pPage* especifica não é destruído até que a janela [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md) seja fechada.

## <a name="cmfcpropertysheetseticonslist"></a><a name="seticonslist"></a>CMFCPropertySheet::SetIconsList

Especifica a lista de imagens usadas no controle de navegação do painel Outlook.

```
BOOL SetIconsList(
    UINT uiImageListResID,
    int cx,
    COLORREF clrTransparent=RGB(255, 0, 255));
void SetIconsList(HIMAGELIST hIcons);
```

### <a name="parameters"></a>Parâmetros

*uiImageListResID*<br/>
[em] O ID de recurso de uma lista de imagens.

*Cx*<br/>
[em] A largura, em pixels, de ícones na lista de imagens.

*clrTransparent*<br/>
[em] A cor da imagem transparente. As partes da imagem que são dessa cor serão transparentes. O valor padrão é o magenta de cor, RGB (255,0,255).

*hIcons*<br/>
[em] Uma alça para uma lista de imagens existente.

### <a name="return-value"></a>Valor retornado

Na sintaxe de sobrecarga do primeiro método, TRUE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se a folha de propriedades estiver no estilo do Microsoft Outlook, a estrutura exibirá uma lista de botões de navegação, chamado de controle de painel do Outlook, à esquerda da folha de propriedades. Use este método para definir a lista de imagens a ser usada pelo controle do painel outlook.

Para obter mais informações sobre os métodos que suportam esse método, consulte [CImageList::Create](../../mfc/reference/cimagelist-class.md#create) e [CImageList::Add](../../mfc/reference/cimagelist-class.md#add). Para obter mais informações sobre como definir o estilo de uma folha de propriedades, consulte [CMFCPropertySheet::SetLook](#setlook).

## <a name="cmfcpropertysheetsetlook"></a><a name="setlook"></a>CMFCPropertySheet::SetLook

Especifica a aparência da folha de propriedades.

```cpp
void SetLook(
    PropSheetLook look,
    int nNavControlWidth=100);
```

### <a name="parameters"></a>Parâmetros

*Olhar*<br/>
[em] Um dos valores de enumeração que especifica o aparecimento da folha de propriedades. O estilo padrão de `CMFCPropertySheet::PropSheetLook_Tabs`uma folha de propriedade é . Para obter mais informações, consulte a tabela na seção Observações deste tópico.

*nNavControlWidth*<br/>
[em] A largura do controle de navegação, em pixels. O valor padrão é 100.

### <a name="remarks"></a>Comentários

Para exibir uma folha de propriedade em um estilo diferente do padrão, chame este método antes de criar a janela da folha de propriedades.

A tabela a seguir lista os valores de enumeração que podem ser especificados no parâmetro *look.*

|Valor|Descrição|
|-----------|-----------------|
|`CMFCPropertySheet::PropSheetLook_Tabs`|(Padrão) Exibe uma guia para cada página de propriedade. As guias são exibidas na parte superior da folha de propriedades e são empilhadas se houver mais abas do que caberão em uma única linha.|
|`CMFCPropertySheet::PropSheetLook_OutlookBar`|Exibe uma lista de botões de navegação, no estilo da barra do Microsoft Outlook, no lado esquerdo da folha de propriedades. Cada botão da lista corresponde a uma página de propriedade. A estrutura exibe setas de rolagem se houver mais botões do que caberá na área visível da lista.|
|`CMFCPropertySheet::PropSheetLook_Tree`|Exibe um controle de árvore no lado esquerdo da folha de propriedades. Cada nó pai ou filho do controle de árvores corresponde a uma página de propriedade. A estrutura exibe setas de rolagem se houver mais nós do que caberá na área visível do controle da árvore.|
|`CMFCPropertySheet::PropSheetLook_OneNoteTabs`|Exibe uma guia, no estilo do Microsoft OneNote, para cada página de propriedade. A estrutura exibe guias na parte superior da folha de propriedades e setas de rolagem se houver mais abas do que caberão em uma única linha.|
|`CMFCPropertySheet::PropSheetLook_List`|Exibe uma lista no lado esquerdo da folha de propriedades. Cada item da lista corresponde a uma página de propriedade. A estrutura exibe setas de rolagem se houver mais itens da lista do que caberá na área visível da lista.|

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)<br/>
[Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)
