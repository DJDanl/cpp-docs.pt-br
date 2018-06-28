---
title: Classe CMFCPropertySheet | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 53ec20a6fb45efc3848381d165256a429b80a386
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37040006"
---
# <a name="cmfcpropertysheet-class"></a>Classe CMFCPropertySheet
O `CMFCPropertySheet` classe oferece suporte a uma folha de propriedades, onde cada página de propriedades é indicada por uma guia de página, um botão de barra de ferramentas, um nó de controle de árvore ou um item de lista.  
  
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
|[CMFCPropertySheet::AddPage](#addpage)|Adiciona uma página de folha de propriedades.|  
|[CMFCPropertySheet::AddPageToTree](#addpagetotree)|Adiciona uma nova página de propriedade para o controle de árvore.|  
|[CMFCPropertySheet::AddTreeCategory](#addtreecategory)|Adiciona um novo nó para o controle de árvore.|  
|[CMFCPropertySheet::EnablePageHeader](#enablepageheader)|Reserva espaço na parte superior de cada página para desenhar um cabeçalho personalizado.|  
|[CMFCPropertySheet::GetHeaderHeight](#getheaderheight)|Recupera a altura do cabeçalho da atual.|  
|[CMFCPropertySheet::GetLook](#getlook)|Recupera um valor de enumeração que especifica a aparência da folha de propriedades atual.|  
|[CMFCPropertySheet::GetNavBarWidth](#getnavbarwidth)|Repete a largura da barra de navegação, em pixels.|  
|[CMFCPropertySheet::GetTab](#gettab)|Recupera o objeto de controle de guia interno que ofereça suporte o controle de folha de propriedades atual.|  
|`CMFCPropertySheet::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCPropertySheet::InitNavigationControl](#initnavigationcontrol)|Inicializa a aparência do controle de folha de propriedade atual.|  
|[CMFCPropertySheet::OnActivatePage](#onactivatepage)|Chamado pelo framework quando uma página de propriedades está habilitada.|  
|[CMFCPropertySheet::OnDrawPageHeader](#ondrawpageheader)|Chamado pelo framework para desenhar um cabeçalho de página de propriedade personalizada.|  
|`CMFCPropertySheet::OnInitDialog`|Manipula o [WM_INITDIALOG](http://msdn.microsoft.com/library/windows/desktop/ms645428) mensagem. (Substitui [CPropertySheet::OnInitDialog](../../mfc/reference/cpropertysheet-class.md#oninitdialog).)|  
|[CMFCPropertySheet::OnRemoveTreePage](#onremovetreepage)|Chamado pelo framework para remover uma página de propriedades de um controle de árvore.|  
|`CMFCPropertySheet::PreTranslateMessage`|Converte as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows. (Substitui `CPropertySheet::PreTranslateMessage`.)|  
|[CMFCPropertySheet::RemoveCategory](#removecategory)|Remove um nó de controle de árvore.|  
|[CMFCPropertySheet::RemovePage](#removepage)|Remove uma página de propriedades da folha de propriedades.|  
|[CMFCPropertySheet::SetIconsList](#seticonslist)|Especifica a lista de imagens que são usados no controle de navegação do painel do Outlook.|  
|[CMFCPropertySheet::SetLook](#setlook)|Especifica a aparência da folha de propriedades.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCPropertySheet` classe representa folhas de propriedades, também conhecido como caixas de diálogo de guia. O `CMFCPropertySheet` classe pode exibir uma página de propriedades de várias maneiras.  
  
 Execute as seguintes etapas para usar o `CMFCPropertySheet` em seu aplicativo:  
  
1.  Derivar uma classe a partir de `CMFCPropertySheet` classe e o nome da classe, por exemplo, CMyPropertySheet.  
  
2.  Construir um [CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md) objeto para cada página de propriedades.  
  
3.  Chamar o [CMFCPropertySheet::SetLook](#setlook) método no construtor CMyPropertySheet. Um parâmetro do método Especifica que as páginas de propriedade devem ser exibidas como guias na parte superior ou esquerda da folha de propriedades; guias no estilo de uma folha de propriedades do OneNote do Microsoft; botões em um controle de barra de ferramentas do Microsoft Outlook; nós em um controle de árvore; ou como uma lista de itens no lado esquerdo da folha de propriedades.  
  
4.  Se você criar uma folha de propriedades no estilo de uma barra de ferramentas do Microsoft Outlook, chame o [CMFCPropertySheet::SetIconsList](#seticonslist) método para associar uma lista de imagens junto com as páginas de propriedades.  
  
5.  Chamar o [CMFCPropertySheet::AddPage](#addpage) método para cada página de propriedades.  
  
6.  Criar um `CMFCPropertySheet` controlar e chame seu `DoModal` método.  
  
## <a name="illustrations"></a>Ilustrações  
 A ilustração a seguir ilustra uma folha de propriedades está no estilo de uma barra de ferramentas do Microsoft Outlook incorporado. A barra de ferramentas do Outlook aparece no lado esquerdo da folha de propriedades.  
  
 ![Controles de cor CMFCPropertySheet](../../mfc/reference/media/cmfcpropertysheet_color.png "cmfcpropertysheet_color")  
  
 A ilustração a seguir mostra uma folha de propriedades que contém um [CMFCPropertyGridCtrl classe](../../mfc/reference/cmfcpropertygridctrl-class.md) objeto. Esse objeto é uma folha de propriedades no estilo de uma folha de propriedades de controles comuns padrão.  
  
 ![Controles de lista e propriedade CMFCPropertySheet](../../mfc/reference/media/cmfcpropertysheet_list.png "cmfcpropertysheet_list")  
  
 A ilustração a seguir ilustra uma folha de propriedades está no estilo de um controle de árvore.  
  
 ![Árvore de propriedades](../../mfc/reference/media/proptree.png "proptree")  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CPropertySheet](../../mfc/reference/cpropertysheet-class.md)  
  
 [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpropertysheet.h  
  
##  <a name="addpage"></a>  CMFCPropertySheet::AddPage  
 Adiciona uma página de folha de propriedades.  
  
```  
void AddPage(CPropertyPage* pPage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *página*  
 Ponteiro para um objeto de página. O parâmetro não pode ser `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Este método adiciona a página de propriedade especificada como a guia mais à direita na folha de propriedades. Portanto, use esse método para adicionar páginas da esquerda para direita.  
  
 Se for a folha de propriedades no estilo do Microsoft Outlook, o framework exibe uma lista de botões de navegação à esquerda da folha de propriedades. Depois que este método adiciona uma página de propriedades, ele adiciona um botão correspondente à lista. Para exibir uma página de propriedades, clique no botão correspondente. Para obter mais informações sobre estilos de folhas de propriedades, consulte [CMFCPropertySheet::SetLook](#setlook).  
  
##  <a name="addpagetotree"></a>  CMFCPropertySheet::AddPageToTree  
 Adiciona uma nova página de propriedade para o controle de árvore.  
  
```  
void AddPageToTree(
    CMFCPropertySheetCategoryInfo* pCategory,  
    CMFCPropertyPage* pPage,  
    int nIconNum=-1,  
    int nSelIconNum=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pCategory*  
 Ponteiro para um nó de árvore pai, ou `NULL` para associar a página especificada com o nó de nível superior. Chamar o [CMFCPropertySheet::AddTreeCategory](#addtreecategory) método para obter esse ponteiro.  
  
 [in] *página*  
 Ponteiro para um objeto de página de propriedade.  
  
 [in] *nIconNum*  
 Índice de base zero de um ícone ou -1 se nenhum ícone é usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página não estiver selecionada. O valor padrão é -1.  
  
 [in] *nSelIconNum*  
 Índice de base zero de um ícone ou -1 se nenhum ícone é usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página for selecionada. O valor padrão é -1.  
  
### <a name="remarks"></a>Comentários  
 Este método adiciona uma página de propriedades como uma folha de um controle de árvore. Para adicionar uma página de propriedades, crie um `CMFCPropertySheet` de objeto, chame o [CMFCPropertySheet::SetLook](#setlook) método com o *pesquisar* parâmetro definido como `CMFCPropertySheet::PropSheetLook_Tree`e, em seguida, use esse método para adicionar a página de propriedades .  
  
##  <a name="addtreecategory"></a>  CMFCPropertySheet::AddTreeCategory  
 Adiciona um novo nó para o controle de árvore.  
  
```  
CMFCPropertySheetCategoryInfo* AddTreeCategory(
    LPCTSTR lpszLabel,  
    int nIconNum=-1,  
    int nSelectedIconNum=-1,  
    const CMFCPropertySheetCategoryInfo* pParentCategory=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszLabel*  
 O nome do nó.  
  
 [in] *nIconNum*  
 Índice de base zero de um ícone ou -1 se nenhum ícone é usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página não estiver selecionada. O valor padrão é -1.  
  
 [in] *nSelectedIconNum*  
 Índice de base zero de um ícone ou -1 se nenhum ícone é usado. O ícone é exibido ao lado da página de propriedade de controle de árvore quando a página for selecionada. O valor padrão é -1.  
  
 [in] *pParentCategory*  
 Ponteiro para um nó de árvore pai, ou `NULL` para associar a página especificada com o nó de nível superior. Defina esse parâmetro com o [CMFCPropertySheet::AddTreeCategory](#addtreecategory) método.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o novo nó no controle de árvore.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para adicionar um novo nó, também é conhecido como uma categoria, o controle de árvore. Para adicionar um nó, crie um `CMFCPropertySheet` de objeto, chame o [CMFCPropertySheet::SetLook](#setlook) método com o *pesquisar* parâmetro definido como `CMFCPropertySheet::PropSheetLook_Tree`e, em seguida, use esse método para adicionar o nó.  
  
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
 [in] *pszCaption*  
 Uma cadeia de caracteres que contém a legenda da folha de propriedade. Não pode ser `NULL`.  
  
 [in] *nIDCaption*  
 Uma ID de recurso que contém a legenda da folha de propriedade.  
  
 [in] *pParentWnd*  
 Ponteiro para a janela pai da folha de propriedades, ou `NULL` se a janela pai é a janela principal do aplicativo. O valor padrão é `NULL`.  
  
 [in] *iSelectPage*  
 O índice baseado em zero da página de propriedades principais. O valor padrão é 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte os parâmetros para o [CPropertySheet::CPropertySheet](../../mfc/reference/cpropertysheet-class.md#cpropertysheet) construtor.  
  
##  <a name="enablepageheader"></a>  CMFCPropertySheet::EnablePageHeader  
 Reserva espaço na parte superior de cada página para desenhar um cabeçalho personalizado.  
  
```  
void EnablePageHeader(int nHeaderHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nHeaderHeight*  
 A altura do cabeçalho, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Para usar o valor da *nHeaderHeight* parâmetro para desenhar um cabeçalho personalizado, substitua o [CMFCPropertySheet::OnDrawPageHeader](#ondrawpageheader) método.  
  
##  <a name="getheaderheight"></a>  CMFCPropertySheet::GetHeaderHeight  
 Recupera a altura do cabeçalho da atual.  
  
```  
int GetHeaderHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura do cabeçalho, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Chamar o [CMFCPropertySheet::EnablePageHeader](#enablepageheader) método antes de chamar esse método.  
  
##  <a name="getlook"></a>  CMFCPropertySheet::GetLook  
 Recupera um valor de enumeração que especifica a aparência da folha de propriedades atual.  
  
```  
PropSheetLook GetLook() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores de enumeração que especifica a aparência da folha de propriedades. Para obter uma lista de valores possíveis, consulte a tabela de enumeração na seção comentários de [CMFCPropertySheet::SetLook](#setlook).  
  
##  <a name="getnavbarwidth"></a>  CMFCPropertySheet::GetNavBarWidth  
 Obtém a largura da barra de navegação.  
  
```  
int GetNavBarWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura da barra de navegação, em pixels.  
  
##  <a name="gettab"></a>  CMFCPropertySheet::GetTab  
 Recupera o objeto de controle de guia interno que ofereça suporte o controle de folha de propriedades atual.  
  
```  
CMFCTabCtrl& GetTab() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto de controle de guia interna.  
  
### <a name="remarks"></a>Comentários  
 Você pode definir uma folha de propriedades para que ele apareça em estilos diferentes, como um controle de árvore, uma lista de botões de navegação ou um conjunto de páginas com guias.  
  
 Antes de chamar esse método, chame o [CMFCPropertySheet::SetLook](#setlook) método para definir a aparência do controle de folha de propriedades. Em seguida, chame o [CMFCPropertySheet::InitNavigationControl](#initnavigationcontrol) método para inicializar o objeto de controle de guia interna. Use esse método para recuperar o objeto de controle de guia e, em seguida, usar esse objeto para trabalhar com as guias na folha de propriedades.  
  
 Esse método declara no modo de depuração, se o controle de folha de propriedade não está definido como exibido no estilo do OneNote do Microsoft.  
  
##  <a name="initnavigationcontrol"></a>  CMFCPropertySheet::InitNavigationControl  
 Inicializa a aparência do controle de folha de propriedade atual.  
  
```  
virtual CWnd* InitNavigationControl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela do controle de folha de propriedades.  
  
### <a name="remarks"></a>Comentários  
 Um controle de folha de propriedades pode aparecer em várias formas diferentes, como um conjunto de páginas com guias, um controle de árvore ou uma lista de botões de navegação. Use o [CMFCPropertySheet::SetLook](#setlook) método para especificar a aparência do controle de folha de propriedades.  
  
##  <a name="onactivatepage"></a>  CMFCPropertySheet::OnActivatePage  
 Chamado pelo framework quando uma página de propriedades está habilitada.  
  
```  
virtual void OnActivatePage(CPropertyPage* pPage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *página*  
 Ponteiro para um objeto de página de propriedade que representa a página de propriedade enabled.  
  
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
 [in] *pDC*  
 Ponteiro para um contexto de dispositivo.  
  
 [in] *nPage*  
 O número de página de propriedades de base zero.  
  
 [in] *rectHeader*  
 Um retângulo que especifica onde desenhar o cabeçalho.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada. Se você substituir esse método, chame o [CMFCPropertySheet::EnablePageHeader](#enablepageheader) método antes do framework chama esse método.  
  
##  <a name="onremovetreepage"></a>  CMFCPropertySheet::OnRemoveTreePage  
 Chamado pelo framework para remover uma página de propriedades de um controle de árvore.  
  
```  
virtual BOOL OnRemoveTreePage(CPropertyPage* pPage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *página*  
 Ponteiro para um objeto de página de propriedade que representa a página de propriedade a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
##  <a name="removecategory"></a>  CMFCPropertySheet::RemoveCategory  
 Remove um nó de controle de árvore.  
  
```  
void RemoveCategory(CMFCPropertySheetCategoryInfo* pCategory);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pCategory*  
 Ponteiro para uma categoria (nó) a ser removido.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para remover um nó, o que também é conhecido como uma categoria de um controle de árvore. Use o [CMFCPropertySheet::AddTreeCategory](#addtreecategory) método para adicionar um nó a um controle de árvore.  
  
##  <a name="removepage"></a>  CMFCPropertySheet::RemovePage  
 Remove uma página de propriedades da folha de propriedades.  
  
```  
void RemovePage(CPropertyPage* pPage);
void RemovePage(int nPage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *página*  
 Ponteiro para objeto de página de propriedade que representa a página de propriedade a ser removido. Não pode ser `NULL`.  
  
 [in] *nPage*  
 Índice de base zero da página a ser removido.  
  
### <a name="remarks"></a>Comentários  
 Este método remove a página de propriedade especificada e destrói a janela associada. A página de propriedades do objeto que o *página* parâmetro especifica não será destruído até que o [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md) janela for fechada.  
  
##  <a name="seticonslist"></a>  CMFCPropertySheet::SetIconsList  
 Especifica a lista de imagens que são usados no controle de navegação do painel do Outlook.  
  
```  
BOOL SetIconsList(
    UINT uiImageListResID,  
    int cx,  
    COLORREF clrTransparent=RGB(255, 0, 255));
void SetIconsList(HIMAGELIST hIcons);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *uiImageListResID*  
 A ID de recurso de uma lista de imagens.  
  
 [in] *cx*  
 A largura, em pixels, dos ícones na lista de imagens.  
  
 [in] *clrTransparent*  
 A cor da imagem transparente. As partes da imagem que têm essa cor será transparentes. O valor padrão é o magenta de cor, RGB(255,0,255).  
  
 [in] *hIcons*  
 Um identificador para uma lista de imagem existente.  
  
### <a name="return-value"></a>Valor de retorno  
 No primeiro método de sobrecarga sintaxe, `TRUE` se esse método for bem-sucedida; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se for a folha de propriedades no estilo do Microsoft Outlook, o framework exibe uma lista de botões de navegação, chamado de controle de painel do Outlook, à esquerda da folha de propriedades. Use esse método para definir a lista de imagens a ser usado pelo controle de painel do Outlook.  
  
 Para obter mais informações sobre os métodos que oferecem suporte a esse método, consulte [CImageList::Create](../../mfc/reference/cimagelist-class.md#create) e [CImageList::Add](../../mfc/reference/cimagelist-class.md#add). Para obter mais informações sobre como definir o estilo de uma folha de propriedades, consulte [CMFCPropertySheet::SetLook](#setlook).  
  
##  <a name="setlook"></a>  CMFCPropertySheet::SetLook  
 Especifica a aparência da folha de propriedades.  
  
```  
void SetLook(
    PropSheetLook look,  
    int nNavControlWidth=100);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pesquisar*  
 Um dos valores de enumeração que especifica a aparência da folha de propriedades. O estilo de padrão de uma folha de propriedades é `CMFCPropertySheet::PropSheetLook_Tabs`. Para obter mais informações, consulte a tabela na seção Comentários deste tópico.  
  
 [in] *nNavControlWidth*  
 A largura do controle de navegação, em pixels. O valor padrão é 100.  
  
### <a name="remarks"></a>Comentários  
 Para exibir uma folha de propriedades em um estilo diferente do padrão, chame esse método antes de criar a janela da folha de propriedades.  
  
 A tabela a seguir lista os valores de enumeração que podem ser especificados o *pesquisar* parâmetro.  
  
|Valor|Descrição|  
|-----------|-----------------|  
|`CMFCPropertySheet::PropSheetLook_Tabs`|(Padrão) Exibe uma guia para cada página de propriedades. As guias são exibidas na parte superior da folha de propriedades e são empilhadas se houver mais guias cabem em uma única linha.|  
|`CMFCPropertySheet::PropSheetLook_OutlookBar`|Exibe uma lista de botões de navegação no estilo de barra do Microsoft Outlook, no lado esquerdo da folha de propriedades. Cada botão na lista corresponde a uma página de propriedades. A estrutura exibe setas de rolagem, se houver mais botões cabem na área visível da lista.|  
|`CMFCPropertySheet::PropSheetLook_Tree`|Exibe um controle de árvore no lado esquerdo da folha de propriedades. Cada nó pai ou filho do controle de árvore corresponde a uma página de propriedades. A estrutura exibe setas de rolagem, se houver mais nós cabem na área visível do controle de árvore.|  
|`CMFCPropertySheet::PropSheetLook_OneNoteTabs`|Exibe uma guia no estilo do Microsoft OneNote para cada página de propriedades. A estrutura exibe as guias na parte superior da folha de propriedades e setas de rolagem se houver mais guias que caberá em uma única linha.|  
|`CMFCPropertySheet::PropSheetLook_List`|Exibe uma lista no lado esquerdo da folha de propriedades. Cada item da lista corresponde a uma página de propriedades. A estrutura exibe setas de rolagem, se houver mais itens de lista que caberá na área visível da lista.|  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)   
 [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)
