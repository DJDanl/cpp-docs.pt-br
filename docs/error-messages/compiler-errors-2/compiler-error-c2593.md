---
title: "Erro do Compilador C2593 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2593"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2593"
ms.assetid: 4a0fe9bb-2163-447d-91f6-1890ed8250f6
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2593
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o identificador de operador” é ambíguo  
  
 Mais de um operador possível é definido para um operador sobrecarregado.  
  
 Esse erro pode ser corrigido se você usar uma conversão explícita em um ou mais parâmetros reais.  
  
 O seguinte exemplo gera C2593:  
  
```  
// C2593.cpp  
struct A {};  
struct B : A {};  
struct X {};  
struct D : B, X {};  
void operator+( X, X );  
void operator+( A, B );  
D d;  
  
int main() {  
   d +  d;         // C2593, D has an A, B, and X   
   (X)d + (X)d;    // OK, uses operator+( X, X )  
}  
```  
  
 Esse erro pode ser causado serializando uma variável de ponto flutuante usando um objeto de `CArchive` .  O compilador identifica o operador de `<<` como ambígua.  Os únicos tipos de primitivo C\+\+ que `CArchive` possível serializar são tipos de tamanho fixo `BYTE`, `WORD`, `DWORD`, e `LONG`.  Todos os tipos de inteiro devem ser convertidos em um desses tipos para a serialização.  Os tipos de ponto flutuante devem ser arquivados usando a função de membro de `CArchive::Write()` .  
  
 O exemplo a seguir mostra como arquivamento uma variável de ponto flutuante \(`f`\) para arquivar `ar`:  
  
```  
ar.Write(&f, sizeof( float ));  
```