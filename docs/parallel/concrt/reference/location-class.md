---
title: Classe Location | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- location
- CONCRT/concurrency::location
- CONCRT/concurrency::location::location
- CONCRT/concurrency::location::current
- CONCRT/concurrency::location::from_numa_node
dev_langs:
- C++
helpviewer_keywords:
- location class
ms.assetid: c3289f51-5bf1-4dff-a18d-d0dab8e5d9c7
caps.latest.revision: 10
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: a0b64804ebfea3ad2c172c509aeffd485f4fe30a
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="location-class"></a>Classe location
Uma abstração de um local físico no hardware.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class location;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[local](#ctor)|Sobrecarregado. Constrói um objeto `location`.|  
|[~ local destruidor](#dtor)|Destrói um objeto `location`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[atual](#current)|Retorna um `location` objeto que representa o local mais específico que o thread de chamada está em execução.|  
|[from_numa_node](#from_numa_node)|Retorna um `location` objeto que representa um nó NUMA.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator!=](#operator_neq)|Determina se dois `location` objetos representam um local diferente.|  
|[operator=](#operator_eq)|Atribui o conteúdo de um outro `location` objeto a este.|  
|[operator==](#operator_eq_eq)|Determina se dois `location` objetos representam o mesmo local.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `location`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="dtor"></a>~ local 

 Destrói um objeto `location`.  
  
```
~location();
```  
  
##  <a name="current"></a>atual 

 Retorna um `location` objeto que representa o local mais específico que o thread de chamada está em execução.  
  
```
static location __cdecl current();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um local que representa o local mais específico o thread de chamada está em execução.  
  
##  <a name="from_numa_node"></a>from_numa_node 

 Retorna um `location` objeto que representa um nó NUMA.  
  
```
static location __cdecl from_numa_node(unsigned short _NumaNodeNumber);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_NumaNodeNumber`  
 O número de nó para construir um local.  
  
### <a name="return-value"></a>Valor de retorno  
 Um local que representa o nó NUMA especificado pelo `_NumaNodeNumber` parâmetro.  
  
##  <a name="ctor"></a>local 

 Constrói um objeto `location`.  
  
```
location();

location(
    const location& _Src);

location(
    T _LocationType,
    unsigned int _Id,
    unsigned int _BindingId = 0,
    _Inout_opt_ void* _PBinding = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Src`  
 `_LocationType`  
 `_Id`  
 `_BindingId`  
 `_PBinding`  
  
### <a name="remarks"></a>Comentários  
 Um local padrão construído representa o sistema como um todo.  
  
##  <a name="operator_neq"></a>operador! = 

 Determina se dois `location` objetos representam um local diferente.  
  
```
bool operator!= (const location& _Rhs) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se os dois locais forem diferentes, `false` caso contrário.  
  
##  <a name="operator_eq"></a>operador = 

 Atribui o conteúdo de um outro `location` objeto a este.  
  
```
location& operator= (const location& _Rhs);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
 A fonte `location` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="operator_eq_eq"></a>operador = = 

 Determina se dois `location` objetos representam o mesmo local.  
  
```
bool operator== (const location& _Rhs) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rhs`  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se os dois locais são idênticos, e `false` caso contrário.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

