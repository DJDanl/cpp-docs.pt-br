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
ms.openlocfilehash: b2fe3ecf2197b8edb13e89600b16e550deff9af2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504546"
---
# <a name="cmultilock-class"></a>Classe CMultiLock

Representa o mecanismo de controle de acesso usado no controle do acesso a recursos em um programa multithread.

## <a name="syntax"></a>Sintaxe

```
class CMultiLock
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMultiLock::CMultiLock](#cmultilock)|Constrói um objeto `CMultiLock`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMultiLock::IsLocked](#islocked)|Determina se um objeto de sincronização específico na matriz está bloqueado.|
|[CMultiLock::Lock](#lock)|Aguarda a matriz de objetos de sincronização.|
|[CMultiLock::Unlock](#unlock)|Libera objetos de sincronização de propriedade.|

## <a name="remarks"></a>Comentários

`CMultiLock`Não tem uma classe base.

Para usar as classes de sincronização [CSemaphore](../../mfc/reference/csemaphore-class.md), [CMutex](../../mfc/reference/cmutex-class.md)e [CEvent](../../mfc/reference/cevent-class.md), você pode criar um `CMultiLock` objeto ou [CSingleLock](../../mfc/reference/csinglelock-class.md) para aguardar e liberar o objeto de sincronização. Use `CMultiLock` quando houver vários objetos que você possa usar em um determinado momento. Use `CSingleLock` quando você precisar aguardar apenas um objeto por vez.

Para usar um `CMultiLock` objeto, primeiro crie uma matriz dos objetos de sincronização que você deseja aguardar. Em seguida, chame `CMultiLock` o construtor do objeto dentro de uma função de membro na classe do recurso controlado. Em seguida, chame a função de [bloqueio](#lock) de membro para determinar se um recurso está disponível (sinalizado). Se houver, continue com o restante da função de membro. Se nenhum recurso estiver disponível, aguarde um período de tempo especificado para que um recurso seja liberado ou retorne a falha. Após a conclusão do uso de um recurso, chame a função [Unlock](#unlock) se o `CMultiLock` objeto for ser usado novamente ou permita que o `CMultiLock` objeto seja destruído.

`CMultiLock`os objetos são mais úteis quando um thread tem um grande número `CEvent` de objetos aos quais ele pode responder. Crie uma matriz que contenha `CEvent` todos os ponteiros `Lock`e chame. Isso fará com que o thread aguarde até que um dos eventos seja sinalizado.

Para obter mais informações sobre como usar `CMultiLock` objetos, consulte o artigo [multithreading: Como usar as classes](../../parallel/multithreading-how-to-use-the-synchronization-classes.md)de sincronização.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CMultiLock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt. h

##  <a name="cmultilock"></a>CMultiLock::CMultiLock

Constrói um objeto `CMultiLock`.

```
CMultiLock(
    CSyncObject* ppObjects [ ],
    DWORD dwCount,
    BOOL bInitialLock = FALSE);
```

### <a name="parameters"></a>Parâmetros

*ppObjects*<br/>
Matriz de ponteiros para os objetos de sincronização a serem aguardados. Não pode ser NULL.

*dwCount*<br/>
Número de objetos no *ppObjects*. Deve ser maior que 0.

*bInitialLock*<br/>
Especifica se deve inicialmente tentar acessar qualquer um dos objetos fornecidos.

### <a name="remarks"></a>Comentários

Essa função é chamada depois de criar a matriz de objetos de sincronização a ser aguardada. Normalmente, ele é chamado de dentro do thread que deve aguardar que um dos objetos de sincronização fique disponível.

##  <a name="islocked"></a>CMultiLock:: IsLocked

Determina se o objeto especificado não está sinalizado (não disponível).

```
BOOL IsLocked(DWORD dwItem);
```

### <a name="parameters"></a>Parâmetros

*dwItem*<br/>
O índice na matriz de objetos correspondente ao objeto cujo estado está sendo consultado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto especificado estiver bloqueado; caso contrário, 0.

##  <a name="lock"></a>CMultiLock:: Lock

Chame essa função para obter acesso a um ou mais dos recursos controlados pelos objetos de sincronização fornecidos ao `CMultiLock` Construtor.

```
DWORD Lock(
    DWORD dwTimeOut = INFINITE,
    BOOL bWaitForAll = TRUE,
    DWORD dwWakeMask = 0);
```

### <a name="parameters"></a>Parâmetros

*dwTimeOut*<br/>
Especifica a quantidade de tempo de espera para o objeto de sincronização estar disponível (sinalizado). Se infinito, `Lock` aguardará até que o objeto seja sinalizado antes de retornar.

*bWaitForAll*<br/>
Especifica se todos os objetos aguardados devem ser sinalizados ao mesmo tempo antes de retornar. Se for false `Lock` , retornará quando qualquer um dos objetos aguardados for sinalizado.

*dwWakeMask*<br/>
Especifica outras condições que têm permissão para anular a espera. Para obter uma lista completa das opções disponíveis para esse parâmetro, consulte [MsgWaitForMultipleObjects](/windows/win32/api/winuser/nf-winuser-msgwaitformultipleobjects) no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Se `Lock` falhar, retornará-1. Se for bem-sucedido, ele retornará um dos seguintes valores:

- Entre WAIT_OBJECT_0 e WAIT_OBJECT_0 + (número de objetos-1)

   Se *bWaitForAll* for true, todos os objetos serão sinalizados (disponíveis). Se *bWaitForAll* for false, o valor de retorno-WAIT_OBJECT_0 será o índice na matriz de objetos do objeto que está sinalizado (disponível).

- WAIT_OBJECT_0 + (número de objetos)

   Um evento especificado em *dwWakeMask* está disponível na fila de entrada do thread.

- Entre WAIT_ABANDONED_0 e WAIT_ABANDONED_0 + (número de objetos-1)

   Se *bWaitForAll* for true, todos os objetos serão sinalizados e pelo menos um dos objetos será um objeto mutex abandonado. Se *bWaitForAll* for false, o valor de retorno-WAIT_ABANDONED_0 será o índice na matriz de objetos do objeto mutex abandonado que satisfez a espera.

- WAIT_TIMEOUT

   O intervalo de tempo limite especificado em *dwTimeout* expirou sem que a espera tenha sido concluída com sucesso.

### <a name="remarks"></a>Comentários

Se *bWaitForAll* for true, `Lock` retornará com êxito assim que todos os objetos de sincronização forem sinalizados simultaneamente. Se *bWaitForAll* for false, `Lock` retornará assim que um ou mais dos objetos de sincronização forem sinalizados.

Se `Lock` não for possível retornar imediatamente, ele aguardará até o número de milissegundos especificado no parâmetro *dwTimeout* antes de retornar. Se *dwTimeout* for infinito, `Lock` não será retornado até que o acesso a um objeto seja obtido ou uma condição especificada em *dwWakeMask* fosse atendida. Caso contrário, `Lock` se o foi capaz de adquirir um objeto de sincronização, ele retornará com êxito; caso contrário, ele retornará uma falha.

##  <a name="unlock"></a>CMultiLock:: desbloquear

Libera o objeto de sincronização de `CMultiLock`propriedade de.

```
BOOL Unlock();

BOOL Unlock(
    LONG lCount,
    LPLONG lPrevCount = NULL);
```

### <a name="parameters"></a>Parâmetros

*lCount*<br/>
Número de contagens de referência a serem liberadas. Deve ser maior que 0. Se o valor especificado fizer com que a contagem do objeto exceda seu máximo, a contagem não será alterada e a função retornará FALSE.

*lPrevCount*<br/>
Aponta para uma variável para receber a contagem anterior do objeto de sincronização. Se for NULL, a contagem anterior não será retornada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função foi bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é chamada por `CMultiLock`destruidor.

A primeira forma de `Unlock` tentativas de desbloquear o objeto de sincronização gerenciado `CMultiLock`pelo. A segunda forma de `Unlock` tentar desbloquear os objetos `CSemaphore` pertencentes `CMultiLock`a. Se `CMultiLock` não possuir nenhum objeto bloqueado `CSemaphore` , a função retornará false; caso contrário, retornará true. *lCount* e *lpPrevCount* são exatamente os mesmos que os parâmetros de [CSingleLock:: Unlock](../../mfc/reference/csinglelock-class.md#unlock). A segunda forma de `Unlock` raramente se aplica a situações de multilock.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
