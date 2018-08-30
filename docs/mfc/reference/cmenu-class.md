---
title: Classe CMenu | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0c94542fdac3734644771f2659d894d1c8c6f907
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43220796"
---
# <a name="cmenu-class"></a>Classe CMenu
Um encapsulamento do Windows `HMENU`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMenu : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMenu::CMenu](#cmenu)|Constrói um objeto `CMenu`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMenu::AppendMenu](#appendmenu)|Acrescenta um novo item ao final nesse menu.|  
|[CMenu::Attach](#attach)|Anexa um identificador de menu do Windows para um `CMenu` objeto.|  
|[CMenu::CheckMenuItem](#checkmenuitem)|Coloca uma marca de seleção ao lado ou remove uma marca de seleção de um item de menu no menu pop-up.|  
|[CMenu::CheckMenuRadioItem](#checkmenuradioitem)|Coloca um botão de opção ao lado de um item de menu e remove todos os outros itens de menu no grupo de botão de opção.|  
|[CMenu::CreateMenu](#createmenu)|Cria um menu vazio e anexa-o para um `CMenu` objeto.|  
|[CMenu::CreatePopupMenu](#createpopupmenu)|Cria um menu pop-up vazio e anexa-o para um `CMenu` objeto.|  
|[CMenu::DeleteMenu](#deletemenu)|Exclui um item especificado a partir do menu. Se o item de menu tem um menu pop-up associado, destrói o identificador para o menu pop-up e libera a memória usada por ele.|  
|[CMenu::DeleteTempMap](#deletetempmap)|Exclui qualquer temporário `CMenu` objetos criados pelo `FromHandle` função de membro.|  
|[CMenu::DestroyMenu](#destroymenu)|Destrói o menu anexado a um `CMenu` do objeto e libera a memória que o menu de ocupado.|  
|[CMenu::Detach](#detach)|Desanexa um identificador de menu do Windows de um `CMenu` do objeto e retorna o identificador.|  
|[CMenu::DrawItem](#drawitem)|Chamado pelo framework quando um aspecto visual de alterações de um menu desenhados pelo proprietário.|  
|[CMenu::EnableMenuItem](#enablemenuitem)|Habilita, desabilita ou esmaece (cinza) um item de menu.|  
|[CMenu::FromHandle](#fromhandle)|Retorna um ponteiro para um `CMenu` objeto dado um identificador de menu do Windows.|  
|[CMenu::GetDefaultItem](#getdefaultitem)|Determina o item de menu padrão no menu especificado.|  
|[CMenu::GetMenuContextHelpId](#getmenucontexthelpid)|Recupera a ID de contexto de ajuda associada com o menu.|  
|[CMenu::GetMenuInfo](#getmenuinfo)|Recupera as informações em um menu específico.|  
|[CMenu::GetMenuItemCount](#getmenuitemcount)|Determina o número de itens em um menu pop-up ou de nível superior.|  
|[CMenu::GetMenuItemID](#getmenuitemid)|Obtém o identificador do item de menu para um item de menu localizado na posição especificada.|  
|[CMenu::GetMenuItemInfo](#getmenuiteminfo)|Recupera informações sobre um item de menu.|  
|[CMenu::GetMenuState](#getmenustate)|Retorna o status do item de menu especificado ou o número de itens em um menu pop-up.|  
|[CMenu::GetMenuString](#getmenustring)|Recupera o rótulo do item de menu especificado.|  
|[CMenu::GetSafeHmenu](#getsafehmenu)|Retorna o `m_hMenu` encapsulado por esse `CMenu` objeto.|  
|[CMenu::GetSubMenu](#getsubmenu)|Recupera um ponteiro para um menu pop-up.|  
|[CMenu::InsertMenu](#insertmenu)|Insere um novo item de menu na posição especificada, movendo outros itens do menu suspenso.|  
|[CMenu::InsertMenuItem](#insertmenuitem)|Insere um novo item de menu na posição especificada em um menu.|  
|[CMenu::LoadMenu](#loadmenu)|Carrega um recurso de menu do arquivo executável e anexa-o para um `CMenu` objeto.|  
|[CMenu::LoadMenuIndirect](#loadmenuindirect)|Carrega um menu de um modelo de menu na memória e anexa-o para um `CMenu` objeto.|  
|[CMenu::MeasureItem](#measureitem)|Chamado pelo framework para determinar as dimensões do menu quando um menu desenhados pelo proprietário é criado.|  
|[CMenu::ModifyMenu](#modifymenu)|Altera um item de menu existente na posição especificada.|  
|[CMenu::RemoveMenu](#removemenu)|Exclui um item de menu com um menu pop-up associado de menu especificado.|  
|[CMenu::SetDefaultItem](#setdefaultitem)|Define o item de menu padrão para o menu especificado.|  
|[CMenu::SetMenuContextHelpId](#setmenucontexthelpid)|Define a ID do contexto de ajuda a ser associado com o menu.|  
|[CMenu::SetMenuInfo](#setmenuinfo)|Define informações sobre um menu específico.|  
|[CMenu::SetMenuItemBitmaps](#setmenuitembitmaps)|Associa os bitmaps de marca de seleção especificado com um item de menu.|  
|[CMenu::SetMenuItemInfo](#setmenuiteminfo)|Altera as informações sobre um item de menu.|  
|[CMenu::TrackPopupMenu](#trackpopupmenu)|Exibe um menu pop-up flutuante no local especificado e controla a seleção de itens no menu pop-up.|  
|[CMenu::TrackPopupMenuEx](#trackpopupmenuex)|Exibe um menu pop-up flutuante no local especificado e controla a seleção de itens no menu pop-up.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMenu::operator HMENU](#operator_hmenu)|Recupera o identificador do objeto de menu.|  
|[CMenu::operator! =](#operator_neq)|Determina se dois objetos de menu não são iguais.|  
|[CMenu::operator = =](#operator_eq_eq)|Determina se dois objetos de menu são iguais.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMenu::m_hMenu](#m_hmenu)|Especifica o identificador para o menu do Windows anexado ao `CMenu` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Ele fornece funções de membro para criação, controle, atualizando e destruição de um menu.  
  
 Criar uma `CMenu` objeto no quadro da pilha, como um local, em seguida, chame `CMenu`de funções de membro para manipular o novo menu conforme necessário. Em seguida, chame [CWnd::SetMenu](../../mfc/reference/cwnd-class.md#setmenu) definir o menu a uma janela, seguido imediatamente por uma chamada para o `CMenu` do objeto [desanexar](#detach) função de membro. O `CWnd::SetMenu` função de membro define o menu da janela para o menu novo, faz com que a janela a ser redesenhado para refletir a alteração de menu e também passa a propriedade do menu para a janela. A chamada para `Detach` desanexa o HMENU do `CMenu` do objeto, isso que, quando o local `CMenu` variável passa fora do escopo, o `CMenu` destruidor do objeto não tenta destruir um menu que ele não possui mais. O próprio menu será destruído automaticamente quando a janela é destruída.  
  
 Você pode usar o [LoadMenuIndirect](#loadmenuindirect) função de membro para criar um menu de um modelo na memória, mas um menu criado de um recurso por uma chamada para [LoadMenu](#loadmenu) mais facilmente é mantida e o próprio recurso de menu pode ser criada e modificada pelo editor de menu.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMenu`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="appendmenu"></a>  CMenu::AppendMenu  
 Acrescenta um novo item ao final de um menu.  
  
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
 *nFlags*  
 Especifica informações sobre o estado do novo item de menu quando ele é adicionado ao menu. Ele consiste em um ou mais dos valores listados na seção comentários.  
  
 *nIDNewItem*  
 Especifica a ID de comando do novo item de menu ou, se *nFlags* é definido como MF_POPUP, o identificador de menu ( `HMENU`) de um menu pop-up. O *nIDNewItem* parâmetro será ignorado (não necessárias) se *nFlags* é definido como MF_SEPARATOR.  
  
 *lpszNewItem*  
 Especifica o conteúdo do novo item de menu. O *nFlags* parâmetro é usado para interpretar *lpszNewItem* da seguinte maneira:  
  
|nFlags|Interpretação de lpszNewItem|  
|------------|-----------------------------------|  
|MF_OWNERDRAW|Contém um valor de 32 bits fornecida pelo aplicativo que o aplicativo pode usar para manter os dados adicionais associados ao item de menu. Esse valor de 32 bits está disponível para o aplicativo quando ele processa as mensagens WM_MEASUREITEM e WM_DRAWITEM. O valor é armazenado no `itemData` membro da estrutura fornecido com essas mensagens.|  
|MF_STRING|Contém um ponteiro para uma cadeia de caracteres terminada em nulo. Essa é a interpretação padrão.|  
|MF_SEPARATOR|O *lpszNewItem* parâmetro é ignorado (não é necessária).|  
  
 *pBmp*  
 Aponta para um `CBitmap` objeto que será usado como o item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O aplicativo pode especificar o estado do item de menu, definindo valores no *nFlags*. Quando *nIDNewItem* Especifica um menu pop-up, ele se torna parte do menu ao qual ele é acrescentado. Se esse menu for destruído, o menu acrescentado também será destruído. Um menu acrescentado deve ser desanexado de um `CMenu` objeto para evitar conflitos. Observe que MF_STRING e MF_OWNERDRAW não são válidas para a versão de bitmap do `AppendMenu`.  
  
 A lista a seguir descreve os sinalizadores que podem ser definidos no *nFlags*:  
  
- Atua de MF_CHECKED como uma alternância com MF_UNCHECKED para colocar o padrão Verifique marca ao lado do item. Quando o aplicativo fornece bitmaps de marca de seleção (consulte a [SetMenuItemBitmaps](#setmenuitembitmaps) função de membro), o bitmap de "marca de seleção no" é exibido.  
  
- MF_UNCHECKED atua como um controle de alternância com MF_CHECKED para remover uma marca de seleção próxima ao item. Quando o aplicativo fornece a marca de seleção bitmaps (veja a `SetMenuItemBitmaps` função de membro), o bitmap de "marca de seleção off" é exibido.  
  
- MF_DISABLED desabilita o item de menu para que ele não pode ser selecionado, mas não esmaecer a ele.  
  
- MF_ENABLED permite que o item de menu para que ele pode ser selecionado e restaurá-lo de seu estado esmaecido.  
  
- MF_GRAYED desabilita o item de menu para que ele não pode ser selecionado e escurece-lo.  
  
- MF_MENUBARBREAK coloca o item em uma nova linha em menus estáticas ou em uma nova coluna nos menus pop-up. A nova coluna de menu pop-up será ser separada de coluna antiga por uma linha divisória vertical.  
  
- MF_MENUBREAK coloca o item em uma nova linha em menus estáticas ou em uma nova coluna nos menus pop-up. Nenhuma linha divisória é colocada entre as colunas.  
  
- MF_OWNERDRAW Especifica que o item é um item de desenho proprietário. Quando o menu é exibido pela primeira vez, a janela que possui o menu recebe uma mensagem WM_MEASUREITEM, que recupera a altura e largura do item de menu. A mensagem WM_DRAWITEM é aquela enviada sempre que o proprietário deve atualizar a aparência visual do item de menu. Essa opção não é válida para um item de menu de nível superior.  
  
- MF_POPUP Especifica que o item de menu tem um menu pop-up associado a ele. O parâmetro de ID Especifica um identificador para um menu pop-up que deve ser associado ao item. Isso é usado para adicionar um menu pop-up de nível superior ou um menu pop-up hierárquico para um item de menu pop-up.  
  
- MF_SEPARATOR desenha uma linha divisória horizontal. Só pode ser usado em um menu pop-up. Essa linha não pode ser esmaecida, desabilitada ou realçada. Outros parâmetros serão ignorados.  
  
- MF_STRING Especifica que o item de menu é uma cadeia de caracteres.  
  
 Cada um dos seguintes grupos de lista de sinalizadores que se excluem mutuamente e não podem ser usados juntos:  
  
- MF_DISABLED, MF_ENABLED e MF_GRAYED  
  
- MF_STRING, MF_OWNERDRAW, MF_SEPARATOR e a versão de bitmap  
  
- MF_MENUBARBREAK e MF_MENUBREAK  
  
- MF_CHECKED e MF_UNCHECKED  
  
 Sempre que um menu que reside em uma janela é alterada (se a janela é exibida), o aplicativo deve chamar [CWnd::DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::CreateMenu](#createmenu).  
  
##  <a name="attach"></a>  CMenu::Attach  
 Anexa um menu do Windows existente para um `CMenu` objeto.  
  
```  
BOOL Attach(HMENU hMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hMenu*  
 Especifica um identificador para um menu do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função não deve ser chamada se um menu já está anexado para o `CMenu` objeto. O identificador de menu é armazenado no `m_hMenu` membro de dados.  
  
 Se o menu que você deseja manipular já está associado uma janela, você pode usar o [CWnd::GetMenu](../../mfc/reference/cwnd-class.md#getmenu) função para obter um identificador para o menu.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#21](../../mfc/reference/codesnippet/cpp/cmenu-class_1.cpp)]  
  
##  <a name="checkmenuitem"></a>  CMenu::CheckMenuItem  
 Adiciona as marcas de seleção para ou remove as marcas de seleção de itens de menu no menu pop-up.  
  
```  
UINT CheckMenuItem(
    UINT nIDCheckItem,  
    UINT nCheck);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDCheckItem*  
 Especifica o item de menu a ser verificada, conforme determinado pela *nVerifique*.  
  
 *nVerifique*  
 Especifica como verificar o item de menu e como determinar a posição do item no menu. O *nVerifique* parâmetro pode ser uma combinação de MF_CHECKED ou MF_UNCHECKED com MF_BYPOSITION ou MF_BYCOMMAND sinalizadores. Esses sinalizadores podem ser combinados usando o operador OR bit a bit. Elas têm os seguintes significados:  
  
- MF_BYCOMMAND Especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse é o padrão.  
  
- MF_BYPOSITION Especifica que o parâmetro fornece a posição do item de menu existente. É o primeiro item na posição 0.  
  
- Atua de MF_CHECKED como uma alternância com MF_UNCHECKED para colocar o padrão Verifique marca ao lado do item.  
  
- MF_UNCHECKED atua como um controle de alternância com MF_CHECKED para remover uma marca de seleção próxima ao item.  
  
### <a name="return-value"></a>Valor de retorno  
 O estado anterior do item: MF_CHECKED ou MF_UNCHECKED, ou 0xFFFFFFFF se o item de menu não existia.  
  
### <a name="remarks"></a>Comentários  
 O *nIDCheckItem* parâmetro especifica o item a ser modificado.  
  
 O *nIDCheckItem* parâmetro pode identificar um item de menu pop-up, bem como um item de menu. Nenhuma etapa especial é necessário para procurar um item de menu pop-up. Itens de menu de nível superior não podem ser verificados. Um item de menu pop-up deve ser verificado por posição, pois ele não tem um identificador de item de menu associado a ele.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::GetMenuState](#getmenustate).  
  
##  <a name="checkmenuradioitem"></a>  CMenu::CheckMenuRadioItem  
 Verifica um item de menu especificado e o torna um item de rádio.  
  
```  
BOOL CheckMenuRadioItem(
    UINT nIDFirst,  
    UINT nIDLast,  
    UINT nIDItem,  
    UINT nFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDFirst*  
 Especifica (como uma ID ou o deslocamento, dependendo do valor de *nFlags*) o primeiro item de menu no grupo de botões de opção.  
  
 *nIDLast*  
 Especifica (como uma ID ou o deslocamento, dependendo do valor de *nFlags*) o último item de menu no grupo de botões de opção.  
  
 *nIDItem*  
 Especifica (como uma ID ou o deslocamento, dependendo do valor de *nFlags*) o item no grupo que será verificado com um botão de opção.  
  
 *nFlags*  
 Especifica a interpretação dos *nIDFirst*, *nIDLast*, e *nIDItem* da seguinte maneira:  
  
|nFlags|Interpretação|  
|------------|--------------------|  
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Se nem MF_BYCOMMAND nem MF_BYPOSITION for definido, esse é o padrão.|  
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. É o primeiro item na posição 0.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0  
  
### <a name="remarks"></a>Comentários  
 Ao mesmo tempo, a função desmarca todos os outros itens de menu do grupo associado e limpa o sinalizador de tipo de item de rádio para esses itens. O item selecionado é exibido usando um bitmap de rádio botão (ou com marcadores) em vez de um bitmap de marca de seleção.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [ON_COMMAND_RANGE](message-map-macros-mfc.md#on_command_range).  
  
##  <a name="cmenu"></a>  CMenu::CMenu  
 Cria um menu vazio e anexa-o para um `CMenu` objeto.  
  
```  
CMenu();
```  
  
### <a name="remarks"></a>Comentários  
 O menu não é criado até que você chame um da criar ou carregar funções de membro de `CMenu:`  
  
- [CreateMenu](#createmenu)  
  
- [CreatePopupMenu](#createpopupmenu)  
  
- [LoadMenu](#loadmenu)  
  
- [LoadMenuIndirect](#loadmenuindirect)  
  
- [Anexar](#attach)  
  
##  <a name="createmenu"></a>  CMenu::CreateMenu  
 Cria um menu e anexa-o para o `CMenu` objeto.  
  
```  
BOOL CreateMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o menu foi criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O menu é inicialmente vazio. Itens de menu podem ser adicionados usando o `AppendMenu` ou `InsertMenu` função de membro.  
  
 Se o menu for atribuído a uma janela, ela será destruída automaticamente quando a janela é destruída.  
  
 Antes de sair, um aplicativo deve liberar recursos do sistema associados com um menu se o menu não for atribuído a uma janela. Um aplicativo libera um menu chamando o [DestroyMenu](#destroymenu) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#22](../../mfc/reference/codesnippet/cpp/cmenu-class_2.cpp)]  
  
##  <a name="createpopupmenu"></a>  CMenu::CreatePopupMenu  
 Cria um menu pop-up e anexa-o para o `CMenu` objeto.  
  
```  
BOOL CreatePopupMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o menu pop-up foi criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O menu é inicialmente vazio. Itens de menu podem ser adicionados usando o `AppendMenu` ou `InsertMenu` função de membro. O aplicativo pode adicionar o menu pop-up a um existente ou no menu pop-up. O `TrackPopupMenu` função de membro pode ser usada para exibir esse menu como um menu pop-up flutuante e para rastrear as seleções no menu pop-up.  
  
 Se o menu for atribuído a uma janela, ela será destruída automaticamente quando a janela é destruída. Se o menu é adicionado a um menu existente, ele será destruído automaticamente quando esse menu é destruído.  
  
 Antes de sair, um aplicativo deve liberar recursos do sistema associados com um menu pop-up, se o menu não for atribuído a uma janela. Um aplicativo libera um menu chamando o [DestroyMenu](#destroymenu) função de membro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::CreateMenu](#createmenu).  
  
##  <a name="deletemenu"></a>  CMenu::DeleteMenu  
 Exclui um item de menu.  
  
```  
BOOL DeleteMenu(
    UINT nPosition,  
    UINT nFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nPosition*  
 Especifica o item de menu deve ser excluída, conforme determinado pela *nFlags*.  
  
 *nFlags*  
 É usado para interpretar *nPosition* da seguinte maneira:  
  
|nFlags|Interpretação de nPosition|  
|------------|---------------------------------|  
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Se nem MF_BYCOMMAND nem MF_BYPOSITION for definido, esse é o padrão.|  
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. É o primeiro item na posição 0.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o item de menu tem um menu pop-up associado `DeleteMenu` destrói o identificador para o menu pop-up e libera a memória usada pelo menu pop-up.  
  
 Sempre que um menu que reside em uma janela é alterada (se a janela é exibida), o aplicativo deve chamar [CWnd::DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::GetMenu](../../mfc/reference/cwnd-class.md#getmenu).  
  
##  <a name="deletetempmap"></a>  CMenu::DeleteTempMap  
 Chamado automaticamente pelo `CWinApp` manipulador de tempo ocioso, exclui qualquer temporário `CMenu` objetos criados pelo [FromHandle](#fromhandle) função de membro.  
  
```  
static void PASCAL DeleteTempMap();
```  
  
### <a name="remarks"></a>Comentários  
 `DeleteTempMap` desanexa o objeto de menu do Windows anexado a um temporário `CMenu` objeto antes de excluir o `CMenu` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#23](../../mfc/reference/codesnippet/cpp/cmenu-class_3.cpp)]  
  
##  <a name="destroymenu"></a>  CMenu::DestroyMenu  
 Destrói o menu e quaisquer recursos do Windows que foram usados.  
  
```  
BOOL DestroyMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o menu é destruído; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O menu é desanexado do `CMenu` objeto antes de ser destruído. O Windows `DestroyMenu` função é chamada automaticamente no `CMenu` destruidor.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::CreateMenu](#createmenu).  
  
##  <a name="detach"></a>  CMenu::Detach  
 Desanexa um menu do Windows em um `CMenu` do objeto e retorna o identificador.  
  
```  
HMENU Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador, do tipo HMENU, a um menu do Windows, se for bem-sucedido; Caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 O `m_hMenu` membro de dados é definido como NULL.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#21](../../mfc/reference/codesnippet/cpp/cmenu-class_1.cpp)]  
  
##  <a name="drawitem"></a>  CMenu::DrawItem  
 Chamado pelo framework quando um aspecto visual de alterações de um menu desenhados pelo proprietário.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpDrawItemStruct*  
 Um ponteiro para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura que contém informações sobre o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 O `itemAction` membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho a ser executada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CMenu` objeto. O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes do encerramento desta função de membro.  
  
 Ver [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição de `DRAWITEMSTRUCT` estrutura.  
  
### <a name="example"></a>Exemplo  
 O código a seguir é de MFC [CTRLTEST](../../visual-cpp-samples.md) exemplo:  
  
 [!code-cpp[NVC_MFCWindowing#24](../../mfc/reference/codesnippet/cpp/cmenu-class_4.cpp)]  
  
##  <a name="enablemenuitem"></a>  CMenu::EnableMenuItem  
 Habilita, desabilita ou solicitará um item de menu.  
  
```  
UINT EnableMenuItem(
    UINT nIDEnableItem,  
    UINT nEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDEnableItem*  
 Especifica o item de menu a ser habilitado, conforme determinado pela *nEnable*. Esse parâmetro pode especificar os itens de menu pop-up, bem como itens de menu padrão.  
  
 *nEnable*  
 Especifica a ação a ser tomada. Ele pode ser uma combinação de MF_DISABLED, MF_ENABLED ou MF_GRAYED com MF_BYCOMMAND ou MF_BYPOSITION. Esses valores podem ser combinados usando o operador OR bit a bit. Esses valores têm os seguintes significados:  
  
- MF_BYCOMMAND Especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse é o padrão.  
  
- MF_BYPOSITION Especifica que o parâmetro fornece a posição do item de menu existente. É o primeiro item na posição 0.  
  
- MF_DISABLED desabilita o item de menu para que ele não pode ser selecionado, mas não esmaecer a ele.  
  
- MF_ENABLED permite que o item de menu para que ele pode ser selecionado e restaurá-lo de seu estado esmaecido.  
  
- MF_GRAYED desabilita o item de menu para que ele não pode ser selecionado e escurece-lo.  
  
### <a name="return-value"></a>Valor de retorno  
 Estado anterior (MF_DISABLED, MF_ENABLED ou MF_GRAYED) ou -1 se não é válido.  
  
### <a name="remarks"></a>Comentários  
 O [CreateMenu](#createmenu), [InsertMenu](#insertmenu), [ModifyMenu](#modifymenu), e [LoadMenuIndirect](#loadmenuindirect) funções de membro também podem definir o estado (habilitado, desabilitado ou esmaecido) de um item de menu.  
  
 Usando o valor MF_BYPOSITION requer um aplicativo para usar o correto `CMenu`. Se o `CMenu` do menu barra é usada, um item de menu de nível superior (um item na barra de menus) é afetado. Para definir o estado de um item em um menu pop-up de pop-up ou aninhado por posição, um aplicativo deve especificar o `CMenu` do menu pop-up.  
  
 Quando um aplicativo especifica o sinalizador MF_BYCOMMAND, o Windows verifica todos os itens de menu pop-up que são subordinados à `CMenu`; portanto, a menos que os itens de menu duplicado estiverem presentes, usando o `CMenu` do menu barra é suficiente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#25](../../mfc/reference/codesnippet/cpp/cmenu-class_5.cpp)]  
  
##  <a name="fromhandle"></a>  CMenu::FromHandle  
 Retorna um ponteiro para um `CMenu` objeto recebe um identificador do Windows a um menu.  
  
```  
static CMenu* PASCAL FromHandle(HMENU hMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hMenu*  
 Um identificador do Windows para um menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CMenu` que pode ser temporário ou permanente.  
  
### <a name="remarks"></a>Comentários  
 Se um `CMenu` objeto já não está anexado ao objeto de menu do Windows, um temporário `CMenu` objeto é criado e anexado.  
  
 Esse temporário `CMenu` objeto só é válido até a próxima vez que o aplicativo tem tempo ocioso em seu loop de eventos, momento em que todos os objetos temporários serão excluídos.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::CreateMenu](#createmenu).  
  
##  <a name="getdefaultitem"></a>  CMenu::GetDefaultItem  
 Determina o item de menu padrão no menu especificado.  
  
```  
UINT GetDefaultItem(
    UINT gmdiFlags,  
    BOOL fByPos = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *gmdiFlags*  
 Valor que especifica como a função de pesquisa para itens de menu. Esse parâmetro pode ser nenhum, um ou uma combinação dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|GMDI_GOINTOPOPUPS|Especifica que, se o item padrão é aquele que abre um submenu, a função é pesquisar recursivamente o submenu correspondente. Se o submenu não tem nenhum item padrão, o valor de retorno identifica o item que abre um submenu.<br /><br /> Por padrão, a função retorna o primeiro item padrão no menu especificado, independentemente de ser um item que abre um submenu.|  
|GMDI_USEDISABLED|Especifica que a função deve retornar um item padrão, mesmo se ele estiver desabilitado.<br /><br /> Por padrão, a função ignora itens desabilitados ou esmaecidos.|  
  
 *fByPos*  
 Valor que especifica se é necessário recuperar o identificador do item de menu ou sua posição. Se esse parâmetro for FALSE, o identificador é retornado. Caso contrário, a posição será retornada.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função for bem-sucedida, o valor de retorno é o identificador ou a posição do item de menu. Se a função falhar, o valor de retorno é - 1.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da função Win32 [GetMenuDefaultItem](/windows/desktop/api/winuser/nf-winuser-getmenudefaultitem), conforme descrito no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="getmenucontexthelpid"></a>  CMenu::GetMenuContextHelpId  
 Recupera a Ajuda de contexto ID associada `CMenu`.  
  
```  
DWORD GetMenuContextHelpId() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A Ajuda de contexto ID atualmente associado `CMenu` se houver; caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="getmenuinfo"></a>  CMenu::GetMenuInfo  
 Recupera informações de um menu.  
  
```  
BOOL GetMenuInfo(LPMENUINFO lpcmi) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpcmi*  
 Um ponteiro para um [MENUINFO](/windows/desktop/api/winuser/ns-winuser-tagmenuinfo) estrutura que contém informações para o menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função for bem-sucedida, o valor de retorno é diferente de zero; Caso contrário, o valor de retorno é zero.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar informações sobre o menu.  
  
##  <a name="getmenuitemcount"></a>  CMenu::GetMenuItemCount  
 Determina o número de itens em um menu pop-up ou de nível superior.  
  
```  
UINT GetMenuItemCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens de menu que se a função for bem-sucedida; Caso contrário,-1.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::GetMenu](../../mfc/reference/cwnd-class.md#getmenu).  
  
##  <a name="getmenuitemid"></a>  CMenu::GetMenuItemID  
 Obtém o identificador do item de menu para um item de menu localizado na posição definida pela *nPos*.  
  
```  
UINT GetMenuItemID(int nPos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nPos*  
 Especifica a posição (baseado em zero) do item de menu cuja ID está sendo recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID do item para o item especificado em um menu pop-up, se a função for bem-sucedida. Se o item especificado é um menu pop-up (em vez de um item de menu pop-up), o valor de retorno é -1. Se *nPos* corresponde a um item de menu SEPARADOR, o valor retornado será 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="getmenuiteminfo"></a>  CMenu::GetMenuItemInfo  
 Recupera informações sobre um item de menu.  
  
```  
BOOL GetMenuItemInfo(
    UINT uItem,  
    LPMENUITEMINFO lpMenuItemInfo,  
    BOOL fByPos = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *uItem*  
 Identificador ou a posição do item de menu para obter informações sobre. O significado desse parâmetro depende do valor de `ByPos`.  
  
 *lpMenuItemInfo*  
 Um ponteiro para um [MENUITEMINFO](/windows/desktop/api/winuser/ns-winuser-tagmenuiteminfoa), conforme descrito no SDK do Windows, que contém informações sobre o menu.  
  
 *fByPos*  
 Valor que especifica o significado de `nIDItem`. Por padrão, `ByPos` é FALSE, o que indica que uItem é um identificador de item de menu. Se `ByPos` não está definido como FALSE, isso indica uma posição de item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função for bem-sucedida, o valor de retorno é diferente de zero. Se a função falhar, o valor retornado será zero. Para obter outras informações de erro, use a função Win32 [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360), conforme descrito no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento das da função Win32 [GetMenuItemInfo](/windows/desktop/api/winuser/nf-winuser-getmenuiteminfoa), conforme descrito no SDK do Windows. Observe que na implementação MFC de `GetMenuItemInfo`, você não usar um identificador para um menu.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#26](../../mfc/reference/codesnippet/cpp/cmenu-class_6.cpp)]  
  
##  <a name="getmenustate"></a>  CMenu::GetMenuState  
 Retorna o status do item de menu especificado ou o número de itens em um menu pop-up.  
  
```  
UINT GetMenuState(
    UINT nID,  
    UINT nFlags) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nID*  
 Especifica a ID do item de menu, conforme determinado pela *nFlags*.  
  
 *nFlags*  
 Especifica a natureza da *nID*. Ele pode ser um dos seguintes valores:  
  
- MF_BYCOMMAND Especifica que o parâmetro fornece a ID de comando do item de menu existente. Esse é o padrão.  
  
- MF_BYPOSITION Especifica que o parâmetro fornece a posição do item de menu existente. É o primeiro item na posição 0.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de 0xFFFFFFFF se o item especificado não existe. Se *nId* identifica um menu pop-up, o byte de ordem superior contém o número de itens no menu pop-up e o byte de ordem inferior contém os sinalizadores de menu associados com o menu pop-up. Caso contrário, o valor retornado é uma máscara (ou booliano) dos valores na lista a seguir (essa máscara descreve o status do menu de item que *nId* identifica):  
  
- Atua de MF_CHECKED como uma alternância com MF_UNCHECKED para colocar o padrão Verifique marca ao lado do item. Quando o aplicativo fornece a marca de seleção bitmaps (veja a `SetMenuItemBitmaps` função de membro), o bitmap de "marca de seleção no" é exibido.  
  
- MF_DISABLED desabilita o item de menu para que ele não pode ser selecionado, mas não esmaecer a ele.  
  
- MF_ENABLED permite que o item de menu para que ele pode ser selecionado e restaurá-lo de seu estado esmaecido. Observe que o valor dessa constante é 0; um aplicativo não deve testar em relação a 0 para Falha ao usar esse valor.  
  
- MF_GRAYED desabilita o item de menu para que ele não pode ser selecionado e escurece-lo.  
  
- MF_MENUBARBREAK coloca o item em uma nova linha em menus estáticas ou em uma nova coluna nos menus pop-up. A nova coluna de menu pop-up será ser separada de coluna antiga por uma linha divisória vertical.  
  
- MF_MENUBREAK coloca o item em uma nova linha em menus estáticas ou em uma nova coluna nos menus pop-up. Nenhuma linha divisória é colocada entre as colunas.  
  
- MF_SEPARATOR desenha uma linha divisória horizontal. Só pode ser usado em um menu pop-up. Essa linha não pode ser esmaecida, desabilitada ou realçada. Outros parâmetros serão ignorados.  
  
- MF_UNCHECKED atua como um controle de alternância com MF_CHECKED para remover uma marca de seleção próxima ao item. Quando o aplicativo fornece a marca de seleção bitmaps (veja a `SetMenuItemBitmaps` função de membro), o bitmap de "marca de seleção off" é exibido. Observe que o valor dessa constante é 0; um aplicativo não deve testar em relação a 0 para Falha ao usar esse valor.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#27](../../mfc/reference/codesnippet/cpp/cmenu-class_7.cpp)]  
  
##  <a name="getmenustring"></a>  CMenu::GetMenuString  
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
  
### <a name="parameters"></a>Parâmetros  
 *nIDItem*  
 Especifica o identificador do inteiro do item de menu ou o deslocamento do item de menu no menu, dependendo do valor de *nFlags*.  
  
 *lpString*  
 Aponta para o buffer que receberá o rótulo.  
  
 *rString*  
 Uma referência a um `CString` objeto que deve receber a cadeia de caracteres copiada do menu.  
  
 *nMaxCount*  
 Especifica o comprimento máximo (em caracteres) do rótulo a ser copiado. Se o rótulo é maior que o máximo especificado na *nMaxCount*, os caracteres extras são truncados.  
  
 *nFlags*  
 Especifica a interpretação do *nIDItem* parâmetro. Ele pode ser um dos seguintes valores:  
  
|nFlags|Interpretação de nIDItem|  
|------------|-------------------------------|  
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Se nem MF_BYCOMMAND nem MF_BYPOSITION for definido, esse é o padrão.|  
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. É o primeiro item na posição 0.|  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o número real de caracteres copiados para o buffer, não incluindo o terminador nulo.  
  
### <a name="remarks"></a>Comentários  
 O *nMaxCount* parâmetro deve ser um maior do que o número de caracteres no rótulo para acomodar o caractere nulo que termina com uma cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="getsafehmenu"></a>  CMenu::GetSafeHmenu  
 Retorna o HMENU encapsulado por esse `CMenu` objeto ou um valor nulo`CMenu` ponteiro.  
  
```  
HMENU GetSafeHmenu() const;  
```  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::LoadMenu](#loadmenu).  
  
##  <a name="getsubmenu"></a>  CMenu::GetSubMenu  
 Recupera o `CMenu` objeto de um menu pop-up.  
  
```  
CMenu* GetSubMenu(int nPos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nPos*  
 Especifica a posição do menu pop-up contido no menu. Valores de posição começam em 0 para o primeiro item de menu. Identificador do menu pop-up não pode ser usado nessa função.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CMenu` do objeto cuja `m_hMenu` membro contém um identificador para o menu pop-up exista um menu pop-up na posição determinada; caso contrário, nulo. Se um `CMenu` objeto não existe e, em seguida, um temporário será criado. O `CMenu` ponteiro retornado não deve ser armazenado.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::TrackPopupMenu](#trackpopupmenu).  
  
##  <a name="insertmenu"></a>  CMenu::InsertMenu  
 Insere um novo item de menu na posição especificada por *nPosition* e move os outros itens do menu suspenso.  
  
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
 *nPosition*  
 Especifica o item de menu antes da qual o novo item de menu deve ser inserido. O *nFlags* parâmetro pode ser usado para interpretar *nPosition* das seguintes maneiras:  
  
|nFlags|Interpretação de nPosition|  
|------------|---------------------------------|  
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Se nem MF_BYCOMMAND nem MF_BYPOSITION for definido, esse é o padrão.|  
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. É o primeiro item na posição 0. Se *nPosition* é -1, o novo item de menu é acrescentado ao final do menu.|  
  
 *nFlags*  
 Especifica como *nPosition* é interpretado e especifica informações sobre o estado do novo item de menu quando ele é adicionado ao menu. Para obter uma lista dos sinalizadores que podem ser definidas, consulte o [AppendMenu](#appendmenu) função de membro. Para especificar mais de um valor, use o operador OR bit a bit para combiná-los com o sinalizador MF_BYCOMMAND ou MF_BYPOSITION.  
  
 *nIDNewItem*  
 Especifica a ID de comando do novo item de menu ou, se *nFlags* é definido como MF_POPUP, o identificador do menu (HMENU) do menu pop-up. O *nIDNewItem* parâmetro será ignorado (não necessárias) se *nFlags* é definido como MF_SEPARATOR.  
  
 *lpszNewItem*  
 Especifica o conteúdo do novo item de menu. *nFlags* pode ser usado para interpretar *lpszNewItem* das seguintes maneiras:  
  
|nFlags|Interpretação de lpszNewItem|  
|------------|-----------------------------------|  
|MF_OWNERDRAW|Contém um valor de 32 bits fornecida pelo aplicativo que o aplicativo pode usar para manter os dados adicionais associados ao item de menu. Esse valor de 32 bits está disponível para o aplicativo na `itemData` membro da estrutura fornecido pelo [WM_MEASUREITEM](/windows/desktop/Controls/wm-measureitem) e [WM_DRAWITEM](/windows/desktop/Controls/wm-drawitem) mensagens. Essas mensagens são enviadas quando o item de menu é exibido inicialmente ou é alterado.|  
|MF_STRING|Contém um ponteiro longo para uma cadeia de caracteres terminada em nulo. Essa é a interpretação padrão.|  
|MF_SEPARATOR|O *lpszNewItem* parâmetro é ignorado (não é necessária).|  
  
 *pBmp*  
 Aponta para um `CBitmap` objeto que será usado como o item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O aplicativo pode especificar o estado do item de menu, definindo valores no *nFlags*.  
  
 Sempre que um menu que reside em uma janela é alterada (se a janela é exibida), o aplicativo deve chamar `CWnd::DrawMenuBar`.  
  
 Quando *nIDNewItem* Especifica um menu pop-up, ele se torna parte do menu no qual ele é inserido. Se esse menu for destruído, o menu inseridos também será destruído. Um menu inserido deve ser desanexado de um `CMenu` objeto para evitar conflitos.  
  
 Se o ativo vários janela filho da MDI (interface MDI) documento estiver maximizada e um aplicativo insere um menu pop-up no menu do aplicativo MDI chamando essa função e especificando que o sinalizador MF_BYPOSITION, o menu é inserida uma posição mais distante à esquerda que espera-se. Isso acontece porque o menu de controle da janela filho MDI ativo é inserido na primeira posição da barra de menus da janela de quadro MDI. Para posicionar o menu corretamente, o aplicativo deve adicionar 1 ao que seria usado caso contrário, o valor da posição. Um aplicativo pode usar a mensagem WM_MDIGETACTIVE para determinar se a janela filho ativa no momento é maximizada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#28](../../mfc/reference/codesnippet/cpp/cmenu-class_8.cpp)]  
  
##  <a name="insertmenuitem"></a>  CMenu::InsertMenuItem  
 Insere um novo item de menu na posição especificada em um menu.  
  
```  
BOOL InsertMenuItem(
    UINT uItem,  
    LPMENUITEMINFO lpMenuItemInfo,  
    BOOL fByPos = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *uItem*  
 Consulte a descrição da *uItem* na [InsertMenuItem](/windows/desktop/api/winuser/nf-winuser-insertmenuitema) no SDK do Windows.  
  
 *lpMenuItemInfo*  
 Consulte a descrição da *lpmii* em `InsertMenuItem` no SDK do Windows.  
  
 *fByPos*  
 Consulte a descrição da *fByPosition* em `InsertMenuItem` no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Essa função encapsula [InsertMenuItem](/windows/desktop/api/winuser/nf-winuser-insertmenuitema), descrito no SDK do Windows.  
  
##  <a name="loadmenu"></a>  CMenu::LoadMenu  
 Carrega um recurso de menu do arquivo executável do aplicativo e anexa-o para o `CMenu` objeto.  
  
```  
BOOL LoadMenu(LPCTSTR lpszResourceName);  
BOOL LoadMenu(UINT nIDResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszResourceName*  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso de menu para carregar.  
  
 *nIDResource*  
 Especifica a ID do menu do recurso de menu para carregar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o recurso de menu foi carregado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Antes de sair, um aplicativo deve liberar recursos do sistema associados com um menu se o menu não for atribuído a uma janela. Um aplicativo libera um menu chamando o [DestroyMenu](#destroymenu) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#29](../../mfc/reference/codesnippet/cpp/cmenu-class_9.cpp)]  
  
##  <a name="loadmenuindirect"></a>  CMenu::LoadMenuIndirect  
 Carrega um recurso de um modelo de menu na memória e anexa-o para o `CMenu` objeto.  
  
```  
BOOL LoadMenuIndirect(const void* lpMenuTemplate);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpMenuTemplate*  
 Aponta para um modelo do menu (que é uma única [MENUITEMTEMPLATEHEADER](/windows/desktop/api/winuser/ns-winuser-menuitemtemplateheader) estrutura e uma coleção de um ou mais [MENUITEMTEMPLATE](/windows/desktop/api/winuser/ns-winuser-menuitemtemplate) estruturas). Para obter mais informações sobre essas duas estruturas, consulte o SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o recurso de menu foi carregado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um modelo de menu é um cabeçalho seguido por uma coleção de um ou mais [MENUITEMTEMPLATE](/windows/desktop/api/winuser/ns-winuser-menuitemtemplate) estruturas, cada um deles pode conter um ou mais itens de menu e menus pop-up.  
  
 O número de versão deve ser 0.  
  
 O `mtOption` sinalizadores devem incluir MF_END para o último item em uma lista pop-up e para o último item na lista principal. Consulte o `AppendMenu` a função de membro para outros sinalizadores. O `mtId` membro deve ser omitido da estrutura de MENUITEMTEMPLATE quando MF_POPUP é especificado em `mtOption`.  
  
 O espaço alocado para a estrutura MENUITEMTEMPLATE deve ser grande o suficiente para `mtString` para conter o nome do item de menu, como uma cadeia de caracteres terminada em nulo.  
  
 Antes de sair, um aplicativo deve liberar recursos do sistema associados com um menu se o menu não for atribuído a uma janela. Um aplicativo libera um menu chamando o [DestroyMenu](#destroymenu) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#30](../../mfc/reference/codesnippet/cpp/cmenu-class_10.cpp)]  
  
##  <a name="m_hmenu"></a>  CMenu::m_hMenu  
 Especifica o identificador HMENU do menu Windows anexado ao `CMenu` objeto.  
  
```  
HMENU m_hMenu;  
```  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::LoadMenu](#loadmenu).  
  
##  <a name="measureitem"></a>  CMenu::MeasureItem  
 Chamado pelo framework quando um menu com o estilo de desenho proprietário é criado.  
  
```  
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpMeasureItemStruct*  
 Um ponteiro para um `MEASUREITEMSTRUCT` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função membro não faz nada. Substituir essa função de membro e preencha o `MEASUREITEMSTRUCT` estrutura para informar ao Windows das dimensões do menu.  
  
 Ver [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter uma descrição de `MEASUREITEMSTRUCT` estrutura.  
  
### <a name="example"></a>Exemplo  
 O código a seguir é de MFC [CTRLTEST](../../visual-cpp-samples.md) exemplo:  
  
 [!code-cpp[NVC_MFCWindowing#31](../../mfc/reference/codesnippet/cpp/cmenu-class_11.cpp)]  
  
##  <a name="modifymenu"></a>  CMenu::ModifyMenu  
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
 *nPosition*  
 Especifica o item de menu a ser alterado. O *nFlags* parâmetro pode ser usado para interpretar *nPosition* das seguintes maneiras:  
  
|nFlags|Interpretação de nPosition|  
|------------|---------------------------------|  
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Se nem MF_BYCOMMAND nem MF_BYPOSITION for definido, esse é o padrão.|  
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. É o primeiro item na posição 0.|  
  
 *nFlags*  
 Especifica como *nPosition* é interpretado e fornece informações sobre as alterações feitas para o item de menu. Para obter uma lista de sinalizadores que podem ser definidas, consulte o [AppendMenu](#appendmenu) função de membro.  
  
 *nIDNewItem*  
 Especifica a ID de comando do item de menu modificado ou, se *nFlags* é definido como MF_POPUP, o identificador do menu (HMENU) de um menu pop-up. O *nIDNewItem* parâmetro será ignorado (não necessárias) se *nFlags* é definido como MF_SEPARATOR.  
  
 *lpszNewItem*  
 Especifica o conteúdo do novo item de menu. O *nFlags* parâmetro pode ser usado para interpretar *lpszNewItem* das seguintes maneiras:  
  
|nFlags|Interpretação de lpszNewItem|  
|------------|-----------------------------------|  
|MF_OWNERDRAW|Contém um valor de 32 bits fornecida pelo aplicativo que o aplicativo pode usar para manter os dados adicionais associados ao item de menu. Esse valor de 32 bits está disponível para o aplicativo quando ele processa MF_MEASUREITEM e MF_DRAWITEM.|  
|MF_STRING|Contém um ponteiro longo para uma cadeia de caracteres terminada em nulo ou um `CString`.|  
|MF_SEPARATOR|O *lpszNewItem* parâmetro é ignorado (não é necessária).|  
  
 *pBmp*  
 Aponta para um `CBitmap` objeto que será usado como o item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O aplicativo especifica o novo estado do item de menu, definindo valores no *nFlags*. Se essa função substitui um menu pop-up associado ao item de menu, ele destrói o antigo menu pop-up e libera a memória usada pelo menu pop-up.  
  
 Quando *nIDNewItem* Especifica um menu pop-up, ele se torna parte do menu no qual ele é inserido. Se esse menu for destruído, o menu inseridos também será destruído. Um menu inserido deve ser desanexado de um `CMenu` objeto para evitar conflitos.  
  
 Sempre que um menu que reside em uma janela é alterada (se a janela é exibida), o aplicativo deve chamar `CWnd::DrawMenuBar`. Para alterar os atributos de itens de menu existentes, é muito mais rápido usar o `CheckMenuItem` e `EnableMenuItem` funções de membro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="operator_hmenu"></a>  CMenu::operator HMENU  
 Use este operador para recuperar o identificador do `CMenu` objeto.  
  
```  
operator HMENU() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o identificador do `CMenu` objeto; caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar o identificador para chamar diretamente as APIs do Windows.  
  
##  <a name="operator_neq"></a>  CMenu::operator! =  
 Determina se dois menus logicamente não são iguais.  
  
```  
BOOL operator!=(const CMenu& menu) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Menu*  
 Um `CMenu` objeto para comparação.  
  
### <a name="remarks"></a>Comentários  
 Testa se um objeto de menu no lado esquerdo não for igual a um objeto de menu no lado direito.  
  
##  <a name="operator_eq_eq"></a>  CMenu::operator = =  
 Determina se dois menus são logicamente iguais.  
  
```  
BOOL operator==(const CMenu& menu) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Menu*  
 Um `CMenu` objeto para comparação.  
  
### <a name="remarks"></a>Comentários  
 Testa se um objeto de menu no lado esquerdo for igual (em termos do valor HMENU) a um objeto de menu no lado direito.  
  
##  <a name="removemenu"></a>  CMenu::RemoveMenu  
 Exclui um item de menu com um menu pop-up associado no menu.  
  
```  
BOOL RemoveMenu(
    UINT nPosition,  
    UINT nFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nPosition*  
 Especifica o item de menu a ser removido. O *nFlags* parâmetro pode ser usado para interpretar *nPosition* das seguintes maneiras:  
  
|nFlags|Interpretação de nPosition|  
|------------|---------------------------------|  
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Se nem MF_BYCOMMAND nem MF_BYPOSITION for definido, esse é o padrão.|  
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. É o primeiro item na posição 0.|  
  
 *nFlags*  
 Especifica como *nPosition* é interpretado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele não destrói o identificador para um menu pop-up, portanto, o menu pode ser reutilizado. Antes de chamar essa função, o aplicativo pode chamar o `GetSubMenu` função de membro para recuperar o pop-up `CMenu` objeto para reutilização.  
  
 Sempre que um menu que reside em uma janela é alterada (se a janela é exibida), o aplicativo deve chamar `CWnd::DrawMenuBar`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="setdefaultitem"></a>  CMenu::SetDefaultItem  
 Define o item de menu padrão para o menu especificado.  
  
```  
BOOL SetDefaultItem(
    UINT uItem,  
    BOOL fByPos = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *uItem*  
 Identificador ou a posição do novo item de menu padrão ou - 1 para nenhum item padrão. O significado desse parâmetro depende do valor de *fByPos*.  
  
 *fByPos*  
 Valor que especifica o significado dos *uItem*. Se esse parâmetro for FALSE, o *uItem* é um identificador de item de menu. Caso contrário, ele é uma posição de item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função for bem-sucedida, o valor de retorno é diferente de zero. Se a função falhar, o valor retornado será zero. Para obter outras informações de erro, use a função Win32 [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360), conforme descrito no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da função Win32 [SetMenuDefaultItem](/windows/desktop/api/winuser/nf-winuser-setmenudefaultitem), conforme descrito no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="setmenucontexthelpid"></a>  CMenu::SetMenuContextHelpId  
 Associa uma ID de ajuda de contexto com `CMenu`.  
  
```  
BOOL SetMenuContextHelpId(DWORD dwContextHelpId);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwContextHelpId*  
 Identificação de ajuda de contexto para associar `CMenu`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0  
  
### <a name="remarks"></a>Comentários  
 Todos os itens no menu de compartilham esse identificador — não é possível anexar um identificador de contexto de ajuda para os itens de menu individuais.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="setmenuinfo"></a>  CMenu::SetMenuInfo  
 Define informações de um menu.  
  
```  
BOOL SetMenuInfo(LPCMENUINFO lpcmi);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpcmi*  
 Um ponteiro para um [MENUINFO](/windows/desktop/api/winuser/ns-winuser-tagmenuinfo) estrutura que contém informações para o menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função for bem-sucedida, o valor de retorno é diferente de zero; Caso contrário, o valor de retorno é zero.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para definir informações específicas sobre o menu.  
  
##  <a name="setmenuitembitmaps"></a>  CMenu::SetMenuItemBitmaps  
 Associa os bitmaps especificados com um item de menu.  
  
```  
BOOL SetMenuItemBitmaps(
    UINT nPosition,  
    UINT nFlags,  
    const CBitmap* pBmpUnchecked,  
    const CBitmap* pBmpChecked);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nPosition*  
 Especifica o item de menu a ser alterado. O *nFlags* parâmetro pode ser usado para interpretar *nPosition* das seguintes maneiras:  
  
|nFlags|Interpretação de nPosition|  
|------------|---------------------------------|  
|MF_BYCOMMAND|Especifica que o parâmetro fornece a ID de comando do item de menu existente. Se nem MF_BYCOMMAND nem MF_BYPOSITION for definido, esse é o padrão.|  
|MF_BYPOSITION|Especifica que o parâmetro fornece a posição do item de menu existente. É o primeiro item na posição 0.|  
  
 *nFlags*  
 Especifica como *nPosition* é interpretado.  
  
 *pBmpUnchecked*  
 Especifica o bitmap a ser usado para itens de menu que não são verificados.  
  
 *pBmpChecked*  
 Especifica o bitmap a ser usado para itens de menu que são verificados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o item de menu está marcado ou desmarcado, o Windows exibe o bitmap apropriado ao lado do item de menu.  
  
 Se qualquer um dos *pBmpUnchecked* ou *pBmpChecked* for NULL, em seguida, o Windows não exibirá nada próxima ao item de menu para o atributo correspondente. Se ambos os parâmetros forem nulos, o Windows usa a marca de seleção padrão quando o item está marcado e remove a marca de seleção, quando o item está desmarcado.  
  
 Quando o menu é destruído, esses bitmaps não são destruídos; o aplicativo deverá destruí-los.  
  
 O Windows `GetMenuCheckMarkDimensions` função recupera as dimensões da marca de seleção padrão usado para itens de menu. O aplicativo usa esses valores para determinar o tamanho apropriado para os bitmaps fornecidos com essa função. Obter o tamanho, criar seus bitmaps e, em seguida, defini-las.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#32](../../mfc/reference/codesnippet/cpp/cmenu-class_12.cpp)]  
  
 [!code-cpp[NVC_MFCWindowing#33](../../mfc/reference/codesnippet/cpp/cmenu-class_13.cpp)]  
  
##  <a name="setmenuiteminfo"></a>  CMenu::SetMenuItemInfo  
 Altera as informações sobre um item de menu.  
  
```  
BOOL SetMenuItemInfo(
    UINT uItem,  
    LPMENUITEMINFO lpMenuItemInfo,  
    BOOL fByPos = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *uItem*  
 Consulte a descrição da *uItem* na [SetMenuItemInfo](/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa) no SDK do Windows.  
  
 *lpMenuItemInfo*  
 Consulte a descrição da *lpmii* em `SetMenuItemInfo` no SDK do Windows.  
  
 *fByPos*  
 Consulte a descrição da *fByPosition* em `SetMenuItemInfo` no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Essa função encapsula [SetMenuItemInfo](/windows/desktop/api/winuser/nf-winuser-setmenuiteminfoa), descrito no SDK do Windows.  
  
##  <a name="trackpopupmenu"></a>  CMenu::TrackPopupMenu  
 Exibe um menu pop-up flutuante no local especificado e controla a seleção de itens no menu pop-up.  
  
```  
BOOL TrackPopupMenu(
    UINT nFlags,  
    int x,  
    int y,  
    CWnd* pWnd,  
    LPCRECT lpRect = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nFlags*  
 Especifica os sinalizadores de posição da tela e a posição do mouse. Ver [TrackPopupMenu](/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) para obter uma lista de sinalizadores disponíveis.  
  
 *x*  
 Especifica a posição horizontal em coordenadas de tela do menu pop-up. Dependendo do valor da *nFlags* parâmetro, o menu pode ser alinhado à esquerda, alinhado à direita ou centralizado em relação a essa posição.  
  
 *y*  
 Especifica a posição vertical em coordenadas de tela da parte superior do menu na tela.  
  
 *Apropriei*  
 Identifica a janela que possui um menu pop-up. Esse parâmetro não pode ser NULL, mesmo se o sinalizador TPM_NONOTIFY for especificado. Esta janela recebe todas as mensagens WM_COMMAND no menu. No Windows versões 3.1 e posteriores, a janela não recebe mensagens WM_COMMAND até `TrackPopupMenu` retorna. No Windows 3.0, a janela recebe mensagens WM_COMMAND antes `TrackPopupMenu` retorna.  
  
 *lpRect*  
 Ignorado.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna o resultado da chamada [TrackPopupMenu](/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Um menu pop-up flutuante pode aparecer em qualquer lugar na tela.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#34](../../mfc/reference/codesnippet/cpp/cmenu-class_14.cpp)]  
  
##  <a name="trackpopupmenuex"></a>  CMenu::TrackPopupMenuEx  
 Exibe um menu pop-up flutuante no local especificado e controla a seleção de itens no menu pop-up.  
  
```  
BOOL TrackPopupMenuEx(
    UINT fuFlags,  
    int x,  
    int y,  
    CWnd* pWnd,  
    LPTPMPARAMS lptpm);
```  
  
### <a name="parameters"></a>Parâmetros  
 *fuFlags*  
 Especifica várias funções para o menu estendido. Para obter uma lista de todos os valores e seu significado, consulte [TrackPopupMenuEx](/windows/desktop/api/winuser/nf-winuser-trackpopupmenuex).  
  
 *x*  
 Especifica a posição horizontal em coordenadas de tela do menu pop-up.  
  
 *y*  
 Especifica a posição vertical em coordenadas de tela da parte superior do menu na tela.  
  
 *Apropriei*  
 Um ponteiro para a janela proprietária do menu pop-up e recebimento de mensagens do menu criado. Esta janela pode ser qualquer janela do aplicativo atual, mas não pode ser NULL. Se você especificar TPM_NONOTIFY na *fuFlags* parâmetro, a função não envia mensagens a serem *Apropriei*. A função deve retornar para a janela apontada por *Apropriei* para receber a mensagem WM_COMMAND.  
  
 *lptpm*  
 Ponteiro para um [TPMPARAMS](/windows/desktop/api/winuser/ns-winuser-tagtpmparams) não deve se sobrepor a estrutura que especifica uma área da tela do menu. Esse parâmetro pode ser NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Se você especificar TPM_RETURNCMD na *fuFlags* parâmetro, o valor de retorno é o identificador do item de menu do item selecionado pelo usuário. Se o usuário cancelar o menu sem fazer uma seleção, ou se ocorrer um erro, o valor de retorno é 0.  
  
 Se você não especificar TPM_RETURNCMD na *fuFlags* parâmetro, o valor de retorno é diferente de zero se a função for bem-sucedida e 0 se ele falhar. Para obter outras informações de erro, chame [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Um menu pop-up flutuante pode aparecer em qualquer lugar na tela. Para obter mais informações sobre como tratar erros ao criar o menu pop-up, consulte [TrackPopupMenuEx](/windows/desktop/api/winuser/nf-winuser-trackpopupmenuex).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLTEST](../../visual-cpp-samples.md)   
 [Exemplo MFC DYNAMENU](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)
