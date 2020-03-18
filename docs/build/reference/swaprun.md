---
title: /SWAPRUN
ms.date: 11/04/2016
f1_keywords:
- /swaprun_editbin
helpviewer_keywords:
- /SWAPRUN editbin option
- -SWAPRUN editbin option
- SWAPRUN editbin option
ms.assetid: 6eefd7f3-ca47-48e3-8509-323d27cf4ae7
ms.openlocfilehash: 83aa2cdb445ed1ac6bac5b1237f90a116986b0a9
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438849"
---
# <a name="swaprun"></a>/SWAPRUN

```
/SWAPRUN:{[!]NET|[!]CD}
```

## <a name="remarks"></a>Comentários

Esta opção edita a imagem para instruir o sistema operacional a copiar a imagem para um arquivo de permuta e executá-la a partir daí. Use essa opção para imagens que residem em redes ou mídias removíveis.

Você pode adicionar ou remover os qualificadores de rede ou de CD:

- NET indica que a imagem reside em uma rede.

- CD indica que a imagem reside em um CD-ROM ou em uma mídia removível semelhante.

- Use! NET e! CD para inverter os efeitos de NET e CD.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)
