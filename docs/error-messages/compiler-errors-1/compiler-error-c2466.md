---
title: C2466 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2466
dev_langs:
- C++
helpviewer_keywords:
- C2466
ms.assetid: 75b251d1-7d0b-4a86-afca-26adedf74486
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e55e5c130b0a0454577a7155b704a18933b86198
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2466"></a>C2466 de erro do compilador
não é possível alocar uma matriz de tamanho constante 0  
  
 Uma matriz é alocada ou declarada com tamanho zero. A expressão de constante para o tamanho da matriz deve ser um inteiro maior que zero. Uma declaração de matriz com um zero subscrito é válida apenas para uma classe, estrutura ou membro de união e apenas com extensões da Microsoft ([/Ze](../../build/reference/za-ze-disable-language-extensions.md)).  
  
 O exemplo a seguir gera C2466:  
  
```  
// C2466.cpp  
// compile with: /c  
int i[0];   // C2466  
int j[1];   // OK  
char *p;  
```