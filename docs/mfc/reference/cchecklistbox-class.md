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
ms.openlocfilehash: dc0e80e80d61104a4d8cb5f1cfd4e26a64c42249
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752738"
---
# <a name="cchecklistbox-class"></a>Classe CCheckListBox

Fornece a funcionalidade de uma caixa de seleção do Windows.

## <a name="syntax"></a>Sintaxe

```
class CCheckListBox : public CListBox
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CCheckListBox::CCheckListBox](#cchecklistbox)|Constrói um objeto `CCheckListBox`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCheckListBox::Criar](#create)|Cria a caixa de seleção `CCheckListBox` do Windows e a anexa ao objeto.|
|[CCheckListBox::DrawItem](#drawitem)|Chamado pela estrutura quando um aspecto visual de uma caixa de lista de sorteio do proprietário é alterado.|
|[CCheckListBox::Habilitar](#enable)|Ativa ou desativa um item da caixa de seleção.|
|[CCheckListBox::GetCheck](#getcheck)|Fica com o estado da caixa de seleção de um item.|
|[CCheckListBox::GetCheckStyle](#getcheckstyle)|Tem o estilo das caixas de seleção do controle.|
|[CCheckListBox::IsEnabled](#isenabled)|Determina se um item está habilitado.|
|[CCheckListBox::MeasureItem](#measureitem)|Chamado pela estrutura quando uma caixa de lista com um estilo de sorteio do proprietário é criada.|
|[CchecklistBox::OnGetCheckPosition](#ongetcheckposition)|Chamado pela estrutura para obter a posição da caixa de seleção de um item.|
|[CCheckListBox::SetCheck](#setcheck)|Define o estado da caixa de seleção de um item.|
|[CCheckListBox::SetCheckStyle](#setcheckstyle)|Define o estilo das caixas de seleção do controle.|

## <a name="remarks"></a>Comentários

Uma "caixa de seleção" exibe uma lista de itens, como nomes de arquivos. Cada item da lista tem uma caixa de seleção ao lado que o usuário pode verificar ou limpar.

`CCheckListBox`é apenas para controles desenhados pelo proprietário porque a lista contém mais do que seqüências de texto. Em sua mais simples, uma caixa de seleção contém seqüências de texto e caixas de seleção, mas você não precisa ter texto em tudo. Por exemplo, você pode ter uma lista de pequenos bitmaps com uma caixa de seleção ao lado de cada item.

Para criar sua própria caixa de seleção, você deve derivar sua própria classe de `CCheckListBox`. Para obter sua própria classe, escreva um construtor para `Create`a classe derivada, em seguida, chame .

Se você quiser lidar com mensagens de notificação do Windows enviadas por uma caixa de lista para seu pai (geralmente uma classe derivada do [CDialog),](../../mfc/reference/cdialog-class.md)adicione uma função de membro do mapa de mensagem e do manipulador de mensagens à classe pai para cada mensagem.

Cada entrada de mapa de mensagem tem o seguinte formulário:

**ON\_**_Notification_ _(id_, _memberFxn_ **)** **(**

onde `id` especifica o ID da janela filho `memberFxn` do controle que envia a notificação e é o nome da função de membro pai que você escreveu para lidar com a notificação.

O protótipo de função dos pais é o seguinte:

`afx_msg void memberFxn();`

Há apenas uma entrada de mapa de `CCheckListBox` mensagem que diz respeito especificamente a (mas veja também as entradas do mapa de mensagem para [CListBox](../../mfc/reference/clistbox-class.md)):

- ON_CLBN_CHKCHANGE O usuário alterou o estado da caixa de seleção de um item.

Se a caixa de seleção for uma caixa de seleção padrão (uma lista de strings com as caixas de seleção do tamanho padrão à esquerda de cada uma), você pode usar o [CCheckListBox padrão::DrawItem](#drawitem) para desenhar a caixa de seleção. Caso contrário, você deve substituir as funções [CListBox::CompareItem](../../mfc/reference/clistbox-class.md#compareitem) e [cCheckListBox::DrawItem](#drawitem) e [CCheckListBox::MeasureItem.](#measureitem)

Você pode criar uma caixa de seleção de seleção a partir de um modelo de diálogo ou diretamente em seu código.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CListBox](../../mfc/reference/clistbox-class.md)

`CCheckListBox`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cchecklistboxcchecklistbox"></a><a name="cchecklistbox"></a>CCheckListBox::CCheckListBox

Constrói um objeto `CCheckListBox`.

```
CCheckListBox();
```

### <a name="remarks"></a>Comentários

Você constrói `CCheckListBox` um objeto em dois passos. Primeiro defina uma `CCheckListBox`classe derivada de , em seguida, chamada `Create`, que `CCheckListBox` inicializa a caixa de seleção do Windows e anexa-a ao objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#60](../../mfc/codesnippet/cpp/cchecklistbox-class_1.cpp)]

## <a name="cchecklistboxcreate"></a><a name="create"></a>CCheckListBox::Criar

Cria a caixa de seleção `CCheckListBox` do Windows e a anexa ao objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo da caixa de seleção. O estilo deve ser LBS_HASSTRINGS e LBS_OWNERDRAWFIXED (todos os itens da lista têm a mesma altura) ou LBS_OWNERDRAWVARIABLE (itens da lista são de alturas variadas). Este estilo pode ser combinado com outros [estilos de list-box,](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) exceto LBS_USETABSTOPS.

*Rect*<br/>
Especifica o tamanho e a posição da caixa de seleção. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT.](/windows/win32/api/windef/ns-windef-rect)

*Pparentwnd*<br/>
Especifica a janela pai da caixa de `CDialog` seleção (geralmente um objeto). Não deve ser NULO.

*nID*<br/>
Especifica o ID de controle da caixa de seleção.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CCheckListBox` um objeto em dois passos. Primeiro, defina uma `CcheckListBox` classe derivada e, em seguida, chamada, `Create`que inicializa a caixa de seleção do Windows e a `CCheckListBox`anexa à . Consulte [CCheckListBox::CCheckListBox](#cchecklistbox) para obter uma amostra.

Quando `Create` é executado, o Windows envia as mensagens [WM_NCCREATE,](../../mfc/reference/cwnd-class.md#onnccreate) [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate)e [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize)e [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) para o controle da caixa de seleção.

Essas mensagens são tratadas por padrão pelas funções de membro [OnNcCreate,](../../mfc/reference/cwnd-class.md#onnccreate) [OnCreate,](../../mfc/reference/cwnd-class.md#oncreate) [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize)e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) na `CWnd` classe base. Para estender o tratamento padrão da mensagem, adicione um mapa de mensagem à classe derivada e anule as funções anteriores do membro do manipulador de mensagens. Substituição, `OnCreate`por exemplo, para realizar a inicialização necessária para uma nova classe.

Aplique os [seguintes estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de caixa de verificação:

- WS_CHILD Sempre

- WS_VISIBLE Normalmente

- WS_DISABLED raramente

- WS_VSCROLL Para adicionar uma barra de rolagem vertical

- WS_HSCROLL Para adicionar uma barra de rolagem horizontal

- WS_GROUP Para controles de grupo

- WS_TABSTOP Para permitir a tabulação a este controle

## <a name="cchecklistboxdrawitem"></a><a name="drawitem"></a>CCheckListBox::DrawItem

Chamado pela estrutura quando um aspecto visual de uma caixa de seleção desenhada pelo proprietário é alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*Lpdrawitemstruct*<br/>
Um ponteiro longo para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

Os `itemAction` `itemState` membros da `DRAWITEMSTRUCT` estrutura definem a ação de desenho a ser realizada.

Por padrão, esta função desenha uma lista de seleção padrão, consistindo de uma lista de strings cada uma com uma caixa de seleção do tamanho padrão à esquerda. O tamanho da lista de caixas de seleção é o especificado em [Criar](#create).

Substituir essa função de membro para implementar o desenho de caixas de seleção de sorteio de proprietários que não são o padrão, como caixas de seleção com listas que não são strings, com itens de altura variável ou com caixas de seleção que não estão à esquerda. O aplicativo deve restaurar todos os objetos GDI (Graphics Device Interface, interface de dispositivo gráfico) selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes do término desta função de membro.

Se os itens da caixa de seleção não estiverem todos da `Create`mesma altura, o estilo da caixa de seleção (especificado) deve ser **LBS_OWNERVARIABLE**, e você deve substituir a função [MeasureItem.](#measureitem)

## <a name="cchecklistboxenable"></a><a name="enable"></a>CCheckListBox::Habilitar

Chame esta função para ativar ou desativar um item da caixa de seleção.

```cpp
void Enable(
    int nIndex,
    BOOL bEnabled = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do item da caixa de seleção a ser ativado.

*bEnabled*<br/>
Especifica se o item está ativado ou desativado.

## <a name="cchecklistboxgetcheck"></a><a name="getcheck"></a>CCheckListBox::GetCheck

Recupera o estado da caixa de seleção especificada.

```
int GetCheck(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice baseado em zero de uma caixa de seleção que está contido na caixa de lista.

### <a name="return-value"></a>Valor retornado

O estado da caixa de seleção especificada. A tabela a seguir lista possíveis valores.

|Valor|Descrição|
|-----------|-----------------|
|BST_CHECKED|A caixa de seleção está marcada.|
|Bst_unchecked|A caixa de seleção não está verificada.|
|BST_INDETERMINATE|O estado da caixa de seleção é indeterminado.|

## <a name="cchecklistboxgetcheckstyle"></a><a name="getcheckstyle"></a>CCheckListBox::GetCheckStyle

Chame esta função para obter o estilo da caixa de seleção.

```
UINT GetCheckStyle();
```

### <a name="return-value"></a>Valor retornado

O estilo das caixas de seleção do controle.

### <a name="remarks"></a>Comentários

Para obter informações sobre possíveis estilos, consulte [SetCheckStyle](#setcheckstyle).

## <a name="cchecklistboxisenabled"></a><a name="isenabled"></a>CCheckListBox::IsEnabled

Ligue para esta função para determinar se um item está ativado.

```
BOOL IsEnabled(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do item.

### <a name="return-value"></a>Valor retornado

Não zero se o item estiver habilitado; caso contrário, 0.

## <a name="cchecklistboxmeasureitem"></a><a name="measureitem"></a>CCheckListBox::MeasureItem

Chamado pelo framework quando uma caixa de seleção com um estilo não padrão é criada.

```
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpMeasureItemStruct*<br/>
Um ponteiro longo para uma estrutura [MEASUREITEMSTRUCT.](/windows/win32/api/winuser/ns-winuser-measureitemstruct)

### <a name="remarks"></a>Comentários

Por padrão, esta função de membro não faz nada. Anular esta função de membro `MEASUREITEMSTRUCT` e preencher a estrutura para informar o Windows das dimensões dos itens da caixa de seleção. Se a caixa de seleção for criada com o estilo [LBS_OWNERDRAWVARIABLE,](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) a estrutura chamará essa função de membro para cada item na caixa de lista. Caso contrário, este membro é chamado apenas uma vez.

## <a name="cchecklistboxongetcheckposition"></a><a name="ongetcheckposition"></a>CchecklistBox::OnGetCheckPosition

A estrutura chama esta função para obter a posição e o tamanho da caixa de seleção em um item.

```
virtual CRect OnGetCheckPosition(
    CRect rectItem,
    CRect rectCheckBox);
```

### <a name="parameters"></a>Parâmetros

*rectItem*<br/>
A posição e o tamanho do item da lista.

*rectCheckBox*<br/>
A posição padrão e o tamanho da caixa de seleção de um item.

### <a name="return-value"></a>Valor retornado

A posição e o tamanho da caixa de seleção de um item.

### <a name="remarks"></a>Comentários

A implementação padrão só retorna a posição`rectCheckBox`padrão e o tamanho da caixa de seleção ( ). Por padrão, uma caixa de seleção está alinhada no canto superior esquerdo de um item e é o tamanho padrão da caixa de seleção. Pode haver casos em que você quer as caixas de seleção à direita, ou quer uma caixa de seleção maior ou menor. Nestes casos, `OnGetCheckPosition` altere-o para alterar a posição e o tamanho da caixa de seleção dentro do item.

## <a name="cchecklistboxsetcheck"></a><a name="setcheck"></a>CCheckListBox::SetCheck

Define o estado da caixa de seleção especificada.

```cpp
void SetCheck(
    int nIndex,
    int nCheck);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice baseado em zero de uma caixa de seleção que está contido na caixa de lista.

*Ncheck*<br/>
O estado do botão para a caixa de seleção especificada. Consulte a seção Observações para obter possíveis valores.

### <a name="remarks"></a>Comentários

A tabela a seguir lista os possíveis valores para o parâmetro *nCheck.*

|Valor|Descrição|
|-----------|-----------------|
|BST_CHECKED|Selecione a caixa de seleção especificada.|
|Bst_unchecked|Limpe a caixa de seleção especificada.|
|BST_INDETERMINATE|Defina o estado da caixa de seleção especificado como indeterminado.<br /><br /> Este estado só está disponível se o estilo da caixa de seleção estiver BS_AUTO3STATE ou BS_3STATE. Para obter mais informações, consulte [Button Styles](../../mfc/reference/styles-used-by-mfc.md#button-styles).|

## <a name="cchecklistboxsetcheckstyle"></a><a name="setcheckstyle"></a>CCheckListBox::SetCheckStyle

Chame esta função para definir o estilo das caixas de seleção na caixa de seleção.

```cpp
void SetCheckStyle(UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*nStyle*<br/>
Determina o estilo das caixas de seleção na caixa de seleção.

### <a name="remarks"></a>Comentários

Os estilos válidos são:

- Bs_checkbox

- BS_AUTOCHECKBOX

- Bs_auto3state

- Bs_3state

Para obter informações sobre esses estilos, consulte [Estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).

## <a name="see-also"></a>Confira também

[Amostra de MFC TSTCON](../../overview/visual-cpp-samples.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)
