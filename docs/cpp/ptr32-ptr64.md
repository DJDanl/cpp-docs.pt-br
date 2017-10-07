---
title: ptr32, ptr64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __ptr32_cpp
- __ptr64_cpp
dev_langs:
- C++
helpviewer_keywords:
- __ptr64 keyword [C++]
- _ptr32 keyword [C++]
- ptr32 keyword [C++]
- ptr64 keyword [C++]
- _ptr64 keyword [C++]
- __ptr32 keyword [C++]
ms.assetid: afb563d8-7458-4fe7-9c30-bd4b5385a59f
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: d722f8403efbe1172fefbe8a792c95d4063e893f
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="ptr32-ptr64"></a>__ptr32, __ptr64
## <a name="microsoft-specific"></a>Específico da Microsoft  
 `__ptr32` representa um ponteiro nativo em um sistema de 32 bits, enquanto `__ptr64` representa um ponteiro nativo em um sistema de 64 bits.  
  
 O exemplo a seguir mostra como declarar cada um desses tipos de ponteiro:  
  
```  
int * __ptr32 p32;  
int * __ptr64 p64;  
```  
  
 Em um sistema de 32 bits, um ponteiro declarado com `__ptr64` é truncado em um ponteiro de 32 bits. Em um sistema de 64 bits, um ponteiro declarado com `__ptr32` é imposto a um ponteiro de 64 bits.  
  
> [!NOTE]
>  Não é possível usar `__ptr32` ou `__ptr64` ao compilar com **/clr: pure**. Caso contrário, o `Compiler Error C2472` será gerado. As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como declarar e alocar ponteiros com as palavras-chave `__ptr32` e `__ptr64`.  
  
```  
#include <cstdlib>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
  
    int * __ptr32 p32;  
    int * __ptr64 p64;  
  
    p32 = (int * __ptr32)malloc(4);  
    *p32 = 32;  
    cout << *p32 << endl;  
  
    p64 = (int * __ptr64)malloc(4);  
    *p64 = 64;  
    cout << *p64 << endl;  
}  
```  
  
```Output  
32  
64  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Tipos fundamentais](../cpp/fundamental-types-cpp.md)
