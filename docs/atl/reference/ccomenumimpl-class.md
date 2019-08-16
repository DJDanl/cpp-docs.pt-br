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
ms.openlocfilehash: 7d26c59a38bfe43e49215fbb6108453e10ca6dea
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497182"
---
# <a name="ccomenumimpl-class"></a>Classe CComEnumImpl

Essa classe fornece a implementação para uma interface de enumerador COM em que os itens que estão sendo enumerados são armazenados em uma matriz.

## <a name="syntax"></a>Sintaxe

```
template <class Base,
    const IID* piid, class T, class Copy>
class ATL_NO_VTABLE CComEnumImpl : public Base
```

#### <a name="parameters"></a>Parâmetros

*Polybase*<br/>
Uma interface de enumerador COM. Consulte [IEnumString](/windows/win32/api/objidl/nn-objidl-ienumstring) para obter um exemplo.

*piid*<br/>
Um ponteiro para a ID de interface da interface do enumerador.

*T*<br/>
O tipo de item exposto pela interface do enumerador.

*Copiar*<br/>
Uma [classe de política de cópia](../../atl/atl-copy-policy-classes.md)homogênea.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComEnumImpl::CComEnumImpl](#ccomenumimpl)|O construtor.|
|[CComEnumImpl:: ~ CComEnumImpl](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComEnumImpl:: clone](#clone)|A implementação do método de interface de enumeração de **clone** .|
|[CComEnumImpl::Init](#init)|Inicializa o enumerador.|
|[CComEnumImpl::Next](#next)|A implementação de **Next**.|
|[CComEnumImpl::Reset](#reset)|A implementação da **redefinição**.|
|[CComEnumImpl::Skip](#skip)|A implementação de **Skip**.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComEnumImpl::m_begin](#m_begin)|Um ponteiro para o primeiro item na matriz.|
|[CComEnumImpl::m_dwFlags](#m_dwflags)|Sinalizadores de cópia passados `Init`.|
|[CComEnumImpl::m_end](#m_end)|Um ponteiro para o local logo após o último item na matriz.|
|[CComEnumImpl::m_iter](#m_iter)|Um ponteiro para o item atual na matriz.|
|[CComEnumImpl::m_spUnk](#m_spunk)|O `IUnknown` ponteiro do objeto que fornece a coleção que está sendo enumerada.|

## <a name="remarks"></a>Comentários

Consulte [IEnumString](/windows/win32/api/objidl/nn-objidl-ienumstring) para obter um exemplo de implementações de método. `CComEnumImpl`fornece a implementação para uma interface de enumerador COM em que os itens que estão sendo enumerados são armazenados em uma matriz. Essa classe é análoga à `IEnumOnSTLImpl` classe, que fornece uma implementação de uma interface de enumerador baseada em um C++ contêiner de biblioteca padrão.

> [!NOTE]
>  Para obter detalhes sobre outras diferenças `CComEnumImpl` entre `IEnumOnSTLImpl`e, consulte [CComEnumImpl:: init](#init).

Normalmente, *não* será necessário criar sua própria classe de enumerador derivando dessa implementação de interface. Se você quiser usar um enumerador fornecido pela ATL com base em uma matriz, será mais comum criar uma instância de [CComEnum](../../atl/reference/ccomenum-class.md).

No entanto, se você precisar fornecer um enumerador personalizado (por exemplo, um que expõe interfaces além da interface do enumerador), poderá derivar dessa classe. Nessa situação, é provável que você precise substituir o método [CComEnumImpl:: clone](#clone) para fornecer sua própria implementação.

Para obter mais informações, consulte [coleções e enumeradores do ATL](../../atl/atl-collections-and-enumerators.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComEnumImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="ccomenumimpl"></a>  CComEnumImpl::CComEnumImpl

O construtor.

```
CComEnumImpl();
```

##  <a name="dtor"></a>CComEnumImpl:: ~ CComEnumImpl

O destruidor.

```
~CComEnumImpl();
```

##  <a name="init"></a>  CComEnumImpl::Init

Você deve chamar esse método antes de passar um ponteiro para a interface do enumerador de volta para qualquer cliente.

```
HRESULT Init(
    T* begin,
    T* end,
    IUnknown* pUnk,
    CComEnumFlags flags = AtlFlagNoCopy);
```

### <a name="parameters"></a>Parâmetros

*begin*<br/>
Um ponteiro para o primeiro elemento da matriz que contém os itens a serem enumerados.

*end*<br/>
Um ponteiro para o local logo após o último elemento da matriz que contém os itens a serem enumerados.

*pUnk*<br/>
no O `IUnknown` ponteiro de um objeto que deve ser mantido ativo durante o tempo de vida do enumerador. Passe NULL se esse objeto não existir.

*flags*<br/>
Sinalizadores que especificam se o enumerador deve ou não assumir a propriedade da matriz ou fazer uma cópia dele. Os valores possíveis são descritos abaixo.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Chame esse método apenas uma vez — inicialize o enumerador, use-o e, em seguida, jogue-o fora.

Se você passar os ponteiros para os itens em uma matriz mantida em outro objeto (e não pedir ao enumerador para copiar os dados), poderá usar o parâmetro *punk* para garantir que o objeto e a matriz que ele contém estejam disponíveis por enquanto o enumerador precisar deles. O enumerador simplesmente mantém uma referência COM no objeto para mantê-lo ativo. A referência COM é liberada automaticamente quando o enumerador é destruído.

O parâmetro *flags* permite que você especifique como o enumerador deve tratar os elementos de matriz passados a ele. os`CComEnumFlags` sinalizadores podem usar um dos valores da enumeração mostrada abaixo:

```
enum CComEnumFlags
   {
   AtlFlagNoCopy = 0,
   AtlFlagTakeOwnership = 2, // BitOwn
   AtlFlagCopy = 3           // BitOwn | BitCopy
   };
```

`AtlFlagNoCopy`significa que o tempo de vida da matriz não é controlado pelo enumerador. Nesse caso, a matriz será estática ou o objeto identificado por *punk* será responsável por liberar a matriz quando ela não for mais necessária.

`AtlFlagTakeOwnership`significa que a destruição da matriz deve ser controlada pelo enumerador. Nesse caso, a matriz deve ter sido dinamicamente alocada usando **New**. O enumerador excluirá a matriz em seu destruidor. Normalmente, você transmitiria NULL para *punk*, embora ainda possa passar um ponteiro válido se precisar ser notificado sobre a destruição do enumerador por algum motivo.

`AtlFlagCopy`significa que uma nova matriz deve ser criada copiando a matriz passada para `Init`. O tempo de vida da nova matriz deve ser controlado pelo enumerador. O enumerador excluirá a matriz em seu destruidor. Normalmente, você transmitiria NULL para *punk*, embora ainda possa passar um ponteiro válido se precisar ser notificado sobre a destruição do enumerador por algum motivo.

> [!NOTE]
>  O protótipo desse método especifica os elementos da matriz como sendo do tipo `T`, em `T` que foi definido como um parâmetro de modelo para a classe. Esse é o mesmo tipo que é exposto por meio do método de interface COM [CComEnumImpl:: Next](#next). A implicação disso é que, ao contrário de [IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md), essa classe não oferece suporte a tipos de dados expostos e de armazenamento diferentes. O tipo de dados dos elementos na matriz deve ser o mesmo que o tipo de dados exposto por meio da interface COM.

##  <a name="clone"></a>CComEnumImpl:: clone

Esse método fornece a implementação do método **clone** criando um objeto do tipo `CComEnum`, inicializando-o com a mesma matriz e iterador usado pelo objeto atual e retornando a interface no objeto recém-criado.

```
STDMETHOD(Clone)(Base** ppEnum);
```

### <a name="parameters"></a>Parâmetros

*ppEnum*<br/>
fora A interface do enumerador em um objeto recém-criado clonado do enumerador atual.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Observe que os enumeradores clonados nunca fazem sua própria cópia (ou apropriar-se) dos dados usados pelo enumerador original. Se necessário, os enumeradores clonados manterão o enumerador original ativo (usando uma referência COM) para garantir que os dados estejam disponíveis pelo tempo necessário.

##  <a name="m_spunk"></a>  CComEnumImpl::m_spUnk

Esse ponteiro inteligente mantém uma referência no objeto passado para [CComEnumImpl:: init](#init), garantindo que ele permaneça ativo durante o tempo de vida do enumerador.

```
CComPtr<IUnknown> m_spUnk;
```

##  <a name="m_begin"></a>  CComEnumImpl::m_begin

Um ponteiro para o local logo após o último elemento da matriz que contém os itens a serem enumerados.

```
T* m_begin;
```

##  <a name="m_end"></a>  CComEnumImpl::m_end

Um ponteiro para o primeiro elemento da matriz que contém os itens a serem enumerados.

```
T* m_end;
```

##  <a name="m_iter"></a>  CComEnumImpl::m_iter

Um ponteiro para o elemento atual da matriz que contém os itens a serem enumerados.

```
T* m_iter;
```

##  <a name="m_dwflags"></a>  CComEnumImpl::m_dwFlags

Os sinalizadores passaram para [CComEnumImpl:: init](#init).

```
DWORD m_dwFlags;
```

##  <a name="next"></a>  CComEnumImpl::Next

Esse método fornece a implementação do **próximo** método.

```
STDMETHOD(Next)(ULONG celt, T* rgelt, ULONG* pceltFetched);
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

##  <a name="reset"></a>  CComEnumImpl::Reset

Esse método fornece a implementação do método **Reset** .

```
STDMETHOD(Reset)(void);
```

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="skip"></a>  CComEnumImpl::Skip

Esse método fornece a implementação do método **Skip** .

```
STDMETHOD(Skip)(ULONG celt);
```

### <a name="parameters"></a>Parâmetros

*celt*<br/>
no O número de elementos a serem ignorados.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Retorna E_INVALIDARG se *celt* for zero, retorna S_FALSE se os elementos inferiores a *celt* forem retornados; caso contrário, retornará S_OK.

## <a name="see-also"></a>Consulte também

[Classe IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)<br/>
[Classe CComEnum](../../atl/reference/ccomenum-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
