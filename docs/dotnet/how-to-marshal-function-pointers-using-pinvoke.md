---
title: 'Como: Marshaling de ponteiros de função usando PInvoke'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- data marshaling [C++], callbacks and delegates
- interop [C++], callbacks and delegates
- platform invoke [C++], callbacks and delegates
- marshaling [C++], callbacks and delegates
ms.assetid: dcf396fd-a91d-49c0-ab0b-1ea160668a89
ms.openlocfilehash: 031bda0f93d6a95aa3c774553aefca0647d0518c
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57742871"
---
# <a name="how-to-marshal-function-pointers-using-pinvoke"></a>Como: Marshaling de ponteiros de função usando PInvoke

Este tópico explica os delegados como gerenciados pode ser usado no lugar de ponteiros de função a interoperação com não gerenciado usando P/Invoke do .NET Framework recursos de funções. No entanto, os programadores de Visual C++ são incentivados a usar os recursos de interoperabilidade C++ em vez disso (quando possível) como P/Invoke oferece pouco tempo de compilação relatório de erro, não é fortemente tipado e pode ser enfadonho implementar. Se a API não gerenciada é empacotada como uma DLL e o código-fonte não estiver disponível, o P/Invoke é a única opção. Caso contrário, consulte os tópicos a seguir:

- [Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)

- [Como: realizar marshaling de retornos de chamada e delegados usando a interop do C++](../dotnet/how-to-marshal-callbacks-and-delegates-by-using-cpp-interop.md)

APIs não gerenciadas que usam ponteiros de funções como argumentos podem ser chamados no código gerenciado com um representante gerenciado no lugar do ponteiro de função nativo. O compilador automaticamente realiza marshaling o delegado para funções não gerenciadas como um ponteiro de função e insere o código necessário transição gerenciado /.

## <a name="example"></a>Exemplo

O código a seguir consiste em uma não gerenciado e um módulo gerenciado. O módulo não gerenciado é uma DLL que define uma função chamada TakesCallback que aceita um ponteiro de função. Esse endereço é usado para executar a função.

O módulo gerenciado define um delegado que tem o marshaling realizado para o código nativo como um ponteiro de função e usa o <xref:System.Runtime.InteropServices.DllImportAttribute> atributo para expor a função TakesCallback nativa ao código gerenciado. Na função principal, uma instância do delegado é criada e passada para a função TakesCallback. A saída do programa demonstra que essa função seja executada pela função TakesCallback nativa.

A função gerenciada suprime a coleta de lixo para o delegado gerenciado evitar a coleta de lixo do .NET Framework da realocando o delegado enquanto executa a função nativa.

```cpp
// TraditionalDll5.cpp
// compile with: /LD /EHsc
#include <iostream>
#define TRADITIONALDLL_EXPORTS
#ifdef TRADITIONALDLL_EXPORTS
#define TRADITIONALDLL_API __declspec(dllexport)
#else
#define TRADITIONALDLL_API __declspec(dllimport)
#endif

extern "C" {
   /* Declare an unmanaged function type that takes two int arguments
      Note the use of __stdcall for compatibility with managed code */
   typedef int (__stdcall *CALLBACK)(int);
   TRADITIONALDLL_API int TakesCallback(CALLBACK fp, int);
}

int TakesCallback(CALLBACK fp, int n) {
   printf_s("[unmanaged] got callback address, calling it...\n");
   return fp(n);
}
```

```cpp
// MarshalDelegate.cpp
// compile with: /clr
using namespace System;
using namespace System::Runtime::InteropServices;

public delegate int GetTheAnswerDelegate(int);
public value struct TraditionalDLL {
   [DllImport("TraditionalDLL5.dll")]
   static public int TakesCallback(GetTheAnswerDelegate^ pfn, int n);
};

int GetNumber(int n) {
   Console::WriteLine("[managed] callback!");
   static int x = 0;
   ++x;
   return x + n;
}

int main() {
   GetTheAnswerDelegate^ fp = gcnew GetTheAnswerDelegate(GetNumber);
   pin_ptr<GetTheAnswerDelegate^> pp = &fp;
   Console::WriteLine("[managed] sending delegate as callback...");

   int answer = TraditionalDLL::TakesCallback(fp, 42);
}
```

Observe que nenhuma parte da DLL é exposta ao código gerenciado usando o tradicional # diretiva include. Na verdade, a DLL é acessada no tempo de execução, para que os problemas com as funções importadas com <xref:System.Runtime.InteropServices.DllImportAttribute> não serão detectados em tempo de compilação.

## <a name="see-also"></a>Consulte também

[Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)
