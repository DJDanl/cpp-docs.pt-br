---
title: Classe CMenu
ms.date: 11/04/2016
f1_keywords:
- CMenu
- AFXWIN/CMenu
- AFXWIN/CMenu::CMenu
- AFXWIN/CMenu::AppendMenu
- AFXWIN/CMenu::Attach
- AFXWIN/CMenu::CheckMenuItem
- AFXWIN/CMenu::CheckMenuRadioItem
- AFXWIN/CMenu::CreateMenu
- AFXWIN/CMenu::CreatePopupMenu
- AFXWIN/CMenu::DeleteMenu
- AFXWIN/CMenu::DeleteTempMap
- AFXWIN/CMenu::DestroyMenu
- AFXWIN/CMenu::Detach
- AFXWIN/CMenu::DrawItem
- AFXWIN/CMenu::EnableMenuItem
- AFXWIN/CMenu::FromHandle
- AFXWIN/CMenu::GetDefaultItem
- AFXWIN/CMenu::GetMenuContextHelpId
- AFXWIN/CMenu::GetMenuInfo
- AFXWIN/CMenu::GetMenuItemCount
- AFXWIN/CMenu::GetMenuItemID
- AFXWIN/CMenu::GetMenuItemInfo
- AFXWIN/CMenu::GetMenuState
- AFXWIN/CMenu::GetMenuString
- AFXWIN/CMenu::GetSafeHmenu
- AFXWIN/CMenu::GetSubMenu
- AFXWIN/CMenu::InsertMenu
- AFXWIN/CMenu::InsertMenuItem
- AFXWIN/CMenu::LoadMenu
- AFXWIN/CMenu::LoadMenuIndirect
- AFXWIN/CMenu::MeasureItem
- AFXWIN/CMenu::ModifyMenu
- AFXWIN/CMenu::RemoveMenu
- AFXWIN/CMenu::SetDefaultItem
- AFXWIN/CMenu::SetMenuContextHelpId
- AFXWIN/CMenu::SetMenuInfo
- AFXWIN/CMenu::SetMenuItemBitmaps
- AFXWIN/CMenu::SetMenuItemInfo
- AFXWIN/CMenu::TrackPopupMenu
- AFXWIN/CMenu::TrackPopupMenuEx
- AFXWIN/CMenu::m_hMenu
helpviewer_keywords:
- CMenu [MFC], CMenu
- CMenu [MFC], AppendMenu
- CMenu [MFC], Attach
- CMenu [MFC], CheckMenuItem
- CMenu [MFC], CheckMenuRadioItem
- CMenu [MFC], CreateMenu
- CMenu [MFC], CreatePopupMenu
- CMenu [MFC], DeleteMenu
- CMenu [MFC], DeleteTempMap
- CMenu [MFC], DestroyMenu
- CMenu [MFC], Detach
- CMenu [MFC], DrawItem
- CMenu [MFC], EnableMenuItem
- CMenu [MFC], FromHandle
- CMenu [MFC], GetDefaultItem
- CMenu [MFC], GetMenuContextHelpId
- CMenu [MFC], GetMenuInfo
- CMenu [MFC], GetMenuItemCount
- CMenu [MFC], GetMenuItemID
- CMenu [MFC], GetMenuItemInfo
- CMenu [MFC], GetMenuState
- CMenu [MFC], GetMenuString
- CMenu [MFC], GetSafeHmenu
- CMenu [MFC], GetSubMenu
- CMenu [MFC], InsertMenu
- CMenu [MFC], InsertMenuItem
- CMenu [MFC], LoadMenu
- CMenu [MFC], LoadMenuIndirect
- CMenu [MFC], MeasureItem
- CMenu [MFC], ModifyMenu
- CMenu [MFC], RemoveMenu
- CMenu [MFC], SetDefaultItem
- CMenu [MFC], SetMenuContextHelpId
- CMenu [MFC], SetMenuInfo
- CMenu [MFC], SetMenuItemBitmaps
- CMenu [MFC], SetMenuItemInfo
- CMenu [MFC], TrackPopupMenu
- CMenu [MFC], TrackPopupMenuEx
- CMenu [MFC], m_hMenu
ms.assetid: 40cacfdc-d45c-4ec7-bf28-991c72812499
ms.openlocfilehash: 1cd7be72dc6c9a38fae4f5ccc1a15c184a2d4466
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420802"
---
# <a name="cmenu-class"></a>Classe CMenu

Um encapsulamento do `HMENU`do Windows.

## <a name="syntax"></a>Sintaxe

```
class CMenu : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CMenu::CMenu](#cmenu)|Constrói um objeto `CMenu`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CMenu::AppendMenu](#appendmenu)|Anexa um novo item ao final deste menu.|
|[CMenu:: Attach](#attach)|Anexa um identificador de menu do Windows a um objeto `CMenu`.|
|[CMenu::CheckMenuItem](#checkmenuitem)|Coloca uma marca de seleção ao lado de ou remove uma marca de seleção de um item de menu no menu pop-up.|
|[CMenu::CheckMenuRadioItem](#checkmenuradioitem)|Coloca um botão de opção ao lado de um item de menu e remove o botão de opção de todos os outros itens de menu no grupo.|
|[CMenu:: CreateMenu](#createmenu)|Cria um menu vazio e o anexa a um objeto `CMenu`.|
|[CMenu::CreatePopupMenu](#createpopupmenu)|Cria um menu pop-up vazio e o anexa a um objeto `CMenu`.|
|[CMenu::D eleteMenu](#deletemenu)|Exclui um item especificado do menu. Se o item de menu tiver um menu pop-up associado, destrói o identificador no menu pop-up e libera a memória usada por ele.|
|[CMenu::D eleteTempMap](#deletetempmap)|Exclui todos os objetos de `CMenu` temporários criados pela função de membro `FromHandle`.|
|[CMenu::D estroyMenu](#destroymenu)|Destrói o menu anexado a um objeto `CMenu` e libera qualquer memória ocupada pelo menu.|
|[CMenu::D Etach](#detach)|Desanexa um identificador de menu do Windows de um objeto `CMenu` e retorna o identificador.|
|[CMenu::D rawItem](#drawitem)|Chamado pelo Framework quando um aspecto visual de um menu desenhado pelo proprietário é alterado.|
|[CMenu::EnableMenuItem](#enablemenuitem)|Habilita, desabilita ou esmaece (cinza) um item de menu.|
|[CMenu:: FromHandle](#fromhandle)|Retorna um ponteiro para um objeto `CMenu` dado a um identificador de menu do Windows.|
|[CMenu::GetDefaultItem](#getdefaultitem)|Determina o item de menu padrão no menu especificado.|
|[CMenu::GetMenuContextHelpId](#getmenucontexthelpid)|Recupera a ID de contexto da ajuda associada ao menu.|
|[CMenu::GetMenuInfo](#getmenuinfo)|Recupera informações em um menu específico.|
|[CMenu::GetMenuItemCount](#getmenuitemcount)|Determina o número de itens em um menu pop-up ou de nível superior.|
|[CMenu:: getmenuitemid](#getmenuitemid)|Obtém o identificador de item de menu para um item de menu localizado na posição especificada.|
|[CMenu::GetMenuItemInfo](#getmenuiteminfo)|Recupera informações sobre um item de menu.|
|[CMenu:: GetMenuState](#getmenustate)|Retorna o status do item de menu especificado ou o número de itens em um menu pop-up.|
|[CMenu:: getmenustring](#getmenustring)|Recupera o rótulo do item de menu especificado.|
|[CMenu::GetSafeHmenu](#getsafehmenu)|Retorna o `m_hMenu` encapsulado por este objeto `CMenu`.|
|[CMenu:: GetSubMenu](#getsubmenu)|Recupera um ponteiro para um menu pop-up.|
|[CMenu::InsertMenu](#insertmenu)|Insere um novo item de menu na posição especificada, movendo outros itens para baixo no menu.|
|[CMenu::InsertMenuItem](#insertmenuitem)|Insere um novo item de menu na posição especificada em um menu.|
|[CMenu:: LoadMenu](#loadmenu)|Carrega um recurso de menu do arquivo executável e o anexa a um objeto `CMenu`.|
|[CMenu::LoadMenuIndirect](#loadmenuindirect)|Carrega um menu de um modelo de menu na memória e o anexa a um objeto `CMenu`.|
|[CMenu::MeasureItem](#measureitem)|Chamado pelo Framework para determinar as dimensões do menu quando um menu desenhado pelo proprietário é criado.|
|[CMenu::ModifyMenu](#modifymenu)|Altera um item de menu existente na posição especificada.|
|[CMenu::RemoveMenu](#removemenu)|Exclui um item de menu com um menu pop-up associado do menu especificado.|
|[CMenu::SetDefaultItem](#setdefaultitem)|Define o item de menu padrão para o menu especificado.|
|[CMenu::SetMenuContextHelpId](#setmenucontexthelpid)|Define a ID de contexto da ajuda a ser associada ao menu.|
|[CMenu::SetMenuInfo](#setmenuinfo)|Define informações em um menu específico.|
|[CMenu::SetMenuItemBitmaps](#setmenuitembitmaps)|Associa os bitmaps de marca de seleção especificados a um item de menu.|
|[CMenu::SetMenuItemInfo](#setmenuiteminfo)|Altera informações sobre um item de menu.|
|[CMenu::TrackPopupMenu](#trackpopupmenu)|Exibe um menu pop-up flutuante no local especificado e controla a seleção de itens no menu pop-up.|
|[CMenu::TrackPopupMenuEx](#trackpopupmenuex)|Exibe um menu pop-up flutuante no local especificado e controla a seleção de itens no menu pop-up.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Operador CMenu:: Operator HMENU](#operator_hmenu)|Recupera o identificador do objeto de menu.|
|[CMenu:: Operator! =](#operator_neq)|Determina se dois objetos de menu não são iguais.|
|[CMenu:: Operator = =](#operator_eq_eq)|Determina se dois objetos de menu são iguais.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CMenu:: m_hMenu](#m_hmenu)|Especifica o identificador para o menu do Windows anexado ao objeto `CMenu`.|

## <a name="remarks"></a>Comentários

Ele fornece funções de membro para criar, controlar, atualizar e destruir um menu.

Crie um objeto `CMenu` no registro de ativação como um local e, em seguida, chame as funções de membro do `CMenu`para manipular o novo menu, conforme necessário. Em seguida, chame [CWnd:: SetMenu](../../mfc/reference/cwnd-class.md#setmenu) para definir o menu para uma janela, seguido imediatamente por uma chamada para a função de membro [Detach](#detach) do objeto `CMenu`. A função membro `CWnd::SetMenu` define o menu da janela para o novo menu, faz com que a janela seja redesenhada para refletir a alteração do menu e também passa a propriedade do menu para a janela. A chamada para `Detach` desanexa o HMENU do objeto `CMenu`, de modo que, quando a variável de `CMenu` local passa para fora do escopo, o destruidor de objeto `CMenu` não tenta destruir um menu que não possui mais. O próprio menu é destruído automaticamente quando a janela é destruída.

Você pode usar a função de membro [LoadMenuIndirect](#loadmenuindirect) para criar um menu de um modelo na memória, mas um menu criado a partir de um recurso por uma chamada para [LoadMenu](#loadmenu) é mais fácil de ser mantido e o próprio recurso de menu pode ser criado e modificado pelo editor de menu.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMenu`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="appendmenu"></a>CMenu::AppendMenu

Anexa um novo item ao final de um menu.

```
BOOL AppendMenu(
    UINT nFlags,
    UINT_PTR nIDNewItem = 0,
    LPCTSTR lpszNewItem = NULL);

BOOL AppendMenu(
    UINT nFlags,
    UINT_PTR nIDNewItem,
    const CBitmap* pBmp);
```

### <a name="parameters"></a>parâmetros

*nFlags*<br/>
Especifica informações sobre o estado do novo item de menu quando ele é adicionado ao menu. Ele consiste em um ou mais dos valores listados na seção comentários.

*nIDNewItem*<br/>
Especifica a ID de comando do novo item de menu ou, se *nFlags* for definido como MF_POPUP, o identificador de menu (`HMENU`) de um menu pop-up. O parâmetro *nIDNewItem* será ignorado (não necessário) se *nFlags* for definido como MF_SEPARATOR.

*lpszNewItem*<br/>
Especifica o conteúdo do novo item de menu. O parâmetro *nFlags* é usado para interpretar o *lpszNewItem* da seguinte maneira:

|nFlags|Interpretação de lpszNewItem|
|------------|-----------------------------------|
|MF_OWNERDRAW|Contém um valor de 32 bits fornecido pelo aplicativo que o aplicativo pode usar para manter dados adicionais associados ao item de menu. Esse valor de 32 bits está disponível para o aplicativo quando ele processa WM_MEASUREITEM e WM_DRAWITEM mensagens. O valor é armazenado no membro `itemData` da estrutura fornecida com essas mensagens.|
|MF_STRING|Contém um ponteiro para uma cadeia de caracteres terminada em nulo. Essa é a interpretação padrão.|
|MF_SEPARATOR|O parâmetro *lpszNewItem* é ignorado (não é necessário).|

*pBmp*<br/>
Aponta para um objeto `CBitmap` que será usado como o item de menu.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O aplicativo pode especificar o estado do item de menu definindo valores em *nFlags*. Quando *nIDNewItem* especifica um menu pop-up, ele se torna parte do menu ao qual é anexado. Se esse menu for destruído, o menu anexado também será destruído. Um menu anexado deve ser desanexado de um objeto `CMenu` para evitar conflitos. Observe que MF_STRING e MF_OWNERDRAW não são válidos para a versão de bitmap do `AppendMenu`.

A lista a seguir descreve os sinalizadores que podem ser definidos em *nFlags*:

- MF_CHECKED atua como uma alternância com MF_UNCHECKED para posicionar a marca de seleção padrão ao lado do item. Quando o aplicativo fornece bitmaps de marca de seleção (consulte a função de membro [SetMenuItemBitmaps](#setmenuitembitmaps) ), o bitmap "marca de seleção ativa" é exibido.

- MF_UNCHECKED atua como uma alternância com MF_CHECKED para remover uma marca de seleção ao lado do item. Quando o aplicativo fornece bitmaps de marca de seleção (consulte a função de membro `SetMenuItemBitmaps`), o bitmap "marca de seleção desativado" é exibido.

- MF_DISABLED desabilita o item de menu para que ele não possa ser selecionado, mas não o esmaece.

- MF_ENABLED habilita o item de menu para que possa ser selecionado e restaurado a partir de seu estado esmaecido.

- MF_GRAYED desabilita o item de menu para que ele não possa ser selecionado e esmaecido.

- MF_MENUBARBREAK coloca o item em uma nova linha em menus estáticos ou em uma nova coluna em menus pop-up. A nova coluna de menu pop-up será separada da coluna antiga por uma linha divisória vertical.

- MF_MENUBREAK coloca o item em uma nova linha em menus estáticos ou em uma nova coluna em menus pop-up. Nenhuma linha de divisão é colocada entre as colunas.

- MF_OWNERDRAW especifica que o item é um item de desenho proprietário. Quando o menu é exibido pela primeira vez, a janela que possui o menu recebe uma mensagem de WM_MEASUREITEM, que recupera a altura e a largura do item de menu. A mensagem de WM_DRAWITEM é a enviada sempre que o proprietário deve atualizar a aparência visual do item de menu. Esta opção não é válida para um item de menu de nível superior.

- MF_POPUP especifica que o item de menu tem um menu pop-up associado a ele. O parâmetro ID especifica um identificador para um menu pop-up que deve ser associado ao item. Isso é usado para adicionar um menu pop-up de nível superior ou um menu pop-up hierárquico a um item de menu pop-up.

- MF_SEPARATOR desenha uma linha divisória horizontal. Só pode ser usado em um menu pop-up. Esta linha não pode ser esmaecida, desabilitada ou realçada. Outros parâmetros são ignorados.

- MF_STRING especifica que o item de menu é uma cadeia de caracteres.

Cada um dos grupos a seguir lista os sinalizadores mutuamente exclusivos e não podem ser usados juntos:

- MF_DISABLED, MF_ENABLED e MF_GRAYED

- MF_STRING, MF_OWNERDRAW, MF_SEPARATOR e a versão do bitmap

- MF_MENUBARBREAK e MF_MENUBREAK

- MF_CHECKED e MF_UNCHECKED

Sempre que um menu que reside em uma janela é alterado (quer a janela seja exibida ou não), o aplicativo deve chamar [CWnd::D rawmenubar](../../mfc/reference/cwnd-class.md#drawmenubar).

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CMenu:: CreateMenu](#createmenu).

##  <a name="attach"></a>CMenu:: Attach

Anexa um menu existente do Windows a um objeto `CMenu`.

```
BOOL Attach(HMENU hMenu);
```

### <a name="parameters"></a>parâmetros

*hMenu*<br/>
Especifica um identificador para um menu do Windows.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a operação foi bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função não deve ser chamada se um menu já estiver anexado ao objeto `CMenu`. O identificador de menu é armazenado no membro de dados `m_hMenu`.

Se o menu que você deseja manipular já estiver associado a uma janela, você poderá usar a função [CWnd:: GetMenu](../../mfc/reference/cwnd-class.md#getmenu) para obter um identificador para o menu.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#21](../../mfc/reference/codesnippet/cpp/cmenu-class_1.cpp)]

##  <a name="checkmenuitem"></a>CMenu::CheckMenuItem

Adiciona marcas de seleção a ou remove marcas de seleção de itens de menu no menu pop-up.

```
UINT CheckMenuItem(
    UINT nIDCheckItem,
    UINT nCheck);
```

### <a name="parameters"></a>parâmetros

*nIDCheckItem*<br/>
Especifica o item de menu a ser verificado, conforme determinado pelo *nVerifique*.

*nVerifique*<br/>
Especifica como verificar o item de menu e como determinar a posição do item no menu. O parâmetro *nVerifique* pode ser uma combinação de MF_CHECKED ou MF_UNCHECKED com sinalizadores MF_BYPOSITION ou MF_BYCOMMAND. Esses sinalizadores podem ser combinados usando-se o operador OR. Eles têm os seguintes significados:

- MF_BYCOMMAND especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse é o padrão.

- MF_BYPOSITION especifica que o parâmetro fornece a posição do item de menu existente. O primeiro item está na posição 0.

- MF_CHECKED atua como uma alternância com MF_UNCHECKED para posicionar a marca de seleção padrão ao lado do item.

- MF_UNCHECKED atua como uma alternância com MF_CHECKED para remover uma marca de seleção ao lado do item.

### <a name="return-value"></a>Valor retornado

O estado anterior do item: MF_CHECKED ou MF_UNCHECKED ou 0xFFFFFFFF se o item de menu não existia.

### <a name="remarks"></a>Comentários

O parâmetro *nIDCheckItem* especifica o item a ser modificado.

O parâmetro *nIDCheckItem* pode identificar um item de menu pop-up, bem como um item de menu. Nenhuma etapa especial é necessária para verificar um item de menu pop-up. Itens de menu de nível superior não podem ser verificados. Um item de menu pop-up deve ser verificado pela posição, pois não tem um identificador de item de menu associado a ele.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CMenu:: GetMenuState](#getmenustate).

##  <a name="checkmenuradioitem"></a>CMenu::CheckMenuRadioItem

Verifica um item de menu especificado e o transforma em um item de rádio.

```
BOOL CheckMenuRadioItem(
    UINT nIDFirst,
    UINT nIDLast,
    UINT nIDItem,
    UINT nFlags);
```

### <a name="parameters"></a>parâmetros

*nIDFirst*<br/>
Especifica (como uma ID ou um deslocamento, dependendo do valor de *nFlags*) do primeiro item de menu no grupo de botões de opção.

*nIDLast*<br/>
Especifica (como uma ID ou um deslocamento, dependendo do valor de *nFlags*) o último item de menu no grupo de botões de opção.

*nIDItem*<br/>
Especifica (como uma ID ou um deslocamento, dependendo do valor de *nFlags*) do item no grupo que será verificado com um botão de opção.

*nFlags*<br/>
Especifica a interpretação de *nIDFirst*, *nIDLast*e *nIDItem* da seguinte maneira:

|nFlags|Interpretação|
|------------|--------------------|
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse será o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION estiver definido.|
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. O primeiro item está na posição 0.|

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário 0

### <a name="remarks"></a>Comentários

Ao mesmo tempo, a função desmarca todos os outros itens de menu no grupo associado e limpa o sinalizador de tipo de item de rádio para esses itens. O item selecionado é exibido usando um bitmap de botão de opção (ou marcador) em vez de um bitmap de marca de seleção.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [ON_COMMAND_RANGE](message-map-macros-mfc.md#on_command_range).

##  <a name="cmenu"></a>CMenu::CMenu

Cria um menu vazio e o anexa a um objeto `CMenu`.

```
CMenu();
```

### <a name="remarks"></a>Comentários

O menu não é criado até que você chame uma das funções de membro Create ou Load de `CMenu:`

- [CreateMenu](#createmenu)

- [CreatePopupMenu](#createpopupmenu)

- [LoadMenu](#loadmenu)

- [LoadMenuIndirect](#loadmenuindirect)

- [Anexar](#attach)

##  <a name="createmenu"></a>CMenu:: CreateMenu

Cria um menu e o anexa ao objeto `CMenu`.

```
BOOL CreateMenu();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o menu foi criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Inicialmente, o menu está vazio. Os itens de menu podem ser adicionados usando a função de membro `AppendMenu` ou `InsertMenu`.

Se o menu for atribuído a uma janela, ele será destruído automaticamente quando a janela for destruída.

Antes de sair, um aplicativo deve liberar recursos do sistema associados a um menu se o menu não estiver atribuído a uma janela. Um aplicativo libera um menu chamando a função membro [DestroyMenu](#destroymenu) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#22](../../mfc/reference/codesnippet/cpp/cmenu-class_2.cpp)]

##  <a name="createpopupmenu"></a>CMenu::CreatePopupMenu

Cria um menu pop-up e o anexa ao objeto `CMenu`.

```
BOOL CreatePopupMenu();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o menu pop-up foi criado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Inicialmente, o menu está vazio. Os itens de menu podem ser adicionados usando a função de membro `AppendMenu` ou `InsertMenu`. O aplicativo pode adicionar o menu pop-up a um menu ou menu pop-up existente. A função membro `TrackPopupMenu` pode ser usada para exibir esse menu como um menu pop-up flutuante e para controlar as seleções no menu pop-up.

Se o menu for atribuído a uma janela, ele será destruído automaticamente quando a janela for destruída. Se o menu for adicionado a um menu existente, ele será destruído automaticamente quando esse menu for destruído.

Antes de sair, um aplicativo deve liberar recursos do sistema associados a um menu pop-up se o menu não estiver atribuído a uma janela. Um aplicativo libera um menu chamando a função membro [DestroyMenu](#destroymenu) .

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CMenu:: CreateMenu](#createmenu).

##  <a name="deletemenu"></a>CMenu::D eleteMenu

Exclui um item do menu.

```
BOOL DeleteMenu(
    UINT nPosition,
    UINT nFlags);
```

### <a name="parameters"></a>parâmetros

*nPosição*<br/>
Especifica o item de menu a ser excluído, conforme determinado pelo *nFlags*.

*nFlags*<br/>
É usado para interpretar *nPosição* da seguinte maneira:

|nFlags|Interpretação de nPosição|
|------------|---------------------------------|
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse será o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION estiver definido.|
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. O primeiro item está na posição 0.|

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o item de menu tiver um menu pop-up associado, `DeleteMenu` destrói o identificador no menu pop-up e libera a memória usada pelo menu pop-up.

Sempre que um menu que reside em uma janela é alterado (independentemente de a janela ser exibida), o aplicativo deve chamar [CWnd::D rawmenubar](../../mfc/reference/cwnd-class.md#drawmenubar).

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CWnd:: GetMenu](../../mfc/reference/cwnd-class.md#getmenu).

##  <a name="deletetempmap"></a>CMenu::D eleteTempMap

Chamado automaticamente pelo manipulador `CWinApp` tempo ocioso, exclui qualquer objeto `CMenu` temporário criado pela função membro [FromHandle](#fromhandle) .

```
static void PASCAL DeleteTempMap();
```

### <a name="remarks"></a>Comentários

`DeleteTempMap` desanexa o objeto de menu do Windows anexado a um objeto de `CMenu` temporário antes de excluir o objeto `CMenu`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#23](../../mfc/reference/codesnippet/cpp/cmenu-class_3.cpp)]

##  <a name="destroymenu"></a>CMenu::D estroyMenu

Destrói o menu e todos os recursos do Windows que foram usados.

```
BOOL DestroyMenu();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o menu for destruído; caso contrário, 0.

### <a name="remarks"></a>Comentários

O menu é desanexado do objeto `CMenu` antes de ser destruído. A função de `DestroyMenu` do Windows é chamada automaticamente no destruidor de `CMenu`.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CMenu:: CreateMenu](#createmenu).

##  <a name="detach"></a>CMenu::D Etach

Desanexa um menu do Windows de um objeto `CMenu` e retorna o identificador.

```
HMENU Detach();
```

### <a name="return-value"></a>Valor retornado

O identificador, do tipo HMENU, para um menu do Windows, se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

O membro de dados `m_hMenu` é definido como nulo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#21](../../mfc/reference/codesnippet/cpp/cmenu-class_1.cpp)]

##  <a name="drawitem"></a>CMenu::D rawItem

Chamado pelo Framework quando um aspecto visual de um menu desenhado pelo proprietário é alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

O membro `itemAction` da estrutura de `DRAWITEMSTRUCT` define a ação de desenho a ser executada. Substitua essa função de membro para implementar o desenho de um objeto de `CMenu` de desenho proprietário. O aplicativo deve restaurar todos os objetos da interface de dispositivo de gráficos (GDI) selecionados para o contexto de exibição fornecido em *lpDrawItemStruct* antes do término dessa função de membro.

Consulte [CWnd:: OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição da estrutura de `DRAWITEMSTRUCT`.

### <a name="example"></a>Exemplo

O código a seguir é do exemplo MFC [CTRLTEST](../../overview/visual-cpp-samples.md) :

[!code-cpp[NVC_MFCWindowing#24](../../mfc/reference/codesnippet/cpp/cmenu-class_4.cpp)]

##  <a name="enablemenuitem"></a>CMenu::EnableMenuItem

Habilita, desabilita ou esmaece um item de menu.

```
UINT EnableMenuItem(
    UINT nIDEnableItem,
    UINT nEnable);
```

### <a name="parameters"></a>parâmetros

*nIDEnableItem*<br/>
Especifica o item de menu a ser habilitado, conforme determinado por *nEnable*. Esse parâmetro pode especificar itens de menu pop-up, bem como itens de menu padrão.

*nEnable*<br/>
Especifica a ação a ser tomada. Pode ser uma combinação de MF_DISABLED, MF_ENABLED ou MF_GRAYED, com MF_BYCOMMAND ou MF_BYPOSITION. Esses valores podem ser combinados usando-se o operador OR. Esses valores têm estes significados:

- MF_BYCOMMAND especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse é o padrão.

- MF_BYPOSITION especifica que o parâmetro fornece a posição do item de menu existente. O primeiro item está na posição 0.

- MF_DISABLED desabilita o item de menu para que ele não possa ser selecionado, mas não o esmaece.

- MF_ENABLED habilita o item de menu para que possa ser selecionado e restaurado a partir de seu estado esmaecido.

- MF_GRAYED desabilita o item de menu para que ele não possa ser selecionado e esmaecido.

### <a name="return-value"></a>Valor retornado

Estado anterior (MF_DISABLED, MF_ENABLED ou MF_GRAYED) ou-1 se não for válido.

### <a name="remarks"></a>Comentários

As funções de membro [CreateMenu](#createmenu), [InsertMenu](#insertmenu), [ModifyMenu](#modifymenu)e [LoadMenuIndirect](#loadmenuindirect) também podem definir o estado (habilitado, desabilitado ou esmaecido) de um item de menu.

O uso do valor MF_BYPOSITION requer que um aplicativo use o `CMenu`correto. Se a `CMenu` da barra de menus for usada, um item de menu de nível superior (um item na barra de menus) será afetado. Para definir o estado de um item em um menu pop-up ou pop-up aninhado por posição, um aplicativo deve especificar o `CMenu` do menu pop-up.

Quando um aplicativo especifica o sinalizador de MF_BYCOMMAND, o Windows verifica todos os itens de menu pop-up subordinados à `CMenu`; Portanto, a menos que itens de menu duplicados estejam presentes, usar o `CMenu` da barra de menus é suficiente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#25](../../mfc/reference/codesnippet/cpp/cmenu-class_5.cpp)]

##  <a name="fromhandle"></a>CMenu:: FromHandle

Retorna um ponteiro para um objeto `CMenu` dado um identificador do Windows a um menu.

```
static CMenu* PASCAL FromHandle(HMENU hMenu);
```

### <a name="parameters"></a>parâmetros

*hMenu*<br/>
Um identificador do Windows para um menu.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um `CMenu` que pode ser temporário ou permanente.

### <a name="remarks"></a>Comentários

Se um objeto de `CMenu` ainda não estiver anexado ao objeto de menu do Windows, um objeto de `CMenu` temporário será criado e anexado.

Esse objeto de `CMenu` temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de eventos, quando todos os objetos temporários forem excluídos.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CMenu:: CreateMenu](#createmenu).

##  <a name="getdefaultitem"></a>CMenu::GetDefaultItem

Determina o item de menu padrão no menu especificado.

```
UINT GetDefaultItem(
    UINT gmdiFlags,
    BOOL fByPos = FALSE);
```

### <a name="parameters"></a>parâmetros

*gmdiFlags*<br/>
Valor que especifica como a função procura itens de menu. Esse parâmetro pode ser None, One ou uma combinação dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|GMDI_GOINTOPOPUPS|Especifica que, se o item padrão for um que abre um submenu, a função será Pesquisar no submenu correspondente recursivamente. Se o submenu não tiver nenhum item padrão, o valor de retorno identificará o item que abre o submenu.<br /><br /> Por padrão, a função retorna o primeiro item padrão no menu especificado, independentemente de ser um item que abre um submenu.|
|GMDI_USEDISABLED|Especifica que a função deve retornar um item padrão, mesmo se estiver desabilitada.<br /><br /> Por padrão, a função ignora itens desabilitados ou esmaecidos.|

*fByPos*<br/>
Valor que especifica se o identificador do item de menu ou sua posição deve ser recuperado. Se esse parâmetro for FALSE, o identificador será retornado. Caso contrário, a posição será retornada.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será o identificador ou a posição do item de menu. Se a função falhar, o valor de retorno será-1.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da função [GetMenuDefaultItem](/windows/win32/api/winuser/nf-winuser-getmenudefaultitem)do Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMenu:: InsertMenu](#insertmenu).

##  <a name="getmenucontexthelpid"></a>CMenu::GetMenuContextHelpId

Recupera a ID da ajuda de contexto associada ao `CMenu`.

```
DWORD GetMenuContextHelpId() const;
```

### <a name="return-value"></a>Valor retornado

A ID da ajuda de contexto associada atualmente a `CMenu` se ela tiver uma; caso contrário, zero.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMenu:: InsertMenu](#insertmenu).

##  <a name="getmenuinfo"></a>CMenu::GetMenuInfo

Recupera informações de um menu.

```
BOOL GetMenuInfo(LPMENUINFO lpcmi) const;
```

### <a name="parameters"></a>parâmetros

*lpcmi*<br/>
Um ponteiro para uma estrutura [MENUINFO](/windows/win32/api/winuser/ns-winuser-menuinfo) que contém informações para o menu.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será diferente de zero; caso contrário, o valor de retorno será zero.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar informações sobre o menu.

##  <a name="getmenuitemcount"></a>CMenu::GetMenuItemCount

Determina o número de itens em um menu pop-up ou de nível superior.

```
UINT GetMenuItemCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens no menu se a função for bem-sucedida; caso contrário,-1.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CWnd:: GetMenu](../../mfc/reference/cwnd-class.md#getmenu).

##  <a name="getmenuitemid"></a>CMenu:: getmenuitemid

Obtém o identificador de item de menu para um item de menu localizado na posição definida por *nPos*.

```
UINT GetMenuItemID(int nPos) const;
```

### <a name="parameters"></a>parâmetros

*nPos*<br/>
Especifica a posição (baseada em zero) do item de menu cuja ID está sendo recuperada.

### <a name="return-value"></a>Valor retornado

A ID do item para o item especificado em um menu pop-up se a função for bem-sucedida. Se o item especificado for um menu pop-up (ao contrário de um item dentro do menu pop-up), o valor de retorno será-1. Se *nPos* corresponder a um item de menu separador, o valor de retorno será 0.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMenu:: InsertMenu](#insertmenu).

##  <a name="getmenuiteminfo"></a>CMenu::GetMenuItemInfo

Recupera informações sobre um item de menu.

```
BOOL GetMenuItemInfo(
    UINT uItem,
    LPMENUITEMINFO lpMenuItemInfo,
    BOOL fByPos = FALSE);
```

### <a name="parameters"></a>parâmetros

*uItem*<br/>
Identificador ou posição do item de menu para o qual obter informações. O significado desse parâmetro depende do valor de `ByPos`.

*lpMenuItemInfo*<br/>
Um ponteiro para um [MENUITEMINFO](/windows/win32/api/winuser/ns-winuser-menuiteminfow), conforme descrito na SDK do Windows, que contém informações sobre o menu.

*fByPos*<br/>
Valor que especifica o significado de `nIDItem`. Por padrão, `ByPos` é FALSE, o que indica que uItem é um identificador de item de menu. Se `ByPos` não estiver definido como FALSE, isso indicará uma posição de item de menu.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será diferente de zero. Se a função falhar, o valor retornado será zero. Para obter informações de erro estendidas, use a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), conforme descrito na SDK do Windows.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do da função [GetMenuItemInfo](/windows/win32/api/winuser/nf-winuser-getmenuiteminfow)do Win32, conforme descrito no SDK do Windows. Observe que, na implementação do MFC de `GetMenuItemInfo`, você não usa um identificador para um menu.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#26](../../mfc/reference/codesnippet/cpp/cmenu-class_6.cpp)]

##  <a name="getmenustate"></a>CMenu:: GetMenuState

Retorna o status do item de menu especificado ou o número de itens em um menu pop-up.

```
UINT GetMenuState(
    UINT nID,
    UINT nFlags) const;
```

### <a name="parameters"></a>parâmetros

*nID*<br/>
Especifica a ID do item de menu, conforme determinado por *nFlags*.

*nFlags*<br/>
Especifica a natureza de *NID*. Pode ser um dos seguintes valores:

- MF_BYCOMMAND especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse é o padrão.

- MF_BYPOSITION especifica que o parâmetro fornece a posição do item de menu existente. O primeiro item está na posição 0.

### <a name="return-value"></a>Valor retornado

O valor 0xFFFFFFFF se o item especificado não existir. Se *NID* identificar um menu pop-up, o byte de ordem superior conterá o número de itens no menu pop-up e o byte de ordem inferior conterá os sinalizadores de menu associados ao menu pop-up. Caso contrário, o valor de retorno será uma máscara (booliana ou) dos valores da lista a seguir (essa máscara descreve o status do item de menu que o *NID* identifica):

- MF_CHECKED atua como uma alternância com MF_UNCHECKED para posicionar a marca de seleção padrão ao lado do item. Quando o aplicativo fornece bitmaps de marca de seleção (consulte a função de membro `SetMenuItemBitmaps`), o bitmap "marca de seleção ativa" é exibido.

- MF_DISABLED desabilita o item de menu para que ele não possa ser selecionado, mas não o esmaece.

- MF_ENABLED habilita o item de menu para que possa ser selecionado e restaurado a partir de seu estado esmaecido. Observe que o valor dessa constante é 0; um aplicativo não deve ser testado em relação a 0 para falha ao usar esse valor.

- MF_GRAYED desabilita o item de menu para que ele não possa ser selecionado e esmaecido.

- MF_MENUBARBREAK coloca o item em uma nova linha em menus estáticos ou em uma nova coluna em menus pop-up. A nova coluna de menu pop-up será separada da coluna antiga por uma linha divisória vertical.

- MF_MENUBREAK coloca o item em uma nova linha em menus estáticos ou em uma nova coluna em menus pop-up. Nenhuma linha de divisão é colocada entre as colunas.

- MF_SEPARATOR desenha uma linha divisória horizontal. Só pode ser usado em um menu pop-up. Esta linha não pode ser esmaecida, desabilitada ou realçada. Outros parâmetros são ignorados.

- MF_UNCHECKED atua como uma alternância com MF_CHECKED para remover uma marca de seleção ao lado do item. Quando o aplicativo fornece bitmaps de marca de seleção (consulte a função de membro `SetMenuItemBitmaps`), o bitmap "marca de seleção desativado" é exibido. Observe que o valor dessa constante é 0; um aplicativo não deve ser testado em relação a 0 para falha ao usar esse valor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#27](../../mfc/reference/codesnippet/cpp/cmenu-class_7.cpp)]

##  <a name="getmenustring"></a>CMenu:: getmenustring

Copia o rótulo do item de menu especificado para o buffer especificado.

```
int GetMenuString(
    UINT nIDItem,
    LPTSTR lpString,
    int nMaxCount,
    UINT nFlags) const;

int GetMenuString(
    UINT nIDItem,
    CString& rString,
    UINT nFlags) const;
```

### <a name="parameters"></a>parâmetros

*nIDItem*<br/>
Especifica o identificador inteiro do item de menu ou o deslocamento do item de menu no menu, dependendo do valor de *nFlags*.

*lpStr*<br/>
Aponta para o buffer que deve receber o rótulo.

*rString*<br/>
Uma referência a um objeto `CString` que deve receber a cadeia de caracteres de menu copiada.

*nMaxCount*<br/>
Especifica o comprimento máximo (em caracteres) do rótulo a ser copiado. Se o rótulo for maior do que o máximo especificado em *nMaxCount*, os caracteres extras serão truncados.

*nFlags*<br/>
Especifica a interpretação do parâmetro *nIDItem* . Pode ser um dos seguintes valores:

|nFlags|Interpretação de nIDItem|
|------------|-------------------------------|
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse será o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION estiver definido.|
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. O primeiro item está na posição 0.|

### <a name="return-value"></a>Valor retornado

Especifica o número real de caracteres copiados para o buffer, não incluindo o terminador nulo.

### <a name="remarks"></a>Comentários

O parâmetro *nMaxCount* deve ser um maior que o número de caracteres no rótulo para acomodar o caractere nulo que termina uma cadeia de caracteres.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMenu:: InsertMenu](#insertmenu).

##  <a name="getsafehmenu"></a>CMenu::GetSafeHmenu

Retorna o HMENU encapsulado por este objeto de `CMenu` ou um ponteiro de`CMenu` nulo.

```
HMENU GetSafeHmenu() const;
```

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CMenu:: LoadMenu](#loadmenu).

##  <a name="getsubmenu"></a>CMenu:: GetSubMenu

Recupera o objeto `CMenu` de um menu pop-up.

```
CMenu* GetSubMenu(int nPos) const;
```

### <a name="parameters"></a>parâmetros

*nPos*<br/>
Especifica a posição do menu pop-up contido no menu. Os valores de posição começam em 0 para o primeiro item de menu. O identificador do menu pop-up não pode ser usado nessa função.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CMenu` cujo membro `m_hMenu` contém um identificador para o menu pop-up se existir um menu pop-up na posição especificada; caso contrário, NULL. Se um objeto `CMenu` não existir, será criado um temporário. O ponteiro de `CMenu` retornado não deve ser armazenado.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMenu:: TrackPopupMenu](#trackpopupmenu).

##  <a name="insertmenu"></a>CMenu::InsertMenu

Insere um novo item de menu na posição especificada por *nPosição* e move outros itens para baixo no menu.

```
BOOL InsertMenu(
    UINT nPosition,
    UINT nFlags,
    UINT_PTR nIDNewItem = 0,
    LPCTSTR lpszNewItem = NULL);

BOOL InsertMenu(
    UINT nPosition,
    UINT nFlags,
    UINT_PTR nIDNewItem,
    const CBitmap* pBmp);
```

### <a name="parameters"></a>parâmetros

*nPosição*<br/>
Especifica o item de menu antes do qual o novo item de menu deve ser inserido. O parâmetro *nFlags* pode ser usado para interpretar *nPosição* das seguintes maneiras:

|nFlags|Interpretação de nPosição|
|------------|---------------------------------|
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse será o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION estiver definido.|
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. O primeiro item está na posição 0. Se *nPosição* for-1, o novo item de menu será acrescentado ao final do menu.|

*nFlags*<br/>
Especifica como *nPosição* é interpretado e especifica informações sobre o estado do novo item de menu quando ele é adicionado ao menu. Para obter uma lista dos sinalizadores que podem ser definidos, consulte a função membro [AppendMenu](#appendmenu) . Para especificar mais de um valor, use o operador OR bit a bit para combiná-los com o sinalizador MF_BYCOMMAND ou MF_BYPOSITION.

*nIDNewItem*<br/>
Especifica a ID de comando do novo item de menu ou, se *nFlags* for definido como MF_POPUP, o identificador de menu (HMENU) do menu pop-up. O parâmetro *nIDNewItem* será ignorado (não necessário) se *nFlags* for definido como MF_SEPARATOR.

*lpszNewItem*<br/>
Especifica o conteúdo do novo item de menu. *nFlags* pode ser usado para interpretar *lpszNewItem* das seguintes maneiras:

|nFlags|Interpretação de lpszNewItem|
|------------|-----------------------------------|
|MF_OWNERDRAW|Contém um valor de 32 bits fornecido pelo aplicativo que o aplicativo pode usar para manter dados adicionais associados ao item de menu. Esse valor de 32 bits está disponível para o aplicativo no membro `itemData` da estrutura fornecida pelo [WM_MEASUREITEM](/windows/win32/Controls/wm-measureitem) e [WM_DRAWITEM](/windows/win32/Controls/wm-drawitem) mensagens. Essas mensagens são enviadas quando o item de menu é exibido inicialmente ou é alterado.|
|MF_STRING|Contém um ponteiro longo para uma cadeia de caracteres terminada em nulo. Essa é a interpretação padrão.|
|MF_SEPARATOR|O parâmetro *lpszNewItem* é ignorado (não é necessário).|

*pBmp*<br/>
Aponta para um objeto `CBitmap` que será usado como o item de menu.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O aplicativo pode especificar o estado do item de menu definindo valores em *nFlags*.

Sempre que um menu que reside em uma janela é alterado (quer a janela seja exibida ou não), o aplicativo deve chamar `CWnd::DrawMenuBar`.

Quando *nIDNewItem* especifica um menu pop-up, ele se torna parte do menu em que é inserido. Se esse menu for destruído, o menu inserido também será destruído. Um menu inserido deve ser desanexado de um objeto `CMenu` para evitar conflitos.

Se a janela filho MDI (interface de vários documentos) ativa for maximizada e um aplicativo inserir um menu pop-up no menu do aplicativo MDI chamando essa função e especificando o sinalizador de MF_BYPOSITION, o menu será inserido uma posição mais distante à esquerda do que vista. Isso acontece porque o menu controle da janela filho MDI ativo é inserido na primeira posição da barra de menus da janela do quadro MDI. Para posicionar o menu corretamente, o aplicativo deve adicionar 1 ao valor de posição que, de outra forma, seria usado. Um aplicativo pode usar a WM_MDIGETACTIVE mensagem para determinar se a janela filho ativa no momento está maximizada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#28](../../mfc/reference/codesnippet/cpp/cmenu-class_8.cpp)]

##  <a name="insertmenuitem"></a>CMenu::InsertMenuItem

Insere um novo item de menu na posição especificada em um menu.

```
BOOL InsertMenuItem(
    UINT uItem,
    LPMENUITEMINFO lpMenuItemInfo,
    BOOL fByPos = FALSE);
```

### <a name="parameters"></a>parâmetros

*uItem*<br/>
Consulte a descrição de *uItem* em [InsertMenuItem](/windows/win32/api/winuser/nf-winuser-insertmenuitemw) na SDK do Windows.

*lpMenuItemInfo*<br/>
Consulte a descrição de *lpmii* em `InsertMenuItem` na SDK do Windows.

*fByPos*<br/>
Consulte a descrição de *fByPosition* em `InsertMenuItem` na SDK do Windows.

### <a name="remarks"></a>Comentários

Essa função encapsula [InsertMenuItem](/windows/win32/api/winuser/nf-winuser-insertmenuitemw), descrita na SDK do Windows.

##  <a name="loadmenu"></a>CMenu:: LoadMenu

Carrega um recurso de menu do arquivo executável do aplicativo e o anexa ao objeto `CMenu`.

```
BOOL LoadMenu(LPCTSTR lpszResourceName);
BOOL LoadMenu(UINT nIDResource);
```

### <a name="parameters"></a>parâmetros

*lpszResourceName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso de menu a ser carregado.

*nIDResource*<br/>
Especifica a ID de menu do recurso de menu a ser carregado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o recurso de menu foi carregado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Antes de sair, um aplicativo deve liberar recursos do sistema associados a um menu se o menu não estiver atribuído a uma janela. Um aplicativo libera um menu chamando a função membro [DestroyMenu](#destroymenu) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#29](../../mfc/reference/codesnippet/cpp/cmenu-class_9.cpp)]

##  <a name="loadmenuindirect"></a>CMenu::LoadMenuIndirect

Carrega um recurso de um modelo de menu na memória e o anexa ao objeto `CMenu`.

```
BOOL LoadMenuIndirect(const void* lpMenuTemplate);
```

### <a name="parameters"></a>parâmetros

*lpMenuTemplate*<br/>
Aponta para um modelo de menu (que é uma estrutura [MENUITEMTEMPLATEHEADER](/windows/win32/api/winuser/ns-winuser-menuitemtemplateheader) única e uma coleção de uma ou mais estruturas [MenuItemTemplate](/windows/win32/api/winuser/ns-winuser-menuitemtemplate) ). Para obter mais informações sobre essas duas estruturas, consulte a SDK do Windows.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o recurso de menu foi carregado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um modelo de menu é um cabeçalho seguido por uma coleção de uma ou mais estruturas [MenuItemTemplate](/windows/win32/api/winuser/ns-winuser-menuitemtemplate) , cada uma delas pode conter um ou mais itens de menu e menus pop-up.

O número de versão deve ser 0.

Os sinalizadores de `mtOption` devem incluir MF_END para o último item em uma lista pop-up e para o último item na lista principal. Consulte a função membro `AppendMenu` para outros sinalizadores. O membro `mtId` deve ser omitido da estrutura MENUITEMTEMPLATE quando MF_POPUP é especificado em `mtOption`.

O espaço alocado para a estrutura MENUITEMTEMPLATE deve ser grande o suficiente para que `mtString` contenha o nome do item de menu como uma cadeia de caracteres terminada em nulo.

Antes de sair, um aplicativo deve liberar recursos do sistema associados a um menu se o menu não estiver atribuído a uma janela. Um aplicativo libera um menu chamando a função membro [DestroyMenu](#destroymenu) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#30](../../mfc/reference/codesnippet/cpp/cmenu-class_10.cpp)]

##  <a name="m_hmenu"></a>CMenu:: m_hMenu

Especifica o identificador HMENU do menu do Windows anexado ao objeto `CMenu`.

```
HMENU m_hMenu;
```

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CMenu:: LoadMenu](#loadmenu).

##  <a name="measureitem"></a>CMenu::MeasureItem

Chamado pelo Framework quando um menu com o estilo de desenho proprietário é criado.

```
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```

### <a name="parameters"></a>parâmetros

*lpMeasureItemStruct*<br/>
Um ponteiro para uma estrutura de `MEASUREITEMSTRUCT`.

### <a name="remarks"></a>Comentários

Por padrão, essa função de membro não faz nada. Substitua essa função de membro e preencha a estrutura de `MEASUREITEMSTRUCT` para informar o Windows das dimensões do menu.

Consulte [CWnd:: OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter uma descrição da estrutura de `MEASUREITEMSTRUCT`.

### <a name="example"></a>Exemplo

O código a seguir é do exemplo MFC [CTRLTEST](../../overview/visual-cpp-samples.md) :

[!code-cpp[NVC_MFCWindowing#31](../../mfc/reference/codesnippet/cpp/cmenu-class_11.cpp)]

##  <a name="modifymenu"></a>CMenu::ModifyMenu

Altera um item de menu existente na posição especificada por *nPosição*.

```
BOOL ModifyMenu(
    UINT nPosition,
    UINT nFlags,
    UINT_PTR nIDNewItem = 0,
    LPCTSTR lpszNewItem = NULL);

BOOL ModifyMenu(
    UINT nPosition,
    UINT nFlags,
    UINT_PTR nIDNewItem,
    const CBitmap* pBmp);
```

### <a name="parameters"></a>parâmetros

*nPosição*<br/>
Especifica o item de menu a ser alterado. O parâmetro *nFlags* pode ser usado para interpretar *nPosição* das seguintes maneiras:

|nFlags|Interpretação de nPosição|
|------------|---------------------------------|
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse será o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION estiver definido.|
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. O primeiro item está na posição 0.|

*nFlags*<br/>
Especifica como *nPosição* é interpretado e fornece informações sobre as alterações a serem feitas no item de menu. Para obter uma lista de sinalizadores que podem ser definidos, consulte a função membro [AppendMenu](#appendmenu) .

*nIDNewItem*<br/>
Especifica a ID de comando do item de menu modificado ou, se *nFlags* for definido como MF_POPUP, o identificador de menu (HMENU) de um menu pop-up. O parâmetro *nIDNewItem* será ignorado (não necessário) se *nFlags* for definido como MF_SEPARATOR.

*lpszNewItem*<br/>
Especifica o conteúdo do novo item de menu. O parâmetro *nFlags* pode ser usado para interpretar *lpszNewItem* das seguintes maneiras:

|nFlags|Interpretação de lpszNewItem|
|------------|-----------------------------------|
|MF_OWNERDRAW|Contém um valor de 32 bits fornecido pelo aplicativo que o aplicativo pode usar para manter dados adicionais associados ao item de menu. Esse valor de 32 bits está disponível para o aplicativo quando ele processa MF_MEASUREITEM e MF_DRAWITEM.|
|MF_STRING|Contém um ponteiro longo para uma cadeia de caracteres terminada em nulo ou para um `CString`.|
|MF_SEPARATOR|O parâmetro *lpszNewItem* é ignorado (não é necessário).|

*pBmp*<br/>
Aponta para um objeto `CBitmap` que será usado como o item de menu.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O aplicativo especifica o novo estado do item de menu definindo valores em *nFlags*. Se essa função substituir um menu pop-up associado ao item de menu, ele destruirá o menu pop-up antigo e liberará a memória usada pelo menu pop-up.

Quando *nIDNewItem* especifica um menu pop-up, ele se torna parte do menu em que é inserido. Se esse menu for destruído, o menu inserido também será destruído. Um menu inserido deve ser desanexado de um objeto `CMenu` para evitar conflitos.

Sempre que um menu que reside em uma janela é alterado (quer a janela seja exibida ou não), o aplicativo deve chamar `CWnd::DrawMenuBar`. Para alterar os atributos dos itens de menu existentes, é muito mais rápido usar as funções de membro `CheckMenuItem` e `EnableMenuItem`.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMenu:: InsertMenu](#insertmenu).

##  <a name="operator_hmenu"></a>Operador CMenu:: Operator HMENU

Use esse operador para recuperar o identificador do objeto `CMenu`.

```
operator HMENU() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, o identificador do objeto `CMenu`; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Você pode usar a alça para chamar as APIs do Windows diretamente.

##  <a name="operator_neq"></a>CMenu:: Operator! =

Determina se dois menus são logicamente diferentes.

```
BOOL operator!=(const CMenu& menu) const;
```

### <a name="parameters"></a>parâmetros

*AdicionarMenu*<br/>
Um objeto `CMenu` para comparação.

### <a name="remarks"></a>Comentários

Testa se um objeto de menu no lado esquerdo não é igual a um objeto de menu no lado direito.

##  <a name="operator_eq_eq"></a>CMenu:: Operator = =

Determina se dois menus são logicamente iguais.

```
BOOL operator==(const CMenu& menu) const;
```

### <a name="parameters"></a>parâmetros

*AdicionarMenu*<br/>
Um objeto `CMenu` para comparação.

### <a name="remarks"></a>Comentários

Testa se um objeto de menu no lado esquerdo é igual (em termos do valor HMENU) para um objeto de menu no lado direito.

##  <a name="removemenu"></a>CMenu::RemoveMenu

Exclui um item de menu com um menu pop-up associado do menu.

```
BOOL RemoveMenu(
    UINT nPosition,
    UINT nFlags);
```

### <a name="parameters"></a>parâmetros

*nPosição*<br/>
Especifica o item de menu a ser removido. O parâmetro *nFlags* pode ser usado para interpretar *nPosição* das seguintes maneiras:

|nFlags|Interpretação de nPosição|
|------------|---------------------------------|
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse será o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION estiver definido.|
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. O primeiro item está na posição 0.|

*nFlags*<br/>
Especifica como *nPosição* é interpretado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ele não destrói o identificador de um menu pop-up, portanto, o menu pode ser reutilizado. Antes de chamar essa função, o aplicativo pode chamar a função de membro `GetSubMenu` para recuperar o objeto pop-up `CMenu` para reutilização.

Sempre que um menu que reside em uma janela é alterado (quer a janela seja exibida ou não), o aplicativo deve chamar `CWnd::DrawMenuBar`.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMenu:: InsertMenu](#insertmenu).

##  <a name="setdefaultitem"></a>CMenu::SetDefaultItem

Define o item de menu padrão para o menu especificado.

```
BOOL SetDefaultItem(
    UINT uItem,
    BOOL fByPos = FALSE);
```

### <a name="parameters"></a>parâmetros

*uItem*<br/>
Identificador ou posição do novo item de menu padrão ou-1 para nenhum item padrão. O significado desse parâmetro depende do valor de *fByPos*.

*fByPos*<br/>
Valor que especifica o significado de *uItem*. Se esse parâmetro for FALSE, *uItem* será um identificador de item de menu. Caso contrário, é uma posição de item de menu.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será diferente de zero. Se a função falhar, o valor retornado será zero. Para obter informações de erro estendidas, use a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), conforme descrito na SDK do Windows.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da função [SetMenuDefaultItem](/windows/win32/api/winuser/nf-winuser-setmenudefaultitem)do Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMenu:: InsertMenu](#insertmenu).

##  <a name="setmenucontexthelpid"></a>CMenu::SetMenuContextHelpId

Associa uma ID de ajuda de contexto a `CMenu`.

```
BOOL SetMenuContextHelpId(DWORD dwContextHelpId);
```

### <a name="parameters"></a>parâmetros

*dwContextHelpId*<br/>
ID da ajuda de contexto a ser associada ao `CMenu`.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário 0

### <a name="remarks"></a>Comentários

Todos os itens no menu compartilham esse identificador — não é possível anexar um identificador de contexto de ajuda aos itens de menu individuais.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMenu:: InsertMenu](#insertmenu).

##  <a name="setmenuinfo"></a>CMenu::SetMenuInfo

Define informações para um menu.

```
BOOL SetMenuInfo(LPCMENUINFO lpcmi);
```

### <a name="parameters"></a>parâmetros

*lpcmi*<br/>
Um ponteiro para uma estrutura [MENUINFO](/windows/win32/api/winuser/ns-winuser-menuinfo) que contém informações para o menu.

### <a name="return-value"></a>Valor retornado

Se a função for realizada com sucesso, o valor de retorno será diferente de zero; caso contrário, o valor de retorno será zero.

### <a name="remarks"></a>Comentários

Chame essa função para definir informações específicas sobre o menu.

##  <a name="setmenuitembitmaps"></a>CMenu::SetMenuItemBitmaps

Associa os bitmaps especificados a um item de menu.

```
BOOL SetMenuItemBitmaps(
    UINT nPosition,
    UINT nFlags,
    const CBitmap* pBmpUnchecked,
    const CBitmap* pBmpChecked);
```

### <a name="parameters"></a>parâmetros

*nPosição*<br/>
Especifica o item de menu a ser alterado. O parâmetro *nFlags* pode ser usado para interpretar *nPosição* das seguintes maneiras:

|nFlags|Interpretação de nPosição|
|------------|---------------------------------|
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse será o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION estiver definido.|
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. O primeiro item está na posição 0.|

*nFlags*<br/>
Especifica como *nPosição* é interpretado.

*pBmpUnchecked*<br/>
Especifica o bitmap a ser usado para itens de menu que não são verificados.

*pBmpChecked*<br/>
Especifica o bitmap a ser usado para itens de menu que são verificados.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o item de menu estiver marcado ou desmarcado, o Windows exibirá o bitmap apropriado ao lado do item de menu.

Se *pBmpUnchecked* ou *pBmpChecked* for nulo, o Windows não exibirá nada ao lado do item de menu para o atributo correspondente. Se ambos os parâmetros forem nulos, o Windows usará a marca de seleção padrão quando o item for marcado e removerá a marca de seleção quando o item estiver desmarcado.

Quando o menu é destruído, esses bitmaps não são destruídos; o aplicativo deve destruí-los.

A função `GetMenuCheckMarkDimensions` do Windows recupera as dimensões da marca de seleção padrão usada para itens de menu. O aplicativo usa esses valores para determinar o tamanho apropriado para os bitmaps fornecidos com essa função. Obtenha o tamanho, crie seus bitmaps e, em seguida, defina-os.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#32](../../mfc/reference/codesnippet/cpp/cmenu-class_12.cpp)]

[!code-cpp[NVC_MFCWindowing#33](../../mfc/reference/codesnippet/cpp/cmenu-class_13.cpp)]

##  <a name="setmenuiteminfo"></a>CMenu::SetMenuItemInfo

Altera informações sobre um item de menu.

```
BOOL SetMenuItemInfo(
    UINT uItem,
    LPMENUITEMINFO lpMenuItemInfo,
    BOOL fByPos = FALSE);
```

### <a name="parameters"></a>parâmetros

*uItem*<br/>
Consulte a descrição de *uItem* em [SetMenuItemInfo](/windows/win32/api/winuser/nf-winuser-setmenuiteminfow) na SDK do Windows.

*lpMenuItemInfo*<br/>
Consulte a descrição de *lpmii* em `SetMenuItemInfo` na SDK do Windows.

*fByPos*<br/>
Consulte a descrição de *fByPosition* em `SetMenuItemInfo` na SDK do Windows.

### <a name="remarks"></a>Comentários

Essa função encapsula [SetMenuItemInfo](/windows/win32/api/winuser/nf-winuser-setmenuiteminfow), descrita na SDK do Windows.

##  <a name="trackpopupmenu"></a>CMenu::TrackPopupMenu

Exibe um menu pop-up flutuante no local especificado e controla a seleção de itens no menu pop-up.

```
BOOL TrackPopupMenu(
    UINT nFlags,
    int x,
    int y,
    CWnd* pWnd,
    LPCRECT lpRect = 0);
```

### <a name="parameters"></a>parâmetros

*nFlags*<br/>
Especifica os sinalizadores de posição de tela e de posição do mouse. Consulte [TrackPopupMenu](/windows/win32/api/winuser/nf-winuser-trackpopupmenu) para obter uma lista de sinalizadores disponíveis.

*x*<br/>
Especifica a posição horizontal nas coordenadas de tela do menu pop-up. Dependendo do valor do parâmetro *nFlags* , o menu pode ser alinhado à esquerda, alinhado à direita ou centralizado em relação a essa posição.

*y*<br/>
Especifica a posição vertical nas coordenadas de tela da parte superior do menu na tela.

*pWnd*<br/>
Identifica a janela que possui o menu pop-up. Esse parâmetro não pode ser nulo, mesmo que o sinalizador de TPM_NONOTIFY seja especificado. Esta janela recebe todas as mensagens de WM_COMMAND do menu. No Windows versões 3,1 e posteriores, a janela não recebe WM_COMMAND mensagens até que `TrackPopupMenu` retorne. No Windows 3,0, a janela recebe WM_COMMAND mensagens antes de o `TrackPopupMenu` retornar.

*lpRect*<br/>
Ignorado.

### <a name="return-value"></a>Valor retornado

Esse método retorna o resultado da chamada de [TrackPopupMenu](/windows/win32/api/winuser/nf-winuser-trackpopupmenu) no SDK do Windows.

### <a name="remarks"></a>Comentários

Um menu pop-up flutuante pode aparecer em qualquer lugar na tela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#34](../../mfc/reference/codesnippet/cpp/cmenu-class_14.cpp)]

##  <a name="trackpopupmenuex"></a>CMenu::TrackPopupMenuEx

Exibe um menu pop-up flutuante no local especificado e controla a seleção de itens no menu pop-up.

```
BOOL TrackPopupMenuEx(
    UINT fuFlags,
    int x,
    int y,
    CWnd* pWnd,
    LPTPMPARAMS lptpm);
```

### <a name="parameters"></a>parâmetros

*fuFlags*<br/>
Especifica várias funções para o menu estendido. Para obter uma lista de todos os valores e seu significado, consulte [TrackPopupMenuEx](/windows/win32/api/winuser/nf-winuser-trackpopupmenuex).

*x*<br/>
Especifica a posição horizontal nas coordenadas de tela do menu pop-up.

*y*<br/>
Especifica a posição vertical nas coordenadas de tela da parte superior do menu na tela.

*pWnd*<br/>
Um ponteiro para a janela que possui o menu pop-up e recebe as mensagens do menu criado. Esta janela pode ser qualquer janela do aplicativo atual, mas não pode ser nula. Se você especificar TPM_NONOTIFY no parâmetro *fuFlags* , a função não enviará mensagens para *pWnd*. A função deve retornar para a janela apontada por *pWnd* para receber a mensagem de WM_COMMAND.

*lptpm*<br/>
Ponteiro para uma estrutura [TPMPARAMS](/windows/win32/api/winuser/ns-winuser-tpmparams) que especifica uma área da tela em que o menu não deve se sobrepor. Esse parâmetro pode ser nulo.

### <a name="return-value"></a>Valor retornado

Se você especificar TPM_RETURNCMD no parâmetro *fuFlags* , o valor de retorno será o identificador de menu-item do item selecionado pelo usuário. Se o usuário cancelar o menu sem fazer uma seleção, ou se ocorrer um erro, o valor de retorno será 0.

Se você não especificar TPM_RETURNCMD no parâmetro *fuFlags* , o valor de retorno será diferente de zero se a função for bem-sucedida e 0 se falhar. Para obter informações de erro estendidas, chame [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Um menu pop-up flutuante pode aparecer em qualquer lugar na tela. Para obter mais informações sobre como lidar com erros ao criar o menu pop-up, consulte [TrackPopupMenuEx](/windows/win32/api/winuser/nf-winuser-trackpopupmenuex).

## <a name="see-also"></a>Confira também

[Exemplo de CTRLTEST do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de DYNAMENU do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)
