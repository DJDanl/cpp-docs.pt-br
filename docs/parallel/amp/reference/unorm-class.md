---
title: Classe unorm | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- unorm
- AMP_SHORT_VECTORS/unorm
- AMP_SHORT_VECTORS/Concurrency::graphics::unorm Constructor
dev_langs: C++
ms.assetid: bc30bd20-6452-4d5f-9158-3b11c4c16ed2
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: fffce416bebda4bcc1d5aa0078135aff27bdb7e3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="unorm-class"></a>Classe unorm
Representa um número unorm. Cada elemento é um flutuante ponto número no intervalo de [0.0 f, 1.0 f].  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class unorm;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de unorm](#ctor)|Sobrecarregado. Construtor padrão. Inicialize 0.0 f.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|unorm::Operator –||  
|unorm::operator float|Operador de conversão. Converter o número de unorm um flutuante valor de ponto.|  
|unorm::Operator * =||  
|unorm::Operator / =||  
|unorm::Operator + +||  
|+ unorm::Operator =||  
|unorm::Operator =||  
|unorm::Operator =||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `unorm`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_short_vectors.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="ctor"></a>unorm 

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
 O objeto de modelo usado para inicializar.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
