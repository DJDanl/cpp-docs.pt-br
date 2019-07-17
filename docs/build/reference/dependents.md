---
title: /DEPENDENTS
ms.date: 07/15/2019
f1_keywords:
- /dependents
helpviewer_keywords:
- -DEPENDENTS dumpbin option
- /DEPENDENTS dumpbin option
- DEPENDENTS dumpbin option
ms.assetid: 9b31da2a-75ac-4bbf-a3f1-adf8b0ecbbb4
ms.openlocfilehash: 88f0062a6bbca3f9199a12f739c2ade5f9d912cd
ms.sourcegitcommit: 7f5b29e24e1be9b5985044a030977485fea0b50c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/17/2019
ms.locfileid: "68299740"
---
# <a name="dependents"></a>/DEPENDENTS

Despeja os nomes das DLLs das quais a imagem importa funções. Você pode usar a lista para determinar quais DLLs redistribuir com seu aplicativo ou localizar o nome de uma dependência ausente.

## <a name="syntax"></a>Sintaxe

> **/DEPENDENTS**

Essa opção se aplica a todos os arquivos executáveis especificados na linha de comando. Ele não assume nenhum argumento.

## <a name="remarks"></a>Comentários

A opção **/Dependents** adiciona os nomes das DLLs das quais a imagem importa funções para a saída. Essa opção não despeja os nomes das funções importadas. Para ver os nomes das funções importadas, use a opção [/Imports](imports-dumpbin.md) .

Somente a opção [/HEADERS](headers.md) DUMPBIN está disponível para uso em arquivos produzidos com a opção do compilador [/GL](gl-whole-program-optimization.md).

## <a name="example"></a>Exemplo

Este exemplo mostra a saída de DUMPBIN da opção **/Dependents** no executável do cliente, criado [em instruções: Crie e use sua própria biblioteca](../walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)de vínculo dinâmico:

```cmd
C:\Users\username\Source\Repos\MathClient\Debug>dumpbin /DEPENDENTS MathClient.exe
Microsoft (R) COFF/PE Dumper Version 14.16.27032.1
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file MathClient1322.exe

File Type: EXECUTABLE IMAGE

  Image has the following dependencies:

    MathLibrary.dll
    MSVCP140D.dll
    VCRUNTIME140D.dll
    ucrtbased.dll
    KERNEL32.dll

  Summary

        1000 .00cfg
        1000 .data
        2000 .idata
        1000 .msvcjmc
        3000 .rdata
        1000 .reloc
        1000 .rsrc
        8000 .text
       10000 .textbss
```

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)
