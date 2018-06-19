---
title: C2071 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2071
dev_langs:
- C++
helpviewer_keywords:
- C2071
ms.assetid: f8c09255-a5c4-47e3-8089-3d875ae43cc5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: faee56023d14e9b010d1c691af654ffcbc31dc78
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33169199"
---
# <a name="compiler-error-c2071"></a>C2071 de erro do compilador
"identificador": classe de armazenamento inválido  
  
 `identifier` foi declarado com inválido [classe de armazenamento](../../c-language/c-storage-classes.md). Esse erro pode ser causado quando mais de uma classe de armazenamento for especificada para um identificador ou quando a definição for incompatível com a declaração de classe de armazenamento.  
  
 Para corrigir esse problema, entender a classe de armazenamento desejado do identificador — por exemplo, `static` ou `extern`— e corrija a declaração para corresponder.  
  
## <a name="example"></a>Exemplo  
 O seguinte exemplo gera C2071.  
  
```  
// C2071.cpp  
// compile with: /c  
struct C {  
   extern int i;   // C2071  
};  
struct D {  
   int i;   // OK, no extern on an automatic  
};  
```  
  
## <a name="example"></a>Exemplo  
 O seguinte exemplo gera C2071.  
  
```  
// C2071_b.cpp  
// compile with: /c  
typedef int x(int i) { return i; }   // C2071  
typedef int (x)(int);   // OK, no local definition in typedef  
```