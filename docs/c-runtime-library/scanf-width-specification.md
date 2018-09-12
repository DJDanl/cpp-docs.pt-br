---
title: Especificação de largura scanf | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apilocation:
- msvcr100.dll
- msvcr120.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr90.dll
apitype: DLLExport
f1_keywords:
- scanf
dev_langs:
- C++
helpviewer_keywords:
- scanf function, width specification
ms.assetid: 94b4e8fe-c4a2-4799-8b6c-a2cf28ffb09c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4e236f323d882ddc7091655d944f0ed78bdeac28
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43203382"
---
# <a name="scanf-width-specification"></a>Especificação de largura scanf Width

Essas informações se aplicam à interpretação de cadeias de caracteres de formato na família de funções `scanf`, incluindo as versões protegidas, como `scanf_s`. Essas funções geralmente pressupõem que o fluxo de entrada é dividido em uma sequência de tokens. Os tokens são separados por espaços em branco (espaço, tabulação ou nova linha) ou, no caso de tipos numéricos, pelo final natural de um tipo de dados numéricos, conforme indicado pelo primeiro caractere que não pode ser convertido em texto numérico. No entanto, a especificação de largura pode ser usada para fazer com que a análise da entrada pare antes do final natural de um token.

O especificação de *largura* consiste em caracteres entre `%` e o especificador de campo de tipo, que pode incluir um número inteiro positivo chamado campo *Largura* e um ou mais caracteres indicando o tamanho do campo, que também pode ser considerado como modificadores do tipo de campo, como uma indicação se o tipo de inteiro é **curto** ou **longo**. Esses caracteres são chamados de prefixo de tamanho.

## <a name="the-width-field"></a>O campo Largura

O campo *largura* é um número inteiro decimal positivo que controla o número máximo de caracteres a ser lido nesse campo. Os caracteres de *largura* são o máximo que pode ser convertido e armazenado no `argument` correspondente. A leitura pode ser menor do que os caracteres de *largura* se um caractere de espaço em branco (espaço, tabulação ou nova linha) ou um caractere que não pode ser convertido de acordo com o formato determinado ocorre antes da *largura* ser alcançada.

A especificação de largura é separada e distinta do argumento de tamanho de buffer exigido para as versões protegidas dessas funções (por exemplo, `scanf_s`, `wscanf_s`, etc.). No exemplo a seguir, a especificação de largura é 20, indicando que até 20 caracteres devem ser lidos do fluxo de entrada. O comprimento do buffer é 21, que inclui espaço para 20 caracteres possíveis mais o terminador nulo:

```C
char str[21];
scanf_s("%20s", str, 21);
```

Se o campo *Largura* não for usado, `scanf_s` tentará ler o token inteiro na cadeia de caracteres. Se o tamanho especificado não é grande o suficiente para armazenar o token inteiro, nada é gravado na cadeia de caracteres de destino. Se o campo *Largura* for especificado, os primeiros caracteres da *largura* no token serão gravados na cadeia de caracteres de destino juntamente com o terminador nulo.

## <a name="the-size-prefix"></a>O prefixo de tamanho

Os prefixos opcionais **h**, **l**, **ll**, **I64**, e **L** indicam o tamanho do `argument` (longo ou curto, caracteres de byte único ou caractere largo, dependendo do caractere de tipo que eles modificam). Esses caracteres de especificação de formato são usados com caracteres de tipo nas funções `scanf` ou `wscanf` para especificar a interpretação dos argumentos, como mostrado na tabela a seguir. O prefixo de tipo **I64** é uma extensão da Microsoft e não é compatível com ANSI. Os caracteres de tipo e seus significados estão descritos na tabela "Caracteres de tipo para funções scanf" em [Caracteres de campo de tipo scanf](../c-runtime-library/scanf-type-field-characters.md).

> [!NOTE]
> Os prefixos **h**, **l** e **L** são extensões da Microsoft quando usados com dados do tipo `char`.

### <a name="size-prefixes-for-scanf-and-wscanf-format-type-specifiers"></a>Prefixos de Tamanho para Especificadores de Tipo de Formato scanf e wscanf

|Para especificar|Use o prefixo|Com especificador de tipo|
|----------------|----------------|-------------------------|
|**double**|**l**|**e**, **E**, **f**, **g** ou **G**|
|**long double** (mesmo que double)|**L**|**e**, **E**, **f**, **g** ou **G**|
|**long int**|**l**|**d**, **i**, **o**, **x** ou **X**|
|**long unsigned int**|**l**|**u**|
|**long long**|**ll**|**d**, **i**, **o**, **x** ou **X**|
|`short int`|**h**|**d**, **i**, **o**, **x** ou **X**|
|**short unsigned int**|**h**|**u**|
|__**int64**|**I64**|**d**, **i**, **o**, **u**, **x** ou **X**|
|Caractere de um byte com `scanf`|**h**|**c** ou **C**|
|Caractere de um byte com `wscanf`|**h**|**c** ou **C**|
|Caracteres largos com `scanf`|**l**|**c** ou **C**|
|Caracteres largos com `wscanf`|**l**|**c** ou **C**|
|Byte único – cadeia de caracteres com `scanf`|**h**|**s** ou **S**|
|Byte único – cadeia de caracteres com `wscanf`|**h**|**s** ou **S**|
|Cadeia de caracteres largos com `scanf`|**l**|**s** ou **S**|
|Cadeia de caracteres largos com `wscanf`|**l**|**s** ou **S**|

Os exemplos abaixo usam **h** e **l** com funções `scanf_s` e funções `wscanf_s`:

```C
scanf_s("%ls", &x, 2);     // Read a wide-character string
wscanf_s(L"%hC", &x, 2);    // Read a single-byte character
```

Se estiver usando uma função não segura na família `scanf`, omita o parâmetro de tamanho que indica o comprimento do buffer do argumento anterior.

## <a name="reading-undelimited-strings"></a>Leitura de cadeias de caracteres não delimitadas

Para ler cadeias de caracteres não delimitadas por caracteres de espaço em branco, um conjunto de caracteres entre colchetes (**[]**) pode ser substituído pelo caractere de tipo (cadeia de caracteres) **s**. O conjunto de caracteres entre colchetes é chamado de cadeia de caracteres de controle. O campo de entrada correspondente é lido até o primeiro caractere que não aparece na cadeia de caracteres de controle. Se o primeiro caractere no conjunto for um acento circunflexo (**^**), o efeito será inverso: o campo de entrada será lido até o primeiro caractere que aparece no restante do conjunto de caracteres.

Observe que **%[a-z]** e **%[z-a]** são interpretados como equivalentes a **%[abcde...z]**. Essa é uma extensão de função `scanf` comum, mas observe que o padrão ANSI não a exige.

## <a name="reading-unterminated-strings"></a>Leitura de cadeias de caracteres não finalizadas

Para armazenar uma cadeia de caracteres sem armazenar um caractere nulo de terminação ('\0'), use a especificação **%**<em>n</em>**c**, em que *n* é um inteiro decimal. Nesse caso, o caractere de tipo **c** indica que o argumento é um ponteiro para uma matriz de caracteres. Os próximos caracteres *n* são lidos do fluxo de entrada para o local especificado e nenhum caractere nulo ('\0') é anexado. Se *n* não for especificado, o valor padrão será 1.

## <a name="when-scanf-stops-reading-a-field"></a>Quando scanf interrompe a leitura de um campo

A função `scanf` examina cada campo de entrada, caractere por caractere. Ela pode parar de ler determinado campo de entrada antes de alcançar um caractere de espaço por vários motivos:

- A largura especificada foi alcançada.

- O próximo caractere não pode ser convertido conforme especificado.

- Os caractere seguinte entra em conflito com um caractere na cadeia de controle com o qual deve corresponder.

- O caractere seguinte não aparece em um determinado conjunto de caracteres.

Por algum motivo, quando a função `scanf` para de ler um campo de entrada, o próximo campo de entrada é considerado começando no primeiro caractere não lido. O caractere conflitante, se houver, é considerado não lido e é o primeiro caractere do próximo campo de entrada ou o primeiro caractere em operações de leitura subsequentes no fluxo de entrada.

## <a name="see-also"></a>Consulte também

[scanf, _scanf_l, wscanf, _wscanf_l](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)<br/>
[scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l](../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)<br/>
[Campos de especificação de formato: funções scanf e wscanf](../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md)<br/>
[Caracteres de campo de tipo scanf](../c-runtime-library/scanf-type-field-characters.md)<br/>
