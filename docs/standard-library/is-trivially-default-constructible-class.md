---
title: Classe is_trivially_default_constructible | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- is_trivially_default_constructible
- std.is_trivially_default_constructible
- std::is_trivially_default_constructible
- type_traits/std::is_trivially_default_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_default_constructible
ms.assetid: 653ecd73-909f-4dd8-b95a-d1164d1c2da4
caps.latest.revision: 17
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
translationtype: Machine Translation
ms.sourcegitcommit: 51fbd09793071631985720550007dddbe16f598f
ms.openlocfilehash: dd41fbdcc33250bc60a0b919b17dd52862549a77
ms.lasthandoff: 02/25/2017

---
# <a name="istriviallydefaultconstructible-class"></a>Classe is_trivially_default_constructible
Testa se um tipo tem um construtor padrão trivial.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Ty>
struct is_trivially_default_constructible;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se o tipo `Ty` for uma classe que tem um construtor trivial; caso contrário, será falsa.  
  
 Um construtor padrão de uma classe `Ty` será trivial se:  
  
-   for um construtor padrão declarado implicitamente  
  
-   a classe `Ty` não tiver funções virtuais  
  
-   a classe `Ty` não tiver bases virtuais  
  
-   todas as bases diretas da classe `Ty` tiverem construtores triviais  
  
-   as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores triviais  
  
-   as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores triviais  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




