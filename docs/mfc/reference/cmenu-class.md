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
ms.openlocfilehash: 5ec97d8cf039034078f29b38fb6a41d6ff9a5e53
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369974"
---
# <a name="cmenu-class"></a>Classe CMenu

Um encapsulamento do `HMENU`Windows .

## <a name="syntax"></a>Sintaxe

```
class CMenu : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMenu::CMenu](#cmenu)|Constrói um objeto `CMenu`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMenu::ApêndiceMenu](#appendmenu)|Anexa um novo item ao final deste menu.|
|[CMenu::Anexar](#attach)|Anexa uma alça de `CMenu` menu do Windows a um objeto.|
|[CMenu::CheckMenuItem](#checkmenuitem)|Coloca uma marca de seleção ao lado ou remove uma marca de seleção de um item do menu no menu pop-up.|
|[CMenu::CheckMenuRadioItem](#checkmenuradioitem)|Coloca um botão de rádio ao lado de um item do menu e remove o botão de rádio de todos os outros itens do menu do grupo.|
|[CMenu::Criarmenu](#createmenu)|Cria um menu vazio e `CMenu` o anexa a um objeto.|
|[CMenu::CreatePopupMenu](#createpopupmenu)|Cria um menu pop-up vazio e `CMenu` anexa-o a um objeto.|
|[CMenu::DeleteMenu](#deletemenu)|Exclui um item especificado do menu. Se o item do menu tiver um menu pop-up associado, destrua a alça no menu pop-up e liberte a memória usada por ele.|
|[CMenu::DeleteTempMap](#deletetempmap)|Exclui quaisquer `CMenu` objetos temporários `FromHandle` criados pela função membro.|
|[CMenu::DestroyMenu](#destroymenu)|Destrói o menu anexado `CMenu` a um objeto e libera qualquer memória que o menu ocupasse.|
|[CMenu::Detach](#detach)|Destaca uma alça do menu `CMenu` do Windows de um objeto e devolve a alça.|
|[CMenu::DrawItem](#drawitem)|Chamado pela estrutura quando um aspecto visual de um menu desenhado pelo proprietário muda.|
|[CMenu::AtivarmenuItem](#enablemenuitem)|Habilita, desativa ou escurece (cinzas) um item do menu.|
|[CMenu::FromHandle](#fromhandle)|Retorna um ponteiro `CMenu` para um objeto dado uma alça de menu do Windows.|
|[CMenu::GetDefaultItem](#getdefaultitem)|Determina o item do menu padrão no menu especificado.|
|[CMenu::GetMenuContextHelpId](#getmenucontexthelpid)|Recupera o ID de contexto de ajuda associado ao menu.|
|[CMenu::GetMenuInfo](#getmenuinfo)|Recupera informações em um menu específico.|
|[CMenu::GetMenuItemCount](#getmenuitemcount)|Determina o número de itens em um menu pop-up ou de nível superior.|
|[CMenu::GetMenuItemID](#getmenuitemid)|Obtém o identificador de item do menu para um item do menu localizado na posição especificada.|
|[CMenu::GetMenuItemInfo](#getmenuiteminfo)|Recupera informações sobre um item do menu.|
|[CMenu::GetMenuState](#getmenustate)|Retorna o status do item do menu especificado ou o número de itens em um menu pop-up.|
|[CMenu::GetMenuString](#getmenustring)|Recupera o rótulo do item do menu especificado.|
|[CMenu::GetSafeHmenu](#getsafehmenu)|Devolve `m_hMenu` o embrulhado `CMenu` por este objeto.|
|[CMenu::GetSubMenu](#getsubmenu)|Recupera um ponteiro para um menu pop-up.|
|[CMenu::InserirMenu](#insertmenu)|Insere um novo item do menu na posição especificada, movendo outros itens para baixo do menu.|
|[CMenu::InserirMenuItem](#insertmenuitem)|Insere um novo item do menu na posição especificada em um menu.|
|[CMenu::Menu de carga](#loadmenu)|Carrega um recurso de menu do arquivo executável `CMenu` e anexa-o a um objeto.|
|[CMenu::Menu de cargaIndirectIndirect](#loadmenuindirect)|Carrega um menu de um modelo de menu `CMenu` na memória e anexa-o a um objeto.|
|[CMenu::MeasureItem](#measureitem)|Chamado pela estrutura para determinar as dimensões do menu quando um menu desenhado pelo proprietário é criado.|
|[CMenu::ModifyMenu](#modifymenu)|Altera um item de menu existente na posição especificada.|
|[CMenu::RemoveMenu](#removemenu)|Exclui um item do menu com um menu pop-up associado do menu especificado.|
|[CMenu::SetDefaultItem](#setdefaultitem)|Define o item do menu padrão para o menu especificado.|
|[CMenu::SetMenuMenuContextHelpId](#setmenucontexthelpid)|Define o ID de contexto de ajuda a ser associado ao menu.|
|[CMenu::SetMenuInformações](#setmenuinfo)|Define informações em um menu específico.|
|[CMenu::SetMenuMenuItemBitmaps](#setmenuitembitmaps)|Associa os bitmaps de marca de verificação especificados com um item do menu.|
|[CMenu::SetMenuItemInfo](#setmenuiteminfo)|Altera informações sobre um item do menu.|
|[CMenu::TrackPopupMenu](#trackpopupmenu)|Exibe um menu pop-up flutuante no local especificado e rastreia a seleção de itens no menu pop-up.|
|[CMenu::TrackPopupMenuEx](#trackpopupmenuex)|Exibe um menu pop-up flutuante no local especificado e rastreia a seleção de itens no menu pop-up.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMenu::operador HMENU](#operator_hmenu)|Recupera a alça do objeto do menu.|
|[CMenu::operador !=](#operator_neq)|Determina se dois objetos de menu não são iguais.|
|[CMenu::operador ==](#operator_eq_eq)|Determina se dois objetos de menu são iguais.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMenu::m_hMenu](#m_hmenu)|Especifica a alça para o menu `CMenu` do Windows anexado ao objeto.|

## <a name="remarks"></a>Comentários

Ele fornece funções de membro para criar, rastrear, atualizar e destruir um menu.

Crie `CMenu` um objeto no quadro stack como `CMenu`local e, em seguida, chame as funções do membro para manipular o novo menu conforme necessário. Em seguida, ligue para [CWnd::SetMenu](../../mfc/reference/cwnd-class.md#setmenu) para definir o menu como `CMenu` uma janela, seguido imediatamente por uma chamada para a função de membro [Desapegar](#detach) do objeto. A `CWnd::SetMenu` função membro define o menu da janela para o novo menu, faz com que a janela seja redesenhada para refletir a alteração do menu e também passa a propriedade do menu para a janela. A chamada `Detach` para desprender o `CMenu` HMENU do objeto, `CMenu` de modo que `CMenu` quando a variável local passa fora do escopo, o destruidor de objetos não tenta destruir um menu que ele não possui mais. O menu em si é automaticamente destruído quando a janela é destruída.

Você pode usar a função de membro [LoadMenuIndirect](#loadmenuindirect) para criar um menu a partir de um modelo na memória, mas um menu criado a partir de um recurso por uma chamada para [LoadMenu](#loadmenu) é mais facilmente mantido, e o recurso do menu em si pode ser criado e modificado pelo editor do menu.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CMenu`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cmenuappendmenu"></a><a name="appendmenu"></a>CMenu::ApêndiceMenu

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

### <a name="parameters"></a>Parâmetros

*Nflags*<br/>
Especifica informações sobre o estado do novo item do menu quando ele é adicionado ao menu. Consiste em um ou mais dos valores listados na seção Observações.

*Nidnewitem*<br/>
Especifica o ID de comando do novo item do menu ou, se `HMENU` *nFlags* estiver definido para MF_POPUP, a alça do menu ( ) de um menu pop-up. O parâmetro *nIDNewItem* é ignorado (não necessário) se *nFlags* estiver definido para MF_SEPARATOR.

*lpszNewItem*<br/>
Especifica o conteúdo do novo item do menu. O parâmetro *nFlags* é usado para interpretar *lpszNewItem* da seguinte maneira:

|Nflags|Interpretação de lpszNewItem|
|------------|-----------------------------------|
|Mf_ownerdraw|Contém um valor de 32 bits fornecido pelo aplicativo que o aplicativo pode usar para manter dados adicionais associados ao item do menu. Este valor de 32 bits está disponível para o aplicativo quando ele processa mensagens WM_MEASUREITEM e WM_DRAWITEM. O valor é `itemData` armazenado no membro da estrutura fornecida com essas mensagens.|
|Mf_string|Contém um ponteiro para uma seqüência de seqüência sumida. Esta é a interpretação padrão.|
|Mf_separator|O parâmetro *lpszNewItem* é ignorado (não necessário).|

*pBmp*<br/>
Aponta para `CBitmap` um objeto que será usado como item do menu.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O aplicativo pode especificar o estado do item do menu definindo valores em *nFlags*. Quando *nIDNewItem* especifica um menu pop-up, ele se torna parte do menu ao qual é anexado. Se esse menu for destruído, o menu anexado também será destruído. Um menu anexado deve `CMenu` ser retirado de um objeto para evitar conflitos. Observe que MF_STRING e MF_OWNERDRAW não são `AppendMenu`válidos para a versão bitmap de .

A lista a seguir descreve as bandeiras que podem ser definidas em *nFlags*:

- MF_CHECKED Atua como um alternador com MF_UNCHECKED para colocar a marca de seleção padrão ao lado do item. Quando o aplicativo fornece bitmaps de marca de verificação (consulte a função membro [SetMenuItemBitmaps),](#setmenuitembitmaps) o bitmap "check-mark on" é exibido.

- MF_UNCHECKED Atua como um alternador com MF_CHECKED para remover uma marca de seleção ao lado do item. Quando o aplicativo fornece bitmaps de `SetMenuItemBitmaps` marca de verificação (veja a função do membro), o bitmap "check mark off" é exibido.

- MF_DISABLED Desativa o item do menu para que ele não possa ser selecionado, mas não o escureça.

- MF_ENABLED Habilita o item do menu para que ele possa ser selecionado e restaure-o a partir de seu estado escurecido.

- MF_GRAYED Desativa o item do menu para que ele não possa ser selecionado e o escureça.

- MF_MENUBARBREAK Coloca o item em uma nova linha em menus estáticos ou em uma nova coluna em menus pop-up. A nova coluna de menu pop-up será separada da coluna antiga por uma linha divisória vertical.

- MF_MENUBREAK Coloca o item em uma nova linha em menus estáticos ou em uma nova coluna em menus pop-up. Nenhuma linha divisória é colocada entre as colunas.

- MF_OWNERDRAW Especifica que o item é um item de sorteio do proprietário. Quando o menu é exibido pela primeira vez, a janela que possui o menu recebe uma mensagem WM_MEASUREITEM, que recupera a altura e a largura do item do menu. A mensagem WM_DRAWITEM é a enviada sempre que o proprietário deve atualizar a aparência visual do item do menu. Esta opção não é válida para um item de menu de nível superior.

- MF_POPUP Especifica que o item do menu tem um menu pop-up associado a ele. O parâmetro ID especifica uma alça para um menu pop-up que deve ser associada ao item. Isso é usado para adicionar um menu pop-up de alto nível ou um menu pop-up hierárquico a um item do menu pop-up.

- MF_SEPARATOR desenha uma linha divisória horizontal. Só pode ser usado em um menu pop-up. Esta linha não pode ser escurecida, desativada ou destacada. Outros parâmetros são ignorados.

- MF_STRING Especifica que o item do menu é uma seqüência de caracteres.

Cada um dos seguintes grupos lista bandeiras que são mutuamente exclusivas e não podem ser usadas juntas:

- MF_DISABLED, MF_ENABLED e MF_GRAYED

- MF_STRING, MF_OWNERDRAW, MF_SEPARATOR e a versão bitmap

- MF_MENUBARBREAK e MF_MENUBREAK

- MF_CHECKED e MF_UNCHECKED

Sempre que um menu que reside em uma janela é alterado (se a janela é ou não exibida), o aplicativo deve chamar [CWnd::DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar).

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::CreateMenu](#createmenu).

## <a name="cmenuattach"></a><a name="attach"></a>CMenu::Anexar

Anexa um menu do Windows `CMenu` existente a um objeto.

```
BOOL Attach(HMENU hMenu);
```

### <a name="parameters"></a>Parâmetros

*Hmenu*<br/>
Especifica uma alça para um menu do Windows.

### <a name="return-value"></a>Valor retornado

Não zero se a operação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função não deve ser chamada se um `CMenu` menu já estiver conectado ao objeto. A alça do menu `m_hMenu` é armazenada no membro de dados.

Se o menu que você deseja manipular já estiver associado a uma janela, você poderá usar a função [CWnd::GetMenu](../../mfc/reference/cwnd-class.md#getmenu) para obter uma alça no menu.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#21](../../mfc/reference/codesnippet/cpp/cmenu-class_1.cpp)]

## <a name="cmenucheckmenuitem"></a><a name="checkmenuitem"></a>CMenu::CheckMenuItem

Adiciona marcas de verificação ou remove marcas de verificação de itens do menu no menu pop-up.

```
UINT CheckMenuItem(
    UINT nIDCheckItem,
    UINT nCheck);
```

### <a name="parameters"></a>Parâmetros

*Nidcheckitem*<br/>
Especifica o item do menu a ser verificado, conforme determinado por *nCheck*.

*Ncheck*<br/>
Especifica como verificar o item do menu e como determinar a posição do item no menu. O parâmetro *nCheck* pode ser uma combinação de MF_CHECKED ou MF_UNCHECKED com bandeiras de MF_BYPOSITION ou MF_BYCOMMAND. Esses sinalizadores podem ser combinados usando o operador bitwise OR. Eles têm os seguintes significados:

- MF_BYCOMMAND Especifica que o parâmetro fornece o ID de comando do item do menu existente. Esse é o padrão.

- MF_BYPOSITION Especifica que o parâmetro dá a posição do item do menu existente. O primeiro item está na posição 0.

- MF_CHECKED Atua como um alternador com MF_UNCHECKED para colocar a marca de seleção padrão ao lado do item.

- MF_UNCHECKED Atua como um alternador com MF_CHECKED para remover uma marca de seleção ao lado do item.

### <a name="return-value"></a>Valor retornado

O estado anterior do item: MF_CHECKED ou MF_UNCHECKED, ou 0xFFFFFFFF se o item do menu não existisse.

### <a name="remarks"></a>Comentários

O parâmetro *nIDCheckItem* especifica o item a ser modificado.

O parâmetro *nIDCheckItem* pode identificar um item do menu pop-up, bem como um item do menu. Não são necessários passos especiais para verificar um item do menu pop-up. Os itens de menu de nível superior não podem ser verificados. Um item do menu pop-up deve ser verificado por posição, uma vez que não possui um identificador de item de menu associado a ele.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::GetMenuState](#getmenustate).

## <a name="cmenucheckmenuradioitem"></a><a name="checkmenuradioitem"></a>CMenu::CheckMenuRadioItem

Verifica um item de menu especificado e torna-o um item de rádio.

```
BOOL CheckMenuRadioItem(
    UINT nIDFirst,
    UINT nIDLast,
    UINT nIDItem,
    UINT nFlags);
```

### <a name="parameters"></a>Parâmetros

*nIDFirst*<br/>
Especifica (como um ID ou offset, dependendo do valor de *nFlags*) o primeiro item do menu no grupo de botões de rádio.

*nIDLast*<br/>
Especifica (como um ID ou offset, dependendo do valor de *nFlags*) o último item do menu no grupo de botões de rádio.

*Niditem*<br/>
Especifica (como um ID ou offset, dependendo do valor de *nFlags*) o item no grupo que será verificado com um botão de rádio.

*Nflags*<br/>
Especifica a interpretação de *nIDFirst,* *nIDLast*e *nIDItem* da seguinte maneira:

|Nflags|Interpretação|
|------------|--------------------|
|Mf_bycommand|Especifica que o parâmetro fornece o id de comando do item do menu existente. Este é o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION for definido.|
|Mf_byposition|Especifica que o parâmetro dá a posição do item do menu existente. O primeiro item está na posição 0.|

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário 0

### <a name="remarks"></a>Comentários

Ao mesmo tempo, a função desverifica todos os outros itens do menu no grupo associado e limpa o sinalizador do tipo de item de rádio para esses itens. O item verificado é exibido usando um bitmap de botão de rádio (ou bala) em vez de um bitmap de marca de seleção.

### <a name="example"></a>Exemplo

  Veja o exemplo [de ON_COMMAND_RANGE](message-map-macros-mfc.md#on_command_range).

## <a name="cmenucmenu"></a><a name="cmenu"></a>CMenu::CMenu

Cria um menu vazio e `CMenu` o anexa a um objeto.

```
CMenu();
```

### <a name="remarks"></a>Comentários

O menu não é criado até que você chame uma das funções de criar ou carregar membros de`CMenu:`

- [Createmenu](#createmenu)

- [Createpopupmenu](#createpopupmenu)

- [Menu de carga](#loadmenu)

- [Menude cargaindireto](#loadmenuindirect)

- [Attach](#attach)

## <a name="cmenucreatemenu"></a><a name="createmenu"></a>CMenu::Criarmenu

Cria um menu e o `CMenu` anexa ao objeto.

```
BOOL CreateMenu();
```

### <a name="return-value"></a>Valor retornado

Não zero se o menu foi criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

O menu está inicialmente vazio. Os itens do menu podem `AppendMenu` ser `InsertMenu` adicionados usando a função ou membro.

Se o menu for atribuído a uma janela, ele será automaticamente destruído quando a janela for destruída.

Antes de sair, um aplicativo deve liberar os recursos do sistema associados a um menu se o menu não for atribuído a uma janela. Um aplicativo libera um menu chamando a função de membro [DestroyMenu.](#destroymenu)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#22](../../mfc/reference/codesnippet/cpp/cmenu-class_2.cpp)]

## <a name="cmenucreatepopupmenu"></a><a name="createpopupmenu"></a>CMenu::CreatePopupMenu

Cria um menu pop-up e `CMenu` anexa-o ao objeto.

```
BOOL CreatePopupMenu();
```

### <a name="return-value"></a>Valor retornado

Não zero se o menu pop-up foi criado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

O menu está inicialmente vazio. Os itens do menu podem `AppendMenu` ser `InsertMenu` adicionados usando a função ou membro. O aplicativo pode adicionar o menu pop-up a um menu existente ou menu pop-up. A `TrackPopupMenu` função de membro pode ser usada para exibir este menu como um menu pop-up flutuante e para rastrear seleções no menu pop-up.

Se o menu for atribuído a uma janela, ele será automaticamente destruído quando a janela for destruída. Se o menu for adicionado a um menu existente, ele será automaticamente destruído quando esse menu for destruído.

Antes de sair, um aplicativo deve liberar os recursos do sistema associados a um menu pop-up se o menu não for atribuído a uma janela. Um aplicativo libera um menu chamando a função de membro [DestroyMenu.](#destroymenu)

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::CreateMenu](#createmenu).

## <a name="cmenudeletemenu"></a><a name="deletemenu"></a>CMenu::DeleteMenu

Exclui um item do menu.

```
BOOL DeleteMenu(
    UINT nPosition,
    UINT nFlags);
```

### <a name="parameters"></a>Parâmetros

*Nposition*<br/>
Especifica o item do menu a ser excluído, conforme determinado por *nFlags*.

*Nflags*<br/>
É usado para interpretar *nPosição* da seguinte maneira:

|Nflags|Interpretação de nPosição|
|------------|---------------------------------|
|Mf_bycommand|Especifica que o parâmetro fornece o id de comando do item do menu existente. Este é o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION for definido.|
|Mf_byposition|Especifica que o parâmetro dá a posição do item do menu existente. O primeiro item está na posição 0.|

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o item do menu tiver `DeleteMenu` um menu pop-up associado, destrua a alça no menu pop-up e liberte a memória usada pelo menu pop-up.

Sempre que um menu que reside em uma janela é alterado (se a janela é ou não exibida), o aplicativo deve chamar [CWnd::DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar).

### <a name="example"></a>Exemplo

  Veja o exemplo [de CWnd::GetMenu](../../mfc/reference/cwnd-class.md#getmenu).

## <a name="cmenudeletetempmap"></a><a name="deletetempmap"></a>CMenu::DeleteTempMap

Chamado automaticamente pelo `CWinApp` manipulador de tempo ocioso, exclui quaisquer objetos temporários `CMenu` criados pela função de membro [FromHandle.](#fromhandle)

```
static void PASCAL DeleteTempMap();
```

### <a name="remarks"></a>Comentários

`DeleteTempMap`destaca o objeto do menu do `CMenu` Windows anexado `CMenu` a um objeto temporário antes de excluir o objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#23](../../mfc/reference/codesnippet/cpp/cmenu-class_3.cpp)]

## <a name="cmenudestroymenu"></a><a name="destroymenu"></a>CMenu::DestroyMenu

Destrói o menu e todos os recursos do Windows que foram usados.

```
BOOL DestroyMenu();
```

### <a name="return-value"></a>Valor retornado

Não zero se o menu for destruído; caso contrário, 0.

### <a name="remarks"></a>Comentários

O menu é `CMenu` separado do objeto antes de ser destruído. A `DestroyMenu` função Windows é automaticamente `CMenu` chamada no destruidor.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::CreateMenu](#createmenu).

## <a name="cmenudetach"></a><a name="detach"></a>CMenu::Detach

Destaca um menu do `CMenu` Windows de um objeto e devolve a alça.

```
HMENU Detach();
```

### <a name="return-value"></a>Valor retornado

A alça, do tipo HMENU, para um menu do Windows, se for bem sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

O `m_hMenu` membro de dados está definido como NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#21](../../mfc/reference/codesnippet/cpp/cmenu-class_1.cpp)]

## <a name="cmenudrawitem"></a><a name="drawitem"></a>CMenu::DrawItem

Chamado pela estrutura quando um aspecto visual de um menu desenhado pelo proprietário muda.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*Lpdrawitemstruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

O `itemAction` membro `DRAWITEMSTRUCT` da estrutura define a ação de desenho a ser realizada. Substituir esta função de membro para implementar `CMenu` o desenho para um objeto de desenho do proprietário. O aplicativo deve restaurar todos os objetos GDI (Graphics Device Interface, interface de dispositivo gráfico) selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes do término desta função de membro.

Consulte [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter `DRAWITEMSTRUCT` uma descrição da estrutura.

### <a name="example"></a>Exemplo

O código a seguir é da amostra MFC [CTRLTEST:](../../overview/visual-cpp-samples.md)

[!code-cpp[NVC_MFCWindowing#24](../../mfc/reference/codesnippet/cpp/cmenu-class_4.cpp)]

## <a name="cmenuenablemenuitem"></a><a name="enablemenuitem"></a>CMenu::AtivarmenuItem

Ativa, desativa ou diminui um item do menu.

```
UINT EnableMenuItem(
    UINT nIDEnableItem,
    UINT nEnable);
```

### <a name="parameters"></a>Parâmetros

*nIDEnableItem*<br/>
Especifica o item do menu a ser ativado, conforme determinado por *nEnable*. Este parâmetro pode especificar itens do menu pop-up, bem como itens de menu padrão.

*nEnable*<br/>
Especifica a ação a ser tomada. Pode ser uma combinação de MF_DISABLED, MF_ENABLED ou MF_GRAYED, com MF_BYCOMMAND ou MF_BYPOSITION. Esses valores podem ser combinados usando o operador bitwise OR. Esses valores têm estes significados:

- MF_BYCOMMAND Especifica que o parâmetro fornece o ID de comando do item do menu existente. Esse é o padrão.

- MF_BYPOSITION Especifica que o parâmetro dá a posição do item do menu existente. O primeiro item está na posição 0.

- MF_DISABLED Desativa o item do menu para que ele não possa ser selecionado, mas não o escureça.

- MF_ENABLED Habilita o item do menu para que ele possa ser selecionado e restaure-o a partir de seu estado escurecido.

- MF_GRAYED Desativa o item do menu para que ele não possa ser selecionado e o escureça.

### <a name="return-value"></a>Valor retornado

Estado anterior (MF_DISABLED, MF_ENABLED ou MF_GRAYED) ou -1, se não for válido.

### <a name="remarks"></a>Comentários

As funções [De CriarMenu,](#createmenu) [InsertMenu,](#insertmenu) [ModifyMenu](#modifymenu)e [LoadMenuIndirect](#loadmenuindirect) também podem definir o estado (ativado, desativado ou escurecido) de um item do menu.

Usar o valor MF_BYPOSITION requer um `CMenu`aplicativo para usar o correto . Se `CMenu` a barra de menu for usada, um item de menu de nível superior (um item na barra de menu) será afetado. Para definir o estado de um item em um menu pop-up pop-up `CMenu` ou aninhado por posição, um aplicativo deve especificar o menu pop-up.

Quando um aplicativo especifica o MF_BYCOMMAND flag, o Windows verifica todos os `CMenu`itens do menu pop-up que estão subordinados ao ; portanto, a menos que os itens de `CMenu` menu duplicados estejam presentes, usar a barra de menu é suficiente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#25](../../mfc/reference/codesnippet/cpp/cmenu-class_5.cpp)]

## <a name="cmenufromhandle"></a><a name="fromhandle"></a>CMenu::FromHandle

Retorna um ponteiro `CMenu` para um objeto dado uma alça do Windows a um menu.

```
static CMenu* PASCAL FromHandle(HMENU hMenu);
```

### <a name="parameters"></a>Parâmetros

*Hmenu*<br/>
Uma alça do Windows para um menu.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CMenu` para um que pode ser temporário ou permanente.

### <a name="remarks"></a>Comentários

Se `CMenu` um objeto ainda não estiver conectado ao `CMenu` objeto do menu do Windows, um objeto temporário será criado e anexado.

Este `CMenu` objeto temporário só é válido até a próxima vez que o aplicativo tiver tempo ocioso em seu loop de evento, momento em que todos os objetos temporários são excluídos.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::CreateMenu](#createmenu).

## <a name="cmenugetdefaultitem"></a><a name="getdefaultitem"></a>CMenu::GetDefaultItem

Determina o item do menu padrão no menu especificado.

```
UINT GetDefaultItem(
    UINT gmdiFlags,
    BOOL fByPos = FALSE);
```

### <a name="parameters"></a>Parâmetros

*gmdiFlags*<br/>
Valor especificando como a função pesquisa itens do menu. Este parâmetro pode ser nenhum, um ou uma combinação dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|GMDI_GOINTOPOPUPS|Especifica que, se o item padrão for aquele que abre um submenu, a função é pesquisar no submenu correspondente recursivamente. Se o submenu não tiver um item padrão, o valor de retorno identificará o item que abre o submenu.<br /><br /> Por padrão, a função retorna o primeiro item padrão no menu especificado, independentemente de ser um item que abre um submenu.|
|GMDI_USEDISABLED|Especifica que a função é retornar um item padrão, mesmo que esteja desativado.<br /><br /> Por padrão, a função ignora itens desativados ou cinzas.|

*fByPos*<br/>
Valor especificando se deve recuperar o identificador do item do menu ou sua posição. Se este parâmetro for FALSO, o identificador será devolvido. Caso contrário, a posição é devolvida.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno será o identificador ou a posição do item do menu. Se a função falhar, o valor de retorno é - 1.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da função Win32 [GetMenuDefaultItem](/windows/win32/api/winuser/nf-winuser-getmenudefaultitem), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).

## <a name="cmenugetmenucontexthelpid"></a><a name="getmenucontexthelpid"></a>CMenu::GetMenuContextHelpId

Recupera o iD de `CMenu`ajuda de contexto associado a .

```
DWORD GetMenuContextHelpId() const;
```

### <a name="return-value"></a>Valor retornado

O contexto ajuda a ID atualmente associado a `CMenu` se ele tem um; zero de outra forma.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).

## <a name="cmenugetmenuinfo"></a><a name="getmenuinfo"></a>CMenu::GetMenuInfo

Recupera informações para um menu.

```
BOOL GetMenuInfo(LPMENUINFO lpcmi) const;
```

### <a name="parameters"></a>Parâmetros

*Lpcmi*<br/>
Um ponteiro para uma estrutura [MENUINFO](/windows/win32/api/winuser/ns-winuser-menuinfo) contendo informações para o menu.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno não será zero; caso contrário, o valor de retorno é zero.

### <a name="remarks"></a>Comentários

Ligue para esta função para recuperar informações sobre o menu.

## <a name="cmenugetmenuitemcount"></a><a name="getmenuitemcount"></a>CMenu::GetMenuItemCount

Determina o número de itens em um menu pop-up ou de nível superior.

```
UINT GetMenuItemCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens no menu se a função for bem sucedida; caso contrário -1.

### <a name="example"></a>Exemplo

  Veja o exemplo [de CWnd::GetMenu](../../mfc/reference/cwnd-class.md#getmenu).

## <a name="cmenugetmenuitemid"></a><a name="getmenuitemid"></a>CMenu::GetMenuItemID

Obtém o identificador de item de menu para um item de menu localizado na posição definida pelos *nPos*.

```
UINT GetMenuItemID(int nPos) const;
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
Especifica a posição (baseada em zero) do item do menu cujo ID está sendo recuperado.

### <a name="return-value"></a>Valor retornado

O id do item para o item especificado em um menu pop-up se a função for bem sucedida. Se o item especificado for um menu pop-up (ao contrário de um item dentro do menu pop-up), o valor de retorno será de -1. Se *os nPos* corresponderem a um item do menu SEPARATOR, o valor de retorno será 0.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).

## <a name="cmenugetmenuiteminfo"></a><a name="getmenuiteminfo"></a>CMenu::GetMenuItemInfo

Recupera informações sobre um item do menu.

```
BOOL GetMenuItemInfo(
    UINT uItem,
    LPMENUITEMINFO lpMenuItemInfo,
    BOOL fByPos = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Uitem*<br/>
Identificador ou posição do item do menu para obter informações sobre. O significado deste parâmetro depende do `ByPos`valor de .

*lpMenuItemInfo*<br/>
Um ponteiro para um [MENUITEMINFO](/windows/win32/api/winuser/ns-winuser-menuiteminfow), conforme descrito no Windows SDK, que contém informações sobre o menu.

*fByPos*<br/>
Valor especificando o `nIDItem`significado de . Por padrão, `ByPos` é FALSE, o que indica que uItem é um identificador de item do menu. Se `ByPos` não estiver definido como FALSO, ele indicará uma posição do item do menu.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno não será zero. Se a função falhar, o valor retornado será zero. Para obter informações de erro estendidas, use a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), conforme descrito no SDK do Windows.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da função Win32 [GetMenuItemInfo](/windows/win32/api/winuser/nf-winuser-getmenuiteminfow), conforme descrito no SDK do Windows. Observe que na implementação `GetMenuItemInfo`do MFC de , você não usa uma alça para um menu.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#26](../../mfc/reference/codesnippet/cpp/cmenu-class_6.cpp)]

## <a name="cmenugetmenustate"></a><a name="getmenustate"></a>CMenu::GetMenuState

Retorna o status do item do menu especificado ou o número de itens em um menu pop-up.

```
UINT GetMenuState(
    UINT nID,
    UINT nFlags) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Especifica o id do item do menu, conforme determinado por *nFlags*.

*Nflags*<br/>
Especifica a natureza do *nID*. Pode ser um dos seguintes valores:

- MF_BYCOMMAND Especifica que o parâmetro fornece o ID de comando do item do menu existente. Esse é o padrão.

- MF_BYPOSITION Especifica que o parâmetro dá a posição do item do menu existente. O primeiro item está na posição 0.

### <a name="return-value"></a>Valor retornado

O valor 0xFFFFFFFF se o item especificado não existir. Se *nId* identificar um menu pop-up, o byte de alta ordem contém o número de itens no menu pop-up e o byte de baixa ordem contém as bandeiras do menu associadas ao menu pop-up. Caso contrário, o valor de retorno é uma máscara (Boolean OR) dos valores da lista a seguir (esta máscara descreve o status do item do menu que *nId* identifica):

- MF_CHECKED Atua como um alternador com MF_UNCHECKED para colocar a marca de seleção padrão ao lado do item. Quando o aplicativo fornece bitmaps de `SetMenuItemBitmaps` marca de verificação (veja a função do membro), o bitmap "check-mark on" é exibido.

- MF_DISABLED Desativa o item do menu para que ele não possa ser selecionado, mas não o escureça.

- MF_ENABLED Habilita o item do menu para que ele possa ser selecionado e restaure-o a partir de seu estado escurecido. Note que o valor desta constante é 0; um aplicativo não deve testar contra 0 para falha ao usar este valor.

- MF_GRAYED Desativa o item do menu para que ele não possa ser selecionado e o escureça.

- MF_MENUBARBREAK Coloca o item em uma nova linha em menus estáticos ou em uma nova coluna em menus pop-up. A nova coluna de menu pop-up será separada da coluna antiga por uma linha divisória vertical.

- MF_MENUBREAK Coloca o item em uma nova linha em menus estáticos ou em uma nova coluna em menus pop-up. Nenhuma linha divisória é colocada entre as colunas.

- MF_SEPARATOR desenha uma linha divisória horizontal. Só pode ser usado em um menu pop-up. Esta linha não pode ser escurecida, desativada ou destacada. Outros parâmetros são ignorados.

- MF_UNCHECKED Atua como um alternador com MF_CHECKED para remover uma marca de seleção ao lado do item. Quando o aplicativo fornece bitmaps de `SetMenuItemBitmaps` marca de verificação (veja a função do membro), o bitmap "check mark off" é exibido. Note que o valor desta constante é 0; um aplicativo não deve testar contra 0 para falha ao usar este valor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#27](../../mfc/reference/codesnippet/cpp/cmenu-class_7.cpp)]

## <a name="cmenugetmenustring"></a><a name="getmenustring"></a>CMenu::GetMenuString

Copia o rótulo do item do menu especificado para o buffer especificado.

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

### <a name="parameters"></a>Parâmetros

*Niditem*<br/>
Especifica o identificador inteiro do item do menu ou a compensação do item do menu no menu, dependendo do valor de *nFlags*.

*Lpstring*<br/>
Aponta para o buffer que deve receber o rótulo.

*rString*<br/>
Uma referência `CString` a um objeto que deve receber a seqüência de menus copiado.

*Nmaxcount*<br/>
Especifica o comprimento máximo (em caracteres) do rótulo a ser copiado. Se o rótulo for maior do que o máximo especificado no *nMaxCount,* os caracteres extras serão truncados.

*Nflags*<br/>
Especifica a interpretação do parâmetro *nIDItem.* Pode ser um dos seguintes valores:

|Nflags|Interpretação do nIDItem|
|------------|-------------------------------|
|Mf_bycommand|Especifica que o parâmetro fornece o id de comando do item do menu existente. Este é o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION for definido.|
|Mf_byposition|Especifica que o parâmetro dá a posição do item do menu existente. O primeiro item está na posição 0.|

### <a name="return-value"></a>Valor retornado

Especifica o número real de caracteres copiados para o buffer, sem incluir o exterminador nulo.

### <a name="remarks"></a>Comentários

O parâmetro *nMaxCount* deve ser maior do que o número de caracteres no rótulo para acomodar o caractere nulo que termina uma string.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).

## <a name="cmenugetsafehmenu"></a><a name="getsafehmenu"></a>CMenu::GetSafeHmenu

Retorna o HMENU `CMenu` embrulhado por este`CMenu` objeto, ou um ponteiro NULL.

```
HMENU GetSafeHmenu() const;
```

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::Menu de carga](#loadmenu).

## <a name="cmenugetsubmenu"></a><a name="getsubmenu"></a>CMenu::GetSubMenu

Recupera o `CMenu` objeto de um menu pop-up.

```
CMenu* GetSubMenu(int nPos) const;
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
Especifica a posição do menu pop-up contido no menu. Os valores de posição começam em 0 para o primeiro item do menu. O identificador do menu pop-up não pode ser usado nesta função.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CMenu` para `m_hMenu` um objeto cujo membro contém uma alça para o menu pop-up se existir um menu pop-up na posição dada; caso contrário, NULL. Se `CMenu` um objeto não existe, então um temporário é criado. O `CMenu` ponteiro devolvido não deve ser armazenado.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::TrackPopupMenu](#trackpopupmenu).

## <a name="cmenuinsertmenu"></a><a name="insertmenu"></a>CMenu::InserirMenu

Insere um novo item do menu na posição especificada por *nPosition* e move outros itens para baixo do menu.

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

### <a name="parameters"></a>Parâmetros

*Nposition*<br/>
Especifica o item do menu antes do qual o novo item do menu deve ser inserido. O parâmetro *nFlags* pode ser usado para interpretar *nPosição* das seguintes maneiras:

|Nflags|Interpretação de nPosição|
|------------|---------------------------------|
|Mf_bycommand|Especifica que o parâmetro fornece o id de comando do item do menu existente. Este é o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION for definido.|
|Mf_byposition|Especifica que o parâmetro dá a posição do item do menu existente. O primeiro item está na posição 0. Se *nPosição* for -1, o novo item do menu será anexado ao final do menu.|

*Nflags*<br/>
Especifica como *o nPosition* é interpretado e especifica informações sobre o estado do novo item do menu quando ele é adicionado ao menu. Para obter uma lista das bandeiras que podem ser definidas, consulte a função membro [AppendMenu.](#appendmenu) Para especificar mais de um valor, use o operador bitwise OR para combiná-los com a bandeira MF_BYCOMMAND ou MF_BYPOSITION.

*Nidnewitem*<br/>
Especifica o ID de comando do novo item do menu ou, se *nFlags* estiver definido para MF_POPUP, a alça do menu (HMENU) do menu pop-up. O parâmetro *nIDNewItem* é ignorado (não necessário) se *nFlags* estiver definido para MF_SEPARATOR.

*lpszNewItem*<br/>
Especifica o conteúdo do novo item do menu. *nFlags* podem ser usados para interpretar *lpszNewItem* das seguintes maneiras:

|Nflags|Interpretação de lpszNewItem|
|------------|-----------------------------------|
|Mf_ownerdraw|Contém um valor de 32 bits fornecido pelo aplicativo que o aplicativo pode usar para manter dados adicionais associados ao item do menu. Este valor de 32 bits está `itemData` disponível para o aplicativo no membro da estrutura fornecida pelo [WM_MEASUREITEM](/windows/win32/Controls/wm-measureitem) e [WM_DRAWITEM](/windows/win32/Controls/wm-drawitem) mensagens. Essas mensagens são enviadas quando o item do menu é exibido inicialmente ou é alterado.|
|Mf_string|Contém um ponteiro longo para uma seqüência de terminadas nula. Esta é a interpretação padrão.|
|Mf_separator|O parâmetro *lpszNewItem* é ignorado (não necessário).|

*pBmp*<br/>
Aponta para `CBitmap` um objeto que será usado como item do menu.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O aplicativo pode especificar o estado do item do menu definindo valores em *nFlags*.

Sempre que um menu que reside em uma janela é alterado (se `CWnd::DrawMenuBar`a janela é ou não exibida), o aplicativo deve chamar .

Quando *nIDNewItem* especifica um menu pop-up, ele se torna parte do menu no qual ele é inserido. Se esse menu for destruído, o menu inserido também será destruído. Um menu inserido deve ser `CMenu` retirado de um objeto para evitar conflitos.

Se a janela de criança mDI (active multiple document interface de documento) for maximizada e um aplicativo inserir um menu pop-up no menu do aplicativo MDI chamando essa função e especificando o MF_BYPOSITION flag, o menu será inserido uma posição mais à esquerda do que o esperado. Isso acontece porque o menu Controle da janela de criança MDI ativa é inserido na primeira posição da barra de menu da janela do quadro MDI. Para posicionar o menu corretamente, o aplicativo deve adicionar 1 ao valor de posição que de outra forma seria usado. Um aplicativo pode usar a mensagem WM_MDIGETACTIVE para determinar se a janela filho ativa atualmente é maximizada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#28](../../mfc/reference/codesnippet/cpp/cmenu-class_8.cpp)]

## <a name="cmenuinsertmenuitem"></a><a name="insertmenuitem"></a>CMenu::InserirMenuItem

Insere um novo item do menu na posição especificada em um menu.

```
BOOL InsertMenuItem(
    UINT uItem,
    LPMENUITEMINFO lpMenuItemInfo,
    BOOL fByPos = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Uitem*<br/>
Veja a descrição do *uItem* em [InsertMenuItem](/windows/win32/api/winuser/nf-winuser-insertmenuitemw) no Windows SDK.

*lpMenuItemInfo*<br/>
Veja a descrição do `InsertMenuItem` *lpmii* no Windows SDK.

*fByPos*<br/>
Veja a descrição do `InsertMenuItem` *fByPosition* no SDK do Windows.

### <a name="remarks"></a>Comentários

Esta função envolve [InsertMenuItem,](/windows/win32/api/winuser/nf-winuser-insertmenuitemw)descrito no SDK do Windows.

## <a name="cmenuloadmenu"></a><a name="loadmenu"></a>CMenu::Menu de carga

Carrega um recurso de menu do arquivo executável do `CMenu` aplicativo e anexa-o ao objeto.

```
BOOL LoadMenu(LPCTSTR lpszResourceName);
BOOL LoadMenu(UINT nIDResource);
```

### <a name="parameters"></a>Parâmetros

*Lpszresourcename*<br/>
Aponta para uma seqüência de terminadas nula que contém o nome do recurso de menu a ser carregado.

*Nidresource*<br/>
Especifica o ID do menu do recurso do menu a ser carregado.

### <a name="return-value"></a>Valor retornado

Não zero se o recurso do menu foi carregado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Antes de sair, um aplicativo deve liberar os recursos do sistema associados a um menu se o menu não for atribuído a uma janela. Um aplicativo libera um menu chamando a função de membro [DestroyMenu.](#destroymenu)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#29](../../mfc/reference/codesnippet/cpp/cmenu-class_9.cpp)]

## <a name="cmenuloadmenuindirect"></a><a name="loadmenuindirect"></a>CMenu::Menu de cargaIndirectIndirect

Carrega um recurso de um modelo de menu `CMenu` na memória e anexa-o ao objeto.

```
BOOL LoadMenuIndirect(const void* lpMenuTemplate);
```

### <a name="parameters"></a>Parâmetros

*modelo de menu lp*<br/>
Aponta para um modelo de menu (que é uma única estrutura [MENUITEMTEMPLATEHEADER](/windows/win32/api/winuser/ns-winuser-menuitemtemplateheader) e uma coleção de uma ou mais estruturas [MENUITEMTEMPLATE).](/windows/win32/api/winuser/ns-winuser-menuitemtemplate) Para obter mais informações sobre essas duas estruturas, consulte o Windows SDK.

### <a name="return-value"></a>Valor retornado

Não zero se o recurso do menu foi carregado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um modelo de menu é um cabeçalho seguido de uma coleção de uma ou mais estruturas [MENUITEMTEMPLATE,](/windows/win32/api/winuser/ns-winuser-menuitemtemplate) cada uma das quais pode conter um ou mais itens do menu e menus pop-up.

O número da versão deve ser 0.

As `mtOption` bandeiras devem incluir MF_END para o último item em uma lista pop-up e para o último item da lista principal. Consulte `AppendMenu` a função do membro para outras bandeiras. O `mtId` membro deve ser omitido da estrutura MENUITEMTEMPLATE quando MF_POPUP for especificado em `mtOption`.

O espaço alocado para a estrutura MENUITEMTEMPLATE `mtString` deve ser grande o suficiente para conter o nome do item do menu como uma seqüência de seqüência sumida.

Antes de sair, um aplicativo deve liberar os recursos do sistema associados a um menu se o menu não for atribuído a uma janela. Um aplicativo libera um menu chamando a função de membro [DestroyMenu.](#destroymenu)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#30](../../mfc/reference/codesnippet/cpp/cmenu-class_10.cpp)]

## <a name="cmenum_hmenu"></a><a name="m_hmenu"></a>CMenu::m_hMenu

Especifica a alça HMENU do menu do `CMenu` Windows anexado ao objeto.

```
HMENU m_hMenu;
```

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::Menu de carga](#loadmenu).

## <a name="cmenumeasureitem"></a><a name="measureitem"></a>CMenu::MeasureItem

Chamado pela estrutura quando um menu com o estilo proprietário-draw é criado.

```
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpMeasureItemStruct*<br/>
Um ponteiro `MEASUREITEMSTRUCT` para uma estrutura.

### <a name="remarks"></a>Comentários

Por padrão, esta função de membro não faz nada. Anular essa função de membro `MEASUREITEMSTRUCT` e preencher a estrutura para informar o Windows sobre as dimensões do menu.

Consulte [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter `MEASUREITEMSTRUCT` uma descrição da estrutura.

### <a name="example"></a>Exemplo

O código a seguir é da amostra MFC [CTRLTEST:](../../overview/visual-cpp-samples.md)

[!code-cpp[NVC_MFCWindowing#31](../../mfc/reference/codesnippet/cpp/cmenu-class_11.cpp)]

## <a name="cmenumodifymenu"></a><a name="modifymenu"></a>CMenu::ModifyMenu

Altera um item de menu existente na posição especificada por *nPosition*.

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

### <a name="parameters"></a>Parâmetros

*Nposition*<br/>
Especifica o item do menu a ser alterado. O parâmetro *nFlags* pode ser usado para interpretar *nPosição* das seguintes maneiras:

|Nflags|Interpretação de nPosição|
|------------|---------------------------------|
|Mf_bycommand|Especifica que o parâmetro fornece o id de comando do item do menu existente. Este é o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION for definido.|
|Mf_byposition|Especifica que o parâmetro dá a posição do item do menu existente. O primeiro item está na posição 0.|

*Nflags*<br/>
Especifica como *o nPosition* é interpretado e fornece informações sobre as alterações a serem feitas no item do menu. Para obter uma lista de sinalizadores que podem ser definidos, consulte a função membro [AppendMenu.](#appendmenu)

*Nidnewitem*<br/>
Especifica o ID de comando do item de menu modificado ou, se *nFlags* estiver definido para MF_POPUP, a alça do menu (HMENU) de um menu pop-up. O parâmetro *nIDNewItem* é ignorado (não necessário) se *nFlags* estiver definido para MF_SEPARATOR.

*lpszNewItem*<br/>
Especifica o conteúdo do novo item do menu. O parâmetro *nFlags* pode ser usado para interpretar *lpszNewItem* das seguintes maneiras:

|Nflags|Interpretação de lpszNewItem|
|------------|-----------------------------------|
|Mf_ownerdraw|Contém um valor de 32 bits fornecido pelo aplicativo que o aplicativo pode usar para manter dados adicionais associados ao item do menu. Este valor de 32 bits está disponível para o aplicativo quando ele processa MF_MEASUREITEM e MF_DRAWITEM.|
|Mf_string|Contém um ponteiro longo para uma seqüência de terminadas nula ou para um `CString`.|
|Mf_separator|O parâmetro *lpszNewItem* é ignorado (não necessário).|

*pBmp*<br/>
Aponta para `CBitmap` um objeto que será usado como item do menu.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

O aplicativo especifica o novo estado do item do menu definindo valores em *nFlags*. Se essa função substituir um menu pop-up associado ao item do menu, ele destruirá o antigo menu pop-up e liberará a memória usada pelo menu pop-up.

Quando *nIDNewItem* especifica um menu pop-up, ele se torna parte do menu no qual ele é inserido. Se esse menu for destruído, o menu inserido também será destruído. Um menu inserido deve ser `CMenu` retirado de um objeto para evitar conflitos.

Sempre que um menu que reside em uma janela é alterado (se `CWnd::DrawMenuBar`a janela é ou não exibida), o aplicativo deve chamar . Para alterar os atributos dos itens de menu existentes, `CheckMenuItem` `EnableMenuItem` é muito mais rápido usar as funções e membro.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).

## <a name="cmenuoperator-hmenu"></a><a name="operator_hmenu"></a>CMenu::operador HMENU

Use este operador para recuperar `CMenu` a alça do objeto.

```
operator HMENU() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, a alça do `CMenu` objeto; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Você pode usar a alça para chamar apis do Windows diretamente.

## <a name="cmenuoperator-"></a><a name="operator_neq"></a>CMenu::operador !=

Determina se dois menus logicamente não são iguais.

```
BOOL operator!=(const CMenu& menu) const;
```

### <a name="parameters"></a>Parâmetros

*Menu*<br/>
Um objeto `CMenu` para comparação.

### <a name="remarks"></a>Comentários

Teste se um objeto de menu no lado esquerdo não é igual a um objeto de menu no lado direito.

## <a name="cmenuoperator-"></a><a name="operator_eq_eq"></a>CMenu::operador ==

Determina se dois menus são logicamente iguais.

```
BOOL operator==(const CMenu& menu) const;
```

### <a name="parameters"></a>Parâmetros

*Menu*<br/>
Um objeto `CMenu` para comparação.

### <a name="remarks"></a>Comentários

Teste se um objeto de menu no lado esquerdo for igual (em termos do valor HMENU) a um objeto de menu no lado direito.

## <a name="cmenuremovemenu"></a><a name="removemenu"></a>CMenu::RemoveMenu

Exclui um item do menu com um menu pop-up associado do menu.

```
BOOL RemoveMenu(
    UINT nPosition,
    UINT nFlags);
```

### <a name="parameters"></a>Parâmetros

*Nposition*<br/>
Especifica o item do menu a ser removido. O parâmetro *nFlags* pode ser usado para interpretar *nPosição* das seguintes maneiras:

|Nflags|Interpretação de nPosição|
|------------|---------------------------------|
|Mf_bycommand|Especifica que o parâmetro fornece o id de comando do item do menu existente. Este é o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION for definido.|
|Mf_byposition|Especifica que o parâmetro dá a posição do item do menu existente. O primeiro item está na posição 0.|

*Nflags*<br/>
Especifica como *nPosition* é interpretado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ele não destrói a alça para um menu pop-up, de modo que o menu pode ser reutilizado. Antes de chamar essa função, `GetSubMenu` o aplicativo pode chamar `CMenu` a função de membro para recuperar o objeto pop-up para reutilização.

Sempre que um menu que reside em uma janela é alterado (se `CWnd::DrawMenuBar`a janela é ou não exibida), o aplicativo deve chamar .

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).

## <a name="cmenusetdefaultitem"></a><a name="setdefaultitem"></a>CMenu::SetDefaultItem

Define o item do menu padrão para o menu especificado.

```
BOOL SetDefaultItem(
    UINT uItem,
    BOOL fByPos = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Uitem*<br/>
Identificador ou posição do novo item de menu padrão ou - 1 para nenhum item padrão. O significado deste parâmetro depende do valor de *fByPos*.

*fByPos*<br/>
Valor especificando o significado de *uItem*. Se este parâmetro for FALSO, *uItem* será um identificador de item do menu. Caso contrário, é uma posição de item do menu.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno não será zero. Se a função falhar, o valor retornado será zero. Para obter informações de erro estendidas, use a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), conforme descrito no SDK do Windows.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da função Win32 [SetMenuDefaultItem](/windows/win32/api/winuser/nf-winuser-setmenudefaultitem), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).

## <a name="cmenusetmenucontexthelpid"></a><a name="setmenucontexthelpid"></a>CMenu::SetMenuMenuContextHelpId

Associa um contexto para `CMenu`ajudar a iD com .

```
BOOL SetMenuContextHelpId(DWORD dwContextHelpId);
```

### <a name="parameters"></a>Parâmetros

*dwContextHelpId*<br/>
O contexto ajuda a `CMenu`iD a associar-se a .

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário 0

### <a name="remarks"></a>Comentários

Todos os itens do menu compartilham este identificador — não é possível anexar um identificador de contexto de ajuda aos itens de menu individuais.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).

## <a name="cmenusetmenuinfo"></a><a name="setmenuinfo"></a>CMenu::SetMenuInformações

Define informações para um menu.

```
BOOL SetMenuInfo(LPCMENUINFO lpcmi);
```

### <a name="parameters"></a>Parâmetros

*Lpcmi*<br/>
Um ponteiro para uma estrutura [MENUINFO](/windows/win32/api/winuser/ns-winuser-menuinfo) contendo informações para o menu.

### <a name="return-value"></a>Valor retornado

Se a função for bem sucedida, o valor de retorno não será zero; caso contrário, o valor de retorno é zero.

### <a name="remarks"></a>Comentários

Ligue para esta função para definir informações específicas sobre o menu.

## <a name="cmenusetmenuitembitmaps"></a><a name="setmenuitembitmaps"></a>CMenu::SetMenuMenuItemBitmaps

Associa os bitmaps especificados com um item do menu.

```
BOOL SetMenuItemBitmaps(
    UINT nPosition,
    UINT nFlags,
    const CBitmap* pBmpUnchecked,
    const CBitmap* pBmpChecked);
```

### <a name="parameters"></a>Parâmetros

*Nposition*<br/>
Especifica o item do menu a ser alterado. O parâmetro *nFlags* pode ser usado para interpretar *nPosição* das seguintes maneiras:

|Nflags|Interpretação de nPosição|
|------------|---------------------------------|
|Mf_bycommand|Especifica que o parâmetro fornece o id de comando do item do menu existente. Este é o padrão se nem MF_BYCOMMAND nem MF_BYPOSITION for definido.|
|Mf_byposition|Especifica que o parâmetro dá a posição do item do menu existente. O primeiro item está na posição 0.|

*Nflags*<br/>
Especifica como *nPosition* é interpretado.

*pBmpUnchecked*<br/>
Especifica o bitmap a ser usado para itens de menu que não foram verificados.

*pBmpChecked*<br/>
Especifica o bitmap a ser usado para itens de menu verificados.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o item do menu for verificado ou não, o Windows exibe o bitmap apropriado ao lado do item do menu.

Se *o pBmpUnchecked* ou *pBmpChecked* for NULL, então o Windows não exibirá nada ao lado do item do menu para o atributo correspondente. Se ambos os parâmetros forem NULOS, o Windows usará a marca de verificação padrão quando o item é verificado e remove a marca de seleção quando o item é desmarcado.

Quando o menu é destruído, esses bitmaps não são destruídos; a aplicação deve destruí-los.

A `GetMenuCheckMarkDimensions` função Windows recupera as dimensões da marca de verificação padrão usada para itens do menu. O aplicativo usa esses valores para determinar o tamanho apropriado para os bitmaps fornecidos com esta função. Obtenha o tamanho, crie seus bitmaps e, em seguida, defina-os.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#32](../../mfc/reference/codesnippet/cpp/cmenu-class_12.cpp)]

[!code-cpp[NVC_MFCWindowing#33](../../mfc/reference/codesnippet/cpp/cmenu-class_13.cpp)]

## <a name="cmenusetmenuiteminfo"></a><a name="setmenuiteminfo"></a>CMenu::SetMenuItemInfo

Altera informações sobre um item do menu.

```
BOOL SetMenuItemInfo(
    UINT uItem,
    LPMENUITEMINFO lpMenuItemInfo,
    BOOL fByPos = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Uitem*<br/>
Veja a descrição do *uItem* em [SetMenuItemInfo](/windows/win32/api/winuser/nf-winuser-setmenuiteminfow) no Windows SDK.

*lpMenuItemInfo*<br/>
Veja a descrição do `SetMenuItemInfo` *lpmii* no Windows SDK.

*fByPos*<br/>
Veja a descrição do `SetMenuItemInfo` *fByPosition* no SDK do Windows.

### <a name="remarks"></a>Comentários

Esta função envolve [SetMenuItemInfo](/windows/win32/api/winuser/nf-winuser-setmenuiteminfow), descrito no Windows SDK.

## <a name="cmenutrackpopupmenu"></a><a name="trackpopupmenu"></a>CMenu::TrackPopupMenu

Exibe um menu pop-up flutuante no local especificado e rastreia a seleção de itens no menu pop-up.

```
BOOL TrackPopupMenu(
    UINT nFlags,
    int x,
    int y,
    CWnd* pWnd,
    LPCRECT lpRect = 0);
```

### <a name="parameters"></a>Parâmetros

*Nflags*<br/>
Especifica bandeiras de posição de tela e posição do mouse. Consulte [TrackPopupMenu](/windows/win32/api/winuser/nf-winuser-trackpopupmenu) para obter uma lista de sinalizadores disponíveis.

*x*<br/>
Especifica a posição horizontal nas coordenadas de tela do menu pop-up. Dependendo do valor do parâmetro *nFlags,* o menu pode ser alinhado à esquerda, alinhado à direita ou centrado em relação a esta posição.

*Y*<br/>
Especifica a posição vertical nas coordenadas de tela da parte superior do menu na tela.

*Pwnd*<br/>
Identifica a janela que possui o menu pop-up. Este parâmetro não pode ser NULO, mesmo que a bandeira TPM_NONOTIFY seja especificada. Esta janela recebe todas as mensagens WM_COMMAND do menu. Nas versões 3.1 do Windows e posteriores, a janela não recebe mensagens WM_COMMAND até `TrackPopupMenu` o retorno. No Windows 3.0, a janela `TrackPopupMenu` recebe mensagens WM_COMMAND antes do retorno.

*Lprect*<br/>
Ignorado.

### <a name="return-value"></a>Valor retornado

Este método retorna o resultado de chamar [TrackPopupMenu](/windows/win32/api/winuser/nf-winuser-trackpopupmenu) no Windows SDK.

### <a name="remarks"></a>Comentários

Um menu pop-up flutuante pode aparecer em qualquer lugar da tela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#34](../../mfc/reference/codesnippet/cpp/cmenu-class_14.cpp)]

## <a name="cmenutrackpopupmenuex"></a><a name="trackpopupmenuex"></a>CMenu::TrackPopupMenuEx

Exibe um menu pop-up flutuante no local especificado e rastreia a seleção de itens no menu pop-up.

```
BOOL TrackPopupMenuEx(
    UINT fuFlags,
    int x,
    int y,
    CWnd* pWnd,
    LPTPMPARAMS lptpm);
```

### <a name="parameters"></a>Parâmetros

*fuFlags*<br/>
Especifica várias funções para o menu estendido. Para obter uma listagem de todos os valores e seu significado, consulte [TrackPopupMenuEx](/windows/win32/api/winuser/nf-winuser-trackpopupmenuex).

*x*<br/>
Especifica a posição horizontal nas coordenadas de tela do menu pop-up.

*Y*<br/>
Especifica a posição vertical nas coordenadas de tela da parte superior do menu na tela.

*Pwnd*<br/>
Um ponteiro para a janela que possui o menu pop-up e recebe as mensagens do menu criado. Esta janela pode ser qualquer janela do aplicativo atual, mas não pode ser NULL. Se você especificar TPM_NONOTIFY no parâmetro *fuFlags,* a função não enviará nenhuma mensagem para *pWnd*. A função deve retornar para a janela apontada por *pWnd* para receber a mensagem WM_COMMAND.

*Lptpm*<br/>
Ponteiro para uma estrutura [TPMPARAMS](/windows/win32/api/winuser/ns-winuser-tpmparams) que especifica uma área da tela o menu não deve se sobrepor. Este parâmetro pode ser NULO.

### <a name="return-value"></a>Valor retornado

Se você especificar TPM_RETURNCMD no parâmetro *fuFlags,* o valor de retorno será o identificador de item de menu do item que o usuário selecionou. Se o usuário cancelar o menu sem fazer uma seleção ou se ocorrer um erro, o valor de retorno será 0.

Se você não especificar TPM_RETURNCMD no parâmetro *fuFlags,* o valor de retorno não será zero se a função for bem sucedida e 0 se falhar. Para obter informações de erro estendidas, ligue para [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### <a name="remarks"></a>Comentários

Um menu pop-up flutuante pode aparecer em qualquer lugar da tela. Para obter mais informações sobre erros de manipulação ao criar o menu pop-up, consulte [TrackPopupMenuEx](/windows/win32/api/winuser/nf-winuser-trackpopupmenuex).

## <a name="see-also"></a>Confira também

[Tomografia de amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC DYNAMENU](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)
