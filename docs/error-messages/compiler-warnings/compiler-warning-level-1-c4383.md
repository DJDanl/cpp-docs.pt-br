---
title: "Aviso do compilador (n&#237;vel 1) C4383 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4383"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4383"
ms.assetid: 96c0e52d-874e-4b57-a154-0e49b6a00fae
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4383
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“instance\_dereference\_operator”: o significado de desreferenciar um identificador pode ser alterada, quando um operador definido pelo usuário “operador” existir; escreva o operador como uma função estática para ser explícito sobre o operando  
  
 Quando você adiciona uma substituição definida pelo usuário da instância do operador desreferenciar em um tipo gerenciado, substitua potencial a capacidade de tipo cancelará o operador para retornar o objeto de identificador.  Considere gravar um estático, definido pelo usuário eliminam o operador.  
  
 Para obter mais informações, consulte [Operador Handle to Object \(^\)](../../windows/handle-to-object-operator-hat-cpp-component-extensions.md) e [Tracking Reference Operator](../../windows/tracking-reference-operator-cpp-component-extensions.md).  
  
 Além disso, um operador de instância não está disponível para outros compiladores de idioma através de metadados referenciados.  Para obter mais informações, consulte [Operadores definidos pelo usuário](../../dotnet/user-defined-operators-cpp-cli.md).  
  
## Exemplo  
 O exemplo a seguir produz C4383.  
  
```  
// C4383.cpp  
// compile with: /clr /W1  
  
ref struct S {  
   int operator*() { return 0; }   // C4383  
};  
  
ref struct T {  
   static int operator*(T%) { return 0; }  
};   
  
int main() {  
   S s;  
   S^ pS = %s;  
  
   T t;  
   T^ pT = %t;  
   T% rT = *pT;  
}  
```