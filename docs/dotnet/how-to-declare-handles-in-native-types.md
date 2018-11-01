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
ms.openlocfilehash: 4b5cd212589be04f5f9f3a5dd6d4496a8f5add2c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50464916"
---
# <a name="how-to-declare-handles-in-native-types"></a>Como declarar identificadores em tipos nativos

Você não pode declarar um tipo de identificador em um tipo nativo. vcclr fornece o modelo de wrapper fortemente tipado `gcroot` para se referir a um objeto CLR do heap de C++. Esse modelo permite que você inserir um identificador virtual em um tipo nativo e tratá-lo como se fosse o tipo subjacente. Na maioria dos casos, você pode usar o `gcroot` objeto como o tipo inserido sem qualquer conversão. No entanto, com [para cada um, na](../dotnet/for-each-in.md), você precisa usar `static_cast` para recuperar a referência gerenciada subjacente.

O `gcroot` modelo é implementado usando os recursos da classe de valor System::Runtime::InteropServices::GCHandle, que fornece "identificadores" para o heap coletado como lixo. Observe que os identificadores em si não são coletadas como lixo e são liberados quando não estiver em uso pelo destruidor no `gcroot` classe (esse destruidor não pode ser chamado manualmente). Se você criar uma instância de um `gcroot` do objeto no heap nativo, você deve chamar delete no recurso.

O tempo de execução mantém uma associação entre o identificador e o objeto CLR, que faz referência a ele. Quando o objeto CLR é movido com o heap coletado como lixo, o identificador retornará o novo endereço do objeto. Uma variável não precisa ser fixado antes que ele é atribuído a um `gcroot` modelo.

## <a name="example"></a>Exemplo

Este exemplo mostra como criar um `gcroot` objeto na pilha nativo.

```
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

```
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

Este exemplo mostra como usar `gcroot` para manter referências a tipos de valor (tipos de referência não) em um tipo nativo usando `gcroot` no tipo Demarcado.

```
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

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)