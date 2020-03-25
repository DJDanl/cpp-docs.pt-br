---
title: Aviso LNK4075 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4075
helpviewer_keywords:
- LNK4075
ms.assetid: f39ad3f9-c263-4cf0-9d70-259fc56ac96d
ms.openlocfilehash: e4a385b9559e2f54e81bda76e6dd13505e978a74
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183482"
---
# <a name="linker-tools-warning-lnk4075"></a>Aviso LNK4075 (Ferramentas de Vinculador)

ignorando "opção 1" devido à especificação "opção 2"

A segunda opção substitui a primeira.

Opções de vinculador mutuamente exclusivas estão sendo especificadas.  Examine as opções do vinculador.  Onde as opções do vinculador são especificadas depende de como você está criando seu projeto.

- Se você estiver criando no ambiente de desenvolvimento, examine as páginas de propriedades do vinculador do seu projeto e veja onde ambas as opções do vinculador estão sendo especificadas.  Consulte [definir compilador e propriedades de compilação](../../build/working-with-project-properties.md) para obter mais informações.

- Se você criar na linha de comando, examine as opções de vinculador especificadas lá.

- Se você criar com scripts de compilação, examine seus scripts para ver onde essas opções de vinculador estão sendo especificadas.

Quando você descobrir onde as opções do vinculador mutuamente exclusivas são especificadas, remova uma das opções do vinculador.

Alguns exemplos específicos:

- Se você vincular um módulo que foi compilado com **/Zi**, o que implica uma opção de vinculador interno chamada/EDITANDCONTINUE e um módulo que foi compilado com/OPT: REF,/OPT: ICF ou/incremental: no, que não implica nenhum/EDITANDCONTINUE, você receberá LNK4075.  Consulte [/Z7,/Zi,/Zi (formato de informações de depuração)](../../build/reference/z7-zi-zi-debug-information-format.md) para obter mais informações.
