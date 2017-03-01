---
title: Classe CMenu | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMenu
dev_langs:
- C++
helpviewer_keywords:
- HMENU
- menus, class
- menus, base class
- menus, creating
- menus, managing
- CMenu class
ms.assetid: 40cacfdc-d45c-4ec7-bf28-991c72812499
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: dcd353bf0be5d23c1782347f54b16a875ed190ed
ms.lasthandoff: 02/25/2017

---
# <a name="cmenu-class"></a>Classe CMenu
Um encapsulamento do Windows `HMENU`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMenu : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMenu::CMenu](#cmenu)|Constrói um objeto `CMenu`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMenu::AppendMenu](#appendmenu)|Acrescenta um novo item ao final desse menu.|  
|[CMenu::Attach](#attach)|Anexa um identificador de menu do Windows para uma `CMenu` objeto.|  
|[CMenu::CheckMenuItem](#checkmenuitem)|Coloque uma marca de seleção ao lado ou remove uma marca de seleção de um item de menu no menu pop-up.|  
|[CMenu::CheckMenuRadioItem](#checkmenuradioitem)|Coloca um botão de opção ao lado de um item de menu e remove todos os outros itens de menu no grupo de botão de opção.|  
|[CMenu::CreateMenu](#createmenu)|Cria um menu vazio e a anexa a um `CMenu` objeto.|  
|[CMenu::CreatePopupMenu](#createpopupmenu)|Cria um menu pop-up vazio e a anexa a um `CMenu` objeto.|  
|[CMenu::DeleteMenu](#deletemenu)|Exclui um item especificado no menu. Se o item de menu tem um menu pop-up associado, destrói o identificador do menu pop-up e libera a memória usada por ele.|  
|[CMenu::DeleteTempMap](#deletetempmap)|Exclui qualquer temporário `CMenu` objetos criados pelo `FromHandle` função de membro.|  
|[CMenu::DestroyMenu](#destroymenu)|Destrói o menu anexado a um `CMenu` de objeto e libera qualquer memória que o menu ocupado.|  
|[CMenu::Detach](#detach)|Desanexa um identificador de menu do Windows de um `CMenu` de objeto e retorna o identificador.|  
|[CMenu::DrawItem](#drawitem)|Chamado pela estrutura quando um aspecto visual das alterações menu desenhados pelo proprietário.|  
|[CMenu::EnableMenuItem](#enablemenuitem)|Habilita, desabilita ou esmaece (cinza) um item de menu.|  
|[CMenu::FromHandle](#fromhandle)|Retorna um ponteiro para um `CMenu` objeto recebe um identificador de menu do Windows.|  
|[CMenu::GetDefaultItem](#getdefaultitem)|Determina o item de menu padrão no menu especificado.|  
|[CMenu::GetMenuContextHelpId](#getmenucontexthelpid)|Recupera a ID do contexto de ajuda associada com o menu.|  
|[CMenu::GetMenuInfo](#getmenuinfo)|Recupera informações em um menu específico.|  
|[CMenu::GetMenuItemCount](#getmenuitemcount)|Determina o número de itens em um menu pop-up ou de nível superior.|  
|[CMenu::GetMenuItemID](#getmenuitemid)|Obtém o identificador do item de menu de um item de menu localizado na posição especificada.|  
|[CMenu::GetMenuItemInfo](#getmenuiteminfo)|Recupera informações sobre um item de menu.|  
|[CMenu::GetMenuState](#getmenustate)|Retorna o status do item de menu especificado ou o número de itens em um menu pop-up.|  
|[CMenu::GetMenuString](#getmenustring)|Recupera o rótulo do item de menu especificado.|  
|[CMenu::GetSafeHmenu](#getsafehmenu)|Retorna o `m_hMenu` encapsulado por esse `CMenu` objeto.|  
|[CMenu::GetSubMenu](#getsubmenu)|Recupera um ponteiro para um menu pop-up.|  
|[CMenu::InsertMenu](#insertmenu)|Insere um novo item de menu na posição especificada, movendo outros itens do menu suspenso.|  
|[CMenu::InsertMenuItem](#insertmenuitem)|Insere um novo item de menu na posição especificada em um menu.|  
|[CMenu::LoadMenu](#loadmenu)|Carrega um recurso de menu do arquivo executável e anexa-o para um `CMenu` objeto.|  
|[CMenu::LoadMenuIndirect](#loadmenuindirect)|Carrega um menu de um modelo de menu na memória e anexa a um `CMenu` objeto.|  
|[CMenu::MeasureItem](#measureitem)|Chamado pela estrutura para determinar as dimensões do menu quando é criado um menu desenhados pelo proprietário.|  
|[CMenu::ModifyMenu](#modifymenu)|Altera um item de menu existente na posição especificada.|  
|[CMenu::RemoveMenu](#removemenu)|Exclui um item de menu com um menu pop-up associado ao menu especificado.|  
|[CMenu::SetDefaultItem](#setdefaultitem)|Define o item de menu padrão para o menu especificado.|  
|[CMenu::SetMenuContextHelpId](#setmenucontexthelpid)|Define a ID do contexto de ajuda a ser associado com o menu.|  
|[CMenu::SetMenuInfo](#setmenuinfo)|Define informações sobre um menu específico.|  
|[CMenu::SetMenuItemBitmaps](#setmenuitembitmaps)|Associa os bitmaps de marca de seleção especificada com um item de menu.|  
|[CMenu::SetMenuItemInfo](#setmenuiteminfo)|Altera as informações sobre um item de menu.|  
|[CMenu::TrackPopupMenu](#trackpopupmenu)|Exibe um menu pop-up flutuante no local especificado e controla a seleção de itens no menu pop-up.|  
|[CMenu::TrackPopupMenuEx](#trackpopupmenuex)|Exibe um menu pop-up flutuante no local especificado e controla a seleção de itens no menu pop-up.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMenu::operator HMENU](#operator_hmenu)|Recupera o identificador do objeto menu.|  
|[CMenu::operator! =](#operator_neq)|Determina se dois objetos de menu não são iguais.|  
|[CMenu::operator = =](#operator_eq_eq)|Determina se dois objetos de menu são iguais.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMenu::m_hMenu](#m_hmenu)|Especifica o identificador do menu do Windows conectado ao `CMenu` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Ele fornece funções de membro para criação, controle, atualizando e Destruindo um menu.  
  
 Criar um `CMenu` objeto no quadro da pilha, como um local, em seguida, chame `CMenu`de funções de membro para manipular o novo menu conforme necessário. Em seguida, chame [CWnd::SetMenu](../../mfc/reference/cwnd-class.md#setmenu) definir o menu para uma janela, seguido imediatamente por uma chamada para o `CMenu` do objeto [desanexar](#detach) função de membro. O `CWnd::SetMenu` função membro define o menu da janela para o novo menu, faz com que a janela seja redesenhado para refletir a alteração do menu e também passa a propriedade do menu na janela. A chamada para **desanexar** desanexa o `HMENU` do `CMenu` objeto, isso que, quando o local `CMenu` variável passa fora do escopo, o `CMenu` destruidor do objeto não tenta destruir um menu que ele não possui. O próprio menu é destruído automaticamente quando a janela for destruída.  
  
 Você pode usar o [LoadMenuIndirect](#loadmenuindirect) a função de membro para criar um menu de um modelo na memória, mas um menu criado a partir de um recurso por uma chamada a [LoadMenu](#loadmenu) mais facilmente mantidos, e o próprio recurso de menu pode ser criado e modificado pelo editor de menu.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMenu`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-nameappendmenua--cmenuappendmenu"></a><a name="appendmenu"></a>CMenu::AppendMenu  
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
 `nFlags`  
 Especifica informações sobre o estado do item de menu novo, quando ele é adicionado ao menu. Ele consiste em um ou mais dos valores listados na seção comentários.  
  
 `nIDNewItem`  
 Especifica a ID de comando do item de menu novo ou, se `nFlags` é definido como **MF_POPUP**, o identificador de menu ( `HMENU`) de um menu pop-up. O `nIDNewItem` parâmetro é ignorado (não necessárias) se `nFlags` é definido como **MF_SEPARATOR**.  
  
 `lpszNewItem`  
 Especifica o conteúdo do novo item de menu. O `nFlags` parâmetro é usado para interpretar `lpszNewItem` da seguinte maneira:  
  
|nFlags|Interpretação de lpszNewItem|  
|------------|-----------------------------------|  
|`MF_OWNERDRAW`|Contém um valor de 32 bits fornecida pelo aplicativo que o aplicativo pode usar para manter dados adicionais associados ao item de menu. Esse valor de 32 bits está disponível para o aplicativo quando ele processa `WM_MEASUREITEM` e `WM_DRAWITEM` mensagens. O valor é armazenado no **itemData** membro da estrutura fornecido com essas mensagens.|  
|**MF_STRING**|Contém um ponteiro para uma cadeia de caracteres terminada em nulo. Essa é a interpretação padrão.|  
|**MF_SEPARATOR**|O `lpszNewItem` parâmetro é ignorado (não é necessária).|  
  
 *pBmp*  
 Aponta para um `CBitmap` objeto que será usado como o item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O aplicativo pode especificar o estado do item de menu, definindo valores no `nFlags`. Quando `nIDNewItem` Especifica um menu pop-up, ela se torna parte do menu ao qual ele está anexado. Se esse menu for destruído, o menu acrescentado também será destruído. Um menu acrescentado deve ser desanexado de um `CMenu` objeto para evitar conflitos. Observe que **MF_STRING** e `MF_OWNERDRAW` não são válidos para a versão de bitmap do `AppendMenu`.  
  
 A lista a seguir descreve os sinalizadores que podem ser definidos em `nFlags`:  
  
- **MF_CHECKED** atua como uma alternância com **MF_UNCHECKED** para colocar a marca de seleção ao lado do item padrão. Quando o aplicativo fornece bitmaps de marca de seleção (consulte a [SetMenuItemBitmaps](#setmenuitembitmaps) função de membro), o bitmap de "marca de seleção no" é exibido.  
  
- **MF_UNCHECKED** atua como uma alternância com **MF_CHECKED** para remover uma marca de seleção ao lado do item. Quando o aplicativo fornece bitmaps de marca de seleção (consulte a `SetMenuItemBitmaps` função de membro), o bitmap de "marca de seleção off" é exibido.  
  
- **MF_DISABLED** desativa o item de menu para que ele não pode ser selecionado, mas a esmaecer.  
  
- `MF_ENABLED`Permite que o item de menu para que ele pode ser selecionado e restaurá-lo de seu estado esmaecido.  
  
- **MF_GRAYED** desabilita o item de menu para que ele não pode ser selecionado e solicitará a ele.  
  
- **MF_MENUBARBREAK** coloca o item em uma nova linha em menus estáticos ou em uma nova coluna nos menus pop-up. A nova coluna do menu pop-up será separada da coluna antiga por uma linha divisória vertical.  
  
- **MF_MENUBREAK** coloca o item em uma nova linha em menus estáticos ou em uma nova coluna nos menus pop-up. Nenhuma linha divisória é colocada entre as colunas.  
  
- `MF_OWNERDRAW`Especifica que o item é um item de desenho proprietário. Quando o menu é exibido pela primeira vez, a janela que possui o menu recebe um `WM_MEASUREITEM` mensagem, que recupera a altura e largura do item de menu. O `WM_DRAWITEM` mensagem é aquela enviada sempre que o proprietário deve atualizar a aparência visual do item de menu. Essa opção não é válida para um item de menu de nível superior.  
  
- **MF_POPUP** Especifica que o item de menu tem um menu pop-up associado a ele. O parâmetro de ID Especifica um identificador para um menu pop-up que deve ser associado ao item. Isso é usado para adicionar um menu pop-up de nível superior ou um menu pop-up hierárquico para um item de menu pop-up.  
  
- **MF_SEPARATOR** desenha uma linha divisória horizontal. Só pode ser usado em um menu pop-up. Essa linha não pode ser esmaecida, desabilitada ou realçada. Outros parâmetros são ignorados.  
  
- **MF_STRING** Especifica que o item de menu é uma cadeia de caracteres.  
  
 Cada um dos seguintes grupos de listas de sinalizadores que se excluem mutuamente e não podem ser usados juntos:  
  
- **MF_DISABLED**, `MF_ENABLED`, e **MF_GRAYED**  
  
- **MF_STRING**, `MF_OWNERDRAW`, **MF_SEPARATOR**e a versão de bitmap  
  
- **MF_MENUBARBREAK** e **MF_MENUBREAK**  
  
- **MF_CHECKED** e **MF_UNCHECKED**  
  
 Sempre que um menu que reside em uma janela é alterada (ou não a janela é exibida), o aplicativo deve chamar [CWnd::DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::CreateMenu](#createmenu).  
  
##  <a name="a-nameattacha--cmenuattach"></a><a name="attach"></a>CMenu::Attach  
 Anexa um menu existente do Windows para uma `CMenu` objeto.  
  
```  
BOOL Attach(HMENU hMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hMenu`  
 Especifica um identificador para um menu do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função não deve ser chamada se um menu já está anexado ao `CMenu` objeto. O identificador de menu é armazenado no `m_hMenu` membro de dados.  
  
 Se o menu que você deseja manipular já está associado uma janela, você pode usar o [CWnd::GetMenu](../../mfc/reference/cwnd-class.md#getmenu) função para obter um identificador para o menu.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#21;](../../mfc/reference/codesnippet/cpp/cmenu-class_1.cpp)]  
  
##  <a name="a-namecheckmenuitema--cmenucheckmenuitem"></a><a name="checkmenuitem"></a>CMenu::CheckMenuItem  
 Adiciona as marcas de seleção para ou remove as marcas de seleção de itens de menu no menu pop-up.  
  
```  
UINT CheckMenuItem(
    UINT nIDCheckItem,  
    UINT nCheck);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDCheckItem`  
 Especifica o item de menu a ser verificada, conforme determinado por `nCheck`.  
  
 `nCheck`  
 Especifica como verificar o item de menu e como determinar a posição do item no menu. O `nCheck` parâmetro pode ser uma combinação de **MF_CHECKED** ou **MF_UNCHECKED** com **MF_BYPOSITION** ou **MF_BYCOMMAND** sinalizadores. Esses sinalizadores podem ser combinados usando o operador OR bit a bit. Eles têm os seguintes significados:  
  
- **MF_BYCOMMAND** Especifica que o parâmetro retorna a ID de comando do item de menu existente. Esse é o padrão.  
  
- **MF_BYPOSITION** Especifica que o parâmetro retorna a posição do item de menu existente. É o primeiro item na posição 0.  
  
- **MF_CHECKED** atua como uma alternância com **MF_UNCHECKED** para colocar a marca de seleção ao lado do item padrão.  
  
- **MF_UNCHECKED** atua como uma alternância com **MF_CHECKED** para remover uma marca de seleção ao lado do item.  
  
### <a name="return-value"></a>Valor de retorno  
 O estado anterior do item: **MF_CHECKED** ou **MF_UNCHECKED**, ou 0xFFFFFFFF se o item de menu não existe.  
  
### <a name="remarks"></a>Comentários  
 O `nIDCheckItem` parâmetro especifica o item a ser modificado.  
  
 O `nIDCheckItem` parâmetro pode identificar um item de menu pop-up, bem como um item de menu. Nenhuma etapa especial é necessários para verificar se um item de menu pop-up. Itens de menu de nível superior não podem ser verificados. Um item de menu pop-up deve ser verificado por posição, pois ele não tem um identificador de item de menu associado a ele.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::GetMenuState](#getmenustate).  
  
##  <a name="a-namecheckmenuradioitema--cmenucheckmenuradioitem"></a><a name="checkmenuradioitem"></a>CMenu::CheckMenuRadioItem  
 Verifica se um item de menu especificado e o torna um item de rádio.  
  
```  
BOOL CheckMenuRadioItem(
    UINT nIDFirst,  
    UINT nIDLast,  
    UINT nIDItem,  
    UINT nFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDFirst`  
 Especifica (como uma ID ou um deslocamento, dependendo do valor de `nFlags`) o primeiro item de menu no grupo de botões de opção.  
  
 `nIDLast`  
 Especifica (como uma ID ou um deslocamento, dependendo do valor de `nFlags`) o último item de menu no grupo de botões de opção.  
  
 `nIDItem`  
 Especifica (como uma ID ou um deslocamento, dependendo do valor de `nFlags`) o item no grupo que será verificado com um botão de opção.  
  
 `nFlags`  
 Especifica a interpretação de `nIDFirst`, `nIDLast`, e `nIDItem` da seguinte maneira:  
  
|nFlags|Interpretação|  
|------------|--------------------|  
|**MF_BYCOMMAND**|Especifica o parâmetro retorna a ID de comando do item de menu existente. Esse é o padrão se nem **MF_BYCOMMAND** nem **MF_BYPOSITION** está definido.|  
|**MF_BYPOSITION**|Especifica o parâmetro retorna a posição do item de menu existente. É o primeiro item na posição 0.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0  
  
### <a name="remarks"></a>Comentários  
 Ao mesmo tempo, a função desmarca todos os outros itens de menu no grupo associado e limpa o sinalizador de tipo de item de rádio para esses itens. O item selecionado é exibido usando um bitmap de botão (ou marcador) de rádio em vez de um bitmap de marca de seleção.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [ON_COMMAND_RANGE](http://msdn.microsoft.com/library/c52719fc-dd6e-48c9-af79-383f48d608e0).  
  
##  <a name="a-namecmenua--cmenucmenu"></a><a name="cmenu"></a>CMenu::CMenu  
 Cria um menu vazio e a anexa a um `CMenu` objeto.  
  
```  
CMenu();
```  
  
### <a name="remarks"></a>Comentários  
 O menu não é criado até que você chame uma das funções de membro create ou carga de **CMenu:**  
  
- [CreateMenu](#createmenu)  
  
- [CreatePopupMenu](#createpopupmenu)  
  
- [LoadMenu](#loadmenu)  
  
- [LoadMenuIndirect](#loadmenuindirect)  
  
- [Anexar](#attach)  
  
##  <a name="a-namecreatemenua--cmenucreatemenu"></a><a name="createmenu"></a>CMenu::CreateMenu  
 Cria um menu e anexa-o para o `CMenu` objeto.  
  
```  
BOOL CreateMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o menu foi criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O menu é inicialmente vazio. Itens de menu podem ser adicionados usando o `AppendMenu` ou `InsertMenu` função de membro.  
  
 Se o menu é atribuído a uma janela, ele será destruído automaticamente quando a janela for destruída.  
  
 Antes de sair, um aplicativo deve Libere recursos do sistema associados a um menu se o menu não está atribuído a uma janela. Um aplicativo libera um menu chamando o [DestroyMenu](#destroymenu) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#22;](../../mfc/reference/codesnippet/cpp/cmenu-class_2.cpp)]  
  
##  <a name="a-namecreatepopupmenua--cmenucreatepopupmenu"></a><a name="createpopupmenu"></a>CMenu::CreatePopupMenu  
 Cria um menu pop-up e anexa-o para o `CMenu` objeto.  
  
```  
BOOL CreatePopupMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o menu pop-up foi criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O menu é inicialmente vazio. Itens de menu podem ser adicionados usando o `AppendMenu` ou `InsertMenu` função de membro. O aplicativo pode adicionar o menu pop-up para um existente ou no menu pop-up. O `TrackPopupMenu` função de membro pode ser usada para exibir esse menu como um menu pop-up flutuante e acompanhar as seleções no menu pop-up.  
  
 Se o menu é atribuído a uma janela, ele será destruído automaticamente quando a janela for destruída. Se o menu é adicionado a um menu existente, ele será destruído automaticamente quando esse menu é destruído.  
  
 Antes de sair, um aplicativo deve Libere recursos do sistema associados a um menu pop-up se o menu não está atribuído a uma janela. Um aplicativo libera um menu chamando o [DestroyMenu](#destroymenu) função de membro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::CreateMenu](#createmenu).  
  
##  <a name="a-namedeletemenua--cmenudeletemenu"></a><a name="deletemenu"></a>CMenu::DeleteMenu  
 Exclui um item de menu.  
  
```  
BOOL DeleteMenu(
    UINT nPosition,  
    UINT nFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPosition`  
 Especifica o item de menu que deve ser excluída, conforme determinado por `nFlags`.  
  
 `nFlags`  
 É usada para interpretar `nPosition` da seguinte maneira:  
  
|nFlags|Interpretação de nPosition|  
|------------|---------------------------------|  
|**MF_BYCOMMAND**|Especifica o parâmetro retorna a ID de comando do item de menu existente. Esse é o padrão se nem **MF_BYCOMMAND** nem **MF_BYPOSITION** está definido.|  
|**MF_BYPOSITION**|Especifica o parâmetro retorna a posição do item de menu existente. É o primeiro item na posição 0.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o item de menu tem um menu pop-up associado `DeleteMenu` destrói o identificador do menu pop-up e libera a memória usada pelo menu pop-up.  
  
 Sempre que um menu que reside em uma janela é alterada (ou não a janela é exibida), o aplicativo deve chamar [CWnd::DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::GetMenu](../../mfc/reference/cwnd-class.md#getmenu).  
  
##  <a name="a-namedeletetempmapa--cmenudeletetempmap"></a><a name="deletetempmap"></a>CMenu::DeleteTempMap  
 Chamado automaticamente pelo `CWinApp` manipulador de tempo ocioso, exclui qualquer temporário `CMenu` objetos criados pelo [FromHandle](#fromhandle) função de membro.  
  
```  
static void PASCAL DeleteTempMap();
```  
  
### <a name="remarks"></a>Comentários  
 `DeleteTempMap`desanexa o objeto de menu do Windows anexado a um temporário `CMenu` objeto antes de excluir o `CMenu` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#23;](../../mfc/reference/codesnippet/cpp/cmenu-class_3.cpp)]  
  
##  <a name="a-namedestroymenua--cmenudestroymenu"></a><a name="destroymenu"></a>CMenu::DestroyMenu  
 Destrói o menu e quaisquer recursos do Windows que foram usados.  
  
```  
BOOL DestroyMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o menu for destruído; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O menu é desanexado do `CMenu` objeto antes que ele seja destruído. O Windows `DestroyMenu` função é chamada automaticamente `CMenu` destruidor.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::CreateMenu](#createmenu).  
  
##  <a name="a-namedetacha--cmenudetach"></a><a name="detach"></a>CMenu::Detach  
 Desanexa um menu do Windows de um `CMenu` de objeto e retorna o identificador.  
  
```  
HMENU Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de tipo `HMENU`, para um menu do Windows, se bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 O `m_hMenu` membro de dados está definido como **nulo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#21;](../../mfc/reference/codesnippet/cpp/cmenu-class_1.cpp)]  
  
##  <a name="a-namedrawitema--cmenudrawitem"></a><a name="drawitem"></a>CMenu::DrawItem  
 Chamado pela estrutura quando um aspecto visual das alterações menu desenhados pelo proprietário.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura que contém informações sobre o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 O `itemAction` membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CMenu` objeto. O aplicativo deve restaurar todos os objetos GDI (interface) do dispositivo gráfico selecionados para o contexto de exibição fornecidos no `lpDrawItemStruct` antes do término desta função de membro.  
  
 Consulte [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição de `DRAWITEMSTRUCT` estrutura.  
  
### <a name="example"></a>Exemplo  
 O código a seguir é do MFC [CTRLTEST](../../visual-cpp-samples.md) exemplo:  
  
 [!code-cpp[NVC_MFCWindowing&#24;](../../mfc/reference/codesnippet/cpp/cmenu-class_4.cpp)]  
  
##  <a name="a-nameenablemenuitema--cmenuenablemenuitem"></a><a name="enablemenuitem"></a>CMenu::EnableMenuItem  
 Habilita, desabilita ou solicitará um item de menu.  
  
```  
UINT EnableMenuItem(
    UINT nIDEnableItem,  
    UINT nEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDEnableItem*  
 Especifica o item de menu a ser habilitado, conforme determinado por `nEnable`. Esse parâmetro pode especificar os itens de menu pop-up, bem como itens de menu padrão.  
  
 `nEnable`  
 Especifica a ação a ser tomada. Pode ser uma combinação de **MF_DISABLED**, `MF_ENABLED`, ou **MF_GRAYED**, com **MF_BYCOMMAND** ou **MF_BYPOSITION**. Esses valores podem ser combinados usando o operador OR bit a bit. Esses valores têm os seguintes significados:  
  
- **MF_BYCOMMAND** Especifica que o parâmetro retorna a ID de comando do item de menu existente. Esse é o padrão.  
  
- **MF_BYPOSITION** Especifica que o parâmetro retorna a posição do item de menu existente. É o primeiro item na posição 0.  
  
- **MF_DISABLED** desativa o item de menu para que ele não pode ser selecionado, mas a esmaecer.  
  
- `MF_ENABLED`Permite que o item de menu para que ele pode ser selecionado e restaurá-lo de seu estado esmaecido.  
  
- **MF_GRAYED** desabilita o item de menu para que ele não pode ser selecionado e solicitará a ele.  
  
### <a name="return-value"></a>Valor de retorno  
 Estado anterior ( **MF_DISABLED**, `MF_ENABLED`, ou **MF_GRAYED**) ou -1 se não é válido.  
  
### <a name="remarks"></a>Comentários  
 O [CreateMenu](#createmenu), [InsertMenu](#insertmenu), [ModifyMenu](#modifymenu), e [LoadMenuIndirect](#loadmenuindirect) funções de membro também podem definir o estado (habilitado, desabilitado ou esmaecido) de um item de menu.  
  
 Usando o **MF_BYPOSITION** valor requer um aplicativo para usar o correto `CMenu`. Se o `CMenu` do menu barra é usada, um item de menu de nível superior (um item na barra de menus) é afetado. Para definir o estado de um item em um menu pop-up pop-up ou aninhado por posição, um aplicativo deve especificar o `CMenu` do menu pop-up.  
  
 Quando um aplicativo especifica o **MF_BYCOMMAND** sinalizador, o Windows verifica todos os itens de menu pop-up que são subordinados ao `CMenu`; portanto, a menos que os itens de menu duplicados estiverem presentes, usando o `CMenu` do menu barra é suficiente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cmenu-class_5.cpp)]  
  
##  <a name="a-namefromhandlea--cmenufromhandle"></a><a name="fromhandle"></a>CMenu::FromHandle  
 Retorna um ponteiro para um `CMenu` objeto recebe um identificador do Windows a um menu.  
  
```  
static CMenu* PASCAL FromHandle(HMENU hMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hMenu`  
 Um identificador para um menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CMenu` que pode ser temporário ou permanente.  
  
### <a name="remarks"></a>Comentários  
 Se um `CMenu` objeto já não está anexado ao objeto de menu do Windows, um temporário `CMenu` objeto é criado e anexado.  
  
 Esse temporário `CMenu` objeto só é válido até a próxima vez que o aplicativo tem tempo ocioso em seu loop de evento, em que todos os objetos temporários são excluídos.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::CreateMenu](#createmenu).  
  
##  <a name="a-namegetdefaultitema--cmenugetdefaultitem"></a><a name="getdefaultitem"></a>CMenu::GetDefaultItem  
 Determina o item de menu padrão no menu especificado.  
  
```  
UINT GetDefaultItem(
    UINT gmdiFlags,  
    BOOL fByPos = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *gmdiFlags*  
 Valor que especifica como a função de pesquisa de itens de menu. Esse parâmetro pode ser nenhum, um ou uma combinação dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|**GMDI_GOINTOPOPUPS**|Especifica que, se o item padrão é aquele que abre um submenu, a função é pesquisar recursivamente o submenu correspondente. Se o submenu não tem nenhum item padrão, o valor de retorno identifica o item que abre o submenu.<br /><br /> Por padrão, a função retorna o primeiro item padrão no menu especificado, independentemente de ser um item que abre um submenu.|  
|**GMDI_USEDISABLED**|Especifica que a função deve retornar um item padrão, mesmo se ele estiver desabilitado.<br /><br /> Por padrão, a função ignora itens desabilitados ou esmaecidos.|  
  
 `fByPos`  
 Valor que especifica se a recuperar o identificador do item de menu ou sua posição. Se esse parâmetro for **FALSE**, o identificador é retornado. Caso contrário, a posição será retornada.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é o identificador ou a posição do item de menu. Se a função falhar, o valor de retorno será - 1.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da função Win32 [GetMenuDefaultItem](http://msdn.microsoft.com/library/windows/desktop/ms647976), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="a-namegetmenucontexthelpida--cmenugetmenucontexthelpid"></a><a name="getmenucontexthelpid"></a>CMenu::GetMenuContextHelpId  
 Recupera a Ajuda de contexto ID associada `CMenu`.  
  
```  
DWORD GetMenuContextHelpId() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A Ajuda de contexto ID atualmente associado `CMenu` se houver; caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="a-namegetmenuinfoa--cmenugetmenuinfo"></a><a name="getmenuinfo"></a>CMenu::GetMenuInfo  
 Recupera as informações de um menu.  
  
```  
BOOL GetMenuInfo(LPMENUINFO lpcmi) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpcmi`  
 Um ponteiro para um [MENUINFO](http://msdn.microsoft.com/library/windows/desktop/ms647575) estrutura que contém informações de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é diferente de zero; Caso contrário, o valor de retorno é zero.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar informações sobre o menu.  
  
##  <a name="a-namegetmenuitemcounta--cmenugetmenuitemcount"></a><a name="getmenuitemcount"></a>CMenu::GetMenuItemCount  
 Determina o número de itens em um menu pop-up ou de nível superior.  
  
```  
UINT GetMenuItemCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens de menu que se a função for bem-sucedida; Caso contrário,-1.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWnd::GetMenu](../../mfc/reference/cwnd-class.md#getmenu).  
  
##  <a name="a-namegetmenuitemida--cmenugetmenuitemid"></a><a name="getmenuitemid"></a>CMenu::GetMenuItemID  
 Obtém o identificador do item de menu de um item de menu localizado na posição definida por `nPos`.  
  
```  
UINT GetMenuItemID(int nPos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 Especifica a posição (baseado em zero) do item de menu cuja ID está sendo recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID do item para o item especificado em um menu pop-up se a função for bem-sucedida. Se o item especificado for um menu pop-up (em vez de um item de menu pop-up), o valor de retorno será –&1;. Se `nPos` corresponde a um **SEPARADOR** item de menu, o valor de retorno é 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="a-namegetmenuiteminfoa--cmenugetmenuiteminfo"></a><a name="getmenuiteminfo"></a>CMenu::GetMenuItemInfo  
 Recupera informações sobre um item de menu.  
  
```  
BOOL GetMenuItemInfo(
    UINT uItem,  
    LPMENUITEMINFO lpMenuItemInfo,  
    BOOL fByPos = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uItem`  
 Identificador ou a posição do item de menu para obter informações. O significado desse parâmetro depende do valor de `ByPos`.  
  
 `lpMenuItemInfo`  
 Um ponteiro para um [MENUITEMINFO](http://msdn.microsoft.com/library/windows/desktop/ms647578), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)], que contém informações sobre o menu.  
  
 `fByPos`  
 Valor que especifica o significado de `nIDItem`. Por padrão, `ByPos` é **FALSE**, que indica que uItem é um identificador de item de menu. Se `ByPos` não está definido como **FALSE**, isso indica uma posição de item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é diferente de zero. Se a função falhar, o valor retornado será zero. Para obter mais informações sobre o erro, use a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da função Win32 [GetMenuItemInfo](http://msdn.microsoft.com/library/windows/desktop/ms647980), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Observe que na implementação do MFC `GetMenuItemInfo`, você não usa um identificador para um menu.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#26;](../../mfc/reference/codesnippet/cpp/cmenu-class_6.cpp)]  
  
##  <a name="a-namegetmenustatea--cmenugetmenustate"></a><a name="getmenustate"></a>CMenu::GetMenuState  
 Retorna o status do item de menu especificado ou o número de itens em um menu pop-up.  
  
```  
UINT GetMenuState(
    UINT nID,  
    UINT nFlags) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Especifica a ID do item de menu, conforme determinado por `nFlags`.  
  
 `nFlags`  
 Especifica a natureza da `nID`. Ele pode ser um dos seguintes valores:  
  
- **MF_BYCOMMAND** Especifica que o parâmetro retorna a ID de comando do item de menu existente. Esse é o padrão.  
  
- **MF_BYPOSITION** Especifica que o parâmetro retorna a posição do item de menu existente. É o primeiro item na posição 0.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor 0xFFFFFFFF se o item especificado não existe. Se *nId* identifica um menu pop-up, o byte de ordem superior contém o número de itens no menu pop-up e o byte de ordem inferior contém os sinalizadores de menu associados com o menu pop-up. Caso contrário, o valor de retorno é uma máscara (booleano ou) dos valores da lista a seguir (esta máscara descreve o status do menu item *nId* identifica):  
  
- **MF_CHECKED** atua como uma alternância com **MF_UNCHECKED** para colocar a marca de seleção ao lado do item padrão. Quando o aplicativo fornece bitmaps de marca de seleção (consulte a `SetMenuItemBitmaps` função de membro), o bitmap de "marca de seleção no" é exibido.  
  
- **MF_DISABLED** desativa o item de menu para que ele não pode ser selecionado, mas a esmaecer.  
  
- `MF_ENABLED`Permite que o item de menu para que ele pode ser selecionado e restaurá-lo de seu estado esmaecido. Observe que o valor dessa constante é 0; um aplicativo não deve testar 0 falha ao usar esse valor.  
  
- **MF_GRAYED** desabilita o item de menu para que ele não pode ser selecionado e solicitará a ele.  
  
- **MF_MENUBARBREAK** coloca o item em uma nova linha em menus estáticos ou em uma nova coluna nos menus pop-up. A nova coluna do menu pop-up será separada da coluna antiga por uma linha divisória vertical.  
  
- **MF_MENUBREAK** coloca o item em uma nova linha em menus estáticos ou em uma nova coluna nos menus pop-up. Nenhuma linha divisória é colocada entre as colunas.  
  
- **MF_SEPARATOR** desenha uma linha divisória horizontal. Só pode ser usado em um menu pop-up. Essa linha não pode ser esmaecida, desabilitada ou realçada. Outros parâmetros são ignorados.  
  
- **MF_UNCHECKED** atua como uma alternância com **MF_CHECKED** para remover uma marca de seleção ao lado do item. Quando o aplicativo fornece bitmaps de marca de seleção (consulte a `SetMenuItemBitmaps` função de membro), o bitmap de "marca de seleção off" é exibido. Observe que o valor dessa constante é 0; um aplicativo não deve testar 0 falha ao usar esse valor.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#27;](../../mfc/reference/codesnippet/cpp/cmenu-class_7.cpp)]  
  
##  <a name="a-namegetmenustringa--cmenugetmenustring"></a><a name="getmenustring"></a>CMenu::GetMenuString  
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
 `nIDItem`  
 Especifica o identificador do inteiro do item de menu ou o deslocamento do item de menu no menu, dependendo do valor de `nFlags`.  
  
 `lpString`  
 Aponta para o buffer que receberá o rótulo.  
  
 `rString`  
 Uma referência a um `CString` objeto que deve receber a cadeia de caracteres de menu copiado.  
  
 `nMaxCount`  
 Especifica o comprimento máximo (em caracteres) do rótulo a ser copiado. Se o rótulo é maior que o máximo especificado no `nMaxCount`, os caracteres extras serão truncados.  
  
 `nFlags`  
 Especifica a interpretação de `nIDItem` parâmetro. Ele pode ser um dos seguintes valores:  
  
|nFlags|Interpretação de nIDItem|  
|------------|-------------------------------|  
|**MF_BYCOMMAND**|Especifica o parâmetro retorna a ID de comando do item de menu existente. Esse é o padrão se nem **MF_BYCOMMAND** nem **MF_BYPOSITION** está definido.|  
|**MF_BYPOSITION**|Especifica o parâmetro retorna a posição do item de menu existente. É o primeiro item na posição 0.|  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o número real de caracteres copiados para o buffer, não incluindo o terminador nulo.  
  
### <a name="remarks"></a>Comentários  
 O `nMaxCount` parâmetro deve ser maior que o número de caracteres de rótulo para acomodar o caractere nulo que finaliza uma cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="a-namegetsafehmenua--cmenugetsafehmenu"></a><a name="getsafehmenu"></a>CMenu::GetSafeHmenu  
 Retorna o `HMENU` encapsulado por esse `CMenu` objeto, ou uma **nulo** `CMenu` ponteiro.  
  
```  
HMENU GetSafeHmenu() const;  
```  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::LoadMenu](#loadmenu).  
  
##  <a name="a-namegetsubmenua--cmenugetsubmenu"></a><a name="getsubmenu"></a>CMenu::GetSubMenu  
 Recupera o `CMenu` objeto de um menu pop-up.  
  
```  
CMenu* GetSubMenu(int nPos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 Especifica a posição do menu pop-up contido no menu. Valores de posição começam em 0 para o primeiro item de menu. Identificador do menu pop-up não pode ser usado nessa função.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CMenu` objeto cuja `m_hMenu` membro contém um identificador para o menu pop-up, se existir um menu pop-up na posição especificada; caso contrário, **nulo**. Se um `CMenu` objeto não existe, um temporário será criado. O `CMenu` ponteiro retornado não deve ser armazenado.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::TrackPopupMenu](#trackpopupmenu).  
  
##  <a name="a-nameinsertmenua--cmenuinsertmenu"></a><a name="insertmenu"></a>CMenu::InsertMenu  
 Insere um novo item de menu na posição especificada por `nPosition` e outros itens de menu.  
  
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
 `nPosition`  
 Especifica o item de menu antes que o novo item de menu deve ser inserido. O `nFlags` parâmetro pode ser usado para interpretar `nPosition` das seguintes maneiras:  
  
|nFlags|Interpretação de nPosition|  
|------------|---------------------------------|  
|**MF_BYCOMMAND**|Especifica o parâmetro retorna a ID de comando do item de menu existente. Esse é o padrão se nem **MF_BYCOMMAND** nem **MF_BYPOSITION** está definido.|  
|**MF_BYPOSITION**|Especifica o parâmetro retorna a posição do item de menu existente. É o primeiro item na posição 0. Se `nPosition` é –&1;, o novo item de menu é acrescentado ao final do menu.|  
  
 `nFlags`  
 Especifica como `nPosition` é interpretado e especifica informações sobre o estado do item de menu novo, quando ele é adicionado ao menu. Para obter uma lista dos sinalizadores que podem ser definidas, consulte o [AppendMenu](#appendmenu) função de membro. Para especificar mais de um valor, use o operador OR bit a bit para combiná-los com o **MF_BYCOMMAND** ou **MF_BYPOSITION** sinalizador.  
  
 `nIDNewItem`  
 Especifica a ID de comando do item de menu novo ou, se `nFlags` é definido como **MF_POPUP**, o identificador de menu ( `HMENU`) do menu pop-up. O `nIDNewItem` parâmetro é ignorado (não necessárias) se `nFlags` é definido como **MF_SEPARATOR**.  
  
 `lpszNewItem`  
 Especifica o conteúdo do novo item de menu. `nFlags`pode ser usado para interpretar `lpszNewItem` das seguintes maneiras:  
  
|nFlags|Interpretação de lpszNewItem|  
|------------|-----------------------------------|  
|`MF_OWNERDRAW`|Contém um valor de 32 bits fornecida pelo aplicativo que o aplicativo pode usar para manter dados adicionais associados ao item de menu. Esse valor de 32 bits está disponível para o aplicativo no **itemData** membro da estrutura fornecido pelo [WM_MEASUREITEM](http://msdn.microsoft.com/library/windows/desktop/bb775925) e [WM_DRAWITEM](http://msdn.microsoft.com/library/windows/desktop/bb775923) mensagens. Essas mensagens são enviadas quando o item de menu é exibido inicialmente ou for alterado.|  
|**MF_STRING**|Contém um ponteiro long para uma cadeia de caracteres terminada em nulo. Essa é a interpretação padrão.|  
|**MF_SEPARATOR**|O `lpszNewItem` parâmetro é ignorado (não é necessária).|  
  
 *pBmp*  
 Aponta para um `CBitmap` objeto que será usado como o item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O aplicativo pode especificar o estado do item de menu, definindo valores no `nFlags`.  
  
 Sempre que um menu que reside em uma janela é alterada (ou não a janela é exibida), o aplicativo deve chamar `CWnd::DrawMenuBar`.  
  
 Quando `nIDNewItem` Especifica um menu pop-up, ela se torna parte do menu no qual ele é inserido. Se esse menu for destruído, o menu inserido também será destruído. Um menu inserido deve ser desanexado de um `CMenu` objeto para evitar conflitos.  
  
 Se o ativo várias janelas do documento interface MDI filho é maximizada e um aplicativo insere um menu pop-up no menu do aplicativo MDI chamar essa função e especificando o **MF_BYPOSITION** sinalizador, o menu é inserida uma posição mais à esquerda do que o esperado. Isso acontece porque o menu de controle da janela filho MDI ativa é inserido na primeira posição da barra de menus da janela de quadro MDI. Para posicionar o menu corretamente, o aplicativo deve adicionar 1 para o valor da posição que outra forma seria usado. Um aplicativo pode usar o **WM_MDIGETACTIVE** mensagem para determinar se a janela filho ativa no momento é maximizada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#28;](../../mfc/reference/codesnippet/cpp/cmenu-class_8.cpp)]  
  
##  <a name="a-nameinsertmenuitema--cmenuinsertmenuitem"></a><a name="insertmenuitem"></a>CMenu::InsertMenuItem  
 Insere um novo item de menu na posição especificada em um menu.  
  
```  
BOOL InsertMenuItem(
    UINT uItem,  
    LPMENUITEMINFO lpMenuItemInfo,  
    BOOL fByPos = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uItem`  
 Consulte a descrição de `uItem` na [InsertMenuItem](http://msdn.microsoft.com/library/windows/desktop/ms647988) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `lpMenuItemInfo`  
 Consulte a descrição de `lpmii` na **InsertMenuItem** no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `fByPos`  
 Consulte a descrição de `fByPosition` na **InsertMenuItem** no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Essa função encapsula [InsertMenuItem](http://msdn.microsoft.com/library/windows/desktop/ms647988), descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameloadmenua--cmenuloadmenu"></a><a name="loadmenu"></a>CMenu::LoadMenu  
 Carrega um recurso de menu do arquivo executável do aplicativo e anexa-o para o `CMenu` objeto.  
  
```  
BOOL LoadMenu(LPCTSTR lpszResourceName);  
BOOL LoadMenu(UINT nIDResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszResourceName`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do recurso de menu para carregar.  
  
 `nIDResource`  
 Especifica a ID do menu do recurso de menu para carregar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o recurso de menu foi carregado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Antes de sair, um aplicativo deve Libere recursos do sistema associados a um menu se o menu não está atribuído a uma janela. Um aplicativo libera um menu chamando o [DestroyMenu](#destroymenu) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[29 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cmenu-class_9.cpp)]  
  
##  <a name="a-nameloadmenuindirecta--cmenuloadmenuindirect"></a><a name="loadmenuindirect"></a>CMenu::LoadMenuIndirect  
 Carrega um recurso de um modelo de menu na memória e anexa-o para o `CMenu` objeto.  
  
```  
BOOL LoadMenuIndirect(const void* lpMenuTemplate);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpMenuTemplate*  
 Aponta para um modelo de menu (que é um único [MENUITEMTEMPLATEHEADER](http://msdn.microsoft.com/library/windows/desktop/ms647583) estrutura e uma coleção de um ou mais [MENUITEMTEMPLATE](http://msdn.microsoft.com/library/windows/desktop/ms647581) estruturas). Para obter mais informações sobre essas duas estruturas, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o recurso de menu foi carregado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um modelo de menu é um cabeçalho seguido de uma coleção de um ou mais [MENUITEMTEMPLATE](http://msdn.microsoft.com/library/windows/desktop/ms647581) estruturas, cada uma delas pode conter um ou mais itens de menu e menus pop-up.  
  
 O número da versão deve ser 0.  
  
 O **mtOption** sinalizadores devem incluir **MF_END** para o último item em uma lista pop-up e para o último item na lista principal. Consulte o `AppendMenu` a função de membro para outros sinalizadores. O **mtId** membro deve ser omitido do **MENUITEMTEMPLATE** estrutura quando **MF_POPUP** é especificado em **mtOption**.  
  
 O espaço alocado para o **MENUITEMTEMPLATE** estrutura deve ser grande o suficiente para **mtString** para conter o nome do item de menu, como uma cadeia de caracteres terminada em nulo.  
  
 Antes de sair, um aplicativo deve Libere recursos do sistema associados a um menu se o menu não está atribuído a uma janela. Um aplicativo libera um menu chamando o [DestroyMenu](#destroymenu) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[30 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cmenu-class_10.cpp)]  
  
##  <a name="a-namemhmenua--cmenumhmenu"></a><a name="m_hmenu"></a>CMenu::m_hMenu  
 Especifica o `HMENU` identificador de menu do Windows conectado ao `CMenu` objeto.  
  
```  
HMENU m_hMenu;  
```  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::LoadMenu](#loadmenu).  
  
##  <a name="a-namemeasureitema--cmenumeasureitem"></a><a name="measureitem"></a>CMenu::MeasureItem  
 Chamado pela estrutura quando um menu com o estilo de desenho proprietário é criado.  
  
```  
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMeasureItemStruct`  
 Um ponteiro para um `MEASUREITEMSTRUCT` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função de membro não fará nada. Substituir essa função de membro e preencha o `MEASUREITEMSTRUCT` estrutura para informar ao Windows das dimensões do menu.  
  
 Consulte [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter uma descrição de `MEASUREITEMSTRUCT` estrutura.  
  
### <a name="example"></a>Exemplo  
 O código a seguir é do MFC [CTRLTEST](../../visual-cpp-samples.md) exemplo:  
  
 [!code-cpp[NVC_MFCWindowing&#31;](../../mfc/reference/codesnippet/cpp/cmenu-class_11.cpp)]  
  
##  <a name="a-namemodifymenua--cmenumodifymenu"></a><a name="modifymenu"></a>CMenu::ModifyMenu  
 Altera um item de menu existente na posição especificada por `nPosition`.  
  
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
 `nPosition`  
 Especifica o item de menu a ser alterado. O `nFlags` parâmetro pode ser usado para interpretar `nPosition` das seguintes maneiras:  
  
|nFlags|Interpretação de nPosition|  
|------------|---------------------------------|  
|**MF_BYCOMMAND**|Especifica o parâmetro retorna a ID de comando do item de menu existente. Esse é o padrão se nem **MF_BYCOMMAND** nem **MF_BYPOSITION** está definido.|  
|**MF_BYPOSITION**|Especifica o parâmetro retorna a posição do item de menu existente. É o primeiro item na posição 0.|  
  
 `nFlags`  
 Especifica como `nPosition` é interpretado e fornece informações sobre as alterações que foram feitas para o item de menu. Para obter uma lista de sinalizadores que podem ser definidos, consulte o [AppendMenu](#appendmenu) função de membro.  
  
 `nIDNewItem`  
 Especifica a ID de comando do item de menu modificado ou, se `nFlags` é definido como **MF_POPUP**, o identificador de menu ( `HMENU`) de um menu pop-up. O `nIDNewItem` parâmetro é ignorado (não necessárias) se `nFlags` é definido como **MF_SEPARATOR**.  
  
 `lpszNewItem`  
 Especifica o conteúdo do novo item de menu. O `nFlags` parâmetro pode ser usado para interpretar `lpszNewItem` das seguintes maneiras:  
  
|nFlags|Interpretação de lpszNewItem|  
|------------|-----------------------------------|  
|`MF_OWNERDRAW`|Contém um valor de 32 bits fornecida pelo aplicativo que o aplicativo pode usar para manter dados adicionais associados ao item de menu. Esse valor de 32 bits está disponível para o aplicativo quando ele processa **MF_MEASUREITEM** e **MF_DRAWITEM**.|  
|**MF_STRING**|Contém um ponteiro de tempo para uma cadeia de caracteres terminada em nulo ou a um `CString`.|  
|**MF_SEPARATOR**|O `lpszNewItem` parâmetro é ignorado (não é necessária).|  
  
 *pBmp*  
 Aponta para um `CBitmap` objeto que será usado como o item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O aplicativo especifica o novo estado do item de menu, definindo valores no `nFlags`. Se essa função substitui um menu pop-up associado ao item de menu, destrói o menu pop-up antigo e libera a memória usada pelo menu pop-up.  
  
 Quando `nIDNewItem` Especifica um menu pop-up, ela se torna parte do menu no qual ele é inserido. Se esse menu for destruído, o menu inserido também será destruído. Um menu inserido deve ser desanexado de um `CMenu` objeto para evitar conflitos.  
  
 Sempre que um menu que reside em uma janela é alterada (ou não a janela é exibida), o aplicativo deve chamar `CWnd::DrawMenuBar`. Para alterar os atributos dos itens de menu existentes, é muito mais rápido usar o `CheckMenuItem` e `EnableMenuItem` funções de membro.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="a-nameoperatorhmenua--cmenuoperator-hmenu"></a><a name="operator_hmenu"></a>CMenu::operator HMENU  
 Usar esse operador para recuperar o identificador do `CMenu` objeto.  
  
```  
operator HMENU() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o identificador do `CMenu` objeto; caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar o identificador para chamar diretamente as APIs do Windows.  
  
##  <a name="a-nameoperatorneqa--cmenuoperator-"></a><a name="operator_neq"></a>CMenu::operator! =  
 Determina se dois menus logicamente não são iguais.  
  
```  
BOOL operator!=(const CMenu& menu) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `menu`  
 Um `CMenu` objeto para comparação.  
  
### <a name="remarks"></a>Comentários  
 Testa se um objeto de menu no lado esquerdo não for igual a um objeto de menu no lado direito.  
  
##  <a name="a-nameoperatoreqeqa--cmenuoperator-"></a><a name="operator_eq_eq"></a>CMenu::operator = =  
 Determina se dois menus são logicamente iguais.  
  
```  
BOOL operator==(const CMenu& menu) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `menu`  
 Um `CMenu` objeto para comparação.  
  
### <a name="remarks"></a>Comentários  
 Testa se um objeto de menu no lado esquerdo for igual (em termos do `HMENU` valor) a um objeto de menu no lado direito.  
  
##  <a name="a-nameremovemenua--cmenuremovemenu"></a><a name="removemenu"></a>CMenu::RemoveMenu  
 Exclui um item de menu com um menu pop-up associado no menu.  
  
```  
BOOL RemoveMenu(
    UINT nPosition,  
    UINT nFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPosition`  
 Especifica o item de menu a ser removido. O `nFlags` parâmetro pode ser usado para interpretar `nPosition` das seguintes maneiras:  
  
|nFlags|Interpretação de nPosition|  
|------------|---------------------------------|  
|**MF_BYCOMMAND**|Especifica o parâmetro retorna a ID de comando do item de menu existente. Esse é o padrão se nem **MF_BYCOMMAND** nem **MF_BYPOSITION** está definido.|  
|**MF_BYPOSITION**|Especifica o parâmetro retorna a posição do item de menu existente. É o primeiro item na posição 0.|  
  
 `nFlags`  
 Especifica como `nPosition` é interpretado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele não destrói o identificador para um menu pop-up, para que o menu pode ser reutilizado. Antes de chamar essa função, o aplicativo pode chamar o `GetSubMenu` função de membro para recuperar o pop-up `CMenu` objeto para reutilização.  
  
 Sempre que um menu que reside em uma janela é alterada (ou não a janela é exibida), o aplicativo deve chamar `CWnd::DrawMenuBar`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="a-namesetdefaultitema--cmenusetdefaultitem"></a><a name="setdefaultitem"></a>CMenu::SetDefaultItem  
 Define o item de menu padrão para o menu especificado.  
  
```  
BOOL SetDefaultItem(
    UINT uItem,  
    BOOL fByPos = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uItem`  
 Identificador ou a posição do novo item de menu padrão ou - 1 para nenhum item padrão. O significado desse parâmetro depende do valor de `fByPos`.  
  
 `fByPos`  
 Valor que especifica o significado de `uItem`. Se esse parâmetro for **FALSE**, `uItem` é um identificador de item de menu. Caso contrário, ele é uma posição de item de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é diferente de zero. Se a função falhar, o valor retornado será zero. Para obter mais informações sobre o erro, use a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da função Win32 [SetMenuDefaultItem](http://msdn.microsoft.com/library/windows/desktop/ms647996), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="a-namesetmenucontexthelpida--cmenusetmenucontexthelpid"></a><a name="setmenucontexthelpid"></a>CMenu::SetMenuContextHelpId  
 Associa um ID de ajuda de contexto com `CMenu`.  
  
```  
BOOL SetMenuContextHelpId(DWORD dwContextHelpId);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwContextHelpId`  
 ID do contexto de ajuda para associar `CMenu`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0  
  
### <a name="remarks"></a>Comentários  
 Todos os itens de menu compartilham esse identificador — não é possível anexar um identificador de contexto de ajuda para os itens de menu individuais.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CMenu::InsertMenu](#insertmenu).  
  
##  <a name="a-namesetmenuinfoa--cmenusetmenuinfo"></a><a name="setmenuinfo"></a>CMenu::SetMenuInfo  
 Define informações de um menu.  
  
```  
BOOL SetMenuInfo(LPCMENUINFO lpcmi);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpcmi`  
 Um ponteiro para um [MENUINFO](http://msdn.microsoft.com/library/windows/desktop/ms647575) estrutura que contém informações de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função obtiver êxito, o valor de retorno é diferente de zero; Caso contrário, o valor de retorno é zero.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para definir informações específicas sobre o menu.  
  
##  <a name="a-namesetmenuitembitmapsa--cmenusetmenuitembitmaps"></a><a name="setmenuitembitmaps"></a>CMenu::SetMenuItemBitmaps  
 Associa os bitmaps especificados com um item de menu.  
  
```  
BOOL SetMenuItemBitmaps(
    UINT nPosition,  
    UINT nFlags,  
    const CBitmap* pBmpUnchecked,  
    const CBitmap* pBmpChecked);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPosition`  
 Especifica o item de menu a ser alterado. O `nFlags` parâmetro pode ser usado para interpretar `nPosition` das seguintes maneiras:  
  
|nFlags|Interpretação de nPosition|  
|------------|---------------------------------|  
|**MF_BYCOMMAND**|Especifica o parâmetro retorna a ID de comando do item de menu existente. Esse é o padrão se nem **MF_BYCOMMAND** nem **MF_BYPOSITION** está definido.|  
|**MF_BYPOSITION**|Especifica o parâmetro retorna a posição do item de menu existente. É o primeiro item na posição 0.|  
  
 `nFlags`  
 Especifica como `nPosition` é interpretado.  
  
 `pBmpUnchecked`  
 Especifica o bitmap a ser usado para itens de menu que não são verificadas.  
  
 `pBmpChecked`  
 Especifica o bitmap a ser usado para itens de menu que são verificadas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o item de menu é marcado ou desmarcado, o Windows exibe o bitmap apropriado ao lado do item de menu.  
  
 Se qualquer um dos `pBmpUnchecked` ou `pBmpChecked` é **nulo**, em seguida, o Windows não exibe nada ao lado do item de menu para o atributo correspondente. Se ambos os parâmetros forem **nulo**, Windows usa a marca de seleção padrão, quando o item é verificado e remove a marca de seleção quando o item está desmarcado.  
  
 Quando o menu é destruído, esses bitmaps não são destruídos; o aplicativo deverá destruí-los.  
  
 O Windows **GetMenuCheckMarkDimensions** função recupera as dimensões da marca de seleção padrão usado para itens de menu. O aplicativo usa esses valores para determinar o tamanho apropriado para os bitmaps fornecidos com essa função. Obter o tamanho, criar seus bitmaps e defini-los.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[32 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cmenu-class_12.cpp)]  
  
 [!code-cpp[33 NVC_MFCWindowing](../../mfc/reference/codesnippet/cpp/cmenu-class_13.cpp)]  
  
##  <a name="a-namesetmenuiteminfoa--cmenusetmenuiteminfo"></a><a name="setmenuiteminfo"></a>CMenu::SetMenuItemInfo  
 Altera as informações sobre um item de menu.  
  
```  
BOOL SetMenuItemInfo(
    UINT uItem,  
    LPMENUITEMINFO lpMenuItemInfo,  
    BOOL fByPos = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uItem`  
 Consulte a descrição de `uItem` na [SetMenuItemInfo](http://msdn.microsoft.com/library/windows/desktop/ms648001) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `lpMenuItemInfo`  
 Consulte a descrição de `lpmii` na **SetMenuItemInfo** no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `fByPos`  
 Consulte a descrição de `fByPosition` na **SetMenuItemInfo** no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Essa função encapsula [SetMenuItemInfo](http://msdn.microsoft.com/library/windows/desktop/ms648001), descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nametrackpopupmenua--cmenutrackpopupmenu"></a><a name="trackpopupmenu"></a>CMenu::TrackPopupMenu  
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
 `nFlags`  
 Especifica sinalizadores posição da tela e a posição do mouse. Consulte [TrackPopupMenu](http://msdn.microsoft.com/library/windows/desktop/ms648002) para obter uma lista de sinalizadores disponíveis.  
  
 *x*  
 Especifica a posição horizontal em coordenadas de tela do menu pop-up. Dependendo do valor da `nFlags` parâmetro, o menu pode ser alinhado à esquerda, direita ou centralizado em relação a essa posição.  
  
 *y*  
 Especifica a posição vertical em coordenadas de tela da parte superior do menu na tela.  
  
 `pWnd`  
 Identifica a janela que possui um menu pop-up. Esse parâmetro não pode ser **nulo**, mesmo que o **TPM_NONOTIFY** sinalizador for especificado. Esta janela recebe todos **WM_COMMAND** mensagens no menu. No Windows versões 3.1 e posteriores, a janela não recebe **WM_COMMAND** mensagens até `TrackPopupMenu` retorna. No Windows 3.0, a janela recebe **WM_COMMAND** mensagens antes de `TrackPopupMenu` retorna.  
  
 `lpRect`  
 Ignorado.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna o resultado da chamada [TrackPopupMenu](http://msdn.microsoft.com/library/windows/desktop/ms648002) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Um menu pop-up flutuante pode aparecer em qualquer lugar na tela.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing&#34;](../../mfc/reference/codesnippet/cpp/cmenu-class_14.cpp)]  
  
##  <a name="a-nametrackpopupmenuexa--cmenutrackpopupmenuex"></a><a name="trackpopupmenuex"></a>CMenu::TrackPopupMenuEx  
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
 `fuFlags`  
 Especifica várias funções de menu estendido. Para obter uma listagem de todos os valores e seu significado, consulte [TrackPopupMenuEx](http://msdn.microsoft.com/library/windows/desktop/ms648003).  
  
 *x*  
 Especifica a posição horizontal em coordenadas de tela do menu pop-up.  
  
 *y*  
 Especifica a posição vertical em coordenadas de tela da parte superior do menu na tela.  
  
 `pWnd`  
 Um ponteiro para a janela de propriedade no menu pop-up e de recebimento de mensagens do menu criado. Esta janela pode ser qualquer janela do aplicativo atual, mas não pode ser **nulo**. Se você especificar **TPM_NONOTIFY** no `fuFlags` parâmetro, a função não enviar mensagens para `pWnd`. A função deve retornar para a janela apontada por `pWnd` para receber o **WM_COMMAND** mensagem.  
  
 *lptpm*  
 Ponteiro para uma [TPMPARAMS](http://msdn.microsoft.com/library/windows/desktop/ms647586) não deve se sobrepor a estrutura que especifica uma área da tela no menu. Esse parâmetro pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Se você especificar **TPM_RETURNCMD** no `fuFlags` parâmetro, o valor de retorno é o identificador do item de menu do item selecionado pelo usuário. Se o usuário cancela o menu sem fazer uma seleção, ou se ocorrer um erro, o valor de retorno é 0.  
  
 Se você não especificar **TPM_RETURNCMD** no `fuFlags` parâmetro, o valor de retorno é diferente de zero se a função for bem-sucedida e 0 se falhar. Para obter mais informações sobre o erro, chame [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360).  
  
### <a name="remarks"></a>Comentários  
 Um menu pop-up flutuante pode aparecer em qualquer lugar na tela. Para obter mais informações sobre o tratamento de erros ao criar o menu pop-up, consulte [TrackPopupMenuEx](http://msdn.microsoft.com/library/windows/desktop/ms648003).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLTEST](../../visual-cpp-samples.md)   
 [Exemplo MFC DYNAMENU](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)

