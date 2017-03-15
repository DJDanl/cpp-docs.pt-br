---
title: "Suporte para Compilador de Tra&#231;os de Tipo (Extens&#245;es de Componentes C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__is_simple_value_class"
  - "__has_trivial_destructor"
  - "__has_assign"
  - "__is_union"
  - "__is_class"
  - "__is_abstract"
  - "__has_trivial_assign"
  - "__has_virtual_destructor"
  - "__is_ref_array"
  - "__is_base_of"
  - "__has_copy"
  - "__is_polymorphic"
  - "__has_nothrow_constructor"
  - "__is_ref_class"
  - "__is_delegate"
  - "__is_convertible_to"
  - "__is_value_class"
  - "__is_interface_class"
  - "__has_nothrow_copy"
  - "__is_sealed"
  - "__has_trivial_constructor"
  - "__has_trivial_copy"
  - "__is_enum"
  - "__has_nothrow_assign"
  - "__has_finalizer"
  - "__is_empty"
  - "__is_pod"
  - "__has_user_destructor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave __is_class [C++]"
  - "palavra-chave __is_pod [C++]"
  - "palavra-chave __is_delegate [C++]"
  - "palavra-chave __is_value_class [C++]"
  - "palavra-chave __has_copy [C++]"
  - "palavra-chave __has_nothrow_copy [C++]"
  - "palavra-chave __is_interface_class [C++]"
  - "palavra-chave __is_sealed [C++]"
  - "palavra-chave __is_convertible_to [C++]"
  - "palavra-chave __is_ref_class [C++]"
  - "palavra-chave __has_trivial_copy [C++]"
  - "palavra-chave __has_user_destructor [C++]"
  - "palavra-chave __is_abstract [C++]"
  - "palavra-chave __is_empty [C++]"
  - "palavra-chave __has_trivial_assign [C++]"
  - "palavra-chave __has_nothrow_constructor [C++]"
  - "palavra-chave __is_ref_array [C++]"
  - "palavra-chave __is_base_of [C++]"
  - "palavra-chave __has_nothrow_assign [C++]"
  - "palavra-chave __has_virtual_destructor [C++]"
  - "palavra-chave __has_finalizer [C++]"
  - "palavra-chave __is_union [C++]"
  - "palavra-chave __has_assign [C++]"
  - "palavra-chave __has_trivial_destructor [C++]"
  - "palavra-chave __is_polymorphic [C++]"
  - "palavra-chave __is_enum [C++]"
  - "palavra-chave __is_simple_value_class [C++]"
  - "palavra-chave __has_trivial_constructor [C++]"
ms.assetid: cd440630-0394-48c0-a16b-1580b6ef5844
caps.latest.revision: 27
caps.handback.revision: 27
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte para Compilador de Tra&#231;os de Tipo (Extens&#245;es de Componentes C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O compilador suporta *Digite características*, que indicam várias características de um tipo em tempo de compilação.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 **Comentários**  
  
 Características de tipo são especialmente úteis para programadores que escrevem bibliotecas.  
  
 A lista a seguir contém as características de tipo que são suportadas pelo compilador. Todos os tipo de retorno de características `false` se a condição especificada pelo nome da característica de tipo não for atendida.  
  
 (Na lista a seguir, exemplos de código são escritos em [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)]. Mas a característica de tipo correspondente também é suportada no [!INCLUDE[cppwrt](../build/reference/includes/cppwrt_md.md)] a menos que indicado de outra forma. O termo "tipo de plataforma" se refere a um [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] tipos ou tipos common language runtime.)  
  
-   `__has_assign(` `type` `)`  
  
     Retornará true se a plataforma ou tipo nativo tem um operador de atribuição de cópia.  
  
    ```  
  
    ref struct R {  
    void operator=(R% r) {}  
    };  
  
    int main() {  
    System::Console::WriteLine(__has_assign(R));  
    }  
  
    ```  
  
-   `__has_copy(` `type` `)`  
  
     Retorna VERDADEIRO se a plataforma ou tipo nativo tem um construtor de cópia.  
  
    ```  
  
    ref struct R {  
    R(R% r) {}  
    };  
  
    int main() {  
    System::Console::WriteLine(__has_copy(R));  
    }  
  
    ```  
  
-   `__has_finalizer(` `type` `)`  
  
     (Não há suportado no [!INCLUDE[cppwrt](../build/reference/includes/cppwrt_md.md)].) Retorna VERDADEIRO se o tipo CLR tem um finalizador. Consulte [destruidores e finalizadores em Visual C++](../misc/destructors-and-finalizers-in-visual-cpp.md) para obter mais informações.  
  
    ```  
  
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
  
-   `__has_nothrow_assign(` `type` `)`  
  
     Retorna VERDADEIRO se um operador de atribuição de cópia tenha uma especificação de exceção vazio.  
  
    ```  
  
    #include <stdio.h>  
    struct S {  
    void operator=(S& r) throw() {}  
    };  
  
    int main() {  
    __has_nothrow_assign(S) == true ?  
    printf("true\n") : printf("false\n");  
    }  
  
    ```  
  
-   `__has_nothrow_constructor(` `type` `)`  
  
     Retorna VERDADEIRO se o construtor padrão tem uma especificação de exceção vazio.  
  
    ```  
  
    #include <stdio.h>  
    struct S {  
    S() throw() {}  
    };  
  
    int main() {  
    __has_nothrow_constructor(S) == true ?  
    printf("true\n") : printf("false\n");  
    }  
  
    ```  
  
-   `__has_nothrow_copy(` `type` `)`  
  
     Retorna VERDADEIRO se o construtor de cópia tenha uma especificação de exceção vazio.  
  
    ```  
  
    #include <stdio.h>  
    struct S {  
    S(S& r) throw() {}  
    };  
  
    int main() {  
    __has_nothrow_copy(S) == true ?  
    printf("true\n") : printf("false\n");  
    }  
  
    ```  
  
-   `__has_trivial_assign(` `type` `)`  
  
     Retorna VERDADEIRO se o tipo tem um operador de atribuição trivial, gerado pelo compilador.  
  
    ```  
  
    #include <stdio.h>  
    struct S {};  
  
    int main() {  
    __has_trivial_assign(S) == true ?  
    printf("true\n") : printf("false\n");  
    }  
  
    ```  
  
-   `__has_trivial_constructor(` `type` `)`  
  
     Retorna VERDADEIRO se o tipo tem um construtor simples, gerado pelo compilador.  
  
    ```  
  
    #include <stdio.h>  
    struct S {};  
  
    int main() {  
    __has_trivial_constructor(S) == true ?  
    printf("true\n") : printf("false\n");  
    }  
  
    ```  
  
-   `__has_trivial_copy(` `type` `)`  
  
     Retorna VERDADEIRO se o tipo tem um construtor de cópia trivial, gerado pelo compilador.  
  
    ```  
  
    #include <stdio.h>  
    struct S {};  
  
    int main() {  
    __has_trivial_copy(S) == true ?  
    printf("true\n") : printf("false\n");  
    }  
  
    ```  
  
-   `__has_trivial_destructor(` `type` `)`  
  
     Retorna VERDADEIRO se o tipo tem um destruidor trivial, gerado pelo compilador.  
  
    ```  
  
    // has_trivial_destructor.cpp  
    #include <stdio.h>  
    struct S {};  
  
    int main() {  
    __has_trivial_destructor(S) == true ?  
    printf("true\n") : printf("false\n");  
    }  
  
    ```  
  
-   `__has_user_destructor(` `type` `)`  
  
     Retornará true se a plataforma ou tipo nativo tem um destruidor declarado pelo usuário.  
  
    ```  
  
    // has_user_destructor.cpp  
  
    using namespace System;  
    ref class R {  
    ~R() {}  
    };  
  
    int main() {  
    Console::WriteLine(__has_user_destructor(R));  
    }  
  
    ```  
  
-   `__has_virtual_destructor(` `type` `)`  
  
     Retorna VERDADEIRO se o tipo tem um destruidor virtual.  
  
     `__has_virtual_destructor` também funciona em tipos de plataforma e qualquer destruidor definido pelo usuário em um tipo de plataforma é um destruidor virtual.  
  
    ```  
  
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
  
-   `__is_abstract(` `type` `)`  
  
     Retorna VERDADEIRO se o tipo for um tipo abstrato. Para obter mais informações sobre tipos abstratos nativos, consulte [abstrato](../windows/abstract-cpp-component-extensions.md).  
  
     `__is_abstract` também funciona para tipos de plataforma. Uma interface com pelo menos um membro é um tipo abstrato, assim como um tipo de referência pelo menos um membro abstrato. Para obter mais informações sobre tipos de plataforma abstratas, consulte [Classes abstratas](../cpp/abstract-classes-cpp.md)  
  
    ```  
  
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
  
-   `__is_base_of(` `base` `,` `derived` `)`  
  
     Retorna VERDADEIRO se o primeiro tipo é de uma classe base do segundo tipo, se ambos os tipos forem iguais.  
  
     `__is_base_of` também funciona em tipos de plataforma. Por exemplo, ele retornará true se o primeiro tipo é um [classe de interface](../windows/interface-class-cpp-component-extensions.md) e o segundo tipo implementa a interface.  
  
    ```  
  
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
  
-   `__is_class(` `type` `)`  
  
     Retorna VERDADEIRO se o tipo for native class ou struct.  
  
    ```  
  
    #include <stdio.h>  
    struct S {};  
  
    int main() {  
    __is_class(S) == true ?  
    printf("true\n") : printf("false\n");  
    }  
  
    ```  
  
-   `__is_convertible_to(` `from` `,`  `to` `)`  
  
     Retorna VERDADEIRO se o primeiro tipo pode ser convertido para o segundo tipo.  
  
    ```  
  
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
  
-   `__is_delegate(` `type` `)`  
  
     Retornará true se `type` é um delegado. Para obter mais informações, consulte [delegado (extensões de componentes C++)](../windows/delegate-cpp-component-extensions.md).  
  
    ```  
  
    delegate void MyDel();  
    int main() {  
    System::Console::WriteLine(__is_delegate(MyDel));  
    }  
  
    ```  
  
-   `__is_empty(` `type` `)`  
  
     Retorna VERDADEIRO se o tipo não tem nenhum membro de dados da instância.  
  
    ```  
  
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
  
-   `__is_enum(` `type` `)`  
  
     Retorna VERDADEIRO se o tipo for um enum nativo.  
  
    ```  
  
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
  
-   `__is_interface_class(` `type` `)`  
  
     Retorna VERDADEIRO se passado a uma interface de plataforma. Para obter mais informações, consulte [classe de interface](../windows/interface-class-cpp-component-extensions.md).  
  
    ```  
  
    // is_interface_class.cpp  
  
    using namespace System;  
    interface class I {};  
    int main() {  
    Console::WriteLine(__is_interface_class(I));  
    }  
  
    ```  
  
-   `__is_pod(` `type` `)`  
  
     Retorna VERDADEIRO se o tipo é uma classe ou união com nenhum construtor ou particulares ou protegidos membros não estáticos, nenhuma classe base e não há funções virtuais. Consulte o C++ standard, seções 8.5.1/1, 9/4 e 3.9 a 10 para obter mais informações sobre PODs.  
  
     `__is_pod` retornará false em tipos fundamentais.  
  
    ```  
  
    #include <stdio.h>  
    struct S {};  
  
    int main() {  
    __is_pod(S) == true ?  
    printf("true\n") : printf("false\n");  
    }  
  
    ```  
  
-   `__is_polymorphic(` `type` `)`  
  
     Retorna VERDADEIRO se um tipo nativo tem funções virtuais.  
  
    ```  
  
    #include <stdio.h>  
    struct S {  
    virtual void Test(){}  
    };  
  
    int main() {  
    __is_polymorphic(S) == true ?  
    printf("true\n") : printf("false\n");  
    }  
  
    ```  
  
-   `__is_ref_array(` `type` `)`  
  
     Retorna VERDADEIRO se passado a uma matriz de plataforma. Para obter mais informações, consulte [matrizes](../windows/arrays-cpp-component-extensions.md).  
  
    ```  
  
    using namespace System;  
    int main() {  
    array<int>^ x = gcnew array<int>(10);  
    Console::WriteLine(__is_ref_array(array<int>));  
    }  
  
    ```  
  
-   `__is_ref_class(` `type` `)`  
  
     Retorna VERDADEIRO se passado a uma classe de referência. Para obter mais informações sobre tipos de referência definidos pelo usuário, consulte [Classes e estruturas](../windows/classes-and-structs-cpp-component-extensions.md).  
  
    ```  
  
    using namespace System;  
    ref class R {};  
    int main() {  
    Console::WriteLine(__is_ref_class(Buffer));  
    Console::WriteLine(__is_ref_class(R));  
    }  
  
    ```  
  
-   `__is_sealed(` `type` `)`  
  
     Retorna VERDADEIRO se passado a uma plataforma ou tipo nativo marcado como sealed. Para obter mais informações, consulte [lacrado](../windows/sealed-cpp-component-extensions.md).  
  
    ```  
  
    ref class R sealed{};  
    int main() {  
    System::Console::WriteLine(__is_sealed(R));  
    }  
  
    ```  
  
-   `__is_simple_value_class(` `type` `)`  
  
     Retorna VERDADEIRO se passado um tipo de valor que não contém nenhuma referência ao heap coletado como lixo. Para obter mais informações sobre tipos de valor definidos pelo usuário, consulte [Classes e estruturas](../windows/classes-and-structs-cpp-component-extensions.md).  
  
    ```  
  
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
  
-   `__is_union(` `type` `)`  
  
     Retorna VERDADEIRO se um tipo é uma união.  
  
    ```  
  
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
  
-   `__is_value_class(` `type` `)`  
  
     Retorna VERDADEIRO se passado um tipo de valor. Para obter mais informações sobre tipos de valor definidos pelo usuário, consulte [Classes e estruturas](../windows/classes-and-structs-cpp-component-extensions.md).  
  
    ```  
  
    value struct V {};  
  
    int main() {  
    System::Console::WriteLine(__is_value_class(V));  
    }  
  
    ```  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 **Comentários**  
  
 O `__has_finalizer(`*tipo*`)` característica de tipo não tem suporte porque esta plataforma não dá suporte para os finalizadores.  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Comentários**  
  
 (Não há nenhum comentários específicos da plataforma para esse recurso.)  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir mostra como usar um modelo de classe para expor uma característica de tipo do compilador para um **/clr** compilação. Para obter mais informações, consulte [tempo de execução do Windows e modelos gerenciados](../windows/windows-runtime-and-managed-templates-cpp-component-extensions.md).  
  
```  
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
  
 **Saída**  
  
```Output  
R is a ref class  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)