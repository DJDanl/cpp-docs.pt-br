---
title: Classe IProvideClassInfo2Impl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9d67f00b88be88e1cb2691414b0666bd298977dd
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43220174"
---
# <a name="iprovideclassinfo2impl-class"></a>Classe IProvideClassInfo2Impl
Essa classe fornece uma implementação padrão do [IProvideClassInfo](/windows/desktop/api/ocidl/nn-ocidl-iprovideclassinfo) e [IProvideClassInfo2](/windows/desktop/api/ocidl/nn-ocidl-iprovideclassinfo2) métodos.  
  
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
 Um ponteiro para o identificador dos coclass.  
  
 *psrcid*  
 Um ponteiro para o identificador do padrão dos coclass dispinterface de saída.  
  
 *plibid*  
 Um ponteiro para o LIBID da biblioteca de tipos que contém informações sobre a interface. Por padrão, a biblioteca de tipos de nível de servidor é passada.  
  
 *wMajor*  
 A versão principal da biblioteca de tipos. O valor padrão é 1.  
  
 *wMinor*  
 A versão secundária da biblioteca de tipos. O valor padrão é 0.  
  
 *tihclass*  
 A classe usada para gerenciar informações de tipo dos coclass. O valor padrão é `CComTypeInfoHolder`.  
  
## <a name="members"></a>Membros  
  
### <a name="constructors"></a>Construtores  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IProvideClassInfo2Impl::IProvideClassInfo2Impl](#iprovideclassinfo2impl)|Construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IProvideClassInfo2Impl::GetClassInfo](#getclassinfo)|Recupera um `ITypeInfo` ponteiro para informações de tipo dos coclass.|  
|[IProvideClassInfo2Impl::GetGUID](#getguid)|Recupera o GUID para dispinterface de saída do objeto.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IProvideClassInfo2Impl::_tih](#_tih)|Gerencia as informações de tipo para coclass.|  
  
## <a name="remarks"></a>Comentários  
 O [IProvideClassInfo2](/windows/desktop/api/ocidl/nn-ocidl-iprovideclassinfo2) interface estende [IProvideClassInfo](/windows/desktop/api/ocidl/nn-ocidl-iprovideclassinfo) adicionando o `GetGUID` método. Esse método permite que um cliente recuperar interface de saída de um objeto IID para que o conjunto de eventos padrão. Classe `IProvideClassInfo2Impl` fornece uma implementação padrão do `IProvideClassInfo` e `IProvideClassInfo2` métodos.  
  
 `IProvideClassInfo2Impl` contém um membro estático do tipo `CComTypeInfoHolder` que gerencia as informações de tipo para coclass.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IProvideClassInfo2`  
  
 `IProvideClassInfo2Impl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom  
  
##  <a name="getclassinfo"></a>  IProvideClassInfo2Impl::GetClassInfo  
 Recupera um `ITypeInfo` ponteiro para informações de tipo dos coclass.  
  
```
STDMETHOD(GetClassInfo)(ITypeInfo** pptinfo);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IProvideClassInfo::GetClassInfo](/windows/desktop/api/ocidl/nf-ocidl-iprovideclassinfo-getclassinfo) no Windows SDK.  
  
##  <a name="getguid"></a>  IProvideClassInfo2Impl::GetGUID  
 Recupera o GUID para dispinterface de saída do objeto.  
  
```
STDMETHOD(GetGUID)(
    DWORD dwGuidKind,
    GUID* pGUID);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IProvideClassInfo2::GetGUID](/windows/desktop/api/ocidl/nf-ocidl-iprovideclassinfo2-getguid) no Windows SDK.  
  
##  <a name="iprovideclassinfo2impl"></a>  IProvideClassInfo2Impl::IProvideClassInfo2Impl  
 O construtor.  
  
```
IProvideClassInfo2Impl();
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas `AddRef` sobre o [_tih](#_tih) membro. O destruidor chama `Release`.  
  
##  <a name="_tih"></a>  IProvideClassInfo2Impl::_tih  
 Esse membro de dados estáticos é uma instância do parâmetro de modelo de classe, *tihclass*, que, por padrão é `CComTypeInfoHolder`.  
  
```
static  tihclass
    _tih;
```     
  
### <a name="remarks"></a>Comentários  
 `_tih` Gerencia as informações de tipo para coclass.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
