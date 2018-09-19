---
title: stdin, stdout, stderr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: a36d5fd60a19222e6f802e5a14037fb01ff865f5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46071972"
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
|**stdout**|Saída padrão|
|`stderr`|Erro padrão|

Esses ponteiros podem ser usados como argumentos para funções. Algumas funções, como **getchar** e `putchar`, usam `stdin` e **stdout** automaticamente.

Esses ponteiros são constantes e não podem receber novos valores. A função `freopen` pode ser usada para redirecionar os fluxos de arquivos de disco ou em outros dispositivos. O sistema operacional permite redirecionar a entrada e saída no nível de comando de um programa.

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../c-runtime-library/stream-i-o.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)