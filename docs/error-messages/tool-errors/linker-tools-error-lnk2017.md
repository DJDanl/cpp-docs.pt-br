---
title: Ferramentas de vinculador LNK2017 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2017
dev_langs:
- C++
helpviewer_keywords:
- LNK2017
ms.assetid: f7c21733-b0fb-4888-a295-9b453ba6ee77
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: bd4a94411967a93d84311c89cbde1e48096c8047
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2017"></a>Erro das Ferramentas de Vinculador LNK2017
realocação de 'symbol' a 'segmento' inválido sem /LARGEADDRESSAWARE:NO  
  
 Você está tentando criar uma imagem de 64 bits com endereços de 32 bits. Para fazer isso, você deve:  
  
-   Use um endereço de carga fixa.  
  
-   Restringir a imagem para 3 GB.  
  
-   Especifique [/largeaddressaware:no](../../build/reference/largeaddressaware-handle-large-addresses.md).
