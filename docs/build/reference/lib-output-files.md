---
title: "Arquivos de saída LIB | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: Lib
dev_langs: C++
helpviewer_keywords: output files, LIB
ms.assetid: e73d2f9b-a42d-402b-b7e3-3a94bebb317e
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ecfb3df6f503e91dbf96a6da4bd1dd79b4f9ee3d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="lib-output-files"></a>Arquivos de saída LIB
Os arquivos de saída produzidos por LIB dependem do modo no qual ele está sendo usado, conforme mostrado na tabela a seguir.  
  
|Modo|Saída|  
|----------|------------|  
|Padrão (Criando ou modificando uma biblioteca)|Biblioteca COFF (. lib)|  
|Extraindo um membro com /EXTRACT|Arquivo de objeto (. obj)|  
|Criar uma exportação de arquivo e importar biblioteca com /DEF|Importar biblioteca (. lib) e um arquivo de exportação (. Exp)|  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral de LIB](../../build/reference/overview-of-lib.md)