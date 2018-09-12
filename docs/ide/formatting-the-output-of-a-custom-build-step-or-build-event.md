---
title: Formatando a saída de uma etapa de build personalizada ou um evento de build | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- builds [C++], build events
- custom build steps [C++], output format
- events [C++], build
- build events [C++], output format
- build steps [C++], output format
- builds [C++], custom build steps
ms.assetid: 92ad3e38-24d7-4b89-90e6-5a16f5f998da
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8a975951142c028ffcfb8ece870ab3ac2d2b60fc
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43203243"
---
# <a name="formatting-the-output-of-a-custom-build-step-or-build-event"></a>Formatando a saída de uma etapa de build personalizado ou evento de build

Se a saída de uma etapa de build personalizada ou um evento de build está formatada corretamente, os usuários podem obter os seguintes benefícios:

- Os avisos e erros são contados na janela de **Saída**.

- A saída é exibida na janela **Lista de Tarefas**.

- Se você clicar na saída da janela de **Saída**, o tópico apropriado será exibido.

- As operações F1 estão habilitadas na janela **Lista de Tarefas** ou na janela de **Saída**.

O formato da saída deve ser:

> {<em>nome do arquivo</em>**(**<em>número da linha</em> \[**,** <em>número da coluna</em>]**)** &#124; *nome da ferramenta*} **:** \[ <em>qualquer texto</em> ] {**error** &#124; **warning**} <em>código+número</em>**:**<em>cadeia de caracteres localizável</em> \[ <em>qualquer texto</em> ]

Sendo que:

- {*a* &#124; *b*} é a opção *a* ou *b*.

- \[<em>item</em>] é um parâmetro ou uma cadeia de caracteres opcional.

- O que está em **negrito** representa uma expressão literal.

Por exemplo:

> C:\\*sourcefile.cpp*(134) : error C2143: syntax error : missing ';' before '}'

> LINK: erro fatal LNK1104: não é possível abrir o arquivo '*somelib.lib*'

## <a name="see-also"></a>Consulte também

[Noções básicas sobre etapas e eventos compilação personalizada](../ide/understanding-custom-build-steps-and-build-events.md)