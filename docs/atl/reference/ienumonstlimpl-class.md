---
title: Classe IEnumONSTLImpl
ms.date: 11/04/2016
f1_keywords:
- IEnumOnSTLImpl
- ATLCOM/ATL::IEnumOnSTLImpl
- ATLCOM/ATL::IEnumOnSTLImpl::Clone
- ATLCOM/ATL::IEnumOnSTLImpl::Init
- ATLCOM/ATL::IEnumOnSTLImpl::Next
- ATLCOM/ATL::IEnumOnSTLImpl::Reset
- ATLCOM/ATL::IEnumOnSTLImpl::Skip
- ATLCOM/ATL::IEnumOnSTLImpl::m_iter
- ATLCOM/ATL::IEnumOnSTLImpl::m_pcollection
- ATLCOM/ATL::IEnumOnSTLImpl::m_spUnk
helpviewer_keywords:
- IEnumOnSTLImpl class
ms.assetid: 1789e77b-88b8-447d-a490-806b918912ce
ms.openlocfilehash: 2fbe6ccfbea2836c42a054da7ea9ebeac4e1555d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329706"
---
# <a name="ienumonstlimpl-class"></a>Classe IEnumONSTLImpl

Esta classe define uma interface enumeradora baseada em uma coleção c++ Standard Library.

## <a name="syntax"></a>Sintaxe

```
template <class Base,
    const IID* piid, class T, class Copy, class CollType>
class ATL_NO_VTABLE IEnumOnSTLImpl : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base*<br/>
Um enumerador COM. Consulte [IEnumString](/windows/win32/api/objidl/nn-objidl-ienumstring) como exemplo.

*Piid*<br/>
Um ponteiro para o ID de interface da interface do enumerador.

*T*<br/>
O tipo de item exposto pela interface do enumerador.

*Cópia*<br/>
Uma [aula de política de cópia.](../../atl/atl-copy-policy-classes.md)

*CollType*<br/>
Uma classe de contêiner C++ Standard Library.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IEnumONSTLImpl::Clone](#clone)|A implementação do **Clone.**|
|[IEnumONSTLImpl::Init](#init)|Inicializa o enumerador.|
|[IEnumONSTLImpl:::Próximo](#next)|A implementação do **Next**.|
|[IEnumONSTLImpl::Reset](#reset)|A implementação do **Reset**.|
|[IEnumONSTLImpl::Skip](#skip)|A implementação de **Skip**.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[iEnumONSTLImpl::m_iter](#m_iter)|O iterador que representa a posição atual do enumerador dentro da coleção.|
|[iEnumONSTLImpl::m_pcollection](#m_pcollection)|Um ponteiro para o contêiner C++ Standard Library que mantém os itens a serem enumerados.|
|[iEnumONSTLImpl::m_spUnk](#m_spunk)|O `IUnknown` ponteiro do objeto que fornece a coleção.|

## <a name="remarks"></a>Comentários

`IEnumOnSTLImpl`fornece a implementação para uma interface de enumerador COM onde os itens que estão sendo enumerados são armazenados em um contêiner compatível com c++ Standard Library. Esta classe é análoga à classe [CComEnumImpl,](../../atl/reference/ccomenumimpl-class.md) que fornece uma implementação para uma interface enumerador baseada em uma matriz.

> [!NOTE]
> Consulte [CComEnumImpl::Init](../../atl/reference/ccomenumimpl-class.md#init) para obter `CComEnumImpl` detalhes sobre mais diferenças entre e `IEnumOnSTLImpl`.

Normalmente, você *não* precisará criar sua própria classe de enumeradores, derivando dessa implementação de interface. Se você quiser usar um enumerador fornecido pela ATL com base em um contêiner C++ Standard Library, é mais comum criar uma instância de [CComEnumOnSTL,](../../atl/reference/ccomenumonstl-class.md)ou criar uma classe de coleta que retorne um enumerador derivando do [ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md).

No entanto, se você precisar fornecer um enumerador personalizado (por exemplo, um que exponha interfaces além da interface enumerador), você pode derivar dessa classe. Nesta situação, é provável que você precise substituir o método [Clone](#clone) para fornecer sua própria implementação.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`IEnumOnSTLImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ienumonstlimplinit"></a><a name="init"></a>IEnumONSTLImpl::Init

Inicializa o enumerador.

```
HRESULT Init(
    IUnknown* pUnkForRelease,
    CollType& collection);
```

### <a name="parameters"></a>Parâmetros

*Punkforrelease*<br/>
[em] O `IUnknown` ponteiro de um objeto que deve ser mantido vivo durante a vida do enumerador. Passe NULA SE tal objeto não existir.

*Coleção*<br/>
Uma referência ao contêiner C++ Standard Library que mantém os itens a serem enumerados.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se você `Init` passar uma referência a uma coleção mantida em outro objeto, você pode usar o parâmetro *pUnkForRelease* para garantir que o objeto, e a coleção que ele contém, esteja disponível enquanto o enumerador precisar dele.

Você deve chamar este método antes de passar um ponteiro para a interface do enumerador de volta para qualquer cliente.

## <a name="ienumonstlimplclone"></a><a name="clone"></a>IEnumONSTLImpl::Clone

Este método fornece a **Clone** implementação do método `CComEnumOnSTL`Clone criando um objeto de tipo, iniciando-o com a mesma coleção e iterator usado pelo objeto atual e retornando a interface no objeto recém-criado.

```
STDMETHOD(Clone)(Base** ppEnum);
```

### <a name="parameters"></a>Parâmetros

*Ppenum*<br/>
[fora] A interface enumeradora em um objeto recém-criado clonado do enumerador atual.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ienumonstlimplm_spunk"></a><a name="m_spunk"></a>iEnumONSTLImpl::m_spUnk

O `IUnknown` ponteiro do objeto que fornece a coleção.

```
CComPtr<IUnknown> m_spUnk;
```

### <a name="remarks"></a>Comentários

Este ponteiro inteligente mantém uma referência sobre o objeto passado para [IEnumOnSTLImpl::Init](#init), garantindo que ele permaneça vivo durante a vida do enumerador.

## <a name="ienumonstlimplm_pcollection"></a><a name="m_pcollection"></a>iEnumONSTLImpl::m_pcollection

Este membro aponta para a coleta que fornece os dados que impulsionam a implementação da interface enumerador.

```
CollType* m_pcollection;
```

### <a name="remarks"></a>Comentários

Este membro é inicializado por uma chamada para [IEnumOnSTLImpl::Init](#init).

## <a name="ienumonstlimplm_iter"></a><a name="m_iter"></a>iEnumONSTLImpl::m_iter

Este membro detém o iterador usado para marcar a posição atual dentro da coleção e navegar para elementos subseqüentes.

```
CollType::iterator m_iter;
```

## <a name="ienumonstlimplnext"></a><a name="next"></a>IEnumONSTLImpl:::Próximo

Este método fornece a implementação do método **Next.**

```
STDMETHOD(Next)(
    ULONG celt,
    T* rgelt,
    ULONG* pceltFetched);
```

### <a name="parameters"></a>Parâmetros

*Celt*<br/>
[em] O número de elementos solicitados.

*Rgelt*<br/>
[fora] A matriz a ser preenchida com os elementos.

*pceltFetched*<br/>
[fora] O número de elementos realmente retornou em *rgelt*. Isso pode ser menor que *celt* se menos elementos *celt* permanecerem na lista.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ienumonstlimplreset"></a><a name="reset"></a>IEnumONSTLImpl::Reset

Este método fornece a implementação do método **Reset.**

```
STDMETHOD(Reset)(void);
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ienumonstlimplskip"></a><a name="skip"></a>IEnumONSTLImpl::Skip

Este método fornece a implementação do método **Skip.**

```
STDMETHOD(Skip)(ULONG celt);
```

### <a name="parameters"></a>Parâmetros

*Celt*<br/>
[em] O número de elementos a serem pulados.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
