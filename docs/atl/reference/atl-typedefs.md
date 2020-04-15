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
ms.openlocfilehash: 5548bee36ac52dbd6add31241714b0404289be45
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319192"
---
# <a name="atl-typedefs"></a>Typedefs ATL

A Biblioteca de Modelos Ativos inclui os seguintes tipos.

|||
|-|-|
|[_ATL_BASE_MODULE](#_atl_base_module)|Definido como um typedef com base em [_ATL_BASE_MODULE70](../../atl/reference/atl-base-module70-structure.md).|
|[_ATL_COM_MODULE](#_atl_com_module)|Definido como um typedef com base em [_ATL_COM_MODULE70](../../atl/reference/atl-com-module70-structure.md).|
|[_ATL_MODULE](#_atl_module)|Definido como um typedef com base em [_ATL_MODULE70](../../atl/reference/atl-module70-structure.md).|
|[_ATL_WIN_MODULE](#_atl_win_module)|Definido como um typedef com base em [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md)|
|[Atl_url_port](#atl_url_port)|O tipo usado por [CUrl](../../atl/reference/curl-class.md) para especificar um número de porta.|
|[CComDispatchDriver](#ccomdispatchdriver)|Esta classe gerencia ponteiros de interface COM.|
|[Ccomglobalsthreadmodel](#ccomglobalsthreadmodel)|Chama os métodos de modelo de rosca apropriados, independentemente do modelo de rosca que está sendo usado.|
|[Ccomobjectthreadmodel](#ccomobjectthreadmodel)|Chama os métodos de modelo de rosca apropriados, independentemente do modelo de rosca que está sendo usado.|
|[Ccontainedwindow](#ccontainedwindow)|Esta aula é uma `CContainedWindowT`especialização de .|
|[Cpath](#cpath)|Uma especialização do [CPathT](../../atl/reference/cpatht-class.md) usando `CString`.|
|[Cpatha](#cpatha)|Uma especialização do [CPathT](../../atl/reference/cpatht-class.md) usando `CStringA`.|
|[CpathW](#cpathw)|Uma especialização do [CPathT](../../atl/reference/cpatht-class.md) usando `CStringW`.|
|[CSimpleValArray](#csimplevalarray)|Representa uma matriz para armazenar tipos simples.|
|[Padrão'SThreadTraits](#defaultthreadtraits)|A classe de características de segmento padrão.|
|[LPCURL](#lpcurl)|Um ponteiro para um objeto [CUrl](../../atl/reference/curl-class.md) constante.|
|[LPURL](#lpurl)|Um ponteiro para um objeto [CUrl.](../../atl/reference/curl-class.md)|

## <a name="_atl_base_module"></a><a name="_atl_base_module"></a>_ATL_BASE_MODULE

Definido como um typedef baseado em _ATL_BASE_MODULE70.

```
typedef ATL::_ATL_BASE_MODULE70 _ATL_BASE_MODULE;
```

### <a name="remarks"></a>Comentários

Usado em todos os projetos ATL. Baseado em [_ATL_BASE_MODULE70](../../atl/reference/atl-base-module70-structure.md).

As aulas que fazem parte das classes do módulo ATL 7.0 derivam da estrutura _ATL_BASE_MODULE.  Para obter mais informações sobre as classes de módulos ATL, consulte [com aulas de módulos COM](../../atl/com-modules-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

## <a name="_atl_com_module"></a><a name="_atl_com_module"></a>_ATL_COM_MODULE

Definido como um typedef com base em _ATL_COM_MODULE70.

```
typedef ATL::_ATL_COM_MODULE70 _ATL_COM_MODULE;
```

### <a name="remarks"></a>Comentários

Usado por projetos ATL que usam recursos COM. Baseado em [_ATL_COM_MODULE70](../../atl/reference/atl-com-module70-structure.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="_atl_module"></a><a name="_atl_module"></a>_ATL_MODULE

Definido como um typedef com base em _ATL_MODULE70.

```
typedef ATL::_ATL_MODULE70 _ATL_MODULE;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**

### <a name="remarks"></a>Comentários

Baseado em [_ATL_MODULE70](../../atl/reference/atl-module70-structure.md).

## <a name="_atl_win_module"></a><a name="_atl_win_module"></a>_ATL_WIN_MODULE

Definido como um typedef com base em _ATL_WIN_MODULE70.

```
typedef ATL::_ATL_WIN_MODULE70 _ATL_WIN_MODULE;
```

### <a name="remarks"></a>Comentários

Usado por quaisquer projetos ATL que utilizem recursos de janelas. Baseado em [_ATL_WIN_MODULE70](../../atl/reference/atl-win-module70-structure.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="atl_url_port"></a><a name="atl_url_port"></a>Atl_url_port

O tipo usado por [CUrl](curl-class.md) para especificar um número de porta.

```
typedef WORD ATL_URL_PORT;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="ccomdispatchdriver"></a><a name="ccomdispatchdriver"></a>CComDispatchDriver

Esta classe gerencia ponteiros de interface COM.

```
typedef CComQIPtr<IDispatch, &__uuidof(IDispatch)> CComDispatchDriver;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomglobalsthreadmodel"></a><a name="ccomglobalsthreadmodel"></a>Ccomglobalsthreadmodel

Chama os métodos de modelo de rosca apropriados, independentemente do modelo de rosca que está sendo usado.

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

Dependendo do modelo de rosca usado pelo aplicativo, o `CComGlobalsThreadModel` nome **typedef** faz referência a [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md). Essas classes `typedef` fornecem nomes adicionais para fazer referência a uma classe de seção crítica.

> [!NOTE]
> `CComGlobalsThreadModel`não faz referência classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).

O `CComGlobalsThreadModel` uso libera você de especificar uma classe de modelo de rosca específica. Independentemente do modelo de rosca utilizado, os métodos apropriados serão chamados.

Além disso, a `CComGlobalsThreadModel`ATL fornece o nome **tipo** [CComObjectThreadModel](#ccomobjectthreadmodel). A classe referenciada `typedef` por cada um depende do modelo de rosca utilizado, conforme mostrado na tabela a seguir:

|typedef|Rosca única|Rosca do apartamento|Rosca grátis|
|-------------|----------------------|-------------------------|--------------------|
|`CComObjectThreadModel`|S|S|M|
|`CComGlobalsThreadModel`|S|M|M|

S= `CComSingleThreadModel`; M=`CComMultiThreadModel`

Use `CComObjectThreadModel` dentro de uma única classe de objeto. Use `CComGlobalsThreadModel` em um objeto que esteja disponível globalmente para o seu programa ou quando você quiser proteger os recursos do módulo em vários segmentos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomobjectthreadmodel"></a><a name="ccomobjectthreadmodel"></a>Ccomobjectthreadmodel

Chama os métodos de modelo de rosca apropriados, independentemente do modelo de rosca que está sendo usado.

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

Dependendo do modelo de rosca usado `typedef` `CComObjectThreadModel` pelo aplicativo, o nome faz referência a [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md). Essas classes `typedef` fornecem nomes adicionais para fazer referência a uma classe de seção crítica.

> [!NOTE]
> `CComObjectThreadModel`não faz referência classe [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md).

O `CComObjectThreadModel` uso libera você de especificar uma classe de modelo de rosca específica. Independentemente do modelo de rosca utilizado, os métodos apropriados serão chamados.

Além disso, a `CComObjectThreadModel`ATL fornece o nome **typedef** [CComGlobalsThreadModel](#ccomglobalsthreadmodel). A classe referenciada por cada **typedef** depende do modelo de rosca utilizado, conforme mostrado na tabela a seguir:

|typedef|Rosca única|Rosca do apartamento|Rosca grátis|
|-------------|----------------------|-------------------------|--------------------|
|`CComObjectThreadModel`|S|S|M|
|`CComGlobalsThreadModel`|S|M|M|

S= `CComSingleThreadModel`; M=`CComMultiThreadModel`

Use `CComObjectThreadModel` dentro de uma única classe de objeto. Use `CComGlobalsThreadModel` em um objeto que esteja disponível globalmente para o seu programa ou quando você quiser proteger os recursos do módulo em vários segmentos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccontainedwindow"></a><a name="ccontainedwindow"></a>Ccontainedwindow

Esta aula é uma `CContainedWindowT`especialização de .

```
typedef CContainedWindowT<CWindow> CContainedWindow;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

### <a name="remarks"></a>Comentários

`CContainedWindow`é uma especialização de [CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md). Se você quiser alterar a classe `CContainedWindowT` base ou características, use diretamente.

## <a name="cpath"></a><a name="cpath"></a>Cpath

Uma especialização do [CPathT](../../atl/reference/cpatht-class.md) usando `CString`.

```
typedef CPathT<CString> CPath;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpath.h

## <a name="cpatha"></a><a name="cpatha"></a>Cpatha

Uma especialização do [CPathT](../../atl/reference/cpatht-class.md) usando `CStringA`.

```
typedef CPathT<CStringA> CPathA;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpath.h

## <a name="cpathw"></a><a name="cpathw"></a>CpathW

Uma especialização do [CPathT](../../atl/reference/cpatht-class.md) usando `CStringW`.

```
typedef ATL::CPathT<CStringW> CPathW;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlpath.h

## <a name="csimplevalarray"></a><a name="csimplevalarray"></a>CSimpleValArray

Representa uma matriz para armazenar tipos simples.

```
#define CSimpleValArray CSimpleArray
```

### <a name="remarks"></a>Comentários

`CSimpleValArray`é fornecido para criar e gerenciar matrizes contendo tipos de dados simples. É uma simples #define do [CSimpleArray](../../atl/reference/csimplearray-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpcoll.h

## <a name="lpcurl"></a><a name="lpcurl"></a>LPCURL

Um ponteiro para um objeto [CUrl](../../atl/reference/curl-class.md) constante.

```
typedef const CUrl* LPCURL;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="defaultthreadtraits"></a><a name="defaultthreadtraits"></a>Padrão'SThreadTraits

A classe de características de segmento padrão.

### <a name="syntax"></a>Sintaxe

```
#if defined(_MT)
   typedef CRTThreadTraits DefaultThreadTraits;
#else
   typedef Win32ThreadTraits DefaultThreadTraits;
#endif
```

## <a name="remarks"></a>Comentários

Se o projeto atual usar o CRT multithreaded, DefaultThreadTraits será definido como CRTThreadTraits. Caso contrário, Win32ThreadTraits é usado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="lpurl"></a><a name="lpurl"></a>LPURL

Um ponteiro para um objeto [CUrl.](../../atl/reference/curl-class.md)

```
typedef CUrl* LPURL;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="see-also"></a>Confira também

[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)<br/>
[Funções](../../atl/reference/atl-functions.md)<br/>
[Variáveis globais](../../atl/reference/atl-global-variables.md)<br/>
[Aulas e estruturas](../../atl/reference/atl-classes.md)<br/>
[Macros](../../atl/reference/atl-macros.md)
