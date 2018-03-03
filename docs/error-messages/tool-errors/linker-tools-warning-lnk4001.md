---
title: Aviso LNK4001 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4001
dev_langs:
- C++
helpviewer_keywords:
- LNK4001
ms.assetid: 0a8b1c3a-64ce-4311-b7c0-065995059246
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2ecc78fe50fd34a0c6f583bf103d368e23f19f2e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4001"></a>Aviso LNK4001 (Ferramentas de Vinculador)
Nenhum arquivo de objeto especificado; bibliotecas usadas  
  
 O vinculador foi passado um ou mais arquivos. lib, mas nenhum arquivo. obj.  
  
 Como o vinculador não é capaz de acessar informações em um arquivo que é capaz de acessar em um arquivo. obj, esse aviso indica que você precisa especificar explicitamente as outras opções de vinculador. Por exemplo, você precisará especificar o [/máquina](../../build/reference/machine-specify-target-platform.md), [/out](../../build/reference/out-output-file-name.md), ou [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opções.