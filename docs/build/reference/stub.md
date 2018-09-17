---
title: STUB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- STUB
dev_langs:
- C++
helpviewer_keywords:
- STUB .def file statement
ms.assetid: 0a3b9643-19ed-47e9-8173-ee16bc8ed056
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 151d7b425a7f397a05e3a06e9d94489a0c76f899
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45725108"
---
# <a name="stub"></a>STUB

Quando usado em um arquivo de definição de módulo que cria um driver de dispositivo virtual (VxD), permite que você especifique um nome de arquivo que contém uma estrutura IMAGE_DOS_HEADER (definida em WINNT. H) a ser usada no driver de dispositivo virtual (VxD), em vez do cabeçalho padrão.

```
STUB:filename
```

## <a name="remarks"></a>Comentários

Uma maneira equivalente para especificar *filename* é com o [/stub](../../build/reference/stub-ms-dos-stub-file-name.md) a opção de vinculador.

STUB é válido em um arquivo de definição de módulo somente quando a criação de um VxD.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)