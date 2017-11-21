---
title: Classe is_literal_type | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: type_traits/std::is_literal_type
dev_langs: C++
helpviewer_keywords: is_literal_type
ms.assetid: a03a4ebb-ee66-48d6-91bb-41cf72b2401f
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a1311d9cfa8cf089a2649b7fcd65d6e0ed224c45
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="isliteraltype-class"></a>Classe is_literal_type
Testa se um tipo pode ser usado como uma variável `constexpr` ou pode ser construído, usado ou retornado de funções `constexpr`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
struct is_literal_type;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo a ser consultado.  
  
## <a name="remarks"></a>Comentários  
 Uma instância do predicado de tipo será verdadeira se o tipo `T` for um *tipo literal*; caso contrário, será falsa. Um tipo literal é `void`, um tipo escalar, um tipo de referência, uma matriz de tipo literal ou um tipo de classe literal. Um tipo de classe literal é um tipo de classe que tem um destruidor trivial, é um tipo agregado ou tem pelo menos construtor `constexpr` que não é de movimentação e não é de cópia, e todas as suas classes base e membros de dados não estáticos são tipos literais não voláteis. Embora o tipo de um literal sempre seja um tipo literal, o conceito de um tipo literal inclui tudo que o compilador puder avaliar como `constexpr` em tempo de compilação.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)



