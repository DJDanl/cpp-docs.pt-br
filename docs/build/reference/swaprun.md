---
title: -SWAPRUN | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /swaprun
dev_langs:
- C++
helpviewer_keywords:
- /SWAPRUN editbin option
- -SWAPRUN editbin option
- SWAPRUN editbin option
ms.assetid: 6eefd7f3-ca47-48e3-8509-323d27cf4ae7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1a93b854dba2855fa68bb3be163cecdcd3570df0
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45723086"
---
# <a name="swaprun"></a>/SWAPRUN

```
/SWAPRUN:{[!]NET|[!]CD}
```

## <a name="remarks"></a>Comentários

Essa opção edita a imagem para informar ao sistema operacional para copiar a imagem para um arquivo de permuta e executá-lo a partir daí. Use esta opção para imagens que residem em redes ou mídia removível.

Você pode adicionar ou remover os qualificadores NET ou CD:

- NET indica que a imagem reside em uma rede.

- CD indica que a imagem reside em um CD-ROM ou mídia removível semelhante.

- Use! NET e! CD para reverter os efeitos de CD e NET.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)