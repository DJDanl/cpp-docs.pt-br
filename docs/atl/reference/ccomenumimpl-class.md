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
ms.openlocfilehash: ccd083f3bfd9ae694c97e466fcb40b348fec0c27
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62259853"
---
# <a name="ccomenumimpl-class"></a>Classe CComEnumImpl

Essa classe fornece a implementação de uma interface de enumerador COM onde os itens que estão sendo enumerados são armazenados em uma matriz.

## <a name="syntax"></a>Sintaxe

```
template <class Base,
    const IID* piid, class T, class Copy>
class ATL_NO_VTABLE CComEnumImpl : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base*<br/>
Uma interface de enumerador de COM. Ver [IEnumString](/windows/desktop/api/objidl/nn-objidl-ienumstring) para obter um exemplo.

*piid*<br/>
Um ponteiro para a ID de interface da interface do enumerador.

*T*<br/>
O tipo de item exposto pela interface do enumerador.

*Copiar*<br/>
Um homogêneos [copie a classe da diretiva](../../atl/atl-copy-policy-classes.md).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComEnumImpl::CComEnumImpl](#ccomenumimpl)|O construtor.|
|[CComEnumImpl::~CComEnumImpl](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComEnumImpl::Clone](#clone)|A implementação de **Clone** método de interface de enumeração.|
|[CComEnumImpl::Init](#init)|Inicializa o enumerador.|
|[CComEnumImpl::Next](#next)|A implementação de **próxima**.|
|[CComEnumImpl::Reset](#reset)|A implementação de **redefinir**.|
|[CComEnumImpl::Skip](#skip)|A implementação de **Skip**.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComEnumImpl::m_begin](#m_begin)|Um ponteiro para o primeiro item na matriz.|
|[CComEnumImpl::m_dwFlags](#m_dwflags)|Copie os sinalizadores passados por meio de `Init`.|
|[CComEnumImpl::m_end](#m_end)|Um ponteiro para o local logo após o último item na matriz.|
|[CComEnumImpl::m_iter](#m_iter)|Um ponteiro para o item atual na matriz.|
|[CComEnumImpl::m_spUnk](#m_spunk)|O `IUnknown` ponteiro do objeto fornecendo a coleção que está sendo enumerada.|

## <a name="remarks"></a>Comentários

Ver [IEnumString](/windows/desktop/api/objidl/nn-objidl-ienumstring) para obter um exemplo de implementações de método. `CComEnumImpl` fornece a implementação de uma interface de enumerador COM onde os itens que estão sendo enumerados são armazenados em uma matriz. Essa classe é semelhante ao `IEnumOnSTLImpl` classe, que fornece uma implementação de uma interface de enumerador com base em um contêiner de biblioteca padrão C++.

> [!NOTE]
>  Para obter detalhes sobre ainda mais as diferenças entre `CComEnumImpl` e `IEnumOnSTLImpl`, consulte [CComEnumImpl::Init](#init).

Normalmente, você irá *não* precisa criar sua própria classe de enumerador, derivando dessa implementação de interface. Se você quiser usar um enumerador fornecido pelo ATL com base em uma matriz, é mais comum para criar uma instância do [CComEnum](../../atl/reference/ccomenum-class.md).

No entanto, se você precisar fornecer um enumerador personalizado (por exemplo, um que expõe interfaces além da interface de enumerador), você pode derivar dessa classe. Nessa situação, é provável que você precisará substituir os [CComEnumImpl::Clone](#clone) método para fornecer sua própria implementação.

Para obter mais informações, consulte [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComEnumImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="ccomenumimpl"></a>  CComEnumImpl::CComEnumImpl

O construtor.

```
CComEnumImpl();
```

##  <a name="dtor"></a>  CComEnumImpl::~CComEnumImpl

O destruidor.

```
~CComEnumImpl();
```

##  <a name="init"></a>  CComEnumImpl::Init

Você deve chamar esse método antes de passar um ponteiro para a interface de enumerador para todos os clientes.

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
[in] O `IUnknown` ponteiro de um objeto que deve ser mantido durante a vida útil do enumerador. Passe NULL se esse objeto não existe.

*flags*<br/>
Sinalizadores que especificam se o enumerador deve assumir a propriedade da matriz ou faça uma cópia dele. Os valores possíveis são descritos abaixo.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Chamar esse método somente uma vez – inicializar o enumerador, usá-lo e, em seguida, descartá-lo.

Se você passar ponteiros para itens em uma matriz mantidos em outro objeto (e você não pergunte o enumerador para copiar os dados), você pode usar o *pUnk* parâmetro para garantir que o objeto e a matriz que ele contém estão disponíveis para desde que o enumerador precisa deles. O enumerador simplesmente se atém uma referência COM o objeto para mantê-lo ativo. A referência COM é liberada automaticamente quando o enumerador é destruído.

O *sinalizadores* parâmetro permite que você especifique como o enumerador deve tratar os elementos da matriz passados para ele. *sinalizadores* pode assumir um dos valores da `CComEnumFlags` enumeração mostrada abaixo:

```
enum CComEnumFlags
   {
   AtlFlagNoCopy = 0,
   AtlFlagTakeOwnership = 2, // BitOwn
   AtlFlagCopy = 3           // BitOwn | BitCopy
   };
```

`AtlFlagNoCopy` significa que o tempo de vida da matriz não é controlado pelo enumerador. Nesse caso, a matriz será estático ou o objeto identificado pelo *pUnk* será responsável por liberar a matriz quando ele não for mais necessário.

`AtlFlagTakeOwnership` significa que a destruição da matriz deve ser controlado pelo enumerador. Nesse caso, a matriz deve ter sido dinamicamente alocada usando **novo**. O enumerador excluirá a matriz em seu destruidor. Normalmente, você poderia passar NULL para *pUnk*, embora você ainda pode passar um ponteiro válido, se você precisar ser notificado sobre a destruição do enumerador por algum motivo.

`AtlFlagCopy` significa que uma nova matriz deve ser criado, copiando a matriz passada para `Init`. Tempo de vida da nova matriz é controlado pelo enumerador. O enumerador excluirá a matriz em seu destruidor. Normalmente, você poderia passar NULL para *pUnk*, embora você ainda pode passar um ponteiro válido, se você precisar ser notificado sobre a destruição do enumerador por algum motivo.

> [!NOTE]
>  O protótipo do método Especifica os elementos da matriz como sendo do tipo `T`, onde `T` foi definido como um parâmetro de modelo para a classe. Esse é o mesmo tipo que é exposto por meio do método de interface COM [CComEnumImpl::Next](#next). A implicação disso é que, diferentemente [IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md), essa classe não dá suporte a armazenamento diferente e expostos a tipos de dados. O tipo de dados dos elementos na matriz deve ser o mesmo que o tipo de dados exposto por meio da interface COM.

##  <a name="clone"></a>  CComEnumImpl::Clone

Esse método fornece a implementação do **Clone** método com a criação de um objeto do tipo `CComEnum`, inicializando-a com a mesma matriz e o iterador usado pelo objeto atual e retorna a interface em recém-criado objeto.

```
STDMETHOD(Clone)(Base** ppEnum);
```

### <a name="parameters"></a>Parâmetros

*ppEnum*<br/>
[out] A interface de enumerador em um objeto recém-criado clonado do enumerador atual.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Observe que os enumeradores clonados nunca fazer seus próprios cópia (ou apropriar) dos dados usados pelo enumerador original. Se necessário, enumeradores clonados manterá o enumerador original ativa (usando uma referência COM) para garantir que os dados estão disponíveis para desde que eles precisam.

##  <a name="m_spunk"></a>  CComEnumImpl::m_spUnk

Ponteiro inteligente mantém uma referência no objeto passado para [CComEnumImpl::Init](#init), garantindo que ele permaneça ativo durante o tempo de vida do enumerador.

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

Os sinalizadores passados para [CComEnumImpl::Init](#init).

```
DWORD m_dwFlags;
```

##  <a name="next"></a>  CComEnumImpl::Next

Esse método fornece a implementação de **próxima** método.

```
STDMETHOD(Next)(ULONG celt, T* rgelt, ULONG* pceltFetched);
```

### <a name="parameters"></a>Parâmetros

*celt*<br/>
[in] O número de elementos solicitados.

*rgelt*<br/>
[out] A matriz a ser preenchido com os elementos.

*pceltFetched*<br/>
[out] O número de elementos realmente retornados na *rgelt*. Isso pode ser menor que *celt* se menos de *celt* elementos permaneceram na lista.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="reset"></a>  CComEnumImpl::Reset

Esse método fornece a implementação de **redefinir** método.

```
STDMETHOD(Reset)(void);
```

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="skip"></a>  CComEnumImpl::Skip

Esse método fornece a implementação de **Skip** método.

```
STDMETHOD(Skip)(ULONG celt);
```

### <a name="parameters"></a>Parâmetros

*celt*<br/>
[in] O número de elementos a serem ignorados.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Retornará E_INVALIDARG se *celt* for zero, retornará S_FALSE se for menor que *celt* elementos são retornados, caso contrário, retornará S_OK.

## <a name="see-also"></a>Consulte também

[Classe IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)<br/>
[Classe CComEnum](../../atl/reference/ccomenum-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
