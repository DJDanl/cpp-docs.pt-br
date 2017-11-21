---
title: C4950 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4950
dev_langs: C++
helpviewer_keywords: C4950
ms.assetid: 50226a5c-c664-4d09-ac59-e9e874ca244f
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 6a922a0ee324afcf5f263abe2189e4071c5575c7
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-c4950"></a>C4950 de aviso do compilador
'type_or_member': marcado como obsoleto  
  
Um membro ou tipo foi marcado como obsoleto com o <xref:System.ObsoleteAttribute> atributo.  
  
C4950 sempre é emitido como um erro. Você pode desativar esse aviso usando o [aviso](../../preprocessor/warning.md) diretiva pragma ou [/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C4950:  
  
```cpp  
// C4950.cpp  
// compile with: /clr  
using namespace System;  
  
// Any reference to Func3 should generate an error with message  
[System::ObsoleteAttribute("Will be removed in next version", true)]  
Int32 Func3(Int32 a, Int32 b) {  
   return (a + b);  
}  
  
int main() {  
   Int32 MyInt3 = ::Func3(2, 2);   // C4950  
}  
```