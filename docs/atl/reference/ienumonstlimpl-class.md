---
title: Classe IEnumOnSTLImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- IEnumOnSTLImpl class
ms.assetid: 1789e77b-88b8-447d-a490-806b918912ce
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1de4bdd0d07e694303f850d6298d77afe3322214
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32365250"
---
# <a name="ienumonstlimpl-class"></a>Classe IEnumOnSTLImpl
Essa classe define uma interface de enumerador com base em uma coleção de biblioteca padrão C++.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Base,
    const IID* piid, class T, class Copy, class CollType>  
class ATL_NO_VTABLE IEnumOnSTLImpl : public Base
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Base`  
 Um enumerador COM ( [IEnumXXXX](https://msdn.microsoft.com/library/ms680089.aspx)) interface.  
  
 `piid`  
 Um ponteiro para a ID de interface da interface do enumerador.  
  
 `T`  
 O tipo de item exposto pela interface do enumerador.  
  
 `Copy`  
 Um [Copiar classe política](../../atl/atl-copy-policy-classes.md).  
  
 `CollType`  
 Uma classe de contêiner da biblioteca padrão C++.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IEnumOnSTLImpl::Clone](#clone)|A implementação de [IEnumXXXX::Clone](https://msdn.microsoft.com/library/ms690336.aspx).|  
|[IEnumOnSTLImpl::Init](#init)|Inicializa o enumerador.|  
|[IEnumOnSTLImpl::Next](#next)|A implementação de [IEnumXXXX::Next](https://msdn.microsoft.com/library/ms695273.aspx).|  
|[IEnumOnSTLImpl::Reset](#reset)|A implementação de [IEnumXXXX::Reset](https://msdn.microsoft.com/library/ms693414.aspx).|  
|[IEnumOnSTLImpl::Skip](#skip)|A implementação de [IEnumXXXX::Skip](https://msdn.microsoft.com/library/ms690392.aspx).|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IEnumOnSTLImpl::m_iter](#m_iter)|O iterador que representa a posição atual do enumerador dentro da coleção.|  
|[IEnumOnSTLImpl::m_pcollection](#m_pcollection)|Um ponteiro para o contêiner de biblioteca padrão C++ contendo os itens a serem enumerados.|  
|[IEnumOnSTLImpl::m_spUnk](#m_spunk)|O **IUnknown** ponteiro do objeto fornecendo a coleção.|  
  
## <a name="remarks"></a>Comentários  
 `IEnumOnSTLImpl` fornece a implementação de uma interface de enumerador COM onde os itens que estão sendo enumerados são armazenados em um contêiner de biblioteca padrão C++-compatível. Essa classe é semelhante ao [CComEnumImpl](../../atl/reference/ccomenumimpl-class.md) classe, que fornece uma implementação de uma interface de enumerador com base em uma matriz.  
  
> [!NOTE]
>  Consulte [CComEnumImpl::Init](../../atl/reference/ccomenumimpl-class.md#init) para obter detalhes sobre ainda mais as diferenças entre `CComEnumImpl` e `IEnumOnSTLImpl`.  
  
 Normalmente, você irá *não* necessário criar sua própria classe de enumerador por esta implementação de interface. Se você quiser usar um enumerador fornecido ATL com base em um contêiner de biblioteca padrão C++, é mais comum para criar uma instância de [CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md), ou para criar uma classe de coleção que retorna um enumerador derivando de [ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md).  
  
 No entanto, se você precisar fornecer um enumerador personalizado (por exemplo, um que expõe interfaces além da interface de enumerador), você pode derivar dessa classe. Nessa situação, é provável que você precisará substituir o [Clone](#clone) método para fornecer sua própria implementação.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Base`  
  
 `IEnumOnSTLImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="init"></a>  IEnumOnSTLImpl::Init  
 Inicializa o enumerador.  
  
```
HRESULT Init(
    IUnknown* pUnkForRelease,
    CollType& collection);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pUnkForRelease`  
 [in] O **IUnknown** ponteiro de um objeto que deve ser mantido ativo durante o tempo de vida do enumerador. Passar **nulo** se esse objeto não existe.  
  
 `collection`  
 Uma referência para o contêiner de biblioteca padrão C++ que contém os itens a serem enumerados.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Se você passar `Init` uma referência a uma coleção é mantido em outro objeto, você pode usar o `pUnkForRelease` parâmetro para garantir que o objeto e coleção que ela contém, está disponível para desde que o enumerador precisa dele.  
  
 Você deve chamar esse método antes de passar um ponteiro para a interface de enumerador para todos os clientes.  
  
##  <a name="clone"></a>  IEnumOnSTLImpl::Clone  
 Esse método fornece a implementação do [IEnumXXXX::Clone](https://msdn.microsoft.com/library/ms690336.aspx) método criando um objeto do tipo `CComEnumOnSTL`, inicializá-la com a mesma coleção e iterador usado pelo objeto atual e retorna a interface em o objeto recém-criado.  
  
```
STDMETHOD(Clone)(Base** ppEnum);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppEnum`  
 [out] A interface de enumerador em um objeto recém-criado é clonado do enumerador atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="m_spunk"></a>  IEnumOnSTLImpl::m_spUnk  
 O **IUnknown** ponteiro do objeto fornecendo a coleção.  
  
```
CComPtr<IUnknown> m_spUnk;
```  
  
### <a name="remarks"></a>Comentários  
 Esse ponteiro inteligente mantém uma referência no objeto passado para [IEnumOnSTLImpl::Init](#init), garantindo que ele permaneça ativo durante o tempo de vida do enumerador.  
  
##  <a name="m_pcollection"></a>  IEnumOnSTLImpl::m_pcollection  
 Este membro aponta para a coleção que fornece os dados que orienta a implementação da interface do enumerador.  
  
```
CollType* m_pcollection;
```  
  
### <a name="remarks"></a>Comentários  
 Esse membro é inicializado por uma chamada para [IEnumOnSTLImpl::Init](#init).  
  
##  <a name="m_iter"></a>  IEnumOnSTLImpl::m_iter  
 Este membro mantém o iterador usado para marcar a posição atual dentro da coleção e navegar por elementos subsequentes.  
  
```
CollType::iterator m_iter;
```  
  
##  <a name="next"></a>  IEnumOnSTLImpl::Next  
 Esse método fornece a implementação do [IEnumXXXX::Next](https://msdn.microsoft.com/library/ms695273.aspx) método.  
  
```
STDMETHOD(Next)(
    ULONG celt,
    T* rgelt,
    ULONG* pceltFetched);
```  
  
### <a name="parameters"></a>Parâmetros  
 `celt`  
 [in] O número de elementos solicitado.  
  
 `rgelt`  
 [out] A matriz a ser preenchido com os elementos.  
  
 `pceltFetched`  
 [out] O número de elementos realmente retornados em `rgelt`. Isso pode ser menor que `celt` se menos de `celt` elementos permanecem na lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="reset"></a>  IEnumOnSTLImpl::Reset  
 Esse método fornece a implementação do [IEnumXXXX::Reset](https://msdn.microsoft.com/library/ms693414.aspx) método.  
  
```
STDMETHOD(Reset)(void);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="skip"></a>  IEnumOnSTLImpl::Skip  
 Esse método fornece a implementação do [IEnumXXXX::Skip](https://msdn.microsoft.com/library/ms690392.aspx) método.  
  
```
STDMETHOD(Skip)(ULONG celt);
```  
  
### <a name="parameters"></a>Parâmetros  
 `celt`  
 [in] O número de elementos a serem ignorados.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
