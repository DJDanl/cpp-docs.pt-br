---
title: Ferramentas de vinculador LNK1223 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1223
dev_langs:
- C++
helpviewer_keywords:
- LNK1223
ms.assetid: c4728c36-daee-462f-a1c7-8733dcdec88e
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
ms.openlocfilehash: 066d4768d58b31e75a0b436c84bff019993f35e2
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1223"></a>Erro das Ferramentas de Vinculador LNK1223
arquivo inválido ou corrompido: o arquivo contém contribuições .pdata inválidas  
  
 Para plataformas RISC que usam pdata, este erro ocorrerá se o compilador tiver emitido uma seção .pdata com entradas não classificadas.  
  
 Para corrigir esse problema, tente compilar sem [/GL (otimização de programa total)](../../error-messages/tool-errors/linker-tools-error-lnk1223.md) habilitado. Corpos de função vazios também podem causar este erro em alguns casos.
