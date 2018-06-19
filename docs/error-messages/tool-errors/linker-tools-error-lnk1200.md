---
title: Ferramentas de vinculador LNK1200 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1200
dev_langs:
- C++
helpviewer_keywords:
- LNK1200
ms.assetid: 55771145-915e-4006-ac6c-ac702041eb2f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ab32939c55dce5e27f907f3d23e639b24741cdc3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33298818"
---
# <a name="linker-tools-error-lnk1200"></a>Erro das Ferramentas de Vinculador LNK1200
Erro ao ler o banco de dados do programa 'filename'  
  
 Não foi possível ler o banco de dados do programa (PDB).  
  
 Esse erro pode ser causado por corrupção de arquivo.  
  
 Se `filename` é o PDB para um arquivo de objeto, recompilar o arquivo de objeto usando [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md).  
  
 Se `filename` é o PDB para o arquivo de saída principal, e esse erro ocorreu durante um link incremental, exclua o PDB e vincular novamente.