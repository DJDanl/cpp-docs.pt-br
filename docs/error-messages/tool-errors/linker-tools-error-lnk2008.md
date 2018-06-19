---
title: Ferramentas de vinculador LNK2008 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2008
dev_langs:
- C++
helpviewer_keywords:
- LNK2008
ms.assetid: bbcd83c5-c8ae-439e-a033-63643a5bb373
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c4ee6a8a4c4cc6d33f47d5335daa9fccd4e5fd99
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33299559"
---
# <a name="linker-tools-error-lnk2008"></a>Erro das Ferramentas de Vinculador LNK2008
O alvo da correção não está alinhado 'symbol_name'  
  
 LINK encontrado um destino de correção no arquivo de objeto que não foi alinhado corretamente.  
  
 Esse erro pode ser causado por um alinhamento personalizado secton (por exemplo, #pragma [pacote](../../preprocessor/pack.md)), [alinhar](../../cpp/align-cpp.md) modificador, ou usando o código de linguagem assembly que modifica secton alinhamento.  
  
 Se seu código não usar qualquer um dos itens acima, isso pode ser causado pelo compilador.