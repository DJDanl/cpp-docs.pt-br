---
title: Classe CComEnumImpl
ms.date: 11/04/2016
f1_keywords:
- CComEnumImpl
- ATLCOM/ATL::CComEnumImpl
- ATLCOM/ATL::CComEnumImpl::CComEnumImpl
- ATLCOM/ATL::CComEnumImpl::Clone
- ATLCOM/ATL::CComEnumImpl::Init
- ATLCOM/ATL::CComEnumImpl::Next
- ATLCOM/ATL::CComEnumImpl::Reset
- ATLCOM/ATL::CComEnumImpl::Skip
- ATLCOM/ATL::CComEnumImpl::m_begin
- ATLCOM/ATL::CComEnumImpl::m_dwFlags
- ATLCOM/ATL::CComEnumImpl::m_end
- ATLCOM/ATL::CComEnumImpl::m_iter
- ATLCOM/ATL::CComEnumImpl::m_spUnk
helpviewer_keywords:
- CComEnumImpl class
ms.assetid: cc0d8e76-e608-46db-87cd-4c7161fe32d2
ms.openlocfilehash: 965e0a8bf6c890882754b60e2785832933d1c52c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327859"
---
# <a name="ccomenumimpl-class"></a>Classe CComEnumImpl

Esta classe fornece a implementação para uma interface de enumerador COM onde os itens que estão sendo enumerados são armazenados em uma matriz.

## <a name="syntax"></a>Sintaxe

```
template <class Base,
    const IID* piid, class T, class Copy>
class ATL_NO_VTABLE CComEnumImpl : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base*<br/>
Uma interface de enumerador COM. Consulte [IEnumString](/windows/win32/api/objidl/nn-objidl-ienumstring) como exemplo.

*Piid*<br/>
Um ponteiro para o ID de interface da interface do enumerador.

*T*<br/>
O tipo de item exposto pela interface do enumerador.

*Cópia*<br/>
Uma [classe de política](../../atl/atl-copy-policy-classes.md)de cópia homogênea.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComEnumImpl::CComEnumImpl](#ccomenumimpl)|O construtor.|
|[CComEnumImpl::~CComEnumImpl](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComEnumImpl::Clone](#clone)|A implementação do método de interface de enumeração **Clone.**|
|[CComEnumImpl::Init](#init)|Inicializa o enumerador.|
|[CComEnumImpl:::Próximo](#next)|A implementação do **Next**.|
|[CComEnumImpl::Reset](#reset)|A implementação do **Reset**.|
|[CComEnumImpl::Skip](#skip)|A implementação de **Skip**.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComEnumImpl::m_begin](#m_begin)|Um ponteiro para o primeiro item na matriz.|
|[CComEnumImpl::m_dwFlags](#m_dwflags)|Bandeiras de `Init`cópia passaram.|
|[CComEnumImpl::m_end](#m_end)|Um ponteiro para o local logo após o último item na matriz.|
|[CComEnumImpl::m_iter](#m_iter)|Um ponteiro para o item atual na matriz.|
|[CComEnumImpl::m_spUnk](#m_spunk)|O `IUnknown` ponteiro do objeto que fornece a coleção está sendo enumerado.|

## <a name="remarks"></a>Comentários

Consulte [IEnumString](/windows/win32/api/objidl/nn-objidl-ienumstring) para obter um exemplo de implementações de métodos. `CComEnumImpl`fornece a implementação de uma interface de enumerador COM onde os itens que estão sendo enumerados são armazenados em uma matriz. Esta classe é análoga à `IEnumOnSTLImpl` classe, que fornece uma implementação de uma interface enumerador baseada em um contêiner C++ Standard Library.

> [!NOTE]
> Para obter mais `CComEnumImpl` detalhes sobre as diferenças entre e `IEnumOnSTLImpl`, consulte [CComEnumImpl::Init](#init).

Normalmente, você *não* precisará criar sua própria classe de enumeradores, derivando dessa implementação de interface. Se você quiser usar um enumerador fornecido pela ATL com base em uma matriz, é mais comum criar uma instância de [CComEnum](../../atl/reference/ccomenum-class.md).

No entanto, se você precisar fornecer um enumerador personalizado (por exemplo, um que exponha interfaces além da interface enumerador), você pode derivar dessa classe. Nesta situação, é provável que você precise substituir o método [CComEnumImpl::Clone](#clone) para fornecer sua própria implementação.

Para obter mais informações, consulte [ATL Collections and Enumerators](../../atl/atl-collections-and-enumerators.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComEnumImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomenumimplccomenumimpl"></a><a name="ccomenumimpl"></a>CComEnumImpl::CComEnumImpl

O construtor.

```
CComEnumImpl();
```

## <a name="ccomenumimplccomenumimpl"></a><a name="dtor"></a>CComEnumImpl::~CComEnumImpl

O destruidor.

```
~CComEnumImpl();
```

## <a name="ccomenumimplinit"></a><a name="init"></a>CComEnumImpl::Init

Você deve chamar este método antes de passar um ponteiro para a interface do enumerador de volta para qualquer cliente.

```
HRESULT Init(
    T* begin,
    T* end,
    IUnknown* pUnk,
    CComEnumFlags flags = AtlFlagNoCopy);
```

### <a name="parameters"></a>Parâmetros

*Começar*<br/>
Um ponteiro para o primeiro elemento da matriz contendo os itens a serem enumerados.

*end*<br/>
Um ponteiro para o local logo após o último elemento da matriz contendo os itens a serem enumerados.

*Punk*<br/>
[em] O `IUnknown` ponteiro de um objeto que deve ser mantido vivo durante a vida do enumerador. Passe NULA SE tal objeto não existir.

*Sinalizadores*<br/>
Sinalizadores especificando se o enumerador deve ou não tomar posse da matriz ou fazer uma cópia dela. Os valores possíveis são descritos abaixo.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Só chame esse método uma vez - inicialize o enumerador, use-o e depois jogue fora.

Se você passar ponteiros para itens em uma matriz mantida em outro objeto (e você não pedir ao enumerador para copiar os dados), você pode usar o parâmetro *pUnk* para garantir que o objeto e a matriz que ele contém estejam disponíveis enquanto o enumerador precisar deles. O enumerador simplesmente mantém uma referência COM no objeto para mantê-lo vivo. A referência COM é liberada automaticamente quando o enumerador é destruído.

O parâmetro *flags* permite especificar como o enumerador deve tratar os elementos da matriz passados a ele. *bandeiras* podem pegar um `CComEnumFlags` dos valores da enumeração mostrada abaixo:

```
enum CComEnumFlags
   {
   AtlFlagNoCopy = 0,
   AtlFlagTakeOwnership = 2, // BitOwn
   AtlFlagCopy = 3           // BitOwn | BitCopy
   };
```

`AtlFlagNoCopy`significa que a vida útil da matriz não é controlada pelo enumerador. Neste caso, ou a matriz será estática ou o objeto identificado pelo *pUnk* será responsável por liberar a matriz quando ela não for mais necessária.

`AtlFlagTakeOwnership`significa que a destruição da matriz deve ser controlada pelo enumerador. Neste caso, a matriz deve ter sido alocada dinamicamente usando **novo**. O enumerador excluirá a matriz em seu destructor. Normalmente, você passaria NULL para *pUnk,* embora você ainda possa passar um ponteiro válido se você precisar ser notificado da destruição do enumerador por algum motivo.

`AtlFlagCopy`significa que uma nova matriz deve ser criada copiando a matriz passada para `Init`. A vida útil da nova matriz deve ser controlada pelo enumerador. O enumerador excluirá a matriz em seu destructor. Normalmente, você passaria NULL para *pUnk,* embora você ainda possa passar um ponteiro válido se você precisar ser notificado da destruição do enumerador por algum motivo.

> [!NOTE]
> O protótipo deste método especifica os elementos `T`da `T` matriz como sendo de tipo, onde foi definido como um parâmetro de modelo para a classe. Este é o mesmo tipo que é exposto por meio do método de interface COM [CComEnumImpl:::Next](#next). A implicação disso é que, ao contrário do [IEnumOnSTLImpl,](../../atl/reference/ienumonstlimpl-class.md)esta classe não suporta diferentes tipos de dados de armazenamento e expostos. O tipo de dados dos elementos no array deve ser o mesmo que o tipo de dados exposto por meio da interface COM.

## <a name="ccomenumimplclone"></a><a name="clone"></a>CComEnumImpl::Clone

Este método fornece a **Clone** implementação do método `CComEnum`Clone criando um objeto de tipo, iniciando-o com o mesmo array e iterator usado pelo objeto atual e retornando a interface no objeto recém-criado.

```
STDMETHOD(Clone)(Base** ppEnum);
```

### <a name="parameters"></a>Parâmetros

*Ppenum*<br/>
[fora] A interface enumeradora em um objeto recém-criado clonado do enumerador atual.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Observe que os enumeradores clonados nunca fazem sua própria cópia (ou tomam posse) dos dados usados pelo enumerador original. Se necessário, os enumeradores clonados manterão o enumerador original vivo (usando uma referência COM) para garantir que os dados estejam disponíveis pelo tempo que precisarem.

## <a name="ccomenumimplm_spunk"></a><a name="m_spunk"></a>CComEnumImpl::m_spUnk

Este ponteiro inteligente mantém uma referência sobre o objeto passado para [CComEnumImpl::Init](#init), garantindo que ele permaneça vivo durante a vida do enumerador.

```
CComPtr<IUnknown> m_spUnk;
```

## <a name="ccomenumimplm_begin"></a><a name="m_begin"></a>CComEnumImpl::m_begin

Um ponteiro para o local logo após o último elemento da matriz contendo os itens a serem enumerados.

```
T* m_begin;
```

## <a name="ccomenumimplm_end"></a><a name="m_end"></a>CComEnumImpl::m_end

Um ponteiro para o primeiro elemento da matriz contendo os itens a serem enumerados.

```
T* m_end;
```

## <a name="ccomenumimplm_iter"></a><a name="m_iter"></a>CComEnumImpl::m_iter

Um ponteiro para o elemento atual da matriz contendo os itens a serem enumerados.

```
T* m_iter;
```

## <a name="ccomenumimplm_dwflags"></a><a name="m_dwflags"></a>CComEnumImpl::m_dwFlags

As bandeiras passaram para [CComEnumImpl::Init](#init).

```
DWORD m_dwFlags;
```

## <a name="ccomenumimplnext"></a><a name="next"></a>CComEnumImpl:::Próximo

Este método fornece a implementação do método **Next.**

```
STDMETHOD(Next)(ULONG celt, T* rgelt, ULONG* pceltFetched);
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

## <a name="ccomenumimplreset"></a><a name="reset"></a>CComEnumImpl::Reset

Este método fornece a implementação do método **Reset.**

```
STDMETHOD(Reset)(void);
```

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ccomenumimplskip"></a><a name="skip"></a>CComEnumImpl::Skip

Este método fornece a implementação do método **Skip.**

```
STDMETHOD(Skip)(ULONG celt);
```

### <a name="parameters"></a>Parâmetros

*Celt*<br/>
[em] O número de elementos a serem pulados.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Retorna E_INVALIDARG se *celt* for zero, retorna S_FALSE se menos que elementos *celt* são devolvidos, retorna S_OK contrário.

## <a name="see-also"></a>Confira também

[Classe IEnumONSTLImpl](../../atl/reference/ienumonstlimpl-class.md)<br/>
[Classe CComEnum](../../atl/reference/ccomenum-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
