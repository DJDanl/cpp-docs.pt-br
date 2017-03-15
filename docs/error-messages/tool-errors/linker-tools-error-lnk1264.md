---
title: Ferramentas de vinculador LNK1264 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1264
dev_langs:
- C++
helpviewer_keywords:
- LNK1264
ms.assetid: 23b1aad7-d382-42c1-bae8-db68575c57a8
caps.latest.revision: 9
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
ms.openlocfilehash: 0d075c807a698e62b4d46fcbd39e660d3e39d469
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1264"></a>Erro das Ferramentas de Vinculador LNK1264
/LTCG:PGINSTRUMENT especificado embora sem código necessário; instrumento falhou  
  
 **/LTCG:PGINSTRUMENT** foi especificado mas. obj não foram encontrados arquivos que foram compilados com [/GL](../../build/reference/gl-whole-program-optimization.md). Instrumentação não pode tirar o local e o link falhado. Deve haver pelo menos um arquivo. obj na linha de comando que é compilado com **/GL** para que a instrumentação pode ocorrer.  
  
 Otimização Guiada por perfil (PGO) só está disponível nos compiladores de 64 bits.
