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
ms.openlocfilehash: f3991d217fbc201bd428ed2522a5c4c25e074928
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327961"
---
# <a name="ccomcriticalsection-class"></a>Classe CComCriticalSection

Esta classe fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComCriticalSection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCriticalSection::CComCriticalsection](#ccomcriticalsection)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCriticalSection::Init](#init)|Cria e inicializa um objeto de seção crítica.|
|[CComCriticalSection::bloqueio](#lock)|Obtém a propriedade do objeto da seção crítica.|
|[CComCriticalSection::Term](#term)|Libera os recursos do sistema usados pelo objeto da seção crítica.|
|[CComCriticalSection::Unlock](#unlock)|Libera a propriedade do objeto da seção crítica.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCriticalSection::m_sec](#m_sec)|Um objeto CRITICAL_SECTION.|

## <a name="remarks"></a>Comentários

`CComCriticalSection`é semelhante à classe [CComAutoCriticalSection,](../../atl/reference/ccomautocriticalsection-class.md)exceto que você deve inicializar e liberar explicitamente a seção crítica.

Normalmente, você `CComCriticalSection` usa através do nome **typedef** [CriticalSection](ccommultithreadmodel-class.md#criticalsection). Este nome `CComCriticalSection` faz referência quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) está sendo usado.

Consulte [CComCritSecLock Class](../../atl/reference/ccomcritseclock-class.md) para obter uma maneira `Lock` `Unlock` mais segura de usar esta classe do que ligar e diretamente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

## <a name="ccomcriticalsectionccomcriticalsection"></a><a name="ccomcriticalsection"></a>CComCriticalSection::CComCriticalsection

O construtor.

```
CComCriticalSection() throw();
```

### <a name="remarks"></a>Comentários

Define o membro de dados [m_sec](#m_sec) como NULL.

## <a name="ccomcriticalsectioninit"></a><a name="init"></a>CComCriticalSection::Init

Chama a função Win32 [InitializeCriticalSection](/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection), que inicializa o objeto de seção crítica contido no membro de dados [m_sec.](#m_sec)

```
HRESULT Init() throw();
```

### <a name="return-value"></a>Valor retornado

O retorno S_OK no sucesso, E_OUTOFMEMORY ou E_FAIL no fracasso.

## <a name="ccomcriticalsectionlock"></a><a name="lock"></a>CComCriticalSection::bloqueio

Chama a função Win32 [EnterCriticalSection](/windows/win32/api/synchapi/nf-synchapi-entercriticalsection), que aguarda até que o segmento possa assumir a propriedade do objeto de seção crítica contido no membro de dados [m_sec.](#m_sec)

```
HRESULT Lock() throw();
```

### <a name="return-value"></a>Valor retornado

O retorno S_OK no sucesso, E_OUTOFMEMORY ou E_FAIL no fracasso.

### <a name="remarks"></a>Comentários

O objeto de seção crítica deve primeiro ser inicializado com uma chamada para o método [Init.](#init) Quando o código protegido tiver concluído a execução, o segmento deve chamar [Desbloquear](#unlock) para liberar a propriedade da seção crítica.

## <a name="ccomcriticalsectionm_sec"></a><a name="m_sec"></a>CComCriticalSection::m_sec

Contém um objeto de seção `CComCriticalSection` crítico que é usado por todos os métodos.

```
CRITICAL_SECTION m_sec;
```

## <a name="ccomcriticalsectionterm"></a><a name="term"></a>CComCriticalSection::Term

Chama a função Win32 [DeleteCriticalSection](/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection), que libera todos os recursos usados pelo objeto de seção crítica contido no membro de dados [m_sec.](#m_sec)

```
HRESULT Term() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Uma `Term` vez chamada, a seção crítica não pode mais ser usada para sincronização.

## <a name="ccomcriticalsectionunlock"></a><a name="unlock"></a>CComCriticalSection::Unlock

Chama a função Win32 [LeaveCriticalSection](/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection), que libera a propriedade do objeto de seção crítica contido no membro de dados [m_sec.](#m_sec)

```
HRESULT Unlock() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Para obter a propriedade, o segmento deve chamar o método [De bloqueio.](#lock) Cada chamada `Lock` requer uma `Unlock` chamada correspondente para liberar a propriedade da seção crítica.

## <a name="see-also"></a>Confira também

[Classe CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComCritSecLock](../../atl/reference/ccomcritseclock-class.md)
