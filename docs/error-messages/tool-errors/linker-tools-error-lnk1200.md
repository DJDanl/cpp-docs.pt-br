---
title: Ferramentas de vinculador LNK1200 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK1200
dev_langs: C++
helpviewer_keywords: LNK1200
ms.assetid: 55771145-915e-4006-ac6c-ac702041eb2f
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 792c81e36b99bbac6c0417f0230bb1ea2bb1787c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-error-lnk1200"></a>Erro das Ferramentas de Vinculador LNK1200
Erro ao ler o banco de dados do programa 'filename'  
  
 Não foi possível ler o banco de dados do programa (PDB).  
  
 Esse erro pode ser causado por corrupção de arquivo.  
  
 Se `filename` é o PDB para um arquivo de objeto, recompilar o arquivo de objeto usando [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md).  
  
 Se `filename` é o PDB para o arquivo de saída principal, e esse erro ocorreu durante um link incremental, exclua o PDB e vincular novamente.