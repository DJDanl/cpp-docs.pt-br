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
ms.openlocfilehash: f2a05963f39393bcc73650beb44c5dbb8e5535ee
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57274213"
---
# <a name="csemaphore-class"></a>Classe CSemaphore

Um objeto da classe `CSemaphore` representa um "semáforo" — um objeto de sincronização que permite que um número limitado de threads em um ou mais processos para acessar um manter uma contagem do número de threads que acessam atualmente um recurso especificado.

## <a name="syntax"></a>Sintaxe

```
class CSemaphore : public CSyncObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CSemaphore::CSemaphore](#csemaphore)|Constrói um objeto `CSemaphore`.|

## <a name="remarks"></a>Comentários

Semáforos são úteis para controlar o acesso a um recurso compartilhado que suporta apenas um número limitado de usuários. A contagem atual do `CSemaphore` objeto é o número de usuários adicionais permitidos. Quando a contagem chega a zero, todas as tentativas de usar o recurso controlado pelo `CSemaphore` objeto será inserido em uma fila do sistema e aguarde até que eles esgotar o tempo limite ou a contagem subir acima de 0. O número máximo de usuários que podem acessar o recurso controlado ao mesmo tempo é especificado durante a construção do `CSemaphore` objeto.

Para usar um `CSemaphore` do objeto, construa o `CSemaphore` objeto quando ele for necessário. Especifique o nome do sinal do qual você deseja esperar e que seu aplicativo deve possuí-lo inicialmente. Você pode acessar o semaphore quando o construtor retorna. Chame [CSyncObject::Unlock](../../mfc/reference/csyncobject-class.md#unlock) quando você terminar o acesso ao recurso controlado.

Um método alternativo para usar `CSemaphore` objetos é adicionar uma variável do tipo `CSemaphore` como um membro de dados para a classe que você deseja o controle. Durante a construção do objeto controlado, chame o construtor do `CSemaphore` membro de dados especificando inicial acessar contagem, contagem máxima de acesso, nome do sinal do (se ele será usado em limites de processo) e os atributos de segurança desejados.

Para acessar os recursos controlados por `CSemaphore` objetos dessa maneira, primeiro crie uma variável do tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou digite [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do recurso. Em seguida, chamar o objeto de bloqueio `Lock` função de membro (por exemplo, [CSingleLock::Lock](../../mfc/reference/csinglelock-class.md#lock)). Neste ponto, seu thread será a obter acesso ao recurso, aguarde até que o recurso a ser lançado e obter acesso ou aguarde até que o recurso seja liberado e o tempo limite, não consegue obter acesso ao recurso. Em qualquer caso, o recurso tiver sido acessado de forma thread-safe. Para liberar o recurso, use o objeto de bloqueio `Unlock` função de membro (por exemplo, [CSingleLock::Unlock](../../mfc/reference/csinglelock-class.md#unlock)), ou permitir que o objeto de bloqueio sair do escopo.

Como alternativa, você pode criar um `CSemaphore` autônomo de objeto e acessá-lo explicitamente antes de tentar acessar o recurso controlado. Esse método, ao mesmo tempo mais evidente para alguém ler seu código-fonte, é mais propenso a erros.

Para obter mais informações sobre como usar `CSemaphore` objetos, consulte o artigo [Multithreading: Como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CSyncObject](../../mfc/reference/csyncobject-class.md)

`CSemaphore`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

##  <a name="csemaphore"></a>  CSemaphore::CSemaphore

Constrói um nomeado ou sem nome `CSemaphore` objeto.

```
CSemaphore(
    LONG lInitialCount = 1,
    LONG lMaxCount = 1,
    LPCTSTR pstrName = NULL,
    LPSECURITY_ATTRIBUTES lpsaAttributes = NULL);
```

### <a name="parameters"></a>Parâmetros

*lInitialCount*<br/>
A contagem de uso inicial para o semáforo. Deve ser maior que ou igual a 0 e menor ou igual a *lMaxCount*.

*lMaxCount*<br/>
A contagem de uso máximo para o semáforo. Deve ser maior que 0.

*pstrName*<br/>
O nome do sinal. Deve ser fornecido se o semáforo será acessado pelos limites do processo. Se `NULL`, o objeto estará sem nome. Se o nome corresponder a um semáforo existente, o construtor cria um novo `CSemaphore` objeto que referencia o semáforo desse nome. Se o nome corresponder a um objeto de sincronização existente que não é um sinal, a construção falhará.

*lpsaAttributes*<br/>
Atributos de segurança para o objeto de semáforo. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](https://msdn.microsoft.com/library/windows/desktop/aa379560) no SDK do Windows.

### <a name="remarks"></a>Comentários

Para acessar ou liberar um `CSemaphore` do objeto, crie um [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto e chame seu [bloqueio](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) funções de membro.

> [!IMPORTANT]
>  Depois de criar o `CSemaphore` do objeto, use [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) para garantir que o mutex ainda não existia. Se o mutex existia inesperadamente, isso poderá indicar um processo não autorizado é apropriação indevida e pode ser pretendendo usar o mutex de maneira mal-intencionada. Nesse caso, o procedimento recomendado de valorizam a segurança é fechar o identificador e continuará como se houve uma falha na criação do objeto.

## <a name="see-also"></a>Consulte também

[Classe CSyncObject](../../mfc/reference/csyncobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
