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
ms.openlocfilehash: 16c79e05c6ba6f50a3e6c0d6dd5f48963be40fa8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219775"
---
# <a name="compiler-support-for-type-traits-ccli-and-ccx"></a>Suporte do compilador para traços de tipo (C++/CLI e C++/CX)

O compilador de C++ da Microsoft é compatível com *traços de tipo* para extensões de C++/CLI e C++/CX, que indicam várias características de um tipo em tempo de compilação.

## <a name="all-runtimes"></a>Todos os Runtimes

### <a name="remarks"></a>Comentários

Os traços de tipo são especialmente úteis para programadores que escrevem bibliotecas.

A lista a seguir contém os traços de tipo compatíveis com o compilador. Todas as características de tipo retornam **`false`** se a condição especificada pelo nome da característica de tipo não é atendida.

(Na lista a seguir, os exemplos de código são escritos somente em C++/CLI. Mas também é compatível com o traço de tipo correspondente em C++/CX, salvo indicação em contrário. O termo "tipo de plataforma" refere-se a tipos de Windows Runtime ou tipos de common language runtime).

- `__has_assign(`*tipo* de`)`

   Retorna **`true`** se a plataforma ou o tipo nativo tem um operador de atribuição de cópia.

    ```cpp
    ref struct R {
    void operator=(R% r) {}
    };

    int main() {
    System::Console::WriteLine(__has_assign(R));
    }
    ```

- `__has_copy(`*tipo* de`)`

   Retorna **`true`** se a plataforma ou o tipo nativo tem um construtor de cópia.

    ```cpp
    ref struct R {
    R(R% r) {}
    };

    int main() {
    System::Console::WriteLine(__has_copy(R));
    }
    ```

- `__has_finalizer(`*tipo* de`)`

   (Sem suporte em C++/CX.) Retorna **`true`** se o tipo CLR tem um finalizador. Consulte [destruidores e finalizadores em como: definir e consumir classes e Structs (C++/CLI)](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers) para obter mais informações.

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

- `__has_nothrow_assign(`*tipo* de`)`

   Retorna **`true`** se um operador de atribuição de cópia tem uma especificação de exceção vazia.

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

- `__has_nothrow_constructor(`*tipo* de`)`

   Retorna **`true`** se o construtor padrão tem uma especificação de exceção vazia.

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

- `__has_nothrow_copy(`*tipo* de`)`

   Retorna **`true`** se o construtor de cópia tem uma especificação de exceção vazia.

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

- `__has_trivial_assign(`*tipo* de`)`

   Retorna **`true`** se o tipo tem um operador de atribuição trivial, gerado por compilador.

    ```cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __has_trivial_assign(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_trivial_constructor(`*tipo* de`)`

   Retorna **`true`** se o tipo tem um Construtor trivial, gerado por compilador.

    ```cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __has_trivial_constructor(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_trivial_copy(`*tipo* de`)`

   Retorna **`true`** se o tipo tem um construtor de cópia trivial, gerado por compilador.

    ```cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __has_trivial_copy(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_trivial_destructor(`*tipo* de`)`

   Retorna **`true`** se o tipo tem um destruidor trivial, gerado por compilador.

    ``` cpp
    // has_trivial_destructor.cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __has_trivial_destructor(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__has_user_destructor(`*tipo* de`)`

   Retorna **`true`** se a plataforma ou o tipo nativo tem um destruidor declarado pelo usuário.

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

- `__has_virtual_destructor(`*tipo* de`)`

   Retorna **`true`** se o tipo tem um destruidor virtual.

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

- `__is_abstract(`*tipo* de`)`

   Retorna **`true`** se o tipo é um tipo abstrato. Saiba mais sobre tipos abstratos nativos em [Classes abstratas](../cpp/abstract-classes-cpp.md).

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

   Retorna **`true`** se o primeiro tipo é uma classe base do segundo tipo, de se ambos os tipos são iguais.

   `__is_base_of` também funciona em tipos de plataforma. Por exemplo, retornará **`true`** se o primeiro tipo for uma classe de [interface](interface-class-cpp-component-extensions.md) e o segundo tipo implementar a interface.

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

- `__is_class(`*tipo* de`)`

   Retorna **`true`** se o tipo é uma classe nativa ou struct.

    ```cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __is_class(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_convertible_to(` `from` `,`  `to` `)`

   Retorna **`true`** se o primeiro tipo pode ser convertido para o segundo tipo.

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

- `__is_delegate(`*tipo* de`)`

   Retorna **`true`** se `type` é um delegado. Saiba mais em [delegado (C++/CLI e C++/CX)](delegate-cpp-component-extensions.md).

    ```cpp
    delegate void MyDel();
    int main() {
    System::Console::WriteLine(__is_delegate(MyDel));
    }
    ```

- `__is_empty(`*tipo* de`)`

   Retorna **`true`** se o tipo não tem nenhum membro de dados de instância.

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

- `__is_enum(`*tipo* de`)`

   Retorna **`true`** se o tipo é uma enumeração nativa.

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

- `__is_interface_class(`*tipo* de`)`

   Retorna **`true`** se passou por uma interface de plataforma. Saiba mais em [classe de interface](interface-class-cpp-component-extensions.md).

    ```cpp
    // is_interface_class.cpp

    using namespace System;
    interface class I {};
    int main() {
    Console::WriteLine(__is_interface_class(I));
    }
    ```

- `__is_pod(`*tipo* de`)`

   Retorna **`true`** se o tipo é uma classe ou Union sem nenhum construtor ou membros não estáticos protegidos ou privados, nenhuma classe base e nenhuma função virtual. Confira o C++ padrão, seções 8.5.1/1, 9/4 e 3.9/10 para saber mais sobre PODs.

   `__is_pod` retornará false em tipos fundamentais.

    ```cpp
    #include <stdio.h>
    struct S {};

    int main() {
    __is_pod(S) == true ?
    printf("true\n") : printf("false\n");
    }
    ```

- `__is_polymorphic(`*tipo* de`)`

   Retorna **`true`** se um tipo nativo tem funções virtuais.

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

- `__is_ref_array(`*tipo* de`)`

   Retorna **`true`** se passou uma matriz de plataforma. Saiba mais em [Matrizes](arrays-cpp-component-extensions.md).

    ```cpp
    using namespace System;
    int main() {
    array<int>^ x = gcnew array<int>(10);
    Console::WriteLine(__is_ref_array(array<int>));
    }
    ```

- `__is_ref_class(`*tipo* de`)`

   Retorna **`true`** se passou uma classe de referência. Saiba mais sobre tipos de referência definidos pelo usuário em [Classes e Structs](classes-and-structs-cpp-component-extensions.md).

    ```cpp
    using namespace System;
    ref class R {};
    int main() {
    Console::WriteLine(__is_ref_class(Buffer));
    Console::WriteLine(__is_ref_class(R));
    }
    ```

- `__is_sealed(`*tipo* de`)`

   Retorna **`true`** se passado uma plataforma ou tipo nativo marcado como Sealed. Saiba mais em [selado](sealed-cpp-component-extensions.md).

    ```cpp
    ref class R sealed{};
    int main() {
    System::Console::WriteLine(__is_sealed(R));
    }
    ```

- `__is_simple_value_class(`*tipo* de`)`

   Retorna **`true`** se passado um tipo de valor que não contém nenhuma referência ao heap coletado por lixo. Saiba mais sobre tipos de valor definidos pelo usuário em [Classes e structs](classes-and-structs-cpp-component-extensions.md).

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

- `__is_union(`*tipo* de`)`

   Retorna **`true`** se um tipo é uma Union.

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

- `__is_value_class(`*tipo* de`)`

   Retorna **`true`** se passado um tipo de valor. Saiba mais sobre tipos de valor definidos pelo usuário em [Classes e structs](classes-and-structs-cpp-component-extensions.md).

    ```cpp
    value struct V {};

    int main() {
    System::Console::WriteLine(__is_value_class(V));
    }
    ```

## <a name="windows-runtime"></a>Windows Runtime

### <a name="remarks"></a>Comentários

`__has_finalizer(` *type* `)` Não há suporte para a característica de tipo de tipo porque esta plataforma não oferece suporte a finalizadores.

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

## <a name="see-also"></a>Confira também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)
