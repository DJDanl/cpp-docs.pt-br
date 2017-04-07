---
title: Classe CContextMenuManager | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CContextMenuManager
- AFXCONTEXTMENUMANAGER/CContextMenuManager
- AFXCONTEXTMENUMANAGER/CContextMenuManager::CContextMenuManager
- AFXCONTEXTMENUMANAGER/CContextMenuManager::AddMenu
- AFXCONTEXTMENUMANAGER/CContextMenuManager::GetMenuById
- AFXCONTEXTMENUMANAGER/CContextMenuManager::GetMenuByName
- AFXCONTEXTMENUMANAGER/CContextMenuManager::GetMenuNames
- AFXCONTEXTMENUMANAGER/CContextMenuManager::LoadState
- AFXCONTEXTMENUMANAGER/CContextMenuManager::ResetState
- AFXCONTEXTMENUMANAGER/CContextMenuManager::SaveState
- AFXCONTEXTMENUMANAGER/CContextMenuManager::SetDontCloseActiveMenu
- AFXCONTEXTMENUMANAGER/CContextMenuManager::ShowPopupMenu
- AFXCONTEXTMENUMANAGER/CContextMenuManager::TrackPopupMenu
dev_langs:
- C++
helpviewer_keywords:
- CContextMenuManager class
ms.assetid: 1de20640-243c-47e1-85de-1baa4153bc83
caps.latest.revision: 32
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
ms.openlocfilehash: fab322d0c60b33454504620170d9c77a98401ec8
ms.lasthandoff: 02/25/2017

---
# <a name="ccontextmenumanager-class"></a>Classe CContextMenuManager
O `CContextMenuManager` objeto gerencia menus de atalho, também conhecido como menus de contexto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CContextMenuManager : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CContextMenuManager::CContextMenuManager](#ccontextmenumanager)|Constrói um objeto `CContextMenuManager`.|  
|`CContextMenuManager::~CContextMenuManager`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CContextMenuManager::AddMenu](#addmenu)|Adiciona um novo menu de atalho.|  
|[CContextMenuManager::GetMenuById](#getmenubyid)|Retorna um identificador para o menu associado com a ID de recurso fornecido.|  
|[CContextMenuManager::GetMenuByName](#getmenubyname)|Retorna um identificador para o menu que corresponda ao nome fornecido do menu.|  
|[CContextMenuManager::GetMenuNames](#getmenunames)|Retorna uma lista de nomes de menus.|  
|[CContextMenuManager::LoadState](#loadstate)|Carrega os menus de atalho armazenados no registro do Windows.|  
|[CContextMenuManager::ResetState](#resetstate)|Limpa os menus de atalho do Gerenciador do menu de contexto.|  
|[CContextMenuManager::SaveState](#savestate)|Salva os menus de atalho no registro do Windows.|  
|[CContextMenuManager::SetDontCloseActiveMenu](#setdontcloseactivemenu)|Controles se o `CContextMenuManager` fecha o menu de atalho ativo quando ele mostra um novo menu de atalho.|  
|[CContextMenuManager::ShowPopupMenu](#showpopupmenu)|Exibe o menu de atalho especificada.|  
|[CContextMenuManager::TrackPopupMenu](#trackpopupmenu)|Exibe o menu de atalho especificada. Retorna o índice do comando de menu selecionado.|  
  
## <a name="remarks"></a>Comentários  
 `CContextMenuManager`gerencia os menus de atalho e garante que eles tenham uma aparência consistente.  
  
 Você não deve criar um `CContextMenuManager` objeto manualmente. A estrutura do seu aplicativo cria o `CContextMenuManager` objeto. No entanto, você deve chamar [CWinAppEx::InitContextMenuManager](../../mfc/reference/cwinappex-class.md#initcontextmenumanager) quando seu aplicativo é inicializado. Após inicializar o Gerenciador de contexto, use o método [CWinAppEx::GetContextMenuManager](../../mfc/reference/cwinappex-class.md#getcontextmenumanager) para obter um ponteiro para o Gerenciador de contexto do seu aplicativo.  
  
 Você pode criar menus de atalho em tempo de execução chamando `AddMenu`. Se você quiser mostrar o menu sem primeiro receber entrada do usuário, chame `ShowPopupMenu`. `TrackPopupMenu`é usado quando você deseja criar um menu e aguarda a entrada do usuário. `TrackPopupMenu`Retorna o índice do comando selecionado ou 0 se o usuário saiu sem selecionar nada.  
  
 O `CContextMenuManager` também pode salvar e carregar seu estado no registro do Windows.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como adicionar um menu para um `CContextMenuManager` objeto e como fechar o menu pop-up ativo quando o `CContextMenuManager` objeto exibe um novo menu pop-up. Este trecho de código é parte do [exemplo páginas personalizadas](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_CustomPages n º&4;](../../mfc/reference/codesnippet/cpp/ccontextmenumanager-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CContextMenuManager`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcontextmenumanager.h  
  
##  <a name="addmenu"></a>CContextMenuManager::AddMenu  
 Adiciona um novo menu de atalho para o [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md).  
  
```  
BOOL AddMenu(
    UINT uiMenuNameResId,  
    UINT uiMenuResId);

 
BOOL AddMenu(
    LPCTSTR lpszName,  
    UINT uiMenuResId);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiMenuNameResId`  
 Uma ID de recurso para uma cadeia de caracteres que contém o nome para o novo menu.  
  
 [in] `uiMenuResId`  
 A ID de recurso do menu.  
  
 [in] `lpszName`  
 Uma cadeia de caracteres que contém o nome para o novo menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método teve êxito; 0 se o método falhar.  
  
### <a name="remarks"></a>Comentários  
 Esse método falhará se `uiMenuResId` é inválida ou se outro menu com o mesmo nome já está no `CContextMenuManager`.  
  
##  <a name="ccontextmenumanager"></a>CContextMenuManager::CContextMenuManager  
 Constrói uma [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) objeto.  
  
```  
CContextMenuManager();
```  
  
### <a name="remarks"></a>Comentários  
 Na maioria dos casos, você não deve criar um `CContextMenuManager` manualmente. A estrutura do seu aplicativo cria o `CContextMenuManager` objeto. Você deve chamar [CWinAppEx::InitContextMenuManager](../../mfc/reference/cwinappex-class.md#initcontextmenumanager) durante a inicialização do aplicativo. Para obter um ponteiro para o Gerenciador de contexto, chame [CWinAppEx::GetContextMenuManager](../../mfc/reference/cwinappex-class.md#getcontextmenumanager).  
  
##  <a name="getmenubyid"></a>CContextMenuManager::GetMenuById  
 Retorna um identificador para o menu associado a uma ID de determinado recurso.  
  
```  
HMENU GetMenuById(UINT nMenuResId) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nMenuResId`  
 A ID de recurso do menu.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o menu associado ou `NULL` se o menu não for encontrado.  
  
##  <a name="getmenubyname"></a>CContextMenuManager::GetMenuByName  
 Retorna um identificador para um menu específico.  
  
```  
HMENU GetMenuByName(
    LPCTSTR lpszName,  
    UINT* puiOrigResID = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 Uma cadeia de caracteres que contém o nome do menu para recuperar.  
  
 [out] `puiOrigResID`  
 Um ponteiro para um `UINT`. Este parâmetro contém a ID de recurso do menu especificado, se encontrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o menu que corresponde ao nome especificado pelo `lpszName`. `NULL`Se não há nenhum menu chamado `lpszName`.  
  
### <a name="remarks"></a>Comentários  
 Se esse método localiza um menu que corresponde a `lpszName`, `GetMenuByName` armazena a ID de recurso do menu no parâmetro `puiOrigResID`.  
  
##  <a name="getmenunames"></a>CContextMenuManager::GetMenuNames  
 Retorna a lista de nomes de menu adicionado para o [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md).  
  
```  
void GetMenuNames(CStringList& listOfNames) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `listOfNames`  
 Uma referência a um [CStringList](../../mfc/reference/cstringlist-class.md) parâmetro. Esse método grava a lista de nomes de menus para esse parâmetro.  
  
##  <a name="loadstate"></a>CContextMenuManager::LoadState  
 Carrega informações associadas a [CContextMenuManager classe](../../mfc/reference/ccontextmenumanager-class.md) do registro do Windows.  
  
```  
virtual BOOL LoadState(LPCTSTR lpszProfileName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `lpszProfileName` parâmetro não é o caminho absoluto para uma entrada de registro. É um caminho relativo que é adicionado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](../../mfc/reference/cwinappex-class.md#getregistrybase) e [CWinAppEx::SetRegistryBase](../../mfc/reference/cwinappex-class.md#setregistrybase) respectivamente.  
  
 Use o método [CContextMenuManager::SaveState](#savestate) para salvar os menus de atalho no registro.  
  
##  <a name="resetstate"></a>CContextMenuManager::ResetState  
 Limpa todos os itens nos menus de atalho associados a [CContextMenuManager classe](../../mfc/reference/ccontextmenumanager-class.md).  
  
```  
virtual BOOL ResetState();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método for bem-sucedido; `FALSE` se ocorrer uma falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método limpa os menus pop-up e remove-los a partir de `CContextMenuManager`.  
  
##  <a name="savestate"></a>CContextMenuManager::SaveState  
 Salva as informações associadas a [CContextMenuManager classe](../../mfc/reference/ccontextmenumanager-class.md) no registro do Windows.  
  
```  
virtual BOOL SaveState(LPCTSTR lpszProfileName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Uma cadeia de caracteres que contém o caminho relativo de uma chave do registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `lpszProfileName` parâmetro não é o caminho absoluto para uma entrada de registro. É um caminho relativo que é adicionado ao final da chave do registro padrão para seu aplicativo. Para obter ou definir a chave de registro padrão, use os métodos [CWinAppEx::GetRegistryBase](../../mfc/reference/cwinappex-class.md#getregistrybase) e [CWinAppEx::SetRegistryBase](../../mfc/reference/cwinappex-class.md#setregistrybase) respectivamente.  
  
 Use o método [CContextMenuManager::LoadState](#loadstate) para carregar os menus de atalho do registro.  
  
##  <a name="setdontcloseactivemenu"></a>CContextMenuManager::SetDontCloseActiveMenu  
 Controles se o [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md) fecha o menu pop-up ativo quando exibe um novo menu pop-up.  
  
```  
void SetDontCloseActiveMenu (BOOL bSet = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSet`  
 Um parâmetro booliano que controla se fechar o menu pop-up ativo. Um valor de `TRUE` indica o menu pop-up ativo não é fechado. `FALSE`indica que o menu pop-up ativo é fechado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o `CContextMenuManager` fecha o menu pop-up ativo.  
  
##  <a name="showpopupmenu"></a>CContextMenuManager::ShowPopupMenu  
 Exibe o menu de atalho especificada.  
  
```  
virtual BOOL ShowPopupMenu(
    UINT uiMenuResId,  
    int x,  
    int y,  
    CWnd* pWndOwner,  
    BOOL bOwnMessage = FALSE,  
    BOOL bRightAlign = FALSE);

 
virtual CMFCPopupMenu* ShowPopupMenu(
    HMENU hmenuPopup,  
    int x,  
    int y,  
    CWnd* pWndOwner,  
    BOOL bOwnMessage = FALSE,  
    BOOL bAutoDestroy = TRUE,  
    BOOL bRightAlign = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiMenuResId`  
 A ID de recurso do menu que esse método será exibido.  
  
 [in] `x`  
 Horizontal de deslocamento para o menu de atalho nas coordenadas do cliente.  
  
 [in] `y`  
 O deslocamento vertical do menu de atalho nas coordenadas do cliente  
  
 [in] `pWndOwner`  
 Um ponteiro para a janela pai do menu de atalho.  
  
 [in] `bOwnMessage`  
 Um parâmetro booleano que indica como as mensagens são roteadas. Se `bOwnMessage` é `FALSE`, roteamento padrão do MFC é usado. Caso contrário, `pWndOwner` recebe as mensagens.  
  
 [in] `hmenuPopup`  
 O identificador do menu que esse método será exibido.  
  
 [in] `bAutoDestroy`  
 Um parâmetro booleano que indica se o menu será destruído automaticamente.  
  
 [in] `bRightAlign`  
 Um parâmetro booleano que indica como os itens de menu são alinhados. Se `bRightAlign` é `TRUE`, o menu é alinhado à direita de ordem de leitura da direita para esquerda.  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira sobrecarga de método retorna zero se o método mostra o menu com êxito; Caso contrário, 0. A segunda sobrecarga do método retorna um ponteiro para [CMFCPopupMenu](../../mfc/reference/cmfcpopupmenu-class.md) se o menu de atalho exibe corretamente; caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Esse método se parece com o método [CContextMenuManager::TrackPopupMenu](#trackpopupmenu) que ambos os métodos exibem um menu de atalho. No entanto, `TrackPopupMenu` retorna o índice do comando de menu selecionado.  
  
 Se o parâmetro `bAutoDestroy` é `FALSE`, você deve manualmente chamar o herdadas `DestroyMenu` método para liberar recursos de memória. A implementação padrão de `ShowPopupMenu` não usar o parâmetro `bAutoDestroy`. Ele é fornecido para uso futuro ou para classes personalizadas que deriva de `CContextMenuManager` classe.  
  
##  <a name="trackpopupmenu"></a>CContextMenuManager::TrackPopupMenu  
 Exibe o menu de atalho especificado e retorna o índice do comando de menu de atalho selecionado.  
  
```  
virtual UINT TrackPopupMenu(
    HMENU hmenuPopup,  
    int x,  
    int y,  
    CWnd* pWndOwner,  
    BOOL bRightAlign = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hmenuPopup`  
 O identificador do menu de atalho que exibe esse método.  
  
 [in] `x`  
 Horizontal de deslocamento para o menu de atalho nas coordenadas do cliente.  
  
 [in] `y`  
 O deslocamento do menu de atalho nas coordenadas do cliente vertical.  
  
 [in] `pWndOwner`  
 Um ponteiro para a janela pai do menu de atalho.  
  
 [in] `bRightAlign`  
 Um parâmetro booleano que indica como os itens de menu são alinhados. Se `bRightAlign` é `TRUE`, o menu é alinhado à direita de ordem de leitura da direita para esquerda. Se `bRightAlign` é `FALSE`, o menu é alinhado à esquerda para a ordem de leitura da esquerda para a direita.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de comando de menu do comando escolhido pelo usuário; 0 se o usuário fechar o menu de atalho sem selecionar um comando de menu.  
  
### <a name="remarks"></a>Comentários  
 Esse método funciona como uma chamada modal para exibir um menu de atalho. O aplicativo não continuará para a seguinte linha no código até que o usuário fecha o menu de atalho ou seleciona um comando. Um método alternativo que você pode usar para exibir um menu de atalho é [CContextMenuManager::ShowPopupMenu](#showpopupmenu). Esse método não é uma chamada modal e não retornará a ID do comando selecionado.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)

