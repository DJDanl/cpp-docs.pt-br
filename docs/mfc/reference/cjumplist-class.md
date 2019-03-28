---
title: Classe CJumpList
ms.date: 03/27/2019
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
ms.openlocfilehash: 9296912c97b1efb5f7cbd1ed9f769d0222d5f85c
ms.sourcegitcommit: 309dc532f13242854b47759cef846de59bb807f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/28/2019
ms.locfileid: "58565302"
---
# <a name="cjumplist-class"></a>Classe CJumpList

Um `CJumpList` é a lista de atalhos revelada quando o botão direito do mouse em um ícone na barra de tarefas.

## <a name="syntax"></a>Sintaxe

```
class CJumpList;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CJumpList::CJumpList](#cjumplist)|Constrói um objeto `CJumpList`.|
|[CJumpList::~CJumpList](#_dtorcjumplist)|Destrói um objeto `CJumpList`.|

|Nome|Descrição|
|----------|-----------------|
|[CJumpList::AbortList](#abortlist)|Anula uma transação de criação de lista sem confirmação.|
|[CJumpList::AddDestination](#adddestination)|Sobrecarregado. Adiciona o destino à lista.|
|[CJumpList::AddKnownCategory](#addknowncategory)|Acrescenta uma categoria conhecidos à lista.|
|[CJumpList::AddTask](#addtask)|Sobrecarregado. Adiciona itens à categoria de tarefas canônica.|
|[CJumpList::AddTasks](#addtasks)|Adiciona itens à categoria de tarefas canônica.|
|[CJumpList::AddTaskSeparator](#addtaskseparator)|Adiciona um separador entre tarefas.|
|[CJumpList::ClearAll](#clearall)|Remove todas as tarefas e destinos que foram adicionados à instância atual do `CJumpList` até o momento.|
|[CJumpList::ClearAllDestinations](#clearalldestinations)|Remove todos os destinos que foram adicionados à instância atual do `CJumpList` até o momento.|
|[CJumpList::CommitList](#commitlist)|Finaliza uma transação de criação de lista e confirma a lista relatada para o armazenamento associado (o registro neste caso).|
|[CJumpList::GetDestinationList](#getdestinationlist)|Recupera um ponteiro de interface à lista de destino.|
|[CJumpList::GetMaxSlots](#getmaxslots)|Recupera o número máximo de itens, incluindo os cabeçalhos de categoria que podem exibir no menu de destino do aplicativo de chamada.|
|[CJumpList::GetRemovedItems](#getremoveditems)|Retorna uma matriz de itens que representam removido destinos.|
|[CJumpList::InitializeList](#initializelist)|Inicia uma transação de criação de lista.|
|[CJumpList::SetAppID](#setappid)|Define a ID de modelo de usuário do aplicativo para a lista que será compilada.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CJumpList](../../mfc/reference/cjumplist-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxadv.h

##  <a name="_dtorcjumplist"></a>  CJumpList::~CJumpList

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

Chamar esse método tem o mesmo efeito que destruindo `CJumpList` sem chamar `CommitList`.

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

*lpcszCategoryName*<br/>
Especifica um nome de categoria. Se a categoria especificada não existir, ele será criado.

*strDestinationPath*<br/>
Especifica um caminho para o arquivo de destino.

*strCategoryName*<br/>
Especifica um nome de categoria. Se a categoria especificada não existir, ele será criado.

*pShellItem*<br/>
Especifica um Item de Shell que representa o destino que está sendo adicionado.

*pShellLink*<br/>
Especifica um Link de Shell que representa o destino que está sendo adicionado.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

A instância do `CJumpList` acumula internamente destinos adicionados e, em seguida, confirma-los no `CommitList`.

##  <a name="addknowncategory"></a>  CJumpList::AddKnownCategory

Acrescenta uma categoria conhecidos à lista.

```
BOOL AddKnownCategory(KNOWNDESTCATEGORY category);
```

### <a name="parameters"></a>Parâmetros

*category*<br/>
Especifica um tipo de categoria conhecidos. Pode ser KDC_RECENT ou KDC_KNOWN.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Conhecido de categorias são as categorias frequentes e recentes que podemos calcular automaticamente para cada aplicativo que utiliza `SHAddToRecentDocs` (ou indiretamente o usa como o shell de chamá-lo em nome do aplicativo em alguns cenários).

##  <a name="addtask"></a>  CJumpList::AddTask

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

*strTargetExecutablePath*<br/>
Especifica o caminho de destino da tarefa.

*strCommandLineArgs*<br/>
Especifica argumentos de linha de comando do executável especificado pelo *strTargetExecutablePath*.

*strTitle*<br/>
Nome da tarefa que será exibido na lista de destino.

*strIconLocation*<br/>
Localização do ícone que será exibido na lista de destino com o título.

*iIconIndex*<br/>
Índice do ícone.

*pShellLink*<br/>
Link de shell que representa uma tarefa a ser adicionado.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

A instância do `CJumpList` acumula tarefas especificadas e os adiciona à lista de destino durante `CommitList`. Itens de tarefa serão exibidos em uma categoria na parte inferior do menu de destino do aplicativo. Esta categoria tem precedência sobre todas as outras categorias, quando ele é preenchido na interface do usuário.

##  <a name="addtasks"></a>  CJumpList::AddTasks

Adiciona itens à categoria de tarefas canônica.

```
BOOL AddTasks(IObjectArray* pObjectCollection);
```

### <a name="parameters"></a>Parâmetros

*pObjectCollection*<br/>
Uma coleção de tarefas a ser adicionado.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

A instância do CJumpList acumula tarefas especificadas e o adiciona à lista de destino durante `CommitList`. Itens de tarefa serão exibidos em uma categoria na parte inferior do menu de destino do aplicativo. Esta categoria tem precedência sobre todas as outras categorias, quando ele é preenchido na interface do usuário.

##  <a name="addtaskseparator"></a>  CJumpList::AddTaskSeparator

Adiciona um separador entre tarefas.

```
BOOL AddTaskSeparator();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se for bem-sucedido, 0 se não estiver.

##  <a name="cjumplist"></a>  CJumpList::CJumpList

Constrói um objeto `CJumpList`.

```
CJumpList(BOOL bAutoCommit = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAutoCommit*<br/>
Se esse parâmetro for falso a lista não é confirmada automaticamente no destruidor.

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

Chame essa função se você precisar remover todos os destinos que serão adicionados até o momento na sessão atual de criação da lista de destino e adicionar outros destinos novamente. Se o interno `ICustomDestinationList` tiver sido inicializado, ele permanecerá ativo.

##  <a name="commitlist"></a>  CJumpList::CommitList

Finaliza uma transação de criação de lista e confirma a lista relatada para o armazenamento associado (o registro neste caso).

```
BOOL CommitList();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

A confirmação é atômica. Um erro será retornado se a confirmação falhar.  Quando `CommitList` é chamado, atual lista de itens removidos serão limpas. Chamar este método redefine o objeto para que ele não tem uma transação ativa de construção de lista. Para atualizar a lista `BeginList` precisa ser chamado novamente.

##  <a name="getdestinationlist"></a>  CJumpList::GetDestinationList

Recupera um ponteiro de interface à lista de destino.

```
ICustomDestinationList* GetDestinationList();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Se a lista de atalhos não foi inicializada, ou foi confirmada ou anulada, o valor retornado será NULL.

##  <a name="getmaxslots"></a>  CJumpList::GetMaxSlots

Recupera o número máximo de itens, incluindo os cabeçalhos de categoria que podem exibir no menu de destino do aplicativo de chamada.

```
UINT GetMaxSlots() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Aplicativos podem apenas relatar um número de itens e cabeçalhos de categoria combinados até esse valor. Se chamadas para `AppendCategory`, `AppendKnownCategory`, ou `AddUserTasks` exceder esse número, eles retornarão uma falha.

##  <a name="getremoveditems"></a>  CJumpList::GetRemovedItems

Retorna uma matriz de itens que representam removido destinos.

```
IObjectArray* GetRemovedItems();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Os destinos removidos são recuperados durante a inicialização da lista de atalhos. Ao gerar uma nova lista de destino, os aplicativos devem processar primeiro a lista de destinos removidos, limpar seus dados de acompanhamento para qualquer item retornado pelo enumerador lista removido. Se um aplicativo tenta fornecer um item que foi removido apenas na transação que a chamada atual para `BeginList` iniciado, chamada de método que é adicionado novamente esse item não conseguirá, certifique-se de que os aplicativos são respeitando lista removida.

##  <a name="initializelist"></a>  CJumpList::InitializeList

Inicia uma transação de criação de lista.

```
BOOL InitializeList();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Você não precisa chamar esse método explicitamente, a menos que você deseja recuperar um ponteiro para `ICustomDestinationList` usando `GetDestinationList`, o número de slots disponíveis usando `GetMaxSlots`, ou uma lista de itens removidos usando `GetRemovedItems`.

##  <a name="setappid"></a>  CJumpList::SetAppID

Define a ID de modelo de usuário do aplicativo para a lista que será compilada.

```
void SetAppID(LPCTSTR strAppID);
```

### <a name="parameters"></a>Parâmetros

*strAppID*<br/>
Uma cadeia de caracteres que especifica a ID do modelo de usuário do aplicativo.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
