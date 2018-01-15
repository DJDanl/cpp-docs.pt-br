---
title: 'Como: Fixar ponteiros e matrizes | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- pointers, pinning
- arrays [C++], pinning
ms.assetid: ee783260-e676-46b8-a38e-11a06f1d57b0
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 68824b9fcdf2f4de47900d5b0c4b03db9e28d9fe
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-pin-pointers-and-arrays"></a>Como fixar ponteiros e matrizes
A fixação de um Subobjeto definido em um objeto gerenciado tem o efeito de fixar o objeto inteiro.  Por exemplo, se qualquer elemento da matriz é fixado, a matriz inteira também está fixada. Não existem extensões para a linguagem para declarar uma matriz fixada. Para fixar uma matriz, declare um ponteiro de fixação de tipo de elemento e fixar um de seus elementos.  
  
## <a name="example"></a>Exemplo  
  
### <a name="code"></a>Código  
  
```  
// pin_ptr_array.cpp  
// compile with: /clr  
#include <stdio.h>  
using namespace System;  
  
int main() {  
   array<Byte>^ arr = gcnew array<Byte>(4);  
   arr[0] = 'C';  
   arr[1] = '+';  
   arr[2] = '+';  
   arr[3] = '\0';  
   pin_ptr<Byte> p = &arr[1];   // entire array is now pinned  
   unsigned char * cp = p;  
  
   printf_s("%s\n", cp); // bytes pointed at by cp  
                         // will not move during call  
}  
```  
  
### <a name="output"></a>Saída  
  
```  
++  
```  
  
## <a name="see-also"></a>Consulte também  
 [pin_ptr (C++/CLI)](../windows/pin-ptr-cpp-cli.md)