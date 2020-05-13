---
title: Visão geral do pré-processador experimental MSVC
description: O pré-processador MSVC está sendo atualizado para conformidade com os padrões C/C++..
ms.date: 02/09/2020
helpviewer_keywords:
- preprocessor, experimental
ms.openlocfilehash: 00c34ef75270e505d3781cf7eedf4d8aba95ee6e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337479"
---
# <a name="msvc-experimental-preprocessor-overview"></a>Visão geral do pré-processador experimental MSVC

::: moniker range="vs-2015"

O Visual Studio 2015 usa o pré-processador tradicional, que não está de acordo com o Padrão C++. Um pré-processador experimental está disponível no Visual Studio 2017 e no Visual Studio 2019 usando o interruptor do compilador [/experimental:pré-processador.](../build/reference/experimental-preprocessor.md) Mais informações sobre o uso do novo pré-processador no Visual Studio 2017 e visual studio 2019 estão disponíveis. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end

::: moniker range=">=vs-2017"

Estamos atualizando o pré-processador Microsoft C++ para melhorar a conformidade dos padrões, corrigir bugs de longa data e alterar alguns comportamentos que são oficialmente indefinidos. Também adicionamos novos diagnósticos para alertar sobre erros nas definições de macro.

Essas alterações estão disponíveis usando o interruptor [/experimental:pré-processador](../build/reference/experimental-preprocessor.md) compilador no Visual Studio 2017 ou visual Studio 2019. O comportamento padrão do pré-processador permanece o mesmo das versões anteriores.

A partir da versão 16.5 do Visual Studio 2019, o suporte experimental ao pré-processador para o padrão C++20 está completo.

## <a name="new-predefined-macro"></a>Nova macro predefinida

Você pode detectar qual pré-processador está em uso no momento da compilação. Verifique o valor da [ \_\_](predefined-macros.md) macro predefinida MSVC TRADICIONAL para saber se o pré-processador tradicional está em uso. Esta macro é definida incondicionalmente por versões do compilador que o suportam, independente do qual o pré-processador é invocado. Seu valor é 1 para o pré-processador tradicional. É 0 para o pré-processador em conformidade.

```cpp
#if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
// Logic using the traditional preprocessor
#else
// Logic using cross-platform compatible preprocessor
#endif
```

## <a name="behavior-changes-in-the-experimental-preprocessor"></a>Mudanças de comportamento no pré-processador experimental

O trabalho inicial no pré-processador experimental foi focado em fazer com que todas as expansões macro estejam em conformidade com o padrão. Ele permite que você use o compilador MSVC com bibliotecas que atualmente são bloqueadas pelos comportamentos tradicionais. Testamos o pré-processador atualizado em projetos do mundo real. Aqui estão algumas das mudanças de quebra mais comuns que encontramos:

### <a name="macro-comments"></a>Comentários macro

O pré-processador tradicional é baseado em buffers de caracteres em vez de tokens de pré-processador. Ele permite comportamentos incomuns, como o seguinte truque de comentário pré-processador, que não funciona sob o pré-processador em conformidade:

```cpp
#if DISAPPEAR
#define DISAPPEARING_TYPE /##/
#else
#define DISAPPEARING_TYPE int
#endif

// myVal disappears when DISAPPEARING_TYPE is turned into a comment
DISAPPEARING_TYPE myVal;
```

A correção em conformidade `int myVal` com as `#ifdef/#endif` normas é declarar dentro das diretivas apropriadas:

```cpp
#define MYVAL 1

#ifdef MYVAL
int myVal;
#endif
```

### <a name="lval"></a>L#val

O pré-processador tradicional combina incorretamente um prefixo de string ao resultado do operador de [stringizing (#):](stringizing-operator-hash.md)

```cpp
 #define DEBUG_INFO(val) L"debug prefix:" L#val
//                                       ^
//                                       this prefix

const wchar_t *info = DEBUG_INFO(hello world);
```

Neste caso, `L` o prefixo é desnecessário porque os literais de seqüência adjacentes são combinados após a expansão macro de qualquer maneira. A correção compatível com o atraso é alterar a definição:

```cpp
#define DEBUG_INFO(val) L"debug prefix:" #val
//                                       ^
//                                       no prefix
```

O mesmo problema também é encontrado em macros de conveniência que "stringizam" o argumento para uma seqüência de strings literal:

```cpp
 // The traditional preprocessor creates a single wide string literal token
#define STRING(str) L#str
```

Você pode corrigir o problema de várias maneiras:

- Use a concatenação de `L""` strings e `#str` para adicionar prefixo. Os literais de seqüência adjacentes são combinados após a expansão da macro:

   ```cpp
   #define STRING1(str) L""#str
   ```

- Adicionar o `#str` prefixo depois é stringized com expansão de macro adicional

   ```cpp
   #define WIDE(str) L##str
   #define STRING2(str) WIDE(#str)
   ```

- Use o operador `##` de concatenação para combinar os tokens. A ordem das `##` `#` operações para e não é especificada, `#` embora `##` todos os compiladores parecem avaliar o operador antes neste caso.

   ```cpp
   #define STRING3(str) L## #str
   ```

### <a name="warning-on-invalid-"></a>Aviso sobre inválido\#\#

Quando o [operador de colar token (##)](token-pasting-operator-hash-hash.md) não resulta em um único token de pré-processamento válido, o comportamento é indefinido. O pré-processador tradicional silenciosamente falha em combinar os tokens. O novo pré-processador corresponde ao comportamento da maioria dos outros compiladores e emite um diagnóstico.

```cpp
// The ## is unnecessary and does not result in a single preprocessing token.
#define ADD_STD(x) std::##x
// Declare a std::string
ADD_STD(string) s;
```

### <a name="comma-elision-in-variadic-macros"></a>Elision de comuma em macros variadas

O pré-processador MSVC tradicional sempre `__VA_ARGS__` remove as massas antes de substituições vazias. O pré-processador experimental acompanha mais de perto o comportamento de outros compiladores multiplataforma populares. Para que a comma seja removida, o argumento variado deve estar faltando `##` (não apenas vazio) e deve ser marcado com um operador. Considere o exemplo a seguir:

```cpp
void func(int, int = 2, int = 3);
// This macro replacement list has a comma followed by __VA_ARGS__
#define FUNC(a, ...) func(a, __VA_ARGS__)
int main()
{
    // In the traditional preprocessor, the
    // following macro is replaced with:
    // func(10,20,30)
    FUNC(10, 20, 30);

    // A conforming preprocessor replaces the
    // following macro with: func(1, ), which
    // results in a syntax error.
    FUNC(1, );
}
```

No exemplo a seguir, `FUNC2(1)` na chamada para o argumento variado está faltando na macro que está sendo invocada. Na chamada `FUNC2(1, )` para o argumento variado está vazio, mas não falta (observe a comma na lista de argumentos).

```cpp
#define FUNC2(a, ...) func(a , ## __VA_ARGS__)
int main()
{
   // Expands to func(1)
   FUNC2(1);

   // Expands to func(1, )
   FUNC2(1, );
}
```

Na próxima norma C++20, este problema foi `__VA_OPT__`abordado adicionando . O suporte experimental `__VA_OPT__` a pré-processador está disponível a partir da versão 16.5 do Visual Studio 2019.

### <a name="c20-variadic-macro-extension"></a>C++20 extensão macro variada

O pré-processador experimental suporta o argumento de macro variacoC+20:

```cpp
#define FUNC(a, ...) __VA_ARGS__ + a
int main()
  {
  int ret = FUNC(0);
  return ret;
  }
```

Este código não está em conformidade antes do padrão C++20. No MSVC, o pré-processador experimental estende este comportamento C++20 para modos padrão de linguagem mais baixos (**`/std:c++14`**). **`/std:c++17`** Esta extensão corresponde ao comportamento de outros grandes compiladores C++ multiplataforma.

### <a name="macro-arguments-are-unpacked"></a>Os argumentos macro são "desembalados"

No pré-processador tradicional, se uma macro encaminha um de seus argumentos para outra macro dependente, então o argumento não fica "desembalado" quando é inserido. Normalmente essa otimização passa despercebida, mas pode levar a comportamentos incomuns:

```cpp
// Create a string out of the first argument, and the rest of the arguments.
#define TWO_STRINGS( first, ... ) #first, #__VA_ARGS__
#define A( ... ) TWO_STRINGS(__VA_ARGS__)
const char* c[2] = { A(1, 2) };

// Conforming preprocessor results:
// const char c[2] = { "1", "2" };

// Traditional preprocessor results, all arguments are in the first string:
// const char c[2] = { "1, 2", };
```

Ao `A()`expandir, o pré-processador tradicional encaminha todos `__VA_ARGS__` os argumentos embalados para o primeiro `TWO_STRINGS` argumento de TWO_STRINGS, o que deixa o argumento variado de vazio. Isso faz com `#first` que o resultado seja "1, 2" em vez de apenas "1". Se você está acompanhando de perto, então você pode `#__VA_ARGS__` estar se perguntando o que aconteceu com o resultado da expansão `""`tradicional do pré-processador: se o parâmetro variado estiver vazio, ele deve resultar em uma seqüência literal vazia . Um problema separado impediu que o token literal de string vazio fosse gerado.

### <a name="rescanning-replacement-list-for-macros"></a>Lista de substituição de revarredura para macros

Depois que uma macro é substituída, os tokens resultantes são reexaminados para que identificadores de macro adicionais sejam substituídos. O algoritmo usado pelo pré-processador tradicional para fazer a rescada não está em conformidade, como mostrado neste exemplo com base no código real:

```cpp
#define CAT(a,b) a ## b
#define ECHO(...) __VA_ARGS__
// IMPL1 and IMPL2 are implementation details
#define IMPL1(prefix,value) do_thing_one( prefix, value)
#define IMPL2(prefix,value) do_thing_two( prefix, value)

// MACRO chooses the expansion behavior based on the value passed to macro_switch
#define DO_THING(macro_switch, b) CAT(IMPL, macro_switch) ECHO(( "Hello", b))
DO_THING(1, "World");

// Traditional preprocessor:
// do_thing_one( "Hello", "World");
// Conforming preprocessor:
// IMPL1 ( "Hello","World");
```

Embora este exemplo possa parecer um pouco inventado, nós vimos isso no código do mundo real. Para ver o que está acontecendo, podemos quebrar `DO_THING`a expansão começando com:

1. `DO_THING(1, "World")`expande para`CAT(IMPL, 1) ECHO(("Hello", "World"))`
1. `CAT(IMPL, 1)`expande `IMPL ## 1`para , que se expande para`IMPL1`
1. Agora os tokens estão neste estado:`IMPL1 ECHO(("Hello", "World"))`
1. O pré-processador encontra o identificador `IMPL1`de macro semelhante à função . Uma vez que não `(`é seguido por um , não é considerado uma invocação macro semelhante a função.
1. O pré-processador passa para os seguintes tokens. Ele encontra a macro `ECHO` semelhante à `ECHO(("Hello", "World"))`função é invocada: , que se expande para`("Hello", "World")`
1. `IMPL1`nunca mais é considerado para expansão, então o resultado completo das expansões é:`IMPL1("Hello", "World");`

Para modificar a macro para se comportar da mesma forma sob o pré-processador experimental e o pré-processador tradicional, adicione outra camada de indireção:

```cpp
#define CAT(a,b) a##b
#define ECHO(...) __VA_ARGS__
// IMPL1 and IMPL2 are macros implementation details
#define IMPL1(prefix,value) do_thing_one( prefix, value)
#define IMPL2(prefix,value) do_thing_two( prefix, value)
#define CALL(macroName, args) macroName args
#define DO_THING_FIXED(a,b) CALL( CAT(IMPL, a), ECHO(( "Hello",b)))
DO_THING_FIXED(1, "World");

// macro expands to:
// do_thing_one( "Hello", "World");
```

## <a name="incomplete-features"></a>Recursos incompletos

A partir da versão 16.5 do Visual Studio 2019, o pré-processador experimental está completo para C++20. Nas versões anteriores do Visual Studio, o pré-processador experimental está quase completo, embora alguma lógica diretiva pré-processadorainda caia ao comportamento tradicional. Aqui está uma lista parcial de recursos incompletos nas versões do Visual Studio antes de 16.5:

- Compatível com `_Pragma`
- C++20 características
- Bug de bloqueio de impulso: Operadores lógicos em expressões constantes de pré-processador não são totalmente implementados no novo pré-processador antes da versão 16.5. Em `#if` algumas diretivas, o novo pré-processador pode voltar ao pré-processador tradicional. O efeito só é perceptível quando macros incompatíveis com o pré-processador tradicional são expandidas. Isso pode acontecer ao construir slots de pré-processador Boost.

::: moniker-end
