---
title: Classe CComCriticalSection
ms.date: 11/04/2016
f1_keywords:
- CComCriticalSection
- ATLCORE/ATL::CComCriticalSection
- ATLCORE/ATL::CComCriticalSection::CComCriticalSection
- ATLCORE/ATL::CComCriticalSection::Init
- ATLCORE/ATL::CComCriticalSection::Lock
- ATLCORE/ATL::CComCriticalSection::Term
- ATLCORE/ATL::CComCriticalSection::Unlock
- ATLCORE/ATL::CComCriticalSection::m_sec
helpviewer_keywords:
- CComCriticalSection class
ms.assetid: 44e1edd2-90be-4bfe-9739-58e8b419e7d1
ms.openlocfilehash: ee4ce32ed4ae04bc3b390af5cf104b8a0af599f8
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497274"
---
# <a name="ccomcriticalsection-class"></a>Classe CComCriticalSection

Essa classe fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComCriticalSection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCriticalSection::CComCriticalSection](#ccomcriticalsection)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCriticalSection::Init](#init)|Cria e inicializa um objeto de seção crítica.|
|[CComCriticalSection::Lock](#lock)|Obtém a propriedade do objeto da seção crítica.|
|[CComCriticalSection::Term](#term)|Libera os recursos do sistema usados pelo objeto da seção crítica.|
|[CComCriticalSection::Unlock](#unlock)|Libera a propriedade do objeto da seção crítica.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCriticalSection::m_sec](#m_sec)|Um objeto CRITICAL_SECTION.|

## <a name="remarks"></a>Comentários

`CComCriticalSection`é semelhante à classe [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md), exceto que você deve inicializar e liberar explicitamente a seção crítica.

Normalmente, você usa `CComCriticalSection` o nome de typedef [CriticalSection](ccommultithreadmodel-class.md#criticalsection). Esse nome faz `CComCriticalSection` referência quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) está sendo usado.

Consulte a [Classe CComCritSecLock](../../atl/reference/ccomcritseclock-class.md) para obter uma maneira mais segura de usar essa classe `Lock` do `Unlock` que chamar e diretamente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore. h

##  <a name="ccomcriticalsection"></a>  CComCriticalSection::CComCriticalSection

O construtor.

```
CComCriticalSection() throw();
```

### <a name="remarks"></a>Comentários

Define o membro de dados [m_sec](#m_sec) como nulo.

##  <a name="init"></a>CComCriticalSection:: init

Chama a função [InitializeCriticalSection](/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection)do Win32, que inicializa o objeto de seção crítica contido no membro de dados [m_sec](#m_sec) .

```
HRESULT Init() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de sucesso, E_OUTOFMEMORY ou E_FAIL em caso de falha.

##  <a name="lock"></a>CComCriticalSection:: Lock

Chama a função [EnterCriticalSection](/windows/win32/api/synchapi/nf-synchapi-entercriticalsection)do Win32, que aguarda até que o thread possa assumir a propriedade do objeto de seção crítica contido no membro de dados [m_sec](#m_sec) .

```
HRESULT Lock() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK em caso de sucesso, E_OUTOFMEMORY ou E_FAIL em caso de falha.

### <a name="remarks"></a>Comentários

O objeto de seção crítica deve primeiro ser inicializado com uma chamada para o método [init](#init) . Quando o código protegido terminar a execução, o thread deverá chamar [Unlock](#unlock) para liberar a propriedade da seção crítica.

##  <a name="m_sec"></a>  CComCriticalSection::m_sec

Contém um objeto de seção crítica que é usado por `CComCriticalSection` todos os métodos.

```
CRITICAL_SECTION m_sec;
```

##  <a name="term"></a>CComCriticalSection:: termo

Chama a função [DeleteCriticalSection](/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection)do Win32, que libera todos os recursos usados pelo objeto de seção crítica contido no membro de dados [m_sec](#m_sec) .

```
HRESULT Term() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Uma `Term` vez foi chamado, a seção crítica não pode mais ser usada para sincronização.

##  <a name="unlock"></a>  CComCriticalSection::Unlock

Chama a função [LeaveCriticalSection](/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection)do Win32, que libera a propriedade do objeto de seção crítica contido no membro de dados [m_sec](#m_sec) .

```
HRESULT Unlock() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para obter a propriedade pela primeira vez, o thread deve chamar o método [Lock](#lock) . Cada chamada para `Lock` requer uma chamada correspondente para `Unlock` para liberar a propriedade da seção crítica.

## <a name="see-also"></a>Consulte também

[Classe CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComCritSecLock](../../atl/reference/ccomcritseclock-class.md)
