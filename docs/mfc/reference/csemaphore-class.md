---
title: Classe CSemaphore
ms.date: 11/04/2016
f1_keywords:
- CSemaphore
- AFXMT/CSemaphore
- AFXMT/CSemaphore::CSemaphore
helpviewer_keywords:
- CSemaphore [MFC], CSemaphore
ms.assetid: 385fc7e4-8f86-4be2-85e1-d23b38c12f7f
ms.openlocfilehash: 26e1fd55d321b221f4732874d57d02a79c4c6398
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318509"
---
# <a name="csemaphore-class"></a>Classe CSemaphore

Um objeto `CSemaphore` de classe representa um "semáforo" — um objeto de sincronização que permite que um número limitado de threads em um ou mais processos acesse mantém uma contagem do número de threads que acessa atualmente um recurso especificado.

## <a name="syntax"></a>Sintaxe

```
class CSemaphore : public CSyncObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSemaphore::CSemaphore](#csemaphore)|Constrói um objeto `CSemaphore`.|

## <a name="remarks"></a>Comentários

Os semáforos são úteis para controlar o acesso a um recurso compartilhado que só pode suportar um número limitado de usuários. A contagem `CSemaphore` atual do objeto é o número de usuários adicionais permitidos. Quando a contagem chegar a zero, todas `CSemaphore` as tentativas de uso do recurso controlado pelo objeto serão inseridas em uma fila do sistema e esperarão até que elas tenham um tempo ou a contagem suba acima de 0. O número máximo de usuários que podem acessar o recurso controlado `CSemaphore` de uma só vez é especificado durante a construção do objeto.

Para usar `CSemaphore` um objeto, construa o `CSemaphore` objeto quando necessário. Especifique o nome do semáforo que deseja esperar e que sua aplicação deve inicialmente possuí-lo. Em seguida, você pode acessar o semáforo quando o construtor retorna. Chamada [CSyncObject::Desbloqueie](../../mfc/reference/csyncobject-class.md#unlock) quando terminar de acessar o recurso controlado.

Um método alternativo `CSemaphore` para o uso de `CSemaphore` objetos é adicionar uma variável de tipo como membro de dados à classe que você deseja controlar. Durante a construção do objeto controlado, `CSemaphore` ligue para o construtor do membro de dados especificando a contagem inicial de acesso, contagem máxima de acesso, nome do semáforo (se ele será usado através dos limites do processo) e atributos de segurança desejados.

Para acessar recursos `CSemaphore` controlados por objetos dessa maneira, primeiro crie uma variável do tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou digite [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do seu recurso. Em seguida, chame `Lock` a função de membro do objeto de bloqueio (por exemplo, [CSingleLock::Lock](../../mfc/reference/csinglelock-class.md#lock)). Neste ponto, seu thread ganhará acesso ao recurso, aguardará o recurso para ser liberado e terá acesso, ou aguardará o recurso ser liberado e o tempo de saída, não conseguindo acesso ao recurso. De qualquer forma, seu recurso foi acessado de forma segura. Para liberar o recurso, use `Unlock` a função de membro do objeto de bloqueio (por exemplo, [CSingleLock::Unlock)](../../mfc/reference/csinglelock-class.md#unlock)ou permita que o objeto de bloqueio saia do escopo.

Alternativamente, você pode `CSemaphore` criar um objeto autônomo e acessá-lo explicitamente antes de tentar acessar o recurso controlado. Este método, embora mais claro para alguém lendo seu código fonte, é mais propenso a erros.

Para obter mais informações `CSemaphore` sobre como usar objetos, consulte o artigo [Multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Csyncobject](../../mfc/reference/csyncobject-class.md)

`CSemaphore`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

## <a name="csemaphorecsemaphore"></a><a name="csemaphore"></a>CSemaphore::CSemaphore

Constrói um objeto nomeado `CSemaphore` ou sem nome.

```
CSemaphore(
    LONG lInitialCount = 1,
    LONG lMaxCount = 1,
    LPCTSTR pstrName = NULL,
    LPSECURITY_ATTRIBUTES lpsaAttributes = NULL);
```

### <a name="parameters"></a>Parâmetros

*lInitialCount*<br/>
A contagem inicial de uso para o semáforo. Deve ser maior ou igual a 0, e menor ou igual a *lMaxCount*.

*iMaxCount*<br/>
A contagem máxima de uso para o semáforo. Deve ser maior que 0.

*pstrName*<br/>
O nome do semáforo. Deve ser fornecido se o semáforo for acessado através dos limites do processo. Se `NULL`, o objeto não será nomeado. Se o nome corresponde a um semáforo existente, o construtor `CSemaphore` constrói um novo objeto que faz referência ao semáforo desse nome. Se o nome corresponder a um objeto de sincronização existente que não seja um semáforo, a construção falhará.

*lpsaAttributes*<br/>
Atributos de segurança para o objeto semafórico. Para obter uma descrição completa desta estrutura, consulte [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) no SDK do Windows.

### <a name="remarks"></a>Comentários

Para acessar ou `CSemaphore` liberar um objeto, crie um objeto [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) e chame suas funções de membro [Bloquear](../../mfc/reference/csinglelock-class.md#lock) e [Desbloquear.](../../mfc/reference/csinglelock-class.md#unlock)

> [!IMPORTANT]
> Depois de `CSemaphore` criar o objeto, use [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) para garantir que o mutex já não existisse. Se o mutex existiu inesperadamente, pode indicar que um processo desonesto está agachado e pode estar pretendendo usar o mutex maliciosamente. Neste caso, o procedimento recomendado para a segurança é fechar a alça e continuar como se houvesse uma falha na criação do objeto.

## <a name="see-also"></a>Confira também

[Classe CSyncObject](../../mfc/reference/csyncobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
