---
title: Como realizar marshal de retornos de chamadas e delegados usando o C++ Interop
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- data marshaling [C++], callbacks and delegates
- C++ Interop, callbacks and delegates
- interop [C++], callbacks and delegates
- delegates [C++], marshaling
- marshaling [C++], callbacks and delegates
- callbacks [C++], marshaling
ms.assetid: 2313e9eb-5df9-4367-be0f-14b4712d8d2d
ms.openlocfilehash: 592eae0ff59baddb79b810d46669b78ecc801155
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988190"
---
# <a name="how-to-marshal-callbacks-and-delegates-by-using-c-interop"></a>Como realizar marshal de retornos de chamadas e delegados usando o C++ Interop

Este tópico demonstra o marshaling de retornos de chamada e delegados (a versão gerenciada de um retorno de chamada) entre códigos gerenciados C++e não gerenciados usando o Visual.

Os exemplos de código a seguir usam as diretivas de #pragma [gerenciadas e não gerenciadas](../preprocessor/managed-unmanaged.md) para implementar funções gerenciadas e não gerenciadas no mesmo arquivo, mas as funções também podem ser definidas em arquivos separados. Os arquivos que contêm apenas funções não gerenciadas não precisam ser compilados com a [compilação/CLR (Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar uma API não gerenciada para disparar um delegado gerenciado. Um delegado gerenciado é criado e um dos métodos de interoperabilidade, <xref:System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate%2A>, é usado para recuperar o ponto de entrada subjacente para o delegado. Esse endereço é passado para a função não gerenciada, que o chama sem conhecimento do fato de que ele é implementado como uma função gerenciada.

Observe que é possível, mas não necessário, fixar o delegado usando [pin_ptr (C++/CLI)](../extensions/pin-ptr-cpp-cli.md) para impedir que ele seja realocado ou Descartado pelo coletor de lixo. A proteção da coleta de lixo prematura é necessária, mas a fixação fornece mais proteção do que o necessário, pois impede a coleta, mas também impede a relocação.

Se um delegado for realocado por uma coleta de lixo, ele não afetará o retorno de chamada gerenciado de subposição, portanto <xref:System.Runtime.InteropServices.GCHandle.Alloc%2A> será usado para adicionar uma referência ao delegado, permitindo a realocação do delegado, mas impedindo a alienação. O uso de GCHandle em vez de pin_ptr reduz o potencial de fragmentação do heap gerenciado.

```cpp
// MarshalDelegate1.cpp
// compile with: /clr
#include <iostream>

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged

// Declare an unmanaged function type that takes two int arguments
// Note the use of __stdcall for compatibility with managed code
typedef int (__stdcall *ANSWERCB)(int, int);

int TakesCallback(ANSWERCB fp, int n, int m) {
   printf_s("[unmanaged] got callback address, calling it...\n");
   return fp(n, m);
}

#pragma managed

public delegate int GetTheAnswerDelegate(int, int);

int GetNumber(int n, int m) {
   Console::WriteLine("[managed] callback!");
   return n + m;
}

int main() {
   GetTheAnswerDelegate^ fp = gcnew GetTheAnswerDelegate(GetNumber);
   GCHandle gch = GCHandle::Alloc(fp);
   IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
   ANSWERCB cb = static_cast<ANSWERCB>(ip.ToPointer());
   Console::WriteLine("[managed] sending delegate as callback...");

// force garbage collection cycle to prove
// that the delegate doesn't get disposed
   GC::Collect();

   int answer = TakesCallback(cb, 243, 257);

// release reference to delegate
   gch.Free();
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir é semelhante ao exemplo anterior, mas, nesse caso, o ponteiro de função fornecido é armazenado pela API não gerenciada, portanto, ele pode ser invocado a qualquer momento, exigindo que a coleta de lixo seja suprimida por um período de tempo arbitrário. Como resultado, o exemplo a seguir usa uma instância global do <xref:System.Runtime.InteropServices.GCHandle> para impedir que o delegado seja realocado, independentemente do escopo da função. Conforme discutido no primeiro exemplo, o uso de pin_ptr é desnecessário para esses exemplos, mas nesse caso não funcionaria mesmo assim, pois o escopo de uma pin_ptr é limitado a uma única função.

```cpp
// MarshalDelegate2.cpp
// compile with: /clr
#include <iostream>

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged

// Declare an unmanaged function type that takes two int arguments
// Note the use of __stdcall for compatibility with managed code
typedef int (__stdcall *ANSWERCB)(int, int);
static ANSWERCB cb;

int TakesCallback(ANSWERCB fp, int n, int m) {
   cb = fp;
   if (cb) {
      printf_s("[unmanaged] got callback address (%d), calling it...\n", cb);
      return cb(n, m);
   }
   printf_s("[unmanaged] unregistering callback");
   return 0;
}

#pragma managed

public delegate int GetTheAnswerDelegate(int, int);

int GetNumber(int n, int m) {
   Console::WriteLine("[managed] callback!");
   static int x = 0;
   ++x;

   return n + m + x;
}

static GCHandle gch;

int main() {
   GetTheAnswerDelegate^ fp = gcnew GetTheAnswerDelegate(GetNumber);

   gch = GCHandle::Alloc(fp);

   IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
   ANSWERCB cb = static_cast<ANSWERCB>(ip.ToPointer());
   Console::WriteLine("[managed] sending delegate as callback...");

   int answer = TakesCallback(cb, 243, 257);

   // possibly much later (in another function)...

   Console::WriteLine("[managed] releasing callback mechanisms...");
   TakesCallback(0, 243, 257);
   gch.Free();
}
```

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
