---
title: Classe NORM | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp_short_vectors/Concurrency::graphics::norm
dev_langs:
- C++
ms.assetid: 73002f3d-c25e-4119-bcd3-4c46c9b6abf1
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
ms.openlocfilehash: 8ff5a99136a75d17d914783496205f1dd1eb4a06
ms.lasthandoff: 02/25/2017

---
# <a name="norm-class"></a>Classe norm
Representa um número de norma. Cada elemento é flutuante ponto número no intervalo de [-1, 0F, 1.0 f].  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class norm;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor NORM](#ctor)|Sobrecarregado. Construtor padrão. Inicialize 0.0 f.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Operador-NORM::Operator||  
|NORM::Operator - operador||  
|NORM::operator float operador|Operador de conversão. Converter o número de norma flutuante valor de ponto.|  
|NORM::Operator * operador =||  
|Operador de NORM::Operator / =||  
|NORM::Operator operador + +||  
|Operador + = NORM::Operator||  
|NORM::Operator = operador||  
|NORM::Operator-= operador||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `norm`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_short_vectors.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="a-namectora-norm"></a><a name="ctor"></a>NORM 

 Construtor padrão. Inicialize 0.0 f.  
  
```  
norm(
    void) restrict(amp,
    cpu);

 
explicit norm(
    float _V) restrict(amp,
    cpu);

 
explicit norm(
    unsigned int _V) restrict(amp,
    cpu);

 
explicit norm(
    int _V) restrict(amp,
    cpu);

 
explicit norm(
    double _V) restrict(amp,
    cpu);

 
norm(
    const norm& _Other) restrict(amp,
    cpu);

 
norm(
    const unorm& _Other) restrict(amp,
    cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_V`  
 O valor usado para inicializar.  
  
 `_Other`  
 O objeto usado para inicializar.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: Graphics](concurrency-graphics-namespace.md)

