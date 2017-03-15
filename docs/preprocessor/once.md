---
title: "once | Microsoft Docs"
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
  - "vc-pragma.once"
  - "once_CPP"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragma once"
  - "pragmas, once"
ms.assetid: c7517556-6403-4b16-8898-f2aa0a6f685f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# once
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica que o arquivo será incluído \(aberto\) apenas uma vez pelo compilador ao compilar um arquivo de código\-fonte.  
  
## Sintaxe  
  
```  
  
#pragma once  
  
```  
  
## Comentários  
 O uso de `#pragma once` pode reduzir os tempos de compilação, o compilador não abrirá e lerá o arquivo após o primeiro \#include do arquivo na unidade de tradução.  Isso é conhecido como *otimização de incluir várias*.  Ele tem um efeito semelhante para o *\#include guard* linguagem, que usa as definições de macro de pré\-processador para impedir que vários inclusão de conteúdo do arquivo.  Isso também ajuda a impedir violações de *regra de definição de um*— o requisito de que todos os modelos, tipos, funções e objetos têm mais de uma definição em seu código.  
  
 Por exemplo:  
  
```  
// header.h  
#pragma once  
// Code placed here is included only once per translation unit  
  
```  
  
 Recomendamos a `#pragma once` diretiva para o novo código porque ele não poluir o namespace global com um símbolo do pré\-processador.  Ele requer menos digitação, é menos distração e não pode provocar colisões de símbolo — erros causados quando os arquivos de cabeçalho diferente usam o símbolo do pré\-processador mesmo como o valor de proteção.  Não é parte do padrão C\+\+, mas é implementado portably por diversos compiladores comuns.  
  
 Não há nenhuma vantagem em usar tanto o \#include protetor de linguagem e `#pragma once` no mesmo arquivo.  O compilador reconhece o \#include protetor de linguagem e implementa o múltiplo incluem a otimização da mesma forma que o `#pragma once` diretiva se nenhum código sem comentário ou diretiva de pré\-processador vem antes ou depois da forma padrão da linguagem:  
  
```  
// header.h  
// Demonstration of the #include guard idiom.  
// Note that the defined symbol can be arbitrary.  
#ifndef HEADER_H_     // equivalently, #if !defined HEADER_H_  
#define HEADER_H_  
// Code placed here is included only once per translation unit  
#endif // HEADER_H_  
  
```  
  
 Recomendamos o \#include protetor de linguagem ao código deve ser portáteis para compiladores que não implementam a `#pragma once` diretiva para manter a consistência com o código existente, ou quando a incluir vários otimização é impossível.  Isso pode ocorrer em projetos complexos ao alias de sistema de arquivos ou um alias incluir caminhos prevenir que o compilador identifica idêntico incluir arquivos pelo caminho canônico.  
  
 Tenha cuidado para não usar `#pragma once` ou \#include protetor de idioma em arquivos de cabeçalho que são projetados para ser incluída várias vezes, usando símbolos de pré\-processador para controlar seus efeitos.  Para obter um exemplo desse design, consulte o arquivo de cabeçalho \< Assert. h \>.  Também ser cuidadoso ao gerenciar incluir caminhos para evitar a criação de vários caminhos para arquivos incluídos, que podem anular a incluir vários de otimização para ambos \#include protege e `#pragma once`.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)