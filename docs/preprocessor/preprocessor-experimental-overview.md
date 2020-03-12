---
title: Visão geral do pré-processador do MSVC experimental
description: O pré-processador MSVC está sendo atualizado para conformidade com C/C++ standards.
ms.date: 02/09/2020
helpviewer_keywords:
- preprocessor, experimental
ms.openlocfilehash: eb861b18a8d42c73429f6d00a3f47b35c9b198ca
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2020
ms.locfileid: "79090547"
---
# <a name="msvc-experimental-preprocessor-overview"></a>Visão geral do pré-processador do MSVC experimental

::: moniker range="vs-2015"

O Visual Studio 2015 usa o pré-processador tradicional, que não está de acordo com C++o padrão. Um pré-processador experimental está disponível no Visual Studio 2017 e no Visual Studio 2019 usando a opção de compilador [/experimental: pré-processador](../build/reference/experimental-preprocessor.md) . Mais informações sobre como usar o novo pré-processador no Visual Studio 2017 e no Visual Studio 2019 estão disponíveis. Para vê-lo, use o seletor de versão da documentação para selecionar uma dessas versões.

::: moniker-end

::: moniker range=">=vs-2017"

Estamos atualizando o pré-processador C++ da Microsoft para melhorar a conformidade dos padrões, corrigir bugs permanentes e alterar alguns comportamentos oficialmente indefinidos. Também adicionamos novos diagnósticos para avisar sobre erros em definições de macro.

Essas alterações estão disponíveis usando a opção de compilador [/experimental: pré-processador](../build/reference/experimental-preprocessor.md) no visual Studio 2017 ou no visual Studio 2019. O comportamento padrão do pré-processador permanece o mesmo que nas versões anteriores.

A partir do Visual Studio 2019 versão 16,5, o suporte a pré-processador experimental para o padrão C++ 20 é o recurso completo.

## <a name="new-predefined-macro"></a>Nova macro predefinida

Você pode detectar qual pré-processador está em uso no momento da compilação. Verifique o valor da macro predefinida [\_MSVC\_tradicional](predefined-macros.md) para saber se o pré-processador tradicional está em uso. Essa macro é definida incondicionalmente por versões do compilador que dão suporte a ela, independentemente de qual pré-processador é invocado. Seu valor é 1 para o pré-processador tradicional. É 0 para o pré-processador de conformidade.

```cpp
#if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
// Logic using the traditional preprocessor
#else
// Logic using cross-platform compatible preprocessor
#endif
```

## <a name="behavior-changes-in-the-experimental-preprocessor"></a>Alterações de comportamento no pré-processador experimental

O trabalho inicial no pré-processador experimental tem se concentrado em fazer com que todas as expansões de macros estejam em conformidade com o padrão. Ele permite que você use o compilador MSVC com bibliotecas atualmente bloqueadas pelos comportamentos tradicionais. Testamos o pré-processador atualizado em projetos do mundo real. Aqui estão algumas das últimas alterações mais comuns que encontramos:

### <a name="macro-comments"></a>Comentários da macro

O pré-processador tradicional baseia-se em buffers de caracteres em vez de tokens de pré-processador. Ele permite um comportamento incomum, como o seguinte truque de comentário de pré-processador, que não funciona no pré-processador de conformidade:

```cpp
#if DISAPPEAR
#define DISAPPEARING_TYPE /##/
#else
#define DISAPPEARING_TYPE int
#endif

// myVal disappears when DISAPPEARING_TYPE is turned into a comment
DISAPPEARING_TYPE myVal;
```

A correção de conformidade com padrões é declarar `int myVal` dentro das diretivas de `#ifdef/#endif` apropriadas:

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

Nesse caso, o prefixo de `L` é desnecessário porque os literais de cadeia de caracteres adjacentes são combinados após a expansão da macro mesmo assim. A correção compatível com versões anteriores é alterar a definição:

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

- Use a concatenação de cadeia de caracteres de `L""` e `#str` para adicionar o prefixo. Literais de cadeia de caracteres adjacentes são combinados após a expansão de macro:

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

Quando o [operador de colagem de tokens (# #)](token-pasting-operator-hash-hash.md) não resulta em um único token de pré-processamento válido, o comportamento é indefinido. O pré-processador tradicional falha silenciosamente ao combinar os tokens. O novo pré-processador corresponde ao comportamento da maioria dos outros compiladores e emite um diagnóstico.

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

No exemplo a seguir, na chamada para `FUNC2(1)` o argumento Variadic está ausente na macro que está sendo invocada. Na chamada para `FUNC2(1, )` o argumento Variadic está vazio, mas não está ausente (Observe a vírgula na lista de argumentos).

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

No próximo padrão de C++ 20, esse problema foi resolvido pela adição de `__VA_OPT__`. O suporte de pré-processador experimental para `__VA_OPT__` está disponível a partir do Visual Studio 2019 versão 16,5.

### <a name="c20-variadic-macro-extension"></a>Extensão de macro do c++ 20 Variadic

O pré-processador experimental dá suporte ao argumento de macro do C++ 20 Variadic corrotina:

```cpp
#define FUNC(a, ...) __VA_ARGS__ + a
int main()
  {
  int ret = FUNC(0);
  return ret;
  }
```

Esse código não está em conformidade antes do padrão C++ 20. No MSVC, o pré-processador experimental estende esse comportamento de C++ 20 para os modos padrão de linguagem inferior ( **`/std:c++14`** , **`/std:c++17`** ). Essa extensão corresponde ao comportamento de outros principais compiladores de C++ plataforma cruzada.

### <a name="macro-arguments-are-unpacked"></a>Os argumentos da macro são "desempacotados"

No pré-processador tradicional, se uma macro encaminhar um de seus argumentos para outra macro dependente, o argumento não obterá "desempacotado" quando for inserido. Normalmente, essa otimização passa despercebida, mas pode levar a um comportamento incomum:

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

Ao expandir `A()`, o pré-processador tradicional encaminha todos os argumentos empacotados em `__VA_ARGS__` para o primeiro argumento de TWO_STRINGS, o que deixa o argumento Variadic de `TWO_STRINGS` vazio. Isso faz com que o resultado de `#first` seja "1, 2" em vez de apenas "1". Se estiver acompanhando com mais detalhes, você deve estar se perguntando o que aconteceu com o resultado de `#__VA_ARGS__` na expansão tradicional do pré-processador: se o parâmetro Variadic estiver vazio, ele deverá resultar em uma cadeia de caracteres literal `""`. Um problema separado manteve o token literal da cadeia de caracteres vazia de ser gerado.

### <a name="rescanning-replacement-list-for-macros"></a>Examinando novamente a lista de substituição de macros

Depois que uma macro é substituída, os tokens resultantes são examinados novamente para que os identificadores de macro adicionais sejam substituídos. O algoritmo usado pelo pré-processador tradicional para fazer o novo exame não é compatível, conforme mostrado neste exemplo com base no código real:

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

Embora este exemplo possa parecer um pouco forçado, nós o vimos no código do mundo real. Para ver o que está acontecendo, podemos dividir a expansão começando com `DO_THING`:

1. `DO_THING(1, "World")` se expande para `CAT(IMPL, 1) ECHO(("Hello", "World"))`
1. `CAT(IMPL, 1)` expande para `IMPL ## 1`, que se expande para `IMPL1`
1. Agora, os tokens estão nesse Estado: `IMPL1 ECHO(("Hello", "World"))`
1. O pré-processador localiza o identificador de macro do tipo função `IMPL1`. Como não é seguido por um `(`, ele não é considerado uma invocação de macro como função.
1. O pré-processador passa para os tokens a seguir. Ele encontra a macro do tipo função `ECHO` é invocada: `ECHO(("Hello", "World"))`, que se expande para `("Hello", "World")`
1. `IMPL1` nunca é considerado novamente para expansão, portanto, o resultado total das expansões é: `IMPL1("Hello", "World");`

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

A partir do Visual Studio 2019 versão 16,5, o pré-processador experimental é o recurso completo para o C++ 20. Nas versões anteriores do Visual Studio, o pré-processador experimental está quase sempre concluído, embora alguma lógica de diretiva de pré-processador ainda volte ao comportamento tradicional. Aqui está uma lista parcial de recursos incompletos do Visual Studio versões anteriores a 16,5:

- Suporte ao `_Pragma`
- Recursos do c++ 20
- Aumento do bug de bloqueio: os operadores lógicos em expressões constantes de pré-processador não são totalmente implementados no novo pré-processador antes da versão 16,5. Em algumas diretivas de `#if`, o novo pré-processador pode retornar ao pré-processador tradicional. O efeito é perceptível apenas quando as macros incompatíveis com o pré-processador tradicional são expandidas. Isso pode acontecer quando se cria um aumento dos slots de pré-processador.

::: moniker-end
