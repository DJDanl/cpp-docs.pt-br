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
ms.openlocfilehash: 2e45e2e58bd51d36b6412940b7ed01aa119017ed
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754940"
---
# <a name="cjumplist-class"></a>Classe CJumpList

A `CJumpList` é a lista de atalhos revelados quando você clica com o botão direito do mouse em um ícone na barra de tarefas.

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
|[CJumpList::Abortlist](#abortlist)|Aborta uma transação de construção de listas sem cometer.|
|[CJumplist::AddDestination](#adddestination)|Sobrecarregado. Adiciona destino à lista.|
|[CJumplist::AddKnownCategory](#addknowncategory)|Anexa uma categoria conhecida à lista.|
|[CJumpList::Adicionartarefa](#addtask)|Sobrecarregado. Adiciona itens à categoria Tarefas canônicas.|
|[CJumplist::Adicionartarefas](#addtasks)|Adiciona itens à categoria Tarefas canônicas.|
|[CJumpList::AddTaskSeparator](#addtaskseparator)|Adiciona um separador entre as tarefas.|
|[CJumpList::ClearAll](#clearall)|Remove todas as tarefas e destinos que foram `CJumpList` adicionados à instância atual até agora.|
|[CJumpList::ClearAllDestinations](#clearalldestinations)|Remove todos os destinos que foram adicionados `CJumpList` à instância atual até agora.|
|[CJumpList::CommitList](#commitlist)|Termina uma transação de construção de listas e compromete a lista relatada à loja associada (o registro neste caso.)|
|[CJumpList::GetDestinationList](#getdestinationlist)|Recupera um ponteiro de interface para a lista de destinos.|
|[CJumpList::GetMaxSlots](#getmaxslots)|Recupera o número máximo de itens, incluindo cabeçalhos de categoria que podem ser exibidos no menu de destino do aplicativo de chamada.|
|[CJumpList::GetRemovedItems](#getremoveditems)|Retorna matriz de itens que representam destinos removidos.|
|[CJumpList::InitializeList](#initializelist)|Começa uma transação de construção de listas.|
|[CJumplist::SetAppID](#setappid)|Define o ID do modelo do usuário do aplicativo para a lista que será construída.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CJumpList](../../mfc/reference/cjumplist-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxadv.h

## <a name="cjumplistcjumplist"></a><a name="_dtorcjumplist"></a>CJumpList::~CJumpList

Destrói um objeto `CJumpList`.

```
~CJumpList();
```

## <a name="cjumplistabortlist"></a><a name="abortlist"></a>CJumpList::Abortlist

Aborta uma transação de construção de listas sem cometer.

```cpp
void AbortList();
```

### <a name="remarks"></a>Comentários

Chamar esse método tem o `CJumpList` mesmo `CommitList`efeito de destruir sem chamar.

## <a name="cjumplistadddestination"></a><a name="adddestination"></a>CJumplist::AddDestination

Adiciona destino à lista.

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
Especifica um nome de categoria. Se a categoria especificada não existir, ela será criada.

*strDestinationPath*<br/>
Especifica um caminho para o arquivo de destino.

*strCategoryName*<br/>
Especifica um nome de categoria. Se a categoria especificada não existir, ela será criada.

*pShellItem*<br/>
Especifica um Item Shell representando o destino a ser adicionado.

*pShellLink*<br/>
Especifica um Link Shell representando o destino a ser adicionado.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

A instância `CJumpList` de internamente acumula destinos adicionados `CommitList`e, em seguida, os compromete em .

## <a name="cjumplistaddknowncategory"></a><a name="addknowncategory"></a>CJumplist::AddKnownCategory

Anexa uma categoria conhecida à lista.

```
BOOL AddKnownCategory(KNOWNDESTCATEGORY category);
```

### <a name="parameters"></a>Parâmetros

*category*<br/>
Especifica um tipo de categoria conhecido. Pode ser KDC_RECENT ou KDC_KNOWN.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Categorias conhecidas são as categorias Freqüentes e Recentes que calcularemos automaticamente para cada aplicativo que utiliza (ou indiretamente usa-o como o shell irá chamá-lo em nome do aplicativo em alguns `SHAddToRecentDocs` cenários).

## <a name="cjumplistaddtask"></a><a name="addtask"></a>CJumpList::Adicionartarefa

Adiciona itens à categoria Tarefas canônicas.

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
Especifica o caminho da tarefa de destino.

*strCommandLineArgs*<br/>
Especifica os argumentos da linha de comando do executável especificado pelo *strTargetExecutablePath*.

*strTitle*<br/>
Nome da tarefa que será exibido na Lista de Destinos.

*strIconLocalização*<br/>
Localização do ícone que será exibido na Lista de Destinos junto com o título.

*iIconIndex*<br/>
Índice de ícones.

*pShellLink*<br/>
Shell Link que representa uma tarefa a ser adicionada.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

A instância `CJumpList` de acumular tarefas especificadas e `CommitList`as adiciona à Lista de destino durante . Os itens de tarefa aparecerão em uma categoria na parte inferior do menu de destino do aplicativo. Esta categoria tem precedência sobre todas as outras categorias quando é preenchida na UI.

## <a name="cjumplistaddtasks"></a><a name="addtasks"></a>CJumplist::Adicionartarefas

Adiciona itens à categoria Tarefas canônicas.

```
BOOL AddTasks(IObjectArray* pObjectCollection);
```

### <a name="parameters"></a>Parâmetros

*pObjectCollection*<br/>
Uma coleção de tarefas a serem adicionadas.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

A instância do CJumpList acumula tarefas especificadas e `CommitList`as adiciona à Lista de destinos durante . Os itens de tarefa aparecerão em uma categoria na parte inferior do menu de destino do aplicativo. Esta categoria tem precedência sobre todas as outras categorias quando é preenchida na UI.

## <a name="cjumplistaddtaskseparator"></a><a name="addtaskseparator"></a>CJumpList::AddTaskSeparator

Adiciona um separador entre as tarefas.

```
BOOL AddTaskSeparator();
```

### <a name="return-value"></a>Valor retornado

Não zero se for bem sucedido, 0 se não for.

## <a name="cjumplistcjumplist"></a><a name="cjumplist"></a>CJumpList::CJumpList

Constrói um objeto `CJumpList`.

```
CJumpList(BOOL bAutoCommit = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bAutoCommit*<br/>
Se este parâmetro for FALSO, a lista não será automaticamente cometida em destructor.

## <a name="cjumplistclearall"></a><a name="clearall"></a>CJumpList::ClearAll

Remove todas as tarefas e destinos que foram `CJumpList` adicionados à instância atual até agora.

```cpp
void ClearAll();
```

### <a name="remarks"></a>Comentários

Este método limpa e libera todos os dados e interfaces internas.

## <a name="cjumplistclearalldestinations"></a><a name="clearalldestinations"></a>CJumpList::ClearAllDestinations

Remove todos os destinos que foram adicionados à instância atual do CJumpList até agora.

```cpp
void ClearAllDestinations();
```

### <a name="remarks"></a>Comentários

Chame essa função se você precisar remover todos os destinos que foram adicionados até agora na sessão atual de construção de lista de destinos e adicionar outros destinos novamente. Se o `ICustomDestinationList` interno foi inicializado, ele é deixado vivo.

## <a name="cjumplistcommitlist"></a><a name="commitlist"></a>CJumpList::CommitList

Termina uma transação de construção de listas e compromete a lista relatada à loja associada (o registro neste caso).

```
BOOL CommitList();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

O compromisso é atômico. Um erro será devolvido se o compromisso falhar.  Quando `CommitList` for chamado, a lista atual de itens removidos será limpa. Chamar esse método redefine o objeto para que ele não tenha uma transação ativa de construção de listas. Para atualizar a `BeginList` lista, precisa ser chamado novamente.

## <a name="cjumplistgetdestinationlist"></a><a name="getdestinationlist"></a>CJumpList::GetDestinationList

Recupera um ponteiro de interface para a lista de destinos.

```
ICustomDestinationList* GetDestinationList();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Se a lista de salto não tiver sido inicializada ou tiver sido comprometida ou abortada, o valor devolvido será NULA.

## <a name="cjumplistgetmaxslots"></a><a name="getmaxslots"></a>CJumpList::GetMaxSlots

Recupera o número máximo de itens, incluindo cabeçalhos de categoria que podem ser exibidos no menu de destino do aplicativo de chamada.

```
UINT GetMaxSlots() const;
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Os aplicativos só podem relatar uma série de itens e cabeçalhos de categoria combinados até este valor. Se chamadas `AppendCategory` `AppendKnownCategory`para `AddUserTasks` , ou exceder este número, eles retornarão falha.

## <a name="cjumplistgetremoveditems"></a><a name="getremoveditems"></a>CJumpList::GetRemovedItems

Retorna matriz de itens que representam destinos removidos.

```
IObjectArray* GetRemovedItems();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Os destinos removidos são recuperados durante a inicialização da lista de saltos. Ao gerar uma nova lista de destinos, espera-se que os aplicativos primeiro processem a lista de destinos removidos, limpando seus dados de rastreamento para qualquer item devolvido pelo enumerador de lista removido. Se um aplicativo tentar fornecer um item que acabou de `BeginList` ser removido na transação que a chamada atual para iniciar, a chamada do método que readicionou esse item falhará, para garantir que os aplicativos estejam respeitando a lista removida.

## <a name="cjumplistinitializelist"></a><a name="initializelist"></a>CJumpList::InitializeList

Começa uma transação de construção de listas.

```
BOOL InitializeList();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Você não precisa chamar este método explicitamente, a menos `ICustomDestinationList` que `GetDestinationList`você deseje recuperar `GetMaxSlots`um ponteiro para usar `GetRemovedItems`, o número de slots disponíveis usando ou lista de itens removidos usando .

## <a name="cjumplistsetappid"></a><a name="setappid"></a>CJumplist::SetAppID

Define o ID do modelo do usuário do aplicativo para a lista que será construída.

```cpp
void SetAppID(LPCTSTR strAppID);
```

### <a name="parameters"></a>Parâmetros

*strAppID*<br/>
Uma seqüência que especifica o ID do modelo do usuário do aplicativo.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
