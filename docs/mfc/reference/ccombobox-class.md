---
title: Classe CComboBox
ms.date: 11/04/2016
f1_keywords:
- CComboBox
- AFXWIN/CComboBox
- AFXWIN/CComboBox::CComboBox
- AFXWIN/CComboBox::AddString
- AFXWIN/CComboBox::Clear
- AFXWIN/CComboBox::CompareItem
- AFXWIN/CComboBox::Copy
- AFXWIN/CComboBox::Create
- AFXWIN/CComboBox::Cut
- AFXWIN/CComboBox::DeleteItem
- AFXWIN/CComboBox::DeleteString
- AFXWIN/CComboBox::Dir
- AFXWIN/CComboBox::DrawItem
- AFXWIN/CComboBox::FindString
- AFXWIN/CComboBox::FindStringExact
- AFXWIN/CComboBox::GetComboBoxInfo
- AFXWIN/CComboBox::GetCount
- AFXWIN/CComboBox::GetCueBanner
- AFXWIN/CComboBox::GetCurSel
- AFXWIN/CComboBox::GetDroppedControlRect
- AFXWIN/CComboBox::GetDroppedState
- AFXWIN/CComboBox::GetDroppedWidth
- AFXWIN/CComboBox::GetEditSel
- AFXWIN/CComboBox::GetExtendedUI
- AFXWIN/CComboBox::GetHorizontalExtent
- AFXWIN/CComboBox::GetItemData
- AFXWIN/CComboBox::GetItemDataPtr
- AFXWIN/CComboBox::GetItemHeight
- AFXWIN/CComboBox::GetLBText
- AFXWIN/CComboBox::GetLBTextLen
- AFXWIN/CComboBox::GetLocale
- AFXWIN/CComboBox::GetMinVisible
- AFXWIN/CComboBox::GetTopIndex
- AFXWIN/CComboBox::InitStorage
- AFXWIN/CComboBox::InsertString
- AFXWIN/CComboBox::LimitText
- AFXWIN/CComboBox::MeasureItem
- AFXWIN/CComboBox::Paste
- AFXWIN/CComboBox::ResetContent
- AFXWIN/CComboBox::SelectString
- AFXWIN/CComboBox::SetCueBanner
- AFXWIN/CComboBox::SetCurSel
- AFXWIN/CComboBox::SetDroppedWidth
- AFXWIN/CComboBox::SetEditSel
- AFXWIN/CComboBox::SetExtendedUI
- AFXWIN/CComboBox::SetHorizontalExtent
- AFXWIN/CComboBox::SetItemData
- AFXWIN/CComboBox::SetItemDataPtr
- AFXWIN/CComboBox::SetItemHeight
- AFXWIN/CComboBox::SetLocale
- AFXWIN/CComboBox::SetMinVisibleItems
- AFXWIN/CComboBox::SetTopIndex
- AFXWIN/CComboBox::ShowDropDown
helpviewer_keywords:
- CComboBox [MFC], CComboBox
- CComboBox [MFC], AddString
- CComboBox [MFC], Clear
- CComboBox [MFC], CompareItem
- CComboBox [MFC], Copy
- CComboBox [MFC], Create
- CComboBox [MFC], Cut
- CComboBox [MFC], DeleteItem
- CComboBox [MFC], DeleteString
- CComboBox [MFC], Dir
- CComboBox [MFC], DrawItem
- CComboBox [MFC], FindString
- CComboBox [MFC], FindStringExact
- CComboBox [MFC], GetComboBoxInfo
- CComboBox [MFC], GetCount
- CComboBox [MFC], GetCueBanner
- CComboBox [MFC], GetCurSel
- CComboBox [MFC], GetDroppedControlRect
- CComboBox [MFC], GetDroppedState
- CComboBox [MFC], GetDroppedWidth
- CComboBox [MFC], GetEditSel
- CComboBox [MFC], GetExtendedUI
- CComboBox [MFC], GetHorizontalExtent
- CComboBox [MFC], GetItemData
- CComboBox [MFC], GetItemDataPtr
- CComboBox [MFC], GetItemHeight
- CComboBox [MFC], GetLBText
- CComboBox [MFC], GetLBTextLen
- CComboBox [MFC], GetLocale
- CComboBox [MFC], GetMinVisible
- CComboBox [MFC], GetTopIndex
- CComboBox [MFC], InitStorage
- CComboBox [MFC], InsertString
- CComboBox [MFC], LimitText
- CComboBox [MFC], MeasureItem
- CComboBox [MFC], Paste
- CComboBox [MFC], ResetContent
- CComboBox [MFC], SelectString
- CComboBox [MFC], SetCueBanner
- CComboBox [MFC], SetCurSel
- CComboBox [MFC], SetDroppedWidth
- CComboBox [MFC], SetEditSel
- CComboBox [MFC], SetExtendedUI
- CComboBox [MFC], SetHorizontalExtent
- CComboBox [MFC], SetItemData
- CComboBox [MFC], SetItemDataPtr
- CComboBox [MFC], SetItemHeight
- CComboBox [MFC], SetLocale
- CComboBox [MFC], SetMinVisibleItems
- CComboBox [MFC], SetTopIndex
- CComboBox [MFC], ShowDropDown
ms.assetid: 4e73b5df-0d2e-4658-9706-38133fb10513
ms.openlocfilehash: b54a1913073ca0b23aeb17a57b16f589a074637b
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418814"
---
# <a name="ccombobox-class"></a>Classe CComboBox

Fornece a funcionalidade de uma caixa de combinação do Windows.

## <a name="syntax"></a>Sintaxe

```
class CComboBox : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CComboBox::CComboBox](#ccombobox)|Constrói um objeto `CComboBox`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CComboBox:: AddString](#addstring)|Adiciona uma cadeia de caracteres ao final da lista na caixa de listagem de uma caixa de combinação ou na posição classificada para caixas de listagem com o estilo de CBS_SORT.|
|[CComboBox:: Clear](#clear)|Exclui (limpa) a seleção atual, se houver, no controle de edição.|
|[CComboBox::CompareItem](#compareitem)|Chamado pelo Framework para determinar a posição relativa de um novo item de lista em uma caixa de combinação de desenho de proprietário classificada.|
|[CComboBox:: copiar](#copy)|Copia a seleção atual, se houver, para a área de transferência no formato CF_TEXT.|
|[CComboBox:: criar](#create)|Cria a caixa de combinação e a anexa ao objeto `CComboBox`.|
|[CComboBox:: recortar](#cut)|Exclui (recorta) a seleção atual, se houver, no controle de edição e copia o texto excluído para a área de transferência no formato CF_TEXT.|
|[CComboBox::D eleteItem](#deleteitem)|Chamado pelo Framework quando um item de lista é excluído de uma caixa de combinação desenhada pelo proprietário.|
|[CComboBox::D eleteString](#deletestring)|Exclui uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.|
|[CComboBox::D ir](#dir)|Adiciona uma lista de nomes de arquivo à caixa de listagem de uma caixa de combinação.|
|[CComboBox::D rawItem](#drawitem)|Chamado pelo Framework quando um aspecto visual de uma caixa de combinação desenhada pelo proprietário é alterado.|
|[CComboBox:: FindString](#findstring)|Localiza a primeira cadeia de caracteres que contém o prefixo especificado na caixa de listagem de uma caixa de combinação.|
|[CComboBox::FindStringExact](#findstringexact)|Localiza a primeira cadeia de caracteres da caixa de listagem (em uma caixa de combinação) que corresponde à cadeia de caracteres especificada.|
|[CComboBox::GetComboBoxInfo](#getcomboboxinfo)|Recupera informações sobre o objeto `CComboBox`.|
|[CComboBox:: GetCount](#getcount)|Recupera o número de itens na caixa de listagem de uma caixa de combinação.|
|[CComboBox::GetCueBanner](#getcuebanner)|Obtém o texto de indicação que é exibido para um controle de caixa de combinação.|
|[CComboBox:: GetCurSel](#getcursel)|Recupera o índice do item atualmente selecionado, se houver, na caixa de listagem de uma caixa de combinação.|
|[CComboBox::GetDroppedControlRect](#getdroppedcontrolrect)|Recupera as coordenadas de tela da caixa de listagem visível (descartada) de uma caixa de combinação suspensa.|
|[CComboBox:: getremovestate](#getdroppedstate)|Determina se a caixa de listagem de uma caixa de combinação suspensa está visível (descartada).|
|[CComboBox::GetDroppedWidth](#getdroppedwidth)|Recupera a largura mínima permitida para a parte da caixa de listagem suspensa de uma caixa de combinação.|
|[CComboBox::GetEditSel](#geteditsel)|Obtém as posições de caractere inicial e final da seleção atual no controle de edição de uma caixa de combinação.|
|[CComboBox::GetExtendedUI](#getextendedui)|Determina se uma caixa de combinação tem a interface do usuário padrão ou a interface do usuário estendida.|
|[CComboBox::GetHorizontalExtent](#gethorizontalextent)|Retorna a largura em pixels na qual a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.|
|[CComboBox::GetItemData](#getitemdata)|Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item da caixa de combinação especificado.|
|[CComboBox::GetItemDataPtr](#getitemdataptr)|Recupera o ponteiro de 32 bits fornecido pelo aplicativo que está associado ao item da caixa de combinação especificado.|
|[CComboBox:: GetItemHeight](#getitemheight)|Recupera a altura dos itens de lista em uma caixa de combinação.|
|[CComboBox::GetLBText](#getlbtext)|Obtém uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.|
|[CComboBox::GetLBTextLen](#getlbtextlen)|Obtém o comprimento de uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|
|[CComboBox:: getlocale](#getlocale)|Recupera o identificador de localidade de uma caixa de combinação.|
|[CComboBox::GetMinVisible](#getminvisible)|Obtém o número mínimo de itens visíveis na lista suspensa da caixa de combinação atual.|
|[CComboBox::GetTopIndex](#gettopindex)|Retorna o índice do primeiro item visível na parte de caixa de listagem da caixa de combinação.|
|[CComboBox::InitStorage](#initstorage)|Prefixa blocos de memória para itens e cadeias de caracteres na parte da caixa de listagem da caixa de combinação.|
|[CComboBox:: InsertString](#insertstring)|Insere uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|
|[CComboBox::LimitText](#limittext)|Limita o comprimento do texto que o usuário pode inserir no controle de edição de uma caixa de combinação.|
|[CComboBox::MeasureItem](#measureitem)|Chamado pelo Framework para determinar as dimensões da caixa de combinação quando uma caixa de combinação de desenho proprietário é criada.|
|[CComboBox::P lar](#paste)|Insere os dados da área de transferência no controle de edição na posição atual do cursor. Os dados só serão inseridos se a área de transferência contiver dados no formato CF_TEXT.|
|[CComboBox::ResetContent](#resetcontent)|Remove todos os itens da caixa de listagem e edita o controle de uma caixa de combinação.|
|[CComboBox:: SelectString](#selectstring)|Procura uma cadeia de caracteres na caixa de listagem de uma caixa de combinação e, se a cadeia de caracteres for encontrada, seleciona a cadeia de caracteres na caixa de listagem e copia a cadeia de caracteres para o controle de edição.|
|[CComboBox::SetCueBanner](#setcuebanner)|Define o texto de indicação que é exibido para um controle de caixa de combinação.|
|[CComboBox:: setcurseal](#setcursel)|Seleciona uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|
|[CComboBox::SetDroppedWidth](#setdroppedwidth)|Define a largura mínima permitida para a parte da caixa de listagem suspensa de uma caixa de combinação.|
|[CComboBox::SetEditSel](#seteditsel)|Seleciona caracteres no controle de edição de uma caixa de combinação.|
|[CComboBox::SetExtendedUI](#setextendedui)|Seleciona a interface do usuário padrão ou a interface do usuário estendida para uma caixa de combinação que tem o estilo de CBS_DROPDOWN ou CBS_DROPDOWNLIST.|
|[CComboBox::SetHorizontalExtent](#sethorizontalextent)|Define a largura em pixels na qual a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.|
|[CComboBox::SetItemData](#setitemdata)|Define o valor de 32 bits associado ao item especificado em uma caixa de combinação.|
|[CComboBox::SetItemDataPtr](#setitemdataptr)|Define o ponteiro de 32 bits associado ao item especificado em uma caixa de combinação.|
|[CComboBox::SetItemHeight](#setitemheight)|Define a altura dos itens de lista em uma caixa de combinação ou a altura da parte do controle de edição (ou texto estático) de uma caixa de combinação.|
|[CComboBox:: setlocale](#setlocale)|Define o identificador de localidade para uma caixa de combinação.|
|[CComboBox::SetMinVisibleItems](#setminvisibleitems)|Define o número mínimo de itens visíveis na lista suspensa da caixa de combinação atual.|
|[CComboBox::SetTopIndex](#settopindex)|Informa a parte da caixa de listagem da caixa de combinação para exibir o item com o índice especificado na parte superior.|
|[CComboBox:: lista suspensa](#showdropdown)|Mostra ou oculta a caixa de listagem de uma caixa de combinação que tem o CBS_DROPDOWN ou o estilo de CBS_DROPDOWNLIST.|

## <a name="remarks"></a>Comentários

Uma caixa de combinação consiste em uma caixa de listagem combinada com um controle estático ou o controle de edição. A parte da caixa de listagem do controle pode ser exibida sempre ou pode ser suspensa apenas quando o usuário seleciona a seta suspensa ao lado do controle.

O item selecionado no momento (se houver) na caixa de listagem é exibido no controle estático ou de edição. Além disso, se a caixa de combinação tiver o estilo de lista suspensa, o usuário poderá digitar o caractere inicial de um dos itens na lista e a caixa de listagem, se visível, realçará o próximo item com esse caractere inicial.

A tabela a seguir compara os três [estilos](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles)de caixa de combinação.

|Estilo|Quando a caixa de listagem está visível|Controle estático ou de edição|
|-----------|-------------------------------|-----------------------------|
|Simples|Sempre|Editar|
|Lista suspensa|Quando solto|Editar|
|Lista suspensa|Quando solto|Estático|

Você pode criar um objeto de `CComboBox` de um modelo de caixa de diálogo ou diretamente em seu código. Em ambos os casos, primeiro chame o Construtor `CComboBox` para construir o objeto `CComboBox`; em seguida, chame a função [criar](#create) membro para criar o controle e anexá-lo ao objeto `CComboBox`.

Se você quiser manipular mensagens de notificação do Windows enviadas por uma caixa de combinação para seu pai (geralmente uma classe derivada de `CDialog`), adicione uma entrada de mapa de mensagem e uma função de membro de manipulador de mensagens à classe pai para cada mensagem.

Cada entrada de mapa de mensagem usa o seguinte formato:

**Na notificação de\_** **(** _ID_, _memberFxn_ **)**

em que `id` especifica a ID da janela filho do controle da caixa de combinação que envia a notificação e `memberFxn` é o nome da função de membro pai que você escreveu para manipular a notificação.

O protótipo de função do pai é o seguinte:

**afx_msg** `void` `memberFxn` **();**

A ordem na qual determinadas notificações serão enviadas não pode ser prevista. Em particular, uma notificação CBN_SELCHANGE pode ocorrer antes ou depois de uma notificação de CBN_CLOSEUP.

As entradas de mapa de mensagens em potencial são as seguintes:

- ON_CBN_CLOSEUP (Windows 3,1 e posterior.) A caixa de listagem de uma caixa de combinação foi fechada. Essa mensagem de notificação não é enviada para uma caixa de combinação que tem o estilo de [CBS_SIMPLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) .

- ON_CBN_DBLCLK o usuário clica duas vezes em uma cadeia de caracteres na caixa de listagem de uma caixa de combinação. Esta mensagem de notificação é enviada somente para uma caixa de combinação com o estilo de CBS_SIMPLE. Para uma caixa de combinação com o estilo de [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) , um clique duplo não pode ocorrer porque um único clique oculta a caixa de listagem.

- ON_CBN_DROPDOWN caixa de listagem de uma caixa de combinação está prestes a ser suspensa (se tornar visível). Essa mensagem de notificação pode ocorrer somente para uma caixa de combinação com o CBS_DROPDOWN ou o estilo de CBS_DROPDOWNLIST.

- ON_CBN_EDITCHANGE o usuário executou uma ação que pode ter alterado o texto na parte de controle de edição de uma caixa de combinação. Ao contrário da mensagem de CBN_EDITUPDATE, essa mensagem é enviada depois que o Windows atualiza a tela. Ele não será enviado se a caixa de combinação tiver o estilo de CBS_DROPDOWNLIST.

- ON_CBN_EDITUPDATE a parte de controle de edição de uma caixa de combinação está prestes a exibir o texto alterado. Essa mensagem de notificação é enviada depois que o controle tiver formatado o texto, mas antes de exibir o texto. Ele não será enviado se a caixa de combinação tiver o estilo de CBS_DROPDOWNLIST.

- ON_CBN_ERRSPACE a caixa de combinação não pode alocar memória suficiente para atender a uma solicitação específica.

- ON_CBN_SELENDCANCEL (Windows 3,1 e posterior.) Indica que a seleção do usuário deve ser cancelada. O usuário clica em um item e clica em outra janela ou controle para ocultar a caixa de listagem de uma caixa de combinação. Essa mensagem de notificação é enviada antes da CBN_CLOSEUP mensagem de notificação para indicar que a seleção do usuário deve ser ignorada. A CBN_SELENDCANCEL ou CBN_SELENDOK mensagem de notificação é enviada mesmo que a CBN_CLOSEUP mensagem de notificação não seja enviada (como no caso de uma caixa de combinação com o estilo CBS_SIMPLE).

- ON_CBN_SELENDOK o usuário seleciona um item e pressiona a tecla ENTER ou clica na tecla de seta para baixo para ocultar a caixa de listagem de uma caixa de combinação. Essa mensagem de notificação é enviada antes da CBN_CLOSEUP mensagem para indicar que a seleção do usuário deve ser considerada válida. A CBN_SELENDCANCEL ou CBN_SELENDOK mensagem de notificação é enviada mesmo que a CBN_CLOSEUP mensagem de notificação não seja enviada (como no caso de uma caixa de combinação com o estilo CBS_SIMPLE).

- ON_CBN_KILLFOCUS a caixa de combinação está perdendo o foco de entrada.

- ON_CBN_SELCHANGE a seleção na caixa de listagem de uma caixa de combinação está prestes a ser alterada como resultado do usuário clicando na caixa de listagem ou alterando a seleção usando as teclas de direção. Ao processar essa mensagem, o texto no controle de edição da caixa de combinação só pode ser recuperado por meio de `GetLBText` ou outra função semelhante. `GetWindowText` não pode ser usado.

- ON_CBN_SETFOCUS a caixa de combinação recebe o foco de entrada.

Se você criar um objeto `CComboBox` dentro de uma caixa de diálogo (por meio de um recurso de caixa de diálogo), o objeto `CComboBox` será destruído automaticamente quando o usuário fechar a caixa de diálogo.

Se você inserir um objeto de `CComboBox` dentro de outro objeto de janela, não será necessário destruí-lo. Se você criar o objeto `CComboBox` na pilha, ele será destruído automaticamente. Se você criar o objeto `CComboBox` no heap usando a **nova** função, deverá chamar **delete** no objeto para destruí-lo quando a caixa de combinação do Windows for destruída.

**Observação** Se você quiser manipular WM_KEYDOWN e WM_CHAR mensagens, terá que subclassear os controles de edição e caixa de listagem da caixa de combinação, derivar classes de `CEdit` e `CListBox`e adicionar manipuladores para essas mensagens às classes derivadas. Para obter mais informações, consulte [CWnd:: SubclassWindow](../../mfc/reference/cwnd-class.md#subclasswindow).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CComboBox`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="addstring"></a>CComboBox:: AddString

Adiciona uma cadeia de caracteres à caixa de listagem de uma caixa de combinação.

```
int AddString(LPCTSTR lpszString);
```

### <a name="parameters"></a>parâmetros

*lpszString*<br/>
Aponta para a cadeia de caracteres terminada em nulo que deve ser adicionada.

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for maior ou igual a 0, ele será o índice de base zero para a cadeia de caracteres na caixa de listagem. O valor de retorno será CB_ERR se ocorrer um erro; o valor de retorno será CB_ERRSPACE se houver espaço insuficiente disponível para armazenar a nova cadeia de caracteres.

### <a name="remarks"></a>Comentários

Se a caixa de listagem não foi criada com o estilo de [CBS_SORT](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) , a cadeia de caracteres será adicionada ao final da lista. Caso contrário, a cadeia de caracteres será inserida na lista e a lista será classificada.

> [!NOTE]
>  Não há suporte para essa função pelo controle de `ComboBoxEx` do Windows. Para obter mais informações sobre esse controle, consulte [ComboBoxEx Controls](/windows/win32/Controls/comboboxex-controls) in the SDK do Windows.

Para inserir uma cadeia de caracteres em um local específico dentro da lista, use a função de membro [InsertString](#insertstring) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#3](../../mfc/reference/codesnippet/cpp/ccombobox-class_1.cpp)]

##  <a name="ccombobox"></a>CComboBox::CComboBox

Constrói um objeto `CComboBox`.

```
CComboBox();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_2.cpp)]

##  <a name="clear"></a>CComboBox:: Clear

Exclui (limpa) a seleção atual, se houver, no controle de edição da caixa de combinação.

```
void Clear();
```

### <a name="remarks"></a>Comentários

Para excluir a seleção atual e inserir o conteúdo excluído na área de transferência, use a função de membro [Cut](#cut) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#4](../../mfc/reference/codesnippet/cpp/ccombobox-class_3.cpp)]

##  <a name="compareitem"></a>CComboBox::CompareItem

Chamado pelo Framework para determinar a posição relativa de um novo item na parte da caixa de listagem de uma caixa de combinação de desenho proprietário classificada.

```
virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
```

### <a name="parameters"></a>parâmetros

*lpCompareItemStruct*<br/>
Um ponteiro longo para uma estrutura [COMPAREITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-compareitemstruct) .

### <a name="return-value"></a>Valor retornado

Indica a posição relativa dos dois itens descritos na estrutura de `COMPAREITEMSTRUCT`. Pode ser qualquer um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|- 1|Item 1 classifica antes do item 2.|
|0|O item 1 e o item 2 são classificados da mesma forma.|
|1|O item 1 é classificado após o item 2.|

Consulte [CWnd:: OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem) para obter uma descrição de `COMPAREITEMSTRUCT`.

### <a name="remarks"></a>Comentários

Por padrão, essa função de membro não faz nada. Se você criar uma caixa de combinação de desenho proprietário com o estilo de LBS_SORT, deverá substituir essa função de membro para ajudar a estrutura na classificação de novos itens adicionados à caixa de listagem.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#5](../../mfc/reference/codesnippet/cpp/ccombobox-class_4.cpp)]

##  <a name="copy"></a>CComboBox:: copiar

Copia a seleção atual, se houver, no controle de edição da caixa de combinação para a área de transferência no formato CF_TEXT.

```
void Copy();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#6](../../mfc/reference/codesnippet/cpp/ccombobox-class_5.cpp)]

##  <a name="create"></a>CComboBox:: criar

Cria a caixa de combinação e a anexa ao objeto `CComboBox`.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>parâmetros

*dwStyle*<br/>
Especifica o estilo da caixa de combinação. Aplique qualquer combinação de [estilos de caixa de combinação](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) à caixa.

*Rect*<br/>
Aponta para a posição e o tamanho da caixa de combinação. Pode ser uma [estrutura RECT](/windows/win32/api/windef/ns-windef-rect) ou um objeto `CRect`.

*pParentWnd*<br/>
Especifica a janela pai da caixa de combinação (geralmente um `CDialog`). Ele não deve ser nulo.

*nID*<br/>
Especifica a ID de controle da caixa de combinação.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um objeto `CComboBox` em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria a caixa de combinação do Windows e a anexa ao objeto `CComboBox`.

Quando `Create` é executado, o Windows envia as mensagens [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize)e [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) para a caixa de combinação.

Essas mensagens são tratadas por padrão pelas funções de membro [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate), [OnCreate](../../mfc/reference/cwnd-class.md#oncreate), [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize)e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) na classe base `CWnd`. Para estender a manipulação de mensagens padrão, derive uma classe de `CComboBox`, adicione um mapa de mensagem à nova classe e substitua as funções de membro do manipulador de mensagens anterior. Substitua `OnCreate`, por exemplo, para executar a inicialização necessária para uma nova classe.

Aplique os seguintes [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de caixa de combinação. :

- WS_CHILD sempre

- Geralmente WS_VISIBLE

- WS_DISABLED raramente

- WS_VSCROLL para adicionar a rolagem vertical da caixa de listagem na caixa de combinação

- WS_HSCROLL adicionar rolagem horizontal para a caixa de listagem na caixa de combinação

- WS_GROUP a controles de grupo

- WS_TABSTOP incluir a caixa de combinação na ordem de tabulação

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_6.cpp)]

##  <a name="cut"></a>CComboBox:: recortar

Exclui (recorta) a seleção atual, se houver, no controle de edição de caixa de combinação e copia o texto excluído para a área de transferência no formato CF_TEXT.

```
void Cut();
```

### <a name="remarks"></a>Comentários

Para excluir a seleção atual sem colocar o texto excluído na área de transferência, chame a função de membro [Clear](#clear) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#7](../../mfc/reference/codesnippet/cpp/ccombobox-class_7.cpp)]

##  <a name="deleteitem"></a>CComboBox::D eleteItem

Chamado pelo Framework quando o usuário exclui um item de um objeto `CComboBox` de desenho proprietário ou destrói a caixa de combinação.

```
virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
```

### <a name="parameters"></a>parâmetros

*lpDeleteItemStruct*<br/>
Um ponteiro longo para uma estrutura [DELETEITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-deleteitemstruct) do Windows que contém informações sobre o item excluído. Consulte [CWnd:: OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem) para obter uma descrição dessa estrutura.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada. Substitua essa função para redesenhar a caixa de combinação conforme necessário.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#8](../../mfc/reference/codesnippet/cpp/ccombobox-class_8.cpp)]

##  <a name="deletestring"></a>CComboBox::D eleteString

Exclui o item na posição *nIndex* da caixa de combinação.

```
int DeleteString(UINT nIndex);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Especifica o índice para a cadeia de caracteres a ser excluída.

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for maior ou igual a 0, será uma contagem das cadeias de caracteres restantes na lista. O valor de retorno será CB_ERR se *nIndex* especificar um índice maior que o número de itens na lista.

### <a name="remarks"></a>Comentários

Todos os itens após *nIndex* agora se movem uma posição para baixo. Por exemplo, se uma caixa de combinação contiver dois itens, a exclusão do primeiro item fará com que o item restante esteja agora na primeira posição. *nIndex*= 0 para o item na primeira posição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#9](../../mfc/reference/codesnippet/cpp/ccombobox-class_9.cpp)]

##  <a name="dir"></a>CComboBox::D ir

Adiciona uma lista de nomes de filedrives ou unidades à caixa de listagem de uma caixa de combinação.

```
int Dir(
    UINT attr,
    LPCTSTR lpszWildCard);
```

### <a name="parameters"></a>parâmetros

*atributo*<br/>
Pode ser qualquer combinação dos valores de **Enumeração** descritos em [CFile:: GetStatus](../../mfc/reference/cfile-class.md#getstatus) ou qualquer combinação dos seguintes valores:

- DDL_READWRITE arquivo pode ser lido ou gravado.

- DDL_READONLY arquivo pode ser lido, mas não gravado no.

- DDL_HIDDEN Arquivo está oculto e não aparece em uma listagem de diretório.

- DDL_SYSTEM arquivo é um arquivo do sistema.

- DDL_DIRECTORY o nome especificado por *lpszWildCard* especifica um diretório.

- DDL_ARCHIVE arquivo foi arquivado.

- DDL_DRIVES incluir todas as unidades que correspondem ao nome especificado por *lpszWildCard*.

- DDL_EXCLUSIVE sinalizador exclusivo. Se o sinalizador exclusivo for definido, somente os arquivos do tipo especificado serão listados. Caso contrário, os arquivos do tipo especificado serão listados, além dos arquivos "normal".

*lpszWildCard*<br/>
Aponta para uma cadeia de caracteres de especificação de arquivo. A cadeia de caracteres pode conter curingas (por exemplo, *.\*).

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for maior ou igual a 0, ele será o índice de base zero do último nome de arquivo adicionado à lista. O valor de retorno será CB_ERR se ocorrer um erro; o valor de retorno será CB_ERRSPACE se houver espaço insuficiente disponível para armazenar as novas cadeias de caracteres.

### <a name="remarks"></a>Comentários

Não há suporte para essa função pelo controle de `ComboBoxEx` do Windows. Para obter mais informações sobre esse controle, consulte [ComboBoxEx Controls](/windows/win32/Controls/comboboxex-controls) in the SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#10](../../mfc/reference/codesnippet/cpp/ccombobox-class_10.cpp)]

##  <a name="drawitem"></a>CComboBox::D rawItem

Chamado pelo Framework quando um aspecto visual de uma caixa de combinação de desenho proprietário é alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

O membro `itemAction` da estrutura de `DRAWITEMSTRUCT` define a ação de desenho a ser executada. Consulte [CWnd:: OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição dessa estrutura.

Por padrão, essa função de membro não faz nada. Substitua essa função de membro para implementar o desenho de um objeto de `CComboBox` de desenho proprietário. Antes que essa função de membro seja encerrada, o aplicativo deve restaurar todos os objetos de interface de dispositivo de gráficos (GDI) selecionados para o contexto de exibição fornecido em *lpDrawItemStruct*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#11](../../mfc/reference/codesnippet/cpp/ccombobox-class_11.cpp)]

##  <a name="findstring"></a>CComboBox:: FindString

Localiza, mas não seleciona, a primeira cadeia de caracteres que contém o prefixo especificado na caixa de listagem de uma caixa de combinação.

```
int FindString(
    int nStartAfter,
    LPCTSTR lpszString) const;
```

### <a name="parameters"></a>parâmetros

*nStartAfter*<br/>
Contém o índice de base zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa atingir a parte inferior da caixa de listagem, ela continuará na parte superior da caixa de listagem de volta para o item especificado por *nStartAfter*. Se-1, a caixa de listagem inteira será pesquisada desde o início.

*lpszString*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo a ser pesquisado. A pesquisa diferencia maiúsculas de minúsculas, portanto, essa cadeia de caracteres pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for maior ou igual a 0, ele será o índice de base zero do item correspondente. É CB_ERR se a pesquisa não foi bem-sucedida.

### <a name="remarks"></a>Comentários

Não há suporte para essa função pelo controle de `ComboBoxEx` do Windows. Para obter mais informações sobre esse controle, consulte [ComboBoxEx Controls](/windows/win32/Controls/comboboxex-controls) in the SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#12](../../mfc/reference/codesnippet/cpp/ccombobox-class_12.cpp)]

##  <a name="findstringexact"></a>CComboBox::FindStringExact

Chame a função de membro `FindStringExact` para localizar a primeira cadeia de caracteres da caixa de listagem (em uma caixa de combinação) que corresponda à cadeia de caracteres especificada em *lpszFind*.

```
int FindStringExact(
    int nIndexStart,
    LPCTSTR lpszFind) const;
```

### <a name="parameters"></a>parâmetros

*nIndexStart*<br/>
Especifica o índice de base zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa atingir a parte inferior da caixa de listagem, ela continuará na parte superior da caixa de listagem de volta para o item especificado por *nIndexStart*. Se *nIndexStart* for-1, a caixa de listagem inteira será pesquisada desde o início.

*lpszFind*<br/>
Aponta para a cadeia de caracteres terminada em nulo a ser pesquisada. Essa cadeia de caracteres pode conter um nome de arquivo completo, incluindo a extensão. A pesquisa não diferencia maiúsculas de minúsculas, portanto, essa cadeia de caracteres pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor retornado

O índice de base zero do item correspondente ou CB_ERR se a pesquisa não foi bem-sucedida.

### <a name="remarks"></a>Comentários

Se a caixa de combinação tiver sido criada com um estilo de desenho proprietário, mas sem o estilo de [CBS_HASSTRINGS](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) , `FindStringExact` tentará corresponder o valor de doubleword em relação ao valor de *lpszFind*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#13](../../mfc/reference/codesnippet/cpp/ccombobox-class_13.cpp)]

##  <a name="getcomboboxinfo"></a>CComboBox::GetComboBoxInfo

Recupera informações para o objeto `CComboBox`.

```
BOOL GetComboBoxInfo(PCOMBOBOXINFO pcbi) const;
```

### <a name="parameters"></a>parâmetros

*pcbi*<br/>
Um ponteiro para a estrutura [COMBOBOXINFO](/windows/win32/api/winuser/ns-winuser-comboboxinfo) .

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da [CB_GETCOMBOBOXINFO](/windows/win32/Controls/cb-getcomboboxinfo) mensagem, conforme descrito na SDK do Windows.

##  <a name="getcount"></a>CComboBox:: GetCount

Chame essa função de membro para recuperar o número de itens na parte da caixa de listagem de uma caixa de combinação.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens. A contagem retornada é uma maior que o valor de índice do último item (o índice é baseado em zero). É CB_ERR se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#14](../../mfc/reference/codesnippet/cpp/ccombobox-class_14.cpp)]

##  <a name="getcuebanner"></a>CComboBox::GetCueBanner

Obtém o texto de indicação que é exibido para um controle de caixa de combinação.

```
CString GetCueBanner() const;

BOOL GetCueBanner(
    LPTSTR lpszText,
    int cchText) const;
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*lpszText*|fora Ponteiro para um buffer que recebe o texto da faixa de indicação.|
|*cchText*|no Tamanho do buffer ao qual o parâmetro *lpszText* aponta.|

### <a name="return-value"></a>Valor retornado

Na primeira sobrecarga, um objeto [CString](../../atl-mfc-shared/using-cstring.md) que contém o texto da faixa de indicação, se existir; caso contrário, um objeto `CString` que tem comprimento zero.

-ou-

Na segunda sobrecarga, TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O texto de indicação é um prompt que é exibido na área de entrada do controle caixa de combinação. O texto de indicação é exibido até que o usuário forneça a entrada.

Esse método envia a mensagem de [CB_GETCUEBANNER](/windows/win32/Controls/cb-getcuebanner) , que é descrita na SDK do Windows.

##  <a name="getcursel"></a>CComboBox:: GetCurSel

Chame essa função de membro para determinar qual item na caixa de combinação está selecionado.

```
int GetCurSel() const;
```

### <a name="return-value"></a>Valor retornado

O índice de base zero do item selecionado no momento na caixa de listagem de uma caixa de combinação ou CB_ERR se nenhum item for selecionado.

### <a name="remarks"></a>Comentários

`GetCurSel` retorna um índice na lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#15](../../mfc/reference/codesnippet/cpp/ccombobox-class_15.cpp)]

##  <a name="getdroppedcontrolrect"></a>CComboBox::GetDroppedControlRect

Chame a função de membro `GetDroppedControlRect` para recuperar as coordenadas de tela da caixa de listagem visível (descartada) de uma caixa de combinação suspensa.

```
void GetDroppedControlRect(LPRECT lprect) const;
```

### <a name="parameters"></a>parâmetros

*lprect*<br/>
Aponta para a [estrutura RECT](/windows/win32/api/windef/ns-windef-rect) que deve receber as coordenadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#16](../../mfc/reference/codesnippet/cpp/ccombobox-class_16.cpp)]

##  <a name="getdroppedstate"></a>CComboBox:: getremovestate

Chame a função de membro `GetDroppedState` para determinar se a caixa de listagem de uma caixa de combinação suspensa está visível (descartada).

```
BOOL GetDroppedState() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a caixa de listagem estiver visível; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#17](../../mfc/reference/codesnippet/cpp/ccombobox-class_17.cpp)]

##  <a name="getdroppedwidth"></a>CComboBox::GetDroppedWidth

Chame essa função para recuperar a largura mínima permitida, em pixels, da caixa de listagem de uma caixa de combinação.

```
int GetDroppedWidth() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, a largura mínima permitida, em pixels; caso contrário, CB_ERR.

### <a name="remarks"></a>Comentários

Essa função só se aplica a caixas de combinação com o estilo [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) .

Por padrão, a largura mínima permitida da caixa de listagem suspensa é 0. A largura mínima permitida pode ser definida chamando [SetDroppedWidth](#setdroppedwidth). Quando a parte da caixa de listagem da caixa de combinação é exibida, sua largura é maior que a largura mínima permitida ou a largura da caixa de combinação.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [SetDroppedWidth](#setdroppedwidth).

##  <a name="geteditsel"></a>CComboBox::GetEditSel

Obtém as posições de caractere inicial e final da seleção atual no controle de edição de uma caixa de combinação.

```
DWORD GetEditSel() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de 32 bits que contém a posição inicial na palavra de ordem inferior e a posição do primeiro caractere não selecionado após o final da seleção na palavra de ordem superior. Se essa função for usada em uma caixa de combinação sem um controle de edição, CB_ERR será retornada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#18](../../mfc/reference/codesnippet/cpp/ccombobox-class_18.cpp)]

##  <a name="getextendedui"></a>CComboBox::GetExtendedUI

Chame a função de membro `GetExtendedUI` para determinar se uma caixa de combinação tem a interface do usuário padrão ou a interface do usuário estendida.

```
BOOL GetExtendedUI() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a caixa de combinação tiver a interface do usuário estendida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A interface do usuário estendida pode ser identificada das seguintes maneiras:

- Clicar no controle estático exibe a caixa de listagem somente para caixas de combinação com o estilo de [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) .

- Pressionar a tecla de seta para baixo exibe a caixa de listagem (F4 está desabilitado).

A rolagem no controle estático é desabilitada quando a lista de itens não está visível (as teclas de seta estão desabilitadas).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#19](../../mfc/reference/codesnippet/cpp/ccombobox-class_19.cpp)]

##  <a name="gethorizontalextent"></a>CComboBox::GetHorizontalExtent

Recupera da caixa de combinação a largura em pixels pela qual a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.

```
UINT GetHorizontalExtent() const;
```

### <a name="return-value"></a>Valor retornado

A largura rolável da parte da caixa de listagem da caixa de combinação, em pixels.

### <a name="remarks"></a>Comentários

Isso será aplicável somente se a parte da caixa de listagem da caixa de combinação tiver uma barra de rolagem horizontal.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#20](../../mfc/reference/codesnippet/cpp/ccombobox-class_20.cpp)]

##  <a name="getitemdata"></a>CComboBox::GetItemData

Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item da caixa de combinação especificado.

```
DWORD_PTR GetItemData(int nIndex) const;
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Contém o índice de base zero de um item na caixa de listagem da caixa de combinação.

### <a name="return-value"></a>Valor retornado

O valor de 32 bits associado ao item, ou CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

O valor de 32 bits pode ser definido com o parâmetro *dwItemData* de uma chamada de função membro [SetItemData](#setitemdata) . Use a função de membro `GetItemDataPtr` se o valor de 32 bits a ser recuperado for um ponteiro (**void** <strong>\*</strong>).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#21](../../mfc/reference/codesnippet/cpp/ccombobox-class_21.cpp)]

##  <a name="getitemdataptr"></a>CComboBox::GetItemDataPtr

Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item de caixa de combinação especificado como um ponteiro (**void** <strong>\*</strong>).

```
void* GetItemDataPtr(int nIndex) const;
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Contém o índice de base zero de um item na caixa de listagem da caixa de combinação.

### <a name="return-value"></a>Valor retornado

Recupera um ponteiro ou-1 se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#22](../../mfc/reference/codesnippet/cpp/ccombobox-class_22.cpp)]

##  <a name="getitemheight"></a>CComboBox:: GetItemHeight

Chame a função de membro `GetItemHeight` para recuperar a altura dos itens de lista em uma caixa de combinação.

```
int GetItemHeight(int nIndex) const;
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Especifica o componente da caixa de combinação cuja altura deve ser recuperada. Se o parâmetro *nIndex* for-1, a altura da parte de controle de edição (ou texto estático) da caixa de combinação será recuperada. Se a caixa de combinação tiver o estilo de [CBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) , *nIndex* especificará o índice de base zero do item de lista cuja altura deve ser recuperada. Caso contrário, *nIndex* deverá ser definido como 0.

### <a name="return-value"></a>Valor retornado

A altura, em pixels, do item especificado em uma caixa de combinação. O valor de retorno será CB_ERR se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#23](../../mfc/reference/codesnippet/cpp/ccombobox-class_23.cpp)]

##  <a name="getlbtext"></a>CComboBox::GetLBText

Obtém uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.

```
int GetLBText(
    int nIndex,
    LPTSTR lpszText) const;

void GetLBText(
    int nIndex,
    CString& rString) const;
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Contém o índice de base zero da cadeia de caracteres da caixa de listagem a ser copiada.

*lpszText*<br/>
Aponta para um buffer que deve receber a cadeia de caracteres. O buffer deve ter espaço suficiente para a cadeia de caracteres e um caractere nulo de terminação.

*rString*<br/>
Uma referência a um `CString`.

### <a name="return-value"></a>Valor retornado

O comprimento (em bytes) da cadeia de caracteres, excluindo o caractere nulo de terminação. Se *nIndex* não especificar um índice válido, o valor de retorno será CB_ERR.

### <a name="remarks"></a>Comentários

A segunda forma dessa função de membro preenche um objeto `CString` com o texto do item.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#24](../../mfc/reference/codesnippet/cpp/ccombobox-class_24.cpp)]

##  <a name="getlbtextlen"></a>CComboBox::GetLBTextLen

Obtém o comprimento de uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.

```
int GetLBTextLen(int nIndex) const;
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Contém o índice de base zero da cadeia de caracteres da caixa de listagem.

### <a name="return-value"></a>Valor retornado

O comprimento da cadeia de caracteres em bytes, excluindo o caractere nulo de terminação. Se *nIndex* não especificar um índice válido, o valor de retorno será CB_ERR.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CComboBox:: GetLBText](#getlbtext).

##  <a name="getlocale"></a>CComboBox:: getlocale

Recupera a localidade usada pela caixa de combinação.

```
LCID GetLocale() const;
```

### <a name="return-value"></a>Valor retornado

O valor do identificador de localidade (LCID) para as cadeias de caracteres na caixa de combinação.

### <a name="remarks"></a>Comentários

A localidade é usada, por exemplo, para determinar a ordem de classificação das cadeias de caracteres em uma caixa de combinação classificada.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CComboBox:: setlocale](#setlocale).

##  <a name="getminvisible"></a>CComboBox::GetMinVisible

Obtém o número mínimo de itens visíveis na lista suspensa do controle da caixa de combinação atual.

```
int GetMinVisible() const;
```

### <a name="return-value"></a>Valor retornado

O número mínimo de itens visíveis na lista suspensa atual.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [CB_GETMINVISIBLE](/windows/win32/Controls/cb-setminvisible) , que é descrita na SDK do Windows.

##  <a name="gettopindex"></a>CComboBox::GetTopIndex

Recupera o índice de base zero do primeiro item visível na parte da caixa de listagem da caixa de combinação.

```
int GetTopIndex() const;
```

### <a name="return-value"></a>Valor retornado

O índice de base zero do primeiro item visível na parte de caixa de listagem da caixa de combinação, se for bem-sucedido, CB_ERR caso contrário.

### <a name="remarks"></a>Comentários

Inicialmente, o item 0 está na parte superior da caixa de listagem, mas se a caixa de listagem for rolada, outro item poderá estar na parte superior.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#25](../../mfc/reference/codesnippet/cpp/ccombobox-class_25.cpp)]

##  <a name="initstorage"></a>CComboBox::InitStorage

Aloca memória para armazenar itens da caixa de listagem na parte da caixa de listagem da caixa de combinação.

```
int InitStorage(
    int nItems,
    UINT nBytes);
```

### <a name="parameters"></a>parâmetros

*nItems*<br/>
Especifica o número de itens a serem adicionados.

*nBytes*<br/>
Especifica a quantidade de memória, em bytes, a ser alocada para cadeias de caracteres de item.

### <a name="return-value"></a>Valor retornado

Se obtiver êxito, o número máximo de itens que a parte da caixa de combinação do box pode armazenar antes de uma realocação de memória ser necessária, caso contrário CB_ERRSPACE, o que significa que não há memória suficiente disponível.

### <a name="remarks"></a>Comentários

Chame essa função antes de adicionar um grande número de itens à parte da caixa de listagem do `CComboBox`.

Somente Windows 95/98: o parâmetro *wParam* é limitado a valores de 16 bits. Isso significa que as caixas de listagem não podem conter mais de 32.767 itens. Embora o número de itens seja restrito, o tamanho total dos itens em uma caixa de listagem é limitado apenas pela memória disponível.

Essa função ajuda a acelerar a inicialização de caixas de listagem que têm um grande número de itens (mais de 100). Ele prealoque a quantidade especificada de memória para que as funções [AddString](#addstring), [InsertString](#insertstring)e [dir](#dir) subsequentes tenham o menor tempo possível. Você pode usar estimativas para os parâmetros. Se você superestimar, uma memória extra é alocada; Se você subestimar, a alocação normal será usada para itens que excedem o valor prealocado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#26](../../mfc/reference/codesnippet/cpp/ccombobox-class_26.cpp)]

##  <a name="insertstring"></a>CComboBox:: InsertString

Insere uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.

```
int InsertString(
    int nIndex,
    LPCTSTR lpszString);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Contém o índice de base zero para a posição na caixa de listagem que receberá a cadeia de caracteres. Se esse parâmetro for-1, a cadeia de caracteres será adicionada ao final da lista.

*lpszString*<br/>
Aponta para a cadeia de caracteres terminada em nulo que deve ser inserida.

### <a name="return-value"></a>Valor retornado

O índice de base zero da posição na qual a cadeia de caracteres foi inserida. O valor de retorno será CB_ERR se ocorrer um erro. O valor de retorno será CB_ERRSPACE se houver espaço insuficiente disponível para armazenar a nova cadeia de caracteres.

### <a name="remarks"></a>Comentários

Ao contrário da função de membro [AddString](#addstring) , a função de membro `InsertString` não faz com que uma lista com o estilo de [CBS_SORT](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) seja classificada.

> [!NOTE]
>  Não há suporte para essa função pelo controle de `ComboBoxEx` do Windows. Para obter mais informações sobre esse controle, consulte [ComboBoxEx Controls](/windows/win32/Controls/comboboxex-controls) in the SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#27](../../mfc/reference/codesnippet/cpp/ccombobox-class_27.cpp)]

##  <a name="limittext"></a>CComboBox::LimitText

Limita o comprimento em bytes do texto que o usuário pode inserir no controle de edição de uma caixa de combinação.

```
BOOL LimitText(int nMaxChars);
```

### <a name="parameters"></a>parâmetros

*nMaxChars*<br/>
Especifica o comprimento (em bytes) do texto que o usuário pode inserir. Se esse parâmetro for 0, o tamanho do texto será definido como 65.535 bytes.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido. Se for chamado para uma caixa de combinação com o estilo [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou para uma caixa de combinação sem um controle de edição, o valor de retorno será CB_ERR.

### <a name="remarks"></a>Comentários

Se a caixa de combinação não tiver o estilo [CBS_AUTOHSCROLL](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles), definir o limite de texto como maior que o tamanho do controle de edição não terá nenhum efeito.

`LimitText` limita apenas o texto que o usuário pode inserir. Ele não tem nenhum efeito em nenhum texto que já esteja no controle de edição quando a mensagem é enviada, nem afeta o comprimento do texto copiado para o controle de edição quando uma cadeia de caracteres na caixa de listagem é selecionada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#28](../../mfc/reference/codesnippet/cpp/ccombobox-class_28.cpp)]

##  <a name="measureitem"></a>CComboBox::MeasureItem

Chamado pelo Framework quando uma caixa de combinação com um estilo de desenho proprietário é criada.

```
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```

### <a name="parameters"></a>parâmetros

*lpMeasureItemStruct*<br/>
Um ponteiro longo para uma estrutura [MEASUREITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-measureitemstruct) .

### <a name="remarks"></a>Comentários

Por padrão, essa função de membro não faz nada. Substitua essa função de membro e preencha a estrutura de `MEASUREITEMSTRUCT` para informar o Windows das dimensões da caixa de listagem na caixa de combinação. Se a caixa de combinação for criada com o estilo de [CBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) , a estrutura chamará essa função de membro para cada item na caixa de listagem. Caso contrário, esse membro será chamado apenas uma vez.

Usar o estilo de CBS_OWNERDRAWFIXED em uma caixa de combinação de desenho proprietário criada com a função membro [SubclassDlgItem](../../mfc/reference/cwnd-class.md#subclassdlgitem) de `CWnd` envolve considerações de programação adicionais. Consulte a discussão na [Nota técnica 14](../../mfc/tn014-custom-controls.md).

Consulte [CWnd:: OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter uma descrição da estrutura de `MEASUREITEMSTRUCT`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#29](../../mfc/reference/codesnippet/cpp/ccombobox-class_29.cpp)]

##  <a name="paste"></a>CComboBox::P lar

Insere os dados da área de transferência no controle de edição da caixa de combinação na posição atual do cursor.

```
void Paste();
```

### <a name="remarks"></a>Comentários

Os dados só serão inseridos se a área de transferência contiver dados no formato CF_TEXT.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#30](../../mfc/reference/codesnippet/cpp/ccombobox-class_30.cpp)]

##  <a name="resetcontent"></a>CComboBox::ResetContent

Remove todos os itens da caixa de listagem e edita o controle de uma caixa de combinação.

```
void ResetContent();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#31](../../mfc/reference/codesnippet/cpp/ccombobox-class_31.cpp)]

##  <a name="selectstring"></a>CComboBox:: SelectString

Procura uma cadeia de caracteres na caixa de listagem de uma caixa de combinação e, se a cadeia de caracteres for encontrada, seleciona a cadeia de caracteres na caixa de listagem e a copia para o controle de edição.

```
int SelectString(
    int nStartAfter,
    LPCTSTR lpszString);
```

### <a name="parameters"></a>parâmetros

*nStartAfter*<br/>
Contém o índice de base zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa atingir a parte inferior da caixa de listagem, ela continuará na parte superior da caixa de listagem de volta para o item especificado por *nStartAfter*. Se-1, a caixa de listagem inteira será pesquisada desde o início.

*lpszString*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo a ser pesquisado. A pesquisa diferencia maiúsculas de minúsculas, portanto, essa cadeia de caracteres pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor retornado

O índice de base zero do item selecionado se a cadeia de caracteres foi encontrada. Se a pesquisa não tiver sido bem-sucedida, o valor de retorno será CB_ERR e a seleção atual não será alterada.

### <a name="remarks"></a>Comentários

Uma cadeia de caracteres será selecionada somente se seus caracteres iniciais (do ponto de partida) corresponderem aos caracteres na cadeia de caracteres do prefixo.

Observe que as funções de membro `SelectString` e `FindString` localizam uma cadeia de caracteres, mas a função de membro `SelectString` também seleciona a cadeia de caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#32](../../mfc/reference/codesnippet/cpp/ccombobox-class_32.cpp)]

##  <a name="setcuebanner"></a>CComboBox::SetCueBanner

Define o texto de indicação que é exibido para um controle de caixa de combinação.

```
BOOL SetCueBanner(LPCTSTR lpszText);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*lpszText*|no Ponteiro para um buffer com terminação nula que contém o texto de indicação.|

### <a name="return-value"></a>Valor retornado

TRUE se o método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O texto de indicação é um prompt que é exibido na área de entrada do controle caixa de combinação. O texto de indicação é exibido até que o usuário forneça a entrada.

Esse método envia a mensagem de [CB_SETCUEBANNER](/windows/win32/Controls/cb-setcuebanner) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_combobox*, que é usada para acessar programaticamente o controle de caixa de combinação. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CComboBox_s1#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_33.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a faixa de indicação para o controle da caixa de combinação.

[!code-cpp[NVC_MFC_CComboBox_s1#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_34.cpp)]

##  <a name="setcursel"></a>CComboBox:: setcurseal

Seleciona uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.

```
int SetCurSel(int nSelect);
```

### <a name="parameters"></a>parâmetros

*nSelecionar*<br/>
Especifica o índice de base zero da cadeia de caracteres a ser selecionada. Se-1, qualquer seleção atual na caixa de listagem será removida e o controle de edição será limpo.

### <a name="return-value"></a>Valor retornado

O índice de base zero do item selecionado se a mensagem for bem-sucedida. O valor de retorno será CB_ERR se *nSelecionar* for maior que o número de itens na lista ou se *nSelecionar* for definido como-1, o que limpará a seleção.

### <a name="remarks"></a>Comentários

Se necessário, a caixa de listagem rola a cadeia de caracteres para a exibição (se a caixa de listagem estiver visível). O texto no controle de edição da caixa de combinação é alterado para refletir a nova seleção. Qualquer seleção anterior na caixa de listagem é removida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#33](../../mfc/reference/codesnippet/cpp/ccombobox-class_35.cpp)]

##  <a name="setdroppedwidth"></a>CComboBox::SetDroppedWidth

Chame essa função para definir a largura mínima permitida, em pixels, da caixa de listagem de uma caixa de combinação.

```
int SetDroppedWidth(UINT nWidth);
```

### <a name="parameters"></a>parâmetros

*nWidth*<br/>
A largura mínima permitida da parte da caixa de listagem da caixa de combinação, em pixels.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedida, a nova largura da caixa de listagem, caso contrário CB_ERR.

### <a name="remarks"></a>Comentários

Essa função só se aplica a caixas de combinação com o estilo [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) .

Por padrão, a largura mínima permitida da caixa de listagem suspensa é 0. Quando a parte da caixa de listagem da caixa de combinação é exibida, sua largura é maior que a largura mínima permitida ou a largura da caixa de combinação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#34](../../mfc/reference/codesnippet/cpp/ccombobox-class_36.cpp)]

##  <a name="seteditsel"></a>CComboBox::SetEditSel

Seleciona caracteres no controle de edição de uma caixa de combinação.

```
BOOL SetEditSel(
    int nStartChar,
    int nEndChar);
```

### <a name="parameters"></a>parâmetros

*nStartChar*<br/>
Especifica a posição inicial. Se a posição inicial for definida como-1, qualquer seleção existente será removida.

*nEndChar*<br/>
Especifica a posição final. Se a posição final for definida como-1, todo o texto da posição inicial para o último caractere no controle de edição será selecionado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função de membro for bem-sucedida; caso contrário, 0. Será CB_ERR se `CComboBox` tiver o estilo de [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou não tiver uma caixa de listagem.

### <a name="remarks"></a>Comentários

As posições são baseadas em zero. Para selecionar o primeiro caractere do controle de edição, especifique uma posição inicial de 0. A posição final é para o caractere logo após o último caractere a ser selecionado. Por exemplo, para selecionar os quatro primeiros caracteres do controle de edição, você usaria uma posição inicial de 0 e uma posição final de 4.

> [!NOTE]
>  Não há suporte para essa função pelo controle de `ComboBoxEx` do Windows. Para obter mais informações sobre esse controle, consulte [ComboBoxEx Controls](/windows/win32/Controls/comboboxex-controls) in the SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CComboBox:: GetEditSel](#geteditsel).

##  <a name="setextendedui"></a>CComboBox::SetExtendedUI

Chame a função de membro `SetExtendedUI` para selecionar a interface do usuário padrão ou a interface do usuário estendida para uma caixa de combinação que tenha o estilo de [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) .

```
int SetExtendedUI(BOOL bExtended = TRUE);
```

### <a name="parameters"></a>parâmetros

*Bo*<br/>
Especifica se a caixa de combinação deve usar a interface do usuário estendida ou a interface do usuário padrão. Um valor TRUE seleciona a interface do usuário estendida; um valor FALSE seleciona a interface do usuário padrão.

### <a name="return-value"></a>Valor retornado

CB_OKAY se a operação for bem-sucedida ou CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

A interface do usuário estendida pode ser identificada das seguintes maneiras:

- Clicar no controle estático exibe a caixa de listagem somente para caixas de combinação com o estilo de CBS_DROPDOWNLIST.

- Pressionar a tecla de seta para baixo exibe a caixa de listagem (F4 está desabilitado).

A rolagem no controle estático é desabilitada quando a lista de itens não está visível (as teclas de seta estão desabilitadas).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CComboBox:: GetExtendedUI](#getextendedui).

##  <a name="sethorizontalextent"></a>CComboBox::SetHorizontalExtent

Define a largura, em pixels, na qual a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.

```
void SetHorizontalExtent(UINT nExtent);
```

### <a name="parameters"></a>parâmetros

*nExtent*<br/>
Especifica o número de pixels pelos quais a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.

### <a name="remarks"></a>Comentários

Se a largura da caixa de listagem for menor que esse valor, a barra de rolagem horizontal irá rolar os itens horizontalmente na caixa de listagem. Se a largura da caixa de listagem for igual ou maior que esse valor, a barra de rolagem horizontal ficará oculta ou, se a caixa de combinação tiver o estilo de [CBS_DISABLENOSCROLL](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) , será desabilitada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#35](../../mfc/reference/codesnippet/cpp/ccombobox-class_37.cpp)]

##  <a name="setitemdata"></a>CComboBox::SetItemData

Define o valor de 32 bits associado ao item especificado em uma caixa de combinação.

```
int SetItemData(
    int nIndex,
    DWORD_PTR dwItemData);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Contém um índice de base zero para o item a ser definido.

*dwItemData*<br/>
Contém o novo valor a ser associado ao item.

### <a name="return-value"></a>Valor retornado

CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Use a função de membro `SetItemDataPtr` se o item de 32 bits for um ponteiro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#36](../../mfc/reference/codesnippet/cpp/ccombobox-class_38.cpp)]

##  <a name="setitemdataptr"></a>CComboBox::SetItemDataPtr

Define o valor de 32 bits associado ao item especificado em uma caixa de combinação para ser o ponteiro especificado (**void** <strong>\*</strong>).

```
int SetItemDataPtr(
    int nIndex,
    void* pData);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Contém um índice de base zero para o item.

*pData*<br/>
Contém o ponteiro a ser associado ao item.

### <a name="return-value"></a>Valor retornado

CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Esse ponteiro permanece válido durante a vida útil da caixa de combinação, mesmo que a posição relativa do item dentro da caixa de combinação possa ser alterada à medida que os itens são adicionados ou removidos. Portanto, o índice do item dentro da caixa pode ser alterado, mas o ponteiro permanece confiável.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#37](../../mfc/reference/codesnippet/cpp/ccombobox-class_39.cpp)]

##  <a name="setitemheight"></a>CComboBox::SetItemHeight

Chame a função de membro `SetItemHeight` para definir a altura dos itens de lista em uma caixa de combinação ou a altura da parte do controle de edição (ou texto estático) de uma caixa de combinação.

```
int SetItemHeight(
    int nIndex,
    UINT cyItemHeight);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Especifica se a altura dos itens de lista ou a altura da parte de controle de edição (ou texto estático) da caixa de combinação está definida.

Se a caixa de combinação tiver o estilo de [CBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) , *nIndex* especificará o índice de base zero do item de lista cuja altura deve ser definida; caso contrário, *nIndex* deverá ser 0 e a altura de todos os itens da lista será definida.

Se *nIndex* for-1, a altura da parte do controle de edição ou do texto estático da caixa de combinação será definida.

*cyItemHeight*<br/>
Especifica a altura, em pixels, do componente de caixa de combinação identificado por *nIndex*.

### <a name="return-value"></a>Valor retornado

CB_ERR se o índice ou a altura for inválido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A altura da parte do controle de edição (ou texto estático) da caixa de combinação é definida independentemente da altura dos itens da lista. Um aplicativo deve garantir que a porção da parte de controle de edição (ou texto estático) não seja menor do que a altura de um item de caixa de listagem específico.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#38](../../mfc/reference/codesnippet/cpp/ccombobox-class_40.cpp)]

##  <a name="setlocale"></a>CComboBox:: setlocale

Define o identificador de localidade para esta caixa de combinação.

```
LCID SetLocale(LCID nNewLocale);
```

### <a name="parameters"></a>parâmetros

*nNewLocale*<br/>
O novo valor de LCID (identificador de localidade) a ser definido para a caixa de combinação.

### <a name="return-value"></a>Valor retornado

O valor do LCID (identificador de localidade) anterior desta caixa de combinação.

### <a name="remarks"></a>Comentários

Se `SetLocale` não for chamado, a localidade padrão será obtida do sistema. Essa localidade padrão do sistema pode ser modificada usando o aplicativo regional (ou internacional) do painel de controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#39](../../mfc/reference/codesnippet/cpp/ccombobox-class_41.cpp)]

##  <a name="setminvisibleitems"></a>CComboBox::SetMinVisibleItems

Define o número mínimo de itens visíveis na lista suspensa do controle da caixa de combinação atual.

```
BOOL SetMinVisibleItems(int iMinVisible);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*ininvisível*|no Especifica o número mínimo de itens visíveis.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [CB_SETMINVISIBLE](/windows/win32/Controls/cb-setminvisible) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_combobox*, que é usada para acessar programaticamente o controle de caixa de combinação. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CComboBox_s1#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_33.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir insere 20 itens na lista suspensa de um controle de caixa de combinação. Em seguida, ele especifica que um mínimo de 10 itens seja exibido quando um usuário pressiona a seta suspensa.

[!code-cpp[NVC_MFC_CComboBox_s1#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_34.cpp)]

##  <a name="settopindex"></a>CComboBox::SetTopIndex

Garante que um item específico esteja visível na parte da caixa de listagem da caixa de combinação.

```
int SetTopIndex(int nIndex);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Especifica o índice de base zero do item da caixa de listagem.

### <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido ou CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

O sistema rola a caixa de listagem até que o item especificado por *nIndex* seja exibido na parte superior da caixa de listagem ou o intervalo máximo de rolagem tenha sido atingido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#40](../../mfc/reference/codesnippet/cpp/ccombobox-class_42.cpp)]

##  <a name="showdropdown"></a>CComboBox:: lista suspensa

Mostra ou oculta a caixa de listagem de uma caixa de combinação que tem o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou o estilo de [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) .

```
void ShowDropDown(BOOL bShowIt = TRUE);
```

### <a name="parameters"></a>parâmetros

*bShowIt*<br/>
Especifica se a caixa de listagem suspensa deve ser exibida ou ocultada. Um valor de TRUE mostra a caixa de listagem. Um valor de FALSE oculta a caixa de listagem.

### <a name="remarks"></a>Comentários

Por padrão, uma caixa de combinação desse estilo mostrará a caixa de listagem.

Essa função de membro não tem nenhum efeito em uma caixa de combinação criada com o estilo de [CBS_SIMPLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) .

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CComboBox:: Getremovestate](#getdroppedstate).

## <a name="see-also"></a>Confira também

[Exemplo de CTRLBARS do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)<br/>
[Classe CStatic](../../mfc/reference/cstatic-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
