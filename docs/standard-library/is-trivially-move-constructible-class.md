---
title: Classe is_trivially_move_constructible | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- type_traits/std::is_trivially_move_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_move_constructible
ms.assetid: 740bdec7-65e5-47b3-b94f-a2479ceac3ec
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: d59ca4d7830940a2b99e4e10e885d80842dc7d1b
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="istriviallymoveconstructible-class"></a>Classe is_trivially_move_constructible
Testa se o tipo tem construtor de movimentação trivial.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Ty>
struct is_trivially_move_constructible;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe que tem um construtor de movimentação trivial; caso contrário, será falsa.  
  
 Um construtor de movimentação de uma classe `Ty` será trivial se:  
  
 for implicitamente declarado  
  
 seus tipos de parâmetro forem equivalentes aos de uma declaração implícita  
  
 a classe `Ty` não tiver funções virtuais  
  
 a classe `Ty` não tiver bases virtuais  
  
 a classe não tiver membros de dados não estáticos voláteis  
  
 todas as bases diretas da classe `Ty` tiverem construtores de movimentação trivial  
  
 as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores de movimentação trivial  
  
 as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores de movimentação trivial  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




