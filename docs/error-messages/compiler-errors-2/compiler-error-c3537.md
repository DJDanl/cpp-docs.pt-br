---
title: "C3537 de erro do compilador | Microsoft Docs"
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
  - "C3537"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3537"
ms.assetid: f537ebd1-4fb0-4e09-a453-4f38db2c6881
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3537 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': não pode ser convertido em um tipo que contém 'auto'  
  
 Você não pode converter uma variável para o tipo indicado porque o tipo contém o `auto` palavra\-chave e o padrão [\/ZC: auto](../../build/reference/zc-auto-deduce-variable-type.md) opção de compilador está em vigor.  
  
## Exemplo  
 O código a seguir produz C3537 porque as variáveis são convertidas em um tipo que contém o `auto` palavra\-chave.  
  
```  
// C3537.cpp  
// Compile with /Zc:auto  
int main()  
{  
   int value = 123;  
   auto(value);                        // C3537  
   (auto)value;                        // C3537  
   auto x1 = auto(value);              // C3537  
   auto x2 = (auto)value;              // C3537  
   auto x3 = static_cast<auto>(value); // C3537  
   return 0;  
}  
```  
  
## Consulte também  
 [Palavra\-chave auto](../../cpp/auto-keyword.md)