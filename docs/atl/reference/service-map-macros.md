---
title: Macros do mapa de serviço
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_SERVICE_MAP
- atlcom/ATL::END_SERVICE_MAP
- atlcom/ATL::SERVICE_ENTRY
- atlcom/ATL::SERVICE_ENTRY_CHAIN
ms.assetid: ca02a125-454a-4cf6-aac2-1c5585025ed4
ms.openlocfilehash: eb2fe41c79135a7ac2ced9bc3242b070170716b9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325934"
---
# <a name="service-map-macros"></a>Macros do mapa de serviço

Essas macros definem mapas de serviço e entradas.

|||
|-|-|
|[BEGIN_SERVICE_MAP](#begin_service_map)|Marca o início de um mapa de serviço ATL.|
|[END_SERVICE_MAP](#end_service_map)|Marca o fim de um mapa de serviço ATL.|
|[SERVICE_ENTRY](#service_entry)|Indica que o objeto suporta um ID de serviço específico.|
|[SERVICE_ENTRY_CHAIN](#service_entry_chain)|Instrui [iServiceProviderImpl::QueryService](#queryservice) para a cadeia para o objeto especificado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="begin_service_map"></a><a name="begin_service_map"></a>BEGIN_SERVICE_MAP

Marca o início do mapa de serviço.

```
BEGIN_SERVICE_MAP(theClass)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
[em] Especifica a classe que contém o mapa de serviço.

### <a name="remarks"></a>Comentários

Use o mapa de serviço para implementar a funcionalidade do provedor de serviços em seu objeto COM. Primeiro, você deve derivar sua classe de [IServiceProviderImpl](../../atl/reference/iserviceproviderimpl-class.md). Existem dois tipos de entradas:

- [SERVICE_ENTRY SERVICE_ENTRY.](#service_entry)   Indica suporte para o ID de serviço especificado (SID).

- [SERVICE_ENTRY_CHAIN SERVICE_ENTRY_CHAIN.](#service_entry_chain)   Instrui [o IServiceProviderImpl::QueryService](#queryservice) para a cadeia para outro objeto especificado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#57](../../atl/codesnippet/cpp/service-map-macros_1.h)]

## <a name="end_service_map"></a><a name="end_service_map"></a>END_SERVICE_MAP

Marca o fim do mapa de serviço.

```
END_SERVICE_MAP()
```

### <a name="example"></a>Exemplo

Veja o exemplo [de BEGIN_SERVICE_MAP](#begin_service_map).

## <a name="service_entry"></a><a name="service_entry"></a>SERVICE_ENTRY

Indica que o objeto suporta o id de serviço especificado pelo *SID*.

```
SERVICE_ENTRY( SID )
```

### <a name="parameters"></a>Parâmetros

*SID*<br/>
A iD de serviço.

### <a name="example"></a>Exemplo

Veja o exemplo [de BEGIN_SERVICE_MAP](#begin_service_map).

## <a name="service_entry_chain"></a><a name="service_entry_chain"></a>SERVICE_ENTRY_CHAIN

Instrui [o IServiceProviderImpl::QueryService](#queryservice) para a cadeia com o objeto especificado pelo *punk*.

```
SERVICE_ENTRY_CHAIN( punk )
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
Um ponteiro para a interface **IUnknown** para a qual a cadeia.

### <a name="example"></a>Exemplo

Veja o exemplo [de BEGIN_SERVICE_MAP](#begin_service_map).

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

[Macros](../../atl/reference/atl-macros.md)
