---
title: Classe is_trivially_copy_constructible | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::is_trivially_copy_constructible
dev_langs: C++
helpviewer_keywords: is_trivially_copy_constructible
ms.assetid: 4274cef5-afdd-4f2d-bc83-7562e7944ddf
caps.latest.revision: "24"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 465d5a1756a416eac2c01c5191b4f63f986ffcba
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="istriviallycopyconstructible-class"></a>Classe is_trivially_copy_constructible
Testa se o tipo tem um construtor de cópia trivial.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>
struct is_trivially_copy_constructible;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se o tipo `T` for uma classe que tem um construtor de cópia trivial; caso contrário, será falsa.  
  
 Um construtor de cópia para uma classe `T` será trivial se for declarado implicitamente, a classe `T` não tiver funções virtuais ou bases virtuais, todas as bases diretas da classe `T` tiverem construtores de cópia triviais, as classes de todos os membros de dados não estáticos de tipo de classe tiverem construtores de cópia triviais e as classes de todos os membros de dados não estáticos de matriz de tipo de classe tiverem operadores de cópia triviais.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)



