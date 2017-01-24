---
title: "Diretivas de pr&#233;-processador | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "Diretivas (), pré-processador"
  - "pré-processador, Diretivas ()"
ms.assetid: e0fc4564-b6cf-4a36-bf51-6ccd7abd0a94
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretivas de pr&#233;-processador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As políticas de pré\-processador, como `#define` e **\#ifdef**, normalmente são usadas para tornar os programas de origem mais fáceis de alterar e compilar em diferentes ambientes de execução.  As políticas no arquivo de origem mandam o pré\-processador realizar ações específicas.  Por exemplo, o pré\-processador pode substituir tokens no texto, inserir o conteúdo de outros arquivos no arquivo de origem ou suprimir a compilação de parte do arquivo removendo seções de texto.  As linhas do pré\-processador são reconhecidas e executadas antes de expansão macro.  Portanto, se uma macro se expandir até algo que se pareça com um comando do pré\-processador, esse comando não será reconhecido pelo pré\-processador.  
  
 As instruções do pré\-processador usam o mesmo conjunto de caracteres das instruções de arquivo de origem, com exceção das sequências de escape, que não têm suporte.  O conjunto de caracteres usado em instruções do pré\-processador é igual ao [conjunto de caracteres de execução](http://msdn.microsoft.com/pt-br/a7901c61-524d-47c6-beb6-d9dacc2e72ed).  O pré\-processador também reconhece valores negativos de caracteres.  
  
 O pré\-processador reconhece as políticas a seguir:  
  
|||||  
|-|-|-|-|  
|[\#define](../preprocessor/hash-define-directive-c-cpp.md)|[\#error](../preprocessor/hash-error-directive-c-cpp.md)|[\#import](../Topic/%23import%20Directive%20\(C++\).md)|[\#undef](../preprocessor/hash-undef-directive-c-cpp.md)|  
|[\#elif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|[\#if](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|[\#include](../preprocessor/hash-include-directive-c-cpp.md)|[\#using](../preprocessor/hash-using-directive-cpp.md)|  
|[\#else](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|[\#ifdef](../preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp.md)|[\#line](../Topic/%23line%20Directive%20\(C-C++\).md)|[\#endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|  
|[\#ifndef](../preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp.md)|[\#pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)|||  
  
 A tecla de cerquilha \(**\#**\) deve ser o primeiro caractere de espaço não em branco na linha que contém a política; os caracteres de espaço em branco podem aparecer entre a tecla de cerquilha e a primeira letra da política.  Algumas políticas incluem argumentos ou valores.  Qualquer texto que segue uma política \(exceto um argumento ou um valor que é parte da política\) deve ser precedido pelo delimitador de comentário de linha única \(**\/\/**\) ou ser incluído em delimitadores de comentário \(**\/\* \*\/**\).  As linhas que contêm políticas de pré\-processamento podem ser continuadas pela predecessão imediata do marcador de final de linha de uma barra invertida \(**\\**\).  
  
 As políticas do pré\-processador podem aparecer em qualquer lugar do arquivo de origem, mas se aplicam somente ao restante dele.  
  
## Consulte também  
 [Operadores de pré\-processador](../preprocessor/preprocessor-operators.md)   
 [Macros predefinidas](../preprocessor/predefined-macros.md)   
 [Referência de pré\-processador C\/C\+\+](../preprocessor/c-cpp-preprocessor-reference.md)