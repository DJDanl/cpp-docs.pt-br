---
title: Classe CMFCDropDownToolbarButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c113ce68cf609970342d69ebc03f700e17c7e2a9
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50064299"
---
# <a name="cmfcdropdowntoolbarbutton-class"></a>Classe CMFCDropDownToolbarButton

Um tipo de botão de barra de ferramentas que se comporta como um botão regular quando é clicado. No entanto, ele abre uma lista suspensa de barra de ferramentas ( [classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md) se o usuário pressiona e mantém o botão de barra de ferramentas para baixo.

## <a name="syntax"></a>Sintaxe

```
class CMFCDropDownToolbarButton : public CMFCToolBarButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownToolbarButton::CMFCDropDownToolbarButton](#cmfcdropdowntoolbarbutton)|Constrói um objeto `CMFCDropDownToolbarButton`.|
|`CMFCDropDownToolbarButton::~CMFCDropDownToolbarButton`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownToolbarButton::CopyFrom](#copyfrom)|Copia as propriedades de outro botão de barra de ferramentas para o botão atual. (Substitui [CMFCToolBarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|
|`CMFCDropDownToolbarButton::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|[CMFCDropDownToolbarButton::DropDownToolbar](#dropdowntoolbar)|Abre uma lista suspensa de barra de ferramentas.|
|[CMFCDropDownToolbarButton::ExportToMenuButton](#exporttomenubutton)|Copia o texto do botão da barra de ferramentas a um menu. (Substitui [CMFCToolBarButton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton).)|
|[CMFCDropDownToolbarButton::GetDropDownToolBar](#getdropdowntoolbar)|Recupera a barra de ferramentas do menu suspenso que está associada com o botão.|
|`CMFCDropDownToolbarButton::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCDropDownToolbarButton::IsDropDown](#isdropdown)|Determina se a barra de ferramentas suspensa é aberta no momento.|
|[CMFCDropDownToolbarButton::IsExtraSize](#isextrasize)|Determina se o botão pode ser exibido com uma borda estendida. (Substitui [CMFCToolBarButton::IsExtraSize](../../mfc/reference/cmfctoolbarbutton-class.md#isextrasize).)|
|[CMFCDropDownToolbarButton::OnCalculateSize](#oncalculatesize)|Chamado pelo framework para calcular o tamanho do botão para o contexto de dispositivo especificado e o estado de encaixe. (Substitui [CMFCToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|
|`CMFCDropDownToolbarButton::OnCancelMode`|Chamado pelo framework para lidar com o [WM_CANCELMODE](/windows/desktop/winmsg/wm-cancelmode) mensagem. (Substitui `CMCToolBarButton::OnCancelMode`.)|
|[CMFCDropDownToolbarButton::OnChangeParentWnd](#onchangeparentwnd)|Chamado pelo framework quando o botão é inserido em uma nova barra de ferramentas. (Substitui [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|
|[CMFCDropDownToolbarButton::OnClick](#onclick)|Chamado pelo framework quando o usuário clica no botão do mouse. (Substitui [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|
|[CMFCDropDownToolbarButton::OnClickUp](#onclickup)|Chamado pelo framework quando o usuário libera o botão do mouse. (Substitui [CMFCToolBarButton::OnClickUp](../../mfc/reference/cmfctoolbarbutton-class.md#onclickup).)|
|[CMFCDropDownToolbarButton::OnContextHelp](#oncontexthelp)|Chamado pelo framework quando a barra de ferramentas pai trata uma mensagem WM_HELPHITTEST. (Substitui [CMFCToolBarButton::OnContextHelp](../../mfc/reference/cmfctoolbarbutton-class.md#oncontexthelp).)|
|[CMFCDropDownToolbarButton::OnCustomizeMenu](#oncustomizemenu)|Modifica o menu fornecido quando o aplicativo exibe um menu de atalho na barra de ferramentas pai. (Substitui [CMFCToolBarButton::OnCustomizeMenu](../../mfc/reference/cmfctoolbarbutton-class.md#oncustomizemenu).)|
|[CMFCDropDownToolbarButton::OnDraw](#ondraw)|Chamado pelo framework para desenhar o botão usando as opções e estilos especificados. (Substitui [CMFCToolBarButton::OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|
|[CMFCDropDownToolbarButton::OnDrawOnCustomizeList](#ondrawoncustomizelist)|Chamado pelo framework para desenhar o botão na **comandos** painel da **personalizar** caixa de diálogo. (Substitui [CMFCToolBarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|
|[CMFCDropDownToolbarButton::Serialize](#serialize)|Lê esse objeto de um arquivo morto ou grava-o em um arquivo morto. (Substitui [CMFCToolBarButton::Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|
|[CMFCDropDownToolbarButton::SetDefaultCommand](#setdefaultcommand)|Define o comando padrão que a estrutura usa quando um usuário clica no botão.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownToolbarButton::m_uiShowBarDelay](#m_uishowbardelay)|Especifica o período de tempo que um usuário deve pressionado o botão do mouse para que a lista suspensa de barra de ferramentas é exibida.|

## <a name="remarks"></a>Comentários

Um `CMFCDropDownToolBarButton` difere de um botão comum porque tem uma pequena seta no canto inferior direito do botão. Depois que o usuário seleciona um botão da barra de ferramentas lista suspensa, o framework exibe seu ícone no botão de barra de ferramentas de nível superior (o botão com a pequena seta no canto inferior direito).

Para obter informações sobre como implementar uma barra de ferramentas da lista suspensa, consulte [classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md).

O `CMFCDropDownToolBarButton` objeto pode ser exportado para um [classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md) do objeto e exibido como um botão de menu com um menu pop-up.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)

[CMFCDropDownToolbarButton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdropdowntoolbar.h

##  <a name="copyfrom"></a>  CMFCDropDownToolbarButton::CopyFrom

Copia as propriedades de outro botão de barra de ferramentas para o botão atual.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
[in] Uma referência para o botão de origem da qual copiar.

### <a name="remarks"></a>Comentários

Chame esse método para copiar de outro botão de barra de ferramentas para este botão de barra de ferramentas. *src* deve ser do tipo `CMFCDropDownToolbarButton`.

##  <a name="cmfcdropdowntoolbarbutton"></a>  CMFCDropDownToolbarButton::CMFCDropDownToolbarButton

Constrói um objeto `CMFCDropDownToolbarButton`.

```
CMFCDropDownToolbarButton();

CMFCDropDownToolbarButton(
    LPCTSTR lpszName,
    CMFCDropDownToolBar* pToolBar);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
[in] O texto padrão do botão.

*pToolBar*<br/>
[in] Um ponteiro para o `CMFCDropDownToolBar` objeto que é exibido quando o usuário pressiona o botão.

### <a name="remarks"></a>Comentários

A segunda sobrecarga do construtor copia para o botão suspenso no primeiro botão da barra de ferramentas que *pToolBar* especifica.

Normalmente, um botão de barra de ferramentas da lista suspensa usa o texto do botão usado mais recentemente na barra de ferramentas que *pToolBar* especifica. Ele usa o texto especificado pelo *lpszName* quando o botão é convertido em um botão de menu ou é exibido na **comandos** guia dos **personalizar** caixa de diálogo. Para obter mais informações sobre o **personalizar** caixa de diálogo, consulte [classe CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto do `CMFCDropDownToolbarButton` classe. Este trecho de código faz parte do [amostra de demonstração do Visual Studio](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#31](../../mfc/codesnippet/cpp/cmfcdropdowntoolbarbutton-class_1.cpp)]

##  <a name="dropdowntoolbar"></a>  CMFCDropDownToolbarButton::DropDownToolbar

Abre uma lista suspensa de barra de ferramentas.

```
BOOL DropDownToolbar(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Apropriei*<br/>
[in] A janela pai do quadro da lista suspensa, ou nulo para usar a janela pai do botão de barra de ferramentas da lista suspensa.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o método for bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

O [CMFCDropDownToolbarButton::OnClick](#onclick) método chama esse método para abrir a barra de ferramentas da lista suspensa quando o usuário pressiona e mantém o botão de barra de ferramentas para baixo.

Esse método cria a lista suspensa de barra de ferramentas usando o [CMFCDropDownFrame::Create](../../mfc/reference/cmfcdropdownframe-class.md#create) método. Se a barra de ferramentas pai estiver encaixada verticalmente, esse método posiciona a barra de ferramentas da lista suspensa para o lado esquerdo ou direito da barra de ferramentas pai, dependendo do ajuste. Caso contrário, esse método posiciona a barra de ferramentas de lista suspensa abaixo da barra de ferramentas pai.

Esse método falhar se *Apropriei* for NULL e o botão de barra de ferramentas de lista suspensa não tem uma janela pai.

##  <a name="exporttomenubutton"></a>  CMFCDropDownToolbarButton::ExportToMenuButton

Copia o texto do botão da barra de ferramentas a um menu.

```
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;
```

### <a name="parameters"></a>Parâmetros

*Botão de menu*<br/>
[in] Uma referência para o botão de menu de destino.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o método for bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método chama a implementação da classe base ( [CMFCToolBarButton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)) e, em seguida, acrescenta ao botão de menu de destino um menu pop-up que contém cada item de menu da barra de ferramentas nesse botão. Esse método não anexa submenus no menu pop-up.

Esse método falhará se a barra de ferramentas do pai, `m_pToolBar`, é NULL ou a implementação de classe base retorna FALSE.

##  <a name="getdropdowntoolbar"></a>  CMFCDropDownToolbarButton::GetDropDownToolBar

Recupera a barra de ferramentas do menu suspenso que está associada com o botão.

```
CMFCToolBar* GetDropDownToolBar() const;
```

### <a name="return-value"></a>Valor de retorno

A barra de ferramentas de lista suspensa que está associada com o botão.

### <a name="remarks"></a>Comentários

Esse método retorna o `m_pToolBar` membro de dados.

##  <a name="isdropdown"></a>  CMFCDropDownToolbarButton::IsDropDown

Determina se a barra de ferramentas suspensa é aberta no momento.

```
BOOL IsDropDown() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a lista suspensa de barra de ferramentas está atualmente aberta. Caso contrário, 0.

### <a name="remarks"></a>Comentários

O framework abre a barra de ferramentas suspenso usando o [CMFCDropDownToolbarButton::DropDownToolbar](#dropdowntoolbar) método. O framework fecha a barra de ferramentas da lista suspensa quando o usuário pressiona o botão esquerdo do mouse na área não cliente da lista suspensa de barra de ferramentas.

##  <a name="isextrasize"></a>  CMFCDropDownToolbarButton::IsExtraSize

Determina se o botão pode ser exibido com uma borda estendida.

```
virtual BOOL IsExtraSize() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão de barra de ferramentas pode ser exibido com uma borda estendida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre bordas estendidas, consulte [CMFCToolBarButton::IsExtraSize](../../mfc/reference/cmfctoolbarbutton-class.md#isextrasize).

##  <a name="m_uishowbardelay"></a>  CMFCDropDownToolbarButton::m_uiShowBarDelay

Especifica o período de tempo que um usuário deve pressionado o botão do mouse para que a lista suspensa de barra de ferramentas é exibida.

```
static UINT m_uiShowBarDelay;
```

### <a name="remarks"></a>Comentários

O tempo de atraso é medido em milissegundos. O valor padrão é 500. Você pode definir outro atraso, alterando o valor desse membro de dados compartilhada.

##  <a name="oncalculatesize"></a>  CMFCDropDownToolbarButton::OnCalculateSize

Chamado pelo framework para calcular o tamanho do botão para o contexto de dispositivo especificado e o estado de encaixe.

```
virtual SIZE OnCalculateSize(
    CDC* pDC,
    const CSize& sizeDefault,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] O contexto de dispositivo que exibe o botão.

*sizeDefault*<br/>
[in] O tamanho padrão do botão.

*bHorz*<br/>
[in] O estado de encaixe da barra de ferramentas pai. Esse parâmetro é TRUE se a barra de ferramentas é encaixada horizontalmente ou for flutuante, ou FALSE se a barra de ferramentas é encaixada verticalmente.

### <a name="return-value"></a>Valor de retorno

Um `SIZE` estrutura que contém as dimensões do botão, em pixels.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base ( [CMFCToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize)), adicionando a largura da seta suspensa para a dimensão horizontal do tamanho do botão.

##  <a name="onchangeparentwnd"></a>  CMFCDropDownToolbarButton::OnChangeParentWnd

Chamado pelo framework quando o botão é inserido em uma nova barra de ferramentas.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[in] A nova janela pai.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base ( [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)), limpando o rótulo de texto ( [CMFCToolBarButton::m_strText](../../mfc/reference/cmfctoolbarbutton-class.md#m_strtext)) e configurando o [ CMFCToolBarButton::m_bText](../../mfc/reference/cmfctoolbarbutton-class.md#m_btext) e [CMFCToolBarButton::m_bUserButton](../../mfc/reference/cmfctoolbarbutton-class.md#m_buserbutton) membros de dados como FALSE.

##  <a name="onclick"></a>  CMFCDropDownToolbarButton::OnClick

Chamado pelo framework quando o usuário clica no botão do mouse.

```
virtual BOOL OnClick(
    CWnd* pWnd,
    BOOL bDelay = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Apropriei*<br/>
[in] A janela pai do botão de barra de ferramentas.

*bDelay*<br/>
[in] TRUE se a mensagem deve ser tratada com um atraso.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão processa a mensagem de clique; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método estende a implementação de classe base [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick), atualizando o estado da barra de ferramentas de lista suspensa.

Quando um usuário clica no botão de barra de ferramentas, esse método cria um temporizador que aguarda o período de tempo especificado pelo [CMFCDropDownToolbarButton::m_uiShowBarDelay](#m_uishowbardelay) membro de dados e, em seguida, abre na lista suspensa de barra de ferramentas usando o [CMFCDropDownToolbarButton::DropDownToolbar](#dropdowntoolbar) método. Este método fecha a barra de ferramentas da lista suspensa na segunda vez que o usuário clica no botão de barra de ferramentas.

##  <a name="onclickup"></a>  CMFCDropDownToolbarButton::OnClickUp

Chamado pelo framework quando o usuário libera o botão do mouse.

```
virtual BOOL OnClickUp();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão processa a mensagem de clique; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método estende a implementação de classe base [CMFCToolBarButton::OnClickUp](../../mfc/reference/cmfctoolbarbutton-class.md#onclickup), atualizando o estado da barra de ferramentas de lista suspensa.

Esse método interrompe o temporizador de barra de ferramentas da lista suspensa, se ele estiver ativo. Se ele estiver aberto, ele fecha a barra de ferramentas da lista suspensa.

Para obter mais informações sobre a lista suspensa da barra de ferramentas e o timer de lista suspensa da barra de ferramentas, consulte [CMFCDropDownToolbarButton::OnClick](#onclick).

##  <a name="oncontexthelp"></a>  CMFCDropDownToolbarButton::OnContextHelp

Chamado pelo framework quando a barra de ferramentas pai trata uma mensagem WM_HELPHITTEST.

```
virtual BOOL OnContextHelp(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Apropriei*<br/>
[in] A janela pai do botão de barra de ferramentas.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão processa a mensagem de ajuda; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base ( [CMFCToolBarButton::OnContextHelp](../../mfc/reference/cmfctoolbarbutton-class.md#oncontexthelp)) por meio da chamada a [CMFCDropDownToolbarButton::OnClick](#onclick) método com *bDelay*definido como FALSE. Esse método retorna o valor retornado por [CMFCDropDownToolbarButton::OnClick](#onclick).

Para obter mais informações sobre a mensagem WM_HELPHITTEST, consulte [TN028: suporte a Ajuda contextual](../../mfc/tn028-context-sensitive-help-support.md).

##  <a name="oncustomizemenu"></a>  CMFCDropDownToolbarButton::OnCustomizeMenu

Modifica o menu fornecido quando o aplicativo exibe um menu de atalho na barra de ferramentas pai.

```
virtual BOOL OnCustomizeMenu(CMenu* pMenu);
```

### <a name="parameters"></a>Parâmetros

*pMenu*<br/>
[in] Menu para personalizar.

### <a name="return-value"></a>Valor de retorno

Esse método retornará TRUE.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base ( [CMFCToolBarButton::OnCustomizeMenu](../../mfc/reference/cmfctoolbarbutton-class.md#oncustomizemenu)) desabilitando os seguintes itens de menu:

- **Imagem do botão de cópia**

- **Aparência do botão**

- **Image**

- **Texto**

- **Imagem e texto**

Substitua este método para modificar o menu de atalho que o framework exibe no modo de personalização.

##  <a name="ondraw"></a>  CMFCDropDownToolbarButton::OnDraw

Chamado pelo framework para desenhar o botão usando as opções e estilos especificados.

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
[in] O contexto de dispositivo que exibe o botão.

*Rect*<br/>
[in] O retângulo delimitador do botão.

*pImages*<br/>
[in] A coleção de imagens da barra de ferramentas que está associada com o botão.

*bHorz*<br/>
[in] O estado de encaixe da barra de ferramentas pai. Esse parâmetro é verdadeiro quando o botão está ancorado horizontalmente e FALSE quando o botão estiver encaixado verticalmente.

*bCustomizeMode*<br/>
[in] Especifica se a barra de ferramentas está no modo de personalização. Esse parâmetro é verdadeiro quando a barra de ferramentas está no modo de personalização e FALSE quando a barra de ferramentas não está no modo de personalização.

*bHighlight*<br/>
[in] Especifica se o botão está realçado. Esse parâmetro é verdadeiro quando o botão está realçado e FALSE quando o botão não esteja realçado.

*bDrawBorder*<br/>
[in] Especifica se o botão deve exibir sua borda. Esse parâmetro é verdadeiro quando o botão deve exibir sua borda e FALSE quando o botão não deve exibir sua borda.

*bGrayDisabledButtons*<br/>
[in] Especifica se deve sombrear botões desabilitados ou usar a coleção de imagens desabilitado. Esse parâmetro é verdadeiro quando botões desabilitados devem ser sombreadas e FALSE quando este método deve usar a coleção de imagens desabilitado.

### <a name="remarks"></a>Comentários

Substitua este método para personalizar o desenho do botão de barra de ferramentas.

##  <a name="ondrawoncustomizelist"></a>  CMFCDropDownToolbarButton::OnDrawOnCustomizeList

Chamado pelo framework para desenhar o botão na **comandos** painel da **personalizar** caixa de diálogo.

```
virtual int OnDrawOnCustomizeList(
    CDC* pDC,
    const CRect& rect,
    BOOL bSelected);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] O contexto de dispositivo que exibe o botão.

*Rect*<br/>
[in] O retângulo delimitador do botão.

*bSelected*<br/>
[in] Se o botão é selecionado. Se esse parâmetro for TRUE, o botão é selecionado. Se esse parâmetro for FALSE, o botão não está selecionado.

### <a name="return-value"></a>Valor de retorno

A largura, em pixels, do botão no contexto de dispositivo especificado.

### <a name="remarks"></a>Comentários

Esse método é chamado pela caixa de diálogo de personalização ( **comandos** guia) quando o botão é necessário para exibir a mesmo na caixa de listagem do desenho proprietário.

Este método estende a implementação da classe base ( [CMFCToolBarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist)), alterando o rótulo de texto do botão para o nome do botão (ou seja, para o valor da *lpszName* parâmetro que é passado para o construtor).

##  <a name="serialize"></a>  CMFCDropDownToolbarButton::Serialize

Lê esse objeto de um arquivo morto ou grava-o em um arquivo morto.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
[in] O `CArchive` objeto do qual ou para a qual serializar.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base ( [CMFCToolBarButton::Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize)) serializando a ID de recurso da barra de ferramentas pai. Quando o arquivo morto está carregando ( [CArchive::IsLoading](../../mfc/reference/carchive-class.md#isloading) retorna um valor diferente de zero), esse método define o `m_pToolBar` membro de dados para a barra de ferramentas que contém a ID de recurso serializado.

##  <a name="setdefaultcommand"></a>  CMFCDropDownToolbarButton::SetDefaultCommand

Define o comando padrão que a estrutura usa quando um usuário clica no botão.

```
void SetDefaultCommand(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
[in] A ID do comando padrão.

### <a name="remarks"></a>Comentários

Chame esse método para especificar um comando padrão que a estrutura executa quando o usuário clica no botão. Um item com a ID de comando especificada por *uiCmd* deve estar localizado na barra de ferramentas da lista suspensa do pai.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md)<br/>
[Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)

