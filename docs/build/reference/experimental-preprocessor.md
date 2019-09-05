---
title: '/experimental: pré-processador (habilitar o modo de conformidade do pré-processador)'
description: 'Use a opção de compilador/experimental: pré-processador para habilitar o suporte experimental ao compilador para um pré-processador de conformidade padrão.'
ms.date: 09/03/2019
f1_keywords:
- preprocessor
- /experimental:preprocessor
helpviewer_keywords:
- preprocessor conformance
- /experimental:preprocessor
- Enable preprocessor conformance mode
ms.openlocfilehash: 3055cfa2a32d1d668dbe0c51b5542415b5bb0af4
ms.sourcegitcommit: fd0f8839da5c6a3663798a47c6b0bb6e63b518bd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2019
ms.locfileid: "70294433"
---
# <a name="experimentalpreprocessor-enable-preprocessor-conformance-mode"></a>/experimental: pré-processador (habilitar o modo de conformidade do pré-processador)

Essa opção habilita um pré-processador experimental baseado em token que está em conformidade com os padrões do C++ 11, incluindo os recursos de pré-processador do C99.

## <a name="syntax"></a>Sintaxe

> **/experimental: pré-processador** [ **-** ]

## <a name="remarks"></a>Comentários

Use a opção de compilador **/experimental: pré-processador** para habilitar o pré-processador de conformidade experimental. Você pode usar a opção **/experimental: pré-processador-** para especificar explicitamente o pré-processador tradicional.

A opção **/experimental: pré-processador** está disponível a partir do Visual Studio 2017 versão 15,8.

Você pode detectar qual pré-processador está em uso no momento da compilação. Verifique o valor da macro [ \_predefinida MSVC\_tradicional](../../preprocessor/predefined-macros.md) para saber se o pré-processador tradicional está em uso. Essa macro é definida incondicionalmente por versões do compilador que dão suporte a ela, independentemente de qual pré-processador é invocado. Seu valor é 1 para o pré-processador tradicional. É 0 para o pré-processador experimental compatível:

```cpp
#if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
// Logic using the traditional preprocessor
#else
// Logic using cross-platform compatible preprocessor
#endif
```

### <a name="behavior-changes-in-the-experimental-preprocessor"></a>Alterações de comportamento no pré-processador experimental

Aqui estão algumas das últimas alterações mais comuns encontradas quando o modo de conformidade do pré-processador está habilitado:

#### <a name="macro-comments"></a>Comentários da macro

O pré-processador tradicional usa buffers de caracteres em vez de tokens de pré-processador. Isso permite algum comportamento incomum, como esse truque de comentário de pré-processador, que não funciona no pré-processador de conformidade:

```cpp
#if DISAPPEAR
#define DISAPPEARING_TYPE /##/
#else
#define DISAPPEARING_TYPE int
#endif

// myVal disappears when DISAPPEARING_TYPE is turned into a comment
// To make standards compliant, wrap the following line with the appropriate #if/#endif
DISAPPEARING_TYPE myVal;
```

#### <a name="string-prefixes-lval"></a>Prefixos de cadeia de caracteres (L # Val)

O pré-processador tradicional combina incorretamente um prefixo de cadeia de caracteres ao resultado do operador de [cadeia de caracteres (#)](../../preprocessor/stringizing-operator-hash.md):

```cpp
#define DEBUG_INFO(val) L"debug prefix:" L#val
//                                       ^
//                                       this prefix

const wchar_t *info = DEBUG_INFO(hello world);
```

O `L` prefixo é desnecessário aqui, porque os literais de cadeia de caracteres adjacentes são combinados após a expansão da macro. A correção compatível com versões anteriores é alterar a definição para:

```cpp
#define DEBUG_INFO(val) L"debug prefix:" #val
//                                       ^
//                                       no prefix
```

Esse problema também é encontrado em macros de conveniência que ' stringize ' o argumento para um literal de cadeia de caracteres largo:

```cpp
// The traditional preprocessor creates a single wide string literal token
#define STRING(str) L#str

// Potential fixes:
// Use string concatenation of L"" and #str to add prefix
// This works because adjacent string literals are combined after macro expansion
#define STRING1(str) L""#str

// Add the prefix after #str is stringized with additional macro expansion
#define WIDE(str) L##str
#define STRING2(str) WIDE(#str)

// Use concatenation operator ## to combine the tokens.
// The order of operations for ## and # is unspecified, although all compilers
// checked perform the # operator before ## in this case.
#define STRING3(str) L## #str
```

#### <a name="warning-on-invalid"></a>Aviso inválida ##

Quando o [operador de colagem de tokens (# #)](../../preprocessor/token-pasting-operator-hash-hash.md) não resulta em um único token de pré-processamento válido, o comportamento é indefinido. O pré-processador tradicional falha silenciosamente ao combinar os tokens. O novo pré-processador corresponde ao comportamento da maioria dos outros compiladores e emite um diagnóstico.

```cpp
// The ## is unnecessary and doesn't result in a single preprocessing token.
#define ADD_STD(x) std::##x

// Declare a std::string
ADD_STD(string) s;
```

#### <a name="comma-elision-in-variadic-macros"></a>Corrotina vírgula em Macros Variadic

Considere o exemplo a seguir:

```cpp
void func(int, int = 2, int = 3);
// This macro replacement list has a comma followed by __VA_ARGS__
#define FUNC(a, ...) func(a, __VA_ARGS__)
int main()
{
    // The following macro is replaced with:
    // func(10,20,30)
    FUNC(10, 20, 30);

    // A conforming preprocessor replaces the following macro with:
    // func(1, );
    // which results in a syntax error.
    FUNC(1, );
}
```

Todos os principais compiladores têm uma extensão de pré-processador que ajuda a resolver esse problema. O pré-processador MSVC tradicional sempre remove vírgulas antes de substituições `__VA_ARGS__` vazias. O pré-processador atualizado segue melhor o comportamento de outros compiladores de plataforma cruzada populares. Para a vírgula a ser removida, o argumento Variadic deve estar ausente, não apenas vazio e deve ser marcado com um `##` operador:

```cpp
#define FUNC2(a, ...) func(a , ## __VA_ARGS__)
int main()
{
    // The variadic argument is missing in the macro being evoked
    // The comma is removed and replaced with:
    // func(1)
    FUNC2(1);

    // The variadic argument is empty, but not missing. (Notice the
    // comma in the argument list.) The comma isn't removed
    // when the macro is replaced:
    // func(1, )
    FUNC2(1, );
}
```

No próximo padrão C + + 2a, esse problema foi resolvido pela adição `__VA_OPT__`, que ainda não está implementada.

#### <a name="macro-arguments-are-unpacked"></a>Os argumentos da macro são ' desempacotados '

No pré-processador tradicional, se uma macro encaminhar um de seus argumentos para outra macro dependente, o argumento não obterá "desempacotado" quando for substituído. Normalmente, essa otimização passa despercebida, mas pode levar a um comportamento incomum:

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

Ao expandir `A()`, o pré-processador tradicional encaminha todos os argumentos empacotados em `__VA_ARGS__` para o primeiro argumento de `TWO_STRINGS`. O argumento Variadic de `TWO_STRINGS` está vazio, o que faz com que `#first` o resultado `"1, 2"` seja em vez `"1"`de apenas. Você deve estar se perguntando o que aconteceu com o `#__VA_ARGS__` resultado da expansão de pré-processador tradicional. Se o parâmetro Variadic estiver vazio, ele deverá resultar em um literal de cadeia de caracteres vazio "". Devido a um problema separado, o token literal da cadeia de caracteres vazia não foi gerado.

#### <a name="rescanning-replacement-list-for-macros"></a>Examinando novamente a lista de substituição de macros

Depois que uma macro é substituída, os tokens resultantes são examinados novamente para que os identificadores de macro adicionais sejam substituídos. O algoritmo de nova verificação usado pelo pré-processador tradicional não é compatível, conforme mostrado neste exemplo com base no código real:

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

Para ver o que está acontecendo neste exemplo, dividimos a expansão começando com `DO_THING`:

`DO_THING(1, "World")` ->
`CAT(IMPL, 1) ECHO(("Hello", "World"))`

Em segundo lugar, CAT é expandido:

`CAT(IMPL, 1)` -> `IMPL ## 1` -> `IMPL1`

Que coloca os tokens nesse Estado:

`IMPL1 ECHO(("Hello", "World"))`

O pré-processador localiza o identificador `IMPL1`de macro do tipo função, mas não é seguido por um "(", portanto, não é considerado uma invocação de macro como função. Ele passa para os seguintes tokens e localiza a macro `ECHO` semelhante à função chamada:

`ECHO(("Hello", "World"))` -> `("Hello", "World")`

`IMPL1`Nunca é considerado novamente para expansão, portanto, o resultado total das expansões é:

`IMPL1("Hello", "World");`

A macro pode ser modificada para se comportar da mesma forma sob o pré-processador experimental e o pré-processador tradicional. A solução é adicionar outra camada de indireção:

```cpp
#define CAT(a,b) a##b
#define ECHO(...) __VA_ARGS__

// IMPL1 and IMPL2 are macros implementation details
#define IMPL1(prefix,value) do_thing_one( prefix, value)
#define IMPL2(prefix,value) do_thing_two( prefix, value)

#define CALL(macroName, args) macroName args
#define DO_THING_FIXED(a,b) CALL( CAT(IMPL, a), ECHO(( "Hello",b)))

DO_THING_FIXED(1, "World");
// macro expanded to:
// do_thing_one( "Hello", "World");
```

### <a name="conformance-mode-conformance"></a>Conformidade do modo de conformidade

O pré-processador experimental ainda não está completo e alguma lógica de diretiva de pré-processador ainda retorna ao comportamento tradicional. Aqui está uma lista parcial de recursos incompletos:

- Suporte para`_Pragma`
- Recursos do c++ 20
- Aprimoramentos de diagnóstico adicionais
- Alterna para controlar a saída em/E e/P
- Aumentar bug de bloqueio: Os operadores lógicos em expressões constantes de pré-processador não são totalmente implementados no novo pré-processador. Em algumas `#if` diretivas, o novo pré-processador pode fazer fallback para o pré-processador tradicional. O efeito é perceptível apenas quando as macros que são incompatíveis com o pré-processador tradicional são expandidas, o que pode ocorrer ao criar um aumento dos slots de pré-processador.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades da Configuração** > **C/C++**  > **Linha de Comando**.

1. Modifique a propriedade **Opções adicionais** para incluir **/experimental: pré-processador** e, em seguida, escolha **OK**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)
