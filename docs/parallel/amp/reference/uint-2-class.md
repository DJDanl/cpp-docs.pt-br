---
title: Classe uint_2 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp_short_vectors/Concurrency::graphics::uint_2::set_xy
- amp_short_vectors/Concurrency::graphics::uint_2::y
- amp_short_vectors/Concurrency::graphics::uint_2::gr
- amp_short_vectors/Concurrency::graphics::uint_2::operator-
- amp_short_vectors/Concurrency::graphics::uint_2::get_x
- amp_short_vectors/Concurrency::graphics::uint_2::operator-=
- amp_short_vectors/Concurrency::graphics::uint_2::r
- amp_short_vectors/Concurrency::graphics::uint_2::yx
- amp_short_vectors/Concurrency::graphics::uint_2::operator--
- amp_short_vectors/Concurrency::graphics::uint_2::set_yx
- amp_short_vectors/Concurrency::graphics::uint_2::operator=
- amp_short_vectors/Concurrency::graphics::uint_2::set_x
- amp_short_vectors/Concurrency::graphics::uint_2::operator+=
- amp_short_vectors/Concurrency::graphics::uint_2::get_y
- amp_short_vectors/Concurrency::graphics::uint_2::xy
- amp_short_vectors/Concurrency::graphics::uint_2::x
- amp_short_vectors/Concurrency::graphics::uint_2::get_xy
- amp_short_vectors/Concurrency::graphics::uint_2::set_y
- amp_short_vectors/Concurrency::graphics::uint_2
- amp_short_vectors/Concurrency::graphics::uint_2::operator*=
- amp_short_vectors/Concurrency::graphics::uint_2::get_yx
- amp_short_vectors/Concurrency::graphics::uint_2::operator/=
- amp_short_vectors/Concurrency::graphics::uint_2::g
- amp_short_vectors/Concurrency::graphics::uint_2::operator++
- amp_short_vectors/Concurrency::graphics::uint_2::rg
dev_langs:
- C++
ms.assetid: 9fcc9129-72b1-4da7-9012-4d3be15f1c52
caps.latest.revision: 11
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
ms.openlocfilehash: 1116be21d4f65b67ab967b7acedf4859df54a6e7
ms.lasthandoff: 02/25/2017

---
# <a name="uint2-class"></a>Classe uint_2
Representa um vetor curto de dois inteiros sem sinal.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class uint_2;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`value_type`||  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor uint_2](#ctor)|Sobrecarregado. Padrão construtor inicializa todos os elementos com 0.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Método uint_2::get_x||  
|Método uint_2::get_xy||  
|Método uint_2::get_y||  
|Método uint_2::get_yx||  
|uint_2::ref_g_Method||  
|uint_2::ref_r_Method||  
|uint_2::ref_x_Method||  
|uint_2::ref_y_Method||  
|Método uint_2::set_x||  
|Método uint_2::set_xy||  
|Método uint_2::set_y||  
|Método uint_2::set_yx||  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|uint_2::Operator - operador||  
|uint_2::Operator % = operador||  
|uint_2::Operator < / operador =||  
|uint_2::Operator * operador =||  
|Operador de uint_2::Operator / =||  
|uint_2::Operator ^ Operator =||  
|uint_2::Operator | operador =||  
|uint_2::Operator ~ operador||  
|uint_2::Operator operador + +||  
|Operador + = uint_2::Operator||  
|uint_2::Operator\<= operador||  
|uint_2::Operator = operador||  
|uint_2::Operator-= operador||  
|uint_2::Operator >> = operador||  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[tamanho constante](#uint_2__size)||  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|Membro de dados uint_2::g||  
|Membro de dados uint_2::GR||  
|Membro de dados uint_2::r||  
|Membro de dados uint_2::RG||  
|Membro de dados uint_2::x||  
|Membro de dados uint_2::xy||  
|Membro de dados uint_2::y||  
|Membro de dados uint_2::YX||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `uint_2`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_short_vectors.h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="a-namectora-uint2"></a><a name="ctor"></a>uint_2 

 Padrão construtor inicializa todos os elementos com 0.  
  
```  
uint_2() restrict(amp,
    cpu);

 
uint_2(
    unsigned int _V0,  
    unsigned int _V1) restrict(amp,
    cpu);

 
uint_2(
    unsigned int _V) restrict(amp,
    cpu);

 
uint_2(
    const uint_2& _Other) restrict(amp,
    cpu);

 
explicit inline uint_2(
    const int_2& _Other) restrict(amp,
    cpu);

 
explicit inline uint_2(
    const float_2& _Other) restrict(amp,
    cpu);

 
explicit inline uint_2(
    const unorm_2& _Other) restrict(amp,
    cpu);

 
explicit inline uint_2(
    const norm_2& _Other) restrict(amp,
    cpu);

 
explicit inline uint_2(
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
  
##  <a name="a-nameuint2sizea-size"></a><a name="uint_2__size"></a>tamanho 

```  
static const int size = 2;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: Graphics](concurrency-graphics-namespace.md)

