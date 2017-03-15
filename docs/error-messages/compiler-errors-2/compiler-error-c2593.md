---
title: C2593 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2593
dev_langs:
- C++
helpviewer_keywords:
- C2593
ms.assetid: 4a0fe9bb-2163-447d-91f6-1890ed8250f6
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a9028227315c1887d226a8fd4833f57346ace62c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2593"></a>C2593 de erro do compilador
'operador identifier' é ambíguo  
  
 Mais de um operador possíveis é definido para um operador sobrecarregado.  
  
 Esse erro pode ser corrigido se você usar uma conversão explícita em um ou mais parâmetros reais.  
  
 O exemplo a seguir gera C2593:  
  
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
  
 Esse erro pode ser causado pela serialização uma variável ponto flutuante usando um `CArchive` objeto. O compilador identifica o `<<` operador como ambígua. O C++ apenas primitivos tipos que `CArchive` pode serializar os tipos de tamanho fixo `BYTE`, `WORD`, `DWORD`, e `LONG`. Todos os tipos de inteiro devem ser convertidos em um desses tipos para serialização. Tipos de ponto flutuante devem ser arquivados usando o `CArchive::Write()` função de membro.  
  
 O exemplo a seguir mostra como arquivar uma variável de ponto flutuante (`f`) ao arquivo `ar`:  
  
```  
ar.Write(&f, sizeof( float ));  
```
