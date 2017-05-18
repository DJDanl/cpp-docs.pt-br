---
title: Classe IDispatchImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IDispatchImpl
- ATLCOM/ATL::IDispatchImpl
- ATLCOM/ATL::IDispatchImpl::IDispatchImpl
- ATLCOM/ATL::IDispatchImpl::GetIDsOfNames
- ATLCOM/ATL::IDispatchImpl::GetTypeInfo
- ATLCOM/ATL::IDispatchImpl::GetTypeInfoCount
- ATLCOM/ATL::IDispatchImpl::Invoke
dev_langs:
- C++
helpviewer_keywords:
- dual interfaces, classes
- IDispatchImpl class
- IDispatch class support in ATL
ms.assetid: 8108eb36-1228-4127-a203-3ab5ba488892
caps.latest.revision: 27
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: fff4cbc0a3f87b584f1a4211f4aad37228ed4da7
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="idispatchimpl-class"></a>Classe IDispatchImpl
Fornece uma implementação padrão para o `IDispatch` faz parte de uma interface dupla.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T,
        const IID* piid= &__uuidof(T),
        const GUID* plibid = &CAtlModule::m_libid,
        WORD wMajor = 1,
        WORD wMinor = 0, 
        class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IDispatchImpl : public T
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `T`  
 Uma interface dupla.  
  
 [in] `piid`  
 Um ponteiro para o IID da `T`.  
  
 [in] `plibid`  
 Um ponteiro para a ID da biblioteca da biblioteca de tipos que contém informações sobre a interface. Por padrão, a biblioteca de tipos de nível de servidor é passada.  
  
 [in] `wMajor`  
 A versão principal da biblioteca de tipos. Por padrão, o valor é 1.  
  
 [in] `wMinor`  
 A versão secundária da biblioteca de tipos. Por padrão, o valor é 0.  
  
 [in] `tihclass`  
 A classe usada para gerenciar as informações de tipo de `T`. Por padrão, o valor é `CComTypeInfoHolder`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IDispatchImpl::IDispatchImpl](#idispatchimpl)|O construtor. Chamadas `AddRef` na variável de membro protegido que gerencia as informações de tipo para a interface dupla. O destruidor chama `Release`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IDispatchImpl::GetIDsOfNames](#getidsofnames)|Mapeia um conjunto de nomes para um conjunto correspondente de identificadores de expedição.|  
|[IDispatchImpl::GetTypeInfo](#gettypeinfo)|Recupera as informações de tipo para a interface dupla.|  
|[IDispatchImpl::GetTypeInfoCount](#gettypeinfocount)|Determina se as informações de tipo está disponível para a interface dupla.|  
|[IDispatchImpl::Invoke](#invoke)|Fornece acesso a métodos e propriedades expostas pela interface dupla.|  
  
## <a name="remarks"></a>Comentários  
 `IDispatchImpl`Fornece uma implementação padrão para o `IDispatch` faz parte de qualquer interface dupla em um objeto. Uma interface dupla deriva de `IDispatch` e usa apenas os tipos compatíveis com a automação. Como um dispinterface, uma interface dupla suporta associação inicial e associação tardia; No entanto, uma interface dupla também suporta associação vtable.  
  
 O exemplo a seguir mostra uma implementação típica do `IDispatchImpl`.  
  
 [!code-cpp[NVC_ATL_COM&47;](../../atl/codesnippet/cpp/idispatchimpl-class_1.h)]  
  
 Por padrão, o `IDispatchImpl` classe procura as informações de tipo `T` no registro. Para implementar uma interface não registrada, você pode usar o `IDispatchImpl` classe sem acessar o registro usando um número de versão predefinidos. Se você criar um `IDispatchImpl` objeto que tem 0xFFFF como o valor para `wMajor` e 0xFFFF como o valor para `wMinor`, a `IDispatchImpl` classe recupera a biblioteca de tipos de arquivo. dll em vez de no registro.  
  
 `IDispatchImpl`contém um membro estático do tipo `CComTypeInfoHolder` que gerencia as informações de tipo para a interface dupla. Se você tiver vários objetos que implementam a mesma dual interface, apenas uma instância de `CComTypeInfoHolder` é usado.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `T`  
  
 `IDispatchImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="getidsofnames"></a>IDispatchImpl::GetIDsOfNames  
 Mapeia um conjunto de nomes para um conjunto correspondente de identificadores de expedição.  
  
```
STDMETHOD(GetIDsOfNames)(
    REFIID riid,
    LPOLESTR* rgszNames,
    UINT cNames,
    LCID lcid,
    DISPID* rgdispid);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDispatch::GetIDsOfNames](http://msdn.microsoft.com/en-us/6f6cf233-3481-436e-8d6a-51f93bf91619) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="gettypeinfo"></a>IDispatchImpl::GetTypeInfo  
 Recupera as informações de tipo para a interface dupla.  
  
```
STDMETHOD(GetTypeInfo)(
    UINT itinfo,
    LCID lcid,
    ITypeInfo** pptinfo);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDispatch:: GetTypeInfo](http://msdn.microsoft.com/en-us/cc1ec9aa-6c40-4e70-819c-a7c6dd6b8c99) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="gettypeinfocount"></a>IDispatchImpl::GetTypeInfoCount  
 Determina se as informações de tipo está disponível para a interface dupla.  
  
```
STDMETHOD(GetTypeInfoCount)(UINT* pctinfo);
```  
  
### <a name="remarks"></a>Comentários  
 See `IDispatch::GetTypeInfoCount` in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="idispatchimpl"></a>IDispatchImpl::IDispatchImpl  
 O construtor. Chamadas `AddRef` na variável de membro protegido que gerencia as informações de tipo para a interface dupla. As chamadas de destruidor **versão**.  
  
```
IDispatchImpl();
```  
  
##  <a name="invoke"></a>IDispatchImpl::Invoke  
 Fornece acesso a métodos e propriedades expostas pela interface dupla.  
  
```
STDMETHOD(Invoke)(
    DISPID dispidMember,
    REFIID riid,
    LCID lcid,
    WORD wFlags,
    DISPPARAMS* pdispparams,
    VARIANT* pvarResult,
    EXCEPINFO* pexcepinfo,
    UINT* puArgErr);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IDispatch:: Invoke](http://msdn.microsoft.com/en-us/964ade8e-9d8a-4d32-bd47-aa678912a54d) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

