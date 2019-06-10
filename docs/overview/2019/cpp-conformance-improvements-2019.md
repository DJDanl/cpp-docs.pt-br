---
title: Aprimoramentos de conformidade do C++
ms.date: 05/16/2019
description: O Microsoft C++ no Visual Studio 2019 está progredindo em direção à plena conformidade com o padrão de linguagem C++20.
ms.technology: cpp-language
author: mikeblome
ms.author: mblome
ms.openlocfilehash: 02b778f10ad94342c922a4e79a856cc2a7d53076
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "66451212"
---
# <a name="c-conformance-improvements-in-visual-studio-2019-rtw-and-version-161improvements161"></a>Melhorias na conformidade do C++ no Visual Studio 2019 RTW e na versão [16.1](#improvements_161)

## <a name="improvements-in-visual-studio-2019-rtw"></a>Melhorias no Visual Studio 2019 RTW

O Visual Studio 2019 RTW contém as seguintes melhorias de conformidade, correções de bug e alterações de comportamento no compilador do Microsoft C++ (MSVC).

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

### <a name="partial-support-for-operator-"></a>Suporte parcial para o operador <=>

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

Para evitar os erros, insira um espaço na linha incorreta antes do colchete final: `U<&S::operator<= > u;`.

### <a name="references-to-types-with-mismatched-cv-qualifiers"></a>Referências a tipos sem qualificadores CV incompatíveis

Anteriormente, o MSVC permitia associação direta de uma referência de um tipo com qualificadores CV incompatíveis abaixo do nível superior. Isso poderia permitir a modificação de dados supostamente const referenciados pela referência e agora o compilador cria um temporário, conforme exigido pelo padrão. No Visual Studio 2017, o código a seguir é compilado sem avisos. No Visual Studio 2019, o compilador gera o *aviso C4172: \<func:#1 "?PData@X@@QBEABQBXXZ"> retornando o endereço de uma variável local ou temporário*.

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

O argumento para `reinterpret_cast` não é um dos contextos nos quais o endereço de uma função sobrecarregada é permitido. O código a seguir é compilado sem erros no Visual Studio 2017, mas no Visual Studio 2019, ele gera *C2440: não é possível converter de 'overloaded-function' em 'fp'* :

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

No C++ 14, os tipos de fechamento lambda não são literais. A consequência principal dessa regra é que o lambda não pode ser atribuído a uma variável `constexpr`. O código a seguir é compilado sem erros no Visual Studio 2017, mas no Visual Studio 2019, gera *C2127: 'l': inicialização inválida da entidade 'constexpr' com uma expressão que não é constante*:

```cpp
int main()
{
    constexpr auto l = [] {}; // C2127 in VS2019
}
```

Para evitar o erro, remova o qualificador `constexpr` ou altere o modo de conformidade para `/std:c++17`.

### <a name="stdcreatedirectory-failure-codes"></a>Códigos de falha std::create_directory

[P1164](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1164r1.pdf) implementado de C++20 incondicionalmente. Isso altera `std::create_directory` para verificar se o destino já foi um diretório em caso de falha. Anteriormente, todos os erros do tipo ERROR_ALREADY_EXISTS foram convertidos em códigos de êxito, mas não criados pelo diretório.

### <a name="operatorstdostream-nullptrt"></a>operator<<(std::ostream, nullptr_t)

Por [LWG 2221](https://cplusplus.github.io/LWG/issue2221), `operator<<(std::ostream, nullptr_t)` adicionado para gravação de nullptrs em fluxos. 

### <a name="additional-parallel-algorithms"></a>Algoritmos paralelos adicionais

Novas versões paralelas de `is_sorted`, `is_sorted_until`, `is_partitioned`, `set_difference`, `set_intersection`, `is_heap` e `is_heap_until`.

### <a name="atomic-initialization"></a>inicialização atômica

[P0883 "Corrigindo inicialização atômica"](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0883r1.pdf) altera `std::atomic` para o valor-inicializar o T independente, em vez do padrão-inicializando-o. A correção é habilitada ao usar o Clang/LLVM com a Biblioteca Padrão da Microsoft. No momento, ela está desabilitada para o compilador do Microsoft C++ como uma solução alternativa para um bug no processamento de constexpr.

### <a name="removecvref-and-removecvreft"></a>remove_cvref e remove_cvref_t

Implementação das características de tipo `remove_cvref` e `remove_cvref_t` de [P0550](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0550r2.pdf). Elas removem a capacidade de referência e a qualificação CV de um tipo sem funções e matrizes decrescentes para ponteiros (diferentemente de `std::decay` e `std::decay_t`).

### <a name="feature-test-macros"></a>Macros de teste de recurso

[P0941R2 – macros de teste de recurso](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0941r2.html) está concluído, com suporte para `__has_cpp_attribute`. Macros de teste de recurso têm suporte em todos os modos padrão.

### <a name="prohibit-aggregates-with-user-declared-constructors"></a>Proibir agregações com construtores declarados pelo usuário

[C++20 P1008R1 – proibição de agregações com construtores declarados pelo usuário](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1008r1.pdf) está concluído.

## <a name="improvements_161"></a> Aprimoramentos no Visual Studio 2019 versão 16.1

### <a name="char8t"></a>char8_t

[P0482r6](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0482r6.html). O C++20 adiciona um novo tipo de caractere usado para representar unidades de código UTF-8. Os literais de cadeia de caracteres u8 no C++20 têm o tipo `const char8_t[N]`, em vez de `const char[N]`, que era o caso anteriormente. Alterações semelhantes foram propostas para o Padrão C em [N2231](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2231.htm). Sugestões para correção de compatibilidade com versões anteriores do char8_t são dadas em [P1423r0](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1423r0.html). O compilador do Microsoft C++ adiciona suporte ao char8_t no Visual Studio 2019 versão 16.1 quando você especifica a opção do compilador **/Zc:char8_t**. No futuro, haverá suporte a ele com [/std:c++latest](../../build/reference/std-specify-language-standard-version.md), que poderá ser revertido para o comportamento do C++17 por meio de **/Zc:char8_t-** . O compilador do EDG que alimenta o IntelliSense ainda não dá suporte a ele; portanto, você verá erros falsos somente do IntelliSense que não afetam a compilação real.

#### <a name="example"></a>Exemplo

```cpp
const char* s = u8"Hello"; // C++17
const char8_t* s = u8"Hello"; // C++20
```

### <a name="stdtypeidentity-metafunction-and-stdidentity-function-object"></a>Metafunção std::type_identity e objeto de função std::identity

[P0887R1 type_identity](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0887r1.pdf). A extensão do modelo de classe `std::identity` preterido foi removida e substituída pela metafunção `std::type_identity` do C++20 e pelo objeto de função `std::identity`. Ambos estão disponíveis somente em [/std:c++latest](../../build/reference/std-specify-language-standard-version.md). 

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

O novo processador lambda permite algumas verificações sintáticas de modo de conformidade em lambdas genéricos, em [/std:c++latest](../../build/reference/std-specify-language-standard-version.md) ou em qualquer outro modo de linguagem com **/experimental:newLambdaProcessor**. 

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

### <a name="new-and-updated-standard-library-functions-c20"></a>Funções da Biblioteca Padrão novas e atualizadas (C++20)

- `starts_with()` e `ends_with()` para `basic_string` e `basic_string_view`.
- `contains()` para contêineres associativos.
- `remove()`, `remove_if()` e `unique()` para ` list` e `forward_list` agora retornam `size_type`.
- `shift_left()` e `shift_right()` adicionados ao \<algoritmo>.

## <a name="bug-fixes-and-behavior-changes-in-visual-studio-2019-rtw"></a>Correções de bug e alterações de comportamento no Visual Studio 2019 RTW

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

Um bug foi introduzido no Visual Studio 2017, que fazia o compilador ignorar silenciosamente erros e não gerar nenhum código para as chamadas inválidas a += e a -= em `/clr` ou em `/ZW`. O seguinte código é compilado sem erros no Visual Studio 2017, mas, no Visual Studio 2019, gera corretamente o *erro C2845: 'System::String ^': aritmética do ponteiro não permitida neste tipo*:

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

O MSVC tinha um aviso de desempenho C4800 sobre a conversão implícita em bool que era muito barulhento e impossível de suprimir, o que nos levou a removê-lo no Visual Studio 2017. No entanto, durante o ciclo de vida do Visual Studio 2017, recebemos muitos comentários sobre os casos úteis que ele estava resolvendo. Trouxemos de volta no Visual Studio 2019 um C4800 cuidadosamente ajustado com seu C4165 de acompanhamento; ambos podem ser suprimidos facilmente com uma conversão explícita ou uma comparação para 0 do tipo apropriado. O C4800 é um aviso desativado por padrão de nível 4 e o C4165 é um aviso desativado por padrão de nível 3. Os dois podem ser descobertos usando a opção do compilador `/Wall`.

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
void foo()
{
    struct A
        {
            int boo(); // warning C4822
        };
}
```

### <a name="function-template-bodies-containing-constexpr-if-statements"></a>Corpos de modelo de função que contêm instruções constexpr if

Corpos de função de modelo que contêm instruções `if constexpr` têm algumas verificações `/permissive-` relacionadas a análise habilitadas. Por exemplo, no Visual Studio 2017, o seguinte código produz C*7510: 'Type': o uso de nome de tipo dependente deverá ser prefixado com 'typename'* somente se a opção `/permissive-` não estiver definida. No Visual Studio 2019, o mesmo código gera erros se a opção `/permissive-` é definida ou não:

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

### <a name="inline-assembly-code-is-not-supported-in-a-lambda-expression"></a>Não há suporte ao código do assembly embutido em uma expressão lambda

A equipe do Visual C++ recentemente tomou conhecimento de um problema de segurança no qual o uso do assembler embutido em um lambda poderia levar à corrupção de 'ebp' (o registro do endereço de retorno) em tempo de execução. Um invasor mal-intencionado poderia tirar vantagem desse cenário. Dada a natureza do problema, o fato de que só há suporte para o assembler embutido em x86 e a interação ruim do assembler embutido com o restante do compilador, sentimos que a solução mais segura para o problema era não permitir o assembler embutido em uma expressão lambda.

Observação: o único uso do assembler embutido em uma expressão lambda que encontramos "em condições naturais" era um uso no qual a meta era capturar o endereço de retorno. Nesse cenário, é possível capturar o endereço de retorno em todas as plataformas usando simplesmente um `_ReturnAddress()` intrínseco do compilador.

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

### <a name="iterator-debugging-and-stdmoveiterator"></a>Depuração do iterador e std::move_iterator

O recurso de depuração do iterador foi ensinado a desencapsular adequadamente o `std::move_iterator`. Por exemplo, agora `std::copy(std::move_iterator<std::vector<int>::iterator>, std::move_iterator<std::vector<int>::iterator>, int*)` pode envolver o caminho `memcpy` rápido.

### <a name="fixes-for-xkeycheckh-keyword-enforcement"></a>Correções para a imposição da palavra-chave \<xkeycheck.h>

A imposição da palavra-chave em macro da Biblioteca Padrão \<xkeycheck.h> foi corrigida para emitir a real palavra-chave do problema detectada em vez de uma mensagem genérica. Ela também dá suporte a palavras-chave do C++20 e evita enganar o IntelliSense dizendo que palavras-chave são macros.

### <a name="allocator-types-un-deprecated"></a>Cancelamento da substituição de tipos de alocadores

A substituição de `std::allocator<void>`, `std::allocator::size_type` e `std::allocator::difference_type` foi cancelada.

### <a name="correct-warning-for-narrowing-string-conversions"></a>Aviso correto para restringir conversões de cadeia de caracteres

Um `static_cast` falso não chamado pelo padrão que acidentalmente suprimiu avisos de restrição do C4244 foi removido do std::string. Tentar chamar `std::string::string(const wchar_t*, const wchar_t*)` agora emitirá devidamente *C4244 "restringindo um wchar_t a um char."*

### <a name="various-filesystem-correctness-fixes"></a>Várias correções de exatidão do \<sistemadearquivos>

- Correção de `std::filesystem::last_write_time` que falhava ao tentar alterar o último horário de gravação de um diretório.
- O construtor `std::filesystem::directory_entry` agora armazena um resultado com falha, em vez de gerar uma exceção, quando um caminho de destino não existente é fornecido.
- A versão de 2 parâmetros `std::filesystem::create_directory` foi alterada para chamar a versão de 1 parâmetro, pois a função `CreateDirectoryExW` subjacente `copy_symlink` seria executada quando o existing_p fosse um symlink.
- `std::filesystem::directory_iterator` não falha mais ao encontrar um symlink corrompido.
- `std::filesystem::space` agora aceita caminhos relativos.
- `std::filesystem::path::lexically_relative` não é mais confundido com barras à direita, relatado como [LWG 3096](https://cplusplus.github.io/LWG/issue3096).
- Solução de `CreateSymbolicLinkW` que rejeitava caminhos com barras à esquerda em `std::filesystem::create_symlink`.
- Solução da função `delete` de modo de exclusão POSIX que existia no Windows 10 LTSB 1609, mas que, na verdade, não era capaz de excluir arquivos.
- Os operadores de atribuição de cópia e construtores de cópia do `std::boyer_moore_searcher` e do `std::boyer_moore_horspool_searcher` agora realmente copiam coisas.

### <a name="parallel-algorithms-on-windows-8-and-later"></a>Algoritmos paralelos no Windows 8 e posterior

A biblioteca de algoritmos paralelos agora usa devidamente a família `WaitOnAddress` real no Windows 8 e posterior, em vez de sempre usar o Windows 7 e versões falsas anteriores.

### <a name="stdsystemcategorymessage-whitespace"></a>std::system_category::message() whitespace

`std::system_category::message()` agora corta o espaço em branco à direita da mensagem retornada.

### <a name="stdlinearcongruentialengine-divide-by-zero"></a>std::linear_congruential_engine divisão por zero

Algumas condições que poderiam fazer `std::linear_congruential_engine` disparar a divisão por 0 foram corrigidas.

### <a name="fixes-for-iterator-unwrapping"></a>Correções para desencapsulamento do iterador

O mecanismo de desencapsulamento do iterador que foi exposto pela primeira vez à integração entre programador e usuário no Visual Studio 2017 15.8 (como descrito em https://devblogs.microsoft.com/cppblog/stl-features-and-fixes-in-vs-2017-15-8/ ) não desencapsula mais os iteradores derivados dos iteradores de biblioteca padrão. Por exemplo, um usuário derivado de `std::vector<int>::iterator` e que tenta personalizar o comportamento agora obtém seu comportamento personalizado ao chamar algoritmos de biblioteca padrão, em vez do comportamento de um ponteiro.
Agora a função de reserva de contêiner não ordenada na verdade reserva N elementos, conforme descrito em [LWG 2156](https://cplusplus.github.io/LWG/issue2156).

### <a name="time-handling"></a>Manipulação de tempo

- Anteriormente, alguns valores temporais que eram passados para a biblioteca de simultaneidade estourariam, por exemplo, `condition_variable::wait_for(seconds::max())`. Esses estouros, agora corrigidos, mudaram o comportamento aparentemente em um ciclo aleatório de 29 dias (quando uint32_t milissegundos aceitos pelas APIs do Win32 subjacentes estouraram).

- Agora o cabeçalho <ctime> declara corretamente timespec e timespec_get no namespace std, além de declará-los no namespace global.

### <a name="various-fixes-for-containers"></a>Várias correções de contêineres

- Muitas funções de contêiner interno da Biblioteca Padrão foram tornadas privadas para melhorar a experiência do IntelliSense. Esperam-se outras correções para marcar membros como privados em versões subsequentes do MSVC.

- Problemas de exatidão de segurança de exceção nos quais contêineres baseados em nós, como `list`, `map` e `unordered_map`, se tornariam corrompidos foram corrigidos. Durante uma operação de reatribuição de `propagate_on_container_copy_assignment` ou de `propagate_on_container_move_assignment`, liberaríamos o nó sentinela do contêiner com o alocador antigo, realizaríamos a atribuição de POCCA/POCMA pelo alocador antigo e tentaríamos adquirir o nó sentinela do novo alocador. Se essa alocação falhou, o contêiner está corrompido e não pode nem ser destruído, uma vez que ter um nó sentinela é uma invariável de estrutura de dados concretos. Isso foi corrigido para alocar o novo nó sentinela do alocador do contêiner de origem antes de destruir o nó sentinela existente.

- Os contêineres foram corrigidos para alocadores sempre copiar/mover/trocar de acordo com `propagate_on_container_copy_assignment`, `propagate_on_container_move_assignment` e `propagate_on_container_swap`, mesmo para alocadores declarados `is_always_equal`.

- Adição das sobrecargas para funções de membro extrair e mesclar do contêiner que aceitam contêineres rvalue de acordo com [P0083 "Unindo mapas e conjuntos"](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0083r3.pdf)

### <a name="stdbasicistreamread-processing-of-rn--n"></a>std::basic_istream::read processamento de \r\n => \n

`std::basic_istream::read` foi corrigido para não gravar em partes do buffer fornecido temporariamente como parte do processamento de \r\n => \n. Isso nos oferece um pouco da vantagem de desempenho obtida no Visual Studio 2017 15.8 para leituras maiores de 4K em tamanho, mas melhorias decorrentes de se evitar três chamadas virtuais por caractere ainda estão presentes.

### <a name="stdbitset-constructor"></a>Construtor std::bitset

O construtor do `std::bitset` não lê mais os uns e os zeros em ordem inversa para grandes bitsets.

### <a name="stdpairoperator-regression"></a>Regressão std::pair::operator=

Correção de uma regressão no operador de atribuição do `std::pair` introduzida ao implementar [LWG 2729 "SFINAE ausente em std::pair::operator =";](https://cplusplus.github.io/LWG/issue2729). Ele agora aceita corretamente tipos conversíveis em `std::pair` novamente.

### <a name="non-deduced-contexts-for-addconstt"></a>Contextos não deduzidos para add_const_t

Correção de um bug de características de tipo secundário, em que `add_const_t` e funções relacionadas devem ser um contexto não deduzido. Em outras palavras, `add_const_t` deve ser um alias para `typename add_const<T>::type`, e não `const T`.

## <a name="see-also"></a>Consulte também

[Novidades no Visual Studio 2019](../what-s-new-for-visual-cpp-in-visual-studio.md)