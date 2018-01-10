---
title: Ferramentas de vinculador LNK1264 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK1264
dev_langs: C++
helpviewer_keywords: LNK1264
ms.assetid: 23b1aad7-d382-42c1-bae8-db68575c57a8
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f590de75998becb9c03c73ac3083b04445a02156
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1264"></a>Erro das Ferramentas de Vinculador LNK1264
/LTCG:PGINSTRUMENT especificado mas não há geração de código necessária; falhado de instrumentação  
  
 **/LTCG:PGINSTRUMENT** foi especificado mas. obj não foram encontrados arquivos que foram compilados com [/GL](../../build/reference/gl-whole-program-optimization.md). Não é possível definir a instrumentação local e o link de falha. Deve haver pelo menos um arquivo. obj na linha de comando que é compilado com **/GL** para que seja feita a instrumentação.  
  
 Otimização Guiada do perfil (PGO) só está disponível no compiladores de 64 bits.