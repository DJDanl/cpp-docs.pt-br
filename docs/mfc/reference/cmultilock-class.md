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
ms.openlocfilehash: 27c0eb396ac1384b691f51bf7089f6820157cf8a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50613415"
---
# <a name="cmultilock-class"></a>Classe CMultiLock

Representa o mecanismo de controle de acesso usado no controle de acesso aos recursos em um programa multi-threaded.

## <a name="syntax"></a>Sintaxe

```
class CMultiLock
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMultiLock::CMultiLock](#cmultilock)|Constrói um objeto `CMultiLock`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMultiLock::IsLocked](#islocked)|Determina se um objeto de sincronização específico na matriz está bloqueado.|
|[CMultiLock::Lock](#lock)|Espera-se na matriz de objetos de sincronização.|
|[CMultiLock::Unlock](#unlock)|Libera todos os objetos corporativos de sincronização.|

## <a name="remarks"></a>Comentários

`CMultiLock` não tem uma classe base.

Para usar as classes de sincronização [CSemaphore](../../mfc/reference/csemaphore-class.md), [CMutex](../../mfc/reference/cmutex-class.md), e [CEvent](../../mfc/reference/cevent-class.md), você pode criar um `CMultiLock` ou [CSingleLock](../../mfc/reference/csinglelock-class.md)objeto para aguardar e liberar o objeto de sincronização. Use `CMultiLock` quando houver vários objetos que você poderia usar em um momento específico. Use `CSingleLock` quando você só precisa esperar em um objeto por vez.

Para usar um `CMultiLock` de objeto, primeiro crie uma matriz de objetos de sincronização que você deseja esperar. Em seguida, chame o `CMultiLock` construtor do objeto dentro de uma função de membro na classe do recurso controlado. Em seguida, chame o [bloqueio](#lock) função de membro para determinar se um recurso está disponível (sinalizado). Caso haja algum, continue com o restante da função de membro. Se nenhum recurso estiver disponível, aguarde até que uma quantidade especificada de tempo para um recurso a ser liberado ou retornar falha. Após a conclusão do uso de um recurso, chamar o [Unlock](#unlock) funcionará se o `CMultiLock` objeto deve ser usado novamente ou permitir que o `CMultiLock` objeto a ser destruído.

`CMultiLock` objetos são mais úteis quando um thread tiver um grande número de `CEvent` objetos que ele pode responder. Criar uma matriz que contém todos os `CEvent` ponteiros e chamada `Lock`. Isso fará com que o thread a esperar até que um dos eventos é sinalizado.

Para obter mais informações sobre como usar `CMultiLock` objetos, consulte o artigo [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CMultiLock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

##  <a name="cmultilock"></a>  CMultiLock::CMultiLock

Constrói um objeto `CMultiLock`.

```
CMultiLock(
    CSyncObject* ppObjects [ ],
    DWORD dwCount,
    BOOL bInitialLock = FALSE);
```

### <a name="parameters"></a>Parâmetros

*ppObjects*<br/>
Matriz de ponteiros para os objetos de sincronização a ser aguardado. Não pode ser NULL.

*dwCount*<br/>
Número de objetos no *ppObjects*. Deve ser maior que 0.

*bInitialLock*<br/>
Especifica se deve ser inicialmente tentar acessar qualquer um dos objetos fornecidos.

### <a name="remarks"></a>Comentários

Essa função é chamada depois de criar a matriz de objetos de sincronização a ser aguardado. Ele geralmente é chamado de dentro do thread que precisarem esperar por um dos objetos de sincronização se torne disponível.

##  <a name="islocked"></a>  CMultiLock::IsLocked

Determina se o objeto especificado é não sinalizado (não disponível).

```
BOOL IsLocked(DWORD dwItem);
```

### <a name="parameters"></a>Parâmetros

*dwItem*<br/>
O índice na matriz de objetos correspondente ao objeto cujo estado está sendo consultado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto especificado estiver bloqueado; Caso contrário, 0.

##  <a name="lock"></a>  CMultiLock::Lock

Chame essa função para obter acesso a um ou mais dos recursos controlados por objetos de sincronização fornecidos para o `CMultiLock` construtor.

```
DWORD Lock(
    DWORD dwTimeOut = INFINITE,
    BOOL bWaitForAll = TRUE,
    DWORD dwWakeMask = 0);
```

### <a name="parameters"></a>Parâmetros

*dwTimeOut*<br/>
Especifica a quantidade de tempo de espera para o objeto de sincronização estejam disponíveis (sinalizado). Se for infinito, `Lock` aguardará até que o objeto é sinalizado antes de retornar.

*bWaitForAll*<br/>
Especifica se todos os objetos que aguardaram devem ser assinados ao mesmo tempo antes de retornar. Se for FALSE, `Lock` retornará quando qualquer um dos objetos aguardada é sinalizado.

*dwWakeMask*<br/>
Especifica a outras condições que têm permissão para anular a espera. Para obter uma lista completa das opções disponíveis para esse parâmetro, consulte [MsgWaitForMultipleObjects](/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Se `Lock` falhar, retornará - 1. Se for bem-sucedido, ele retorna um dos seguintes valores:

- Entre WAIT_OBJECT_0 e WAIT_OBJECT_0 + (número de objetos - 1)

   Se *bWaitForAll* for TRUE, todos os objetos são sinalizados (disponível). Se *bWaitForAll* é FALSE, o valor de retorno - WAIT_OBJECT_0 é o índice na matriz de objetos do objeto que é sinalizado (disponível).

- WAIT_OBJECT_0 + (número de objetos)

   Um evento especificado na *dwWakeMask* está disponível na fila de entrada do thread.

- Entre WAIT_ABANDONED_0 e WAIT_ABANDONED_0 + (número de objetos - 1)

   Se *bWaitForAll* for TRUE, todos os objetos são sinalizados e pelo menos um dos objetos é um objeto de mutex abandonado. Se *bWaitForAll* é FALSE, o valor de retorno - WAIT_ABANDONED_0 é o índice na matriz de objetos do objeto mutex abandonado que atendeu à espera.

- WAIT_TIMEOUT

   O intervalo de tempo limite especificado na *dwTimeOut* expiradas sem o sucesso de espera.

### <a name="remarks"></a>Comentários

Se *bWaitForAll* for TRUE, `Lock` retornará com êxito, assim como todos os objetos de sincronização sinalizados simultaneamente. Se *bWaitForAll* é FALSE, `Lock` retornará assim que um ou mais dos objetos de sincronização se torna sinalizado.

Se `Lock` não é capaz de retornar imediatamente, ele aguardará para não mais do que o número de milissegundos especificado na *dwTimeOut* parâmetro antes de retornar. Se *dwTimeOut* é infinito, `Lock` não retornará até que o acesso a um objeto for obtido ou uma condição especificada no *dwWakeMask* foi atendida. Caso contrário, se `Lock` foi capaz de adquirir um objeto de sincronização, ele retornará com êxito; se não, ela retornará a falha.

##  <a name="unlock"></a>  CMultiLock::Unlock

Libera o objeto de sincronização pertencente a `CMultiLock`.

```
BOOL Unlock();

BOOL Unlock(
    LONG lCount,
    LPLONG lPrevCount = NULL);
```

### <a name="parameters"></a>Parâmetros

*lCount*<br/>
Número de referência de conta liberar. Deve ser maior que 0. Se a quantidade especificada faria com que a contagem de objeto exceder seu máximo, a contagem não será alterada e a função retornará FALSE.

*lPrevCount*<br/>
Aponta para uma variável para receber a contagem anterior para o objeto de sincronização. Se for NULL, a contagem anterior não é retornada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função for bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é chamada pelo `CMultiLock`do destruidor.

A primeira forma de `Unlock` tenta desbloquear o objeto de sincronização gerenciado pelo `CMultiLock`. A segunda forma de `Unlock` tenta desbloquear o `CSemaphore` objetos possuídos por `CMultiLock`. Se `CMultiLock` não possui qualquer bloqueado `CSemaphore` objeto, a função retorna FALSO; caso contrário, retornará TRUE. *lCount* e *lpPrevCount* são exatamente os mesmos que os parâmetros do [CSingleLock::Unlock](../../mfc/reference/csinglelock-class.md#unlock). A segunda forma de `Unlock` é raramente aplicável a situações multilock.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

