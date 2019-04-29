---
title: STUB
ms.date: 11/04/2016
f1_keywords:
- STUB
helpviewer_keywords:
- STUB .def file statement
ms.assetid: 0a3b9643-19ed-47e9-8173-ee16bc8ed056
ms.openlocfilehash: 5224fdaa2a03dc615c9e7e7bb7f7ba822a40807e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62318115"
---
# <a name="stub"></a>STUB

Quando usado em um arquivo de definição de módulo que cria um driver de dispositivo virtual (VxD), permite que você especifique um nome de arquivo que contém uma estrutura IMAGE_DOS_HEADER (definida em WINNT. H) a ser usada no driver de dispositivo virtual (VxD), em vez do cabeçalho padrão.

```
STUB:filename
```

## <a name="remarks"></a>Comentários

Uma maneira equivalente para especificar *filename* é com o [/stub](stub-ms-dos-stub-file-name.md) a opção de vinculador.

STUB é válido em um arquivo de definição de módulo somente quando a criação de um VxD.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](rules-for-module-definition-statements.md)
