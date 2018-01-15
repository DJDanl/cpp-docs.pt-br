---
title: Classe is_trivially_default_constructible | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::is_trivially_default_constructible
dev_langs: C++
helpviewer_keywords: is_trivially_default_constructible
ms.assetid: 653ecd73-909f-4dd8-b95a-d1164d1c2da4
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6b936e6cfa3557591a5be9ec2cafda36920039c3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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



