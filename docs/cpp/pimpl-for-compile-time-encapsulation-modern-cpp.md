---
title: "Pimpl para encapsulamento do tempo de compila&#231;&#227;o (C++ moderno) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: c3e8a90a-b328-4990-82bb-e1b147f76e07
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pimpl para encapsulamento do tempo de compila&#231;&#227;o (C++ moderno)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

*O idioma de pimpl* é uma técnica moderna C\+\+ ocultar a implementação, minimizar o envolvimento, e separar interfaces.  Pimpl é curta para o “ponteiro para a implementação.” Você pode já esteja familiarizado com o conceito mas conhecê\-lo por outros nomes como o idioma de firewall de categorias ou do compilador de Cheshire.  
  
## Por que usar o pimpl?  
 Veja como o idioma de pimpl pode melhorar o ciclo de vida de desenvolvimento de software:  
  
-   Minimização de dependências da compilação.  
  
-   Divisão da interface e de implementação.  
  
-   Mobilidade.  
  
## Cabeçalho de Pimpl  
  
```cpp  
  
// my_class.h  
class my_class {  
   //  ... all public and protected stuff goes here ...  
private:  
   class impl; unique_ptr<impl> pimpl; // opaque type here  
};  
  
```  
  
 O idioma de pimpl impede cascatas de recriação e layouts é frágil do objeto.  É o mais adequado para \(\) transitiva tipos comuns.  
  
## Implementação de Pimpl  
 Define a classe de `impl` no arquivo .cpp.  
  
```cpp  
  
// my_class.cpp  
class my_class::impl {  // defined privately here  
  // ... all private data and functions: all of these  
  //     can now change without recompiling callers ...  
};  
my_class::my_class(): pimpl( new impl )  
{  
  // ... set impl values ...   
}  
```  
  
## Práticas recomendadas  
 Considere se adicionar suporte para a especialização de emissão de troca.  
  
## Consulte também  
 [Bem\-vindo ao C\+\+](../Topic/Welcome%20Back%20to%20C++%20\(Modern%20C++\).md)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)