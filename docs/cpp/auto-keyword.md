---
title: "Palavra-chave auto | Microsoft Docs"
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
  - "auto"
  - "auto_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave auto"
  - "classe de armazenamento automático, palavra-chave auto"
ms.assetid: 744a41c0-2510-4140-a1be-96257e722908
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Palavra-chave auto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A palavra\-chave `auto` é um especificador de declaração.  Porém, o padrão do C\+\+ define um significado original e um significado revisado para essa palavra\-chave.  Antes do [!INCLUDE[cpp_dev10_long](../Token/cpp_dev10_long_md.md)], a palavra\-chave `auto` declara uma variável na classe de armazenamento *automatic*; ou seja, uma variável que tem um tempo de vida local.  A partir do [!INCLUDE[cpp_dev10_long](../Token/cpp_dev10_long_md.md)], a palavra\-chave`auto` declara uma variável cujo tipo é deduzido da expressão de inicialização na declaração.  A opção de compilador [\/Zc:auto&#91;\-&#93;](../build/reference/zc-auto-deduce-variable-type.md) controla o significado da palavra\-chave `auto`.  
  
## Sintaxe  
  
```cpp  
auto declarator ;  
auto declarator initializer;  
```  
  
## Comentários  
 A definição da palavra\-chave `auto` muda na linguagem de programação C\+\+, mas não na linguagem de programação C.  
  
 Os tópicos a seguir descrevem a palavra\-chave `auto` e a opção de compilador correspondente:  
  
-   [auto](../cpp/auto-cpp.md) descreve a nova definição da palavra\-chave `auto`.  
  
-   [\(NOTINBUILD\)auto Keyword \(Storage\-Class Specifier\)](http://msdn.microsoft.com/pt-br/c7d0cecf-393d-4058-a6e6-b39e31d9edb0) descreve a definição original da palavra\-chave `auto`.  
  
-   [\/Zc:auto \(deduzir tipo variável\)](../build/reference/zc-auto-deduce-variable-type.md) descreve a opção de compilador que informa ao compilador qual definição da palavra\-chave `auto` deve ser usada.  
  
## Consulte também  
 [\(NOTINBUILD\)Storage\-Class Specifiers](http://msdn.microsoft.com/pt-br/10b3d22d-cb40-450b-994b-08cf9a211b6c)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)