---
title: Reutilizando arquivos embutidos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- inline files, reusing NMAKE
- revising inline files
- NMAKE program, inline files
ms.assetid: d42dbffb-2cef-4ccb-9a1f-20b8ef81481c
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: cbad7ad7a4aee928158155a7a38c8d14a2b33a63
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="reusing-inline-files"></a>Reutilizando arquivos embutidos
Para reutilizar um arquivo embutido, especifique <<*filename* onde o arquivo é definido e usado pela primeira vez, em seguida, reutilize *filename* sem << posterior no mesmo ou em outro comando. O comando para criar o arquivo embutido deve executar antes de todos os comandos que usam o arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)