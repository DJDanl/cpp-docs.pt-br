---
title: Classe CComMultiThreadModelNoCS
ms.date: 11/04/2016
f1_keywords:
- CComMultiThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModelNoCS::AutoCriticalSection
- ATLBASE/ATL::CComMultiThreadModelNoCS::CriticalSection
- ATLBASE/ATL::CComMultiThreadModelNoCS::ThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModelNoCS::Decrement
- ATLBASE/ATL::CComMultiThreadModelNoCS::Increment
helpviewer_keywords:
- ATL, multithreading
- CComMultiThreadModelNoCS class
- threading [ATL]
ms.assetid: 2b3f7a45-fd72-452c-aaf3-ccdaa621c821
ms.openlocfilehash: 01c7f953b6b8916394ee4c2b5b27cf84af52b920
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497083"
---
# <a name="ccommultithreadmodelnocs-class"></a>Classe CComMultiThreadModelNoCS

`CComMultiThreadModelNoCS`fornece métodos com segurança de thread para incrementar e decrementar o valor de uma variável, sem bloqueio de seção crítica ou funcionalidade de desbloqueio.

## <a name="syntax"></a>Sintaxe

```
class CComMultiThreadModelNoCS
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CComMultiThreadModelNoCS::AutoCriticalSection](#autocriticalsection)|Faz referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).|
|[CComMultiThreadModelNoCS::CriticalSection](#criticalsection)|Classe `CComFakeCriticalSection`References.|
|[CComMultiThreadModelNoCS::ThreadModelNoCS](#threadmodelnocs)|Classe `CComMultiThreadModelNoCS`References.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComMultiThreadModelNoCS::Decrement](#decrement)|Auto-estática Decrementa o valor da variável especificada de forma segura para thread.|
|[CComMultiThreadModelNoCS::Increment](#increment)|Auto-estática Incrementa o valor da variável especificada de forma segura para thread.|

## <a name="remarks"></a>Comentários

`CComMultiThreadModelNoCS`é semelhante a [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) , pois fornece métodos thread-safe para incrementar e decrementar uma variável. No entanto, quando você faz referência a uma `CComMultiThreadModelNoCS`classe de seção crítica `Lock` por `Unlock` meio de, métodos como e não farão nada.

Normalmente, você usa `CComMultiThreadModelNoCS` o nome `ThreadModelNoCS` do **typedef** . Esse **typedef** é definido em `CComMultiThreadModelNoCS`, `CComMultiThreadModel`e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md).

> [!NOTE]
>  Os nomes de **typedef** global [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) e [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel) não fazem `CComMultiThreadModelNoCS`referência.

Além `ThreadModelNoCS`de, `CComMultiThreadModelNoCS` define `AutoCriticalSection` e. `CriticalSection` Esses dois últimos nomes de **typedef** fazem referência a [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md), que fornece métodos vazios associados à obtenção e à liberação de uma seção crítica.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="autocriticalsection"></a>  CComMultiThreadModelNoCS::AutoCriticalSection

Ao usar `CComMultiThreadModelNoCS`, o nome `AutoCriticalSection` do typedef faz referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).

```
typedef CComFakeCriticalSection AutoCriticalSection;
```

### <a name="remarks"></a>Comentários

Como `CComFakeCriticalSection` o não fornece uma seção crítica, seus métodos não fazem nada.

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também contêm definições para `AutoCriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção `AutoCriticalSection`crítica referenciada por:

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|
|`CComMultiThreadModel`|`CComAutoCriticalSection`|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|

Além disso `AutoCriticalSection`, você pode usar o nome de **typedef** [CriticalSection](#criticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização do CRT.

### <a name="example"></a>Exemplo

Consulte [CComMultiThreadModel:: AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

##  <a name="criticalsection"></a>  CComMultiThreadModelNoCS::CriticalSection

Ao usar `CComMultiThreadModelNoCS`, o nome `CriticalSection` do typedef faz referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).

```
typedef CComFakeCriticalSection CriticalSection;
```

### <a name="remarks"></a>Comentários

Como `CComFakeCriticalSection` o não fornece uma seção crítica, seus métodos não fazem nada.

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também contêm definições para `CriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção `CriticalSection`crítica referenciada por:

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|
|`CComMultiThreadModel`|`CComCriticalSection`|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|

Além disso `CriticalSection`, você pode usar o nome `AutoCriticalSection`do typedef. Você não deve especificar `AutoCriticalSection` em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização do CRT.

### <a name="example"></a>Exemplo

Consulte [CComMultiThreadModel:: AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

##  <a name="decrement"></a>  CComMultiThreadModelNoCS::Decrement

Essa função estática chama a função [InterlockedDecrement](/windows/win32/api/winnt/nf-winnt-interlockeddecrement)do Win32, que Decrementa o valor da variável apontada por *p*.

```
static ULONG WINAPI Decrement(LPLONG p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
no Ponteiro para a variável a ser decrementada.

### <a name="return-value"></a>Valor de retorno

Se o resultado do decréscimo for 0, `Decrement` retornará 0. Se o resultado do decréscimo for diferente de zero, o valor de retorno também será diferente de zero, mas talvez não seja igual ao resultado do decréscimo.

### <a name="remarks"></a>Comentários

**InterlockedDecrement** impede que mais de um thread use simultaneamente essa variável.

##  <a name="increment"></a>  CComMultiThreadModelNoCS::Increment

Essa função estática chama a função [InterlockedIncrement](/windows/win32/api/winnt/nf-winnt-interlockedincrement)do Win32, que incrementa o valor da variável apontada por *p*.

```
static ULONG WINAPI Increment(LPLONG p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
no Ponteiro para a variável a ser incrementada.

### <a name="return-value"></a>Valor de retorno

Se o resultado do incremento for 0, **incremento** retornará 0. Se o resultado do incremento for diferente de zero, o valor de retorno também será diferente de zero, mas talvez não seja igual ao resultado do incremento.

### <a name="remarks"></a>Comentários

**InterlockedIncrement** impede que mais de um thread use simultaneamente essa variável.

##  <a name="threadmodelnocs"></a>  CComMultiThreadModelNoCS::ThreadModelNoCS

Ao usar `CComMultiThreadModelNoCS`, o nome `ThreadModelNoCS` de typedef simplesmente `CComMultiThreadModelNoCS`faz referência a.

```
typedef CComMultiThreadModelNoCS ThreadModelNoCS;
```

### <a name="remarks"></a>Comentários

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também contêm definições para `ThreadModelNoCS`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe `ThreadModelNoCS`referenciada por:

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|
|`CComSingleThreadModel`|`CComSingleThreadModel`|

Observe que a definição de `ThreadModelNoCS` no `CComMultiThreadModelNoCS` fornece simetria com `CComMultiThreadModel` e `CComSingleThreadModel`. Por exemplo, suponha que o código de `CComMultiThreadModel::AutoCriticalSection` exemplo em declarou o seguinte **typedef**:

[!code-cpp[NVC_ATL_COM#37](../../atl/codesnippet/cpp/ccommultithreadmodelnocs-class_1.h)]

Independentemente da classe especificada para `ThreadModel` ( `CComMultiThreadModelNoCS`como), `_ThreadModel` o resolve de acordo.

### <a name="example"></a>Exemplo

Consulte [CComMultiThreadModel:: AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
