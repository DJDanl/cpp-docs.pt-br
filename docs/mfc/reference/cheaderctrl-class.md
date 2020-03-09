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
ms.openlocfilehash: 62915da703e1c938e65643ab389999b83c72d459
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78871581"
---
# <a name="cheaderctrl-class"></a>Classe CHeaderCtrl

Fornece a funcionalidade do controle de cabeçalho comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CHeaderCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CHeaderCtrl::CHeaderCtrl](#cheaderctrl)|Constrói um objeto `CHeaderCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CHeaderCtrl::ClearAllFilters](#clearallfilters)|Limpa todos os filtros de um controle de cabeçalho.|
|[CHeaderCtrl::ClearFilter](#clearfilter)|Limpa o filtro de um controle de cabeçalho.|
|[CHeaderCtrl:: criar](#create)|Cria um controle de cabeçalho e o anexa a um objeto `CHeaderCtrl`.|
|[CHeaderCtrl::CreateDragImage](#createdragimage)|Cria uma versão transparente da imagem de um item dentro de um controle de cabeçalho.|
|[CHeaderCtrl::CreateEx](#createex)|Cria um controle de cabeçalho com os estilos estendidos do Windows especificados e o anexa a um objeto `CListCtrl`.|
|[CHeaderCtrl::D eleteItem](#deleteitem)|Exclui um item de um controle de cabeçalho.|
|[CHeaderCtrl::D rawItem](#drawitem)|Desenha o item especificado de um controle de cabeçalho.|
|[CHeaderCtrl::EditFilter](#editfilter)|Inicia a edição do filtro especificado de um controle de cabeçalho.|
|[CHeaderCtrl::GetBitmapMargin](#getbitmapmargin)|Recupera a largura da margem de um bitmap em um controle de cabeçalho.|
|[CHeaderCtrl::GetFocusedItem](#getfocuseditem)|Obtém o identificador do item no controle de cabeçalho atual que tem o foco.|
|[CHeaderCtrl:: GetImageList](#getimagelist)|Recupera o identificador de uma lista de imagens usada para desenhar itens de cabeçalho em um controle de cabeçalho.|
|[CHeaderCtrl:: GetItem](#getitem)|Recupera informações sobre um item em um controle de cabeçalho.|
|[CHeaderCtrl:: GetItemCount](#getitemcount)|Recupera uma contagem dos itens em um controle de cabeçalho.|
|[CHeaderCtrl::GetItemDropDownRect](#getitemdropdownrect)|Obtém as informações de retângulo delimitador para o botão suspenso especificado em um controle de cabeçalho.|
|[CHeaderCtrl::GetItemRect](#getitemrect)|Recupera o retângulo delimitador de um determinado item em um controle de cabeçalho.|
|[CHeaderCtrl::GetOrderArray](#getorderarray)|Recupera a ordem da esquerda para a direita de itens em um controle de cabeçalho.|
|[CHeaderCtrl::GetOverflowRect](#getoverflowrect)|Obtém o retângulo delimitador do botão de estouro para o controle de cabeçalho atual.|
|[CHeaderCtrl:: HitTest](#hittest)|Determina qual item de cabeçalho, se houver, está localizado em um ponto especificado.|
|[CHeaderCtrl:: InsertItem](#insertitem)|Insere um novo item em um controle de cabeçalho.|
|[CHeaderCtrl:: layout](#layout)|Recupera o tamanho e a posição de um controle de cabeçalho em um determinado retângulo.|
|[CHeaderCtrl::OrderToIndex](#ordertoindex)|Recupera o valor de índice de um item com base em sua ordem no controle de cabeçalho.|
|[CHeaderCtrl::SetBitmapMargin](#setbitmapmargin)|Define a largura da margem de um bitmap em um controle de cabeçalho.|
|[CHeaderCtrl::SetFilterChangeTimeout](#setfilterchangetimeout)|Define o intervalo de tempo limite entre a hora em que uma alteração ocorre nos atributos de filtro e o lançamento de uma notificação de `HDN_FILTERCHANGE`.|
|[CHeaderCtrl::SetFocusedItem](#setfocuseditem)|Define o foco para um item de cabeçalho especificado no controle de cabeçalho atual.|
|[CHeaderCtrl::SetHotDivider](#sethotdivider)|Altera o divisor entre itens de cabeçalho para indicar um arrastar e soltar manual de um item de cabeçalho.|
|[CHeaderCtrl:: SetImageList](#setimagelist)|Atribui uma lista de imagens a um controle de cabeçalho.|
|[CHeaderCtrl::SetItem](#setitem)|Define os atributos do item especificado em um controle de cabeçalho.|
|[CHeaderCtrl::SetOrderArray](#setorderarray)|Define a ordem da esquerda para a direita de itens em um controle de cabeçalho.|

## <a name="remarks"></a>Comentários

Um controle de cabeçalho é uma janela que geralmente está posicionada acima de um conjunto de colunas de texto ou números. Ele contém um título para cada coluna e pode ser dividido em partes. O usuário pode arrastar os divisores que separam as partes para definir a largura de cada coluna. Para obter uma ilustração de um controle de cabeçalho, consulte [controles de cabeçalho](/windows/win32/Controls/header-controls).

Esse controle (e, portanto, a classe `CHeaderCtrl`) está disponível somente para programas executados no Windows 95/98 e no Windows NT versão 3,51 e posterior.

A funcionalidade adicionada para controles comuns do Windows 95/Internet Explorer 4,0 inclui o seguinte:

- Ordenação personalizada de item de cabeçalho.

- Arrastar e soltar item de cabeçalho para reordenação de itens de cabeçalho. Use o estilo de HDS_DRAGDROP ao criar o objeto `CHeaderCtrl`.

- Texto da coluna de cabeçalho em constante visualização durante o redimensionamento de coluna. Use o estilo de HDS_FULLDRAG ao criar um objeto de `CHeaderCtrl`.

- Rastreamento dinâmico de cabeçalho, que realça o item de cabeçalho quando o ponteiro passa sobre ele. Use o estilo de HDS_HOTTRACK ao criar o objeto `CHeaderCtrl`.

- Suporte à lista de imagens. Os itens de cabeçalho podem conter imagens armazenadas em um `CImageList` objeto ou texto.

Para obter mais informações sobre como usar `CHeaderCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CHeaderCtrl](../../mfc/using-cheaderctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CHeaderCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="cheaderctrl"></a>CHeaderCtrl::CHeaderCtrl

Constrói um objeto `CHeaderCtrl`.

```
CHeaderCtrl();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#1](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_1.cpp)]

##  <a name="clearallfilters"></a>CHeaderCtrl::ClearAllFilters

Limpa todos os filtros de um controle de cabeçalho.

```
BOOL ClearAllFilters();
```

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método implementa o comportamento da mensagem Win32 [HDM_CLEARFILTER](/windows/win32/Controls/hdm-clearfilter) com um valor de coluna de-1, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#2](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_2.cpp)]

##  <a name="clearfilter"></a>CHeaderCtrl::ClearFilter

Limpa o filtro de um controle de cabeçalho.

```
BOOL ClearFilter(int nColumn);
```

### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
Valor da coluna que indica qual filtro deve ser limpo.

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método implementa o comportamento da mensagem Win32 [HDM_CLEARFILTER](/windows/win32/Controls/hdm-clearfilter), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#3](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_3.cpp)]

##  <a name="create"></a>CHeaderCtrl:: criar

Cria um controle de cabeçalho e o anexa a um objeto `CHeaderCtrl`.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle de cabeçalho. Para obter uma descrição dos estilos de controle de cabeçalho, consulte [estilos de controle de cabeçalho](/windows/win32/Controls/header-control-styles) na SDK do Windows.

*Rect*<br/>
Especifica o tamanho e a posição do controle de cabeçalho. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) .

*pParentWnd*<br/>
Especifica a janela pai do controle de cabeçalho, geralmente um `CDialog`. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle de cabeçalho.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a inicialização tiver sido bem-sucedida; caso contrário, zero.

### <a name="remarks"></a>Comentários

Você constrói um objeto `CHeaderCtrl` em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria o controle de cabeçalho e o anexa ao objeto `CHeaderCtrl`.

Além dos estilos de controle de cabeçalho, você pode usar os seguintes estilos de controle comuns para determinar como as posições de controle de cabeçalho e redimensionam-se (consulte os [estilos de controle comuns](/windows/win32/Controls/common-control-styles) para obter mais informações):

- CCS_BOTTOM faz com que o controle se posicione na parte inferior da área do cliente da janela pai e defina a largura como a mesma que a largura da janela pai.

- CCS_NODIVIDER impede que um realce de dois pixels seja desenhado na parte superior do controle.

- CCS_NOMOVEY faz com que o controle redimensione e se mova horizontalmente, mas não verticalmente, em resposta a uma mensagem de WM_SIZE. Se o estilo de CCS_NORESIZE for usado, esse estilo não se aplicará. Os controles de cabeçalho têm esse estilo por padrão.

- CCS_NOPARENTALIGN impede que o controle se mova automaticamente para a parte superior ou inferior da janela pai. Em vez disso, o controle mantém sua posição dentro da janela pai apesar das alterações no tamanho da janela pai. Se o CCS_TOP ou o estilo de CCS_BOTTOM também for usado, a altura será ajustada para o padrão, mas a posição e a largura permanecerão inalteradas.

- CCS_NORESIZE impede que o controle use a largura e a altura padrão ao definir seu tamanho inicial ou um novo tamanho. Em vez disso, o controle usa a largura e a altura especificadas na solicitação de criação ou dimensionamento.

- CCS_TOP faz com que o controle se posicione na parte superior da área do cliente da janela pai e defina a largura como a mesma que a largura da janela pai.

Você também pode aplicar os seguintes estilos de janela a um controle de cabeçalho (consulte os [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) para obter mais informações):

- WS_CHILD cria uma janela filho. Não pode ser usado com o estilo de WS_POPUP.

- WS_VISIBLE cria uma janela que inicialmente é visível.

- WS_DISABLED Cria uma janela que está inicialmente desabilitada.

- WS_GROUP especifica o primeiro controle de um grupo de controles no qual o usuário pode passar de um controle para o próximo com as teclas de direção. Todos os controles definidos com o estilo de WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o estilo WS_GROUP encerra o grupo de estilos e inicia o próximo grupo (ou seja, um grupo termina onde o próximo começa).

- WS_TABSTOP especifica um dos vários controles pelos quais o usuário pode se mover usando a tecla TAB. A tecla TAB move o usuário para o próximo controle especificado pelo estilo de WS_TABSTOP.

Se você quiser usar estilos estendidos do Windows com seu controle, chame [CreateEx](#createex) em vez de `Create`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_4.cpp)]

##  <a name="createex"></a>CHeaderCtrl::CreateEx

Cria um controle (uma janela filho) e o associa ao objeto `CHeaderCtrl`.

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
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*dwStyle*<br/>
O estilo do controle de cabeçalho. Para obter uma descrição dos estilos de controle de cabeçalho, consulte [estilos de controle de cabeçalho](/windows/win32/Controls/header-control-styles) na SDK do Windows. Consulte [criar](#create) para obter uma lista de estilos adicionais.

*Rect*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que descreve o tamanho e a posição da janela a ser criada, nas coordenadas de cliente de *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A ID da janela filho do controle.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de `Create` para aplicar estilos estendidos do Windows, especificados pelo **WS_EX_** de prefácio de estilo estendido do Windows.

##  <a name="createdragimage"></a>CHeaderCtrl::CreateDragImage

Cria uma versão transparente da imagem de um item dentro de um controle de cabeçalho.

```
CImageList* CreateDragImage(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice de base zero do item dentro do controle de cabeçalho. A imagem atribuída a esse item é a base para a imagem transparente.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) se for bem-sucedido; caso contrário, NULL. A lista retornada contém apenas uma imagem.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [HDM_CREATEDRAGIMAGE](/windows/win32/Controls/hdm-createdragimage)de mensagens Win32, conforme descrito no SDK do Windows. Ele é fornecido para dar suporte ao arrastar e soltar item de cabeçalho.

O objeto `CImageList` ao qual o ponteiro retornado aponta é um objeto temporário e é excluído no próximo processamento em tempo ocioso.

##  <a name="deleteitem"></a>CHeaderCtrl::D eleteItem

Exclui um item de um controle de cabeçalho.

```
BOOL DeleteItem(int nPos);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Especifica o índice de base zero do item a ser excluído.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#5](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_5.cpp)]

##  <a name="drawitem"></a>CHeaderCtrl::D rawItem

Chamado pelo Framework quando um aspecto visual de um controle de cabeçalho de desenho proprietário é alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que descreve o item a ser pintado.

### <a name="remarks"></a>Comentários

O membro `itemAction` da estrutura de `DRAWITEMSTRUCT` define a ação de desenho a ser executada.

Por padrão, essa função de membro não faz nada. Substitua essa função de membro para implementar o desenho de um objeto de `CHeaderCtrl` de desenho proprietário.

O aplicativo deve restaurar todos os objetos da interface de dispositivo de gráficos (GDI) selecionados para o contexto de exibição fornecido em *lpDrawItemStruct* antes que essa função de membro seja encerrada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_6.cpp)]

##  <a name="editfilter"></a>CHeaderCtrl::EditFilter

Começa a editar o filtro especificado de um controle de cabeçalho.

```
BOOL EditFilter(
    int nColumn,
    BOOL bDiscardChanges);
```

### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
A coluna a ser editada.

*bDiscardChanges*<br/>
Um valor que especifica como tratar as alterações de edição do usuário se o usuário estiver no processo de edição do filtro quando a mensagem de [HDM_EDITFILTER](/windows/win32/Controls/hdm-editfilter) for enviada.

Especifique TRUE para descartar as alterações feitas pelo usuário ou FALSE para aceitar as alterações feitas pelo usuário.

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método implementa o comportamento da mensagem Win32 [HDM_EDITFILTER](/windows/win32/Controls/hdm-editfilter), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#7](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_7.cpp)]

##  <a name="getbitmapmargin"></a>CHeaderCtrl::GetBitmapMargin

Recupera a largura da margem de um bitmap em um controle de cabeçalho.

```
int GetBitmapMargin() const;
```

### <a name="return-value"></a>Valor retornado

A largura da margem do bitmap em pixels.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [HDM_GETBITMAPMARGIN](/windows/win32/Controls/hdm-getbitmapmargin)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#8](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_8.cpp)]

##  <a name="getfocuseditem"></a>CHeaderCtrl::GetFocusedItem

Obtém o índice do item que tem o foco no controle de cabeçalho atual.

```
int GetFocusedItem() const;
```

### <a name="return-value"></a>Valor retornado

O índice de base zero do item de cabeçalho que tem o foco.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [HDM_GETFOCUSEDITEM](/windows/win32/Controls/hdm-getfocuseditem) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_headerCtrl`, que é usada para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra os métodos `SetFocusedItem` e `GetFocusedItem`. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não fique visível. O exemplo a seguir define e confirma o último cabeçalho de coluna como o item de foco.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_10.cpp)]

##  <a name="getimagelist"></a>CHeaderCtrl:: GetImageList

Recupera o identificador de uma lista de imagens usada para desenhar itens de cabeçalho em um controle de cabeçalho.

```
CImageList* GetImageList() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) .

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [HDM_GETIMAGELIST](/windows/win32/Controls/hdm-getimagelist)de mensagens Win32, conforme descrito no SDK do Windows. O objeto `CImageList` ao qual o ponteiro retornado aponta é um objeto temporário e é excluído no próximo processamento em tempo ocioso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#9](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_11.cpp)]

##  <a name="getitem"></a>CHeaderCtrl:: GetItem

Recupera informações sobre um item de controle de cabeçalho.

```
BOOL GetItem(
    int nPos,
    HDITEM* pHeaderItem) const;
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
Especifica o índice de base zero do item a ser recuperado.

*pHeaderItem*<br/>
Ponteiro para uma estrutura [HDITEM](/windows/win32/api/commctrl/ns-commctrl-hditemw) que recebe o novo item. Essa estrutura é usada com as funções de membro `InsertItem` e `SetItem`. Todos os sinalizadores definidos no elemento `mask` garantem que os valores nos elementos correspondentes sejam preenchidos corretamente no retorno. Se o elemento `mask` for definido como zero, os valores nos outros elementos de estrutura não serão sem sentido.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#10](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_12.cpp)]

##  <a name="getitemcount"></a>CHeaderCtrl:: GetItemCount

Recupera uma contagem dos itens em um controle de cabeçalho.

```
int GetItemCount() const;
```

### <a name="return-value"></a>Valor retornado

Número de itens de controle de cabeçalho se bem-sucedido; caso contrário,-1.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CHeaderCtrl::D eleteitem](#deleteitem).

##  <a name="getitemdropdownrect"></a>CHeaderCtrl::GetItemDropDownRect

Obtém o retângulo delimitador do botão suspenso para um item de cabeçalho no controle de cabeçalho atual.

```
BOOL GetItemDropDownRect(
    int iItem,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*iItem*|no Índice de base zero de um item de cabeçalho cujo estilo é HDF_SPLITBUTTON. Para obter mais informações, consulte o membro `fmt` da estrutura [HDITEM](/windows/win32/api/commctrl/ns-commctrl-hditemw) .|
|*lpRect*|fora Ponteiro para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) para receber as informações de retângulo delimitador.|

### <a name="return-value"></a>Valor retornado

TRUE se essa função for bem-sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [HDM_GETITEMDROPDOWNRECT](/windows/win32/Controls/hdm-getitemdropdownrect) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_headerCtrl`, que é usada para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra o método `GetItemDropDownRect`. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. O exemplo de código a seguir desenha um retângulo 3D em volta do local na primeira coluna reservada para o botão suspenso de cabeçalho.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#2](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_13.cpp)]

##  <a name="getitemrect"></a>CHeaderCtrl::GetItemRect

Recupera o retângulo delimitador de um determinado item em um controle de cabeçalho.

```
BOOL GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice de base zero do item de controle de cabeçalho.

*lpRect*<br/>
Um ponteiro para o endereço de uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que recebe as informações do retângulo delimitador.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método implementa o comportamento da mensagem Win32 [HDM_GETITEMRECT](/windows/win32/Controls/hdm-getitemrect), conforme descrito no SDK do Windows.

##  <a name="getorderarray"></a>CHeaderCtrl::GetOrderArray

Recupera a ordem da esquerda para a direita de itens em um controle de cabeçalho.

```
BOOL GetOrderArray(
    LPINT piArray,
    int iCount);
```

### <a name="parameters"></a>Parâmetros

*piArray*<br/>
Um ponteiro para o endereço de um buffer que recebe os valores de índice dos itens no controle de cabeçalho, na ordem em que aparecem da esquerda para a direita.

*iCount*<br/>
O número de itens de controle de cabeçalho. Deve ser não negativo.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [HDM_GETORDERARRAY](/windows/win32/Controls/hdm-getorderarray)de mensagens Win32, conforme descrito no SDK do Windows. Ele é fornecido para dar suporte à ordenação do item de cabeçalho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#11](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_14.cpp)]

##  <a name="getoverflowrect"></a>CHeaderCtrl::GetOverflowRect

Obtém o retângulo delimitador do botão de estouro do controle de cabeçalho atual.

```
BOOL GetOverflowRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*lpRect*|fora Ponteiro para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que recebe as informações de retângulo delimitador.|

### <a name="return-value"></a>Valor retornado

TRUE se essa função for bem-sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o controle de cabeçalho contiver mais itens do que pode ser exibido simultaneamente, o controle poderá exibir um botão de estouro que rola para os itens que não estão visíveis. O controle de cabeçalho deve ter os estilos HDS_OVERFLOW e HDF_SPLITBUTTON para exibir o botão de estouro. O retângulo delimitador inclui o botão de estouro e existe somente quando o botão de estouro é exibido. Para obter mais informações, consulte [estilos de controle de cabeçalho](/windows/win32/Controls/header-control-styles).

Esse método envia a mensagem de [HDM_GETOVERFLOWRECT](/windows/win32/Controls/hdm-getoverflowrect) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_headerCtrl`, que é usada para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra o método `GetOverflowRect`. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não fique visível. Se algumas colunas não estiverem visíveis, o controle de cabeçalho desenha um botão de estouro. O exemplo de código a seguir desenha um retângulo 3D em volta do local do botão de estouro.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#3](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_15.cpp)]

##  <a name="hittest"></a>CHeaderCtrl:: HitTest

Determina qual item de cabeçalho, se houver, está localizado em um ponto especificado.

```
int HitTest(LPHDHITTESTINFO* phdhti);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*phdhti*|[entrada, saída] Ponteiro para uma estrutura [HDHITTESTINFO](/windows/win32/api/commctrl/ns-commctrl-hdhittestinfo) que especifica o ponto para testar e receber os resultados do teste.|

### <a name="return-value"></a>Valor retornado

O índice de base zero do item de cabeçalho, se houver, na posição especificada; caso contrário,-1.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [HDM_HITTEST](/windows/win32/Controls/hdm-hittest) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_headerCtrl`, que é usada para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra o método `HitTest`. Em uma seção anterior deste exemplo de código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não fique visível. Este exemplo relata o índice da coluna se ela estiver visível e-1 se a coluna não estiver visível.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#1](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_16.cpp)]

##  <a name="insertitem"></a>CHeaderCtrl:: InsertItem

Insere um novo item em um controle de cabeçalho no índice especificado.

```
int InsertItem(
    int nPos,
    HDITEM* phdi);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
O índice de base zero do item a ser inserido. Se o valor for zero, o item será inserido no início do controle de cabeçalho. Se o valor for maior que o valor máximo, o item será inserido no final do controle de cabeçalho.

*phdi*<br/>
Ponteiro para uma estrutura [HDITEM](/windows/win32/api/commctrl/ns-commctrl-hditemw) que contém informações sobre o item a ser inserido.

### <a name="return-value"></a>Valor retornado

Índice do novo item se for bem-sucedido; caso contrário,-1.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#12](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_17.cpp)]

##  <a name="layout"></a>CHeaderCtrl:: layout

Recupera o tamanho e a posição de um controle de cabeçalho em um determinado retângulo.

```
BOOL Layout(HDLAYOUT* pHeaderLayout);
```

### <a name="parameters"></a>Parâmetros

*pHeaderLayout*<br/>
Ponteiro para uma estrutura [HDLAYOUT](/windows/win32/api/commctrl/ns-commctrl-hdlayout) , que contém informações usadas para definir o tamanho e a posição de um controle de cabeçalho.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é usada para determinar as dimensões apropriadas para um novo controle de cabeçalho que deve ocupar o retângulo fornecido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#13](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_18.cpp)]

##  <a name="ordertoindex"></a>CHeaderCtrl::OrderToIndex

Recupera o valor de índice de um item com base em sua ordem no controle de cabeçalho.

```
int OrderToIndex(int nOrder) const;
```

### <a name="parameters"></a>Parâmetros

*nOrder*<br/>
A ordem baseada em zero que o item aparece no controle de cabeçalho, da esquerda para a direita.

### <a name="return-value"></a>Valor retornado

O índice do item, com base em sua ordem no controle de cabeçalho. O índice conta da esquerda para a direita, começando com 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da macro Win32 [HDM_ORDERTOINDEX](/windows/win32/controls/hdm-ordertoindex), conforme descrito na SDK do Windows. Ele é fornecido para dar suporte à ordenação do item de cabeçalho.

##  <a name="setbitmapmargin"></a>CHeaderCtrl::SetBitmapMargin

Define a largura da margem de um bitmap em um controle de cabeçalho.

```
int SetBitmapMargin(int nWidth);
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
Largura, especificada em pixels, da margem que circunda um bitmap dentro de um controle de cabeçalho existente.

### <a name="return-value"></a>Valor retornado

A largura da margem do bitmap em pixels.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [HDM_SETBITMAPMARGIN](/windows/win32/Controls/hdm-setbitmapmargin)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#14](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_19.cpp)]

##  <a name="setfilterchangetimeout"></a>CHeaderCtrl::SetFilterChangeTimeout

Define o intervalo de tempo limite entre a hora em que uma alteração ocorre nos atributos de filtro e o lançamento de uma notificação de [HDN_FILTERCHANGE](/windows/win32/Controls/hdn-filterchange) .

```
int SetFilterChangeTimeout(DWORD dwTimeOut);
```

### <a name="parameters"></a>Parâmetros

*dwTimeOut*<br/>
Valor de tempo limite, em milissegundos.

### <a name="return-value"></a>Valor retornado

O índice do controle de filtro que está sendo modificado.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [HDM_SETFILTERCHANGETIMEOUT](/windows/win32/Controls/hdm-setfilterchangetimeout)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#15](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_20.cpp)]

##  <a name="setfocuseditem"></a>CHeaderCtrl::SetFocusedItem

Define o foco para um item de cabeçalho especificado no controle de cabeçalho atual.

```
BOOL SetFocusedItem(int iItem);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*iItem*|no Índice de base zero de um item de cabeçalho.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [HDM_SETFOCUSEDITEM](/windows/win32/Controls/hdm-setfocuseditem) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_headerCtrl`, que é usada para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra os métodos `SetFocusedItem` e `GetFocusedItem`. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não fique visível. O exemplo a seguir define e confirma o último cabeçalho de coluna como o item de foco.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_10.cpp)]

##  <a name="sethotdivider"></a>CHeaderCtrl::SetHotDivider

Altera o divisor entre itens de cabeçalho para indicar um arrastar e soltar manual de um item de cabeçalho.

```
int SetHotDivider(CPoint pt);
int SetHotDivider(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
A posição do ponteiro. O controle de cabeçalho realça o divisor apropriado com base na posição do ponteiro.

*nIndex*<br/>
O índice do divisor realçado.

### <a name="return-value"></a>Valor retornado

O índice do divisor realçado.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [HDM_SETHOTDIVIDER](/windows/win32/Controls/hdm-sethotdivider)de mensagens Win32, conforme descrito no SDK do Windows. Ele é fornecido para dar suporte ao arrastar e soltar item de cabeçalho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#16](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_21.cpp)]

##  <a name="setimagelist"></a>CHeaderCtrl:: SetImageList

Atribui uma lista de imagens a um controle de cabeçalho.

```
CImageList* SetImageList(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*pImageList*<br/>
Um ponteiro para um objeto `CImageList` que contém a lista de imagens a ser atribuída ao controle de cabeçalho.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto [CImageList](../../mfc/reference/cimagelist-class.md) atribuído anteriormente ao controle de cabeçalho.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [HDM_SETIMAGELIST](/windows/win32/Controls/hdm-setimagelist)de mensagens Win32, conforme descrito no SDK do Windows. O objeto `CImageList` ao qual o ponteiro retornado aponta é um objeto temporário e é excluído no próximo processamento em tempo ocioso.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CHeaderCtrl:: GetImageList](#getimagelist).

##  <a name="setitem"></a>CHeaderCtrl::SetItem

Define os atributos do item especificado em um controle de cabeçalho.

```
BOOL SetItem(
    int nPos,
    HDITEM* pHeaderItem);
```

### <a name="parameters"></a>Parâmetros

*nPos*<br/>
O índice de base zero do item a ser manipulado.

*pHeaderItem*<br/>
Ponteiro para uma estrutura [HDITEM](/windows/win32/api/commctrl/ns-commctrl-hditemw) que contém informações sobre o novo item.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CHeaderCtrl:: GetItem](#getitem).

##  <a name="setorderarray"></a>CHeaderCtrl::SetOrderArray

Define a ordem da esquerda para a direita de itens em um controle de cabeçalho.

```
BOOL SetOrderArray(
    int iCount,
    LPINT piArray);
```

### <a name="parameters"></a>Parâmetros

*iCount*<br/>
O número de itens de controle de cabeçalho.

*piArray*<br/>
Um ponteiro para o endereço de um buffer que recebe os valores de índice dos itens no controle de cabeçalho, na ordem em que aparecem da esquerda para a direita.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da macro Win32 [HDM_SETORDERARRAY](/windows/win32/Controls/hdm-setorderarray), conforme descrito na SDK do Windows. Ele é fornecido para dar suporte à ordenação do item de cabeçalho.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CHeaderCtrl:: GetOrderArray](#getorderarray).

## <a name="see-also"></a>Veja também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CTabCtrl](../../mfc/reference/ctabctrl-class.md)<br/>
[Classe CListCtrl](../../mfc/reference/clistctrl-class.md)<br/>
[Classe CImageList](../../mfc/reference/cimagelist-class.md)
