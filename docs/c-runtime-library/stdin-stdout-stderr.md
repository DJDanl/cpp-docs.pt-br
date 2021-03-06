---
title: stdin, stdout, stderr
ms.date: 10/23/2018
f1_keywords:
- stdin
- stderr
- stdout
helpviewer_keywords:
- stdout function
- standard output stream
- standard error stream
- stdin function
- standard input stream
- stderr function
ms.assetid: badd4735-596d-4498-857c-ec8b7e670e4c
ms.openlocfilehash: 5de1ff01282f30ad133f909cb87f5d7c8d521ae5
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57741955"
---
# <a name="stdin-stdout-stderr"></a>stdin, stdout, stderr

## <a name="syntax"></a>Sintaxe

```
FILE *stdin;
FILE *stdout;
FILE *stderr;
#include <stdio.h>
```

## <a name="remarks"></a>Comentários

Esses são fluxos padrão para entrada, saída e saída de erro.

Por padrão, a entrada padrão é lida do teclado, enquanto a saída padrão e erro padrão são impressos na tela.

Os ponteiros de fluxo a seguir estão disponíveis para acessar fluxos padrão:

|Ponteiro|Fluxo|
|-------------|------------|
|`stdin`|Entrada padrão|
|`stdout`|Saída padrão|
|`stderr`|Erro padrão|

Esses ponteiros podem ser usados como argumentos para funções. Algumas funções, como [getchar](../c-runtime-library/reference/getchar-getwchar.md) e [putchar](../c-runtime-library/reference/putchar-putwchar.md), usam `stdin` e `stdout` automaticamente.

Esses ponteiros são constantes e não podem receber novos valores. A função [freopen](../c-runtime-library/reference/freopen-wfreopen.md) pode ser usada para redirecionar os fluxos para arquivos de disco ou outros dispositivos. O sistema operacional permite redirecionar a entrada e saída no nível de comando de um programa.

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../c-runtime-library/stream-i-o.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)
