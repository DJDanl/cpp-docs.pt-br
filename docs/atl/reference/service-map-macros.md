---
title: Mapa do Serviço macros
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_SERVICE_MAP
- atlcom/ATL::END_SERVICE_MAP
- atlcom/ATL::SERVICE_ENTRY
- atlcom/ATL::SERVICE_ENTRY_CHAIN
ms.assetid: ca02a125-454a-4cf6-aac2-1c5585025ed4
ms.openlocfilehash: ab130b2401dc9885f82fd5668a2d722a96dd289b
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417470"
---
# <a name="service-map-macros"></a>Mapa do Serviço macros

Essas macros definem as entradas e mapas de serviço.

|||
|-|-|
|[BEGIN_SERVICE_MAP](#begin_service_map)|Marca o início de um mapa do serviço ATL.|
|[END_SERVICE_MAP](#end_service_map)|Marca o final de um mapa do serviço ATL.|
|[SERVICE_ENTRY](#service_entry)|Indica que o objeto dá suporte a uma ID de serviço específica.|
|[SERVICE_ENTRY_CHAIN](#service_entry_chain)|Instrui o [IServiceProviderImpl:: QueryService](#queryservice) ao encadeamento com o objeto especificado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="begin_service_map"></a>BEGIN_SERVICE_MAP

Marca o início do mapa do serviço.

```
BEGIN_SERVICE_MAP(theClass)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
no Especifica a classe que contém o mapa do serviço.

### <a name="remarks"></a>Comentários

Use o mapa do serviço para implementar a funcionalidade do provedor de serviços em seu objeto COM. Primeiro, você deve derivar sua classe de [IServiceProviderImpl](../../atl/reference/iserviceproviderimpl-class.md). Há dois tipos de entradas:

- [SERVICE_ENTRY](#service_entry)   Indica suporte para a ID de serviço (SID) especificada.

- [SERVICE_ENTRY_CHAIN](#service_entry_chain)   Instrui o [IServiceProviderImpl:: QueryService](#queryservice) à cadeia para outro objeto especificado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#57](../../atl/codesnippet/cpp/service-map-macros_1.h)]

##  <a name="end_service_map"></a>END_SERVICE_MAP

Marca o final do mapa do serviço.

```
END_SERVICE_MAP()
```

### <a name="example"></a>Exemplo

Consulte o exemplo para [BEGIN_SERVICE_MAP](#begin_service_map).

##  <a name="service_entry"></a>SERVICE_ENTRY

Indica que o objeto dá suporte à ID de serviço especificada pelo *Sid*.

```
SERVICE_ENTRY( SID )
```

### <a name="parameters"></a>parâmetros

*SID*<br/>
A ID do serviço.

### <a name="example"></a>Exemplo

Consulte o exemplo para [BEGIN_SERVICE_MAP](#begin_service_map).

##  <a name="service_entry_chain"></a>SERVICE_ENTRY_CHAIN

Instrui o [IServiceProviderImpl:: QueryService](#queryservice) ao encadeamento com o objeto especificado por *punk*.

```
SERVICE_ENTRY_CHAIN( punk )
```

### <a name="parameters"></a>parâmetros

*punk*<br/>
Um ponteiro para a interface **IUnknown** a ser encadeada.

### <a name="example"></a>Exemplo

Consulte o exemplo para [BEGIN_SERVICE_MAP](#begin_service_map).

##  <a name="queryservice"></a>IServiceProviderImpl:: QueryService

Cria ou acessa o serviço especificado e retorna um ponteiro de interface para a interface especificada para o serviço.

```
STDMETHOD(QueryService)(
    REFGUID guidService,
    REFIID riid,
    void** ppvObject);
```

### <a name="parameters"></a>parâmetros

*guidService*<br/>
no Ponteiro para um identificador de serviço (SID).

*riid*<br/>
no Identificador da interface à qual o chamador deve obter acesso.

*ppvObj*<br/>
fora Ponteiro indireto para a interface solicitada.

### <a name="return-value"></a>Valor retornado

O valor HRESULT retornado é um dos seguintes:

|Valor retornado|Significado|
|------------------|-------------|
|S_OK|O serviço foi criado ou recuperado com êxito.|
|E_INVALIDARG|Um ou mais argumentos são inválidos.|
|E_OUTOFMEMORY|A memória é insuficiente para criar o serviço.|
|E_UNEXPECTED|Erro desconhecido.|
|{1&gt;E_NOINTERFACE&lt;1}|A interface solicitada não faz parte deste serviço ou o serviço é desconhecido.|

### <a name="remarks"></a>Comentários

`QueryService` retorna um ponteiro indireto para a interface solicitada no serviço especificado. O chamador é responsável por liberar esse ponteiro quando ele não for mais necessário.

Ao chamar `QueryService`, você passa um*guidService*(identificador de serviço) e um*riid*(identificador de interface). O *guidService* especifica o serviço ao qual você deseja acessar e o *riid* identifica uma interface que faz parte do serviço. Em retorno, você recebe um ponteiro indireto para a interface.

O objeto que implementa a interface também pode implementar interfaces que fazem parte de outros serviços. Considere o seguinte:

- Algumas dessas interfaces podem ser opcionais. Nem todas as interfaces definidas na descrição do serviço estão necessariamente presentes em todas as implementações do serviço ou em todos os objetos retornados.

- Ao contrário de chamadas para `QueryInterface`, a passagem de um identificador de serviço diferente não significa necessariamente que um objeto COM (Component Object Model) diferente seja retornado.

- O objeto retornado pode ter interfaces adicionais que não fazem parte da definição do serviço.

Dois serviços diferentes, como SID_SMyService e SID_SYourService, podem especificar o uso da mesma interface, mesmo que a implementação da interface possa não ter nada em comum entre os dois serviços. Isso funciona porque uma chamada para `QueryService` (SID_SMyService, IID_IDispatch) pode retornar um objeto diferente de `QueryService` (SID_SYourService, IID_IDispatch). A identidade do objeto não é presumida quando você especifica um identificador de serviço diferente.

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
