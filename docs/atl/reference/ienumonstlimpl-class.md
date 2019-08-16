---
title: Classe IEnumOnSTLImpl
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
ms.openlocfilehash: 7cf777f3ff0d298f224157735a06bf57a2c10cf5
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495867"
---
# <a name="ienumonstlimpl-class"></a>Classe IEnumOnSTLImpl

Essa classe define uma interface de enumerador com C++ base em uma coleção de bibliotecas padrão.

## <a name="syntax"></a>Sintaxe

```
template <class Base,
    const IID* piid, class T, class Copy, class CollType>
class ATL_NO_VTABLE IEnumOnSTLImpl : public Base
```

#### <a name="parameters"></a>Parâmetros

*Polybase*<br/>
Um enumerador COM. Consulte [IEnumString](/windows/win32/api/objidl/nn-objidl-ienumstring) para obter um exemplo.

*piid*<br/>
Um ponteiro para a ID de interface da interface do enumerador.

*T*<br/>
O tipo de item exposto pela interface do enumerador.

*Copiar*<br/>
Uma [classe de política de cópia](../../atl/atl-copy-policy-classes.md).

*CollType*<br/>
Uma C++ classe de contêiner de biblioteca padrão.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IEnumOnSTLImpl::Clone](#clone)|A implementação do **clone**.|
|[IEnumOnSTLImpl::Init](#init)|Inicializa o enumerador.|
|[IEnumOnSTLImpl::Next](#next)|A implementação de **Next**.|
|[IEnumOnSTLImpl::Reset](#reset)|A implementação da **redefinição**.|
|[IEnumOnSTLImpl::Skip](#skip)|A implementação de **Skip**.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[IEnumOnSTLImpl::m_iter](#m_iter)|O iterador que representa a posição atual do enumerador dentro da coleção.|
|[IEnumOnSTLImpl::m_pcollection](#m_pcollection)|Um ponteiro para o C++ contêiner da biblioteca padrão que contém os itens a serem enumerados.|
|[IEnumOnSTLImpl::m_spUnk](#m_spunk)|O `IUnknown` ponteiro do objeto que fornece a coleção.|

## <a name="remarks"></a>Comentários

`IEnumOnSTLImpl`fornece a implementação para uma interface de enumerador COM em que os itens que estão sendo enumerados são armazenados em um C++ contêiner padrão compatível com biblioteca. Essa classe é análoga à classe [CComEnumImpl](../../atl/reference/ccomenumimpl-class.md) , que fornece uma implementação para uma interface de enumerador baseada em uma matriz.

> [!NOTE]
>  Consulte [CComEnumImpl:: init](../../atl/reference/ccomenumimpl-class.md#init) para obter detalhes sobre outras diferenças `CComEnumImpl` entre `IEnumOnSTLImpl`e.

Normalmente, *não* será necessário criar sua própria classe de enumerador derivando dessa implementação de interface. Se você quiser usar um enumerador fornecido pela ATL com base em C++ um contêiner de biblioteca padrão, é mais comum criar uma instância de [CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md)ou criar uma classe de coleção que retorna um enumerador derivando de [ICollectionOnSTLImpl ](../../atl/reference/icollectiononstlimpl-class.md).

No entanto, se você precisar fornecer um enumerador personalizado (por exemplo, um que expõe interfaces além da interface do enumerador), poderá derivar dessa classe. Nessa situação, é provável que você precise substituir o método [clone](#clone) para fornecer sua própria implementação.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`IEnumOnSTLImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="init"></a>  IEnumOnSTLImpl::Init

Inicializa o enumerador.

```
HRESULT Init(
    IUnknown* pUnkForRelease,
    CollType& collection);
```

### <a name="parameters"></a>Parâmetros

*pUnkForRelease*<br/>
no O `IUnknown` ponteiro de um objeto que deve ser mantido ativo durante o tempo de vida do enumerador. Passe NULL se esse objeto não existir.

*collection*<br/>
Uma referência ao contêiner C++ da biblioteca padrão que contém os itens a serem enumerados.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Se você passar `Init` uma referência a uma coleção mantida em outro objeto, poderá usar o parâmetro *pUnkForRelease* para garantir que o objeto e a coleção que ele contém, estarão disponíveis por enquanto o enumerador precisar.

Você deve chamar esse método antes de passar um ponteiro para a interface do enumerador de volta para qualquer cliente.

##  <a name="clone"></a>  IEnumOnSTLImpl::Clone

Esse método fornece a implementação do método **clone** criando um objeto do tipo `CComEnumOnSTL`, inicializando-o com a mesma coleção e iterador usados pelo objeto atual e retornando a interface no objeto recém-criado.

```
STDMETHOD(Clone)(Base** ppEnum);
```

### <a name="parameters"></a>Parâmetros

*ppEnum*<br/>
fora A interface do enumerador em um objeto recém-criado clonado do enumerador atual.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="m_spunk"></a>  IEnumOnSTLImpl::m_spUnk

O `IUnknown` ponteiro do objeto que fornece a coleção.

```
CComPtr<IUnknown> m_spUnk;
```

### <a name="remarks"></a>Comentários

Esse ponteiro inteligente mantém uma referência no objeto passado para [IEnumOnSTLImpl:: init](#init), garantindo que ele permaneça ativo durante o tempo de vida do enumerador.

##  <a name="m_pcollection"></a>  IEnumOnSTLImpl::m_pcollection

Esse membro aponta para a coleção que fornece os dados que orientam a implementação da interface do enumerador.

```
CollType* m_pcollection;
```

### <a name="remarks"></a>Comentários

Esse membro é inicializado por uma chamada para [IEnumOnSTLImpl:: init](#init).

##  <a name="m_iter"></a>  IEnumOnSTLImpl::m_iter

Esse membro contém o iterador usado para marcar a posição atual dentro da coleção e navegar para os elementos subsequentes.

```
CollType::iterator m_iter;
```

##  <a name="next"></a>  IEnumOnSTLImpl::Next

Esse método fornece a implementação do **próximo** método.

```
STDMETHOD(Next)(
    ULONG celt,
    T* rgelt,
    ULONG* pceltFetched);
```

### <a name="parameters"></a>Parâmetros

*celt*<br/>
no O número de elementos solicitados.

*rgelt*<br/>
fora A matriz a ser preenchida com os elementos.

*pceltFetched*<br/>
fora O número de elementos realmente retornados em *rgelt*. Isso pode ser menor que *celt* se menos de *celt* elementos permanecerem na lista.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="reset"></a>  IEnumOnSTLImpl::Reset

Esse método fornece a implementação do método **Reset** .

```
STDMETHOD(Reset)(void);
```

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="skip"></a>  IEnumOnSTLImpl::Skip

Esse método fornece a implementação do método **Skip** .

```
STDMETHOD(Skip)(ULONG celt);
```

### <a name="parameters"></a>Parâmetros

*celt*<br/>
no O número de elementos a serem ignorados.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
