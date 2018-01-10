---
title: 'Passo a passo: Testando um projeto (C++) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- project testing [C++]
- testing projects
- projects [C++], testing
ms.assetid: 88cdd377-c5c8-4201-889d-32f5653ebead
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2ba928d4a81252b76856273160af63ed8707e7e5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-testing-a-project-c"></a>Instruções passo a passo: testando um projeto (C++)
Quando você executar um programa em modo de depuração, você pode usar pontos de interrupção para pausar o programa para examinar o estado de variáveis e objetos.  
  
 Neste passo a passo, observe o valor de uma variável como o programa é executado e deduzir o motivo pelo qual o valor é não esperado.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Este passo a passo pressupõe que você entender os conceitos básicos da linguagem C++.  
  
-   Ele também pressupõe que você tenha concluído as orientações relacionadas anteriormente listados na [usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
### <a name="to-run-a-program-in-debug-mode"></a>Para executar um programa em modo de depuração  
  
1.  Abra TestGames.cpp para edição.  
  
2.  Selecione esta linha de código:  
  
     `Cardgame.solitaire(1);`  
  
3.  Para definir um ponto de interrupção nessa linha, na barra de menus, escolha **depurar**, **alternar ponto de interrupção**, ou escolha a tecla F9. Um círculo vermelho é exibido à esquerda da linha; indica que um ponto de interrupção está definido. Para remover um ponto de interrupção, você pode escolher o comando de menu ou a tecla F9 novamente.  
  
     Se você estiver usando um mouse, você também pode definir ou remover um ponto de interrupção clicando na margem esquerda.  
  
4.  Na barra de menus, escolha **depurar**, **iniciar depuração**, ou pressione a tecla F5.  
  
     Quando o programa atingir a linha que tem o ponto de interrupção, execução interrompe temporariamente, porque o programa está no modo de interrupção. Uma seta amarela à esquerda de uma linha de código indica que é a próxima linha a ser executado.  
  
5.  Para examinar o valor da `Cardgame::totalParticipants` variável, mova o ponteiro sobre `Cardgame` e, em seguida, movê-lo sobre o controle de expansão à esquerda da janela de dica de ferramenta. O nome da variável `totalParticipants` e seu valor de 12 são exibidos.  
  
     Abra o menu de atalho para o `Cardgame::totalParticipants` variável e, em seguida, escolha **Adicionar inspeção** para exibir essa variável no **inspecionar 1** janela. Você também pode selecionar uma variável e arraste-o para o **inspecionar 1** janela.  
  
6.  Para passar para a próxima linha de código, na barra de menus, escolha **depurar**, **passar por**, ou escolha a tecla F10.  
  
     O valor de `Cardgame::totalParticipants` no **inspecionar 1** janela agora é exibida como 13.  
  
7.  Abra o menu de atalho para o `return 0;` instrução e, em seguida, escolha **executar até o Cursor**. A seta amarela à esquerda dos pontos de código para a próxima instrução a ser executada.  
  
8.  O `Cardgame::totalParticipants` número diminua quando um Cardgame termina. Neste ponto, `Cardgame::totalParticipants` deve ser igual a 0 porque todas as instâncias de Cardgame tem sido excluídas, mas o **inspecionar 1** janela indica que `Cardgame::totalparticipants` é igual a 18. Isso indica que há um bug no código, que você pode detectar e corrigir Concluindo a próximo passo a passo, [passo a passo: depurando um projeto (C++)](../ide/walkthrough-debugging-a-project-cpp.md).  
  
9. Para parar o programa na barra de menus, escolha **depurar**, **parar depuração**, ou escolha o atalho de teclado Shift + F5.  
  
## <a name="next-steps"></a>Próximas etapas  
 **Anterior:** [passo a passo: Criando um projeto (C++)](../ide/walkthrough-building-a-project-cpp.md) &#124; **Próximo:**[passo a passo: depurando um projeto (C++)](../ide/walkthrough-debugging-a-project-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)