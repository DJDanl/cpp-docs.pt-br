---
title: Classe int_2 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp_short_vectors/Concurrency::graphics::int_2::y
- amp_short_vectors/Concurrency::graphics::int_2::set_x
- amp_short_vectors/Concurrency::graphics::int_2::set_y
- amp_short_vectors/Concurrency::graphics::int_2::get_yx
- amp_short_vectors/Concurrency::graphics::int_2::operator++
- amp_short_vectors/Concurrency::graphics::int_2::x
- amp_short_vectors/Concurrency::graphics::int_2::set_yx
- amp_short_vectors/Concurrency::graphics::int_2::operator/=
- amp_short_vectors/Concurrency::graphics::int_2::get_y
- amp_short_vectors/Concurrency::graphics::int_2::gr
- amp_short_vectors/Concurrency::graphics::int_2::operator*=
- amp_short_vectors/Concurrency::graphics::int_2::r
- amp_short_vectors/Concurrency::graphics::int_2::get_xy
- amp_short_vectors/Concurrency::graphics::int_2::operator=
- amp_short_vectors/Concurrency::graphics::int_2::g
- amp_short_vectors/Concurrency::graphics::int_2::rg
- amp_short_vectors/Concurrency::graphics::int_2::xy
- amp_short_vectors/Concurrency::graphics::int_2::operator-=
- amp_short_vectors/Concurrency::graphics::int_2::get_x
- amp_short_vectors/Concurrency::graphics::int_2::yx
- amp_short_vectors/Concurrency::graphics::int_2
- amp_short_vectors/Concurrency::graphics::int_2::operator-
- amp_short_vectors/Concurrency::graphics::int_2::set_xy
- amp_short_vectors/Concurrency::graphics::int_2::operator+=
- amp_short_vectors/Concurrency::graphics::int_2::operator--
dev_langs:
- C++
ms.assetid: 258b02e9-f1ee-46c2-8edd-dc9f69184846
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
ms.openlocfilehash: 1fb9eba97f469aa407dfe3287a216ceb8f707faf
ms.lasthandoff: 02/25/2017

---
# <a name="int2-class"></a>Classe int_2
Representa um vetor curto de dois inteiros.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class int_2;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`value_type`||  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor int_2](#ctor)|Sobrecarregado. Padrão construtor inicializa todos os elementos com 0.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Método int_2::get_x||  
|Método int_2::get_xy||  
|Método int_2::get_y||  
|Método int_2::get_yx||  
|Método int_2::ref_g||  
|Método int_2::ref_r||  
|Método int_2::ref_x||  
|Método int_2::ref_y||  
|Método int_2::set_x||  
|Método int_2::set_xy||  
|Método int_2::set_y||  
|Método int_2::set_yx||  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Operador-int_2::Operator||  
|int_2::Operator - operador||  
|int_2::Operator % = operador||  
|int_2::Operator < / operador =||  
|int_2::Operator * operador =||  
|Operador de int_2::Operator / =||  
|int_2::Operator ^ Operator =||  
|int_2::Operator | operador =||  
|int_2::Operator ~ operador||  
|int_2::Operator operador + +||  
|Operador + = int_2::Operator||  
|int_2::Operator\<= operador||  
|int_2::Operator = operador||  
|int_2::Operator-= operador||  
|int_2::Operator >> = operador||  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[tamanho constante](#int_2__size)||  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Membro de dados int_2::g||  
|Membro de dados int_2::GR||  
|Membro de dados int_2::r||  
|Membro de dados int_2::RG||  
|Membro de dados int_2::x||  
|Membro de dados int_2::xy||  
|Membro de dados int_2::y||  
|Membro de dados int_2::YX||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `int_2`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_short_vectors.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="a-namectora-int2"></a><a name="ctor"></a>int_2 

 Padrão construtor inicializa todos os elementos com 0.  
  
```  
int_2() restrict(amp,
    cpu);

 
int_2(
    int _V0,  
    int _V1) restrict(amp,
    cpu);

 
int_2(
    int _V) restrict(amp,
    cpu);

 
int_2(
    const int_2& _Other) restrict(amp,
    cpu);

 
explicit inline int_2(
    const uint_2& _Other) restrict(amp,
    cpu);

 
explicit inline int_2(
    const float_2& _Other) restrict(amp,
    cpu);

 
explicit inline int_2(
    const unorm_2& _Other) restrict(amp,
    cpu);

 
explicit inline int_2(
    const norm_2& _Other) restrict(amp,
    cpu);

 
explicit inline int_2(
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
  
##  <a name="a-nameint2sizea-size"></a><a name="int_2__size"></a>tamanho 

```  
static const int size = 2;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: Graphics](concurrency-graphics-namespace.md)

