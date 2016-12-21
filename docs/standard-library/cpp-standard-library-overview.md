---
title: "Vis&#227;o geral da Biblioteca Padr&#227;o C++ | Microsoft Docs"
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
helpviewer_keywords: 
  - "cabeçalhos, biblioteca C++"
  - "bibliotecas, C++ Padrão"
  - "Biblioteca Padrão C++"
  - "Biblioteca Padrão C++, cabeçalhos"
ms.assetid: 7acb83a4-da73-4ad3-bc30-a71289db7f60
caps.latest.revision: 16
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vis&#227;o geral da Biblioteca Padr&#227;o C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Todas as entidades de biblioteca C\+\+ são declaradas ou definidas em um ou mais cabeçalhos padrão.  Essa implementação inclui dois cabeçalhos adicionais, `<hash_map>` e `<hash_set>`, que não são exigidos pelo padrão C\+\+.  Para obter uma lista completa dos cabeçalhos que essa implementação suporta, consulte [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md).  
  
 Uma implementação independente da biblioteca C\+\+ fornece apenas um subconjunto desses cabeçalhos:  
  
|||  
|-|-|  
|[\<cstddef\>](../Topic/%3Ccstddef%3E.md)|[\<cstdlib\>](../standard-library/cstdlib.md) \(pelo menos declarar as funções `abort`, `atexit`, e `exit`\)|  
|[\< exceção \>](../standard-library/exception.md)|[\<limits\>](../standard-library/limits.md)|  
|[\<new\>](../standard-library/new.md)|[\<cstdarg\>](../Topic/%3Ccstdarg%3E.md)|  
  
 Os cabeçalhos da biblioteca C\+\+ têm dois subdivisões maiores:  
  
-   [iostreams](../standard-library/iostreams-conventions.md) convenções.  
  
-   [Standard Template Library](../misc/standard-template-library.md) convenções.  
  
 Esta seção contém as seções a seguir:  
  
-   [Usando cabeçalhos da Biblioteca C\+\+](../standard-library/using-cpp-library-headers.md)  
  
-   [Convenções da Biblioteca C\+\+](../standard-library/cpp-library-conventions.md)  
  
-   [Convenções iostreams](../standard-library/iostreams-conventions.md)  
  
-   [Inicialização e encerramento de programas em C\+\+](../standard-library/cpp-program-startup-and-termination.md)  
  
-   [Bibliotecas seguras: Biblioteca Padrão C\+\+](../standard-library/safe-libraries-cpp-standard-library.md)  
  
-   [Iteradores Verificados](../standard-library/checked-iterators.md)  
  
-   [Suporte a Iterador de Depuração](../standard-library/debug-iterator-support.md)  
  
-   [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)  
  
-   [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)  
  
-   [Namespace stdext](../Topic/stdext%20Namespace.md)  
  
-   [Expressões regulares \(C\+\+\)](../standard-library/regular-expressions-cpp.md)  
  
 Para obter mais informações sobre as bibliotecas de tempo de execução do Visual C\+\+, consulte [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).  
  
## Consulte também  
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)