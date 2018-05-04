---
title: Classe CComEnumImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CComEnumImpl class
ms.assetid: cc0d8e76-e608-46db-87cd-4c7161fe32d2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 14c7b1e72db3337b786a0e524ae3d8da964f6bbc
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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
 `Base`  
 Um enumerador COM ( [IEnumXXXX](https://msdn.microsoft.com/library/ms680089.aspx)) interface.  
  
 `piid`  
 Um ponteiro para a ID de interface da interface do enumerador.  
  
 `T`  
 O tipo de item exposto pela interface do enumerador.  
  
 `Copy`  
 Um homogênea [Copiar classe política](../../atl/atl-copy-policy-classes.md).  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComEnumImpl::CComEnumImpl](#ccomenumimpl)|O construtor.|  
|[CComEnumImpl:: ~ CComEnumImpl](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComEnumImpl::Clone](#clone)|A implementação de [IEnumXXXX::Clone](https://msdn.microsoft.com/library/ms690336.aspx).|  
|[CComEnumImpl::Init](#init)|Inicializa o enumerador.|  
|[CComEnumImpl::Next](#next)|A implementação de [IEnumXXXX::Next](https://msdn.microsoft.com/library/ms695273.aspx).|  
|[CComEnumImpl::Reset](#reset)|A implementação de [IEnumXXXX::Reset](https://msdn.microsoft.com/library/ms693414.aspx).|  
|[CComEnumImpl::Skip](#skip)|A implementação de [IEnumXXXX::Skip](https://msdn.microsoft.com/library/ms690392.aspx).|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComEnumImpl::m_begin](#m_begin)|Um ponteiro para o primeiro item na matriz.|  
|[CComEnumImpl::m_dwFlags](#m_dwflags)|Copiar sinalizadores passados por meio de `Init`.|  
|[CComEnumImpl::m_end](#m_end)|Um ponteiro para o local logo após o último item na matriz.|  
|[CComEnumImpl::m_iter](#m_iter)|Um ponteiro para o item atual na matriz.|  
|[CComEnumImpl::m_spUnk](#m_spunk)|O **IUnknown** ponteiro do objeto fornecendo a coleção que estão sendo enumerada.|  
  
## <a name="remarks"></a>Comentários  
 `CComEnumImpl` fornece a implementação de uma interface de enumerador COM onde os itens que estão sendo enumerados são armazenados em uma matriz. Essa classe é semelhante a de `IEnumOnSTLImpl` classe, que fornece uma implementação de uma interface de enumerador com base em um contêiner de biblioteca padrão C++.  
  
> [!NOTE]
>  Para obter detalhes sobre ainda mais as diferenças entre `CComEnumImpl` e `IEnumOnSTLImpl`, consulte [CComEnumImpl::Init](#init).  
  
 Normalmente, você irá *não* necessário criar sua própria classe de enumerador por esta implementação de interface. Se você quiser usar um enumerador fornecido ATL com base em uma matriz, é mais comum para criar uma instância de [CComEnum](../../atl/reference/ccomenum-class.md).  
  
 No entanto, se você precisar fornecer um enumerador personalizado (por exemplo, um que expõe interfaces além da interface de enumerador), você pode derivar dessa classe. Nessa situação, é provável que você precisará substituir o [CComEnumImpl::Clone](#clone) método para fornecer sua própria implementação.  
  
 Para obter mais informações, consulte [ATL coleções e enumeradores](../../atl/atl-collections-and-enumerators.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Base`  
  
 `CComEnumImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="ccomenumimpl"></a>  CComEnumImpl::CComEnumImpl  
 O construtor.  
  
```
CComEnumImpl();
```  
  
##  <a name="dtor"></a>  CComEnumImpl:: ~ CComEnumImpl  
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
 *begin*  
 Um ponteiro para o primeiro elemento da matriz que contém os itens a serem enumerados.  
  
 `end`  
 Um ponteiro para o local logo após o último elemento da matriz que contém os itens a serem enumerados.  
  
 *pUnk*  
 [in] O **IUnknown** ponteiro de um objeto que deve ser mantido ativo durante o tempo de vida do enumerador. Passar **nulo** se esse objeto não existe.  
  
 `flags`  
 Sinalizadores que especificam se o enumerador deve assumir a propriedade da matriz ou faça uma cópia dele. Os valores possíveis são descritos abaixo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Chamar esse método uma vez — inicializar o enumerador, usá-lo e, em seguida, eliminá-lo.  
  
 Se você passar ponteiros para itens em uma matriz mantido em outro objeto (e não perguntar o enumerador para copiar os dados), você pode usar o *pUnk* parâmetro para garantir que o objeto e a matriz que ele contém estão disponíveis para desde que o enumerador precisa deles. O enumerador simplesmente contém uma referência de COM no objeto mantê-lo em funcionamento. A referência COM é liberada automaticamente quando o enumerador é destruído.  
  
 O `flags` parâmetro permite que você especifique como o enumerador deve tratar os elementos da matriz passados para ele. `flags` pode ter um dos valores a partir de **CComEnumFlags** enumeração mostrada abaixo:  
  
```  
enum CComEnumFlags  
   {  
   AtlFlagNoCopy = 0,  
   AtlFlagTakeOwnership = 2, // BitOwn  
   AtlFlagCopy = 3           // BitOwn | BitCopy  
   };  
```  
  
 **AtlFlagNoCopy** significa que o tempo de vida da matriz não é controlado pelo enumerador. Nesse caso, a matriz será estático ou o objeto identificado por *pUnk* será responsável pela liberação da matriz quando ele não for mais necessário.  
  
 **AtlFlagTakeOwnership** significa que a destruição da matriz é controlado pelo enumerador. Nesse caso, a matriz deve ter sido dinamicamente alocada usando **novo**. O enumerador excluirá a matriz em seu destruidor. Normalmente, você passaria **nulo** para *pUnk*, embora você ainda pode passar um ponteiro válido, se você precisar ser notificado sobre a destruição do enumerador por alguma razão.  
  
 **AtlFlagCopy** significa que uma nova matriz deve ser criado, copiando a matriz passada para `Init`. Tempo de vida da nova matriz é controlado pelo enumerador. O enumerador excluirá a matriz em seu destruidor. Normalmente, você passaria **nulo** para *pUnk*, embora você ainda pode passar um ponteiro válido, se você precisar ser notificado sobre a destruição do enumerador por alguma razão.  
  
> [!NOTE]
>  O protótipo desse método Especifica os elementos da matriz como sendo do tipo **T**, onde **T** foi definido como um parâmetro de modelo para a classe. Esse é o mesmo tipo que é exposto por meio do método de interface COM [CComEnumImpl::Next](#next). A implicação é que, ao contrário de [IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md), essa classe não oferece suporte a armazenamento diferentes e expostos a tipos de dados. O tipo de dados dos elementos na matriz deve ser o mesmo que o tipo de dados exposto por meio de interface COM.  
  
##  <a name="clone"></a>  CComEnumImpl::Clone  
 Esse método fornece a implementação do [IEnumXXXX::Clone](https://msdn.microsoft.com/library/ms690336.aspx) método criando um objeto do tipo `CComEnum`, inicializá-la com a mesma matriz e iterador usado pelo objeto atual e retornar a interface a objeto criado recentemente.  
  
```
STDMETHOD(Clone)(Base** ppEnum);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppEnum`  
 [out] A interface de enumerador em um objeto recém-criado é clonado do enumerador atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Observe que os enumeradores clonados nunca fazem seus próprios cópia (ou apropriar-se) dos dados usados pelo enumerador original. Se necessário, enumeradores clonados manterá o enumerador original ativo (usando uma referência COM) para garantir que os dados estão disponíveis para desde que eles precisam.  
  
##  <a name="m_spunk"></a>  CComEnumImpl::m_spUnk  
 Esse ponteiro inteligente mantém uma referência no objeto passado para [CComEnumImpl::Init](#init), garantindo que ele permaneça ativo durante o tempo de vida do enumerador.  
  
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
 Esse método fornece a implementação do [IEnumXXXX::Next](https://msdn.microsoft.com/library/ms695273.aspx) método.  
  
```
STDMETHOD(Next)(ULONG celt, T* rgelt, ULONG* pceltFetched);
```  
  
### <a name="parameters"></a>Parâmetros  
 `celt`  
 [in] O número de elementos solicitado.  
  
 `rgelt`  
 [out] A matriz a ser preenchida com os elementos.  
  
 `pceltFetched`  
 [out] O número de elementos realmente retornados em `rgelt`. Isso pode ser menor que `celt` se menos de `celt` elementos permaneceram na lista.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="reset"></a>  CComEnumImpl::Reset  
 Esse método fornece a implementação do [IEnumXXXX::Reset](https://msdn.microsoft.com/library/ms693414.aspx) método.  
  
```
STDMETHOD(Reset)(void);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="skip"></a>  CComEnumImpl::Skip  
 Esse método fornece a implementação do [IEnumXXXX::Skip](https://msdn.microsoft.com/library/ms690392.aspx) método.  
  
```
STDMETHOD(Skip)(ULONG celt);
```  
  
### <a name="parameters"></a>Parâmetros  
 `celt`  
 [in] O número de elementos a serem ignorados.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Retornará E_INVALIDARG se `celt` for zero, retornará S_FALSE se for menor que `celt` elementos são retornados, caso contrário, retornará S_OK.  
  
## <a name="see-also"></a>Consulte também  
 [Classe IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)   
 [Classe CComEnum](../../atl/reference/ccomenum-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
