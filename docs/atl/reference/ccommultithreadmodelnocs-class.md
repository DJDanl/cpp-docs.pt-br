---
title: Classe CComMultiThreadModelNoCS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComMultiThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModelNoCS::AutoCriticalSection
- ATLBASE/ATL::CComMultiThreadModelNoCS::CriticalSection
- ATLBASE/ATL::CComMultiThreadModelNoCS::ThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModelNoCS::Decrement
- ATLBASE/ATL::CComMultiThreadModelNoCS::Increment
dev_langs:
- C++
helpviewer_keywords:
- ATL, multithreading
- CComMultiThreadModelNoCS class
- threading [ATL]
ms.assetid: 2b3f7a45-fd72-452c-aaf3-ccdaa621c821
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 13a8b36c3238d75d9a6cb03972023a6d85d3097a
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43756542"
---
# <a name="ccommultithreadmodelnocs-class"></a>Classe CComMultiThreadModelNoCS

`CComMultiThreadModelNoCS` fornece métodos thread-safe para incrementar e diminuir o valor de uma variável, sem bloqueio de seção crítica ou a funcionalidade de desbloqueio.

## <a name="syntax"></a>Sintaxe

```
class CComMultiThreadModelNoCS
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CComMultiThreadModelNoCS::AutoCriticalSection](#autocriticalsection)|Referencia a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).|
|[CComMultiThreadModelNoCS::CriticalSection](#criticalsection)|Referencia a classe `CComFakeCriticalSection`.|
|[CComMultiThreadModelNoCS::ThreadModelNoCS](#threadmodelnocs)|Referencia a classe `CComMultiThreadModelNoCS`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComMultiThreadModelNoCS::Decrement](#decrement)|(Estático) Decrementa o valor da variável especificada em uma forma thread-safe.|
|[CComMultiThreadModelNoCS::Increment](#increment)|(Estático) Incrementa o valor da variável especificada em uma forma thread-safe.|

## <a name="remarks"></a>Comentários

`CComMultiThreadModelNoCS` é semelhante à [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) em que ele fornece métodos thread-safe para incrementar e diminuir uma variável. No entanto, ao fazer referência a uma classe de seção crítica por meio `CComMultiThreadModelNoCS`, métodos, como `Lock` e `Unlock` não fará nada.

Normalmente, você usa `CComMultiThreadModelNoCS` por meio de `ThreadModelNoCS` **typedef** nome. Isso **typedef** é definida no `CComMultiThreadModelNoCS`, `CComMultiThreadModel`, e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md).

> [!NOTE]
>  Global **typedef** nomes [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) e [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel) não fazem referência a `CComMultiThreadModelNoCS`.

Além `ThreadModelNoCS`, `CComMultiThreadModelNoCS` define `AutoCriticalSection` e `CriticalSection`. Esses dois últimos **typedef** nomes referenciam [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md), que fornece métodos vazios associados como adquirir e liberar uma seção crítica.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="autocriticalsection"></a>  CComMultiThreadModelNoCS::AutoCriticalSection

Ao usar `CComMultiThreadModelNoCS`, o **typedef** nome `AutoCriticalSection` referencia a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).

```
typedef CComFakeCriticalSection AutoCriticalSection;
```

### <a name="remarks"></a>Comentários

Porque `CComFakeCriticalSection` não oferece uma seção crítica, seus métodos não fazem nada.

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também contêm as definições para `AutoCriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `AutoCriticalSection`:

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|
|`CComMultiThreadModel`|`CComAutoCriticalSection`|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|

Além `AutoCriticalSection`, você pode usar o **typedef** nome [CriticalSection](#criticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros da classe estática para eliminar o código de inicialização do CRT.

### <a name="example"></a>Exemplo

Ver [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

##  <a name="criticalsection"></a>  CComMultiThreadModelNoCS::CriticalSection

Ao usar `CComMultiThreadModelNoCS`, o **typedef** nome `CriticalSection` referencia a classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md).

```
typedef CComFakeCriticalSection CriticalSection;
```

### <a name="remarks"></a>Comentários

Porque `CComFakeCriticalSection` não oferece uma seção crítica, seus métodos não fazem nada.

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também contêm as definições para `CriticalSection`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `CriticalSection`:

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|
|`CComMultiThreadModel`|`CComCriticalSection`|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|

Além `CriticalSection`, você pode usar o **typedef** nome `AutoCriticalSection`. Você não deve especificar `AutoCriticalSection` em objetos globais ou membros da classe estática para eliminar o código de inicialização do CRT.

### <a name="example"></a>Exemplo

Ver [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

##  <a name="decrement"></a>  CComMultiThreadModelNoCS::Decrement

A função estática chama a função Win32 [InterlockedDecrement](/windows/desktop/api/winbase/nf-winbase-interlockeddecrement), que diminui o valor da variável apontado por *p*.

```
static ULONG WINAPI Decrement(LPLONG p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*  
[in] Ponteiro para a variável a ser diminuída.

### <a name="return-value"></a>Valor de retorno

Se o resultado de decremento for 0, em seguida, `Decrement` retornará 0. Se o resultado de decremento for diferente de zero, o valor retornado também é diferente de zero, mas não pode ser igual ao resultado de decremento.

### <a name="remarks"></a>Comentários

**InterlockedDecrement** impede que mais de um thread simultaneamente usando essa variável.

##  <a name="increment"></a>  CComMultiThreadModelNoCS::Increment

A função estática chama a função Win32 [InterlockedIncrement](/windows/desktop/api/winbase/nf-winbase-interlockedincrement), que incrementa o valor da variável apontado por *p*.

```
static ULONG WINAPI Increment(LPLONG p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*  
[in] Ponteiro para a variável a ser incrementado.

### <a name="return-value"></a>Valor de retorno

Se o resultado do incremento é 0, então **incremento** retornará 0. Se o resultado do incremento for diferente de zero, o valor retornado também é diferente de zero, mas não pode ser igual ao resultado do incremento.

### <a name="remarks"></a>Comentários

**InterlockedIncrement** impede que mais de um thread simultaneamente usando essa variável.

##  <a name="threadmodelnocs"></a>  CComMultiThreadModelNoCS::ThreadModelNoCS

Ao usar `CComMultiThreadModelNoCS`, o **typedef** nome `ThreadModelNoCS` simplesmente faz referência a `CComMultiThreadModelNoCS`.

```
typedef CComMultiThreadModelNoCS ThreadModelNoCS;
```

### <a name="remarks"></a>Comentários

[CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) também contêm as definições para `ThreadModelNoCS`. A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe referenciada por `ThreadModelNoCS`:

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|
|`CComSingleThreadModel`|`CComSingleThreadModel`|

Observe que a definição de `ThreadModelNoCS` na `CComMultiThreadModelNoCS` oferece simetria com `CComMultiThreadModel` e `CComSingleThreadModel`. Por exemplo, suponha que o código de exemplo na `CComMultiThreadModel::AutoCriticalSection` declarada a seguir **typedef**:

[!code-cpp[NVC_ATL_COM#37](../../atl/codesnippet/cpp/ccommultithreadmodelnocs-class_1.h)]

Independentemente da classe especificada para `ThreadModel` (como `CComMultiThreadModelNoCS`), `_ThreadModel` resolve adequadamente.

### <a name="example"></a>Exemplo

Ver [CComMultiThreadModel::AutoCriticalSection](../../atl/reference/ccommultithreadmodel-class.md#autocriticalsection).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)