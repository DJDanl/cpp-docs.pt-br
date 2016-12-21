---
title: "Aviso do compilador (n&#237;vel 3) C4800 | Microsoft Docs"
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
  - "C4800"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4800"
ms.assetid: 4f409799-a250-45ed-bb5f-657691b0d9f7
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4800
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: forçando o valor ao bool “verdadeiro” ou “false” \(aviso de desempenho\)  
  
 Esse aviso é gerado quando um valor que não é `bool` é atribuído ou forçado no tipo `bool`.  Normalmente, essa mensagem é gerada para alocar variáveis de `int` para variáveis de `bool` onde a variável de `int` contém apenas valores **true** e **false**, e pode ser redeclarado como o tipo `bool`.  Se você não pode reescrever a expressão para usar o tipo `bool`, você pode adicionar “`!=0`” à expressão, que fornece o tipo `bool`da expressão.  Convertendo a expressão para digitar `bool` não desabilitará o aviso, que ocorre por design.  
  
 O seguinte exemplo gera C4800:  
  
```  
// C4800.cpp  
// compile with: /W3  
int main() {  
   int i = 0;  
  
   // try..  
   // bool i = 0;  
  
   bool j = i;   // C4800  
   j++;  
}  
```