---
title: Ferramentas de vinculador LNK2008 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK2008
dev_langs: C++
helpviewer_keywords: LNK2008
ms.assetid: bbcd83c5-c8ae-439e-a033-63643a5bb373
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a7c2fecff55677653c25c7d87fb22fa984526159
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk2008"></a>Erro das Ferramentas de Vinculador LNK2008
O alvo da correção não está alinhado 'symbol_name'  
  
 LINK encontrado um destino de correção no arquivo de objeto que não foi alinhado corretamente.  
  
 Esse erro pode ser causado por um alinhamento personalizado secton (por exemplo, #pragma [pacote](../../preprocessor/pack.md)), [alinhar](../../cpp/align-cpp.md) modificador, ou usando o código de linguagem assembly que modifica secton alinhamento.  
  
 Se seu código não usar qualquer um dos itens acima, isso pode ser causado pelo compilador.