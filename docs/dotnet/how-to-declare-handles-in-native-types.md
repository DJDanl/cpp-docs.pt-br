---
title: Como declarar identificadores em tipos nativos
ms.custom: get-started-article
ms.date: 11/04/2016
f1_keywords:
- gcroot
helpviewer_keywords:
- handles, declaring
- gcroot keyword [C++]
- types [C++], declaring handles in
ms.assetid: b8c0eead-17e5-4003-b21f-b673f997d79f
ms.openlocfilehash: 1aca21402122a0c8641a7e57ace2a3477ff96f01
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221335"
---
# <a name="how-to-declare-handles-in-native-types"></a>Como declarar identificadores em tipos nativos

Você não pode declarar um tipo de identificador em um tipo nativo. Vcclr. h fornece o modelo de wrapper de tipo seguro `gcroot` para se referir a um objeto CLR do heap do C++. Esse modelo permite que você incorpore um identificador virtual em um tipo nativo e o trate como se fosse o tipo subjacente. Na maioria dos casos, você pode usar o `gcroot` objeto como o tipo inserido sem qualquer conversão. No entanto, com [for each, no](../dotnet/for-each-in.md), você precisa usar **`static_cast`** para recuperar a referência gerenciada subjacente.

O `gcroot` modelo é implementado usando os recursos da classe de valor System:: Runtime:: InteropServices:: GCHandle, que fornece "Handles" para o heap coletado por lixo. Observe que os próprios identificadores não são coletados pelo lixo e são liberados quando não são mais usados pelo destruidor na `gcroot` classe (esse destruidor não pode ser chamado manualmente). Se você criar uma instância de um `gcroot` objeto no heap nativo, deverá chamar Delete nesse recurso.

O tempo de execução manterá uma associação entre o identificador e o objeto CLR, ao qual ele faz referência. Quando o objeto CLR for movido com o heap coletado por lixo, o identificador retornará o novo endereço do objeto. Uma variável não precisa ser fixada antes de ser atribuída a um `gcroot` modelo.

## <a name="example"></a>Exemplo

Este exemplo mostra como criar um `gcroot` objeto na pilha nativa.

```cpp
// mcpp_gcroot.cpp
// compile with: /clr
#include <vcclr.h>
using namespace System;

class CppClass {
public:
   gcroot<String^> str;   // can use str as if it were String^
   CppClass() {}
};

int main() {
   CppClass c;
   c.str = gcnew String("hello");
   Console::WriteLine( c.str );   // no cast required
}
```

```Output
hello
```

## <a name="example"></a>Exemplo

Este exemplo mostra como criar um `gcroot` objeto no heap nativo.

```cpp
// mcpp_gcroot_2.cpp
// compile with: /clr
// compile with: /clr
#include <vcclr.h>
using namespace System;

struct CppClass {
   gcroot<String ^> * str;
   CppClass() : str(new gcroot<String ^>) {}

   ~CppClass() { delete str; }

};

int main() {
   CppClass c;
   *c.str = gcnew String("hello");
   Console::WriteLine( *c.str );
}
```

```Output
hello
```

## <a name="example"></a>Exemplo

Este exemplo mostra como usar `gcroot` para manter referências a tipos de valor (não tipos de referência) em um tipo nativo usando `gcroot` no tipo boxed.

```cpp
// mcpp_gcroot_3.cpp
// compile with: /clr
#include < vcclr.h >
using namespace System;

public value struct V {
   String^ str;
};

class Native {
public:
   gcroot< V^ > v_handle;
};

int main() {
   Native native;
   V v;
   native.v_handle = v;
   native.v_handle->str = "Hello";
   Console::WriteLine("String in V: {0}", native.v_handle->str);
}
```

```Output
String in V: Hello
```

## <a name="see-also"></a>Confira também

[Usando a interoperabilidade C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
