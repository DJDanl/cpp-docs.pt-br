---
title: Classe CJumpList | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- afxadv/CJumpList
- CJumpList
dev_langs:
- C++
helpviewer_keywords:
- CJumpList class
ms.assetid: d364d27e-f512-4b12-9872-c2a17c78ab1f
caps.latest.revision: 15
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
ms.openlocfilehash: b3662bd00f7c757df3a77f5920c48389bbd749fb
ms.lasthandoff: 02/25/2017

---
# <a name="cjumplist-class"></a>Classe CJumpList
A `CJumpList` é a lista de atalhos exibido quando você clique com botão direito no ícone na barra de tarefas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CJumpList;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CJumpList::CJumpList](#cjumplist)|Constrói um objeto `CJumpList`.|  
|[CJumpList:: ~ CJumpList](#cjumplist__~cjumplist)|Destrói um objeto `CJumpList`.|  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CJumpList::AbortList](#abortlist)|Anula uma transação de criação de lista sem confirmação.|  
|[CJumpList::AddDestination](#adddestination)|Sobrecarregado. Adiciona o destino à lista.|  
|[CJumpList::AddKnownCategory](#addknowncategory)|Acrescenta uma categoria conhecido na lista.|  
|[CJumpList::AddTask](#addtask)|Sobrecarregado. Adiciona itens à categoria de tarefas canônica.|  
|[CJumpList::AddTasks](#addtasks)|Adiciona itens à categoria de tarefas canônica.|  
|[CJumpList::AddTaskSeparator](#addtaskseparator)|Adiciona um separador entre tarefas.|  
|[CJumpList::ClearAll](#clearall)|Remove todas as tarefas e destinos que foram adicionados à instância atual do `CJumpList` até agora.|  
|[CJumpList::ClearAllDestinations](#clearalldestinations)|Remove todos os destinos que foram adicionados à instância atual do `CJumpList` até agora.|  
|[CJumpList::CommitList](#commitlist)|Termina uma transação de criação de lista e confirma a lista relatada para o armazenamento associado (o registro neste caso).|  
|[CJumpList::GetDestinationList](#getdestinationlist)|Recupera um ponteiro de interface à lista de destino.|  
|[CJumpList::GetMaxSlots](#getmaxslots)|Recupera o número máximo de itens, incluindo os cabeçalhos de categoria que podem exibir no menu de destino do aplicativo de chamada.|  
|[CJumpList::GetRemovedItems](#getremoveditems)|A matriz retorna os itens que representam removido destinos.|  
|[CJumpList::InitializeList](#initializelist)|Inicia uma transação de criação de lista.|  
|[CJumpList::SetAppID](#setappid)|Define a ID do modelo do usuário de aplicativo da lista que será criada.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CJumpList](../../mfc/reference/cjumplist-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxadv.h  
  
##  <a name="a-namedtorcjumplista--cjumplistcjumplist"></a><a name="_dtorcjumplist"></a>CJumpList:: ~ CJumpList  
 Destrói um objeto `CJumpList`.  
  
```  
~CJumpList();
```  
  
##  <a name="a-nameabortlista--cjumplistabortlist"></a><a name="abortlist"></a>CJumpList::AbortList  
 Anula uma transação de criação de lista sem confirmação.  
  
```  
void AbortList();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar esse método tem o mesmo efeito que destruindo `CJumpList` sem chamar `CommitList`.  
  
##  <a name="a-nameadddestinationa--cjumplistadddestination"></a><a name="adddestination"></a>CJumpList::AddDestination  
 Adiciona o destino à lista.  
  
```  
BOOL AddDestination(
    LPCTSTR lpcszCategoryName,  
    LPCTSTR strDestinationPath);

 
BOOL AddDestination(
    LPCTSTR strCategoryName,  
    IShellItem* pShellItem);

 
BOOL AddDestination(
    LPCTSTR strCategoryName,  
    IShellLink* pShellLink);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpcszCategoryName`  
 Especifica um nome de categoria. Se a categoria especificada não existir, ele será criado.  
  
 `strDestinationPath`  
 Especifica um caminho para o arquivo de destino.  
  
 `strCategoryName`  
 Especifica um nome de categoria. Se a categoria especificada não existir, ele será criado.  
  
 `pShellItem`  
 Especifica um Item de Shell que representa o destino que está sendo adicionado.  
  
 `pShellLink`  
 Especifica um Link do Shell que representa o destino que está sendo adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 A instância do `CJumpList` internamente acumula destinos adicionados e, em seguida, confirma em `CommitList`.  
  
##  <a name="a-nameaddknowncategorya--cjumplistaddknowncategory"></a><a name="addknowncategory"></a>CJumpList::AddKnownCategory  
 Acrescenta uma categoria conhecido na lista.  
  
```  
BOOL AddKnownCategory(KNOWNDESTCATEGORY category);
```  
  
### <a name="parameters"></a>Parâmetros  
 `category`  
 Especifica um tipo de categoria conhecidos. Pode ser uma `KDC_RECENT`, ou `KDC_KNOWN`.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Conhecido categorias são as categorias frequentes e recente que podemos calculará automaticamente para cada aplicativo que utiliza `SHAddToRecentDocs` (ou indiretamente o utiliza como o shell chamá-lo em nome do aplicativo em alguns cenários).  
  
##  <a name="a-nameaddtaska--cjumplistaddtask"></a><a name="addtask"></a>CJumpList::AddTask  
 Adiciona itens à categoria de tarefas canônica.  
  
```  
BOOL AddTask(
    LPCTSTR strTargetExecutablePath,  
    LPCTSTR strCommandLineArgs,  
    LPCTSTR strTitle,  
    LPCTSTR strIconLocation,  
    int iIconIndex);  
  
BOOL AddTask(IShellLink* pShellLink);
```  
  
### <a name="parameters"></a>Parâmetros  
 `strTargetExecutablePath`  
 Especifica o caminho de destino da tarefa.  
  
 `strCommandLineArgs`  
 Especifica os argumentos de linha de comando do executável especificado pelo strTargetExecutablePath.  
  
 `strTitle`  
 Nome da tarefa que será exibido na lista de destino.  
  
 `strIconLocation`  
 Localização do ícone que será exibido na lista de destino, junto com o título.  
  
 `iIconIndex`  
 Índice do ícone.  
  
 `pShellLink`  
 Link do shell que representa uma tarefa a ser adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 A instância do `CJumpList` acumula tarefas especificadas e os adiciona à lista de destino durante a `CommitList`. Itens de tarefa serão exibidos em uma categoria na parte inferior do menu de destino do aplicativo. Essa categoria tem precedência sobre todas as outras categorias quando ele é preenchido na interface do usuário.  
  
##  <a name="a-nameaddtasksa--cjumplistaddtasks"></a><a name="addtasks"></a>CJumpList::AddTasks  
 Adiciona itens à categoria de tarefas canônica.  
  
```  
BOOL AddTasks(IObjectArray* pObjectCollection);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pObjectCollection`  
 Uma coleção de tarefas a ser adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 A instância do CJumpList acumula tarefas especificadas e os adiciona à lista de destino durante a `CommitList`. Itens de tarefa serão exibidos em uma categoria na parte inferior do menu de destino do aplicativo. Essa categoria tem precedência sobre todas as outras categorias quando ele é preenchido na interface do usuário.  
  
##  <a name="a-nameaddtaskseparatora--cjumplistaddtaskseparator"></a><a name="addtaskseparator"></a>CJumpList::AddTaskSeparator  
 Adiciona um separador entre tarefas.  
  
```  
BOOL AddTaskSeparator();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se ele for bem-sucedido, 0 se não for.  
  
##  <a name="a-namecjumplista--cjumplistcjumplist"></a><a name="cjumplist"></a>CJumpList::CJumpList  
 Constrói um objeto `CJumpList`.  
  
```  
CJumpList(BOOL bAutoCommit = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bAutoCommit`  
 Se esse parâmetro for falso a lista não é automaticamente confirmada no destruidor.  
  
##  <a name="a-nameclearalla--cjumplistclearall"></a><a name="clearall"></a>CJumpList::ClearAll  
 Remove todas as tarefas e destinos que foram adicionados à instância atual do `CJumpList` até agora.  
  
```  
void ClearAll();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método limpa e libera todos os dados e as interfaces internas.  
  
##  <a name="a-nameclearalldestinationsa--cjumplistclearalldestinations"></a><a name="clearalldestinations"></a>CJumpList::ClearAllDestinations  
 Remove todos os destinos que foram adicionados à instância atual do CJumpList até agora.  
  
```  
void ClearAllDestinations();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função se você precisar remover todos os destinos que foram adicionados até o momento na sessão atual de criação da lista de destino e adicionar outros destinos novamente. Se o interno `ICustomDestinationList` tiver sido inicializado, fica ativo.  
  
##  <a name="a-namecommitlista--cjumplistcommitlist"></a><a name="commitlist"></a>CJumpList::CommitList  
 Termina uma transação de criação de lista e confirma a lista relatada para o armazenamento associado (o registro neste caso).  
  
```  
BOOL CommitList();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 A confirmação é atômica. Um erro será retornado se houver uma falha.  Quando `CommitList` é chamado, o atual lista de itens removidos serão limpas. Chamar este método redefine o objeto para que ele não tem uma transação ativa de criação de lista. Para atualizar a lista `BeginList` precisa ser chamado novamente.  
  
##  <a name="a-namegetdestinationlista--cjumplistgetdestinationlist"></a><a name="getdestinationlist"></a>CJumpList::GetDestinationList  
 Recupera um ponteiro de interface à lista de destino.  
  
```  
ICustomDestinationList* GetDestinationList();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Se a lista de atalhos não foi inicializada, ou foi confirmada ou anulada, o valor retornado será `NULL`.  
  
##  <a name="a-namegetmaxslotsa--cjumplistgetmaxslots"></a><a name="getmaxslots"></a>CJumpList::GetMaxSlots  
 Recupera o número máximo de itens, incluindo os cabeçalhos de categoria que podem exibir no menu de destino do aplicativo de chamada.  
  
```  
UINT GetMaxSlots() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Aplicativos podem apenas relatar um número de itens e cabeçalhos de categoria combinados até esse valor. Se chama `AppendCategory`, `AppendKnownCategory`, ou `AddUserTasks` exceder esse número, eles retornarão uma falha.  
  
##  <a name="a-namegetremoveditemsa--cjumplistgetremoveditems"></a><a name="getremoveditems"></a>CJumpList::GetRemovedItems  
 A matriz retorna os itens que representam removido destinos.  
  
```  
IObjectArray* GetRemovedItems();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Os destinos removidos são recuperados durante a inicialização da lista de atalhos. Ao gerar uma nova lista de destino, aplicativos devem processar primeiro a lista de destinos removidos, limpando os dados de rastreamento para qualquer item retornado pelo enumerador lista removido. Se um aplicativo tenta fornecer um item que simplesmente foi removido da transação atual plano de `BeginList` iniciado, a chamada de método adicionados novamente esse item falhará, para garantir que os aplicativos são respeitando lista removida.  
  
##  <a name="a-nameinitializelista--cjumplistinitializelist"></a><a name="initializelist"></a>CJumpList::InitializeList  
 Inicia uma transação de criação de lista.  
  
```  
BOOL InitializeList();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Você não precisa chamar esse método explicitamente, a menos que você deseja recuperar um ponteiro para `ICustomDestinationList` usando `GetDestinationList`, o número de slots disponíveis usando o `GetMaxSlots`, ou uma lista de itens removidos usando `GetRemovedItems`.  
  
##  <a name="a-namesetappida--cjumplistsetappid"></a><a name="setappid"></a>CJumpList::SetAppID  
 Define a ID do modelo do usuário de aplicativo da lista que será criada.  
  
```  
void SetAppID(LPCTSTR strAppID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `strAppID`  
 Uma cadeia de caracteres que especifica a ID do modelo de usuário do aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

