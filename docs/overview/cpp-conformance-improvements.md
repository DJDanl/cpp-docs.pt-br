---
title: Aprimoramentos de conformidade do C++
ms.date: 08/04/2020
description: O Microsoft C++ no Visual Studio está progredindo em direção à plena conformidade com o padrão de linguagem C++20.
ms.technology: cpp-language
ms.openlocfilehash: 3a0e21bf08fcf7861feedd3fd43666bd3768deee
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90042115"
---
# <a name="c-conformance-improvements-in-visual-studio"></a>Aprimoramentos de conformidade do C++ no Visual Studio

O Microsoft C++ faz melhorias de conformidade e correções de bugs em cada versão. Este artigo lista as melhorias por versão principal e depois pela versão. Ele também lista correções de bugs importantes por versão. Para ir diretamente para as alterações de uma versão específica, use a lista **Neste artigo**.

::: moniker range="vs-2019"

## <a name="conformance-improvements-in-visual-studio-2019-rtw-version-160"></a><a name="improvements_160"></a> Melhorias de conformidade no Visual Studio 2019 RTW (versão 16,0)

O Visual Studio 2019 RTW contém as seguintes melhorias de conformidade, correções de bugs e alterações de comportamento no compilador do Microsoft C++ (MSVC)

**Observação:** Os recursos do c++ 20 serão disponibilizados no **`/std:c++latest`** modo até que a implementação do c++ 20 seja concluída para o compilador e o IntelliSense. Nesse momento, o **`/std:c++20`** modo do compilador será introduzido.

### <a name="improved-modules-support-for-templates-and-error-detection"></a>Os módulos aprimorados dão suporte a modelos e à detecção de erros

Agora os módulos estão oficialmente no padrão C++20. O suporte aprimorado foi adicionado no Visual Studio 2017 versão 15.9. Para saber mais, confira [Melhor detecção de erro e de suporte de modelo em Módulos do C++ com o MSVC 2017 versão 15.9](https://devblogs.microsoft.com/cppblog/better-template-support-and-error-detection-in-c-modules-with-msvc-2017-version-15-9/).

### <a name="modified-specification-of-aggregate-type"></a>Especificação modificada de tipo de agregação

A especificação de um tipo de agregação foi alterada no C++20 (confira [Proibir agregações com construtores declarados pelo usuário](https://wg21.link/p1008r1)). No Visual Studio 2019, em **`/std:c++latest`** , uma classe com qualquer Construtor declarado pelo usuário (por exemplo, incluindo um construtor declarado `= default` ou `= delete` ) não é uma agregação. Anteriormente, somente os construtores fornecidos pelo usuário desqualificariam uma classe de uma agregação. Essa alteração impõe outras restrições sobre como esses tipos podem ser inicializados.

O código a seguir compila sem erros no Visual Studio 2017, mas gera erros C2280 e C2440 no Visual Studio 2019 em **`/std:c++latest`** :

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

[P0515R3](https://wg21.link/p0515r3) O C++20 apresenta o operador de comparação de três vias `<=>`, também conhecido como o "operador espaçonave". O Visual Studio 2019 no **`/std:c++latest`** modo apresenta suporte parcial para o operador, gerando erros de sintaxe que agora não é permitido. Por exemplo, o código a seguir compila sem erros no Visual Studio 2017, mas gera vários erros no Visual Studio 2019 em **`/std:c++latest`** :

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

Anteriormente, o MSVC permitia associação direta de uma referência a partir de um tipo com qualificadores CV incompatíveis abaixo do nível superior. Essa associação poderia permitir a modificação de dados const supostamente mencionados pela referência. Agora, o compilador cria um temporário, conforme exigido pelo padrão. No Visual Studio 2017, o código a seguir é compilado sem avisos. No Visual Studio 2019, o compilador gera o aviso C4172: `<func:#1 "?PData@X@@QBEABQBXXZ"> returning address of local variable or temporary.` :

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

### <a name="reinterpret_cast-from-an-overloaded-function"></a>`reinterpret_cast` de uma função sobrecarregada

O argumento para **`reinterpret_cast`** não é um dos contextos nos quais o endereço de uma função sobrecarregada é permitido. O código a seguir compila sem erros no Visual Studio 2017, mas no Visual Studio 2019 ele gera o erro C2440: `cannot convert from 'overloaded-function' to 'fp'` :

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

No C++ 14, os tipos de fechamento lambda não são literais. A principal consequência dessa regra é que um lambda não pode ser atribuído a uma **`constexpr`** variável. O código a seguir compila sem erros no Visual Studio 2017, mas no Visual Studio 2019 ele gera o erro C2127: `'l': illegal initialization of 'constexpr' entity with a non-constant expression` :

```cpp
int main()
{
    constexpr auto l = [] {}; // C2127 in VS2019
}
```

Para evitar o erro, remova o **`constexpr`** qualificador ou, caso contrário, altere o modo de conformidade para **`/std:c++17`** .

### <a name="stdcreate_directory-failure-codes"></a>Códigos de falha de `std::create_directory`

[P1164](https://wg21.link/p1164r1) implementado de C++20 incondicionalmente. Isso altera `std::create_directory` para verificar se o destino já foi um diretório em caso de falha. Anteriormente, todos os erros do tipo ERROR_ALREADY_EXISTS foram convertidos em códigos de êxito, mas não criados pelo diretório.

### `operator<<(std::ostream, nullptr_t)`

Por [LWG 2221](https://cplusplus.github.io/LWG/issue2221), `operator<<(std::ostream, nullptr_t)` adicionado para gravação de nullptrs em fluxos.

### <a name="additional-parallel-algorithms"></a>Algoritmos paralelos adicionais

Novas versões paralelas de `is_sorted`, `is_sorted_until`, `is_partitioned`, `set_difference`, `set_intersection`, `is_heap` e `is_heap_until`.

### <a name="atomic-initialization"></a>inicialização atômica

[P0883 "Corrigindo inicialização atômica"](https://wg21.link/p0883r1) altera `std::atomic` para o valor-inicializar o T independente, em vez do padrão-inicializando-o. A correção é habilitada ao usar o Clang/LLVM com a biblioteca padrão da Microsoft. Atualmente, ele está desabilitado para o compilador do Microsoft C++, como uma solução alternativa para um bug no **`constexpr`** processamento.

### <a name="remove_cvref-and-remove_cvref_t"></a>`remove_cvref` e `remove_cvref_t`

Implementação das características de tipo `remove_cvref` e `remove_cvref_t` de [P0550](https://wg21.link/p0550r2). Elas removem a capacidade de referência e a qualificação CV de um tipo sem funções e matrizes decrescentes para ponteiros (diferentemente de `std::decay` e `std::decay_t`).

### <a name="feature-test-macros"></a>Macros de teste de recurso

[P0941R2 – macros de teste de recurso](https://wg21.link/p0941r2) está concluído, com suporte para `__has_cpp_attribute`. Macros de teste de recurso têm suporte em todos os modos padrão.

### <a name="prohibit-aggregates-with-user-declared-constructors"></a>Proibir agregações com construtores declarados pelo usuário

[C++20 P1008R1 – proibição de agregações com construtores declarados pelo usuário](https://wg21.link/p1008r1) está concluído.

## <a name="conformance-improvements-in-161"></a><a name="improvements_161"></a> Melhorias de conformidade no 16,1

### <a name="char8_t"></a>char8_t

[P0482r6](https://wg21.link/p0482r6). O C++20 adiciona um novo tipo de caractere usado para representar unidades de código UTF-8. Os literais de cadeia de caracteres `u8` no C++20 têm o tipo `const char8_t[N]`, em vez de `const char[N]`, que era o caso anteriormente. Alterações semelhantes foram propostas para o padrão C no [N2231](https://wg14.link/n2231). As sugestões para a **`char8_t`** correção de compatibilidade com versões anteriores são fornecidas em [P1423r3](https://wg21.link/p1423r3). O compilador do Microsoft C++ adiciona suporte para **`char8_t`** o no Visual Studio 2019 versão 16,1 quando você especifica a **`/Zc:char8_t`** opção do compilador. No futuro, ele terá suporte com [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) , que pode ser revertido para o comportamento do c++ 17 por meio do **`/Zc:char8_t-`** . O compilador EDG que capacita o IntelliSense ainda não oferece suporte a ele. Você pode ver erros falsos somente do IntelliSense que não afetam a compilação real.

#### <a name="example"></a>Exemplo

```cpp
const char* s = u8"Hello"; // C++17
const char8_t* s = u8"Hello"; // C++20
```

### <a name="stdtype_identity-metafunction-and-stdidentity-function-object"></a>Metafunção std::type_identity e objeto de função std::identity

[Type_identity P0887R1](https://wg21.link/p0887r1). A extensão do modelo de classe `std::identity` preterido foi removida e substituída pela metafunção `std::type_identity` do C++20 e pelo objeto de função `std::identity`. Ambos estão disponíveis apenas em [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) .

O exemplo a seguir produz C4996 de aviso de reprovação para `std::identity` (definido em \<type_traits> ) no Visual Studio 2017:

```cpp
#include <type_traits>

using T = std::identity<int>::type;
T x, y = std::identity<T>{}(x);
int i = 42;
long j = std::identity<long>{}(i);
```

O exemplo a seguir mostra como usar o novo `std::identity` (definido em \<functional> ) junto com o novo `std::type_identity` :

```cpp
#include <type_traits>
#include <functional>

using T = std::type_identity<int>::type;
T x, y = std::identity{}(x);
int i = 42;
long j = static_cast<long>(i);
```

### <a name="syntax-checks-for-generic-lambdas"></a>Verificações de sintaxe para lambdas genéricos

O novo processador lambda permite algumas verificações sintáticas de modo de conformidade em lambdas genéricos, em [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) ou sob qualquer outro modo de linguagem com **`/experimental:newLambdaProcessor`** .

No Visual Studio 2017, esse código é compilado sem avisos, mas no Visual Studio 2019 ele produz o erro C2760 `syntax error: unexpected token '\<id-expr>', expected 'id-expression'` :

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

[P0846R0](https://wg21.link/p0846r0) (c++ 20) aumentou a capacidade de localizar modelos de função por meio de pesquisa dependente de argumento para expressões de chamada de função com argumentos de modelo explícitos. Requer **`/std:c++latest`** .

### <a name="designated-initialization"></a>Inicialização designada

A *inicialização designada* do [P0329R4](https://wg21.link/p0329r4) (c++ 20) permite que membros específicos sejam selecionados na inicialização agregada usando a `Type t { .member = expr }` sintaxe. Requer **`/std:c++latest`** .

### <a name="new-and-updated-standard-library-functions-c20"></a>Funções da biblioteca padrão novas e atualizadas (C++20)

- `starts_with()` e `ends_with()` para `basic_string` e `basic_string_view`.
- `contains()` para contêineres associativos.
- `remove()`, `remove_if()`, e `unique()` para `list` e `forward_list` agora retornam `size_type`.
- `shift_left()` e `shift_right()` adicionados a \<algorithm>.

## <a name="conformance-improvements-in-162"></a><a name="improvements_162"></a> Melhorias de conformidade no 16,2

### <a name="noexcept-constexpr-functions"></a>`noexcept``constexpr`funções do

**`constexpr`** as funções não são mais consideradas **`noexcept`** por padrão quando usadas em uma expressão constante. Essa alteração de comportamento vem da resolução do [CWG 1351](https://wg21.link/cwg1351) e está habilitada no [`/permissive-`](../build/reference/permissive-standards-conformance.md) . O exemplo a seguir compila no Visual Studio 2019 versão 16,1 e anterior, mas produz C2338 no Visual Studio 2019 versão 16,2:

```cpp
constexpr int f() { return 0; }

int main() {
    static_assert(noexcept(f()), "f should be noexcept"); // C2338 in 16.2
}
```

Para corrigir o erro, adicione a **`noexcept`** expressão à declaração da função:

```cpp
constexpr int f() noexcept { return 0; }

int main() {
    static_assert(noexcept(f()), "f should be noexcept");
}
```

### <a name="binary-expressions-with-different-enum-types"></a>Expressões binárias com diferentes tipos de enumeração

O c++ 20 preteriu as conversões aritméticas usuais em operandos, em que:

- Um operando é do tipo de enumeração e

- o outro é de um tipo de enumeração diferente ou de um tipo de ponto flutuante.

Para obter mais informações, consulte [P1120R0](https://wg21.link/p1120r0).

No Visual Studio 2019 versão 16,2 e posteriores, o código a seguir produz um aviso de nível 4 quando a [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) opção do compilador está habilitada:

```cpp
enum E1 { a };
enum E2 { b };
int main() {
    int i = a | b; // warning C5054: operator '|': deprecated between enumerations of different types
}
```

Para evitar o aviso, use [static_cast](../cpp/static-cast-operator.md) para converter o segundo operando:

```cpp
enum E1 { a };
enum E2 { b };
int main() {
  int i = a | static_cast<int>(b);
}
```

Usar uma operação binária entre uma enumeração e um tipo de ponto flutuante agora é um aviso quando a [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) opção do compilador está habilitada:

```cpp
enum E1 { a };
int main() {
  double i = a * 1.1;
}
```

Para evitar o aviso, use [static_cast](../cpp/static-cast-operator.md) para converter o segundo operando:

```cpp
enum E1 { a };
int main() {
   double i = static_cast<int>(a) * 1.1;
}
```

### <a name="equality-and-relational-comparisons-of-arrays"></a>Igualdade e comparações relacionais de matrizes

As comparações de igualdade e relacional entre dois operandos do tipo de matriz são preteridas em C++ 20 ([P1120R0](https://wg21.link/p1120r0)). Em outras palavras, uma operação de comparação entre duas matrizes (apesar das semelhanças de classificação e extensão) é agora um aviso. A partir do Visual Studio 2019 versão 16,2, o código a seguir produz C5056: `operator '==': deprecated for array types` quando a [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) opção do compilador está habilitada:

```cpp
int main() {
    int a[] = { 1, 2, 3 };
    int b[] = { 1, 2, 3 };
    if (a == b) { return 1; }
}
```

Para evitar o aviso, você pode comparar os endereços dos primeiros elementos:

```cpp
int main() {
    int a[] = { 1, 2, 3 };
    int b[] = { 1, 2, 3 };
    if (&a[0] == &b[0]) { return 1; }
}
```

Para determinar se o conteúdo de duas matrizes é igual, use a função [std:: equal](../standard-library/algorithm-functions.md#equal) :

```cpp
std::equal(std::begin(a), std::end(a), std::begin(b), std::end(b));
```

### <a name="effect-of-defining-spaceship-operator-on--and-"></a>Efeito de definir o operador de espaçamento em `==` e `!=`

Uma definição do operador Spaceship ( **`<=>`** ) sozinha não irá mais reescrever expressões que envolvam **`==`** ou a **`!=`** menos que o operador de espaço esteja marcado como **`= default`** ([P1185R2](https://wg21.link/p1185r2)). O exemplo a seguir é compilado no Visual Studio 2019 RTW e na versão 16,1, mas produz C2678 no Visual Studio 2019 versão 16,2:

```cpp
#include <compare>

struct S {
  int a;
  auto operator<=>(const S& rhs) const {
    return a <=> rhs.a;
  }
};
bool eq(const S& lhs, const S& rhs) {
  return lhs == rhs;
}
bool neq(const S& lhs, const S& rhs) {
    return lhs != rhs;
}
```

Para evitar o erro, defina o operador = = ou declare-o como padrão:

```cpp
#include <compare>

struct S {
  int a;
  auto operator<=>(const S& rhs) const {
    return a <=> rhs.a;
  }
  bool operator==(const S&) const = default;
};
bool eq(const S& lhs, const S& rhs) {
  return lhs == rhs;
}
bool neq(const S& lhs, const S& rhs) {
    return lhs != rhs;
}
```

### <a name="standard-library-improvements"></a>Aprimoramentos da biblioteca padrão

- \<charconv>`to_chars()`com precisão fixa/científica. (A precisão geral está atualmente planejada para 16,4.)
- [P0020R6](https://wg21.link/p0020r6): Atomic \<float> , atômico \<double> , atômico\<long double>
- [P0463R1](https://wg21.link/p0463r1): endian
- [P0482R6](https://wg21.link/p0482r6): suporte de biblioteca para char8_t
- [P0600R1](https://wg21.link/p0600r1): [ \[ nodescarte]] para a STL, parte 1
- [P0653R2](https://wg21.link/p0653r2): to_address ()
- [P0754R2](https://wg21.link/p0754r2): \<version>
- [P0771R1](https://wg21.link/p0771r1): Noexcept para o construtor de movimentação std:: function

## <a name="conformance-improvements-in-visual-studio-2019-version-163"></a><a name="improvements_163"></a> Melhorias de conformidade no Visual Studio 2019 versão 16,3

### <a name="stream-extraction-operators-for-char-removed"></a>Operadores de extração de fluxo para char * removidos

Os operadores de extração de fluxo para ponteiro para caracteres foram removidos e substituídos pelos operadores de extração para a matriz de caracteres (por [P0487R1](https://wg21.link/p0487r1)). WG21 considera que as sobrecargas removidas não são seguras. No [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) modo, o exemplo a seguir agora produz C2679: `binary '>>': no operator found which takes a right-hand operand of type 'char*' (or there is no acceptable conversion)` :

```cpp
   char x[42];
   char* p = x;
   std::cin >> std::setw(42);
   std::cin >> p;
```

Para evitar o erro, use o operador de extração com uma variável char []:

```cpp
char x[42];
std::cin >> x;
```

### <a name="new-keywords-requires-and-concept"></a>Novas palavras-chave `requires` e `concept`

Novas palavras-chave **`requires`** e foram **`concept`** adicionadas ao compilador do Microsoft C++. Se você tentar usar uma como um identificador no [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) modo, o compilador irá gerar C2059: `syntax error` .

### <a name="constructors-as-type-names-disallowed"></a>Construtores como nomes de tipo não permitidos

O compilador não considera mais os nomes de construtor como nomes de classe injetados nesse caso: quando eles aparecem em um nome qualificado após um alias para uma especialização de modelo de classe. Anteriormente, os construtores eram utilizáveis como um nome de tipo para declarar outras entidades. O exemplo a seguir agora produz C3646: `'TotalDuration': unknown override specifier` :

```cpp
#include <chrono>

class Foo {
   std::chrono::milliseconds::duration TotalDuration{};
};

```

Para evitar o erro, declare `TotalDuration` conforme mostrado aqui:

```cpp
#include <chrono>

class Foo {
  std::chrono::milliseconds TotalDuration {};
};
```

### <a name="stricter-checking-of-extern-c-functions"></a>Verificação mais estrita de `extern "C"` funções

Se uma **`extern "C"`** função foi declarada em namespaces diferentes, as versões anteriores do compilador do Microsoft C++ não verificaram se as declarações eram compatíveis. A partir do Visual Studio 2019 versão 16,3, o compilador verifica a compatibilidade. No [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo, o código a seguir produz erros C2371 `redefinition; different basic types` e C2733 `you cannot overload a function with C linkage` :

```cpp
using BOOL = int;

namespace N
{
   extern "C" void f(int, int, int, bool);
}

void g()
{
   N::f(0, 1, 2, false);
}

extern "C" void f(int, int, int, BOOL){}
```

Para evitar os erros no exemplo anterior, use **`bool`** em vez de `BOOL` consistentemente em ambas as declarações do `f` .

### <a name="standard-library-improvements"></a>Aprimoramentos da biblioteca padrão

Os cabeçalhos não padrão \<stdexcpt.h> e foram \<typeinfo.h> removidos. O código que os inclui deve incluir os cabeçalhos padrão \<exception> e \<typeinfo> , respectivamente.

## <a name="conformance-improvements-in-visual-studio-2019-version-164"></a><a name="improvements_164"></a> Melhorias de conformidade no Visual Studio 2019 versão 16,4

### <a name="better-enforcement-of-two-phase-name-lookup-for-qualified-ids-in-permissive-"></a>Melhor imposição de pesquisa de nome de duas fases para as IDs qualificadas em `/permissive-`

A pesquisa de nome em duas fases requer que os nomes não dependentes usados nos corpos do modelo fiquem visíveis para o modelo no tempo de definição. Anteriormente, esses nomes podem ter sido encontrados quando o modelo é instanciado. Essa alteração torna mais fácil escrever código portátil e de conformidade no MSVC sob o [`/permissive-`](../build/reference/permissive-standards-conformance.md) sinalizador.

No Visual Studio 2019 versão 16,4 com o **`/permissive-`**  sinalizador definido, o exemplo a seguir produz um erro, porque `N::f` não está visível quando o `f<T>` modelo é definido:

```cpp
template <class T>
int f() {
    return N::f() + T{}; // error C2039: 'f': is not a member of 'N'
}

namespace N {
    int f() { return 42; }
}
```

Normalmente, esse erro pode ser corrigido incluindo cabeçalhos ausentes ou funções ou variáveis declaradoras de encaminhamento, conforme mostrado no exemplo a seguir:

```cpp
namespace N {
    int f();
}

template <class T>
int f() {
    return N::f() + T{};
}

namespace N {
    int f() { return 42; }
}
```

### <a name="implicit-conversion-of-integral-constant-expressions-to-null-pointer"></a>Conversão implícita de expressões de constante integral para ponteiro nulo

O compilador MSVC agora implementa o [CWG Issue 903](https://wg21.link/cwg903) no modo de conformidade ( **`/permissive-`** ). Essa regra não permite a conversão implícita de expressões de constante integral (exceto para o literal inteiro ' 0 ') para constantes de ponteiro NULL. O exemplo a seguir produz C2440 no modo de conformidade:

```cpp
int* f(bool* p) {
    p = false; // error C2440: '=': cannot convert from 'bool' to 'bool *'
    p = 0; // OK
    return false; // error C2440: 'return': cannot convert from 'bool' to 'int *'
}
```

Para corrigir o erro, use **`nullptr`** em vez de **`false`** . Um literal 0 ainda é permitido:

```cpp
int* f(bool* p) {
    p = nullptr; // OK
    p = 0; // OK
    return nullptr; // OK
}
```

### <a name="standard-rules-for-types-of-integer-literals"></a>Regras padrão para tipos de literais inteiros

No modo de conformidade (habilitado por [`/permissive-`](../build/reference/permissive-standards-conformance.md) ), o MSVC usa as regras padrão para tipos de literais inteiros. Literais decimais muito grandes para se ajustarem a um **`signed int`** tipo anteriormente determinado **`unsigned int`** . Agora, esses literais recebem o próximo maior **`signed`** tipo de inteiro, **`long long`** . Além disso, literais com o sufixo ' ' que são muito grandes para caber em um tipo recebem o **`signed`** tipo **`unsigned long long`** .

Essa alteração pode levar a geração de diagnósticos de aviso diferentes e diferenças de comportamento para operações aritméticas em literais.

O exemplo a seguir mostra o novo comportamento no Visual Studio 2019 versão 16,4. A `i` variável agora é do tipo **`unsigned int`** . É por isso que o aviso é gerado. Os bits de ordem superior da variável `j` são definidos como 0.

```cpp
void f(int r) {
    int i = 2964557531; // warning C4309: truncation of constant value
    long long j = 0x8000000000000000ll >> r; // literal is now unsigned, shift will fill high-order bits with 0
}
```

O exemplo a seguir demonstra como manter o comportamento antigo e evitar os avisos e a alteração de comportamento de tempo de execução:

```cpp
void f(int r) {
int i = 2964557531u; // OK
long long j = (long long)0x8000000000000000ll >> r; // shift will keep high-order bits
}
```

### <a name="function-parameters-that-shadow-template-parameters"></a>Parâmetros de função que os parâmetros de modelo de sombra

O compilador MSVC agora gera um erro quando um parâmetro de função sombreia um parâmetro de modelo:

```cpp
template<typename T>
void f(T* buffer, int size, int& size_read);

template<typename T, int Size>
void f(T(&buffer)[Size], int& Size) // error C7576: declaration of 'Size' shadows a template parameter
{
    return f(buffer, Size, Size);
}
```

Para corrigir o erro, altere o nome de um dos parâmetros:

```cpp
template<typename T>
void f(T* buffer, int size, int& size_read);

template<typename T, int Size>
void f(T (&buffer)[Size], int& size_read)
{
    return f(buffer, Size, size_read);
}
```

### <a name="user-provided-specializations-of-type-traits"></a>Especializações fornecidas pelo usuário de características de tipo

Em conformidade com a subcláusula *meta. rqmts* do padrão, o compilador MSVC agora gera um erro quando encontra uma especialização definida pelo usuário de um dos `type_traits` modelos especificados no `std` namespace. A menos que especificado de outra forma, essas especializações resultam em um comportamento indefinido. O exemplo a seguir tem um comportamento indefinido porque ele viola a regra e a **`static_assert`** falha com o erro C2338.

```cpp
#include <type_traits>
struct S;

template<>
struct std::is_fundamental<S> : std::true_type {};

static_assert(std::is_fundamental<S>::value, "fail");
```

Para evitar o erro, defina um struct que herde do preferencial `type_trait` e specialize que:

```cpp
#include <type_traits>

struct S;

template<typename T>
struct my_is_fundamental : std::is_fundamental<T> {};

template<>
struct my_is_fundamental<S> : std::true_type { };

static_assert(my_is_fundamental<S>::value, "fail");
```

### <a name="changes-to-compiler-provided-comparison-operators"></a>Alterações nos operadores de comparação fornecidos pelo compilador

O compilador MSVC agora implementa as seguintes alterações para operadores de comparação por [P1630R1](https://wg21.link/p1630r1) quando a [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) opção está habilitada:

O compilador não reescreve as expressões usando `operator==` se envolve um tipo de retorno que não é um **`bool`** . O código a seguir agora produz o erro C2088: `'!=': illegal for struct` :

```cpp
struct U {
    operator bool() const;
};

struct S {
    U operator==(const S&) const;
};

bool neq(const S& lhs, const S& rhs) {
    return lhs != rhs;
}
```

Para evitar o erro, você deve definir explicitamente o operador necessário:

```cpp
struct U {
    operator bool() const;
};

struct S {
    U operator==(const S&) const;
    U operator!=(const S&) const;
};

bool neq(const S& lhs, const S& rhs) {
    return lhs != rhs;
}
```

O compilador não definirá mais um operador de comparação padronizado se for um membro de uma classe semelhante a Union. O exemplo a seguir agora produz o erro C2120: `'void' illegal with all types` :

```cpp
#include <compare>

union S {
    int a;
    char b;
    auto operator<=>(const S&) const = default;
};

bool lt(const S& lhs, const S& rhs) {
    return lhs < rhs;
}
```

Para evitar o erro, defina um corpo para o operador:

```cpp
#include <compare>

union S {
    int a;
    char b;
    auto operator<=>(const S&) const { ... }
};

bool lt(const S& lhs, const S& rhs) {
    return lhs < rhs;
}
```

O compilador não definirá mais um operador de comparação padronizado se a classe contiver um membro de referência. O código a seguir agora produz o erro C2120: `'void' illegal with all types` :

```cpp
#include <compare>

struct U {
    int& a;
    auto operator<=>(const U&) const = default;
};

bool lt(const U& lhs, const U& rhs) {
    return lhs < rhs;
}
```

Para evitar o erro, defina um corpo para o operador:

```cpp
#include <compare>

struct U {
    int& a;
    auto operator<=>(const U&) const { ... };
};

bool lt(const U& lhs, const U& rhs) {
    return lhs < rhs;
}
```

## <a name="conformance-improvements-in-visual-studio-2019-version-165"></a><a name="improvements_165"></a> Melhorias de conformidade no Visual Studio 2019 versão 16,5

### <a name="explicit-specialization-declaration-without-an-initializer-isnt-a-definition"></a>Declaração de especialização explícita sem um inicializador não é uma definição

Em `/permissive-` , MSVC agora impõe uma regra padrão que declarações de especialização explícitas sem inicializadores não são definições. Anteriormente, a declaração seria considerada uma definição com um inicializador padrão. O efeito é observável no momento do link, pois um programa que depende desse comportamento agora pode ter símbolos não resolvidos. Este exemplo agora resulta em um erro:

```cpp
template <typename> struct S {
    static int a;
};

// In permissive-, this declaration isn't a definition, and the program won't link.
template <> int S<char>::a;

int main() {
    return S<char>::a;
}
```

```Output
error LNK2019: unresolved external symbol "public: static int S<char>::a" (?a@?$S@D@@2HA) referenced in function _main
at link time.
```

Para resolver o problema, adicione um inicializador:

```cpp
template <typename> struct S {
    static int a;
};

// Add an initializer for the declaration to be a definition.
template <> int S<char>::a{};

int main() {
    return S<char>::a;
}
```

### <a name="preprocessor-output-preserves-newlines"></a>A saída do pré-processador preserva as novas linhas

O pré-processador experimental agora preserva as novas linhas e o espaço em branco ao usar **`/P`** ou **`/E`** com **`/experimental:preprocessor`** .

Dada esta origem de exemplo,

```cpp
#define m()
line m(
) line
```

A saída anterior do **`/E`** foi:

```Output
line line
#line 2
```

A nova saída de **`/E`** é agora:

```Output
line
 line
```

### <a name="import-and-module-keywords-are-context-dependent"></a>as palavras-chave ' import ' e ' module ' são dependentes de contexto

Por P1857R1, as diretivas de pré-processador de importação e de módulo têm restrições adicionais sobre sua sintaxe. Este exemplo não compila mais:

```cpp
import // Invalid
m;
```

Ele produz a seguinte mensagem de erro:

```Output
error C2146: syntax error: missing ';' before identifier 'm'
```

Para resolver o problema, mantenha a importação na mesma linha:

```cpp
import m; // OK
```

### <a name="removal-of-stdweak_equality-and-stdstrong_equality"></a>Remoção de std:: weak_equality e std:: strong_equality

A mesclagem de P1959R0 exige que o compilador remova o comportamento e as referências aos `std::weak_equality` `std::strong_equality` tipos e.

O código neste exemplo não compila mais:

```cpp
#include <compare>

struct S {
    std::strong_equality operator<=>(const S&) const = default;
};

void f() {
    nullptr<=>nullptr;
    &f <=> &f;
    &S::operator<=> <=> &S::operator<=>;
}
```

O exemplo agora leva a esses erros:

```Output
error C2039: 'strong_equality': is not a member of 'std'
error C2143: syntax error: missing ';' before '<=>'
error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
error C4430: missing type specifier - int assumed. Note: C++ does not support default-int
error C7546: binary operator '<=>': unsupported operand types 'nullptr' and 'nullptr'
error C7546: binary operator '<=>': unsupported operand types 'void (__cdecl *)(void)' and 'void (__cdecl *)(void)'
error C7546: binary operator '<=>': unsupported operand types 'int (__thiscall S::* )(const S &) const' and 'int (__thiscall S::* )(const S &) const'
```

Para resolver o problema, atualize para preferir os operadores relacionais internos e substitua os tipos removidos:

```cpp
#include <compare>

struct S {
    std::strong_ordering operator<=>(const S&) const = default; // prefer 'std::strong_ordering'
};

void f() {
    nullptr != nullptr; // use pre-existing builtin operator != or ==.
    &f != &f;
    &S::operator<=> != &S::operator<=>;
}
```

### <a name="tls-guard-changes"></a>Alterações na proteção TLS

Anteriormente, as variáveis de local de thread em DLLs não foram inicializadas corretamente. Além do thread que carregou a DLL, eles não foram inicializados antes do primeiro uso em threads que existiam antes do carregamento da DLL. Este defeito foi corrigido agora. Variáveis de local de thread em tal DLL são inicializadas imediatamente antes de seu primeiro uso em tais threads.

Esse novo comportamento de teste para inicialização em usos de variáveis de local de thread pode ser desabilitado usando a **`/Zc:tlsGuards-`** opção de compilador. Ou, adicionando o `[[msvc:no_tls_guard]]` atributo a determinadas variáveis locais de thread.

### <a name="better-diagnosis-of-call-to-deleted-functions"></a>Melhor diagnóstico de chamada para funções excluídas

Nosso compilador era mais permissivo sobre chamadas para funções excluídas anteriormente. Por exemplo, se as chamadas ocorreram no contexto de um corpo de modelo, não diagnosticaremos a chamada. Além disso, se houver várias instâncias de chamadas para funções excluídas, poderíamos emitir apenas um diagnóstico. Agora, emitimos um diagnóstico para cada um deles.

Uma consequência do novo comportamento pode produzir uma pequena alteração significativa: o código que chamou uma função excluída não seria diagnosticado se nunca fosse necessário para a geração de código. Agora, vamos diagnostica-lo antecipadamente.

Este exemplo mostra o código que agora produz um erro:

```cpp
struct S {
  S() = delete;
  S(int) { }
};

struct U {
  U() = delete;
  U(int i): s{ i } { }

  S s{};
};

U u{ 0 };
```

```Output
error C2280: 'S::S(void)': attempting to reference a deleted function
note: see declaration of 'S::S'
note: 'S::S(void)': function was explicitly deleted
```

Para resolver o problema, remova as chamadas para funções excluídas:

```cpp
struct S {
  S() = delete;
  S(int) { }
};

struct U {
  U() = delete;
  U(int i): s{ i } { }

  S s;  // Do not call the deleted ctor of 'S'.
};

U u{ 0 };
```

## <a name="conformance-improvements-in-visual-studio-2019-version-166"></a><a name="improvements_166"></a> Melhorias de conformidade no Visual Studio 2019 versão 16,6

### <a name="standard-library-streams-reject-insertions-of-mis-encoded-character-types"></a>Os fluxos de biblioteca padrão rejeitam inserções de tipos de caracteres codificados incorretamente

Tradicionalmente, inserir um **`wchar_t`** em um `std::ostream` , e inserir **`char16_t`** ou **`char32_t`** em um `std::ostream` ou `std::wostream` , gera seu valor integral. A inserção de ponteiros para esses tipos de caractere gera o valor do ponteiro. Os programadores não encontram nenhum dos casos intuitivos. Em geral, eles esperam que a biblioteca padrão transcodifique o caractere ou a cadeia de caracteres terminada em nulo e gere o resultado.

A proposta de C++ 20 [P1423R3](https://wg21.link/p1423r3) adiciona sobrecargas de operador de inserção de fluxo excluídas para essas combinações de tipos de ponteiro de fluxo e caractere ou caractere. Em **`/std:c++latest`** , as sobrecargas tornam essas inserções malformadas, em vez de se comportarem do que é provavelmente uma maneira não intencional. O compilador gera o erro C2280 quando um é encontrado. Você pode definir a macro "hachura de escape" `_HAS_STREAM_INSERTION_OPERATORS_DELETED_IN_CXX20` para `1` restaurar o comportamento antigo. (A proposta também exclui operadores de inserção de fluxo para **`char8_t`** . Nossa biblioteca padrão implementou sobrecargas semelhantes quando adicionamos **`char8_t`** suporte, de modo que o comportamento "errado" nunca esteve disponível para o **`char8_t`** .)

Este exemplo mostra o comportamento com essa alteração:

```cpp
#include <iostream>
int main() {
    const wchar_t cw = L'x', *pw = L"meow";
    const char16_t c16 = u'x', *p16 = u"meow";
    const char32_t c32 = U'x', *p32 = U"meow";
    std::cout << cw << ' ' << pw << '\n';
    std::cout << c16 << ' ' << p16 << '\n';
    std::cout << c32 << ' ' << p32 << '\n';
    std::wcout << c16 << ' ' << p16 << '\n';
    std::wcout << c32 << ' ' << p32 << '\n';
}
```

O código agora produz estas mensagens de diagnóstico:

```Output
error C2280: 'std::basic_ostream<char,std::char_traits<char>> &std::<<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,wchar_t)': attempting to reference a deleted function
error C2280: 'std::basic_ostream<char,std::char_traits<char>> &std::<<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,char16_t)': attempting to reference a deleted function
error C2280: 'std::basic_ostream<char,std::char_traits<char>> &std::<<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,char32_t)': attempting to reference a deleted function
error C2280: 'std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &std::<<<std::char_traits<wchar_t>>(std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &,char16_t)': attempting to reference a deleted function
error C2280: 'std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &std::<<<std::char_traits<wchar_t>>(std::basic_ostream<wchar_t,std::char_traits<wchar_t>> &,char32_t)': attempting to reference a deleted function
```

Você pode obter o efeito do comportamento antigo em todos os modos de linguagem convertendo tipos de caracteres para **`unsigned int`** , ou tipos de ponteiro para caractere para `const void*` :

```c++
#include <iostream>
int main() {
    const wchar_t cw = L'x', *pw = L"meow";
    const char16_t c16 = u'x', *p16 = u"meow";
    const char32_t c32 = U'x', *p32 = U"meow";
    std::cout << (unsigned)cw << ' ' << (const void*)pw << '\n'; // Outputs "120 0052B1C0"
    std::cout << (unsigned)c16 << ' ' << (const void*)p16 << '\n'; // Outputs "120 0052B1CC"
    std::cout << (unsigned)c32 << ' ' << (const void*)p32 << '\n'; // Outputs "120 0052B1D8"
    std::wcout << (unsigned)c16 << ' ' << (const void*)p16 << '\n'; // Outputs "120 0052B1CC"
    std::wcout << (unsigned)c32 << ' ' << (const void*)p32 << '\n'; // Outputs "120 0052B1D8"
}
```

### <a name="changed-return-type-of-stdpow-for-stdcomplex"></a>Tipo de retorno alterado de `std::pow()` para `std::complex`

Anteriormente, a implementação de MSVC das regras de promoção para o tipo de retorno do modelo de função `std::pow()` estava incorreta. Por exemplo, `pow(complex<float>, int)` retornado anteriormente `complex<float>` . Agora ele retorna corretamente `complex<double>` . A correção foi implementada incondicionalmente para todos os modos de padrões no Visual Studio 2019 versão 16,6.

Essa alteração pode causar erros de compilador. Por exemplo, anteriormente você poderia multiplicar `pow(complex<float>, int)` por um **`float`** . Como `complex<T> operator*` o espera argumentos do mesmo tipo, o exemplo a seguir agora emite o erro do compilador C2676: `binary '*': 'std::complex<double>' does not define this operator or a conversion to a type acceptable to the predefined operator` :

```cpp
// pow_error.cpp
// compile by using: cl /EHsc /nologo /W4 pow_error.cpp
#include <complex>

int main() {
    std::complex<float> cf(2.0f, 0.0f);
    (void) (std::pow(cf, -1) * 3.0f);
}
```

Há muitas correções possíveis:

- Altere o tipo de **`float`** multiplicando para **`double`** . Esse argumento pode ser convertido diretamente em um `complex<double>` para corresponder ao tipo retornado por `pow` .

- Restrinja o resultado de `pow` ao `complex<float>` dizendo `complex<float>{pow(ARG, ARG)}` . Em seguida, você pode continuar a multiplicar por um **`float`** valor.

- Passe **`float`** em vez de **`int`** para `pow` . Esta operação pode ser mais lenta.

- Em alguns casos, você pode evitar `pow` totalmente. Por exemplo, `pow(cf, -1)` pode ser substituído por divisão.

### <a name="switch-related-warnings-for-c"></a>Avisos relacionados ao comutador para C

A partir do Visual Studio 2019 versão 16,6, o compilador implementa alguns avisos de C++ preexistentes para o código compilado como C. Os seguintes avisos agora estão habilitados em diferentes níveis: C4060, C4061, C4062, C4063, C4064, C4065, C4808 e C4809. Os avisos C4065 e C4060 são desabilitados por padrão em C.

O gatilho de avisos sobre **`case`** instruções ausentes, indefinidos **`enum`** e opções incorretas **`bool`** (ou seja, aquelas que contêm muitos casos). Por exemplo:

```c
#include <stdbool.h>

int main() {
    bool b = true;
    switch (b) {
        case true: break;
        case false: break;
        default: break; // C4809: switch statement has redundant 'default' label;
                        // all possible 'case' labels are given
    }
}
```

Para corrigir esse código, remova o **`default`** caso redundante:

```c
#include <stdbool.h>

int main() {
    bool b = true;
    switch (b) {
        case true: break;
        case false: break;
    }
}
```

### <a name="unnamed-classes-in-typedef-declarations"></a>Classes sem nome em `typedef` declarações

A partir do Visual Studio 2019 versão 16,6, o comportamento das **`typedef`** declarações foi restrito a estar em conformidade com o [P1766R1](https://wg21.link/P1766R1). Com esta atualização, as classes sem nome dentro de uma **`typedef`** declaração não podem ter membros diferentes de:

- Membros de dados não estáticos,
- classes de membro,
- enumerações de membro,
- e inicializadores de membro padrão.

As mesmas restrições são aplicadas recursivamente a cada classe aninhada. A restrição destina-se a garantir a simplicidade de structs que têm **`typedef`** nomes para fins de vinculação. Eles devem ser simples o suficiente para que nenhum cálculo de ligação seja necessário antes que o compilador obtenha o **`typedef`** nome para vinculação.

Essa alteração afeta todos os modos de padrões do compilador. Em padrão ( **`/std:c++14`** ) e  **`/std:c++17`** modos, o compilador emite o aviso C5208 para o código não compatível. Se **`/permissive-`** for especificado, o compilador emitirá o aviso C5208 como um erro em **`/std:c++14`** e emitirá o erro C7626 em **`/std:c++17`** . O compilador emite o erro C7626 para o código não compatível quando **`/std:c++latest`** é especificado.

O exemplo a seguir mostra as construções que não são mais permitidas em structs sem nome. Dependendo do modo de padrões especificado, erros ou avisos C5208 ou C7626 são emitidos:

```cpp
struct B { };
typedef struct : B { // inheriting from 'B'; ill-formed
    void f(); // ill-formed
    static int i; // ill-formed
    struct U {
        void f(); // nested class has non-data member; ill-formed
    };
    int j = 10; // default member initializer; ill-formed
} S;
```

O código acima pode ser corrigido fornecendo o nome da classe sem nome:

```cpp
struct B { };
typedef struct S_ : B {
    void f();
    static int i;
    struct U {
        void f();
    };
    int j = 10;
} S;
```

### <a name="default-argument-import-in-ccli"></a>Importação de argumento padrão em C++/CLI

Um número cada vez maior de APIs tem argumentos padrão no .NET Core. É por isso que agora damos suporte à importação de argumento padrão em C++/CLI. Essa alteração pode interromper o código existente em que várias sobrecargas são declaradas, como neste exemplo:

```cpp
public class R {
    public void Func(string s) {}   // overload 1
    public void Func(string s, string s2 = "") {} // overload 2;
}
```

Quando essa classe é importada para C++/CLI, uma chamada para uma das sobrecargas causa um erro:

```cpp
    (gcnew R)->Func("abc"); // error C2668: 'R::Func' ambiguous call to overloaded function
```

O compilador emite o erro C2668 porque as sobrecargas correspondem a essa lista de argumentos. Na segunda sobrecarga, o segundo argumento é preenchido pelo argumento padrão. Para contornar esse problema, você pode excluir a sobrecarga redundante (1). Ou use a lista completa de argumentos e forneça explicitamente os argumentos padrão.

## <a name="conformance-improvements-in-visual-studio-2019-version-167"></a><a name="improvements_167"></a> Melhorias de conformidade no Visual Studio 2019 versão 16,7

### <a name="definition-of-is-trivially-copyable"></a>A definição de *é trivialmente copiável*

O c++ 20 alterou a definição de *é trivialmente copiável*. Quando uma classe tem um membro de dados não estático com **`volatile`** tipo qualificado, ela não implica mais que qualquer Construtor de cópia ou movimentação gerado pelo compilador, ou operador de atribuição de cópia ou movimentação, não é trivial. O Comitê standard do C++ aplicou essa alteração retroativamente como um relatório de defeito. No MSVC, o comportamento do compilador não é alterado em modos de linguagem diferentes, como **`/std:c++14`** ou **`/std:c++latest`** .

Veja um exemplo do novo comportamento:

```cpp
#include <type_traits>

struct S
{
    volatile int m;
};

static_assert(std::is_trivially_copyable_v<S>, "Meow!");
```

Este código não é compilado em versões do MSVC antes do Visual Studio 2019 versão 16,7. Há um aviso de compilador fora por padrão que você pode usar para detectar essa alteração. Se você compilar o código acima usando **`cl /W4 /w45220`** o, você verá o seguinte aviso:

C5220 de aviso: `'S::m': a non-static data member with a volatile qualified type no longer implies that compiler generated copy/move constructors and copy/move assignment operators are non trivial`

### <a name="pointer-to-member-and-string-literal-conversions-to-bool-are-narrowing"></a>Conversões de ponteiro para membro e literal de cadeia de caracteres para `bool` estão estreitando

O Comitê standard do C++ adotou recentemente um relatório de defeito [P1957R2](https://wg21.link/p1957r2), que considera `T*`  ->  **`bool`** como uma conversão de restrição. O MSVC corrigiu um bug em sua implementação, que deve ser diagnosticado anteriormente `T*`  ->  **`bool`** como restrito, mas não Diagnostique a conversão de um literal de cadeia de caracteres para **`bool`** ou um ponteiro para membro para **`bool`** .

O programa a seguir está mal formado no Visual Studio 2019 versão 16,7:

```cpp
struct X { bool b; };
void f(X);

int main() {
    f(X { "whoops?" }); // error: conversion from 'const char [8]' to 'bool' requires a narrowing conversion

    int (X::* p) = nullptr;
    f(X { p }); // error: conversion from 'int X::*' to 'bool' requires a narrowing conversion
}
```

Para corrigir esse código, adicione comparações explícitas **`nullptr`** ou Evite contextos em que conversões redutoras são malformadas:

```cpp
struct X { bool b; };
void f(X);

int main() {
    f(X { "whoops?" != nullptr }); // Absurd, but OK

    int (X::* p) = nullptr;
    f(X { p != nullptr }); // OK
}
```

### <a name="nullptr_t-is-only-convertible-to-bool-as-a-direct-initialization"></a>`nullptr_t` Só é conversível `bool` como uma inicialização direta

No C++ 11, **`nullptr`** só é conversível **`bool`** como uma *conversão direta*; por exemplo, quando você inicializa um **`bool`** usando uma lista de inicializadores de chaves. Essa restrição nunca foi imposta por MSVC. MSVC agora implementa a regra em [`/permissive-`](../build/reference/permissive-standards-conformance.md) . Conversões implícitas agora são diagnosticadas como mal formadas. Uma conversão contextual para **`bool`** ainda é permitida, pois a inicialização direta `bool b(nullptr)` é válida.

Na maioria dos casos, o erro pode ser corrigido com a substituição por **`nullptr`** **`false`** , conforme mostrado neste exemplo:

```cpp
struct S { bool b; };
void g(bool);
bool h() { return nullptr; } // error, should be 'return false;'

int main() {
    bool b1 = nullptr; // error: cannot convert from 'nullptr' to 'bool'
    S s { nullptr }; // error: cannot convert from 'nullptr' to 'bool'
    g(nullptr); // error: cannot convert argument 1 from 'nullptr' to 'bool'

    bool b2 { nullptr }; // OK: Direct-initialization
    if (!nullptr) {} // OK: Contextual conversion to bool
}
```

### <a name="conforming-initialization-behavior-for-array-initializations-with-missing-initializers"></a>Conformidade do comportamento de inicialização para inicializações de matriz com inicializadores ausentes

Anteriormente, MSVC tinha um comportamento não compatível para inicializações de matriz que tinham inicializadores ausentes. MSVC sempre chamou o construtor padrão para cada elemento de matriz que não tinha um inicializador. O comportamento padrão é inicializar cada elemento com um colchete de chave-inicializador vazio ( **`{}`** ). O contexto de inicialização para uma lista de chaves-inicializadores vazia é a inicialização de cópia, o que não permite chamadas para construtores explícitos. Também pode haver diferenças de tempo de execução, pois `{}` o uso de para inicializar pode chamar um construtor que usa um `std::initializer_list` , em vez do construtor padrão. O comportamento de conformidade é habilitado em [`/permissive-`](../build/reference/permissive-standards-conformance.md) .

Veja um exemplo do comportamento alterado:

```cpp
struct B {
    explicit B() {}
};

void f() {
    B b1[1]{}; // Error in /permissive-, because aggregate init calls explicit ctor
    B b2[1]; // OK: calls default ctor for each array element
}
```

## <a name="bug-fixes-and-behavior-changes-in-visual-studio-2019"></a><a name="update_160"></a> Correções de bugs e alterações de comportamento no Visual Studio 2019

### <a name="reinterpret_cast-in-a-constexpr-function"></a>`reinterpret_cast` em uma `constexpr` função

Um **`reinterpret_cast`** é ilegal em uma **`constexpr`** função. O compilador do Microsoft C++ seria rejeitado anteriormente **`reinterpret_cast`** apenas se fosse usado em um **`constexpr`** contexto. No Visual Studio 2019, em todos os modos de padrões de linguagem, o compilador diagnostica corretamente um **`reinterpret_cast`** na definição de uma **`constexpr`** função. O código a seguir agora produz C3615: `constexpr function 'f' cannot result in a constant expression` .

```cpp
long long i = 0;
constexpr void f() {
    int* a = reinterpret_cast<int*>(i);
}
```

Para evitar o erro, remova o **`constexpr`** modificador da declaração de função.

### <a name="correct-diagnostics-for-basic_string-range-constructor"></a>Diagnóstico correto para o construtor do intervalo basic_string

No Visual Studio 2019, o `basic_string` Construtor Range não suprime mais o diagnóstico do compilador com **`static_cast`** . O código a seguir é compilado sem avisos no Visual Studio 2017, apesar da possível perda de dados do **`wchar_t`** ao **`char`** inicializar `out` :

```cpp
std::wstring ws = /* … */;
std::string out(ws.begin(), ws.end());
```

O Visual Studio 2019 gera corretamente o aviso C4244: `'argument': conversion from 'wchar_t' to 'const _Elem', possible loss of data` . Para evitar o aviso, é possível inicializar o std::string como mostrado neste exemplo:

```cpp
std::wstring ws = L"Hello world";
std::string out;
for (wchar_t ch : ws)
{
    out.push_back(static_cast<char>(ch));
}
```

### <a name="incorrect-calls-to--and---under-clr-or-zw-are-now-correctly-detected"></a>Chamadas incorretas para `+=` and `-=` sob `/clr` ou `/ZW` agora estão corretamente detectadas

Foi introduzido um bug no Visual Studio 2017 que fazia com que o compilador ignorasse silenciosamente os erros e não gerava nenhum código para as chamadas inválidas para **`+=`** e **`-=`** sob **`/clr`** ou **`/ZW`** . O código a seguir compila sem erros no Visual Studio 2017, mas no Visual Studio 2019 ele gera corretamente o erro C2845: `'System::String ^': pointer arithmetic not allowed on this type` :

```cpp
public enum class E { e };

void f(System::String ^s)
{
    s += E::e; // C2845 in VS2019
}
```

Para evitar o erro neste exemplo, use o **`+=`** operador com o `ToString()` método: `s += E::e.ToString();` .

### <a name="initializers-for-inline-static-data-members"></a>Inicializadores de membros de dados estáticos embutidos

Os acessos a membros inválidos dentro de **`inline`** e **`static constexpr`** inicializadores agora são detectados corretamente. O exemplo a seguir compila sem erro no Visual Studio 2017, mas no Visual Studio 2019 em **`/std:c++17`** modo, ele gera o erro C2248: `cannot access private member declared in class 'X'` .

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

MSVC costumava ter um aviso de desempenho C4800 sobre a conversão implícita no **`bool`** . Ele estava muito ruidosa e não pôde ser suprimido, levando-nos a removê-lo no Visual Studio 2017. No entanto, durante o ciclo de vida do Visual Studio 2017, recebemos muitos comentários sobre os casos úteis que ele estava resolvendo. No Visual Studio 2019, estamos retornando um C4800 cuidadosamente ajustado com o C4165 explicativo. Ambos os avisos são fáceis de suprimir: usando uma conversão explícita ou por comparação com 0 do tipo apropriado. O C4800 é um aviso desativado por padrão de nível 4 e o C4165 é um aviso desativado por padrão de nível 3. Ambos são detectáveis usando a **`/Wall`** opção do compilador.

O exemplo a seguir gera C4800 e C4165 em **`/Wall`** :

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

No Visual Studio 2017, o aviso C4822: `Local class member function doesn't have a body` é gerado somente quando a opção do compilador **`/w14822`** é definida explicitamente. Ele não é mostrado com **`/Wall`** . No Visual Studio 2019, C4822 é um aviso desativado por padrão, o que o torna detectável **`/Wall`** sem a necessidade de definir **`/w14822`** explicitamente.

```cpp
void example()
{
    struct A
        {
            int boo(); // warning C4822
        };
}
```

### <a name="function-template-bodies-containing-if-constexpr-statements"></a>Corpos de modelo de função contendo `if constexpr` instruções

Os corpos de função **`if constexpr`** de modelo contendo instruções têm algumas [`/permissive-`](../build/reference/permissive-standards-conformance.md) verificações relacionadas à análise habilitadas. Por exemplo, no Visual Studio 2017, o código a seguir produz C7510: `'Type': use of dependent type name must be prefixed with 'typename'` somente se a **`/permissive-`** opção não estiver definida. No Visual Studio 2019, o mesmo código gera erros mesmo quando a **`/permissive-`** opção é definida:

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

Para evitar o erro, adicione a **`typename`** palavra-chave à declaração de `a` : `typename T::Type a;` .

### <a name="inline-assembly-code-isnt-supported-in-a-lambda-expression"></a>Não há suporte ao código do assembly embutido em uma expressão lambda

A equipe do Microsoft C++ foi recentemente consciente de um problema de segurança no qual o uso de Assembler embutido em um lambda poderia causar a corrupção de `ebp` (o registro do endereço de retorno) em tempo de execução. Um invasor mal-intencionado possivelmente poderia tirar proveito desse cenário. O Assembler embutido só tem suporte no x86, e a interação entre o Assembler embutido e o restante do compilador é ruim. Considerando esses fatos e a natureza do problema, a solução mais segura para esse problema foi não permitir o Assembler embutido dentro de uma expressão lambda.

O único uso do assembler embutido em uma expressão lambda que encontramos “em condições naturais” era capturar o endereço de retorno. Nesse cenário, é possível capturar o endereço de retorno em todas as plataformas usando simplesmente um `_ReturnAddress()` intrínseco do compilador.

O código a seguir produz C7552: `inline assembler is not supported in a lambda` no visual studio 2017 15,9 e no visual studio 2019:

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

### <a name="iterator-debugging-and-stdmove_iterator"></a>Depuração do iterador e `std::move_iterator`

O recurso de depuração do iterador foi ensinado a desencapsular adequadamente o `std::move_iterator`. Por exemplo, agora `std::copy(std::move_iterator<std::vector<int>::iterator>, std::move_iterator<std::vector<int>::iterator>, int*)` pode envolver o caminho `memcpy` rápido.

### <a name="fixes-for-xkeycheckh-keyword-enforcement"></a>Correções para \<xkeycheck.h> imposição de palavra-chave

A imposição da biblioteca padrão no \<xkeycheck.h> para macros que substitui uma palavra-chave foi corrigida. A biblioteca agora emite a palavra-chave do problema real detectada em vez de uma mensagem genérica. Ela também dá suporte a palavras-chave do C++20 e evita enganar o IntelliSense dizendo que palavras-chave são macros.

### <a name="allocator-types-no-longer-deprecated"></a>Tipos de alocador não mais preteridos

`std::allocator<void>`, `std::allocator::size_type` e `std::allocator::difference_type` não são mais preteridos.

### <a name="correct-warning-for-narrowing-string-conversions"></a>Aviso correto para restringir conversões de cadeia de caracteres

Removeu um falso **`static_cast`** de `std::string` que não foi chamado pelo padrão e que suprimiva acidentalmente os avisos de restrição de C4244. As tentativas de chamar `std::string::string(const wchar_t*, const wchar_t*)` agora emitem corretamente o C4244 `narrowing a wchar_t into a char` .

### <a name="various-fixes-for-filesystem-correctness"></a>Várias correções para \<filesystem> exatidão

- Correção de `std::filesystem::last_write_time` falha ao tentar alterar a hora da última gravação do diretório.
- O construtor `std::filesystem::directory_entry` agora armazena um resultado com falha, em vez de gerar uma exceção, quando um caminho de destino não existente é fornecido.
- A versão de dois parâmetros `std::filesystem::create_directory` foi alterada para chamar a versão de um parâmetro, pois a função `CreateDirectoryExW` subjacente usaria `copy_symlink` quando `existing_p` fosse um symlink.
- `std::filesystem::directory_iterator` não falha mais quando um symlink corrompido é encontrado.
- `std::filesystem::space` agora aceita caminhos relativos.
- `std::filesystem::path::lexically_relative` não é mais confundido com barras à direita, relatado como [LWG 3096](https://cplusplus.github.io/LWG/issue3096).
- Solução de `CreateSymbolicLinkW` que rejeitava caminhos com barras à esquerda em `std::filesystem::create_symlink`.
- Trabalhou na função do modo de exclusão do POSIX `delete` que existia no Windows 10 LTSB 1609, mas não podia realmente excluir arquivos.
- Os operadores de atribuição de cópia e construtores de cópia do `std::boyer_moore_searcher` e do `std::boyer_moore_horspool_searcher` agora realmente copiam coisas.

### <a name="parallel-algorithms-on-windows-8-and-later"></a>Algoritmos paralelos no Windows 8 e posterior

A biblioteca de algoritmos paralelos agora usa devidamente a família `WaitOnAddress` real no Windows 8 e posterior, em vez de sempre usar o Windows 7 e versões falsas anteriores.

### <a name="stdsystem_categorymessage-whitespace"></a>Espaço em branco em `std::system_category::message()`

`std::system_category::message()` agora corta o espaço em branco à direita da mensagem retornada.

### <a name="stdlinear_congruential_engine-divide-by-zero"></a>Divisão por zero em `std::linear_congruential_engine`

Algumas condições que poderiam fazer `std::linear_congruential_engine` disparar a divisão por 0 foram corrigidas.

### <a name="fixes-for-iterator-unwrapping"></a>Correções para desencapsulamento do iterador

Algumas máquinas de iterador-desencapsulamento foram expostas primeiro para a integração de usuário do programador no Visual Studio 2017 15,8. Ele foi descrito no artigo do blog da equipe do C++ [recursos STL e correções no VS 2017 15,8](https://devblogs.microsoft.com/cppblog/stl-features-and-fixes-in-vs-2017-15-8/). Essa maquina não desenvolve mais os iteradores derivados dos iteradores de biblioteca padrão. Por exemplo, um usuário derivado de `std::vector<int>::iterator` e que tenta personalizar o comportamento agora obtém seu comportamento personalizado ao chamar algoritmos de biblioteca padrão, em vez do comportamento de um ponteiro.

Agora, a função `reserve` de contêiner não ordenada na verdade reserva N elementos, conforme descrito em [LWG 2156](https://cplusplus.github.io/LWG/issue2156).

### <a name="time-handling"></a>Manipulação de tempo

- Anteriormente, alguns valores temporais que eram passados para a biblioteca de simultaneidade estourariam, por exemplo, `condition_variable::wait_for(seconds::max())`. Agora corrigidos, os estouros mudaram o comportamento em um ciclo aparentemente aleatório de 29 dias (quando uint32_t milissegundos aceitos pelas APIs do Win32 subjacentes estouravam).

- O \<ctime> cabeçalho agora declara `timespec` e `timespec_get` no namespace corretamente `std` e também os declara no namespace global.

### <a name="various-fixes-for-containers"></a>Várias correções de contêineres

- Muitas funções de contêiner interno da biblioteca padrão tornaram-se privadas para uma experiência aprimorada do IntelliSense. Outras correções para marcar membros como privados são esperadas em versões posteriores do MSVC.

- Problemas de exatidão de segurança de exceção nos quais contêineres baseados em nós, como `list`, `map` e `unordered_map`, se tornariam corrompidos foram corrigidos. Durante uma `propagate_on_container_copy_assignment` `propagate_on_container_move_assignment` operação ou reatribuição, liberamos o nó Sentinel do contêiner com o alocador antigo, fazemos a atribuição de POCCA/POCMA sobre o alocador antigo e, em seguida, tentamos adquirir o nó Sentinel do novo alocador. Se essa alocação falhou, o contêiner estava corrompido. Ele não poderia até ser destruído, pois a propriedade de um nó Sentinela é uma invariável de estrutura de dados rígido. Esse código foi corrigido para criar o novo nó Sentinel usando o alocador do contêiner de origem antes de destruir o nó sentinela existente.

- Os contêineres foram corrigidos para alocadores sempre copiar/mover/trocar de acordo com `propagate_on_container_copy_assignment`, `propagate_on_container_move_assignment` e `propagate_on_container_swap`, mesmo para alocadores declarados `is_always_equal`.

- Foram adicionadas sobrecargas para mesclagem de contêiner e extração de funções de membro que aceitam contêineres rvalue. Para obter mais informações, consulte o [P0083 "mapas e conjuntos do da União"](https://wg21.link/p0083r3)

### <a name="stdbasic_istreamread-processing-of-rn--n"></a>`std::basic_istream::read` processamento de `\r\n`` => ` \n '

`std::basic_istream::read`foi corrigido para não gravar em partes do buffer fornecido temporariamente como parte do `\r\n`  =>  `\n` processamento. Essa alteração perde um pouco da vantagem de desempenho que foi obtida no Visual Studio 2017 15.8 para leituras com mais de 4 K. No entanto, as melhorias na eficiência evitando três chamadas virtuais por caractere ainda estão presentes.

### <a name="stdbitset-constructor"></a>Construtor `std::bitset`

O construtor `std::bitset` não lê mais os numerais um e zero em ordem inversa em conjuntos de bits grandes.

### <a name="stdpairoperator-regression"></a>Regressão de `std::pair::operator=`

Correção de uma regressão no operador de atribuição do `std::pair` introduzida ao implementar [LWG 2729 "SFINAE ausente em std::pair::operator =";](https://cplusplus.github.io/LWG/issue2729). Ele agora aceita corretamente tipos conversíveis em `std::pair` novamente.

### <a name="non-deduced-contexts-for-add_const_t"></a>Contextos não deduzidos para `add_const_t`

Correção de um bug de características de tipo secundário, em que `add_const_t` e funções relacionadas devem ser um contexto não deduzido. Em outras palavras, `add_const_t` deve ser um alias para `typename add_const<T>::type`, e não `const T`.

## <a name="bug-fixes-and-behavior-changes-in-162"></a><a name="update_162"></a> Correções de bugs e alterações de comportamento em 16,2

### <a name="const-comparators-for-associative-containers"></a>Comparadores const para contêineres associativos

O código para pesquisa e inserção em [set](../standard-library/set-class.md), map [,](../standard-library/multiset-class.md)e [Multimap](../standard-library/multimap-class.md) foi mesclado para tamanho de código reduzido. [map](../standard-library/map-class.md) As operações de inserção agora chamam a comparação de menor que em um **`const`** functor de comparação, da mesma forma que as operações de pesquisa foram feitas anteriormente. O código a seguir é compilado no Visual Studio 2019 versão 16,1 e anterior, mas gera C3848 no Visual Studio 2019 versão 16,2:

```cpp
#include <iostream>
#include <map>

using namespace std;

struct K
{
   int a;
   string b = "label";
};

struct Comparer  {
   bool operator() (K a, K b) {
      return a.a < b.a;
   }
};

map<K, double, Comparer> m;

K const s1{1};
K const s2{2};
K const s3{3};

int main() {

   m.emplace(s1, 1.08);
   m.emplace(s2, 3.14);
   m.emplace(s3, 5.21);

}
```

Para evitar o erro, torne o operador de comparação **`const`** :

```cpp
struct Comparer  {
   bool operator() (K a, K b) const {
      return a.a < b.a;
   }
};

```

## <a name="bug-fixes-and-behavior-changes-in-visual-studio-2019-version-167"></a><a name="updates_167"></a> Correções de bugs e alterações de comportamento no Visual Studio 2019 versão 16,7

### <a name="initialization-of-class-members-with-overloaded-names-is-correctly-sequenced"></a>A inicialização de membros de classe com nomes sobrecarregados está sequenciada corretamente

Identificamos um bug na representação interna dos membros de dados de classe quando um nome de tipo também é sobrecarregado como o nome de um membro de dados. Esse bug causou inconsistências na inicialização agregada e na ordem de inicialização do membro. O código de inicialização gerado agora está correto. No entanto, essa alteração pode levar a erros ou avisos na fonte que dependam inadvertidamente dos membros com ordem incorreta, como neste exemplo:

```cpp
// Compiling with /w15038 now gives:
// warning C5038: data member 'Outer::Inner' will be initialized after data member 'Outer::v'
struct Outer {
    Outer(int i, int j) : Inner{ i }, v{ j } {}

    struct Inner { int x; };
    int v;
    Inner Inner; // 'Inner' is both a type name and data member name in the same scope
};
```

Em versões anteriores, o Construtor inicializaria incorretamente o membro de dados `Inner` antes do membro de dados `v` . (O padrão C++ requer uma ordem de inicialização que seja igual à ordem de declaração dos membros). Agora que o código gerado segue o padrão, o membro-init-List está fora de ordem. O compilador gera um aviso para este exemplo. Para corrigi-lo, reordene a lista de inicializadores de membro para refletir a ordem da declaração.

### <a name="overload-resolution-involving-integral-overloads-and-long-arguments"></a>Resolução de sobrecarga envolvendo sobrecargas e `long` argumentos integral

O padrão C++ exige a classificação de a **`long`** para **`int`** conversão como uma conversão padrão. Os compiladores MSVC anteriores o classificam incorretamente como uma promoção integral, que classifica mais para resolução de sobrecarga. Essa classificação pode fazer com que a resolução de sobrecarga seja resolvida com êxito quando deve ser considerada ambígua.

O compilador agora considera a classificação corretamente no [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo. O código inválido é diagnosticado corretamente, como neste exemplo:

```cpp
void f(long long);
void f(int);

int main() {
    long x {};
    f(x); // error: 'f': ambiguous call to overloaded function
    f(static_cast<int>(x)); // OK
}
```

Você pode corrigir esse problema de várias maneiras:

- No local de chamada, altere o tipo do argumento passado para **`int`** . Você pode alterar o tipo de variável ou convertê-lo.

- Se houver muitos sites de chamada, você poderá adicionar outra sobrecarga que usa um **`long`** argumento. Nessa função, converta e encaminhe o argumento para a **`int`** sobrecarga.

### <a name="use-of-undefined-variable-with-internal-linkage"></a>Uso de variável indefinida com ligação interna

Versões do MSVC antes do Visual Studio 2019 versão 16,7 aceitam o uso de uma variável declarada **`extern`** que tinha ligação interna e não foi definida. Essas variáveis não podem ser definidas em nenhuma outra unidade de tradução e não podem formar um programa válido. O compilador agora diagnostica esse caso no momento da compilação. O erro é semelhante ao erro para funções estáticas indefinidas.

```cpp
namespace {
    extern int x; // Not a definition, but has internal linkage because of the anonymous namespace
}

int main()
{
    return x; // Use of 'x' that no other translation unit can possibly define.
}
```

Este programa foi compilado e vinculado anteriormente, mas agora emitirá:

erro C7631: `'anonymous-namespace'::x': variable with internal linkage declared but not defined`

Essas variáveis devem ser definidas na mesma unidade de tradução em que são usadas. Por exemplo, você pode fornecer um inicializador explícito ou uma definição separada.

### <a name="type-completeness-and-derived-to-base-pointer-conversions"></a>Conversões de tipo completo e de ponteiro derivadas para base

Em padrões do C++ antes do C++ 20, uma conversão de uma classe derivada em uma classe base não exigia que a classe derivada fosse um tipo de classe completo. O Comitê standard do C++ aprovou uma alteração de relatório de defeito retroativa que se aplica a todas as versões da linguagem C++. Essa alteração alinha o processo de conversão com características de tipo, como `std::is_base_of` , que exigem que a classe derivada seja um tipo de classe completo.

Aqui está um exemplo:

```cpp
template<typename A, typename B>
struct check_derived_from
{
    static A a;
    static constexpr B* p = &a;
};

struct W { };
struct X { };
struct Y { };

// With this change this code will fail as Z1 is not a complete class type
struct Z1 : X, check_derived_from<Z1, X>
{
};

// This code failed before and it will still fail after this change
struct Z2 : check_derived_from<Z2, Y>, Y
{
};

// With this change this code will fail as Z3 is not a complete class type
struct Z3 : W
{
    check_derived_from<Z3, W> cdf;
};
```

Essa alteração de comportamento se aplica a todos os modos de linguagem C++ de MSVC, não apenas **`/std:c++latest`** .

### <a name="narrowing-conversions-are-more-consistently-diagnosed"></a>Conversões redutoras são diagnosticadas de forma mais consistente

MSVC emite um aviso para restringir conversões em um inicializador de lista de chaves. Anteriormente, o compilador não diagnosticaria conversões estreitas de **`enum`** tipos subjacentes maiores para tipos integrais mais estreitos. (O compilador considera incorretamente uma promoção integral em vez de uma conversão). Se a conversão de restrição for intencional, você poderá evitar o aviso usando um **`static_cast`** no argumento do inicializador. Ou escolha um tipo de integral de destino maior.

Aqui está um exemplo de como usar um explícito **`static_cast`** para resolver o aviso:

```cpp
enum E : long long { e1 };
struct S { int i; };

void f(E e) {
    S s = { e }; // warning: conversion from 'E' to 'int' requires a narrowing conversion
    S s1 = { static_cast<int>(e) }; // Suppress warning with explicit conversion
}
```

::: moniker-end

::: moniker range="vs-2017"

## <a name="conformance-improvements-in-visual-studio-2017-rtw-version-150"></a><a name="improvements_150"></a> Melhorias de conformidade no Visual Studio 2017 RTW (versão 15,0)

Com suporte para **`constexpr`** NSDMI (inicialização de membro de dados) generalizada e não estática para agregações, o compilador do Microsoft C++ no Visual Studio 2017 agora está completo para os recursos adicionados no padrão C++ 14. No entanto, o compilador ainda não tem alguns recursos dos padrões C++11 e C++98. Consulte a [tabela de conformidade da linguagem Microsoft C++](../visual-cpp-language-conformance.md) para obter uma tabela que mostra o estado atual do compilador.

### <a name="c11-expression-sfinae-support-in-more-libraries"></a>C++ 11: suporte ao Expression SFINAE em mais bibliotecas

O compilador continua a melhorar seu suporte para o Expression SFINAE. Ele é necessário para dedução de argumento de modelo e substituição onde **`decltype`** e **`constexpr`** as expressões podem aparecer como parâmetros de modelo. Para obter mais informações, consulte [Expression SFINAE improvements in Visual Studio 2017 RC (Melhorias da expressão SFINAE no Visual Studio 2017 RC)](https://devblogs.microsoft.com/cppblog/expression-sfinae-improvements-in-vs-2015-update-3/).

### <a name="c14-nsdmi-for-aggregates"></a>C++ 14: NSDMI para agregações

Uma agregação é uma matriz ou uma classe que tem: nenhum construtor fornecido pelo usuário, nenhum membro de dados não estático privado ou protegido, nenhuma classe base e nenhuma função virtual. A partir do C++ 14, as agregações podem conter inicializadores de membro. Para obter mais informações, consulte [Member initializers and aggregates (Inicializadores de membro e agregações)](https://wg21.link/n3605).

### <a name="c14-extended-constexpr"></a>C++ 14: estendido `constexpr`

As expressões declaradas como **`constexpr`** agora podem conter determinados tipos de declarações, instruções IF e switch, instruções de loop e mutação de objetos cujo tempo de vida começou dentro da **`constexpr`** avaliação da expressão. Não há mais um requisito de que uma **`constexpr`** função de membro não estática deva ser implicitamente **`const`** . Para obter mais informações, consulte [relaxando restrições em `constexpr` funções](https://wg21.link/n3652).

### <a name="c17-terse-static_assert"></a>C++ 17: conciso `static_assert`

o parâmetro de mensagem para **`static_assert`** é opcional. Para obter mais informações, consulte [Extending static_assert, v2 (Estendendo static_assert, v2)](https://wg21.link/n3928).

### <a name="c17-fallthrough-attribute"></a>C++17: atributo `[[fallthrough]]`

No **`/std:c++17`** modo, o `[[fallthrough]]` atributo pode ser usado no contexto de instruções switch como uma dica para o compilador que o comportamento de passagem é pretendido. Esse atributo impede o compilador de emitir avisos em tais casos. Para obter mais informações, consulte [palavras para o `[[fallthrough]]` atributo](https://wg21.link/p0188r0).

### <a name="generalized-range-based-for-loops"></a>Generalizados baseados em intervalo para loops

Loops for baseados em intervalo não exigem mais que `begin()` e `end()` retornem objetos do mesmo tipo. Essa mudança permite que `end()` retorne uma sentinela conforme usado pelos intervalos em [range-v3](https://github.com/ericniebler/range-v3) e na Especificação Técnica de Intervalos concluída, mas não completamente publicada. Para obter mais informações, consulte [generalizando o `for` loop baseado em intervalo](https://wg21.link/p0184r0).

## <a name="conformance-improvements-in-153"></a><a name="improvements_153"></a> Melhorias de conformidade no 15,3

### <a name="constexpr-lambdas"></a>`constexpr` Lambdas

Expressões Lambda agora podem ser usadas em expressões de constante. Para obter mais informações, consulte [ `constexpr` expressões lambda em C++](../cpp/lambda-expressions-constexpr.md).

### <a name="if-constexpr-in-function-templates"></a>`if constexpr` em modelos de função

Um modelo de função pode conter **`if constexpr`** instruções para habilitar a ramificação em tempo de compilação. Para obter mais informações, consulte [ `if constexpr` instruções](../cpp/if-else-statement-cpp.md#if_constexpr).

### <a name="selection-statements-with-initializers"></a>Instruções de seleção com inicializadores

Uma **`if`** instrução pode incluir um inicializador que apresenta uma variável no escopo do bloco dentro da própria instrução. Para obter mais informações, consulte [ `if` instruções com inicializador](../cpp/if-else-statement-cpp.md#if_with_init).

### <a name="maybe_unused-and-nodiscard-attributes"></a>Atributos `[[maybe_unused]]` e `[[nodiscard]]`

O novo atributo `[[maybe_unused]]` silencia avisos quando uma entidade não é usada. O atributo `[[nodiscard]]` criará um aviso se o valor retornado de uma chamada de função for descartado. Para saber mais, veja [Atributos em C++](../cpp/attributes.md).

### <a name="using-attribute-namespaces-without-repetition"></a>Uso de namespaces de atributo sem repetição

Nova sintaxe para permitir apenas um único identificador de namespace em uma lista de atributos. Para saber mais, veja [Atributos em C++](../cpp/attributes.md).

### <a name="structured-bindings"></a>Associações estruturadas

Agora é possível, em uma única declaração, armazenar um valor com nomes individuais de seus componentes, quando o valor é uma matriz, um `std::tuple` ou `std::pair`, ou tem todos os membros de dados não estáticos públicos. Para saber mais, veja [Associações estruturadas](https://wg21.link/p0144r0) e [Retornar vários valores de uma função](../cpp/functions-cpp.md#multi_val).

### <a name="construction-rules-for-enum-class-values"></a>Regras de construção para valores `enum class`

Agora há uma conversão implícita para enumerações com escopo que não são restritas. Ele converte de um tipo subjacente de enumeração com escopo para a própria enumeração. A conversão está disponível quando sua definição não introduz um enumerador e quando a origem usa uma sintaxe de inicialização de lista. Para saber mais, veja [Regras de construção para valores de classe de enumeração](https://wg21.link/p0138r2)e[Enumerações](../cpp/enumerations-cpp.md#no_enumerators).

### <a name="capturing-this-by-value"></a>Capturar `*this` por valor

O **`*this`** objeto em uma expressão lambda agora pode ser capturado por valor. Essa mudança permite cenários nos quais o lambda é invocado em operações paralelas e assíncronas, especialmente em arquiteturas de computadores mais recentes. Para obter mais informações, consulte [captura de lambda disso \* por valor como \[ =, \* isso \] ](https://wg21.link/p0018r3).

### <a name="removing-operator-for-bool"></a>Remover `operator++` para `bool`

`operator++` Não é mais suportado em **`bool`** tipos. Para saber mais, veja [Remover operator++(bool) preterido](https://wg21.link/p0002r1).

### <a name="removing-deprecated-register-keyword"></a>Remover a palavra-chave `register` preterida

A **`register`** palavra-chave, anteriormente preterida (e ignorada pelo compilador), agora é removida da linguagem. Para obter mais informações, consulte [remover o uso preterido da `register` palavra-chave](https://wg21.link/p0001r1).

## <a name="conformance-improvements-in-155"></a><a name="improvements_155"></a> Melhorias de conformidade no 15,5

Os recursos marcados com \[ 14] estão disponíveis incondicionalmente até mesmo no **`/std:c++14`** modo.

### <a name="new-compiler-switch-for-extern-constexpr"></a>Nova opção de compilador para `extern constexpr`

Em versões anteriores do Visual Studio, o compilador sempre deu um **`constexpr`** vínculo interno de variável, mesmo quando a variável foi marcada **`extern`** . No Visual Studio 2017 versão 15,5, uma nova opção de compilador, [`/Zc:externConstexpr`](../build/reference/zc-externconstexpr.md) , habilita o comportamento correto e de conformidade com os padrões. Para obter mais informações, consulte [vinculação de contexpr externo](#extern_linkage).

### <a name="removing-dynamic-exception-specifications"></a>Remover especificações de exceção dinâmica

[P0003R5](https://wg21.link/p0003r5) As especificações de exceções dinâmicas foram preteridas no C++11. O recurso foi removido do C++17, mas a especificação `throw()` (ainda) preterida é mantida estritamente como um alias para `noexcept(true)`. Para obter mais informações, consulte [Remoção de especificação de exceção dinâmica e noexcept](#noexcept_removal).

### `not_fn()`

[P0005R4](https://wg21.link/p0005r4) `not_fn` é uma substituição de `not1` e `not2`.

### <a name="rewording-enable_shared_from_this"></a>Reescrever `enable_shared_from_this`

[P0033R1](https://wg21.link/p0033r1) `enable_shared_from_this` foi adicionada no C++ 11. O padrão C++17 atualiza a especificação para lidar melhor com certos casos de canto. \[140

### <a name="splicing-maps-and-sets"></a>Unir mapas e conjuntos

[P0083R3](https://wg21.link/p0083r3) Esse recurso permite a extração de nós de contêineres associativos (ou seja,,,, `map` `set` `unordered_map` `unordered_set` ) que podem ser modificados e inseridos novamente no mesmo contêiner ou em um contêiner diferente que usa o mesmo tipo de nó. (É um caso de uso comum extrair um nó de um `std::map`, alterar a chave e inseri-lo novamente.)

### <a name="deprecating-vestigial-library-parts"></a>Preterir partes residuais da biblioteca

[P0174R2](https://wg21.link/p0174r2) Vários recursos da biblioteca padrão do C++ foram substituídos por novos recursos ao longo dos anos, ou porque não se mostraram úteis, ou porque apresentaram problemas. Esses recursos foram oficialmente preteridos no C++17.

### <a name="removing-allocator-support-in-stdfunction"></a>Remover o suporte ao alocador em `std::function`

[P0302R1](https://wg21.link/p0302r1) Antes do C++ 17, o modelo de classe `std::function` tinha vários construtores que pegavam um argumento de alocador. No entanto, o uso de alocadores neste contexto era problemático e a semântica era confusa. Os construtores de problema foram removidos.

### <a name="fixes-for-not_fn"></a>Correções para `not_fn()`

[P0358R1](https://wg21.link/p0358r1) A nova expressão para `std::not_fn` dão suporte à propagação de categoria de valor quando usada na invocação do wrapper.

### <a name="shared_ptrt-shared_ptrtn"></a>`shared_ptr<T[]>`, `shared_ptr<T[N]>`

[P0414R2](https://wg21.link/p0414r2) Mesclando alterações do `shared_ptr` dos Princípios básicos de biblioteca para o C++17. \[140

### <a name="fixing-shared_ptr-for-arrays"></a>Corrigir `shared_ptr` para matrizes

[P0497R0](https://wg21.link/p0497r0) Correções para o suporte de shared_ptr para matrizes. \[140

### <a name="clarifying-insert_return_type"></a>Esclarecer `insert_return_type`

[P0508R0](https://wg21.link/p0508r0) Os contêineres associativos e não ordenados, ambos com chaves exclusivas, têm uma função de membro `insert` que retorna um tipo aninhado `insert_return_type`. O tipo de retorno agora é definido como uma especialização de um tipo com parâmetros no iterador e NodeType do contêiner.

### <a name="inline-variables-for-the-standard-library"></a>Variáveis embutidas para a biblioteca padrão

[P0607R0](https://wg21.link/p0607r0)

### <a name="annex-d-features-deprecated"></a>Recursos preteridos do anexo D

O anexo D do C++ padrão contém todos os recursos que foram preteridos, incluindo `shared_ptr::unique()`, `<codecvt>` e `namespace std::tr1`. Quando a **`/std:c++17`** opção do compilador é definida, quase todos os recursos de biblioteca padrão no anexo D são marcados como preteridos. Para obter mais informações, consulte [recursos de biblioteca padrão no anexo D são marcados como preteridos](#annex_d).

O `std::tr2::sys` namespace no `<experimental/filesystem>` agora emite um aviso de reprovação sob **`/std:c++14`** por padrão e agora é removido sob **`/std:c++17`** por padrão.

Melhoria na conformidade em `<iostream>`, evitando uma extensão não padrão (especializações explícitas na classe).

A biblioteca padrão agora usa modelos de variável internamente.

A biblioteca padrão foi atualizada em resposta às alterações do compilador C++ 17. As atualizações incluem a adição de **`noexcept`** no sistema de tipos e a remoção de especificações dinâmicas de exceção.

## <a name="conformance-improvements-in-156"></a><a name="improvements_156"></a> Melhorias de conformidade no 15,6

### <a name="c17-library-fundamentals-v1"></a>Princípios básicos da biblioteca C++17 V1

O [P0220R1](https://wg21.link/p0220r1) incorpora a especificação técnica dos princípios básicos da biblioteca para o C++17 no padrão. Aborda atualizações para,,,,,, \<experimental/tuple> \<experimental/optional> \<experimental/functional> \<experimental/any> \<experimental/string_view> \<experimental/memory> \<experimental/memory_resource> e \<experimental/algorithm> .

### <a name="c17-improving-class-template-argument-deduction-for-the-standard-library"></a>C++ 17: melhorando a dedução de argumento de modelo de classe para a biblioteca padrão

O [P0739R0](https://wg21.link/p0739r0) move o `adopt_lock_t` para a frente da lista de parâmetros para `scoped_lock` a fim de habilitar o uso consistente de `scoped_lock`. Permite que o construtor `std::variant` participe na resolução de sobrecarga em mais casos para habilitar a atribuição de cópia.

## <a name="conformance-improvements-in-157"></a><a name="improvements_157"></a> Melhorias de conformidade no 15,7

### <a name="c17-rewording-inheriting-constructors"></a>C++ 17: repalavras que herdam construtores

[P0136R1](https://wg21.link/p0136r1) especifica que uma **`using`** declaração que nomeia um Construtor agora faz com que os construtores de classe base correspondentes fiquem visíveis para inicializações da classe derivada, em vez de declarar construtores de classe derivados adicionais. Essa reformulação é uma mudança a partir do C++14. No Visual Studio 2017 versão 15,7 e posterior, no **`/std:c++17`** modo, o código que é válido no c++ 14 e usa construtores de herança pode não ser válido ou ter semânticas diferentes.

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

O exemplo a seguir mostra o **`/std:c++17`** comportamento no Visual Studio 15,7:

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

### <a name="c17-extended-aggregate-initialization"></a>C++ 17: inicialização de agregação estendida

[P0017R1](https://wg21.link/p0017r1)

Se o construtor de uma classe base for não público, mas estiver acessível a uma classe derivada, em **`/std:c++17`** modo no Visual Studio 2017 versão 15,7, você não poderá mais usar chaves vazias para inicializar um objeto do tipo derivado.
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
O exemplo a seguir mostra o comportamento do C++ 17 no Visual Studio versão 15,7 no **`/std:c++17`** modo:

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

### <a name="c17-declaring-non-type-template-parameters-with-auto"></a>C++ 17: declarando parâmetros de modelo sem tipo com auto

[P0127R2](https://wg21.link/p0127r2)

No **`/std:c++17`** modo, o compilador agora pode deduzir o tipo de um argumento de modelo não tipo que é declarado com **`auto`** :

```cpp
template <auto x> constexpr auto constant = x;

auto v1 = constant<5>;      // v1 == 5, decltype(v1) is int
auto v2 = constant<true>;   // v2 == true, decltype(v2) is bool
auto v3 = constant<'a'>;    // v3 == 'a', decltype(v3) is char
```

Um impacto desse novo recurso é que um código válido do C++14 pode não ser válido ou pode ter semântica diferente. Por exemplo, algumas sobrecargas que anteriormente eram inválidas, agora são válidas. O exemplo a seguir mostra um código do C++14 que é compilado porque a chamada a `example(p)` está associada a `example(void*);`. No Visual Studio 2017 versão 15,7, no **`/std:c++17`** modo, o `example` modelo de função é a melhor correspondência.

```cpp
template <int N> struct A;
template <typename T, T N> int example(A<N>*) = delete;

void example(void *);

void sample(A<0> *p)
{
    example(p); // OK in C++14
}
```

O exemplo a seguir mostra o código C++ 17 no Visual Studio 15,7 no **`/std:c++17`** modo:

```cpp
template <int N> struct A;
template <typename T, T N> int example(A<N>*);

void example(void *);

void sample(A<0> *p)
{
    example(p); // C2280: 'int example<int,0>(A<0>*)': attempting to reference a deleted function
}
```

### <a name="c17-elementary-string-conversions-partial"></a>C++ 17: conversões elementares de cadeia de caracteres (parcial)

[P0067R5](https://wg21.link/p0067r5) funções de nível baixo, independentes de localidade para conversões entre cadeias de caracteres e inteiros e entre cadeias de caracteres e números de ponto flutuante.

### <a name="c20-avoiding-unnecessary-decay-partial"></a>C++ 20: evitando decaimento desnecessárias (parcial)

[P0777R1](https://wg21.link/p0777r1) Adiciona diferenciação entre o conceito de "decaimento" e o da simples remoção de const ou de qualificadores de referência.  A característica de novo tipo de `remove_reference_t` substitui `decay_t` em alguns contextos. O suporte a `remove_cvref_t` é implementado no Visual Studio 2019.

### <a name="c17-parallel-algorithms"></a>C++ 17: algoritmos paralelos

[P0024R2](https://wg21.link/p0024r2) A TS de paralelismo será incorporada no padrão, com pequenas modificações.

### <a name="c17-hypotx-y-z"></a>C++17: `hypot(x, y, z)`

[P0030R1](https://wg21.link/p0030r1) Adiciona três novas sobrecargas para `std::hypot` , para tipos **`float`** , **`double`** e **`long double`** , cada uma delas tem três parâmetros de entrada.

### <a name="c17-filesystem"></a>C++17: \<filesystem>

[P0218R1](https://wg21.link/p0218r1) Adota a TS do sistema de arquivos no padrão, com algumas modificações de frase.

### <a name="c17-mathematical-special-functions"></a>C++ 17: funções especiais matemáticas

[P0226R1](https://wg21.link/p0220r1) Adota especificações técnicas anteriores para funções especiais matemáticas no cabeçalho padrão \<cmath> .

### <a name="c17-deduction-guides-for-the-standard-library"></a>C++ 17: guias de dedução para a biblioteca padrão

[P0433R2](https://wg21.link/p0433r2) Atualizações ao STL para aproveitar a adoção do [P0091R3](https://wg21.link/p0091r3) pelo C++17, que adiciona suporte à dedução de argumento de modelo de classe.

### <a name="c17-repairing-elementary-string-conversions"></a>C++ 17: reparar conversões de cadeia de caracteres elementares

[P0682R1](https://wg21.link/p0682r1) Mova as novas funções de conversão de cadeia de caracteres elementares do P0067R5 para um novo cabeçalho \<charconv> e faça outras melhorias, incluindo a alteração do tratamento de erro a ser usado `std::errc` em vez de `std::error_code` .

### <a name="c17-constexpr-for-char_traits-partial"></a>C++17: `constexpr` para `char_traits` (parcial)

[P0426R1](https://wg21.link/p0426r1) Alterações em `std::traits_type` funções de membro `length` , `compare` e `find` para tornar `std::string_view` utilizáveis em expressões constantes. (No Visual Studio 2017 versão 15.6, compatível somente com Clang/LLVM. Na versão 15.7 Preview 2, há compatibilidade quase concluída com ClXX também).

## <a name="conformance-improvements-in-159"></a><a name="improvements_159"></a> Melhorias de conformidade no 15,9

### <a name="left-to-right-evaluation-order-for-operators-----and-"></a>Ordem de avaliação da esquerda para a direita para os operadores `->*`, `[]`, `>>` e `<<`

A partir do C++17, os operandos dos operadores `->*`, `[]`, `>>` e `<<` devem ser avaliados na ordem da esquerda para a direita. Há dois casos em que o compilador não conseguirá garantir esta ordem:

- quando uma das expressões do operando é um objeto passado por valor ou que contém um objeto passado por valor ou

- Quando compilado usando **`/clr`** , e um dos operandos é um campo de um objeto ou um elemento de matriz.

O compilador emite um aviso [C4866](../error-messages/compiler-warnings/c4866.md) quando não é capaz de garantir a avaliação da esquerda para a direita. O compilador gera esse aviso somente se **`/std:c++17`** ou mais tarde for especificado, pois o requisito de ordem da esquerda para a direita desses operadores foi introduzido em c++ 17.

Para resolver esse aviso, primeiro considere se a avaliação da esquerda para a direita dos operandos é necessária. Por exemplo, pode ser necessário quando a avaliação dos operandos puder produzir efeitos colaterais dependentes de ordem. A ordem na qual os operandos são avaliados não tem nenhum efeito observável em muitos casos. Se a ordem da avaliação precisar ser da esquerda para a direita, considere se não é possível passar os operandos por referência const. Essa alteração elimina o aviso no seguinte exemplo de código:

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

## <a name="bug-fixes-in-visual-studio-2017-rtw-version-150"></a><a name="update_150"></a> Correções de bugs no Visual Studio 2017 RTW (versão 15.0)

### <a name="copy-list-initialization"></a>Inicialização de lista de cópia

O Visual Studio 2017 gera corretamente erros de compilador relacionados à criação de objetos usando listas de inicializadores. Esses erros não foram capturados no Visual Studio 2015 e podem levar a falhas ou comportamento indefinido do tempo de execução. De acordo com o N4594 13.3.1.7 P1, na inicialização de lista de cópia, o compilador é necessário para considerar um construtor explícito para resolução de sobrecarga. No entanto, ele deve gerar um erro se essa sobrecarga específica for escolhida.

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

No Visual Studio 2015, o compilador incorretamente tratava a inicialização da lista de cópia da mesma maneira que a inicialização de cópia regular: ela considerou apenas converter construtores para resolução de sobrecarga. No exemplo a seguir, o Visual Studio 2015 escolhe `MyInt(23)` . O Visual Studio 2017 gera corretamente o erro.

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

O Visual Studio 2017 agora emite o aviso correto para TYPEDEFs preteridos declarados em uma classe ou estrutura. O exemplo a seguir compila sem avisos no Visual Studio 2015. Ele produz C4996 no Visual Studio 2017.

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

O Visual Studio 2017 gera corretamente um erro quando o operando esquerdo de uma operação de avaliação condicional não é válido em um contexto constexpr. O código a seguir é compilado no Visual Studio 2015, mas não no Visual Studio 2017, onde ele gera C3615 `constexpr function 'f' cannot result in a constant expression` :

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

Para corrigir o erro, declare a `array::size()` função como **`constexpr`** ou remova o **`constexpr`** qualificador de `f` .

### <a name="class-types-passed-to-variadic-functions"></a>Tipos de classe passados para funções variadic

No Visual Studio 2017, as classes ou structs que são passadas para uma função Variadic como `printf` devem ser trivialmente copiáveis. Ao passar esses objetos, o compilador simplesmente faz uma cópia bit a bit e não chama o construtor nem o destruidor.

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

Para cadeias de caracteres criadas e gerenciadas usando `CString` , o fornecido `operator LPCTSTR()` deve ser usado para converter um `CString` objeto para o ponteiro C esperado pela cadeia de caracteres de formato.

```cpp
CString str1;
CString str2 = _T("hello!");
str1.Format(_T("%s"), static_cast<LPCTSTR>(str2));
```

### <a name="cv-qualifiers-in-class-construction"></a>Qualificadores CV na construção de classe

No Visual Studio 2015, às vezes, o compilador ignora incorretamente o qualificador CV ao gerar um objeto de classe por meio de uma chamada do construtor. Eventualmente, esse problema pode gerar uma falha ou comportamento inesperado do runtime. O exemplo a seguir é compilado no Visual Studio 2015, mas gera um erro de compilador no Visual Studio 2017:

```cpp
struct S
{
    S(int);
    operator int();
};

int i = (const S)0; // error C2440
```

Para corrigir o erro, declare `operator int()` como **`const`** .

### <a name="access-checking-on-qualified-names-in-templates"></a>Verificação de acesso em nomes qualificados em modelos

As versões anteriores do compilador não verificaram o acesso a nomes qualificados em alguns contextos de modelo. Esse problema pode interferir no comportamento esperado do SFINAE, em que a substituição deve falhar devido à inacessibilidade de um nome. Ele poderia ter causado potencialmente uma falha ou um comportamento inesperado no tempo de execução, pois o compilador incorretamente chamou a sobrecarga incorreta do operador. No Visual Studio 2017, é gerado um erro do compilador. O erro específico pode variar, mas normalmente é C2672 `no matching overloaded function found` . O código a seguir é compilado no Visual Studio 2015, mas gera um erro no Visual Studio 2017:

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

No Visual Studio 2015 e anterior, o compilador não diagnósticou todas as listas de argumentos de modelo ausentes. Não notaria quando o modelo ausente apareceu em uma lista de parâmetros de modelo: por exemplo, quando parte de um argumento de modelo padrão ou um parâmetro de modelo sem tipo estava ausente. Esse problema pode resultar em comportamento imprevisível, incluindo falhas do compilador ou comportamento inesperado do runtime. O código a seguir é compilado no Visual Studio 2015, mas produz um erro no Visual Studio 2017.

```cpp
template <class T> class ListNode;
template <class T> using ListNodeMember = ListNode<T> T::*;
template <class T, ListNodeMember M> class ListHead; // C2955: 'ListNodeMember': use of alias
                                                     // template requires template argument list

// correct:  template <class T, ListNodeMember<T> M> class ListHead;
```

### <a name="expression-sfinae"></a>Expressão SFINAE

Para dar suporte ao Expression-SFINAE, o compilador agora analisa **`decltype`** argumentos quando os modelos são declarados em vez de instanciados. Consequentemente, se uma especialização não dependente for encontrada no argumento decltype, ela não será adiada para a hora da instanciação. Ela será processada imediatamente, e qualquer erro resultante será diagnosticado nesse momento.

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

De acordo com o padrão C++, uma classe declarada dentro de um namespace anônimo tem vinculação interna, e isso significa que ela não pode ser exportada. No Visual Studio 2015 e anteriores, essa regra não era aplicada. No Visual Studio 2017, a regra é parcialmente aplicada. No Visual Studio 2017, o exemplo a seguir gera o erro C2201: `const anonymous namespace::S1::vftable: must have external linkage in order to be exported/imported.`

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

No Visual Studio 2015 e em versões anteriores, o compilador, em alguns casos, identificava incorretamente uma propriedade padrão como um indexador padrão. Era possível contornar o problema usando o identificador **`default`** para acessar a propriedade. A solução alternativa se tornou problemática após ter **`default`** sido introduzida como uma palavra-chave em c++ 11. No Visual Studio 2017, os bugs que exigiam a solução alternativa foram corrigidos. O compilador agora gera um erro quando **`default`** é usado para acessar a propriedade padrão para uma classe.

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

## <a name="bug-fixes-in-153"></a><a name="update_153"></a> Correções de bugs no 15,3

### <a name="calls-to-deleted-member-templates"></a>Chamadas para modelos de membros excluídos

Nas versões anteriores do Visual Studio, o compilador em alguns casos não emitiria um erro para chamadas malformadas para um modelo de membro excluído. Essas chamadas poderiam causar falhas em tempo de execução. O código a seguir agora produz C2280, `'int S<int>::f<int>(void)': attempting to reference a deleted function` :

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

Para corrigir o erro, declare `i` como **`int`** .

### <a name="pre-condition-checks-for-type-traits"></a>Verificações de pré-condição para características de tipo

O Visual Studio 2017 versão 15.3 melhora as verificações de pré-condição para características de tipo para seguir o padrão mais estritamente. Uma verificação assim destina-se aos atribuíveis. O código a seguir produz C2139 no Visual Studio 2017 versão 15.3:

```cpp
struct S;
enum E;

static_assert(!__is_assignable(S, S), "fail"); // C2139 in 15.3
static_assert(__is_convertible_to(E, E), "fail"); // C2139 in 15.3
```

### <a name="new-compiler-warning-and-runtime-checks-on-native-to-managed-marshaling"></a>Novas verificações de runtime e o aviso do compilador em marshaling nativo para gerenciado

Chamar desde funções gerenciadas a funções nativas requer o marshaling. O CLR faz marshaling, mas não entende a semântica do C++. Se você passar um objeto nativo por valor, o CLR chamará o construtor de cópia do objeto ou usará `BitBlt`, o que poderá causar um comportamento indefinido em runtime.

Agora, o compilador emite um aviso se encontrar esse erro no momento da compilação: um objeto nativo com o construtor de cópia excluído é passado entre um limite nativo e o gerenciado por valor. Nos casos em que o compilador não souber no tempo de compilação, ele injetará uma verificação de runtime para que o programa chame `std::terminate` imediatamente quando um marshaling malformado ocorrer. No Visual Studio 2017 versão 15,3, o código a seguir produz o aviso C4606 `'A': passing argument by value across native and managed boundary requires valid copy constructor. Otherwise, the runtime behavior is undefined.`

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

As APIs do WinRT lançadas para experimentação e comentários são decoradas com `Windows.Foundation.Metadata.ExperimentalAttribute`. No Visual Studio 2017 versão 15,3, o compilador produz o aviso C4698 para este atributo. Algumas APIs em versões anteriores do SDK do Windows já tinham sido decoradas com o atributo, e chamadas para essas APIs agora começam a disparar esse aviso do compilador. SDKs mais recentes do Windows têm o atributo removido de todos os tipos enviados. Se estiver usando um SDK mais antigo, você precisará suprimir esses avisos para todas as chamadas para os tipos enviados.

O código a seguir produz o aviso C4698: `'Windows::Storage::IApplicationDataStatics2::GetForUserAsync' is for evaluation purposes only and is subject to change or removal in future updates` :

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

O Visual Studio 2017 versão 15,3 produz um erro para uma definição fora de linha de uma função de membro de modelo que não foi declarada na classe. O código a seguir agora produz o erro C2039: `'f': is not a member of 'S'` :

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

Em C++, **`this`** é um não prvalue do tipo ponteiro para X. Você não pode pegar o endereço **`this`** ou associá-lo a uma referência lvalue. Nas versões anteriores do Visual Studio, o compilador permitia contornar essa restrição com o uso de uma conversão. No Visual Studio 2017 versão 15.3, o compilador produz o erro C2664.

### <a name="conversion-to-an-inaccessible-base-class"></a>Conversão em uma classe base inacessível

O Visual Studio 2017 versão 15.3 gera um erro quando você tenta converter um tipo em uma classe base que está inacessível. O compilador agora gera o erro C2243: `'type cast': conversion from 'D *' to 'B *' exists, but is inaccessible` . O código a seguir está malformado e poderá causar uma falha em runtime. O compilador agora produz C2243 quando vê um código como este:

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

Os argumentos padrão não são permitidos em definições fora da linha de funções de membro em classes de modelo. O compilador emitirá um aviso em **`/permissive`** e um erro de hardware em [`/permissive-`](../build/reference/permissive-standards-conformance.md) .

Nas versões anteriores do Visual Studio, o código malformado a seguir pode causar uma falha de runtime. O Visual Studio 2017 versão 15,3 produz o aviso C5034: `'A\<T>::f': an out-of-line definition of a member of a class template cannot have default arguments` :

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

No Visual Studio 2017 versão 15,3, usar `offsetof(T, m)` onde *m* é um "designador de membro composto" resulta em um aviso quando você compila com a **`/Wall`** opção. O código a seguir está malformado e pode causar falhas em runtime. O Visual Studio 2017 versão 15,3 produz o aviso C4841: `non-standard extension used: compound member designator in offsetof` :

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

No Visual Studio 2017 versão 15.3, usar `offsetof(T, m)`, em que *m* se refere a um membro de dados estático ou uma função de membro, resultará em um erro. O código a seguir produz o erro C4597: `undefined behavior: offsetof applied to member function 'example'` e o erro C4597: `undefined behavior: offsetof applied to static data member 'sample'` :

```cpp
#include <cstddef>

struct A {
   int ten() { return 10; }
   static constexpr int two = 2;
};

constexpr auto off = offsetof(A, ten);
constexpr auto off2 = offsetof(A, two);
```

Esse código está malformado e pode causar falhas em runtime. Para corrigir o erro, altere o código para não invocar mais um comportamento indefinido. Esse é o código não portátil que não é permitido pelo padrão C++.

### <a name="new-warning-on-__declspec-attributes"></a><a name="declspec"></a> Novo aviso em atributos `__declspec`

No Visual Studio 2017 versão 15.3, o compilador não ignora os atributos se `__declspec(...)` é aplicado antes da especificação de vinculação `extern "C"`. Anteriormente, o compilador ignorava o atributo, o que podia ter implicações de runtime. Quando as **`/Wall`** **`/WX`** Opções e são definidas, o código a seguir produz o aviso C4768: `__declspec attributes before linkage specification are ignored` :

```cpp
__declspec(noinline) extern "C" HRESULT __stdcall //C4768
```

Para corrigir o aviso, coloque `extern "C"` primeiro:

```cpp
extern "C" __declspec(noinline) HRESULT __stdcall
```

Esse aviso está desativado por padrão em 15,3, mas ativado por padrão em 15,5 e só afeta o código compilado com  **`/Wall`** **`/WX`** .

### <a name="decltype-and-calls-to-deleted-destructors"></a>`decltype` e chamadas para destruidores excluídos

Nas versões anteriores do Visual Studio, o compilador não detectou quando uma chamada a um destruidor excluído ocorreu no contexto da expressão associada a **`decltype`** . No Visual Studio 2017 versão 15,3, o código a seguir produz o erro C2280: `'A<T>::~A(void)': attempting to reference a deleted function` :

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

A versão do Visual Studio 2017 RTW teve uma regressão: o compilador C++ não emitiu um diagnóstico para uma variável não inicializada **`const`** . Essa regressão foi corrigida no Visual Studio 2017 versão 15.3. O código a seguir agora produz o aviso C4132: `'Value': const object should be initialized` :

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

O aviso é excluído em **`/Wv:18`** e está ativado por padrão no nível de aviso W2.

### <a name="stdis_convertible-for-array-types"></a>`std::is_convertible` para tipos de matriz

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

### <a name="private-destructors-and-stdis_constructible"></a>Destruidores privados e `std::is_constructible`

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

### <a name="c2668-ambiguous-overload-resolution"></a>C2668: resolução de sobrecarga ambígua

As versões anteriores do compilador falhavam algumas vezes ao detectar ambiguidade quando encontravam vários candidatos, tanto por meio de declarações using quanto de pesquisas dependentes de argumento. Essa falha pode levar à escolha errada de sobrecarga e ao comportamento inesperado de runtime. No exemplo a seguir, o Visual Studio 2017 versão 15,3 gera C2668 corretamente `'f': ambiguous call to overloaded function` :

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

As declarações de função local ocultam a declaração de função no escopo delimitador e desabilitam a pesquisa dependente de argumento. No entanto, as versões anteriores do compilador sempre fizeram a pesquisa dependente de argumento nesse caso. Ele poderia potencialmente levar à sobrecarga incorreta sendo escolhida e ao comportamento de tempo de execução inesperado. Normalmente, o erro é devido a uma assinatura incorreta da declaração da função local. No exemplo a seguir, o Visual Studio 2017 versão 15,3 gera C2660 corretamente `'f': function does not take two arguments` :

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

Membros de classe são inicializados na ordem em que são declarados, não na ordem em que aparecem nas listas de inicializadores. As versões anteriores do compilador não avisavam quando a ordem da lista de inicializadores era diferente da ordem da declaração. Esse problema pode levar a um comportamento indefinido em tempo de execução se a inicialização de um membro depender de outro membro da lista já estar sendo inicializada. No exemplo a seguir, o Visual Studio 2017 versão 15,3 (with **`/Wall`** ) gera o aviso C5038: `data member 'A::y' will be initialized after data member 'A::x'` :

```cpp
struct A
{
    A(int a) : y(a), x(y) {} // Initialized in reverse, y reused
    int x;
    int y;
};
```

Para corrigir o problema, organize a lista do inicializador para que tenha a mesma ordem que as declarações. Um aviso semelhante é gerado quando um ou ambos os inicializadores fazem referência a membros de classe base.

Esse aviso está fora do padrão e afeta apenas o código compilado com **`/Wall`** .

## <a name="bug-fixes-and-other-behavior-changes-in-155"></a><a name="update_155"></a> Correções de bugs e outras alterações de comportamento no 15,5

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

O problema no exemplo acima é que há duas diferenças nos tipos (const versus não const e pacote versus não pack). Para eliminar o erro do compilador, remova uma das diferenças. Em seguida, o compilador pode ordenar de forma não ambígua as funções.

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

Manipuladores de referência para o tipo de matriz ou função nunca são uma correspondência para qualquer objeto de exceção. O compilador agora segue corretamente essa regra e aciona um aviso de nível 4. Ele também não corresponde mais a um manipulador de `char*` ou `wchar_t*` a uma cadeia de caracteres literal quando **`/Zc:strictStrings`** é usado.

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

### <a name="stdtr1-namespace-is-deprecated"></a>O namespace <a name="tr1"></a> `std::tr1` é preterido

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

### <a name="standard-library-features-in-annex-d-are-marked-as-deprecated"></a><a name="annex_d"></a> Os recursos de biblioteca padrão no anexo D são marcados como preteridos

Quando a **`/std:c++17`** opção de compilador de modo é definida, quase todos os recursos de biblioteca padrão no anexo D são marcados como preteridos.

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

No Visual Studio 2017 versão 15.5, os avisos C4001 e C4179 não são emitidos pelo compilador C. Anteriormente, eles eram emitidos apenas sob a **`/Za`** opção do compilador.  Os avisos não são mais necessários porque comentários de linha única fazem parte do padrão C desde C99.

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

Quando o código não precisa ser compatível com versões anteriores, você pode evitar o aviso removendo a supressão de C4001/C4179. Se o código precisar ser compatível com versões anteriores, suprima somente C4619.

```C

/* C only */

#pragma warning(disable:4619)
#pragma warning(disable:4001)
#pragma warning(disable:4179)

// single line comment
/* single line comment */
```

### <a name="__declspec-attributes-with-extern-c-linkage"></a>Atributos `__declspec` com vinculação `extern "C"`

Em versões anteriores do Visual Studio, o compilador ignorou atributos `__declspec(...)` quando `__declspec(...)` foi aplicado antes da especificação de vinculação `extern "C"`. Esse comportamento faz com que seja gerado código não pretendido pelo usuário, com possíveis consequências no runtime. O aviso foi adicionado no Visual Studio versão 15.3, mas era desativado por padrão. No Visual Studio 2017 versão 15.5, o aviso está habilitado por padrão.

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

### <a name="extern-constexpr-linkage"></a><a name="extern_linkage"></a>`extern constexpr`vinculação

Em versões anteriores do Visual Studio, o compilador sempre deu uma **`constexpr`** variável de vinculação interna mesmo quando a variável foi marcada **`extern`** . No Visual Studio 2017 versão 15,5, uma nova opção de compilador ( **`/Zc:externConstexpr`** ) habilita o comportamento correto de conformidade com padrões. No fim das contas, esse comportamento se tornará o padrão.

```cpp
extern constexpr int x = 10;
```

```Output
error LNK2005: "int const x" already defined
```

Se um arquivo de cabeçalho contiver uma variável declarada **`extern constexpr`** , ele precisará ser marcado `__declspec(selectany)` para ter suas declarações duplicadas combinadas corretamente:

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

### <a name="stdis_convertible-target-type"></a>Tipo de destino de `std::is_convertible`

`std::is_convertible` requer que o tipo de destino seja um tipo de retorno válido. Em versões anteriores do Visual Studio, o compilador permitia incorretamente tipos abstratos, que podem levar à resolução de sobrecarga incorreta e ao comportamento de runtime imprevisto.  O código a seguir agora aciona C2338 corretamente:

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

### <a name="dynamic-exception-specification-removal-and-noexcept"></a><a name="noexcept_removal"></a> Remoção de especificação de exceção dinâmica e `noexcept`

No C++ 17, `throw()` é um alias para **`noexcept`** , `throw(<type list>)` e `throw(...)` é removido, e determinados tipos podem incluir **`noexcept`** . Essa mudança pode causar problemas de compatibilidade de origem com o código que está em conformidade com a C++14 ou anterior. A **`/Zc:noexceptTypes-`** opção pode ser usada para reverter para a versão c++ 14 do **`noexcept`** ao usar o modo c++ 17 em geral. Ela permite atualizar seu código-fonte para estar em conformidade com a C++17 sem precisar reescrever todo o código `throw()` ao mesmo tempo.

O compilador agora também diagnostica mais especificações de exceção incompatíveis em declarações no modo C++ 17 ou com [`/permissive-`](../build/reference/permissive-standards-conformance.md) o novo aviso C5043.

O código a seguir gera C5043 e C5040 no Visual Studio 2017 versão 15,5 quando a **`/std:c++17`** opção é aplicada:

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

Para remover os erros enquanto estiver usando o **`/std:c++17`** , adicione a **`/Zc:noexceptTypes-`** opção à linha de comando ou atualize seu código para usar **`noexcept`** , conforme mostrado no exemplo a seguir:

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

**`constexpr`** Os membros de dados estáticos agora são implicitamente **`inline`** , o que significa que sua declaração dentro de uma classe agora é sua definição. O uso de uma definição fora de linha para um **`static constexpr`** membro de dados é redundante e agora é preterido. No Visual Studio 2017 versão 15,5, quando a **`/std:c++17`** opção é aplicada, o seguinte código agora produz o aviso C5041 `'size': out-of-line definition for constexpr static data member is not needed and is deprecated in C++17` :

```cpp
struct X {
    static constexpr int size = 3;
};
const int X::size; // C5041
```

### <a name="extern-c-__declspec-warning-c4768-now-on-by-default"></a>O aviso C4768 de `extern "C" __declspec(...)` agora está ativado por padrão

O aviso foi adicionado no Visual Studio versão 2017 versão 15.3, mas estava desativado por padrão. No Visual Studio 2017 versão 15.5, o aviso está ativo por padrão. Para obter mais informações, consulte [novo aviso em \_ \_ atributos declspec](#declspec).

### <a name="defaulted-functions-and-__declspecnothrow"></a>Funções usadas como padrão e `__declspec(nothrow)`

O compilador permitia anteriormente que funções padronizadas fossem declaradas com `__declspec(nothrow)` quando as funções de base/membro correspondente permitiam exceções. Esse comportamento é contrário ao padrão C++ e pode causar um comportamento indefinido no runtime. O padrão exige que tais funções sejam definidas como excluídas se houver uma incompatibilidade de especificação de exceção.  Em **`/std:c++17`** , o código a seguir gera C2280 `attempting to reference a deleted function. Function was implicitly deleted because the explicit exception specification is incompatible with that of the implicit declaration.`

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

Com **`noexcept`** no sistema de tipos, as especializações parciais para correspondência de tipos "chamáveis" específicos podem não compilar ou não escolher o modelo primário, devido à ausência de uma especialização parcial para ponteiros para as funções Except.

Nesses casos, talvez seja necessário adicionar mais especialidades parciais para lidar com ponteiros de **`noexcept`** função e **`noexcept`** ponteiros para funções de membro. Essas sobrecargas são apenas no **`/std:c++17`** modo legal. Se for necessário manter a compatibilidade com versões anteriores de C++14 e você estiver escrevendo código que outras pessoas consumirão, será necessário proteger essas novas sobrecargas dentro de diretivas `#ifdef`. Se você estiver trabalhando em um módulo independente, em vez de usar `#ifdef` as proteções, basta compilar com a **`/Zc:noexceptTypes-`** opção.

O código a seguir é compilado em **`/std:c++14`** , mas falha em **`/std:c++17`** com `error C2027: use of undefined type 'A<T>'` :

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

O código a seguir é executado com sucesso **`/std:c++17`** porque o compilador escolhe a nova especialização parcial `A<void (*)() noexcept>` :

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

## <a name="bug-fixes-and-other-behavior-changes-in-157"></a><a name="update_157"></a> Correções de bugs e outras alterações de comportamento no 15,7

### <a name="c17-default-argument-in-the-primary-class-template"></a>C++ 17: argumento padrão no modelo de classe primária

Essa alteração de comportamento é uma pré-condição para [Dedução de argumento de modelo para modelos de classe – P0091R3](https://wg21.link/p0091r3).

Anteriormente, o compilador ignorava o argumento padrão no modelo de classe primária:

```cpp
template<typename T>
struct S {
    void f(int = 0);
};

template<typename T>
void S<T>::f(int = 0) {} // Re-definition necessary
```

No **`/std:c++17`** modo no Visual Studio 2017 versão 15,7, o argumento padrão não é ignorado:

```cpp
template<typename T>
struct S {
    void f(int = 0);
};

template<typename T>
void S<T>::f(int) {} // Default argument is used
```

### <a name="dependent-name-resolution"></a>Resolução de nome dependente

Essa alteração de comportamento é uma pré-condição para [Dedução de argumento de modelo para modelos de classe – P0091R3](https://wg21.link/p0091r3).

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

O Visual Studio 2017 versão 15,7, no **`/std:c++17`** modo, requer a **`typename`** palavra-chave na **`using`** instrução em D. Sem **`typename`** , o compilador gera o aviso C4346: `'B<T*>::type': dependent name is not a type` e o erro C2061: `syntax error: identifier 'type'` :

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

No Visual Studio 2017 versão 15,7 no **`/std:c++17`** modo, o nível de aviso de C4834 `discarding return value of function with 'nodiscard' attribute` é aumentado de W3 para W1. Você pode desabilitar o aviso com uma conversão para **`void`** ou passando **`/wd:4834`** para o compilador

```cpp
[[nodiscard]] int f() { return 0; }

int main() {
    f(); // warning: discarding return value
         // of function with 'nodiscard'
}
```

### <a name="variadic-template-constructor-base-class-initialization-list"></a>Lista de inicialização de classe base do construtor de modelo Variadic

Em edições anteriores do Visual Studio, uma lista de inicialização de classe base do construtor de modelo variadic que não continha argumentos de modelos foi erroneamente permitida sem erro. No Visual Studio 2017 versão 15.7 é gerado um erro do compilador.

O exemplo de código a seguir no Visual Studio 2017 versão 15,7 gera o erro C2614: `D<int>: illegal member initialization: 'B' is not a base or member` .

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

Para corrigir o erro, altere a expressão B () para B \<T> ().

### <a name="constexpr-aggregate-initialization"></a>Inicialização de agregação de `constexpr`

As versões anteriores do compilador C++ manipulavam incorretamente a **`constexpr`** inicialização de agregação. O compilador aceitou o código inválido no qual o Aggregate-init-List tinha muitos elementos e produziu CodeGen incorreto para ele. O código a seguir é um exemplo desse código:

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

No Visual Studio 2017 versão 15,7 atualização 3 e posterior, o exemplo anterior agora gera C2078 `too many initializers` . O exemplo a seguir mostra como corrigir o código. Ao inicializar um `std::array` com chaves init-lists aninhadas, forneça para matriz interna uma lista entre chaves própria:

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

## <a name="bug-fixes-and-behavior-changes-in-158"></a><a name="update_158"></a> Correções de bugs e alterações de comportamento em 15,8

As alterações do compilador no Visual Studio 2017 versão 15,8 são todas as correções de bugs e alterações de comportamento. Eles estão listados abaixo:

### <a name="typename-on-unqualified-identifiers"></a>`typename` em identificadores não qualificados

No [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo, **`typename`** palavras-chave falsas em identificadores não qualificados em definições de modelo de alias não são mais aceitas pelo compilador. O código a seguir agora produz C7511 `'T': 'typename' keyword must be followed by a qualified name` :

```cpp
template <typename T>
using  X = typename T;
```

Para corrigir o erro, altere a segunda linha para `using  X = T;`.

### <a name="__declspec-on-right-side-of-alias-template-definitions"></a>`__declspec()` no lado direito das definições de modelo de alias

[__declspec](../cpp/declspec.md) não é mais permitido no lado direito de uma definição de modelo de alias. Anteriormente, o compilador aceitou, mas ignorei esse código. Ele nunca resultaria em um aviso de reprovação quando o alias foi usado.

O atributo C++ padrão [ \[ \[ \] \] preterido](../cpp/attributes.md) pode ser usado em vez disso e é respeitado no Visual Studio 2017 versão 15,6. O código a seguir agora produz C2760 `syntax error: unexpected token '__declspec', expected 'type specifier'` :

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

Uma forma em que isso se manifesta é com a pesquisa em classes base dependentes. Anteriormente, o compilador permitia o uso de nomes que são definidos em classes base dependentes. Isso ocorre porque eles seriam pesquisados durante o tempo de instanciação quando todos os tipos são resolvidos. Agora, esse código é tratado como um erro. Nesses casos, você pode forçar a pesquisa da variável no tempo de instanciação qualificando-a com o tipo de classe base ou, de outro modo, tornando-a dependente, por exemplo, adicionando um ponteiro `this->`.

No [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo, o código a seguir agora gera C3861: `'base_value': identifier not found` :

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

Para corrigir o erro, altere a **`return`** instrução para `return this->base_value;` .

**Observação:** Na biblioteca do Python Boost, há uma solução alternativa específica de MSVC para uma declaração de encaminhamento de modelo em [unwind_type. HPP](https://github.com/boostorg/python/blame/develop/include/boost/python/detail/unwind_type.hpp). Em [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo começando no Visual Studio 2017 versão 15,8 ( \_ MSC \_ Ver = 1915), o compilador MSVC faz a pesquisa de nome dependente de argumento (ADL) corretamente. Agora é consistente com outros compiladores, tornando essa proteção alternativa desnecessária. Para evitar o erro C3861: `'unwind_type': identifier not found` , consulte [PR 229](https://github.com/boostorg/python/pull/229) no repositório de aumentos para atualizar o arquivo de cabeçalho. Já aplicamos patch no pacote Boost [vcpkg](../build/vcpkg.md), portanto, se você obtiver ou atualizar suas fontes de Boost usando vcpkg, não será necessário aplicar o patch separadamente.

### <a name="forward-declarations-and-definitions-in-namespace-std"></a>Declarações e definições de encaminhamento no namespace `std`

O padrão C++ não permite que um usuário adicione declarações ou definições de encaminhamento no namespace `std`. A adição de declarações ou de definições ao namespace `std` ou a um namespace no namespace `std` agora resulta em um comportamento indefinido.

Em algum momento no futuro, a Microsoft mudará o local em que alguns tipos padrão são definidos. Essa mudança interromperá o código existente que adiciona as declarações de encaminhamento ao namespace `std`. Um novo aviso, o C4643, ajuda a identificar esses problemas de origem. O aviso é habilitado no **`/default`** modo e é desativado por padrão. Ele afetará os programas que são compilados com o **`/Wall`** ou o **`/WX`** .

O código a seguir agora gera C4643: `Forward declaring 'vector' in namespace std is not permitted by the C++ Standard` .

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

O padrão C++ sugere que um compilador deve emitir um diagnóstico quando um construtor de delegação delega a si mesmo. O compilador do Microsoft C++ no [`/std:c++17`](../build/reference/std-specify-language-standard-version.md) e os [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) modos agora geram C7535: `'X::X': delegating constructor calls itself` .

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

[offsetof](../c-runtime-library/reference/offsetof-macro.md) normalmente tem sido implementado usando uma macro que requer um [reinterpret_cast](../cpp/reinterpret-cast-operator.md). Esse uso não é válido em contextos que requerem uma expressão de constante, mas usualmente o compilador C++ da Microsoft tem permitido isso. A macro `offsetof` que é fornecida como parte da biblioteca padrão usa corretamente um compilador intrínseco (**__builtin_offsetof**), mas muitas pessoas têm usado o truque da macro para definir seu próprio `offsetof`.

No Visual Studio 2017 versão 15,8, o compilador restringe as áreas que esses **`reinterpret_cast`** operadores podem aparecer no modo padrão, para ajudar o código a obedecer ao comportamento padrão do C++. Em [`/permissive-`](../build/reference/permissive-standards-conformance.md) , as restrições são ainda mais estritas. O uso do resultado de um `offsetof` em locais que exigem expressões constantes pode resultar em código que emite aviso C4644 `usage of the macro-based offsetof pattern in constant expressions is non-standard; use offsetof defined in the C++ standard library instead` ou C2975 `invalid template argument, expected compile-time constant expression` .

O código a seguir gera C4644 **`/default`** e **`/std:c++17`** modos, e C2975 no [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo:

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

Para corrigir o erro, use `offsetof` conforme definido por meio de \<cstddef> :

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

No Visual Studio 2017 versão 15,8, no [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo, o código a seguir gera C3770 `'const S': is not a valid base class` :

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

No [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo, o compilador agora requer que a **`template`** palavra-chave preceda um nome de modelo quando ele vier após um especificador de nome aninhado dependente.

O código a seguir no [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo agora gera C7510: `'example': use of dependent template name must be prefixed with 'template'. note: see reference to class template instantiation 'X<T>' being compiled` :

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

Para corrigir o erro, adicione a **`template`** palavra-chave à `Base<T>::example<int>();` instrução, conforme mostrado no exemplo a seguir:

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

## <a name="bug-fixes-and-behavior-changes-in-159"></a><a name="update_159"></a> Correções de bugs e alterações de comportamento em 15,9

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

No Visual Studio 2017 versão 15,9, no [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo, o compilador gera C3861: `'from_template': identifier not found` .

Para corrigir o erro, declare `from_template` antes de `from_template_t`.

### <a name="modules-changes"></a>Alterações nos módulos

No Visual Studio 2017, versão 15.9, o compilador gera C5050 sempre que as opções de linha de comando dos módulos não são consistentes entre os lados da criação do módulo e do consumo do módulo. No exemplo a seguir, há dois problemas:

- No lado de consumo (Main. cpp), a opção **`/EHsc`** não é especificada.

- A versão C++ está **`/std:c++17`** no lado da criação e **`/std:c++14`** no lado do consumo.

```cmd
cl /EHsc /std:c++17 m.ixx /experimental:module
cl /experimental:module /module:reference m.ifc main.cpp /std:c++14
```

O compilador gera C5050 para ambos os casos: `warning C5050: Possible incompatible environment while importing module 'm': mismatched C++ versions.  Current "201402" module version "201703"` .

O compilador também gera C7536 sempre que o arquivo .ifc é adulterado. O cabeçalho da interface do módulo contém um hash SHA2 do conteúdo abaixo dele. Na importação, o arquivo. IFC é submetido a hash e, em seguida, verificado em relação ao hash fornecido no cabeçalho. Se eles não corresponderem, o erro C7536 será gerado: `ifc failed integrity checks.  Expected SHA2: '66d5c8154df0c71d4cab7665bab4a125c7ce5cb9a401a4d8b461b706ddd771c6'` .

### <a name="partial-ordering-involving-aliases-and-non-deduced-contexts"></a>Ordenação parcial envolvendo aliases e contextos não deduzidos

As implementações divergem nas regras de ordenação parciais que envolvem aliases em contextos não deduzidos. No exemplo a seguir, GCC e o compilador do Microsoft C++ (no [`/permissive-`](../build/reference/permissive-standards-conformance.md) modo) geram um erro, enquanto Clang aceita o código.

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

Para evitar o erro, remova o **`constexpr`** qualificador da instanciação explícita da função `f()` .

::: moniker-end

::: moniker range="vs-2015"

## <a name="c-conformance-improvements-in-visual-studio-2015"></a>Aprimoramentos de conformidade do C++ no Visual Studio 2015

Temos uma lista completa de melhorias de conformidade no Visual Studio 2015 atualização 3. Para obter mais informações, consulte [Novidades no Visual C++ de 2003 até 2015](/cpp/porting/visual-cpp-what-s-new-2003-through-2015).

::: moniker-end

## <a name="see-also"></a>Confira também

[Tabela de conformidade da linguagem Microsoft C++](visual-cpp-language-conformance.md)
