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
ms.openlocfilehash: d62d5ecb0962f74a5dac1658c207cfb08cf12588
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367615"
---
# <a name="cmfcdropdowntoolbarbutton-class"></a>Classe CMFCDropDownToolbarButton

Um tipo de botão de barra de ferramentas que se comporta como um botão normal quando é clicado. No entanto, ele abre uma barra de ferramentas para dada [(CMFCDropDownToolBar Class](../../mfc/reference/cmfcdropdowntoolbar-class.md) se o usuário pressionar e segurar o botão da barra de ferramentas para baixo.

## <a name="syntax"></a>Sintaxe

```
class CMFCDropDownToolbarButton : public CMFCToolBarButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownToolbarBotão:CMFCDropDownToolbarBotão](#cmfcdropdowntoolbarbutton)|Constrói um objeto `CMFCDropDownToolbarButton`.|
|`CMFCDropDownToolbarButton::~CMFCDropDownToolbarButton`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownToolbarBotão::CopiarDe](#copyfrom)|Copia as propriedades de outro botão de barra de ferramentas para o botão atual. (Substitui [cmfctoolbarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|
|`CMFCDropDownToolbarButton::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCDropDownToolbarBotão::DropDownToolbar](#dropdowntoolbar)|Abre uma barra de ferramentas para dada.|
|[CMFCDropDownBarra de ferramentasButton::ExportToMenuButton](#exporttomenubutton)|Copia o texto do botão da barra de ferramentas para um menu. (Substitui [cmfcToolBarButton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton).)|
|[CMFCDropDownToolbarBotão::GetDropDownToolBar](#getdropdowntoolbar)|Recupera a barra de ferramentas que está associada ao botão.|
|`CMFCDropDownToolbarButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCDropDownToolbarBotão::IsDropDown](#isdropdown)|Determina se a barra de ferramentas está aberta no momento.|
|[CMFCDropDownToolbarBotão:IsExtraSize](#isextrasize)|Determina se o botão pode ser exibido com uma borda estendida. (Substitui [cmfctoolbarButton::IsExtraSize](../../mfc/reference/cmfctoolbarbutton-class.md#isextrasize).)|
|[CMFCDropDownBarra de ferramentasButton::OnCalculateSize](#oncalculatesize)|Chamado pela estrutura para calcular o tamanho do botão para o contexto do dispositivo especificado e o estado de acoplamento. (Substitui [cmfcToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|
|`CMFCDropDownToolbarButton::OnCancelMode`|Chamado pelo quadro para lidar com a [mensagem WM_CANCELMODE.](/windows/win32/winmsg/wm-cancelmode) (Substitui `CMCToolBarButton::OnCancelMode`.)|
|[CMFCDropDownToolbarBotão:OnChangeParentWnd](#onchangeparentwnd)|Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas. (Substitui [cmfctoolbarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|
|[CMFCDropDownToolbarBotão::OnClick](#onclick)|Chamado pela estrutura quando o usuário clica no botão do mouse. (Substitui [cmfctoolbarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|
|[CMFCDropDownToolbarBotão:OnClickUp](#onclickup)|Chamado pela estrutura quando o usuário libera o botão do mouse. (Substitui [cmfctoolbarButton::OnClickUp](../../mfc/reference/cmfctoolbarbutton-class.md#onclickup).)|
|[CMFCDropDownToolbarBotão:OnContextHelp](#oncontexthelp)|Chamado pela framework quando a barra de ferramentas dos pais lida com uma mensagem WM_HELPHITTEST. (Substitui [cmfctoolbarButton::OnContextHelp](../../mfc/reference/cmfctoolbarbutton-class.md#oncontexthelp).)|
|[CMFCDropDownBarra de ferramentasButton::OnPersonalizarmenu](#oncustomizemenu)|Modifica o menu fornecido quando o aplicativo exibe um menu de atalho na barra de ferramentas pai. (Substitui [cmfctoolbarButton::OnPersonalizeMenu](../../mfc/reference/cmfctoolbarbutton-class.md#oncustomizemenu).)|
|[CMFCDropDownToolbarBotão::OnDraw](#ondraw)|Chamado pela estrutura para desenhar o botão usando os estilos e opções especificados. (Substitui [cmfctoolbarButton::OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|
|[CMFCDropDownToolbarBotão:OnDrawOnCustomizeList](#ondrawoncustomizelist)|Chamado pela estrutura para desenhar o botão no painel **Comandos** da caixa de diálogo **Personalizar.** (Substitui [cmfctoolbarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|
|[CMFCDropDownToolbarButton::Serialize](#serialize)|Lê este objeto de um arquivo ou grava-o em um arquivo. (Substitui [cmfctoolbarButton::Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|
|[CMFCDropDownBarra de ferramentasBotão::SetDefaultCommand](#setdefaultcommand)|Define o comando padrão que a estrutura usa quando um usuário clica no botão.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCDropDownBarra de ferramentasButton::m_uiShowBarDelay](#m_uishowbardelay)|Especifica o tempo que um usuário deve segurar o botão do mouse para baixo antes que a barra de ferramentas suspenso seja exibida.|

## <a name="remarks"></a>Comentários

A `CMFCDropDownToolBarButton` difere de um botão comum na forma de ter uma pequena seta no canto inferior direito do botão. Depois que o usuário seleciona um botão na barra de ferramentas para baixo, a estrutura exibe seu ícone no botão de barra de ferramentas de nível superior (o botão com a pequena seta no canto inferior direito).

Para obter informações sobre como implementar uma barra de ferramentas parada, consulte [CMFCDropDownToolBar Class](../../mfc/reference/cmfcdropdowntoolbar-class.md).

O `CMFCDropDownToolBarButton` objeto pode ser exportado para um objeto [CMFCToolBarMenuButton Class](../../mfc/reference/cmfctoolbarmenubutton-class.md) e exibido como um botão de menu com um menu pop-up.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfctoolbarbutton](../../mfc/reference/cmfctoolbarbutton-class.md)

[Cmfcdropdowntoolbarbutton](../../mfc/reference/cmfcdropdowntoolbarbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdropdowntoolbar.h

## <a name="cmfcdropdowntoolbarbuttoncopyfrom"></a><a name="copyfrom"></a>CMFCDropDownToolbarBotão::CopiarDe

Copia as propriedades de outro botão de barra de ferramentas para o botão atual.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
[em] Uma referência ao botão de origem a partir do qual copiar.

### <a name="remarks"></a>Comentários

Chame este método para copiar outro botão de barra de ferramentas para este botão de barra de ferramentas. *src* deve ser `CMFCDropDownToolbarButton`do tipo .

## <a name="cmfcdropdowntoolbarbuttoncmfcdropdowntoolbarbutton"></a><a name="cmfcdropdowntoolbarbutton"></a>CMFCDropDownToolbarBotão:CMFCDropDownToolbarBotão

Constrói um objeto `CMFCDropDownToolbarButton`.

```
CMFCDropDownToolbarButton();

CMFCDropDownToolbarButton(
    LPCTSTR lpszName,
    CMFCDropDownToolBar* pToolBar);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
[em] O texto padrão do botão.

*pToolBar*<br/>
[em] Um ponteiro `CMFCDropDownToolBar` para o objeto que é exibido quando o usuário pressiona o botão.

### <a name="remarks"></a>Comentários

A segunda sobrecarga do construtor copia para o botão de saque o primeiro botão da barra de ferramentas que *pToolBar* especifica.

Normalmente, um botão de barra de ferramentas para baixo usa o texto do botão usado mais recentemente na barra de ferramentas que *o pToolBar* especifica. Ele usa o texto especificado por *lpszName* quando o botão é convertido em um botão de menu ou é exibido na guia **Comandos** da caixa de diálogo **Personalizar.** Para obter mais informações sobre a caixa de diálogo **Personalizar,** consulte [CMFCToolBarsPersonalizeSala de diálogo](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCDropDownToolbarButton` construir um objeto da classe. Este trecho de código faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#31](../../mfc/codesnippet/cpp/cmfcdropdowntoolbarbutton-class_1.cpp)]

## <a name="cmfcdropdowntoolbarbuttondropdowntoolbar"></a><a name="dropdowntoolbar"></a>CMFCDropDownToolbarBotão::DropDownToolbar

Abre uma barra de ferramentas para dada.

```
BOOL DropDownToolbar(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] A janela pai do quadro drop-down ou NULL para usar a janela pai do botão barra de ferramentas gota.

### <a name="return-value"></a>Valor retornado

Não zero se o método for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O [cmfcdropdowntoolbarButton::O](#onclick) método OnClick chama este método para abrir a barra de ferramentas parabaixo quando o usuário pressiona e segura o botão da barra de ferramentas para baixo.

Esses métodos criam a barra de ferramentas para dada usando o método [CMFCDropDownFrame:::Criar.](../../mfc/reference/cmfcdropdownframe-class.md#create) Se a barra de ferramentas pai estiver encaixada verticalmente, este método posicionará a barra de ferramentas suspensa para o lado esquerdo ou direito da barra de ferramentas dos pais, dependendo do ajuste. Caso contrário, este método posiciona a barra de ferramentas parada abaixo da barra de ferramentas dos pais.

Este método falha se *o pWnd* for NULL e o botão de barra de ferramentas drop-down não tiver uma janela pai.

## <a name="cmfcdropdowntoolbarbuttonexporttomenubutton"></a><a name="exporttomenubutton"></a>CMFCDropDownBarra de ferramentasButton::ExportToMenuButton

Copia o texto do botão da barra de ferramentas para um menu.

```
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;
```

### <a name="parameters"></a>Parâmetros

*menuButton*<br/>
[em] Uma referência ao botão de menu de destino.

### <a name="return-value"></a>Valor retornado

Não zero se o método for bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método chama a implementação da classe base [(CMFCToolBarButton::ExportToMenuButton)](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)e, em seguida, anexa ao botão de menu de destino um menu pop-up que contém cada item do menu da barra de ferramentas neste botão. Este método não anexa submenus ao menu pop-up.

Este método falha se a `m_pToolBar`barra de ferramentas pai, , é NULL ou a implementação da classe base retorna FALSA.

## <a name="cmfcdropdowntoolbarbuttongetdropdowntoolbar"></a><a name="getdropdowntoolbar"></a>CMFCDropDownToolbarBotão::GetDropDownToolBar

Recupera a barra de ferramentas que está associada ao botão.

```
CMFCToolBar* GetDropDownToolBar() const;
```

### <a name="return-value"></a>Valor retornado

A barra de ferramentas parada que está associada ao botão.

### <a name="remarks"></a>Comentários

Este método `m_pToolBar` retorna o membro de dados.

## <a name="cmfcdropdowntoolbarbuttonisdropdown"></a><a name="isdropdown"></a>CMFCDropDownToolbarBotão::IsDropDown

Determina se a barra de ferramentas está aberta no momento.

```
BOOL IsDropDown() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a barra de ferramentas abaixada estiver atualmente aberta; caso contrário, 0.

### <a name="remarks"></a>Comentários

A estrutura abre a barra de ferramentas para baixo usando o método [CMFCDropDownToolbarButton::DropDownToolbar.](#dropdowntoolbar) A estrutura fecha a barra de ferramentas para baixo quando o usuário pressiona o botão do mouse esquerdo na área não cliente da barra de ferramentas gota.

## <a name="cmfcdropdowntoolbarbuttonisextrasize"></a><a name="isextrasize"></a>CMFCDropDownToolbarBotão:IsExtraSize

Determina se o botão pode ser exibido com uma borda estendida.

```
virtual BOOL IsExtraSize() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o botão da barra de ferramentas puder ser exibido com uma borda estendida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre fronteiras estendidas, consulte [CMFCToolBarButton::IsExtraSize](../../mfc/reference/cmfctoolbarbutton-class.md#isextrasize).

## <a name="cmfcdropdowntoolbarbuttonm_uishowbardelay"></a><a name="m_uishowbardelay"></a>CMFCDropDownBarra de ferramentasButton::m_uiShowBarDelay

Especifica o tempo que um usuário deve segurar o botão do mouse para baixo antes que a barra de ferramentas suspenso seja exibida.

```
static UINT m_uiShowBarDelay;
```

### <a name="remarks"></a>Comentários

O tempo de atraso é medido em milissegundos. O valor padrão é 500. Você pode definir outro atraso alterando o valor deste membro de dados compartilhados.

## <a name="cmfcdropdowntoolbarbuttononcalculatesize"></a><a name="oncalculatesize"></a>CMFCDropDownBarra de ferramentasButton::OnCalculateSize

Chamado pela estrutura para calcular o tamanho do botão para o contexto do dispositivo especificado e o estado de acoplamento.

```
virtual SIZE OnCalculateSize(
    CDC* pDC,
    const CSize& sizeDefault,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] O contexto do dispositivo que exibe o botão.

*tamanhoPadrão*<br/>
[em] O tamanho padrão do botão.

*Bhorz*<br/>
[em] O estado das docas da barra de ferramentas dos pais. Este parâmetro é VERDADEIRO se a barra de ferramentas estiver ancorada horizontalmente ou estiver flutuando, ou FALSA se a barra de ferramentas estiver encaixada verticalmente.

### <a name="return-value"></a>Valor retornado

Uma `SIZE` estrutura que contém as dimensões do botão, em pixels.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base [(CMFCToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize)) adicionando a largura da seta gota à dimensão horizontal do tamanho do botão.

## <a name="cmfcdropdowntoolbarbuttononchangeparentwnd"></a><a name="onchangeparentwnd"></a>CMFCDropDownToolbarBotão:OnChangeParentWnd

Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] A nova janela dos pais.

### <a name="remarks"></a>Comentários

Este método substitui a implementação da classe base [(CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)) limpando o rótulo de texto [(CMFCToolBarButton::m_strText)](../../mfc/reference/cmfctoolbarbutton-class.md#m_strtext)e definindo o [CMFCToolBarButton::m_bText](../../mfc/reference/cmfctoolbarbutton-class.md#m_btext) e [CMFCToolBarButton::m_bUserButton](../../mfc/reference/cmfctoolbarbutton-class.md#m_buserbutton) membros de dados para FALSE.

## <a name="cmfcdropdowntoolbarbuttononclick"></a><a name="onclick"></a>CMFCDropDownToolbarBotão::OnClick

Chamado pela estrutura quando o usuário clica no botão do mouse.

```
virtual BOOL OnClick(
    CWnd* pWnd,
    BOOL bDelay = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] A janela pai do botão da barra de ferramentas.

*bAtraso*<br/>
[em] VERDADE se a mensagem deve ser tratada com um atraso.

### <a name="return-value"></a>Valor retornado

Não zero se o botão processa a mensagem de clique; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método amplia a implementação da classe base, [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick), atualizando o estado da barra de ferramentas parada.

Quando um usuário clica no botão da barra de ferramentas, este método cria um temporizador que aguarda o tempo especificado pelo [CMFCDropDownToolbarButton::m_uiShowBarDelay](#m_uishowbardelay) membro de dados e, em seguida, abre a barra de ferramentas para baixo usando o método [CMFCDropDownToolbarButton::DropDownToolbar.](#dropdowntoolbar) Este método fecha a barra de ferramentas para baixo na segunda vez que o usuário clica no botão da barra de ferramentas.

## <a name="cmfcdropdowntoolbarbuttononclickup"></a><a name="onclickup"></a>CMFCDropDownToolbarBotão:OnClickUp

Chamado pela estrutura quando o usuário libera o botão do mouse.

```
virtual BOOL OnClickUp();
```

### <a name="return-value"></a>Valor retornado

Não zero se o botão processa a mensagem de clique; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método amplia a implementação da classe base, [CMFCToolBarButton::OnClickUp](../../mfc/reference/cmfctoolbarbutton-class.md#onclickup), atualizando o estado da barra de ferramentas parada.

Este método interrompe o temporizador da barra de ferramentas para baixo se estiver ativo. Ele fecha a barra de ferramentas drop-down se estiver aberta.

Para obter mais informações sobre a barra de ferramentas para dada e o temporizador da barra de ferramentas parada, consulte [CMFCDropDownToolbarButton::OnClick](#onclick).

## <a name="cmfcdropdowntoolbarbuttononcontexthelp"></a><a name="oncontexthelp"></a>CMFCDropDownToolbarBotão:OnContextHelp

Chamado pela framework quando a barra de ferramentas dos pais lida com uma mensagem WM_HELPHITTEST.

```
virtual BOOL OnContextHelp(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] A janela pai do botão da barra de ferramentas.

### <a name="return-value"></a>Valor retornado

Não zero se o botão processa a mensagem de ajuda; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base [(CMFCToolBarButton::OnContextHelp)](../../mfc/reference/cmfctoolbarbutton-class.md#oncontexthelp)chamando o [CMFCDropDownToolbarButton::OnClick](#onclick) método com *bDelay* definido como FALSE. Este método retorna o valor que é retornado pelo [CMFCDropDownToolbarButton::OnClick](#onclick).

Para obter mais informações sobre a mensagem WM_HELPHITTEST, consulte [TN028: Suporte de ajuda sensível ao contexto](../../mfc/tn028-context-sensitive-help-support.md).

## <a name="cmfcdropdowntoolbarbuttononcustomizemenu"></a><a name="oncustomizemenu"></a>CMFCDropDownBarra de ferramentasButton::OnPersonalizarmenu

Modifica o menu fornecido quando o aplicativo exibe um menu de atalho na barra de ferramentas pai.

```
virtual BOOL OnCustomizeMenu(CMenu* pMenu);
```

### <a name="parameters"></a>Parâmetros

*pMenu*<br/>
[em] O menu para personalizar.

### <a name="return-value"></a>Valor retornado

Este método retorna TRUE.

### <a name="remarks"></a>Comentários

Este método amplia a implementação da classe base [(CMFCToolBarButton::OnPersonalizeMenu)](../../mfc/reference/cmfctoolbarbutton-class.md#oncustomizemenu)desativando os seguintes itens de menu:

- **Imagem do botão de cópia**

- **Aparência do botão**

- **Imagem**

- **Texto**

- **Imagem e Texto**

Substituir este método para modificar o menu de atalho que a estrutura exibe no modo de personalização.

## <a name="cmfcdropdowntoolbarbuttonondraw"></a><a name="ondraw"></a>CMFCDropDownToolbarBotão::OnDraw

Chamado pela estrutura para desenhar o botão usando os estilos e opções especificados.

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
[em] O contexto do dispositivo que exibe o botão.

*Rect*<br/>
[em] O retângulo delimitador do botão.

*pImagens*<br/>
[em] A coleção de imagens da barra de ferramentas que está associada ao botão.

*Bhorz*<br/>
[em] O estado das docas da barra de ferramentas dos pais. Este parâmetro é VERDADEIRO quando o botão é encaixado horizontalmente e FALSO quando o botão está encaixado verticalmente.

*bPersonalizeMode*<br/>
[em] Especifica se a barra de ferramentas está no modo de personalização. Este parâmetro é VERDADEIRO quando a barra de ferramentas está no modo de personalização e FALSE quando a barra de ferramentas não está no modo de personalização.

*bDestaque*<br/>
[em] Especifica se o botão está destacado. Este parâmetro é VERDADEIRO quando o botão é destacado e FALSO quando o botão não é destacado.

*bDrawBorder*<br/>
[em] Especifica se o botão deve exibir sua borda. Este parâmetro é VERDADEIRO quando o botão deve exibir sua borda e FALSE quando o botão não deve exibir sua borda.

*bGrayDisabledButtons*<br/>
[em] Especifica se é para sombrear botões desativados ou usar a coleção de imagens desativadas. Este parâmetro é VERDADEIRO quando os botões desativados devem ser sombreados e FALSOs quando este método deve usar a coleção de imagens desativadas.

### <a name="remarks"></a>Comentários

Anular este método para personalizar o desenho do botão da barra de ferramentas.

## <a name="cmfcdropdowntoolbarbuttonondrawoncustomizelist"></a><a name="ondrawoncustomizelist"></a>CMFCDropDownToolbarBotão:OnDrawOnCustomizeList

Chamado pela estrutura para desenhar o botão no painel **Comandos** da caixa de diálogo **Personalizar.**

```
virtual int OnDrawOnCustomizeList(
    CDC* pDC,
    const CRect& rect,
    BOOL bSelected);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] O contexto do dispositivo que exibe o botão.

*Rect*<br/>
[em] O retângulo delimitador do botão.

*bSelecionado*<br/>
[em] Se o botão está selecionado. Se este parâmetro for TRUE, o botão será selecionado. Se este parâmetro for FALSO, o botão não será selecionado.

### <a name="return-value"></a>Valor retornado

A largura, em pixels, do botão no contexto especificado do dispositivo.

### <a name="remarks"></a>Comentários

Esse método é chamado pela caixa de diálogo de personalização (guia **Comandos)** quando o botão é necessário para se exibir na caixa de lista de sorteio do proprietário.

Este método estende a implementação da classe base [(CMFCToolBarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist)) alterando o rótulo de texto do botão para o nome do botão (isto é, para o valor do parâmetro *lpszName* que você passou para o construtor).

## <a name="cmfcdropdowntoolbarbuttonserialize"></a><a name="serialize"></a>CMFCDropDownToolbarButton::Serialize

Lê este objeto de um arquivo ou grava-o em um arquivo.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
[em] O `CArchive` objeto a partir do qual ou para o qual serializar.

### <a name="remarks"></a>Comentários

Este método amplia a implementação da classe base [(CMFCToolBarButton::Serialize)](../../mfc/reference/cmfctoolbarbutton-class.md#serialize)serializando o ID de recurso da barra de ferramentas pai. Quando o arquivo está carregando [(CArchive::IsLoading](../../mfc/reference/carchive-class.md#isloading) retorna um `m_pToolBar` valor não zero), esse método define o membro de dados na barra de ferramentas que contém o ID de recurso serializado.

## <a name="cmfcdropdowntoolbarbuttonsetdefaultcommand"></a><a name="setdefaultcommand"></a>CMFCDropDownBarra de ferramentasBotão::SetDefaultCommand

Define o comando padrão que a estrutura usa quando um usuário clica no botão.

```
void SetDefaultCommand(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O ID do comando padrão.

### <a name="remarks"></a>Comentários

Chame este método para especificar um comando padrão que a estrutura executa quando o usuário clica no botão. Um item com o ID de comando especificado pelo *uiCmd* deve ser localizado na barra de ferramentas do pai.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md)<br/>
[Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
