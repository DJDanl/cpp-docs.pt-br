---
title: Especificadores de tipo C
ms.date: 01/29/2018
helpviewer_keywords:
- type specifiers, C
- specifiers, type
ms.assetid: fbe13441-04c3-4829-b047-06d374adc2b6
ms.openlocfilehash: 652388fdf345cab7878bbd8c054b769377b322a9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217149"
---
# <a name="c-type-specifiers"></a>Especificadores de tipo C

Os especificadores de tipo em declarações definem o tipo de uma declaração de função ou variável.

## <a name="syntax"></a>Sintaxe

*tipo-especificador*: &nbsp; &nbsp; &nbsp; &nbsp; **`void`** &nbsp; &nbsp; &nbsp; &nbsp; **`char`** &nbsp; &nbsp; &nbsp; &nbsp; **`short`** &nbsp; &nbsp; &nbsp; &nbsp; **`int`** &nbsp; &nbsp; &nbsp; &nbsp; **`long`** &nbsp; &nbsp; &nbsp; &nbsp; **`float`** &nbsp; &nbsp; &nbsp; &nbsp; **`double`** &nbsp; &nbsp; &nbsp; &nbsp; **`signed`** &nbsp; &nbsp; &nbsp; &nbsp; **`unsigned`** &nbsp; &nbsp; &nbsp; &nbsp; *struct-or-Union-do especificador* do &nbsp; &nbsp; &nbsp; &nbsp; *especificador* &nbsp; &nbsp; &nbsp; &nbsp; *-nome do typedef-Name*

Os **`signed char`** **`signed int`** **`signed short int`** tipos **int Long assinados** ,, e com suas **`unsigned`** contrapartes e **`enum`** , são chamados de tipos *integrais* . Os **`float`** **`double`** especificadores,, e de **`long double`** tipo são chamados de tipos *flutuantes* ou *de ponto flutuante* . Você pode usar qualquer especificador do tipo integral ou de ponto flutuante em uma declaração de variável ou função. Se um *especificador de tipo* não for fornecido em uma declaração, ele será levado a ser **`int`** .

As palavras-chave opcionais **`signed`** e **`unsigned`** podem preceder ou seguir qualquer um dos tipos integrais, exceto **`enum`** , e também podem ser usadas sozinhas como especificadores de tipo; nesse caso, eles são compreendidos como **`signed int`** e **`unsigned int`** , respectivamente. Quando usado sozinho, a palavra-chave **`int`** é considerada **`signed`** . Quando usado sozinho, as palavras-chave **`long`** e **`short`** são compreendidas como **Long int** e **`short int`** .

Os tipos de enumeração são considerados tipos básicos. Os especificadores de tipo para tipos de enumeração são discutidos em [Declarações de enumeração](../c-language/c-enumeration-declarations.md).

A palavra-chave **`void`** tem três usos: para especificar um tipo de retorno de função, para especificar uma lista de tipo de argumento para uma função que não usa argumentos e para especificar um ponteiro para um tipo não especificado. Você pode usar o **`void`** tipo para declarar funções que não retornam nenhum valor ou para declarar um ponteiro para um tipo não especificado. Consulte [argumentos](../c-language/arguments.md) para obter informações sobre **`void`** quando ele aparece sozinho dentro dos parênteses após um nome de função.

**Específico da Microsoft**

A verificação de tipo agora está em conformidade com ANSI, o que significa que tipo **`short`** e tipo **`int`** são tipos distintos. Por exemplo, esta é uma redefinição do compilador do Microsoft C que foi aceita por versões anteriores do compilador.

```C
int   myfunc();
short myfunc();
```

O exemplo a seguir também gerencia um aviso sobre a ação indireta a diferentes tipos:

```C
int *pi;
short *ps;

ps = pi;  /* Now generates warning */
```

O compilador do Microsoft C também gerencia avisos para as diferenças no sinal. Por exemplo:

```C
signed int *pi;
unsigned int *pu

pi = pu;  /* Now generates warning */
```

**`void`** Expressões de tipo são avaliadas para efeitos colaterais. Você não pode usar o valor (não existente) de uma expressão que tenha tipo **`void`** de qualquer forma, nem pode converter uma **`void`** expressão (por conversão implícita ou explícita) em qualquer tipo, exceto **`void`** . Se você usar uma expressão de qualquer outro tipo em um contexto em que uma **`void`** expressão é necessária, seu valor será Descartado.

Para estar em conformidade com a especificação ANSI, <strong>void \* \* </strong> não pode ser usado como <strong>int \* \* </strong>. Somente **`void`** <strong>\*</strong> pode ser usado como um ponteiro para um tipo não especificado.

**FINAL específico da Microsoft**

Você pode criar especificadores de tipo adicionais com **`typedef`** declarações, conforme descrito em [declarações de typedef](../c-language/typedef-declarations.md). Consulte [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md) para obter informações sobre o tamanho de cada tipo.

## <a name="see-also"></a>Confira também

[Declarações e tipos](../c-language/declarations-and-types.md)
