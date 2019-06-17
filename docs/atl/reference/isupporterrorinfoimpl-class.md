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
ms.openlocfilehash: 650d90c9ec98754e11586f63e0871b70ebbe34f3
ms.sourcegitcommit: e79188287189b76b34eb7e8fb1bfe646bdb586bc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/14/2019
ms.locfileid: "67141700"
---
# <a name="isupporterrorinfoimpl-class"></a>Classe ISupportErrorInfoImpl

Essa classe fornece uma implementação padrão do [ISupportErrorInfo Interface](/windows/desktop/api/oaidl/nn-oaidl-isupporterrorinfo) e pode ser usada quando somente uma única interface gera erros em um objeto.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```cpp
template<const IID* piid>
class ATL_NO_VTABLE ISupportErrorInfoImpl
   : public ISupportErrorInfo
```

### <a name="parameters"></a>Parâmetros

*piid*<br/>
Um ponteiro para o IID de uma interface que suporta [IErrorInfo](/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo).

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ISupportErrorInfoImpl::InterfaceSupportsErrorInfo](#interfacesupportserrorinfo)|Indica se a interface identificada pelo `riid` oferece suporte a [IErrorInfo](/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo) interface.|

## <a name="remarks"></a>Comentários

O [ISupportErrorInfo Interface](/windows/desktop/api/oaidl/nn-oaidl-isupporterrorinfo) garante que as informações de erro podem ser retornadas ao cliente. Objetos que usam `IErrorInfo` deve implementar `ISupportErrorInfo`.

Classe `ISupportErrorInfoImpl` fornece uma implementação padrão de `ISupportErrorInfo` e pode ser usada quando somente uma única interface gera erros em um objeto. Por exemplo:

[!code-cpp[NVC_ATL_COM#48](../../atl/codesnippet/cpp/isupporterrorinfoimpl-class_1.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISupportErrorInfo`

`ISupportErrorInfoImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="interfacesupportserrorinfo"></a>  ISupportErrorInfoImpl::InterfaceSupportsErrorInfo

Indica se a interface identificada pelo `riid` oferece suporte a [IErrorInfo](/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo) interface.

```cpp
STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
```

### <a name="remarks"></a>Comentários

Ver [ISupportErrorInfo::InterfaceSupportsErrorInfo](/windows/desktop/api/oaidl/nf-oaidl-isupporterrorinfo-interfacesupportserrorinfo) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
