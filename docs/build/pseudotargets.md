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
ms.openlocfilehash: 34b2b2f0d54a6e11bdfd6e818eb08d01721d80e2
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414824"
---
# <a name="pseudotargets"></a>Pseudodestinos

Um pseudotarget é um rótulo usado no lugar de um nome de arquivo em uma linha de dependência. Ele será interpretado como um arquivo que não existe e, portanto, está desatualizado. NMAKE pressupõe que o carimbo de hora de um pseudotarget é a mais recente de todos os seus dependentes. Se ela tem nenhum dependentes, a hora atual será assumida. Se um pseudotarget for usado como um destino, seus comandos sempre são executados. Um pseudotarget usado como um dependente também deve aparecer como um destino em outra dependência. No entanto, essa dependência não precisa ter um bloco de comandos.

Nomes de pseudotarget seguir as regras de sintaxe de nome de arquivo para destinos. No entanto, se o nome não tiver uma extensão (ou seja, não contém um período), ele pode exceder o limite de 8 caracteres para nomes de arquivo e pode ter até 256 caracteres.

## <a name="see-also"></a>Consulte também

[Destinos](../build/targets.md)
