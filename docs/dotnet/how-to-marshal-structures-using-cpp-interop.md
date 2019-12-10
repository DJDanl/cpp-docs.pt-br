---
title: Como realizar marshaling de estruturas usando interop C++
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- C++ Interop, structures
- structures [C++], marshaling
- data marshaling [C++], structures
- interop [C++], structures
- marshaling [C++], structures
ms.assetid: c2080200-f983-4d6e-a557-cd870f060a54
ms.openlocfilehash: a77745c9a60c9759f8b3b2df91bcbc4cb507533b
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988175"
---
# <a name="how-to-marshal-structures-using-c-interop"></a>Como realizar marshaling de estruturas usando interop C++

Este tópico demonstra uma faceta da interoperabilidade Visual C++ . Para obter mais informações, [consulte C++ usando a interoperabilidade (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md).

Os exemplos de código a seguir usam as diretivas de #pragma [gerenciadas e não gerenciadas](../preprocessor/managed-unmanaged.md) para implementar funções gerenciadas e não gerenciadas no mesmo arquivo, mas essas funções interoperam da mesma maneira, se definidas em arquivos separados. Os arquivos que contêm apenas funções não gerenciadas não precisam ser compilados com [/CLR (compilação em tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra a passagem de uma estrutura de um gerenciado para uma função não gerenciada, tanto por valor quanto por referência. Como a estrutura neste exemplo contém apenas tipos de dados intrínsecos simples (consulte [tipos blittable e não blittable](/dotnet/framework/interop/blittable-and-non-blittable-types)), não é necessário realizar marshaling especial. Para realizar marshaling de estruturas que não permitem a transferência de bits, como aquelas que contêm ponteiros, consulte [como C++ realizar marshaling de ponteiros inseridos usando a interoperabilidade](../dotnet/how-to-marshal-embedded-pointers-using-cpp-interop.md).

```cpp
// PassStruct1.cpp
// compile with: /clr

#include <stdio.h>
#include <math.h>

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged

struct Location {
   int x;
   int y;
};

double GetDistance(Location loc1, Location loc2) {
   printf_s("[unmanaged] loc1(%d,%d)", loc1.x, loc1.y);
   printf_s(" loc2(%d,%d)\n", loc2.x, loc2.y);

   double h = loc1.x - loc2.x;
   double v = loc1.y = loc2.y;
   double dist = sqrt( pow(h,2) + pow(v,2) );

   return dist;
}

void InitLocation(Location* lp) {
   printf_s("[unmanaged] Initializing location...\n");
   lp->x = 50;
   lp->y = 50;
}

#pragma managed

int main() {
   Location loc1;
   loc1.x = 0;
   loc1.y = 0;

   Location loc2;
   loc2.x = 100;
   loc2.y = 100;

   double dist = GetDistance(loc1, loc2);
   Console::WriteLine("[managed] distance = {0}", dist);

   Location loc3;
   InitLocation(&loc3);
   Console::WriteLine("[managed] x={0} y={1}", loc3.x, loc3.y);
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra a passagem de uma estrutura de um não gerenciado para uma função gerenciada, tanto por valor quanto por referência. Como a estrutura neste exemplo contém apenas tipos de dados intrínsecos simples (consulte [tipos blittable e não blittable](/dotnet/framework/interop/blittable-and-non-blittable-types)), não é necessário realizar marshaling especial. Para realizar marshaling de estruturas que não permitem a transferência de bits, como aquelas que contêm ponteiros, consulte [como C++ realizar marshaling de ponteiros inseridos usando a interoperabilidade](../dotnet/how-to-marshal-embedded-pointers-using-cpp-interop.md).

```cpp
// PassStruct2.cpp
// compile with: /clr
#include <stdio.h>
#include <math.h>
using namespace System;

// native structure definition
struct Location {
   int x;
   int y;
};

#pragma managed

double GetDistance(Location loc1, Location loc2) {
   Console::Write("[managed] got loc1({0},{1})", loc1.x, loc1.y);
   Console::WriteLine(" loc2({0},{1})", loc2.x, loc2.y);

   double h = loc1.x - loc2.x;
   double v = loc1.y = loc2.y;
   double dist = sqrt( pow(h,2) + pow(v,2) );

   return dist;
}

void InitLocation(Location* lp) {
   Console::WriteLine("[managed] Initializing location...");
   lp->x = 50;
   lp->y = 50;
}

#pragma unmanaged

int UnmanagedFunc() {
   Location loc1;
   loc1.x = 0;
   loc1.y = 0;

   Location loc2;
   loc2.x = 100;
   loc2.y = 100;

   printf_s("(unmanaged) loc1=(%d,%d)", loc1.x, loc1.y);
   printf_s(" loc2=(%d,%d)\n", loc2.x, loc2.y);

   double dist = GetDistance(loc1, loc2);
   printf_s("[unmanaged] distance = %f\n", dist);

   Location loc3;
   InitLocation(&loc3);
   printf_s("[unmanaged] got x=%d y=%d\n", loc3.x, loc3.y);

    return 0;
}

#pragma managed

int main() {
   UnmanagedFunc();
}
```

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
