---
title: Marshaling de funções globais
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlFreeMarshalStream
- atlbase/ATL::AtlMarshalPtrInProc
- atlbase/ATL::AtlUnmarshalPtr
ms.assetid: 877100b5-6ad9-44c5-a2e0-09414f1720d0
ms.openlocfilehash: 79b19b613fbae49c0f8338dcadd2225e092fb371
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835318"
---
# <a name="marshaling-global-functions"></a>Marshaling de funções globais

Essas funções fornecem suporte para marshaling e conversão de dados de marshaling em ponteiros de interface.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados no Windows Runtime.

|Nome|Descrição|
|-|-|
|[AtlFreeMarshalStream](#atlfreemarshalstream)|Libera os dados de marshaling e o `IStream` ponteiro.|
|[AtlMarshalPtrInProc](#atlmarshalptrinproc)|Cria um novo objeto de fluxo e realiza marshaling do ponteiro de interface especificado.|
|[AtlUnmarshalPtr](#atlunmarshalptr)|Converte os dados de marshaling de um fluxo em um ponteiro de interface.|

## <a name="requirements"></a>Requisitos:

**Cabeçalho:** atlbase. h

## <a name="atlfreemarshalstream"></a><a name="atlfreemarshalstream"></a> AtlFreeMarshalStream

Libera os dados de marshaling no fluxo e depois libera o ponteiro de fluxo.

```
HRESULT AtlFreeMarshalStream(IStream* pStream);
```

### <a name="parameters"></a>parâmetros

*pStream*<br/>
no Um ponteiro para a `IStream` interface no fluxo usado para marshaling.

### <a name="example"></a>Exemplo

Consulte o exemplo de [AtlMarshalPtrInProc](#atlmarshalptrinproc).

## <a name="atlmarshalptrinproc"></a><a name="atlmarshalptrinproc"></a> AtlMarshalPtrInProc

Cria um novo objeto de fluxo, grava o CLSID do proxy no fluxo e realiza o marshaling do ponteiro de interface especificado gravando os dados necessários para inicializar o proxy no fluxo.

```
HRESULT AtlMarshalPtrInProc(
    IUnknown* pUnk,
    const IID& iid,
    IStream** ppStream);
```

### <a name="parameters"></a>parâmetros

*pUnk*<br/>
no Um ponteiro para a interface a ser empacotada.

*IID*<br/>
no O GUID da interface que está sendo empacotada.

*ppStream*<br/>
fora Um ponteiro para a `IStream` interface no novo objeto de fluxo usado para marshaling.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O sinalizador MSHLFLAGS_TABLESTRONG é definido para que o ponteiro possa ser empacotado para vários fluxos. O ponteiro também pode ser desempacotado várias vezes.

Se o marshaling falhar, o ponteiro de fluxo será liberado.

`AtlMarshalPtrInProc` Só pode ser usado em um ponteiro para um objeto em processo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#50](../../atl/codesnippet/cpp/marshaling-global-functions_1.cpp)]

## <a name="atlunmarshalptr"></a><a name="atlunmarshalptr"></a> AtlUnmarshalPtr

Converte os dados de marshaling do fluxo em um ponteiro de interface que pode ser usado pelo cliente.

```
HRESULT AtlUnmarshalPtr(
    IStream* pStream,
    const IID& iid,
    IUnknown** ppUnk);
```

### <a name="parameters"></a>parâmetros

*pStream*<br/>
no Um ponteiro para o fluxo que está sendo desempacotado.

*IID*<br/>
no O GUID da interface que está sendo desempacotada.

*ppUnk*<br/>
fora Um ponteiro para a interface não empacotada.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="example"></a>Exemplo

Consulte o exemplo de [AtlMarshalPtrInProc](#atlmarshalptrinproc).

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
