---
title: Compilador (nível 1) de aviso C4905 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4905
dev_langs:
- C++
helpviewer_keywords:
- C4905
ms.assetid: 40240bf4-b14e-4c22-aeb2-52f2851532f6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b70206bed88ab24d094171acca471f2461c17089
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33290297"
---
# <a name="compiler-warning-level-1-c4905"></a>Compilador C4905 de aviso (nível 1)
literal amplo de cadeia de caracteres convertido em 'LPSTR'  
  
 O compilador detectou uma conversão não segura. A conversão foi bem-sucedida, mas você deve usar uma rotina de conversão.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4905.  
  
```  
// C4905.cpp  
// compile with: /W1  
#pragma warning(default : 4905)  
#include <windows.h>  
#include <stdlib.h>  
#include <stdio.h>  
  
int main()  
{  
    LPSTR y = (LPSTR)L"1234";   // C4905  
  
    // try the following lines instead  
    // wchar_t y[128];  
    // size_t  sizeOfConverted;  
    // errcode err = 0;  
    //  
    // err = mbstowcs_s(&sizeOfConverted, &y[0], 128, "12345", 4);  
    // if (err != 0)  
    // {  
    //     printf_s("mbstowcs_s failed!");  
    //     exit (-1);  
    // }  
    // wprintf(L"%s\n", y);  
  
    return 0;  
}  
```