---
title: stdin, stdout, stderr | Microsoft Docs
ms.custom: ''
ms.date: 10/23/2018
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- stdin
- stderr
- stdout
dev_langs:
- C++
helpviewer_keywords:
- stdout function
- standard output stream
- standard error stream
- stdin function
- standard input stream
- stderr function
ms.assetid: badd4735-596d-4498-857c-ec8b7e670e4c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 707811a9c05135cb46520dd72895d677cdc0a6e4
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49808700"
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
