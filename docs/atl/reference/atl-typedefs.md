---
title: Typedefs ATL | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: 'index-page '
dev_langs:
- C++
helpviewer_keywords:
- typedefs, ATL
- typedefs
- ATL, typedefs
ms.assetid: 7dd05baa-3efb-4e3b-af23-793c610f4560
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
ms.sourcegitcommit: 347e7bf7cd9173fb2815f44fc052ec23ab4055a6
ms.openlocfilehash: aa57212b602538e4e8d2854c6075562e72472796
ms.lasthandoff: 02/25/2017

---
# <a name="atl-typedefs"></a>Typedefs ATL
O Active Template Library inclui as seguintes definições de tipo.  
  
|||  
|-|-|  
|[_ATL_BASE_MODULE](#_atl_base_module)|Definido como um typedef com base em [_ATL_BASE_MODULE70](../../atl/reference/atl-base-module70-structure.md).|  
|[_ATL_COM_MODULE](#_atl_com_module)|Definido como um typedef com base em [_ATL_COM_MODULE70](../../atl/reference/atl-com-module70-structure.md).|  
|[_ATL_MODULE](#_atl_module)|Definido como um typedef com base em [_ATL_MODULE70](../../atl/reference/atl-module70-structure.md).|  
|[_ATL_WIN_MODULE](#_atl_win_module)|Definido como um typedef com base em [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md)|  
|[ATL_URL_PORT](#atl_url_port)|O tipo usado pelo [CUrl](../../atl/reference/curl-class.md) para especificar um número de porta.|  
|[CComDispatchDriver](#ccomdispatchdriver)|Essa classe gerencia os ponteiros de interface.|  
|[CComGlobalsThreadModel](#ccomglobalsthreadmodel)|O segmento apropriado chama métodos do modelo, independentemente do modelo de threading que está sendo usado.|  
|[CComObjectThreadModel](#ccomobjectthreadmodel)|O segmento apropriado chama métodos do modelo, independentemente do modelo de threading que está sendo usado.|  
|[CContainedWindow](#ccontainedwindow)|Essa classe é uma especialização de **CContainedWindowT.**|  
|[CPath](#cpath)|Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CString`.|  
|[CPathA](#cpatha)|Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CStringA`.|  
|[CPathW](#cpathw)|Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CStringW`.|  
|[CSimpleValArray](#csimplevalarray)|Representa uma matriz para armazenar tipos simples.|  
|[DefaultThreadTraits](#defaultthreadtraits)|A classe de características de threads padrão.|  
|[LPCURL](#lpcurl)|Um ponteiro para uma constante [CUrl](../../atl/reference/curl-class.md) objeto.|  
|[LPURL](#lpurl)|Um ponteiro para um [CUrl](../../atl/reference/curl-class.md) objeto.|  
  
##  <a name="a-nameatlbasemodulea--atlbasemodule"></a><a name="_atl_base_module"></a>_ATL_BASE_MODULE  
 Definido como um typedef com base em _ATL_BASE_MODULE70.  
  
```   
typedef ATL::_ATL_BASE_MODULE70 _ATL_BASE_MODULE;   
```  
  
### <a name="remarks"></a>Comentários  
 Usado em cada projeto ATL. Com base em [_ATL_BASE_MODULE70](../../atl/reference/atl-base-module70-structure.md).  
  
 Classes que fazem parte das Classes ATL 7.0 módulo derivar a estrutura _ATL_BASE_MODULE.  Para obter mais informações sobre Classes de módulo ATL, consulte [Classes de módulos COM](../../atl/com-modules-classes.md).  
  
##  <a name="a-nameatlcommodulea--atlcommodule"></a><a name="_atl_com_module"></a>_ATL_COM_MODULE  
 Definido como um typedef com base em _ATL_COM_MODULE70.  
  
```   
typedef ATL::_ATL_COM_MODULE70 _ATL_COM_MODULE;   
```  
  
### <a name="remarks"></a>Comentários  
 Usado por projetos do ATL que usam recursos de COM. Com base em [_ATL_COM_MODULE70](../../atl/reference/atl-com-module70-structure.md).  
  
##  <a name="a-nameatlmodulea--atlmodule"></a><a name="_atl_module"></a>_ATL_MODULE  
 Definido como um typedef com base em _ATL_MODULE70.  
  
```   
typedef ATL::_ATL_MODULE70 _ATL_MODULE;   
```  
  
### <a name="remarks"></a>Comentários  
 Com base em [_ATL_MODULE70](../../atl/reference/atl-module70-structure.md).  
  
##  <a name="a-nameatlwinmodulea--atlwinmodule"></a><a name="_atl_win_module"></a>_ATL_WIN_MODULE  
 Definido como um typedef com base em _ATL_WIN_MODULE70.  
  
```   
typedef ATL::_ATL_WIN_MODULE70 _ATL_WIN_MODULE; 
 
```  
  
### <a name="remarks"></a>Comentários  
 Usado por nenhum projeto ATL que usam recursos de janelas. Com base em [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md).  
  
##  <a name="a-nameatlurlporta--atlurlport"></a><a name="atl_url_port"></a>ATL_URL_PORT 
  O tipo usado pelo [CUrl](curl-class.md) para especificar um número de porta.
```  
typedef WORD ATL_URL_PORT;
```  

##  <a name="a-nameccomdispatchdrivera--ccomdispatchdriver"></a><a name="ccomdispatchdriver"></a>CComDispatchDriver  
 Essa classe gerencia os ponteiros de interface.  
  
```   
typedef CComQIPtr<IDispatch, &__uuidof(IDispatch)> CComDispatchDriver;   
```  
  
##  <a name="a-nameccomglobalsthreadmodela--ccomglobalsthreadmodel"></a><a name="ccomglobalsthreadmodel"></a>CComGlobalsThreadModel  
 O segmento apropriado chama métodos do modelo, independentemente do modelo de threading que está sendo usado.  
  
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
 Dependendo do modelo de threading usado pelo seu aplicativo, o `typedef` nome `CComGlobalsThreadModel` referencia um [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md). Essas classes fornecem adicionais `typedef` nomes para fazer referência a uma classe de seção crítica.  
  
> [!NOTE]
> `CComGlobalsThreadModel`não faz referência a classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).  
  
 Usando `CComGlobalsThreadModel` libera você da especificação de uma determinada classe de modelo de threading. Independentemente do modelo de threading que está sendo usado, os métodos apropriados serão chamados.  
  
 Além `CComGlobalsThreadModel`, a ATL fornece o `typedef` nome [CComObjectThreadModel](#ccomobjectthreadmodel). A classe referenciada por cada `typedef` depende do modelo de threading usado, conforme mostrado na tabela a seguir:  
  
|typedef|Threading único|Apartment threading|Livre de threading|  
|-------------|----------------------|-------------------------|--------------------|  
|`CComObjectThreadModel`|S|S|M|  
|`CComGlobalsThreadModel`|S|M|M|  
  
 S= `CComSingleThreadModel`; M =`CComMultiThreadModel`  
  
 Use `CComObjectThreadModel` dentro de uma classe de objeto único. Use `CComGlobalsThreadModel` em um objeto que está disponível globalmente para o seu programa ou quando você deseja proteger recursos do módulo entre vários threads.  
  
##  <a name="a-nameccomobjectthreadmodela--ccomobjectthreadmodel"></a><a name="ccomobjectthreadmodel"></a>CComObjectThreadModel  
 O segmento apropriado chama métodos do modelo, independentemente do modelo de threading que está sendo usado.  
  
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
 Dependendo do modelo de threading usado pelo seu aplicativo, o `typedef` nome `CComObjectThreadModel` referencia um [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md). Essas classes fornecem adicionais `typedef` nomes para fazer referência a uma classe de seção crítica.  
  
> [!NOTE]
> `CComObjectThreadModel`não faz referência a classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).  
  
 Usando `CComObjectThreadModel` libera você da especificação de uma determinada classe de modelo de threading. Independentemente do modelo de threading que está sendo usado, os métodos apropriados serão chamados.  
  
 Além `CComObjectThreadModel`, a ATL fornece o `typedef` nome [CComGlobalsThreadModel](#ccomglobalsthreadmodel). A classe referenciada por cada `typedef` depende do modelo de threading usado, conforme mostrado na tabela a seguir:  
  
|typedef|Threading único|Apartment threading|Livre de threading|  
|-------------|----------------------|-------------------------|--------------------|  
|`CComObjectThreadModel`|S|S|M|  
|`CComGlobalsThreadModel`|S|M|M|  
  
 S= `CComSingleThreadModel`; M =`CComMultiThreadModel`  
  
 Use `CComObjectThreadModel` dentro de uma classe de objeto único. Use `CComGlobalsThreadModel` em um objeto que está disponível globalmente para o seu programa, ou quando você deseja proteger recursos do módulo entre vários threads.  
  
##  <a name="a-nameccontainedwindowa--ccontainedwindow"></a><a name="ccontainedwindow"></a>CContainedWindow  
 Essa classe é uma especialização de **CContainedWindowT.**  
  
```   
typedef CContainedWindowT<CWindow> CContainedWindow;   
```  
  
### <a name="remarks"></a>Comentários  
 `CContainedWindow`é uma especialização de [CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md). Se você deseja alterar a classe base ou características, use `CContainedWindowT` diretamente.  
  
##  <a name="a-namecpatha--cpath"></a><a name="cpath"></a>CPath  
 Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CString`.  
  
```   
typedef CPathT<CString> CPath;   
```  
  
##  <a name="a-namecpathaa--cpatha"></a><a name="cpatha"></a>CPathA  
 Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CStringA`.  
  
```   
typedef CPathT<CStringA> CPathA;   
```  
  
##  <a name="a-namecpathwa--cpathw"></a><a name="cpathw"></a>CPathW  
 Uma especialização de [CPathT](../../atl/reference/cpatht-class.md) usando `CStringW`.  
  
```   
typedef ATL::CPathT<CStringW> CPathW;   
```  
  
##  <a name="a-namecsimplevalarraya--csimplevalarray"></a><a name="csimplevalarray"></a>CSimpleValArray  
 Representa uma matriz para armazenar tipos simples.  
  
```   
#define CSimpleValArray CSimpleArray   
```  
  
### <a name="remarks"></a>Comentários  
 `CSimpleValArray`é fornecida para criar e gerenciar matrizes que contêm tipos de dados simples. É um simples #define do [CSimpleArray](../../atl/reference/csimplearray-class.md).  
  
##  <a name="a-namelpcurla--lpcurl"></a><a name="lpcurl"></a>LPCURL  
 Um ponteiro para uma constante [CUrl](../../atl/reference/curl-class.md) objeto.  
  
```   
typedef const CUrl* LPCURL;   
```  

##  <a name="a-namedefaultthreadtraitsa--defaultthreadtraits"></a><a name="defaultthreadtraits"></a>DefaultThreadTraits
A classe de características de threads padrão.

### <a name="syntax"></a>Sintaxe
```  
      #if defined(_MT)  
   typedef CRTThreadTraits DefaultThreadTraits;  
#else  
   typedef Win32ThreadTraits DefaultThreadTraits;  
#endif  
```

## <a name="remarks"></a>Comentários
Se o projeto atual usa o CRT multithread, DefaultThreadTraits é definido como CRTThreadTraits. Caso contrário, Win32ThreadTraits será usado.
  
##  <a name="a-namelpurla--lpurl"></a><a name="lpurl"></a>LPURL  
 Um ponteiro para um [CUrl](../../atl/reference/curl-class.md) objeto.  
  
```   
typedef CUrl* LPURL;   
```  
  
## <a name="see-also"></a>Consulte também  
 [Componentes da área de trabalho COM de ATL](../../atl/atl-com-desktop-components.md)   
 [Funções](../../atl/reference/atl-functions.md)   
 [Variáveis globais](../../atl/reference/atl-global-variables.md)   
 [Estruturas](../../atl/reference/atl-structures.md)   
 [Macros](../../atl/reference/atl-macros.md)   
 [Classes](../../atl/reference/atl-classes.md)
