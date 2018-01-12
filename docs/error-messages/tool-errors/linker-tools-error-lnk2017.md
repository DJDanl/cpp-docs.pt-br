---
title: Ferramentas de vinculador LNK2017 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK2017
dev_langs: C++
helpviewer_keywords: LNK2017
ms.assetid: f7c21733-b0fb-4888-a295-9b453ba6ee77
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9446cb72ba9380e57b014b32d9ae00f6e9e554d1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk2017"></a>Erro das Ferramentas de Vinculador LNK2017
realocação 'symbol' para 'segmento' inválido sem /LARGEADDRESSAWARE: no  
  
 Você está tentando criar uma imagem de 64 bits com endereços de 32 bits. Para fazer isso, você deve:  
  
-   Use um endereço de carga fixa.  
  
-   Restringir a imagem a 3 GB.  
  
-   Especifique [/LARGEADDRESSAWARE: no](../../build/reference/largeaddressaware-handle-large-addresses.md).