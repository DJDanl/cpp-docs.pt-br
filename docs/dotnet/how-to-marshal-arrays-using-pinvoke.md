---
title: 'Como: Marshaling de matrizes usando PInvoke'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- marshaling [C++], arrays
- platform invoke [C++], arrays
- interop [C++], arrays
- data marshaling [C++], arrays
ms.assetid: a1237797-a2da-4df4-984a-6333ed3af406
ms.openlocfilehash: 60b49135928e3dadffc2a3c7a422646d2f3a768d
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57752305"
---
# <a name="how-to-marshal-arrays-using-pinvoke"></a>Como: Marshaling de matrizes usando PInvoke

Este tópico explica como nativas funções que aceitam cadeias de caracteres de estilo C podem ser chamadas usando o tipo de cadeia de caracteres CLR <xref:System.String> usando o suporte de invocação de plataforma do .NET Framework. Programadores de Visual C++ são incentivados a usar os recursos de interoperabilidade C++ em vez disso (quando possível) como P/Invoke oferece pouco tempo de compilação relatório de erro, não é fortemente tipado e pode ser enfadonho implementar. Se a API não gerenciada é empacotada como uma DLL e o código-fonte não estiver disponível, o P/Invoke é a única opção (caso contrário, consulte [usando Interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)).

## <a name="example"></a>Exemplo

Porque as matrizes nativas e gerenciadas são dispostas diferente na memória, passá-los com êxito, além do limite gerenciado/requer conversão ou marshaling. Este tópico demonstra como uma matriz de itens simples (blitable) pode ser passada para funções nativas de código gerenciado.

Assim como ocorre de marshaling de dados gerenciados/não gerenciados em geral, o <xref:System.Runtime.InteropServices.DllImportAttribute> atributo é usado para criar um ponto de entrada gerenciado para cada função nativa que será usado. No caso de funções que usam matrizes como argumentos, o <xref:System.Runtime.InteropServices.MarshalAsAttribute> atributo deve ser usado também para especificar para o compilador, como os dados serão ser empacotados. No exemplo a seguir, o <xref:System.Runtime.InteropServices.UnmanagedType> enumeração é usada para indicar que a matriz gerenciada será empacotado como uma matriz C-style.

O código a seguir consiste em uma não gerenciado e um módulo gerenciado. O módulo não gerenciado é uma DLL que define uma função que aceita uma matriz de inteiros. O segundo módulo é um aplicativo gerenciado de linha de comando que importa essa função, mas define isso em termos de uma matriz gerenciada e usa o <xref:System.Runtime.InteropServices.MarshalAsAttribute> atributo para especificar que a matriz deve ser convertida para uma matriz nativa quando chamado.

O módulo gerenciado é compilado com /clr.

```cpp
// TraditionalDll4.cpp
// compile with: /LD /EHsc
#include <iostream>

#define TRADITIONALDLL_EXPORTS
#ifdef TRADITIONALDLL_EXPORTS
#define TRADITIONALDLL_API __declspec(dllexport)
#else
#define TRADITIONALDLL_API __declspec(dllimport)
#endif

extern "C" {
   TRADITIONALDLL_API void TakesAnArray(int len, int[]);
}

void TakesAnArray(int len, int a[]) {
   printf_s("[unmanaged]\n");
   for (int i=0; i<len; i++)
      printf("%d = %d\n", i, a[i]);
}
```

```cpp
// MarshalBlitArray.cpp
// compile with: /clr
using namespace System;
using namespace System::Runtime::InteropServices;

value struct TraditionalDLL {
   [DllImport("TraditionalDLL4.dll")]
   static public void TakesAnArray(
   int len,[MarshalAs(UnmanagedType::LPArray)]array<int>^);
};

int main() {
   array<int>^ b = gcnew array<int>(3);
   b[0] = 11;
   b[1] = 33;
   b[2] = 55;
   TraditionalDLL::TakesAnArray(3, b);

   Console::WriteLine("[managed]");
   for (int i=0; i<3; i++)
      Console::WriteLine("{0} = {1}", i, b[i]);
}
```

Observe que nenhuma parte da DLL é exposta ao código gerenciado por meio do tradicional # diretiva include. Na verdade, como a DLL é acessada no tempo de execução apenas, problemas com as funções importadas com <xref:System.Runtime.InteropServices.DllImportAttribute> não serão detectados em tempo de compilação.

## <a name="see-also"></a>Consulte também

[Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)
