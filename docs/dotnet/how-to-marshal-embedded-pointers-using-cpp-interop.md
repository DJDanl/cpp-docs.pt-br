---
title: Como realizar marshaling de ponteiros inseridos usando interop C++
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- structures [C++], marshaling embedded pointers
- interop [C++], embedded pointers
- C++ Interop, embedded pointers
- marshaling [C++], embedded pointers
- pointers [C++], marshaling
- data marshaling [C++], embedded pointers
ms.assetid: 05fb8858-97f2-47aa-86b2-2c0ad713bdb2
ms.openlocfilehash: 972d7a9c09100c35cb0bf527efbd0884c909c46d
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988179"
---
# <a name="how-to-marshal-embedded-pointers-using-c-interop"></a>Como realizar marshaling de ponteiros inseridos usando interop C++

Os exemplos de código a seguir usam as diretivas de #pragma [gerenciadas e não gerenciadas](../preprocessor/managed-unmanaged.md) para implementar funções gerenciadas e não gerenciadas no mesmo arquivo, mas essas funções interoperam da mesma maneira, se definidas em arquivos separados. Os arquivos que contêm apenas funções não gerenciadas não precisam ser compilados com [/CLR (compilação em tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como uma função não gerenciada que usa uma estrutura que contém ponteiros pode ser chamada de uma função gerenciada. A função gerenciada cria uma instância da estrutura e inicializa o ponteiro inserido com a nova palavra-chave (em vez da palavra-chave [ref New, gcnew](../extensions/ref-new-gcnew-cpp-component-extensions.md) ). Como isso aloca a memória no heap nativo, não é necessário fixar a matriz para suprimir a coleta de lixo. No entanto, a memória deve ser excluída explicitamente para evitar o vazamento de memória.

```cpp
// marshal_embedded_pointer.cpp
// compile with: /clr
#include <iostream>

using namespace System;
using namespace System::Runtime::InteropServices;

// unmanaged struct
struct ListStruct {
   int count;
   double* item;
};

#pragma unmanaged

void UnmanagedTakesListStruct(ListStruct list) {
   printf_s("[unmanaged] count = %d\n", list.count);
   for (int i=0; i<list.count; i++)
      printf_s("array[%d] = %f\n", i, list.item[i]);
}

#pragma managed

int main() {
   ListStruct list;
   list.count = 10;
   list.item = new double[list.count];

   Console::WriteLine("[managed] count = {0}", list.count);
   Random^ r = gcnew Random(0);
   for (int i=0; i<list.count; i++) {
      list.item[i] = r->NextDouble() * 100.0;
      Console::WriteLine("array[{0}] = {1}", i, list.item[i]);
   }

   UnmanagedTakesListStruct( list );
   delete list.item;
}
```

```Output
[managed] count = 10
array[0] = 72.624326996796
array[1] = 81.7325359590969
array[2] = 76.8022689394663
array[3] = 55.8161191436537
array[4] = 20.6033154021033
array[5] = 55.8884794618415
array[6] = 90.6027066011926
array[7] = 44.2177873310716
array[8] = 97.754975314138
array[9] = 27.370445768987
[unmanaged] count = 10
array[0] = 72.624327
array[1] = 81.732536
array[2] = 76.802269
array[3] = 55.816119
array[4] = 20.603315
array[5] = 55.888479
array[6] = 90.602707
array[7] = 44.217787
array[8] = 97.754975
array[9] = 27.370446
```

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
