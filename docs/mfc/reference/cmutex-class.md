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
ms.openlocfilehash: 823f38a6292152774f72c97963b9add5d429d2f7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50508778"
---
# <a name="cmutex-class"></a>Classe CMutex

Representa um "mutex" — um objeto de sincronização que permite um acesso mutuamente exclusivo de thread a um recurso.

## <a name="syntax"></a>Sintaxe

```
class CMutex : public CSyncObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMutex::CMutex](#cmutex)|Constrói um objeto `CMutex`.|

## <a name="remarks"></a>Comentários

Mutexes são úteis quando apenas um thread por vez poderá receber permissão para modificar dados ou algum outro recurso controlado. Por exemplo, adicionar nós a uma lista vinculada é um processo que só deve ser permitido por um thread por vez. Usando um `CMutex` objeto para controlar a lista vinculada, somente um thread por vez pode obter acesso à lista.

Para usar um `CMutex` do objeto, construa o `CMutex` objeto quando ele for necessário. Especifique o nome do mutex desejar esperar e que seu aplicativo deve possuí-lo inicialmente. Em seguida, você pode acessar o mutex quando o construtor retorna. Chame [CSyncObject::Unlock](../../mfc/reference/csyncobject-class.md#unlock) quando você terminar o acesso ao recurso controlado.

Um método alternativo para usar `CMutex` objetos é adicionar uma variável do tipo `CMutex` como um membro de dados para a classe que você deseja o controle. Durante a construção do objeto controlado, chame o construtor do `CMutex` membro de dados, especificando se o mutex pertence inicialmente, o nome do mutex (se ele será usado em limites de processo) e os atributos de segurança desejados.

Para acessar os recursos controlados por `CMutex` objetos dessa maneira, primeiro crie uma variável do tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou digite [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do recurso. Em seguida, chamar o objeto de bloqueio `Lock` função de membro (por exemplo, [CSingleLock::Lock](../../mfc/reference/csinglelock-class.md#lock)). Neste ponto, seu thread será a obter acesso ao recurso, aguarde até que o recurso a ser lançado e obter acesso ou aguarde até que o recurso seja liberado e o tempo limite, não consegue obter acesso ao recurso. Em qualquer caso, o recurso tiver sido acessado de forma thread-safe. Para liberar o recurso, use o objeto de bloqueio `Unlock` função de membro (por exemplo, [CSingleLock::Unlock](../../mfc/reference/csinglelock-class.md#unlock)), ou permitir que o objeto de bloqueio sair do escopo.

Para obter mais informações sobre como usar `CMutex` objetos, consulte o artigo [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CSyncObject](../../mfc/reference/csyncobject-class.md)

`CMutex`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

##  <a name="cmutex"></a>  CMutex::CMutex

Constrói um nomeado ou sem nome `CMutex` objeto.

```
CMutex(
    BOOL bInitiallyOwn = FALSE,
    LPCTSTR lpszName = NULL,
    LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
```

### <a name="parameters"></a>Parâmetros

*bInitiallyOwn*<br/>
Especifica se a criação de thread a `CMutex` objeto inicialmente tem acesso ao recurso controlado pelo mutex.

*lpszName*<br/>
Nome do objeto de `CMutex` . Se o mutex outro com o mesmo nome existe, *lpszName* deve ser fornecido se o objeto será usado em limites de processo. Se **nulo**, mutex será sem nome. Se o nome corresponder a um mutex existente, o construtor cria um novo `CMutex` objeto que referencia o mutex desse nome. Se o nome corresponder a um objeto de sincronização existente que não é um mutex, a construção falhará.

*lpsaAttribute*<br/>
Atributos de segurança para o objeto de mutex. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](https://msdn.microsoft.com/library/windows/desktop/aa379560) no SDK do Windows.

### <a name="remarks"></a>Comentários

Para acessar ou liberar um `CMutex` do objeto, crie um [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto e chame seu [bloqueio](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) funções de membro. Se o `CMutex` objeto está sendo usado como autônomo, chame seu `Unlock` função de membro para liberá-lo.

> [!IMPORTANT]
>  Depois de criar o `CMutex` do objeto, use [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) para garantir que o mutex ainda não existia. Se o mutex existia inesperadamente, isso poderá indicar um processo não autorizado é apropriação indevida e pode ser pretendendo usar o mutex de maneira mal-intencionada. Nesse caso, o procedimento recomendado de valorizam a segurança é fechar o identificador e continuará como se houve uma falha na criação do objeto.

## <a name="see-also"></a>Consulte também

[Classe CSyncObject](../../mfc/reference/csyncobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

