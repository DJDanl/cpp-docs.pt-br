---
title: Classe IProvideClassInfo2Impl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IProvideClassInfo2Impl
- ATLCOM/ATL::IProvideClassInfo2Impl
- ATLCOM/ATL::IProvideClassInfo2Impl::IProvideClassInfo2Impl
- ATLCOM/ATL::IProvideClassInfo2Impl::GetClassInfo
- ATLCOM/ATL::IProvideClassInfo2Impl::GetGUID
- ATLCOM/ATL::IProvideClassInfo2Impl::_tih
dev_langs:
- C++
helpviewer_keywords:
- IProvideClassInfo2Impl class
- IProvideClassInfo2 ATL implementation
- class information, ATL
ms.assetid: d74956e8-9c69-4cba-b99d-ca1ac031bb9d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6fe466608acaecfaf6219b6d15d27e0611ac2511
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iprovideclassinfo2impl-class"></a>Classe IProvideClassInfo2Impl
Essa classe fornece uma implementação padrão de [IProvideClassInfo](http://msdn.microsoft.com/library/windows/desktop/ms687303) e [IProvideClassInfo2](http://msdn.microsoft.com/library/windows/desktop/ms693764) métodos.  
  
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
 Um ponteiro para o identificador de padrão dos coclass dispinterface de saída.  
  
 `plibid`  
 Um ponteiro para a ID da biblioteca da biblioteca de tipo que contém informações sobre a interface. Por padrão, a biblioteca de tipos de nível de servidor é passada.  
  
 `wMajor`  
 A versão principal da biblioteca de tipos. O valor padrão é 1.  
  
 `wMinor`  
 A versão secundária da biblioteca de tipos. O valor padrão é 0.  
  
 `tihclass`  
 A classe usada para gerenciar informações de tipo dos coclass. O valor padrão é `CComTypeInfoHolder`.  
  
## <a name="members"></a>Membros  
  
### <a name="constructors"></a>Construtores  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IProvideClassInfo2Impl::IProvideClassInfo2Impl](#iprovideclassinfo2impl)|Construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IProvideClassInfo2Impl::GetClassInfo](#getclassinfo)|Recupera um **ITypeInfo** ponteiro para informações sobre o tipo dos coclass.|  
|[IProvideClassInfo2Impl::GetGUID](#getguid)|Recupera o GUID de dispinterface de saída do objeto.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IProvideClassInfo2Impl::_tih](#_tih)|Gerencia as informações de tipo para coclass.|  
  
## <a name="remarks"></a>Comentários  
 O [IProvideClassInfo2](http://msdn.microsoft.com/library/windows/desktop/ms693764) estende a interface [IProvideClassInfo](http://msdn.microsoft.com/library/windows/desktop/ms687303) adicionando o `GetGUID` método. Esse método permite que um cliente recuperar interface de saída de um objeto IID para seu conjunto de eventos padrão. Classe `IProvideClassInfo2Impl` fornece uma implementação padrão de **IProvideClassInfo** e `IProvideClassInfo2` métodos.  
  
 `IProvideClassInfo2Impl`contém um membro estático do tipo `CComTypeInfoHolder` que gerencia as informações de tipo para coclass.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IProvideClassInfo2`  
  
 `IProvideClassInfo2Impl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="getclassinfo"></a>IProvideClassInfo2Impl::GetClassInfo  
 Recupera um `ITypeInfo` ponteiro para informações sobre o tipo dos coclass.  
  
```
STDMETHOD(GetClassInfo)(ITypeInfo** pptinfo);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IProvideClassInfo::GetClassInfo](http://msdn.microsoft.com/library/windows/desktop/ms690192) no SDK do Windows.  
  
##  <a name="getguid"></a>IProvideClassInfo2Impl::GetGUID  
 Recupera o GUID de dispinterface de saída do objeto.  
  
```
STDMETHOD(GetGUID)(
    DWORD dwGuidKind,
    GUID* pGUID);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IProvideClassInfo2::GetGUID](http://msdn.microsoft.com/library/windows/desktop/ms679721) no SDK do Windows.  
  
##  <a name="iprovideclassinfo2impl"></a>IProvideClassInfo2Impl::IProvideClassInfo2Impl  
 O construtor.  
  
```
IProvideClassInfo2Impl();
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas `AddRef` no [_tih](#_tih) membro. As chamadas de destruidor **versão**.  
  
##  <a name="_tih"></a>IProvideClassInfo2Impl::_tih  
 Este membro de dados estáticos é uma instância do parâmetro de modelo de classe, `tihclass`, que por padrão é `CComTypeInfoHolder`.  
  
```
static  tihclass
    _tih;
```     
  
### <a name="remarks"></a>Comentários  
 `_tih`gerencia as informações de tipo para coclass.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
