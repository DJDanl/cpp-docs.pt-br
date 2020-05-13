---
title: Especificadores de tipo C
ms.date: 01/29/2018
helpviewer_keywords:
- type specifiers, C
- specifiers, type
ms.assetid: fbe13441-04c3-4829-b047-06d374adc2b6
ms.openlocfilehash: 1191cf4d2912cda535547f465fe4bfbedebe8fa2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62313188"
---
# <a name="c-type-specifiers"></a>Especificadores de tipo C

Os especificadores de tipo em declarações definem o tipo de uma declaração de função ou variável.

## <a name="syntax"></a>Sintaxe

*especificador de tipo* &nbsp; &nbsp; &nbsp;: &nbsp; **void** &nbsp; **unsigned** **short** &nbsp; **char** &nbsp; **signed** **int** &nbsp; **long** **double** **float** *enum-specifier* *typedef-name* *struct-or-union-specifier* Char &nbsp;long int &nbsp;longo flutuante duplo &nbsp;assinado &nbsp;de struct-or-Union-do especificador &nbsp;enum- &nbsp;nome do typedef-name &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;

Os tipos **signed char**, **signed int**, **signed short int** e **signed long int**, junto com suas contrapartes **unsigned** e **enum**, são chamados de tipos *integrais*. Os especificadores de tipo **float**, **double** e **long double** são chamados de tipos *flutuantes* ou de *ponto flutuante*. Você pode usar qualquer especificador do tipo integral ou de ponto flutuante em uma declaração de variável ou função. Se um *especificador de tipo* não for fornecido em uma declaração, será considerado como **int**.

As palavras-chave opcionais **signed** e **unsigned** podem vir antes ou depois de qualquer um dos tipos integrais, exceto **enum**, e também podem ser usadas separadamente, como especificadores de tipo. Nesse caso, são entendidas como **signed int** e **unsigned int**, respectivamente. Quando usada sozinha, a palavra-chave **int** é considerada como **signed**. Quando usadas isoladamente, as palavras-chave **long** e **short** são entendidas como **long int** e **short int**.

Os tipos de enumeração são considerados tipos básicos. Os especificadores de tipo para tipos de enumeração são discutidos em [Declarações de enumeração](../c-language/c-enumeration-declarations.md).

A palavra-chave **void** tem três usos: especificar um tipo de retorno da função, especificar uma lista de tipo de argumento para uma função que não leve argumentos e especificar um ponteiro para um tipo não especificado. Você pode usar o tipo **void** para declarar as funções que não retornam nenhum valor ou para declarar um ponteiro para um tipo não especificado. Consulte [Argumentos](../c-language/arguments.md) para obter informações sobre **void** quando é exibido sozinho dentro dos parênteses depois de um nome de função.

**Específico da Microsoft**

A verificação de tipo agora está em conformidade com ANSI, o que significa que o tipo **short** e o tipo **int** são tipos distintos. Por exemplo, esta é uma redefinição do compilador do Microsoft C que foi aceita por versões anteriores do compilador.

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

As expressões do tipo **void** são avaliadas quanto a efeitos colaterais. Você não pode usar o valor (inexistente) de uma expressão que tem o tipo **void** em qualquer modo, nem pode converter uma expressão **void** (por conversão implícita ou explícita) em qualquer tipo exceto **void**. Se você usar uma expressão de qualquer outro tipo em um contexto em que a expressão **void** é necessária, seu valor será descartado.

Para estar em conformidade com a especificação ANSI, <strong>void\* </strong> não pode ser usado como <strong>int\*</strong>. Somente **void** <strong>\*</strong> pode ser usado como um ponteiro para um tipo não especificado.

**FINAL específico da Microsoft**

Você pode criar especificadores de tipo adicionais com as declarações **typedef**, conforme descrito em [Declarações de Typedef](../c-language/typedef-declarations.md). Consulte [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md) para obter informações sobre o tamanho de cada tipo.

## <a name="see-also"></a>Confira também

[Declarações e tipos](../c-language/declarations-and-types.md)
