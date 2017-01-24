---
title: "Bibliotecas seguras: Biblioteca Padr&#227;o C++ | Microsoft Docs"
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
  - "_SCL_SECURE_NO_DEPRECATE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Bibliotecas Seguras"
  - "Bibliotecas seguras, biblioteca C++ padrão"
  - "Biblioteca Padrão C++ Segura"
ms.assetid: 3993340f-1f29-4d81-b3f5-52a52bc8e148
caps.latest.revision: 10
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Bibliotecas seguras: Biblioteca Padr&#227;o C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Vários aprimoramentos foram feitos para as bibliotecas fornecidas com o Visual C\+\+, incluindo a biblioteca C\+\+ padrão, para torná\-los mais seguros.  
  
 Vários métodos na biblioteca C\+\+ padrão foram identificados como potencialmente inseguro porque podem causar um estouro de buffer ou outros defeitos de código. Não é recomendado o uso desses métodos, e métodos novos e mais seguros foram criados para substituí\-los. Esses novos métodos todos terminam em `_s`.  
  
 Também foram feitas várias melhorias para tornar os iteradores e algoritmos mais seguros. Para obter mais informações, consulte [Iteradores Verificados](../standard-library/checked-iterators.md), [Suporte a Iterador de Depuração](../standard-library/debug-iterator-support.md) e [\_ITERATOR\_DEBUG\_LEVEL](../standard-library/iterator-debug-level.md).  
  
## Comentários  
 A tabela a seguir lista os métodos de biblioteca C\+\+ padrão que são potencialmente não seguros, bem como seus equivalentes mais segura:  
  
|Método potencialmente não seguro|Equivalente mais seguro|  
|--------------------------------------|-----------------------------|  
|[basic\_string::copy](../Topic/basic_string::copy.md)|[basic\_string::\_Copy\_s](../Topic/basic_string::_Copy_s.md)|  
|[char\_traits::copy](../Topic/char_traits::copy.md)|[char\_traits::\_Copy\_s](../Topic/char_traits::_Copy_s.md)|  
  
 Se você chamar qualquer um dos métodos acima potencialmente não seguros, ou se você usar iteradores incorretamente, o compilador irá gerar [Compilador \(nível 3\) aviso C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). Para obter informações sobre como desabilitar esses avisos, consulte [\_SCL\_SECURE\_NO\_WARNINGS](../standard-library/scl-secure-no-warnings.md).  
  
## Nesta seção  
 [\_ITERATOR\_DEBUG\_LEVEL](../standard-library/iterator-debug-level.md)  
  
 [\_SCL\_SECURE\_NO\_WARNINGS](../standard-library/scl-secure-no-warnings.md)  
  
 [Iteradores Verificados](../standard-library/checked-iterators.md)  
  
 [Suporte a Iterador de Depuração](../standard-library/debug-iterator-support.md)  
  
## Consulte também  
 [Visão geral da STL](../standard-library/cpp-standard-library-overview.md)