---
title: STUB
ms.date: 11/04/2016
f1_keywords:
- STUB
helpviewer_keywords:
- STUB .def file statement
ms.assetid: 0a3b9643-19ed-47e9-8173-ee16bc8ed056
ms.openlocfilehash: fd2e7c4a3bd9fa09b88f4c3caa9b7d5b73c1ad98
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57412933"
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
