---
title: Formatando a saída de uma etapa de compilação personalizada ou evento de compilação
ms.date: 08/27/2018
helpviewer_keywords:
- builds [C++], build events
- custom build steps [C++], output format
- events [C++], build
- build events [C++], output format
- build steps [C++], output format
- builds [C++], custom build steps
ms.assetid: 92ad3e38-24d7-4b89-90e6-5a16f5f998da
ms.openlocfilehash: 09bf8485a352d6ec2c1297f8a1be508cb7476c31
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169819"
---
# <a name="formatting-the-output-of-a-custom-build-step-or-build-event"></a>Formatando a saída de uma etapa de compilação personalizada ou evento de compilação

Se a saída de uma etapa de build personalizada ou um evento de build está formatada corretamente, os usuários podem obter os seguintes benefícios:

- Os avisos e erros são contados na janela de **Saída**.

- A saída é exibida na janela **Lista de Tarefas**.

- Se você clicar na saída da janela de **Saída**, o tópico apropriado será exibido.

- As operações F1 estão habilitadas na janela **Lista de Tarefas** ou na janela de **Saída**.

O formato da saída deve ser:

> {<em>filename</em> **(** <em>linha #</em> \[ **,** <em>coluna #</em>] **)** &#124; *ToolName*} **:** \[ <em>qualquer texto</em> ] {**error** &#124; **aviso**de erro} <em>código + número</em> **:** <em>cadeia de caracteres localizável</em> \[ <em>qualquer texto</em> ]

Em que:

- {*a* &#124; *b*} é a opção *a* ou *b*.

- \[<em>item</em>] é um parâmetro ou uma cadeia de caracteres opcional.

- O que está em **negrito** representa uma expressão literal.

Por exemplo:

> C:\\*sourcefile.cpp*(134) : error C2143: syntax error : missing ';' before '}'
>
> LINK: erro fatal LNK1104: não é possível abrir o arquivo '*somelib.lib*'

## <a name="see-also"></a>Confira também

[Noções básicas sobre etapas e eventos de build personalizados](understanding-custom-build-steps-and-build-events.md)
