---
title: Como usar um tipo nativo na compilação a-CLR
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- compilation, native types in /clr
- /clr compiler option [C++], using native types
ms.assetid: 3a505c90-4adb-4942-9cf9-7d1fdcbc01e7
ms.openlocfilehash: 88a678a19043d3229218dd69afbf8548348817df
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90683956"
---
# <a name="how-to-use-a-native-type-in-a-clr-compilation"></a>Como usar um tipo nativo em uma compilação /clr

Você pode definir um tipo nativo em uma compilação **/CLR** e qualquer uso desse tipo nativo de dentro do assembly é válido. No entanto, os tipos nativos não estarão disponíveis para uso de metadados referenciados.

Cada assembly deve conter a definição de cada tipo nativo que será usado.

Para obter mais informações, consulte [/CLR (compilação em tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md).

## <a name="examples"></a>Exemplos

Este exemplo cria um componente que define e usa um tipo nativo.

```cpp
// use_native_type_in_clr.cpp
// compile with: /clr /LD
public struct NativeClass {
   static int Test() { return 98; }
};

public ref struct ManagedClass {
   static int i = NativeClass::Test();
   void Test() {
      System::Console::WriteLine(i);
   }
};
```

Este exemplo define um cliente que consome o componente. Observe que é um erro para acessar o tipo nativo, a menos que ele esteja definido no compiland.

```cpp
// use_native_type_in_clr_2.cpp
// compile with: /clr
#using "use_native_type_in_clr.dll"
// Uncomment the following 3 lines to resolve.
// public struct NativeClass {
//    static int Test() { return 98; }
// };

int main() {
   ManagedClass x;
   x.Test();

   System::Console::WriteLine(NativeClass::Test());   // C2653
}
```

## <a name="see-also"></a>Confira também

[Usando a interoperabilidade C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
