---
title: Classe CMFCDropDownToolbarButton
ms.date: 11/04/2016
f1_keywords:
- CMFCDropDownToolbarButton
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::CMFCDropDownToolbarButton
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::CopyFrom
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::DropDownToolbar
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::ExportToMenuButton
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::GetDropDownToolBar
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::IsDropDown
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::IsExtraSize
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnCalculateSize
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnChangeParentWnd
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnClick
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnClickUp
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnContextHelp
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnCustomizeMenu
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnDraw
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::OnDrawOnCustomizeList
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::Serialize
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::SetDefaultCommand
- AFXDROPDOWNTOOLBAR/CMFCDropDownToolbarButton::m_uiShowBarDelay
helpviewer_keywords:
- CMFCDropDownToolbarButton [MFC], CMFCDropDownToolbarButton
- CMFCDropDownToolbarButton [MFC], CopyFrom
- CMFCDropDownToolbarButton [MFC], DropDownToolbar
- CMFCDropDownToolbarButton [MFC], ExportToMenuButton
- CMFCDropDownToolbarButton [MFC], GetDropDownToolBar
- CMFCDropDownToolbarButton [MFC], IsDropDown
- CMFCDropDownToolbarButton [MFC], IsExtraSize
- CMFCDropDownToolbarButton [MFC], OnCalculateSize
- CMFCDropDownToolbarButton [MFC], OnChangeParentWnd
- CMFCDropDownToolbarButton [MFC], OnClick
- CMFCDropDownToolbarButton [MFC], OnClickUp
- CMFCDropDownToolbarButton [MFC], OnContextHelp
- CMFCDropDownToolbarButton [MFC], OnCustomizeMenu
- CMFCDropDownToolbarButton [MFC], OnDraw
- CMFCDropDownToolbarButton [MFC], OnDrawOnCustomizeList
- CMFCDropDownToolbarButton [MFC], Serialize
- CMFCDropDownToolbarButton [MFC], SetDefaultCommand
- CMFCDropDownToolbarButton [MFC], m_uiShowBarDelay
ms.assetid: bc9d69e6-bd3e-4c15-9368-e80a504a0ba7
ms.openlocfilehash: fcfb521e309463da81d0064451297b3b73610d2f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505328"
---
# <a name="cmfcdropdowntoolbarbutton-class"></a>Classe CMFCDropDownToolbarButton

Um tipo de botão da barra de ferramentas que se comporta como um botão normal quando ele é clicado. No entanto, ele abre uma barra de ferramentas suspensa ( [Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md) se o usuário pressiona e mantém o botão da barra de ferramentas pressionado.

## <a name="syntax"></a>Sintaxe

```
class CMFCDropDownToolbarButton : public CMFCToolBarButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownToolbarButton::CMFCDropDownToolbarButton](#cmfcdropdowntoolbarbutton)|Constrói um objeto `CMFCDropDownToolbarButton`.|
|`CMFCDropDownToolbarButton::~CMFCDropDownToolbarButton`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownToolbarButton::CopyFrom](#copyfrom)|Copia as propriedades de outro botão da barra de ferramentas para o botão atual. (Substitui [CMFCToolBarButton:: CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|
|`CMFCDropDownToolbarButton::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCDropDownToolbarButton::DropDownToolbar](#dropdowntoolbar)|Abre uma barra de ferramentas suspensa.|
|[CMFCDropDownToolbarButton::ExportToMenuButton](#exporttomenubutton)|Copia o texto do botão da barra de ferramentas para um menu. (Substitui [CMFCToolBarButton:: ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton).)|
|[CMFCDropDownToolbarButton::GetDropDownToolBar](#getdropdowntoolbar)|Recupera a barra de ferramentas suspensa associada ao botão.|
|`CMFCDropDownToolbarButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCDropDownToolbarButton::IsDropDown](#isdropdown)|Determina se a barra de ferramentas suspensa está aberta no momento.|
|[CMFCDropDownToolbarButton::IsExtraSize](#isextrasize)|Determina se o botão pode ser exibido com uma borda estendida. (Substitui [CMFCToolBarButton:: IsExtraSize](../../mfc/reference/cmfctoolbarbutton-class.md#isextrasize).)|
|[CMFCDropDownToolbarButton::OnCalculateSize](#oncalculatesize)|Chamado pelo Framework para calcular o tamanho do botão para o contexto do dispositivo especificado e o estado de encaixe. (Substitui [CMFCToolBarButton:: OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|
|`CMFCDropDownToolbarButton::OnCancelMode`|Chamado pelo Framework para manipular a mensagem [WM_CANCELMODE](/windows/win32/winmsg/wm-cancelmode) . (Substitui `CMCToolBarButton::OnCancelMode`.)|
|[CMFCDropDownToolbarButton::OnChangeParentWnd](#onchangeparentwnd)|Chamado pelo Framework quando o botão é inserido em uma nova barra de ferramentas. (Substitui [CMFCToolBarButton:: OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|
|[CMFCDropDownToolbarButton::OnClick](#onclick)|Chamado pelo Framework quando o usuário clica no botão do mouse. (Substitui [CMFCToolBarButton:: OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|
|[CMFCDropDownToolbarButton::OnClickUp](#onclickup)|Chamado pelo Framework quando o usuário libera o botão do mouse. (Substitui [CMFCToolBarButton:: OnClickUp](../../mfc/reference/cmfctoolbarbutton-class.md#onclickup).)|
|[CMFCDropDownToolbarButton::OnContextHelp](#oncontexthelp)|Chamado pelo Framework quando a barra de ferramentas pai manipula uma mensagem WM_HELPHITTEST. (Substitui [CMFCToolBarButton:: OnContextHelp](../../mfc/reference/cmfctoolbarbutton-class.md#oncontexthelp).)|
|[CMFCDropDownToolbarButton::OnCustomizeMenu](#oncustomizemenu)|Modifica o menu fornecido quando o aplicativo exibe um menu de atalho na barra de ferramentas pai. (Substitui [CMFCToolBarButton:: OnCustomizeMenu](../../mfc/reference/cmfctoolbarbutton-class.md#oncustomizemenu).)|
|[CMFCDropDownToolbarButton::OnDraw](#ondraw)|Chamado pelo Framework para desenhar o botão usando os estilos e as opções especificadas. (Substitui [CMFCToolBarButton:: OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|
|[CMFCDropDownToolbarButton::OnDrawOnCustomizeList](#ondrawoncustomizelist)|Chamado pelo Framework para desenhar o botão no painel **comandos** da caixa de diálogo **Personalizar** . (Substitui [CMFCToolBarButton:: OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|
|[CMFCDropDownToolbarButton:: Serialize](#serialize)|Lê este objeto de um arquivo ou grava-o em um arquivo morto. (Substitui [CMFCToolBarButton:: Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|
|[CMFCDropDownToolbarButton::SetDefaultCommand](#setdefaultcommand)|Define o comando padrão usado pela estrutura quando um usuário clica no botão.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownToolbarButton::m_uiShowBarDelay](#m_uishowbardelay)|Especifica o período de tempo que um usuário deve manter o botão do mouse pressionado antes que a barra de ferramentas suspensa seja exibida.|

## <a name="remarks"></a>Comentários

Um `CMFCDropDownToolBarButton` é diferente de um botão comum, pois ele tem uma pequena seta no canto inferior direito do botão. Depois que o usuário seleciona um botão na barra de ferramentas suspensa, a estrutura exibe seu ícone no botão de barra de ferramentas de nível superior (o botão com a seta pequena no canto inferior direito).

Para obter informações sobre como implementar uma barra de ferramentas suspensa, consulte [Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md).

O `CMFCDropDownToolBarButton` objeto pode ser exportado para um objeto de [Classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md) e exibido como um botão de menu com um menu pop-up.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)

[CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdropdowntoolbar. h

##  <a name="copyfrom"></a>CMFCDropDownToolbarButton::CopyFrom

Copia as propriedades de outro botão da barra de ferramentas para o botão atual.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
no Uma referência ao botão de origem a partir do qual copiar.

### <a name="remarks"></a>Comentários

Chame esse método para copiar outro botão da barra de ferramentas para este botão da barra de ferramentas. *src* deve ser do tipo `CMFCDropDownToolbarButton`.

##  <a name="cmfcdropdowntoolbarbutton"></a>CMFCDropDownToolbarButton::CMFCDropDownToolbarButton

Constrói um objeto `CMFCDropDownToolbarButton`.

```
CMFCDropDownToolbarButton();

CMFCDropDownToolbarButton(
    LPCTSTR lpszName,
    CMFCDropDownToolBar* pToolBar);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
no O texto padrão do botão.

*pToolBar*<br/>
no Um ponteiro para o `CMFCDropDownToolBar` objeto que é exibido quando o usuário pressiona o botão.

### <a name="remarks"></a>Comentários

A segunda sobrecarga do construtor copia para o botão suspenso o primeiro botão da barra de ferramentas que o *pToolBar* especifica.

Normalmente, um botão de barra de ferramentas suspensa usa o texto do botão usado mais recentemente na barra de ferramentas que o *pToolBar* especifica. Ele usa o texto especificado por *lpszName* quando o botão é convertido em um botão de menu ou é exibido na guia **comandos** da caixa de diálogo **Personalizar** . Para obter mais informações sobre a caixa de diálogo **Personalizar** , consulte [Classe CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto da `CMFCDropDownToolbarButton` classe. Este trecho de código faz parte do [exemplo de demonstração do Visual Studio](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#31](../../mfc/codesnippet/cpp/cmfcdropdowntoolbarbutton-class_1.cpp)]

##  <a name="dropdowntoolbar"></a>CMFCDropDownToolbarButton::D ropDownToolbar

Abre uma barra de ferramentas suspensa.

```
BOOL DropDownToolbar(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no A janela pai do quadro suspenso ou nulo para usar a janela pai do botão da barra de ferramentas suspensa.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o método for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O método [CMFCDropDownToolbarButton:: OnClick](#onclick) chama esse método para abrir a barra de ferramentas suspensa quando o usuário pressiona e mantém o botão da barra de ferramentas pressionado.

Esses métodos criam a barra de ferramentas suspensa usando o método [CMFCDropDownFrame:: Create](../../mfc/reference/cmfcdropdownframe-class.md#create) . Se a barra de ferramentas pai estiver encaixada verticalmente, esse método posicionará a barra de ferramentas suspensa no lado esquerdo ou direito da barra de ferramentas pai, dependendo do ajuste. Caso contrário, esse método posiciona a barra de ferramentas suspensa abaixo da barra de ferramentas pai.

Esse método falhará se *pWnd* for nulo e o botão da barra de ferramentas suspensa não tiver uma janela pai.

##  <a name="exporttomenubutton"></a>CMFCDropDownToolbarButton::ExportToMenuButton

Copia o texto do botão da barra de ferramentas para um menu.

```
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;
```

### <a name="parameters"></a>Parâmetros

*menuButton*<br/>
no Uma referência ao botão de menu de destino.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o método tiver sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método chama a implementação da classe base ( [CMFCToolBarButton:: ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)) e, em seguida, anexa ao botão de menu de destino um menu pop-up que contém cada item de menu da barra de ferramentas neste botão. Esse método não adiciona submenus ao menu pop-up.

Esse método falhará se a barra de `m_pToolBar`ferramentas pai,, for nula ou a implementação da classe base retornar false.

##  <a name="getdropdowntoolbar"></a>CMFCDropDownToolbarButton::GetDropDownToolBar

Recupera a barra de ferramentas suspensa associada ao botão.

```
CMFCToolBar* GetDropDownToolBar() const;
```

### <a name="return-value"></a>Valor de retorno

A barra de ferramentas suspensa associada ao botão.

### <a name="remarks"></a>Comentários

Esse método retorna o `m_pToolBar` membro de dados.

##  <a name="isdropdown"></a>  CMFCDropDownToolbarButton::IsDropDown

Determina se a barra de ferramentas suspensa está aberta no momento.

```
BOOL IsDropDown() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a barra de ferramentas suspensa estiver aberta no momento; caso contrário, 0.

### <a name="remarks"></a>Comentários

A estrutura abre a barra de ferramentas suspensa usando o método [CMFCDropDownToolbarButton::D ropdowntoolbar](#dropdowntoolbar) . A estrutura fecha a barra de ferramentas suspensa quando o usuário pressiona o botão esquerdo do mouse na área de não-cliente da barra de ferramentas suspensa.

##  <a name="isextrasize"></a>CMFCDropDownToolbarButton::IsExtraSize

Determina se o botão pode ser exibido com uma borda estendida.

```
virtual BOOL IsExtraSize() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão da barra de ferramentas puder ser exibido com uma borda estendida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre bordas estendidas, consulte [CMFCToolBarButton:: IsExtraSize](../../mfc/reference/cmfctoolbarbutton-class.md#isextrasize).

##  <a name="m_uishowbardelay"></a>  CMFCDropDownToolbarButton::m_uiShowBarDelay

Especifica o período de tempo que um usuário deve manter o botão do mouse pressionado antes que a barra de ferramentas suspensa seja exibida.

```
static UINT m_uiShowBarDelay;
```

### <a name="remarks"></a>Comentários

O tempo de atraso é medido em milissegundos. O valor padrão é 500. Você pode definir outro atraso alterando o valor desse membro de dados compartilhados.

##  <a name="oncalculatesize"></a>CMFCDropDownToolbarButton::OnCalculateSize

Chamado pelo Framework para calcular o tamanho do botão para o contexto do dispositivo especificado e o estado de encaixe.

```
virtual SIZE OnCalculateSize(
    CDC* pDC,
    const CSize& sizeDefault,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no O contexto do dispositivo que exibe o botão.

*sizeDefault*<br/>
no O tamanho padrão do botão.

*bHorz*<br/>
no O estado de encaixe da barra de ferramentas pai. Esse parâmetro será TRUE se a barra de ferramentas for encaixada horizontalmente ou for flutuante, ou FALSE se a barra de ferramentas for encaixada verticalmente.

### <a name="return-value"></a>Valor de retorno

Uma `SIZE` estrutura que contém as dimensões do botão, em pixels.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize)) adicionando a largura da seta suspensa à dimensão horizontal do tamanho do botão.

##  <a name="onchangeparentwnd"></a>  CMFCDropDownToolbarButton::OnChangeParentWnd

Chamado pelo Framework quando o botão é inserido em uma nova barra de ferramentas.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no A nova janela pai.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base ( [CMFCToolBarButton:: OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)) limpando o rótulo de texto ( [CMFCToolBarButton:: m_strText](../../mfc/reference/cmfctoolbarbutton-class.md#m_strtext)) e definindo [CMFCToolBarButton:: m_bText](../../mfc/reference/cmfctoolbarbutton-class.md#m_btext) e [CMFCToolBarButton :: m_bUserButton](../../mfc/reference/cmfctoolbarbutton-class.md#m_buserbutton) os membros de dados como false.

##  <a name="onclick"></a>CMFCDropDownToolbarButton:: OnClick

Chamado pelo Framework quando o usuário clica no botão do mouse.

```
virtual BOOL OnClick(
    CWnd* pWnd,
    BOOL bDelay = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no A janela pai do botão da barra de ferramentas.

*bDelay*<br/>
no TRUE se a mensagem deve ser manipulada com um atraso.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão processar a mensagem de clique; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base, [CMFCToolBarButton:: OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick), atualizando o estado da barra de ferramentas suspensa.

Quando um usuário clica no botão da barra de ferramentas, esse método cria um temporizador que aguarda o período especificado pelo membro de dados [CMFCDropDownToolbarButton:: m_uiShowBarDelay](#m_uishowbardelay) e, em seguida, abre a barra de ferramentas suspensa usando o [CMFCDropDownToolbarButton ::D método ropDownToolbar](#dropdowntoolbar) . Esse método fecha a barra de ferramentas suspensa na segunda vez em que o usuário clica no botão da barra de ferramentas.

##  <a name="onclickup"></a>  CMFCDropDownToolbarButton::OnClickUp

Chamado pelo Framework quando o usuário libera o botão do mouse.

```
virtual BOOL OnClickUp();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão processar a mensagem de clique; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base, [CMFCToolBarButton:: OnClickUp](../../mfc/reference/cmfctoolbarbutton-class.md#onclickup), atualizando o estado da barra de ferramentas suspensa.

Esse método interrompe o temporizador da barra de ferramentas suspensa se ele estiver ativo. Ele fecha a barra de ferramentas suspensa se ela estiver aberta.

Para obter mais informações sobre a barra de ferramentas suspensa e o temporizador da barra de ferramentas suspensa, consulte [CMFCDropDownToolbarButton:: OnClick](#onclick).

##  <a name="oncontexthelp"></a>  CMFCDropDownToolbarButton::OnContextHelp

Chamado pelo Framework quando a barra de ferramentas pai manipula uma mensagem WM_HELPHITTEST.

```
virtual BOOL OnContextHelp(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no A janela pai do botão da barra de ferramentas.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão processar a mensagem de ajuda; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnContextHelp](../../mfc/reference/cmfctoolbarbutton-class.md#oncontexthelp)) chamando o método [CMFCDropDownToolbarButton:: OnClick](#onclick) com *bDelay* definido como false. Esse método retorna o valor retornado por [CMFCDropDownToolbarButton:: OnClick](#onclick).

Para obter mais informações sobre a mensagem WM_HELPHITTEST, [consulte TN028: Suporte](../../mfc/tn028-context-sensitive-help-support.md)de ajuda contextual.

##  <a name="oncustomizemenu"></a>CMFCDropDownToolbarButton::OnCustomizeMenu

Modifica o menu fornecido quando o aplicativo exibe um menu de atalho na barra de ferramentas pai.

```
virtual BOOL OnCustomizeMenu(CMenu* pMenu);
```

### <a name="parameters"></a>Parâmetros

*pMenu*<br/>
no O menu a ser personalizado.

### <a name="return-value"></a>Valor de retorno

Esse método retorna TRUE.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnCustomizeMenu](../../mfc/reference/cmfctoolbarbutton-class.md#oncustomizemenu)) desabilitando os seguintes itens de menu:

- **Copiar imagem do botão**

- **Aparência do botão**

- **Image**

- **Texto**

- **Imagem e texto**

Substitua esse método para modificar o menu de atalho que a estrutura exibe no modo de personalização.

##  <a name="ondraw"></a>CMFCDropDownToolbarButton:: OnDraw

Chamado pelo Framework para desenhar o botão usando os estilos e as opções especificadas.

```
virtual void OnDraw(
    CDC* pDC,
    const CRect& rect,
    CMFCToolBarImages* pImages,
    BOOL bHorz = TRUE,
    BOOL bCustomizeMode = FALSE,
    BOOL bHighlight = FALSE,
    BOOL bDrawBorder = TRUE,
    BOOL bGrayDisabledButtons = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no O contexto do dispositivo que exibe o botão.

*rect*<br/>
no O retângulo delimitador do botão.

*pImages*<br/>
no A coleção de imagens da barra de ferramentas que está associada ao botão.

*bHorz*<br/>
no O estado de encaixe da barra de ferramentas pai. Esse parâmetro é TRUE quando o botão é encaixado horizontalmente e falso quando o botão é encaixado verticalmente.

*bCustomizeMode*<br/>
no Especifica se a barra de ferramentas está no modo de personalização. Esse parâmetro é TRUE quando a barra de ferramentas está no modo de personalização e FALSE quando a barra de ferramentas não está no modo de personalização.

*bHighlight*<br/>
no Especifica se o botão está realçado. Esse parâmetro é TRUE quando o botão é realçado e FALSE quando o botão não é realçado.

*bDrawBorder*<br/>
no Especifica se o botão deve exibir sua borda. Esse parâmetro é TRUE quando o botão deve exibir sua borda e FALSE quando o botão não deve exibir sua borda.

*bGrayDisabledButtons*<br/>
no Especifica se os botões desabilitados devem ser sombreados ou usar a coleção de imagens desabilitadas. Esse parâmetro é TRUE quando os botões desabilitados devem ser sombreados e FALSE quando esse método deve usar a coleção de imagens desabilitadas.

### <a name="remarks"></a>Comentários

Substitua esse método para personalizar o desenho de botão da barra de ferramentas.

##  <a name="ondrawoncustomizelist"></a>CMFCDropDownToolbarButton::OnDrawOnCustomizeList

Chamado pelo Framework para desenhar o botão no painel **comandos** da caixa de diálogo **Personalizar** .

```
virtual int OnDrawOnCustomizeList(
    CDC* pDC,
    const CRect& rect,
    BOOL bSelected);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no O contexto do dispositivo que exibe o botão.

*rect*<br/>
no O retângulo delimitador do botão.

*bSelected*<br/>
no Se o botão está selecionado. Se esse parâmetro for TRUE, o botão será selecionado. Se esse parâmetro for FALSE, o botão não será selecionado.

### <a name="return-value"></a>Valor de retorno

A largura, em pixels, do botão no contexto do dispositivo especificado.

### <a name="remarks"></a>Comentários

Esse método é chamado pela caixa de diálogo de personalização (guia **comandos** ) quando o botão é necessário para se exibir na caixa de listagem proprietário-desenho.

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist)) alterando o rótulo de texto do botão para o nome do botão (ou seja, para o valor do parâmetro *lpszName* que você passou para o Construtor ).

##  <a name="serialize"></a>CMFCDropDownToolbarButton:: Serialize

Lê este objeto de um arquivo ou grava-o em um arquivo morto.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
no O `CArchive` objeto do qual ou para o qual serializar.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize)) serializando a ID de recurso da barra de ferramentas pai. Quando o arquivo está sendo carregado ( [CArchive::](../../mfc/reference/carchive-class.md#isloading) isuploading retorna um valor diferente de zero), esse `m_pToolBar` método define o membro de dados para a barra de ferramentas que contém a ID do recurso serializado.

##  <a name="setdefaultcommand"></a>CMFCDropDownToolbarButton::SetDefaultCommand

Define o comando padrão usado pela estrutura quando um usuário clica no botão.

```
void SetDefaultCommand(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID do comando padrão.

### <a name="remarks"></a>Comentários

Chame esse método para especificar um comando padrão que a estrutura executará quando o usuário clicar no botão. Um item com a ID de comando especificada por *uiCmd* deve estar localizado na barra de ferramentas suspensa pai.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md)<br/>
[Passo a passo: colocar controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
