---
title: Classe CMultiLock
ms.date: 11/04/2016
f1_keywords:
- CMultiLock
- AFXMT/CMultiLock
- AFXMT/CMultiLock::CMultiLock
- AFXMT/CMultiLock::IsLocked
- AFXMT/CMultiLock::Lock
- AFXMT/CMultiLock::Unlock
helpviewer_keywords:
- CMultiLock [MFC], CMultiLock
- CMultiLock [MFC], IsLocked
- CMultiLock [MFC], Lock
- CMultiLock [MFC], Unlock
ms.assetid: c5b7c78b-1f81-4387-b7dd-2c813c5b6b61
ms.openlocfilehash: a051c6a510c53ac0c7c0a6efd8b4b5720080b264
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319706"
---
# <a name="cmultilock-class"></a>Classe CMultiLock

Representa o mecanismo de controle de acesso usado no controle do acesso aos recursos em um programa multithreaded.

## <a name="syntax"></a>Sintaxe

```
class CMultiLock
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMultilock::CMultiLock](#cmultilock)|Constrói um objeto `CMultiLock`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMultilock::islocked](#islocked)|Determina se um objeto de sincronização específico na matriz está bloqueado.|
|[CMultilock::Bloqueio](#lock)|Espera na matriz de objetos de sincronização.|
|[CMultilock::Desbloquear](#unlock)|Libera quaisquer objetos de sincronização próprios.|

## <a name="remarks"></a>Comentários

`CMultiLock`não tem uma classe base.

Para usar as classes de sincronização [CSemaphore,](../../mfc/reference/csemaphore-class.md) [CMutex](../../mfc/reference/cmutex-class.md)e `CMultiLock` [CEvent,](../../mfc/reference/cevent-class.md)você pode criar um objeto CSingleLock ou [CSingleLock](../../mfc/reference/csinglelock-class.md) para aguardar e liberar o objeto de sincronização. Use `CMultiLock` quando houver vários objetos que você pode usar em um determinado momento. Use `CSingleLock` quando você só precisa esperar em um objeto de cada vez.

Para usar `CMultiLock` um objeto, primeiro crie uma matriz dos objetos de sincronização que você deseja esperar. Em seguida, `CMultiLock` chame o construtor do objeto dentro de uma função de membro na classe do recurso controlado. Em seguida, ligue para a função [bloquear](#lock) membro para determinar se um recurso está disponível (sinalizado). Se for, continue com o restante da função do membro. Se não houver nenhum recurso disponível, aguarde um período de tempo especificado para que um recurso seja liberado ou falha no retorno. Depois que o uso de um recurso estiver `CMultiLock` concluído, ligue para a `CMultiLock` função [Desbloquear](#unlock) se o objeto for usado novamente ou permita que o objeto seja destruído.

`CMultiLock`objetos são mais úteis quando `CEvent` um segmento tem um grande número de objetos que pode responder. Crie uma matriz contendo `CEvent` todos os `Lock`ponteiros e chame . Isso fará com que o fio espere até que um dos eventos seja sinalizado.

Para obter mais informações `CMultiLock` sobre como usar objetos, consulte o artigo [Multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CMultiLock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

## <a name="cmultilockcmultilock"></a><a name="cmultilock"></a>CMultilock::CMultiLock

Constrói um objeto `CMultiLock`.

```
CMultiLock(
    CSyncObject* ppObjects [ ],
    DWORD dwCount,
    BOOL bInitialLock = FALSE);
```

### <a name="parameters"></a>Parâmetros

*ppObjetos*<br/>
Matriz de ponteiros para os objetos de sincronização a serem aguardados. Não pode ser NULL.

*Dwcount*<br/>
Número de objetos em *ppObjects*. Deve ser maior que 0.

*bInitialLock*<br/>
Especifica se inicialmente tentará acessar qualquer um dos objetos fornecidos.

### <a name="remarks"></a>Comentários

Esta função é chamada depois de criar o conjunto de objetos de sincronização a serem aguardados. Geralmente é chamado de dentro do segmento que deve esperar que um dos objetos de sincronização fique disponível.

## <a name="cmultilockislocked"></a><a name="islocked"></a>CMultilock::islocked

Determina se o objeto especificado não está sinalizado (indisponível).

```
BOOL IsLocked(DWORD dwItem);
```

### <a name="parameters"></a>Parâmetros

*dwItem*<br/>
O índice na matriz de objetos correspondenteao objeto cujo estado está sendo consultado.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto especificado estiver bloqueado; caso contrário, 0.

## <a name="cmultilocklock"></a><a name="lock"></a>CMultilock::Bloqueio

Chame esta função para obter acesso a um ou mais dos `CMultiLock` recursos controlados pelos objetos de sincronização fornecidos ao construtor.

```
DWORD Lock(
    DWORD dwTimeOut = INFINITE,
    BOOL bWaitForAll = TRUE,
    DWORD dwWakeMask = 0);
```

### <a name="parameters"></a>Parâmetros

*Dwtimeout*<br/>
Especifica a quantidade de tempo para esperar que o objeto de sincronização esteja disponível (sinalizado). Se INFINITE, `Lock` esperará até que o objeto seja sinalizado antes de retornar.

*Bwaitforall*<br/>
Especifica se todos os objetos esperados devem ser sinalizados ao mesmo tempo antes de retornar. Se FALSO, `Lock` retornará quando qualquer um dos objetos esperados for sinalizado.

*Dwwakemask*<br/>
Especifica outras condições que podem abortar a espera. Para obter uma lista completa das opções disponíveis para este parâmetro, consulte [MsgWaitForMultipleObjects](/windows/win32/api/winuser/nf-winuser-msgwaitformultipleobjects) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Se `Lock` falhar, ele retorna - 1. Se for bem sucedido, retorna um dos seguintes valores:

- Entre WAIT_OBJECT_0 e WAIT_OBJECT_0 + (número de objetos - 1)

   Se *bWaitForAll* for TRUE, todos os objetos serão sinalizados (disponíveis). Se *bWaitForAll* for FALSE, o valor de retorno - WAIT_OBJECT_0 é o índice na matriz de objetos do objeto que é sinalizado (disponível).

- WAIT_OBJECT_0 + (número de objetos)

   Um evento especificado no *dwWakeMask* está disponível na fila de entrada do segmento.

- Entre WAIT_ABANDONED_0 e WAIT_ABANDONED_0 + (número de objetos - 1)

   Se *bWaitForAll* for TRUE, todos os objetos serão sinalizados, e pelo menos um dos objetos é um objeto mutex abandonado. Se *bWaitForAll* for FALSE, o valor de retorno - WAIT_ABANDONED_0 é o índice na matriz de objetos do objeto mutex abandonado que satisfez a espera.

- Wait_timeout

   O intervalo de tempo especificado no *dwTimeOut* expirou sem que a espera tivesse sucesso.

### <a name="remarks"></a>Comentários

Se *bWaitForAll* for `Lock` TRUE, retornará com sucesso assim que todos os objetos de sincronização forem sinalizados simultaneamente. Se *bWaitForAll* for `Lock` FALSE, retornará assim que um ou mais objetos de sincronização forem sinalizados.

Se `Lock` não puder retornar imediatamente, não esperará mais do que o número de milissegundos especificado no parâmetro *dwTimeOut* antes de retornar. Se *dwTimeOut* for `Lock` INFINITE, não retornará até que o acesso a um objeto seja adquirido ou uma condição especificada no *dwWakeMask* seja atendida. Caso contrário, `Lock` se fosse capaz de adquirir um objeto de sincronização, ele retornará com sucesso; se não, ele vai retornar o fracasso.

## <a name="cmultilockunlock"></a><a name="unlock"></a>CMultilock::Desbloquear

Libera o objeto de `CMultiLock`sincronização de propriedade de .

```
BOOL Unlock();

BOOL Unlock(
    LONG lCount,
    LPLONG lPrevCount = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lcount*<br/>
Número de contagens de referência para liberação. Deve ser maior que 0. Se a quantidade especificada fizer com que a contagem do objeto exceda seu máximo, a contagem não será alterada e a função retorna FALSA.

*IPrevCount*<br/>
Aponta para uma variável para receber a contagem anterior para o objeto de sincronização. Se NULA, a contagem anterior não é devolvida.

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função é `CMultiLock`chamada pelo destruidor.

A primeira `Unlock` forma de tentativas de desbloquear `CMultiLock`o objeto de sincronização gerenciado por . A segunda `Unlock` forma de `CSemaphore` tenta desbloquear `CMultiLock`os objetos de propriedade de . Se `CMultiLock` não possuir `CSemaphore` nenhum objeto bloqueado, a função retorna FALSA; caso contrário, ele retorna VERDADEIRO. *iCount* e *lpPrevCount* são exatamente os mesmos que os parâmetros do [CSingleLock::Unlock](../../mfc/reference/csinglelock-class.md#unlock). A segunda `Unlock` forma de raramente é aplicável a situações de multitravamento.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
