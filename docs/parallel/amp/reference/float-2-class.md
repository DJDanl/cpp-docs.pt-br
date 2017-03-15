---
title: Classe float_2 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp_short_vectors/Concurrency::graphics::float_2::yx
- amp_short_vectors/Concurrency::graphics::float_2::operator-=
- amp_short_vectors/Concurrency::graphics::float_2::operator++
- amp_short_vectors/Concurrency::graphics::float_2::operator-
- amp_short_vectors/Concurrency::graphics::float_2::r
- amp_short_vectors/Concurrency::graphics::float_2::get_yx
- amp_short_vectors/Concurrency::graphics::float_2::get_xy
- amp_short_vectors/Concurrency::graphics::float_2::operator/=
- amp_short_vectors/Concurrency::graphics::float_2::set_yx
- amp_short_vectors/Concurrency::graphics::float_2::x
- amp_short_vectors/Concurrency::graphics::float_2::get_y
- amp_short_vectors/Concurrency::graphics::float_2::operator+=
- amp_short_vectors/Concurrency::graphics::float_2::gr
- amp_short_vectors/Concurrency::graphics::float_2::operator=
- amp_short_vectors/Concurrency::graphics::float_2::set_x
- amp_short_vectors/Concurrency::graphics::float_2::operator--
- amp_short_vectors/Concurrency::graphics::float_2::get_x
- amp_short_vectors/Concurrency::graphics::float_2::operator*=
- amp_short_vectors/Concurrency::graphics::float_2::rg
- amp_short_vectors/Concurrency::graphics::float_2::set_xy
- amp_short_vectors/Concurrency::graphics::float_2::xy
- amp_short_vectors/Concurrency::graphics::float_2
- amp_short_vectors/Concurrency::graphics::float_2::set_y
- amp_short_vectors/Concurrency::graphics::float_2::y
- amp_short_vectors/Concurrency::graphics::float_2::g
dev_langs:
- C++
ms.assetid: b3ebd48e-f8c8-4f00-a640-357f702f0cae
caps.latest.revision: 11
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
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 05707bd43a8f9b89a93c0da0011c46d67361fc84
ms.lasthandoff: 02/25/2017

---
# <a name="float2-class"></a>Classe float_2
Representa um vetor curto de dois flutuações.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class float_2;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`value_type`||  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor float_2](#ctor)|Sobrecarregado. Padrão construtor inicializa todos os elementos com 0.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Método float_2::get_x||  
|Método float_2::get_xy||  
|Método float_2::get_y||  
|Método float_2::get_yx||  
|Método float_2::ref_g||  
|Método float_2::ref_r||  
|Método float_2::ref_x||  
|Método float_2::ref_y||  
|Método float_2::set_x||  
|Método float_2::set_xy||  
|Método float_2::set_y||  
|Método float_2::set_yx||  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Operador-float_2::Operator||  
|float_2::Operator - operador||  
|float_2::Operator * operador =||  
|Operador de float_2::Operator / =||  
|float_2::Operator operador + +||  
|Operador + = float_2::Operator||  
|float_2::Operator = operador||  
|float_2::Operator-= operador||  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[tamanho constante](#float_2__size)||  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Membro de dados float_2::g||  
|Membro de dados float_2::GR||  
|Membro de dados float_2::r||  
|Membro de dados float_2::RG||  
|Membro de dados float_2::x||  
|Membro de dados float_2::xy||  
|Membro de dados float_2::y||  
|Membro de dados float_2::YX||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `float_2`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_short_vectors.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="a-namectora-float2"></a><a name="ctor"></a>float_2 

 Padrão construtor inicializa todos os elementos com 0.  
  
```  
float_2() restrict(amp,
    cpu);

 
float_2(
    float _V0,  
    float _V1) restrict(amp,
    cpu);

 
float_2(
    float _V) restrict(amp,
    cpu);

 
float_2(
    const float_2& _Other) restrict(amp,
    cpu);

 
explicit inline float_2(
    const uint_2& _Other) restrict(amp,
    cpu);

 
explicit inline float_2(
    const int_2& _Other) restrict(amp,
    cpu);

 
explicit inline float_2(
    const unorm_2& _Other) restrict(amp,
    cpu);

 
explicit inline float_2(
    const norm_2& _Other) restrict(amp,
    cpu);

 
explicit inline float_2(
    const double_2& _Other) restrict(amp,
    cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_V0`  
 O valor para inicializar o elemento 0.  
  
 `_V1`  
 O valor para inicializar o elemento 1.  
  
 `_V`  
 O valor de inicialização.  
  
 `_Other`  
 O objeto usado para inicializar.  
  
##  <a name="a-namefloat2sizea-size"></a><a name="float_2__size"></a>tamanho 

```  
static const int size = 2;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: Graphics](concurrency-graphics-namespace.md)

