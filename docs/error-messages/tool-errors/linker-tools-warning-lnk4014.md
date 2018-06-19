---
title: Aviso LNK4014 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4014
dev_langs:
- C++
helpviewer_keywords:
- LNK4014
ms.assetid: 394903e9-3ded-4ea4-b7c0-a3535d4b4da4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2fb86efbdc70342861a87a233ab687f7564cb48b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33300053"
---
# <a name="linker-tools-warning-lnk4014"></a>Aviso LNK4014 (Ferramentas de Vinculador)
não é possível localizar o objeto de membro "objectname"  
  
 Não foi possível encontrar LIB `objectname` na biblioteca.  
  
 O **/remover** e **/extract** opções exigem o nome completo do objeto de membro que deve ser excluído ou copiado em um arquivo. O nome completo inclui o caminho do arquivo de objeto original. Para ver os nomes completos de objetos de membro em uma biblioteca, use DUMPBIN [/ARCHIVEMEMBERS](../../build/reference/archivemembers.md) ou LIB [/lista](../../build/reference/managing-a-library.md).