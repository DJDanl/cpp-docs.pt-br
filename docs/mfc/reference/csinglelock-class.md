---
title: Classe CSingleLock
ms.date: 11/04/2016
f1_keywords:
- CSingleLock
- AFXMT/CSingleLock
- AFXMT/CSingleLock::CSingleLock
- AFXMT/CSingleLock::IsLocked
- AFXMT/CSingleLock::Lock
- AFXMT/CSingleLock::Unlock
helpviewer_keywords:
- CSingleLock [MFC], CSingleLock
- CSingleLock [MFC], IsLocked
- CSingleLock [MFC], Lock
- CSingleLock [MFC], Unlock
ms.assetid: 7dae7288-8066-4a3e-85e0-78d28bfc6bc8
ms.openlocfilehash: 231397228d94e58665602453b5d377571e24a967
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318267"
---
# <a name="csinglelock-class"></a>Classe CSingleLock

Representa o mecanismo de controle de acesso usado no controle do acesso a um recurso em um programa multithreaded.

## <a name="syntax"></a>Sintaxe

```
class CSingleLock
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[csinglelock::Csinglelock](#csinglelock)|Constrói um objeto `CSingleLock`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[csinglelock::islocked](#islocked)|Determina se o objeto está bloqueado.|
|[Csinglelock::Bloqueio](#lock)|Espera em um objeto de sincronização.|
|[Csinglelock::Unlock](#unlock)|Libera um objeto de sincronização.|

## <a name="remarks"></a>Comentários

`CSingleLock`não tem uma classe base.

Para usar as classes de sincronização [CSemaphore,](../../mfc/reference/csemaphore-class.md) [CMutex,](../../mfc/reference/cmutex-class.md) [CCriticalSection](../../mfc/reference/ccriticalsection-class.md)e `CSingleLock` [CEvent,](../../mfc/reference/cevent-class.md)você deve criar um objeto CMultiLock ou [cmultilock](../../mfc/reference/cmultilock-class.md) para aguardar e liberar o objeto de sincronização. Use `CSingleLock` quando você só precisa esperar em um objeto de cada vez. Use `CMultiLock` quando houver vários objetos que você pode usar em um determinado momento.

Para usar `CSingleLock` um objeto, chame seu construtor dentro de uma função de membro na classe do recurso controlado. Em seguida, ligue para a função [membro IsLocked](#islocked) para determinar se o recurso está disponível. Se for, continue com o restante da função do membro. Se o recurso não estiver disponível, aguarde um período de tempo especificado para que o recurso seja liberado ou falha no retorno. Depois que o uso do recurso estiver concluído, ligue para a função `CSingleLock` [Desbloquear](#unlock) se o `CSingleLock` objeto for usado novamente ou permita que o objeto seja destruído.

`CSingleLock`objetos requerem a presença de um objeto derivado do [CSyncObject](../../mfc/reference/csyncobject-class.md). Este é geralmente um membro de dados da classe do recurso controlado. Para obter mais informações `CSingleLock` sobre como usar objetos, consulte o artigo [Multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CSingleLock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

## <a name="csinglelockcsinglelock"></a><a name="csinglelock"></a>csinglelock::Csinglelock

Constrói um objeto `CSingleLock`.

```
explicit CSingleLock(
    CSyncObject* pObject,
    BOOL bInitialLock = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Pobject*<br/>
Aponta para o objeto de sincronização a ser acessado. Não pode ser NULL.

*bInitialLock*<br/>
Especifica se inicialmente tentará acessar o objeto fornecido.

### <a name="remarks"></a>Comentários

Esta função é geralmente chamada de dentro de uma função membro de acesso do recurso controlado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#19](../../mfc/codesnippet/cpp/csinglelock-class_1.h)]

## <a name="csinglelockislocked"></a><a name="islocked"></a>csinglelock::islocked

Determina se o objeto `CSingleLock` associado ao objeto não está sinalizado (indisponível).

```
BOOL IsLocked();
```

### <a name="return-value"></a>Valor retornado

Não zero se o objeto estiver bloqueado; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#20](../../mfc/codesnippet/cpp/csinglelock-class_2.h)]

## <a name="csinglelocklock"></a><a name="lock"></a>Csinglelock::Bloqueio

Chame esta função para obter acesso ao recurso controlado `CSingleLock` pelo objeto de sincronização fornecido ao construtor.

```
BOOL Lock(DWORD dwTimeOut = INFINITE);
```

### <a name="parameters"></a>Parâmetros

*Dwtimeout*<br/>
Especifica a quantidade de tempo para esperar que o objeto de sincronização esteja disponível (sinalizado). Se INFINITE, `Lock` esperará até que o objeto seja sinalizado antes de retornar.

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o objeto de sincronização for sinalizado, `Lock` retornará com sucesso e o segmento agora possui o objeto. Se o objeto de sincronização não `Lock` for sinalizado (indisponível), aguardará que o objeto de sincronização seja sinalizado até o número de milissegundos especificados no parâmetro *dwTimeOut.* Se o objeto de sincronização não tiver sido sinalizado na quantidade de tempo especificada, `Lock` a falha de retorno.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#21](../../mfc/codesnippet/cpp/csinglelock-class_3.h)]

## <a name="csinglelockunlock"></a><a name="unlock"></a>Csinglelock::Unlock

Libera o objeto de `CSingleLock`sincronização de propriedade de .

```
BOOL Unlock();

BOOL Unlock(
    LONG lCount,
    LPLONG lPrevCount = NULL);
```

### <a name="parameters"></a>Parâmetros

*Lcount*<br/>
Número de acessos à liberação. Deve ser maior que 0. Se a quantidade especificada fizer com que a contagem do objeto exceda seu máximo, a contagem não será alterada e a função retorna FALSA.

*IPrevCount*<br/>
Aponta para uma variável para receber a contagem anterior do objeto de sincronização. Se NULA, a contagem anterior não é devolvida.

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função é `CSingleLock`chamada pelo destruidor.

Se você precisar liberar mais de uma contagem de acesso de `Unlock` um semáforo, use a segunda forma de e especifique o número de acessos à liberação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#21](../../mfc/codesnippet/cpp/csinglelock-class_3.h)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMultiLock](../../mfc/reference/cmultilock-class.md)
