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
ms.openlocfilehash: 4d41ffcfccbd7ef65ed86df79bffec1209a88cd3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327659"
---
# <a name="ccommultithreadmodelnocs-class"></a>Classe CComMultiThreadModelNoCS

`CComMultiThreadModelNoCS`fornece métodos seguros para incrementar e diminuir o valor de uma variável, sem a funcionalidade de bloqueio ou desbloqueio de seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComMultiThreadModelNoCS
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CComMultithreadmodelnocs::AutocriticalSection](#autocriticalsection)|Referências classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).|
|[CComMultiThreadModelnoCs::CriticalSection](#criticalsection)|Classe de `CComFakeCriticalSection`referências .|
|[CcomMultithreadmodelnocs::threadmodelnocs](#threadmodelnocs)|Classe de `CComMultiThreadModelNoCS`referências .|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComMultiThreadModelNoCS::Decrement](#decrement)|(Estática) Decreta o valor da variável especificada de forma segura para o segmento.|
|[CcomMultithreadmodelnocs:incremento](#increment)|(Estática) Incrementa o valor da variável especificada de forma segura para o segmento.|

## <a name="remarks"></a>Comentários

`CComMultiThreadModelNoCS`é semelhante ao [CComMultiThreadModel,](../../atl/reference/ccommultithreadmodel-class.md) na pois fornece métodos seguros para incrementar e diminuir uma variável. No entanto, quando você `CComMultiThreadModelNoCS`faz referência a `Lock` `Unlock` uma classe de seção crítica através de métodos como e não fará nada.

Normalmente, você `CComMultiThreadModelNoCS` usa `ThreadModelNoCS` através do nome **typedef.** Este **typedef** é `CComMultiThreadModelNoCS` `CComMultiThreadModel`definido em , e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md).

> [!NOTE]
> Os **nomes** globais [ccomObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) e [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel) não fazem referência `CComMultiThreadModelNoCS`.

Além `ThreadModelNoCS`de, `CComMultiThreadModelNoCS` define `AutoCriticalSection` `CriticalSection`e . Estes dois últimos nomes **typedef** fazem referência [ao CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md), que fornece métodos vazios associados à obtenção e liberação de uma seção crítica.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccommultithreadmodelnocsautocriticalsection"></a><a name="autocriticalsection"></a>CComMultithreadmodelnocs::AutocriticalSection

Ao `CComMultiThreadModelNoCS`usar, o nome `AutoCriticalSection` **typedef** faz referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).

```
typedef CComFakeCriticalSection AutoCriticalSection;
```

### <a name="remarks"></a>Comentários

Porque `CComFakeCriticalSection` não fornece uma seção crítica, seus métodos não fazem nada.

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também `AutoCriticalSection`contêm definições para . A tabela a seguir mostra a relação entre a classe `AutoCriticalSection`do modelo de rosca e a classe de seção crítica referenciada por :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|
|`CComMultiThreadModel`|`CComAutoCriticalSection`|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|

Além disso, `AutoCriticalSection`você pode usar o nome **typedef** [CriticalSection](#criticalsection). Você não `AutoCriticalSection` deve especificar em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização CRT.

### <a name="example"></a>Exemplo

Veja [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

## <a name="ccommultithreadmodelnocscriticalsection"></a><a name="criticalsection"></a>CComMultiThreadModelnoCs::CriticalSection

Ao `CComMultiThreadModelNoCS`usar, o nome `CriticalSection` **typedef** faz referência à classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).

```
typedef CComFakeCriticalSection CriticalSection;
```

### <a name="remarks"></a>Comentários

Porque `CComFakeCriticalSection` não fornece uma seção crítica, seus métodos não fazem nada.

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também `CriticalSection`contêm definições para . A tabela a seguir mostra a relação entre a classe `CriticalSection`do modelo de rosca e a classe de seção crítica referenciada por :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|
|`CComMultiThreadModel`|`CComCriticalSection`|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|

Além disso, `CriticalSection`você pode usar o `AutoCriticalSection`nome **typedef** . Você não `AutoCriticalSection` deve especificar em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização CRT.

### <a name="example"></a>Exemplo

Veja [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

## <a name="ccommultithreadmodelnocsdecrement"></a><a name="decrement"></a>CComMultiThreadModelNoCS::Decrement

Esta função estática chama a função Win32 [InterlockedDecrement](/windows/win32/api/winnt/nf-winnt-interlockeddecrement), que diminui o valor da variável apontada para *p*.

```
static ULONG WINAPI Decrement(LPLONG p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Ponteiro para a variável a ser decretada.

### <a name="return-value"></a>Valor retornado

Se o resultado do decremento `Decrement` for 0, então retorna 0. Se o resultado do decremento não for zero, o valor de retorno também não é zero, mas pode não ser igual ao resultado do decremento.

### <a name="remarks"></a>Comentários

**InterlockedDecrement** impede que mais de um segmento use simultaneamente esta variável.

## <a name="ccommultithreadmodelnocsincrement"></a><a name="increment"></a>CcomMultithreadmodelnocs:incremento

Esta função estática chama a função Win32 [InterlockedIncrement](/windows/win32/api/winnt/nf-winnt-interlockedincrement), que incrementa o valor da variável apontada para *p*.

```
static ULONG WINAPI Increment(LPLONG p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Ponteiro para a variável a ser incrementada.

### <a name="return-value"></a>Valor retornado

Se o resultado do incremento for 0, então **Incremento** retorna 0. Se o resultado do incremento não for zero, o valor de retorno também não é zero, mas pode não ser igual ao resultado do incremento.

### <a name="remarks"></a>Comentários

**InterlockedIncrement** impede que mais de um segmento use simultaneamente essa variável.

## <a name="ccommultithreadmodelnocsthreadmodelnocs"></a><a name="threadmodelnocs"></a>CcomMultithreadmodelnocs::threadmodelnocs

Ao `CComMultiThreadModelNoCS`usar , o `ThreadModelNoCS` nome `CComMultiThreadModelNoCS` **typedef** simplesmente faz referência .

```
typedef CComMultiThreadModelNoCS ThreadModelNoCS;
```

### <a name="remarks"></a>Comentários

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também `ThreadModelNoCS`contêm definições para . A tabela a seguir mostra a relação entre a `ThreadModelNoCS`classe do modelo de rosca e a classe referenciada por :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|
|`CComSingleThreadModel`|`CComSingleThreadModel`|

Note que a `ThreadModelNoCS` `CComMultiThreadModelNoCS` definição de in fornece `CComMultiThreadModel` `CComSingleThreadModel`simetria com e . Por exemplo, suponha `CComMultiThreadModel::AutoCriticalSection` que o código de amostra em declarou o seguinte **tipo:**

[!code-cpp[NVC_ATL_COM#37](../../atl/codesnippet/cpp/ccommultithreadmodelnocs-class_1.h)]

Independentemente da classe `ThreadModel` especificada `CComMultiThreadModelNoCS`para `_ThreadModel` (como), resolve-se em conformidade.

### <a name="example"></a>Exemplo

Veja [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
