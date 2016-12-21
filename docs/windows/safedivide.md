---
title: "SafeDivide | Microsoft Docs"
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
  - "SafeDivide"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função SafeDivide"
ms.assetid: b5b27484-ad6e-46b1-ba9f-1c7120dd103b
caps.latest.revision: 5
caps.handback.revision: 5
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# SafeDivide
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Divide dois números de uma maneira que protege contra dividir por zero.  
  
## Sintaxe  
  
```  
template<typename T, typename U>  
inline bool SafeDivide (  
   T t,  
   U u,  
   T& result  
) throw ();  
```  
  
#### Parâmetros  
 \[entrada\] `t`  
 O divisor.  Isso deve ser do tipo T.  
  
 \[entrada\] `u`  
 O dividendo.  Isso deve ser do tipo U.  
  
 \[saída\] `result`  
 O parâmetro `SafeDivide` onde armazena o resultado.  
  
## Valor de retorno  
 `true` se nenhum erro ocorre; `false` se ocorrer um erro.  
  
## Comentários  
 Esse método é parte de [Biblioteca de SafeInt](../windows/safeint-library.md) e é criado para uma única operação de divisão sem criar uma instância de [Classe SafeInt](../windows/safeint-class.md).  
  
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
 [SafeModulus](../windows/safemodulus.md)   
 [SafeMultiply](../Topic/SafeMultiply.md)