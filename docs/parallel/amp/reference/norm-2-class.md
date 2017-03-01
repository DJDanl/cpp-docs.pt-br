---
title: Classe norm_2 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp_short_vectors/Concurrency::graphics::norm_2::set_x
- amp_short_vectors/Concurrency::graphics::norm_2::set_xy
- amp_short_vectors/Concurrency::graphics::norm_2::g
- amp_short_vectors/Concurrency::graphics::norm_2::get_yx
- amp_short_vectors/Concurrency::graphics::norm_2::set_yx
- amp_short_vectors/Concurrency::graphics::norm_2::operator-=
- amp_short_vectors/Concurrency::graphics::norm_2::operator/=
- amp_short_vectors/Concurrency::graphics::norm_2::operator*=
- amp_short_vectors/Concurrency::graphics::norm_2::yx
- amp_short_vectors/Concurrency::graphics::norm_2::y
- amp_short_vectors/Concurrency::graphics::norm_2::xy
- amp_short_vectors/Concurrency::graphics::norm_2::operator++
- amp_short_vectors/Concurrency::graphics::norm_2::operator-
- amp_short_vectors/Concurrency::graphics::norm_2::rg
- amp_short_vectors/Concurrency::graphics::norm_2::operator=
- amp_short_vectors/Concurrency::graphics::norm_2::get_y
- amp_short_vectors/Concurrency::graphics::norm_2::r
- amp_short_vectors/Concurrency::graphics::norm_2::get_x
- amp_short_vectors/Concurrency::graphics::norm_2::get_xy
- amp_short_vectors/Concurrency::graphics::norm_2::gr
- amp_short_vectors/Concurrency::graphics::norm_2::set_y
- amp_short_vectors/Concurrency::graphics::norm_2::x
- amp_short_vectors/Concurrency::graphics::norm_2::operator+=
- amp_short_vectors/Concurrency::graphics::norm_2
- amp_short_vectors/Concurrency::graphics::norm_2::operator--
dev_langs:
- C++
ms.assetid: 80703f9b-61f4-414a-93fd-bc774f7d3393
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
ms.openlocfilehash: 7ff9cb756ca17633aa90e2f35c6f6f02da6cc884
ms.lasthandoff: 02/25/2017

---
# <a name="norm2-class"></a>Classe norm_2
Representa um vetor curto de dois números normais.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class norm_2;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`value_type`||  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor norm_2](#ctor)|Sobrecarregado. Padrão construtor inicializa todos os elementos com 0.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Método norm_2::get_x||  
|Método norm_2::get_xy||  
|Método norm_2::get_y||  
|Método norm_2::get_yx||  
|Método norm_2::ref_g||  
|Método norm_2::ref_r||  
|Método norm_2::ref_x||  
|Método norm_2::ref_y||  
|Método norm_2::set_x||  
|Método norm_2::set_xy||  
|Método norm_2::set_y||  
|Método norm_2::set_yx||  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Operador-norm_2::Operator||  
|norm_2::Operator - operador||  
|norm_2::Operator * operador =||  
|Operador de norm_2::Operator / =||  
|norm_2::Operator operador + +||  
|Operador + = norm_2::Operator||  
|norm_2::Operator = operador||  
|norm_2::Operator-= operador||  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[tamanho constante](#norm_2__size)||  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Membro de dados norm_2::g||  
|Membro de dados norm_2::GR||  
|Membro de dados norm_2::r||  
|Membro de dados norm_2::RG||  
|Membro de dados norm_2::x||  
|Membro de dados norm_2::xy||  
|Membro de dados norm_2::y||  
|Membro de dados norm_2::YX||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `norm_2`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_short_vectors.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="a-namectora-norm2"></a><a name="ctor"></a>norm_2 

 Padrão construtor inicializa todos os elementos com 0.  
  
```  
norm_2() restrict(amp,
    cpu);

 
norm_2(
    norm _V0,  
    norm _V1) restrict(amp,
    cpu);

 
norm_2(
    float _V0,  
    float _V1) restrict(amp,
    cpu);

 
norm_2(
    unorm _V0,  
    unorm _V1) restrict(amp,
    cpu);

 
norm_2(
    norm _V) restrict(amp,
    cpu);

 
explicit norm_2(
    float _V) restrict(amp,
    cpu);

 
norm_2(
    const norm_2& _Other) restrict(amp,
    cpu);

 
explicit inline norm_2(
    const uint_2& _Other) restrict(amp,
    cpu);

 
explicit inline norm_2(
    const int_2& _Other) restrict(amp,
    cpu);

 
explicit inline norm_2(
    const float_2& _Other) restrict(amp,
    cpu);

 
explicit inline norm_2(
    const unorm_2& _Other) restrict(amp,
    cpu);

 
explicit inline norm_2(
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
  
##  <a name="a-namenorm2sizea-size"></a><a name="norm_2__size"></a>tamanho 

```  
static const int size = 2;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: Graphics](concurrency-graphics-namespace.md)

