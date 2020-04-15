---
title: CComSafeDeleteCriticalSection Class
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
ms.openlocfilehash: cb0dc440fc0e79e0023b5fbd6e4ca2345d031d3d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327366"
---
# <a name="ccomsafedeletecriticalsection-class"></a>CComSafeDeleteCriticalSection Class

Esta classe fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComSafeDeleteCriticalSection : public CComCriticalSection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeDeleteCriticalSection::CComSafeDeleteCriticalsection](#ccomsafedeletecriticalsection)|O construtor.|
|[CComSafeDeleteCriticalSection::~CComSafeDeleteCriticalsection](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeDeleteCriticalSection::Init](#init)|Cria e inicializa um objeto de seção crítica.|
|[CComSafeDeleteCriticalsection::Lock](#lock)|Obtém a propriedade do objeto da seção crítica.|
|[CComSafeDeleteCriticalsection::Term](#term)|Libera os recursos do sistema usados pelo objeto da seção crítica.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[m_bInitialized](#m_binitialized)|Sinaliza se `CRITICAL_SECTION` o objeto interno foi inicializado.|

## <a name="remarks"></a>Comentários

`CComSafeDeleteCriticalSection`deriva da classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md). No `CComSafeDeleteCriticalSection` entanto, fornece mecanismos adicionais de segurança sobre [cComCriticalSection](../../atl/reference/ccomcriticalsection-class.md).

Quando uma `CComSafeDeleteCriticalSection` instância de sair do escopo ou for explicitamente excluída da memória, o objeto da seção crítica subjacente será automaticamente limpo se ainda for válido. Além disso, o método [CComSafeDeleteCriticalSection::Term](#term) sairá graciosamente se o objeto da seção crítica subjacente ainda não tiver sido alocado ou já tiver sido liberado da memória.

Consulte [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) para obter mais informações sobre classes de ajudantes de seção críticas.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Ccomcriticalsection](../../atl/reference/ccomcriticalsection-class.md)

`CComSafeDeleteCriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

## <a name="ccomsafedeletecriticalsectionccomsafedeletecriticalsection"></a><a name="ccomsafedeletecriticalsection"></a>CComSafeDeleteCriticalSection::CComSafeDeleteCriticalsection

O construtor.

```
CComSafeDeleteCriticalSection();
```

### <a name="remarks"></a>Comentários

Define o membro de dados [m_bInitialized](#m_binitialized) como FALSO.

## <a name="ccomsafedeletecriticalsectionccomsafedeletecriticalsection"></a><a name="dtor"></a>CComSafeDeleteCriticalSection::~CComSafeDeleteCriticalsection

O destruidor.

```
~CComSafeDeleteCriticalSection() throw();
```

### <a name="remarks"></a>Comentários

Libera o `CRITICAL_SECTION` objeto interno da memória se o [membro de](#m_binitialized) dados m_bInitialized estiver definido como TRUE.

## <a name="ccomsafedeletecriticalsectioninit"></a><a name="init"></a>CComSafeDeleteCriticalSection::Init

Chama a implementação da classe base do [Init](/visualstudio/debugger/init) e define [m_bInitialized](#m_binitialized) para TRUE se for bem-sucedido.

```
HRESULT Init() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o resultado de [CComCriticalSection::Init](../../atl/reference/ccomcriticalsection-class.md#init).

## <a name="ccomsafedeletecriticalsectionlock"></a><a name="lock"></a>CComSafeDeleteCriticalsection::Lock

Chama a implementação da classe base do [Lock](ccomcriticalsection-class.md#lock).

```
HRESULT Lock();
```

### <a name="return-value"></a>Valor retornado

Retorna o resultado de [CComCriticalSection::Lock](../../atl/reference/ccomcriticalsection-class.md#lock).

### <a name="remarks"></a>Comentários

Este método pressupõe que [o membro de](#m_binitialized) dados m_bInitialized esteja definido como TRUE no momento da entrada. Uma afirmação é gerada em compilações Debug se essa condição não for atendida.

Para obter mais informações sobre o comportamento da função, consulte [CComCriticalSection:::Lock](../../atl/reference/ccomcriticalsection-class.md#lock).

## <a name="ccomsafedeletecriticalsectionm_binitialized"></a><a name="m_binitialized"></a>CComSafeDeleteCriticalSection::m_bInitialized

Sinaliza se `CRITICAL_SECTION` o objeto interno foi inicializado.

```
bool m_bInitialized;
```

### <a name="remarks"></a>Comentários

O `m_bInitialized` membro de dados é usado para `CRITICAL_SECTION` rastrear a validade do objeto subjacente associado à classe [CComSafeDeleteCriticalSection.](../../atl/reference/ccomsafedeletecriticalsection-class.md) O objeto `CRITICAL_SECTION` subjacente não será liberado da memória se este sinalizador não estiver definido como TRUE.

## <a name="ccomsafedeletecriticalsectionterm"></a><a name="term"></a>CComSafeDeleteCriticalsection::Term

Chama a implementação da classe base de [CComCriticalSection::Term](../../atl/reference/ccomcriticalsection-class.md#term) se o objeto interno `CRITICAL_SECTION` for válido.

```
HRESULT Term() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o resultado de [CComCriticalSection::Term](../../atl/reference/ccomcriticalsection-class.md#term)ou S_OK se [m_bInitialized](#m_binitialized) foi definido como FALSO após a entrada.

### <a name="remarks"></a>Comentários

É seguro chamar esse método mesmo `CRITICAL_SECTION` que o objeto interno não seja válido. O destruidor desta classe chama esse método se o [membro de](#m_binitialized) dados m_bInitialized estiver definido como TRUE.

## <a name="see-also"></a>Confira também

[Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
