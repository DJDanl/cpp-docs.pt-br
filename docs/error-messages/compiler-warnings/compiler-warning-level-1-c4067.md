---
title: Compilador (nível 1) de aviso C4067 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4067
dev_langs:
- C++
helpviewer_keywords:
- C4067
ms.assetid: 1d10353e-8cd5-4b01-9184-a06189b965a4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4eccec985e6a9e652f18c6513542942351ff6efc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4067"></a>Compilador C4067 de aviso (nível 1)
tokens inesperados após diretiva de pré-processador - esperado um newline  
  
 O compilador encontrada e ignorada caracteres extras após uma diretiva de pré-processador. Esse aviso é exibido apenas sob compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).  
  
```  
// C4067a.cpp  
// compile with: /DX /Za /W1  
#pragma warning(default:4067)  
#if defined(X)  
#else  
#endif v   // C4067  
int main()  
{  
}  
```  
  
### <a name="to-resolve-this-warning-try-the-following"></a>Para resolver este aviso, tente o seguinte:  
  
1.  Compilar com **/Ze**.  
  
2.  Use delimitadores de comentário:  
  
```  
// C4067b.cpp  
// compile with: /DX /Za /W1  
#if defined(X)  
#else  
#endif  
int main()  
{  
}  
```