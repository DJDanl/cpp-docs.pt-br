---
title: "Instancia&#231;&#227;o do modelo de fun&#231;&#227;o | Microsoft Docs"
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
  - "modelos de função, instanciação"
  - "instanciação, modelos de função"
  - "modelos, instanciação"
ms.assetid: f22a07c7-3ad1-465a-84f5-8737e274bd47
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instancia&#231;&#227;o do modelo de fun&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando um modelo da função é chamado primeiramente para cada tipo, o compilador cria uma instanciação.  Cada instanciação é uma versão da função em modelo, especializada para o tipo.  Essa instanciação será chamada sempre que a função for usada para o tipo.  Se você tiver várias instanciações idênticas, mesmo em módulos diferentes, apenas uma cópia de instanciação terminará acima no arquivo executável.  
  
 A conversão de argumentos da função é permitida em modelos de função para qualquer par de argumento e de parâmetro, nos quais o parâmetro não depende de um argumento de modelo.  
  
 Os modelos da função podem ser instanciados explicitamente declarando o modelo com um tipo específico como um argumento.  Por exemplo, o código a seguir é permitido:  
  
```  
// function_template_instantiation.cpp  
template<class T> void f(T) { }  
  
// Instantiate f with the explicitly specified template.  
// argument 'int'  
//  
template void f<int> (int);  
  
// Instantiate f with the deduced template argument 'char'.  
template void f(char);  
int main()  
{  
}  
```  
  
## Consulte também  
 [Modelos de função](../cpp/function-templates.md)