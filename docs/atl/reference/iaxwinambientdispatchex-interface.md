---
title: IAxWinAmbientDispatchEx Interface
ms.date: 11/04/2016
f1_keywords:
- IAxWinAmbientDispatchEx
- ATLIFACE/ATL::IAxWinAmbientDispatchEx
- ATLIFACE/ATL::SetAmbientDispatch
helpviewer_keywords:
- IAxWinAmbientDispatchEx interface
ms.assetid: 2c25e079-6128-4278-bc72-b2c6195ba7ef
ms.openlocfilehash: 638152d8c49bd20742a586bc665efcdb662b6f3a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62276088"
---
# <a name="iaxwinambientdispatchex-interface"></a>IAxWinAmbientDispatchEx Interface

Essa interface implementa propriedades complementares de ambiente para um controle hospedado.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
MIDL_INTERFACE("B2D0778B - AC99 - 4c58 - A5C8 - E7724E5316B5") IAxWinAmbientDispatchEx : public IAxWinAmbientDispatch
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[SetAmbientDispatch](#setambientdispatch)|Esse método é chamado para complementar a interface de propriedade de ambiente padrão com uma interface definida pelo usuário.|

## <a name="remarks"></a>Comentários

Inclua essa interface em aplicativos de ATL que são vinculados estaticamente para ATL e hospedar controles ActiveX, especialmente os controles ActiveX que têm propriedades de ambiente. Não incluindo essa interface gerará essa asserção: "Você esqueceu de passar o LIBID para CComModule"

Essa interface é exposta pelo controle ActiveX do ATL que objetos de hospedagem. Derivado [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md), `IAxWinAmbientDispatchEx` adiciona um método que permite que você complementar a interface de propriedade de ambiente fornecida pelo ATL com um de seus próprios.

<xref:System.Windows.Forms.AxHost> tentará carregar as informações de tipo sobre `IAxWinAmbientDispatch` e `IAxWinAmbientDispatchEx` da biblioteca de tipos que contém o código.

Se você está vinculando ATL90.dll, **AXHost** carregará as informações de tipo na biblioteca de tipos na DLL.

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter mais detalhes.

## <a name="requirements"></a>Requisitos

A definição desta interface está disponível em um número de formulários, conforme mostrado na tabela a seguir.

|Tipo de definição|Arquivo|
|---------------------|----------|
|IDL|atliface.idl|
|Biblioteca de tipos|ATL.dll|
|C++|atliface (também é incluído em atlbase. H)|

##  <a name="setambientdispatch"></a>  IAxWinAmbientDispatchEx::SetAmbientDispatch

Esse método é chamado para complementar a interface de propriedade de ambiente padrão com uma interface definida pelo usuário.

```
virtual HRESULT STDMETHODCALLTYPE SetAmbientDispatch(IDispatch* pDispatch) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDispatch*<br/>
Ponteiro para a nova interface.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Quando `SetAmbientDispatch` é chamado com um ponteiro para uma nova interface, essa nova interface será usado para invocar quaisquer propriedades ou métodos solicitados pelo controle hospedado, se essas propriedades já não são fornecidas pela [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md).

## <a name="see-also"></a>Consulte também

[Interface IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)
