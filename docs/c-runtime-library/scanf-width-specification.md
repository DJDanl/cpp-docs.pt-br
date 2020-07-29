---
title: Especificação de largura scanf
ms.date: 10/22/2019
helpviewer_keywords:
- scanf function, width specification
ms.assetid: 94b4e8fe-c4a2-4799-8b6c-a2cf28ffb09c
ms.openlocfilehash: 781e292140babd61fbcde77cefcb917736b17cc3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87188733"
---
# <a name="scanf-width-specification"></a>`scanf`especificação de largura

Essas informações se aplicam à interpretação de cadeias de caracteres de formato na família de funções `scanf`, incluindo as versões protegidas, como `scanf_s`. Essas funções geralmente pressupõem que o fluxo de entrada é dividido em uma sequência de tokens. Os tokens são separados por espaço em branco (espaço, tabulação ou nova linha), ou para tipos numéricos, pela extremidade natural de um tipo de dados numéricos, conforme indicado pelo primeiro caractere que não pode ser convertido em texto numérico. No entanto, a especificação de largura pode ser usada para fazer com que a análise da entrada pare antes do final natural de um token.

A especificação de *largura* consiste em caracteres entre o `%` e o especificador de campo de tipo, que pode incluir um inteiro positivo chamado de campo de *largura* e um ou mais caracteres indicando o tamanho do campo, que também pode ser considerado como modificadores do tipo do campo, como uma indicação de se o tipo de inteiro é **`short`** ou **`long`** . Esses caracteres são chamados de prefixo de tamanho.

## <a name="the-width-field"></a>O campo largura

O campo *largura* é um inteiro decimal positivo que controla o número máximo de caracteres a serem lidos para esse campo. Não mais do que caracteres de *largura* são convertidos e armazenados no correspondente `argument` . Caracteres com menos de *largura* podem ser lidos se um caractere de espaço em branco ou um caractere que não pode ser convertido de acordo com o formato especificado ocorrer antes de a *largura* ser atingida.

A especificação de largura é separada e distinta do argumento de tamanho de buffer exigido pelas versões seguras dessas funções (por exemplo,,, `scanf_s` `wscanf_s` e assim por diante). No exemplo a seguir, a especificação de largura é 20, indicando que até 20 caracteres devem ser lidos do fluxo de entrada. O comprimento do buffer é 21, que inclui espaço para 20 caracteres possíveis mais o terminador nulo:

```C
char str[21];
scanf_s("%20s", str, 21);
```

Se o campo *largura* não for usado, o `scanf_s` tentará ler o token inteiro na cadeia de caracteres. Se o tamanho especificado não for grande o suficiente para manter o token inteiro, nada será gravado na cadeia de caracteres de destino. Se o campo *largura* for especificado, os caracteres da primeira *largura* no token serão gravados na cadeia de caracteres de destino, juntamente com o terminador nulo.

## <a name="the-size-prefix"></a>O prefixo de tamanho

Os prefixos opcionais **h**, **hh**, **l**, **ll**, **i64**e **l** indicam o tamanho do `argument` (longo ou curto, caractere de byte único ou caractere largo, dependendo do caractere de tipo que eles modificam). Esses caracteres de especificação de formato são usados com caracteres de tipo nas funções `scanf` ou `wscanf` para especificar a interpretação dos argumentos, como mostrado na tabela a seguir. O prefixo de tipo **i64** é uma extensão da Microsoft e não é compatível com C padrão. Os caracteres de tipo e seus significados são descritos na tabela "tipos de caracteres para funções scanf" em [ `scanf` caracteres de campo de tipo](../c-runtime-library/scanf-type-field-characters.md).

> [!NOTE]
> Os prefixos **h**, **l**e **l** são extensões da Microsoft quando usados com dados do tipo **`char`** .

### <a name="size-prefixes-for-scanf-and-wscanf-format-type-specifiers"></a>Prefixos de tamanho `scanf` e `wscanf` especificadores de tipo de formato

|Para especificar|Use o prefixo|Com especificador de tipo|
|----------------|----------------|-------------------------|
|**`double`**|**debug**|**e**, **E**, **f**, **g** ou **G**|
|**`long double`**(o mesmo que **`double`** )|**Debug**|**e**, **E**, **f**, **g** ou **G**|
|**`long int`**|**debug**|**d**, **i**, **o**, **x** ou **X**|
|**`long unsigned int`**|**debug**|**u**|
|**`long long`**|**precisa**|**d**, **i**, **o**, **x** ou **X**|
|**`short int`**|**h**|**d**, **i**, **o**, **x** ou **X**|
|**`short unsigned int`**|**h**|**u**|
|**`char`**|**hh**|**d**, **i**, **o**, **x** ou **X**|
|**`unsigned char`**|**hh**|**u**|
|**`int64`**|**I64**|**d**, **i**, **o**, **u**, **x** ou **X**|
|Caractere de um byte com `scanf`|**h**|**c** ou **C**|
|Caractere de um byte com `wscanf`|**h**|**c** ou **C**|
|Caracteres largos com `scanf`|**debug**|**c** ou **C**|
|Caracteres largos com `wscanf`|**debug**|**c**ou **c**|
|Cadeia de caracteres de byte único com`scanf`|**h**|**s** ou **S**|
|Cadeia de caracteres de byte único com`wscanf`|**h**|**s** ou **S**|
|Cadeia de caracteres largos com`scanf`|**debug**|**s** ou **S**|
|Cadeia de caracteres largos com`wscanf`|**debug**|**s** ou **S**|

Os exemplos abaixo usam **h** e **l** com funções `scanf_s` e funções `wscanf_s`:

```C
scanf_s("%ls", &x, 2);     // Read a wide-character string
wscanf_s(L"%hC", &x, 2);    // Read a single-byte character
```

Se estiver usando uma função não segura na família `scanf`, omita o parâmetro de tamanho que indica o comprimento do buffer do argumento anterior.

## <a name="reading-undelimited-strings"></a>Lendo cadeias de caracteres não delimitadas

Para ler cadeias não delimitadas por caracteres de espaço em branco, um conjunto de caracteres entre colchetes ( **`[ ]`** ) pode ser substituído pelo caractere de tipo **s** (cadeia de caracteres). O conjunto de caracteres entre colchetes é conhecido como uma *cadeia de caracteres de controle*. O campo de entrada correspondente é lido até o primeiro caractere que não aparece na cadeia de caracteres de controle. Se o primeiro caractere no conjunto for um acento circunflexo ( **`^`** ), o efeito será invertido: o campo de entrada será lido até o primeiro caractere que aparece no restante do conjunto de caracteres.

Ambos **% [a-z]** e **% [z-a]** são interpretados como equivalentes a **% [abcde... z]**. É uma extensão de `scanf` função comum, mas não é exigida por Standard C.

## <a name="reading-unterminated-strings"></a>Lendo cadeias de caracteres não finalizadas

Para armazenar uma cadeia de caracteres sem armazenar um caractere nulo de terminação (' \ 0 '), use a especificação `%Nc` , em que *N* é um inteiro decimal. Nesse caso, o caractere de tipo **c** indica que o argumento é um ponteiro para uma matriz de caracteres. Os próximos *N* caracteres são lidos do fluxo de entrada para o local especificado e nenhum caractere nulo (' \ 0 ') é acrescentado. Se *N* não for especificado, seu valor padrão será 1.

## <a name="when-scanf-stops-reading-a-field"></a>Quando `scanf` a leitura de um campo é interrompida

A função `scanf` examina cada campo de entrada, caractere por caractere. Ele pode parar de ler um campo de entrada específico antes de atingir um caractere de espaço por um dos vários motivos:

- A largura especificada foi alcançada.

- O próximo caractere não pode ser convertido como especificado.

- O próximo caractere entra em conflito com um caractere na cadeia de caracteres de controle que deve corresponder.

- O caractere seguinte não aparece em um determinado conjunto de caracteres.

Por algum motivo, quando a função `scanf` para de ler um campo de entrada, o próximo campo de entrada é considerado começando no primeiro caractere não lido. O caractere conflitante, se houver, é considerado não lido. É o primeiro caractere do próximo campo de entrada ou o primeiro caractere nas operações de leitura subsequentes no fluxo de entrada.

## <a name="see-also"></a>Confira também

[`scanf`, `_scanf_l`, `wscanf`, `_wscanf_l`](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)<br/>
[`scanf_s`, `_scanf_s_l`, `wscanf_s`, `_wscanf_s_l`](../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)<br/>
[Campos de especificação de formato: `scanf` e `wscanf` funções](../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md)<br/>
[`scanf`Digitar caracteres de campo](../c-runtime-library/scanf-type-field-characters.md)<br/>
