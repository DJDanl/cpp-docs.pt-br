---
title: -permissive - (conformidade com padrões) | Microsoft Docs
ms.date: 06/21/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /permissive
- VC.Project.VCCLCompilerTool.ConformanceMode
dev_langs:
- C++
helpviewer_keywords:
- /permissive compiler options [C++]
- -permissive compiler options [C++]
- Standards conformance compiler options
- permissive compiler options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1f2f0b1ca5351fbf2cfa2ab4b3233f8e709fae44
ms.sourcegitcommit: f7703076b850c717c33d72fb0755fbb2215c5ddc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/28/2018
ms.locfileid: "43131210"
---
# <a name="permissive--standards-conformance"></a>/permissive--(conformidade com padrões)

Especifique o modo de conformidade de padrões para o compilador. Use esta opção para ajudá-lo a identificar e corrigir problemas de conformidade em seu código, para torná-lo mais correto e mais portátil.

## <a name="syntax"></a>Sintaxe

> **/permissive-**

## <a name="remarks"></a>Comentários

Essa opção tem suporte no Visual Studio 2017 e posterior.

Você pode usar o **/permissive--** opção de compilador para especificar o comportamento do compilador em conformidade com os padrões. Esta opção desabilita permissivos comportamentos e configura o [/Zc](../../build/reference/zc-conformance.md) opções do compilador de conformidade estrita. No IDE, essa opção também torna o código IntelliSense mecanismo sublinhado não conformes.

Por padrão, o **/permissive--** opção é definida em novos projetos criados pelo Visual Studio 2017 versão 15.5 e posteriores. Ele não é definido por padrão em versões anteriores. Quando a opção for definida, o compilador gera erros de diagnóstico ou avisos quando construções de linguagem não padrão são detectados em seu código, incluindo alguns erros comuns em pré-C + + 11 código.

O **/permissive--** opção é compatível com quase todos os arquivos de cabeçalho de Kits do Windows mais recente, como o Software Development Kit (SDK) ou o Windows Driver Kit (WDK), a partir do SDK do Windows Fall Creators (10.0.16299.0). Versões mais antigas do SDK podem falhar ao compilar sob **/permissive--** para várias motivos de conformidade de código de origem. O compilador e remessa de SDKs em cronogramas de lançamento diferentes, portanto, há alguns problemas restantes. Para problemas de arquivo de cabeçalho específicos, consulte [problemas de cabeçalho do Windows](#windows-header-issues) abaixo.

O **/permissive--** conjuntos de opções de [/ZC: strictstrings](../../build/reference/zc-conformance.md) e [/ZC: rvaluecast](../../build/reference/zc-conformance.md) opções de comportamento em conformidade. Eles têm como padrão o comportamento de não conformes. Você pode passar específico **/Zc** opções após **/permissive--** na linha de comando para substituir esse comportamento.

Nas versões do início de compilador no Visual Studio 2017 versão 15.3, o **/permissive--** conjuntos de opções de [/ZC: ternary](../../build/reference/zc-ternary.md) opção. O compilador também implementa mais os requisitos para a pesquisa de nome em duas fases. Quando o **/permissive--** opção for definida, o compilador analisa as definições de modelo de função e de classe, identificando nomes dependentes e não dependente usados nos modelos. Nesta versão, a análise de dependência de nome só é executada.

Extensões específicas do ambiente e áreas de idioma que o padrão deixa a implementação não são afetadas por **/permissive--**. Por exemplo, específicos da Microsoft `__declspec`, convenção de chamada e palavras-chave e diretivas pragma específicos do compilador ou atributos de manipulação de exceção estruturada não são sinalizados pelo compilador **/permissive--** modo.

O **/permissive--** opção usa o suporte de conformidade na versão atual do compilador para determinar quais construções de linguagem são não conformes. A opção não determina se seu código está de acordo com uma versão específica do C++ padrão. Para habilitar a todo o suporte de compilador implementado para o padrão de rascunho mais recente, use o [/std:latest](../../build/reference/std-specify-language-standard-version.md) opção. Para restringir o suporte do compilador implementado atualmente c++17 standard, use o [/std: c + + 17](../../build/reference/std-specify-language-standard-version.md) opção. Para restringir o suporte do compilador para corresponder a mais de perto o padrão c++14, use o [/std: c + + 14](../../build/reference/std-specify-language-standard-version.md) opção, que é o padrão.

Não todas as c++11, c++14 ou c++17 em conformidade com os padrões de código é suportado pelo compilador Visual C++ no Visual Studio 2017. Dependendo da versão do Visual Studio, o **/permissive--** opção pode não detectar problemas em relação a alguns aspectos da pesquisa de nome em duas fases, uma referência não const para um temporário de associação, tratando de inicialização de cópia como init direto, permitindo que várias conversões definidas pelo usuário na inicialização ou tokens alternativos para os operadores lógicos e outras áreas de conformidade sem suporte. Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md). Para obter o máximo proveito do **/permissive--**, atualizar o Visual Studio para a versão mais recente.

### <a name="how-to-fix-your-code"></a>Como corrigir seu código

Aqui estão alguns exemplos de código que é detectado como não conformes quando você usa **/permissive--**, juntamente com maneiras sugeridas para corrigir os problemas.

#### <a name="use-default-as-an-identifier-in-native-code"></a>Usar o padrão como um identificador em código nativo

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

#### <a name="initialize-multiple-union-members-in-a-member-initializer"></a>Inicializar vários membros de união em um inicializador de membro

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

Nas versões do compilador antes do Visual Studio 2017 versão 15.3, o compilador aceita argumentos para o operador condicional (ou o operador ternário) `?:` que são considerados ambíguos pelo padrão. Na **/permissive--** modo, o compilador agora emitirá um ou mais diagnósticos nos casos em que é compilado sem o diagnóstico em versões anteriores.

Erros comuns que poderão incidir essa alteração incluem:

- Erro C2593: 'operator'? é ambíguo

- Erro C2679: binário '?': Nenhum operador encontrado que receba um operando à direita do tipo 'B' (ou não há nenhuma conversão aceitável)

- Erro C2678: binário '?': Nenhum operador encontrado que receba um operando esquerdo do tipo 'A' (ou não há nenhuma conversão aceitável)

- Erro C2446: ':': nenhuma conversão de 'B' para 'A'

Um padrão de código típico que pode causar esse problema é quando alguma classe C fornece um construtor não explícito de outro tipo T e um operador de conversão não explícita para o tipo T. Nesse caso, a conversão do argumento 2º para o tipo de dia 3 e a conversão do argumento 3ª para o tipo do 2º são conversões válidas, que é ambíguo de acordo com o padrão.

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

Há uma exceção a esse padrão comum quando T representa um dos tipos de cadeia de caracteres terminada em nulo (por exemplo, `const char *`, `const char16_t *`e assim por diante) e o argumento real para `?:` é uma cadeia de caracteres literal do tipo correspondente. C + + 17 alterou a semântica do C + + 14. Como resultado, o código no exemplo 2 é aceito em **/std:c++17 + + 14** e rejeitados sob **/std: c + + 17** quando **/ZC: ternary** ou **/permissive-** é usado.

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

Outro caso em que você poderá ver erros está em operadores condicionais com um argumento do tipo `void`. Nesse caso, pode ser comum em macros de declaração.

```cpp
// Example 3: void arguments
void myassert(const char* text, const char* file, int line);
// Accepted when /Zc:ternary or /permissive- is not used:
#define ASSERT_A(ex) (void)((ex) ? 1 : myassert(#ex, __FILE__, __LINE__))
// Accepted always:
#define ASSERT_B(ex) (void)((ex) ? void() : myassert(#ex, __FILE__, __LINE__))
```

Você também poderá ver erros no modelo metaprogramação, onde os tipos de resultado do operador condicional podem mudar em **/ZC: ternary** e **/permissive--**. É uma maneira de resolver esse problema é usar [std::remove_reference](../../standard-library/remove-reference-class.md) no tipo resultante.

```cpp
// Example 4: different result types
extern bool cond;
extern int count;
char  a = 'A';
const char  b = 'B';
decltype(auto) x = cond ? a : b; // char without, const char& with /Zc:ternary
const char (&z)[2] = count > 3 ? "A" : "B"; // const char* without /Zc:ternary
```

#### <a name="two-phase-name-look-up"></a>Pesquisar nome de duas fases

Quando o **/permissive--** opção for definida, o compilador analisa as definições de modelo de função e de classe, identificando nomes dependentes e não dependente usados nos modelos conforme necessário para a pesquisa de nome em duas fases. No Visual Studio 2017 versão 15.3, análise de dependência de nome é executada. Os nomes não dependentes que não são declarados no contexto de uma definição de modelo em particular, fazer com que uma mensagem de diagnóstico conforme exigido por padrões ISO do C++. No Visual Studio 2017 versão 15.7, associação de nomes não dependentes que exigem um argumento dependentes pesquisar no contexto de definição também é feita.

```cpp
// dependent base
struct B {
    void g() {}
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

Se você quiser o comportamento herdado para a pesquisa em duas fases, mas caso contrário, quer **/permissive--** comportamento, adicione o **/Zc:twoPhase-** opção.

### <a name="windows-header-issues"></a>Problemas de cabeçalho do Windows

O **/permissive--** opção é muito estrita para versões dos Kits do Windows antes do SDK do Windows Fall Creators Update (10.0.16299.0) ou a versão 1709 do Windows Driver Kit (WDK). É recomendável atualizar as versões mais recentes dos Kits do Windows para usar **/permissive--** em seu código de driver do Windows ou dispositivo.

Alguns arquivos de cabeçalho em abril o Windows SDK da atualização de 2018 (10.0.17134.0), o SDK do Windows Fall Creators Update (10.0.16299.0) ou o Windows Driver Kit (WDK) 1709, ainda tiverem problemas que torná-los incompatíveis com o uso de **/permissive-**. Para contornar esses problemas, recomendamos que você restringir o uso desses cabeçalhos somente os arquivos de código fonte que necessitam deles e remover as **/permissive--** opção quando você compila os arquivos de código fonte específica.

Esses cabeçalhos de WinRT WRL lançados o Windows de abril de 2018 SDK da atualização (10.0.17134.0) não são limpas com **/permissive--**. Para contornar esses problemas, não use **/permissive--**, ou use **/permissive--** com **/Zc:twoPhase-** ao trabalhar com esses cabeçalhos:

- Problemas no winrt/wrl/async.h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(483): error C3861: 'TraceDelegateAssigned': identifier not found
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(491): error C3861: 'CheckValidStateForDelegateCall': identifier not found
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(509): error C3861: 'TraceProgressNotificationStart': identifier not found
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(513): error C3861: 'TraceProgressNotificationComplete': identifier not found
   ```

- Problema no winrt/wrl/implements.h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\winrt\wrl\implements.h(2086): error C2039: 'SetStrongReference': is not a member of 'Microsoft::WRL::Details::WeakReferenceImpl'
   ```

Esses cabeçalhos de modo de usuário lançados o Windows de abril de 2018 SDK da atualização (10.0.17134.0) não são limpas com **/permissive--**. Para contornar esses problemas, não use **/permissive--** ao trabalhar com esses cabeçalhos:

- Problemas no um/Tune.h

   ```Output
   C:\ProgramFiles(x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(139): error C3861: 'Release': identifier not found
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(559): error C3861: 'Release': identifier not found
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(1240): error C3861: 'Release': identifier not found
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(1240): note: 'Release': function declaration must be available as none of the arguments depend on a template parameter
   ```

- Problema no um/spddkhlp.h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\spddkhlp.h(759): error C3861: 'pNode': identifier not found
   ```

- Problemas no um/refptrco.h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\refptrco.h(179): error C2760: syntax error: unexpected token 'identifier', expected 'type specifier'
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\refptrco.h(342): error C2760: syntax error: unexpected token 'identifier', expected 'type specifier'
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\refptrco.h(395): error C2760: syntax error: unexpected token 'identifier', expected 'type specifier'
   ```

Esses problemas são específicos aos cabeçalhos de modo de usuário em que o SDK do Windows Fall Creators Update (10.0.16299.0):

- Problema no um/Query.h

   Ao usar o **/permissive--** opção de compilador, o `tagRESTRICTION` estrutura não compila devido ao membro case(RTOr) 'ou'.

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

   Para resolver esse problema, compile os arquivos que incluem Query.h sem o **/permissive--** opção.

- Problema no um/cellularapi_oem.h

   Ao usar o **/permissive--** opção de compilador, a declaração de encaminhamento de `enum UICCDATASTOREACCESSMODE` faz com que um aviso:

   ```cpp
   typedef enum UICCDATASTOREACCESSMODE UICCDATASTOREACCESSMODE; // C4471
   ```

   A declaração de encaminhamento de enum sem escopo é uma extensão da Microsoft. Para resolver esse problema, compile os arquivos que incluem cellularapi_oem.h sem o **/permissive--** opção ou usar o [/wd](../../build/reference/compiler-option-warning-level.md) opção para silenciar aviso C4471.

- Problema no um/omscript.h

   No c++03, uma conversão de um literal de cadeia de caracteres BSTR (que é um typedef para ' wchar_t *') foi preterido mas permitido. No c++11, a conversão não é mais permitida.

   ```cpp
   virtual /* [id] */ HRESULT STDMETHODCALLTYPE setExpression(
       /* [in] */ __RPC__in BSTR propname,
       /* [in] */ __RPC__in BSTR expression,
       /* [in][defaultvalue] */ __RPC__in BSTR language = L"") = 0; // C2440
   ```

   Para resolver esse problema, compile os arquivos que incluem omscript.h sem o **/permissive--** opção ou use **/Zc:strictStrings-** em vez disso.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

No Visual Studio 2017 versão 15.5 e versões posteriores, use este procedimento:

1. Abra seu projeto **páginas de propriedade** caixa de diálogo.

1. Selecione o **propriedades de configuração** > **C/C++** > **idioma** página de propriedades.

1. Alterar o **modo de conformidade** valor da propriedade **Sim (/ permissivo-)**. Escolher **Okey** ou **aplicar** para salvar suas alterações.

Nas versões anteriores do Visual Studio 2017 versão 15.5, use este procedimento:

1. Abra seu projeto **páginas de propriedade** caixa de diálogo.

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Insira o **/permissive--** opção de compilador na **opções adicionais** caixa. Escolher **Okey** ou **aplicar** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

- [Opções do Compilador](../../build/reference/compiler-options.md)
- [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
