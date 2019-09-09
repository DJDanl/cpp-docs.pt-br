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
ms.openlocfilehash: 65f7f4db9489de1c9a380d760ed5cab41bfdc2ec
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504513"
---
# <a name="cmutex-class"></a>Classe CMutex

Representa um "mutex" — um objeto de sincronização que permite que um thread tenha acesso mutuamente exclusivo a um recurso.

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

Os mutexes são úteis quando apenas um thread de cada vez pode ter permissão para modificar dados ou algum outro recurso controlado. Por exemplo, a adição de nós a uma lista vinculada é um processo que só deve ser permitido por um thread por vez. Usando um `CMutex` objeto para controlar a lista vinculada, somente um thread por vez pode obter acesso à lista.

Para usar um `CMutex` objeto, construa o `CMutex` objeto quando necessário. Especifique o nome do mutex que você deseja aguardar e que seu aplicativo inicialmente deve ser proprietário dele. Em seguida, você pode acessar o mutex quando o Construtor retornar. Chame [CSyncObject:: Unlock](../../mfc/reference/csyncobject-class.md#unlock) quando você terminar de acessar o recurso controlado.

Um método alternativo para usar `CMutex` objetos é adicionar uma variável do tipo `CMutex` como um membro de dados à classe que você deseja controlar. Durante a construção do objeto controlado, chame o construtor do membro `CMutex` de dados especificando se o mutex é de propriedade inicial, o nome do mutex (se ele será usado em limites de processo) e os atributos de segurança desejados.

Para acessar recursos controlados `CMutex` por objetos dessa maneira, primeiro crie uma variável de um dos tipos [CSingleLock](../../mfc/reference/csinglelock-class.md) ou digite [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do recurso. Em seguida, chame a função `Lock` de membro do objeto de bloqueio (por exemplo, [CSingleLock:: Lock](../../mfc/reference/csinglelock-class.md#lock)). Neste ponto, seu thread terá acesso ao recurso, aguardará o lançamento do recurso e obterá acesso, ou aguardará que o recurso seja liberado e atingirá o tempo limite, falha ao obter acesso ao recurso. Em qualquer caso, o recurso foi acessado de forma segura para thread. Para liberar o recurso, use a função de membro `Unlock` do objeto de bloqueio (por exemplo, [CSingleLock:: Unlock](../../mfc/reference/csinglelock-class.md#unlock)) ou permita que o objeto de bloqueio se torne fora do escopo.

Para obter mais informações sobre `CMutex` como usar objetos, consulte [o artigo Multithreading: Como usar as classes](../../parallel/multithreading-how-to-use-the-synchronization-classes.md)de sincronização.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CSyncObject](../../mfc/reference/csyncobject-class.md)

`CMutex`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt. h

##  <a name="cmutex"></a>CMutex::CMutex

Constrói um `CMutex` objeto nomeado ou sem nome.

```
CMutex(
    BOOL bInitiallyOwn = FALSE,
    LPCTSTR lpszName = NULL,
    LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
```

### <a name="parameters"></a>Parâmetros

*bInitiallyOwn*<br/>
Especifica se o thread que cria `CMutex` o objeto inicialmente tem acesso ao recurso controlado pelo mutex.

*lpszName*<br/>
Nome do objeto de `CMutex` . Se outro mutex com o mesmo nome existir, *lpszName* deverá ser fornecido se o objeto for usado em limites de processo. Se for **NULL**, o mutex não será nomeado. Se o nome corresponder a um mutex existente, o Construtor criará `CMutex` um novo objeto que referencia o mutex desse nome. Se o nome corresponder a um objeto de sincronização existente que não seja um mutex, a construção falhará.

*lpsaAttribute*<br/>
Atributos de segurança para o objeto mutex. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) no SDK do Windows.

### <a name="remarks"></a>Comentários

Para acessar ou liberar um `CMutex` objeto, crie um objeto [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) e chame suas funções de membro [Lock](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) . Se o `CMutex` objeto estiver sendo usado de forma autônoma, chame sua `Unlock` função de membro para liberá-lo.

> [!IMPORTANT]
>  Depois de criar `CMutex` o objeto, use [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) para garantir que o mutex ainda não exista. Se o mutex existia inesperadamente, ele pode indicar que um processo não autorizado é de apropriação indevida e pode estar pretendendo usar o mutex de forma mal-intencionada. Nesse caso, o procedimento de consciência de segurança recomendado é fechar a alça e continuar como se houvesse uma falha na criação do objeto.

## <a name="see-also"></a>Consulte também

[Classe CSyncObject](../../mfc/reference/csyncobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
