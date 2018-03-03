---
title: "Compilador (nível 4) de aviso C4221 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4221
dev_langs:
- C++
helpviewer_keywords:
- C4221
ms.assetid: 8532bd68-54dc-4526-8597-f61dcb0a0129
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6a08b300961bd19cc0355cc556d52dd00d05632e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4221"></a>Compilador C4221 de aviso (nível 4)
extensão não padrão usada: 'Identificador': não pode ser inicializado usando endereço da variável automática  
  
 Com as extensões do Microsoft padrão (/Ze), você pode inicializar um tipo de agregação (**matriz**, `struct`, ou **união**) com o endereço de uma variável (automático) local.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4221.c  
// compile with: /W4  
struct S  
{  
   int *i;  
};  
  
void func()  
{  
   int j;  
   struct S s1 = { &j };   // C4221  
}  
  
int main()  
{  
}  
```  
  
 Inicializações são inválidas em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).