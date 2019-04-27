---
title: Aviso LNK4075 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4075
helpviewer_keywords:
- LNK4075
ms.assetid: f39ad3f9-c263-4cf0-9d70-259fc56ac96d
ms.openlocfilehash: bf22e7c78dce6949c357d7ad4a0c76209c88eef3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62186899"
---
# <a name="linker-tools-warning-lnk4075"></a>Aviso LNK4075 (Ferramentas de Vinculador)

Ignorando a opção "1" devido a especificação de "como option2"

A segunda opção substitui o primeiro.

Opções do vinculador mutuamente exclusivos que estão sendo especificadas.  Examine suas opções de vinculador.  Em que as opções do vinculador são especificadas depende de como você está criando seu projeto.

- Se você estiver compilando no ambiente de desenvolvimento, consulte as páginas de propriedades do vinculador para seu projeto e ver onde as duas opções de vinculador estão sendo especificadas.  Ver [definir compilador e propriedades de compilação](../../build/working-with-project-properties.md) para obter mais informações.

- Se você compilar na linha de comando, examine as opções de vinculador especificadas existe.

- Se você compilar com scripts de build, examine a seus scripts para ver onde essas opções de vinculador estão sendo especificadas.

Quando você encontrar em que as opções de vinculador mutuamente exclusivas são especificadas, remova uma das opções do vinculador.

Alguns exemplos específicos:

- Se você vincular um módulo que foi compilado com **/ZI**, que significa que uma opção de vinculador internos chamados /EDITANDCONTINUE e um módulo que foi compilado com /OPT: REF, /OPT: ICF ou /incremental: no, que não implicam nenhum /EDITANDCONTINUE, será obter LNK4075.  Ver [/Z7, /Zi, /ZI (formato de informações de depuração)](../../build/reference/z7-zi-zi-debug-information-format.md) para obter mais informações.