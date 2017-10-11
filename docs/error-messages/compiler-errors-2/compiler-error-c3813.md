---
title: C3813 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3813
dev_langs:
- C++
helpviewer_keywords:
- C3813
ms.assetid: ffdbc489-71bf-4cd6-988c-f824c9ab3ceb
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: cabe753691b3d72ede25f0c25404d73fb63ceba8
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3813"></a>C3813 de erro do compilador
uma declaração de propriedade só pode aparecer dentro da definição de um serviço ou tipo de WinRT  
  
Um [propriedade](../../dotnet/how-to-use-properties-in-cpp-cli.md) só pode ser declarado dentro de um gerenciado ou tempo de execução do Windows tipo. Tipos nativos não dão suporte a `property` palavra-chave.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3813 e mostra como corrigi-lo:  
  
```cpp  
// C3813.cpp  
// compile by using: cl /c /clr C3813.cpp  
class A  
{  
   property int Int; // C3813  
};  
  
ref class B  
{  
   property int Int; // OK - declared within managed type  
};  
```
