---
title: Ferramentas de vinculador LNK2008 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2008
dev_langs:
- C++
helpviewer_keywords:
- LNK2008
ms.assetid: bbcd83c5-c8ae-439e-a033-63643a5bb373
caps.latest.revision: 11
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 20e5f6214c9d4d50639cf493663f3c9944289752
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2008"></a>Erro das Ferramentas de Vinculador LNK2008
Destino de correção não está alinhado 'symbol_name'  
  
 LINK encontrado um destino de correção no arquivo de objeto que não estava alinhado corretamente.  
  
 Esse erro pode ser causado por alinhamento secton personalizado (por exemplo, #pragma [pack](../../preprocessor/pack.md)), [alinhar](../../cpp/align-cpp.md) modificador, ou usando o código de linguagem assembly que modifica o alinhamento de secton.  
  
 Se seu código não usar qualquer um dos itens acima, isso pode ser causado pelo compilador.
