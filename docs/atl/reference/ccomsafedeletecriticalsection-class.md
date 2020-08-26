---
title: Classe CComSafeDeleteCriticalSection
ms.date: 11/04/2016
f1_keywords:
- CComSafeDeleteCriticalSection
- ATLCORE/ATL::CComSafeDeleteCriticalSection
- ATLCORE/ATL::CComSafeDeleteCriticalSection::CComSafeDeleteCriticalSection
- ATLCORE/ATL::CComSafeDeleteCriticalSection::Init
- ATLCORE/ATL::CComSafeDeleteCriticalSection::Lock
- ATLCORE/ATL::CComSafeDeleteCriticalSection::Term
- ATLCORE/ATL::m_bInitialized
helpviewer_keywords:
- CComSafeDeleteCriticalSection class
ms.assetid: 4d2932c4-ba8f-48ec-8664-1db8bed01314
ms.openlocfilehash: 115cbd466f51db271f4be65ce708fe54c7f2b2ce
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833628"
---
# <a name="ccomsafedeletecriticalsection-class"></a>Classe CComSafeDeleteCriticalSection

Essa classe fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComSafeDeleteCriticalSection : public CComCriticalSection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeDeleteCriticalSection::CComSafeDeleteCriticalSection](#ccomsafedeletecriticalsection)|O construtor.|
|[CComSafeDeleteCriticalSection:: ~ CComSafeDeleteCriticalSection](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeDeleteCriticalSection:: init](#init)|Cria e inicializa um objeto de seção crítica.|
|[CComSafeDeleteCriticalSection:: Lock](#lock)|Obtém a propriedade do objeto da seção crítica.|
|[CComSafeDeleteCriticalSection:: termo](#term)|Libera os recursos do sistema usados pelo objeto da seção crítica.|

### <a name="data-members"></a>Membros de dados

|Membro de dados|Descrição|
|-|-|
|[m_bInitialized](#m_binitialized)|Sinaliza se o objeto interno foi `CRITICAL_SECTION` inicializado.|

## <a name="remarks"></a>Comentários

`CComSafeDeleteCriticalSection` deriva da classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md). No entanto, o `CComSafeDeleteCriticalSection` fornece mecanismos de segurança adicionais em [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md).

Quando uma instância de `CComSafeDeleteCriticalSection` sai do escopo ou é explicitamente excluída da memória, o objeto de seção crítica subjacente será limpo automaticamente se ainda for válido. Além disso, o método [CComSafeDeleteCriticalSection:: Term](#term) sairá normalmente se o objeto de seção crítica subjacente ainda não tiver sido alocado ou já tiver sido liberado da memória.

Consulte [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) para obter mais informações sobre classes auxiliares de seção críticas.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)

`CComSafeDeleteCriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore. h

## <a name="ccomsafedeletecriticalsectionccomsafedeletecriticalsection"></a><a name="ccomsafedeletecriticalsection"></a> CComSafeDeleteCriticalSection::CComSafeDeleteCriticalSection

O construtor.

```
CComSafeDeleteCriticalSection();
```

### <a name="remarks"></a>Comentários

Define o membro de dados [m_bInitialized](#m_binitialized) como false.

## <a name="ccomsafedeletecriticalsectionccomsafedeletecriticalsection"></a><a name="dtor"></a> CComSafeDeleteCriticalSection:: ~ CComSafeDeleteCriticalSection

O destruidor.

```
~CComSafeDeleteCriticalSection() throw();
```

### <a name="remarks"></a>Comentários

Libera o `CRITICAL_SECTION` objeto interno da memória se o membro de dados [m_bInitialized](#m_binitialized) for definido como true.

## <a name="ccomsafedeletecriticalsectioninit"></a><a name="init"></a> CComSafeDeleteCriticalSection:: init

Chama a implementação da classe base de [init](/visualstudio/debugger/init) e define [m_bInitialized](#m_binitialized) como true se for bem-sucedida.

```
HRESULT Init() throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o resultado de [CComCriticalSection:: init](../../atl/reference/ccomcriticalsection-class.md#init).

## <a name="ccomsafedeletecriticalsectionlock"></a><a name="lock"></a> CComSafeDeleteCriticalSection:: Lock

Chama a implementação da classe base do [bloqueio](ccomcriticalsection-class.md#lock).

```
HRESULT Lock();
```

### <a name="return-value"></a>Valor Retornado

Retorna o resultado de [CComCriticalSection:: Lock](../../atl/reference/ccomcriticalsection-class.md#lock).

### <a name="remarks"></a>Comentários

Esse método assume que o membro de dados [m_bInitialized](#m_binitialized) é definido como true na entrada. Uma asserção será gerada em compilações de depuração se essa condição não for atendida.

Para obter mais informações sobre o comportamento da função, consulte [CComCriticalSection:: Lock](../../atl/reference/ccomcriticalsection-class.md#lock).

## <a name="ccomsafedeletecriticalsectionm_binitialized"></a><a name="m_binitialized"></a> CComSafeDeleteCriticalSection:: m_bInitialized

Sinaliza se o objeto interno foi `CRITICAL_SECTION` inicializado.

```
bool m_bInitialized;
```

### <a name="remarks"></a>Comentários

O `m_bInitialized` membro de dados é usado para acompanhar a validade do `CRITICAL_SECTION` objeto subjacente associado à classe [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md) . O `CRITICAL_SECTION` objeto subjacente não será tentado para ser liberado da memória se esse sinalizador não estiver definido como true.

## <a name="ccomsafedeletecriticalsectionterm"></a><a name="term"></a> CComSafeDeleteCriticalSection:: termo

Chama a implementação da classe base de [CComCriticalSection:: Term](../../atl/reference/ccomcriticalsection-class.md#term) se o `CRITICAL_SECTION` objeto interno for válido.

```
HRESULT Term() throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o resultado de [CComCriticalSection:: Term](../../atl/reference/ccomcriticalsection-class.md#term)ou S_OK se [m_bInitialized](#m_binitialized) foi definido como false na entrada.

### <a name="remarks"></a>Comentários

É seguro chamar esse método, mesmo se o objeto interno `CRITICAL_SECTION` não for válido. O destruidor dessa classe chama esse método se o membro de dados [m_bInitialized](#m_binitialized) for definido como true.

## <a name="see-also"></a>Confira também

[Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
