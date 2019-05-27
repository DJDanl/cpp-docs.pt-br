---
title: Suporte do compilador para traços de tipo (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- __is_simple_value_class
- __has_trivial_destructor
- __has_assign
- __is_union
- __is_class
- __is_abstract
- __has_trivial_assign
- __has_virtual_destructor
- __is_ref_array
- __is_base_of
- __has_copy
- __is_polymorphic
- __has_nothrow_constructor
- __is_ref_class
- __is_delegate
- __is_convertible_to
- __is_value_class
- __is_interface_class
- __has_nothrow_copy
- __is_sealed
- __has_trivial_constructor
- __has_trivial_copy
- __is_enum
- __has_nothrow_assign
- __has_finalizer
- __is_empty
- __is_pod
- __has_user_destructor
helpviewer_keywords:
- __is_class keyword [C++]
- __is_pod keyword [C++]
- __is_delegate keyword [C++]
- __is_value_class keyword [C++]
- __has_copy keyword [C++]
- __has_nothrow_copy keyword [C++]
- __is_interface_class keyword [C++]
- __is_sealed keyword [C++]
- __is_convertible_to keyword [C++]
- __is_ref_class keyword [C++]
- __has_trivial_copy keyword [C++]
- __has_user_destructor keyword [C++]
- __is_abstract keyword [C++]
- __is_empty keyword [C++]
- __has_trivial_assign keyword [C++]
- __has_nothrow_constructor keyword [C++]
- __is_ref_array keyword [C++]
- __is_base_of keyword [C++]
- __has_nothrow_assign keyword [C++]
- __has_virtual_destructor keyword [C++]
- __has_finalizer keyword [C++]
- __is_union keyword [C++]
- __has_assign keyword [C++]
- __has_trivial_destructor keyword [C++]
- __is_polymorphic keyword [C++]
- __is_enum keyword [C++]
- __is_simple_value_class keyword [C++]
- __has_trivial_constructor keyword [C++]
ms.assetid: cd440630-0394-48c0-a16b-1580b6ef5844
ms.openlocfilehash: d068917a02fef0f1d4b7fd46fd6978da2d358872
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65516211"
---
# <a name="compiler-support-for-type-traits-ccli-and-ccx"></a>Suporte do compilador para traços de tipo (C++/CLI e C++/CX)

O compilador de C++ da Microsoft é compatível com *traços de tipo* para extensões de C++/CLI e C++/CX, que indicam várias características de um tipo em tempo de compilação.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

### <a name="remarks"></a>Comentários

Os traços de tipo são especialmente úteis para programadores que escrevem bibliotecas.

A lista a seguir contém os traços de tipo compatíveis com o compilador. Todos os traços de tipo retornam **false** se a condição especificada pelo nome do traço de tipo não for atendida.

(Na lista a seguir, os exemplos de código são escritos somente em C++/CLI. Mas também é compatível com o traço de tipo correspondente em C++/CX, salvo indicação em contrário. O termo "tipo de plataforma" refere-se a tipos de Windows Runtime ou tipos de common language runtime).

- `__has_assign(` *tipo* `)`

   Retorna **true** se o tipo plataforma ou nativo tiver um operador de atribuição de cópia.

    ```cpp
    ref struct R {
    void operator=(R% r) {}
    };

    int main() {
    System::Console::WriteLine(__has_assign(R));
    }
    ```

- `__has_copy(` *tipo* `)`

   Retorna **true** se o tipo plataforma ou nativo tiver um construtor de cópia.

    ```cpp
    ref struct R {
    R(R% r) {}
    };

    int main() {
    System::Console::WriteLine(__has_copy(R));
    }
    ```

- `__has_finalizer(` *tipo* `)`

   (Não é compatível com C++/CX). Retorna **true** se o tipo CLR tiver um finalizador. Veja mais em [Destruidores e finalizadores em Como definir e consumir classes e structs (C++/CLI)](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

    ```cpp
    using namespace System;
    ref struct R {
    ~R() {}
    protected:
    !R() {}
    };

    int main() {
    Console::WriteLine(__has_finalizer(R));
    }
    ```

- `__has_nothrow_assign(` *tipo* `)`

   Retorna **true** se um operador de atribuição de cópia tiver uma especificação de exceção vazia.

    ```cpp
    #include <stdio.h>
    struct S {
    void operator=(S& r) throw() {}
    };

    int main() {
    __has_nothrow_assign(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_nothrow_constructor(` *tipo* `)`

   Retorna **true** se um construtor padrão tiver uma especificação de exceção vazia.

    ```cpp
    #include <stdio.h>
    struct S {
    S() throw() {}
    };

    int main() {
    __has_nothrow_constructor(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_nothrow_copy(` *tipo* `)`

   Retorna **true** se um construtor de cópia tiver uma especificação de exceção vazia.

    ```cpp
    #include <stdio.h>
    struct S {
    S(S& r) throw() {}
    };

    int main() {
    __has_nothrow_copy(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_trivial_assign(` *tipo* `)`

   Retorna **true** se o tipo tiver um operador de atribuição trivial, gerado pelo compilador.

    ```cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __has_trivial_assign(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_trivial_constructor(` *tipo* `)`

   Retorna **true** se o tipo tiver um construtor trivial, gerado pelo compilador.

    ```cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __has_trivial_constructor(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_trivial_copy(` *tipo* `)`

   Retorna **true** se o tipo tiver um construtor de cópia trivial, gerado pelo compilador.

    ```cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __has_trivial_copy(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_trivial_destructor(` *tipo* `)`

   Retorna **true** se o tipo tiver um destruidor trivial, gerado pelo compilador.

    ``` cpp
    // has_trivial_destructor.cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __has_trivial_destructor(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_user_destructor(` *tipo* `)`

   Retorna **true** se o tipo plataforma ou nativo tiver um destruidor declarado pelo usuário.

    ```cpp
    // has_user_destructor.cpp

    using namespace System;
    ref class R {
    ~R() {}
    };

    int main() {
    Console::WriteLine(__has_user_destructor(R));
    }
    ```

- `__has_virtual_destructor(` *tipo* `)`

   Retorna **true** se o tipo tiver um destruidor virtual.

   `__has_virtual_destructor` também funciona em tipos de plataforma, e qualquer destruidor definido pelo usuário em um tipo de plataforma é um destruidor virtual.

    ```cpp
    // has_virtual_destructor.cpp
    #include <stdio.h>
    struct S {
    virtual ~S() {}
    };

    int main() {
    __has_virtual_destructor(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_abstract(` *tipo* `)`

   Retorna **true** se o tipo for um tipo abstrato. Saiba mais sobre tipos abstratos nativos em [Classes abstratas](../cpp/abstract-classes-cpp.md).

   `__is_abstract` também funciona para tipos de plataforma. Uma interface com pelo menos um membro é um tipo abstrato, assim como um tipo de referência com pelo menos um membro abstrato. Saiba mais sobre tipos de plataforma abstratos em [abstract](abstract-cpp-component-extensions.md).

    ```cpp
    // is_abstract.cpp
    #include <stdio.h>
    struct S {
    virtual void Test() = 0;
    };

    int main() {
    __is_abstract(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_base_of(` `base` `,` `derived` `)`

   Retorna **true** se o primeiro tipo for uma classe base do segundo tipo, ou se os dois tipos forem iguais.

   `__is_base_of` também funciona em tipos de plataforma. Por exemplo, retornará **true** se o primeiro tipo for uma [classe de interface](interface-class-cpp-component-extensions.md), e o segundo tipo implementar a interface.

    ```cpp
    // is_base_of.cpp
    #include <stdio.h>
    struct S {};
    struct T : public S {};

    int main() {
    __is_base_of(S, T) == true ?
    printf("true\n") : printf("false\n");

    __is_base_of(S, S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_class(` *tipo* `)`

   Retorna **true** se o tipo for uma classe ou struct nativa.

    ```cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __is_class(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_convertible_to(` `from` `,`  `to` `)`

   Retorna **true** se o primeiro tipo puder ser convertido no segundo tipo.

    ```cpp
    #include <stdio.h>
    struct S {};
    struct T : public S {};

    int main() {
    S * s = new S;
    T * t = new T;
    s = t;
    __is_convertible_to(T, S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_delegate(` *tipo* `)`

   Retorna **true** se `type` for um delegado. Saiba mais em [delegado (C++/CLI e C++/CX)](delegate-cpp-component-extensions.md).

    ```cpp
    delegate void MyDel();
    int main() {
    System::Console::WriteLine(__is_delegate(MyDel));
    }
    ```

- `__is_empty(` *tipo* `)`

   Retorna **true** se o tipo não tiver membro de dados de instância.

    ```cpp
    #include <stdio.h>
    struct S {
    int Test() {}
    static int i;
    };
    int main() {
    __is_empty(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_enum(` *tipo* `)`

   Retorna **true** se o tipo for uma enumeração nativa.

    ```cpp
    // is_enum.cpp
    #include <stdio.h>
    enum E { a, b };

    struct S {
    enum E2 { c, d };
    };

    int main() {
    __is_enum(E) == true ?
    printf("true\n") : printf("false\n");

    __is_enum(S::E2) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_interface_class(` *tipo* `)`

   Retorna **true** se uma interface de plataforma for passada. Saiba mais em [classe de interface](interface-class-cpp-component-extensions.md).

    ```cpp
    // is_interface_class.cpp

    using namespace System;
    interface class I {};
    int main() {
    Console::WriteLine(__is_interface_class(I));
    }
    ```

- `__is_pod(` *tipo* `)`

   Retorna **true** se o tipo for uma classe ou união sem construtor ou os membros não estáticos privados ou protegidos, sem classes base e sem funções virtuais. Confira o C++ padrão, seções 8.5.1/1, 9/4 e 3.9/10 para saber mais sobre PODs.

   `__is_pod` retornará false em tipos fundamentais.

    ```cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __is_pod(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_polymorphic(` *tipo* `)`

   Retorna **true** se um tipo nativo tiver funções virtuais.

    ```cpp
    #include <stdio.h>
    struct S {
    virtual void Test(){}
    };

    int main() {
    __is_polymorphic(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_ref_array(` *tipo* `)`

   Retorna **true** se uma matriz de plataforma for passada. Saiba mais em [Matrizes](arrays-cpp-component-extensions.md).

    ```cpp
    using namespace System;
    int main() {
    array<int>^ x = gcnew array<int>(10);
    Console::WriteLine(__is_ref_array(array<int>));
    }
    ```

- `__is_ref_class(` *tipo* `)`

   Retorna **true** se uma classe de referência for passada. Saiba mais sobre tipos de referência definidos pelo usuário em [Classes e Structs](classes-and-structs-cpp-component-extensions.md).

    ```cpp
    using namespace System;
    ref class R {};
    int main() {
    Console::WriteLine(__is_ref_class(Buffer));
    Console::WriteLine(__is_ref_class(R));
    }
    ```

- `__is_sealed(` *tipo* `)`

   Retornará **true** se uma plataforma ou tipo nativo for passado marcado como selado. Saiba mais em [selado](sealed-cpp-component-extensions.md).

    ```cpp
    ref class R sealed{};
    int main() {
    System::Console::WriteLine(__is_sealed(R));
    }
    ```

- `__is_simple_value_class(` *tipo* `)`

   Retorna **true** se um tipo de valor que não contém nenhuma referência for passado para o heap coletado como lixo. Saiba mais sobre tipos de valor definidos pelo usuário em [Classes e structs](classes-and-structs-cpp-component-extensions.md).

    ```cpp
    using namespace System;
    ref class R {};
    value struct V {};
    value struct V2 {
    R ^ r;   // not a simnple value type
    };

    int main() {
    Console::WriteLine(__is_simple_value_class(V));
    Console::WriteLine(__is_simple_value_class(V2));
    }
    ```

- `__is_union(` *tipo* `)`

   Retornará **true** se um tipo for uma união.

    ```cpp
    #include <stdio.h>
    union A {
    int i;
    float f;
    };

    int main() {
    __is_union(A) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_value_class(` *tipo* `)`

   Retornará **true** se um tipo de valor for passado. Saiba mais sobre tipos de valor definidos pelo usuário em [Classes e structs](classes-and-structs-cpp-component-extensions.md).

    ```cpp
    value struct V {};

    int main() {
    System::Console::WriteLine(__is_value_class(V));
    }
    ```

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="remarks"></a>Comentários

O traço `__has_finalizer(`*tipo*`)` não é compatível porque esta plataforma não é compatível com finalizadores.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

(Não há comentários específicos da plataforma para esse recurso.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

**Exemplo**

O exemplo de código a seguir mostra como usar um modelo de classe para expor um traço de tipo de compilador para uma compilação `/clr`. Saiba mais em [Windows Runtime e modelos gerenciados](windows-runtime-and-managed-templates-cpp-component-extensions.md).

```cpp
// compiler_type_traits.cpp
// compile with: /clr
using namespace System;

template <class T>
ref struct is_class {
   literal bool value = __is_ref_class(T);
};

ref class R {};

int main () {
   if (is_class<R>::value)
      Console::WriteLine("R is a ref class");
   else
      Console::WriteLine("R is not a ref class");
}
```

```Output
R is a ref class
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)