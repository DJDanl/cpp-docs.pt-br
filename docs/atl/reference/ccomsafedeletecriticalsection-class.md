---
title: Classe CComSafeDeleteCriticalSection | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComSafeDeleteCriticalSection
- ATLCORE/ATL::CComSafeDeleteCriticalSection
- ATLCORE/ATL::CComSafeDeleteCriticalSection::CComSafeDeleteCriticalSection
- ATLCORE/ATL::CComSafeDeleteCriticalSection::Init
- ATLCORE/ATL::CComSafeDeleteCriticalSection::Lock
- ATLCORE/ATL::CComSafeDeleteCriticalSection::Term
- ATLCORE/ATL::m_bInitialized
dev_langs:
- C++
helpviewer_keywords:
- CComSafeDeleteCriticalSection class
ms.assetid: 4d2932c4-ba8f-48ec-8664-1db8bed01314
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 939340a60d9448c6fac5f97c606a27182a2bb88b
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50068431"
---
# <a name="ccomsafedeletecriticalsection-class"></a>Classe CComSafeDeleteCriticalSection

Essa classe fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComSafeDeleteCriticalSection : public CComCriticalSection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeDeleteCriticalSection::CComSafeDeleteCriticalSection](#ccomsafedeletecriticalsection)|O construtor.|
|[CComSafeDeleteCriticalSection:: ~ CComSafeDeleteCriticalSection](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSafeDeleteCriticalSection::Init](#init)|Cria e inicializa um objeto de seção crítica.|
|[CComSafeDeleteCriticalSection::Lock](#lock)|Obtém a propriedade do objeto de seção crítica.|
|[CComSafeDeleteCriticalSection::Term](#term)|Libera os recursos do sistema usados pelo objeto de seção crítica.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_bInitialized](#m_binitialized)|Sinalizadores se interno `CRITICAL_SECTION` objeto foi inicializado.|

## <a name="remarks"></a>Comentários

`CComSafeDeleteCriticalSection` deriva da classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md). No entanto, `CComSafeDeleteCriticalSection` fornece mecanismos de segurança adicionais sobre [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md).

Quando uma instância do `CComSafeDeleteCriticalSection` sai do escopo ou é explicitamente excluído da memória, o objeto subjacente de seção crítica será automaticamente limpo se ela ainda é válida. Além disso, o [CComSafeDeleteCriticalSection::Term](#term) método sairá normalmente se o objeto de seção crítica subjacente ainda não foi alocado ou já foi liberado da memória.

Ver [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) para obter mais informações sobre classes de auxiliar de seção crítica.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)

`CComSafeDeleteCriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

##  <a name="ccomsafedeletecriticalsection"></a>  CComSafeDeleteCriticalSection::CComSafeDeleteCriticalSection

O construtor.

```
CComSafeDeleteCriticalSection();
```

### <a name="remarks"></a>Comentários

Define o [m_bInitialized](#m_binitialized) membro de dados como FALSE.

##  <a name="dtor"></a>  CComSafeDeleteCriticalSection:: ~ CComSafeDeleteCriticalSection

O destruidor.

```
~CComSafeDeleteCriticalSection() throw();
```

### <a name="remarks"></a>Comentários

Libera o internal `CRITICAL_SECTION` do objeto da memória se o [m_bInitialized](#m_binitialized) membro de dados está definido como TRUE.

##  <a name="init"></a>  CComSafeDeleteCriticalSection::Init

Chama a implementação da classe base [Init](/visualstudio/debugger/init) e define [m_bInitialized](#m_binitialized) como TRUE se for bem-sucedido.

```
HRESULT Init() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o resultado da [CComCriticalSection::Init](../../atl/reference/ccomcriticalsection-class.md#init).

##  <a name="lock"></a>  CComSafeDeleteCriticalSection::Lock

Chama a implementação da classe base [bloqueio](ccomcriticalsection-class.md#lock).

```
HRESULT Lock();
```

### <a name="return-value"></a>Valor de retorno

Retorna o resultado da [CComCriticalSection::Lock](../../atl/reference/ccomcriticalsection-class.md#lock).

### <a name="remarks"></a>Comentários

Este método assume a [m_bInitialized](#m_binitialized) membro de dados está definido como TRUE na entrada. Uma declaração é gerada em compilações de depuração se este condidtion não for atendida.

Para obter mais informações sobre o comportamento da função, consulte [CComCriticalSection::Lock](../../atl/reference/ccomcriticalsection-class.md#lock).

##  <a name="m_binitialized"></a>  CComSafeDeleteCriticalSection::m_bInitialized

Sinalizadores se interno `CRITICAL_SECTION` objeto foi inicializado.

```
bool m_bInitialized;
```

### <a name="remarks"></a>Comentários

O `m_bInitialized` membro de dados é usado para controlar a validade de subjacente `CRITICAL_SECTION` objeto associado a [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md) classe. Subjacente `CRITICAL_SECTION` objeto não será tentado seja liberado da memória se este sinalizador não for definido como TRUE.

##  <a name="term"></a>  CComSafeDeleteCriticalSection::Term

Chama a implementação da classe base [CComCriticalSection::Term](../../atl/reference/ccomcriticalsection-class.md#term) se o interno `CRITICAL_SECTION` objeto é válido.

```
HRESULT Term() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o resultado da [CComCriticalSection::Term](../../atl/reference/ccomcriticalsection-class.md#term), ou S_OK se [m_bInitialized](#m_binitialized) foi definida como FALSE na entrada.

### <a name="remarks"></a>Comentários

É seguro chamar esse mesmo método interno `CRITICAL_SECTION` objeto não é válido. O destruidor dessa classe chama esse método se a [m_bInitialized](#m_binitialized) membro de dados está definido como TRUE.

## <a name="see-also"></a>Consulte também

[Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
