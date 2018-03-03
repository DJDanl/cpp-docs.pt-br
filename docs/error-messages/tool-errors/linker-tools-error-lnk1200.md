---
title: Ferramentas de vinculador LNK1200 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1200
dev_langs:
- C++
helpviewer_keywords:
- LNK1200
ms.assetid: 55771145-915e-4006-ac6c-ac702041eb2f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 70bf262d4f99c807e3488c1f9b2ed9e73b1eb715
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1200"></a>Erro das Ferramentas de Vinculador LNK1200
Erro ao ler o banco de dados do programa 'filename'  
  
 Não foi possível ler o banco de dados do programa (PDB).  
  
 Esse erro pode ser causado por corrupção de arquivo.  
  
 Se `filename` é o PDB para um arquivo de objeto, recompilar o arquivo de objeto usando [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md).  
  
 Se `filename` é o PDB para o arquivo de saída principal, e esse erro ocorreu durante um link incremental, exclua o PDB e vincular novamente.