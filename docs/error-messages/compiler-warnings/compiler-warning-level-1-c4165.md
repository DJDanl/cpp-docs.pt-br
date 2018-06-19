---
title: Compilador (nível 1) de aviso C4165 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4165
dev_langs:
- C++
helpviewer_keywords:
- C4165
ms.assetid: f5bed515-2290-4f88-8dab-b45d95fe26ef
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 39487999f2aa74a5600d84d71917712e03b2d626
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33277560"
---
# <a name="compiler-warning-level-1-c4165"></a>Compilador C4165 de aviso (nível 1)
'HRESULT' está sendo convertido em 'bool'; Tem certeza de que é isso que você deseja?  
  
Ao usar um HRESULT em um [se](../../cpp/if-else-statement-cpp.md) instrução, o HRESULT será convertido em um [bool](../../cpp/bool-cpp.md) , a menos que você explicitamente de teste para a variável como um HRESULT. Esse aviso é desativada por padrão.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C4165  
  
```cpp  
// C4165.cpp  
// compile with: /W1  
#include <windows.h>  
#pragma warning(1:4165)  
  
extern HRESULT hr;  
int main() {  
   if (hr) {  
   // try either of the following ...  
   // if (FAILED(hr)) { // C4165 expected  
   // if (hr != S_OK) {  
   }  
}  
```