---
title: Ferramentas de vinculador LNK1158 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1158
dev_langs:
- C++
helpviewer_keywords:
- LNK1158
ms.assetid: 45febf16-d9e1-42db-af91-532e2717fd6a
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f7dca2c5b64863146d63436f326a90a59be06601
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1158"></a>Erro das Ferramentas de Vinculador LNK1158
não é possível executar 'filename'  
  
 O arquivo executável específico chamado por [LINK](../../build/reference/linker-command-line-syntax.md) está fora do diretório que contém o LINK nem em um diretório especificado na variável de ambiente PATH.  
  
 Por exemplo, você receberá esse erro se você tentar usar o parâmetro PGOPTIMIZE para o [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) opção de vinculador em um computador com um sistema operacional de 32 bits.
