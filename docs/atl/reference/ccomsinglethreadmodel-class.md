---
title: Classe CComSingleThreadModel
ms.date: 2/29/2020
f1_keywords:
- CComSingleThreadModel
- ATLBASE/ATL::CComSingleThreadModel
- ATLBASE/ATL::CComSingleThreadModel::AutoCriticalSection
- ATLBASE/ATL::CComSingleThreadModel::CriticalSection
- ATLBASE/ATL::CComSingleThreadModel::ThreadModelNoCS
- ATLBASE/ATL::CComSingleThreadModel::Decrement
- ATLBASE/ATL::CComSingleThreadModel::Increment
helpviewer_keywords:
- single-threaded applications
- CComSingleThreadModel class
- single-threaded applications, ATL
ms.assetid: e5dc30c7-405a-4ba4-8ae9-51937243fce8
ms.openlocfilehash: 9b111e06ba475a5077ba36b2235e8bd530302189
ms.sourcegitcommit: ab8d7b47b63b62892a1256a09b1324a9a136eccf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/02/2020
ms.locfileid: "78215456"
---
# <a name="ccomsinglethreadmodel-class"></a>Classe CComSingleThreadModel

Essa classe fornece métodos para incrementar e decrementar o valor de uma variável.

## <a name="syntax"></a>Sintaxe

```
class CComSingleThreadModel
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CComSingleThreadModel::AutoCriticalSection](#autocriticalsection)|Faz referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).|
|[CComSingleThreadModel:: CriticalSection](#criticalsection)|Faz referência à classe `CComFakeCriticalSection`.|
|[CComSingleThreadModel::ThreadModelNoCS](#threadmodelnocs)|Faz referência a `CComSingleThreadModel`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CComSingleThreadModel::D ecrement](#decrement)|Decrementa o valor da variável especificada. Essa implementação não é thread-safe.|
|[CComSingleThreadModel:: incremento](#increment)|Incrementa o valor da variável especificada. Essa implementação não é thread-safe.|

## <a name="remarks"></a>Comentários

`CComSingleThreadModel` fornece métodos para incrementar e decrementar o valor de uma variável. Ao contrário de [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md), esses métodos não são thread-safe.

Normalmente, você usa o `CComSingleThreadModel` por meio de um dos dois nomes de **typedef** , [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) ou [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel). A classe referenciada por cada **typedef** depende do modelo de Threading usado, conforme mostrado na tabela a seguir:

|typedef|Modelo de Threading único|Modelo de Threading Apartment|Modelo de Threading gratuito|
|-------------|----------------------------|-------------------------------|--------------------------|
|`CComObjectThreadModel`|S|S|M|
|`CComGlobalsThreadModel`|S|M|M|

S = `CComSingleThreadModel`; M = `CComMultiThreadModel`

`CComSingleThreadModel` ele mesmo define três nomes de **typedef** . `ThreadModelNoCS` faz referência a `CComSingleThreadModel`. `AutoCriticalSection` e `CriticalSection` classe de referência [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md), que fornece métodos vazios associados à obtenção e à liberação de propriedade de uma seção crítica.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="autocriticalsection"></a>CComSingleThreadModel::AutoCriticalSection

Ao usar `CComSingleThreadModel`, o nome do **typedef** `AutoCriticalSection` faz referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).

```
typedef CComFakeCriticalSection AutoCriticalSection;
```

### <a name="remarks"></a>Comentários

Como `CComFakeCriticalSection` não fornece uma seção crítica, seus métodos não fazem nada.

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm definições para `AutoCriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `AutoCriticalSection`:

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|
|`CComMultiThreadModel`|`CComAutoCriticalSection`|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|

Além de `AutoCriticalSection`, você pode usar o nome de typedef [CriticalSection](#criticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização do CRT.

### <a name="example"></a>Exemplo

Consulte [CComMultiThreadModel:: AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

##  <a name="criticalsection"></a>CComSingleThreadModel:: CriticalSection

Ao usar `CComSingleThreadModel`, o nome do **typedef** `CriticalSection` faz referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).

```
typedef CComFakeCriticalSection CriticalSection;
```

### <a name="remarks"></a>Comentários

Como `CComFakeCriticalSection` não fornece uma seção crítica, seus métodos não fazem nada.

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm definições para `CriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `CriticalSection`:

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|
|`CComMultiThreadModel`|`CComCriticalSection`|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|

Além de `CriticalSection`, você pode usar o nome de typedef [AutoCriticalSection](#autocriticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização do CRT.

### <a name="example"></a>Exemplo

Consulte [CComMultiThreadModel:: AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

##  <a name="decrement"></a>CComSingleThreadModel::D ecrement

Essa função estática Decrementa o valor da variável apontada por *p*.

```
static ULONG WINAPI Decrement(LPLONG p) throw();
```

### <a name="parameters"></a>parâmetros

*p*<br/>
no Ponteiro para a variável a ser decrementada.

### <a name="return-value"></a>Valor retornado

O resultado do decréscimo.

##  <a name="increment"></a>CComSingleThreadModel:: incremento

Essa função estática incrementa o valor da variável apontada por *p*.

```
static ULONG WINAPI Increment(LPLONG p) throw();
```

### <a name="parameters"></a>parâmetros

*p*<br/>
no Ponteiro para a variável a ser incrementada.

### <a name="return-value"></a>Valor retornado

O resultado do incremento.

##  <a name="threadmodelnocs"></a>CComSingleThreadModel::ThreadModelNoCS

Ao usar `CComSingleThreadModel`, o nome do **typedef** `ThreadModelNoCS` simplesmente faz referência a `CComSingleThreadModel`.

```
typedef CComSingleThreadModel ThreadModelNoCS;
```

### <a name="remarks"></a>Comentários

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm definições para `ThreadModelNoCS`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe referenciada por `ThreadModelNoCS`:

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComSingleThreadModel`|`CComSingleThreadModel`|
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|

### <a name="example"></a>Exemplo

Consulte [CComMultiThreadModel:: AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
