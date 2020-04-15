---
title: Marshaling Funções Globais
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlFreeMarshalStream
- atlbase/ATL::AtlMarshalPtrInProc
- atlbase/ATL::AtlUnmarshalPtr
ms.assetid: 877100b5-6ad9-44c5-a2e0-09414f1720d0
ms.openlocfilehash: b839e93b6251a09ce79df60a49b4054d1af76cc9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326258"
---
# <a name="marshaling-global-functions"></a>Marshaling Funções Globais

Essas funções fornecem suporte para empacotar e converter dados de empacotamento em ponteiros de interface.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no Tempo de execução do Windows.

|||
|-|-|
|[AtlFreeMarshalStream](#atlfreemarshalstream)|Libera os dados do `IStream` marechal e o ponteiro.|
|[AtlMarshalPtrInProc](#atlmarshalptrinproc)|Cria um novo objeto de fluxo e empacota o ponteiro de interface especificado.|
|[AtlUnmarshalPtr](#atlunmarshalptr)|Converte os dados de empacotamento de um fluxo em um ponteiro de interface.|

## <a name="requirements"></a>Requisitos:

**Cabeçalho:** atlbase.h

## <a name="atlfreemarshalstream"></a><a name="atlfreemarshalstream"></a>AtlFreeMarshalStream

Libera os dados de marshaling no fluxo e depois libera o ponteiro de fluxo.

```
HRESULT AtlFreeMarshalStream(IStream* pStream);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
[em] Um ponteiro `IStream` para a interface no fluxo usado para empacotar.

### <a name="example"></a>Exemplo

Veja o exemplo [de AtlMarshalPtrInProc](#atlmarshalptrinproc).

## <a name="atlmarshalptrinproc"></a><a name="atlmarshalptrinproc"></a>AtlMarshalPtrInProc

Cria um novo objeto de fluxo, grava o CLSID do proxy no fluxo e realiza o marshaling do ponteiro de interface especificado gravando os dados necessários para inicializar o proxy no fluxo.

```
HRESULT AtlMarshalPtrInProc(
    IUnknown* pUnk,
    const IID& iid,
    IStream** ppStream);
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
[em] Um ponteiro para a interface a ser empacotada.

*Iid*<br/>
[em] O GUID da interface que está sendo empacotada.

*ppStream*<br/>
[fora] Um ponteiro `IStream` para a interface no novo objeto de fluxo usado para empacotar.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A bandeira MSHLFLAGS_TABLESTRONG é definida para que o ponteiro possa ser empacotado para vários fluxos. O ponteiro também pode ser desmembrado várias vezes.

Se o marshaling falhar, o ponteiro de fluxo será liberado.

`AtlMarshalPtrInProc`só pode ser usado em um ponteiro para um objeto em processo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#50](../../atl/codesnippet/cpp/marshaling-global-functions_1.cpp)]

## <a name="atlunmarshalptr"></a><a name="atlunmarshalptr"></a>AtlUnmarshalPtr

Converte os dados de marshaling do fluxo em um ponteiro de interface que pode ser usado pelo cliente.

```
HRESULT AtlUnmarshalPtr(
    IStream* pStream,
    const IID& iid,
    IUnknown** ppUnk);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
[em] Um ponteiro para o córrego sendo desmarshaled.

*Iid*<br/>
[em] O GUID da interface sendo desmarshaled.

*ppUnk*<br/>
[fora] Um ponteiro para a interface desmembrada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="example"></a>Exemplo

Veja o exemplo [de AtlMarshalPtrInProc](#atlmarshalptrinproc).

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
