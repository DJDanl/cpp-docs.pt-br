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
ms.openlocfilehash: e6e8af5b23d2e6cd0759f75c4054e0a811f687e1
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32375042"
---
# <a name="swaprun"></a>/SWAPRUN
```  
/SWAPRUN:{[!]NET|[!]CD}  
```  
  
## <a name="remarks"></a>Comentários  
 Essa opção edita a imagem para informar o sistema operacional para copiar a imagem para um arquivo de permuta e executá-lo lá. Use esta opção para imagens que residem em redes ou mídia removível.  
  
 Você pode adicionar ou remover os qualificadores NET ou CD:  
  
-   NET indica que a imagem reside em uma rede.  
  
-   CD indica que a imagem reside em um CD-ROM ou mídia removível semelhante.  
  
-   Use! NET e! CD para reverter os efeitos do CD e NET.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de EDITBIN](../../build/reference/editbin-options.md)