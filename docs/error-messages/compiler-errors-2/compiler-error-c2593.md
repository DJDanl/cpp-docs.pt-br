---
title: C2593 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2593
dev_langs:
- C++
helpviewer_keywords:
- C2593
ms.assetid: 4a0fe9bb-2163-447d-91f6-1890ed8250f6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e419416266e0e3c4ebff8190b3b26b1c43c9ba0f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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