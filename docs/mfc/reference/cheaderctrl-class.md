---
title: Classe CHeaderCtrl
ms.date: 11/04/2016
f1_keywords:
- CHeaderCtrl
- AFXCMN/CHeaderCtrl
- AFXCMN/CHeaderCtrl::CHeaderCtrl
- AFXCMN/CHeaderCtrl::ClearAllFilters
- AFXCMN/CHeaderCtrl::ClearFilter
- AFXCMN/CHeaderCtrl::Create
- AFXCMN/CHeaderCtrl::CreateDragImage
- AFXCMN/CHeaderCtrl::CreateEx
- AFXCMN/CHeaderCtrl::DeleteItem
- AFXCMN/CHeaderCtrl::DrawItem
- AFXCMN/CHeaderCtrl::EditFilter
- AFXCMN/CHeaderCtrl::GetBitmapMargin
- AFXCMN/CHeaderCtrl::GetFocusedItem
- AFXCMN/CHeaderCtrl::GetImageList
- AFXCMN/CHeaderCtrl::GetItem
- AFXCMN/CHeaderCtrl::GetItemCount
- AFXCMN/CHeaderCtrl::GetItemDropDownRect
- AFXCMN/CHeaderCtrl::GetItemRect
- AFXCMN/CHeaderCtrl::GetOrderArray
- AFXCMN/CHeaderCtrl::GetOverflowRect
- AFXCMN/CHeaderCtrl::HitTest
- AFXCMN/CHeaderCtrl::InsertItem
- AFXCMN/CHeaderCtrl::Layout
- AFXCMN/CHeaderCtrl::OrderToIndex
- AFXCMN/CHeaderCtrl::SetBitmapMargin
- AFXCMN/CHeaderCtrl::SetFilterChangeTimeout
- AFXCMN/CHeaderCtrl::SetFocusedItem
- AFXCMN/CHeaderCtrl::SetHotDivider
- AFXCMN/CHeaderCtrl::SetImageList
- AFXCMN/CHeaderCtrl::SetItem
- AFXCMN/CHeaderCtrl::SetOrderArray
helpviewer_keywords:
- CHeaderCtrl [MFC], CHeaderCtrl
- CHeaderCtrl [MFC], ClearAllFilters
- CHeaderCtrl [MFC], ClearFilter
- CHeaderCtrl [MFC], Create
- CHeaderCtrl [MFC], CreateDragImage
- CHeaderCtrl [MFC], CreateEx
- CHeaderCtrl [MFC], DeleteItem
- CHeaderCtrl [MFC], DrawItem
- CHeaderCtrl [MFC], EditFilter
- CHeaderCtrl [MFC], GetBitmapMargin
- CHeaderCtrl [MFC], GetFocusedItem
- CHeaderCtrl [MFC], GetImageList
- CHeaderCtrl [MFC], GetItem
- CHeaderCtrl [MFC], GetItemCount
- CHeaderCtrl [MFC], GetItemDropDownRect
- CHeaderCtrl [MFC], GetItemRect
- CHeaderCtrl [MFC], GetOrderArray
- CHeaderCtrl [MFC], GetOverflowRect
- CHeaderCtrl [MFC], HitTest
- CHeaderCtrl [MFC], InsertItem
- CHeaderCtrl [MFC], Layout
- CHeaderCtrl [MFC], OrderToIndex
- CHeaderCtrl [MFC], SetBitmapMargin
- CHeaderCtrl [MFC], SetFilterChangeTimeout
- CHeaderCtrl [MFC], SetFocusedItem
- CHeaderCtrl [MFC], SetHotDivider
- CHeaderCtrl [MFC], SetImageList
- CHeaderCtrl [MFC], SetItem
- CHeaderCtrl [MFC], SetOrderArray
ms.assetid: b847ac90-5fae-4a87-88e0-ca45f77b8b3b
ms.openlocfilehash: a683c877b67f4eae1a7411f5916987c9789b6817
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57261343"
---
# <a name="cheaderctrl-class"></a>Classe CHeaderCtrl

Fornece a funcionalidade do controle de cabeçalho comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CHeaderCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeaderCtrl::CHeaderCtrl](#cheaderctrl)|Constrói um objeto `CHeaderCtrl`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeaderCtrl::ClearAllFilters](#clearallfilters)|Limpa todos os filtros para um controle de cabeçalho.|
|[CHeaderCtrl::ClearFilter](#clearfilter)|Limpa o filtro para um controle de cabeçalho.|
|[CHeaderCtrl::Create](#create)|Cria um controle de cabeçalho e anexa-o para um `CHeaderCtrl` objeto.|
|[CHeaderCtrl::CreateDragImage](#createdragimage)|Cria uma versão transparente da imagem de um item dentro de um controle de cabeçalho.|
|[CHeaderCtrl::CreateEx](#createex)|Cria um controle de cabeçalho com os estilos estendidos do Windows especificados e anexa-o para um `CListCtrl` objeto.|
|[CHeaderCtrl::DeleteItem](#deleteitem)|Exclui um item de um controle de cabeçalho.|
|[CHeaderCtrl::DrawItem](#drawitem)|Desenha o item especificado de um controle de cabeçalho.|
|[CHeaderCtrl::EditFilter](#editfilter)|Começa a editar o filtro especificado de um controle de cabeçalho.|
|[CHeaderCtrl::GetBitmapMargin](#getbitmapmargin)|Recupera a largura da margem de um bitmap em um controle de cabeçalho.|
|[CHeaderCtrl::GetFocusedItem](#getfocuseditem)|Obtém o identificador do item no controle de cabeçalho atual que tem o foco.|
|[CHeaderCtrl::GetImageList](#getimagelist)|Recupera o identificador de uma lista de imagens usada para desenho itens de cabeçalho em um controle de cabeçalho.|
|[CHeaderCtrl::GetItem](#getitem)|Recupera informações sobre um item em um controle de cabeçalho.|
|[CHeaderCtrl::GetItemCount](#getitemcount)|Recupera uma contagem dos itens em um controle de cabeçalho.|
|[CHeaderCtrl::GetItemDropDownRect](#getitemdropdownrect)|Obtém as informações do retângulo delimitador para o botão de menu especificado em um controle de cabeçalho.|
|[CHeaderCtrl::GetItemRect](#getitemrect)|Recupera o retângulo delimitador para um determinado item em um controle de cabeçalho.|
|[CHeaderCtrl::GetOrderArray](#getorderarray)|Recupera a ordem da esquerda para a direita dos itens em um controle de cabeçalho.|
|[CHeaderCtrl::GetOverflowRect](#getoverflowrect)|Obtém o retângulo delimitador do botão de estouro para o controle de cabeçalho atual.|
|[CHeaderCtrl::HitTest](#hittest)|Determina qual item de cabeçalho, se houver, está localizado em um ponto especificado.|
|[CHeaderCtrl::InsertItem](#insertitem)|Insere um novo item em um controle de cabeçalho.|
|[CHeaderCtrl::Layout](#layout)|Recupera o tamanho e a posição de um controle de cabeçalho dentro de um retângulo determinado.|
|[CHeaderCtrl::OrderToIndex](#ordertoindex)|Recupera o valor de índice para um item com base em sua ordem no controle de cabeçalho.|
|[CHeaderCtrl::SetBitmapMargin](#setbitmapmargin)|Define a largura da margem de um bitmap em um controle de cabeçalho.|
|[CHeaderCtrl::SetFilterChangeTimeout](#setfilterchangetimeout)|Define o intervalo de tempo limite entre a hora em que uma alteração é feita em atributos de filtro e o lançamento de um `HDN_FILTERCHANGE` notificação.|
|[CHeaderCtrl::SetFocusedItem](#setfocuseditem)|Define o foco para um item de cabeçalho especificado no controle de cabeçalho atual.|
|[CHeaderCtrl::SetHotDivider](#sethotdivider)|Arraste o divisor entre itens de cabeçalho para indicar um manual de alterações e soltar de um item de cabeçalho.|
|[CHeaderCtrl::SetImageList](#setimagelist)|Atribui uma lista de imagens a um controle de cabeçalho.|
|[CHeaderCtrl::SetItem](#setitem)|Define os atributos do item especificado em um controle de cabeçalho.|
|[CHeaderCtrl::SetOrderArray](#setorderarray)|Define a ordem da esquerda para a direita dos itens em um controle de cabeçalho.|

## <a name="remarks"></a>Comentários

Um controle de cabeçalho é uma janela que geralmente é posicionada acima de um conjunto de colunas de texto ou números. Ela contém um título para cada coluna, e ele pode ser dividido em partes. O usuário pode arrastar os divisores que separam as partes para definir a largura de cada coluna. Para obter uma ilustração de um controle de cabeçalho, consulte [controles de cabeçalho](/windows/desktop/Controls/header-controls).

Esse controle (e, portanto, o `CHeaderCtrl` classe) está disponível somente para programas que são executados na versão do Windows 95/98 e Windows NT 3.51 e posterior.

Funcionalidade adicionada para controles comuns do Windows 95/Internet Explorer 4.0 inclui o seguinte:

- Cabeçalho personalizado ordenação de itens.

- Item de cabeçalho arrastar e soltar, para a reordenação de itens de cabeçalho. Usar o estilo HDS_DRAGDROP quando você cria o `CHeaderCtrl` objeto.

- Texto da coluna de cabeçalho constantemente visível durante o redimensionamento de colunas. Usar o estilo HDS_FULLDRAG quando você cria um `CHeaderCtrl` objeto.

- Cabeçalho rastreio importante, que destaca o item de cabeçalho quando o ponteiro está sobre ele. Usar o estilo HDS_HOTTRACK quando você cria o `CHeaderCtrl` objeto.

- Suporte à lista de imagem. Itens de cabeçalho podem conter imagens armazenadas em um `CImageList` objeto ou texto.

Para obter mais informações sobre como usar `CHeaderCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CHeaderCtrl](../../mfc/using-cheaderctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CHeaderCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="cheaderctrl"></a>  CHeaderCtrl::CHeaderCtrl

Constrói um objeto `CHeaderCtrl`.

```
CHeaderCtrl();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#1](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_1.cpp)]

##  <a name="clearallfilters"></a>  CHeaderCtrl::ClearAllFilters

Limpa todos os filtros para um controle de cabeçalho.

```
BOOL ClearAllFilters();
```

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método implementa o comportamento da mensagem do Win32 [HDM_CLEARFILTER](/windows/desktop/Controls/hdm-clearfilter) com um valor de coluna de -1, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#2](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_2.cpp)]

##  <a name="clearfilter"></a>  CHeaderCtrl::ClearFilter

Limpa o filtro para um controle de cabeçalho.

```
BOOL ClearFilter(int nColumn);
```

### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
Valor de coluna que indica quais filtrar para limpar.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método implementa o comportamento da mensagem do Win32 [HDM_CLEARFILTER](/windows/desktop/Controls/hdm-clearfilter), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#3](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_3.cpp)]

##  <a name="create"></a>  CHeaderCtrl::Create

Cria um controle de cabeçalho e anexa-o para um `CHeaderCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle de cabeçalho. Para obter uma descrição dos estilos de controle de cabeçalho, consulte [estilos de controle de cabeçalho](/windows/desktop/Controls/header-control-styles) no SDK do Windows.

*rect*<br/>
Especifica o tamanho e a posição do controle de cabeçalho. Ela pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou uma [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura.

*pParentWnd*<br/>
Especifica a janela do pai do controle de cabeçalho, geralmente um `CDialog`. Ele não deve ser NULL.

*nID*<br/>
Especifica a ID. do controle de cabeçalho

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a inicialização foi bem-sucedida; Caso contrário, zero.

### <a name="remarks"></a>Comentários

Você constrói um `CHeaderCtrl` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria o controle de cabeçalho e anexa-o para o `CHeaderCtrl` objeto.

Além dos estilos de controle de cabeçalho, você pode usar os seguintes estilos de controle comuns para determinar como o controle de cabeçalho posiciona e redimensionada (consulte [estilos de controle comuns](/windows/desktop/Controls/common-control-styles) para obter mais informações):

- CCS_BOTTOM faz com que o controle se posicionar na parte inferior da área de cliente da janela pai e define a largura para ser o mesmo que o pai a largura da janela.

- CCS_NODIVIDER impede que um pixel de dois realce do que está sendo desenhado na parte superior do controle.

- CCS_NOMOVEY faz com que o controle redimensionar e mover em si horizontalmente, mas não na vertical, em resposta a uma mensagem WM_SIZE. Se o estilo CCS_NORESIZE for usado, esse estilo não se aplica. Por padrão, os controles de cabeçalho têm esse estilo.

- CCS_NOPARENTALIGN impede que o controle sejam movidos automaticamente para a parte superior ou inferior da janela pai. Em vez disso, o controle mantém sua posição dentro da janela pai, apesar das alterações para o tamanho da janela pai. Se o estilo CCS_TOP ou CCS_BOTTOM também é usado, a altura é ajustada para o padrão, mas a posição e a largura permanecem inalterados.

- CCS_NORESIZE impede que o controle usando a largura e altura padrão ao definir seu tamanho inicial ou um novo tamanho. Em vez disso, o controle usa a largura e altura especificada na solicitação para a criação ou dimensionamento.

- CCS_TOP faz com que o controle se posicionar na parte superior da área de cliente da janela pai e define a largura para ser o mesmo que o pai a largura da janela.

Você também pode aplicar os seguintes estilos de janela para um controle de cabeçalho (consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) para obter mais informações):

- WS_CHILD cria uma janela filho. Não pode ser usado com o estilo WS_POPUP.

- WS_VISIBLE cria uma janela que é visível inicialmente.

- WS_DISABLED cria uma janela que é inicialmente desabilitada.

- WS_GROUP Especifica o primeiro controle de um grupo de controles em que o usuário pode mover de um controle para a próxima com as teclas de direção. Todos os controles definidos com o estilo WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o estilo WS_GROUP termina o grupo de estilo e inicia o próximo grupo (ou seja, um grupo termina onde o próximo começa).

- WS_TABSTOP Especifica um número de controles por meio do qual o usuário pode mover usando a tecla TAB. A tecla TAB move o usuário para o próximo controle especificado pelo estilo de WS_TABSTOP.

Se você quiser usar estilos estendidos do windows com o seu controle, chame [CreateEx](#createex) em vez de `Create`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_4.cpp)]

##  <a name="createex"></a>  CHeaderCtrl::CreateEx

Cria um controle (uma janela filho) e associá-la com o `CHeaderCtrl` objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwExStyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o *dwExStyle* parâmetro para [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) no SDK do Windows.

*dwStyle*<br/>
Estilo do controle de cabeçalho. Para obter uma descrição dos estilos de controle de cabeçalho, consulte [estilos de controle de cabeçalho](/windows/desktop/Controls/header-control-styles) no SDK do Windows. Ver [criar](#create) para obter uma lista de estilos adicionais.

*rect*<br/>
Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e posição da janela a ser criado, em coordenadas do cliente do *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
ID da janela filho. do controle

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de `Create` para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

##  <a name="createdragimage"></a>  CHeaderCtrl::CreateDragImage

Cria uma versão transparente da imagem de um item dentro de um controle de cabeçalho.

```
CImageList* CreateDragImage(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do item dentro do controle de cabeçalho. A imagem atribuída a este item é a base para a imagem transparente.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto se for bem-sucedido; caso contrário, NULL. A lista retornada contém apenas uma imagem.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [HDM_CREATEDRAGIMAGE](/windows/desktop/Controls/hdm-createdragimage), conforme descrito no SDK do Windows. Ele é fornecido para dar suporte ao cabeçalho item arrastar e soltar.

O `CImageList` objeto ao qual o ponteiro retornado aponta é um objeto temporário e será excluído no próximo processamento de tempo ocioso.

##  <a name="deleteitem"></a>  CHeaderCtrl::DeleteItem

Exclui um item de um controle de cabeçalho.

```
BOOL DeleteItem(int nPos);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Especifica o índice baseado em zero do item a ser excluído.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#5](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_5.cpp)]

##  <a name="drawitem"></a>  CHeaderCtrl::DrawItem

Chamado pelo framework quando um aspecto visual de um alterações de controle de cabeçalho desenhados pelo proprietário.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro para um [DRAWITEMSTRUCT](/windows/desktop/api/winuser/ns-winuser-tagdrawitemstruct) estrutura que descreve o item a ser pintado.

### <a name="remarks"></a>Comentários

O `itemAction` membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho a ser executada.

Por padrão, essa função membro não faz nada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CHeaderCtrl` objeto.

O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes desse membro função encerra.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_6.cpp)]

##  <a name="editfilter"></a>  CHeaderCtrl::EditFilter

Começa a editar o filtro especificado de um controle de cabeçalho.

```
BOOL EditFilter(
    int nColumn,
    BOOL bDiscardChanges);
```

### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
A coluna para editar.

*bDiscardChanges*<br/>
Um valor que especifica como lidar com o usuário de edição de alterações se o usuário estiver no processo de edição do filtro quando o [HDM_EDITFILTER](/windows/desktop/Controls/hdm-editfilter) mensagem é enviada.

Especifique verdadeiro para descartar as alterações feitas pelo usuário, ou falso para aceitar as alterações feitas pelo usuário.

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método implementa o comportamento da mensagem do Win32 [HDM_EDITFILTER](/windows/desktop/Controls/hdm-editfilter), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#7](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_7.cpp)]

##  <a name="getbitmapmargin"></a>  CHeaderCtrl::GetBitmapMargin

Recupera a largura da margem de um bitmap em um controle de cabeçalho.

```
int GetBitmapMargin() const;
```

### <a name="return-value"></a>Valor de retorno

A largura da margem de bitmap em pixels.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [HDM_GETBITMAPMARGIN](/windows/desktop/Controls/hdm-getbitmapmargin), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#8](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_8.cpp)]

##  <a name="getfocuseditem"></a>  CHeaderCtrl::GetFocusedItem

Obtém o índice do item que tem o foco no controle de cabeçalho atual.

```
int GetFocusedItem() const;
```

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do item de cabeçalho que tem o foco.

### <a name="remarks"></a>Comentários

Esse método envia o [HDM_GETFOCUSEDITEM](/windows/desktop/Controls/hdm-getfocuseditem) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_headerCtrl`, que é usado para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra a `SetFocusedItem` e `GetFocusedItem` métodos. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não está visível. O exemplo a seguir define e, em seguida, confirma o último cabeçalho de coluna como o item de foco.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_10.cpp)]

##  <a name="getimagelist"></a>  CHeaderCtrl::GetImageList

Recupera o identificador de uma lista de imagens usada para desenho itens de cabeçalho em um controle de cabeçalho.

```
CImageList* GetImageList() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [HDM_GETIMAGELIST](/windows/desktop/Controls/hdm-getimagelist), conforme descrito no SDK do Windows. O `CImageList` objeto ao qual o ponteiro retornado aponta é um objeto temporário e será excluído no próximo processamento de tempo ocioso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#9](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_11.cpp)]

##  <a name="getitem"></a>  CHeaderCtrl::GetItem

Recupera informações sobre um item de controle de cabeçalho.

```
BOOL GetItem(
    int nPos,
    HDITEM* pHeaderItem) const;
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Especifica o índice baseado em zero do item a ser recuperado.

*pHeaderItem*<br/>
Ponteiro para um [HDITEM](/windows/desktop/api/commctrl/ns-commctrl-_hd_itema) estrutura que recebe o novo item. Essa estrutura é usada com o `InsertItem` e `SetItem` funções de membro. Quaisquer sinalizadores definidos `mask` elemento Certifique-se de que valores nos elementos correspondentes são preenchidos corretamente após o retorno. Se o `mask` elemento é definido como zero, os valores em outros elementos de estrutura não fazem sentidos.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#10](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_12.cpp)]

##  <a name="getitemcount"></a>  CHeaderCtrl::GetItemCount

Recupera uma contagem dos itens em um controle de cabeçalho.

```
int GetItemCount() const;
```

### <a name="return-value"></a>Valor de retorno

Número de itens de controle de cabeçalho, se for bem-sucedido; Caso contrário, - 1.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CHeaderCtrl::DeleteItem](#deleteitem).

##  <a name="getitemdropdownrect"></a>  CHeaderCtrl::GetItemDropDownRect

Obtém o retângulo delimitador do botão de menu suspenso para um item de cabeçalho no controle de cabeçalho atual.

```
BOOL GetItemDropDownRect(
    int iItem,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iItem*|[in] Índice baseado em zero de um item de cabeçalho cujo estilo é HDF_SPLITBUTTON. Para obter mais informações, consulte o `fmt` membro a [HDITEM](/windows/desktop/api/commctrl/ns-commctrl-_hd_itema) estrutura.|
|*lpRect*|[out] Ponteiro para um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que receberá as informações do retângulo delimitador.|

### <a name="return-value"></a>Valor de retorno

TRUE se essa função for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia o [HDM_GETITEMDROPDOWNRECT](/windows/desktop/Controls/hdm-getitemdropdownrect) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_headerCtrl`, que é usado para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra o `GetItemDropDownRect` método. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. O exemplo de código a seguir desenha um retângulo 3D em todo o local na primeira coluna que é reservada para o botão de lista suspensa de cabeçalho.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#2](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_13.cpp)]

##  <a name="getitemrect"></a>  CHeaderCtrl::GetItemRect

Recupera o retângulo delimitador para um determinado item em um controle de cabeçalho.

```
BOOL GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do item de controle de cabeçalho.

*lpRect*<br/>
Um ponteiro para o endereço de uma [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que recebe as informações do retângulo delimitador.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método implementa o comportamento da mensagem do Win32 [HDM_GETITEMRECT](/windows/desktop/Controls/hdm-getitemrect), conforme descrito no SDK do Windows.

##  <a name="getorderarray"></a>  CHeaderCtrl::GetOrderArray

Recupera a ordem da esquerda para a direita dos itens em um controle de cabeçalho.

```
BOOL GetOrderArray(
    LPINT piArray,
    int iCount);
```

### <a name="parameters"></a>Parâmetros

*piArray*<br/>
Um ponteiro para o endereço de um buffer que recebe os valores de índice dos itens no controle de cabeçalho, na ordem em que são exibidos da esquerda para a direita.

*iCount*<br/>
O número de itens de controle de cabeçalho. Deve ser não negativo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [HDM_GETORDERARRAY](/windows/desktop/Controls/hdm-getorderarray), conforme descrito no SDK do Windows. Ele é fornecido para dar suporte a ordenação de item de cabeçalho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#11](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_14.cpp)]

##  <a name="getoverflowrect"></a>  CHeaderCtrl::GetOverflowRect

Obtém o retângulo delimitador do botão de estouro de controle de cabeçalho atual.

```
BOOL GetOverflowRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*lpRect*|[out] Ponteiro para um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que recebe as informações do retângulo delimitador.|

### <a name="return-value"></a>Valor de retorno

TRUE se essa função for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o controle de cabeçalho contém mais itens que podem ser exibidos simultaneamente, o controle pode exibir um botão de estouro rola para itens que não estão visíveis. O controle de cabeçalho deve ter os estilos HDS_OVERFLOW e HDF_SPLITBUTTON para exibir o botão de estouro. O retângulo delimitador circunscreve o botão de estouro e existe somente quando o botão de estouro é exibido. Para obter mais informações, consulte [estilos de controle de cabeçalho](/windows/desktop/Controls/header-control-styles).

Esse método envia o [HDM_GETOVERFLOWRECT](/windows/desktop/Controls/hdm-getoverflowrect) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_headerCtrl`, que é usado para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra o `GetOverflowRect` método. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não está visível. Se algumas colunas não estiverem visíveis, o controle de cabeçalho desenha um botão de estouro. O exemplo de código a seguir desenha um retângulo 3D em todo o local do botão de estouro.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#3](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_15.cpp)]

##  <a name="hittest"></a>  CHeaderCtrl::HitTest

Determina qual item de cabeçalho, se houver, está localizado em um ponto especificado.

```
int HitTest(LPHDHITTESTINFO* phdhti);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*phdhti*|[no, out] Ponteiro para um [HDHITTESTINFO](/windows/desktop/api/commctrl/ns-commctrl-_hd_hittestinfo) estrutura que especifica o ponto a ser testado e recebe os resultados do teste.|

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do item de cabeçalho, se houver, na posição especificada; Caso contrário, -1.

### <a name="remarks"></a>Comentários

Esse método envia o [HDM_HITTEST](/windows/desktop/Controls/hdm-hittest) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_headerCtrl`, que é usado para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra o `HitTest` método. Em uma seção anterior deste exemplo de código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não está visível. Este exemplo relata o índice da coluna se ela estiver visível e -1 se a coluna não estiver visível.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#1](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_16.cpp)]

##  <a name="insertitem"></a>  CHeaderCtrl::InsertItem

Insere um novo item em um controle de cabeçalho no índice especificado.

```
int InsertItem(
    int nPos,
    HDITEM* phdi);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
O índice de base zero do item a ser inserido. Se o valor for zero, o item é inserido no início do controle de cabeçalho. Se o valor for maior que o valor máximo, o item é inserido no final do controle de cabeçalho.

*phdi*<br/>
Ponteiro para um [HDITEM](/windows/desktop/api/commctrl/ns-commctrl-_hd_itema) estrutura que contém informações sobre o item a ser inserido.

### <a name="return-value"></a>Valor de retorno

Índice do novo item, se for bem-sucedido; Caso contrário, - 1.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#12](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_17.cpp)]

##  <a name="layout"></a>  CHeaderCtrl::Layout

Recupera o tamanho e a posição de um controle de cabeçalho dentro de um retângulo determinado.

```
BOOL Layout(HDLAYOUT* pHeaderLayout);
```

### <a name="parameters"></a>Parâmetros

*pHeaderLayout*<br/>
Ponteiro para um [HDLAYOUT](/windows/desktop/api/commctrl/ns-commctrl-_hd_layout) estrutura, que contém informações usadas para definir o tamanho e posição de um controle de cabeçalho.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é usada para determinar as dimensões apropriadas para um novo controle de cabeçalho que deve ocupar o retângulo especificado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#13](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_18.cpp)]

##  <a name="ordertoindex"></a>  CHeaderCtrl::OrderToIndex

Recupera o valor de índice para um item com base em sua ordem no controle de cabeçalho.

```
int OrderToIndex(int nOrder) const;
```

### <a name="parameters"></a>Parâmetros

*nOrder*<br/>
A ordem com base em zero que o item é exibido no controle de cabeçalho, da esquerda para a direita.

### <a name="return-value"></a>Valor de retorno

O índice do item, com base em sua ordem no controle de cabeçalho. O índice de contagens da esquerda para a direita, começando com 0.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da macro do Win32 [HDM_ORDERTOINDEX](https://msdn.microsoft.com/library/windows/desktop/bb775355), conforme descrito no SDK do Windows. Ele é fornecido para dar suporte a ordenação de item de cabeçalho.

##  <a name="setbitmapmargin"></a>  CHeaderCtrl::SetBitmapMargin

Define a largura da margem de um bitmap em um controle de cabeçalho.

```
int SetBitmapMargin(int nWidth);
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
Largura, especificada em pixels, da margem ao redor de um bitmap dentro de um controle de cabeçalho existente.

### <a name="return-value"></a>Valor de retorno

A largura da margem de bitmap em pixels.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [HDM_SETBITMAPMARGIN](/windows/desktop/Controls/hdm-setbitmapmargin), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#14](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_19.cpp)]

##  <a name="setfilterchangetimeout"></a>  CHeaderCtrl::SetFilterChangeTimeout

Define o intervalo de tempo limite entre a hora em que uma alteração é feita em atributos de filtro e o lançamento de uma [HDN_FILTERCHANGE](/windows/desktop/Controls/hdn-filterchange) notificação.

```
int SetFilterChangeTimeout(DWORD dwTimeOut);
```

### <a name="parameters"></a>Parâmetros

*dwTimeOut*<br/>
Valor de tempo limite, em milissegundos.

### <a name="return-value"></a>Valor de retorno

O índice do controle de filtro que está sendo modificado.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [HDM_SETFILTERCHANGETIMEOUT](/windows/desktop/Controls/hdm-setfilterchangetimeout), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#15](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_20.cpp)]

##  <a name="setfocuseditem"></a>  CHeaderCtrl::SetFocusedItem

Define o foco para um item de cabeçalho especificado no controle de cabeçalho atual.

```
BOOL SetFocusedItem(int iItem);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iItem*|[in] Índice baseado em zero de um item de cabeçalho.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia o [HDM_SETFOCUSEDITEM](/windows/desktop/Controls/hdm-setfocuseditem) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável `m_headerCtrl`, que é usado para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra a `SetFocusedItem` e `GetFocusedItem` métodos. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não está visível. O exemplo a seguir define e, em seguida, confirma o último cabeçalho de coluna como o item de foco.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_10.cpp)]

##  <a name="sethotdivider"></a>  CHeaderCtrl::SetHotDivider

Arraste o divisor entre itens de cabeçalho para indicar um manual de alterações e soltar de um item de cabeçalho.

```
int SetHotDivider(CPoint pt);
int SetHotDivider(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
A posição do ponteiro. O controle de cabeçalho destaca o divisor apropriado com base na posição do ponteiro.

*nIndex*<br/>
O índice do divisor de realçado.

### <a name="return-value"></a>Valor de retorno

O índice do divisor de realçado.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [HDM_SETHOTDIVIDER](/windows/desktop/Controls/hdm-sethotdivider), conforme descrito no SDK do Windows. Ele é fornecido para dar suporte ao cabeçalho item arrastar e soltar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#16](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_21.cpp)]

##  <a name="setimagelist"></a>  CHeaderCtrl::SetImageList

Atribui uma lista de imagens a um controle de cabeçalho.

```
CImageList* SetImageList(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*pImageList*<br/>
Um ponteiro para um `CImageList` objeto que contém a lista de imagens a ser atribuído ao controle de cabeçalho.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o [CImageList](../../mfc/reference/cimagelist-class.md) anteriormente atribuído ao controle de cabeçalho do objeto.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [HDM_SETIMAGELIST](/windows/desktop/Controls/hdm-setimagelist), conforme descrito no SDK do Windows. O `CImageList` objeto ao qual o ponteiro retornado aponta é um objeto temporário e será excluído no próximo processamento de tempo ocioso.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CHeaderCtrl::GetImageList](#getimagelist).

##  <a name="setitem"></a>  CHeaderCtrl::SetItem

Define os atributos do item especificado em um controle de cabeçalho.

```
BOOL SetItem(
    int nPos,
    HDITEM* pHeaderItem);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
O índice baseado em zero do item a ser manipulado.

*pHeaderItem*<br/>
Ponteiro para um [HDITEM](/windows/desktop/api/commctrl/ns-commctrl-_hd_itema) estrutura que contém informações sobre o novo item.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CHeaderCtrl::GetItem](#getitem).

##  <a name="setorderarray"></a>  CHeaderCtrl::SetOrderArray

Define a ordem da esquerda para a direita dos itens em um controle de cabeçalho.

```
BOOL SetOrderArray(
    int iCount,
    LPINT piArray);
```

### <a name="parameters"></a>Parâmetros

*iCount*<br/>
O número de itens de controle de cabeçalho.

*piArray*<br/>
Um ponteiro para o endereço de um buffer que recebe os valores de índice dos itens no controle de cabeçalho, na ordem em que são exibidos da esquerda para a direita.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da macro do Win32 [HDM_SETORDERARRAY](/windows/desktop/Controls/hdm-setorderarray), conforme descrito no SDK do Windows. Ele é fornecido para dar suporte a ordenação de item de cabeçalho.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CHeaderCtrl::GetOrderArray](#getorderarray).

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CTabCtrl](../../mfc/reference/ctabctrl-class.md)<br/>
[Classe CListCtrl](../../mfc/reference/clistctrl-class.md)<br/>
[Classe CImageList](../../mfc/reference/cimagelist-class.md)
