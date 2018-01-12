---
title: C3622 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3622
dev_langs: C++
helpviewer_keywords: C3622
ms.assetid: 02836f78-0cf2-4947-b87e-710187d81014
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 75d853b01f4f88fbf5e435b3b1f7a86fed0c8388
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3622"></a>C3622 de erro do compilador
'class': uma classe declarada como 'palavra-chave' não pode ser instanciado  
  
Foi feita uma tentativa para instanciar uma classe marcada como [abstrata](../../windows/abstract-cpp-component-extensions.md). Uma classe marcada como `abstract` pode ser uma classe base, mas ele não pode ser instanciado.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3622.  
  
```  
// C3622.cpp  
// compile with: /clr  
ref class a abstract {};  
  
int main() {  
   a aa;   // C3622  
}  
```  
