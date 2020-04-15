---
title: Classe ISupportErrorInfoImpl
ms.date: 06/13/2019
f1_keywords:
- ISupportErrorInfoImpl
- ATLCOM/ATL::ISupportErrorInfoImpl
- ATLCOM/ATL::ISupportErrorInfoImpl::InterfaceSupportsErrorInfo
helpviewer_keywords:
- ISupportErrorInfo ATL implementation
- ISupportErrorInfoImpl class
- error information, ATL
ms.assetid: e33a4b11-a123-41cf-bcea-7b19743902af
ms.openlocfilehash: 4c60b58ba697f00b146077a2cdecd727fe2cac02
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326373"
---
# <a name="isupporterrorinfoimpl-class"></a>Classe ISupportErrorInfoImpl

Essa classe fornece uma implementação padrão da [Interface ISupportErrorInfo](/windows/win32/api/oaidl/nn-oaidl-isupporterrorinfo) e pode ser usada quando apenas uma única interface gera erros em um objeto.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```cpp
template<const IID* piid>
class ATL_NO_VTABLE ISupportErrorInfoImpl
   : public ISupportErrorInfo
```

### <a name="parameters"></a>Parâmetros

*Piid*<br/>
Um ponteiro para o IID de uma interface que suporta [IErrorInfo](/windows/win32/api/oaidl/nn-oaidl-ierrorinfo).

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[ISupportErrorInfoImpl::InterfaceSupportsErrorInfo](#interfacesupportserrorinfo)|Indica se a `riid` interface identificada por suporta a interface [IErrorInfo.](/windows/win32/api/oaidl/nn-oaidl-ierrorinfo)|

## <a name="remarks"></a>Comentários

A [Interface ISupportErrorInfo](/windows/win32/api/oaidl/nn-oaidl-isupporterrorinfo) garante que as informações de erro possam ser devolvidas ao cliente. Objetos `IErrorInfo` que `ISupportErrorInfo`usam devem ser implementados .

A `ISupportErrorInfoImpl` classe fornece `ISupportErrorInfo` uma implementação padrão e pode ser usada quando apenas uma única interface gera erros em um objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#48](../../atl/codesnippet/cpp/isupporterrorinfoimpl-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISupportErrorInfo`

`ISupportErrorInfoImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="isupporterrorinfoimplinterfacesupportserrorinfo"></a><a name="interfacesupportserrorinfo"></a>ISupportErrorInfoImpl::InterfaceSupportsErrorInfo

Indica se a `riid` interface identificada por suporta a interface [IErrorInfo.](/windows/win32/api/oaidl/nn-oaidl-ierrorinfo)

```cpp
STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
```

### <a name="remarks"></a>Comentários

Consulte [ISupportErrorInfo::InterfaceSupportsErrorInfo](/windows/win32/api/oaidl/nf-oaidl-isupporterrorinfo-interfacesupportserrorinfo) no Windows SDK.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
