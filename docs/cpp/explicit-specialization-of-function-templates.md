---
title: "Especializa&#231;&#227;o expl&#237;cita de modelos de fun&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "declarando funções, especialização de modelo de função"
  - "especialização explícita de modelos de função"
  - "modelos de função, especialização"
  - "substituição, Funções "
  - "especialização de modelos de função"
ms.assetid: eb0fcb73-eaed-42a1-9b83-14b055a34bf8
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especializa&#231;&#227;o expl&#237;cita de modelos de fun&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Com um modelo de função, você pode definir o comportamento especial para um tipo específico fornecendo uma especialização explícita \(substituição\) do modelo da função para esse tipo.  Por exemplo:  
  
```  
template<> void MySwap(double a, double b);  
```  
  
 Esta declaração permite definir uma função diferente para variáveis **double**.  Assim como as funções que não são modelos, as conversões de tipo padrão \(como a promoção de uma variável de tipo **float** para **double**\) são aplicadas.  
  
## Exemplo  
  
```  
// explicit_specialization.cpp  
template<class T> void f(T t)  
{  
};  
  
// Explicit specialization of f with 'char' with the  
// template argument explicitly specified:  
//  
template<> void f<char>(char c)  
{  
}  
  
// Explicit specialization of f with 'double' with the  
// template argument deduced:  
//  
template<> void f(double d)  
{  
}  
int main()  
{  
}  
```  
  
## Consulte também  
 [Modelos de função](../cpp/function-templates.md)