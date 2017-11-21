---
title: C3320 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3320
dev_langs: C++
helpviewer_keywords: C3320
ms.assetid: 2ef72d9a-1f1d-4b2e-b244-9fd3f3e70cb6
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: fbc375682bb42070d49dd08b711926462c17f32b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3320"></a>C3320 de erro do compilador
'type': tipo não pode ter o mesmo nome que a propriedade 'name' de módulo  
  
Um exportado-tipo definido pelo usuário (UDT), que pode ser um struct, classe, enum ou union, não pode ter o mesmo nome como o parâmetro passado para o [módulo](../../windows/module-cpp.md) propriedade de nome do atributo.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3320:  
  
```cpp  
// C3320.cpp  
#include "unknwn.h"  
[module(name="xx")];  
  
[export] struct xx {   // C3320  
// Try the following line instead  
// [export] struct yy {  
   int i;  
};  
```