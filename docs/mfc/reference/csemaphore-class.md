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
ms.openlocfilehash: d5a0e4187107aaab7cedf4e7a0e2fc47b9f9f305
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502578"
---
# <a name="csemaphore-class"></a>Classe CSemaphore

Um objeto da classe `CSemaphore` representa um "semáforo" — um objeto de sincronização que permite que um número limitado de threads em um ou mais processos acessem um mantenha uma contagem do número de threads que atualmente acessam um recurso especificado.

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

Os semáforos são úteis para controlar o acesso a um recurso compartilhado que só pode dar suporte a um número limitado de usuários. A contagem atual do `CSemaphore` objeto é o número de usuários adicionais permitidos. Quando a contagem chega a zero, todas as tentativas de usar o recurso controlado `CSemaphore` pelo objeto serão inseridas em uma fila do sistema e aguardarão até que elas atinjam o tempo limite ou a contagem seja acima de 0. O número máximo de usuários que podem acessar o recurso controlado ao mesmo tempo é especificado durante a `CSemaphore` construção do objeto.

Para usar um `CSemaphore` objeto, construa o `CSemaphore` objeto quando necessário. Especifique o nome do semáforo que você deseja aguardar e que seu aplicativo inicialmente deve ser proprietário dele. Em seguida, você pode acessar o semáforo quando o construtor retorna. Chame [CSyncObject:: Unlock](../../mfc/reference/csyncobject-class.md#unlock) quando você terminar de acessar o recurso controlado.

Um método alternativo para usar `CSemaphore` objetos é adicionar uma variável do tipo `CSemaphore` como um membro de dados à classe que você deseja controlar. Durante a construção do objeto controlado, chame o construtor do membro `CSemaphore` de dados especificando a contagem de acesso inicial, a contagem máxima de acesso, o nome do semáforo (se ele será usado em limites de processo) e os atributos de segurança desejados.

Para acessar recursos controlados `CSemaphore` por objetos dessa maneira, primeiro crie uma variável de um dos tipos [CSingleLock](../../mfc/reference/csinglelock-class.md) ou digite [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do recurso. Em seguida, chame a função `Lock` de membro do objeto de bloqueio (por exemplo, [CSingleLock:: Lock](../../mfc/reference/csinglelock-class.md#lock)). Neste ponto, seu thread terá acesso ao recurso, aguardará o lançamento do recurso e obterá acesso, ou aguardará que o recurso seja liberado e atingirá o tempo limite, falha ao obter acesso ao recurso. Em qualquer caso, o recurso foi acessado de forma segura para thread. Para liberar o recurso, use a função de membro `Unlock` do objeto de bloqueio (por exemplo, [CSingleLock:: Unlock](../../mfc/reference/csinglelock-class.md#unlock)) ou permita que o objeto de bloqueio se torne fora do escopo.

Como alternativa, você pode criar um `CSemaphore` objeto autônomo e acessá-lo explicitamente antes de tentar acessar o recurso controlado. Esse método, embora mais claro para alguém que leia seu código-fonte, é mais propenso a erros.

Para obter mais informações sobre como usar `CSemaphore` objetos, consulte o artigo [multithreading: Como usar as classes](../../parallel/multithreading-how-to-use-the-synchronization-classes.md)de sincronização.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CSyncObject](../../mfc/reference/csyncobject-class.md)

`CSemaphore`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt. h

##  <a name="csemaphore"></a>  CSemaphore::CSemaphore

Constrói um `CSemaphore` objeto nomeado ou sem nome.

```
CSemaphore(
    LONG lInitialCount = 1,
    LONG lMaxCount = 1,
    LPCTSTR pstrName = NULL,
    LPSECURITY_ATTRIBUTES lpsaAttributes = NULL);
```

### <a name="parameters"></a>Parâmetros

*lInitialCount*<br/>
A contagem de uso inicial para o semáforo. Deve ser maior ou igual a 0 e menor ou igual a *lMaxCount*.

*lMaxCount*<br/>
A contagem máxima de uso para o semáforo. Deve ser maior que 0.

*pstrName*<br/>
O nome do semáforo. Deve ser fornecido se o semáforo for acessado entre limites de processo. Se `NULL`, o objeto não será nomeado. Se o nome corresponder a um semáforo existente, o Construtor criará `CSemaphore` um novo objeto que faz referência ao semáforo desse nome. Se o nome corresponder a um objeto de sincronização existente que não seja um semáforo, a construção falhará.

*lpsaAttributes*<br/>
Atributos de segurança para o objeto Semaphore. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) no SDK do Windows.

### <a name="remarks"></a>Comentários

Para acessar ou liberar um `CSemaphore` objeto, crie um objeto [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) e chame suas funções de membro [Lock](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) .

> [!IMPORTANT]
>  Depois de criar `CSemaphore` o objeto, use [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) para garantir que o mutex ainda não exista. Se o mutex existia inesperadamente, ele pode indicar que um processo não autorizado é de apropriação indevida e pode estar pretendendo usar o mutex de forma mal-intencionada. Nesse caso, o procedimento de consciência de segurança recomendado é fechar a alça e continuar como se houvesse uma falha na criação do objeto.

## <a name="see-also"></a>Consulte também

[Classe CSyncObject](../../mfc/reference/csyncobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
