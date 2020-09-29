---
title: Como realizar marshaling de cadeias de caracteres Unicode usando interop C++
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- interop [C++], strings
- marshaling [C++], strings
- C++ Interop, strings
- data marshaling [C++], strings
- Unicode, marshaling strings
ms.assetid: 96c2141d-6c5d-43ef-a1aa-5785afb9a9aa
ms.openlocfilehash: da320dbd41e7158e3bc2482b96a73c1f4728a01b
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91414302"
---
# <a name="how-to-marshal-unicode-strings-using-c-interop"></a>Como realizar marshaling de cadeias de caracteres Unicode usando interop C++

Este tópico demonstra uma faceta da interoperabilidade do Visual C++. Para obter mais informações, consulte [usando a interoperabilidade C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md).

Os exemplos de código a seguir usam as diretivas de #pragma [gerenciadas e não gerenciadas](../preprocessor/managed-unmanaged.md) para implementar funções gerenciadas e não gerenciadas no mesmo arquivo, mas essas funções interoperam da mesma maneira, se definidas em arquivos separados. Os arquivos que contêm apenas funções não gerenciadas não precisam ser compilados com [/CLR (compilação em tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md).

Este tópico demonstra como cadeias de caracteres Unicode podem ser passadas de um gerenciado para uma função não gerenciada e vice-versa. Para interoperar com outros tipos de cadeias de caracteres, consulte os seguintes tópicos:

- [Como realizar marshaling de cadeias de caracteres ANSI usando a interoperabilidade C++](../dotnet/how-to-marshal-ansi-strings-using-cpp-interop.md)

- [Como realizar marshaling de cadeias de caracteres COM usando interoperabilidade C++](../dotnet/how-to-marshal-com-strings-using-cpp-interop.md)

## <a name="example-pass-unicode-string-from-managed-to-unmanaged-function"></a>Exemplo: passar cadeia de caracteres Unicode de gerenciado para função não gerenciada

Para passar uma cadeia de caracteres Unicode de um gerenciado para uma função não gerenciada, a função PtrToStringChars (declarada em Vcclr. h) pode ser usada para acessar na memória onde a cadeia de caracteres gerenciada está armazenada. Como esse endereço será passado para uma função nativa, é importante que a memória seja fixada com [pin_ptr (C++/CLI)](../extensions/pin-ptr-cpp-cli.md) para impedir que os dados da cadeia de caracteres sejam realocados, caso um ciclo de coleta de lixo ocorra enquanto a função não gerenciada é executada.

```cpp
// MarshalUnicode1.cpp
// compile with: /clr
#include <iostream>
#include <stdio.h>
#include <vcclr.h>

using namespace std;

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged

void NativeTakesAString(const wchar_t* p) {
   printf_s("(native) received '%S'\n", p);
}

#pragma managed

int main() {
   String^ s = gcnew String("test string");
   pin_ptr<const wchar_t> str = PtrToStringChars(s);

   Console::WriteLine("(managed) passing string to native func...");
   NativeTakesAString( str );
}
```

## <a name="example-data-marshaling-required-to-access-unicode-string"></a>Exemplo: marshaling de dados necessário para acessar a cadeia de caracteres Unicode

O exemplo a seguir demonstra o marshaling de dados necessário para acessar uma cadeia de caracteres Unicode em uma função gerenciada chamada por uma função não gerenciada. A função gerenciada, ao receber a cadeia de caracteres Unicode nativa, converte-a em uma cadeia de caracteres gerenciada usando o <xref:System.Runtime.InteropServices.Marshal.PtrToStringUni%2A> método.

```cpp
// MarshalUnicode2.cpp
// compile with: /clr
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices;

#pragma managed

void ManagedStringFunc(wchar_t* s) {
   String^ ms = Marshal::PtrToStringUni((IntPtr)s);
   Console::WriteLine("(managed) received '{0}'", ms);
}

#pragma unmanaged

void NativeProvidesAString() {
   cout << "(unmanaged) calling managed func...\n";
   ManagedStringFunc(L"test string");
}

#pragma managed

int main() {
   NativeProvidesAString();
}
```

## <a name="see-also"></a>Confira também

[Usando a interoperabilidade C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
