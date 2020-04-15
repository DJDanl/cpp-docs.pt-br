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
ms.openlocfilehash: 3d8169c999ba96049bc711033f7ba2ef53989663
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327330"
---
# <a name="ccomsinglethreadmodel-class"></a>Classe CComSingleThreadModel

Esta classe fornece métodos para incrementar e diminuir o valor de uma variável.

## <a name="syntax"></a>Sintaxe

```
class CComSingleThreadModel
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSingleThreadModel::AutoCriticalSection](#autocriticalsection)|Referências classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).|
|[CComSingleThreadModel::CriticalSection](#criticalsection)|Classe de `CComFakeCriticalSection`referências .|
|[CComSingleThreadModel::ThreadModelNoCS](#threadmodelnocs)|Referências `CComSingleThreadModel`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComSingleThreadModelo::Decrement](#decrement)|Decreta o valor da variável especificada. Esta implementação não é segura para threads.|
|[CComSingleThreadModelo::Incremento](#increment)|Incrementa o valor da variável especificada. Esta implementação não é segura para threads.|

## <a name="remarks"></a>Comentários

`CComSingleThreadModel`fornece métodos para incrementar e diminuir o valor de uma variável. Ao contrário [de CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS,](../../atl/reference/ccommultithreadmodelnocs-class.md)esses métodos não são seguros para threads.

Normalmente, você `CComSingleThreadModel` usa através de um dos dois nomes **typedef,** [cComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) ou [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel). A classe referenciada por cada **typedef** depende do modelo de rosca utilizado, conforme mostrado na tabela a seguir:

|typedef|Modelo de rosca simples|Modelo de rosca do apartamento|Modelo de rosca grátis|
|-------------|----------------------------|-------------------------------|--------------------------|
|`CComObjectThreadModel`|S|S|M|
|`CComGlobalsThreadModel`|S|M|M|

S= `CComSingleThreadModel`; M=`CComMultiThreadModel`

`CComSingleThreadModel`em si define três nomes **typedef.** `ThreadModelNoCS`referências `CComSingleThreadModel`. `AutoCriticalSection`e `CriticalSection` classe de referência [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md), que fornece métodos vazios associados à obtenção e liberação da propriedade de uma seção crítica.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomsinglethreadmodelautocriticalsection"></a><a name="autocriticalsection"></a>CComSingleThreadModel::AutoCriticalSection

Ao `CComSingleThreadModel`usar, o nome `AutoCriticalSection` **typedef** faz referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).

```
typedef CComFakeCriticalSection AutoCriticalSection;
```

### <a name="remarks"></a>Comentários

Porque `CComFakeCriticalSection` não fornece uma seção crítica, seus métodos não fazem nada.

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm definições para `AutoCriticalSection`. A tabela a seguir mostra a relação entre a classe `AutoCriticalSection`do modelo de rosca e a classe de seção crítica referenciada por :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|
|`CComMultiThreadModel`|`CComAutoCriticalSection`|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|

Além disso, `AutoCriticalSection`você pode usar o nome **typedef** [CriticalSection](#criticalsection). Você não `AutoCriticalSection` deve especificar em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização CRT.

### <a name="example"></a>Exemplo

Veja [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

## <a name="ccomsinglethreadmodelcriticalsection"></a><a name="criticalsection"></a>CComSingleThreadModel::CriticalSection

Ao `CComSingleThreadModel`usar, o nome `CriticalSection` **typedef** faz referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).

```
typedef CComFakeCriticalSection CriticalSection;
```

### <a name="remarks"></a>Comentários

Porque `CComFakeCriticalSection` não fornece uma seção crítica, seus métodos não fazem nada.

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm definições para `CriticalSection`. A tabela a seguir mostra a relação entre a classe `CriticalSection`do modelo de rosca e a classe de seção crítica referenciada por :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|
|`CComMultiThreadModel`|`CComCriticalSection`|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|

Além disso, `CriticalSection`você pode usar o nome **typedef** [AutoCriticalSection](#autocriticalsection). Você não `AutoCriticalSection` deve especificar em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização CRT.

### <a name="example"></a>Exemplo

Veja [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

## <a name="ccomsinglethreadmodeldecrement"></a><a name="decrement"></a>CComSingleThreadModelo::Decrement

Esta função estática diminui o valor da variável apontada para *p*.

```
static ULONG WINAPI Decrement(LPLONG p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Ponteiro para a variável a ser decretada.

### <a name="return-value"></a>Valor retornado

O resultado do decrésia.

## <a name="ccomsinglethreadmodelincrement"></a><a name="increment"></a>CComSingleThreadModelo::Incremento

Esta função estática aumenta o valor da variável apontada para *p*.

```
static ULONG WINAPI Increment(LPLONG p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Ponteiro para a variável a ser incrementada.

### <a name="return-value"></a>Valor retornado

O resultado do incremento.

## <a name="ccomsinglethreadmodelthreadmodelnocs"></a><a name="threadmodelnocs"></a>CComSingleThreadModel::ThreadModelNoCS

Ao `CComSingleThreadModel`usar , o `ThreadModelNoCS` nome `CComSingleThreadModel` **typedef** simplesmente faz referência .

```
typedef CComSingleThreadModel ThreadModelNoCS;
```

### <a name="remarks"></a>Comentários

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md) contêm definições para `ThreadModelNoCS`. A tabela a seguir mostra a relação entre a `ThreadModelNoCS`classe do modelo de rosca e a classe referenciada por :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComSingleThreadModel`|`CComSingleThreadModel`|
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|

### <a name="example"></a>Exemplo

Veja [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
