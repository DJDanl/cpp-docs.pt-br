---
title: /permissive- (conformidade com padrões)
ms.date: 03/08/2019
f1_keywords:
- /permissive
- VC.Project.VCCLCompilerTool.ConformanceMode
helpviewer_keywords:
- /permissive compiler options [C++]
- -permissive compiler options [C++]
- Standards conformance compiler options
- permissive compiler options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
ms.openlocfilehash: aca0fbc6a2ca36ceae26ba060b5bf92fea79c32c
ms.sourcegitcommit: fd0f8839da5c6a3663798a47c6b0bb6e63b518bd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2019
ms.locfileid: "70273734"
---
# <a name="permissive--standards-conformance"></a>/permissive- (conformidade com padrões)

Especifique o modo de conformidade de padrões para o compilador. Use esta opção para ajudá-lo a identificar e corrigir problemas de conformidade em seu código, para torná-los mais corretos e mais portáteis.

## <a name="syntax"></a>Sintaxe

> **/permissive-**

## <a name="remarks"></a>Comentários

Essa opção tem suporte no Visual Studio 2017 e posterior.

Você pode usar a opção de compilador **/permissive-** para especificar o comportamento de compilador de conformidade com padrões. Essa opção desabilita comportamentos permissivos e define as opções de compilador [/Zc](zc-conformance.md) para conformidade estrita. No IDE, essa opção também faz com que o mecanismo do IntelliSense sublinhado código não compatível.

Por padrão, a opção **/permissive-** é definida em novos projetos criados pelo Visual Studio 2017 versão 15,5 e versões posteriores. Ele não é definido por padrão em versões anteriores. Quando a opção é definida, o compilador gera erros de diagnóstico ou avisos quando construções de linguagem não padrão são detectadas em seu código, incluindo alguns bugs comuns no código pré-C + + 11.

A opção **/permissive-** é compatível com quase todos os arquivos de cabeçalho dos kits mais recentes do Windows, como o Software Development Kit (SDK) ou o Windows Driver Kit (WDK), a partir do SDK do Windows Outono Creators (10.0.16299.0). Versões mais antigas do SDK podem falhar na compilação em **/permissive-** para vários motivos de conformidade do código-fonte. O compilador e os SDKs são fornecidos em cronogramas de liberação diferentes, portanto, há alguns problemas restantes. Para problemas de arquivo de cabeçalho específicos, consulte os [problemas de cabeçalho do Windows](#windows-header-issues) abaixo.

A opção **/permissive-** define as opções [/Zc: referencebinding](zc-referencebinding-enforce-reference-binding-rules.md), [/Zc: strictStrings](zc-strictstrings-disable-string-literal-type-conversion.md)e [/Zc: rvalueCast](zc-rvaluecast-enforce-type-conversion-rules.md) para a conformidade do comportamento. Essas opções assumem como padrão o comportamento não compatível. Você pode passar opções **/Zc** específicas após **/permissive-** na linha de comando para substituir esse comportamento.

Em versões do compilador que começam no Visual Studio 2017 versão 15,3, a opção **/permissive-** define a opção [/Zc: ternário](zc-ternary.md) . O compilador também implementa mais dos requisitos para a pesquisa de nome de duas fases. Quando a opção **/permissive-** é definida, o compilador analisa as definições de modelo de função e classe e identifica nomes dependentes e não dependentes usados nos modelos. Nesta versão, apenas a análise de dependência de nome é executada.

As extensões específicas do ambiente e as áreas de linguagem que o padrão deixa para a implementação não são afetadas pelo **/permissive-** . Por exemplo, as palavras-chave `__declspec`específicas da Microsoft, de Convenção de chamada e manipulação de exceção estruturada e as diretivas ou atributos pragma específicos do compilador não são sinalizadas pelo compilador no modo **/permissive-** .

A opção **/permissive-** usa o suporte de conformidade na versão do compilador atual para determinar quais construções de linguagem não estão em conformidade. A opção não determina se o código está em conformidade com uma versão específica do C++ padrão. Para habilitar todo o suporte do compilador implementado para o padrão de rascunho mais recente, use a opção [/std: Latest](std-specify-language-standard-version.md) . Para restringir o suporte do compilador ao padrão C++ 17 atualmente implementado, use a opção [/std: c++ 17](std-specify-language-standard-version.md) . Para restringir o suporte do compilador para corresponder mais próximo ao padrão C++ 14, use a opção [/std: c++ 14](std-specify-language-standard-version.md) , que é o padrão.

Nem todos os padrões do C++ 11, do C++ 14 ou do C++ 17 – a conformidade do código é compatível com o compilador MSVC em todas as versões do Visual Studio 2017. Dependendo da versão do Visual Studio, a opção **/permissive-** pode não detectar problemas relacionados a alguns aspectos da pesquisa de nome de duas fases, associando uma referência não const a um temporário, tratando a inicialização de cópia como inicialização direta, permitindo que vários usuários definidos pelo usuário conversões na inicialização, ou tokens alternativos para operadores lógicos e outras áreas de conformidade sem suporte. Para obter mais informações sobre problemas de conformidade C++no Visual, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md). Para obter o máximo do **/permissive-** , atualize o Visual Studio para a versão mais recente.

### <a name="how-to-fix-your-code"></a>Como corrigir seu código

Aqui estão alguns exemplos de código que é detectado como não compatível quando você usa o **/permissive-** , juntamente com formas sugeridas para corrigir os problemas.

#### <a name="use-default-as-an-identifier-in-native-code"></a>Usar o padrão como um identificador no código nativo

```cpp
void func(int default); // Error C2321: 'default' is a keyword, and
                        // cannot be used in this context
```

#### <a name="look-up-members-in-dependent-base"></a>Pesquisar Membros na base dependente

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

#### <a name="initialize-multiple-union-members-in-a-member-initializer"></a>Inicializar vários membros de União em um inicializador de membro

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

#### <a name="use-scoped-enums-in-array-bounds"></a>Usar enumerações com escopo em limites de matriz

```cpp
enum class Color {
    Red, Green, Blue
};

int data[Color::Blue]; // error C3411: 'Color' is not valid as the size
                       // of an array as it is not an integer type.
                       // Cast to type size_t or int to fix.
```

#### <a name="use-for-each-in-native-code"></a>Usar para cada um em código nativo

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

#### <a name="ambiguous-conditional-operator-arguments"></a>Argumentos de operador condicional ambíguos

Em versões do compilador antes do Visual Studio 2017 versão 15,3, o compilador aceitou os argumentos para o operador condicional (ou operador ternário `?:` ) que são considerados ambíguos pelo padrão. No modo **/permissive-** , o compilador agora emite um ou mais diagnósticos em casos que são compilados sem diagnóstico em versões anteriores.

Os erros comuns que podem resultar dessa alteração incluem:

- erro C2593: ' operator? ' é ambíguo

- erro C2679: Binary '? ': nenhum operador encontrado que recebe um operando de lado direito do tipo ' B ' (ou não há conversão aceitável)

- erro C2678: Binary '? ': nenhum operador encontrado que recebe um operando de lado esquerdo do tipo ' A ' (ou não há conversão aceitável)

- erro C2446: ': ': nenhuma conversão de ' B ' para ' A '

Um padrão de código típico que pode causar esse problema é quando alguma classe C fornece um construtor não explícito de outro tipo T e um operador de conversão não explícita para o tipo T. Nesse caso, a conversão do segundo argumento para o tipo do terceiro argumento, e a conversão do terceiro argumento para o tipo do segundo argumento, são conversões válidas. Como ambos são válidos, eles são ambíguos de acordo com o padrão.

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

Há uma exceção importante para esse padrão comum quando T representa um dos tipos de cadeia de caracteres terminadas em nulo (por `const char *`exemplo `const char16_t *`,, e assim por diante) `?:` e o argumento real é um literal de cadeia de caracteres do tipo correspondente. O c++ 17 mudou a semântica do C++ 14. Como resultado, o código no exemplo 2 é aceito em **/std: c++ 14** e rejeitado em **/std: c++ 17** quando **/Zc: ternário** ou **/permissive-** é usado.

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

Outro caso em que você pode ver erros está em operadores condicionais com um argumento `void`do tipo. Esse caso pode ser comum em macros semelhantes a ASSERT.

```cpp
// Example 3: void arguments
void myassert(const char* text, const char* file, int line);
// Accepted when /Zc:ternary or /permissive- is not used:
#define ASSERT_A(ex) (void)((ex) ? 1 : myassert(#ex, __FILE__, __LINE__))
// Accepted always:
#define ASSERT_B(ex) (void)((ex) ? void() : myassert(#ex, __FILE__, __LINE__))
```

Você também pode ver erros na metaprogramação de modelo, em que os tipos de resultados de operador condicional podem ser alterados em **/Zc: ternário** e **/permissive-** . Uma maneira de resolver esse problema é usar [std:: remove_reference](../../standard-library/remove-reference-class.md) no tipo resultante.

```cpp
// Example 4: different result types
extern bool cond;
extern int count;
char  a = 'A';
const char  b = 'B';
decltype(auto) x = cond ? a : b; // char without, const char& with /Zc:ternary
const char (&z)[2] = count > 3 ? "A" : "B"; // const char* without /Zc:ternary
```

#### <a name="two-phase-name-look-up"></a>Pesquisa de nome de duas fases

Quando a opção **/permissive-** é definida, o compilador analisa as definições de modelo de função e classe, identificando nomes dependentes e não dependentes usados em modelos, conforme necessário para a pesquisa de nome de duas fases. No Visual Studio 2017 versão 15,3, a análise de dependência de nome é executada. Em particular, nomes não dependentes que não são declarados no contexto de uma definição de modelo causam uma mensagem de diagnóstico, conforme C++ exigido pelos padrões ISO. No Visual Studio 2017 versão 15,7, a associação de nomes não dependentes que exigem a pesquisa dependente de argumento no contexto de definição também é feita.

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

Se você quiser um comportamento herdado para pesquisa de duas fases, mas, caso contrário, quiser o comportamento de **/permissive-** , adicione a opção **/Zc: twoPhase-** .

### <a name="windows-header-issues"></a>Problemas de cabeçalho do Windows

A opção **/permissive-** é muito estrita para versões dos kits do Windows antes do Windows Outono Creators Update SDK (10.0.16299.0) ou do Windows Driver Kit (WDK) versão 1709. Recomendamos que você atualize para as versões mais recentes dos kits do Windows para usar o **/permissive-** em seu código de driver de dispositivo ou Windows.

Alguns arquivos de cabeçalho no SDK de atualização do Windows de abril de 2018 (10.0.17134.0), o 10.0.16299.0 (Windows Outono Creators Update SDK) ou o WDK (Windows Driver Kit) 1709, ainda têm problemas que os tornam incompatíveis com o uso de **/permissive-** . Para solucionar esses problemas, recomendamos restringir o uso desses cabeçalhos apenas aos arquivos de código-fonte que os exigem e remover a opção **/permissive-** ao compilar esses arquivos de código-fonte específicos.

Esses cabeçalhos do WRL do WinRT lançados no SDK de atualização do Windows de abril de 2018 (10.0.17134.0) não estão limpos com o **/permissive-** . Para solucionar esses problemas, não use **/permissive-** ou use **/permissive-** com **/Zc: twoPhase-** ao trabalhar com esses cabeçalhos:

- Problemas no winrt/WRL/Async. h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(483): error C3861: 'TraceDelegateAssigned': identifier not found
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(491): error C3861: 'CheckValidStateForDelegateCall': identifier not found
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(509): error C3861: 'TraceProgressNotificationStart': identifier not found
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(513): error C3861: 'TraceProgressNotificationComplete': identifier not found
   ```

- Problema em winrt/WRL/Implements. h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\winrt\wrl\implements.h(2086): error C2039: 'SetStrongReference': is not a member of 'Microsoft::WRL::Details::WeakReferenceImpl'
   ```

Esses cabeçalhos de modo de usuário lançados no SDK de atualização do Windows de abril de 2018 (10.0.17134.0) não estão limpos com **/permissive-** . Para contornar esses problemas, não use **/permissive-** ao trabalhar com estes cabeçalhos:

- Problemas em um/ajuste. h

   ```Output
   C:\ProgramFiles(x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(139): error C3861: 'Release': identifier not found
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(559): error C3861: 'Release': identifier not found
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(1240): error C3861: 'Release': identifier not found
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(1240): note: 'Release': function declaration must be available as none of the arguments depend on a template parameter
   ```

- Problema em um/spddkhlp. h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\spddkhlp.h(759): error C3861: 'pNode': identifier not found
   ```

- Problemas em um/refptrco. h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\refptrco.h(179): error C2760: syntax error: unexpected token 'identifier', expected 'type specifier'
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\refptrco.h(342): error C2760: syntax error: unexpected token 'identifier', expected 'type specifier'
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\refptrco.h(395): error C2760: syntax error: unexpected token 'identifier', expected 'type specifier'
   ```

Esses problemas são específicos para cabeçalhos de modo de usuário no SDK de atualização do Windows Outono Creators (10.0.16299.0):

- Problema em um/Query. h

   Ao usar a opção de compilador **/permissive-** , `tagRESTRICTION` a estrutura não é compilada devido ao membro de caso (RTOr) ' ou '.

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

   Para resolver esse problema, compile os arquivos que incluem Query. h sem a opção **/permissive-** .

- Problema em um/cellularapi_oem. h

   Ao usar a opção de compilador **/permissive-** , a declaração de `enum UICCDATASTOREACCESSMODE` encaminhamento causa um aviso:

   ```cpp
   typedef enum UICCDATASTOREACCESSMODE UICCDATASTOREACCESSMODE; // C4471
   ```

   A declaração de encaminhamento de enumeração sem escopo é uma extensão da Microsoft. Para resolver esse problema, compile os arquivos que incluem cellularapi_oem. h sem a opção **/permissive-** ou use a opção [/WD](compiler-option-warning-level.md) para silenciar o aviso C4471.

- Problema em um/omscript. h

   No C++ 03, uma conversão de um literal de cadeia de caracteres em BSTR (que é um typedef para ' wchar_t * ') é preterida, mas permitida. No C++ 11, a conversão não é mais permitida.

   ```cpp
   virtual /* [id] */ HRESULT STDMETHODCALLTYPE setExpression(
       /* [in] */ __RPC__in BSTR propname,
       /* [in] */ __RPC__in BSTR expression,
       /* [in][defaultvalue] */ __RPC__in BSTR language = L"") = 0; // C2440
   ```

   Para resolver esse problema, compile os arquivos que incluem omscript. h sem a opção **/permissive-** ou use **/Zc: strictStrings-** em vez disso.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

No Visual Studio 2017 versão 15,5 e versões posteriores, use este procedimento:

1. Abra a caixa de diálogo **páginas de propriedades** do projeto.

1. Selecione a página de **Propriedades** >  > configuração**C/C++** **idioma** .

1. Altere o valor da propriedade **modo de conformidade** para **Sim (/permissive-)** . Escolha **OK** ou **aplicar** para salvar suas alterações.

Em versões anteriores ao Visual Studio 2017 versão 15,5, use este procedimento:

1. Abra a caixa de diálogo **páginas de propriedades** do projeto.

1. Selecione a página de propriedades **Propriedades da Configuração** > **C/C++**  > **Linha de Comando**.

1. Insira a opção do compilador **/permissive-** na caixa **Opções adicionais** . Escolha **OK** ou **aplicar** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
