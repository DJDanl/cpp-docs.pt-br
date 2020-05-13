---
title: Classe CMFCColorMenuButton
ms.date: 11/04/2016
f1_keywords:
- CMFCColorMenuButton
- AFXCOLORMENUBUTTON/CMFCColorMenuButton
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::CMFCColorMenuButton
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::EnableAutomaticButton
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::EnableDocumentColors
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::EnableOtherButton
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::EnableTearOff
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::GetAutomaticColor
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::GetColor
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::GetColorByCmdID
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::OnChangeParentWnd
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::OpenColorDialog
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::SetColor
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::SetColorByCmdID
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::SetColorName
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::SetColumnsNumber
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::CopyFrom
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::CreatePopupMenu
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::IsEmptyMenuAllowed
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::OnDraw
- AFXCOLORMENUBUTTON/CMFCColorMenuButton::OnDrawOnCustomizeList
helpviewer_keywords:
- CMFCColorMenuButton [MFC], CMFCColorMenuButton
- CMFCColorMenuButton [MFC], EnableAutomaticButton
- CMFCColorMenuButton [MFC], EnableDocumentColors
- CMFCColorMenuButton [MFC], EnableOtherButton
- CMFCColorMenuButton [MFC], EnableTearOff
- CMFCColorMenuButton [MFC], GetAutomaticColor
- CMFCColorMenuButton [MFC], GetColor
- CMFCColorMenuButton [MFC], GetColorByCmdID
- CMFCColorMenuButton [MFC], OnChangeParentWnd
- CMFCColorMenuButton [MFC], OpenColorDialog
- CMFCColorMenuButton [MFC], SetColor
- CMFCColorMenuButton [MFC], SetColorByCmdID
- CMFCColorMenuButton [MFC], SetColorName
- CMFCColorMenuButton [MFC], SetColumnsNumber
- CMFCColorMenuButton [MFC], CopyFrom
- CMFCColorMenuButton [MFC], CreatePopupMenu
- CMFCColorMenuButton [MFC], IsEmptyMenuAllowed
- CMFCColorMenuButton [MFC], OnDraw
- CMFCColorMenuButton [MFC], OnDrawOnCustomizeList
ms.assetid: 42685704-e994-4f7b-9553-62283c27b754
ms.openlocfilehash: 9c895573c626a890facfef689fce4b516aff5115
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752522"
---
# <a name="cmfccolormenubutton-class"></a>Classe CMFCColorMenuButton

A `CMFCColorMenuButton` classe suporta um comando de menu ou um botão de barra de ferramentas que inicia uma caixa de diálogo do seletor de cores.

## <a name="syntax"></a>Sintaxe

```
class CMFCColorMenuButton : public CMFCToolBarMenuButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorMenubutton::CMFCColorMenubutton](#cmfccolormenubutton)|Constrói um objeto `CMFCColorMenuButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorMenubutton::Ativarbotão automático](#enableautomaticbutton)|Ativa e desativa um botão "automático" posicionado acima dos botões de cor regulares. (O botão automático do sistema padrão é rotulado **como Automático**.)|
|[CMFCColorMenubutton::Ativarcores de documentos](#enabledocumentcolors)|Habilita a exibição de cores específicas do documento em vez de cores do sistema.|
|[CMFCColorMenubutton::Ativaroutro botão](#enableotherbutton)|Ativa e desativa um botão "outro" posicionado abaixo dos botões de cor regulares. (O botão padrão do sistema "outros" está rotulado como **Mais Cores**.)|
|[CMFCColormenubutton::EnabletearOff](#enabletearoff)|Permite a capacidade de rasgar um painel colorido.|
|[CMFCColormenubutton::GetAutomaticColor](#getautomaticcolor)|Recupera a cor automática atual.|
|[CMFCColormenubutton::GetColor](#getcolor)|Recupera a cor do botão atual.|
|[CMFCColorMenuButton::GetColorByCmdID](#getcolorbycmdid)|Recupera a cor que corresponde a um ID de comando especificado.|
|[CMFCColorMenuButton::OnChangeParentWnd](#onchangeparentwnd)|Chamado pela estrutura quando a janela pai muda.|
|[CMFCColormenubutton::OpenColorDialog](#opencolordialog)|Abre uma caixa de diálogo de seleção de cores.|
|[CMFCColorMenubutton::setColor](#setcolor)|Define a cor do botão de cor atual.|
|[CMFCColorMenuButton::SetColorByCmdID](#setcolorbycmdid)|Define a cor do botão de menu de cores especificado.|
|[CMFCColorMenuButton::conjuntoNome de cores](#setcolorname)|Define um novo nome para a cor especificada.|
|[CMFCColorMenuButton::ConjuntoColunasNúmero de colunas](#setcolumnsnumber)|Define o número de colunas exibidas por um `CMFCColorBar` objeto.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorMenubutton::CopiarDe](#copyfrom)|Copia outro botão de barra de ferramentas para o botão atual.|
|[CMFCColorMenuButton::CreatePopupMenu](#createpopupmenu)|Cria uma caixa de diálogo do seletor de cores.|
|[CMFCColormenubutton::isemptymenuallowed](#isemptymenuallowed)|Indica se os menus vazios são suportados.|
|[CMFCColormenubutton::OnDraw](#ondraw)|Chamado pela estrutura para exibir uma imagem em um botão.|
|[CMFCColorMenubutton::OndrawonPersonalizelist](#ondrawoncustomizelist)|Chamado pela estrutura `CMFCColorMenuButton` antes de um objeto ser exibido na lista de uma caixa de diálogo de personalização da barra de ferramentas.|

## <a name="remarks"></a>Comentários

Para substituir o comando de menu `CMFCColorMenuButton` original ou `CMFCColorMenuButton` o botão da barra de ferramentas por um `ReplaceButton` objeto, crie o objeto, defina os estilos apropriados da CLASSE [CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md) e, em seguida, chame o método da classe [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) Class. Se você personalizar uma barra de ferramentas, chame o [CMFCToolBarsPersonalize-seDiálogo::Substituirmétodo Botão.](../../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton)

A caixa de diálogo seletor de cores é criada durante o processamento do [CMFCColorMenuButton::CreatePopupMenu](#createpopupmenu) manipulador de eventos. O manipulador de eventos notifica o quadro pai com uma mensagem WM_COMMAND. O `CMFCColorMenuButton` objeto envia o ID de controle atribuído ao comando de menu original ou ao botão barra de ferramentas.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar e configurar um botão `CMFCColorMenuButton` de menu de cores usando vários métodos na classe. No exemplo, `CPalette` um objeto é primeiro criado e depois `CMFCColorMenuButton` usado para construir um objeto da classe. O `CMFCColorMenuButton` objeto é então configurado ativando seus botões automáticos e outros, e definindo sua cor e o número de colunas. Este código faz parte da amostra do [Word Pad](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_WordPad#5](../../mfc/reference/codesnippet/cpp/cmfccolormenubutton-class_1.h)]
[!code-cpp[NVC_MFC_WordPad#6](../../mfc/reference/codesnippet/cpp/cmfccolormenubutton-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfctoolbarbutton](../../mfc/reference/cmfctoolbarbutton-class.md)

[Cmfctoolbarmenubutton](../../mfc/reference/cmfctoolbarmenubutton-class.md)

[Cmfccolormenubutton](../../mfc/reference/cmfccolormenubutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolormenubutton.h

## <a name="cmfccolormenubuttoncmfccolormenubutton"></a><a name="cmfccolormenubutton"></a>CMFCColorMenubutton::CMFCColorMenubutton

Constrói um objeto `CMFCColorMenuButton`.

```
CMFCColorMenuButton();

CMFCColorMenuButton(
    UINT uiCmdID,
    LPCTSTR lpszText,
    CPalette* pPalette=NULL);
```

### <a name="parameters"></a>Parâmetros

*uiCmdID*<br/>
[em] Um botão de comando ID.

*lpszText*<br/>
[em] O texto do botão.

*Ppalette*<br/>
[em] Um ponteiro para a paleta de cores do botão.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

O primeiro construtor é o construtor padrão. A cor atual e a cor automática do objeto são inicializadas em preto (RGB(0, 0, 0)).

O segundo construtor inicializa o botão para a cor que corresponde ao ID de comando especificado.

## <a name="cmfccolormenubuttoncopyfrom"></a><a name="copyfrom"></a>CMFCColorMenubutton::CopiarDe

Copia um objeto derivado do [CMFCToolBarMenuButton Class](../../mfc/reference/cmfctoolbarmenubutton-class.md)para outro.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
[em] Botão de origem para copiar.

### <a name="remarks"></a>Comentários

Anular este método para copiar objetos `CMFCColorMenuButton` derivados do objeto.

## <a name="cmfccolormenubuttoncreatepopupmenu"></a><a name="createpopupmenu"></a>CMFCColorMenuButton::CreatePopupMenu

Cria uma caixa de diálogo do seletor de cores.

```
virtual CMFCPopupMenu* CreatePopupMenu();
```

### <a name="return-value"></a>Valor retornado

Um objeto que representa uma caixa de diálogo do seletor de cores.

### <a name="remarks"></a>Comentários

Este método é chamado pela estrutura quando o usuário pressiona um botão de menu de cores.

## <a name="cmfccolormenubuttonenableautomaticbutton"></a><a name="enableautomaticbutton"></a>CMFCColorMenubutton::Ativarbotão automático

Ativa e desativa um botão "automático" posicionado acima dos botões de cor regulares. (O botão automático do sistema padrão é rotulado **como Automático**.)

```cpp
void EnableAutomaticButton(
    LPCTSTR lpszLabel,
    COLORREF colorAutomatic,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] Especifica o texto do botão exibido quando o botão se torna automático.

*corAutomático*<br/>
[em] Especifica uma nova cor automática.

*Benable*<br/>
[em] Especifica se o botão é automático ou não.

### <a name="remarks"></a>Comentários

O botão automático aplica a cor padrão atual.

## <a name="cmfccolormenubuttonenabledocumentcolors"></a><a name="enabledocumentcolors"></a>CMFCColorMenubutton::Ativarcores de documentos

Habilita a exibição de cores específicas do documento em vez de cores do sistema.

```cpp
void EnableDocumentColors(
    LPCTSTR lpszLabel,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] Especifica o texto do botão.

*Benable*<br/>
[em] TRUE para exibir cores específicas do documento ou FALSE para exibir as cores do sistema.

### <a name="remarks"></a>Comentários

Use este método para exibir as cores atuais do documento ou as cores da paleta do sistema quando o usuário clicar em um botão de menu de cores.

## <a name="cmfccolormenubuttonenableotherbutton"></a><a name="enableotherbutton"></a>CMFCColorMenubutton::Ativaroutro botão

Ativa e desativa um botão "outro" posicionado abaixo dos botões de cor regulares. (O botão padrão do sistema "outros" está rotulado como **Mais Cores**.)

```cpp
void EnableOtherButton(
    LPCTSTR lpszLabel,
    BOOL bAltColorDlg=TRUE,
    BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] Especifica o texto do botão.

*bAltColorDlg*<br/>
[em] Especifique `CMFCColorDialog` TRUE para exibir a caixa de diálogo ou FALSE para exibir a caixa de diálogo de cor padrão do sistema.

*Benable*<br/>
[em] Especificar TRUE para exibir o botão "outro"; caso contrário, FALSE. O padrão é TRUE.

### <a name="remarks"></a>Comentários

## <a name="cmfccolormenubuttonenabletearoff"></a><a name="enabletearoff"></a>CMFCColormenubutton::EnabletearOff

Permite a capacidade de rasgar um painel colorido.

```cpp
void EnableTearOff(
    UINT uiID,
    int nVertDockColumns=-1,
    int nHorzDockRows=-1);
```

### <a name="parameters"></a>Parâmetros

*Uiid*<br/>
[em] Especifica o ID para o painel de rasgo.

*nVertDockColumns*<br/>
[em] Especifica o número de colunas no painel de cores ancorado verticalmente enquanto estiver em estado de ruptura.

*nHorzDockRows*<br/>
[em] Especifica o número de linhas para o painel de cores ancorado horizontalmente enquanto estiver em estado de ruptura.

### <a name="remarks"></a>Comentários

Chame este método para ativar o recurso "tear-off" para o `CMFCColorMenuButton` painel de cores que aparece quando o botão é pressionado.

## <a name="cmfccolormenubuttongetautomaticcolor"></a><a name="getautomaticcolor"></a>CMFCColormenubutton::GetAutomaticColor

Recupera a cor automática atual.

```
COLORREF GetAutomaticColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de cor RGB que representa a cor automática atual.

### <a name="remarks"></a>Comentários

Chame este método para obter a cor automática definida pelo [CMFCColorMenuButton::EnableAutomaticButton](#enableautomaticbutton).

## <a name="cmfccolormenubuttongetcolor"></a><a name="getcolor"></a>CMFCColormenubutton::GetColor

Recupera a cor do botão atual.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor retornado

A cor do botão.

### <a name="remarks"></a>Comentários

## <a name="cmfccolormenubuttongetcolorbycmdid"></a><a name="getcolorbycmdid"></a>CMFCColorMenuButton::GetColorByCmdID

Recupera a cor que corresponde a um ID de comando especificado.

```
static COLORREF GetColorByCmdID(UINT uiCmdID);
```

### <a name="parameters"></a>Parâmetros

*uiCmdID*<br/>
[em] Uma id de comando.

### <a name="return-value"></a>Valor retornado

A cor que corresponde ao ID de comando especificado.

### <a name="remarks"></a>Comentários

Use este método quando tiver vários botões de cor em um aplicativo. Quando o usuário clica em um botão de cor, o botão envia seu ID de comando em uma mensagem WM_COMMAND para seu pai. O `GetColorByCmdID` método usa o id de comando para recuperar a cor correspondente.

## <a name="cmfccolormenubuttonisemptymenuallowed"></a><a name="isemptymenuallowed"></a>CMFCColormenubutton::isemptymenuallowed

Indica se os menus vazios são suportados.

```
virtual BOOL IsEmptyMenuAllowed() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se menus vazios forem permitidos; caso contrário, zero.

### <a name="remarks"></a>Comentários

Menus vazios são suportados por padrão. Anular este método para mudar esse comportamento em classe derivada.

## <a name="cmfccolormenubuttononchangeparentwnd"></a><a name="onchangeparentwnd"></a>CMFCColorMenuButton::OnChangeParentWnd

Chamado pela estrutura quando a janela pai muda.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Um ponteiro para a nova janela dos pais.

### <a name="remarks"></a>Comentários

## <a name="cmfccolormenubuttonondraw"></a><a name="ondraw"></a>CMFCColormenubutton::OnDraw

Chamado pela estrutura para exibir uma imagem em um botão.

```
virtual void OnDraw(
    CDC* pDC,
    const CRect& rect,
    CMFCToolBarImages* pImages,
    BOOL bHorz=TRUE,
    BOOL bCustomizeMode=FALSE,
    BOOL bHighlight=FALSE,
    BOOL bDrawBorder=TRUE,
    BOOL bGrayDisabledButtons=TRUE);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] Um retângulo que limita a área a ser redesenhada.

*pImagens*<br/>
[em] Aponta para uma lista de imagens da barra de ferramentas.

*Bhorz*<br/>
[em] TRUE para especificar que a barra de ferramentas está em um estado horizontal ancorado; caso contrário, FALSE. O padrão é TRUE.

*bPersonalizeMode*<br/>
[em] TRUE para especificar que o aplicativo está no modo de personalização; caso contrário, FALSE. O padrão é FALSO.

*bDestaque*<br/>
[em] TRUE para especificar que o botão está destacado; caso contrário, FALSE. O padrão é FALSO.

*bDrawBorder*<br/>
[em] TRUE para especificar que a borda do botão é exibida; caso contrário, FALSE. O padrão é TRUE.

*bGrayDisabledButtons*<br/>
[em] TRUE para especificar que os botões desativados estão acinzentados (escurecidos) para fora; caso contrário, FALSE. O padrão é TRUE.

### <a name="remarks"></a>Comentários

## <a name="cmfccolormenubuttonondrawoncustomizelist"></a><a name="ondrawoncustomizelist"></a>CMFCColorMenubutton::OndrawonPersonalizelist

Chamado pela estrutura `CMFCColorMenuButton` antes de um objeto ser exibido na lista de uma caixa de diálogo de personalização da barra de ferramentas.

```
virtual int OnDrawOnCustomizeList(
    CDC* pDC,
    const CRect& rect,
    BOOL bSelected);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] Um retângulo que limita o botão a ser desenhado.

*bSelecionado*<br/>
[em] TRUE especifica que o botão está em estado selecionado; caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

A largura do botão.

### <a name="remarks"></a>Comentários

Esse método é chamado pela `CMFCColorMenuButton` estrutura quando um objeto é exibido na caixa de lista durante o processo de personalização da barra de ferramentas.

## <a name="cmfccolormenubuttonopencolordialog"></a><a name="opencolordialog"></a>CMFCColormenubutton::OpenColorDialog

Abre uma caixa de diálogo de seleção de cores.

```
virtual BOOL OpenColorDialog(
    const COLORREF colorDefault,
    COLORREF& colorRes);
```

### <a name="parameters"></a>Parâmetros

*corPadrão*<br/>
[em] A cor padrão selecionada na caixa de diálogo de cor.

*coresRes*<br/>
[fora] Retorna a cor que o usuário seleciona na caixa de diálogo de cor.

### <a name="return-value"></a>Valor retornado

Não zero se o usuário selecionar uma nova cor; caso contrário, zero.

### <a name="remarks"></a>Comentários

Quando o botão de menu for clicado, chame este método para abrir uma caixa de diálogo de cor. Se o valor de retorno não for zero, a cor que o usuário seleciona será armazenada no parâmetro *colorRes.* Use o [CMFCColorMenuButton::EnableOtherButton](#enableotherbutton) method para alternar entre a caixa de diálogo de cor padrão e a caixa de diálogo [CMFCColorDialog Class.](../../mfc/reference/cmfccolordialog-class.md)

## <a name="cmfccolormenubuttonsetcolor"></a><a name="setcolor"></a>CMFCColorMenubutton::setColor

Define a cor do botão de cor atual.

```
virtual void SetColor(
    COLORREF clr,
    BOOL bNotify=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Clr*<br/>
[em] Um valor de cor RGB.

*bNotificar*<br/>
[em] TRUE para aplicar a cor do parâmetro *clr* a qualquer botão de menu associado ou botão de barra de ferramentas; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame este método para alterar a cor do botão de cor atual. Se o parâmetro *bNotificar* não for zero, a cor do botão correspondente em qualquer menu popup associado ou barra de ferramentas será alterada para a cor especificada pelo parâmetro *clr.*

## <a name="cmfccolormenubuttonsetcolorbycmdid"></a><a name="setcolorbycmdid"></a>CMFCColorMenuButton::SetColorByCmdID

Define a cor do botão de menu de cores especificado.

```
static void SetColorByCmdID(
    UINT uiCmdID,
    COLORREF color);
```

### <a name="parameters"></a>Parâmetros

*uiCmdID*<br/>
[em] O ID de recurso de um botão de menu de cores.

*cor*<br/>
[em] Um valor de cor RGB.

## <a name="cmfccolormenubuttonsetcolorname"></a><a name="setcolorname"></a>CMFCColorMenuButton::conjuntoNome de cores

Define um novo nome para a cor especificada.

```
static void SetColorName(
    COLORREF color,
    const CString& strName);
```

### <a name="parameters"></a>Parâmetros

*cor*<br/>
[em] O valor RGB da cor cujo nome muda.

*strName*<br/>
[em] O novo nome da cor.

### <a name="remarks"></a>Comentários

## <a name="cmfccolormenubuttonsetcolumnsnumber"></a><a name="setcolumnsnumber"></a>CMFCColorMenuButton::ConjuntoColunasNúmero de colunas

Define o número de colunas a serem exibidas em um controle de seleção de cores (objeto [CMFCColorBar).](../../mfc/reference/cmfccolorbar-class.md)

```cpp
void SetColumnsNumber(int nColumns);
```

### <a name="parameters"></a>Parâmetros

*nColumns*<br/>
[em] O número de colunas a serem exibidas.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCColorBar](../../mfc/reference/cmfccolorbar-class.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md)<br/>
[Classe CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md)
