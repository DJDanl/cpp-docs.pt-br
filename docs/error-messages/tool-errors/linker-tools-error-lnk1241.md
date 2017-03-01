---
title: Ferramentas de vinculador LNK1241 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1241
dev_langs:
- C++
helpviewer_keywords:
- LNK1241
ms.assetid: 7b8b52eb-0231-4521-b52a-2bce8d3e8956
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
ms.openlocfilehash: f2d84ba279e3fbb0219dc337a932e23f42101a6d
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1241"></a>Erro das Ferramentas de Vinculador LNK1241
arquivo de recurso 'arquivo de recurso' já especificado  
  
 Esse erro é gerado se você executar **cvtres** manualmente a partir da linha de comando e se você passar o obj resultantes de arquivo para o vinculador além para outros arquivos. res.  
  
 Para especificar vários arquivos. res, passá-los para o vinculador como arquivos. res, não de dentro. obj arquivos criados pelo **cvtres**.
