---
title: '#Diretiva define (C/C++)'
ms.date: 08/29/2019
f1_keywords:
- '#define'
helpviewer_keywords:
- define directive (#define), syntax
- preprocessor, directives
- define directive (#define)
- '#define directive, syntax'
- '#define directive'
ms.assetid: 33cf25c6-b24e-40bf-ab30-9008f0391710
ms.openlocfilehash: b72e2468b9e9984237c81f5cdb3c5691fe95cbd0
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216270"
---
# <a name="define-directive-cc"></a>Diretiva de #define (CC++/)

O **#define** cria uma *macro*, que é a associação de um identificador ou identificador com parâmetros com uma cadeia de caracteres de token. Após a definição da macro, o compilador pode substituir a cadeia de caracteres de token para cada ocorrência do identificador no arquivo de origem.

## <a name="syntax"></a>Sintaxe

> **#define** *identificador* do *cadeia de caracteres de token* <sub>aceitar</sub>\
> **#define** *identificador* do **(** <sub>aceitar</sub>identificador **,** ... **,** *identificador* do <sub>aceitar</sub> **)** <sub>aceitar</sub> *cadeia de caracteres de token*

## <a name="remarks"></a>Comentários

A diretiva **#define** faz com que o compilador substitua a *cadeia de caracteres de token* para cada ocorrência de *identificador* no arquivo de origem. O *identificador* é substituído somente quando ele forma um token. Ou seja, o *identificador* não será substituído se aparecer em um comentário, em uma cadeia de caracteres ou como parte de um identificador mais longo. Para obter mais informações, consulte [tokens](../cpp/tokens-cpp.md).

O argumento *token-String* consiste em uma série de tokens, como palavras-chave, constantes ou instruções completas. Um ou mais caracteres de espaço em branco devem separar *cadeia de caracteres de token* do *identificador*. Esse espaço em branco não é considerado parte do texto substituído, nem de qualquer espaço em branco que siga o último token do texto.

Um `#define` sem uma *cadeia de caracteres de token* remove ocorrências de *identificador* do arquivo de origem. O *identificador* permanece definido e pode ser testado usando as `#if defined` diretivas e. `#ifdef`

A segunda forma de sintaxe define uma macro do tipo função com parâmetros. Essa forma aceita uma lista opcional de parâmetros que devem aparecer entre parênteses. Depois que a macro é definida, cada ocorrência subsequente *do identificador*(<sub>opt</sub>,.. *.,* <sub>opcional</sub> do identificador) é substituída por uma versão do argumento de cadeia de caracteres de *token* que tem argumentos reais substituído por parâmetros formais.

Os nomes de parâmetro formais aparecem na *cadeia de caracteres de token* para marcar os locais onde os valores reais são substituídos. Cada nome de parâmetro pode aparecer várias vezes na *cadeia de caracteres de token*e os nomes podem aparecer em qualquer ordem. O número de argumentos na chamada deve coincidir com o número de parâmetros na definição da macro. O uso liberal dos parênteses garante que os argumentos complexos reais sejam interpretados corretamente.

Os parâmetros formais na lista são separados por vírgulas. Cada nome da lista deve ser exclusivo, e a lista deve ser colocada entre parênteses. Nenhum espaço pode separar o *identificador* e o parêntese de abertura. Usar concatenação de linha — Coloque uma barra invertida (`\`) imediatamente antes do caractere de nova linha — para diretivas longas em várias linhas de origem. O escopo de um nome de parâmetro formal se estende para a nova linha que termina a *cadeia de caracteres de token*.

Quando uma macro é definida na segunda forma de sintaxe, as instâncias textuais subsequentes seguidas por uma lista de argumentos indicam uma chamada de macro. Os argumentos reais que seguem uma instância do *identificador* no arquivo de origem são correspondidos aos parâmetros formais correspondentes na definição de macro. Cada parâmetro formal na *cadeia de caracteres de token* que não é precedido por um operador`#`de cadeia de caracteres (`#@`), Charting () ou de`##`símbolo de colagem (), ou não `##` seguido por um operador, é substituído pelo correspondente argumento real. As macros no argumento real são expandidas antes da política substituir o parâmetro formal. (Os operadores são descritos em [operadores de pré-processador](../preprocessor/preprocessor-operators.md).)

Os seguintes exemplos de macros com argumentos ilustram a segunda forma da sintaxe de **#define** :

```C
// Macro to define cursor lines
#define CURSOR(top, bottom) (((top) << 8) | (bottom))

// Macro to get a random integer with a specified range
#define getrandom(min, max) \
    ((rand()%(int)(((max) + 1)-(min)))+ (min))
```

Os argumentos com efeitos colaterais às vezes fazem com que as macros produzam resultados inesperados. Um determinado parâmetro formal pode aparecer mais de uma vez em *cadeia de caracteres de token*. Se o parâmetro formal for substituído por uma expressão com efeitos colaterais, a expressão, com seus efeitos colaterais, poderá ser avaliada mais de uma vez. (Consulte os exemplos em [operador de colagem de tokens (# #)](../preprocessor/token-pasting-operator-hash-hash.md).)

A política `#undef` faz com que a definição de pré-processador de um identificador seja esquecida. Consulte [a diretiva #undef](../preprocessor/hash-undef-directive-c-cpp.md) para obter mais informações.

Se o nome da macro que está sendo definida ocorrer na *cadeia de caracteres de token* (mesmo como resultado de outra expansão de macro), ele não será expandido.

Um segundo **#define** para uma macro com o mesmo nome gera um aviso, a menos que a segunda sequência de token seja idêntica à primeira.

**Seção específica da Microsoft**

O Microsoft C/C++ permite que você redefina uma macro se a nova definição for sintaticamente idêntica à definição original. Ou seja, as duas definições podem ter nomes de parâmetro diferentes. Esse comportamento difere do ANSI C, o que exige que as duas definições sejam lexicalmente idênticas.

Por exemplo, as duas macros a seguir são idênticas, exceto os nomes de parâmetro. O ANSI C não permite essa redefinição, mas o Microsoft C/C++ compila sem erros.

```C
#define multiply( f1, f2 ) ( f1 * f2 )
#define multiply( a1, a2 ) ( a1 * a2 )
```

Por outro lado, as duas macros a seguir não são idênticas e irão gerar um aviso no Microsoft C/C++.

```C
#define multiply( f1, f2 ) ( f1 * f2 )
#define multiply( a1, a2 ) ( b1 * b2 )
```

**Fim da seção específica da Microsoft**

Este exemplo ilustra a diretiva **#define** :

```C
#define WIDTH       80
#define LENGTH      ( WIDTH + 10 )
```

A primeira declaração define o identificador `WIDTH` como a constante inteira 80 e define `LENGTH` em termos de `WIDTH` e da constante inteira 10. Cada ocorrência de `LENGTH` é substituída por (`WIDTH + 10`). Por sua vez, cada ocorrência de `WIDTH + 10` é substituída pela expressão (`80 + 10`). Os parênteses em torno de `WIDTH + 10` são importantes porque controlam a interpretação em instruções como esta:

```C
var = LENGTH * 20;
```

Após o estágio de pré-processamento, a instrução se torna:

```C
var = ( 80 + 10 ) * 20;
```

que é avaliado em 1800. Sem parênteses, o resultado é:

```C
var = 80 + 10 * 20;
```

que é avaliada como 280.

**Seção específica da Microsoft**

A definição de macros e constantes com a opção [/d](../build/reference/d-preprocessor-definitions.md) do compilador tem o mesmo efeito que usar uma diretiva de pré-processamento **#define** no início do arquivo. Até 30 macros podem ser definidas usando a opção /D.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)
