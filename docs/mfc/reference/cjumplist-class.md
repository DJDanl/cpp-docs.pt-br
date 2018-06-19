---
title: Classe CJumpList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CJumpList
- AFXADV/CJumpList
- AFXADV/CJumpList::CJumpList
- AFXADV/CJumpList::AbortList
- AFXADV/CJumpList::AddDestination
- AFXADV/CJumpList::AddKnownCategory
- AFXADV/CJumpList::AddTask
- AFXADV/CJumpList::AddTasks
- AFXADV/CJumpList::AddTaskSeparator
- AFXADV/CJumpList::ClearAll
- AFXADV/CJumpList::ClearAllDestinations
- AFXADV/CJumpList::CommitList
- AFXADV/CJumpList::GetDestinationList
- AFXADV/CJumpList::GetMaxSlots
- AFXADV/CJumpList::GetRemovedItems
- AFXADV/CJumpList::InitializeList
- AFXADV/CJumpList::SetAppID
dev_langs:
- C++
helpviewer_keywords:
- CJumpList [MFC], CJumpList
- CJumpList [MFC], AbortList
- CJumpList [MFC], AddDestination
- CJumpList [MFC], AddKnownCategory
- CJumpList [MFC], AddTask
- CJumpList [MFC], AddTasks
- CJumpList [MFC], AddTaskSeparator
- CJumpList [MFC], ClearAll
- CJumpList [MFC], ClearAllDestinations
- CJumpList [MFC], CommitList
- CJumpList [MFC], GetDestinationList
- CJumpList [MFC], GetMaxSlots
- CJumpList [MFC], GetRemovedItems
- CJumpList [MFC], InitializeList
- CJumpList [MFC], SetAppID
ms.assetid: d364d27e-f512-4b12-9872-c2a17c78ab1f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d22fa264f48d3c5b1b6b88db338bc3be45c3f398
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33369044"
---
# <a name="cjumplist-class"></a>Classe CJumpList
A `CJumpList` é a lista de atalhos exibido quando você clique com botão direito em um ícone na barra de tarefas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CJumpList;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CJumpList::CJumpList](#cjumplist)|Constrói um objeto `CJumpList`.|  
|[CJumpList:: ~ CJumpList](#cjumplist__~cjumplist)|Destrói um objeto `CJumpList`.|  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CJumpList::AbortList](#abortlist)|Anula uma transação de criação de lista sem confirmação.|  
|[CJumpList::AddDestination](#adddestination)|Sobrecarregado. Adiciona o destino à lista.|  
|[CJumpList::AddKnownCategory](#addknowncategory)|Acrescenta uma categoria conhecida à lista.|  
|[CJumpList::AddTask](#addtask)|Sobrecarregado. Adiciona itens a categoria de tarefa canônica.|  
|[CJumpList::AddTasks](#addtasks)|Adiciona itens a categoria de tarefa canônica.|  
|[CJumpList::AddTaskSeparator](#addtaskseparator)|Adiciona um separador entre tarefas.|  
|[CJumpList::ClearAll](#clearall)|Remove todas as tarefas e destinos que foram adicionados à instância atual do `CJumpList` até o momento.|  
|[CJumpList::ClearAllDestinations](#clearalldestinations)|Remove todos os destinos que foram adicionados à instância atual do `CJumpList` até o momento.|  
|[CJumpList::CommitList](#commitlist)|Finaliza uma transação de criação de lista e confirma a lista relatada para o armazenamento associado (o registro neste caso).|  
|[CJumpList::GetDestinationList](#getdestinationlist)|Recupera um ponteiro de interface à lista de destino.|  
|[CJumpList::GetMaxSlots](#getmaxslots)|Recupera o número máximo de itens, incluindo os cabeçalhos de categoria que podem exibir no menu de destino do aplicativo de chamada.|  
|[CJumpList::GetRemovedItems](#getremoveditems)|Matriz retorna itens que representam remover destinos.|  
|[CJumpList::InitializeList](#initializelist)|Inicia uma transação de criação de lista.|  
|[CJumpList::SetAppID](#setappid)|Define a ID de modelo de usuário do aplicativo para obter a lista que será criada.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CJumpList](../../mfc/reference/cjumplist-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxadv.h  
  
##  <a name="_dtorcjumplist"></a>  CJumpList:: ~ CJumpList  
 Destrói um objeto `CJumpList`.  
  
```  
~CJumpList();
```  
  
##  <a name="abortlist"></a>  CJumpList::AbortList  
 Anula uma transação de criação de lista sem confirmação.  
  
```  
void AbortList();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar esse método tem o mesmo efeito de destruição `CJumpList` sem chamar `CommitList`.  
  
##  <a name="adddestination"></a>  CJumpList::AddDestination  
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
 Especifica um Link de Shell que representa o destino que está sendo adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 A instância do `CJumpList` internamente acumula adicionados destinos e, em seguida, confirma em `CommitList`.  
  
##  <a name="addknowncategory"></a>  CJumpList::AddKnownCategory  
 Acrescenta uma categoria conhecida à lista.  
  
```  
BOOL AddKnownCategory(KNOWNDESTCATEGORY category);
```  
  
### <a name="parameters"></a>Parâmetros  
 `category`  
 Especifica um tipo de categoria conhecida. Pode ser uma `KDC_RECENT`, ou `KDC_KNOWN`.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Conhecido categorias são as categorias frequentes e recentes que podemos calcular automaticamente para cada aplicativo que utiliza `SHAddToRecentDocs` (ou indiretamente o utiliza como o shell chamá-lo em nome do aplicativo em alguns cenários).  
  
##  <a name="addtask"></a>  CJumpList::AddTask  
 Adiciona itens a categoria de tarefa canônica.  
  
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
 Especifica argumentos de linha de comando do executável especificado pelo strTargetExecutablePath.  
  
 `strTitle`  
 Nome da tarefa que será exibido na lista de destino.  
  
 `strIconLocation`  
 Localização do ícone que será exibido na lista de destino, junto com o título.  
  
 `iIconIndex`  
 Índice do ícone.  
  
 `pShellLink`  
 Link de shell que representa uma tarefa a ser adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 A instância do `CJumpList` acumula tarefas especificadas e os adiciona à lista de destino durante a `CommitList`. Itens de tarefas serão exibidos em uma categoria na parte inferior do menu de destino do aplicativo. Esta categoria tem precedência sobre todas as outras categorias quando ele é preenchido na interface de usuário.  
  
##  <a name="addtasks"></a>  CJumpList::AddTasks  
 Adiciona itens a categoria de tarefa canônica.  
  
```  
BOOL AddTasks(IObjectArray* pObjectCollection);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pObjectCollection`  
 Uma coleção de tarefas a ser adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 A instância do CJumpList acumula tarefas especificadas e adiciona-os à lista de destino durante a `CommitList`. Itens de tarefas serão exibidos em uma categoria na parte inferior do menu de destino do aplicativo. Esta categoria tem precedência sobre todas as outras categorias quando ele é preenchido na interface de usuário.  
  
##  <a name="addtaskseparator"></a>  CJumpList::AddTaskSeparator  
 Adiciona um separador entre tarefas.  
  
```  
BOOL AddTaskSeparator();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se ele for bem-sucedido, 0 se não for.  
  
##  <a name="cjumplist"></a>  CJumpList::CJumpList  
 Constrói um objeto `CJumpList`.  
  
```  
CJumpList(BOOL bAutoCommit = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bAutoCommit`  
 Se esse parâmetro for FALSE a lista não é confirmada automaticamente em destruidor.  
  
##  <a name="clearall"></a>  CJumpList::ClearAll  
 Remove todas as tarefas e destinos que foram adicionados à instância atual do `CJumpList` até o momento.  
  
```  
void ClearAll();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método limpa e libera todos os dados e as interfaces internas.  
  
##  <a name="clearalldestinations"></a>  CJumpList::ClearAllDestinations  
 Remove todos os destinos que foram adicionados à instância atual do CJumpList até o momento.  
  
```  
void ClearAllDestinations();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função se você precisar remover todos os destinos que foram adicionados até o momento na sessão atual de criação de lista de destino e adicionar outros destinos novamente. Se o interno `ICustomDestinationList` tiver sido inicializado, ele permanecerá ativo.  
  
##  <a name="commitlist"></a>  CJumpList::CommitList  
 Finaliza uma transação de criação de lista e confirma a lista relatada para o armazenamento associado (o registro neste caso).  
  
```  
BOOL CommitList();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 A confirmação é atômica. Um erro será retornado se houver uma falha.  Quando `CommitList` é chamado, atual lista de itens removidos serão limpas. Chamar este método redefine o objeto para que ele não tem uma transação ativa de criação de lista. Para atualizar a lista `BeginList` precisa ser chamado novamente.  
  
##  <a name="getdestinationlist"></a>  CJumpList::GetDestinationList  
 Recupera um ponteiro de interface à lista de destino.  
  
```  
ICustomDestinationList* GetDestinationList();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Se a lista de salto não foi inicializada, ou foi confirmada ou anulada, o valor retornado será `NULL`.  
  
##  <a name="getmaxslots"></a>  CJumpList::GetMaxSlots  
 Recupera o número máximo de itens, incluindo os cabeçalhos de categoria que podem exibir no menu de destino do aplicativo de chamada.  
  
```  
UINT GetMaxSlots() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Aplicativos só podem relatar um número de itens e cabeçalhos de categoria combinados até esse valor. Se chamadas para `AppendCategory`, `AppendKnownCategory`, ou `AddUserTasks` exceder esse número, eles retornarão uma falha.  
  
##  <a name="getremoveditems"></a>  CJumpList::GetRemovedItems  
 Matriz retorna itens que representam remover destinos.  
  
```  
IObjectArray* GetRemovedItems();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Os destinos removidos são recuperados durante a inicialização da lista de salto. Ao gerar uma nova lista de destino, os aplicativos devem processar primeiro a lista de destinos removidos, limpar seus dados de rastreamento para qualquer item retornado pelo enumerador lista removido. Se um aplicativo tenta fornecer um item que foi removido apenas na transação atual chamada para `BeginList` iniciado, a chamada de método adicionado novamente esse item falhará, para garantir que os aplicativos são respeitando a lista removida.  
  
##  <a name="initializelist"></a>  CJumpList::InitializeList  
 Inicia uma transação de criação de lista.  
  
```  
BOOL InitializeList();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Você não precisa chamar este método explicitamente, a menos que você deseja recuperar um ponteiro para `ICustomDestinationList` usando `GetDestinationList`, o número de slots disponíveis usando `GetMaxSlots`, ou uma lista de itens removidos usando `GetRemovedItems`.  
  
##  <a name="setappid"></a>  CJumpList::SetAppID  
 Define a ID de modelo de usuário do aplicativo para obter a lista que será criada.  
  
```  
void SetAppID(LPCTSTR strAppID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `strAppID`  
 Uma cadeia de caracteres que especifica a ID do modelo de usuário do aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
