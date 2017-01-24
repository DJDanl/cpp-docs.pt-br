---
title: "Diretiva #undef (C/C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "#undef"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Diretiva #undef"
  - "pré-processador, Diretivas ()"
  - "diretiva undef (#undef)"
ms.assetid: 88900e0e-2c19-4a63-b681-f3d3133c24ca
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretiva #undef (C/C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Remove \(não define\) um nome criado anteriormente com `#define`.  
  
## Sintaxe  
  
```  
  
#undef   
identifier  
  
```  
  
## Comentários  
 A política `#undef` remove a definição atual do *identificador*.  Consequentemente, as ocorrências subsequentes do *identificador* serão ignoradas pelo pré\-processador.  Para remover uma definição de macro usando `#undef`, especifique apenas o *identificador* da macro; não forneça uma lista de parâmetros.  
  
 Você também pode aplicar a política de `#undef` a um identificador que não tem nenhuma definição anterior.  Isso garante que o identificador seja indefinido.  A substituição da macro não é executada nas instruções de `#undef`.  
  
 A política de `#undef` é emparelhada normalmente com uma política de `#define` para criar uma região em um programa de origem no qual um identificador tem um significado especial.  Por exemplo, uma função específica do programa de origem pode usar constantes manifestas para definir os valores específicos que não afetam o restante do programa.  A política de `#undef` também funciona com a política de `#if` para controlar a compilação condicional do programa de origem.  Consulte [O \#if, o \#elif, o \#else e as políticas de \#endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md) para obter mais informações.  
  
 No exemplo a seguir, a política de `#undef` remove as definições de uma constante de token e de uma macro.  Somente o identificador de macro será fornecido.  
  
```  
#define WIDTH 80  
#define ADD( X, Y ) ((X) + (Y))  
.  
.  
.  
#undef WIDTH  
#undef ADD  
```  
  
 **Específico da Microsoft**  
  
 Macros podem ser definidas a partir da linha de comando usando a opção \/U, seguida dos nomes de macros a serem definidos.  O efeito de emitir esse comando é equivalente a uma sequência de instruções *macro\-name* `#undef`no início do arquivo.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Diretivas de pré\-processador](../preprocessor/preprocessor-directives.md)