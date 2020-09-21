---
title: static_assert
ms.date: 07/29/2019
f1_keywords:
- static_assert_cpp
helpviewer_keywords:
- assertions [C++], static_assert
- static_assert
ms.assetid: 28dd3668-e78c-4de8-ba68-552084743426
ms.openlocfilehash: b30af5fcf5d4f58143e657d84e743ef09a34e268
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742964"
---
# <a name="static_assert"></a>static_assert

Testa uma asserção de software no tempo de compilação. Se a expressão constante especificada for **`false`** , o compilador exibirá a mensagem especificada, se uma for fornecida, e a compilação falhar com o erro C2338; caso contrário, a declaração não terá nenhum efeito.

## <a name="syntax"></a>Sintaxe

```
static_assert( constant-expression, string-literal );

static_assert( constant-expression ); // C++17 (Visual Studio 2017 and later)
```

### <a name="parameters"></a>Parâmetros

*expressão de constante*\
Uma expressão constante integral que pode ser convertida em um valor booliano. Se a expressão avaliada for zero (false), o parâmetro *String-literal* será exibido e a compilação falhará com um erro. Se a expressão for diferente de zero (true), a **`static_assert`** declaração não terá nenhum efeito.

*literal de cadeia de caracteres*\
Uma mensagem que será exibida se o parâmetro de *expressão constante* for zero. A mensagem é uma cadeia de caracteres no [conjunto de caracteres base](../c-language/ascii-character-set.md) do compilador; ou seja, [caracteres não multibyte ou largos](../c-language/multibyte-and-wide-characters.md).

## <a name="remarks"></a>Comentários

O parâmetro *constante-expressão* de uma **`static_assert`** declaração representa uma *asserção de software*. Uma asserção de software especifica uma condição que você espera ser verdadeira (true) em um ponto específico de seu programa. Se a condição for verdadeira, a **`static_assert`** declaração não terá nenhum efeito. Se a condição for falsa, a asserção falhará, o compilador exibirá a mensagem no parâmetro *String-literal* e a compilação falhará com um erro. No Visual Studio 2017 e posterior, o parâmetro String-literal é opcional.

A **`static_assert`** declaração testa uma declaração de software no momento da compilação. Por outro lado, a [macro Assert e as funções _assert e _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md) testam uma declaração de software em tempo de execução e incorrem em um custo de tempo de execução em espaço ou tempo. A **`static_assert`** declaração é especialmente útil para a depuração de modelos porque os argumentos de modelo podem ser incluídos no parâmetro *constante-expressão* .

O compilador examina a **`static_assert`** declaração de erros de sintaxe quando a declaração é encontrada. O compilador avaliará o parâmetro de *expressão constante* imediatamente se ele não depender de um parâmetro de modelo. Caso contrário, o compilador avaliará o parâmetro de *expressão constante* quando o modelo for instanciado. Consequentemente, o compilador pode emitir uma mensagem de diagnóstico uma vez quando a declaração for encontrada e novamente quando o modelo for instanciado.

Você pode usar a **`static_assert`** palavra-chave em namespace, classe ou escopo de bloco. (A **`static_assert`** palavra-chave é tecnicamente uma declaração, mesmo que não introduza um novo nome em seu programa, pois ela pode ser usada no escopo do namespace.)

## <a name="description-of-static_assert-with-namespace-scope"></a>Descrição de static_assert com escopo de namespace

No exemplo a seguir, a **`static_assert`** declaração tem escopo de namespace. Como o compilador conhece o tamanho do tipo `void *`, a expressão é avaliada imediatamente.

## <a name="example-of-static_assert-with-namespace-scope"></a>Exemplo de static_assert com escopo de namespace

```cpp
static_assert(sizeof(void *) == 4, "64-bit code generation is not supported.");
```

## <a name="description-of-static_assert-with-class-scope"></a>Descrição de static_assert com escopo de classe

No exemplo a seguir, a **`static_assert`** declaração tem escopo de classe. O **`static_assert`** verifica se um parâmetro de modelo é um tipo Pod ( *dados antigos simples* ). O compilador examina a **`static_assert`** declaração quando ela é declarada, mas não avalia o parâmetro de *expressão constante* até que o `basic_string` modelo de classe seja instanciado no `main()` .

## <a name="example-of-static_assert-with-class-scope"></a>Exemplo de static_assert com escopo de classe

```cpp
#include <type_traits>
#include <iosfwd>
namespace std {
template <class CharT, class Traits = std::char_traits<CharT> >
class basic_string {
    static_assert(std::is_pod<CharT>::value,
                  "Template argument CharT must be a POD type in class template basic_string");
    // ...
    };
}

struct NonPOD {
    NonPOD(const NonPOD &) {}
    virtual ~NonPOD() {}
};

int main()
{
    std::basic_string<char> bs;
}
```

## <a name="description"></a>Descrição

No exemplo a seguir, a **`static_assert`** declaração tem escopo de bloco. O **`static_assert`** verifica se o tamanho da estrutura VMPage é igual ao pageSize de memória virtual do sistema.

## <a name="example"></a>Exemplo

```cpp
#include <sys/param.h> // defines PAGESIZE
class VMMClient {
public:
    struct VMPage { // ...
           };
    int check_pagesize() {
    static_assert(sizeof(VMPage) == PAGESIZE,
        "Struct VMPage must be the same size as a system virtual memory page.");
    // ...
    }
// ...
};
```

## <a name="see-also"></a>Confira também

[Asserção e mensagens fornecidas pelo usuário (C++)](../cpp/assertion-and-user-supplied-messages-cpp.md)<br/>
[Diretiva de #error (C/C++)](../preprocessor/hash-error-directive-c-cpp.md)<br/>
[Macro Assert, _assert _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md)<br/>
[Modelos](../cpp/templates-cpp.md)<br/>
[Conjunto de caracteres ASCII](../c-language/ascii-character-set.md)<br/>
[Declarações e definições](declarations-and-definitions-cpp.md)
