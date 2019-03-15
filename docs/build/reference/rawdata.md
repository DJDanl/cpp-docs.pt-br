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
ms.openlocfilehash: 02af8df04d80c20c5d7629b51abab6295a21f5e5
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57816458"
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

Somente o [/HEADERS](headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](gl-whole-program-optimization.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)
