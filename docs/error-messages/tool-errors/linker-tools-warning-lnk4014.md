---
title: Aviso LNK4014 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4014
dev_langs: C++
helpviewer_keywords: LNK4014
ms.assetid: 394903e9-3ded-4ea4-b7c0-a3535d4b4da4
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8e0e0e87fb9c8e6006c62e07b7bb9b6435a22dd3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4014"></a>Aviso LNK4014 (Ferramentas de Vinculador)
não é possível localizar o objeto de membro "objectname"  
  
 Não foi possível encontrar LIB `objectname` na biblioteca.  
  
 O **/remover** e **/extract** opções exigem o nome completo do objeto de membro que deve ser excluído ou copiado em um arquivo. O nome completo inclui o caminho do arquivo de objeto original. Para ver os nomes completos de objetos de membro em uma biblioteca, use DUMPBIN [/ARCHIVEMEMBERS](../../build/reference/archivemembers.md) ou LIB [/lista](../../build/reference/managing-a-library.md).