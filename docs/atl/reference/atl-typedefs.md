---
title: Typedefs ATL
ms.date: 11/04/2016
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
helpviewer_keywords:
- typedefs, ATL
- typedefs
- ATL, typedefs
ms.assetid: 7dd05baa-3efb-4e3b-af23-793c610f4560
ms.openlocfilehash: 26e4e80ed3110351130731e6030427d25fc4a0ea
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168718"
---
# <a name="atl-typedefs"></a>Typedefs ATL

O Active Template Library inclui os seguintes TYPEDEFs.

|||
|-|-|
|[_ATL_BASE_MODULE](#_atl_base_module)|Definido como um typedef baseado em [_ATL_BASE_MODULE70](../../atl/reference/atl-base-module70-structure.md).|
|[_ATL_COM_MODULE](#_atl_com_module)|Definido como um typedef baseado em [_ATL_COM_MODULE70](../../atl/reference/atl-com-module70-structure.md).|
|[_ATL_MODULE](#_atl_module)|Definido como um typedef baseado em [_ATL_MODULE70](../../atl/reference/atl-module70-structure.md).|
|[_ATL_WIN_MODULE](#_atl_win_module)|Definido como um typedef baseado em [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md)|
|[ATL_URL_PORT](#atl_url_port)|O tipo usado por [ondulação](../../atl/reference/curl-class.md) para especificar um número de porta.|
|[CComDispatchDriver](#ccomdispatchdriver)|Essa classe gerencia ponteiros de interface COM.|
|[CComGlobalsThreadModel](#ccomglobalsthreadmodel)|Chama os métodos de modelo de thread apropriados, independentemente do modelo de Threading que está sendo usado.|
|[CComObjectThreadModel](#ccomobjectthreadmodel)|Chama os métodos de modelo de thread apropriados, independentemente do modelo de Threading que está sendo usado.|
|[CContainedWindow](#ccontainedwindow)|Essa classe é uma especialização `CContainedWindowT`do.|
|[CPath](#cpath)|Uma especialização [CPathT](../../atl/reference/cpatht-class.md) de CPathT `CString`usando.|
|[CPathA](#cpatha)|Uma especialização [CPathT](../../atl/reference/cpatht-class.md) de CPathT `CStringA`usando.|
|[CPathW](#cpathw)|Uma especialização [CPathT](../../atl/reference/cpatht-class.md) de CPathT `CStringW`usando.|
|[CSimpleValArray](#csimplevalarray)|Representa uma matriz para armazenar tipos simples.|
|[DefaultThreadTraits](#defaultthreadtraits)|A classe de características de thread padrão.|
|[LPCURL](#lpcurl)|Um ponteiro para um objeto de [ondulação](../../atl/reference/curl-class.md) constante.|
|[LPURL](#lpurl)|Um ponteiro para um objeto de [ondulação](../../atl/reference/curl-class.md) .|

## <a name="_atl_base_module"></a><a name="_atl_base_module"></a>_ATL_BASE_MODULE

Definido como um typedef baseado em _ATL_BASE_MODULE70.

```cpp
typedef ATL::_ATL_BASE_MODULE70 _ATL_BASE_MODULE;
```

### <a name="remarks"></a>Comentários

Usado em todos os projetos ATL. Com base em [_ATL_BASE_MODULE70](../../atl/reference/atl-base-module70-structure.md).

As classes que fazem parte das classes do módulo ATL 7,0 derivam da estrutura _ATL_BASE_MODULE.  Para obter mais informações sobre classes de módulo do ATL, consulte [classes de módulos com](../../atl/com-modules-classes.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore. h

## <a name="_atl_com_module"></a><a name="_atl_com_module"></a>_ATL_COM_MODULE

Definido como um typedef baseado em _ATL_COM_MODULE70.

```cpp
typedef ATL::_ATL_COM_MODULE70 _ATL_COM_MODULE;
```

### <a name="remarks"></a>Comentários

Usado por projetos ATL que usam recursos COM. Com base em [_ATL_COM_MODULE70](../../atl/reference/atl-com-module70-structure.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="_atl_module"></a><a name="_atl_module"></a>_ATL_MODULE

Definido como um typedef baseado em _ATL_MODULE70.

```cpp
typedef ATL::_ATL_MODULE70 _ATL_MODULE;
```

### <a name="requirements"></a>Requisitos

**Verga**

### <a name="remarks"></a>Comentários

Com base em [_ATL_MODULE70](../../atl/reference/atl-module70-structure.md).

## <a name="_atl_win_module"></a><a name="_atl_win_module"></a>_ATL_WIN_MODULE

Definido como um typedef baseado em _ATL_WIN_MODULE70.

```cpp
typedef ATL::_ATL_WIN_MODULE70 _ATL_WIN_MODULE;
```

### <a name="remarks"></a>Comentários

Usado por qualquer projeto ATL que use recursos de janelas. Com base em [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="atl_url_port"></a><a name="atl_url_port"></a>ATL_URL_PORT

O tipo usado por [ondulação](curl-class.md) para especificar um número de porta.

```cpp
typedef WORD ATL_URL_PORT;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil. h

## <a name="ccomdispatchdriver"></a><a name="ccomdispatchdriver"></a>CComDispatchDriver

Essa classe gerencia ponteiros de interface COM.

```cpp
typedef CComQIPtr<IDispatch, &__uuidof(IDispatch)> CComDispatchDriver;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="ccomglobalsthreadmodel"></a><a name="ccomglobalsthreadmodel"></a>CComGlobalsThreadModel

Chama os métodos de modelo de thread apropriados, independentemente do modelo de Threading que está sendo usado.

```cpp
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

Dependendo do modelo de Threading usado pelo seu aplicativo, o `CComGlobalsThreadModel` nome do **typedef** faz referência a [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou a [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md). Essas classes fornecem nomes `typedef` adicionais para fazer referência a uma classe de seção crítica.

> [!NOTE]
> `CComGlobalsThreadModel`Não faz referência à classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).

O `CComGlobalsThreadModel` uso do libera você de especificar uma classe de modelo de Threading específica. Independentemente do modelo de Threading que está sendo usado, os métodos apropriados serão chamados.

Além disso, `CComGlobalsThreadModel`a ATL fornece o nome de **typedef** [CComObjectThreadModel](#ccomobjectthreadmodel). A classe referenciada por `typedef` cada depende do modelo de Threading usado, conforme mostrado na tabela a seguir:

|typedef|Thread único|Threading de apartamento|Threading gratuito|
|-------------|----------------------|-------------------------|--------------------|
|`CComObjectThreadModel`|S|S|M|
|`CComGlobalsThreadModel`|S|M|M|

S = `CComSingleThreadModel`; M =`CComMultiThreadModel`

Use `CComObjectThreadModel` em uma única classe de objeto. Use `CComGlobalsThreadModel` em um objeto que esteja globalmente disponível para seu programa ou quando desejar proteger os recursos do módulo em vários threads.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="ccomobjectthreadmodel"></a><a name="ccomobjectthreadmodel"></a>CComObjectThreadModel

Chama os métodos de modelo de thread apropriados, independentemente do modelo de Threading que está sendo usado.

```cpp
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

Dependendo do modelo de Threading usado pelo seu aplicativo `typedef` , o nome `CComObjectThreadModel` faz referência a [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou a [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md). Essas classes fornecem nomes `typedef` adicionais para fazer referência a uma classe de seção crítica.

> [!NOTE]
> `CComObjectThreadModel`Não faz referência à classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).

O `CComObjectThreadModel` uso do libera você de especificar uma classe de modelo de Threading específica. Independentemente do modelo de Threading que está sendo usado, os métodos apropriados serão chamados.

Além disso, `CComObjectThreadModel`a ATL fornece o nome de **typedef** [CComGlobalsThreadModel](#ccomglobalsthreadmodel). A classe referenciada por cada **typedef** depende do modelo de Threading usado, conforme mostrado na tabela a seguir:

|typedef|Thread único|Threading de apartamento|Threading gratuito|
|-------------|----------------------|-------------------------|--------------------|
|`CComObjectThreadModel`|S|S|M|
|`CComGlobalsThreadModel`|S|M|M|

S = `CComSingleThreadModel`; M =`CComMultiThreadModel`

Use `CComObjectThreadModel` em uma única classe de objeto. Use `CComGlobalsThreadModel` em um objeto que esteja globalmente disponível para seu programa ou quando desejar proteger recursos de módulo em vários threads.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="ccontainedwindow"></a><a name="ccontainedwindow"></a>CContainedWindow

Essa classe é uma especialização `CContainedWindowT`do.

```cpp
typedef CContainedWindowT<CWindow> CContainedWindow;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

### <a name="remarks"></a>Comentários

`CContainedWindow`é uma especialização de [CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md). Se você quiser alterar a classe base ou as características, use `CContainedWindowT` diretamente.

## <a name="cpath"></a><a name="cpath"></a>CPath

Uma especialização [CPathT](../../atl/reference/cpatht-class.md) de CPathT `CString`usando.

```cpp
typedef CPathT<CString> CPath;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpath. h

## <a name="cpatha"></a><a name="cpatha"></a>CPathA

Uma especialização [CPathT](../../atl/reference/cpatht-class.md) de CPathT `CStringA`usando.

```cpp
typedef CPathT<CStringA> CPathA;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpath. h

## <a name="cpathw"></a><a name="cpathw"></a>CPathW

Uma especialização [CPathT](../../atl/reference/cpatht-class.md) de CPathT `CStringW`usando.

```cpp
typedef ATL::CPathT<CStringW> CPathW;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpath. h

## <a name="csimplevalarray"></a><a name="csimplevalarray"></a>CSimpleValArray

Representa uma matriz para armazenar tipos simples.

```cpp
#define CSimpleValArray CSimpleArray
```

### <a name="remarks"></a>Comentários

`CSimpleValArray`é fornecido para criar e gerenciar matrizes que contenham tipos de dados simples. É um #define simples de [CSimpleArray](../../atl/reference/csimplearray-class.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpcoll. h

## <a name="lpcurl"></a><a name="lpcurl"></a>LPCURL

Um ponteiro para um objeto de [ondulação](../../atl/reference/curl-class.md) constante.

```cpp
typedef const CUrl* LPCURL;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil. h

## <a name="defaultthreadtraits"></a><a name="defaultthreadtraits"></a>DefaultThreadTraits

A classe de características de thread padrão.

### <a name="syntax"></a>Sintaxe

```cpp
#if defined(_MT)
   typedef CRTThreadTraits DefaultThreadTraits;
#else
   typedef Win32ThreadTraits DefaultThreadTraits;
#endif
```

## <a name="remarks"></a>Comentários

Se o projeto atual usar o CRT multi-threaded, DefaultThreadTraits será definido como CRTThreadTraits. Caso contrário, Win32ThreadTraits será usado.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="lpurl"></a><a name="lpurl"></a>LPURL

Um ponteiro para um objeto de [ondulação](../../atl/reference/curl-class.md) .

```cpp
typedef CUrl* LPURL;
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil. h

## <a name="see-also"></a>Confira também

[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)<br/>
[Funções](../../atl/reference/atl-functions.md)<br/>
[Variáveis globais](../../atl/reference/atl-global-variables.md)<br/>
[Classes e structs](../../atl/reference/atl-classes.md)<br/>
[Macros](../../atl/reference/atl-macros.md)
