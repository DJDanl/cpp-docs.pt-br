---
title: Inicializando classes e structs sem construtores (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 3e55c3d6-1c6b-4084-b9e5-221b151402f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bca7ef417a633f186f2b7ca6f7d92af37e780420
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39409331"
---
# <a name="initializing-classes-and-structs-without-constructors-c"></a>Inicializando classes e structs sem construtores (C++)
Nem sempre é necessário definir um construtor para uma classe, especialmente aqueles que são relativamente simples. Os usuários podem inicializar objetos de uma classe ou struct usando inicialização uniforme, conforme mostrado no exemplo a seguir:  
  
```cpp 
#include "stdafx.h"  
#include <Windows.h>  
  
// No constructor  
struct TempData  
{  
    int StationId;  
    time_t time;  
    double current;  
    double maxTemp;  
    double minTemp;  
};  
  
// Has a constructor  
struct TempData2  
{  
    TempData2(double minimum, double maximum, double cur, int id, time_t t) :  
       minTemp(minimum), maxTemp(maximum), current(cur), stationId(id), time(t) {}  
    int stationId;  
    time_t time;  
    double current;  
    double maxTemp;  
    double minTemp;  
};  
  
int main()  
{  
    // Member initialization (in order of declaration):  
    TempData td{ 45978, GetCurrentTime(), 28.9, 37.0, 16.7 };  
  
    // Default initialization = {0,0,0,0,0}  
    TempData td_default{};  
  
    //Error C4700 uninitialized local variable  
    TempData td_noInit;  
  
    // Member declaration (in order of ctor parameters)  
    TempData2 td2{ 16.7, 37.0, 28.9, 45978, GetCurrentTime() };  
  
    return 0;  
}  
```  
  
 Observe que, quando uma classe ou struct não tem nenhum construtor, você fornece os elementos da lista na ordem em que os membros são declarados na classe. Se a classe tiver um construtor, que fornecem os elementos na ordem dos parâmetros.  
  
## <a name="see-also"></a>Consulte também  
 [Classes e structs](../cpp/classes-and-structs-cpp.md)   
 [Construtores](../cpp/constructors-cpp.md)