---
title: Ferramentas de vinculador LNK1140 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1140
dev_langs:
- C++
helpviewer_keywords:
- LNK1140
ms.assetid: 468d7651-a7cd-47b9-aead-5bb2fab56121
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fc0d59589a1882aca4ef2deb419e1e4f1081e52b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-error-lnk1140"></a>Erro das Ferramentas de Vinculador LNK1140
muitos módulos para o banco de dados do programa; Vincular ao /PDB: NONE  
  
 O projeto contém mais de 4096 módulos.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Vincular novamente usando [/PDB: NONE](../../build/reference/pdb-use-program-database.md).  
  
2.  Compile alguns módulos sem informações de depuração.  
  
3.  Reduza o número de módulos.