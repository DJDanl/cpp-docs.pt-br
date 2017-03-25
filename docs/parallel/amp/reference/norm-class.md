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
- norm
- AMP_SHORT_VECTORS/norm
- AMP_SHORT_VECTORS/Concurrency::graphics::norm Constructor
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 6f6477f37a94a0c2a093fd3a63fa8e87463a5a7b
ms.lasthandoff: 03/17/2017

---
# <a name="norm-class"></a>Classe norm
Representa um número de norma. Cada elemento é flutuante aponte número no intervalo de [-1, 0F, 1.0 f].  
  
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
|NORM::Operator-||  
|NORM::Operator-||  
|NORM::operator float|Operador de conversão. Converter o número de norma flutuante valor de ponto.|  
|NORM::Operator * =||  
|NORM::Operator / =||  
|NORM::Operator + +||  
|+ = NORM::Operator||  
|NORM::Operator =||  
|NORM::Operator =||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `norm`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_short_vectors.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="ctor"></a>NORM 

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
 [Namespace Concurrency::graphics](concurrency-graphics-namespace.md)

