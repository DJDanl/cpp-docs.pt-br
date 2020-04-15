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
ms.openlocfilehash: 7ef803439d2d683633e8f9c00810542dd787541e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327663"
---
# <a name="ccommultithreadmodel-class"></a>Classe CComMultiThreadModel

`CComMultiThreadModel`fornece métodos seguros para incrementar e diminuir o valor de uma variável.

## <a name="syntax"></a>Sintaxe

```
class CComMultiThreadModel
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CComMultiThreadModel::AutoCriticalSection](#autocriticalsection)|Referências classe [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md).|
|[CComMultiThreadModel::CriticalSection](#criticalsection)|Referências classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md).|
|[CComMultithreadModel::threadmodelnocs](#threadmodelnocs)|Referências classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComMultiThreadModelo::Decrement](#decrement)|(Estática) Decreta o valor da variável especificada de forma segura para o segmento.|
|[CComMultiThreadModel::Incremento](#increment)|(Estática) Incrementa o valor da variável especificada de forma segura para o segmento.|

## <a name="remarks"></a>Comentários

Normalmente, você `CComMultiThreadModel` usa através de um dos dois nomes **typedef,** [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel ou [CComGlobalsThreadModel](atl-typedefs.md#ccomglobalsthreadmodel. A classe referenciada por cada **typedef** depende do modelo de rosca utilizado, conforme mostrado na tabela a seguir:

|typedef|Rosca única|Rosca do apartamento|Rosca grátis|
|-------------|----------------------|-------------------------|--------------------|
|`CComObjectThreadModel`|S|S|M|
|`CComGlobalsThreadModel`|S|M|M|

S= `CComSingleThreadModel`; M=`CComMultiThreadModel`

`CComMultiThreadModel`em si define três nomes **typedef.** `AutoCriticalSection`e `CriticalSection` classes de referência que fornecem métodos para a obtenção e liberação da propriedade de uma seção crítica. `ThreadModelNoCS`classe de referências [CComMultiThreadModelNoCS(ccommultithreadmodelnocs-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccommultithreadmodelautocriticalsection"></a><a name="autocriticalsection"></a>CComMultiThreadModel::AutoCriticalSection

Ao `CComMultiThreadModel`usar , o `AutoCriticalSection` nome **typedef** faz referência à classe [CComAutoCriticalSection](ccomautocriticalsection-class.md), que fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

```
typedef CComAutoCriticalSection AutoCriticalSection;
```

### <a name="remarks"></a>Comentários

[CComSingleThreadModel](ccomsinglethreadmodel-class.md) e [CComMultiThreadModelNoCS](ccommultithreadmodelnocs-class.md) também `AutoCriticalSection`contêm definições para . A tabela a seguir mostra a relação entre a classe `AutoCriticalSection`do modelo de rosca e a classe de seção crítica referenciada por :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModel`|`CComCriticalSection`|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|

Além disso, `AutoCriticalSection`você pode usar o nome **typedef** [CriticalSection](#criticalsection). Você não `AutoCriticalSection` deve especificar em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização CRT.

### <a name="example"></a>Exemplo

O código a seguir é modelado após `AutoCriticalSection` [CComObjectRootEx](ccomobjectrootex-class.md), e demonstra ser usado em um ambiente de rosca.

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

As tabelas a seguir `InternalAddRef` `Lock` mostram os resultados `ThreadModel` dos métodos e métodos, dependendo do parâmetro do modelo e do modelo de rosca utilizado pela aplicação:

### <a name="threadmodel--ccomobjectthreadmodel"></a>Modelo de rosca = Modelo CComObjectThread

|Método|Rosca única ou de apartamento|Rosqueamento gratuito|
|------------|-----------------------------------|--------------------|
|`InternalAddRef`|O incremento não é seguro para rosca.|O incremento é seguro para rosca.|
|`Lock`|Não faz nada; não há nenhuma seção crítica para travar.|A seção crítica está bloqueada.|

### <a name="threadmodel--ccomobjectthreadmodelthreadmodelnocs"></a>Modelo de thread = CComObjectThreadModel::ThreadModelNoCS

|Método|Rosca única ou de apartamento|Rosqueamento gratuito|
|------------|-----------------------------------|--------------------|
|`InternalAddRef`|O incremento não é seguro para rosca.|O incremento é seguro para rosca.|
|`Lock`|Não faz nada; não há nenhuma seção crítica para travar.|Não faz nada; não há nenhuma seção crítica para travar.|

## <a name="ccommultithreadmodelcriticalsection"></a><a name="criticalsection"></a>CComMultiThreadModel::CriticalSection

Ao `CComMultiThreadModel`usar , o `CriticalSection` nome **typedef** faz referência à classe [CComCriticalSection](ccomcriticalsection-class.md), que fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

```
typedef CComCriticalSection CriticalSection;
```

### <a name="remarks"></a>Comentários

[CComSingleThreadModel](ccomsinglethreadmodel-class.md) e [CComMultiThreadModelNoCS](ccommultithreadmodelnocs-class.md) também `CriticalSection`contêm definições para . A tabela a seguir mostra a relação entre a classe `CriticalSection`do modelo de rosca e a classe de seção crítica referenciada por :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModel`|`CComCriticalSection`|
|`CComSingleThreadModel`|`CComFakeCriticalSection`|
|`CComMultiThreadModelNoCS`|`CComFakeCriticalSection`|

Além disso, `CriticalSection`você pode usar o nome **typedef** [AutoCriticalSection](#autocriticalsection). Você não `AutoCriticalSection` deve especificar em objetos globais ou membros de classe estática se quiser eliminar o código de inicialização CRT.

### <a name="example"></a>Exemplo

Veja [CComMultiThreadModel::AutoCriticalSection](#autocriticalsection).

## <a name="ccommultithreadmodeldecrement"></a><a name="decrement"></a>CComMultiThreadModelo::Decrement

Esta função estática chama a função Win32 [InterlockedDecrement](/windows/win32/api/winnt/nf-winnt-interlockeddecrement), que diminui o valor da variável apontada para *p*.

```
static ULONG WINAPI Decrement(LPLONG p) throw ();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Ponteiro para a variável a ser decretada.

### <a name="return-value"></a>Valor retornado

Se o resultado do decremento `Decrement` for 0, então retorna 0. Se o resultado do decremento não for zero, o valor de retorno também não é zero, mas pode não ser igual ao resultado do decremento.

### <a name="remarks"></a>Comentários

`InterlockedDecrement`impede que mais de um segmento use simultaneamente essa variável.

## <a name="ccommultithreadmodelincrement"></a><a name="increment"></a>CComMultiThreadModel::Incremento

Esta função estática chama a função Win32 [InterlockedIncrement](/windows/win32/api/winnt/nf-winnt-interlockedincrement), que incrementa o valor da variável apontada para *p*.

```
static ULONG WINAPI Increment(LPLONG p) throw ();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Ponteiro para a variável a ser incrementada.

### <a name="return-value"></a>Valor retornado

Se o resultado do incremento `Increment` for 0, então retorna 0. Se o resultado do incremento não for zero, o valor de retorno também não é zero, mas pode não ser igual ao resultado do incremento.

### <a name="remarks"></a>Comentários

`InterlockedIncrement`impede que mais de um segmento use simultaneamente essa variável.

## <a name="ccommultithreadmodelthreadmodelnocs"></a><a name="threadmodelnocs"></a>CComMultithreadModel::threadmodelnocs

Ao `CComMultiThreadModel`usar, o nome `ThreadModelNoCS` **typedef** faz referência à classe [CComMultiThreadModelNoCS](ccommultithreadmodelnocs-class.md).

```
typedef CComMultiThreadModelNoCS ThreadModelNoCS;
```

### <a name="remarks"></a>Comentários

`CComMultiThreadModelNoCS`fornece métodos seguros para incrementar e diminuir uma variável; no entanto, não fornece uma seção crítica.

[CComSingleThreadModel](ccomsinglethreadmodel-class.md) `CComMultiThreadModelNoCS` e também contém `ThreadModelNoCS`definições para . A tabela a seguir mostra a relação entre a `ThreadModelNoCS`classe do modelo de rosca e a classe referenciada por :

|Classe definida em|Classe referenciada|
|----------------------|----------------------|
|`CComMultiThreadModel`|`CComMultiThreadModelNoCS`|
|`CComSingleThreadModel`|`CComSingleThreadModel`|
|`CComMultiThreadModelNoCS`|`CComMultiThreadModelNoCS`|

### <a name="example"></a>Exemplo

Veja [CComMultiThreadModel::AutoCriticalSection](#autocriticalsection).

## <a name="see-also"></a>Confira também

[Classe CComSingleThreadModel](ccomsinglethreadmodel-class.md)<br/>
[Classe CComAutoCriticalSection](ccomautocriticalsection-class.md)<br/>
[Classe CComCriticalSection](ccomcriticalsection-class.md)<br/>
[Visão geral da classe](../atl-class-overview.md)
