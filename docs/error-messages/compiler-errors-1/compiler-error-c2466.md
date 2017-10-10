---
title: C2466 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2466
dev_langs:
- C++
helpviewer_keywords:
- C2466
ms.assetid: 75b251d1-7d0b-4a86-afca-26adedf74486
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 3c3ad19ce37aa51bd6b670da6e857d7eccce04ca
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
