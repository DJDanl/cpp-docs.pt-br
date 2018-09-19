---
title: Classe int_2 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: reference
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7c3e3d61179717648c50709dc219038956438f3e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46080292"
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
|[Construtor int_2](#ctor)|Sobrecarregado. Padrão construtor, inicializa todos os elementos com 0.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|int_2::get_x||  
|int_2::get_xy||  
|int_2::get_y||  
|int_2::get_yx||  
|int_2::ref_g||  
|int_2::ref_r||  
|int_2::ref_x||  
|int_2::ref_y||  
|int_2::set_x||  
|int_2::set_xy||  
|int_2::set_y||  
|int_2::set_yx||  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|int_2::operator-||  
|int_2::operator--||  
|int_2::operator%=||  
|int_2::operator&=||  
|int_2::operator*=||  
|int_2::operator/=||  
|int_2::operator^=||  
|int_2::operator&#124;=||  
|int_2::operator~||  
|int_2::operator++||  
|int_2::operator+=||  
|int_2::operator<\<=||  
|int_2::operator=||  
|int_2::operator-=||  
|int_2::operator>>=||  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[tamanho constante](#int_2__size)||  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|int_2::g||  
|int_2::gr||  
|int_2::r||  
|int_2::rg||  
|int_2::x||  
|int_2::xy||  
|int_2::y||  
|int_2::yx||  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `int_2`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_short_vectors. h  
  
 **Namespace:** Concurrency:: Graphics  
  
##  <a name="ctor"></a> int_2 

 Padrão construtor, inicializa todos os elementos com 0.  
  
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
*_V0*<br/>
O valor para inicializar o elemento 0.  
  
*V1*<br/>
O valor para inicializar o elemento 1.  
  
*_V*<br/>
O valor para a inicialização.  
  
*Outro*<br/>
O objeto usado para inicializar.  
  
##  <a name="int_2__size"></a> Tamanho 

```  
static const int size = 2;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
