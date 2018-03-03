---
title: C2593 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2593
dev_langs:
- C++
helpviewer_keywords:
- C2593
ms.assetid: 4a0fe9bb-2163-447d-91f6-1890ed8250f6
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 675c929995e7b0c4043586cf081343136d8e7a5e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2593"></a>C2593 de erro do compilador
'Identificador do operador' é ambíguo  
  
 Mais de um operador possíveis é definido para um operador sobrecarregado.  
  
 Esse erro pode ser corrigido, se você usar uma conversão explícita em um ou mais parâmetros reais.  
  
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
  
 Esse erro pode ser causado pela serialização de uma variável ponto flutuante usando um `CArchive` objeto. O compilador identifica o `<<` operador como ambígua. Tipos de C++ somente primitivo `CArchive` pode serializar os tipos de tamanho fixo `BYTE`, `WORD`, `DWORD`, e `LONG`. Todos os tipos de inteiro devem ser convertidos em um desses tipos de serialização. Tipos de ponto flutuante devem ser arquivados usando o `CArchive::Write()` função de membro.  
  
 O exemplo a seguir mostra como arquivar uma variável de ponto flutuante (`f`) ao arquivo `ar`:  
  
```  
ar.Write(&f, sizeof( float ));  
```