---
title: Funções globais do ponto de conexão
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlAdvise
- atlbase/ATL::AtlUnadvise
- atlbase/ATL::AtlAdviseSinkMap
helpviewer_keywords:
- connection points [C++], global functions
ms.assetid: bcb4bf50-2155-4e20-b8bb-f2908b03a6e7
ms.openlocfilehash: 6474297f8b9adf04541f7d232fb88d5e52d4e88c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81331524"
---
# <a name="connection-point-global-functions"></a>Funções globais do ponto de conexão

Essas funções fornecem suporte para pontos de conexão e mapas de afundamento.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no Tempo de execução do Windows.

|||
|-|-|
|[AtlAdvise](#atladvise)|Cria uma conexão entre o ponto de conexão de um objeto e o coletor de um cliente.|
|[AtlUnadvise](#atlunadvise)|Termina a conexão `AtlAdvise`estabelecida através de .|
|[AtlAdviseSinkMap](#atladvisesinkmap)|Aconselha ou desaconselha entradas em um mapa de dissipação de eventos.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="atladvise"></a><a name="atladvise"></a>Atladvise

Cria uma conexão entre o ponto de conexão de um objeto e o coletor de um cliente.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
HRESULT    AtlAdvise(
    IUnknown* pUnkCP,
    IUnknown* pUnk,
    const IID& iid,
    LPDWORD pdw);
```

### <a name="parameters"></a>Parâmetros

*pUnkCP*<br/>
[em] Um ponteiro `IUnknown` para o objeto com o que o cliente deseja conectar.

*Punk*<br/>
[em] Um ponteiro para o `IUnknown`cliente.

*Iid*<br/>
[em] O GUID do ponto de conexão. Normalmente, isso é o mesmo que a interface de saída gerenciada pelo ponto de conexão.

*Pdw*<br/>
[fora] Um ponteiro para o cookie que identifica exclusivamente a conexão.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O dissipador implementa a interface de saída suportada pelo ponto de conexão. O cliente usa o biscoito *pdw* para remover a conexão passando-a para [atlUnadvise](#atlunadvise).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#91](../../atl/codesnippet/cpp/connection-point-global-functions_1.cpp)]

## <a name="atlunadvise"></a><a name="atlunadvise"></a>Atlunadvise

Termina a conexão estabelecida através [do AtlAdvise](#atladvise).

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
HRESULT    AtlUnadvise(
    IUnknown* pUnkCP,
    const IID& iid,
    DWORD dw);
```

### <a name="parameters"></a>Parâmetros

*pUnkCP*<br/>
[em] Um ponteiro `IUnknown` para o objeto com o que o cliente está conectado.

*Iid*<br/>
[em] O GUID do ponto de conexão. Normalmente, isso é o mesmo que a interface de saída gerenciada pelo ponto de conexão.

*dw*<br/>
[em] O cookie que identifica exclusivamente a conexão.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#96](../../atl/codesnippet/cpp/connection-point-global-functions_2.cpp)]

## <a name="atladvisesinkmap"></a><a name="atladvisesinkmap"></a>AtlAdviseSinkMap

Chame essa função para recomendar ou não recomendar todas as entradas no mapa de eventos do coletor do objeto.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
HRESULT AtlAdviseSinkMap(T* pT, bool bAdvise);
```

### <a name="parameters"></a>Parâmetros

*pT*<br/>
[em] Um ponteiro para o objeto que contém o mapa da pia.

*bAconselhar*<br/>
[em] VERDADE se todas as entradas da pia forem aconselhadas; FALSO se todas as entradas da pia forem desaconselhadas.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#92](../../atl/codesnippet/cpp/connection-point-global-functions_3.h)]

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)<br/>
[Macros de ponto de conexão](../../atl/reference/connection-point-macros.md)
