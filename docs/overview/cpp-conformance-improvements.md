---
title: Aprimoramentos de conformidade do C++
ms.date: 06/14/2019
description: O Microsoft C++ no Visual Studio está progredindo em direção à plena conformidade com o padrão de linguagem C++20.
ms.technology: cpp-language
author: mikeblome
ms.author: mblome
ms.openlocfilehash: 1652c7ab9a48de65b32123b34c3231a0b06a410a
ms.sourcegitcommit: 0ad35b26e405bbde17dc0bd0141e72f78f0a38fb
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/18/2019
ms.locfileid: "67194787"
---
# <a name="c-conformance-improvements-in-visual-studio"></a>Aprimoramentos de conformidade do C++ no Visual Studio

O Microsoft C++ faz melhorias de conformidade e correções de bugs em cada versão. Este artigo lista as melhorias por versão principal e depois pela versão. Ele também lista correções de bugs importantes por versão. Para ir diretamente para as alterações de uma versão específica, use a lista **Neste artigo**.

::: moniker range=">=vs-2019"

## <a name="improvements_160"></a> Melhorias no Visual Studio 2019 RTW (versão 16.0)

O Visual Studio 2019 RTW apresenta as melhorias de conformidade, correções de bug e alterações de comportamento a seguir no compilador do Microsoft C++ (MSVC).

**Observação:** Os recursos do C++20 serão disponibilizados no modo `/std:c++latest` até que a implementação do C++20 seja concluída para o compilador e para o IntelliSense. Nesse momento, o modo do compilador `/std:c++20` será introduzido.

### <a name="improved-modules-support-for-templates-and-error-detection"></a>Os módulos aprimorados dão suporte a modelos e à detecção de erros

Agora os módulos estão oficialmente no padrão C++20. O suporte aprimorado foi adicionado no Visual Studio 2017 versão 15.9. Para saber mais, confira [Melhor detecção de erro e de suporte de modelo em Módulos do C++ com o MSVC 2017 versão 15.9](https://devblogs.microsoft.com/cppblog/better-template-support-and-error-detection-in-c-modules-with-msvc-2017-version-15-9/).

### <a name="modified-specification-of-aggregate-type"></a>Especificação modificada de tipo de agregação

A especificação de um tipo de agregação foi alterada no C++20 (confira [Proibir agregações com construtores declarados pelo usuário](https://wg21.link/p1008r1)). No Visual Studio de 2019, em `/std:c++latest`, uma classe com qualquer construtor declarado pelo usuário (por exemplo, incluindo um `= default` ou `= delete` declarado por construtor) não é uma agregação. Anteriormente, somente os construtores fornecidos pelo usuário desqualificariam uma classe de uma agregação. Essa alteração impõe outras restrições sobre como esses tipos podem ser inicializados.

O seguinte código é compilado sem erros no Visual Studio 2017, mas gera os erros C2280 e C2440 no Visual Studio 2019 em `/std:c++latest`:

```cpp
struct A
{
    A() = delete; // user-declared ctor
};

struct B
{
    B() = default; // user-declared ctor
    int i = 0;
};

A a{}; // ill-formed in C++20, previously well-formed
B b = { 1 }; // ill-formed in C++20, previously well-formed
```

### <a name="partial-support-for-operator-"></a>Suporte parcial para `operator <=>`

[P0515R3](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0515r3.pdf) O C++20 apresenta o operador de comparação de três vias `<=>`, também conhecido como o "operador espaçonave". O Visual Studio 2019 no modo `/std:c++latest` introduz suporte parcial para o operador gerando erros de sintaxe que agora está cancelada. Por exemplo, o seguinte código é compilado sem erros no Visual Studio 2017, mas gera vários erros no Visual Studio 2019 em `/std:c++latest`:

```cpp
struct S
{
    bool operator<=(const S&) const { return true; }
};

template <bool (S::*)(const S&) const>
struct U { };

int main(int argc, char** argv)
{
    U<&S::operator<=> u; // In Visual Studio 2019 raises C2039, 2065, 2146.
}
```

Para evitar os erros, insira um espaço na linha incorreta antes do colchete angular final: `U<&S::operator<= > u;`.

### <a name="references-to-types-with-mismatched-cv-qualifiers"></a>Referências a tipos sem qualificadores CV incompatíveis

Anteriormente, o MSVC permitia associação direta de uma referência a partir de um tipo com qualificadores CV incompatíveis abaixo do nível superior. Essa associação poderia permitir a modificação de dados const supostamente mencionados pela referência. Agora, o compilador cria um temporário, conforme exigido pelo padrão. No Visual Studio 2017, o código a seguir é compilado sem avisos. No Visual Studio 2019, o compilador gera o *aviso C4172: \<func:#1 "?PData@X@@QBEABQBXXZ"> retornando o endereço de uma variável local ou temporário*.

```cpp
struct X
{
    const void* const& PData() const
    {
        return _pv;
    }

    void* _pv;
};

int main()
{
    X x;
    auto p = x.PData(); // C4172
}
```

### <a name="reinterpretcast-from-an-overloaded-function"></a>`reinterpret_cast` de uma função sobrecarregada

O argumento para `reinterpret_cast` não é um dos contextos em que o endereço de uma função sobrecarregada é permitido. O código a seguir é compilado sem erros no Visual Studio 2017, mas no Visual Studio 2019, ele gera *C2440: não é possível converter de 'overloaded-function' em 'fp'* :

```cpp
int f(int) { return 1; }
int f(float) { return .1f; }
using fp = int(*)(int);

int main()
{
    fp r = reinterpret_cast<fp>(&f);
}
```

Para evitar o erro, use uma conversão permitida para esse cenário:

```cpp
int f(int);
int f(float);
using fp = int(*)(int);

int main()
{
    fp r = static_cast<fp>(&f); // or just &f;
}
```

### <a name="lambda-closures"></a>Fechamentos lambda

No C++ 14, os tipos de fechamento lambda não são literais. A consequência principal dessa regra é que o lambda não pode ser atribuído a uma variável `constexpr`. O seguinte código é compilado sem erros no Visual Studio 2017. No entanto, no Visual Studio 2019, ele gera *C2127: 'l': inicialização inválida da entidade 'constexpr' com uma expressão que não é constante*:

```cpp
int main()
{
    constexpr auto l = [] {}; // C2127 in VS2019
}
```

Para evitar o erro, remova o qualificador `constexpr` ou altere o modo de conformidade para `/std:c++17`.

### <a name="stdcreatedirectory-failure-codes"></a>Códigos de falha de `std::create_directory`

[P1164](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1164r1.pdf) implementado de C++20 incondicionalmente. Isso altera `std::create_directory` para verificar se o destino já foi um diretório em caso de falha. Anteriormente, todos os erros do tipo ERROR_ALREADY_EXISTS foram convertidos em códigos de êxito, mas não criados pelo diretório.

### `operator<<(std::ostream, nullptr_t)`

Por [LWG 2221](https://cplusplus.github.io/LWG/issue2221), `operator<<(std::ostream, nullptr_t)` adicionado para gravação de nullptrs em fluxos.

### <a name="additional-parallel-algorithms"></a>Algoritmos paralelos adicionais

Novas versões paralelas de `is_sorted`, `is_sorted_until`, `is_partitioned`, `set_difference`, `set_intersection`, `is_heap` e `is_heap_until`.

### <a name="atomic-initialization"></a>inicialização atômica

[P0883 "Corrigindo inicialização atômica"](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0883r1.pdf) altera `std::atomic` para o valor-inicializar o T independente, em vez do padrão-inicializando-o. A correção é habilitada ao usar o Clang/LLVM com a biblioteca padrão da Microsoft. No momento, ela está desabilitada para o compilador do Microsoft C++ como uma solução alternativa para um bug no processamento de `constexpr`.

### <a name="removecvref-and-removecvreft"></a>`remove_cvref` e `remove_cvref_t`

Implementação das características de tipo `remove_cvref` e `remove_cvref_t` de [P0550](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0550r2.pdf). Elas removem a capacidade de referência e a qualificação CV de um tipo sem funções e matrizes decrescentes para ponteiros (diferentemente de `std::decay` e `std::decay_t`).

### <a name="feature-test-macros"></a>Macros de teste de recurso

[P0941R2 – macros de teste de recurso](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0941r2.html) está concluído, com suporte para `__has_cpp_attribute`. Macros de teste de recurso têm suporte em todos os modos padrão.

### <a name="prohibit-aggregates-with-user-declared-constructors"></a>Proibir agregações com construtores declarados pelo usuário

[C++20 P1008R1 – proibição de agregações com construtores declarados pelo usuário](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1008r1.pdf) está concluído.

## <a name="improvements_161"></a> Aprimoramentos no Visual Studio 2019 versão 16.1

### <a name="char8t"></a>char8_t

[P0482r6](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0482r6.html). O C++20 adiciona um novo tipo de caractere usado para representar unidades de código UTF-8. Os literais de cadeia de caracteres `u8` no C++20 têm o tipo `const char8_t[N]`, em vez de `const char[N]`, que era o caso anteriormente. Alterações semelhantes foram propostas para o padrão C em [N2231](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2231.htm). Sugestões para correção de compatibilidade com versões anteriores do `char8_t` são dadas em [P1423r0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1423r0.html). O compilador do Microsoft C++ adiciona suporte ao `char8_t` no Visual Studio 2019 versão 16.1 quando você especifica a opção do compilador **/Zc:char8_t**. No futuro, haverá suporte a ele com [/std:c++latest](../build/reference/std-specify-language-standard-version.md), que poderá ser revertido para o comportamento do C++17 por meio de **/Zc:char8_t-** . O compilador do EDG que alimenta o IntelliSense ainda não dá suporte a ele; portanto, você verá apenas erros falsos do IntelliSense que não afetam a compilação real.

#### <a name="example"></a>Exemplo

```cpp
const char* s = u8"Hello"; // C++17
const char8_t* s = u8"Hello"; // C++20
```

### <a name="stdtypeidentity-metafunction-and-stdidentity-function-object"></a>Metafunção std::type_identity e objeto de função std::identity

[P0887R1 type_identity](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0887r1.pdf). A extensão do modelo de classe `std::identity` preterido foi removida e substituída pela metafunção `std::type_identity` do C++20 e pelo objeto de função `std::identity`. Ambos estão disponíveis somente em [/std:c++latest](../build/reference/std-specify-language-standard-version.md).

O exemplo a seguir produz o aviso de substituição C4996 para `std::identity` (definido em \<type_traits>) no Visual Studio 2017:

```cpp
#include <type_traits>

using T = std::identity<int>::type;
T x, y = std::identity<T>{}(x);
int i = 42;
long j = std::identity<long>{}(i);
```

O exemplo a seguir mostra como usar o novo `std::identity` (definido no \<functional>) juntamente com o novo `std::type_identity`:

```cpp
#include <type_traits>
#include <functional>

using T = std::type_identity<int>::type;
T x, y = std::identity{}(x);
int i = 42;
long j = static_cast<long>(i);
```

### <a name="syntax-checks-for-generic-lambdas"></a>Verificações de sintaxe para lambdas genéricos

O novo processador lambda permite algumas verificações sintáticas de modo de conformidade em lambdas genéricos, em [/std:c++latest](../build/reference/std-specify-language-standard-version.md) ou em qualquer outro modo de linguagem com **/experimental:newLambdaProcessor**.

No Visual Studio 2017, esse código é compilado sem avisos, mas, no Visual Studio 2019, ele produz o erro *C2760 erro de sintaxe: token inesperado '\<id-expr>', 'id-expression' esperada*:

```cpp
void f() {
    auto a = [](auto arg) {
        decltype(arg)::Type t;
    };
}
```

O exemplo a seguir mostra a sintaxe correta, agora imposta pelo compilador:

```cpp
void f() {
    auto a = [](auto arg) {
        typename decltype(arg)::Type t;
    };
}
```

### <a name="argument-dependent-lookup-for-function-calls"></a>Pesquisa dependente de argumento para chamadas de função

[P0846R0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0846r0.html) (C++20) Maior capacidade de localizar os modelos de função por meio de pesquisa dependente de argumento para expressões de chamada de função com argumentos de modelo explícitos. Requer **/std:c++latest**.

### <a name="designated-initialization"></a>Inicialização designada

[P0329R4](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0329r4.pdf) (C++20) A inicialização designada permite que membros específicos sejam selecionados na inicialização de agregação usando a sintaxe `Type t { .member = expr }`. Requer **/std:c++latest**.

### <a name="new-and-updated-standard-library-functions-c20"></a>Funções da biblioteca padrão novas e atualizadas (C++20)

- `starts_with()` e `ends_with()` para `basic_string` e `basic_string_view`.
- `contains()` para contêineres associativos.
- `remove()`, `remove_if()`, e `unique()` para `list` e `forward_list` agora retornam `size_type`.
- `shift_left()` e `shift_right()` adicionados ao \<algoritmo>.

## <a name="bug-fixes-and-behavior-changes-in-visual-studio-2019"></a>Correções de bug e alterações de comportamento no Visual Studio 2019

### <a name="correct-diagnostics-for-basicstring-range-constructor"></a>Diagnóstico correto para o construtor do intervalo basic_string

No Visual Studio 2019, o construtor de intervalo `basic_string` não suprime mais o diagnóstico do compilador com `static_cast`. O código a seguir é compilado sem avisos no Visual Studio 2017, apesar de possível perda de dados do `wchar_t` ao `char` ao inicializar `out`:

```cpp
std::wstring ws = /* … */;
std::string out(ws.begin(), ws.end());
```

O Visual Studio 2019 gera corretamente *C4244: 'argument': conversão de 'wchar_t' em 'const _Elem', possível perda de dados*. Para evitar o aviso, é possível inicializar o std::string como mostrado neste exemplo:

```cpp
std::wstring ws = L"Hello world";
std::string out;
for (wchar_t ch : ws)
{
    out.push_back(static_cast<char>(ch));
}
```

### <a name="incorrect-calls-to--and---under-clr-or-zw-are-now-correctly-detected"></a>Chamadas incorretas a += e a -= em /clr ou /ZW não são detectadas corretamente

Um bug foi introduzido no Visual Studio 2017 e fazia com que o compilador ignorasse silenciosamente erros e não gerasse código para as chamadas inválidas a += e a -= em `/clr` ou em `/ZW`. O seguinte código é compilado sem erros no Visual Studio 2017, mas, no Visual Studio 2019, gera corretamente o *erro C2845: 'System::String ^': aritmética do ponteiro não permitida neste tipo*:

```cpp
public enum class E { e };

void f(System::String ^s)
{
    s += E::e; // C2845 in VS2019
}
```

Para evitar o erro deste exemplo, use o operador com o método ToString (): `s += E::e.ToString();`.

### <a name="initializers-for-inline-static-data-members"></a>Inicializadores de membros de dados estáticos embutidos

Agora os acessos do membro inválido dentro de `inline` e de `static constexpr` são detectados corretamente. O exemplo a seguir é compilado sem erro no Visual Studio 2017, mas, no Visual Studio 2019, no modo `/std:c++17`, gera o *erro C2248: não é possível acessar o membro privado declarado na classe 'X'* .

```cpp
struct X
{
    private:
        static inline const int c = 1000;
};

struct Y : X
{
    static inline int d = c; // C2248 in Visual Studio 2019
};
```

Para evitar o erro, declare o membro `X::c` como protegido:

```cpp
struct X
{
    protected:
        static inline const int c = 1000;
};
```

### <a name="c4800-reinstated"></a>C4800 restabelecido

O MSVC costumava ter um aviso de desempenho C4800 sobre a conversão implícita em `bool`. Ele era muito inconveniente e não podia ser suprimido, o que nos levou a removê-lo do Visual Studio 2017. No entanto, durante o ciclo de vida do Visual Studio 2017, recebemos muitos comentários sobre os casos úteis que ele estava resolvendo. No Visual Studio 2019, estamos retornando um C4800 cuidadosamente ajustado com o C4165 explicativo. Ambos os avisos podem ser facilmente suprimidos com conversão explícita ou comparação com 0 do tipo apropriado. O C4800 é um aviso desativado por padrão de nível 4 e o C4165 é um aviso desativado por padrão de nível 3. Os dois podem ser descobertos usando a opção do compilador `/Wall`.

O exemplo a seguir gera o C4800 e o C4165 em `/Wall`:

```cpp
bool test(IUnknown* p)
{
    bool valid = p; // warning C4800: Implicit conversion from 'IUnknown*' to bool. Possible information loss
    IDispatch* d = nullptr;
    HRESULT hr = p->QueryInterface(__uuidof(IDispatch), reinterpret_cast<void**>(&d));
    return hr; // warning C4165: 'HRESULT' is being converted to 'bool'; are you sure this is what you want?
}
```

Para evitar os avisos no exemplo anterior, é possível escrever o código da seguinte maneira:

```cpp
bool test(IUnknown* p)
{
    bool valid = p != nullptr; // OK
    IDispatch* d = nullptr;
    HRESULT hr = p->QueryInterface(__uuidof(IDispatch), reinterpret_cast<void**>(&d));
    return SUCCEEDED(hr);  // OK
}
```

### <a name="local-class-member-function-doesnt-have-a-body"></a>A função de membro de classe local não tem um corpo

No Visual Studio 2017, *C4822: a função de membro de classe local não tem um corpo* é gerado somente quando a opção do compilador `/w14822` é definida explicitamente; ela não é mostrada com `/Wall`. No Visual Studio 2019, o C4822 é um aviso desativado por padrão, o que o faz poder ser descoberto em `/Wall` sem precisar definir `/w14822` explicitamente.

```cpp
void example()
{
    struct A
        {
            int boo(); // warning C4822
        };
}
```

### <a name="function-template-bodies-containing-constexpr-if-statements"></a>Corpos de modelo de função que contêm instruções constexpr if

Corpos de função de modelo que contêm instruções `if constexpr` têm algumas verificações `/permissive-` relacionadas a análise habilitadas. Por exemplo, no Visual Studio 2017, o seguinte código produz C*7510: 'Type': o uso de nome de tipo dependente deverá ser prefixado com 'typename'* somente se a opção `/permissive-` não estiver definida. No Visual Studio 2019, o mesmo código gera erros mesmo quando a opção `/permissive-` é definida:

```cpp
template <typename T>

int f()
{
    T::Type a; // error C7510

    if constexpr (T::val)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

struct X
{
    using Type = X;
    constexpr static int val = 1;
};

int main()
{
    return f<X>();
}
```

Para evitar o erro, adicione a palavra-chave `typename` à declaração de `a`: `typename T::Type a;`.

### <a name="inline-assembly-code-isnt-supported-in-a-lambda-expression"></a>Não há suporte ao código do assembly embutido em uma expressão lambda

A equipe do Visual C++ recentemente tomou conhecimento de um problema de segurança em que o uso do assembler embutido em um lambda poderia levar à corrupção de `ebp` (o registro do endereço de retorno) em tempo de execução. Um invasor mal-intencionado possivelmente poderia tirar proveito desse cenário. Dada a natureza do problema, o fato de que só há suporte ao assembler embutido em x86 e a interação instável entre o assembler embutido e o restante do compilador, a solução mais segura para o problema era não permitir o assembler embutido em uma expressão lambda.

O único uso do assembler embutido em uma expressão lambda que encontramos “em condições naturais” era capturar o endereço de retorno. Nesse cenário, é possível capturar o endereço de retorno em todas as plataformas usando simplesmente um `_ReturnAddress()` intrínseco do compilador.

O código a seguir produz *C7552: não há suporte ao assembler embutido em um lambda* no Visual Studio 2017 15.9 e no Visual Studio 2019:

```cpp
#include <cstdio>

int f()
{
    int y = 1724;
    int x = 0xdeadbeef;

    auto lambda = [&]
    {
        __asm {

            mov eax, x
            mov y, eax
        }
    };

    lambda();
    return y;
}
```

Para evitar o erro, mova o código do assembly para uma função nomeada conforme mostrado no exemplo a seguir:

```cpp
#include <cstdio>

void g(int& x, int& y)
{
    __asm {
        mov eax, x
        mov y, eax
    }
}

int f()
{
    int y = 1724;
    int x = 0xdeadbeef;
    auto lambda = [&]
    {
        g(x, y);
    };
    lambda();
    return y;
}

int main()
{
    std::printf("%d\n", f());
}
```

### <a name="iterator-debugging-and-stdmoveiterator"></a>Depuração do iterador e `std::move_iterator`

O recurso de depuração do iterador foi ensinado a desencapsular adequadamente o `std::move_iterator`. Por exemplo, agora `std::copy(std::move_iterator<std::vector<int>::iterator>, std::move_iterator<std::vector<int>::iterator>, int*)` pode envolver o caminho `memcpy` rápido.

### <a name="fixes-for-xkeycheckh-keyword-enforcement"></a>Correções para a imposição da palavra-chave \<xkeycheck.h>

A macro da biblioteca padrão que substitui uma imposição da palavra-chave \<xkeycheck.h> foi corrigida para emitir a palavra-chave do problema real detectada, em vez de uma mensagem genérica. Ela também dá suporte a palavras-chave do C++20 e evita enganar o IntelliSense dizendo que palavras-chave são macros.

### <a name="allocator-types-no-longer-deprecated"></a>Tipos de alocador não mais preteridos

`std::allocator<void>`, `std::allocator::size_type` e `std::allocator::difference_type` não são mais preteridos.

### <a name="correct-warning-for-narrowing-string-conversions"></a>Aviso correto para restringir conversões de cadeia de caracteres

Um `static_cast` falso não chamado pelo padrão que acidentalmente suprimiu avisos de restrição do C4244 foi removido de `std::string`. Tentar chamar `std::string::string(const wchar_t*, const wchar_t*)` agora emitirá devidamente *C4244 "restringindo um wchar_t a um char."*

### <a name="various-filesystem-correctness-fixes"></a>Várias correções de exatidão do \<sistemadearquivos>

- Correção de `std::filesystem::last_write_time` que falhava ao tentar alterar o último horário de gravação de um diretório.
- O construtor `std::filesystem::directory_entry` agora armazena um resultado com falha, em vez de gerar uma exceção, quando um caminho de destino não existente é fornecido.
- A versão de dois parâmetros `std::filesystem::create_directory` foi alterada para chamar a versão de um parâmetro, pois a função `CreateDirectoryExW` subjacente usaria `copy_symlink` quando `existing_p` fosse um symlink.
- `std::filesystem::directory_iterator` não falha mais quando um symlink corrompido é encontrado.
- `std::filesystem::space` agora aceita caminhos relativos.
- `std::filesystem::path::lexically_relative` não é mais confundido com barras à direita, relatado como [LWG 3096](https://cplusplus.github.io/LWG/issue3096).
- Solução de `CreateSymbolicLinkW` que rejeitava caminhos com barras à esquerda em `std::filesystem::create_symlink`.
- Solução alternativa da função `delete` no modo de exclusão POSIX existente no Windows 10 LTSB 1609, mas que, na verdade, não é capaz de excluir arquivos.
- Os operadores de atribuição de cópia e construtores de cópia do `std::boyer_moore_searcher` e do `std::boyer_moore_horspool_searcher` agora realmente copiam coisas.

### <a name="parallel-algorithms-on-windows-8-and-later"></a>Algoritmos paralelos no Windows 8 e posterior

A biblioteca de algoritmos paralelos agora usa devidamente a família `WaitOnAddress` real no Windows 8 e posterior, em vez de sempre usar o Windows 7 e versões falsas anteriores.

### <a name="stdsystemcategorymessage-whitespace"></a>Espaço em branco em `std::system_category::message()`

`std::system_category::message()` agora corta o espaço em branco à direita da mensagem retornada.

### <a name="stdlinearcongruentialengine-divide-by-zero"></a>Divisão por zero em `std::linear_congruential_engine`

Algumas condições que poderiam fazer `std::linear_congruential_engine` disparar a divisão por 0 foram corrigidas.

### <a name="fixes-for-iterator-unwrapping"></a>Correções para desencapsulamento do iterador

O mecanismo de desencapsulamento do iterador que foi exposto pela primeira vez à integração entre programador e usuário no Visual Studio 2017 15.8, como descrito no artigo do Blog da Equipe do C++, [Recursos e correções de STL no VS 2017 15.8](https://devblogs.microsoft.com/cppblog/stl-features-and-fixes-in-vs-2017-15-8/), não desencapsula mais os iteradores derivados dos iteradores da biblioteca padrão. Por exemplo, um usuário derivado de `std::vector<int>::iterator` e que tenta personalizar o comportamento agora obtém seu comportamento personalizado ao chamar algoritmos de biblioteca padrão, em vez do comportamento de um ponteiro.

Agora, a função `reserve` de contêiner não ordenada na verdade reserva N elementos, conforme descrito em [LWG 2156](https://cplusplus.github.io/LWG/issue2156).

### <a name="time-handling"></a>Manipulação de tempo

- Anteriormente, alguns valores temporais que eram passados para a biblioteca de simultaneidade estourariam, por exemplo, `condition_variable::wait_for(seconds::max())`. Agora corrigidos, os estouros mudaram o comportamento em um ciclo aparentemente aleatório de 29 dias (quando uint32_t milissegundos aceitos pelas APIs do Win32 subjacentes estouravam).

- Agora o cabeçalho <ctime> declara corretamente `timespec` e `timespec_get` no namespace `std`, além de declará-los no namespace global.

### <a name="various-fixes-for-containers"></a>Várias correções de contêineres

- Muitas funções de contêiner interno da biblioteca padrão tornaram-se privadas para uma experiência aprimorada do IntelliSense. Outras correções para marcar membros como privados são esperadas em versões posteriores do MSVC.

- Problemas de exatidão de segurança de exceção nos quais contêineres baseados em nós, como `list`, `map` e `unordered_map`, se tornariam corrompidos foram corrigidos. Durante uma operação de reatribuição de `propagate_on_container_copy_assignment` ou de `propagate_on_container_move_assignment`, liberaríamos o nó sentinela do contêiner com o alocador antigo, realizaríamos a atribuição de POCCA/POCMA pelo alocador antigo e tentaríamos adquirir o nó sentinela do novo alocador. Se essa alocação falhasse, o contêiner era corrompido e não poderia nem mesmo ser destruído, pois ter um nó sentinela é uma invariável fixa da estrutura de dados. Esse código foi corrigido para alocar o novo nó sentinela do alocador do contêiner de origem antes de destruir o nó sentinela existente.

- Os contêineres foram corrigidos para alocadores sempre copiar/mover/trocar de acordo com `propagate_on_container_copy_assignment`, `propagate_on_container_move_assignment` e `propagate_on_container_swap`, mesmo para alocadores declarados `is_always_equal`.

- Adição das sobrecargas para funções de membro extrair e mesclar do contêiner que aceitam contêineres rvalue de acordo com [P0083 "Unindo mapas e conjuntos"](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0083r3.pdf)

### <a name="stdbasicistreamread-processing-of-rn--n"></a>Processamento de \\r\\n = > \\n em `std::basic_istream::read`

`std::basic_istream::read` foi corrigido para não gravar em partes do buffer fornecido temporariamente como parte do processamento de \\r\\n => \\n. Essa alteração perde um pouco da vantagem de desempenho que foi obtida no Visual Studio 2017 15.8 para leituras com mais de 4 K. No entanto, as melhorias na eficiência evitando três chamadas virtuais por caractere ainda estão presentes.

### <a name="stdbitset-constructor"></a>Construtor `std::bitset`

O construtor `std::bitset` não lê mais os numerais um e zero em ordem inversa em conjuntos de bits grandes.

### <a name="stdpairoperator-regression"></a>Regressão de `std::pair::operator=`

Correção de uma regressão no operador de atribuição do `std::pair` introduzida ao implementar [LWG 2729 "SFINAE ausente em std::pair::operator =";](https://cplusplus.github.io/LWG/issue2729). Ele agora aceita corretamente tipos conversíveis em `std::pair` novamente.

### <a name="non-deduced-contexts-for-addconstt"></a>Contextos não deduzidos para `add_const_t`

Correção de um bug de características de tipo secundário, em que `add_const_t` e funções relacionadas devem ser um contexto não deduzido. Em outras palavras, `add_const_t` deve ser um alias para `typename add_const<T>::type`, e não `const T`.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="improvements_150"></a> Melhorias no Visual Studio 2017 RTW (versão 15.0)

Com suporte para `constexpr` generalizado e NSDMI (inicialização de membros de dados não estáticos) para agregações, o compilador do Microsoft C++ no Visual Studio 2017 agora está completo para recursos adicionados no padrão C++14. No entanto, o compilador ainda não tem alguns recursos dos padrões C++11 e C++98. Confira [Conformidade com a linguagem Visual C++](../visual-cpp-language-conformance.md) para ver uma tabela que mostra o estado atual do compilador.

### <a name="c11-expression-sfinae-support-in-more-libraries"></a>C++11: Suporte da expressão SFINAE em mais bibliotecas

O compilador continua melhorando seu suporte à expressão SFINAE, necessário para dedução e substituição de argumentos de modelo em que as expressões `decltype` e `constexpr` podem ser exibidas como parâmetros de modelo. Para obter mais informações, consulte [Expression SFINAE improvements in Visual Studio 2017 RC (Melhorias da expressão SFINAE no Visual Studio 2017 RC)](https://blogs.msdn.microsoft.com/vcblog/2016/06/07/expression-sfinae-improvements-in-vs-2015-update-3).

### <a name="c14-nsdmi-for-aggregates"></a>C++14: NSDMI para agregações

Uma agregação é uma matriz ou uma classe sem nenhum construtor fornecido pelo usuário, sem membros de dados não estáticos privados ou protegidos, sem classes base e sem funções virtuais. Começando pelo C ++14, as agregações podem conter inicializadores de membro. Para obter mais informações, consulte [Member initializers and aggregates (Inicializadores de membro e agregações)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3605.html).

### <a name="c14-extended-constexpr"></a>C++14: `constexpr` estendido

Agora, as expressões declaradas como `constexpr` podem conter determinados tipos de declaração, instruções if e switch, declarações de loop e mutação de objetos cujo tempo de vida começou dentro da avaliação da expressão constexpr. Além disso, não há mais o requisito de que uma função de membro não estática `constexpr` seja implicitamente `const`. Para obter mais informações, consulte [Relaxing constraints on constexpr functions (Relaxando restrições em funções constexpr)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3652.html).

### <a name="c17-terse-staticassert"></a>C++17: `static_assert` conciso

O parâmetro de mensagem para `static_assert` é opcional. Para obter mais informações, consulte [Extending static_assert, v2 (Estendendo static_assert, v2)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928.pdf).

### <a name="c17-fallthrough-attribute"></a>C++17: atributo `[[fallthrough]]`

No modo **/std:c++17**, o atributo `[[fallthrough]]` pode ser usado no contexto de instruções switch como uma dica para o compilador de que o comportamento de fall-through é intencional. Esse atributo impede o compilador de emitir avisos em tais casos. Para saber mais, confira [Expressão para o atributo \[\[fallthrough\]\]](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0188r0.pdf).

### <a name="generalized-range-based-for-loops"></a>Generalizados baseados em intervalo para loops

Loops for baseados em intervalo não exigem mais que `begin()` e `end()` retornem objetos do mesmo tipo. Essa mudança permite que `end()` retorne uma sentinela conforme usado pelos intervalos em [range-v3](https://github.com/ericniebler/range-v3) e na Especificação Técnica de Intervalos concluída, mas não completamente publicada. Para obter mais informações, consulte [Generalizando o loop “for” baseado em intervalo](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html).

## <a name="improvements_153"></a> Melhorias no Visual Studio 2017 versão 15.3

### <a name="constexpr-lambdas"></a>Lambdas constexpr

Expressões Lambda agora podem ser usadas em expressões de constante. Para saber mais, veja [Expressões lambda constexpr em C++](../cpp/lambda-expressions-constexpr.md).

### <a name="if-constexpr-in-function-templates"></a>`if constexpr` em modelos de função

Um modelo de função pode conter instruções `if constexpr` para habilitar a ramificação de tempo de compilação. Para saber mais, veja [Instruções if constexpr](../cpp/if-else-statement-cpp.md#if_constexpr).

### <a name="selection-statements-with-initializers"></a>Instruções de seleção com inicializadores

Uma instrução `if` pode conter um inicializador que apresenta uma variável no escopo de bloco dentro da instrução em si. Para saber mais, veja [Instruções if com inicializador](../cpp/if-else-statement-cpp.md#if_with_init).

### <a name="maybeunused-and-nodiscard-attributes"></a>Atributos `[[maybe_unused]]` e `[[nodiscard]]`

O novo atributo `[[maybe_unused]]` silencia avisos quando uma entidade não é usada. O atributo `[[nodiscard]]` criará um aviso se o valor retornado de uma chamada de função for descartado. Para saber mais, veja [Atributos em C++](../cpp/attributes.md).

### <a name="using-attribute-namespaces-without-repetition"></a>Uso de namespaces de atributo sem repetição

Nova sintaxe para permitir apenas um único identificador de namespace em uma lista de atributos. Para saber mais, veja [Atributos em C++](../cpp/attributes.md).

### <a name="structured-bindings"></a>Associações estruturadas

Agora é possível, em uma única declaração, armazenar um valor com nomes individuais de seus componentes, quando o valor é uma matriz, um `std::tuple` ou `std::pair`, ou tem todos os membros de dados não estáticos públicos. Para saber mais, veja [Associações estruturadas](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0144r0.pdf) e [Retornar vários valores de uma função](../cpp/functions-cpp.md#multi_val).

### <a name="construction-rules-for-enum-class-values"></a>Regras de construção para valores `enum class`

Agora, há uma conversão implícita/não restrição do tipo subjacente de uma enumeração com escopo em enumeração em si, quando sua definição não apresenta enumerador e a origem usa uma sintaxe de inicialização da lista. Para saber mais, veja [Regras de construção para valores de classe de enumeração](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0138r2.pdf)e[Enumerações](../cpp/enumerations-cpp.md#no_enumerators).

### <a name="capturing-this-by-value"></a>Capturar `*this` por valor

O objeto `*this` em uma expressão lambda agora pode ser capturado por valor. Essa mudança permite cenários nos quais o lambda é invocado em operações paralelas e assíncronas, especialmente em arquiteturas de computadores mais recentes. Para saber mais, confira [Captura de Lambda de \*this por valor como \[=,\*this\]](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0018r3.html).

### <a name="removing-operator-for-bool"></a>Remover `operator++` para `bool`

`operator++` não é mais compatível em tipos `bool`. Para saber mais, veja [Remover operator++(bool) preterido](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0002r1.html).

### <a name="removing-deprecated-register-keyword"></a>Remover a palavra-chave `register` preterida

A palavra-chave `register`, anteriormente preterida (e ignorada pelo compilador), agora foi removida da linguagem. Para saber mais, veja [Remover uso preterido da palavra-chave register](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0001r1.html).

## <a name="improvements_155"></a> Melhorias no Visual Studio 2017 versão 15.5

Recursos marcados com \[14] estão disponíveis incondicionalmente, mesmo no modo **/std:c++14**.

### <a name="new-compiler-switch-for-extern-constexpr"></a>Nova opção de compilador para `extern constexpr`

Em versões anteriores do Visual Studio, o compilador sempre forneceu uma ligação interna variável `constexpr`, mesmo quando a variável era marcada como `extern`. No Visual Studio 2017 versão 15.5, uma nova opção de compilador, [/Zc:externConstexpr](../build/reference/zc-externconstexpr.md), habilita o comportamento correto em conformidade com os padrões. Para obter mais informações, consulte [vinculação de contexpr externo](#extern_linkage).

### <a name="removing-dynamic-exception-specifications"></a>Remover especificações de exceção dinâmica

[P0003R5](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0003r5.html) As especificações de exceções dinâmicas foram preteridas no C++11. O recurso foi removido do C++17, mas a especificação `throw()` (ainda) preterida é mantida estritamente como um alias para `noexcept(true)`. Para obter mais informações, consulte [Remoção de especificação de exceção dinâmica e noexcept](#noexcept_removal).

### `not_fn()`

[P0005R4](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0005r4.html) `not_fn` é uma substituição de `not1` e `not2`.

### <a name="rewording-enablesharedfromthis"></a>Reescrever `enable_shared_from_this`

[P0033R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0033r1.html) `enable_shared_from_this` foi adicionada no C++ 11. O padrão C++17 atualiza a especificação para lidar melhor com certos casos de canto. [14]

### <a name="splicing-maps-and-sets"></a>Unir mapas e conjuntos

[P0083R3](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0083r3.pdf) Esse recurso permite a extração de nós de contêineres associativos (isto é, `map`, `set`, `unordered_map`, `unordered_set`) que podem ser modificados e inseridos de volta no mesmo contêiner ou em um contêiner diferente que use o mesmo tipo de nó. (É um caso de uso comum extrair um nó de um `std::map`, alterar a chave e inseri-lo novamente.)

### <a name="deprecating-vestigial-library-parts"></a>Preterir partes residuais da biblioteca

[P0174R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0174r2.html) Vários recursos da biblioteca padrão do C++ foram substituídos por novos recursos ao longo dos anos, ou porque não se mostraram úteis, ou porque apresentaram problemas. Esses recursos foram oficialmente preteridos no C++17.

### <a name="removing-allocator-support-in-stdfunction"></a>Remover o suporte ao alocador em `std::function`

[P0302R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0302r1.html) Antes do C++17, o modelo de classe `std::function` tinha vários construtores que usavam um argumento de alocador. No entanto, o uso de alocadores neste contexto era problemático e a semântica era confusa. Os construtores de problema foram removidos.

### <a name="fixes-for-notfn"></a>Correções para `not_fn()`

[P0358R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0358r1.html) A nova expressão para `std::not_fn` dão suporte à propagação de categoria de valor quando usada na invocação do wrapper.

### <a name="sharedptrt-sharedptrtn"></a>`shared_ptr<T[]>`, `shared_ptr<T[N]>`

[P0414R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0414r2.html) Mesclando alterações do `shared_ptr` dos Princípios básicos de biblioteca para o C++17. [14]

### <a name="fixing-sharedptr-for-arrays"></a>Corrigir `shared_ptr` para matrizes

[P0497R0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0497r0.html) Correções para o suporte de shared_ptr para matrizes. [14]

### <a name="clarifying-insertreturntype"></a>Esclarecer `insert_return_type`

[P0508R0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0508r0.html) Os contêineres associativos e não ordenados, ambos com chaves exclusivas, têm uma função de membro `insert` que retorna um tipo aninhado `insert_return_type`. O tipo de retorno agora é definido como uma especialização de um tipo com parâmetros no iterador e NodeType do contêiner.

### <a name="inline-variables-for-the-standard-library"></a>Variáveis embutidas para a biblioteca padrão

[P0607R0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0607r0.html)

### <a name="annex-d-features-deprecated"></a>Recursos preteridos do anexo D

O anexo D do C++ padrão contém todos os recursos que foram preteridos, incluindo `shared_ptr::unique()`, `<codecvt>` e `namespace std::tr1`. Quando a opção do compilador **/std:c++17** está definida, quase todos os recursos da biblioteca padrão do Anexo D são marcados como preteridos. Para saber mais, confira [Recursos da biblioteca padrão no Anexo D são marcados como preteridos](#annex_d).

O namespace `std::tr2::sys` em `<experimental/filesystem>` agora emite um aviso de substituição em **/std:c++14** por padrão e agora será removido em **/std:c++17** por padrão.

Melhoria na conformidade em `<iostream>`, evitando uma extensão não padrão (especializações explícitas na classe).

A biblioteca padrão agora usa modelos de variável internamente.

A biblioteca padrão foi atualizada em resposta às alterações do compilador do C++17, incluindo a adição de `noexcept` no sistema de tipos e a remoção das especificações de exceção dinâmica.

## <a name="improvements_156"></a> Melhorias no Visual Studio 2017 versão 15.6

### <a name="c17-library-fundamentals-v1"></a>Princípios básicos da biblioteca C++17 V1

O [P0220R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0220r1.html) incorpora a especificação técnica dos princípios básicos da biblioteca para o C++17 no padrão. Ele aborda as atualizações para \<experimental/tuple>, \<experimental/optional>, \<experimental/functional>, \<experimental/any>, \<experimental/string_view>, \<experimental/memory>, \<experimental/memory_resource> e \<experimental/algorithm>.

### <a name="c17-improving-class-template-argument-deduction-for-the-standard-library"></a>C++17: Como aprimorar a dedução de argumento do modelo de classe para a biblioteca padrão

O [P0739R0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0739r0.html) move o `adopt_lock_t` para a frente da lista de parâmetros para `scoped_lock` a fim de habilitar o uso consistente de `scoped_lock`. Permite que o construtor `std::variant` participe na resolução de sobrecarga em mais casos para habilitar a atribuição de cópia.

## <a name="improvements_157"></a> Melhorias no Visual Studio 2017 versão 15.7

### <a name="c17-rewording-inheriting-constructors"></a>C++17: Como reescrever construtores de herança

[P0136R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0136r1.html) especifica que uma declaração **using** que nomeia um construtor, agora torna os construtores de classe base correspondentes visíveis para inicializações da classe derivada, em vez de declarar construtores de classe derivada adicionais. Essa reformulação é uma mudança a partir do C++14. No Visual Studio 2017 versão 15.7 e posteriores, no modo **/std:c++17**, o código que é válido no C++14 e usa os construtores de herança pode não ser válido ou pode ter semântica diferente.

O exemplo a seguir mostra o comportamento do C++14:

```cpp
struct A {
    template<typename T>
    A(T, typename T::type = 0);
    A(int);
};

struct B : A {
    using A::A;
    B(int n) = delete; // Error C2280
};

B b(42L); // Calls B<long>(long), which calls A(int)
          //  due to substitution failure in A<long>(long).
```

A exemplo a seguir mostra o comportamento do modo **/std:c++17** no Visual Studio 15.7:

```cpp
struct A {
    template<typename T>
    A(T, typename T::type = 0);
    A(int);
};

struct B : A {
    using A::A;
    B(int n)
    {
        //do something
    }
};

B b(42L); // now calls B(int)
```

Para saber mais, veja [Construtores](../cpp/constructors-cpp.md#inheriting_constructors).

### <a name="c17-extended-aggregate-initialization"></a>C++17: Inicialização de agregação estendida

[P0017R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0017r1.html)

quando o construtor de uma classe base não é não público, mas é acessível a uma classe derivada, então, no modo **/std:c++17**, no Visual Studio versão 15.7, não é mais possível usar chaves vazias para inicializar um objeto do tipo derivado.

O exemplo a seguir mostra o comportamento de conformidade do C++14:

```cpp
struct Derived;

struct Base {
    friend struct Derived;
private:
    Base() {}
};

struct Derived : Base {};

Derived d1; // OK. No aggregate init involved.
Derived d2 {}; // OK in C++14: Calls Derived::Derived()
               // which can call Base ctor.
```

No C++ 17, `Derived` agora é considerado um tipo de agregação. Isso significa que a inicialização de `Base` por meio do construtor padrão privado acontece diretamente como parte da regra de inicialização de agregação estendida. Anteriormente, o construtor privado `Base` era chamado por meio do construtor `Derived`, e isso era bem-sucedido devido à declaração friend.

O exemplo a seguir mostra o comportamento do C++17 no Visual Studio versão 15.7, no modo **/std:c++17**:

```cpp
struct Derived;

struct Base {
    friend struct Derived;
private:
    Base() {}
};

struct Derived : Base {
    Derived() {} // add user-defined constructor
                 // to call with {} initialization
};

Derived d1; // OK. No aggregate init involved.

Derived d2 {}; // error C2248: 'Base::Base': cannot access
               // private member declared in class 'Base'
```

### <a name="c17-declaring-non-type-template-parameters-with-auto"></a>C++17: Declarar parâmetros de modelo de não tipo com auto

[P0127R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0127r2.html)

No modo **/std:c++17**, o compilador agora pode deduzir o tipo de um argumento de modelo de não tipo que é declarado com **auto**:

```cpp
template <auto x> constexpr auto constant = x;

auto v1 = constant<5>;      // v1 == 5, decltype(v1) is int
auto v2 = constant<true>;   // v2 == true, decltype(v2) is bool
auto v3 = constant<'a'>;    // v3 == 'a', decltype(v3) is char
```

Um impacto desse novo recurso é que um código válido do C++14 pode não ser válido ou pode ter semântica diferente. Por exemplo, algumas sobrecargas que anteriormente eram inválidas, agora são válidas. O exemplo a seguir mostra um código do C++14 que é compilado porque a chamada a `example(p)` está associada a `example(void*);`. No Visual Studio 2017 versão 15.7, no modo **/std:c++17**, o modelo da função `example` é a melhor correspondência.

```cpp
template <int N> struct A;
template <typename T, T N> int example(A<N>*) = delete;

void example(void *);

void sample(A<0> *p)
{
    example(p); // OK in C++14
}
```

O exemplo a seguir mostra um código do C++17 no Visual Studio 15.7, no modo **/std:c++17**:

```cpp
template <int N> struct A;
template <typename T, T N> int example(A<N>*);

void example(void *);

void sample(A<0> *p)
{
    example(p); // C2280: 'int example<int,0>(A<0>*)': attempting to reference a deleted function
}
```

### <a name="c17-elementary-string-conversions-partial"></a>C++17: Conversões elementares de cadeia de caracteres (parcial)

[P0067R5](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0067r5.html) funções de nível baixo, independentes de localidade para conversões entre cadeias de caracteres e inteiros e entre cadeias de caracteres e números de ponto flutuante.

### <a name="c20-avoiding-unnecessary-decay-partial"></a>C++20: Como evitar o decaimento desnecessário (parcial)

[P0777R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0777r1.pdf) Adiciona diferenciação entre o conceito de "decaimento" e o da simples remoção de const ou de qualificadores de referência.  A característica de novo tipo de `remove_reference_t` substitui `decay_t` em alguns contextos. O suporte a `remove_cvref_t` é implementado no Visual Studio 2019.

### <a name="c17-parallel-algorithms"></a>C++17: Algoritmos paralelos

[P0024R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0024r2.html) A TS de paralelismo será incorporada no padrão, com pequenas modificações.

### <a name="c17-hypotx-y-z"></a>C++17: `hypot(x, y, z)`

[P0030R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0030r1.pdf) Adiciona três novas sobrecargas para `std::hypot`, para os tipos **float**, **double** e **long double**, cada um deles com três parâmetros de entrada.

### <a name="c17-filesystem"></a>C++17: \<filesystem>

[P0218R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0218r1.html) Adota a TS do sistema de arquivos no padrão, com algumas modificações de frase.

### <a name="c17-mathematical-special-functions"></a>C++17: Funções matemáticas especiais

[P0226R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0220r1.html) Adota especificações técnicas anteriores para as funções matemáticas especiais no cabeçalho \<cmath> padrão.

### <a name="c17-deduction-guides-for-the-standard-library"></a>C++17: Guias de dedução da biblioteca padrão

[P0433R2](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0433r2.html) Atualizações ao STL para aproveitar a adoção do [P0091R3](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0091r3.html) pelo C++17, que adiciona suporte à dedução de argumento de modelo de classe.

### <a name="c17-repairing-elementary-string-conversions"></a>C++17: Como reparar conversões de cadeia de caracteres elementares

[P0682R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0682r1.html) Mover as novas funções de conversão de cadeia de caracteres elementares do P0067R5 para um novo cabeçalho \<charconv> e fazer outras melhorias, incluindo alterações no tratamento de erro para usar `std::errc` em vez de `std::error_code`.

### <a name="c17-constexpr-for-chartraits-partial"></a>C++17: `constexpr` para `char_traits` (parcial)

[P0426R1](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0426r1.html) Alterações nas funções de membro `std::traits_type`, `length`, `compare` e `find` para tornar `std::string_view` utilizável em expressões de constante. (No Visual Studio 2017 versão 15.6, compatível somente com Clang/LLVM. Na versão 15.7 Preview 2, há compatibilidade quase concluída com ClXX também).

## <a name="improvements_159"></a> Melhorias no Visual Studio 2017 versão 15.9

### <a name="left-to-right-evaluation-order-for-operators-----and-"></a>Ordem de avaliação da esquerda para a direita para os operadores `->*`, `[]`, `>>` e `<<`

A partir do C++17, os operandos dos operadores `->*`, `[]`, `>>` e `<<` devem ser avaliados na ordem da esquerda para a direita. Há dois casos em que o compilador não conseguirá garantir esta ordem:

- quando uma das expressões do operando é um objeto passado por valor ou que contém um objeto passado por valor ou

- quando é compilado usando **/clr** e um dos operandos é um campo de um elemento de matriz ou objeto.

O compilador emite um aviso [C4866](https://docs.microsoft.com/cpp/error-messages/compiler-warnings/c4866?view=vs-2017) quando não é capaz de garantir a avaliação da esquerda para a direita. O compilador vai gerar esse aviso apenas se **/std:c++17** ou posterior for especificado, já que o requisito de ordem da esquerda para direita desses operadores foi introduzido no C++17.

Para tratar desse aviso, considere primeiro se a avaliação da esquerda para a direita dos operandos é necessária; por exemplo, quando a avaliação dos operandos pode produzir efeitos colaterais dependentes da ordem. Em muitos casos, a ordem em que os operandos são avaliados não tem efeitos observáveis. Se a ordem da avaliação precisar ser da esquerda para a direita, considere se não é possível passar os operandos por referência const. Essa alteração elimina o aviso no seguinte exemplo de código:

```cpp
// C4866.cpp
// compile with: /w14866 /std:c++17

class HasCopyConstructor
{
public:
    int x;

    HasCopyConstructor(int x) : x(x) {}
    HasCopyConstructor(const HasCopyConstructor& h) : x(h.x) { }
};

int operator>>(HasCopyConstructor a, HasCopyConstructor b) { return a.x >> b.x; }

// This version of operator>> does not trigger the warning:
// int operator>>(const HasCopyConstructor& a, const HasCopyConstructor& b) { return a.x >> b.x; }

int main()
{
    HasCopyConstructor a{ 1 };
    HasCopyConstructor b{ 2 };

    a>>b;        // C4866 for call to operator>>
};
```

## <a name="update_150"></a> Correções de bugs no Visual Studio 2017 RTW (versão 15.0)

### <a name="copy-list-initialization"></a>Inicialização de lista de cópia

O Visual Studio 2017 gera corretamente erros de compilador relacionados à criação de objetos usando listas de inicializador que não foram detectadas no Visual Studio 2015 e que podem causar falhas ou comportamento indefinido do tempo de execução. De acordo com a N4594 13.3.1.7p1, na inicialização de lista de cópia, o compilador deverá considerar um construtor explícito para resolução de sobrecarga, mas deverá gerar um erro se essa sobrecarga específica for escolhida.

Os dois exemplos a seguir são compilados no Visual Studio 2015, mas não no Visual Studio 2017.

```cpp
struct A
{
    explicit A(int) {}
    A(double) {}
};

int main()
{
    A a1 = { 1 }; // error C3445: copy-list-initialization of 'A' cannot use an explicit constructor
    const A& a2 = { 1 }; // error C2440: 'initializing': cannot convert from 'int' to 'const A &'

}
```

Para corrigir o erro, use a inicialização direta:

```cpp
A a1{ 1 };
const A& a2{ 1 };
```

No Visual Studio 2015, o compilador tratou a inicialização de lista de cópia de maneira incorreta da mesma maneira que a inicialização de cópia regular; ele considerou somente a conversão de construtores para a resolução de sobrecarga. No exemplo a seguir, o Visual Studio 2015 escolhe MyInt(23), mas o Visual Studio 2017 gera o erro corretamente.

```cpp
// From http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_closed.html#1228
struct MyStore {
    explicit MyStore(int initialCapacity);
};

struct MyInt {
    MyInt(int i);
};

struct Printer {
    void operator()(MyStore const& s);
    void operator()(MyInt const& i);
};

void f() {
    Printer p;
    p({ 23 }); // C3066: there are multiple ways that an object of this type can be called with these arguments
}
```

Esse exemplo é semelhante ao anterior, mas gera um erro diferente. Ele tem êxito no Visual Studio 2015 e falha no Visual Studio 2017 com C2668.

```cpp
struct A {
    explicit A(int) {}
};

struct B {
    B(int) {}
};

void f(const A&) {}
void f(const B&) {}

int main()
{
    f({ 1 }); // error C2668: 'f': ambiguous call to overloaded function
}
```

### <a name="deprecated-typedefs"></a>Typedefs preteridos

Agora o Visual Studio 2017 emite o aviso correto para typedefs preteridos declarados em uma classe ou em um struct. O exemplo a seguir é compilado sem avisos no Visual Studio 2015, mas gera C4996 no Visual Studio 2017.

```cpp
struct A
{
    // also for __declspec(deprecated)
    [[deprecated]] typedef int inttype;
};

int main()
{
    A::inttype a = 0; // C4996 'A::inttype': was declared deprecated
}
```

### `constexpr`

O Visual Studio 2017 gera corretamente um erro quando o operando esquerdo de uma operação de avaliação condicional não é válido em um contexto constexpr. O código a seguir é compilado no Visual Studio 2015, mas não no Visual Studio 2017 (C3615 a função constexpr 'f' não pode resultar em uma expressão de constante):

```cpp
template<int N>
struct array
{
    int size() const { return N; }
};

constexpr bool f(const array<1> &arr)
{
    return arr.size() == 10 || arr.size() == 11; // C3615
}
```

Para corrigir o erro, declare a função `array::size()` como `constexpr` ou remova o qualificador `constexpr` de `f`.

### <a name="class-types-passed-to-variadic-functions"></a>Tipos de classe passados para funções variadic

No Visual Studio de 2017, as classes ou structs passados para uma função variadic como printf devem ser facilmente copiados. Ao passar esses objetos, o compilador simplesmente faz uma cópia bit a bit e não chama o construtor nem o destruidor.

```cpp
#include <atomic>
#include <memory>
#include <stdio.h>

int main()
{
    std::atomic<int> i(0);
    printf("%i\n", i); // error C4839: non-standard use of class 'std::atomic<int>'
                        // as an argument to a variadic function.
                        // note: the constructor and destructor will not be called;
                        // a bitwise copy of the class will be passed as the argument
                        // error C2280: 'std::atomic<int>::atomic(const std::atomic<int> &)':
                        // attempting to reference a deleted function

    struct S {
        S(int i) : i(i) {}
        S(const S& other) : i(other.i) {}
        operator int() { return i; }
    private:
        int i;
    } s(0);
    printf("%i\n", s); // warning C4840 : non-portable use of class 'main::S'
                      // as an argument to a variadic function
}
```

Para corrigir o erro, é possível chamar uma função membro que retorna um tipo facilmente copiado,

```cpp
    std::atomic<int> i(0);
    printf("%i\n", i.load());
```

ou usa uma conversão estática para converter o objeto antes de passá-lo:

```cpp
    struct S {/* as before */} s(0);
    printf("%i\n", static_cast<int>(s))
```

Para cadeias de caracteres criadas e gerenciadas usando o CString, o `operator LPCTSTR()` fornecido deve ser usado para converter um objeto CString no ponteiro do C esperado pela cadeia de caracteres de formato.

```cpp
CString str1;
CString str2 = _T("hello!");
str1.Format(_T("%s"), static_cast<LPCTSTR>(str2));
```

### <a name="cv-qualifiers-in-class-construction"></a>Qualificadores CV na construção de classe

No Visual Studio 2015, às vezes, o compilador ignora incorretamente o qualificador CV ao gerar um objeto de classe por meio de uma chamada do construtor. Eventualmente, esse problema pode gerar uma falha ou comportamento inesperado do tempo de execução. O exemplo a seguir é compilado no Visual Studio 2015, mas gera um erro de compilador no Visual Studio 2017:

```cpp
struct S
{
    S(int);
    operator int();
};

int i = (const S)0; // error C2440
```

Para corrigir o erro, declare `operator int()` como `const`.

### <a name="access-checking-on-qualified-names-in-templates"></a>Verificação de acesso em nomes qualificados em modelos

As versões anteriores do compilador não verificavam o acesso a nomes qualificados em alguns contextos de modelo. Esse problema pode interferir no comportamento SFINAE esperado, em que a substituição deve falhar devido à inacessibilidade de um nome. Eventualmente, isso poderia ter causado uma falha ou comportamento inesperado no tempo de execução porque o compilador chamou incorretamente a sobrecarga errada do operador. No Visual Studio 2017, é gerado um erro do compilador. O erro específico pode variar, mas geralmente é "C2672 nenhuma função sobrecarregada correspondente encontrada". O código a seguir é compilado no Visual Studio 2015, mas gera um erro no Visual Studio 2017:

```cpp
#include <type_traits>

template <class T> class S {
    typedef typename T type;
};

template <class T, std::enable_if<std::is_integral<typename S<T>::type>::value, T> * = 0>
bool f(T x);

int main()
{
    f(10); // C2672: No matching overloaded function found.
}
```

### <a name="missing-template-argument-lists"></a>Listas de argumentos de modelo ausentes

No Visual Studio 2015 e anteriores, o compilador não diagnosticava listas de argumentos de modelo ausentes quando o modelo era exibido em uma lista de parâmetros de modelo, por exemplo, como parte de um argumento de modelo padrão ou um parâmetro de não tipo de modelo. Esse problema pode resultar em comportamento imprevisível, incluindo falhas do compilador ou comportamento inesperado do tempo de execução. O código a seguir é compilado no Visual Studio 2015, mas produz um erro no Visual Studio 2017.

```cpp
template <class T> class ListNode;
template <class T> using ListNodeMember = ListNode<T> T::*;
template <class T, ListNodeMember M> class ListHead; // C2955: 'ListNodeMember': use of alias
                                                     // template requires template argument list

// correct:  template <class T, ListNodeMember<T> M> class ListHead;
```

### <a name="expression-sfinae"></a>Expressão SFINAE

Para dar suporte à expressão SFINAE, agora o compilador analisa argumentos `decltype` quando os modelos são declarados em vez de instanciados. Consequentemente, se uma especialização não dependente for encontrada no argumento decltype, ela não será adiada para a hora da instanciação. Ela será processada imediatamente, e qualquer erro resultante será diagnosticado nesse momento.

O exemplo a seguir mostra esse erro do compilador gerado no momento da declaração:

```cpp
#include <utility>
template <class T, class ReturnT, class... ArgsT>
class IsCallable
{
public:
    struct BadType {};

    template <class U>
    static decltype(std::declval<T>()(std::declval<ArgsT>()...)) Test(int); //C2064. Should be declval<U>

    template <class U>
    static BadType Test(...);

    static constexpr bool value = std::is_convertible<decltype(Test<T>(0)), ReturnT>::value;
};

constexpr bool test1 = IsCallable<int(), int>::value;
static_assert(test1, "PASS1");
constexpr bool test2 = !IsCallable<int*, int>::value;
static_assert(test2, "PASS2");
```

### <a name="classes-declared-in-anonymous-namespaces"></a>Classes declaradas em namespaces anônimos

De acordo com o padrão C++, uma classe declarada dentro de um namespace anônimo tem vinculação interna, e isso significa que ela não pode ser exportada. No Visual Studio 2015 e anteriores, essa regra não era aplicada. No Visual Studio 2017, a regra é parcialmente aplicada. O exemplo a seguir gera este erro no Visual Studio 2017: "erro C2201: const anonymous namespace::S1::vftable: deve ter vinculação externa para poder ser exportado/importado".

```cpp
struct __declspec(dllexport) S1 { virtual void f() {} }; //C2201
```

### <a name="default-initializers-for-value-class-members-ccli"></a>Inicializadores padrão para membros de classe de valor (C++/CLI)

No Visual Studio 2015 e nas versões anteriores, o compilador permitia (mas ignorava) um inicializador de membro padrão para um membro de uma classe de valor. A inicialização padrão de uma classe de valor sempre inicializa os membros em zero. Não é permitido um construtor padrão. No Visual Studio 2017, os inicializadores de membro padrão geram um erro de compilador, conforme mostrado neste exemplo:

```cpp
value struct V
{
    int i = 0; // error C3446: 'V::i': a default member initializer
               // isn't allowed for a member of a value class
};
```

### <a name="default-indexers-ccli"></a>Indexadores padrão (C++/CLI)

No Visual Studio 2015 e em versões anteriores, o compilador, em alguns casos, identificava incorretamente uma propriedade padrão como um indexador padrão. É possível resolver o problema usando o identificador `default` para acessar a propriedade. A solução em si se tornou um problema depois que `default` foi introduzido como uma palavra-chave no C++ 11. No Visual Studio 2017, os bugs que exigiam a solução alternativa foram corrigidos, e agora o compilador gera um erro quando o `default` é usado para acessar a propriedade padrão de uma classe.

```cpp
//class1.cs

using System.Reflection;
using System.Runtime.InteropServices;

namespace ClassLibrary1
{
    [DefaultMember("Value")]
    public class Class1
    {
        public int Value
        {
            // using attribute on the return type triggers the compiler bug
            [return: MarshalAs(UnmanagedType.I4)]
            get;
        }
    }
    [DefaultMember("Value")]
    public class Class2
    {
        public int Value
        {
            get;
        }
    }
}

// code.cpp
#using "class1.dll"

void f(ClassLibrary1::Class1 ^r1, ClassLibrary1::Class2 ^r2)
{
       r1->Value; // error
       r1->default;
       r2->Value;
       r2->default; // error
}
```

No Visual Studio de 2017, é possível acessar ambas as propriedades Value pelo nome:

```cpp
#using "class1.dll"

void f(ClassLibrary1::Class1 ^r1, ClassLibrary1::Class2 ^r2)
{
       r1->Value;
       r2->Value;
}
```

## <a name="update_153"></a> Correções de bugs no Visual Studio 2017 versão 15.3

### <a name="calls-to-deleted-member-templates"></a>Chamadas para modelos de membros excluídos

Nas versões anteriores do Visual Studio, em alguns casos, o compilador falha ao emitir um erro para chamadas malformadas para um modelo de membro excluído que poderia potencialmente causar falhas no tempo de execução. Agora, o código a seguir produz C2280, "'int S\<int>::f\<int>(void)': tentativa de fazer referência a uma função excluída":

```cpp
template<typename T>
struct S {
   template<typename U> static int f() = delete;
};

void g()
{
   decltype(S<int>::f<int>()) i; // this should fail
}
```

Para corrigir o erro, declare `i` como `int`.

### <a name="pre-condition-checks-for-type-traits"></a>Verificações de pré-condição para características de tipo

O Visual Studio 2017 versão 15.3 melhora as verificações de pré-condição para características de tipo para seguir o padrão mais estritamente. Uma verificação assim destina-se aos atribuíveis. O código a seguir produz C2139 no Visual Studio 2017 versão 15.3:

```cpp
struct S;
enum E;

static_assert(!__is_assignable(S, S), "fail"); // C2139 in 15.3
static_assert(__is_convertible_to(E, E), "fail"); // C2139 in 15.3
```

### <a name="new-compiler-warning-and-runtime-checks-on-native-to-managed-marshaling"></a>Novas verificações de tempo de execução e o aviso do compilador em marshaling nativo para gerenciado

Chamar desde funções gerenciadas a funções nativas requer o marshaling. O CLR faz marshaling, mas não entende a semântica do C++. Se você passar um objeto nativo por valor, o CLR chamará o construtor de cópia do objeto ou usará `BitBlt`, o que poderá causar um comportamento indefinido em tempo de execução.

Agora, o compilador emitirá um aviso se puder saber em tempo de compilação que um objeto nativo com o construtor de cópia excluído será passado entre limites nativos e gerenciados por valor. Nos casos em que o compilador não souber no tempo de compilação, ele injetará uma verificação de tempo de execução para que o programa chame `std::terminate` imediatamente quando um marshaling malformado ocorrer. No Visual Studio 2017 versão 15.3, o código a seguir produz o aviso C4606 "'A': passar o argumento por valor entre limites nativo e gerenciado exige um construtor de cópia válido. Caso contrário, o comportamento de tempo de execução é indefinido.

```cpp
class A
{
public:
   A() : p_(new int) {}
   ~A() { delete p_; }

   A(A const &) = delete;
   A(A &&rhs) {
   p_ = rhs.p_;
}

private:
   int *p_;
};

#pragma unmanaged

void f(A a)
{
}

#pragma managed

int main()
{
    f(A()); // This call from managed to native requires marshaling. The CLR doesn't understand C++ and uses BitBlt, which results in a double-free later.
}
```

Para corrigir o erro, remova a diretiva `#pragma managed` para marcar o chamador como nativo e evitar marshaling.

### <a name="experimental-api-warning-for-winrt"></a>Aviso de API experimental para WinRT

As APIs do WinRT lançadas para experimentação e comentários são decoradas com `Windows.Foundation.Metadata.ExperimentalAttribute`. No Visual Studio 2017 versão 15.3, o compilador gera o aviso C4698 quando encontrar o atributo. Algumas APIs em versões anteriores do SDK do Windows já tinham sido decoradas com o atributo, e chamadas para essas APIs agora começam a disparar esse aviso do compilador. Os SDKs do Windows mais recentes têm o atributo removido de todos os tipos enviados, porém, se estiver usando um SDK mais antigo, você precisará suprimir esses avisos de todas as chamadas para tipos enviados.

O código a seguir produz o aviso C4698: "'Windows::Storage::IApplicationDataStatics2::GetForUserAsync' é para fins de avaliação e está sujeito a alteração ou remoção em atualizações futuras":

```cpp
Windows::Storage::IApplicationDataStatics2::GetForUserAsync(); //C4698
```

Para desabilitar o aviso, adicione um #pragma:

```cpp
#pragma warning(push)
#pragma warning(disable:4698)

Windows::Storage::IApplicationDataStatics2::GetForUserAsync();

#pragma warning(pop)
```

### <a name="out-of-line-definition-of-a-template-member-function"></a>Definição fora da linha de uma função de membro de modelo

O Visual Studio 2017 versão 15.3 produz um erro ao encontrar uma definição fora da linha de uma função de membro de modelo que não foi declarada na classe. Agora, o código a seguir produz o erro C2039: 'f': não é membro de 'S':

```cpp
struct S {};

template <typename T>
void S::f(T t) {} //C2039: 'f': is not a member of 'S'
```

Para corrigir o erro, adicione uma declaração à classe:

```cpp
struct S {
    template <typename T>
    void f(T t);
};
template <typename T>
void S::f(T t) {}
```

### <a name="attempting-to-take-the-address-of-this-pointer"></a>Tentar obter o endereço do ponteiro `this`

No C++, `this` é um prvalue do tipo ponteiro para X. Você não pode obter o endereço de `this` nem associá-lo a uma referência de lvalue. Nas versões anteriores do Visual Studio, o compilador permitia contornar essa restrição com o uso de uma conversão. No Visual Studio 2017 versão 15.3, o compilador produz o erro C2664.

### <a name="conversion-to-an-inaccessible-base-class"></a>Conversão em uma classe base inacessível

O Visual Studio 2017 versão 15.3 gera um erro quando você tenta converter um tipo em uma classe base que está inacessível. O compilador agora gera "erro C2243: 'conversão de tipo': a conversão de 'D *' em 'B *' existe, mas está inacessível". O código a seguir está malformado e poderá causar uma falha em tempo de execução. Agora, o compilador produz C2243 ao encontrar código como este:

```cpp
#include <memory>

class B { };
class D : B { }; // C2243. should be public B { };

void f()
{
   std::unique_ptr<B>(new D());
}
```

### <a name="default-arguments-arent-allowed-on-out-of-line-definitions-of-member-functions"></a>Os argumentos padrão não são permitidos em definições fora de linha de funções de membro

Os argumentos padrão não são permitidos em definições fora da linha de funções de membro em classes de modelo. O compilador emitirá um aviso em **/permissive** e um erro de hardware em **/permissive-** .

Nas versões anteriores do Visual Studio, o código malformado a seguir pode causar uma falha de tempo de execução. Visual Studio 2017 versão 15.3 produz o aviso C5034: 'A\<T>::f': uma definição fora de linha de um membro de um modelo de classe não pode ter argumentos padrão:

```cpp
template <typename T>
struct A {
    T f(T t, bool b = false);
};

template <typename T>
T A<T>::f(T t, bool b = false) // C5034
{
    // ...
}
```

Para corrigir o erro, remova o argumento padrão `= false`.

### <a name="use-of-offsetof-with-compound-member-designator"></a>Uso de `offsetof` com o designador de membro composto

No Visual Studio 2017 versão 15.3, usar `offsetof(T, m)`, em que *m* é um “designador membro composto", resulta em um aviso quando você compilar com a opção **/Wall**. O código a seguir está malformado e pode causar falhas em tempo de execução. O Visual Studio 2017 versão 15.3 produz o "aviso C4841: extensão não padrão usada: designador de membro composto em offsetof":

```cpp
struct A {
   int arr[10];
};

// warning C4841: non-standard extension used: compound member designator in offsetof
constexpr auto off = offsetof(A, arr[2]);
```

Para corrigir o código, desabilite o aviso com um pragma ou altere o código para não usar `offsetof`:

```cpp
#pragma warning(push)
#pragma warning(disable: 4841)
constexpr auto off = offsetof(A, arr[2]);
#pragma warning(pop)
```

### <a name="using-offsetof-with-static-data-member-or-member-function"></a>Uso de `offsetof` com o membro de dados estáticos ou função de membro

No Visual Studio 2017 versão 15.3, usar `offsetof(T, m)`, em que *m* se refere a um membro de dados estático ou uma função de membro, resultará em um erro. O seguinte código produz o "erro C4597: comportamento indefinido: offsetof aplicado à função de membro 'example'" e "erro C4597: comportamento indefinido: offsetof aplicado ao membro de dados estáticos 'sample'":

```cpp
#include <cstddef>

struct A {
   int ten() { return 10; }
   static constexpr int two = 2;
};

constexpr auto off = offsetof(A, ten);
constexpr auto off2 = offsetof(A, two);
```

Esse código está malformado e pode causar falhas em tempo de execução. Para corrigir o erro, altere o código para não invocar mais um comportamento indefinido. Esse é o código não portátil que não é permitido pelo padrão C++.

### <a name="declspec"></a> Novo aviso em atributos `__declspec`

No Visual Studio 2017 versão 15.3, o compilador não ignora os atributos se `__declspec(...)` é aplicado antes da especificação de vinculação `extern "C"`. Anteriormente, o compilador ignorava o atributo, o que podia ter implicações de tempo de execução. Quando as opções **/Wall** e **/WX** são definidas, o código a seguir produz o "aviso C4768: atributos __declspec antes da especificação de vinculação são ignorados":

```cpp
__declspec(noinline) extern "C" HRESULT __stdcall //C4768
```

Para corrigir o aviso, coloque `extern "C"` primeiro:

```cpp
extern "C" __declspec(noinline) HRESULT __stdcall
```

Esse aviso é desativado por padrão na versão 15.3, mas ativado por padrão na 15.5, e só afeta o código compilado com **/Wall** **/WX**.

### <a name="decltype-and-calls-to-deleted-destructors"></a>`decltype` e chamadas para destruidores excluídos

Nas versões anteriores do Visual Studio, o compilador não detectava quando ocorria uma chamada para um destruidor excluído no contexto de expressão associada a `decltype`. No Visual Studio 2017 versão 15.3, o código a seguir produz "erro C2280: 'A\<T>::~A(void)': tentando fazer referência a uma função excluída":

```cpp
template<typename T>
struct A
{
   ~A() = delete;
};

template<typename T>
auto f() -> A<T>;

template<typename T>
auto g(T) -> decltype((f<T>()));

void h()
{
   g(42);
}
```

### <a name="uninitialized-const-variables"></a>Variáveis constantes não inicializadas

O Visual Studio 2017 RTW teve uma regressão em que o compilador do C++ não emitia um diagnóstico se uma variável `const` não fosse inicializada. Essa regressão foi corrigida no Visual Studio 2017 versão 15.3. O código a seguir agora produz "aviso C4132: 'Value': objeto const deve ser inicializado":

```cpp
const int Value; //C4132
```

Para corrigir o erro, atribua um valor a `Value`.

### <a name="empty-declarations"></a>Declarações vazias

O Visual Studio 2017 versão 15.3 agora avisa sobre declarações vazias para todos os tipos, não apenas tipos internos. Agora, o código a seguir produz um aviso C4091 de nível 2 para todas as quatro declarações:

```cpp
struct A {};
template <typename> struct B {};
enum C { c1, c2, c3 };

int;    // warning C4091 : '' : ignored on left of 'int' when no variable is declared
A;      // warning C4091 : '' : ignored on left of 'main::A' when no variable is declared
B<int>; // warning C4091 : '' : ignored on left of 'B<int>' when no variable is declared
C;      // warning C4091 : '' : ignored on left of 'C' when no variable is declared
```

Para remover os avisos, comente ou remova as declarações vazias. Em casos em que o objeto não nomeado se destinar a ter um efeito colateral (como RAII), ele deverá receber um nome.

O aviso é excluído em **/Wv:18** e é ativado por padrão em W2 de nível de aviso.

### <a name="stdisconvertible-for-array-types"></a>`std::is_convertible` para tipos de matriz

As versões anteriores do compilador forneciam resultados incorretos para [std::is_convertible](../standard-library/is-convertible-class.md) para tipos de matriz. Isso exigia que gravadores de biblioteca tratassem o compilador do Microsoft C++ de forma especial ao usar a característica de tipo `std::is_convertible<...>`. No exemplo a seguir, as declarações de estática passam em versões anteriores do Visual Studio, mas falham no Visual Studio 2017 versão 15.3:

```cpp
#include <type_traits>

using Array = char[1];

static_assert(std::is_convertible<Array, Array>::value);
static_assert(std::is_convertible<const Array, const Array>::value, "");
static_assert(std::is_convertible<Array&, Array>::value, "");
static_assert(std::is_convertible<Array, Array&>::value, "");
```

`std::is_convertible<From, To>` é calculada para verificar se uma definição de função imaginária está bem formada:

```cpp
   To test() { return std::declval<From>(); }
```

### <a name="private-destructors-and-stdisconstructible"></a>Destruidores privados e `std::is_constructible`

As versões anteriores do compilador ignoravam se um destruidor era particular quando decidia o resultado de [std::is_constructible](../standard-library/is-constructible-class.md). Agora ele os considera. No exemplo a seguir, as declarações de estática passam em versões anteriores do Visual Studio, mas falham no Visual Studio 2017 versão 15.3:

```cpp
#include <type_traits>

class PrivateDtor {
   PrivateDtor(int) { }
private:
   ~PrivateDtor() { }
};

// This assertion used to succeed. It now correctly fails.
static_assert(std::is_constructible<PrivateDtor, int>::value);
```

Os destruidores particulares fazem com que um tipo não seja construível. `std::is_constructible<T, Args...>` é calculada como se a declaração a seguir estivesse escrita:

```cpp
   T obj(std::declval<Args>()...)
```

Essa chamada implica em uma chamada de destruidor.

### <a name="c2668-ambiguous-overload-resolution"></a>C2668: Resolução de sobrecarga ambígua

As versões anteriores do compilador falhavam algumas vezes ao detectar ambiguidade quando encontravam vários candidatos, tanto por meio de declarações using quanto de pesquisas dependentes de argumento. Essa falha pode levar à escolha errada de sobrecarga e ao comportamento inesperado de tempo de execução. No exemplo a seguir, o Visual Studio 2017 versão 15.3 aciona corretamente o C2668 'f': chamada ambígua à função sobrecarregada:

```cpp
namespace N {
   template<class T>
   void f(T&, T&);

   template<class T>
   void f();
}

template<class T>
void f(T&, T&);

struct S {};
void f()
{
   using N::f;

   S s1, s2;
   f(s1, s2); // C2668
}
```

Para corrigir o código, remova o uso da instrução `N::f` se você pretende chamar `::f()`.

### <a name="c2660-local-function-declarations-and-argument-dependent-lookup"></a>C2660: declarações de função locais e pesquisa dependente de argumento

As declarações de função local ocultam a declaração de função no escopo delimitador e desabilitam a pesquisa dependente de argumento. No entanto, as versões anteriores do compilador executavam a pesquisa dependente de argumento nesse caso, possivelmente resultando na escolha errada de sobrecarga e em comportamento inesperado de tempo de execução. Normalmente, o erro é devido a uma assinatura incorreta da declaração da função local. No exemplo a seguir, o Visual Studio 2017 versão 15.3 aciona corretamente C2660 'f': função não recebe dois argumentos:

```cpp
struct S {};
void f(S, int);

void g()
{
   void f(S); // C2660 'f': function does not take 2 arguments:
   // or void f(S, int);
   S s;
   f(s, 0);
}
```

Para corrigir o problema, altere a assinatura `f(S)` ou remova-a.

### <a name="c5038-order-of-initialization-in-initializer-lists"></a>C5038: ordem de inicialização em listas de inicializador

Os membros de classe são inicializados na ordem em que são declarados, e não na ordem em que aparecem em listas de inicializadores. As versões anteriores do compilador não avisavam quando a ordem da lista de inicializadores era diferente da ordem da declaração. Esse problema poderia resultar em comportamento indefinido de tempo de execução, caso a inicialização de um membro dependesse de outro membro na lista que já estivesse sendo inicializado. No exemplo a seguir, o Visual Studio 2017 versão 15.3 (com **/Wall**) aciona o "aviso C5038: membro de dados 'A::y' será inicializados após o membro de dados 'A::x'":

```cpp
struct A
{
    A(int a) : y(a), x(y) {} // Initialized in reverse, y reused
    int x;
    int y;
};
```

Para corrigir o problema, organize a lista do inicializador para que tenha a mesma ordem que as declarações. Um aviso semelhante é gerado quando um ou ambos os inicializadores fazem referência a membros de classe base.

Esse aviso está desativado por padrão e afeta somente o código compilado com **/Wall**.

## <a name="update_155"></a> Correções de bugs e outras alterações de comportamento no Visual Studio 2017 versão 15.5

### <a name="partial-ordering-change"></a>Alteração de ordenação parcial

O compilador agora rejeita corretamente o código a seguir e oferece a mensagem de erro correta:

```cpp
template<typename... T>
int f(T* ...)
{
    return 1;
}

template<typename T>
int f(const T&)
{
    return 2;
}

int main()
{
    int i = 0;
    f(&i);    // C2668
}
```

```Output
t161.cpp
t161.cpp(16): error C2668: 'f': ambiguous call to overloaded function
t161.cpp(8): note: could be 'int f<int*>(const T &)'
        with
        [
            T=int*
        ]
t161.cpp(2): note: or       'int f<int>(int*)'
t161.cpp(16): note: while trying to match the argument list '(int*)'
```

O problema no exemplo acima é que há duas diferenças nos tipos (const versus não const e pacote versus não pack). Para eliminar o erro do compilador, remova uma das diferenças. Isso permite ao compilador ordenar inequivocamente as funções.

```cpp
template<typename... T>
int f(T* ...)
{
    return 1;
}

template<typename T>
int f(T&)
{
    return 2;
}

int main()
{
    int i = 0;
    f(&i);
}
```

### <a name="exception-handlers"></a>Manipuladores de exceção

Manipuladores de referência para o tipo de matriz ou função nunca são uma correspondência para qualquer objeto de exceção. O compilador agora segue corretamente essa regra e aciona um aviso de nível 4. Ele também não corresponde mais a um manipulador de `char*` ou `wchar_t*` para um literal de cadeia de caracteres quando **/ZC: strictStrings** é usado.

```cpp
int main()
{
    try {
        throw "";
    }
    catch (int (&)[1]) {} // C4843 (This should always be dead code.)
    catch (void (&)()) {} // C4843 (This should always be dead code.)
    catch (char*) {} // This should not be a match under /Zc:strictStrings
}
```

```Output
warning C4843: 'int (&)[1]': An exception handler of reference to array or function type is unreachable, use 'int*' instead
warning C4843: 'void (__cdecl &)(void)': An exception handler of reference to array or function type is unreachable, use 'void (__cdecl*)(void)' instead
```

O código a seguir evita o erro:

```cpp
catch (int (*)[1]) {}
```

### O namespace <a name="tr1"></a> `std::tr1` é preterido

O namespace não padrão `std::tr1` está marcado como preterido nos modos C++14 e C++17. No Visual Studio 2017 versão 15.5, o código a seguir aciona C4996:

```cpp
#include <functional>
#include <iostream>
using namespace std;

int main() {
    std::tr1::function<int (int, int)> f = std::plus<int>(); //C4996
    cout << f(3, 5) << std::endl;
    f = std::multiplies<int>();
    cout << f(3, 5) << std::endl;
}
```

```Output
warning C4996: 'std::tr1': warning STL4002: The non-standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. You can define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to acknowledge that you have received this warning.
```

Para corrigir o erro, remova a referência ao namespace `tr1`:

```cpp
#include <functional>
#include <iostream>
using namespace std;

int main() {
    std::function<int (int, int)> f = std::plus<int>();
    cout << f(3, 5) << std::endl;
    f = std::multiplies<int>();
    cout << f(3, 5) << std::endl;
}
```

### <a name="annex_d"></a> Os recursos da biblioteca padrão no Anexo D são marcados como preteridos

Quando a opção do compilador do modo **/std:c++17** é definida, quase todos os recursos da biblioteca padrão do Anexo D são marcados como preteridos.

No Visual Studio 2017 versão 15.5, o código a seguir aciona C4996:

```cpp
#include <iterator>

class MyIter : public std::iterator<std::random_access_iterator_tag, int> {
public:
    // ... other members ...
};

#include <type_traits>

static_assert(std::is_same<MyIter::pointer, int*>::value, "BOOM");
```

```Output
warning C4996: 'std::iterator<std::random_access_iterator_tag,int,ptrdiff_t,_Ty*,_Ty &>::pointer': warning STL4015: The std::iterator class template (used as a base class to provide typedefs) is deprecated in C++17. (The <iterator> header is NOT deprecated.) The C++ standard has never required user-defined iterators to derive from std::iterator. To fix this warning, stop deriving from std::iterator and start providing publicly accessible typedefs named iterator_category, value_type, difference_type, pointer, and reference. Note that value_type is required to be non-const, even for constant iterators. You can define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.
```

Para corrigir o erro, siga as instruções no texto de aviso, conforme demonstrado no código a seguir:

```cpp
#include <iterator>

class MyIter {
public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef int value_type;
    typedef ptrdiff_t difference_type;
    typedef int* pointer;
    typedef int& reference;

    // ... other members ...
};

#include <type_traits>

static_assert(std::is_same<MyIter::pointer, int*>::value, "BOOM");
```

### <a name="unreferenced-local-variables"></a>Variáveis locais não referenciadas

No Visual Studio 15.5, o aviso C4189 é emitido em mais casos, conforme mostrado no código a seguir:

```cpp
void f() {
    char s[2] = {0}; // C4189. Either use the variable or remove it.
}
```

```Output
warning C4189: 's': local variable is initialized but not referenced
```

Para corrigir o erro, remova a variável não usada.

### <a name="single-line-comments"></a>Comentários de única linha

No Visual Studio 2017 versão 15.5, os avisos C4001 e C4179 não são emitidos pelo compilador C. Anteriormente, eles somente eram emitidos na opção do compilador **/Za**.  Os avisos não são mais necessários porque comentários de linha única fazem parte do padrão C desde C99.

```cpp
/* C only */
#pragma warning(disable:4001) //C4619
#pragma warning(disable:4179)
// single line comment
//* single line comment */
```

```Output
warning C4619: #pragma warning: there is no warning number '4001'
```

Se o código não precisar ser compatível com versões anteriores, você poderá evitar o aviso removendo a supressão de C4001/C4179. Se o código precisar ser compatível com versões anteriores, suprima somente C4619.

```C

/* C only */

#pragma warning(disable:4619)
#pragma warning(disable:4001)
#pragma warning(disable:4179)

// single line comment
/* single line comment */
```

### <a name="declspec-attributes-with-extern-c-linkage"></a>Atributos `__declspec` com vinculação `extern "C"`

Em versões anteriores do Visual Studio, o compilador ignorou atributos `__declspec(...)` quando `__declspec(...)` foi aplicado antes da especificação de vinculação `extern "C"`. Esse comportamento faz com que seja gerado código não pretendido pelo usuário, com possíveis consequências no tempo de execução. O aviso foi adicionado no Visual Studio versão 15.3, mas era desativado por padrão. No Visual Studio 2017 versão 15.5, o aviso está habilitado por padrão.

```cpp
__declspec(noinline) extern "C" HRESULT __stdcall //C4768
```

```Output
warning C4768: __declspec attributes before linkage specification are ignored
```

Para corrigir o erro, coloque a especificação de vinculação antes do atributo __declspec:

```cpp
extern "C" __declspec(noinline) HRESULT __stdcall
```

Esse novo aviso C4768 é determinado em alguns cabeçalhos do SDK do Windows que foram fornecidos com o Visual Studio 2017 15.3 ou anterior (por exemplo: versão 10.0.15063.0, também conhecido como SDK do RS2). No entanto, as versões posteriores dos cabeçalhos do SDK do Windows (especificamente, ShlObj.h e ShlObj_core.h) foram corrigidas para que não produzam o aviso. Quando você vir esse aviso proveniente de cabeçalhos do SDK do Windows, poderá executar estas ações:

1. Mude para o SDK do Windows mais recente que acompanha o Visual Studio 2017 versão 15.5.

1. Desligue o aviso ao redor de #include da instrução de cabeçalho do SDK do Windows:

```cpp
   #pragma warning (push)
   #pragma warning(disable:4768)
   #include <shlobj.h>
   #pragma warning (pop)
   ```

### <a name="extern_linkage"></a>Vinculação de constexpr externo

Em versões anteriores do Visual Studio, o compilador sempre forneceu uma ligação interna variável `constexpr`, mesmo quando a variável era marcada como `extern`. No Visual Studio 2017 versão 15.5, uma nova opção de compilador, ( **/Zc:externConstexpr**), habilita o comportamento correto em conformidade com os padrões. No fim das contas, esse comportamento se tornará o padrão.

```cpp
extern constexpr int x = 10;
```

```Output
error LNK2005: "int const x" already defined
```

Se um arquivo de cabeçalho contiver uma variável declarada `extern constexpr`, ele precisará ser marcado como `__declspec(selectany)` para que suas declarações duplicadas sejam combinadas corretamente:

```cpp
extern constexpr __declspec(selectany) int x = 10;
```

### <a name="typeid-cant-be-used-on-incomplete-class-type"></a>`typeid` não pode ser usado em tipo de classe incompleto

Em versões anteriores do Visual Studio, o compilador permitia incorretamente o código a seguir, resultando em informações de tipo potencialmente incorretas. No Visual Studio 2017 versão 15.5, o compilador produz corretamente um erro:

```cpp
#include <typeinfo>

struct S;

void f() { typeid(S); } //C2027 in 15.5
```

```Output
error C2027: use of undefined type 'S'
```

### <a name="stdisconvertible-target-type"></a>Tipo de destino de `std::is_convertible`

`std::is_convertible` requer que o tipo de destino seja um tipo de retorno válido. Em versões anteriores do Visual Studio, o compilador permitia incorretamente tipos abstratos, que podem levar à resolução de sobrecarga incorreta e ao comportamento de tempo de execução imprevisto.  O código a seguir agora aciona C2338 corretamente:

```cpp
#include <type_traits>

struct B { virtual ~B() = 0; };
struct D : public B { virtual ~D(); };

static_assert(std::is_convertible<D, B>::value, "fail"); // C2338 in 15.5
```

Para evitar o erro, você deve comparar tipos de ponteiro ao usar `is_convertible`, pois uma comparação de tipo que não é de ponteiro poderá falhar se um tipo for abstrato:

```cpp
#include <type_traits>

struct B { virtual ~B() = 0; };
struct D : public B { virtual ~D(); };

static_assert(std::is_convertible<D *, B *>::value, "fail");
```

### <a name="noexcept_removal"></a> Remoção de especificação de exceção dinâmica e `noexcept`

No C++ 17, `throw()` é um alias para `noexcept`, `throw(<type list>)` e `throw(...)` foram removidos e determinados tipos podem incluir `noexcept`. Essa mudança pode causar problemas de compatibilidade de origem com o código que está em conformidade com a C++14 ou anterior. A opção **/Zc:noexceptTypes-** pode ser usada para reverter para a versão C++14 do `noexcept` ao usar o modo C++17 em geral. Ela permite atualizar seu código-fonte para estar em conformidade com a C++17 sem precisar reescrever todo o código `throw()` ao mesmo tempo.

O compilador agora também diagnostica mais especificações de exceção incompatíveis em declarações no modo C++17 ou com **/permissive-** com o novo aviso C5043.

O código a seguir gera C5043 e C5040 no Visual Studio 2017 versão 15.5 quando a opção **/std:c++17** é aplicada:

```cpp
void f() throw(); // equivalent to void f() noexcept;
void f() {} // warning C5043
void g() throw(); // warning C5040

struct A {
    virtual void f() throw();
};

struct B : A {
    virtual void f() { } // error C2694
};
```

Para remover os erros enquanto estiver usando **/std:c++17**, adicione a opção **/Zc:noexceptTypes-** à linha de comando ou atualize o código para usar `noexcept`, conforme mostrado no exemplo a seguir:

```cpp
void f() noexcept;
void f() noexcept { }
void g() noexcept(false);

struct A {
    virtual void f() noexcept;
};

struct B : A {
    virtual void f() noexcept { }
};
```

### <a name="inline-variables"></a>Variáveis embutidas

Membros de dados constexpr estáticos agora são implicitamente embutidos, o que significa que sua declaração em uma classe agora é sua definição. Usar uma definição fora de linha para um membro de dados constexpr estáticos é redundante e agora está preterido. No Visual Studio 2017 versão 15.5, quando a opção **/std:c++17** é aplicada, o seguinte código agora produz o aviso C5041 *'size': a definição fora de linha para o membro de dados estáticos constexpr não é necessária e foi preterida no C++17*:

```cpp
struct X {
    static constexpr int size = 3;
};
const int X::size; // C5041
```

### <a name="extern-c-declspec-warning-c4768-now-on-by-default"></a>O aviso C4768 de `extern "C" __declspec(...)` agora está ativado por padrão

O aviso foi adicionado no Visual Studio versão 2017 versão 15.3, mas estava desativado por padrão. No Visual Studio 2017 versão 15.5, o aviso está ativo por padrão. Para saber mais, confira [Novo aviso sobre \_\_atributos declspec](#declspec).

### <a name="defaulted-functions-and-declspecnothrow"></a>Funções usadas como padrão e `__declspec(nothrow)`

O compilador permitia anteriormente que funções padronizadas fossem declaradas com `__declspec(nothrow)` quando as funções de base/membro correspondente permitiam exceções. Esse comportamento é contrário ao padrão C++ e pode causar um comportamento indefinido no tempo de execução. O padrão exige que tais funções sejam definidas como excluídas se houver uma incompatibilidade de especificação de exceção.  No **/std:c++17**, o código a seguir aciona um C2280 *tentativa de fazer referência a uma função excluída. A função foi excluída implicitamente porque a especificação de exceção explícita é incompatível com aquela da declaração implícita.*

```cpp
struct A {
    A& operator=(const A& other) { // No exception specification; this function may throw.
        ...
    }
};

struct B : public A {
    __declspec(nothrow) B& operator=(const B& other) = default;
};

int main()
{
    B b1, b2;
    b2 = b1; // error C2280
}
```

Para corrigir esse código, remova o __declspec(nothrow) da função padronizada ou o `= default` e forneça uma definição para a função juntamente com qualquer manipulação de exceção necessária:

```cpp
struct A {
    A& operator=(const A& other) {
        // ...
    }
};

struct B : public A {
    B& operator=(const B& other) = default;
};

int main()
{
    B b1, b2;
    b2 = b1;
}
```

### <a name="noexcept-and-partial-specializations"></a>Especializações parciais e `noexcept`

Com `noexcept` no sistema de tipos, as especializações parciais para correspondência de tipos "chamáveis" específicos podem falhar ao compilar ou escolher o modelo primário devido a uma especialização parcial ausente para funções de ponteiros para noexcept.

Nesses casos, pode ser necessário acrescentar especializações parciais adicionais para tratar os ponteiros de função `noexcept` e ponteiros `noexcept` para funções de membro. Essas sobrecargas só são válidas no modo **/std:c++17**. Se for necessário manter a compatibilidade com versões anteriores de C++14 e você estiver escrevendo código que outras pessoas consumirão, será necessário proteger essas novas sobrecargas dentro de diretivas `#ifdef`. Se você estiver trabalhando em um módulo independente, em vez de usar proteções `#ifdef`, será possível compilar apenas com a opção **/Zc:noexceptTypes-** .

O código a seguir é compilado em **/std:c++14**, mas falha em **/std:c++17** com "erro C2027: uso do tipo indefinido 'A\<T>'":

```cpp
template <typename T> struct A;

template <>
struct A<void(*)()>
{
    static const bool value = true;
};

template <typename T>
bool g(T t)
{
    return A<T>::value;
}

void f() noexcept {}

int main()
{
    return g(&f) ? 0 : 1; // C2027
}
```

O código a seguir terá êxito em **/std:c++17** porque o compilador escolhe a nova especialização parcial `A<void (*)() noexcept>`:

```cpp
template <typename T> struct A;

template <>
struct A<void(*)()>
{
    static const bool value = true;
};

template <>
struct A<void(*)() noexcept>
{
    static const bool value = true;
};

template <typename T>
bool g(T t)
{
    return A<T>::value;
}

void f() noexcept {}

int main()
{
    return g(&f) ? 0 : 1; // OK
}
```

## <a name="update_157"></a> Correções de bug e outras alterações de comportamento no Visual Studio 2017 versão 15.7

### <a name="c17-default-argument-in-the-primary-class-template"></a>C++17: Argumento padrão no modelo de classe primária

Essa alteração de comportamento é uma pré-condição para [Dedução de argumento de modelo para modelos de classe – P0091R3](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0091r3.html).

Anteriormente, o compilador ignorava o argumento padrão no modelo de classe primária:

```cpp
template<typename T>
struct S {
    void f(int = 0);
};

template<typename T>
void S<T>::f(int = 0) {} // Re-definition necessary
```

No modo **/std:c++17** do Visual Studio 2017 versão 15.7, o argumento padrão não é ignorado:

```cpp
template<typename T>
struct S {
    void f(int = 0);
};

template<typename T>
void S<T>::f(int) {} // Default argument is used
```

### <a name="dependent-name-resolution"></a>Resolução de nome dependente

Essa alteração de comportamento é uma pré-condição para [Dedução de argumento de modelo para modelos de classe – P0091R3](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0091r3.html).

No exemplo a seguir, o compilador do Visual Studio 15.6 e anterior resolve `D::type` como `B<T>::type` no modelo de classe primária.

```cpp
template<typename T>
struct B {
    using type = T;
};

template<typename T>
struct D : B<T*> {
    using type = B<T*>::type;
};
```

O Visual Studio 2017 versão 15.7, no modo **/std:c++17**, requer a palavra-chave `typename` na instrução `using` em D. Sem `typename`, o compilador gera um aviso C4346: *'B<T\*>::type': o nome dependente não é um tipo*  e erro C2061: *erro de sintaxe: identificador 'type'* :

```cpp
template<typename T>
struct B {
    using type = T;
};

template<typename T>
struct D : B<T*> {
    using type = typename B<T*>::type;
};
```

### <a name="c17-nodiscard-attribute---warning-level-increase"></a>C++17: Atributo `[[nodiscard]]` – aumento do nível de aviso

No Visual Studio 2017 versão 15.7 no modo **/std:c++17**, o nível de aviso de C4834 ("descartando o valor retornado da função com o atributo 'nodiscard'") é aumentado de W3 para W1. Você pode desabilitar o aviso com uma conversão para `void`, ou passando **/wd:4834** para o compilador

```cpp
[[nodiscard]] int f() { return 0; }

int main() {
    f(); // warning: discarding return value
         // of function with 'nodiscard'
}
```

### <a name="variadic-template-constructor-base-class-initialization-list"></a>Lista de inicialização de classe base do construtor de modelo Variadic

Em edições anteriores do Visual Studio, uma lista de inicialização de classe base do construtor de modelo variadic que não continha argumentos de modelos foi erroneamente permitida sem erro. No Visual Studio 2017 versão 15.7 é gerado um erro do compilador.

O exemplo de código a seguir no Visual Studio 2017 versão 15.7 gera *erro C2614: D\<int>: inicialização de membro ilícito: 'B' não é uma base ou um membro*

```cpp
template<typename T>
struct B {};

template<typename T>
struct D : B<T>
{

    template<typename ...C>
    D() : B() {} // C2614. Missing template arguments to B.
};

D<int> d;
```

Para corrigir o erro, altere a expressão de B() para B\<T>().

### <a name="constexpr-aggregate-initialization"></a>Inicialização de agregação de `constexpr`

As versões anteriores do compilador C++ tratavam incorretamente a inicialização de agregação de `constexpr`; ele aceitava o código inválido na qual a agregação init-list tinha muitos elementos e produzia um codegen incorreto para ele. O código a seguir é um exemplo desse código:

```cpp
#include <array>
struct X {
    unsigned short a;
    unsigned char b;
};

int main() {
    constexpr std::array<X, 2> xs = {
        { 1, 2 },
        { 3, 4 }
    };
    return 0;
}
```

No Visual Studio 2017 versão 15.7 atualização 3 e versões posteriores, o exemplo anterior agora gera o erro *C2078 muitos inicializadores*. O exemplo a seguir mostra como corrigir o código. Ao inicializar um `std::array` com chaves init-lists aninhadas, forneça para matriz interna uma lista entre chaves própria:

```cpp
#include <array>
struct X {
    unsigned short a;
    unsigned char b;
};

int main() {
    constexpr std::array<X, 2> xs = {{ // note double braces
        { 1, 2 },
        { 3, 4 }
    }}; // note double braces
    return 0;
}
```

## <a name="update_158"></a> Correções de bugs e alterações de comportamento no Visual Studio 2017 versão 15.8

Todas as alterações de compilador no Visual Studio 2017 versão 15.8 enquadram-se na categoria de correções de bugs e alterações de comportamento e estão listadas abaixo:

### <a name="typename-on-unqualified-identifiers"></a>`typename` em identificadores não qualificados

No modo [/permissive-](../build/reference/permissive-standards-conformance.md), palavras-chave `typename` falsas em identificadores não qualificados nas definições de modelo de alias não são mais aceitas pelo compilador. O código a seguir agora produz C7511 *'T': a palavra-chave 'typename' precisa ser seguida por um nome qualificado*:

```cpp
template <typename T>
using  X = typename T;
```

Para corrigir o erro, altere a segunda linha para `using  X = T;`.

### <a name="declspec-on-right-side-of-alias-template-definitions"></a>`__declspec()` no lado direito das definições de modelo de alias

[__declspec](../cpp/declspec.md) não é mais permitido no lado direito de uma definição de modelo de alias. Esse código anteriormente era aceito, mas ignorado pelo compilador, e nunca resultava em um aviso de reprovação quando o alias era usado.

O atributo [\[\[deprecated\]\]](../cpp/attributes.md) de C++ padrão pode ser usado nesse caso e é respeitado no Visual Studio 2017 versão 15.6. O código a seguir agora produz C2760 *erro de sintaxe: token inesperado '__declspec', era esperado 'type specifier'* :

```cpp
template <typename T>
using X = __declspec(deprecated("msg")) T;
```

Para corrigir o erro, altere o código da seguinte forma (com o atributo colocado antes de '=' da definição do alias):

```cpp
template <typename T>
using  X [[deprecated("msg")]] = T;
```

### <a name="two-phase-name-lookup-diagnostics"></a>Diagnóstico de pesquisa de nome em duas fases

A pesquisa de nome em duas fases requer que os nomes não dependentes usados nos corpos do modelo fiquem visíveis para o modelo no tempo de definição. Anteriormente, o compilador C++ da Microsoft deixaria um nome não encontrado como não pesquisado até o momento da instanciação. Agora, ele exige que os nomes não dependentes estejam vinculados no corpo do modelo.

Uma forma em que isso se manifesta é com a pesquisa em classes base dependentes. Anteriormente, o compilador permitia o uso de nomes definidos nas classes base dependentes porque a pesquisa deles acontecia durante o tempo de instanciação quando todos os tipos eram resolvidos. Agora, esse código é tratado como um erro. Nesses casos, você pode forçar a pesquisa da variável no tempo de instanciação qualificando-a com o tipo de classe base ou, de outro modo, tornando-a dependente, por exemplo, adicionando um ponteiro `this->`.

No modo **/permissive-** , o código a seguir agora gera C3861: *'base_value': identificador não encontrado*:

```cpp
template <class T>
struct Base {
    int base_value = 42;
};

template <class T>
struct S : Base<T> {
    int f() {
        return base_value;
    }
};
```

Para corrigir o erro, altere a instrução `return` para `return this->base_value;`.

**Observação:** Na biblioteca python Boost, já existe há algum tempo uma solução alternativa específica ao MSVC para uma declaração de encaminhamento de modelo no [unwind_type.hpp](https://github.com/boostorg/python/blame/develop/include/boost/python/detail/unwind_type.hpp). No modo [/permissive-](../build/reference/permissive-standards-conformance.md), a partir do Visual Studio 2017 versão 15.8 (_MSC_VER=1915), o compilador de MSVC faz a pesquisa de nome dependente de argumento (ADL) corretamente e é consistente com outros compiladores, tornando essa proteção alternativa desnecessária. Para evitar o erro *C3861: 'unwind_type': identificador não encontrado*, confira [PR 229](https://github.com/boostorg/python/pull/229) no repositório Boost para atualizar o arquivo de cabeçalho. Já aplicamos patch no pacote Boost [vcpkg](../build/vcpkg.md), portanto, se você obtiver ou atualizar suas fontes de Boost usando vcpkg, não será necessário aplicar o patch separadamente.

### <a name="forward-declarations-and-definitions-in-namespace-std"></a>Declarações e definições de encaminhamento no namespace `std`

O padrão C++ não permite que um usuário adicione declarações ou definições de encaminhamento no namespace `std`. A adição de declarações ou de definições ao namespace `std` ou a um namespace no namespace `std` agora resulta em um comportamento indefinido.

Em algum momento no futuro, a Microsoft mudará o local em que alguns tipos padrão são definidos. Essa mudança interromperá o código existente que adiciona as declarações de encaminhamento ao namespace `std`. Um novo aviso, o C4643, ajuda a identificar esses problemas de origem. O aviso está habilitado no modo **/default** e fica desativado por padrão. Ele afetará os programas que são compilados com **/Wall** ou **/WX**.

O código a seguir agora gera C4643: *O 'vector' da declaração de encaminhamento no namespace std não é permitido pelo C++ Standard*.

```cpp
namespace std {
    template<typename T> class vector;
}
```

Para corrigir o erro, use uma diretiva **include** em vez de uma declaração de encaminhamento:

```cpp
#include <vector>
```

### <a name="constructors-that-delegate-to-themselves"></a>Construtores que delegam a si mesmos

O padrão C++ sugere que um compilador deve emitir um diagnóstico quando um construtor de delegação delega a si mesmo. O compilador C++ da Microsoft nos modos [/std:c++17](../build/reference/std-specify-language-standard-version.md) e [/std:c++latest](../build/reference/std-specify-language-standard-version.md) agora gera C7535: *'X::X': construtor de delegação chama a si próprio*.

Sem esse erro, o programa a seguir será compilado, mas gerará um loop infinito:

```cpp
class X {
public:
    X(int, int);
    X(int v) : X(v){}
};
```

Para evitar o loop infinito, delegue para um construtor diferente:

```cpp
class X {
public:

    X(int, int);
    X(int v) : X(v, 0) {}
};
```

### <a name="offsetof-with-constant-expressions"></a>`offsetof` com expressões de constante

[offsetof](../c-runtime-library/reference/offsetof-macro.md) normalmente tem sido implementado usando uma macro que requer um [reinterpret_cast](../cpp/reinterpret-cast-operator.md). Esse uso não é válido em contextos que requerem uma expressão de constante, mas usualmente o compilador C++ da Microsoft tem permitido isso. A macro `offsetof` que é fornecida como parte da biblioteca padrão usa corretamente um compilador intrínseco ( **__builtin_offsetof**), mas muitas pessoas têm usado o truque da macro para definir seu próprio `offsetof`.

No Visual Studio 2017 versão 15.8, o compilador restringe as áreas em que esses operadores `reinterpret_cast` podem aparecer no modo padrão para ajudar o código a ficar em conformidade com o comportamento do C++ padrão. Em [/permissive-](../build/reference/permissive-standards-conformance.md), as restrições são ainda mais rígidas. O uso do resultado de um `offsetof` em locais que requerem expressões de constante pode resultar em um código que emite o aviso C4644 *uso do padrão offsetof baseado em macro em expressões de constantes não padrão; use offsetof definido na biblioteca padrão C++ em vez de* ou C2975 *argumento de modelo inválido, uma expressão de constante em tempo de compilação é esperada*.

O código a seguir gera C4644 nos modos **/default** e **/std:c++17** e C2975 no modo **/permissive-** :

```cpp
struct Data {
    int x;
};

// Common pattern of user-defined offsetof
#define MY_OFFSET(T, m) (unsigned long long)(&(((T*)nullptr)->m))

int main()

{
    switch (0) {
    case MY_OFFSET(Data, x): return 0;
    default: return 1;
    }
}
```

Para corrigir o erro, use `offsetof` conforme a definição por meio de \<cstddef>:

```cpp
#include <cstddef>

struct Data {
    int x;
};

int main()
{
    switch (0) {
    case offsetof(Data, x): return 0;
    default: return 1;
    }
}
```

### <a name="cv-qualifiers-on-base-classes-subject-to-pack-expansion"></a>qualificadores de cv em classes base sujeitos a expansão de pacote

As versões anteriores do compilador C++ da Microsoft não detectavam que uma classe base tinha qualificadores de cv se ele também estivesse sujeito à expansão do pacote.

No Visual Studio 2017 versão 15.8, no modo **/permissive-** o código a seguir gera C3770 *'const S': não é uma classe base válida*:

```cpp
template<typename... T>
class X : public T... { };

class S { };

int main()
{
    X<const S> x;
}
```

### <a name="template-keyword-and-nested-name-specifiers"></a>Palavra-chave `template` e especificadores de nome aninhados

No modo **/permissive-** , o compilador agora requer que a palavra-chave `template` preceda um nome de modelo quando ele vier depois de um especificador de nome aninhado dependente.

O seguinte código no modo **/permissive-** agora gera C7510: *'example': o uso do nome de modelo dependente precisa ser prefixado com 'template'. Observação: confira a referência à instanciação do modelo de classe ' X<T>' que está sendo compilado*:

```cpp
template<typename T> struct Base
{
    template<class U> void example() {}
};

template<typename T>
struct X : Base<T>
{
    void example()
    {
        Base<T>::example<int>();
    }
};
```

Para corrigir o erro, adicione a palavra-chave `template` à instrução `Base<T>::example<int>();`, conforme é mostrado no exemplo a seguir:

```cpp
template<typename T> struct Base
{
    template<class U> void example() {}
};

template<typename T>
struct X : Base<T>
{
    void example()
    {
        // Add template keyword here:
        Base<T>::template example<int>();
    }
};
```

## <a name="update_159"></a> Correções de bug e alterações de comportamento no Visual Studio 2017 versão 15.9

### <a name="identifiers-in-member-alias-templates"></a>Identificadores em modelos de alias de membro

Um identificador usado em uma definição de modelo de alias de membro precisa ser declarado antes de ser usado.

Nas versões anteriores do compilador, o código a seguir era permitido:

```cpp
template <typename... Ts>
struct A
{
  public:
    template <typename U>
    using from_template_t = decltype(from_template(A<U>{}));

  private:
    template <template <typename...> typename Type, typename... Args>
    static constexpr A<Args...> from_template(A<Type<Args...>>);
};

A<>::from_template_t<A<int>> a;
```

No Visual Studio 2017 versão 15.9, no modo **/permissive-** , o compilador gera C3861: *'from_template': identificador não encontrado*.

Para corrigir o erro, declare `from_template` antes de `from_template_t`.

### <a name="modules-changes"></a>Alterações nos módulos

No Visual Studio 2017, versão 15.9, o compilador gera C5050 sempre que as opções de linha de comando dos módulos não são consistentes entre os lados da criação do módulo e do consumo do módulo. No exemplo a seguir, há dois problemas:

- No lado do consumo (main.cpp), a opção **/EHsc** não está especificada.

- A versão do C++ é **/std:c++17** no lado da criação e **/std:c++14** no lado do consumo.

```cmd
cl /EHsc /std:c++17 m.ixx /experimental:module
cl /experimental:module /module:reference m.ifc main.cpp /std:c++14
```

O compilador gera C5050 para ambos os casos: *aviso C5050: Possível ambiente incompatível durante a importação do módulo 'm': versões incompatíveis do C++.  Versão do módulo "201402" atual "201703"* .

O compilador também gera C7536 sempre que o arquivo .ifc é adulterado. O cabeçalho da interface do módulo contém um hash SHA2 do conteúdo abaixo dele. Na importação, o arquivo .ifc é inserido em hash da mesma maneira e verificado em relação ao hash fornecido no cabeçalho. Se eles não corresponderem, será gerado o erro C7536: *falha nas verificações de integridade do ifc.  Esperado SHA2: '66d5c8154df0c71d4cab7665bab4a125c7ce5cb9a401a4d8b461b706ddd771c6'* .

### <a name="partial-ordering-involving-aliases-and-non-deduced-contexts"></a>Ordenação parcial envolvendo aliases e contextos não deduzidos

As implementações divergem nas regras de ordenação parciais que envolvem aliases em contextos não deduzidos. No exemplo a seguir, a GCC e o compilador de C++ da Microsoft (no modo **/permissive-** ) geram um erro, enquanto o Clang aceita o código.

```cpp
#include <utility>
using size_t = std::size_t;

template <typename T>
struct A {};
template <size_t, size_t>
struct AlignedBuffer {};
template <size_t len>
using AlignedStorage = AlignedBuffer<len, 4>;

template <class T, class Alloc>
int f(Alloc &alloc, const AlignedStorage<T::size> &buffer)
{
    return 1;
}

template <class T, class Alloc>
int f(A<Alloc> &alloc, const AlignedStorage<T::size> &buffer)
{
    return 2;
}

struct Alloc
{
    static constexpr size_t size = 10;
};

int main()
{
    A<void> a;
    AlignedStorage<Alloc::size> buf;
    if (f<Alloc>(a, buf) != 2)
    {
        return 1;
    }

    return 0;
}
```

O exemplo anterior gera C2668:

```Output
partial_alias.cpp(32): error C2668: 'f': ambiguous call to overloaded function
partial_alias.cpp(18): note: could be 'int f<Alloc,void>(A<void> &,const AlignedBuffer<10,4> &)'
partial_alias.cpp(12): note: or       'int f<Alloc,A<void>>(Alloc &,const AlignedBuffer<10,4> &)'
        with
        [
            Alloc=A<void>
        ]
partial_alias.cpp(32): note: while trying to match the argument list '(A<void>, AlignedBuffer<10,4>)'
```

A divergência de implementação se deve a uma regressão na expressão do padrão C++. A resolução para edição de núcleo de 2235 removeu algum texto que permitiria que essas sobrecargas fossem ordenadas. O padrão C++ atual não fornece um mecanismo para ordenar parcialmente essas funções, portanto, elas são consideradas ambíguas.

Como solução alternativa, é recomendável não depender de ordenação parcial para resolver esse problema. Em vez disso, use SFINAE para remover sobrecargas específicas. No exemplo a seguir, usamos uma classe auxiliar `IsA` para remover a primeira sobrecarga quando `Alloc` é uma especialização de `A`:

```cpp
#include <utility>
using size_t = std::size_t;

template <typename T>
struct A {};
template <size_t, size_t>
struct AlignedBuffer {};
template <size_t len>
using AlignedStorage = AlignedBuffer<len, 4>;

template <typename T> struct IsA : std::false_type {};
template <typename T> struct IsA<A<T>> : std::true_type {};

template <class T, class Alloc, typename = std::enable_if_t<!IsA<Alloc>::value>>
int f(Alloc &alloc, const AlignedStorage<T::size> &buffer)
{
    return 1;
}

template <class T, class Alloc>
int f(A<Alloc> &alloc, const AlignedStorage<T::size> &buffer)
{
    return 2;
}

struct Alloc
{
    static constexpr size_t size = 10;
};

int main()
{
    A<void> a;
    AlignedStorage<Alloc::size> buf;
    if (f<Alloc>(a, buf) != 2)
    {
        return 1;
    }

    return 0;
}
```

### <a name="illegal-expressions-and-non-literal-types-in-templated-function-definitions"></a>Expressões ilegais e tipos não literais em definições de função com modelo

Expressões ilegais e tipos não literais agora são diagnosticados corretamente nas definições de funções com modelo especializadas explicitamente. Anteriormente, esses erros não eram emitidos para a definição da função. No entanto, o tipo não literal ou a expressão ilegal ainda teria sido diagnosticado se avaliado como parte de uma expressão de constante.

Em versões anteriores do Visual Studio, o seguinte código é compilado sem aviso:

```cpp
void g();

template<typename T>
struct S
{
    constexpr void f();
};
  
template<>
constexpr void S<int>::f()
{
    g(); // C3615 in 15.9
}
```

No Visual Studio 2017 versão 15.9, o código aciona este erro:

```Output
error C3615: constexpr function 'S<int>::f' cannot result in a constant expression.
note: failure was caused by call of undefined function or one not declared 'constexpr'
note: see usage of 'g'.
```

Para evitar o erro, remova o qualificador `constexpr` da instanciação explícita da função `f()`.

::: moniker-end

## <a name="c-conformance-improvements-in-visual-studio-2015"></a>Aprimoramentos de conformidade do C++ no Visual Studio 2015

Para obter uma lista das melhorias de conformidade até o Visual Studio 2015, Atualização 3, consulte [Visual C++ What's New 2003 through 2015 (Novidades do Visual C++ 2003 a 2015)](/cpp/porting/visual-cpp-what-s-new-2003-through-2015).

## <a name="see-also"></a>Consulte também

[Conformidade com a linguagem Visual C++](../visual-cpp-language-conformance.md)
