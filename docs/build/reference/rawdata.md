---
title: -RAWDATA | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /rawdata
dev_langs:
- C++
helpviewer_keywords:
- RAWDATA dumpbin option
- raw data
- -RAWDATA dumpbin option
- /RAWDATA dumpbin option
ms.assetid: 41cba845-5e1f-415e-9fe4-604a52235983
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 38677b0e67ddaec5b6ef0e3fcffed1bed27826b6
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707168"
---
# <a name="rawdata"></a>/RAWDATA

```
/RAWDATA[:{1|2|4|8|NONE[,number]]
```

## <a name="remarks"></a>Comentários

Essa opção exibe o conteúdo bruto de cada seção no arquivo. Os argumentos de controlam o formato da tela, conforme mostrado abaixo:

|Argumento|Resultado|
|--------------|------------|
|1|O padrão. Conteúdo é exibido em bytes hexadecimais e também como caracteres ASCII se eles tiverem uma representação impressa.|
|2|Conteúdo é exibido como valores hexadecimais de 2 bytes.|
|4|Conteúdo é exibido como valores hexadecimais de 4 bytes.|
|8|Conteúdo é exibido como valores hexadecimais de 8 bytes.|
|NONE|Dados brutos são suprimidos. Esse argumento é útil para controlar a saída de/ALL.|
|*Número*|Linhas exibidas são definidas para uma largura que mantém `number` valores por linha.|

Somente o [/HEADERS](../../build/reference/headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](../../build/reference/dumpbin-options.md)