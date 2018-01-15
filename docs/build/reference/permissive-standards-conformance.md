---
title: "-permissiva - (conformidade com os padrões) | Microsoft Docs"
ms.date: 11/11/2016
ms.technology: cpp-tools
ms.topic: article
f1_keywords:
- /permissive
- VC.Project.VCCLCompilerTool.ConformanceMode
dev_langs: C++
helpviewer_keywords:
- /permissive compiler options [C++]
- -permissive compiler options [C++]
- Standards conformance compiler options
- permissive compiler options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 90ff6d2be6174f32d7d93252ebd8b693b422076d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="permissive--standards-conformance"></a>/ permissivo-(conformidade com os padrões)

Especifique o modo de conformidade de padrões para o compilador. Use esta opção para ajudá-lo a identificar e corrigir problemas de conformidade em seu código, para torná-la mais correto e mais portáteis.

## <a name="syntax"></a>Sintaxe

> **/ permissivo-**

## <a name="remarks"></a>Comentários

Você pode usar o **/ permissivo-** opção de compilador para especificar o comportamento do compilador em conformidade com padrões. Esta opção desabilita permissivas comportamentos e configura o [/Zc](../../build/reference/zc-conformance.md) opções do compilador para compatibilidade total. No IDE, essa opção também torna o código IntelliSense mecanismo sublinhado não conforme. 

Por padrão, o **/ permissivo-** opção é definida em novos projetos criados por versão do Visual Studio de 2017 15,5 e versões posteriores. Ele não está definido por padrão em versões anteriores. Quando a opção for definida, o compilador gera o diagnósticos erros ou avisos quando construções de linguagem não padrão forem detectados em seu código, incluindo alguns erros comuns no pré-código C++ 11.

O **/ permissivo-** opção é compatível com quase todos os arquivos de cabeçalho de Kits do Windows mais recente, como o Software Development Kit (SDK) ou o Windows Driver Kit (WDK), começando no SDK do Windows estão criadores (10.0.16299.0). Versões mais antigas do SDK podem falhar compilar em **/ permissivo-** por vários motivos de conformidade do código de origem. O compilador e remessa de SDKs em cronogramas de lançamento diferentes, portanto, há alguns problemas restantes. Para problemas de arquivo de cabeçalho específico, consulte [problemas de cabeçalho do Windows](#windows-header-issues) abaixo.

O **/ permissivo-** opção define a [/ZC: strictstrings](../../build/reference/zc-conformance.md) e [/ZC: rvaluecast](../../build/reference/zc-conformance.md) opções de comportamento em conformidade. Eles padrão não conformes comportamento. Você pode passar específico **/Zc** opções após **/ permissivo-** na linha de comando para substituir esse comportamento.

Em versões do início de compilador no Visual Studio 2017 versão 15,3, o **/ permissivo-** opção define a **/Zc:ternary** opção. O compilador também implementa mais os requisitos para a pesquisa de nome em duas fases. Quando o **/ permissivo-** opção for definida, o compilador analisa definições de modelo de função e de classe, identificando dependentes e independentes nomes usados nos modelos. Nesta versão, a análise de dependência de nome só é executada.

Extensões específicas do ambiente e áreas de idioma que o padrão permite até a implementação não são afetadas por **/ permissivo-**. Por exemplo, o Microsoft específicos `__declspec`, convenção de chamada e palavras-chave e diretivas pragma específico do compilador ou atributos de tratamento de exceções estruturado não são sinalizados pelo compilador **/ permissivo-** modo.

O **/ permissivo-** opção usa o suporte de conformidade na versão atual do compilador para determinar quais as construções de linguagem não conforme. A opção não determina se o código está em conformidade com uma versão específica do C++ padrão. Para habilitar todo o suporte de compilador implementado para o padrão de rascunho mais recente, use o [/std:latest](../../build/reference/std-specify-language-standard-version.md) opção. Para restringir o suporte de compilador implementado atualmente C++ 17 padrão, use o [/std:c + + 17](../../build/reference/std-specify-language-standard-version.md) opção. Para restringir o suporte de compilador para atender melhor o padrão de 14 C++, use o [/std:c + + 14](../../build/reference/std-specify-language-standard-version.md) opção, que é o padrão.

Não todos os C++ 11, C++ 14 ou C++ 17 em conformidade com padrões de código é suportado pelo compilador Visual C++ no Visual Studio de 2017. O **/ permissivo-** opção pode não detectar problemas sobre alguns aspectos de pesquisa de nome em duas fases, associação a uma referência não const para um temporário, tratando init cópia como init direto, permitindo que várias conversões definidas pelo usuário no a inicialização, ou tokens alternativos para os operadores lógicos e outras áreas de conformidade sem suporte. Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="how-to-fix-your-code"></a>Como corrigir seu código

Aqui estão alguns exemplos de código que é detectada como não conformes quando você usar **/ permissivo-**, juntamente com maneiras sugeridas para corrigir os problemas.

#### <a name="use-default-as-an-identifier-in-native-code"></a>Use o padrão como um identificador em código nativo

```cpp
void func(int default); // Error C2321: 'default' is a keyword, and
                        // cannot be used in this context
```

#### <a name="lookup-members-in-dependent-base"></a>Membros de pesquisa na base de dados dependente

```cpp
template <typename T>
struct B {
    void f();
};

template <typename T>
struct D : public B<T> // B is a dependent base because its type
                       // depends on the type of T.
{
    // One possible fix is to uncomment the following line.
    // If this is a type, don't forget the 'typename' keyword.
    // using B<T>::f;

    void g() {
        f(); // error C3861: 'f': identifier not found
             // Another fix is to change it to 'this->f();'
    }
};

void h() {
    D<int> d;
    d.g();
}
```

#### <a name="use-of-qualified-names-in-member-declarations"></a>Uso de nomes qualificados em declarações de membro

```cpp
struct A {
    void A::f() { } // error C4596: illegal qualified name in member
                    // declaration.
                    // Remove redundant 'A::' to fix.
};
```

#### <a name="initialize-multiple-union-members-in-a-member-initializer"></a>Inicializar os vários membros de união em um inicializador de membro

```cpp
union U
{
    U()
        : i(1), j(1) // error C3442: Initializing multiple members of
                     // union: 'U::i' and 'U::j'.
                     // Remove all but one of the initializations to fix.
    {}
    int i;
    int j;
};
```

#### <a name="hidden-friend-name-lookup-rules"></a>Regras de pesquisa de nome de amigo oculto

```cpp
// Example 1
struct S {
    friend void f(S *);
};
// Uncomment this declaration to make the hidden friend visible:
// void f(S *); // This declaration makes the hidden friend visible

using type = void (*)(S *);
type p = &f; // error C2065: 'f': undeclared identifier.
```

```cpp
// Example 2
struct S {
    friend void f(S *);
};
void g() {
    // Using nullptr instead of S prevents argument dependent lookup in S
    f(nullptr); // error C3861: 'f': identifier not found

    S *p = nullptr;
    f(S); // Hidden friend now found via argument-dependent lookup.
}
```

#### <a name="use-scoped-enums-in-array-bounds"></a>Usar enums com escopo em limites de matriz

```cpp
enum class Color {
    Red, Green, Blue
};

int data[Color::Blue]; // error C3411: 'Color' is not valid as the size
                       // of an array as it is not an integer type.
                       // Cast to type size_t or int to fix.
```

#### <a name="use-for-each-in-native-code"></a>Use para cada um no código nativo

```cpp
void func() {
    int array[] = {1, 2, 30, 40};
    for each (int i in array) // error C4496: nonstandard extension
                              // 'for each' used: replace with
                              // ranged-for statement:
                              // for (int i: array)
    {
        // ...
    }
}
```

#### <a name="use-of-atl-attributes"></a>Uso de atributos ATL

```cpp
// Example 1
[uuid("594382D9-44B0-461A-8DE3-E06A3E73C5EB")]
class A {};
```

```cpp
// Fix for example 1
class __declspec(uuid("594382D9-44B0-461A-8DE3-E06A3E73C5EB")) B {};
```

```cpp
// Example 2
[emitidl];
[module(name="Foo")];

[object, local, uuid("9e66a290-4365-11d2-a997-00c04fa37ddb")]
__interface ICustom {
    HRESULT Custom([in] longl, [out, retval] long*pLong);
    [local] HRESULT CustomLocal([in] longl, [out, retval] long*pLong);
};

[coclass, appobject, uuid("9e66a294-4365-11d2-a997-00c04fa37ddb")]
class CFoo : public ICustom
{};
```

```cpp
// Fix for example 2
// First, create the *.idl file. The vc140.idl generated file can be 
// used to automatically obtain a *.idl file for the interfaces with 
// annotation. Second, add a midl step to your build system to make 
// sure that the C++ interface definitions are outputted. 
// Last, adjust your existing code to use ATL directly as shown in 
// the atl implementation section.

-- IDL  FILE--
import "docobj.idl";

[object, local, uuid(9e66a290-4365-11d2-a997-00c04fa37ddb)]
interface ICustom : IUnknown {
    HRESULT Custom([in] longl, [out,retval] long*pLong);
    [local] HRESULT CustomLocal([in] longl, [out,retval] long*pLong);
};

[ version(1.0), uuid(29079a2c-5f3f-3325-99a1-3ec9c40988bb) ]
library Foo {
    importlib("stdole2.tlb");
    importlib("olepro32.dll");

    [version(1.0), appobject, uuid(9e66a294-4365-11d2-a997-00c04fa37ddb)]
    coclass CFoo { interface ICustom; };
}

-- ATL IMPLEMENTATION--
#include <idl.header.h>
#include <atlbase.h>

class ATL_NO_VTABLE CFooImpl : public ICustom,
    public ATL::CComObjectRootEx<CComMultiThreadModel>
{
    public:BEGIN_COM_MAP(CFooImpl)
    COM_INTERFACE_ENTRY(ICustom)
    END_COM_MAP()
};
```

#### <a name="ambiguous-conditional-operator-arguments"></a>Argumentos do operador condicional ambíguo

Em versões do compilador antes da versão 15,3 2017 de Visual Studio, o compilador aceita argumentos para o operador condicional (ou o operador ternário) `?:` que são consideradas ambíguo por padrão. Em **/ permissivo-** modo, o compilador emite agora um ou mais diagnósticos nos casos em que é compilado sem o diagnóstico em versões anteriores.

Erros comuns que podem resultar dessa alteração incluem:

- Erro C2593: 'operator'? é ambíguo

- Erro C2679: binário '?': Nenhum operador encontrado que receba um operando à direita do tipo 'B' (ou não há conversão aceitável)

- Erro C2678: binário '?': Nenhum operador encontrado que receba um operando esquerdo do tipo 'A' (ou não há conversão aceitável)

- Erro C2446: ':': nenhuma conversão de 'B' para 'A'

Um padrão de código típico que pode causar esse problema é quando alguma classe C fornece um construtor não explícito de outro tipo T e um operador de conversão não explícita para o tipo T. Nesse caso, a conversão do 2º argumento para o tipo de dia 3 e a conversão do 3º argumento para o tipo do 2º são conversões válidas, que é ambíguo de acordo com o padrão.

```cpp
// Example 1: class that provides conversion to and initialization from some type T
struct A
{
    A(int);
    operator int() const;
};

extern bool cond;

A a(42);
// Accepted when /Zc:ternary or /permissive- is not used:
auto x = cond ? 7 : a; // A: permissive behavior prefers A(7) over (int)a
// Accepted always:
auto y = cond ? 7 : int(a);
auto z = cond ? A(7) : a;
```

Há uma exceção a esse padrão comum quando T representa um dos tipos de cadeia de caracteres terminada em nulo (por exemplo, `const char *`, `const char16_t *`, e assim por diante) e o argumento para `?:` é uma cadeia de caracteres literal do tipo correspondente. C++ 17 foi alterado semântica de C + + 14. Como resultado, o código no exemplo 2 é aceito em **/std:c + + 14** e rejeitados em **/std:c + + 17** quando **/Zc:ternary** ou **/permissive-**é usado.

```cpp
// Example 2: exception from the above
struct MyString
{
    MyString(const char* s = "") noexcept;  // from char*
    operator const char* () const noexcept; //   to char*
};

extern bool cond;

MyString s; 
// Using /std:c++14, /permissive- or /Zc:ternary behavior
// is to prefer MyString("A") over (const char*)s
// but under /std:c++17 this line causes error C2445:
auto x = cond ? "A" : s;
// You can use a static_cast to resolve the ambiguity:
auto y = cond ? "A" : static_cast<const char*>(s);
```

Outro caso em que você pode ver erros está em operadores condicionais com um argumento do tipo `void`. Neste caso, pode ser comum em macros de declaração.

```cpp
// Example 3: void arguments
void myassert(const char* text, const char* file, int line);
// Accepted when /Zc:ternary or /permissive- is not used:
#define ASSERT_A(ex) (void)((ex) ? 1 : myassert(#ex, __FILE__, __LINE__))
// Accepted always:
#define ASSERT_B(ex) (void)((ex) ? void() : myassert(#ex, __FILE__, __LINE__))
```

Você também pode ver erros no modelo metaprogramação, onde os tipos de resultado do operador condicional podem alterar em **/Zc:ternary** e **/ permissivo-**. Uma maneira de resolver esse problema é usar [std::remove_reference](../../standard-library/remove-reference-class.md) no tipo resultante.

```cpp
// Example 4: different result types 
extern bool cond;
extern int count;
char  a = 'A'; 
const char  b = 'B'; 
decltype(auto) x = cond ? a : b; // char without, const char& with /Zc:ternary 
const char (&z)[2] = count > 3 ? "A" : "B"; // const char* without /Zc:ternary 
```

#### <a name="two-phase-name-look-up-partial"></a>Pesquisar nome de duas fases (parcial)

Quando o **/ permissivo-** opção é definida no Visual Studio 2017 versão 15,3, o compilador analisa definições de modelo de função e de classe, identificando dependentes e independentes nomes usados em modelos conforme necessário para o nome de duas fases pesquisa. Nesta versão, a análise de dependência de nome só é executada. Nomes não dependentes que não sejam declarados no contexto de uma definição de modelo em particular, fazer com que uma mensagem de diagnóstico conforme exigido pelos padrões ISO C++. No entanto, a associação dos nomes de dependente não requerem o argumento dependentes pesquisar no contexto de definição não está pronto.

```cpp
// dependent base
struct B {
    void g();
};

template<typename T>
struct D : T {
    void f() {
        // The call to g was incorrectly allowed in VS2017:
        g();  // Now under /permissive-: C3861
        // Possible fixes:
        // this->g();
        // T::g();
    }
};

int main()
{
    D<B> d;
    d.f();
}
```

### <a name="windows-header-issues"></a>Problemas de cabeçalho do Windows

O **/ permissivo-** opção é muito estrita para versões do Windows Kits antes do SDK do Windows estão criadores de atualização (10.0.16299.0) ou a versão do Windows Driver Kit (WDK) 1709. É recomendável atualizar as versões mais recentes do Windows Kits para usar **/ permissivo-** em seu código de driver do Windows ou dispositivo.

Alguns arquivos de cabeçalho do SDK do Windows estão criadores de atualização (10.0.16299.0) ou o Windows Driver Kit (WDK) 1709, ainda tiverem problemas que os tornam incompatível com o uso de **/ permissivo-**. Para solucionar esses problemas, recomendamos que você restringir o uso desses cabeçalhos para somente os arquivos de código fonte que exigem e remover o **/ permissivo-** opção quando você compila esses arquivos de código fonte específica. Os problemas a seguir são específicos para o SDK do Windows estão criadores de atualização (10.0.16299.0):

#### <a name="issue-in-umqueryh"></a>Problema no um\Query.h

Ao usar o **/ permissivo-** opção de compilador, o `tagRESTRICTION` estrutura não compila devido ao membro case(RTOr) 'ou'.

```cpp
struct tagRESTRICTION
    {
    ULONG rt;
    ULONG weight;
    /* [switch_is][switch_type] */ union _URes
        {
        /* [case()] */ NODERESTRICTION ar;
        /* [case()] */ NODERESTRICTION or;  // error C2059: syntax error: '||'
        /* [case()] */ NODERESTRICTION pxr;
        /* [case()] */ VECTORRESTRICTION vr;
        /* [case()] */ NOTRESTRICTION nr;
        /* [case()] */ CONTENTRESTRICTION cr;
        /* [case()] */ NATLANGUAGERESTRICTION nlr;
        /* [case()] */ PROPERTYRESTRICTION pr;
        /* [default] */  /* Empty union arm */
        } res;
    };
```

Para resolver esse problema, compile arquivos que incluem Query.h sem o **/ permissivo-** opção.

#### <a name="issue-in-umcellularapioemh"></a>Problema no um\cellularapi_oem.h

Ao usar o **/ permissivo-** opção de compilador, a declaração de encaminhamento de `enum UICCDATASTOREACCESSMODE` faz com que um aviso:

```cpp
typedef enum UICCDATASTOREACCESSMODE UICCDATASTOREACCESSMODE; // C4471
```

A declaração de encaminhamento de enum sem escopo é uma extensão da Microsoft. Para resolver esse problema, compile arquivos que incluem cellularapi_oem.h sem o **/ permissivo-** opção ou use o [/wd](../../build/reference/compiler-option-warning-level.md) opção para aviso C4471 de silêncio.

#### <a name="issue-in-umomscripth"></a>Problema no um\omscript.h

Em C + + 03, uma conversão de um literal de cadeia de caracteres BSTR (que é um typedef para ' wchar_t *') é substituído, mas permitido. No C++ 11, a conversão não é mais permitida.

```cpp
virtual /* [id] */ HRESULT STDMETHODCALLTYPE setExpression(
    /* [in] */ __RPC__in BSTR propname,
    /* [in] */ __RPC__in BSTR expression,
    /* [in][defaultvalue] */ __RPC__in BSTR language = L"") = 0; // C2440
```

Para resolver esse problema, compile arquivos que incluem omscript.h sem o **/ permissivo-** opção ou use **/Zc:strictStrings-** em vez disso.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

Na versão do Visual Studio de 2017 15,5 e versões posteriores, use este procedimento:

1. Abra seu projeto **páginas de propriedade** caixa de diálogo.

1. Em **propriedades de configuração**, expanda o **C/C++** pasta e escolha o **idioma** página de propriedades.

1. Alterar o **modo de conformidade** valor da propriedade **Sim (/ permissivo-)**. Escolha **Okey** ou **aplicar** para salvar suas alterações.

Nas versões anteriores do Visual Studio 2017 versão 15,5, use este procedimento:

1. Abra seu projeto **páginas de propriedade** caixa de diálogo.

1. Em **propriedades de configuração**, expanda o **C/C++** pasta e escolha o **linha de comando** página de propriedades.

1. Insira o **/ permissivo-** opção de compilador no **opções adicionais** caixa. Escolha **Okey** ou **aplicar** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador](../../build/reference/compiler-options.md)   
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
