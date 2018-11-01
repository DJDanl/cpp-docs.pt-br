---
title: /SWAPRUN
ms.date: 11/04/2016
f1_keywords:
- /swaprun
helpviewer_keywords:
- /SWAPRUN editbin option
- -SWAPRUN editbin option
- SWAPRUN editbin option
ms.assetid: 6eefd7f3-ca47-48e3-8509-323d27cf4ae7
ms.openlocfilehash: 0440d268a807e6f3f43beb9f38bd1950dee55ffd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50550716"
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