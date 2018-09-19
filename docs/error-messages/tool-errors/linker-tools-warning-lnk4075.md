---
title: Ferramentas de vinculador LNK4075 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4075
dev_langs:
- C++
helpviewer_keywords:
- LNK4075
ms.assetid: f39ad3f9-c263-4cf0-9d70-259fc56ac96d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1a021a9345975dcb197ab578901baf22f76db846
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46059648"
---
# <a name="linker-tools-warning-lnk4075"></a>Aviso LNK4075 (Ferramentas de Vinculador)

Ignorando a opção "1" devido a especificação de "como option2"

A segunda opção substitui o primeiro.

Opções do vinculador mutuamente exclusivos que estão sendo especificadas.  Examine suas opções de vinculador.  Em que as opções do vinculador são especificadas depende de como você está criando seu projeto.

- Se você estiver compilando no ambiente de desenvolvimento, consulte as páginas de propriedades do vinculador para seu projeto e ver onde as duas opções de vinculador estão sendo especificadas.  Ver [trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md) para obter mais informações.

- Se você compilar na linha de comando, examine as opções de vinculador especificadas existe.

- Se você compilar com scripts de build, examine a seus scripts para ver onde essas opções de vinculador estão sendo especificadas.

Quando você encontrar em que as opções de vinculador mutuamente exclusivas são especificadas, remova uma das opções do vinculador.

Alguns exemplos específicos:

- Se você vincular um módulo que foi compilado com **/ZI**, que significa que uma opção de vinculador internos chamados /EDITANDCONTINUE e um módulo que foi compilado com /OPT: REF, /OPT: ICF ou /incremental: no, que não implicam nenhum /EDITANDCONTINUE, será obter LNK4075.  Ver [/Z7, /Zi, /ZI (formato de informações de depuração)](../../build/reference/z7-zi-zi-debug-information-format.md) para obter mais informações.