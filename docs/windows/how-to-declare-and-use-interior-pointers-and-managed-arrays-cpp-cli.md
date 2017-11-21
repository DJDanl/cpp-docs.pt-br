---
title: 'Como: declarar e usar ponteiros internos e matrizes gerenciadas (C + + CLI) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- pointers, interior
- arrays [C++], managed
ms.assetid: e61a2c09-a7d0-4867-91ea-6b8788a01079
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 83cd51bbba64a9b28e8b3cf7f9a1ecadd369d16b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-declare-and-use-interior-pointers-and-managed-arrays-ccli"></a>Como declarar e usar ponteiros internos e matrizes gerenciadas (C++/CLI)
Os seguintes C + + exemplo CLI mostra como declarar e usar um ponteiro interior em uma matriz.  
  
> [!IMPORTANT]
>  Este recurso de idioma é suportado pelo **/clr** opção de compilador, mas não pelo **/ZW** opção de compilador.  
  
## <a name="example"></a>Exemplo  
  
### <a name="code"></a>Código  
  
```  
// interior_ptr_arrays.cpp  
// compile with: /clr  
#define SIZE 10  
  
int main() {  
   // declare the array  
   array<int>^ arr = gcnew array<int>(SIZE);  
  
   // initialize the array  
   for (int i = 0 ; i < SIZE ; i++)  
      arr[i] = i + 1;  
  
   // create an interior pointer into the array  
   interior_ptr<int> ipi = &arr[0];  
  
   System::Console::WriteLine("1st element in arr holds: {0}", arr[0]);  
   System::Console::WriteLine("ipi points to memory address whose value is: {0}", *ipi);  
  
   ipi++;  
   System::Console::WriteLine("after incrementing ipi, it points to memory address whose value is: {0}", *ipi);  
}  
```  
  
### <a name="output"></a>Saída  
  
```  
1st element in arr holds: 1  
ipi points to memory address whose value is: 1  
after incrementing ipi, it points to memory address whose value is: 2  
```  
  
## <a name="see-also"></a>Consulte também  
 [interior_ptr (C++/CLI)](../windows/interior-ptr-cpp-cli.md)