---
title: Classe unorm | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp_short_vectors/Concurrency::graphics::unorm
- amp/Concurrency::graphics::unorm
dev_langs:
- C++
ms.assetid: bc30bd20-6452-4d5f-9158-3b11c4c16ed2
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: aae5de80bed3b2d3d5c15285c2d12f2f6771a251
ms.lasthandoff: 02/25/2017

---
# <a name="unorm-class"></a>Classe unorm
Representa um número unorm. Cada elemento é flutuante ponto número no intervalo de [0.0 f, 1.0 f].  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class unorm;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor unorm](#ctor)|Sobrecarregado. Construtor padrão. Inicialize 0.0 f.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|unorm::Operator - operador||  
|unorm::operator float operador|Operador de conversão. Converter o número unorm flutuante valor de ponto.|  
|unorm::Operator * operador =||  
|Operador de unorm::Operator / =||  
|unorm::Operator operador + +||  
|Operador + = unorm::Operator||  
|unorm::Operator = operador||  
|unorm::Operator-= operador||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `unorm`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_short_vectors.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="a-namectora-unorm"></a><a name="ctor"></a>unorm 

 Construtor padrão. Inicialize 0.0 f.  
  
```  
unorm(
    void) restrict(amp,
    cpu);

 
explicit unorm(
    float _V) restrict(amp,
    cpu);

 
explicit unorm(
    unsigned int _V) restrict(amp,
    cpu);

 
explicit unorm(
    int _V) restrict(amp,
    cpu);

 
explicit unorm(
    double _V) restrict(amp,
    cpu);

 
unorm(
    const unorm& _Other) restrict(amp,
    cpu);

 
inline explicit unorm(
    const norm& _Other) restrict(amp,
    cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_V`  
 O valor usado para inicializar.  
  
 `_Other`  
 O objeto de norma usado para inicializar.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: Graphics](concurrency-graphics-namespace.md)

