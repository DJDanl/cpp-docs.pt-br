---
title: Funções globais de ponto de conexão
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlAdvise
- atlbase/ATL::AtlUnadvise
- atlbase/ATL::AtlAdviseSinkMap
helpviewer_keywords:
- connection points [C++], global functions
ms.assetid: bcb4bf50-2155-4e20-b8bb-f2908b03a6e7
ms.openlocfilehash: 0313e93ee82bb96f3bfe08e45f70ccfee30dbee6
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78864393"
---
# <a name="connection-point-global-functions"></a>Funções globais de ponto de conexão

Essas funções fornecem suporte para pontos de conexão e mapas de coletor.

> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados no Windows Runtime.

|||
|-|-|
|[AtlAdvise](#atladvise)|Cria uma conexão entre o ponto de conexão de um objeto e o coletor de um cliente.|
|[AtlUnadvise](#atlunadvise)|Encerra a conexão estabelecida por meio de `AtlAdvise`.|
|[AtlAdviseSinkMap](#atladvisesinkmap)|Aconselha ou informa as entradas em um mapa do coletor de eventos.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="atladvise"></a>AtlAdvise

Cria uma conexão entre o ponto de conexão de um objeto e o coletor de um cliente.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
HRESULT    AtlAdvise(
    IUnknown* pUnkCP,
    IUnknown* pUnk,
    const IID& iid,
    LPDWORD pdw);
```

### <a name="parameters"></a>parâmetros

*pUnkCP*<br/>
no Um ponteiro para a `IUnknown` do objeto ao qual o cliente deseja se conectar.

*pUnk*<br/>
no Um ponteiro para a `IUnknown`do cliente.

*IID*<br/>
no O GUID do ponto de conexão. Normalmente, isso é o mesmo que a interface de saída gerenciada pelo ponto de conexão.

*PDW*<br/>
fora Um ponteiro para o cookie que identifica exclusivamente a conexão.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O coletor implementa a interface de saída com suporte do ponto de conexão. O cliente usa o cookie *PDW* para remover a conexão passando-a para [AtlUnadvise](#atlunadvise).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#91](../../atl/codesnippet/cpp/connection-point-global-functions_1.cpp)]

##  <a name="atlunadvise"></a>AtlUnadvise

Encerra a conexão estabelecida por meio de [AtlAdvise](#atladvise).

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
HRESULT    AtlUnadvise(
    IUnknown* pUnkCP,
    const IID& iid,
    DWORD dw);
```

### <a name="parameters"></a>parâmetros

*pUnkCP*<br/>
no Um ponteiro para a `IUnknown` do objeto ao qual o cliente está conectado.

*IID*<br/>
no O GUID do ponto de conexão. Normalmente, isso é o mesmo que a interface de saída gerenciada pelo ponto de conexão.

*dw*<br/>
no O cookie que identifica exclusivamente a conexão.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#96](../../atl/codesnippet/cpp/connection-point-global-functions_2.cpp)]

##  <a name="atladvisesinkmap"></a>AtlAdviseSinkMap

Chame essa função para recomendar ou não recomendar todas as entradas no mapa de eventos do coletor do objeto.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
HRESULT AtlAdviseSinkMap(T* pT, bool bAdvise);
```

### <a name="parameters"></a>parâmetros

*pT*<br/>
no Um ponteiro para o objeto que contém o mapa do coletor.

*bAdvise*<br/>
no TRUE se todas as entradas do coletor forem recomendadas; FALSE se todas as entradas do coletor forem desaconselhadas.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#92](../../atl/codesnippet/cpp/connection-point-global-functions_3.h)]

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)<br/>
[Macros de ponto de conexão](../../atl/reference/connection-point-macros.md)
