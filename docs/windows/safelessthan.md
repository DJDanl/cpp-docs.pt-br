---
title: "SafeLessThan | Microsoft Docs"
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
  - "SafeLessThan"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função SafeLessThan"
ms.assetid: 9d85bc0d-8d94-4d59-9b72-ef3c63a120a0
caps.latest.revision: 6
caps.handback.revision: 6
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# SafeLessThan
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Determina se um número é menor que outro.  
  
## Sintaxe  
  
```  
template<typename T, typename U>  
inline bool SafeLessThan (  
   const T t,  
   const U u  
) throw ();  
```  
  
#### Parâmetros  
 \[entrada\] `t`  
 O primeiro número.  Isso deve ser do tipo T.  
  
 \[entrada\] `u`  
 O segundo numer.  Isso deve ser do tipo U.  
  
## Valor de retorno  
 `true` se `t` é menor que `u`; se não `false`.  
  
## Comentários  
 Esse método aprimora o operador de comparação padrão porque `SafeLessThan` permite comparar dois tipos diferentes de número.  
  
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
 [SafeLessThanEquals](../windows/safelessthanequals.md)   
 [SafeGreaterThan](../windows/safegreaterthan.md)   
 [SafeGreaterThanEquals](../windows/safegreaterthanequals.md)