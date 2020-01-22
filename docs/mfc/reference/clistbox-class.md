---
title: Classe CListBox
description: Uma descrição da classe MFC CListBox e suas funções de membro.
ms.date: 01/22/2020
f1_keywords:
- CListBox
- AFXWIN/CListBox
- AFXWIN/CListBox::CListBox
- AFXWIN/CListBox::AddString
- AFXWIN/CListBox::CharToItem
- AFXWIN/CListBox::CompareItem
- AFXWIN/CListBox::Create
- AFXWIN/CListBox::DeleteItem
- AFXWIN/CListBox::DeleteString
- AFXWIN/CListBox::Dir
- AFXWIN/CListBox::DrawItem
- AFXWIN/CListBox::FindString
- AFXWIN/CListBox::FindStringExact
- AFXWIN/CListBox::GetAnchorIndex
- AFXWIN/CListBox::GetCaretIndex
- AFXWIN/CListBox::GetCount
- AFXWIN/CListBox::GetCurSel
- AFXWIN/CListBox::GetHorizontalExtent
- AFXWIN/CListBox::GetItemData
- AFXWIN/CListBox::GetItemDataPtr
- AFXWIN/CListBox::GetItemHeight
- AFXWIN/CListBox::GetItemRect
- AFXWIN/CListBox::GetListBoxInfo
- AFXWIN/CListBox::GetLocale
- AFXWIN/CListBox::GetSel
- AFXWIN/CListBox::GetSelCount
- AFXWIN/CListBox::GetSelItems
- AFXWIN/CListBox::GetText
- AFXWIN/CListBox::GetTextLen
- AFXWIN/CListBox::GetTopIndex
- AFXWIN/CListBox::InitStorage
- AFXWIN/CListBox::InsertString
- AFXWIN/CListBox::ItemFromPoint
- AFXWIN/CListBox::MeasureItem
- AFXWIN/CListBox::ResetContent
- AFXWIN/CListBox::SelectString
- AFXWIN/CListBox::SelItemRange
- AFXWIN/CListBox::SetAnchorIndex
- AFXWIN/CListBox::SetCaretIndex
- AFXWIN/CListBox::SetColumnWidth
- AFXWIN/CListBox::SetCurSel
- AFXWIN/CListBox::SetHorizontalExtent
- AFXWIN/CListBox::SetItemData
- AFXWIN/CListBox::SetItemDataPtr
- AFXWIN/CListBox::SetItemHeight
- AFXWIN/CListBox::SetLocale
- AFXWIN/CListBox::SetSel
- AFXWIN/CListBox::SetTabStops
- AFXWIN/CListBox::SetTopIndex
- AFXWIN/CListBox::VKeyToItem
helpviewer_keywords:
- CListBox [MFC], CListBox
- CListBox [MFC], AddString
- CListBox [MFC], CharToItem
- CListBox [MFC], CompareItem
- CListBox [MFC], Create
- CListBox [MFC], DeleteItem
- CListBox [MFC], DeleteString
- CListBox [MFC], Dir
- CListBox [MFC], DrawItem
- CListBox [MFC], FindString
- CListBox [MFC], FindStringExact
- CListBox [MFC], GetAnchorIndex
- CListBox [MFC], GetCaretIndex
- CListBox [MFC], GetCount
- CListBox [MFC], GetCurSel
- CListBox [MFC], GetHorizontalExtent
- CListBox [MFC], GetItemData
- CListBox [MFC], GetItemDataPtr
- CListBox [MFC], GetItemHeight
- CListBox [MFC], GetItemRect
- CListBox [MFC], GetListBoxInfo
- CListBox [MFC], GetLocale
- CListBox [MFC], GetSel
- CListBox [MFC], GetSelCount
- CListBox [MFC], GetSelItems
- CListBox [MFC], GetText
- CListBox [MFC], GetTextLen
- CListBox [MFC], GetTopIndex
- CListBox [MFC], InitStorage
- CListBox [MFC], InsertString
- CListBox [MFC], ItemFromPoint
- CListBox [MFC], MeasureItem
- CListBox [MFC], ResetContent
- CListBox [MFC], SelectString
- CListBox [MFC], SelItemRange
- CListBox [MFC], SetAnchorIndex
- CListBox [MFC], SetCaretIndex
- CListBox [MFC], SetColumnWidth
- CListBox [MFC], SetCurSel
- CListBox [MFC], SetHorizontalExtent
- CListBox [MFC], SetItemData
- CListBox [MFC], SetItemDataPtr
- CListBox [MFC], SetItemHeight
- CListBox [MFC], SetLocale
- CListBox [MFC], SetSel
- CListBox [MFC], SetTabStops
- CListBox [MFC], SetTopIndex
- CListBox [MFC], VKeyToItem
ms.assetid: 7ba3c699-c286-4cd9-9066-532c41ec05d1
ms.openlocfilehash: 5c3337641dcfc720a5f9fbccf5bb0614e97c3b54
ms.sourcegitcommit: a930a9b47bd95599265d6ba83bb87e46ae748949
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2020
ms.locfileid: "76518420"
---
# <a name="clistbox-class"></a>Classe CListBox

Fornece a funcionalidade de uma caixa de listagem do Windows.

## <a name="syntax"></a>Sintaxe

```
class CListBox : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Name|Descrição|
|----------|-----------------|
|[CListBox::CListBox](#clistbox)|Constrói um objeto `CListBox`.|

### <a name="public-methods"></a>Métodos Públicos

|Name|Descrição|
|----------|-----------------|
|[CListBox::AddString](#addstring)|Adiciona uma cadeia de caracteres a uma caixa de listagem.|
|[CListBox::CharToItem](#chartoitem)|Substitua para fornecer tratamento de WM_CHAR personalizado para caixas de listagem de desenho proprietário que não têm cadeias de caracteres.|
|[CListBox::CompareItem](#compareitem)|Chamado pelo Framework para determinar a posição de um novo item em uma caixa de listagem de desenho proprietário classificada.|
|[CListBox:: criar](#create)|Cria a caixa de listagem do Windows e a anexa ao objeto `CListBox`.|
|[CListBox::DeleteItem](#deleteitem)|Chamado pelo Framework quando o usuário exclui um item de uma caixa de listagem de desenho proprietário.|
|[CListBox::DeleteString](#deletestring)|Exclui uma cadeia de caracteres de uma caixa de listagem.|
|[CListBox::Dir](#dir)|Adiciona nomes de filedrives, unidades ou ambos do diretório atual a uma caixa de listagem.|
|[CListBox::DrawItem](#drawitem)|Chamado pelo Framework quando um aspecto visual de uma caixa de listagem de desenho proprietário é alterado.|
|[CListBox::FindString](#findstring)|Procura uma cadeia de caracteres em uma caixa de listagem.|
|[CListBox::FindStringExact](#findstringexact)|Localiza a primeira cadeia de caracteres da caixa de listagem que corresponde a uma cadeia de caracteres especificada.|
|[CListBox::GetAnchorIndex](#getanchorindex)|Recupera o índice de base zero do item de âncora atual em uma caixa de listagem.|
|[CListBox::GetCaretIndex](#getcaretindex)|Determina o índice do item que tem o retângulo de foco em uma caixa de listagem de seleção múltipla.|
|[CListBox::GetCount](#getcount)|Retorna o número de cadeias de caracteres em uma caixa de listagem.|
|[CListBox::GetCurSel](#getcursel)|Retorna o índice de base zero da cadeia de caracteres selecionada no momento em uma caixa de listagem.|
|[CListBox::GetHorizontalExtent](#gethorizontalextent)|Retorna a largura em pixels em que uma caixa de listagem pode ser rolada horizontalmente.|
|[CListBox::GetItemData](#getitemdata)|Retorna um valor associado ao item da caixa de listagem.|
|[CListBox::GetItemDataPtr](#getitemdataptr)|Retorna um ponteiro para um item da caixa de listagem.|
|[CListBox::GetItemHeight](#getitemheight)|Determina a altura dos itens em uma caixa de listagem.|
|[CListBox::GetItemRect](#getitemrect)|Retorna o retângulo delimitador do item da caixa de listagem, como ele é exibido no momento.|
|[CListBox::GetListBoxInfo](#getlistboxinfo)|Recupera o número de itens por coluna.|
|[CListBox::GetLocale](#getlocale)|Recupera o identificador de localidade de uma caixa de listagem.|
|[CListBox::GetSel](#getsel)|Retorna o estado de seleção de um item da caixa de listagem.|
|[CListBox::GetSelCount](#getselcount)|Retorna o número de cadeias de caracteres selecionadas atualmente em uma caixa de listagem de seleção múltipla.|
|[CListBox::GetSelItems](#getselitems)|Retorna os índices das cadeias de caracteres selecionadas atualmente em uma caixa de listagem.|
|[CListBox::GetText](#gettext)|Copia um item da caixa de listagem em um buffer.|
|[CListBox::GetTextLen](#gettextlen)|Retorna o comprimento em bytes de um item da caixa de listagem.|
|[CListBox::GetTopIndex](#gettopindex)|Retorna o índice da primeira cadeia de caracteres visível em uma caixa de listagem.|
|[CListBox::InitStorage](#initstorage)|Prefixa blocos de memória para itens da caixa de listagem e cadeias de caracteres.|
|[CListBox::InsertString](#insertstring)|Insere uma cadeia de caracteres em um local específico em uma caixa de listagem.|
|[CListBox::ItemFromPoint](#itemfrompoint)|Retorna o índice do item da caixa de listagem mais próximo de um ponto.|
|[CListBox::MeasureItem](#measureitem)|Chamado pelo Framework quando uma caixa de listagem de desenho proprietário é criada para determinar as dimensões da caixa de listagem.|
|[CListBox::ResetContent](#resetcontent)|Limpa todas as entradas de uma caixa de listagem.|
|[CListBox::SelectString](#selectstring)|Procura e seleciona uma cadeia de caracteres em uma caixa de listagem de seleção única.|
|[CListBox::SelItemRange](#selitemrange)|Seleciona ou anula a seleção de um intervalo de cadeias de caracteres em uma caixa de listagem de seleção múltipla.|
|[CListBox::SetAnchorIndex](#setanchorindex)|Define a âncora em uma caixa de listagem de seleção múltipla para iniciar uma seleção estendida.|
|[CListBox::SetCaretIndex](#setcaretindex)|Define o retângulo de foco para o item no índice especificado em uma caixa de listagem de seleção múltipla.|
|[CListBox::SetColumnWidth](#setcolumnwidth)|Define a largura da coluna de uma caixa de listagem de várias colunas.|
|[CListBox::SetCurSel](#setcursel)|Seleciona uma cadeia de caracteres da caixa de listagem.|
|[CListBox::SetHorizontalExtent](#sethorizontalextent)|Define a largura em pixels em que uma caixa de listagem pode ser rolada horizontalmente.|
|[CListBox::SetItemData](#setitemdata)|Define um valor associado ao item da caixa de listagem.|
|[CListBox::SetItemDataPtr](#setitemdataptr)|Define um ponteiro para o item da caixa de listagem.|
|[CListBox::SetItemHeight](#setitemheight)|Define a altura dos itens em uma caixa de listagem.|
|[CListBox::SetLocale](#setlocale)|Define o identificador de localidade para uma caixa de listagem.|
|[CListBox::SetSel](#setsel)|Seleciona ou anula a seleção de um item da caixa de listagem em uma caixa de listagem de seleção múltipla.|
|[CListBox::SetTabStops](#settabstops)|Define as posições de parada de tabulação em uma caixa de listagem.|
|[CListBox::SetTopIndex](#settopindex)|Define o índice de base zero da primeira cadeia de caracteres visível em uma caixa de listagem.|
|[CListBox::VKeyToItem](#vkeytoitem)|Substitua para fornecer a manipulação de WM_KEYDOWN personalizada para caixas de listagem com o estilo de LBS_WANTKEYBOARDINPUT definido.|

## <a name="remarks"></a>Comentários

Uma caixa de listagem exibe uma lista de itens, como nomes de File, que o usuário pode exibir e selecionar.

Em uma caixa de listagem de seleção única, o usuário pode selecionar apenas um item. Em uma caixa de listagem de seleção múltipla, um intervalo de itens pode ser selecionado. Quando o usuário seleciona um item, ele é realçado e a caixa de listagem envia uma mensagem de notificação para a janela pai.

Você pode criar uma caixa de listagem a partir de um modelo de diálogo ou diretamente no seu código. Para criá-lo diretamente, construa o objeto `CListBox` e, em seguida, chame a função [criar](#create) membro para criar o controle da caixa de listagem do Windows e anexá-lo ao objeto `CListBox`. Para usar uma caixa de listagem em um modelo de caixa de diálogo, declare uma variável do box na sua classe caixa de diálogo e, em seguida, use `DDX_Control` na função `DoDataExchange` da sua caixa de diálogo para conectar a variável de membro ao controle. (isso é feito para você automaticamente quando você adiciona uma variável de controle à sua classe de caixa de diálogo.)

A construção pode ser um processo de uma etapa em uma classe derivada de `CListBox`. Escreva um construtor para a classe derivada e chame `Create` de dentro do construtor.

Se você quiser manipular as mensagens de notificação do Windows enviadas por uma caixa de listagem para seu pai (geralmente uma classe derivada de [CDialog](../../mfc/reference/cdialog-class.md)), adicione uma entrada de mapa de mensagem e uma função de membro de manipulador de mensagens à classe pai para cada mensagem.

Cada entrada de mapa de mensagem usa o seguinte formato:

`ON_Notification( id, memberFxn )`

em que `id` especifica a ID da janela filho do controle da caixa de listagem que envia a notificação e `memberFxn` é o nome da função de membro pai que você escreveu para manipular a notificação.

O protótipo de função do pai é o seguinte:

`afx_msg void memberFxn( );`

A seguir está uma lista de possíveis entradas de mapa de mensagem e uma descrição dos casos em que eles seriam enviados para o pai:

- ON_LBN_DBLCLK o usuário clica duas vezes em uma cadeia de caracteres em uma caixa de listagem. Somente uma caixa de listagem com o estilo de [LBS_NOTIFY](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) enviará essa mensagem de notificação.

- ON_LBN_ERRSPACE caixa de listagem não pode alocar memória suficiente para atender à solicitação.

- ON_LBN_KILLFOCUS caixa de listagem está perdendo o foco de entrada.

- ON_LBN_SELCANCEL a seleção atual da caixa de listagem é cancelada. Esta mensagem é enviada somente quando uma caixa de listagem tem o estilo de LBS_NOTIFY.

- ON_LBN_SELCHANGE a seleção na caixa de listagem foi alterada. Essa notificação não será enviada se a seleção for alterada pela função de membro [CListBox:: Setcurseal](#setcursel) . Essa notificação se aplica somente a uma caixa de listagem que tem o estilo de LBS_NOTIFY. A LBN_SELCHANGE mensagem de notificação é enviada para uma caixa de listagem de seleção múltipla sempre que o usuário pressiona uma tecla de seta, mesmo que a seleção não seja alterada.

- ON_LBN_SETFOCUS caixa de listagem está recebendo o foco de entrada.

- ON_WM_CHARTOITEM uma caixa de listagem de desenho proprietário que não tem cadeias de caracteres recebe uma mensagem de WM_CHAR.

- ON_WM_VKEYTOITEM uma caixa de listagem com o estilo de LBS_WANTKEYBOARDINPUT recebe uma mensagem de WM_KEYDOWN.

Se você criar um objeto `CListBox` dentro de uma caixa de diálogo (por meio de um recurso de caixa de diálogo), o objeto `CListBox` será destruído automaticamente quando o usuário fechar a caixa de diálogo.

Se você criar um objeto de `CListBox` dentro de uma janela, talvez seja necessário destruir o objeto `CListBox`. Se você criar o objeto `CListBox` na pilha, ele será destruído automaticamente. Se você criar o objeto `CListBox` no heap usando a **nova** função, deverá chamar **delete** no objeto para destruí-lo quando o usuário fechar a janela pai.

Se você alocar qualquer memória no objeto `CListBox`, substitua o destruidor `CListBox` para descartar a alocação.

## <a name="inheritance-hierarchy"></a>Hierarquia de Herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CListBox`

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** Afxwin. h

##  <a name="addstring"></a>  CListBox::AddString

Adiciona uma cadeia de caracteres a uma caixa de listagem.

```
int AddString(LPCTSTR lpszItem);
```

### <a name="parameters"></a>Parâmetros

*lpszItem*<br/>
Aponta para a cadeia de caracteres terminada em nulo que deve ser adicionada.

### <a name="return-value"></a>Valor de retorno

O índice de base zero para a cadeia de caracteres na caixa de listagem. O valor de retorno será LB_ERR se ocorrer um erro; o valor de retorno será LB_ERRSPACE se houver espaço insuficiente disponível para armazenar a nova cadeia de caracteres.

### <a name="remarks"></a>Comentários

Se a caixa de listagem não foi criada com o estilo de [LBS_SORT](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) , a cadeia de caracteres será adicionada ao final da lista. Caso contrário, a cadeia de caracteres será inserida na lista e a lista será classificada. Se a caixa de listagem tiver sido criada com o estilo de LBS_SORT, mas não o estilo de [LBS_HASSTRINGS](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) , a estrutura classificará a lista por uma ou mais chamadas para a função membro `CompareItem`.

Use [InsertString](#insertstring) para inserir uma cadeia de caracteres em um local específico dentro da caixa de listagem.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#3](../../mfc/codesnippet/cpp/clistbox-class_1.cpp)]

##  <a name="chartoitem"></a>  CListBox::CharToItem

Chamado pelo Framework quando a janela pai da caixa de listagem recebe uma mensagem de WM_CHARTOITEM da caixa de listagem.

```
virtual int CharToItem(
    UINT nKey,
    UINT nIndex);
```

### <a name="parameters"></a>Parâmetros

*nKey*<br/>
O código ANSI do caractere digitado pelo usuário.

*nIndex*<br/>
A posição atual do cursor da caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Retorna-1 ou-2 para nenhuma ação adicional ou um número não negativo para especificar um índice de um item da caixa de listagem no qual executar a ação padrão para o pressionamento de tecla. A implementação padrão retorna-1.

### <a name="remarks"></a>Comentários

A mensagem de WM_CHARTOITEM é enviada pela caixa de listagem quando recebe uma mensagem de WM_CHAR, mas somente se a caixa de listagem atender a todos esses critérios:

- É uma caixa de listagem de desenho proprietário.

- Não tem o estilo de [LBS_HASSTRINGS](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) definido.

- Tem pelo menos um item.

Você mesmo nunca deve chamar essa função. Substitua essa função para fornecer sua própria manipulação personalizada de mensagens de teclado.

Em sua substituição, você deve retornar um valor para informar ao Framework qual ação você executou. Um valor de retorno de-1 ou-2 indica que você tratou todos os aspectos da seleção do item e não requer nenhuma ação adicional na caixa de listagem. Antes de retornar-1 ou-2, você pode definir a seleção ou mover o cursor ou ambos. Para definir a seleção, use [Setcurseal](#setcursel) ou [SetSel](#setsel). Para mover o cursor, use [SetCaretIndex](#setcaretindex).

Um valor de retorno 0 ou maior especifica o índice de um item na caixa de listagem e indica que a caixa de listagem deve executar a ação padrão para o pressionamento de tecla no item determinado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#4](../../mfc/codesnippet/cpp/clistbox-class_2.cpp)]

##  <a name="clistbox"></a>CListBox::CListBox

Constrói um objeto `CListBox`.

```
CListBox();
```

### <a name="remarks"></a>Comentários

Você constrói um objeto `CListBox` em duas etapas. Primeiro, chame o Construtor `ClistBox` e, em seguida, chame `Create`, que inicializa a caixa de listagem do Windows e a anexa à `CListBox`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#1](../../mfc/codesnippet/cpp/clistbox-class_3.cpp)]

##  <a name="compareitem"></a>  CListBox::CompareItem

Chamado pelo Framework para determinar a posição relativa de um novo item em uma caixa de listagem de desenho de proprietário classificada.

```
virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpCompareItemStruct*<br/>
Um ponteiro longo para uma estrutura de `COMPAREITEMSTRUCT`.

### <a name="return-value"></a>Valor de retorno

Indica a posição relativa dos dois itens descritos na estrutura [COMPAREITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-compareitemstruct) . Pode ser qualquer um dos seguintes valores:

|Value|Significado|
|-----------|-------------|
|-1|Item 1 classifica antes do item 2.|
|0|O item 1 e o item 2 são classificados da mesma forma.|
|1|O item 1 é classificado após o item 2.|

Consulte [CWnd:: OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem) para obter uma descrição da estrutura de `COMPAREITEMSTRUCT`.

### <a name="remarks"></a>Comentários

Por padrão, essa função de membro não faz nada. Se você criar uma caixa de listagem de desenho proprietário com o estilo de LBS_SORT, deverá substituir essa função de membro para ajudar a estrutura na classificação de novos itens adicionados à caixa de listagem.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#5](../../mfc/codesnippet/cpp/clistbox-class_4.cpp)]

##  <a name="create"></a>CListBox:: criar

Cria a caixa de listagem do Windows e a anexa ao objeto `CListBox`.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo da caixa de listagem. Aplique qualquer combinação de [estilos de caixa de listagem](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) à caixa.

*rect*<br/>
Especifica o tamanho e a posição da caixa de listagem. Pode ser um objeto `CRect` ou uma estrutura de `RECT`.

*pParentWnd*<br/>
Especifica a janela pai da caixa de listagem (geralmente um objeto `CDialog`). Ele não deve ser nulo.

*nID*<br/>
Especifica a ID de controle da caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um objeto `CListBox` em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que inicializa a caixa de listagem do Windows e a anexa ao objeto `CListBox`.

Quando `Create` é executado, o Windows envia as mensagens [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize)e [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) para o controle da caixa de listagem.

Essas mensagens são tratadas por padrão pelas funções de membro [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate), [OnCreate](../../mfc/reference/cwnd-class.md#oncreate), [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize)e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) na classe base `CWnd`. Para estender a manipulação de mensagens padrão, derive uma classe de `CListBox`, adicione um mapa de mensagem à nova classe e substitua as funções de membro do manipulador de mensagens anterior. Substitua `OnCreate`, por exemplo, para executar a inicialização necessária para uma nova classe.

Aplique os seguintes [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de caixa de listagem.

- WS_CHILD sempre

- Geralmente WS_VISIBLE

- WS_DISABLED raramente

- WS_VSCROLL adicionar uma barra de rolagem vertical

- WS_HSCROLL adicionar uma barra de rolagem horizontal

- WS_GROUP a controles de grupo

- WS_TABSTOP permitir a Tabulação deste controle

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#2](../../mfc/codesnippet/cpp/clistbox-class_5.cpp)]

##  <a name="deleteitem"></a>  CListBox::DeleteItem

Chamado pelo Framework quando o usuário exclui um item de um objeto `CListBox` de desenho proprietário ou destrói a caixa de listagem.

```
virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDeleteItemStruct*<br/>
Um ponteiro longo para uma estrutura [DELETEITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-deleteitemstruct) do Windows que contém informações sobre o item excluído.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada. Substitua essa função para redesenhar uma caixa de listagem de desenho proprietário conforme necessário.

Consulte [CWnd:: OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem) para obter uma descrição da estrutura de `DELETEITEMSTRUCT`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#6](../../mfc/codesnippet/cpp/clistbox-class_6.cpp)]

##  <a name="deletestring"></a>  CListBox::DeleteString

Exclui o item na posição *nIndex* da caixa de listagem.

```
int DeleteString(UINT nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero da cadeia de caracteres a ser excluída.

### <a name="return-value"></a>Valor de retorno

Uma contagem das cadeias de caracteres restantes na lista. O valor de retorno será LB_ERR se *nIndex* especificar um índice maior que o número de itens na lista.

### <a name="remarks"></a>Comentários

Todos os itens após *nIndex* agora se movem uma posição para baixo. Por exemplo, se uma caixa de listagem contiver dois itens, a exclusão do primeiro item fará com que o item restante esteja agora na primeira posição. *nIndex*= 0 para o item na primeira posição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#7](../../mfc/codesnippet/cpp/clistbox-class_7.cpp)]

##  <a name="dir"></a>CListBox::D ir

Adiciona uma lista de nomes de filedrives, unidades ou ambos a uma caixa de listagem.

```
int Dir(
    UINT attr,
    LPCTSTR lpszWildCard);
```

### <a name="parameters"></a>Parâmetros

*attr*<br/>
Pode ser qualquer combinação dos valores de **Enumeração** descritos em `CFile::GetStatu`[s](../../mfc/reference/cfile-class.md#getstatus)ou qualquer combinação dos seguintes valores:

|Value|Significado|
|-----------|-------------|
|0x0000|O arquivo pode ser lido ou gravado.|
|0x0001|O arquivo pode ser lido, mas não gravado no.|
|0x0002|O arquivo está oculto e não aparece em uma listagem de diretório.|
|0x0004|O arquivo é um arquivo do sistema.|
|0x0010|O nome especificado por *lpszWildCard* especifica um diretório.|
|0x0020|O arquivo foi arquivado.|
|0x4000|Inclua todas as unidades que correspondem ao nome especificado por *lpszWildCard*.|
|0x8000|Sinalizador exclusivo. Se o sinalizador exclusivo for definido, somente os arquivos do tipo especificado serão listados. Caso contrário, os arquivos do tipo especificado serão listados, além dos arquivos "normal".|

*lpszWildCard*<br/>
Aponta para uma cadeia de caracteres de especificação de arquivo. A cadeia de caracteres pode conter curingas (por exemplo, *.\*).

### <a name="return-value"></a>Valor de retorno

O índice de base zero do último nome de arquivo adicionado à lista. O valor de retorno será LB_ERR se ocorrer um erro; o valor de retorno será LB_ERRSPACE se houver espaço insuficiente disponível para armazenar as novas cadeias de caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#8](../../mfc/codesnippet/cpp/clistbox-class_8.cpp)]

##  <a name="drawitem"></a>  CListBox::DrawItem

Chamado pelo Framework quando um aspecto visual de uma caixa de listagem de desenho proprietário é alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro longo para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

Os membros `itemAction` e `itemState` da estrutura de `DRAWITEMSTRUCT` definem a ação de desenho a ser executada.

Por padrão, essa função de membro não faz nada. Substitua essa função de membro para implementar o desenho de um objeto de `CListBox` de desenho proprietário. O aplicativo deve restaurar todos os objetos da interface de dispositivo de gráficos (GDI) selecionados para o contexto de exibição fornecido em *lpDrawItemStruct* antes que essa função de membro seja encerrada.

Consulte [CWnd:: OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição da estrutura de `DRAWITEMSTRUCT`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#9](../../mfc/codesnippet/cpp/clistbox-class_9.cpp)]

##  <a name="findstring"></a>  CListBox::FindString

Localiza a primeira cadeia de caracteres em uma caixa de listagem que contém o prefixo especificado sem alterar a seleção da caixa de listagem.

```
int FindString(
    int nStartAfter,
    LPCTSTR lpszItem) const;
```

### <a name="parameters"></a>Parâmetros

*nStartAfter*<br/>
Contém o índice de base zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa atingir a parte inferior da caixa de listagem, ela continuará na parte superior da caixa de listagem de volta para o item especificado por *nStartAfter*. Se *nStartAfter* for-1, a caixa de listagem inteira será pesquisada desde o início.

*lpszItem*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo a ser pesquisado. A pesquisa diferencia maiúsculas de minúsculas, portanto, essa cadeia de caracteres pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor de retorno

O índice de base zero do item correspondente ou LB_ERR se a pesquisa não foi bem-sucedida.

### <a name="remarks"></a>Comentários

Use a função de membro [SelectString](#selectstring) para localizar e selecionar uma cadeia de caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#10](../../mfc/codesnippet/cpp/clistbox-class_10.cpp)]

##  <a name="findstringexact"></a>  CListBox::FindStringExact

Localiza a primeira cadeia de caracteres da caixa de listagem que corresponde à cadeia de caracteres especificada em *lpszFind*.

```
int FindStringExact(
    int nIndexStart,
    LPCTSTR lpszFind) const;
```

### <a name="parameters"></a>Parâmetros

*nIndexStart*<br/>
Especifica o índice de base zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa atingir a parte inferior da caixa de listagem, ela continuará na parte superior da caixa de listagem de volta para o item especificado por *nIndexStart*. Se *nIndexStart* for-1, a caixa de listagem inteira será pesquisada desde o início.

*lpszFind*<br/>
Aponta para a cadeia de caracteres terminada em nulo a ser pesquisada. Essa cadeia de caracteres pode conter um nome de arquivo completo, incluindo a extensão. A pesquisa não diferencia maiúsculas de minúsculas, portanto, a cadeia de caracteres pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor de retorno

O índice do item correspondente ou LB_ERR se a pesquisa não tiver sido bem-sucedida.

### <a name="remarks"></a>Comentários

Se a caixa de listagem tiver sido criada com um estilo de desenho proprietário, mas sem o estilo [LBS_HASSTRINGS](../../mfc/reference/styles-used-by-mfc.md#list-box-styles), a função de membro `FindStringExact` tentará corresponder o valor de doubleword em relação ao valor de *lpszFind*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#11](../../mfc/codesnippet/cpp/clistbox-class_11.cpp)]

##  <a name="getanchorindex"></a>  CListBox::GetAnchorIndex

Recupera o índice de base zero do item de âncora atual na caixa de listagem.

```
int GetAnchorIndex() const;
```

### <a name="return-value"></a>Valor de retorno

O índice do item de âncora atual, se bem-sucedido; caso contrário LB_ERR.

### <a name="remarks"></a>Comentários

Em uma caixa de listagem de seleção múltipla, o item de âncora é o primeiro ou o último item em um bloco de itens selecionados contíguos.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CListBox:: SetAnchorIndex](#setanchorindex).

##  <a name="getcaretindex"></a>  CListBox::GetCaretIndex

Determina o índice do item que tem o retângulo de foco em uma caixa de listagem de seleção múltipla.

```
int GetCaretIndex() const;
```

### <a name="return-value"></a>Valor de retorno

O índice de base zero do item que tem o retângulo de foco em uma caixa de listagem. Se a caixa de listagem for uma caixa de listagem de seleção única, o valor de retorno será o índice do item selecionado, se houver.

### <a name="remarks"></a>Comentários

O item pode ou não ser selecionado.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CListBox:: SetCaretIndex](#setcaretindex).

##  <a name="getcount"></a>  CListBox::GetCount

Recupera o número de itens em uma caixa de listagem.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens na caixa de listagem ou LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

A contagem retornada é uma maior que o valor de índice do último item (o índice é baseado em zero).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#12](../../mfc/codesnippet/cpp/clistbox-class_12.cpp)]

##  <a name="getcursel"></a>  CListBox::GetCurSel

Recupera o índice de base zero do item selecionado no momento, se houver, em uma caixa de listagem de seleção única.

```
int GetCurSel() const;
```

### <a name="return-value"></a>Valor de retorno

O índice de base zero do item selecionado no momento se for uma caixa de listagem de seleção única. Será LB_ERR se nenhum item estiver selecionado no momento.

Em uma caixa de listagem de seleção múltipla, o índice do item que tem o foco.

### <a name="remarks"></a>Comentários

Não chame `GetCurSel` para uma caixa de listagem de seleção múltipla. Use [CListBox:: GetSelItems](#getselitems) em vez disso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#13](../../mfc/codesnippet/cpp/clistbox-class_13.cpp)]

##  <a name="gethorizontalextent"></a>  CListBox::GetHorizontalExtent

Recupera da caixa de listagem a largura em pixels pela qual ela pode ser rolada horizontalmente.

```
int GetHorizontalExtent() const;
```

### <a name="return-value"></a>Valor de retorno

A largura rolável da caixa de listagem, em pixels.

### <a name="remarks"></a>Comentários

Isso será aplicável somente se a caixa de listagem tiver uma barra de rolagem horizontal.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#14](../../mfc/codesnippet/cpp/clistbox-class_14.cpp)]

##  <a name="getitemdata"></a>  CListBox::GetItemData

Recupera o valor de doubleword fornecido pelo aplicativo associado ao item da caixa de listagem especificado.

```
DWORD_PTR GetItemData(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

O valor associado ao item ou LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

O valor de doubleword era o parâmetro *dwItemData* de uma chamada [SetItemData](#setitemdata) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#15](../../mfc/codesnippet/cpp/clistbox-class_15.cpp)]

##  <a name="getitemdataptr"></a>  CListBox::GetItemDataPtr

Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item da caixa de listagem especificado como um ponteiro (**void** <strong>\*</strong>).

```
void* GetItemDataPtr(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Recupera um ponteiro ou-1 se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#16](../../mfc/codesnippet/cpp/clistbox-class_16.cpp)]

##  <a name="getitemheight"></a>  CListBox::GetItemHeight

Determina a altura dos itens em uma caixa de listagem.

```
int GetItemHeight(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item na caixa de listagem. Esse parâmetro será usado somente se a caixa de listagem tiver o estilo de LBS_OWNERDRAWVARIABLE; caso contrário, ele deve ser definido como 0.

### <a name="return-value"></a>Valor de retorno

A altura, em pixels, dos itens na caixa de listagem. Se a caixa de listagem tiver o estilo de [LBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) , o valor de retorno será a altura do item especificado por *nIndex*. Se ocorrer um erro, o valor de retorno será LB_ERR.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#17](../../mfc/codesnippet/cpp/clistbox-class_17.cpp)]

##  <a name="getitemrect"></a>  CListBox::GetItemRect

Recupera as dimensões do retângulo que vincula um item da caixa de listagem, como ele é exibido atualmente na janela da caixa de listagem.

```
int GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item.

*lpRect*<br/>
Especifica um ponteiro longo para uma [estrutura RECT](/windows/win32/api/windef/ns-windef-rect) que recebe as coordenadas de cliente da caixa de listagem do item.

### <a name="return-value"></a>Valor de retorno

LB_ERR se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#18](../../mfc/codesnippet/cpp/clistbox-class_18.cpp)]

##  <a name="getlistboxinfo"></a>  CListBox::GetListBoxInfo

Recupera o número de itens por coluna.

```
DWORD GetListBoxInfo() const;
```

### <a name="return-value"></a>Valor de retorno

Número de itens por coluna do objeto de `CListBox`.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da [LB_GETLISTBOXINFO](/windows/win32/Controls/lb-getlistboxinfo) mensagem, conforme descrito na SDK do Windows.

##  <a name="getlocale"></a>  CListBox::GetLocale

Recupera a localidade usada pela caixa de listagem.

```
LCID GetLocale() const;
```

### <a name="return-value"></a>Valor de retorno

O valor do identificador de localidade (LCID) para as cadeias de caracteres na caixa de listagem.

### <a name="remarks"></a>Comentários

A localidade é usada, por exemplo, para determinar a ordem de classificação das cadeias de caracteres em uma caixa de listagem classificada.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CListBox:: setlocale](#setlocale).

##  <a name="getsel"></a>  CListBox::GetSel

Recupera o estado de seleção de um item.

```
int GetSel(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item.

### <a name="return-value"></a>Valor de retorno

Um número positivo se o item especificado for selecionado; caso contrário, será 0. O valor de retorno será LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Essa função de membro funciona com caixas de listagem de seleção única e múltipla.

Para recuperar o índice do item da caixa de listagem selecionado no momento, use [CListBox:: Getcurseal](#getcursel).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#19](../../mfc/codesnippet/cpp/clistbox-class_19.cpp)]

##  <a name="getselcount"></a>  CListBox::GetSelCount

Recupera o número total de itens selecionados em uma caixa de listagem de seleção múltipla.

```
int GetSelCount() const;
```

### <a name="return-value"></a>Valor de retorno

A contagem de itens selecionados em uma caixa de listagem. Se a caixa de listagem for uma caixa de listagem de seleção única, o valor de retorno será LB_ERR.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CListBox:: GetSelItems](#getselitems).

##  <a name="getselitems"></a>  CListBox::GetSelItems

Preenche um buffer com uma matriz de inteiros que especifica os números de item dos itens selecionados em uma caixa de listagem de seleção múltipla.

```
int GetSelItems(
    int nMaxItems,
    LPINT rgIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nMaxItems*<br/>
Especifica o número máximo de itens selecionados cujos números de item devem ser colocados no buffer.

*rgIndex*<br/>
Especifica um ponteiro para um buffer grande o suficiente para o número de inteiros especificados por *nMaxItems*.

### <a name="return-value"></a>Valor de retorno

O número real de itens colocados no buffer. Se a caixa de listagem for uma caixa de listagem de seleção única, o valor de retorno será `LB_ERR`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#20](../../mfc/codesnippet/cpp/clistbox-class_20.cpp)]

##  <a name="gettext"></a>  CListBox::GetText

Obtém uma cadeia de caracteres de uma caixa de listagem.

```
int GetText(
    int nIndex,
    LPTSTR lpszBuffer) const;

void GetText(
    int nIndex,
    CString& rString) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero da cadeia de caracteres a ser recuperada.

*lpszBuffer*<br/>
Aponta para o buffer que recebe a cadeia de caracteres. O buffer deve ter espaço suficiente para a cadeia de caracteres e um caractere nulo de terminação. O tamanho da cadeia de caracteres pode ser determinado antecipadamente chamando a função membro `GetTextLen`.

*rString*<br/>
Uma referência a um objeto `CString`.

### <a name="return-value"></a>Valor de retorno

O comprimento (em bytes) da cadeia de caracteres, excluindo o caractere nulo de terminação. Se *nIndex* não especificar um índice válido, o valor de retorno será LB_ERR.

### <a name="remarks"></a>Comentários

A segunda forma dessa função de membro preenche um objeto `CString` com o texto da cadeia de caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#21](../../mfc/codesnippet/cpp/clistbox-class_21.cpp)]

##  <a name="gettextlen"></a>  CListBox::GetTextLen

Obtém o comprimento de uma cadeia de caracteres em um item da caixa de listagem.

```
int GetTextLen(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero da cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

O comprimento da cadeia em caracteres, excluindo o caractere nulo de terminação. Se *nIndex* não especificar um índice válido, o valor de retorno será LB_ERR.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CListBox:: gettext](#gettext).

##  <a name="gettopindex"></a>  CListBox::GetTopIndex

Recupera o índice de base zero do primeiro item visível em uma caixa de listagem.

```
int GetTopIndex() const;
```

### <a name="return-value"></a>Valor de retorno

O índice de base zero do primeiro item visível em uma caixa de listagem, se for bem-sucedido, LB_ERR caso contrário.

### <a name="remarks"></a>Comentários

Inicialmente, o item 0 está na parte superior da caixa de listagem, mas se a caixa de listagem for rolada, outro item poderá estar na parte superior.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#22](../../mfc/codesnippet/cpp/clistbox-class_22.cpp)]

##  <a name="initstorage"></a>  CListBox::InitStorage

Aloca memória para armazenar itens da caixa de listagem.

```
int InitStorage(
    int nItems,
    UINT nBytes);
```

### <a name="parameters"></a>Parâmetros

*nItems*<br/>
Especifica o número de itens a serem adicionados.

*nBytes*<br/>
Especifica a quantidade de memória, em bytes, a ser alocada para cadeias de caracteres de item.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o número máximo de itens que a caixa de listagem pode armazenar antes de uma realocação de memória é necessária, caso contrário LB_ERRSPACE, o que significa que não há memória suficiente disponível.

### <a name="remarks"></a>Comentários

Chame essa função antes de adicionar um grande número de itens a um `CListBox`.

Essa função ajuda a acelerar a inicialização de caixas de listagem que têm um grande número de itens (mais de 100). Ele prealoque a quantidade especificada de memória para que as funções [AddString](#addstring), [InsertString](#insertstring)e [dir](#dir) subsequentes tenham o menor tempo possível. Você pode usar estimativas para os parâmetros. Se você superestimar, uma memória extra é alocada; Se você subestimar, a alocação normal será usada para itens que excedem o valor prealocado.

Somente Windows 95/98: o parâmetro *nItems* é limitado a valores de 16 bits. Isso significa que as caixas de listagem não podem conter mais de 32.767 itens. Embora o número de itens seja restrito, o tamanho total dos itens em uma caixa de listagem é limitado apenas pela memória disponível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#23](../../mfc/codesnippet/cpp/clistbox-class_23.cpp)]

##  <a name="insertstring"></a>  CListBox::InsertString

Insere uma cadeia de caracteres na caixa de listagem.

```
int InsertString(
    int nIndex,
    LPCTSTR lpszItem);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero da posição para inserir a cadeia de caracteres. Se esse parâmetro for-1, a cadeia de caracteres será adicionada ao final da lista.

*lpszItem*<br/>
Aponta para a cadeia de caracteres terminada em nulo que deve ser inserida.

### <a name="return-value"></a>Valor de retorno

O índice de base zero da posição na qual a cadeia de caracteres foi inserida. O valor de retorno será LB_ERR se ocorrer um erro; o valor de retorno será LB_ERRSPACE se houver espaço insuficiente disponível para armazenar a nova cadeia de caracteres.

### <a name="remarks"></a>Comentários

Ao contrário da função de membro [AddString](#addstring) , `InsertString` não faz com que uma lista com o estilo de [LBS_SORT](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) seja classificada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#24](../../mfc/codesnippet/cpp/clistbox-class_24.cpp)]

##  <a name="itemfrompoint"></a>  CListBox::ItemFromPoint

Determina o item da caixa de listagem próximo ao ponto especificado em *pt*.

```
UINT ItemFromPoint(
    CPoint pt,
    BOOL& bOutside) const;
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Ponto para o qual encontrar o item mais próximo, especificado em relação ao canto superior esquerdo da área do cliente da caixa de listagem.

*bOutside*<br/>
Referência a uma variável BOOL que será definida como TRUE se *pt* estiver fora da área do cliente da caixa de listagem, false se *pt* estiver dentro da área do cliente da caixa de listagem.

### <a name="return-value"></a>Valor de retorno

O índice do item mais próximo ao ponto especificado em *pt*.

### <a name="remarks"></a>Comentários

Você pode usar essa função para determinar a qual item da caixa de listagem o cursor do mouse se move.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CListBox:: SetAnchorIndex](#setanchorindex).

##  <a name="measureitem"></a>CListBox::MeasureItem

Chamado pelo Framework quando uma caixa de listagem com um estilo de desenho proprietário é criada.

```
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpMeasureItemStruct*<br/>
Um ponteiro longo para uma estrutura [MEASUREITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-measureitemstruct) .

### <a name="remarks"></a>Comentários

Por padrão, essa função de membro não faz nada. Substitua essa função de membro e preencha a estrutura de `MEASUREITEMSTRUCT` para informar o Windows das dimensões da caixa de listagem. Se a caixa de listagem for criada com o estilo de [LBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) , a estrutura chamará essa função de membro para cada item na caixa de listagem. Caso contrário, esse membro será chamado apenas uma vez.

Para obter mais informações sobre como usar o estilo de [LBS_OWNERDRAWFIXED](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) em uma caixa de listagem de desenho proprietário criada com a `SubclassDlgItem` função membro do `CWnd`, consulte a discussão na [Nota técnica 14](../../mfc/tn014-custom-controls.md).

Consulte [CWnd:: OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter uma descrição da estrutura de `MEASUREITEMSTRUCT`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#25](../../mfc/codesnippet/cpp/clistbox-class_25.cpp)]

##  <a name="resetcontent"></a>  CListBox::ResetContent

Remove todos os itens de uma caixa de listagem.

```
void ResetContent();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#26](../../mfc/codesnippet/cpp/clistbox-class_26.cpp)]

##  <a name="selectstring"></a>  CListBox::SelectString

Procura um item da caixa de listagem que corresponda à cadeia de caracteres especificada e, se um item correspondente for encontrado, ele selecionará o item.

```
int SelectString(
    int nStartAfter,
    LPCTSTR lpszItem);
```

### <a name="parameters"></a>Parâmetros

*nStartAfter*<br/>
Contém o índice de base zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa atingir a parte inferior da caixa de listagem, ela continuará na parte superior da caixa de listagem de volta para o item especificado por *nStartAfter*. Se *nStartAfter* for-1, a caixa de listagem inteira será pesquisada desde o início.

*lpszItem*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo a ser pesquisado. A pesquisa diferencia maiúsculas de minúsculas, portanto, essa cadeia de caracteres pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor de retorno

O índice do item selecionado se a pesquisa foi bem-sucedida. Se a pesquisa não tiver sido bem-sucedida, o valor de retorno será LB_ERR e a seleção atual não será alterada.

### <a name="remarks"></a>Comentários

A caixa de listagem é rolada, se necessário, para colocar o item selecionado em exibição.

Esta função de membro não pode ser usada com uma caixa de listagem que tenha o estilo de [LBS_MULTIPLESEL](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) .

Um item será selecionado somente se seus caracteres iniciais (do ponto de partida) corresponderem aos caracteres na cadeia de caracteres especificada por *lpszItem*.

Use a função de membro `FindString` para localizar uma cadeia de caracteres sem selecionar o item.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#27](../../mfc/codesnippet/cpp/clistbox-class_27.cpp)]

##  <a name="selitemrange"></a>  CListBox::SelItemRange

Seleciona vários itens consecutivos em uma caixa de listagem de seleção múltipla.

```
int SelItemRange(
    BOOL bSelect,
    int nFirstItem,
    int nLastItem);
```

### <a name="parameters"></a>Parâmetros

*bSelect*<br/>
Especifica como definir a seleção. Se *bSelect* for true, a cadeia de caracteres será selecionada e realçada; Se for FALSE, o realce será removido e a cadeia de caracteres não será mais selecionada.

*nFirstItem*<br/>
Especifica o índice de base zero do primeiro item a ser definido.

*nLastItem*<br/>
Especifica o índice de base zero do último item a ser definido.

### <a name="return-value"></a>Valor de retorno

LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Use essa função de membro somente com caixas de listagem de seleção múltipla. Se você precisar selecionar apenas um item em uma caixa de listagem de seleção múltipla, ou seja, se *nFirstItem* for igual a *nLastItem* , chame a função membro [SetSel](#setsel) em vez disso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#28](../../mfc/codesnippet/cpp/clistbox-class_28.cpp)]

##  <a name="setanchorindex"></a>  CListBox::SetAnchorIndex

Define a âncora em uma caixa de listagem de seleção múltipla para iniciar uma seleção estendida.

```
void SetAnchorIndex(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item da caixa de listagem que será a âncora.

### <a name="remarks"></a>Comentários

Em uma caixa de listagem de seleção múltipla, o item de âncora é o primeiro ou o último item em um bloco de itens selecionados contíguos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#29](../../mfc/codesnippet/cpp/clistbox-class_29.cpp)]

##  <a name="setcaretindex"></a>  CListBox::SetCaretIndex

Define o retângulo de foco para o item no índice especificado em uma caixa de listagem de seleção múltipla.

```
int SetCaretIndex(
    int nIndex,
    BOOL bScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item para receber o retângulo de foco na caixa de listagem.

*bScroll*<br/>
Se esse valor for 0, o item será rolado até que fique totalmente visível. Se esse valor não for 0, o item será rolado até que seja pelo menos parcialmente visível.

### <a name="return-value"></a>Valor de retorno

LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Se o item não estiver visível, ele será rolado para a exibição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#30](../../mfc/codesnippet/cpp/clistbox-class_30.cpp)]

##  <a name="setcolumnwidth"></a>  CListBox::SetColumnWidth

Define a largura em pixels de todas as colunas em uma caixa de listagem de várias colunas (criada com o estilo de [LBS_MULTICOLUMN](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) ).

```
void SetColumnWidth(int cxWidth);
```

### <a name="parameters"></a>Parâmetros

*cxWidth*<br/>
Especifica a largura em pixels de todas as colunas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#31](../../mfc/codesnippet/cpp/clistbox-class_31.cpp)]

##  <a name="setcursel"></a>  CListBox::SetCurSel

Seleciona uma cadeia de caracteres e a rola para a exibição, se necessário.

```
int SetCurSel(int nSelect);
```

### <a name="parameters"></a>Parâmetros

*nSelect*<br/>
Especifica o índice de base zero da cadeia de caracteres a ser selecionada. Se *nSelecionar* for-1, a caixa de listagem será definida como sem seleção.

### <a name="return-value"></a>Valor de retorno

LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Quando a nova cadeia de caracteres é selecionada, a caixa de listagem remove o realce da cadeia de caracteres selecionada anteriormente.

Use essa função de membro somente com caixas de listagem de seleção única.

Para definir ou remover uma seleção em uma caixa de listagem de seleção múltipla, use [CListBox:: SetSel](#setsel).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#32](../../mfc/codesnippet/cpp/clistbox-class_32.cpp)]

##  <a name="sethorizontalextent"></a>CListBox::SetHorizontalExtent

Define a largura, em pixels, pela qual uma caixa de listagem pode ser rolada horizontalmente.

```
void SetHorizontalExtent(int cxExtent);
```

### <a name="parameters"></a>Parâmetros

*cxExtent*<br/>
Especifica o número de pixels pelos quais a caixa de listagem pode ser rolada horizontalmente.

### <a name="remarks"></a>Comentários

Se o tamanho da caixa de listagem for menor que esse valor, a barra de rolagem horizontal irá rolar os itens horizontalmente na caixa de listagem. Se a caixa de listagem for tão grande ou maior que esse valor, a barra de rolagem horizontal ficará oculta.

Para responder a uma chamada para `SetHorizontalExtent`, a caixa de listagem deve ter sido definida com o estilo de [WS_HSCROLL](../../mfc/reference/styles-used-by-mfc.md#window-styles) .

Essa função de membro não é útil para caixas de listagem de várias colunas. Para caixas de listagem de várias colunas, chame a função membro `SetColumnWidth`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#33](../../mfc/codesnippet/cpp/clistbox-class_33.cpp)]

##  <a name="setitemdata"></a>  CListBox::SetItemData

Define um valor associado ao item especificado em uma caixa de listagem.

```
int SetItemData(
    int nIndex,
    DWORD_PTR dwItemData);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item.

*dwItemData*<br/>
Especifica o valor a ser associado ao item.

### <a name="return-value"></a>Valor de retorno

LB_ERR se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#34](../../mfc/codesnippet/cpp/clistbox-class_34.cpp)]

##  <a name="setitemdataptr"></a>  CListBox::SetItemDataPtr

Define o valor de 32 bits associado ao item especificado em uma caixa de listagem para ser o ponteiro especificado ( **void** <strong>\*</strong>).

```
int SetItemDataPtr(
    int nIndex,
    void* pData);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item.

*pData*<br/>
Especifica o ponteiro a ser associado ao item.

### <a name="return-value"></a>Valor de retorno

LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Esse ponteiro permanece válido durante a vida útil da caixa de listagem, mesmo que a posição relativa do item dentro da caixa de listagem possa ser alterada à medida que os itens são adicionados ou removidos. Portanto, o índice do item dentro da caixa pode ser alterado, mas o ponteiro permanece confiável.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#35](../../mfc/codesnippet/cpp/clistbox-class_35.cpp)]

##  <a name="setitemheight"></a>  CListBox::SetItemHeight

Define a altura dos itens em uma caixa de listagem.

```
int SetItemHeight(
    int nIndex,
    UINT cyItemHeight);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item na caixa de listagem. Esse parâmetro será usado somente se a caixa de listagem tiver o estilo de LBS_OWNERDRAWVARIABLE; caso contrário, ele deve ser definido como 0.

*cyItemHeight*<br/>
Especifica a altura, em pixels, do item.

### <a name="return-value"></a>Valor de retorno

LB_ERR se o índice ou a altura for inválido.

### <a name="remarks"></a>Comentários

Se a caixa de listagem tiver o estilo de [LBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) , essa função definirá a altura do item especificado por *nIndex*. Caso contrário, essa função define a altura de todos os itens na caixa de listagem.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#36](../../mfc/codesnippet/cpp/clistbox-class_36.cpp)]

##  <a name="setlocale"></a>  CListBox::SetLocale

Define o identificador de localidade para esta caixa de listagem.

```
LCID SetLocale(LCID nNewLocale);
```

### <a name="parameters"></a>Parâmetros

*nNewLocale*<br/>
O novo valor de LCID (identificador de localidade) a ser definido para a caixa de listagem.

### <a name="return-value"></a>Valor de retorno

O valor do LCID (identificador de localidade) anterior desta caixa de listagem.

### <a name="remarks"></a>Comentários

Se `SetLocale` não for chamado, a localidade padrão será obtida do sistema. Essa localidade padrão do sistema pode ser modificada usando o aplicativo regional (ou internacional) do painel de controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#37](../../mfc/codesnippet/cpp/clistbox-class_37.cpp)]

##  <a name="setsel"></a>  CListBox::SetSel

Seleciona uma cadeia de caracteres em uma caixa de listagem de seleção múltipla.

```
int SetSel(
    int nIndex,
    BOOL bSelect = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice de base zero da cadeia de caracteres a ser definida. Se-1, a seleção é adicionada ou removida de todas as cadeias de caracteres, dependendo do valor de *bSelect*.

*bSelect*<br/>
Especifica como definir a seleção. Se *bSelect* for true, a cadeia de caracteres será selecionada e realçada; Se for FALSE, o realce será removido e a cadeia de caracteres não será mais selecionada. A cadeia de caracteres especificada é selecionada e realçada por padrão.

### <a name="return-value"></a>Valor de retorno

LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Use essa função de membro somente com caixas de listagem de seleção múltipla.

Para selecionar um item de uma caixa de listagem de seleção única, use [CListBox:: Setcurseal](#setcursel).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#38](../../mfc/codesnippet/cpp/clistbox-class_38.cpp)]

##  <a name="settabstops"></a>  CListBox::SetTabStops

Define as posições de parada de tabulação em uma caixa de listagem.

```
void SetTabStops();
BOOL SetTabStops(const int& cxEachStop);

BOOL SetTabStops(
    int nTabStops,
    LPINT rgTabStops);
```

### <a name="parameters"></a>Parâmetros

*cxEachStop*<br/>
As marcas de tabulação são definidas em todas as unidades de diálogo *cxEachStop* . Consulte *rgTabStops* para obter uma descrição de uma unidade de diálogo.

*nTabStops*<br/>
Especifica o número de paradas de tabulação a serem feitas na caixa de listagem.

*rgTabStops*<br/>
Aponta para o primeiro membro de uma matriz de inteiros contendo as posições de parada de tabulação em unidades de diálogo. Uma unidade de caixa de diálogo é uma distância horizontal ou vertical. Uma unidade de caixa de diálogo horizontal é igual a um quarto da unidade de largura base da caixa de diálogo atual e uma unidade de caixa de diálogo vertical é igual a um oitavo da unidade de altura base da caixa de diálogo atual. As unidades base da caixa de diálogo são computadas com base na altura e na largura da fonte atual do sistema. A função `GetDialogBaseUnits` do Windows retorna as unidades base da caixa de diálogo atual em pixels. As paradas de tabulação devem ser classificadas em ordem crescente; Não são permitidas guias de trás.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se todas as guias tiverem sido definidas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para definir paradas de tabulação com o tamanho padrão de 2 unidades de caixa de diálogo, chame a versão sem parâmetros dessa função de membro. Para definir paradas de tabulação com um tamanho diferente de 2, chame a versão com o argumento *cxEachStop* .

Para definir paradas de tabulação para uma matriz de tamanhos, use a versão com os argumentos *rgTabStops* e *nTabStops* . Uma parada de tabulação será definida para cada valor em *rgTabStops*, até o número especificado por *nTabStops*.

Para responder a uma chamada para a função de membro `SetTabStops`, a caixa de listagem deve ter sido criada com o estilo de [LBS_USETABSTOPS](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#39](../../mfc/codesnippet/cpp/clistbox-class_39.cpp)]

##  <a name="settopindex"></a>  CListBox::SetTopIndex

Garante que um item de caixa de listagem específico esteja visível.

```
int SetTopIndex(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item da caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

O sistema rola a caixa de listagem até que o item especificado por *nIndex* seja exibido na parte superior da caixa de listagem ou o intervalo máximo de rolagem tenha sido atingido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#40](../../mfc/codesnippet/cpp/clistbox-class_40.cpp)]

##  <a name="vkeytoitem"></a>  CListBox::VKeyToItem

Chamado pelo Framework quando a janela pai da caixa de listagem recebe uma mensagem de WM_VKEYTOITEM da caixa de listagem.

```
virtual int VKeyToItem(
    UINT nKey,
    UINT nIndex);
```

### <a name="parameters"></a>Parâmetros

*nKey*<br/>
O código de chave virtual da chave que o usuário pressionou. Para obter uma lista de códigos de chaves virtuais padrão, consulte WinUser. h

*nIndex*<br/>
A posição atual do cursor da caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Retorna-2 para nenhuma ação adicional,-1 para a ação padrão ou um número não negativo para especificar um índice de um item da caixa de listagem no qual executar a ação padrão para o pressionamento de tecla.

### <a name="remarks"></a>Comentários

A mensagem de WM_VKEYTOITEM é enviada pela caixa de listagem quando recebe uma mensagem de WM_KEYDOWN, mas somente se a caixa de listagem atender aos dois itens a seguir:

- Tem o estilo de [LBS_WANTKEYBOARDINPUT](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) definido.

- Tem pelo menos um item.

Você mesmo nunca deve chamar essa função. Substitua essa função para fornecer sua própria manipulação personalizada de mensagens de teclado.

Você deve retornar um valor para informar ao Framework qual ação sua substituição executou. Um valor de retorno de-2 indica que o aplicativo tratou todos os aspectos da seleção do item e não requer nenhuma ação adicional na caixa de listagem. Antes de retornar-2, você pode definir a seleção ou mover o cursor ou ambos. Para definir a seleção, use [Setcurseal](#setcursel) ou [SetSel](#setsel). Para mover o cursor, use [SetCaretIndex](#setcaretindex).

Um valor de retorno de-1 indica que a caixa de listagem deve executar a ação padrão em resposta ao pressionamento de tecla. A implementação padrão retorna-1.

Um valor de retorno 0 ou maior especifica o índice de um item na caixa de listagem e indica que a caixa de listagem deve executar a ação padrão para o pressionamento de tecla no item determinado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#41](../../mfc/codesnippet/cpp/clistbox-class_41.cpp)]

## <a name="see-also"></a>Veja também

[Exemplo de CTRLTEST do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)<br/>
[Classe CStatic](../../mfc/reference/cstatic-class.md)
