---
title: C2432 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2432
dev_langs:
- C++
helpviewer_keywords:
- C2432
ms.assetid: 0e3326e8-cab1-45a5-b48d-61edd33793e8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8dfbadf2c7d53cce799efbd5f10286b31bb3cd3b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33196929"
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