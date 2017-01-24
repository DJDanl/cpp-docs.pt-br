---
title: "SafeInt::SafeInt | Microsoft Docs"
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
  - "SafeInt::SafeInt"
  - "SafeInt"
  - "SafeInt.SafeInt"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe SafeInt, construtor"
ms.assetid: 39e6f632-a396-40e6-9ece-cc3d4c5a78ef
caps.latest.revision: 7
caps.handback.revision: 7
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# SafeInt::SafeInt
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Constrói um objeto `SafeInt`.  
  
## Sintaxe  
  
```  
SafeInt() throw  
  
SafeInt (  
   const T& i  
) throw ()  
  
SafeInt (  
   bool b  
) throw ()  
  
template <typename U>  
SafeInt (  
   const SafeInt <U, E>& u  
)  
  
I template <typename U>  
SafeInt (  
   const U& i  
)  
```  
  
#### Parâmetros  
 \[entrada\] `i`  
 O valor para o novo objeto de `SafeInt` .  Isso deve ser um parâmetro de tipo T ou U, dependendo do construtor.  
  
 \[entrada\] `b`  
 O valor booliano para o novo objeto de `SafeInt` .  
  
 \[entrada\] `u`  
 `SafeInt` do tipo U.  O novo objeto de `SafeInt` terá o mesmo valor que `u`, mas será do tipo T.  
  
 U  
 O tipo de dados armazenados em `SafeInt`.  Esse pode ser um booliano, caractere, ou tipo inteiro.  Se for um tipo inteiro, pode ser assinado ou não assinado e estar entre 8 e 64 bits.  
  
## Comentários  
 Para obter mais informações sobre os tipos `T` e `E`de modelo, consulte [Classe SafeInt](../windows/safeint-class.md).  
  
 O parâmetro de entrada para o construtor, `i` ou `u`, deve ser um booliano, um caractere, ou um tipo inteiro.  Se for outro tipo de parâmetro, a classe de `SafeInt` chama [static\_assert](../cpp/static-assert.md) para indicar um parâmetro de entrada inválido.  
  
 Os construtores que usam o converter de `U` do tipo de modelo automaticamente o parâmetro de entrada para o tipo especificado por `T`.  A classe de `SafeInt` converte os dados sem perda de dados.  Informa ao manipulador de erros `E` se não pode converter os dados para digitar `T` sem perda de dados.  
  
 Se você criar `SafeInt` de um parâmetro booliano, você precisa iniciar imediatamente o valor.  Você não pode construir `SafeInt` usando o código `SafeInt<bool> sb;`.  Isso gerará um erro de compilação.  
  
## Requisitos  
 **Cabeçalho:** safeint.h  
  
 msl::utilities de**Namespace:**  
  
## Consulte também  
 [Biblioteca de SafeInt](../windows/safeint-library.md)   
 [Classe SafeInt](../windows/safeint-class.md)   
 [Classe SafeIntException](../windows/safeintexception-class.md)