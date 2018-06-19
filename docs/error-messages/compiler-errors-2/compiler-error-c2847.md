---
title: C2847 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2847
dev_langs:
- C++
helpviewer_keywords:
- C2847
ms.assetid: 9ad9a0e0-8b16-49d9-a5be-f8eda2372aa9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cd18d685649c5ad8f03e3fdbb8b375717227f4c2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33245969"
---
# <a name="compiler-error-c2847"></a>C2847 de erro do compilador
não é possível aplicar sizeof gerenciado ou tipo de WinRT 'class'  
  
 O [sizeof](../../cpp/sizeof-operator.md) operador obtém o valor de um objeto em tempo de compilação. O tamanho de um gerenciado ou classe WinRT, interface ou tipo de valor é dinâmico e não pode ser conhecido em tempo de compilação.  
  
 Por exemplo, o exemplo a seguir gera C2847:  
  
```  
// C2847.cpp  
// compile with: /clr  
ref class A {};  
  
int main() {  
   A ^ xA = gcnew A;  
   sizeof(*xA);   // C2847 cannot use sizeof on managed object  
}  
```  
