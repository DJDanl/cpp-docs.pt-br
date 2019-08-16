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
ms.openlocfilehash: d5e7f087f6646940777ae8b2d2a4ea888fdd3593
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495372"
---
# <a name="isupporterrorinfoimpl-class"></a>Classe ISupportErrorInfoImpl

Essa classe fornece uma implementação padrão da [interface ISupportErrorInfo](/windows/win32/api/oaidl/nn-oaidl-isupporterrorinfo) e pode ser usada quando apenas uma única interface gera erros em um objeto.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template<const IID* piid>
class ATL_NO_VTABLE ISupportErrorInfoImpl
   : public ISupportErrorInfo
```

### <a name="parameters"></a>Parâmetros

*piid*<br/>
Um ponteiro para o IID de uma interface que dá suporte a [IErrorInfo](/windows/win32/api/oaidl/nn-oaidl-ierrorinfo).

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ISupportErrorInfoImpl::InterfaceSupportsErrorInfo](#interfacesupportserrorinfo)|Indica se a interface identificada `riid` pelo oferece suporte à interface [IErrorInfo](/windows/win32/api/oaidl/nn-oaidl-ierrorinfo) .|

## <a name="remarks"></a>Comentários

A [interface ISupportErrorInfo](/windows/win32/api/oaidl/nn-oaidl-isupporterrorinfo) garante que as informações de erro possam ser retornadas ao cliente. Os objetos que `IErrorInfo` usam o `ISupportErrorInfo`devem implementar.

A `ISupportErrorInfoImpl` classe fornece uma implementação padrão `ISupportErrorInfo` de e pode ser usada quando apenas uma interface gera erros em um objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#48](../../atl/codesnippet/cpp/isupporterrorinfoimpl-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISupportErrorInfo`

`ISupportErrorInfoImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="interfacesupportserrorinfo"></a>  ISupportErrorInfoImpl::InterfaceSupportsErrorInfo

Indica se a interface identificada `riid` pelo oferece suporte à interface [IErrorInfo](/windows/win32/api/oaidl/nn-oaidl-ierrorinfo) .

```cpp
STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
```

### <a name="remarks"></a>Comentários

Consulte [ISupportErrorInfo:: InterfaceSupportsErrorInfo](/windows/win32/api/oaidl/nf-oaidl-isupporterrorinfo-interfacesupportserrorinfo) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
