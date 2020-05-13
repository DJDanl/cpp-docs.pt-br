---
title: Classe CToolBar
ms.date: 11/04/2016
f1_keywords:
- CToolBar
- AFXEXT/CToolBar
- AFXEXT/CToolBar::CToolBar
- AFXEXT/CToolBar::CommandToIndex
- AFXEXT/CToolBar::Create
- AFXEXT/CToolBar::CreateEx
- AFXEXT/CToolBar::GetButtonInfo
- AFXEXT/CToolBar::GetButtonStyle
- AFXEXT/CToolBar::GetButtonText
- AFXEXT/CToolBar::GetItemID
- AFXEXT/CToolBar::GetItemRect
- AFXEXT/CToolBar::GetToolBarCtrl
- AFXEXT/CToolBar::LoadBitmap
- AFXEXT/CToolBar::LoadToolBar
- AFXEXT/CToolBar::SetBitmap
- AFXEXT/CToolBar::SetButtonInfo
- AFXEXT/CToolBar::SetButtons
- AFXEXT/CToolBar::SetButtonStyle
- AFXEXT/CToolBar::SetButtonText
- AFXEXT/CToolBar::SetHeight
- AFXEXT/CToolBar::SetSizes
helpviewer_keywords:
- CToolBar [MFC], CToolBar
- CToolBar [MFC], CommandToIndex
- CToolBar [MFC], Create
- CToolBar [MFC], CreateEx
- CToolBar [MFC], GetButtonInfo
- CToolBar [MFC], GetButtonStyle
- CToolBar [MFC], GetButtonText
- CToolBar [MFC], GetItemID
- CToolBar [MFC], GetItemRect
- CToolBar [MFC], GetToolBarCtrl
- CToolBar [MFC], LoadBitmap
- CToolBar [MFC], LoadToolBar
- CToolBar [MFC], SetBitmap
- CToolBar [MFC], SetButtonInfo
- CToolBar [MFC], SetButtons
- CToolBar [MFC], SetButtonStyle
- CToolBar [MFC], SetButtonText
- CToolBar [MFC], SetHeight
- CToolBar [MFC], SetSizes
ms.assetid: e868da26-5e07-4607-9651-e2f863ad9059
ms.openlocfilehash: cbb2d1bb797737a14e9728d339305bf9c371b543
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752215"
---
# <a name="ctoolbar-class"></a>Classe CToolBar

Barras de controle que têm uma linha de botões bitmapped e separadores opcionais.

## <a name="syntax"></a>Sintaxe

```
class CToolBar : public CControlBar
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Barra de ferramentas::CtoolBar](#ctoolbar)|Constrói um objeto `CToolBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Ctoolbar::CommandToIndex](#commandtoindex)|Retorna o índice de um botão com o ID de comando dado.|
|[Barra de ferramentas::Criar](#create)|Cria a barra de ferramentas do `CToolBar` Windows e a anexa ao objeto.|
|[Barra de ferramentas::CreateEx](#createex)|Cria `CToolBar` um objeto com estilos `CToolBarCtrl` adicionais para o objeto incorporado.|
|[Barra de ferramentas::GetButtonInfo](#getbuttoninfo)|Recupera o iD, o estilo e o número de imagem de um botão.|
|[Barra de ferramentas::GetButtonStyle](#getbuttonstyle)|Recupera o estilo para um botão.|
|[Barra de ferramentas::GetButtonText](#getbuttontext)|Recupera o texto que aparecerá em um botão.|
|[CToolBar::GetItemID](#getitemid)|Retorna o ID de comando de um botão ou separador no índice dado.|
|[CToolBar::GetItemRect](#getitemrect)|Recupera o retângulo do visor para o item no índice dado.|
|[CToolBar::GetToolBarCtrl](#gettoolbarctrl)|Permite acesso direto ao controle comum subjacente.|
|[CToolBar::LoadBitmap](#loadbitmap)|Carrega o bitmap contendo imagens de botão bitmap.|
|[Barra de ferramentas::LoadtoolBar](#loadtoolbar)|Carrega um recurso de barra de ferramentas criado com o editor de recursos.|
|[CToolBar::SetBitmap](#setbitmap)|Define uma imagem bitmapapped.|
|[Barra de ferramentas::SetButtonInfo](#setbuttoninfo)|Define o ID, o estilo e o número de imagem de um botão.|
|[CToolBar::SetButtons](#setbuttons)|Define estilos de botão e um índice de imagens de botão dentro do bitmap.|
|[Barra de ferramentas::SetButtonStyle](#setbuttonstyle)|Define o estilo para um botão.|
|[Barra de ferramentas::SetButtonText](#setbuttontext)|Define o texto que aparecerá em um botão.|
|[Barra de ferramentas::SetHeight](#setheight)|Define a altura da barra de ferramentas.|
|[Barra de ferramentas::SetSizes](#setsizes)|Define os tamanhos dos botões e seus bitmaps.|

## <a name="remarks"></a>Comentários

Os botões podem agir como botões, botões de caixa de seleção ou botões de rádio. `CToolBar`objetos geralmente são membros incorporados de objetos de janela de quadro derivados da classe [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md).

[CToolBar::GetToolBarCtrl](#gettoolbarctrl), uma função de membro nova no MFC 4.0, permite que você aproveite o suporte do controle comum do Windows para personalização da barra de ferramentas e funcionalidade adicional. `CToolBar`as funções de membro dão a maior parte da funcionalidade dos controles comuns do Windows; no entanto, `GetToolBarCtrl`quando você liga, você pode dar às suas barras de ferramentas ainda mais as características das barras de ferramentas do Windows 95/98. Quando você `GetToolBarCtrl`ligar, ele retornará `CToolBarCtrl` uma referência a um objeto. Consulte [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) para obter mais informações sobre como projetar barras de ferramentas usando controles comuns do Windows. Para obter informações mais gerais sobre controles comuns, consulte [Controles Comuns](/windows/win32/Controls/common-controls-intro) no SDK do Windows.

O Visual C++ fornece dois métodos para criar uma barra de ferramentas. Para criar um recurso de barra de ferramentas usando o Resource Editor, siga estas etapas:

1. Crie um recurso de barra de ferramentas.

1. Construa `CToolBar` o objeto.

1. Chame a função [Criar](#create) (ou [CreateEx)](#createex)para criar a `CToolBar` barra de ferramentas do Windows e anexá-la ao objeto.

1. Ligue para [loadToolBar](#loadtoolbar) para carregar o recurso da barra de ferramentas.

Caso contrário, siga estas etapas:

1. Construa `CToolBar` o objeto.

1. Chame a função [Criar](#create) (ou [CreateEx)](#createex)para criar a `CToolBar` barra de ferramentas do Windows e anexá-la ao objeto.

1. Ligue para [loadBitmap](#loadbitmap) para carregar o bitmap que contém as imagens do botão da barra de ferramentas.

1. Chamada [SetButtons](#setbuttons) para definir o estilo do botão e associar cada botão a uma imagem no bitmap.

Todas as imagens de botão na barra de ferramentas são tiradas de um bitmap, que deve conter uma imagem para cada botão. Todas as imagens devem ter o mesmo tamanho; o padrão é de 16 pixels de largura e 15 pixels de altura. As imagens devem estar lado a lado no bitmap.

A `SetButtons` função leva um ponteiro para uma matriz de IDs de controle e um inteiro que especifica o número de elementos na matriz. A função define o ID de cada botão para o valor do elemento correspondente da matriz e atribui a cada botão um índice de imagem, que especifica a posição da imagem do botão no bitmap. Se um elemento de matriz tiver o valor ID_SEPARATOR, nenhum índice de imagem será atribuído.

A ordem das imagens no bitmap é tipicamente a ordem em que elas são desenhadas na tela, mas você pode usar a função [SetButtonInfo](#setbuttoninfo) para alterar a relação entre ordem de imagem e ordem de desenho.

Todos os botões em uma barra de ferramentas são do mesmo tamanho. O padrão é de 24 x 22 pixels, de acordo com *as Diretrizes de Interface do Windows para Design de Software*. Qualquer espaço adicional entre as dimensões da imagem e do botão é usado para formar uma borda em torno da imagem.

Cada botão tem uma imagem. Os vários estados e estilos de botões (pressionados, para cima, para baixo, desativados, desativados e indeterminados) são gerados a partir dessa imagem. Embora os bitmaps possam ser de qualquer cor, você pode alcançar os melhores resultados com imagens em preto e tons de cinza.

> [!WARNING]
> `CToolBar`suporta bitmaps com um máximo de 16 cores. Quando você carrega uma imagem em um editor de barras de ferramentas, o Visual Studio converte automaticamente a imagem em um bitmap de 16 cores, se necessário, e exibe uma mensagem de aviso se a imagem for convertida. Se você usar uma imagem com mais de 16 cores (usando um editor externo para editar a imagem), o aplicativo pode se comportar inesperadamente.

Botões de barra de ferramentas imitam botões por padrão. No entanto, botões de barra de ferramentas também podem imitar botões de caixa de seleção ou botões de rádio. Os botões da caixa de seleção têm três estados: verificados, limpos e indeterminados. Os botões de rádio têm apenas dois estados: verificados e limpos.

Para definir um estilo individual de botão ou separador sem apontar para uma matriz, chame `SetButtons` [GetButtonStyle](#getbuttonstyle) para recuperar o estilo e, em seguida, chame [SetButtonStyle](#setbuttonstyle) em vez de . `SetButtonStyle`é mais útil quando você quer alterar o estilo de um botão no tempo de execução.

Para atribuir texto para aparecer em um botão, ligue para [GetButtonText](#getbuttontext) para recuperar o texto para aparecer no botão e, em seguida, ligue [para SetButtonText](#setbuttontext) para definir o texto.

Para criar um botão de caixa de seleção, atribua-o o estilo TBBS_CHECKBOX ou use a função de membro de `CCmdUI` `SetCheck` um objeto em um manipulador de ON_UPDATE_COMMAND_UI. Ligar `SetCheck` transforma um botão em um botão de caixa de seleção. Passe `SetCheck` um argumento de 0 para desmarcado, 1 para verificado ou 2 para indeterminado.

Para criar um botão de rádio, ligue para a função [setRadio](../../mfc/reference/ccmdui-class.md#setradio) de um membro do objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) a partir de um manipulador de ON_UPDATE_COMMAND_UI. Passe `SetRadio` um argumento de 0 para verificação não verificada ou não. Para fornecer o comportamento mutuamente exclusivo de um grupo de rádio, você deve ter ON_UPDATE_COMMAND_UI manipuladores para todos os botões do grupo.

Para obter mais `CToolBar`informações sobre o uso, consulte o artigo [Implementação da barra de ferramentas MFC](../../mfc/mfc-toolbar-implementation.md) e [nota técnica 31: Barras de controle](../../mfc/tn031-control-bars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Ccontrolbar](../../mfc/reference/ccontrolbar-class.md)

`CToolBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="ctoolbarcommandtoindex"></a><a name="commandtoindex"></a>Ctoolbar::CommandToIndex

Esta função de membro retorna o índice do primeiro botão de barra `nIDFind`de ferramentas, começando na posição 0, cujo iD de comando corresponde .

```
int CommandToIndex(UINT nIDFind) const;
```

### <a name="parameters"></a>Parâmetros

*nIDFind*<br/>
ID de comando de um botão de barra de ferramentas.

### <a name="return-value"></a>Valor retornado

O índice do botão, ou -1, se nenhum botão tiver o ID de comando dado.

## <a name="ctoolbarcreate"></a><a name="create"></a>Barra de ferramentas::Criar

Essa função de membro cria uma barra de ferramentas `CToolBar` do Windows (uma janela filho) e a associa ao objeto.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_TOP,
    UINT nID = AFX_IDW_TOOLBAR);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Ponteiro para a janela que é o pai da barra de ferramentas.

*Dwstyle*<br/>
O estilo da barra de ferramentas. Os estilos adicionais de barra de ferramentas suportados são:

- CBRS_TOP barra de controle está no topo da janela da moldura.

- CBRS_BOTTOM barra de controle está na parte inferior da janela da moldura.

- CBRS_NOALIGN barra de controle não é reposicionada quando o pai é redimensionado.

- CBRS_TOOLTIPS barra de controle exibe dicas de ferramentas.

- CBRS_SIZE_DYNAMIC barra de controle é dinâmica.

- CBRS_SIZE_FIXED barra de controle está fixa.

- CBRS_FLOATING barra de controle está flutuando.

- CBRS_FLYBY Barra de status exibe informações sobre o botão.

- CBRS_HIDE_INPLACE barra de controle não é exibida para o usuário.

*nID*<br/>
A caixa de ferramentas da janela infantil.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ele também define a altura da barra de ferramentas para um valor padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#179](../../mfc/codesnippet/cpp/ctoolbar-class_1.cpp)]

## <a name="ctoolbarcreateex"></a><a name="createex"></a>Barra de ferramentas::CreateEx

Chame essa função para criar uma barra de ferramentas do `CToolBar` Windows (uma janela filho) e associá-la com o objeto.

```
virtual BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = TBSTYLE_FLAT,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP,
    CRect rcBorders = CRect(
    0,
    0,
    0,
    0),
    UINT nID = AFX_IDW_TOOLBAR);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Ponteiro para a janela que é o pai da barra de ferramentas.

*dwCtrlStyle*<br/>
Estilos adicionais para a criação do objeto [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) incorporado. Por padrão, esse valor é definido como TBSTYLE_FLAT. Para obter uma lista completa de estilos de barra de ferramentas, consulte *dwStyle*.

*Dwstyle*<br/>
O estilo da barra de ferramentas. Consulte [O Controle da barra de ferramentas e](/windows/win32/Controls/toolbar-control-and-button-styles) os estilos de botão no SDK do Windows para obter uma lista de estilos apropriados.

*fronteiras rc*<br/>
Um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que define as larguras das bordas da janela da barra de ferramentas. Essas bordas são definidas como 0,0,0,0 por padrão, resultando assim em uma janela de barra de ferramentas sem fronteiras.

*nID*<br/>
A caixa de ferramentas da janela infantil.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ele também define a altura da barra de ferramentas para um valor padrão.

Use `CreateEx`, em vez de [Criar,](#create)quando certos estilos precisarem estar presentes durante a criação do controle da barra de ferramentas incorporada. Por exemplo, defina *o dwCtrlStyle* para TBSTYLE_FLAT &#124; TBSTYLE_TRANSPARENT para criar uma barra de ferramentas que se assemelhe às barras de ferramentas do Internet Explorer 4.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#180](../../mfc/codesnippet/cpp/ctoolbar-class_2.cpp)]

## <a name="ctoolbarctoolbar"></a><a name="ctoolbar"></a>Barra de ferramentas::CtoolBar

Esta função membro `CToolBar` constrói um objeto e define os tamanhos padrão.

```
CToolBar();
```

### <a name="remarks"></a>Comentários

Ligue [para](#create) a função Criar membro para criar a janela da barra de ferramentas.

## <a name="ctoolbargetbuttoninfo"></a><a name="getbuttoninfo"></a>Barra de ferramentas::GetButtonInfo

Esta função de membro recupera o índice de id, estilo e imagem de controle do botão da barra de ferramentas ou separador no local especificado pelo *nIndex.*

```cpp
void GetButtonInfo(
    int nIndex,
    UINT& nID,
    UINT& nStyle,
    int& iImage) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do botão da barra de ferramentas ou separador cujas informações devem ser recuperadas.

*nID*<br/>
Referência a um UINT definido como ID de comando do botão.

*nStyle*<br/>
Referência a um UINT definido para o estilo do botão.

*Iimage*<br/>
Referência a um inteiro definido para o índice da imagem do botão dentro do bitmap.

### <a name="remarks"></a>Comentários

Esses valores são atribuídos às variáveis referenciadas por *nID,* *nStyle*e *iImage*. O índice de imagem é a posição da imagem dentro do bitmap que contém imagens para todos os botões da barra de ferramentas. A primeira imagem está na posição 0.

Se *nIndex* especificar um separador, *o iImage* será definido como a largura do separador em pixels.

## <a name="ctoolbargetbuttonstyle"></a><a name="getbuttonstyle"></a>Barra de ferramentas::GetButtonStyle

Chame esta função de membro para recuperar o estilo de um botão ou separador na barra de ferramentas.

```
UINT GetButtonStyle(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do botão da barra de ferramentas ou do estilo separador a ser recuperado.

### <a name="return-value"></a>Valor retornado

O estilo do botão ou separador especificado pelo *nIndex*.

### <a name="remarks"></a>Comentários

O estilo de um botão determina como o botão aparece e como ele responde à entrada do usuário. Consulte [SetButtonStyle](#setbuttonstyle) para exemplos de estilos de botões.

## <a name="ctoolbargetbuttontext"></a><a name="getbuttontext"></a>Barra de ferramentas::GetButtonText

Ligue para esta função de membro para recuperar o texto que aparece em um botão.

```
CString GetButtonText(int nIndex) const;

void GetButtonText(
    int nIndex,
    CString& rString) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do texto a ser recuperado.

*rString*<br/>
Uma referência a um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que conterá o texto a ser recuperado.

### <a name="return-value"></a>Valor retornado

Um `CString` objeto contendo o texto do botão.

### <a name="remarks"></a>Comentários

A segunda forma desta função `CString` membro preenche um objeto com o texto da seqüência.

## <a name="ctoolbargetitemid"></a><a name="getitemid"></a>CToolBar::GetItemID

Esta função de membro retorna o ID de comando do botão ou separador especificado pelo *nIndex*.

```
UINT GetItemID(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do item cujo ID deve ser recuperado.

### <a name="return-value"></a>Valor retornado

O id de comando do botão ou separador especificado pelo *nIndex*.

### <a name="remarks"></a>Comentários

Separadores retornam ID_SEPARATOR.

## <a name="ctoolbargetitemrect"></a><a name="getitemrect"></a>CToolBar::GetItemRect

Esta função membro `RECT` preenche a estrutura cujo endereço está contido em *lpRect* com as coordenadas do botão ou separador especificados por *nIndex*.

```
virtual void GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do item (botão ou separador) cujas coordenadas retângulo devem ser recuperadas.

*Lprect*<br/>
Endereço da estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) que conterá as coordenadas do item.

### <a name="remarks"></a>Comentários

As coordenadas estão em pixels relativos ao canto superior esquerdo da barra de ferramentas.

Use `GetItemRect` para obter as coordenadas de um separador que você deseja substituir por uma caixa de combinação ou outro controle.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CToolBar::SetSizes](#setsizes).

## <a name="ctoolbargettoolbarctrl"></a><a name="gettoolbarctrl"></a>CToolBar::GetToolBarCtrl

Esta função de membro permite acesso direto ao controle comum subjacente.

```
CToolBarCtrl& GetToolBarCtrl() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência a um objeto `CToolBarCtrl`.

### <a name="remarks"></a>Comentários

Use `GetToolBarCtrl` para aproveitar a funcionalidade do controle comum da barra de ferramentas do Windows e para aproveitar o suporte que o [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) fornece para personalização da barra de ferramentas.

Para obter mais informações sobre o uso de controles comuns, consulte o artigo [Controles](../../mfc/controls-mfc.md) e [Controles Comuns](/windows/win32/Controls/common-controls-intro) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocViewSDI#15](../../mfc/codesnippet/cpp/ctoolbar-class_3.cpp)]

## <a name="ctoolbarloadbitmap"></a><a name="loadbitmap"></a>CToolBar::LoadBitmap

Ligue para esta função de membro `lpszResourceName` para `nIDResource`carregar o bitmap especificado por ou .

```
BOOL LoadBitmap(LPCTSTR lpszResourceName);
BOOL LoadBitmap(UINT nIDResource);
```

### <a name="parameters"></a>Parâmetros

*Lpszresourcename*<br/>
Ponteiro para o nome de recurso do bitmap a ser carregado.

*Nidresource*<br/>
ID de recurso do bitmap a ser carregado.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap deve conter uma imagem para cada botão da barra de ferramentas. Se as imagens não forem do tamanho padrão (16 pixels de largura e 15 pixels de altura), ligue [setSizes](#setsizes) para definir os tamanhos dos botões e suas imagens.

> [!WARNING]
> `CToolBar`suporta bitmaps com um máximo de 16 cores. Quando você carrega uma imagem em um editor de barras de ferramentas, o Visual Studio converte automaticamente a imagem em um bitmap de 16 cores, se necessário, e exibe uma mensagem de aviso se a imagem for convertida. Se você usar uma imagem com mais de 16 cores (usando um editor externo para editar a imagem), o aplicativo pode se comportar inesperadamente.

## <a name="ctoolbarloadtoolbar"></a><a name="loadtoolbar"></a>Barra de ferramentas::LoadtoolBar

Chame esta função de membro para carregar a barra de ferramentas especificada por *lpszResourceName* ou *nIDResource*.

```
BOOL LoadToolBar(LPCTSTR lpszResourceName);
BOOL LoadToolBar(UINT nIDResource);
```

### <a name="parameters"></a>Parâmetros

*Lpszresourcename*<br/>
Ponteiro para o nome de recurso da barra de ferramentas a ser carregada.

*Nidresource*<br/>
ID de recursos da barra de ferramentas a ser carregada.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Consulte [o editor da barra de ferramentas](../../windows/toolbar-editor.md) para obter mais informações sobre a criação de um recurso de barra de ferramentas.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CToolBar::CreateEx](#createex).

## <a name="ctoolbarsetbitmap"></a><a name="setbitmap"></a>CToolBar::SetBitmap

Ligue para esta função de membro para definir a imagem bitmap para a barra de ferramentas.

```
BOOL SetBitmap(HBITMAP hbmImageWell);
```

### <a name="parameters"></a>Parâmetros

*hbmImageWell*<br/>
Manuseie uma imagem de bitmap associada a uma barra de ferramentas.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Por exemplo, `SetBitmap` chamada para alterar a imagem bitmapapped depois que o usuário toma uma ação em um documento que altera a ação de um botão.

## <a name="ctoolbarsetbuttoninfo"></a><a name="setbuttoninfo"></a>Barra de ferramentas::SetButtonInfo

Ligue para esta função de membro para definir o ID de comando do botão, o estilo e o número da imagem.

```cpp
void SetButtonInfo(
    int nIndex,
    UINT nID,
    UINT nStyle,
    int iImage);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice baseado em zero do botão ou separador para o qual as informações devem ser definidas.

*nID*<br/>
O valor para o qual o ID de comando do botão está definido.

*nStyle*<br/>
O novo estilo de botão. Os seguintes estilos de botão são suportados:

- TBBS_BUTTON botão padrão (padrão)

- Separador TBBS_SEPARATOR

- TBBS_CHECKBOX botão de caixa de seleção automática

- TBBS_GROUP Marca o início de um grupo de botões

- TBBS_CHECKGROUP Marca o início de um grupo de botões de caixa de seleção

- TBBS_DROPDOWN Cria um botão de lista baixa.

- TBBS_AUTOSIZE A largura do botão será calculada com base no texto do botão, não no tamanho da imagem.

- TBBS_NOPREFIX O texto do botão não terá um prefixo do acelerador associado a ele.

*Iimage*<br/>
Novo índice para a imagem do botão dentro do bitmap.

### <a name="remarks"></a>Comentários

Para separadores, que têm o estilo TBBS_SEPARATOR, esta função define a largura do separador em pixels para o valor armazenado no *iImage*.

> [!NOTE]
> Você também pode definir estados de botão usando o parâmetro *nStyle;* no entanto, como os estados de botão são `SetButtonInfo` controlados pelo manipulador [de ON_UPDATE_COMMAND_UI,](message-map-macros-mfc.md#on_update_command_ui) qualquer estado que você definir usando será perdido durante o próximo processamento ocioso. Veja [Como atualizar objetos de interface de usuário](../../mfc/how-to-update-user-interface-objects.md) e [TN031: Barras de controle](../../mfc/tn031-control-bars.md) para obter mais informações.

Para obter informações sobre imagens e botões do bitmap, consulte a visão geral da Barra de [CToolBar](../../mfc/reference/ctoolbar-class.md) e [a Barra de Ferramentas::LoadBitmap](#loadbitmap).

## <a name="ctoolbarsetbuttons"></a><a name="setbuttons"></a>CToolBar::SetButtons

Esta função de membro define o ID de comando de cada botão de barra de ferramentas para o valor especificado pelo elemento correspondente do *array lpIDArray*.

```
BOOL SetButtons(
    const UINT* lpIDArray,
    int nIDCount);
```

### <a name="parameters"></a>Parâmetros

*Lpidarray*<br/>
Ponteiro para uma matriz de ids de comando. Pode ser NULL para alocar botões vazios.

*nIDCount*<br/>
Número de elementos na matriz apontado sustado por *lpIDArray*.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se um elemento da matriz tiver o valor ID_SEPARATOR, um separador será criado na posição correspondente da barra de ferramentas. Esta função também define o estilo de cada botão para TBBS_BUTTON e o estilo de cada separador para TBBS_SEPARATOR, e atribui um índice de imagem a cada botão. O índice de imagem especifica a posição da imagem do botão dentro do bitmap.

Você não precisa explicar separadores no bitmap porque esta função não atribui índices de imagem para separadores. Se a barra de ferramentas tiver botões nas posições 0, 1 e 3 e um separador na posição 2, as imagens nas posições 0, 1 e 2 no bitmap são atribuídas aos botões nas posições 0, 1 e 3, respectivamente.

Se *o lpIDArray* for NULL, esta função alocará espaço para o número de itens especificados pelo *nIDCount*. Use [SetButtonInfo](#setbuttoninfo) para definir os atributos de cada item.

## <a name="ctoolbarsetbuttonstyle"></a><a name="setbuttonstyle"></a>Barra de ferramentas::SetButtonStyle

Ligue para esta função de membro para definir o estilo de um botão ou separador, ou para botões de grupo.

```cpp
void SetButtonStyle(
    int nIndex,
    UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do botão ou separador cujas informações devem ser definidas.

*nStyle*<br/>
O estilo do botão. Os seguintes estilos de botão são suportados:

- TBBS_BUTTON botão padrão (padrão)

- Separador TBBS_SEPARATOR

- TBBS_CHECKBOX botão de caixa de seleção automática

- TBBS_GROUP Marca o início de um grupo de botões

- TBBS_CHECKGROUP Marca o início de um grupo de botões de caixa de seleção

- TBBS_DROPDOWN Cria um botão de lista para dada

- TBBS_AUTOSIZE A largura do botão será calculada com base no texto do botão, não no tamanho da imagem

- TBBS_NOPREFIX O texto do botão não terá um prefixo do acelerador associado a ele

### <a name="remarks"></a>Comentários

O estilo de um botão determina como o botão aparece e como ele responde à entrada do usuário.

Antes `SetButtonStyle`de ligar, ligue para a função de membro [GetButtonStyle](#getbuttonstyle) para recuperar o estilo do botão ou do separador.

> [!NOTE]
> Você também pode definir estados de botão usando o parâmetro *nStyle;* no entanto, como os estados de botão são `SetButtonStyle` controlados pelo manipulador [de ON_UPDATE_COMMAND_UI,](message-map-macros-mfc.md#on_update_command_ui) qualquer estado que você definir usando será perdido durante o próximo processamento ocioso. Veja [Como atualizar objetos de interface de usuário](../../mfc/how-to-update-user-interface-objects.md) e [TN031: Barras de controle](../../mfc/tn031-control-bars.md) para obter mais informações.

## <a name="ctoolbarsetbuttontext"></a><a name="setbuttontext"></a>Barra de ferramentas::SetButtonText

Chame esta função para definir o texto em um botão.

```
BOOL SetButtonText(
    int nIndex,
    LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do botão cujo texto deve ser definido.

*lpszText*<br/>
Aponta para o texto a ser definido em um botão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CToolBar::GetToolBarCtrl](#gettoolbarctrl).

## <a name="ctoolbarsetheight"></a><a name="setheight"></a>Barra de ferramentas::SetHeight

Esta função de membro define a altura da barra de ferramentas para o valor, em pixels, especificado em *cyHeight*.

```cpp
void SetHeight(int cyHeight);
```

### <a name="parameters"></a>Parâmetros

*cyHeight*<br/>
A altura dos pixels da barra de ferramentas.

### <a name="remarks"></a>Comentários

Depois de chamar [SetSizes,](#setsizes)use esta função de membro para substituir a altura padrão da barra de ferramentas. Se a altura for muito pequena, os botões serão cortados na parte inferior.

Se esta função não for chamada, a estrutura usará o tamanho do botão para determinar a altura da barra de ferramentas.

## <a name="ctoolbarsetsizes"></a><a name="setsizes"></a>Barra de ferramentas::SetSizes

Chame esta função de membro para definir os botões da barra de ferramentas para o tamanho, em pixels, especificado em *sizeButton*.

```cpp
void SetSizes(
    SIZE sizeButton,
    SIZE sizeImage);
```

### <a name="parameters"></a>Parâmetros

*Sizebutton*<br/>
O tamanho em pixels de cada botão.

*sizeImage*<br/>
O tamanho em pixels de cada imagem.

### <a name="remarks"></a>Comentários

O *parâmetro sizeImage* deve conter o tamanho, em pixels, das imagens no bitmap da barra de ferramentas. As dimensões em *tamanhoButton* deve ser suficiente para segurar a imagem mais 7 pixels extra em largura e 6 pixels extra de altura. Esta função também define a altura da barra de ferramentas para ajustar os botões.

Ligue para esta função de membro apenas para barras de ferramentas que não seguem *as diretrizes do Windows Interface para* recomendações de design de software para tamanhos de botão e imagem.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCListView#8](../../atl/reference/codesnippet/cpp/ctoolbar-class_4.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC CTRLBARS](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC DLGCBR32](../../overview/visual-cpp-samples.md)<br/>
[DockTOOL de amostra De MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)
