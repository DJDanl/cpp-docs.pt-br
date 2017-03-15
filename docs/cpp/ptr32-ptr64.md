---
title: "__ptr32, __ptr64 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__ptr32_cpp"
  - "__ptr64_cpp"
  - "__ptr32"
  - "__ptr64"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __ptr32 [C++]"
  - "Palavra-chave __ptr64 [C++]"
  - "Palavra-chave _ptr32 [C++]"
  - "Palavra-chave _ptr64 [C++]"
  - "Palavra-chave ptr32 [C++]"
  - "Palavra-chave ptr64 [C++]"
ms.assetid: afb563d8-7458-4fe7-9c30-bd4b5385a59f
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __ptr32, __ptr64
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 `__ptr32` representa um ponteiro nativo em um sistema de 32 bits, enquanto `__ptr64` representa um ponteiro nativo em um sistema de 64 bits.  
  
 O exemplo a seguir mostra como declarar cada um desses tipos de ponteiro:  
  
```  
int * __ptr32 p32;  
int * __ptr64 p64;  
```  
  
 Em um sistema de 32 bits, um ponteiro declarado com `__ptr64` é truncado em um ponteiro de 32 bits.  Em um sistema de 64 bits, um ponteiro declarado com `__ptr32` é imposto a um ponteiro de 64 bits.  
  
> [!NOTE]
>  Não é possível usar `__ptr32` ou `__ptr64` durante a compilação com **\/clr:pure**.  Caso contrário, o `Compiler Error C2472` será gerado.  
  
## Exemplo  
 O exemplo a seguir mostra como declarar e alocar ponteiros com as palavras\-chave `__ptr32` e `__ptr64`.  
  
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
  
  **32**  
**64**   
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Tipos fundamentais](../cpp/fundamental-types-cpp.md)