---
title: Comentários C
ms.date: 06/25/2018
helpviewer_keywords:
- code comments, C code
- comments, documenting code
- comments, C code
- /* */ comment delimiters
- comments
ms.assetid: 0f5f2825-e673-49e7-8669-94e2f5294989
ms.openlocfilehash: fd2c08855bcc3ef3b4068f3841ce177d8162ff5b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62326281"
---
# <a name="c-comments"></a>Comentários C

Um "comentário" é uma sequência de caracteres que começa com uma combinação de barra/asterisco<strong>/</strong>() que é tratada como um único caractere de espaço em branco pelo compilador e, caso contrário, é ignorada. Um comentário pode incluir qualquer combinação de caracteres do conjunto de caracteres representáveis, incluindo caracteres de nova linha, mas excluindo o delimitador de<strong>\*</strong>"final comment" (). Os comentários podem ocupar mais de uma linha mas não podem ser aninhados.

Os comentários podem aparecer em qualquer lugar em que um caractere de espaço em branco é permitido. Como o compilador trata um comentário como um único caractere de espaço em branco, você não pode incluir comentários nos tokens. O compilador ignora os caracteres no comentário.

Use comentários para documentar seu código. Este exemplo é um comentário aceito pelo compilador:

```C
/* Comments can contain keywords such as
   for and while without generating errors. */
```

Os comentários podem aparecer na mesma linha de uma instrução de código:

```C
printf( "Hello\n" );  /* Comments can go here */
```

Você pode optar por preceder funções ou módulos do programa com um bloco de comentário descritivo:

```C
/* MATHERR.C illustrates writing an error routine
* for math functions.
*/
```

Como os comentários não podem conter comentários aninhados, este exemplo causa um erro:

```C
/* Comment out this routine for testing

   /* Open file */
    fh = _open( "myfile.c", _O_RDONLY );
    .
    .
    .
*/
```

O erro ocorre porque o compilador reconhece o primeiro `*/`, após as palavras `Open file`, como o fim do comentário. Ele tenta processar o texto restante e gera um erro ao encontrar `*/` fora de um comentário.

Embora você possa usar comentários para executar determinadas linhas de código inativo para fins de teste, as políticas `#if` e `#endif` do pré-processador e a compilação condicional são uma alternativa útil para essa tarefa. Para obter mais informações, consulte [Diretivas do pré-processador](../preprocessor/preprocessor-directives.md) na *Referência do pré-processador*.

**Específico da Microsoft**

O compilador da Microsoft também dá suporte a comentários de linha única precedidos por duas__//__ barras (). Se você compilar com /Za (padrão ANSI), esses comentários gerarão erros. Esses comentários não podem se estender para uma segunda linha.

```C
// This is a valid comment
```

Os comentários que começam com duas barras (__//__) são encerrados pelo próximo caractere de nova linha que não é precedido por um caractere de escape. No próximo exemplo, o caractere de nova linha é precedido por uma barra invertida (**\\**), criando uma "sequência de escape". Essa sequência de escape faz com que o compilador trate a próxima linha como parte da linha anterior. (Para obter mais informações, consulte [Sequências de escape](../c-language/escape-sequences.md).)

```C
// my comment \
    i++;
```

Portanto, a instrução `i++;` é comentada.

O padrão do Microsoft C é que as extensões da Microsoft sejam habilitadas. Use /Za para desabilitar essas extensões.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Tokens C](../c-language/c-tokens.md)
