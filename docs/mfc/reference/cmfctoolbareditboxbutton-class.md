---
title: Classe de botão CMFCToolBarEditBox
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
ms.openlocfilehash: 52989f7b523bf0ba9a00da350242a968ca0db153
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360479"
---
# <a name="cmfctoolbareditboxbutton-class"></a>Classe de botão CMFCToolBarEditBox

Um botão de barra de ferramentas que contém um controle de edição [(CEdit Class).](../../mfc/reference/cedit-class.md)

## <a name="syntax"></a>Sintaxe

```
class CMFCToolBarEditBoxButton : public CMFCToolBarButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarEditAto::CMFCToolBareditboxButton](#cmfctoolbareditboxbutton)|Constrói um objeto `CMFCToolBarEditBoxButton`.|
|`CMFCToolBarEditBoxButton::~CMFCToolBarEditBoxButton`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarEditBoxButton::CanBeStretched](#canbestretched)|Especifica se um usuário pode esticar o botão durante a personalização. (Substitui [cmfctoolbarbutton::CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched).)|
|[CMFCToolBarEditeditbutton::CopyFrom](#copyfrom)|Copia as propriedades de outro botão de barra de ferramentas para o botão atual. (Substitui [cmfctoolbarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|
|`CMFCToolBarEditBoxButton::`[CMFCToolBarEditia::CriarEditar](#createedit)|Cria um novo controle de edição no botão.|
|`CMFCToolBarEditBoxButton::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCToolBarEditBoxButton::GetByCmd](#getbycmd)|Recupera o `CMFCToolBarEditBoxButton` primeiro objeto no aplicativo que tem o ID de comando especificado.|
|[CMFCToolBarEditeditbutton::getcontentsAll](#getcontentsall)|Recupera o texto do primeiro controle da barra de ferramentas da caixa de edição que tem o ID de comando especificado.|
|[CMFCToolBarEditeditbutton::getcontextmenuid](#getcontextmenuid)|Recupera o ID de recurso do menu de atalho associado ao botão.|
|[CMFCToolBarEditBoxbutton::getEditBorder](#geteditborder)|Recupera o retângulo delimitador da parte de edição do botão editar caixa.|
|`CMFCToolBarEditBoxButton::`[CMFCToolBarEditEditButton::getEditBox](#geteditbox)|Retorna um ponteiro para o controle de edição que está incorporado no botão.|
|[CMFCToolBarEditBoxButton::GetHwnd](#gethwnd)|Recupera a alça da janela associada ao botão da barra de ferramentas. (Substitui [cmfctoolbarbutton::GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd).)|
|[CMFCToolBarEditBoxButton::GetInvalidRect](#getinvalidaterect)|Recupera a região da área cliente do botão que deve ser redesenhada. (Substitui [cmfctoolbarbutton::GetInvalidateRect](../../mfc/reference/cmfctoolbarbutton-class.md#getinvalidaterect).)|
|`CMFCToolBarEditBoxButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCToolBarEditBoxbutton::HaveHotBorder](#havehotborder)|Determina se uma borda do botão é exibida quando um usuário clica no botão. (Substitui [cmfctoolbarButton::HaveHotBorder](../../mfc/reference/cmfctoolbarbutton-class.md#havehotborder).)|
|[CMFCToolBarEditabotão::isflatMode](#isflatmode)|Determina se os botões de caixa de edição têm um estilo plano.|
|[CMFCToolBarEditEditButton::NotificarComando](#notifycommand)|Especifica se o botão processa a [mensagem WM_COMMAND.](/windows/win32/menurc/wm-command) (Substitui [cmfcToolBarButton::Notificarcomando](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand).)|
|[CMFCToolBarEditabotão::onaddtocustompage](#onaddtocustomizepage)|Chamado pela estrutura quando o botão é adicionado a uma caixa de diálogo **Personalizar.** (Substitui [cmfcToolBarButton::OnAddToCustomPage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage).)|
|`CMFCToolBarEditBoxButton::OnCalculateSize`|Chamado pela estrutura para calcular o tamanho do botão para o contexto do dispositivo especificado e o estado de acoplamento. (Substitui [cmfcToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|
|[CMFCToolBarEditabotão::OnChangeParentWnd](#onchangeparentwnd)|Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas. (Substitui [cmfctoolbarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|
|[CMFCToolBarEditeditbutton::OnClick](#onclick)|Chamado pela estrutura quando o usuário clica no botão do mouse. (Substitui [cmfctoolbarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|
|[CMFCToolBarEditBoxButton::OnCtlColor](#onctlcolor)|Chamado pela estrutura quando a barra de ferramentas dos pais lida com uma mensagem WM_CTLCOLOR. (Substitui [cmfctoolbarButton::OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor).)|
|`CMFCToolBarEditBoxButton::OnDraw`|Chamado pela estrutura para desenhar o botão usando os estilos e opções especificados. (Substitui [cmfctoolbarButton::OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|
|`CMFCToolBarEditBoxButton::OnDrawOnCustomizeList`|Chamado pela estrutura para desenhar o botão no painel **Comandos** da caixa de diálogo **Personalizar.** (Substitui [cmfctoolbarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|
|[CMFCToolBarEditAtoButton::OnGlobalFontsChanged](#onglobalfontschanged)|Chamado pelo framework quando a fonte global foi alterada. (Substitui [cmfctoolbarButton::OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged).)|
|[CMFCToolBarEditBoxButton::OnMove](#onmove)|Chamada pela estrutura quando a barra de ferramentas dos pais se move. (Substitui [cmfctoolbarButton::OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove).)|
|[CMFCToolBarEditBoxbutton::OnShow](#onshow)|Chamado pela estrutura quando o botão se torna visível ou invisível. (Substitui [cmfctoolbarbutton::OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow).)|
|[CMFCToolBarEditeditbutton::OnSize](#onsize)|Chamada pela estrutura quando a barra de ferramentas pai muda seu tamanho ou posição e essa alteração faz com que o botão mude de tamanho. (Substitui [cmfcToolbarButton::OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize).)|
|[CMFCToolBarEditEditButton::OnUpdateToolTip](#onupdatetooltip)|Chamada pela framework quando a barra de ferramentas pai atualiza seu texto de dica de ferramenta. (Substitui [cmfctoolbarButton::OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip).)|
|`CMFCToolBarEditBoxButton::Serialize`|Lê este objeto de um arquivo ou grava-o em um arquivo. (Substitui [cmfctoolbarButton::Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|
|`CMFCToolBarEditBoxButton::SetACCData`|Preenche o objeto `CAccessibilityData` fornecido com dados de acessibilidade do botão barra de ferramentas. (Substitui [cmfcToolBarButton::SetACCData](../../mfc/reference/cmfctoolbarbutton-class.md#setaccdata).)|
|`CMFCToolBarEditBoxButton::`[CMFCToolBarEditabotão::conjuntoConteúdo](#setcontents)|Define o texto no controle de edição do botão.|
|`CMFCToolBarEditBoxButton::`[CMFCToolBarEditabotão::conjuntoConteúdotudo](#setcontentsall)|Encontra o botão de controle de edição que tem um ID de comando especificado e define o texto no controle de edição desse botão.|
|[CMFCToolBarEditabotão::setcontextmenuId](#setcontextmenuid)|Especifica o ID de recurso do menu de atalho associado ao botão.|
|[CMFCToolBarEditabotão::setFlatMode](#setflatmode)|Especifica a aparência de estilo plano dos botões de caixa de edição no aplicativo.|
|`CMFCToolBarEditBoxButton::`[CMFCToolBarEditabotão::setStyle](#setstyle)|Especifica o estilo do botão. (Substitui [cmfctoolbarButton::SetStyle](../../mfc/reference/cmfctoolbarbutton-class.md#setstyle).)|

## <a name="remarks"></a>Comentários

Para adicionar um botão de caixa de edição a uma barra de ferramentas, siga estas etapas:

1. Reserve um ID de recurso de boneco para o botão no recurso da barra de ferramentas pai.

2. Construa `CMFCToolBarEditBoxButton` um objeto.

3. No manipulador de mensagens que processa a mensagem AFX_WM_RESETTOOLBAR, substitua o botão manequim pelo novo botão de caixa de combinação usando [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).

Para obter mais informações, consulte [Passo a Passo: Colocando controles nas barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCToolBarEditBoxButton` usar vários métodos na classe. O exemplo mostra como especificar que um usuário pode esticar o botão durante a personalização, especificar que uma borda do botão é exibida quando um usuário clica no botão, definir o texto no controle da caixa de texto, especificar a aparência de estilo plano dos botões da caixa de edição no aplicativo e especificar o estilo de um controle de caixa de edição da barra de ferramentas.

[!code-cpp[NVC_MFC_RibbonApp#40](../../mfc/reference/codesnippet/cpp/cmfctoolbareditboxbutton-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfctoolbarbutton](../../mfc/reference/cmfctoolbarbutton-class.md)

`CMFCToolBarEditBoxButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbareditboxbutton.h

## <a name="cmfctoolbareditboxbuttoncanbestretched"></a><a name="canbestretched"></a>CMFCToolBarEditBoxButton::CanBeStretched

Especifica se um usuário pode esticar o botão durante a personalização.

```
virtual BOOL CanBeStretched() const;
```

### <a name="return-value"></a>Valor retornado

Este método retorna TRUE.

### <a name="remarks"></a>Comentários

Por padrão, a estrutura não permite que o usuário estique um botão de barra de ferramentas durante a personalização. Este método estende a implementação da classe base [(CMFCToolBarButton::CanBeStretched)](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched)permitindo que o usuário estique um botão de barra de ferramentas de caixa de edição durante a personalização.

## <a name="cmfctoolbareditboxbuttoncmfctoolbareditboxbutton"></a><a name="cmfctoolbareditboxbutton"></a>CMFCToolBarEditAto::CMFCToolBareditboxButton

Constrói um objeto [CMFCToolBarEditBoxButton.](../../mfc/reference/cmfctoolbareditboxbutton-class.md)

```
CMFCToolBarEditBoxButton(
    UINT uiID,
    int iImage,
    DWORD dwStyle=ES_AUTOHSCROLL,
    int iWidth=0);
```

### <a name="parameters"></a>Parâmetros

*Uiid*<br/>
[em] Especifica o ID de controle.

*Iimage*<br/>
[em] Especifica o índice baseado em zero de uma imagem de barra de ferramentas. A imagem está localizada no objeto [CMFCToolBarImages Class](../../mfc/reference/cmfctoolbarimages-class.md) que a classe [CMFCToolBar class](../../mfc/reference/cmfctoolbar-class.md) mantém.

*Dwstyle*<br/>
[em] Especifica o estilo de controle de edição.

*iWidth*<br/>
[em] Especifica a largura em pixels do controle de edição.

### <a name="remarks"></a>Comentários

O construtor padrão define o estilo de controle de edição para a seguinte combinação:

WS_CHILD | WS_VISIBLE | Es_autohscroll

A largura padrão do controle é de 150 pixels.

## <a name="cmfctoolbareditboxbuttoncopyfrom"></a><a name="copyfrom"></a>CMFCToolBarEditeditbutton::CopyFrom

Copia as propriedades de outro botão de barra de ferramentas para o botão atual.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
[em] Uma referência ao botão de origem a partir do qual copiar.

### <a name="remarks"></a>Comentários

Chame este método para copiar outro botão de barra de ferramentas para este botão de barra de ferramentas. *src* deve ser `CMFCToolBarEditBoxButton`do tipo .

## <a name="cmfctoolbareditboxbuttoncreateedit"></a><a name="createedit"></a>CMFCToolBarEditia::CriarEditar

Cria um novo controle de edição no botão.

```
virtual CEdit* CreateEdit(
    CWnd* pWndParent,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Especifica a janela pai do controle de edição. Não deve ser NULO.

*Rect*<br/>
[em] Especifica o tamanho e a posição do controle de edição.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o controle de edição recém-criado; é NULO se a criação e o anexo do controle falharem.

### <a name="remarks"></a>Comentários

Você constrói `CMFCToolBarEditBoxButton` um objeto em dois passos. Primeiro ligue para o construtor `CreateEdit`e, em seguida, chame, que `CMFCToolBarEditBoxButton` cria o controle de edição do Windows e o anexa ao objeto.

## <a name="cmfctoolbareditboxbuttongetbycmd"></a><a name="getbycmd"></a>CMFCToolBarEditBoxButton::GetByCmd

Recupera o `CMFCToolBarEditBoxButton` primeiro objeto no aplicativo que tem o ID de comando especificado.

```
static CMFCToolBarEditBoxButton* __stdcall GetByCmd(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O id de comando do botão para recuperar.

### <a name="return-value"></a>Valor retornado

O `CMFCToolBarEditBoxButton` primeiro objeto no aplicativo que tem o ID de comando especificado ou NULL se não houver tal objeto.

### <a name="remarks"></a>Comentários

Este método de utilidade compartilhada é usado por métodos como [CMFCToolBarEditBoxButton::SetContentsAll](#setcontentsall) e [CMFCToolBarEditBoxButton::GetContentsTudo](#getcontentsall) para definir ou obter o texto do primeiro controle de barra de ferramentas da caixa de edição que tem o ID de comando especificado.

## <a name="cmfctoolbareditboxbuttongetcontentsall"></a><a name="getcontentsall"></a>CMFCToolBarEditeditbutton::getcontentsAll

Recupera o texto do primeiro controle da barra de ferramentas da caixa de edição que tem o ID de comando especificado.

```
static CString __stdcall GetContentsAll(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O id de comando do botão a partir do qual recuperar o conteúdo.

### <a name="return-value"></a>Valor retornado

Um `CString` objeto que contém o texto do primeiro controle da barra de ferramentas da caixa de edição que tem o ID de comando especificado.

### <a name="remarks"></a>Comentários

Este método retorna a `CMFCToolBarEditBoxButton` seqüência vazia se nenhum objeto tiver o ID de comando especificado.

## <a name="cmfctoolbareditboxbuttongetcontextmenuid"></a><a name="getcontextmenuid"></a>CMFCToolBarEditeditbutton::getcontextmenuid

Recupera o ID de recurso do menu de atalho associado ao botão.

```
UINT GetContextMenuID();
```

### <a name="return-value"></a>Valor retornado

O ID de recurso do menu de atalho que está associado ao botão ou 0 se o botão não tiver menu de atalho associado.

### <a name="remarks"></a>Comentários

A estrutura usa o ID de recurso para criar o menu de atalho quando o usuário clica com o botão com o botão.

## <a name="cmfctoolbareditboxbuttongeteditborder"></a><a name="geteditborder"></a>CMFCToolBarEditBoxbutton::getEditBorder

Recupera o retângulo delimitador da parte de edição do botão editar caixa.

```
virtual void GetEditBorder(CRect& rectBorder);
```

### <a name="parameters"></a>Parâmetros

*rectBorder*<br/>
[fora] Uma referência `CRect` ao objeto que recebe o retângulo delimitador.

### <a name="remarks"></a>Comentários

Este método recupera o retângulo delimitador do controle de edição nas coordenadas do cliente. Ele expande o tamanho do retângulo em cada direção por um pixel.

O método [CMFCVisualManager::OnDrawEditBorder](../../mfc/reference/cmfcvisualmanager-class.md#ondraweditborder) chama esse método quando `CMFCToolBarEditBoxButton` ele desenha a borda em torno de um objeto.

## <a name="cmfctoolbareditboxbuttongeteditbox"></a><a name="geteditbox"></a>CMFCToolBarEditEditButton::getEditBox

Retorna um ponteiro para o controle [CEdit Class](../../mfc/reference/cedit-class.md) que está incorporado no botão.

```
CEdit* GetEditBox() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o controle [CEdit Class](../../mfc/reference/cedit-class.md) que o botão contém. É NULO `CEdit` se o controle ainda não foi criado.

### <a name="remarks"></a>Comentários

Você cria `CEdit` o controle chamando [CMFCToolBarEditBoxButton::CreateEdit](#createedit).

## <a name="cmfctoolbareditboxbuttongethwnd"></a><a name="gethwnd"></a>CMFCToolBarEditBoxButton::GetHwnd

Recupera a alça da janela associada ao botão da barra de ferramentas.

```
virtual HWND GetHwnd();
```

### <a name="return-value"></a>Valor retornado

A alça da janela que está associada ao botão.

### <a name="remarks"></a>Comentários

Este método substitui o método [CMFCToolBarButton::GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd) retornando a alça da janela da parte de controle de edição do botão editar caixa.

## <a name="cmfctoolbareditboxbuttongetinvalidaterect"></a><a name="getinvalidaterect"></a>CMFCToolBarEditBoxButton::GetInvalidRect

Recupera a região da área cliente do botão que deve ser redesenhada.

```
virtual const CRect GetInvalidateRect() const;
```

### <a name="return-value"></a>Valor retornado

Um `CRect` objeto que especifica a região que deve ser redesenhada.

### <a name="remarks"></a>Comentários

Este método amplia a implementação da classe base, [CMFCToolBarButton::GetInvalidateRect](../../mfc/reference/cmfctoolbarbutton-class.md#getinvalidaterect), incluindo na região a área do rótulo de texto.

## <a name="cmfctoolbareditboxbuttonhavehotborder"></a><a name="havehotborder"></a>CMFCToolBarEditBoxbutton::HaveHotBorder

Determina se uma borda do botão é exibida quando um usuário clica no botão.

```
virtual BOOL HaveHotBorder() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se um botão exibir sua borda quando selecionado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base, [CMFCToolBarButton::HaveHotBorder](../../mfc/reference/cmfctoolbarbutton-class.md#havehotborder), retornando um valor não zero se o controle estiver visível.

## <a name="cmfctoolbareditboxbuttonisflatmode"></a><a name="isflatmode"></a>CMFCToolBarEditabotão::isflatMode

Determina se os botões de caixa de edição têm um estilo plano.

```
static BOOL __stdcall IsFlatMode();
```

### <a name="return-value"></a>Valor retornado

Não zero se os botões tiverem um estilo plano; caso contrário, 0.

### <a name="remarks"></a>Comentários

Por padrão, os botões de caixa de edição têm um estilo plano. Use o [método CMFCToolBarEditBoxButton::SetFlatMode](#setflatmode) para alterar a aparência de estilo plano para o aplicativo.

## <a name="cmfctoolbareditboxbuttonnotifycommand"></a><a name="notifycommand"></a>CMFCToolBarEditEditButton::NotificarComando

Especifica se o botão processa a [mensagem WM_COMMAND.](/windows/win32/menurc/wm-command)

```
virtual BOOL NotifyCommand(int iNotifyCode);
```

### <a name="parameters"></a>Parâmetros

*iNotifyCode*<br/>
[em] A mensagem de notificação que está associada ao comando.

### <a name="return-value"></a>Valor retornado

TRUE se o botão processa a mensagem WM_COMMAND ou FALSE para indicar que a mensagem deve ser tratada pela barra de ferramentas pai.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando ele está prestes a enviar uma mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) para a janela pai.

Este método amplia a implementação da classe base [(CMFCToolBarButton::NotifyCommand)](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand)processando a notificação [EN_UPDATE.](/windows/win32/Controls/en-update) Para cada caixa de edição com o mesmo ID de comando deste objeto, ele define seu rótulo de texto para o rótulo de texto deste objeto.

## <a name="cmfctoolbareditboxbuttononaddtocustomizepage"></a><a name="onaddtocustomizepage"></a>CMFCToolBarEditabotão::onaddtocustompage

Chamado pela estrutura quando o botão é adicionado a uma caixa de diálogo **Personalizar.**

```
virtual void OnAddToCustomizePage();
```

### <a name="remarks"></a>Comentários

Este método amplia a implementação da classe base [(CMFCToolBarButton::OnAddToCustomizePage)](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage)copiando as propriedades do controle da caixa de edição em qualquer barra de ferramentas que tenha o mesmo ID de comando que este objeto. Este método não faz nada se nenhuma barra de ferramentas tiver um controle de caixa de edição que tenha o mesmo ID de comando que este objeto.

Para obter mais informações sobre a caixa de diálogo **Personalizar,** consulte [CMFCToolBarsPersonalizeSala de diálogo](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).

## <a name="cmfctoolbareditboxbuttononchangeparentwnd"></a><a name="onchangeparentwnd"></a>CMFCToolBarEditabotão::OnChangeParentWnd

Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Um ponteiro para a nova janela dos pais.

### <a name="remarks"></a>Comentários

Este método substitui a implementação da classe base [(CMFCToolBarButton::OnChangeParentWnd)](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)recriando o objeto interno. `CEdit`

## <a name="cmfctoolbareditboxbuttononclick"></a><a name="onclick"></a>CMFCToolBarEditeditbutton::OnClick

Chamado pela estrutura quando o usuário clica no botão do mouse.

```
virtual BOOL OnClick(
    CWnd* pWnd,
    BOOL bDelay = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] Utilizadas.

*bAtraso*<br/>
[em] Utilizadas.

### <a name="return-value"></a>Valor retornado

Não zero se o botão processa a mensagem de clique; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método substitui a implementação da classe base [(CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick)) `CEdit` retornando um valor não zero se o objeto interno estiver visível.

## <a name="cmfctoolbareditboxbuttononctlcolor"></a><a name="onctlcolor"></a>CMFCToolBarEditBoxButton::OnCtlColor

Chamado pela estrutura quando a barra de ferramentas dos pais lida com uma mensagem WM_CTLCOLOR.

```
virtual HBRUSH OnCtlColor(
    CDC* pDC,
    UINT nCtlColor);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] O contexto do dispositivo que exibe o botão.

*nCtlColor*<br/>
[em] Utilizadas.

### <a name="return-value"></a>Valor retornado

Uma alça para a escova de janelas global.

### <a name="remarks"></a>Comentários

Este método substitui a implementação da classe base [(CMFCToolBarButton::OnCtlColor)](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor)definindo as cores de texto e de fundo do contexto do dispositivo fornecido para as cores globais de texto e de fundo, respectivamente.

Para obter mais informações sobre as opções globais disponíveis para o seu aplicativo, consulte [AFX_GLOBAL_DATA Estrutura](../../mfc/reference/afx-global-data-structure.md).

## <a name="cmfctoolbareditboxbuttononglobalfontschanged"></a><a name="onglobalfontschanged"></a>CMFCToolBarEditAtoButton::OnGlobalFontsChanged

Chamado pelo framework quando a fonte global foi alterada.

```
virtual void OnGlobalFontsChanged();
```

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base [(CMFCToolBarButton::OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged)) alterando a fonte do controle para a da fonte global.

Para obter mais informações sobre as opções globais disponíveis para o seu aplicativo, consulte [AFX_GLOBAL_DATA Estrutura](../../mfc/reference/afx-global-data-structure.md).

## <a name="cmfctoolbareditboxbuttononmove"></a><a name="onmove"></a>CMFCToolBarEditBoxButton::OnMove

Chamada pela estrutura quando a barra de ferramentas dos pais se move.

```
virtual void OnMove();
```

### <a name="remarks"></a>Comentários

Este método substitui a implementação de classe padrão [(CMFCToolBarButton::OnMove)](../../mfc/reference/cmfctoolbarbutton-class.md#onmove)atualizando a posição do objeto interno `CEdit`

## <a name="cmfctoolbareditboxbuttononshow"></a><a name="onshow"></a>CMFCToolBarEditBoxbutton::OnShow

Chamado pela estrutura quando o botão se torna visível ou invisível.

```
virtual void OnShow(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
[em] Especifica se o botão está visível. Se este parâmetro for TRUE, o botão será visível. Caso contrário, o botão não é visível.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base [(CMFCToolBarButton::OnShow)](../../mfc/reference/cmfctoolbarbutton-class.md#onshow)exibindo o botão se *bShow* for TRUE. Caso contrário, este método esconde o botão.

## <a name="cmfctoolbareditboxbuttononsize"></a><a name="onsize"></a>CMFCToolBarEditeditbutton::OnSize

Chamada pela estrutura quando a barra de ferramentas pai muda seu tamanho ou posição e essa alteração faz com que o botão mude de tamanho.

```
virtual void OnSize(int iSize);
```

### <a name="parameters"></a>Parâmetros

*iSize*<br/>
[em] A nova largura do botão, em pixels.

### <a name="remarks"></a>Comentários

Este método substitui a implementação da classe padrão, [CMFCToolBarButton::OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize) `CEdit` , atualizando o tamanho e a posição do objeto interno.

## <a name="cmfctoolbareditboxbuttononupdatetooltip"></a><a name="onupdatetooltip"></a>CMFCToolBarEditEditButton::OnUpdateToolTip

Chamada pela framework quando a barra de ferramentas pai atualiza seu texto de dica de ferramenta.

```
virtual BOOL OnUpdateToolTip(
    CWnd* pWndParent,
    int iButtonIndex,
    CToolTipCtrl& wndToolTip,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Utilizadas.

*iButtonIndex*<br/>
[em] Utilizadas.

*wndToolTip*<br/>
[em] O controle que exibe o texto da dica de ferramenta.

*Str*<br/>
[fora] Um `CString` objeto que recebe o texto atualizado da dica de ferramenta.

### <a name="return-value"></a>Valor retornado

Não zero se o método atualizar o texto da dica de ferramenta; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método amplia a implementação da classe base [(CMFCToolBarButton::OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip)) exibindo o texto da dica de ferramenta que está associado à parte de edição do botão. Se o `CEdit` objeto interno for NULO `CEdit` ou a alça da janela do objeto não identificar uma janela existente, este método não faz nada e retorna FALSO.

## <a name="cmfctoolbareditboxbuttonsetcontents"></a><a name="setcontents"></a>CMFCToolBarEditabotão::conjuntoConteúdo

Define o texto no controle da caixa de texto.

```
virtual void SetContents(const CString& sContents);
```

### <a name="parameters"></a>Parâmetros

*sConteúdo*<br/>
[em] Especifica o novo texto a ser definido.

## <a name="cmfctoolbareditboxbuttonsetcontentsall"></a><a name="setcontentsall"></a>CMFCToolBarEditabotão::conjuntoConteúdotudo

Encontra um objeto [CMFCToolBarEditBoxButton](../../mfc/reference/cmfctoolbareditboxbutton-class.md) que tem um ID de comando especificado e define o texto especificado em sua caixa de texto.

```
static BOOL SetContentsAll(
    UINT uiCmd,
    const CString& strContents);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] Especifica o ID de comando do controle para o qual o texto será alterado.

*strConteúdo*<br/>
[em] Especifica o novo texto a ser definido.

### <a name="return-value"></a>Valor retornado

Não zero se o texto foi definido; 0 se `CMFCToolBarEditBoxButton` o controle com o ID de comando especificado não existir.

## <a name="cmfctoolbareditboxbuttonsetcontextmenuid"></a><a name="setcontextmenuid"></a>CMFCToolBarEditabotão::setcontextmenuId

Especifica o ID de recurso do menu de atalho associado ao botão.

```
void SetContextMenuID(UINT uiResID);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O ID de recurso do menu de atalho.

### <a name="remarks"></a>Comentários

A estrutura usa o ID de recurso para criar o menu de atalho quando o usuário clica com o botão da barra de ferramentas.

## <a name="cmfctoolbareditboxbuttonsetflatmode"></a><a name="setflatmode"></a>CMFCToolBarEditabotão::setFlatMode

Especifica a aparência de estilo plano dos botões de caixa de edição no aplicativo.

```
static void __stdcall SetFlatMode(BOOL bFlat = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bFlat*<br/>
[em] O estilo plano para editar botões de caixa. Se este parâmetro for TRUE, a aparência de estilo plano está ativada; caso contrário, a aparência de estilo plano está desativada.

### <a name="remarks"></a>Comentários

O estilo plano padrão para editar botões de caixa é TRUE. Use o [método CMFCToolBarEditBoxButton::IsFlatMode](#isflatmode) para recuperar a aparência de estilo plano para o aplicativo.

## <a name="cmfctoolbareditboxbuttonsetstyle"></a><a name="setstyle"></a>CMFCToolBarEditabotão::setStyle

Especifica o estilo de um controle de caixa de edição da barra de ferramentas.

```
virtual void SetStyle(UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*nStyle*<br/>
[em] Um novo estilo para definir.

### <a name="remarks"></a>Comentários

Este método define [CMFCToolBarButton::m_nStyle](../../mfc/reference/cmfctoolbarbutton-class.md#m_nstyle) para *nStyle* Ele também desativa a caixa de texto quando o aplicativo está no modo Personalizar e o habilita quando o aplicativo não está no modo Personalizar (consulte [CMFCToolBar::SetCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#setcustomizemode) e [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)). Consulte [Estilos de controle da barra de](../../mfc/reference/toolbar-control-styles.md) ferramentas para obter uma lista de sinalizadores de estilo válidos.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[CMFCToolBar::Substituir botão](../../mfc/reference/cmfctoolbar-class.md#replacebutton)<br/>
[Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
