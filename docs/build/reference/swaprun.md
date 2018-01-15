---
title: -SWAPRUN | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /swaprun
dev_langs: C++
helpviewer_keywords:
- /SWAPRUN editbin option
- -SWAPRUN editbin option
- SWAPRUN editbin option
ms.assetid: 6eefd7f3-ca47-48e3-8509-323d27cf4ae7
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 249ed999d9a60116875e88553863ef5cd234ade9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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