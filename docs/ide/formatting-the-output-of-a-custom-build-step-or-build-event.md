---
title: "Formatando a saída de uma etapa de compilação personalizada ou evento de compilação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 53720e93c7d45f1eaeb0e62749194720373bee1c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="formatting-the-output-of-a-custom-build-step-or-build-event"></a>Formatando a saída de uma etapa de build personalizado ou evento de build
Se a saída de uma etapa de compilação personalizada ou evento de compilação está formatada corretamente, os usuários podem obter os seguintes benefícios:  
  
-   Erros e avisos são contados no **saída** janela.  
  
-   Saída é exibida no **lista de tarefas** janela.  
  
-   Clicar na saída no **saída** janela exibe o tópico apropriado.  
  
-   F1 operações estão habilitadas no **lista de tarefas** janela ou **saída** janela.  
  
 O formato da saída deve ser:  
  
 {*filename* (*linha #* [, *coluna #*]) &#124; *toolname*} **:**  
  
 [*qualquer texto*] {**erro** &#124; **aviso**} *código # # #***:***cadeia de caracteres localizável*  
  
 [ *qualquer texto* ]  
  
 Sendo que:  
  
-   {*um* &#124; *b*} é uma opção do *um* ou *b*.  
  
-   [`ccc`] é um parâmetro ou uma cadeia de caracteres opcional.  
  
 Por exemplo:  
  
 C:\\*sourcefile.cpp*(134): erro C2143: erro de sintaxe: faltando ';' antes '}'  
  
 LINK: erro fatal LNK1104: não é possível abrir o arquivo '*somelib.lib*'  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas sobre etapas e eventos compilação personalizada](../ide/understanding-custom-build-steps-and-build-events.md)