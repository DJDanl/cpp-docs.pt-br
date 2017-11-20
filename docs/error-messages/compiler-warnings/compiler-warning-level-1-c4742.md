---
title: "Compilador (nível 1) de aviso C4742 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4742
dev_langs: C++
helpviewer_keywords: C4742
ms.assetid: e520881d-1eeb-48b1-9df0-8017ee8ba076
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 934c7d14d95d0b90cfdcdb694f743e6b13abd0e2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4742"></a>Compilador C4742 de aviso (nível 1)
'var' possui alinhamento diferente em 'file1' e 'file2': número e o número  
  
 Uma variável externa que foi referenciada ou definida em dois arquivos possui alinhamento diferente nesses arquivos. Esse aviso é emitido quando o compilador encontra que `__alignof` para a variável na *file1* difere `__alignof` para a variável na *file2*. Isso pode ser causado por meio de tipos incompatíveis ao declarar a variável em diferentes arquivos, ou usando a correspondência não `#pragma pack` em arquivos diferentes.  
  
 Para resolver este aviso, use a mesma definição de tipo ou usar nomes diferentes para as variáveis.  
  
 Para obter mais informações, consulte [pacote](../../preprocessor/pack.md) e [alignof operador](../../cpp/alignof-operator.md).  
  
## <a name="example"></a>Exemplo  
 Este é o primeiro arquivo que define o tipo.  
  
```  
// C4742a.c  
// compile with: /c  
struct X {  
   char x, y, z, w;  
} global;  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4742.  
  
```  
// C4742b.c  
// compile with: C4742a.c /W1 /GL  
// C4742 expected  
extern struct X {  
   int a;  
} global;  
  
int main() {  
   global.a = 0;  
}  
```