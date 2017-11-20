---
title: Destinos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: targets, specifying in NMAKE
ms.assetid: 826ee849-4278-4c6e-97c3-79a2b5fe6463
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 40bb3e7e35b00f6c09cdaf5a87fc558db8324989
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="targets"></a>Destinos
Em uma linha de dependência, especifique um ou mais destinos, usando qualquer nome de arquivo válido, o nome do diretório ou [pseudotarget](../build/pseudotargets.md). Separe vários destinos com um ou mais espaços ou guias. Destinos não diferenciam maiusculas de minúsculas. São permitidos caminhos com nomes de arquivo. Um destino não pode exceder 256 caracteres. Se o destino precede o vírgula é um único caractere, use um espaço separar; Caso contrário, NMAKE interpreta a combinação de letra vírgula como um especificador de unidade.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
 [Pseudodestinos](../build/pseudotargets.md)  
  
 [Vários destinos](../build/multiple-targets.md)  
  
 [Dependências cumulativas](../build/cumulative-dependencies.md)  
  
 [Destinos em vários blocos de descrição](../build/targets-in-multiple-description-blocks.md)  
  
 [Efeitos colaterais da dependência](../build/dependency-side-effects.md)  
  
## <a name="see-also"></a>Consulte também  
 [Blocos de descrição](../build/description-blocks.md)