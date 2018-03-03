---
title: Ferramentas de vinculador LNK1223 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1223
dev_langs:
- C++
helpviewer_keywords:
- LNK1223
ms.assetid: c4728c36-daee-462f-a1c7-8733dcdec88e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c330077e8de73b8eeb71b0a418eb89d2ec0ebfdc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1223"></a>Erro das Ferramentas de Vinculador LNK1223
arquivo inválido ou corrompido: o arquivo contém contribuições .pdata inválidas  
  
 Para plataformas RISC que usam pdata, este erro ocorrerá se o compilador tiver emitido uma seção .pdata com entradas não classificadas.  
  
 Para corrigir esse problema, tente compilar sem [/GL (otimização de programa total)](../../error-messages/tool-errors/linker-tools-error-lnk1223.md) habilitado. Corpos de função vazios também podem causar este erro em alguns casos.