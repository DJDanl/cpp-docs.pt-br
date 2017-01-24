---
title: "SafeLessThanEquals | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "SafeLessThanEquals"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função SafeLessThanEquals"
ms.assetid: cbd70526-faf2-4fbc-96a0-b61e8cf5f04a
caps.latest.revision: 6
caps.handback.revision: 6
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# SafeLessThanEquals
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Compara dois números.  
  
## Sintaxe  
  
```  
template <typename T, typename U>  
inline bool SafeLessThanEquals (  
   const T t,  
   const U u  
) throw ();  
```  
  
#### Parâmetros  
 \[entrada\] `t`  
 O primeiro número a ser comparado.  Isso deve ser do tipo T.  
  
 \[entrada\] `u`  
 O segundo número a ser comparado.  Isso deve ser do tipo U.  
  
## Valor de retorno  
 `true` se `t` é menor ou igual a `u`; se não `false`.  
  
## Comentários  
 `SafeLessThanEquals` estende o operador de comparação normal habilitando o para comparar dois tipos diferentes de números.  
  
 Esse método é parte de [Biblioteca de SafeInt](../windows/safeint-library.md) e é criado para uma única operação de comparação sem criar uma instância de [Classe SafeInt](../windows/safeint-class.md).  
  
> [!NOTE]
>  Esse método deve ser usado apenas quando uma única operação matemática deve ser protegida.  Se houver várias operações, você deve usar a classe de `SafeInt` em vez de chamar funções autônomas individuais.  
  
 Para obter mais informações sobre os tipos T e U de modelo, consulte [Funções \(SafeInt\)](../windows/safeint-functions.md).  
  
## Requisitos  
 **Cabeçalho:** safeint.h  
  
 **Namespace:** Microsoft::Utilities  
  
## Consulte também  
 [Funções \(SafeInt\)](../windows/safeint-functions.md)   
 [Biblioteca de SafeInt](../windows/safeint-library.md)   
 [Classe SafeInt](../windows/safeint-class.md)   
 [SafeGreaterThan](../windows/safegreaterthan.md)   
 [SafeLessThan](../windows/safelessthan.md)   
 [SafeGreaterThanEquals](../windows/safegreaterthanequals.md)