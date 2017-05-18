---
title: C2891 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2891
dev_langs:
- C++
helpviewer_keywords:
- C2891
ms.assetid: e12cfb2d-df45-4b0d-b155-c51d17e812fa
caps.latest.revision: 7
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 629d1c0b98f1bf6a813bd28f25c4e5afc0e7b367
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2891"></a>C2891 de erro do compilador
'parâmetro': não é possível obter o endereço de um parâmetro de modelo  
  
 Você não pode obter o endereço de um parâmetro de modelo, a menos que é um l-value. Parâmetros de tipo não são l-Values porque eles não possuem endereço. Valores sem tipo em listas de parâmetros de modelo que não são l-Values também não tem um endereço. Este é um exemplo de código que faz com que o compilador C2891 de erro, porque o valor passado como o parâmetro do modelo é uma cópia do argumento de modelo gerado pelo compilador.  
  
```  
template <int i> int* f() { return &i; }  
```  
  
 Parâmetros de modelo são l-Values, como tipos de referência, podem ter seus endereços executadas.  
  
```  
template <int& r> int* f() { return &r; }  
```  
  
 Para corrigir esse erro, não têm o endereço de um parâmetro de modelo, a menos que é um l-value.
