---
title: "Compilador aviso (nível 1) C4742 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4742
dev_langs:
- C++
helpviewer_keywords:
- C4742
ms.assetid: e520881d-1eeb-48b1-9df0-8017ee8ba076
caps.latest.revision: 6
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 36d2106062c2dd2a20054ce4656ec4ee826955b1
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4742"></a>Compilador C4742 de aviso (nível 1)
'var' tem um alinhamento diferente em 'file1' e 'file2': número e número  
  
 Uma variável externa que foi referenciada ou definida em dois arquivos tem alinhamento diferente nesses arquivos. Esse aviso é emitido quando o compilador encontra que `__alignof` para a variável na *file1* difere `__alignof` para a variável na *file2*. Isso pode ser causado por meio de tipos incompatíveis ao declarar a variável em arquivos diferentes, ou usando não correspondentes `#pragma pack` em arquivos diferentes.  
  
 Para resolver esse aviso, use a mesma definição de tipo ou usar nomes diferentes para as variáveis.  
  
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
