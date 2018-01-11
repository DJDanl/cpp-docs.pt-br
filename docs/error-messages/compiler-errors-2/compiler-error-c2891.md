---
title: C2891 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2891
dev_langs: C++
helpviewer_keywords: C2891
ms.assetid: e12cfb2d-df45-4b0d-b155-c51d17e812fa
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 979d77ad5b5bd0b68dd539695d6cb1b60b099c55
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2891"></a>C2891 de erro do compilador
'parameter': não é possível obter o endereço de um parâmetro de modelo  
  
 Você não pode obter o endereço de um parâmetro de modelo, a menos que ele seja um lvalue. Parâmetros de tipo não são lvalues porque eles não possuem endereço. Não-digite os valores nas listas de parâmetros de modelo que não são lvalues também não tem um endereço. Este é um exemplo de código que faz com que o compilador C2891 de erro, porque o valor passado como parâmetro de modelo é uma cópia gerada pelo compilador do argumento de modelo.  
  
```  
template <int i> int* f() { return &i; }  
```  
  
 Parâmetros de modelo são lvalues, como tipos de referência, pode ter seu endereço feitos.  
  
```  
template <int& r> int* f() { return &r; }  
```  
  
 Para corrigir esse erro, não tomar o endereço de um parâmetro de modelo, a menos que ele é um lvalue.