---
title: Macros de mapa do serviço
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_SERVICE_MAP
- atlcom/ATL::END_SERVICE_MAP
- atlcom/ATL::SERVICE_ENTRY
- atlcom/ATL::SERVICE_ENTRY_CHAIN
ms.assetid: ca02a125-454a-4cf6-aac2-1c5585025ed4
ms.openlocfilehash: ab130b2401dc9885f82fd5668a2d722a96dd289b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62274558"
---
# <a name="service-map-macros"></a>Macros de mapa do serviço

Essas macros definem entradas e mapas de serviço.

|||
|-|-|
|[BEGIN_SERVICE_MAP](#begin_service_map)|Marca o início de um mapa de serviço do ATL.|
|[END_SERVICE_MAP](#end_service_map)|Marca o final de um mapa de serviço do ATL.|
|[SERVICE_ENTRY](#service_entry)|Indica que o objeto oferece suporte a uma ID de serviço específico.|
|[SERVICE_ENTRY_CHAIN](#service_entry_chain)|Instrui [IServiceProviderImpl::QueryService](#queryservice) encadear para o objeto especificado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="begin_service_map"></a>  BEGIN_SERVICE_MAP

Marca o início do mapa do serviço.

```
BEGIN_SERVICE_MAP(theClass)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
[in] Especifica a classe que contém o mapa do serviço.

### <a name="remarks"></a>Comentários

Use o mapa de serviço para implementar a funcionalidade de provedor de serviço em seu objeto COM. Primeiro, você deve derivar sua classe de [IServiceProviderImpl](../../atl/reference/iserviceproviderimpl-class.md). Há dois tipos de entradas:

- [SERVICE_ENTRY](#service_entry) indica que há suporte para o SID (ID) de serviço especificado.

- [SERVICE_ENTRY_CHAIN](#service_entry_chain) instrui [IServiceProviderImpl::QueryService](#queryservice) encadear para outro objeto especificado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#57](../../atl/codesnippet/cpp/service-map-macros_1.h)]

##  <a name="end_service_map"></a>  END_SERVICE_MAP

Marca o fim do mapa do serviço.

```
END_SERVICE_MAP()
```

### <a name="example"></a>Exemplo

Veja o exemplo de [BEGIN_SERVICE_MAP](#begin_service_map).

##  <a name="service_entry"></a>  SERVICE_ENTRY

Indica que o objeto oferece suporte a id de serviço especificada por *SID*.

```
SERVICE_ENTRY( SID )
```

### <a name="parameters"></a>Parâmetros

*SID*<br/>
A ID de serviço.

### <a name="example"></a>Exemplo

Veja o exemplo de [BEGIN_SERVICE_MAP](#begin_service_map).

##  <a name="service_entry_chain"></a>  SERVICE_ENTRY_CHAIN

Instrui [IServiceProviderImpl::QueryService](#queryservice) encadear para o objeto especificado por *punk*.

```
SERVICE_ENTRY_CHAIN( punk )
```

### <a name="parameters"></a>Parâmetros

*punk*<br/>
Um ponteiro para o **IUnknown** interface à qual a cadeia.

### <a name="example"></a>Exemplo

Veja o exemplo de [BEGIN_SERVICE_MAP](#begin_service_map).

##  <a name="queryservice"></a>  IServiceProviderImpl::QueryService

Cria ou acessa o serviço especificado e retorna um ponteiro de interface para a interface especificada para o serviço.

```
STDMETHOD(QueryService)(
    REFGUID guidService,
    REFIID riid,
    void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*guidService*<br/>
[in] Ponteiro para um serviço SID (identificador).

*riid*<br/>
[in] Identificador da interface ao qual o chamador deve ter acesso.

*ppvObj*<br/>
[out] Ponteiro indireto para a interface solicitada.

### <a name="return-value"></a>Valor de retorno

O valor HRESULT retornado é um dos seguintes:

|Valor retornado|Significado|
|------------------|-------------|
|S_OK|O serviço com êxito foi criado ou recuperado.|
|E_INVALIDARG|Um ou mais argumentos são inválidos.|
|E_OUTOFMEMORY|Memória é insuficiente para criar o serviço.|
|E_UNEXPECTED|Erro desconhecido.|
|E_NOINTERFACE|A interface solicitada não é parte do serviço ou o serviço é desconhecido.|

### <a name="remarks"></a>Comentários

`QueryService` Retorna um ponteiro indireto para a interface solicitada no serviço especificado. O chamador é responsável por liberar esse ponteiro quando não for mais necessário.

Quando você chama `QueryService`, você passa um identificador do serviço (*guidService*) e um identificador de interface (*riid*). O *guidService* Especifica o serviço ao qual você deseja acesso, e o *riid* identifica uma interface que é parte do serviço. Em troca, você recebe um ponteiro indireto para a interface.

O objeto que implementa a interface também pode implementar interfaces que fazem parte de outros serviços. Considere o seguinte:

- Algumas dessas interfaces podem ser opcionais. Nem todas as interfaces definidas na descrição de serviço estão necessariamente presentes em cada implementação do serviço ou em cada objeto retornado.

- Ao contrário das chamadas para `QueryInterface`, passar um identificador de serviço diferentes não significa necessariamente que um objeto diferente do modelo de objeto de componente (COM) é retornado.

- O objeto retornado pode ter interfaces adicionais que não fazem parte da definição do serviço.

Dois serviços diferentes, como SID_SMyService e SID_SYourService, podem ambos especificam o uso da mesma interface, mesmo que a implementação da interface pode ter nada em comum entre os dois serviços. Isso funciona, porque uma chamada para `QueryService` (SID_SMyService, IID_IDispatch) pode retornar um objeto diferente que `QueryService` (SID_SYourService, IID_IDispatch). Identidade do objeto não será considerada quando você especificar um identificador de serviço diferentes.

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
