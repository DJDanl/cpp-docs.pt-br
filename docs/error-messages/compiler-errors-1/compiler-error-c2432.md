---
title: C2432 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2432
dev_langs:
- C++
helpviewer_keywords:
- C2432
ms.assetid: 0e3326e8-cab1-45a5-b48d-61edd33793e8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e921fa0cd2a9c56b6449b554fcee307c1121c598
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2432"></a>C2432 de erro do compilador
referência inválida para dados de 16 bits em 'Identificador'  
  
 Um registro de 16 bits é usado como um índice ou registro base. O compilador não oferece suporte para fazer referência a dados de 16 bits. registros de 16 bits não podem ser usados como índice ou a base de dados de registros ao compilar o código de 32 bits.  
  
 O exemplo a seguir gera C2432:  
  
```  
// C2432.cpp  
// processor: x86  
int main() {  
   _asm mov eax, DWORD PTR [bx]   // C2432  
}  
```