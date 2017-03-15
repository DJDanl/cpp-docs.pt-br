---
title: Classe IProvideClassInfo2Impl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IProvideClassInfo2
- ATL.IProvideClassInfo2Impl
- IProvideClassInfo2Impl
- ATL::IProvideClassInfo2Impl
dev_langs:
- C++
helpviewer_keywords:
- IProvideClassInfo2Impl class
- IProvideClassInfo2 ATL implementation
- class information, ATL
ms.assetid: d74956e8-9c69-4cba-b99d-ca1ac031bb9d
caps.latest.revision: 20
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
translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 0d3bed0f625e396b63ada19ded02ba9ad3b697b0
ms.lasthandoff: 02/25/2017

---
# <a name="iprovideclassinfo2impl-class"></a>Classe de IProvideClassInfo2Impl
Essa classe fornece uma implementação padrão da [IProvideClassInfo](http://msdn.microsoft.com/library/windows/desktop/ms687303) e [IProvideClassInfo2](http://msdn.microsoft.com/library/windows/desktop/ms693764) métodos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <const CLSID* pcoclsid,
    const IID* psrcid,
    const GUID* plibid = &CAtlModule::m_libid,
    WORD wMajor = 1,
    WORD wMinor = 0, class tihclass = CComTypeInfoHolder>  
class ATL_NO_VTABLE IProvideClassInfo2Impl : public IProvideClassInfo2
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pcoclsid*  
 Um ponteiro para o identificador de coclass.  
  
 *psrcid*  
 Um ponteiro para o identificador de padrão de coclass dispinterface de saída.  
  
 `plibid`  
 Um ponteiro para a ID da biblioteca da biblioteca de tipos que contém informações sobre a interface. Por padrão, a biblioteca de tipos de nível de servidor é passada.  
  
 `wMajor`  
 A versão principal da biblioteca de tipos. O valor padrão é 1.  
  
 `wMinor`  
 A versão secundária da biblioteca de tipos. O valor padrão é 0.  
  
 `tihclass`  
 A classe usada para gerenciar informações de tipo de coclass. O valor padrão é `CComTypeInfoHolder`.  
  
## <a name="members"></a>Membros  
  
### <a name="constructors"></a>Construtores  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IProvideClassInfo2Impl::IProvideClassInfo2Impl](#iprovideclassinfo2impl)|Construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IProvideClassInfo2Impl::GetClassInfo](#getclassinfo)|Recupera um **ITypeInfo** ponteiro informações de tipo de coclass.|  
|[IProvideClassInfo2Impl::GetGUID](#getguid)|Recupera o GUID para dispinterface de saída do objeto.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IProvideClassInfo2Impl::_tih](#_tih)|Gerencia as informações de tipo para o coclass.|  
  
## <a name="remarks"></a>Comentários  
 O [IProvideClassInfo2](http://msdn.microsoft.com/library/windows/desktop/ms693764) interface estende [IProvideClassInfo](http://msdn.microsoft.com/library/windows/desktop/ms687303) adicionando o `GetGUID` método. Esse método permite que um cliente recuperar interface de saída de um objeto IID para seu conjunto de eventos padrão. Classe `IProvideClassInfo2Impl` fornece uma implementação padrão de **IProvideClassInfo** e `IProvideClassInfo2` métodos.  
  
 `IProvideClassInfo2Impl`contém um membro estático do tipo `CComTypeInfoHolder` que gerencia as informações de tipo para o coclass.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IProvideClassInfo2`  
  
 `IProvideClassInfo2Impl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="a-namegetclassinfoa--iprovideclassinfo2implgetclassinfo"></a><a name="getclassinfo"></a>IProvideClassInfo2Impl::GetClassInfo  
 Recupera um `ITypeInfo` ponteiro informações de tipo de coclass.  
  
```
STDMETHOD(GetClassInfo)(ITypeInfo** pptinfo);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IProvideClassInfo::GetClassInfo](http://msdn.microsoft.com/library/windows/desktop/ms690192) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetguida--iprovideclassinfo2implgetguid"></a><a name="getguid"></a>IProvideClassInfo2Impl::GetGUID  
 Recupera o GUID para dispinterface de saída do objeto.  
  
```
STDMETHOD(GetGUID)(
    DWORD dwGuidKind,
    GUID* pGUID);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IProvideClassInfo2::GetGUID](http://msdn.microsoft.com/library/windows/desktop/ms679721) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameiprovideclassinfo2impla--iprovideclassinfo2impliprovideclassinfo2impl"></a><a name="iprovideclassinfo2impl"></a>IProvideClassInfo2Impl::IProvideClassInfo2Impl  
 O construtor.  
  
```
IProvideClassInfo2Impl();
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas `AddRef` sobre o [_tih](#_tih) membro. As chamadas de destruidor **versão**.  
  
##  <a name="a-nametiha--iprovideclassinfo2impltih"></a><a name="_tih"></a>IProvideClassInfo2Impl::_tih  
 Este membro de dados estáticos é uma instância de parâmetro do modelo de classe, `tihclass`, que por padrão é `CComTypeInfoHolder`.  
  
```
static  tihclass
    _tih;
```     
  
### <a name="remarks"></a>Comentários  
 `_tih`gerencia as informações de tipo para o coclass.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

