---
title: "Diretivas #ifdef e #ifndef (C/C++) | Microsoft Docs"
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
  - "#ifndef"
  - "#ifdef"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Diretiva #ifdef"
  - "Diretiva #ifndef"
  - "diretiva ifdef (#ifdef)"
  - "diretiva ifndef (#ifndef)"
  - "pré-processador, Diretivas ()"
ms.assetid: 2b0be69d-9e72-45d8-8e24-e4130fb2455b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretivas #ifdef e #ifndef (C/C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As políticas **\#ifdef** e **\#ifndef** executam a mesma tarefa da política `#if` quando usadas com **defined**\( *identifier* \).  
  
## Sintaxe  
  
```  
#ifdef identifier  
#ifndef identifier  
  
// equivalent to  
#if defined identifier  
#if !defined identifier  
```  
  
## Comentários  
 É possível usar as políticas **\#ifdef** e **\#ifndef** em qualquer lugar que `#if` possa ser usado.  A instrução **\#ifdef** *identifier* é equivalente a `#if 1` quando o *identificador* é definido e é equivalente a `#if 0` quando o *identificador* não é definido ou se tiver sido indefinido com a política `#undef`.  Essas políticas verificam somente a presença ou ausência de identificadores definidos com `#define`, não para identificadores declarados no código\-fonte C ou C\+\+.  
  
 Essas políticas são fornecidas somente para compatibilidade com versões anteriores da linguagem.  A expressão de constante **defined\(** *identifier* **\)** usada com a política `#if` é preferencial.  
  
 A política **\#ifndef** verifica o oposto da condição verificada por **\#ifdef**.  Se o identificador não foi definido \(ou a definição foi removida com `#undef`\), a condição é true \(diferente de zero\).  Caso contrário, a condição será false \(0\).  
  
 **Específico da Microsoft**  
  
 O *identificador* pode ser passado da linha de comando usando a opção \/D.  Até 30 macros podem ser especificadas com \/D.  
  
 Isso é útil para verificar se uma definição existe, uma vez que uma definição pode ser passada da linha de comando.  Por exemplo:  
  
```  
// ifdef_ifndef.CPP  
// compile with: /Dtest /c  
#ifndef test  
#define final  
#endif  
```  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Diretivas de pré\-processador](../preprocessor/preprocessor-directives.md)