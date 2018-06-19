---
title: C3813 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3813
dev_langs:
- C++
helpviewer_keywords:
- C3813
ms.assetid: ffdbc489-71bf-4cd6-988c-f824c9ab3ceb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e947b281c90c4d2ace83971f1de972c29bde72ac
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33273101"
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