---
title: Ferramentas de vinculador LNK1200 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1200
dev_langs:
- C++
helpviewer_keywords:
- LNK1200
ms.assetid: 55771145-915e-4006-ac6c-ac702041eb2f
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 898b098944d223c2be74f454cc979fb7393f9fed
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1200"></a>Erro das Ferramentas de Vinculador LNK1200
Erro ao ler o banco de dados do programa 'filename'  
  
 Não foi possível ler o banco de dados do programa (PDB).  
  
 Esse erro pode ser causado por corrupção de arquivo.  
  
 Se `filename` é o PDB para um arquivo de objeto, recompilar o arquivo de objeto usando [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md).  
  
 Se `filename` é o PDB para o arquivo de saída principal, e esse erro ocorreu durante um link incremental, exclua o PDB e vincular novamente.
