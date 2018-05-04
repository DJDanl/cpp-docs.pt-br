---
title: Pseudodestinos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- makefiles, pseudotargets
- pseudotargets and NMAKE
- NMAKE program, pseudotargets
- timestamps, makefile pseudotargets
- NMAKE program, targets
ms.assetid: c8c479dc-0129-4186-8366-bc6251f2b494
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 67dbc6ae3ad331ab3297b62d00044c3edf679994
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="pseudotargets"></a>Pseudodestinos
Um pseudotarget é um rótulo usado no lugar de um nome de arquivo em uma linha de dependência. Ele será interpretado como um arquivo que não existe e então está desatualizado. NMAKE pressupõe que o carimbo de hora do pseudotarget é o mais recente de todos os seus dependentes. Se ele tiver nenhuma dependentes, supõe-se a hora atual. Se um pseudotarget é usado como um destino, os comandos são sempre executados. Um pseudotarget usado como um dependente também deve aparecer como um destino em outra dependência. No entanto, essa dependência não precisa ter um bloco de comandos.  
  
 Nomes de pseudotarget seguir as regras de sintaxe de nome de arquivo para destinos. No entanto, se o nome não tem uma extensão (ou seja, não contém um período), ele pode exceder o limite de 8 caracteres de nomes de arquivos e pode ter até 256 caracteres.  
  
## <a name="see-also"></a>Consulte também  
 [Destinos](../build/targets.md)