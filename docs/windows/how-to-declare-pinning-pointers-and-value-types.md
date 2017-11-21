---
title: "Como: declarar ponteiros de fixação e tipos de valor | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- value types, declaring
- pinning pointers
ms.assetid: 57c5ec8a-f85a-48c4-ba8b-a81268bcede0
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 04ee5a54ec797324aa0bad6e72f8cfc0861d2a38
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-declare-pinning-pointers-and-value-types"></a>Como declarar ponteiros de fixação e tipos de valor
Um tipo de valor pode ser convertido implicitamente. Você pode, em seguida, declarar um ponteiro de fixação para o objeto de tipo de valor em si e use um **pin_ptr** para o tipo de valor Demarcado.  
  
## <a name="example"></a>Exemplo  
  
### <a name="code"></a>Código  
  
```  
// pin_ptr_value.cpp  
// compile with: /clr  
value struct V {  
   int i;  
};  
  
int main() {  
   V ^ v = gcnew V;   // imnplicit boxing  
   v->i=8;  
   System::Console::WriteLine(v->i);  
   pin_ptr<V> mv = &*v;  
   mv->i = 7;  
   System::Console::WriteLine(v->i);  
   System::Console::WriteLine(mv->i);  
}  
```  
  
### <a name="output"></a>Saída  
  
```  
8  
7  
7  
```  
  
## <a name="see-also"></a>Consulte também  
 [pin_ptr (C++/CLI)](../windows/pin-ptr-cpp-cli.md)