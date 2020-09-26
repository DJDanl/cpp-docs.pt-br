---
title: Interface IAxWinAmbientDispatchEx
ms.date: 11/04/2016
f1_keywords:
- IAxWinAmbientDispatchEx
- ATLIFACE/ATL::IAxWinAmbientDispatchEx
- ATLIFACE/ATL::SetAmbientDispatch
helpviewer_keywords:
- IAxWinAmbientDispatchEx interface
ms.assetid: 2c25e079-6128-4278-bc72-b2c6195ba7ef
ms.openlocfilehash: 3359c17996eb78c3249abc83ff2d439381f209fe
ms.sourcegitcommit: d9c94dcabd94537e304be0261b3263c2071b437b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2020
ms.locfileid: "91352980"
---
# <a name="iaxwinambientdispatchex-interface"></a>Interface IAxWinAmbientDispatchEx

Essa interface implementa propriedades de ambiente suplementares para um controle hospedado.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
MIDL_INTERFACE("B2D0778B - AC99 - 4c58 - A5C8 - E7724E5316B5") IAxWinAmbientDispatchEx : public IAxWinAmbientDispatch
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|Nome|Descrição|
|-|-|
|[SetAmbientDispatch](#setambientdispatch)|Esse método é chamado para complementar a interface de propriedade de ambiente padrão com uma interface definida pelo usuário.|

## <a name="remarks"></a>Comentários

Inclua essa interface em aplicativos ATL que são estaticamente vinculados a controles ActiveX ATL e host, especialmente controles ActiveX que têm propriedades de ambiente. Não incluir essa interface gerará esta asserção: "você se esqueceu de passar o LIBID para CComModule:: init"

Essa interface é exposta pelos objetos de hospedagem do controle ActiveX da ATL. Derivado de [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md), `IAxWinAmbientDispatchEx` adiciona um método que permite complementar a interface de propriedade de ambiente fornecida pela ATL com uma de suas próprias.

<xref:System.Windows.Forms.AxHost> tentará carregar informações de tipo sobre `IAxWinAmbientDispatch` e `IAxWinAmbientDispatchEx` da biblioteca de tipos que contém o código.

Se você estiver vinculando a ATL90.dll, **AxHost** carregará as informações de tipo da biblioteca de tipos na dll.

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/atl-control-containment-faq.md#hosting-activex-controls-using-atl-axhost) para obter mais detalhes.

## <a name="requirements"></a>Requisitos

A definição dessa interface está disponível em vários formatos, conforme mostrado na tabela a seguir.

|Tipo de definição|Arquivo|
|---------------------|----------|
|INSERI|atliface. idl|
|Biblioteca de tipos|ATL.dll|
|C++|atliface. h (também incluído em ATLBase. h)|

## <a name="iaxwinambientdispatchexsetambientdispatch"></a><a name="setambientdispatch"></a> IAxWinAmbientDispatchEx::SetAmbientDispatch

Esse método é chamado para complementar a interface de propriedade de ambiente padrão com uma interface definida pelo usuário.

```
virtual HRESULT STDMETHODCALLTYPE SetAmbientDispatch(IDispatch* pDispatch) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDispatch*<br/>
Ponteiro para a nova interface.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Quando `SetAmbientDispatch` é chamado com um ponteiro para uma nova interface, essa nova interface será usada para invocar quaisquer propriedades ou métodos solicitados pelo controle hospedado, se essas propriedades ainda não forem fornecidas pelo [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md).

## <a name="see-also"></a>Confira também

[Interface IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)
