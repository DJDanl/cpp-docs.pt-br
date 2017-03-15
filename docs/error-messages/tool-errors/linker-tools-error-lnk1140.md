---
title: Ferramentas de vinculador LNK1140 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1140
dev_langs:
- C++
helpviewer_keywords:
- LNK1140
ms.assetid: 468d7651-a7cd-47b9-aead-5bb2fab56121
caps.latest.revision: 7
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
ms.openlocfilehash: c6b7fd082fa5e0cb601c3cfb00917e7f059e5e79
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1140"></a>Erro das Ferramentas de Vinculador LNK1140
muitos módulos para o programa de banco de dados; vincular ao /PDB:NONE  
  
 O projeto contém mais de 4096 módulos.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir, usando as seguintes soluções possíveis  
  
1.  Vincular novamente usando [/PDB: nenhum](../../build/reference/pdb-use-program-database.md).  
  
2.  Compile alguns módulos sem informações de depuração.  
  
3.  Reduza o número de módulos.
