---
title: Ferramentas de vinculador LNK1264 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1264
dev_langs:
- C++
helpviewer_keywords:
- LNK1264
ms.assetid: 23b1aad7-d382-42c1-bae8-db68575c57a8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7ed21327028fc9849f6e0694bb82ae34c6084842
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33301457"
---
# <a name="linker-tools-error-lnk1264"></a>Erro das Ferramentas de Vinculador LNK1264
/LTCG:PGINSTRUMENT especificado mas não há geração de código necessária; falhado de instrumentação  
  
 **/LTCG:PGINSTRUMENT** foi especificado mas. obj não foram encontrados arquivos que foram compilados com [/GL](../../build/reference/gl-whole-program-optimization.md). Não é possível definir a instrumentação local e o link de falha. Deve haver pelo menos um arquivo. obj na linha de comando que é compilado com **/GL** para que seja feita a instrumentação.  
  
 Otimização Guiada do perfil (PGO) só está disponível no compiladores de 64 bits.