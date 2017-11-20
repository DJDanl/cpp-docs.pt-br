---
title: Typedefs ATL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlcore/ATL::_ATL_BASE_MODULE
- atlbase/ATL::_ATL_COM_MODULE
- atlbase/ATL::_ATL_MODULE
- atlbase/ATL::_ATL_WIN_MODULE
- atlutil/ATL::ATL_URL_PORT
- atlbase/ATL::CComDispatchDriver
- atlbase/ATL::CComGlobalsThreadModel
- atlbase/ATL::CComObjectThreadModel
- atlwin/ATL::CContainedWindow
- atlpath/ATL::CPath
- atlpath/ATL::CPathA
- atlpath/ATL::CPathW
- " atlsimpcoll/ATL::CSimpleValArray"
- " atlutil/ATL::LPCURL"
- atlbase/ATL::DefaultThreadTraits
- atlutil/ATL::LPURL
dev_langs: C++
helpviewer_keywords:
- typedefs, ATL
- typedefs
- ATL, typedefs
ms.assetid: 7dd05baa-3efb-4e3b-af23-793c610f4560
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ae5a0d527bd503422176fb01f4024d98100ef351
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="atl-typedefs"></a>Definições de tipo ATL
O Active Template Library inclui as seguintes definições de tipo.  
  
|||  
|-|-|  
|[_ATL_BASE_MODULE](#_atl_base_module)|Definido como um typedef com base em [_ATL_BASE_MODULE70](../../atl/reference/atl-base-module70-structure.md).|  
|[_ATL_COM_MODULE](#_atl_com_module)|Definido como um typedef com base em [_ATL_COM_MODULE70](../../atl/reference/atl-com-module70-structure.md).|  
|[_ATL_MODULE](#_atl_module)|Definido como um typedef com base em [_ATL_MODULE70](../../atl/reference/atl-module70-structure.md).|  
|[_ATL_WIN_MODULE](#_atl_win_module)|Definido como um typedef com base em [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md)|  
|[ATL_URL_PORT](#atl_url_port)|O tipo usado pelo [CUrl](../../atl/reference/curl-class.md) para especificar um número de porta.|  
|[CComDispatchDriver](#ccomdispatchdriver)|Essa classe gerencia ponteiros de interface COM.|  
|[CComGlobalsThreadModel](#ccomglobalsthreadmodel)|Chama o thread apropriado métodos do modelo, independentemente do modelo de threading que está sendo usado.|  
|[CComObjectThreadModel](#ccomobjectthreadmodel)|Chama o thread apropriado métodos do modelo, independentemente do modelo de threading que está sendo usado.|  
|[CContainedWindow](#ccontainedwindow)|Essa classe é uma especialização de **CContainedWindowT.**|  
|[CPath](#cpath)|Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CString`.|  
|[CPathA](#cpatha)|Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CStringA`.|  
|[CPathW](#cpathw)|Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CStringW`.|  
|[CSimpleValArray](#csimplevalarray)|Representa uma matriz de armazenamento de tipos simples.|  
|[DefaultThreadTraits](#defaultthreadtraits)|A classe de características de thread do padrão.|  
|[LPCURL](#lpcurl)|Um ponteiro para uma constante [CUrl](../../atl/reference/curl-class.md) objeto.|  
|[LPURL](#lpurl)|Um ponteiro para um [CUrl](../../atl/reference/curl-class.md) objeto.|  
  
##  <a name="_atl_base_module"></a>_ATL_BASE_MODULE  
 Definido como um typedef com base em _ATL_BASE_MODULE70.  
  
```   
typedef ATL::_ATL_BASE_MODULE70 _ATL_BASE_MODULE;   
```  
  
### <a name="remarks"></a>Comentários  
 Usado em cada projeto ATL. Com base em [_ATL_BASE_MODULE70](../../atl/reference/atl-base-module70-structure.md).  
  
 Classes que fazem parte das Classes de módulo ATL 7.0 derivar a estrutura _ATL_BASE_MODULE.  Para obter mais informações sobre Classes de módulo ATL, consulte [Classes de módulos COM](../../atl/com-modules-classes.md).  

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlcore.h

##  <a name="_atl_com_module"></a>_ATL_COM_MODULE  
 Definido como um typedef com base em _ATL_COM_MODULE70.  
  
```   
typedef ATL::_ATL_COM_MODULE70 _ATL_COM_MODULE;   
```  
  
### <a name="remarks"></a>Comentários  
 Usado por projetos ATL que usam recursos de COM. Com base em [_ATL_COM_MODULE70](../../atl/reference/atl-com-module70-structure.md).  

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlbase
  
##  <a name="_atl_module"></a>_ATL_MODULE  
 Definido como um typedef com base em _ATL_MODULE70.  
  
```   
typedef ATL::_ATL_MODULE70 _ATL_MODULE;   
```  
## <a name="requirements"></a>Requisitos
**Cabeçalho:** 
  
### <a name="remarks"></a>Comentários  
 Com base em [_ATL_MODULE70](../../atl/reference/atl-module70-structure.md).  
  
##  <a name="_atl_win_module"></a>_ATL_WIN_MODULE  
 Definido como um typedef com base em _ATL_WIN_MODULE70.  
  
```   
typedef ATL::_ATL_WIN_MODULE70 _ATL_WIN_MODULE; 
 
```  
  
### <a name="remarks"></a>Comentários  
 Usado por qualquer projeto ATL que usam recursos de janelas. Com base em [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md).  

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlbase 
  
##  <a name="atl_url_port"></a>ATL_URL_PORT 
  O tipo usado pelo [CUrl](curl-class.md) para especificar um número de porta.
```  
typedef WORD ATL_URL_PORT;
```  

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlutil.h

##  <a name="ccomdispatchdriver"></a>CComDispatchDriver  
 Essa classe gerencia ponteiros de interface COM.  
  
```   
typedef CComQIPtr<IDispatch, &__uuidof(IDispatch)> CComDispatchDriver;   
```  
## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlbase
  
##  <a name="ccomglobalsthreadmodel"></a>CComGlobalsThreadModel  
 Chama o thread apropriado métodos do modelo, independentemente do modelo de threading que está sendo usado.  
  
```   
#if defined(_ATL_SINGLE_THREADED)  
typedef CComSingleThreadModel CComGlobalsThreadModel;  
#elif defined(_ATL_APARTMENT_THREADED)  
typedef CComMultiThreadModel CComGlobalsThreadModel;  
#elif defined(_ATL_FREE_THREADED)  
typedef CComMultiThreadModel CComGlobalsThreadModel;  
#else  
#pragma message ("No global threading model defined")  
#endif   
```  
  
### <a name="remarks"></a>Comentários  
 Dependendo do modelo de threading usado pelo seu aplicativo, o `typedef` nome `CComGlobalsThreadModel` faz referência a um [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md). Essas classes fornecem adicionais `typedef` nomes para fazer referência a uma classe de seção crítica.  
  
> [!NOTE]
> `CComGlobalsThreadModel`não faz referência a classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).  
  
 Usando `CComGlobalsThreadModel` libera você da especificação de uma determinada classe de modelo de threading. Independentemente do modelo de threading que está sendo usado, os métodos apropriados serão chamados.  
  
 Além `CComGlobalsThreadModel`, ATL fornece o `typedef` nome [CComObjectThreadModel](#ccomobjectthreadmodel). A classe referenciada por cada `typedef` depende do modelo de threading usado, conforme mostrado na tabela a seguir:  
  
|typedef|Thread único|apartment threading|Livre de threading|  
|-------------|----------------------|-------------------------|--------------------|  
|`CComObjectThreadModel`|S|S|M|  
|`CComGlobalsThreadModel`|S|M|M|  
  
 S = `CComSingleThreadModel`; M =`CComMultiThreadModel`  
  
 Use `CComObjectThreadModel` dentro de uma classe de objeto único. Use `CComGlobalsThreadModel` em um objeto que é globalmente disponível para seu programa, ou quando você deseja proteger recursos do módulo entre vários threads.  

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlbase
  
##  <a name="ccomobjectthreadmodel"></a>CComObjectThreadModel  
 Chama o thread apropriado métodos do modelo, independentemente do modelo de threading que está sendo usado.  
  
```   
#if defined(_ATL_SINGLE_THREADED)  
typedef CComSingleThreadModel CComObjectThreadModel;  
#elif defined(_ATL_APARTMENT_THREADED)  
typedef CComSingleThreadModel CComObjectThreadModel;  
#elif defined(_ATL_FREE_THREADED)  
typedef CComMultiThreadModel CComObjectThreadModel;  
#else  
#pragma message ("No global threading model defined")  
#endif   
```  
  
### <a name="remarks"></a>Comentários  
 Dependendo do modelo de threading usado pelo seu aplicativo, o `typedef` nome `CComObjectThreadModel` faz referência a um [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md). Essas classes fornecem adicionais `typedef` nomes para fazer referência a uma classe de seção crítica.  
  
> [!NOTE]
> `CComObjectThreadModel`não faz referência a classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).  
  
 Usando `CComObjectThreadModel` libera você da especificação de uma determinada classe de modelo de threading. Independentemente do modelo de threading que está sendo usado, os métodos apropriados serão chamados.  
  
 Além `CComObjectThreadModel`, ATL fornece o `typedef` nome [CComGlobalsThreadModel](#ccomglobalsthreadmodel). A classe referenciada por cada `typedef` depende do modelo de threading usado, conforme mostrado na tabela a seguir:  
  
|typedef|Thread único|apartment threading|Livre de threading|  
|-------------|----------------------|-------------------------|--------------------|  
|`CComObjectThreadModel`|S|S|M|  
|`CComGlobalsThreadModel`|S|M|M|  
  
 S = `CComSingleThreadModel`; M =`CComMultiThreadModel`  
  
 Use `CComObjectThreadModel` dentro de uma classe de objeto único. Use `CComGlobalsThreadModel` em um objeto que seja globalmente disponíveis para o seu programa, ou quando você deseja proteger recursos do módulo entre vários threads.  

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlbase
  
##  <a name="ccontainedwindow"></a>CContainedWindow  
 Essa classe é uma especialização de **CContainedWindowT.**  
  
```   
typedef CContainedWindowT<CWindow> CContainedWindow;   
```  

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlwin.h
  
### <a name="remarks"></a>Comentários  
 `CContainedWindow`é uma especialização de [CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md). Se você deseja alterar a classe base ou características, use `CContainedWindowT` diretamente.  
  
##  <a name="cpath"></a>CPath  
 Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CString`.  
  
```   
typedef CPathT<CString> CPath;   
```  

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlpath.h
  
##  <a name="cpatha"></a>CPathA  
 Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CStringA`.  
  
```   
typedef CPathT<CStringA> CPathA;   
```

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlpath.h  
  
##  <a name="cpathw"></a>CPathW  
 Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CStringW`.  
  
```   
typedef ATL::CPathT<CStringW> CPathW;   
```  
## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlpath.h
  
##  <a name="csimplevalarray"></a>CSimpleValArray  
 Representa uma matriz de armazenamento de tipos simples.  
  
```   
#define CSimpleValArray CSimpleArray   
```  

  
### <a name="remarks"></a>Comentários  
 `CSimpleValArray`é fornecido para a criação e gerenciamento de matrizes que contêm tipos de dados simples. É um simples #define do [CSimpleArray](../../atl/reference/csimplearray-class.md).  


## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlsimpcoll.h
  
##  <a name="lpcurl"></a>LPCURL  
 Um ponteiro para uma constante [CUrl](../../atl/reference/curl-class.md) objeto.  
  
```   
typedef const CUrl* LPCURL;   
```  

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlutil.h

##  <a name="defaultthreadtraits"></a>DefaultThreadTraits
A classe de características de thread do padrão.

### <a name="syntax"></a>Sintaxe
```  
      #if defined(_MT)  
   typedef CRTThreadTraits DefaultThreadTraits;  
#else  
   typedef Win32ThreadTraits DefaultThreadTraits;  
#endif  
```

## <a name="remarks"></a>Comentários
Se o projeto atual usa CRT multithread, DefaultThreadTraits é definido como CRTThreadTraits. Caso contrário, Win32ThreadTraits será usado.


## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlbase
  
##  <a name="lpurl"></a>LPURL  
 Um ponteiro para um [CUrl](../../atl/reference/curl-class.md) objeto.  
  
```   
typedef CUrl* LPURL;   
```  

## <a name="requirements"></a>Requisitos
**Cabeçalho:** atlutil.h


## <a name="see-also"></a>Consulte também  
 [Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)   
 [Funções](../../atl/reference/atl-functions.md)   
 [Variáveis globais](../../atl/reference/atl-global-variables.md)   
 [Estruturas](../../atl/reference/atl-structures.md)   
 [Macros](../../atl/reference/atl-macros.md)   
 [Classes](../../atl/reference/atl-classes.md)