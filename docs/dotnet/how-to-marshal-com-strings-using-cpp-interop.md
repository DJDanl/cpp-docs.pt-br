---
title: Como realizar marshaling de cadeias de caracteres COM usando interop C++
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- interop [C++], strings
- marshaling [C++], strings
- C++ Interop, strings
- data marshaling [C++], strings
- COM [C++], marshaling strings
ms.assetid: 06590759-bf99-4e34-a3a9-4527ea592cc2
ms.openlocfilehash: 8dfdad892261d5ae2d3494734458e1447f8ebd7c
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988459"
---
# <a name="how-to-marshal-com-strings-using-c-interop"></a>Como realizar marshaling de cadeias de caracteres COM usando interop C++

Este tópico demonstra como um BSTR (o formato de cadeia de caracteres básico preferir na programação COM) pode ser passado de um gerenciado para uma função não gerenciada e vice-versa. Para interoperar com outros tipos de cadeias de caracteres, consulte os seguintes tópicos:

- [Como realizar marshaling de cadeias de caracteres Unicode usando interop do C++](../dotnet/how-to-marshal-unicode-strings-using-cpp-interop.md)

- [Como realizar marshaling de cadeias de caracteres ANSI usando interop do C++](../dotnet/how-to-marshal-ansi-strings-using-cpp-interop.md)

Os exemplos de código a seguir usam as diretivas de #pragma [gerenciadas e não gerenciadas](../preprocessor/managed-unmanaged.md) para implementar funções gerenciadas e não gerenciadas no mesmo arquivo, mas essas funções interoperam da mesma maneira, se definidas em arquivos separados. Os arquivos que contêm apenas funções não gerenciadas não precisam ser compilados com [/CLR (compilação em tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como um BSTR (um formato de cadeia de caracteres usado em programação COM) pode ser passado de um gerenciado para uma função não gerenciada. A função gerenciada de chamada usa <xref:System.Runtime.InteropServices.Marshal.StringToBSTR%2A> para obter o endereço de uma representação BSTR do conteúdo de um System. String do .NET. Esse ponteiro é fixado usando [pin_ptr (C++/CLI)](../extensions/pin-ptr-cpp-cli.md) para garantir que seu endereço físico não seja alterado durante um ciclo de coleta de lixo enquanto a função não gerenciada é executada. O coletor de lixo é proibido de mover a memória até que a [pin_ptr (C++/CLI)](../extensions/pin-ptr-cpp-cli.md) saia do escopo.

```cpp
// MarshalBSTR1.cpp
// compile with: /clr
#define WINVER 0x0502
#define _AFXDLL
#include <afxwin.h>

#include <iostream>
using namespace std;

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged

void NativeTakesAString(BSTR bstr) {
   printf_s("%S", bstr);
}

#pragma managed

int main() {
   String^ s = "test string";

   IntPtr ip = Marshal::StringToBSTR(s);
   BSTR bs = static_cast<BSTR>(ip.ToPointer());
   pin_ptr<BSTR> b = &bs;

   NativeTakesAString( bs );
   Marshal::FreeBSTR(ip);
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como um BSTR pode ser passado de um não gerenciado para uma função não gerenciada. A função gerenciada de recebimento pode usar a cadeia de caracteres em como um BSTR ou usar <xref:System.Runtime.InteropServices.Marshal.PtrToStringBSTR%2A> para convertê-la em um <xref:System.String> para uso com outras funções gerenciadas. Como a memória que representa o BSTR é alocada no heap não gerenciado, nenhuma fixação é necessária, porque não há nenhuma coleta de lixo no heap não gerenciado.

```cpp
// MarshalBSTR2.cpp
// compile with: /clr
#define WINVER 0x0502
#define _AFXDLL
#include <afxwin.h>

#include <iostream>
using namespace std;

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma managed

void ManagedTakesAString(BSTR bstr) {
   String^ s = Marshal::PtrToStringBSTR(static_cast<IntPtr>(bstr));
   Console::WriteLine("(managed) convered BSTR to String: '{0}'", s);
}

#pragma unmanaged

void UnManagedFunc() {
   BSTR bs = SysAllocString(L"test string");
   printf_s("(unmanaged) passing BSTR to managed func...\n");
   ManagedTakesAString(bs);
}

#pragma managed

int main() {
   UnManagedFunc();
}
```

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
