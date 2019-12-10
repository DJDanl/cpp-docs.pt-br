---
title: Como realizar marshaling de cadeias de caracteres ANSI usando interop C++
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- interop [C++], strings
- ANSI [C++], marshaling strings
- marshaling [C++], strings
- C++ Interop, strings
- data marshaling [C++], strings
ms.assetid: 5eda2eb6-5140-40f0-82cf-7ce171fffb45
ms.openlocfilehash: 6987b23311354cfe6fd095e0e811d043e9b9692e
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988469"
---
# <a name="how-to-marshal-ansi-strings-using-c-interop"></a>Como realizar marshaling de cadeias de caracteres ANSI usando interop C++

Este tópico demonstra como cadeias de caracteres ANSI podem C++ ser passadas usando a interoperabilidade, mas a .NET Framework <xref:System.String> representa cadeias de caracteres no formato Unicode; portanto, a conversão para ANSI é uma etapa extra. Para interoperar com outros tipos de cadeia de caracteres, consulte os seguintes tópicos:

- [Como realizar marshaling de cadeias de caracteres Unicode usando interop do C++](../dotnet/how-to-marshal-unicode-strings-using-cpp-interop.md)

- [Como realizar marshaling de cadeias de caracteres COM usando interop do C++](../dotnet/how-to-marshal-com-strings-using-cpp-interop.md)

Os exemplos de código a seguir usam as diretivas de #pragma [gerenciadas e não gerenciadas](../preprocessor/managed-unmanaged.md) para implementar funções gerenciadas e não gerenciadas no mesmo arquivo, mas essas funções interoperam da mesma maneira, se definidas em arquivos separados. Como os arquivos que contêm apenas funções não gerenciadas não precisam ser compilados com [/CLR (compilação de Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md), eles podem manter suas características de desempenho.

## <a name="example"></a>Exemplo

O exemplo demonstra a passagem de uma cadeia de caracteres ANSI de um gerenciado para uma função não gerenciada usando <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalAnsi%2A>. Esse método aloca memória no heap não gerenciado e retorna o endereço após a execução da conversão. Isso significa que nenhuma fixação é necessária (porque a memória no heap de GC não está sendo passada para a função não gerenciada) e que o IntPtr retornado de <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalAnsi%2A> deve ser liberado explicitamente ou ter resultados de perda de memória.

```cpp
// MarshalANSI1.cpp
// compile with: /clr
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged

void NativeTakesAString(const char* p) {
   printf_s("(native) received '%s'\n", p);
}

#pragma managed

int main() {
   String^ s = gcnew String("sample string");
   IntPtr ip = Marshal::StringToHGlobalAnsi(s);
   const char* str = static_cast<const char*>(ip.ToPointer());

   Console::WriteLine("(managed) passing string...");
   NativeTakesAString( str );

   Marshal::FreeHGlobal( ip );
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra o marshaling de dados necessário para acessar uma cadeia de caracteres ANSI em uma função gerenciada que é chamada por uma função não gerenciada. A função gerenciada, ao receber a cadeia de caracteres nativa, pode usá-la diretamente ou convertê-la em uma cadeia de caracteres gerenciada usando o método <xref:System.Runtime.InteropServices.Marshal.PtrToStringAnsi%2A>, conforme mostrado.

```cpp
// MarshalANSI2.cpp
// compile with: /clr
#include <iostream>
#include <vcclr.h>

using namespace std;

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma managed

void ManagedStringFunc(char* s) {
   String^ ms = Marshal::PtrToStringAnsi(static_cast<IntPtr>(s));
   Console::WriteLine("(managed): received '{0}'", ms);
}

#pragma unmanaged

void NativeProvidesAString() {
   cout << "(native) calling managed func...\n";
   ManagedStringFunc("test string");
}

#pragma managed

int main() {
   NativeProvidesAString();
}
```

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
