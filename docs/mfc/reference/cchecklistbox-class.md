---
title: Classe CCheckListBox
ms.date: 11/04/2016
f1_keywords:
- CCheckListBox
- AFXWIN/CCheckListBox
- AFXWIN/CCheckListBox::CCheckListBox
- AFXWIN/CCheckListBox::Create
- AFXWIN/CCheckListBox::DrawItem
- AFXWIN/CCheckListBox::Enable
- AFXWIN/CCheckListBox::GetCheck
- AFXWIN/CCheckListBox::GetCheckStyle
- AFXWIN/CCheckListBox::IsEnabled
- AFXWIN/CCheckListBox::MeasureItem
- AFXWIN/CCheckListBox::OnGetCheckPosition
- AFXWIN/CCheckListBox::SetCheck
- AFXWIN/CCheckListBox::SetCheckStyle
helpviewer_keywords:
- CCheckListBox [MFC], CCheckListBox
- CCheckListBox [MFC], Create
- CCheckListBox [MFC], DrawItem
- CCheckListBox [MFC], Enable
- CCheckListBox [MFC], GetCheck
- CCheckListBox [MFC], GetCheckStyle
- CCheckListBox [MFC], IsEnabled
- CCheckListBox [MFC], MeasureItem
- CCheckListBox [MFC], OnGetCheckPosition
- CCheckListBox [MFC], SetCheck
- CCheckListBox [MFC], SetCheckStyle
ms.assetid: 1dd78438-00e8-441c-b36f-9c4f9ac0d019
ms.openlocfilehash: cd50711813a3cfc1305cd5558c95e909ddbfc3f2
ms.sourcegitcommit: ab8d7b47b63b62892a1256a09b1324a9a136eccf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/02/2020
ms.locfileid: "78215519"
---
# <a name="cchecklistbox-class"></a>Classe CCheckListBox

Fornece a funcionalidade de uma caixa de lista de verificação do Windows.

## <a name="syntax"></a>Sintaxe

```
class CCheckListBox : public CListBox
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CCheckListBox::CCheckListBox](#cchecklistbox)|Constrói um objeto `CCheckListBox`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CCheckListBox:: criar](#create)|Cria a caixa lista de verificação do Windows e a anexa ao objeto `CCheckListBox`.|
|[CCheckListBox::D rawItem](#drawitem)|Chamado pelo Framework quando um aspecto visual de uma caixa de listagem de desenho proprietário é alterado.|
|[CCheckListBox:: habilitar](#enable)|Habilita ou desabilita um item da caixa de lista de verificação.|
|[CCheckListBox:: getcheck](#getcheck)|Obtém o estado da caixa de seleção de um item.|
|[CCheckListBox:: getcheckstyle](#getcheckstyle)|Obtém o estilo das caixas de seleção do controle.|
|[CCheckListBox:: IsEnabled](#isenabled)|Determina se um item está habilitado.|
|[CCheckListBox::MeasureItem](#measureitem)|Chamado pelo Framework quando uma caixa de listagem com um estilo de desenho proprietário é criada.|
|[CCheckListBox::OnGetCheckPosition](#ongetcheckposition)|Chamado pelo Framework para obter a posição da caixa de seleção de um item.|
|[CCheckListBox:: SetCheck](#setcheck)|Define o estado da caixa de seleção de um item.|
|[CCheckListBox:: SetCheckStyle](#setcheckstyle)|Define o estilo das caixas de seleção do controle.|

## <a name="remarks"></a>Comentários

Uma "caixa de listagem de verificação" exibe uma lista de itens, como nomes de File. Cada item na lista tem uma caixa de seleção ao lado do que o usuário pode marcar ou desmarcar.

`CCheckListBox` é apenas para controles desenhados pelo proprietário porque a lista contém mais de cadeias de caracteres de texto. Em sua forma mais simples, uma caixa de lista de verificação contém cadeias de caracteres de texto e caixas de seleção, mas você não precisa ter texto. Por exemplo, você pode ter uma lista de bitmaps pequenos com uma caixa de seleção ao lado de cada item.

Para criar sua própria caixa de lista de verificação, você deve derivar sua própria classe de `CCheckListBox`. Para derivar sua própria classe, escreva um construtor para a classe derivada e, em seguida, chame `Create`.

Se você quiser manipular as mensagens de notificação do Windows enviadas por uma caixa de listagem para seu pai (geralmente uma classe derivada de [CDialog](../../mfc/reference/cdialog-class.md)), adicione uma entrada de mapa de mensagem e uma função de membro de manipulador de mensagens à classe pai para cada mensagem.

Cada entrada de mapa de mensagem usa o seguinte formato:

**Na notificação de\_** **(** _ID_, _memberFxn_ **)**

em que `id` especifica a ID da janela filho do controle que envia a notificação e `memberFxn` é o nome da função de membro pai que você escreveu para manipular a notificação.

O protótipo de função do pai é o seguinte:

`afx_msg void memberFxn();`

Há apenas uma entrada de mapa de mensagem que pertence especificamente a `CCheckListBox` (mas veja também as entradas de mapa de mensagem para [CListBox](../../mfc/reference/clistbox-class.md)):

- ON_CLBN_CHKCHANGE o usuário alterou o estado da caixa de seleção de um item.

Se a caixa lista de verificação for uma caixa de lista de verificação padrão (uma listagem de cadeias de caracteres com as caixas de seleção de tamanho padrão à esquerda de cada), você poderá usar o [CCheckListBox::D rawitem](#drawitem) padrão para desenhar a caixa lista de verificação. Caso contrário, você deve substituir a função [CListBox:: CompareItem](../../mfc/reference/clistbox-class.md#compareitem) e as funções [CCheckListBox::D rawitem](#drawitem) e [CCheckListBox:: MeasureItem](#measureitem) .

Você pode criar uma caixa de lista de verificação a partir de um modelo de caixa de diálogo ou diretamente no seu código.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CListBox](../../mfc/reference/clistbox-class.md)

`CCheckListBox`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cchecklistbox"></a>CCheckListBox::CCheckListBox

Constrói um objeto `CCheckListBox`.

```
CCheckListBox();
```

### <a name="remarks"></a>Comentários

Você constrói um objeto `CCheckListBox` em duas etapas. Primeiro, defina uma classe derivada de `CCheckListBox`, em seguida, chame `Create`, que inicializa a caixa lista de verificação do Windows e a anexa ao objeto `CCheckListBox`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#60](../../mfc/codesnippet/cpp/cchecklistbox-class_1.cpp)]

##  <a name="create"></a>CCheckListBox:: criar

Cria a caixa lista de verificação do Windows e a anexa ao objeto `CCheckListBox`.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>parâmetros

*dwStyle*<br/>
Especifica o estilo da caixa de lista de verificação. O estilo deve ser LBS_HASSTRINGS e LBS_OWNERDRAWFIXED (todos os itens da lista têm a mesma altura) ou LBS_OWNERDRAWVARIABLE (os itens na lista têm alturas variadas). Esse estilo pode ser combinado com outros [estilos de caixa de listagem](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) , exceto LBS_USETABSTOPS.

*Rect*<br/>
Especifica o tamanho e a posição da caixa de lista de verificação. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) .

*pParentWnd*<br/>
Especifica a janela pai da caixa de lista de verificação (geralmente um objeto `CDialog`). Ele não deve ser nulo.

*nID*<br/>
Especifica a ID de controle da caixa de lista de verificação.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um objeto `CCheckListBox` em duas etapas. Primeiro, defina uma classe derivada de `CcheckListBox` e, em seguida, chame `Create`, que inicializa a caixa lista de verificação do Windows e a anexa à `CCheckListBox`. Consulte [CCheckListBox:: CCheckListBox](#cchecklistbox) para obter um exemplo.

Quando `Create` é executado, o Windows envia as mensagens [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize)e [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) para o controle caixa de lista de verificação.

Essas mensagens são tratadas por padrão pelas funções de membro [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate), [OnCreate](../../mfc/reference/cwnd-class.md#oncreate), [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize)e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) na classe base `CWnd`. Para estender a manipulação de mensagens padrão, adicione um mapa de mensagem à classe derivada e substitua as funções de membro do manipulador de mensagens anterior. Substitua `OnCreate`, por exemplo, para executar a inicialização necessária para uma nova classe.

Aplique os seguintes [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle caixa de seleção:

- WS_CHILD sempre

- Geralmente WS_VISIBLE

- WS_DISABLED raramente

- WS_VSCROLL adicionar uma barra de rolagem vertical

- WS_HSCROLL adicionar uma barra de rolagem horizontal

- WS_GROUP a controles de grupo

- WS_TABSTOP permitir a Tabulação deste controle

##  <a name="drawitem"></a>CCheckListBox::D rawItem

Chamado pelo Framework quando um aspecto visual de uma caixa da lista de verificação de desenho proprietário é alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro longo para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

Os membros `itemAction` e `itemState` da estrutura de `DRAWITEMSTRUCT` definem a ação de desenho a ser executada.

Por padrão, essa função desenha uma lista de caixas de seleção padrão, que consiste em uma lista de cadeias de caracteres cada uma com uma caixa de seleção de tamanho padrão à esquerda. O tamanho da lista de caixas de seleção é aquele especificado em [criar](#create).

Substitua essa função de membro para implementar o desenho de caixas de lista de verificação de desenho proprietário que não são o padrão, como as caixas de listas de verificação que não são cadeias de caracteres, com itens de altura variável ou com caixas de seleção que não estão à esquerda. O aplicativo deve restaurar todos os objetos da interface de dispositivo de gráficos (GDI) selecionados para o contexto de exibição fornecido em *lpDrawItemStruct* antes do término dessa função de membro.

Se os itens da caixa da lista de verificação não tiverem a mesma altura, o estilo da caixa de lista de verificação (especificado em `Create`) deverá ser **LBS_OWNERVARIABLE**e você deverá substituir a função [MeasureItem](#measureitem) .

##  <a name="enable"></a>CCheckListBox:: habilitar

Chame essa função para habilitar ou desabilitar um item da caixa de lista de verificação.

```
void Enable(
    int nIndex,
    BOOL bEnabled = TRUE);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Índice do item da caixa de lista de verificação a ser habilitado.

*bEnabled*<br/>
Especifica se o item está habilitado ou desabilitado.

##  <a name="getcheck"></a>CCheckListBox:: getcheck

Recupera o estado da caixa de seleção especificada.

```
int GetCheck(int nIndex);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Índice de base zero de uma caixa de seleção contida na caixa de listagem.

### <a name="return-value"></a>Valor retornado

O estado da caixa de seleção especificada. A tabela a seguir lista os valores possíveis.

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|BST_CHECKED|A caixa de seleção está marcada.|
|BST_UNCHECKED|A caixa de seleção não está marcada.|
|BST_INDETERMINATE|O estado da caixa de seleção é indeterminado.|

##  <a name="getcheckstyle"></a>CCheckListBox:: getcheckstyle

Chame essa função para obter o estilo da caixa de lista de verificação.

```
UINT GetCheckStyle();
```

### <a name="return-value"></a>Valor retornado

O estilo das caixas de seleção do controle.

### <a name="remarks"></a>Comentários

Para obter informações sobre os possíveis estilos, consulte [SetCheckStyle](#setcheckstyle).

##  <a name="isenabled"></a>CCheckListBox:: IsEnabled

Chame essa função para determinar se um item está habilitado.

```
BOOL IsEnabled(int nIndex);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Índice do item.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o item estiver habilitado; caso contrário, 0.

##  <a name="measureitem"></a>CCheckListBox::MeasureItem

Chamado pelo Framework quando uma caixa de lista de verificação com um estilo não padrão é criada.

```
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```

### <a name="parameters"></a>parâmetros

*lpMeasureItemStruct*<br/>
Um ponteiro longo para uma estrutura [MEASUREITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-measureitemstruct) .

### <a name="remarks"></a>Comentários

Por padrão, essa função de membro não faz nada. Substitua essa função de membro e preencha a estrutura de `MEASUREITEMSTRUCT` para informar o Windows das dimensões dos itens da caixa de lista de verificação. Se a caixa lista de verificação for criada com o estilo de [LBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) , a estrutura chamará essa função de membro para cada item na caixa de listagem. Caso contrário, esse membro será chamado apenas uma vez.

##  <a name="ongetcheckposition"></a>CCheckListBox::OnGetCheckPosition

A estrutura chama essa função para obter a posição e o tamanho da caixa de seleção em um item.

```
virtual CRect OnGetCheckPosition(
    CRect rectItem,
    CRect rectCheckBox);
```

### <a name="parameters"></a>parâmetros

*rectItem*<br/>
A posição e o tamanho do item de lista.

*rectCheckBox*<br/>
A posição e o tamanho padrão da caixa de seleção de um item.

### <a name="return-value"></a>Valor retornado

A posição e o tamanho da caixa de seleção de um item.

### <a name="remarks"></a>Comentários

A implementação padrão só retorna a posição e o tamanho padrão da caixa de seleção (`rectCheckBox`). Por padrão, uma caixa de seleção é alinhada no canto superior esquerdo de um item e é o tamanho da caixa de seleção padrão. Pode haver casos em que você deseja que as caixas de seleção estejam à direita ou que desejam uma caixa de seleção maior ou menor. Nesses casos, substitua `OnGetCheckPosition` para alterar a posição e o tamanho da caixa de seleção dentro do item.

##  <a name="setcheck"></a>CCheckListBox:: SetCheck

Define o estado da caixa de seleção especificada.

```
void SetCheck(
    int nIndex,
    int nCheck);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Índice de base zero de uma caixa de seleção contida na caixa de listagem.

*nVerifique*<br/>
O estado do botão para a caixa de seleção especificada. Consulte a seção comentários para obter os valores possíveis.

### <a name="remarks"></a>Comentários

A tabela a seguir lista os possíveis valores para o parâmetro *nVerifique* .

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|BST_CHECKED|Marque a caixa de seleção especificada.|
|BST_UNCHECKED|Desmarque a caixa de seleção especificada.|
|BST_INDETERMINATE|Defina o estado da caixa de seleção especificada como indeterminado.<br /><br /> Esse Estado só estará disponível se o estilo da caixa de seleção for BS_AUTO3STATE ou BS_3STATE. Para obter mais informações, consulte [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).|

##  <a name="setcheckstyle"></a>CCheckListBox:: SetCheckStyle

Chame essa função para definir o estilo das caixas de seleção na caixa lista de verificação.

```
void SetCheckStyle(UINT nStyle);
```

### <a name="parameters"></a>parâmetros

*nStyle*<br/>
Determina o estilo das caixas de seleção na caixa lista de verificação.

### <a name="remarks"></a>Comentários

Os estilos válidos são:

- BS_CHECKBOX

- BS_AUTOCHECKBOX

- BS_AUTO3STATE

- BS_3STATE

Para obter informações sobre esses estilos, consulte [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).

## <a name="see-also"></a>Confira também

[Exemplo de TSTCON do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)
