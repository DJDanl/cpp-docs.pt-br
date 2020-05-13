---
title: /permissive- (conformidade com padrões)
description: Guia de referência para a opção de compilador Microsoft C++ /permissivo- (Conformidade de padrões).
ms.date: 04/14/2020
f1_keywords:
- /permissive
- VC.Project.VCCLCompilerTool.ConformanceMode
helpviewer_keywords:
- /permissive compiler options [C++]
- -permissive compiler options [C++]
- Standards conformance compiler options
- permissive compiler options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
ms.openlocfilehash: 695f84e64f07128ac7744dc99e736f2a71ab3e79
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337411"
---
# <a name="permissive--standards-conformance"></a>/permissive- (conformidade com padrões)

Especifique o modo de conformidade dos padrões para o compilador. Use esta opção para ajudá-lo a identificar e corrigir problemas de conformidade em seu código, para torná-lo mais correto e mais portátil.

## <a name="syntax"></a>Sintaxe

> **/permissivo-**

## <a name="remarks"></a>Comentários

Essa opção é suportada no Visual Studio 2017 e posteriormente.

Você pode usar a opção **/permissivo-compilador** para especificar o comportamento do compilador em conformidade com os padrões. Esta opção desativa comportamentos permissivos e define as opções do compilador [/Zc](zc-conformance.md) para conformidade estrita. No IDE, essa opção também faz com que o mecanismo IntelliSense sublinhe código não conforme.

Por padrão, a opção **/permissiva** é definida em novos projetos criados pelo Visual Studio 2017 versão 15.5 e versões posteriores. Não é definido por padrão em versões anteriores. Quando a opção é definida, o compilador gera erros de diagnóstico ou avisos quando construções de linguagem não padronizadas são detectadas em seu código, incluindo alguns bugs comuns no código pré-C++11.

A opção **/permissiva** é compatível com quase todos os arquivos de cabeçalho dos mais recentes Kits windows, como o Kit de Desenvolvimento de Software (SDK) ou o Windows Driver Kit (WDK), começando pelo Windows Fall Creators SDK (10.0.16299.0). As versões mais antigas do SDK podem não ser compiladas sob **/permissiva-** por várias razões de conformidade de código-fonte. O compilador e os SDKs são enviados em diferentes cronogramas de lançamento, portanto, há alguns problemas restantes. Para problemas específicos de arquivo de cabeçalho, consulte [problemas de cabeçalho do Windows](#windows-header-issues) abaixo.

A opção **/permissiva define** as opções [/Zc:referenceBinding](zc-referencebinding-enforce-reference-binding-rules.md), [/Zc:strictStrings](zc-strictstrings-disable-string-literal-type-conversion.md)e [/Zc:rvalueCast](zc-rvaluecast-enforce-type-conversion-rules.md) opções para comportamento em conformidade. Essas opções são padrão para comportamentos não conformes. Você pode passar opções específicas **/Zc** depois **/permissiva-** na linha de comando para substituir esse comportamento.

Nas versões do compilador a partir da versão 15.3 do Visual Studio 2017, a opção **/permissivo** define a opção [/Zc:ternário.](zc-ternary.md) O compilador também implementa mais dos requisitos para a pesquisa de nomes em duas fases. Quando a opção **/permissiva** é definida, o compilador analisa definições de função e modelo de classe e identifica nomes dependentes e não dependentes usados nos modelos. Nesta versão, é realizada apenas a análise de dependência de nomes.

Extensões específicas do ambiente e áreas de linguagem que a norma deixa até a implementação não são afetadas por **/permissivos-**. Por exemplo, a `__declspec`convenção específica da Microsoft, a convenção de chamadas e a exceção estruturada que manuseia palavras-chave e as diretivas ou atributos pragma específicos do compilador não são sinalizadas pelo compilador no modo **/permissivo.**

A opção **/permissiva** usa o suporte de conformidade na versão atual do compilador para determinar quais construções de idioma não estão em conformidade. A opção não determina se seu código está de acordo com uma versão específica do padrão C++. Para habilitar todo o suporte ao compilador implementado para o padrão de rascunho mais recente, use a opção [/std:latest.](std-specify-language-standard-version.md) Para restringir o suporte ao compilador ao padrão C++17 atualmente implementado, use a opção [/std:c++17.](std-specify-language-standard-version.md) Para restringir o suporte ao compilador para corresponder mais de perto ao padrão C++14, use a opção [/std:c++14,](std-specify-language-standard-version.md) que é o padrão.

Nem todos os códigos c++11, C++14 ou C++17 são suportados pelo compilador MSVC em todas as versões do Visual Studio 2017. Dependendo da versão do Visual Studio, a opção **/permissiva** pode não detectar problemas em relação a alguns aspectos da busca de nomes em duas fases, vinculando uma referência não const a um init temporário, tratando a cópia como entrada direta, permitindo várias conversões definidas pelo usuário na inicialização, ou tokens alternativos para operadores lógicos e outras áreas de conformidade não suportadas. Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [Comportamento Não Padrão](../../cpp/nonstandard-behavior.md). Para obter o máximo de **/permissivo-**, atualize o Visual Studio para a versão mais recente.

### <a name="how-to-fix-your-code"></a>Como corrigir seu código

Aqui estão alguns exemplos de código que é detectado como não-conforme quando você usa **/permissivo-**, juntamente com maneiras sugeridas de corrigir os problemas.

#### <a name="use-default-as-an-identifier-in-native-code"></a>Use o padrão como um identificador no código nativo

```cpp
void func(int default); // Error C2321: 'default' is a keyword, and
                        // cannot be used in this context
```

#### <a name="look-up-members-in-dependent-base"></a>Procure membros na base dependente

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

#### <a name="use-of-qualified-names-in-member-declarations"></a>Uso de nomes qualificados em declarações de membros

```cpp
struct A {
    void A::f() { } // error C4596: illegal qualified name in member
                    // declaration.
                    // Remove redundant 'A::' to fix.
};
```

#### <a name="initialize-multiple-union-members-in-a-member-initializer"></a>Inicialize vários membros do sindicato em um inicializador de membros

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

#### <a name="hidden-friend-name-lookup-rules"></a>Regras ocultas de procuração de nome de amigo

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
    f(p); // Hidden friend now found via argument-dependent lookup.
}
```

#### <a name="use-scoped-enums-in-array-bounds"></a>Use enums escoped em limites de matriz

```cpp
enum class Color {
    Red, Green, Blue
};

int data[Color::Blue]; // error C3411: 'Color' is not valid as the size
                       // of an array as it is not an integer type.
                       // Cast to type size_t or int to fix.
```

#### <a name="use-for-each-in-native-code"></a>Use para cada um em código nativo

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

#### <a name="ambiguous-conditional-operator-arguments"></a>Argumentos ambíguos do operador condicional

Nas versões do compilador antes do Visual Studio 2017 versão 15.3, o compilador aceitou `?:` argumentos para o operador condicional (ou operador ternário) que são considerados ambíguos pela Norma. No modo **/permissivo,** o compilador agora emite um ou mais diagnósticos em casos que compilados sem diagnósticos em versões anteriores.

Os erros comuns que podem resultar dessa alteração incluem:

- erro C2593: 'operador ?' é ambíguo

- erro C2679: binário '?': nenhum operador encontrou que toma um opere à direita do tipo 'B' (ou não há conversão aceitável)

- erro C2678: binário '?': nenhum operador encontrou que pega um operand esquerdo do tipo 'A' (ou não há conversão aceitável)

- erro C2446: ':': sem conversão de 'B' para 'A'

Um padrão de código típico que pode causar esse problema é quando alguns da classe C fornecem um construtor não explícito de outro tipo T e um operador de conversão não explícito para o tipo T. Neste caso, tanto a conversão do segundo argumento para o tipo do terceiro argumento, quanto a conversão do terceiro argumento para o tipo do segundo argumento, são conversões válidas. Como ambos são válidos, é ambíguo de acordo com o padrão.

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

Há uma exceção importante a este padrão comum quando T representa um dos `const char *` `const char16_t *`tipos de strings terminadas nulamente (por exemplo, , e assim por diante) e o argumento real é `?:` uma seqüência literal do tipo correspondente. C++17 mudou a semântica de C++14. Como resultado, o código no exemplo 2 é aceito em **/std:c++14** e rejeitado em **/std:c++17** quando **/Zc:ternary** ou **/permissivo-** é usado.

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

Outro caso em que você pode ver erros é `void`em operadores condicionais com um argumento de tipo . Este caso pode ser comum em macros semelhantes ao ASSERT.

```cpp
// Example 3: void arguments
void myassert(const char* text, const char* file, int line);
// Accepted when /Zc:ternary or /permissive- is not used:
#define ASSERT_A(ex) (void)((ex) ? 1 : myassert(#ex, __FILE__, __LINE__))
// Accepted always:
#define ASSERT_B(ex) (void)((ex) ? void() : myassert(#ex, __FILE__, __LINE__))
```

Você também pode ver erros na metaprogramação do modelo, onde os tipos de resultados do operador condicional podem ser alterantes em **/Zc:ternário** e **/permissivo-**. Uma maneira de resolver esse problema é usar [o std::remove_reference](../../standard-library/remove-reference-class.md) no tipo resultante.

```cpp
// Example 4: different result types
extern bool cond;
extern int count;
char  a = 'A';
const char  b = 'B';
decltype(auto) x = cond ? a : b; // char without, const char& with /Zc:ternary
const char (&z)[2] = count > 3 ? "A" : "B"; // const char* without /Zc:ternary
```

#### <a name="two-phase-name-look-up"></a>Look-up de nomes em duas fases

Quando a opção **/permissiva** é definida, o compilador analisa definições de função e modelo de classe, identificando nomes dependentes e não dependentes usados em modelos conforme necessário para a busca de nomes de duas fases. No Visual Studio 2017 versão 15.3, a análise de dependência de nomes é realizada. Em particular, nomes não dependentes que não são declarados no contexto de uma definição de modelo causam uma mensagem de diagnóstico conforme exigido pelas normas ISO C++. No Visual Studio 2017 versão 15.7, a vinculação de nomes não dependentes que requerem pesquisa dependente de argumentos no contexto de definição também é feita.

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

Se você quiser comportamento legado para uma busca em duas fases, mas de outra forma quiser **comportamento /permissivo,** adicione a opção **/Zc:twoPhase-** .

### <a name="windows-header-issues"></a>Problemas de cabeçalho do Windows

A opção **/permissiva** é muito rigorosa para versões dos Kits do Windows antes do Windows Fall Creators Update SDK (10.0.16299.0), ou do Windows Driver Kit (WDK) versão 1709. Recomendamos que você atualize para as versões mais recentes dos Kits do Windows, a fim de usar **/permissivo-** em seu Código de driver windows ou dispositivo.

Certos arquivos de cabeçalho no Windows April 2018 Update SDK (10.0.17134.0), o Windows Fall Creators Update SDK (10.0.16299.0), ou o Windows Driver Kit (WDK) 1709, ainda têm problemas que os tornam incompatíveis com o uso de **/permissivo-**. Para contornar esses problemas, recomendamos que você restrinja o uso desses cabeçalhos apenas aos arquivos de código-fonte que os requerem e remova a opção **/permissiva quando** você compila esses arquivos de código-fonte específicos.

Estes cabeçalhos WinRT WRL lançados no Windows April 2018 Update SDK (10.0.17134.0) não são limpos com **/permissivo-**. Para contornar esses problemas, não use **/permissivo,** ou use **/permissivo-** com **/Zc:twoPhase-** quando você trabalha com esses cabeçalhos:

- Problemas em winrt/wrl/async.h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(483): error C3861: 'TraceDelegateAssigned': identifier not found
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(491): error C3861: 'CheckValidStateForDelegateCall': identifier not found
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(509): error C3861: 'TraceProgressNotificationStart': identifier not found
   C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt\wrl\async.h(513): error C3861: 'TraceProgressNotificationComplete': identifier not found
   ```

- Problema em winrt/wrl/implements.h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\winrt\wrl\implements.h(2086): error C2039: 'SetStrongReference': is not a member of 'Microsoft::WRL::Details::WeakReferenceImpl'
   ```

Estes cabeçalhos do Modo de Usuário lançados no Windows April 2018 Update SDK (10.0.17134.0) não são limpos com **/permissivo-**. Para contornar esses problemas, não use **/permissivo-** ao trabalhar com esses cabeçalhos:

- Problemas em um/Tune.h

   ```Output
   C:\ProgramFiles(x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(139): error C3861: 'Release': identifier not found
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(559): error C3861: 'Release': identifier not found
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(1240): error C3861: 'Release': identifier not found
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\tune.h(1240): note: 'Release': function declaration must be available as none of the arguments depend on a template parameter
   ```

- Problema em um/spddkhlp.h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\spddkhlp.h(759): error C3861: 'pNode': identifier not found
   ```

- Problemas em um/refptrco.h

   ```Output
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\refptrco.h(179): error C2760: syntax error: unexpected token 'identifier', expected 'type specifier'
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\refptrco.h(342): error C2760: syntax error: unexpected token 'identifier', expected 'type specifier'
   C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um\refptrco.h(395): error C2760: syntax error: unexpected token 'identifier', expected 'type specifier'
   ```

Esses problemas são específicos para cabeçalhos do modo de usuário no Windows Fall Creators Update SDK (10.0.16299.0):

- Problema em um/Query.h

   Ao usar o interruptor **/permissivo-compilador,** a `tagRESTRICTION` estrutura não compila por causa do membro 'ou' do membro do caso (RTOr).

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

   Para resolver esse problema, compile arquivos que incluem Query.h sem a opção **/permissivo.**

- Problema em um/cellularapi_oem.h

   Ao usar o interruptor **/permissivo-compilador,** a `enum UICCDATASTOREACCESSMODE` declaração de encaminhamento causa um aviso:

   ```cpp
   typedef enum UICCDATASTOREACCESSMODE UICCDATASTOREACCESSMODE; // C4471
   ```

   A declaração de enum não escopoé uma extensão da Microsoft. Para resolver esse problema, compile arquivos que incluem cellularapi_oem.h sem a opção **/permissiva,** ou use a opção [/wd](compiler-option-warning-level.md) para silenciar o aviso C4471.

- Problema em um/omscript.h

   Em C++03, uma conversão de uma seqüência literal para BSTR (que é um typedef para 'wchar_t *') é preterida, mas permitida. Em C++11, a conversão não é mais permitida.

   ```cpp
   virtual /* [id] */ HRESULT STDMETHODCALLTYPE setExpression(
       /* [in] */ __RPC__in BSTR propname,
       /* [in] */ __RPC__in BSTR expression,
       /* [in][defaultvalue] */ __RPC__in BSTR language = L"") = 0; // C2440
   ```

   Para resolver esse problema, compile arquivos que incluem omscript.h sem a opção **/permissivo,** ou use **/Zc:strictStrings-** em vez disso.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

No Visual Studio 2017 versão 15.5 e versões posteriores, use este procedimento:

1. Abra a caixa de diálogo Páginas de **Propriedade** do projeto.

1. Selecione a página **De configuração Propriedades** > **C/C++** > **Idioma.**

1. Alterar o valor de propriedade do **modo conformidade** para **Sim (/permissivo-)**. Escolha **OK** ou **Aplicar** para salvar suas alterações.

Nas versões anteriores ao Visual Studio 2017 versão 15.5, use este procedimento:

1. Abra a caixa de diálogo Páginas de **Propriedade** do projeto.

1. Selecione a página de**propriedade** **Configuração Propriedades** > **C/C++.** > 

1. Digite a opção **compilação /permissiva** na caixa **Opções adicionais.** Escolha **OK** ou **Aplicar** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
