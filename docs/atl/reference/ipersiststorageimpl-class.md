---
title: Classe IPersistStorageImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IPersistStorageImpl
- ATLCOM/ATL::IPersistStorageImpl
- ATLCOM/ATL::IPersistStorageImpl::GetClassID
- ATLCOM/ATL::IPersistStorageImpl::HandsOffStorage
- ATLCOM/ATL::IPersistStorageImpl::InitNew
- ATLCOM/ATL::IPersistStorageImpl::IsDirty
- ATLCOM/ATL::IPersistStorageImpl::Load
- ATLCOM/ATL::IPersistStorageImpl::Save
- ATLCOM/ATL::IPersistStorageImpl::SaveCompleted
dev_langs:
- C++
helpviewer_keywords:
- storage, ATL
- IPersistStorageImpl class
ms.assetid: d652f02c-239c-47c7-9a50-3e9fc3014fff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 18f03ba235fdfc14dba22f1759240bd5fb72bafd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32364656"
---
# <a name="ipersiststorageimpl-class"></a>Classe IPersistStorageImpl
Essa classe implementa o [IPersistStorage](http://msdn.microsoft.com/library/windows/desktop/ms679731) interface.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE IPersistStorageImpl : public IPersistStorage
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IPersistStorageImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPersistStorageImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|  
|[IPersistStorageImpl::HandsOffStorage](#handsoffstorage)|Instrui o objeto para liberar todos os objetos de armazenamento e entrar no modo HandsOff. Retorna a implementação de ATL `S_OK`.|  
|[IPersistStorageImpl::InitNew](#initnew)|Inicializa um novo armazenamento.|  
|[IPersistStorageImpl::IsDirty](#isdirty)|Verifica se os dados do objeto foi alterado desde que foi salvo pela última vez.|  
|[IPersistStorageImpl::Load](#load)|Carrega as propriedades do objeto de armazenamento especificado.|  
|[IPersistStorageImpl::Save](#save)|Salva as propriedades do objeto de armazenamento especificado.|  
|[IPersistStorageImpl::SaveCompleted](#savecompleted)|Notifica um objeto que pode retornar ao modo Normal para gravar seu objeto de armazenamento. Retorna a implementação de ATL `S_OK`.|  
  
## <a name="remarks"></a>Comentários  
 `IPersistStorageImpl` implementa o [IPersistStorage](http://msdn.microsoft.com/library/windows/desktop/ms679731) de interface, que permite que um cliente para solicitar que o carregamento do objeto e salvar seus dados persistentes usando um armazenamento.  
  
 A implementação desta classe exige a classe `T` para fazer uma implementação do `IPersistStreamInit` disponível por meio da interface `QueryInterface`. Normalmente, isso significa que a classe `T` deve derivar de [IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md), fornecer uma entrada para `IPersistStreamInit` no [mapa COM](http://msdn.microsoft.com/library/ead2a1e3-334d-44ad-bb1f-b94bb14c2333)e usar um [mapa de propriedade](http://msdn.microsoft.com/library/bfe30be6-62c3-4dc2-bd49-21ef96f15427) para descrever dados persistentes da classe.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IPersistStorage`  
  
 `IPersistStorageImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="getclassid"></a>  IPersistStorageImpl::GetClassID  
 Recupera o CLSID do objeto.  
  
```
STDMETHOD(GetClassID)(CLSID* pClassID);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [ipersist:: GetClassID](http://msdn.microsoft.com/library/windows/desktop/ms688664) no SDK do Windows.  
  
##  <a name="handsoffstorage"></a>  IPersistStorageImpl::HandsOffStorage  
 Instrui o objeto para liberar todos os objetos de armazenamento e entrar no modo HandsOff.  
  
```
STDMETHOD(HandsOffStorage)(void);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPersistStorage::HandsOffStorage](http://msdn.microsoft.com/library/windows/desktop/ms679742) no SDK do Windows.  
  
##  <a name="initnew"></a>  IPersistStorageImpl::InitNew  
 Inicializa um novo armazenamento.  
  
```
STDMETHOD(InitNew)(IStorage*);
```  
  
### <a name="remarks"></a>Comentários  
 A implementação de ATL delega para o [IPersistStreamInit](http://msdn.microsoft.com/library/windows/desktop/ms682273) interface.  
  
 Consulte [IPersistStorage:InitNew](http://msdn.microsoft.com/library/windows/desktop/ms687194) no SDK do Windows.  
  
##  <a name="isdirty"></a>  IPersistStorageImpl::IsDirty  
 Verifica se os dados do objeto foi alterado desde que foi salvo pela última vez.  
  
```
STDMETHOD(IsDirty)(void);
```  
  
### <a name="remarks"></a>Comentários  
 A implementação de ATL delega para o [IPersistStreamInit](http://msdn.microsoft.com/library/windows/desktop/ms682273) interface.  
  
 Consulte [IPersistStorage:IsDirty](http://msdn.microsoft.com/library/windows/desktop/ms683910) no SDK do Windows.  
  
##  <a name="load"></a>  IPersistStorageImpl::Load  
 Carrega as propriedades do objeto de armazenamento especificado.  
  
```
STDMETHOD(Load)(IStorage* pStorage);
```  
  
### <a name="remarks"></a>Comentários  
 A implementação de ATL delega para o [IPersistStreamInit](http://msdn.microsoft.com/library/windows/desktop/ms682273) interface. **Carga** usa um fluxo denominado "Conteúdo" para recuperar os dados do objeto. O [salvar](#save) método originalmente cria esse fluxo.  
  
 Consulte [IPersistStorage:Load](http://msdn.microsoft.com/library/windows/desktop/ms680557) no SDK do Windows.  
  
##  <a name="save"></a>  IPersistStorageImpl::Save  
 Salva as propriedades do objeto de armazenamento especificado.  
  
```
STDMETHOD(Save)(IStorage* pStorage, BOOL fSameAsLoad);
```  
  
### <a name="remarks"></a>Comentários  
 A implementação de ATL delega para o [IPersistStreamInit](http://msdn.microsoft.com/library/windows/desktop/ms682273) interface. Quando **salvar** primeiro é chamado, ele cria um fluxo denominado "Conteúdo" no armazenamento especificado. Esse fluxo é usado em chamadas posteriores para **salvar** e nas chamadas ao [carga](#load).  
  
 Consulte [IPersistStorage:Save](http://msdn.microsoft.com/library/windows/desktop/ms680680) no SDK do Windows.  
  
##  <a name="savecompleted"></a>  IPersistStorageImpl::SaveCompleted  
 Notifica um objeto que pode retornar ao modo Normal para gravar seu objeto de armazenamento.  
  
```
STDMETHOD(SaveCompleted)(IStorage*);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPersistStorage:SaveCompleted](http://msdn.microsoft.com/library/windows/desktop/ms679713) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos e armazenamentos](http://msdn.microsoft.com/library/windows/desktop/aa380352)   
 [Classe IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md)   
 [Classe IPersistPropertyBagImpl](../../atl/reference/ipersistpropertybagimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
