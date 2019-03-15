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
ms.openlocfilehash: ff11e64ae8ec0eb5236369e8322e051ee40b26bd
ms.sourcegitcommit: faa42c8a051e746d99dcebe70fd4bbaf3b023ace
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/15/2019
ms.locfileid: "57820111"
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

[Opções de EDITBIN](editbin-options.md)
