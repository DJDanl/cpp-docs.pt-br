---
title: 'Como: Cadeias de caracteres COM marshaling usando Interop do C++'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- interop [C++], strings
- marshaling [C++], strings
- C++ Interop, strings
- data marshaling [C++], strings
- COM [C++], marshaling strings
ms.assetid: 06590759-bf99-4e34-a3a9-4527ea592cc2
ms.openlocfilehash: e86cf0b3e57eda9a0f4fa5fe2337d0c42de5669f
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58780867"
---
# <a name="how-to-marshal-com-strings-using-c-interop"></a>Como: Cadeias de caracteres COM marshaling usando Interop do C++

Este tópico demonstra como um BSTR (o formato de cadeia de caracteres básicas preferido na programação COM) pode ser passados do gerenciado para uma função não gerenciada e vice-versa. Para interoperar com outros tipos de cadeias de caracteres, consulte os tópicos a seguir:

- [Como: realizar marshaling de cadeias de caracteres Unicode usando a interop do C++](../dotnet/how-to-marshal-unicode-strings-using-cpp-interop.md)

- [Como: realizar marshaling de cadeias de caracteres ANSI usando a interop do C++](../dotnet/how-to-marshal-ansi-strings-using-cpp-interop.md)

O código a seguir exemplos de uso de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) #pragma diretivas para implementar gerenciados e funções no mesmo arquivo, mas essas funções interoperam da mesma maneira, se definida em arquivos separados. Arquivos que contêm apenas as funções não gerenciadas não precisa ser compilado com [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como um BSTR (um formato de cadeia de caracteres usado na programação COM) pode ser passado de gerenciado para uma função não gerenciada. Chamada gerenciada a função usará <xref:System.Runtime.InteropServices.Marshal.StringToBSTR%2A> para obter o endereço de uma representação do BSTR do conteúdo de um System. String do .NET. Esse ponteiro é fixado usando [pin_ptr (C++/CLI)](../extensions/pin-ptr-cpp-cli.md) para garantir que seu endereço físico não é alterado durante um ciclo de coleta de lixo enquanto executa a função não gerenciada. O coletor de lixo é proibido da mudança de memória até que o [pin_ptr (C++/CLI)](../extensions/pin-ptr-cpp-cli.md) sai do escopo.

```
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

O exemplo a seguir demonstra como um BSTR pode ser passado de um não gerenciado para uma função não gerenciada. O recebimento de função gerenciada pode usar a cadeia de caracteres no como um BSTR ou usar <xref:System.Runtime.InteropServices.Marshal.PtrToStringBSTR%2A> convertê-lo para um <xref:System.String> para uso com as outras funções gerenciadas. Como a memória que representa o BSTR é alocada no heap não gerenciado, nenhuma fixação é necessária, porque não há nenhuma coleta de lixo no heap não gerenciada.

```
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
