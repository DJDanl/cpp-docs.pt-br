---
title: Classe CMFCToolBarEditBoxButton
ms.date: 11/04/2016
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
ms.openlocfilehash: 3e988d789ca6a038ce41bca829850f6509fd9df1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504723"
---
# <a name="cmfctoolbareditboxbutton-class"></a>Classe CMFCToolBarEditBoxButton

Um botão da barra de ferramentas que contém um controle de edição ( [Classe CEdit](../../mfc/reference/cedit-class.md)).

## <a name="syntax"></a>Sintaxe

```
class CMFCToolBarEditBoxButton : public CMFCToolBarButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarEditBoxButton::CMFCToolBarEditBoxButton](#cmfctoolbareditboxbutton)|Constrói um objeto `CMFCToolBarEditBoxButton`.|
|`CMFCToolBarEditBoxButton::~CMFCToolBarEditBoxButton`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarEditBoxButton::CanBeStretched](#canbestretched)|Especifica se um usuário pode alongar o botão durante a personalização. (Substitui [CMFCToolBarButton:: CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched).)|
|[CMFCToolBarEditBoxButton::CopyFrom](#copyfrom)|Copia as propriedades de outro botão da barra de ferramentas para o botão atual. (Substitui [CMFCToolBarButton:: CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|
|`CMFCToolBarEditBoxButton::`[CMFCToolBarEditBoxButton:: CreateEdit](#createedit)|Cria um novo controle de edição no botão.|
|`CMFCToolBarEditBoxButton::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCToolBarEditBoxButton::GetByCmd](#getbycmd)|Recupera o primeiro `CMFCToolBarEditBoxButton` objeto no aplicativo que tem a ID de comando especificada.|
|[CMFCToolBarEditBoxButton::GetContentsAll](#getcontentsall)|Recupera o texto do primeiro controle da barra de ferramentas da caixa de edição que tem a ID de comando especificada.|
|[CMFCToolBarEditBoxButton::GetContextMenuID](#getcontextmenuid)|Recupera a ID de recurso do menu de atalho associado ao botão.|
|[CMFCToolBarEditBoxButton::GetEditBorder](#geteditborder)|Recupera o retângulo delimitador da parte de edição do botão Editar caixa.|
|`CMFCToolBarEditBoxButton::` [CMFCToolBarEditBoxButton::GetEditBox](#geteditbox)|Retorna um ponteiro para o controle de edição que é inserido no botão.|
|[CMFCToolBarEditBoxButton::GetHwnd](#gethwnd)|Recupera o identificador de janela que está associado ao botão da barra de ferramentas. (Substitui [CMFCToolBarButton:: GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd).)|
|[CMFCToolBarEditBoxButton::GetInvalidateRect](#getinvalidaterect)|Recupera a região da área do cliente do botão que deve ser redesenhado. (Substitui [CMFCToolBarButton:: GetInvalidateRect](../../mfc/reference/cmfctoolbarbutton-class.md#getinvalidaterect).)|
|`CMFCToolBarEditBoxButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCToolBarEditBoxButton::HaveHotBorder](#havehotborder)|Determina se uma borda do botão é exibida quando um usuário clica no botão. (Substitui [CMFCToolBarButton:: HaveHotBorder](../../mfc/reference/cmfctoolbarbutton-class.md#havehotborder).)|
|[CMFCToolBarEditBoxButton::IsFlatMode](#isflatmode)|Determina se os botões da caixa de edição têm um estilo simples.|
|[CMFCToolBarEditBoxButton::NotifyCommand](#notifycommand)|Especifica se o botão processa a mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) . (Substitui [CMFCToolBarButton:: NotifyCommand](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand).)|
|[CMFCToolBarEditBoxButton::OnAddToCustomizePage](#onaddtocustomizepage)|Chamado pelo Framework quando o botão é adicionado a uma caixa de diálogo **Personalizar** . (Substitui [CMFCToolBarButton:: OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage).)|
|`CMFCToolBarEditBoxButton::OnCalculateSize`|Chamado pelo Framework para calcular o tamanho do botão para o contexto do dispositivo especificado e o estado de encaixe. (Substitui [CMFCToolBarButton:: OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|
|[CMFCToolBarEditBoxButton::OnChangeParentWnd](#onchangeparentwnd)|Chamado pelo Framework quando o botão é inserido em uma nova barra de ferramentas. (Substitui [CMFCToolBarButton:: OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|
|[CMFCToolBarEditBoxButton::OnClick](#onclick)|Chamado pelo Framework quando o usuário clica no botão do mouse. (Substitui [CMFCToolBarButton:: OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|
|[CMFCToolBarEditBoxButton::OnCtlColor](#onctlcolor)|Chamado pelo Framework quando a barra de ferramentas pai manipula uma mensagem WM_CTLCOLOR. (Substitui [CMFCToolBarButton:: OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor).)|
|`CMFCToolBarEditBoxButton::OnDraw`|Chamado pelo Framework para desenhar o botão usando os estilos e as opções especificadas. (Substitui [CMFCToolBarButton:: OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|
|`CMFCToolBarEditBoxButton::OnDrawOnCustomizeList`|Chamado pelo Framework para desenhar o botão no painel **comandos** da caixa de diálogo **Personalizar** . (Substitui [CMFCToolBarButton:: OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|
|[CMFCToolBarEditBoxButton::OnGlobalFontsChanged](#onglobalfontschanged)|Chamado pelo Framework quando a fonte global é alterada. (Substitui [CMFCToolBarButton:: OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged).)|
|[CMFCToolBarEditBoxButton::OnMove](#onmove)|Chamado pelo Framework quando a barra de ferramentas pai é movida. (Substitui [CMFCToolBarButton:: OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove).)|
|[CMFCToolBarEditBoxButton::OnShow](#onshow)|Chamado pelo Framework quando o botão fica visível ou invisível. (Substitui [CMFCToolBarButton:: OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow).)|
|[CMFCToolBarEditBoxButton::OnSize](#onsize)|Chamado pelo Framework quando a barra de ferramentas pai altera seu tamanho ou posição e essa alteração faz com que o botão mude de tamanho. (Substitui [CMFCToolBarButton:: OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize).)|
|[CMFCToolBarEditBoxButton::OnUpdateToolTip](#onupdatetooltip)|Chamado pelo Framework quando a barra de ferramentas pai atualiza seu texto de dica de ferramenta. (Substitui [CMFCToolBarButton:: OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip).)|
|`CMFCToolBarEditBoxButton::Serialize`|Lê este objeto de um arquivo ou grava-o em um arquivo morto. (Substitui [CMFCToolBarButton:: Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|
|`CMFCToolBarEditBoxButton::SetACCData`|Popula o objeto fornecido `CAccessibilityData` com dados de acessibilidade do botão da barra de ferramentas. (Substitui [CMFCToolBarButton:: SetACCData](../../mfc/reference/cmfctoolbarbutton-class.md#setaccdata).)|
|`CMFCToolBarEditBoxButton::` [CMFCToolBarEditBoxButton::SetContents](#setcontents)|Define o texto no controle de edição do botão.|
|`CMFCToolBarEditBoxButton::` [CMFCToolBarEditBoxButton::SetContentsAll](#setcontentsall)|Localiza o botão de controle de edição que tem uma ID de comando especificada e define o texto no controle de edição desse botão.|
|[CMFCToolBarEditBoxButton::SetContextMenuID](#setcontextmenuid)|Especifica a ID de recurso do menu de atalho associado ao botão.|
|[CMFCToolBarEditBoxButton::SetFlatMode](#setflatmode)|Especifica a aparência de estilo plano dos botões da caixa de edição no aplicativo.|
|`CMFCToolBarEditBoxButton::`[CMFCToolBarEditBoxButton:: SetStyle](#setstyle)|Especifica o estilo do botão. (Substitui [CMFCToolBarButton:: SetStyle](../../mfc/reference/cmfctoolbarbutton-class.md#setstyle).)|

## <a name="remarks"></a>Comentários

Para adicionar um botão Editar caixa a uma barra de ferramentas, siga estas etapas:

1. Reserve uma ID de recurso fictícia para o botão no recurso de barra de ferramentas pai.

2. Construa um `CMFCToolBarEditBoxButton` objeto.

3. No manipulador de mensagens que processa a mensagem AFX_WM_RESETTOOLBAR, substitua o botão fictício pelo novo botão de caixa de combinação usando [CMFCToolBar:: ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).

Para obter mais informações, confira [Passo a passo: Colocando controles em barras de](../../mfc/walkthrough-putting-controls-on-toolbars.md)ferramentas.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos na `CMFCToolBarEditBoxButton` classe. O exemplo mostra como especificar que um usuário pode alongar o botão durante a personalização, especificar que uma borda do botão é exibida quando um usuário clica no botão, define o texto no controle caixa de texto, especifica a aparência de estilo plano dos botões da caixa de edição no aplicador la e especifique o estilo de um controle caixa de edição da barra de ferramentas.

[!code-cpp[NVC_MFC_RibbonApp#40](../../mfc/reference/codesnippet/cpp/cmfctoolbareditboxbutton-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)

`CMFCToolBarEditBoxButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbareditboxbutton. h

##  <a name="canbestretched"></a>  CMFCToolBarEditBoxButton::CanBeStretched

Especifica se um usuário pode alongar o botão durante a personalização.

```
virtual BOOL CanBeStretched() const;
```

### <a name="return-value"></a>Valor de retorno

Esse método retorna TRUE.

### <a name="remarks"></a>Comentários

Por padrão, a estrutura não permite que o usuário alongue um botão da barra de ferramentas durante a personalização. Esse método estende a implementação da classe base ( [CMFCToolBarButton:: CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched)) permitindo que o usuário alongue um botão de barra de ferramentas de edição durante a personalização.

##  <a name="cmfctoolbareditboxbutton"></a>CMFCToolBarEditBoxButton::CMFCToolBarEditBoxButton

Constrói um objeto [CMFCToolBarEditBoxButton](../../mfc/reference/cmfctoolbareditboxbutton-class.md) .

```
CMFCToolBarEditBoxButton(
    UINT uiID,
    int iImage,
    DWORD dwStyle=ES_AUTOHSCROLL,
    int iWidth=0);
```

### <a name="parameters"></a>Parâmetros

*uiID*<br/>
no Especifica a ID de controle.

*iImage*<br/>
no Especifica o índice de base zero de uma imagem de barra de ferramentas. A imagem está localizada no objeto de [Classe CMFCToolBarImages](../../mfc/reference/cmfctoolbarimages-class.md) que a classe de [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) mantém.

*dwStyle*<br/>
no Especifica o estilo de controle de edição.

*iWidth*<br/>
no Especifica a largura em pixels do controle de edição.

### <a name="remarks"></a>Comentários

O construtor padrão define o estilo de controle de edição como a seguinte combinação:

WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL

A largura padrão do controle é de 150 pixels.

##  <a name="copyfrom"></a>  CMFCToolBarEditBoxButton::CopyFrom

Copia as propriedades de outro botão da barra de ferramentas para o botão atual.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
no Uma referência ao botão de origem a partir do qual copiar.

### <a name="remarks"></a>Comentários

Chame esse método para copiar outro botão da barra de ferramentas para este botão da barra de ferramentas. *src* deve ser do tipo `CMFCToolBarEditBoxButton`.

##  <a name="createedit"></a>  CMFCToolBarEditBoxButton::CreateEdit

Cria um novo controle de edição no botão.

```
virtual CEdit* CreateEdit(
    CWnd* pWndParent,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no Especifica a janela pai do controle de edição. Ele não deve ser nulo.

*rect*<br/>
no Especifica o tamanho e a posição do controle de edição.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o controle de edição recém-criado; será nulo se a criação e o anexo do controle falharem.

### <a name="remarks"></a>Comentários

Você constrói um `CMFCToolBarEditBoxButton` objeto em duas etapas. Primeiro, chame o construtor e, em `CreateEdit`seguida, chame, que cria o controle de edição do Windows e `CMFCToolBarEditBoxButton` o anexa ao objeto.

##  <a name="getbycmd"></a>  CMFCToolBarEditBoxButton::GetByCmd

Recupera o primeiro `CMFCToolBarEditBoxButton` objeto no aplicativo que tem a ID de comando especificada.

```
static CMFCToolBarEditBoxButton* __stdcall GetByCmd(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de comando do botão a ser recuperado.

### <a name="return-value"></a>Valor de retorno

O primeiro `CMFCToolBarEditBoxButton` objeto no aplicativo que tem a ID de comando especificada ou NULL se não existir esse objeto.

### <a name="remarks"></a>Comentários

Esse método de utilitário compartilhado é usado por métodos como [CMFCToolBarEditBoxButton:: SetContentsAll](#setcontentsall) e [CMFCToolBarEditBoxButton:: GetContentsAll](#getcontentsall) para definir ou obter o texto do primeiro controle da barra de ferramentas da caixa de edição que tem a ID de comando especificada.

##  <a name="getcontentsall"></a>  CMFCToolBarEditBoxButton::GetContentsAll

Recupera o texto do primeiro controle da barra de ferramentas da caixa de edição que tem a ID de comando especificada.

```
static CString __stdcall GetContentsAll(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de comando do botão do qual recuperar o conteúdo.

### <a name="return-value"></a>Valor de retorno

Um `CString` objeto que contém o texto do primeiro controle da barra de ferramentas da caixa de edição que tem a ID de comando especificada.

### <a name="remarks"></a>Comentários

Esse método retornará a cadeia de caracteres vazia `CMFCToolBarEditBoxButton` se nenhum objeto tiver a ID de comando especificada.

##  <a name="getcontextmenuid"></a>  CMFCToolBarEditBoxButton::GetContextMenuID

Recupera a ID de recurso do menu de atalho associado ao botão.

```
UINT GetContextMenuID();
```

### <a name="return-value"></a>Valor de retorno

A ID de recurso do menu de atalho que está associada ao botão ou 0 se o botão não tiver nenhum menu de atalho associado.

### <a name="remarks"></a>Comentários

A estrutura usa a ID do recurso para criar o menu de atalho quando o usuário clica com o botão direito do mouse no botão.

##  <a name="geteditborder"></a>  CMFCToolBarEditBoxButton::GetEditBorder

Recupera o retângulo delimitador da parte de edição do botão Editar caixa.

```
virtual void GetEditBorder(CRect& rectBorder);
```

### <a name="parameters"></a>Parâmetros

*rectBorder*<br/>
fora Uma referência ao `CRect` objeto que recebe o retângulo delimitador.

### <a name="remarks"></a>Comentários

Esse método recupera o retângulo delimitador do controle de edição nas coordenadas do cliente. Ele expande o tamanho do retângulo em cada direção em um pixel.

O método [CMFCVisualManager:: OnDrawEditBorder](../../mfc/reference/cmfcvisualmanager-class.md#ondraweditborder) chama esse método quando ele desenha a borda em torno `CMFCToolBarEditBoxButton` de um objeto.

##  <a name="geteditbox"></a>  CMFCToolBarEditBoxButton::GetEditBox

Retorna um ponteiro para o controle da [Classe CEdit](../../mfc/reference/cedit-class.md) que é inserido no botão.

```
CEdit* GetEditBox() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o controle da [Classe CEdit](../../mfc/reference/cedit-class.md) que o botão contém. Será nulo se o `CEdit` controle ainda não tiver sido criado.

### <a name="remarks"></a>Comentários

Você cria o `CEdit` controle chamando [CMFCToolBarEditBoxButton:: CreateEdit](#createedit).

##  <a name="gethwnd"></a>  CMFCToolBarEditBoxButton::GetHwnd

Recupera o identificador de janela que está associado ao botão da barra de ferramentas.

```
virtual HWND GetHwnd();
```

### <a name="return-value"></a>Valor de retorno

O identificador de janela que está associado ao botão.

### <a name="remarks"></a>Comentários

Esse método substitui o método [CMFCToolBarButton:: GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd) retornando o identificador de janela da parte de controle de edição do botão da caixa de edição.

##  <a name="getinvalidaterect"></a>  CMFCToolBarEditBoxButton::GetInvalidateRect

Recupera a região da área do cliente do botão que deve ser redesenhado.

```
virtual const CRect GetInvalidateRect() const;
```

### <a name="return-value"></a>Valor de retorno

Um `CRect` objeto que especifica a região que deve ser redesenhada.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base, [CMFCToolBarButton:: GetInvalidateRect](../../mfc/reference/cmfctoolbarbutton-class.md#getinvalidaterect), incluindo na região a área do rótulo de texto.

##  <a name="havehotborder"></a>  CMFCToolBarEditBoxButton::HaveHotBorder

Determina se uma borda do botão é exibida quando um usuário clica no botão.

```
virtual BOOL HaveHotBorder() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se um botão exibir sua borda quando selecionado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base, [CMFCToolBarButton:: HaveHotBorder](../../mfc/reference/cmfctoolbarbutton-class.md#havehotborder), retornando um valor diferente de zero se o controle estiver visível.

##  <a name="isflatmode"></a>  CMFCToolBarEditBoxButton::IsFlatMode

Determina se os botões da caixa de edição têm um estilo simples.

```
static BOOL __stdcall IsFlatMode();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se os botões tiverem um estilo simples; caso contrário, 0.

### <a name="remarks"></a>Comentários

Por padrão, os botões da caixa de edição têm um estilo simples. Use o método [CMFCToolBarEditBoxButton::](#setflatmode) SetFlatMode para alterar a aparência do estilo plano para seu aplicativo.

##  <a name="notifycommand"></a>  CMFCToolBarEditBoxButton::NotifyCommand

Especifica se o botão processa a mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) .

```
virtual BOOL NotifyCommand(int iNotifyCode);
```

### <a name="parameters"></a>Parâmetros

*iNotifyCode*<br/>
no A mensagem de notificação associada ao comando.

### <a name="return-value"></a>Valor de retorno

TRUE se o botão processar a mensagem WM_COMMAND ou FALSE para indicar que a mensagem deve ser manipulada pela barra de ferramentas pai.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando está prestes a enviar uma mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) para a janela pai.

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: NotifyCommand](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand)) processando a notificação [EN_UPDATE](/windows/win32/Controls/en-update) . Para cada caixa de edição com a mesma ID de comando que esse objeto, ele define seu rótulo de texto como o rótulo de texto desse objeto.

##  <a name="onaddtocustomizepage"></a>  CMFCToolBarEditBoxButton::OnAddToCustomizePage

Chamado pelo Framework quando o botão é adicionado a uma caixa de diálogo **Personalizar** .

```
virtual void OnAddToCustomizePage();
```

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage)) copiando as propriedades do controle caixa de edição em qualquer barra de ferramentas que tenha a mesma ID de comando que esse objeto. Esse método não fará nada se nenhuma barra de ferramentas tiver um controle caixa de edição que tenha a mesma ID de comando que esse objeto.

Para obter mais informações sobre a caixa de diálogo **Personalizar** , consulte [Classe CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).

##  <a name="onchangeparentwnd"></a>  CMFCToolBarEditBoxButton::OnChangeParentWnd

Chamado pelo Framework quando o botão é inserido em uma nova barra de ferramentas.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no Um ponteiro para a nova janela pai.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base ( [CMFCToolBarButton:: OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)) recriando o `CEdit` objeto interno.

##  <a name="onclick"></a>  CMFCToolBarEditBoxButton::OnClick

Chamado pelo Framework quando o usuário clica no botão do mouse.

```
virtual BOOL OnClick(
    CWnd* pWnd,
    BOOL bDelay = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no Não utilizado.

*bDelay*<br/>
no Não utilizado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão processar a mensagem de clique; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base ( [CMFCToolBarButton:: OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick)) retornando um valor diferente de zero `CEdit` se o objeto interno estiver visível.

##  <a name="onctlcolor"></a>  CMFCToolBarEditBoxButton::OnCtlColor

Chamado pelo Framework quando a barra de ferramentas pai manipula uma mensagem WM_CTLCOLOR.

```
virtual HBRUSH OnCtlColor(
    CDC* pDC,
    UINT nCtlColor);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no O contexto do dispositivo que exibe o botão.

*nCtlColor*<br/>
no Não utilizado.

### <a name="return-value"></a>Valor de retorno

Um identificador para o pincel de janela global.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base ( [CMFCToolBarButton:: OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor)) definindo o texto e as cores de plano de fundo do contexto do dispositivo fornecido para o texto global e as cores do plano de fundo, respectivamente.

Para obter mais informações sobre as opções globais disponíveis para seu aplicativo, consulte [Estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md).

##  <a name="onglobalfontschanged"></a>  CMFCToolBarEditBoxButton::OnGlobalFontsChanged

Chamado pelo Framework quando a fonte global é alterada.

```
virtual void OnGlobalFontsChanged();
```

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged)) alterando a fonte do controle para a da fonte global.

Para obter mais informações sobre as opções globais disponíveis para seu aplicativo, consulte [Estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md).

##  <a name="onmove"></a>  CMFCToolBarEditBoxButton::OnMove

Chamado pelo Framework quando a barra de ferramentas pai é movida.

```
virtual void OnMove();
```

### <a name="remarks"></a>Comentários

Esse método substitui a implementação de classe padrão ( [CMFCToolBarButton:: OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove)) atualizando a posição do objeto `CEdit` interno

##  <a name="onshow"></a>  CMFCToolBarEditBoxButton::OnShow

Chamado pelo Framework quando o botão fica visível ou invisível.

```
virtual void OnShow(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*bShow*<br/>
no Especifica se o botão está visível. Se esse parâmetro for TRUE, o botão ficará visível. Caso contrário, o botão não estará visível.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow)) exibindo o botão se *bShow* for true. Caso contrário, esse método ocultará o botão.

##  <a name="onsize"></a>  CMFCToolBarEditBoxButton::OnSize

Chamado pelo Framework quando a barra de ferramentas pai altera seu tamanho ou posição e essa alteração faz com que o botão mude de tamanho.

```
virtual void OnSize(int iSize);
```

### <a name="parameters"></a>Parâmetros

*iSize*<br/>
no A nova largura do botão, em pixels.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação de classe padrão, [CMFCToolBarButton:: OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize), atualizando o tamanho e a posição do `CEdit` objeto interno.

##  <a name="onupdatetooltip"></a>  CMFCToolBarEditBoxButton::OnUpdateToolTip

Chamado pelo Framework quando a barra de ferramentas pai atualiza seu texto de dica de ferramenta.

```
virtual BOOL OnUpdateToolTip(
    CWnd* pWndParent,
    int iButtonIndex,
    CToolTipCtrl& wndToolTip,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no Não utilizado.

*iButtonIndex*<br/>
no Não utilizado.

*wndToolTip*<br/>
no O controle que exibe o texto da dica de ferramenta.

*str*<br/>
fora Um `CString` objeto que recebe o texto da dica de ferramenta atualizado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o método atualizar o texto da dica de ferramenta; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip)) exibindo o texto da dica de ferramenta que está associado à parte de edição do botão. Se o objeto `CEdit` interno for nulo ou o identificador `CEdit` de janela do objeto não identificar uma janela existente, esse método não fará nada e retornará false.

##  <a name="setcontents"></a>  CMFCToolBarEditBoxButton::SetContents

Define o texto no controle da caixa de texto.

```
virtual void SetContents(const CString& sContents);
```

### <a name="parameters"></a>Parâmetros

*sContents*<br/>
no Especifica o novo texto a ser definido.

##  <a name="setcontentsall"></a>  CMFCToolBarEditBoxButton::SetContentsAll

Localiza um objeto [CMFCToolBarEditBoxButton](../../mfc/reference/cmfctoolbareditboxbutton-class.md) que tem uma ID de comando especificada e define o texto especificado dentro de sua caixa de texto.

```
static BOOL SetContentsAll(
    UINT uiCmd,
    const CString& strContents);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no Especifica a ID de comando do controle para o qual o texto será alterado.

*strContents*<br/>
no Especifica o novo texto a ser definido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o texto foi definido; 0 se o `CMFCToolBarEditBoxButton` controle com a ID de comando especificada não existir.

##  <a name="setcontextmenuid"></a>  CMFCToolBarEditBoxButton::SetContextMenuID

Especifica a ID de recurso do menu de atalho associado ao botão.

```
void SetContextMenuID(UINT uiResID);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de recurso do menu de atalho.

### <a name="remarks"></a>Comentários

A estrutura usa a ID do recurso para criar o menu de atalho quando o usuário clica com o botão direito do mouse no botão da barra de ferramentas.

##  <a name="setflatmode"></a>  CMFCToolBarEditBoxButton::SetFlatMode

Especifica a aparência de estilo plano dos botões da caixa de edição no aplicativo.

```
static void __stdcall SetFlatMode(BOOL bFlat = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bFlat*<br/>
no O estilo plano para botões da caixa de edição. Se esse parâmetro for TRUE, a aparência de estilo simples será habilitada; caso contrário, a aparência do estilo plano será desabilitada.

### <a name="remarks"></a>Comentários

O estilo plano padrão para botões da caixa de edição é TRUE. Use o método [CMFCToolBarEditBoxButton::](#isflatmode) IsFlatMode para recuperar a aparência de estilo plano para seu aplicativo.

##  <a name="setstyle"></a>  CMFCToolBarEditBoxButton::SetStyle

Especifica o estilo de um controle de caixa de edição da barra de ferramentas.

```
virtual void SetStyle(UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*nStyle*<br/>
no Um novo estilo a ser definido.

### <a name="remarks"></a>Comentários

Esse método define [CMFCToolBarButton:: m_nStyle](../../mfc/reference/cmfctoolbarbutton-class.md#m_nstyle) como *nStyle* também desabilita a caixa de texto quando o aplicativo está no modo de personalização e o habilita quando o aplicativo não está no modo de personalização (consulte [CMFCToolBar::](../../mfc/reference/cmfctoolbar-class.md#setcustomizemode) setcustommode e [CMFCToolBar::](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)iscustommode). Consulte [estilos de controle da barra de ferramentas](../../mfc/reference/toolbar-control-styles.md) para obter uma lista de sinalizadores de estilo válidos.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)<br/>
[Passo a passo: colocar controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
