---
title: /RAWDATA
ms.date: 11/04/2016
f1_keywords:
- /rawdata
helpviewer_keywords:
- RAWDATA dumpbin option
- raw data
- -RAWDATA dumpbin option
- /RAWDATA dumpbin option
ms.assetid: 41cba845-5e1f-415e-9fe4-604a52235983
ms.openlocfilehash: 91fa1e26ca159f23c848efc6bf46afdea2a8bc52
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50621475"
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