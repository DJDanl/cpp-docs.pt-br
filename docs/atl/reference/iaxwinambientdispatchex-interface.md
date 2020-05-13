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
ms.openlocfilehash: f4816846801e388619db62998ec979a1100916ee
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329986"
---
# <a name="iaxwinambientdispatchex-interface"></a>IAxWinAmbientDispatchEx Interface

Esta interface implementa propriedades ambientais suplementares para um controle hospedado.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
MIDL_INTERFACE("B2D0778B - AC99 - 4c58 - A5C8 - E7724E5316B5") IAxWinAmbientDispatchEx : public IAxWinAmbientDispatch
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Definir Despacho ambiente](#setambientdispatch)|Este método é chamado para complementar a interface de propriedade ambiente padrão com uma interface definida pelo usuário.|

## <a name="remarks"></a>Comentários

Inclua essa interface em aplicativos ATL que estão estáticamente ligados ao ATL e aos controles ActiveX host, especialmente os Controles ActiveX que possuem Propriedades Ambientais. Não incluir essa interface gerará essa afirmação: "Você esqueceu de passar o LIBID para CComModule::Init"

Esta interface é exposta pelos objetos de hospedagem de controle ActiveX da ATL. Derivado do [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md), `IAxWinAmbientDispatchEx` adiciona um método que permite complementar a interface de propriedade ambiente fornecida pela ATL com um dos seus.

<xref:System.Windows.Forms.AxHost>tentará carregar informações `IAxWinAmbientDispatch` de `IAxWinAmbientDispatchEx` tipo sobre e da biblioteca do tipo que contém o código.

Se você estiver vinculando ao ATL90.dll, **o AXHost** carregará as informações do tipo da biblioteca do tipo na DLL.

Consulte [Host ActiveX Controls Usando atl AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter mais detalhes.

## <a name="requirements"></a>Requisitos

A definição desta interface está disponível em uma série de formulários, como mostrado na tabela a seguir.

|Tipo de definição|Arquivo|
|---------------------|----------|
|Idl|atliface.idl|
|Biblioteca de tipos|ATL.dll|
|C++|atliface.h (também incluído no ATLBase.h)|

## <a name="iaxwinambientdispatchexsetambientdispatch"></a><a name="setambientdispatch"></a>IAxWinAmbientDispatchEx::SetAmbientDispatch

Este método é chamado para complementar a interface de propriedade ambiente padrão com uma interface definida pelo usuário.

```
virtual HRESULT STDMETHODCALLTYPE SetAmbientDispatch(IDispatch* pDispatch) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDispatch*<br/>
Ponteiro para a nova interface.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Quando `SetAmbientDispatch` é chamado com um ponteiro para uma nova interface, esta nova interface será usada para invocar quaisquer propriedades ou métodos solicitados pelo controle hospedado, se essas propriedades ainda não estiverem fornecidas pelo [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md).

## <a name="see-also"></a>Confira também

[IAxWinAmbientDispatch Interface](../../atl/reference/iaxwinambientdispatch-interface.md)
