---
title: Linha de comando DUMPBIN | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- dumpbin
dev_langs:
- C++
helpviewer_keywords:
- DUMPBIN program, command line
ms.assetid: e6ad17d3-965d-41aa-9dfd-75bb073718d4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c9028cebd7c75bb37bbfa958186ebb2e5d206094
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45724750"
---
# <a name="dumpbin-command-line"></a>Linha de comando DUMPBIN

Para executar (DUMPBIN), use a seguinte sintaxe:

```
DUMPBIN [options] files...
```

Especifique um ou mais arquivos binários, juntamente com as opções necessárias para controlar as informações. Opção DUMPBIN exibe as informações para a saída padrão. Você pode redirecioná-la para um arquivo ou use a opção /out sobrescreve para especificar um nome de arquivo para a saída.

Quando você executa (DUMPBIN) em um arquivo sem especificar uma opção, DUMPBIN exibe o /SUMMARY saída.

Quando você digita o comando `dumpbin` sem qualquer outra entrada de linha de comando DUMPBIN exibirá uma instrução de uso que resume as suas opções.

## <a name="see-also"></a>Consulte também

[Ferramentas de build de C/C++](../../build/reference/c-cpp-build-tools.md)<br/>
[Referência de DUMPBIN](../../build/reference/dumpbin-reference.md)