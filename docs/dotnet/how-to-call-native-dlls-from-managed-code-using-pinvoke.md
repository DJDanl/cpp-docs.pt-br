---
title: 'Como: Chamar DLLs nativas do código gerenciado usando PInvoke'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- platform invoke [C++], calling native DLLs
- interop [C++], calling native DLLs
- marshaling [C++], calling native DLLs
- data marshaling [C++], calling native DLLs
ms.assetid: 3273eb4b-38d1-4619-92a6-71bda542be72
ms.openlocfilehash: b36496690c4d83837a6dff1752f3f0db514869eb
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311767"
---
# <a name="how-to-call-native-dlls-from-managed-code-using-pinvoke"></a>Como: Chamar DLLs nativas do código gerenciado usando PInvoke

As funções implementadas em DLLs não gerenciadas podem ser chamadas a partir de código gerenciado usando a funcionalidade de invocação de plataforma (P/Invoke). Se o código-fonte da DLL não estiver disponível, P/Invoke será a única opção para interoperação. No entanto, ao contrário de outras C++ linguagens .net, o Visual fornece uma alternativa para P/Invoke. Para obter mais informações, [consulte C++ usando a interoperabilidade (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md).

## <a name="example"></a>Exemplo

O exemplo de código a seguir usa a função [GetSystemMetrics](/windows/win32/api/winuser/nf-winuser-getsystemmetrics) do Win32 para recuperar a resolução atual da tela em pixels.

Para funções que usam apenas tipos intrínsecos como argumentos e valores de retorno, nenhum trabalho extra é necessário. Outros tipos de dados, como ponteiros de função, matrizes e estruturas, exigem atributos adicionais para garantir o marshaling de dados adequado.

Embora não seja necessário, é recomendável fazer declarações P/Invoke membros estáticos de uma classe Value para que eles não existam no namespace global, como demonstrado neste exemplo.

```
// pinvoke_basic.cpp
// compile with: /clr
using namespace System;
using namespace System::Runtime::InteropServices;

value class Win32 {
public:
   [DllImport("User32.dll")]
   static int GetSystemMetrics(int);

   enum class SystemMetricIndex {
      // Same values as those defined in winuser.h.
      SM_CXSCREEN = 0,
      SM_CYSCREEN = 1
   };
};

int main() {
   int hRes = Win32::GetSystemMetrics( safe_cast<int>(Win32::SystemMetricIndex::SM_CXSCREEN) );
   int vRes = Win32::GetSystemMetrics( safe_cast<int>(Win32::SystemMetricIndex::SM_CYSCREEN) );
   Console::WriteLine("screen resolution: {0},{1}", hRes, vRes);
}
```

## <a name="see-also"></a>Consulte também

[Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)
