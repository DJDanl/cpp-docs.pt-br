---
title: Como realizar marshaling de retornos de chamadas e delegados usando o C++ Interop
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
ms.openlocfilehash: b72b99798a2c719f1ba919478132c7133fd71ca1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50615716"
---
# <a name="how-to-marshal-callbacks-and-delegates-by-using-c-interop"></a>Como realizar marshaling de retornos de chamadas e delegados usando o C++ Interop

Este tópico demonstra a realização de marshaling de retornos de chamada e delega (a versão gerenciada de um retorno de chamada) entre códigos gerenciados e não gerenciados usando o Visual C++.

O código a seguir exemplos de uso de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) #pragma diretivas para implementar gerenciados e funções no mesmo arquivo, mas as funções também pode ser definidas em arquivos separados. Arquivos que contêm apenas as funções não gerenciadas não precisa ser compilado com o [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar uma API não gerenciada para disparar um representante gerenciado. Um representante gerenciado é criado e um dos métodos a interoperabilidade, <xref:System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate%2A>, é usado para recuperar o ponto de entrada subjacente para o delegado. Esse endereço é então passado para a função não gerenciada, o que faz a chamada sem o conhecimento do fato de que ele é implementado como uma função gerenciada.

Observe que é possível, mas não necessário, para fixar o representante que usa [pin_ptr (C + + / CLI)](../windows/pin-ptr-cpp-cli.md) para impedir que ela seja localizado novamente ou descartado pelo coletor de lixo. Proteção da coleta de lixo prematura é necessária, mas a fixação oferece mais proteção do que é necessário, pois ele impede a coleta, mas também previne a realocação.

Se um delegado novamente está localizado, uma coleta de lixo, ele não afetará o retorno de chamada subjacentes gerenciados, então, <xref:System.Runtime.InteropServices.GCHandle.Alloc%2A> é usado para adicionar uma referência ao delegado, permitindo que a realocação do delegado, mas impedindo o descarte. O uso de GCHandle em vez de pin_ptr reduz o potencial de fragmentação do heap gerenciado.

```
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

O exemplo a seguir é semelhante ao exemplo anterior, mas nesse caso, o ponteiro de função fornecida é armazenado por API não gerenciada, para que ele pode ser chamado a qualquer momento, exigindo que a coleta de lixo ser suprimidos durante um período arbitrário. Como resultado, o exemplo a seguir usa uma instância global do <xref:System.Runtime.InteropServices.GCHandle> para impedir que o delegado que estão sendo realocados, independentemente do escopo da função. Conforme discutido no primeiro exemplo, usando pin_ptr é desnecessário para esses exemplos, mas nesse caso, não funcionariam de qualquer forma, o escopo de um pin_ptr é limitado a uma única função.

```
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