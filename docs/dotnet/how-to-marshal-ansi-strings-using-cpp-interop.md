---
title: 'Como: cadeias de caracteres ANSI marshaling usando Interop do C++ | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- interop [C++], strings
- ANSI [C++], marshaling strings
- marshaling [C++], strings
- C++ Interop, strings
- data marshaling [C++], strings
ms.assetid: 5eda2eb6-5140-40f0-82cf-7ce171fffb45
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: d4a1a0cd8b9da5812e404f70dc999dfaf1606666
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46383357"
---
# <a name="how-to-marshal-ansi-strings-using-c-interop"></a>Como realizar marshaling de cadeias de caracteres ANSI usando interop C++

Este tópico demonstra como cadeias de caracteres ANSI podem ser passados usando Interop do C++, mas o .NET Framework <xref:System.String> representa cadeias de caracteres no formato Unicode, portanto, a conversão em ANSI é uma etapa extra. Para interoperar com outros tipos de cadeia de caracteres, consulte os tópicos a seguir:

- [Como realizar marshaling de cadeias de caracteres Unicode usando interop do C++](../dotnet/how-to-marshal-unicode-strings-using-cpp-interop.md)

- [Como realizar marshaling de cadeias de caracteres COM usando interop do C++](../dotnet/how-to-marshal-com-strings-using-cpp-interop.md)

O código a seguir exemplos de uso de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) #pragma diretivas para implementar gerenciados e funções no mesmo arquivo, mas essas funções interoperam da mesma maneira, se definida em arquivos separados. Porque arquivos que contêm apenas as funções não gerenciadas não precisam ser compilados com [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md), eles podem manter suas características de desempenho.

## <a name="example"></a>Exemplo

O exemplo demonstra passando uma cadeia de caracteres ANSI de gerenciado para uma função não gerenciada usando <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalAnsi%2A>. Esse método aloca memória no heap não gerenciada e retorna o endereço depois de executar a conversão. Isso significa que não é necessária nenhuma fixação (porque a memória no heap de GC não está sendo passada para a função não gerenciada) e que o IntPtr retornado do <xref:System.Runtime.InteropServices.Marshal.StringToHGlobalAnsi%2A> deverá ser explicitamente liberados ou uma memória vazar os resultados.

```
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

O exemplo a seguir demonstra o marshaling de dados necessárias para acessar uma cadeia de caracteres ANSI em uma função gerenciada que é chamada por uma função não gerenciada. A função gerenciada, durante o recebimento de uma cadeia de caracteres nativa, pode usá-lo diretamente ou convertê-lo em uma cadeia de caracteres gerenciada usando o <xref:System.Runtime.InteropServices.Marshal.PtrToStringAnsi%2A> método, conforme mostrado.

```
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