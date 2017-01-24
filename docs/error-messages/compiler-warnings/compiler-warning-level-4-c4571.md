---
title: "Aviso do compilador (n&#237;vel 4) C4571 | Microsoft Docs"
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
  - "C4571"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4571"
ms.assetid: 07aa17bd-b15c-4266-824c-57cc445e8edd
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4571
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Informativo: a semântica de captura \(...\) foi alterado desde Visual C\+\+ 7.1; as exceções estruturados \(SEH\) são capturadas não  
  
 C4571 é gerado para cada bloco de captura \(...\) a compile com **\/EHs**.  
  
 Ao criar com **\/EHs**, um bloco de captura \(...\) não detectará uma exceção estruturado \(divisão por zero, ponteiro nulo, por exemplo\); um bloco de captura \(...\) detectará somente explicitamente\- lançadas exceções, C\+\+.  Para obter mais informações, consulte [Tratamento de Exceção](../../cpp/exception-handling-in-visual-cpp.md).  
  
 Esse aviso é desativada por padrão.  Defina esse aviso sobre assegurar que quando você compila com **\/EHs** seus blocos de try\/catch \(...\) não pretendam capturar exceções estruturados.  Consulte [Avisos de compilador desativados por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para maiores informações.  
  
 Você pode resolver C4571 em uma das seguintes maneiras,  
  
-   Compile com **\/EHa** se você ainda quiser que seus blocos de try\/catch \(...\) para capturar exceções estruturados.  
  
-   Não habilite C4571 se você não quiser que seus blocos de try\/catch \(...\) para capturar exceções estruturados, mas ainda quiser usar blocos de try\/catch \(...\).  Você ainda pode capturar exceções estruturados usando as palavras\-chave estruturados a manipulação de exceções \(**\_\_try**, **\_\_except**, e **\_\_finally**\).  Mas lembre\-se de que, quando os destruidores compilados de **\/EHs** serão chamados somente quando a exceção c criando será gerada, não a exceção.  
  
-   Substitua o bloco de captura \(...\) com os blocos de try\/catch para exceções específicas do C\+\+ e, opcionalmente, adicione manipulação de exceção estruturados em torno de manipulação de exceção C\+\+ \(**\_\_try**, **\_\_except**, e **\_\_finally**\).  Consulte [Tratamento de exceções estruturado](../../cpp/structured-exception-handling-c-cpp.md) para maiores informações.  
  
 Consulte [\/EH \(modelo de tratamento de exceções\)](../../build/reference/eh-exception-handling-model.md) para maiores informações.  
  
## Exemplo  
 O exemplo a seguir produz C4571.  
  
```  
// C4571.cpp  
// compile with: /EHs /W4 /c  
#pragma warning(default : 4571)  
int main() {  
   try {  
      int i = 0, j = 1;  
      j /= i;   // this will throw a SE (divide by zero)  
   }  
   catch(...) {}   // C4571 warning  
}  
```