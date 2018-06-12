---
title: 'Passo a passo: Testando um projeto (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- project testing [C++]
- testing projects
- projects [C++], testing
ms.assetid: 88cdd377-c5c8-4201-889d-32f5653ebead
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3a9455fa9bf3c9f903f5018a1263978913aa35b2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33333558"
---
# <a name="walkthrough-testing-a-project-c"></a>Instruções passo a passo: testando um projeto (C++)
Ao executar um programa no modo de Depuração, você pode usar pontos de interrupção para pausar o programa a fim de examinar o estado de variáveis e objetos.  
  
 Neste passo a passo, você observará o valor de uma variável durante a execução do programa e deduzirá o motivo pelo qual o valor não é o esperado.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Este passo a passo pressupõe que você conheça os princípios básicos da linguagem C++.  
  
-   Também pressupõe que você tenha concluído os passos a passos relacionados anteriores listados em [Usando o IDE do Visual Studio para desenvolvimento para desktop com C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
### <a name="to-run-a-program-in-debug-mode"></a>Para executar o programa no modo de Depuração  
  
1.  Abra TestGames.cpp para edição.  
  
2.  Selecione esta linha de código:  
  
     `Cardgame.solitaire(1);`  
  
3.  Para definir um ponto de interrupção nessa linha, na barra de menus, escolha **Depurar**, **Ativar/Desativar Ponto de Interrupção** ou escolha a tecla F9. Um círculo vermelho é exibido à esquerda da linha; ele indica que um ponto de interrupção está definido. Para remover um ponto de interrupção, escolha o comando de menu ou a tecla F9 novamente.  
  
     Caso esteja usando um mouse, defina ou remova também um ponto de interrupção clicando na margem esquerda.  
  
4.  Na barra de menus, escolha **Depurar**, **Iniciar Depuração** ou pressione a tecla F5.  
  
     Quando o programa atinge a linha que tem o ponto de interrupção, a execução é interrompida temporariamente, porque o programa está no modo de Interrupção. Uma seta amarela à esquerda de uma linha de código indica que ela é a próxima linha a ser executada.  
  
5.  Para examinar o valor da variável `Cardgame::totalParticipants`, mova o ponteiro sobre `Cardgame` e, em seguida, mova-o sobre o controle de expansão à esquerda da janela de dica de ferramenta. O nome da variável `totalParticipants` e seu valor 12 são exibidos.  
  
     Abra o menu de atalho da variável `Cardgame::totalParticipants` e, em seguida, escolha **Adicionar Inspeção** para exibir essa variável na janela **Inspeção 1**. Selecione também uma variável e arraste-a para a janela **Inspeção 1**.  
  
6.  Para passar para a próxima linha de código, na barra de menus, escolha **Depurar**, **Depuração Parcial** ou escolha a tecla F10.  
  
     O valor de `Cardgame::totalParticipants` na janela **Inspeção 1** agora é exibido como 13.  
  
7.  Abra o menu de atalho da instrução `return 0;` e, em seguida, escolha **Executar até o Cursor**. A seta amarela à esquerda do código aponta para a próxima instrução a ser executada.  
  
8.  O número `Cardgame::totalParticipants` deve diminuir quando um Cardgame é encerrado. Neste ponto, `Cardgame::totalParticipants` deve ser igual a 0 porque todas as instâncias de Cardgame foram excluídas, mas a janela **Inspeção 1** indica que `Cardgame::totalparticipants` é igual a 18. Isso indica que há um bug no código, que você pode detectar e corrigir concluindo o próximo passo a passo, [Passo a passo: Depurando um projeto (C++)](../ide/walkthrough-debugging-a-project-cpp.md).  
  
9. Para interromper o programa, na barra de menus, escolha **Depurar**, **Parar Depuração** ou escolha o atalho de teclado Shift+F5.  
  
## <a name="next-steps"></a>Próximas etapas  
 **Anterior:** [Passo a passo: Compilando um projeto (C++)](../ide/walkthrough-building-a-project-cpp.md) &#124; **Próximo:**[Passo a passo: Depurando um projeto (C++)](../ide/walkthrough-debugging-a-project-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)