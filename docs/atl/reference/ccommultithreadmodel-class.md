---
title: Classe CComMultiThreadModel
ms.date: 11/04/2016
f1_keywords:
- CComMultiThreadModel
- ATLBASE/ATL::CComMultiThreadModel
- ATLBASE/ATL::CComMultiThreadModel::AutoCriticalSection
- ATLBASE/ATL::CComMultiThreadModel::CriticalSection
- ATLBASE/ATL::CComMultiThreadModel::ThreadModelNoCS
- ATLBASE/ATL::CComMultiThreadModel::Decrement
- ATLBASE/ATL::CComMultiThreadModel::Increment
helpviewer_keywords:
- ATL, multithreading
- CComMultiThreadModel class
- threading [ATL]
ms.assetid: db8f1662-2f7a-44b3-b341-ffbfb6e422a3
ms.openlocfilehash: 38ed43e77492484b7c8d8cb06cad71e695d41c4a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224273"
---
# <a name="ccommultithreadmodel-class"></a>Classe CComMultiThreadModel

`CComMultiThreadModel`fornece métodos thread-safe para incrementar e decrementar o valor de uma variável.

## <a name="syntax"></a>Sintaxe

```
class CComMultiThreadModel
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CComMultiThreadModel::AutoCriticalSection](#autocriticalsection)|Faz referência à classe [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md).|
|[CComMultiThreadModel:: CriticalSection](#criticalsection)|Faz referência à classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md).|
|[CComMultiThreadModel::ThreadModelNoCS](#threadmodelnocs)|Faz referência à classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComMultiThreadModel::D ecrement](#decrement)|Auto-estática Decrementa o valor da variável especificada de forma segura para thread.|
|[CComMultiThreadModel:: incremento](#increment)|Auto-estática Incrementa o valor da variável especificada de forma segura para thread.|

## <a name="remarks"></a>Comentários

Normalmente, você usa `CComMultiThreadModel` um dos dois **`typedef`** nomes, ou [CComObjectThreadModel] (ATL-TYPEDEFs. MD # CComObjectThreadModel ou [CComGlobalsThreadModel] (ATL-TYPEDEFs. MD # CComGlobalsThreadModel. A classe referenciada por cada **`typedef`** depende do modelo de Threading usado, conforme mostrado na tabela a seguir:

|typedef|Thread único|Threading de apartamento|Threading gratuito|
|-------------|----------------------|-------------------------|--------------------|
|`CComObjectThreadModel`|S|S|M|
|`CComGlobalsThreadModel`|S|M|M|

S = `CComSingleThreadModel` ; M =`CComMultiThreadModel`

`CComMultiThreadModel`em si, define três **`typedef`** nomes. `AutoCriticalSection`e `CriticalSection` classes de referência que fornecem métodos para obter e liberar a propriedade de uma seção crítica. `ThreadModelNoCS`faz referência à classe [CComMultiThreadModelNoCS (CComMultiThreadModelNoCS-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="ccommultithreadmodelautocriticalsection"></a><a name="autocriticalsection"></a>CComMultiThreadModel::AutoCriticalSection

Ao usar `CComMultiThreadModel` , o **`typedef`** nome `AutoCriticalSection` faz referência à classe [CComAutoCriticalSection](ccomautocriticalsection-class.md), que fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

```
typedef CComAutoCriticalSection AutoCriticalSection;
```

### <a name="remarks"></a>Comentários

[CComSingleThreadModel](ccomsinglethreadmodel-class.md) e [CComMultiThreadModelNoCS](ccommultithreadmodelnocs-class.md) também contêm definições para `AutoCriticalSection` . A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `AutoCriticalSection` :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModel`|`CComCriticalSection`|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|

Além disso `AutoCriticalSection` , você pode usar o **`typedef`** nome [CriticalSection](#criticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização do CRT.

### <a name="example"></a>Exemplo

O código a seguir é modelado após [CComObjectRootEx](ccomobjectrootex-class.md)e demonstra `AutoCriticalSection` ser usado em um ambiente de Threading.

```cpp
template<class ThreadModel>
class CMyAutoCritClass
{
public:
   typedef ThreadModel _ThreadModel;
   typedef typename _ThreadModel::AutoCriticalSection _CritSec;

   CMyAutoCritClass() : m_dwRef(0) {}

   ULONG InternalAddRef()
   {
      return _ThreadModel::Increment(&m_dwRef);
   }
   ULONG InternalRelease()
   {
      return _ThreadModel::Decrement(&m_dwRef);
   }
   void Lock() { m_critsec.Lock( ); }
   void Unlock() { m_critsec.Unlock(); }

private:
   _CritSec m_critsec;
   LONG m_dwRef;
```

As tabelas a seguir mostram os resultados dos `InternalAddRef` `Lock` métodos e, dependendo do parâmetro de `ThreadModel` modelo e do modelo de Threading usado pelo aplicativo:

### <a name="threadmodel--ccomobjectthreadmodel"></a>ThreadModel = CComObjectThreadModel

|Método|Thread único ou Apartment|Threading gratuito|
|------------|-----------------------------------|--------------------|
|`InternalAddRef`|O incremento não é thread-safe.|O incremento é thread-safe.|
|`Lock`|Não faz nada; Não há seção crítica para bloquear.|A seção crítica está bloqueada.|

### <a name="threadmodel--ccomobjectthreadmodelthreadmodelnocs"></a>ThreadModel = CComObjectThreadModel:: ThreadModelNoCS

|Método|Thread único ou Apartment|Threading gratuito|
|------------|-----------------------------------|--------------------|
|`InternalAddRef`|O incremento não é thread-safe.|O incremento é thread-safe.|
|`Lock`|Não faz nada; Não há seção crítica para bloquear.|Não faz nada; Não há seção crítica para bloquear.|

## <a name="ccommultithreadmodelcriticalsection"></a><a name="criticalsection"></a>CComMultiThreadModel:: CriticalSection

Ao usar `CComMultiThreadModel` , o **`typedef`** nome `CriticalSection` faz referência à classe [CComCriticalSection](ccomcriticalsection-class.md), que fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

```
typedef CComCriticalSection CriticalSection;
```

### <a name="remarks"></a>Comentários

[CComSingleThreadModel](ccomsinglethreadmodel-class.md) e [CComMultiThreadModelNoCS](ccommultithreadmodelnocs-class.md) também contêm definições para `CriticalSection` . A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe de seção crítica referenciada por `CriticalSection` :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModel`|`CComCriticalSection`|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|

Além disso `CriticalSection` , você pode usar o **`typedef`** nome [AutoCriticalSection](#autocriticalsection). Você não deve especificar `AutoCriticalSection` em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização do CRT.

### <a name="example"></a>Exemplo

Consulte [CComMultiThreadModel:: AutoCriticalSection](#autocriticalsection).

## <a name="ccommultithreadmodeldecrement"></a><a name="decrement"></a>CComMultiThreadModel::D ecrement

Essa função estática chama a função [InterlockedDecrement](/windows/win32/api/winnt/nf-winnt-interlockeddecrement)do Win32, que Decrementa o valor da variável apontada por *p*.

```
static ULONG WINAPI Decrement(LPLONG p) throw ();
```

### <a name="parameters"></a>parâmetros

*DTI*<br/>
no Ponteiro para a variável a ser decrementada.

### <a name="return-value"></a>Valor retornado

Se o resultado do decréscimo for 0, `Decrement` retornará 0. Se o resultado do decréscimo for diferente de zero, o valor de retorno também será diferente de zero, mas talvez não seja igual ao resultado do decréscimo.

### <a name="remarks"></a>Comentários

`InterlockedDecrement`impede que mais de um thread use simultaneamente essa variável.

## <a name="ccommultithreadmodelincrement"></a><a name="increment"></a>CComMultiThreadModel:: incremento

Essa função estática chama a função [InterlockedIncrement](/windows/win32/api/winnt/nf-winnt-interlockedincrement)do Win32, que incrementa o valor da variável apontada por *p*.

```
static ULONG WINAPI Increment(LPLONG p) throw ();
```

### <a name="parameters"></a>parâmetros

*DTI*<br/>
no Ponteiro para a variável a ser incrementada.

### <a name="return-value"></a>Valor retornado

Se o resultado do incremento for 0, `Increment` retornará 0. Se o resultado do incremento for diferente de zero, o valor de retorno também será diferente de zero, mas talvez não seja igual ao resultado do incremento.

### <a name="remarks"></a>Comentários

`InterlockedIncrement`impede que mais de um thread use simultaneamente essa variável.

## <a name="ccommultithreadmodelthreadmodelnocs"></a><a name="threadmodelnocs"></a>CComMultiThreadModel::ThreadModelNoCS

Ao usar `CComMultiThreadModel` , o **`typedef`** nome `ThreadModelNoCS` faz referência à classe [CComMultiThreadModelNoCS](ccommultithreadmodelnocs-class.md).

```
typedef CComMultiThreadModelNoCS ThreadModelNoCS;
```

### <a name="remarks"></a>Comentários

`CComMultiThreadModelNoCS`fornece métodos thread-safe para incrementar e decrementar uma variável; no entanto, ele não fornece uma seção crítica.

[CComSingleThreadModel](ccomsinglethreadmodel-class.md) e `CComMultiThreadModelNoCS` também contêm definições para `ThreadModelNoCS` . A tabela a seguir mostra a relação entre a classe de modelo de threading e a classe referenciada por `ThreadModelNoCS` :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|
|`CComSingleThreadModel`|`CComSingleThreadModel`|
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|

### <a name="example"></a>Exemplo

Consulte [CComMultiThreadModel:: AutoCriticalSection](#autocriticalsection).

## <a name="see-also"></a>Confira também

[Classe CComSingleThreadModel](ccomsinglethreadmodel-class.md)<br/>
[Classe CComAutoCriticalSection](ccomautocriticalsection-class.md)<br/>
[Classe CComCriticalSection](ccomcriticalsection-class.md)<br/>
[Visão geral da classe](../atl-class-overview.md)
