---
title: Classe CMutex
ms.date: 11/04/2016
f1_keywords:
- CMutex
- AFXMT/CMutex
- AFXMT/CMutex::CMutex
helpviewer_keywords:
- CMutex [MFC], CMutex
ms.assetid: 6330c050-4f01-4195-a099-2029b92f8cf1
ms.openlocfilehash: 2d6f637ab4828b3e70df205ebf359ae45a940d60
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363281"
---
# <a name="cmutex-class"></a>Classe CMutex

Representa um "mutex" — um objeto de sincronização que permite um thread de acesso mutuamente exclusivo a um recurso.

## <a name="syntax"></a>Sintaxe

```
class CMutex : public CSyncObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMutex::CMutex](#cmutex)|Constrói um objeto `CMutex`.|

## <a name="remarks"></a>Comentários

Mutexes são úteis quando apenas um segmento de cada vez pode ser permitido modificar dados ou algum outro recurso controlado. Por exemplo, adicionar nomes a uma lista vinculada é um processo que só deve ser permitido por um segmento de cada vez. Usando um `CMutex` objeto para controlar a lista vinculada, apenas um segmento de cada vez pode ter acesso à lista.

Para usar `CMutex` um objeto, construa o `CMutex` objeto quando necessário. Especifique o nome do mutex que deseja esperar e que seu aplicativo deve inicialmente possuí-lo. Em seguida, você pode acessar o mutex quando o construtor retorna. Chamada [CSyncObject::Desbloqueie](../../mfc/reference/csyncobject-class.md#unlock) quando terminar de acessar o recurso controlado.

Um método alternativo `CMutex` para o uso de `CMutex` objetos é adicionar uma variável de tipo como membro de dados à classe que você deseja controlar. Durante a construção do objeto controlado, `CMutex` ligue para o construtor do membro de dados especificando se o mutex é inicialmente de propriedade, o nome do mutex (se ele será usado através dos limites do processo) e os atributos de segurança desejados.

Para acessar recursos `CMutex` controlados por objetos dessa maneira, primeiro crie uma variável do tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou digite [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do seu recurso. Em seguida, chame `Lock` a função de membro do objeto de bloqueio (por exemplo, [CSingleLock::Lock](../../mfc/reference/csinglelock-class.md#lock)). Neste ponto, seu thread ganhará acesso ao recurso, aguardará o recurso para ser liberado e terá acesso, ou aguardará o recurso ser liberado e o tempo de saída, não conseguindo acesso ao recurso. De qualquer forma, seu recurso foi acessado de forma segura. Para liberar o recurso, use `Unlock` a função de membro do objeto de bloqueio (por exemplo, [CSingleLock::Unlock)](../../mfc/reference/csinglelock-class.md#unlock)ou permita que o objeto de bloqueio saia do escopo.

Para obter mais `CMutex` informações sobre o uso de objetos, consulte o artigo [Multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Csyncobject](../../mfc/reference/csyncobject-class.md)

`CMutex`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

## <a name="cmutexcmutex"></a><a name="cmutex"></a>CMutex::CMutex

Constrói um objeto nomeado `CMutex` ou sem nome.

```
CMutex(
    BOOL bInitiallyOwn = FALSE,
    LPCTSTR lpszName = NULL,
    LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
```

### <a name="parameters"></a>Parâmetros

*bInicialmentePossuir*<br/>
Especifica se o segmento `CMutex` que cria o objeto inicialmente tem acesso ao recurso controlado pelo mutex.

*lpszName*<br/>
Nome do objeto de `CMutex` . Se houver outro mutex com o mesmo nome, *lpszName* deve ser fornecido se o objeto for usado através dos limites do processo. Se **NULO,** o mutex não será nomeado. Se o nome corresponder a um mutex existente, `CMutex` o construtor construirá um novo objeto que faz referência ao mutex desse nome. Se o nome corresponder a um objeto de sincronização existente que não seja um mutex, a construção falhará.

*lpsaAttribute*<br/>
Atributos de segurança para o objeto mutex. Para obter uma descrição completa desta estrutura, consulte [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) no SDK do Windows.

### <a name="remarks"></a>Comentários

Para acessar ou `CMutex` liberar um objeto, crie um objeto [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) e chame suas funções de membro [Bloquear](../../mfc/reference/csinglelock-class.md#lock) e [Desbloquear.](../../mfc/reference/csinglelock-class.md#unlock) Se `CMutex` o objeto estiver sendo usado `Unlock` autônomo, chame sua função de membro para liberá-lo.

> [!IMPORTANT]
> Depois de `CMutex` criar o objeto, use [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) para garantir que o mutex já não existisse. Se o mutex existiu inesperadamente, pode indicar que um processo desonesto está agachado e pode estar pretendendo usar o mutex maliciosamente. Neste caso, o procedimento recomendado para a segurança é fechar a alça e continuar como se houvesse uma falha na criação do objeto.

## <a name="see-also"></a>Confira também

[Classe CSyncObject](../../mfc/reference/csyncobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
