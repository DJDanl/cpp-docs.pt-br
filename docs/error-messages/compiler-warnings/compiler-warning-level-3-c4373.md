---
title: "Compilador C4373 de aviso (n&#237;vel 3) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4373"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4373"
ms.assetid: 670c0ba3-b7d6-4aed-b207-1cb84da3bcde
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4373 de aviso (n&#237;vel 3)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'%$S': '%$pS' substituições de função virtual, as versões anteriores do compilador não substituiu quando parâmetros diferente apenas por qualificadores const\/volátil  
  
 Seu aplicativo contém um método em uma classe derivada que substitui um método virtual em uma classe base, e os parâmetros no método de substituição diferem somente por um [const](../../cpp/const-cpp.md) ou [volátil](../../cpp/volatile-cpp.md) qualificador dos parâmetros do método virtual. Isso significa que o compilador deve vincular uma referência de função para o método em uma base ou classe derivada.  
  
 Versões do compilador antes [!INCLUDE[cpp_orcas_long](../../error-messages/compiler-warnings/includes/cpp_orcas_long_md.md)] associar a função para o método na classe base, em seguida, emitir uma mensagem de aviso. As versões subseqüentes do compilador ignoram a `const` ou `volatile` qualificador, associar a função para o método na classe derivada, em seguida, emitir aviso `C4373`. Esse último comportamento compatível com o padrão de C\+\+.  
  
## Exemplo  
 O exemplo de código a seguir gera um aviso C4373.  
  
```  
// c4373.cpp // compile with: /c /W3 #include <stdio.h> struct Base { virtual void f(int i) { printf("base\n"); } }; struct Derived : Base { void f(const int i) {  // C4373 printf("derived\n"); } }; void main() { Derived d; Base* p = &d; p->f(1); }  
```  
  
```Output  
derivado  
```