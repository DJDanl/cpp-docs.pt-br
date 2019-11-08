---
title: Visão geral do pré-processador do MSVC experimental
description: O pré-processador MSVC está sendo atualizado para conformidade com C/C++ standards.
ms.date: 11/06/2019
helpviewer_keywords:
- preprocessor, experimental
ms.openlocfilehash: 446603b34d9309c256afba9abd7234ae2ab16f5c
ms.sourcegitcommit: 2362d15b5eb18d27773c3f7522da3d0eed9e2571
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/07/2019
ms.locfileid: "73797172"
---
# <a name="msvc-experimental-preprocessor-overview"></a>Visão geral do pré-processador do MSVC experimental

O pré-processador C++ da Microsoft está sendo atualizado no momento para melhorar a conformidade dos padrões, corrigir bugs permanentes e alterar alguns comportamentos que são oficialmente indefinidos. Além disso, foram adicionados novos diagnósticos para avisar sobre erros em definições de macro.

Essas alterações em seu estado atual estão disponíveis usando a opção de compilador [/experimental: pré-processador](../build/reference/experimental-preprocessor.md) no visual Studio 2017 ou no visual Studio 2019. O comportamento padrão do pré-processador permanece o mesmo que nas versões anteriores.

## <a name="new-predefined-macro"></a>Nova macro predefinida

Você pode detectar qual pré-processador está em uso no momento da compilação. Verifique o valor da macro predefinida [\_MSVC\_tradicional](predefined-macros.md) para saber se o pré-processador tradicional está em uso. Essa macro é definida incondicionalmente por versões do compilador que dão suporte a ela, independentemente de qual pré-processador é invocado. Seu valor é 1 para o pré-processador tradicional. É 0 para o pré-processador experimental compatível:

```cpp
#if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
// Logic using the traditional preprocessor
#else
// Logic using cross-platform compatible preprocessor
#endif
```

```cpp
#if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
// Logic using the traditional preprocessor
#else
// Logic using cross-platform compatible preprocessor
#endif
```

## <a name="behavior-changes-in-the-experimental-preprocessor"></a>Alterações de comportamento no pré-processador experimental

O trabalho inicial no pré-processador experimental tem se concentrado em fazer todas as expansões de macros em conformidade para habilitar o uso do compilador MSVC com bibliotecas que estão bloqueadas no momento devido a comportamentos tradicionais. Abaixo está uma lista de algumas das últimas alterações mais comuns que foram executadas ao testar o pré-processador atualizado com projetos reais.

### <a name="macro-comments"></a>Comentários da macro

O pré-processador tradicional baseia-se em buffers de caracteres em vez de tokens de pré-processador. Isso permite um comportamento incomum, como o truque de comentário do pré-processador a seguir, que não funcionará no pré-processador de conformidade:

```cpp
#if DISAPPEAR
#define DISAPPEARING_TYPE /##/
#else
#define DISAPPEARING_TYPE int
#endif

// myVal disappears when DISAPPEARING_TYPE is turned into a comment
DISAPPEARING_TYPE myVal;
```

A correção de conformidade com os padrões é declarar `int myVal` dentro das diretivas de `#ifdef/#endif` apropriadas:

```cpp
#define MYVAL 1

#ifdef MYVAL
int myVal;
#endif
```

### <a name="lval"></a>Valor L #

O pré-processador tradicional combina incorretamente um prefixo de cadeia de caracteres ao resultado do operador do [operador de cadeia de caracteres (#)](stringizing-operator-hash.md) :

```cpp
 #define DEBUG_INFO(val) L"debug prefix:" L#val
//                                       ^
//                                       this prefix

const wchar_t *info = DEBUG_INFO(hello world);
```

Nesse caso, o prefixo de `L` é desnecessário porque os literais de cadeia de caracteres adjacentes são combinados após a expansão da macro mesmo assim. A correção compatível com versões anteriores é alterar a definição para o seguinte:

```cpp
#define DEBUG_INFO(val) L"debug prefix:" #val
//                                       ^
//                                       no prefix
```

O mesmo problema também é encontrado em macros de conveniência que "stringize" o argumento para um literal de cadeia de caracteres largo:

```cpp
 // The traditional preprocessor creates a single wide string literal token
#define STRING(str) L#str
```

Você pode corrigir o problema de várias maneiras:

- Use a concatenação de cadeia de caracteres de `L""` e `#str` para adicionar o prefixo. Isso funciona porque literais de cadeia de caracteres adjacentes são combinados após a expansão de macro:

   ```cpp
   #define STRING1(str) L""#str
   ```

- Adicionar o prefixo após `#str` é cadeia de caracteres com expansão de macro adicional

   ```cpp
   #define WIDE(str) L##str
   #define STRING2(str) WIDE(#str)
   ```

- Use o operador de concatenação `##` para combinar os tokens. A ordem das operações para `##` e `#` não é especificada, embora todos os compiladores pareçam avaliar o operador de `#` antes de `##` nesse caso.

   ```cpp
   #define STRING3(str) L## #str
   ```

### <a name="warning-on-invalid-"></a>Aviso sobre \#inválidos \#

Quando o [operador de colagem de tokens (# #)](token-pasting-operator-hash-hash.md) não resulta em um único token de pré-processamento válido, o comportamento é indefinido. O pré-processador tradicional falhará ao combinar os tokens de forma silenciosa. O novo pré-processador corresponderá ao comportamento da maioria dos outros compiladores e emitirá um diagnóstico.

```cpp
// The ## is unnecessary and does not result in a single preprocessing token.
#define ADD_STD(x) std::##x
// Declare a std::string
ADD_STD(string) s;
```

### <a name="comma-elision-in-variadic-macros"></a>Corrotina vírgula em Macros Variadic

O pré-processador MSVC tradicional sempre remove vírgulas antes de vazias `__VA_ARGS__` substituições. O pré-processador experimental segue melhor o comportamento de outros compiladores de plataforma cruzada populares. Para a vírgula a ser removida, o argumento Variadic deve estar ausente (não apenas vazio) e deve ser marcado com um operador de `##`. Considere o exemplo a seguir:

```cpp
void func(int, int = 2, int = 3);
// This macro replacement list has a comma followed by __VA_ARGS__
#define FUNC(a, ...) func(a, __VA_ARGS__)
int main()
{
    // In the traditional preprocessor, the following macro is replaced with:
    // func(10,20,30)
    FUNC(10, 20, 30);

    // A conforming preprocessor will replace the following macro with: func(1, ), which will result in a syntax error.
    FUNC(1, );
}
```

No exemplo a seguir, na chamada para `FUNC2(1)` o argumento Variadic está ausente na macro sendo evoked. Na chamada para `FUNC2(1, )` o argumento Variadic está vazio, mas não está ausente (Observe a vírgula na lista de argumentos).

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

No próximo C + + 2a padrão, esse problema foi resolvido com a adição de `__VA_OPT__`, que ainda não foi implementado.

### <a name="macro-arguments-are-unpacked"></a>Os argumentos da macro são "desempacotados"

No pré-processador tradicional, se uma macro encaminhar um de seus argumentos para outra macro dependente, o argumento não obterá "desempacotado" quando ele for substituído. Normalmente, essa otimização passa despercebida, mas pode levar a um comportamento incomum:

```cpp
// Create a string out of the first argument, and the rest of the arguments.
#define TWO_STRINGS( first, ... ) #first, #__VA_ARGS__
#define A( ... ) TWO_STRINGS(__VA_ARGS__)
const char* c[2] = { A(1, 2) };

// Conformant preprocessor results:
// const char c[2] = { "1", "2" };

// Traditional preprocessor results, all arguments are in the first string:
// const char c[2] = { "1, 2", };
```

Ao expandir `A()`, o pré-processador tradicional encaminha todos os argumentos empacotados em `__VA_ARGS__` para o primeiro argumento de TWO_STRINGS, o que deixa o argumento Variadic de `TWO_STRINGS` vazio. Isso faz com que o resultado de `#first` seja "1, 2" em vez de apenas "1". Se você estiver acompanhando com mais detalhes, talvez esteja se perguntando o que aconteceu com o resultado de `#__VA_ARGS__` na expansão tradicional do pré-processador: se o parâmetro Variadic estiver vazio, ele deverá resultar em uma cadeia de caracteres literal `""`. Devido a um problema separado, o token literal da cadeia de caracteres vazia não foi gerado.

### <a name="rescanning-replacement-list-for-macros"></a>Examinando novamente a lista de substituição de macros

Depois que uma macro é substituída, os tokens resultantes são verificados novamente em busca de identificadores de macro adicionais que precisam ser substituídos. O algoritmo usado pelo pré-processador tradicional para fazer o novo exame não está em conformidade, conforme mostrado neste exemplo com base no código real:

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
// Conformant preprocessor:
// IMPL1 ( "Hello","World");
```

Embora este exemplo pareça um pouco forçado, ele foi encontrado para ocorrer código do mundo real. Para ver o que está acontecendo, podemos dividir a expansão começando com `DO_THING`:

1. `DO_THING(1, "World")` se expande para `CAT(IMPL, 1) ECHO(("Hello", "World"))`
1. `CAT(IMPL, 1)` expande para `IMPL ## 1` que se expande para `IMPL1`
1. Agora, os tokens estão nesse Estado: `IMPL1 ECHO(("Hello", "World"))`
1. O pré-processador localiza o identificador de macro como função `IMPL1`, mas não é seguido por um `(`, portanto, não é considerado uma invocação de macro como função. 
1. Ele passa para os seguintes tokens e localiza a macro do tipo função `ECHO` invocada: `ECHO(("Hello", "World"))`, que se expande para `("Hello", "World")`
1. `IMPL1` nunca é considerado novamente para expansão, portanto, o resultado total das expansões é: `IMPL1("Hello", "World");`

A macro pode ser modificada para se comportar da mesma forma sob o pré-processador experimental e o pré-processador tradicional adicionando em outra camada de indireção:

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

O pré-processador experimental está quase sempre concluído, embora alguma lógica de diretiva de pré-processador ainda volte ao comportamento tradicional. Aqui está uma lista parcial de recursos incompletos:

- Suporte para `_Pragma`
- Recursos do c++ 20
- Aumento do bug de bloqueio: os operadores lógicos em expressões constantes de pré-processador não são totalmente implementados no novo pré-processador. Em algumas diretivas de `#if`, o novo pré-processador pode retornar ao pré-processador tradicional. O efeito é perceptível apenas quando as macros que são incompatíveis com o pré-processador tradicional são expandidas, o que pode ocorrer ao criar um aumento dos slots de pré-processador.
