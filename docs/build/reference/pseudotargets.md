---
title: Pseudodestinos
ms.date: 11/04/2016
helpviewer_keywords:
- makefiles, pseudotargets
- pseudotargets and NMAKE
- NMAKE program, pseudotargets
- timestamps, makefile pseudotargets
- NMAKE program, targets
ms.assetid: c8c479dc-0129-4186-8366-bc6251f2b494
ms.openlocfilehash: 90552d00aaeed804f2bf492a94493882f196167d
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824422"
---
# <a name="pseudotargets"></a>Pseudodestinos

Um pseudotarget é um rótulo usado no lugar de um nome de arquivo em uma linha de dependência. Ele será interpretado como um arquivo que não existe e, portanto, está desatualizado. NMAKE pressupõe que o carimbo de hora de um pseudotarget é a mais recente de todos os seus dependentes. Se ela tem nenhum dependentes, a hora atual será assumida. Se um pseudotarget for usado como um destino, seus comandos sempre são executados. Um pseudotarget usado como um dependente também deve aparecer como um destino em outra dependência. No entanto, essa dependência não precisa ter um bloco de comandos.

Nomes de pseudotarget seguir as regras de sintaxe de nome de arquivo para destinos. No entanto, se o nome não tiver uma extensão (ou seja, não contém um período), ele pode exceder o limite de 8 caracteres para nomes de arquivo e pode ter até 256 caracteres.

## <a name="see-also"></a>Consulte também

[Destinos](targets.md)
