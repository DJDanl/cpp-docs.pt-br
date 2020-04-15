---
title: Classe IServiceProviderImpl
ms.date: 11/04/2016
f1_keywords:
- IServiceProviderImpl
- ATLCOM/ATL::IServiceProviderImpl
- ATLCOM/ATL::IServiceProviderImpl::QueryService
helpviewer_keywords:
- IServiceProviderImpl class
- IServiceProvider interface, ATL implementation
ms.assetid: 251254d3-c4ce-40d7-aee0-3d676d1d72f2
ms.openlocfilehash: ef0ee4f77441cb8d19ea2d6dcada1fed9faf2782
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329422"
---
# <a name="iserviceproviderimpl-class"></a>Classe IServiceProviderImpl

Esta classe fornece uma `IServiceProvider` implementação padrão da interface.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE IServiceProviderImpl : public IServiceProvider
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IServiceProviderImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IServiceProviderImpl::QueryService](#queryservice)|Cria ou acessa o serviço especificado e retorna um ponteiro de interface para a interface especificada para o serviço.|

## <a name="remarks"></a>Comentários

A `IServiceProvider` interface localiza um serviço especificado por seu GUID e retorna o ponteiro de interface para a interface solicitada no serviço. A `IServiceProviderImpl` classe fornece uma implementação padrão desta interface.

`IServiceProviderImpl`especifica um método: [QueryService](#queryservice), que cria ou acessa o serviço especificado e retorna um ponteiro de interface para a interface especificada para o serviço.

`IServiceProviderImpl`usa um mapa de serviço, começando com [BEGIN_SERVICE_MAP](service-map-macros.md#begin_service_map) e terminando com [END_SERVICE_MAP](service-map-macros.md#end_service_map).

O mapa de serviço contém duas entradas: [SERVICE_ENTRY](service-map-macros.md#service_entry), que indica um sid (service id) de serviço especificado suportado pelo objeto, e [SERVICE_ENTRY_CHAIN](service-map-macros.md#service_entry_chain), que chama `QueryService` para cadeia para outro objeto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IServiceProvider`

`IServiceProviderImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="iserviceproviderimplqueryservice"></a><a name="queryservice"></a>IServiceProviderImpl::QueryService

Cria ou acessa o serviço especificado e retorna um ponteiro de interface para a interface especificada para o serviço.

```
STDMETHOD(QueryService)(
    REFGUID guidService,
    REFIID riid,
    void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*guidService*<br/>
[em] Ponteiro para um identificador de serviço (SID).

*riid*<br/>
[em] Identificador da interface à qual o chamador deve ter acesso.

*Ppvobj*<br/>
[fora] Ponteiro indireto para a interface solicitada.

### <a name="return-value"></a>Valor retornado

O valor HRESULT retornado é um dos seguintes:

|Valor retornado|Significado|
|------------------|-------------|
|S_OK|O serviço foi criado ou recuperado com sucesso.|
|E_INVALIDARG|Um ou mais argumentos são inválidos.|
|E_OUTOFMEMORY|A memória é insuficiente para criar o serviço.|
|E_UNEXPECTED|Erro desconhecido.|
|E_NOINTERFACE|A interface solicitada não faz parte deste serviço, ou o serviço é desconhecido.|

### <a name="remarks"></a>Comentários

`QueryService`retorna um ponteiro indireto para a interface solicitada no serviço especificado. O chamador é responsável por liberar este ponteiro quando ele não é mais necessário.

Quando você `QueryService`liga, você passa tanto um identificador de serviço *(guidService)* quanto um identificador de interface *(riid).* O *guidService* especifica o serviço ao qual você deseja acesso, e o *riid* identifica uma interface que faz parte do serviço. Em troca, você recebe um ponteiro indireto para a interface.

O objeto que implementa a interface também pode implementar interfaces que fazem parte de outros serviços. Considere o seguinte:

- Algumas dessas interfaces podem ser opcionais. Nem todas as interfaces definidas na descrição do serviço estão necessariamente presentes em cada implementação do serviço ou em cada objeto retornado.

- Ao contrário `QueryInterface`das chamadas para , passar um identificador de serviço diferente não significa necessariamente que um objeto COM (Component Object Model, modelo de objeto componente) diferente seja devolvido.

- O objeto retornado pode ter interfaces adicionais que não fazem parte da definição do serviço.

Dois serviços diferentes, como SID_SMyService e SID_SYourService, podem tanto especificar o uso da mesma interface, embora a implementação da interface possa não ter nada em comum entre os dois serviços. Isso funciona, pois `QueryService` uma chamada para (SID_SMyService, IID_IDispatch) pode retornar um objeto diferente do `QueryService` (SID_SYourService, IID_IDispatch). A identidade do objeto não é assumida quando você especifica um identificador de serviço diferente.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
