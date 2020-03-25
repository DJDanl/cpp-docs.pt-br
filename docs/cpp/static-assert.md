---
title: static_assert
ms.date: 07/29/2019
f1_keywords:
- static_assert_cpp
helpviewer_keywords:
- assertions [C++], static_assert
- static_assert
ms.assetid: 28dd3668-e78c-4de8-ba68-552084743426
ms.openlocfilehash: a3336e9e41e3dc6804c2398d3ef815ba8c471e50
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80160899"
---
# <a name="static_assert"></a>static_assert

Testa uma asserção de software no tempo de compilação. Se a expressão constante especificada for FALSE, o compilador exibirá a mensagem especificada, se uma for fornecida, e a compilação falhará com o erro C2338; caso contrário, a declaração não terá nenhum efeito.

## <a name="syntax"></a>Sintaxe

```
static_assert( constant-expression, string-literal );

static_assert( constant-expression ); // C++17 (Visual Studio 2017 and later)
```

#### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*expressão de constante*|Uma expressão constante integral que pode ser convertida em um valor booliano.<br /><br /> Se a expressão avaliada for zero (false), o parâmetro *String-literal* será exibido e a compilação falhará com um erro. Se a expressão for diferente de zero (true), a declaração de **static_assert** não terá nenhum efeito.|
|*string-literal*|Uma mensagem que será exibida se o parâmetro de *expressão constante* for zero. A mensagem é uma cadeia de caracteres no [conjunto de caracteres base](../c-language/ascii-character-set.md) do compilador; ou seja, [caracteres não multibyte ou largos](../c-language/multibyte-and-wide-characters.md).|

## <a name="remarks"></a>Comentários

O parâmetro *constante-expressão* de uma declaração de **static_assert** representa uma *asserção de software*. Uma asserção de software especifica uma condição que você espera ser verdadeira (true) em um ponto específico de seu programa. Se a condição for verdadeira, a declaração de **static_assert** não terá nenhum efeito. Se a condição for falsa, a asserção falhará, o compilador exibirá a mensagem no parâmetro *String-literal* e a compilação falhará com um erro. No Visual Studio 2017 e posterior, o parâmetro String-literal é opcional.

A declaração de **static_assert** testa uma declaração de software no momento da compilação. Por outro lado, a [macro Assert e as funções _assert e _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md) testam uma declaração de software em tempo de execução e incorrem em um custo de tempo de execução em espaço ou tempo. A declaração de **static_assert** é especialmente útil para a depuração de modelos porque os argumentos de modelo podem ser incluídos no parâmetro *constante-expressão* .

O compilador examina a declaração de **static_assert** para erros de sintaxe quando a declaração é encontrada. O compilador avaliará o parâmetro de *expressão constante* imediatamente se ele não depender de um parâmetro de modelo. Caso contrário, o compilador avaliará o parâmetro de *expressão constante* quando o modelo for instanciado. Consequentemente, o compilador pode emitir uma mensagem de diagnóstico uma vez quando a declaração for encontrada e novamente quando o modelo for instanciado.

Você pode usar a palavra-chave **static_assert** em namespace, classe ou escopo de bloco. (A palavra-chave **static_assert** é tecnicamente uma declaração, mesmo que não introduza um novo nome em seu programa, pois ela pode ser usada no escopo do namespace.)

## <a name="description"></a>DESCRIÇÃO

No exemplo a seguir, a declaração de **static_assert** tem escopo de namespace. Como o compilador conhece o tamanho do tipo `void *`, a expressão é avaliada imediatamente.

## <a name="example"></a>Exemplo

```cpp
static_assert(sizeof(void *) == 4, "64-bit code generation is not supported.");
```

## <a name="description"></a>DESCRIÇÃO

No exemplo a seguir, a declaração de **static_assert** tem escopo de classe. O **static_assert** verifica se um parâmetro de modelo é um tipo de *dados simples* (Pod). O compilador examina a declaração de **static_assert** quando ela é declarada, mas não avalia o parâmetro de *expressão constante* até que o modelo de classe `basic_string` seja instanciado em `main()`.

## <a name="example"></a>Exemplo

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

## <a name="description"></a>DESCRIÇÃO

No exemplo a seguir, a declaração de **static_assert** tem escopo de bloco. O **static_assert** verifica se o tamanho da estrutura VMPage é igual ao pageSize de memória virtual do sistema.

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
[Diretiva #error (C/C++)](../preprocessor/hash-error-directive-c-cpp.md)<br/>
[assert Macro, _assert, _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md)<br/>
[Modelos](../cpp/templates-cpp.md)<br/>
[Conjunto de caracteres ASCII](../c-language/ascii-character-set.md)<br/>
[Declarações e definições](declarations-and-definitions-cpp.md)
