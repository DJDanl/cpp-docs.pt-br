---
title: Aviso LNK4001 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4001
dev_langs:
- C++
helpviewer_keywords:
- LNK4001
ms.assetid: 0a8b1c3a-64ce-4311-b7c0-065995059246
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: acf65c00c5c039769a05e009dcfe46ea42633ac4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33300352"
---
# <a name="linker-tools-warning-lnk4001"></a>Aviso LNK4001 (Ferramentas de Vinculador)
Nenhum arquivo de objeto especificado; bibliotecas usadas  
  
 O vinculador foi passado um ou mais arquivos. lib, mas nenhum arquivo. obj.  
  
 Como o vinculador não é capaz de acessar informações em um arquivo que é capaz de acessar em um arquivo. obj, esse aviso indica que você precisa especificar explicitamente as outras opções de vinculador. Por exemplo, você precisará especificar o [/máquina](../../build/reference/machine-specify-target-platform.md), [/out](../../build/reference/out-output-file-name.md), ou [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opções.