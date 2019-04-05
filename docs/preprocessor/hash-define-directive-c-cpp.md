---
title: '#definir a diretiva (C/C++)'
ms.date: 11/04/2016
f1_keywords:
- '#define'
helpviewer_keywords:
- define directive (#define), syntax
- preprocessor, directives
- define directive (#define)
- '#define directive, syntax'
- '#define directive'
ms.assetid: 33cf25c6-b24e-40bf-ab30-9008f0391710
ms.openlocfilehash: 8a0cc7e7836a0c82c72055fe8d9e7497995485d0
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59039488"
---
# <a name="define-directive-cc"></a>Diretiva #define (C/C++)

O **#define** cria um *macro*, que é a associação de um identificador ou um identificador parametrizado com uma cadeia de caracteres de token. Após a definição da macro, o compilador pode substituir a cadeia de caracteres de token para cada ocorrência do identificador no arquivo de origem.

## <a name="syntax"></a>Sintaxe

`#define` *identifier* *token-string*<sub>opt</sub>

`#define` *identifier* `(` *identifier*<sub>opt</sub>`,` *...* `,` *identifier*<sub>opt</sub>`)` *token-string*<sub>opt</sub>

## <a name="remarks"></a>Comentários

O **#define** diretiva faz com que o compilador substitua *cadeia de caracteres de token* para cada ocorrência dos *identificador* no arquivo de origem. O *identificador* só será substituído quando formar um token. Ou seja, *identificador* não será substituído se ele é exibido em um comentário em uma cadeia de caracteres ou como parte de um identificador mais longo. Para obter mais informações, consulte [Tokens](../cpp/tokens-cpp.md).

O *token de cadeia de caracteres* argumento consiste em uma série de tokens, como palavras-chave, constantes ou instruções completas. Um ou mais caracteres de espaço em branco devem separar *token de cadeia de caracteres* partir *identificador*. Esse espaço em branco não é considerado parte do texto substituído, nem de qualquer espaço em branco que siga o último token do texto.

Um `#define` sem uma *token de cadeia de caracteres* remove as ocorrências de *identificador* do arquivo de origem. O *identificador* permanece definido e pode ser testado usando o `#if defined` e `#ifdef` diretivas.

A segunda forma de sintaxe define uma macro do tipo função com parâmetros. Essa forma aceita uma lista opcional de parâmetros que devem aparecer entre parênteses. Depois que a macro é definida, cada ocorrência subsequente de *identificador*( *identificador*<sub>aceitar</sub>,..., *identificador* <sub>opt</sub> ) é substituído por uma versão dos *token de cadeia de caracteres* argumento que tem argumentos reais substituídos por parâmetros formais.

Nomes de parâmetros formais aparecem em *token de cadeia de caracteres* para marcar os locais onde os valores reais são substituídos. Cada nome de parâmetro pode aparecer várias vezes em *token de cadeia de caracteres*, e os nomes podem aparecer em qualquer ordem. O número de argumentos na chamada deve coincidir com o número de parâmetros na definição da macro. O uso liberal dos parênteses garante que os argumentos complexos reais sejam interpretados corretamente.

Os parâmetros formais na lista são separados por vírgulas. Cada nome da lista deve ser exclusivo, e a lista deve ser colocada entre parênteses. Nenhum espaço pode separar *identificador* e o parêntese de abertura. Use a linha concatenação, coloque uma barra invertida (`\`) imediatamente antes do caractere de nova linha — para diretivas longas em várias linhas de código-fonte. O escopo de um nome de parâmetro formal estende-se para a nova linha que termina *token de cadeia de caracteres*.

Quando uma macro é definida na segunda forma de sintaxe, as instâncias textuais subsequentes seguidas por uma lista de argumentos indicam uma chamada de macro. Os argumentos reais que seguem uma instância de *identificador* no arquivo de origem são correspondidas parâmetros formais na definição da macro. Cada parâmetro formal na *token de cadeia de caracteres* que não é precedido por um stringizing (`#`), charizing (`#@`), ou token-pasting (`##`) operador, ou não é seguido por um `##` operador, é substituído pelo argumento correspondente real. As macros no argumento real são expandidas antes da política substituir o parâmetro formal. (Os operadores são descritos em [operadores do pré-processador](../preprocessor/preprocessor-operators.md).)

Os exemplos de macros com argumentos a seguir ilustram a segunda forma do **#define** sintaxe:

```C
// Macro to define cursor lines
#define CURSOR(top, bottom) (((top) << 8) | (bottom))

// Macro to get a random integer with a specified range
#define getrandom(min, max) \
    ((rand()%(int)(((max) + 1)-(min)))+ (min))
```

Os argumentos com efeitos colaterais às vezes fazem com que as macros produzam resultados inesperados. Um parâmetro formal determinado pode aparecer mais de uma vez na *token de cadeia de caracteres*. Se o parâmetro formal for substituído por uma expressão com efeitos colaterais, a expressão, com seus efeitos colaterais, poderá ser avaliada mais de uma vez. (Consulte os exemplos na [operador Token-Pasting (#)](../preprocessor/token-pasting-operator-hash-hash.md).)

A política `#undef` faz com que a definição de pré-processador de um identificador seja esquecida. Ver [#undef](../preprocessor/hash-undef-directive-c-cpp.md) para obter mais informações.

Se o nome da macro que está sendo definida ocorre em *token de cadeia de caracteres* (mesmo em resultado de outra expansão de macro), ele não estiver expandido.

Um segundo **#define** para uma macro com o mesmo nome gera um aviso, a menos que a segunda sequência de token é idêntica ao primeiro.

**Específico da Microsoft**

O Microsoft C/C++ permite que você redefina uma macro se a nova definição for sintaticamente idêntica à definição original. Ou seja, as duas definições podem ter nomes de parâmetro diferentes. Esse comportamento difere de ANSI C, que exige que as duas definições sejam lexicalmente idênticas.

Por exemplo, as duas macros a seguir são idênticas, exceto os nomes de parâmetro. ANSI C não permite uma redefinição, mas o Microsoft C/C++ compila sem erro.

```C
#define multiply( f1, f2 ) ( f1 * f2 )
#define multiply( a1, a2 ) ( a1 * a2 )
```

Por outro lado, as duas macros a seguir não são idênticas e irão gerar um aviso no Microsoft C/C++.

```C
#define multiply( f1, f2 ) ( f1 * f2 )
#define multiply( a1, a2 ) ( b1 * b2 )
```

**FIM de Específico da Microsoft**

Este exemplo ilustra a **#define** diretiva:

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

**Específico da Microsoft**

Definindo macros e constantes com a [/D](../build/reference/d-preprocessor-definitions.md) opção de compilador tem o mesmo efeito que usar um **#define** diretiva de pré-processamento no início do seu arquivo. Até 30 macros podem ser definidas usando a opção /D.

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)