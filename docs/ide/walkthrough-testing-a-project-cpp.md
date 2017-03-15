---
title: "Instru&#231;&#245;es passo a passo: testando um projeto (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "teste de projeto [C++]"
  - "projetos [C++], testando"
  - "testando projetos"
ms.assetid: 88cdd377-c5c8-4201-889d-32f5653ebead
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: testando um projeto (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao executar um programa em modo de depuração, você pode usar pontos de interrupção para pausar o programa a fim de examinar o estado das variáveis e dos objetos.  
  
 Nesse passo a passo, você inspeciona o valor de uma variável enquanto o programa é executado e deduz porque o valor não é o que você espera.  
  
## Pré-requisitos  
  
-   Esta explicação passo a passo pressupõe que você compreenda os fundamentos da linguagem C\+\+.  
  
-   Também pressupõe que você tenha concluído os passo a passo relacionados anteriormente, que estão listados em [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C\+\+](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
### Para executar um programa no modo de depuração  
  
1.  Abra TestGames.cpp para edição.  
  
2.  Selecione esta linha de código:  
  
     `Cardgame.solitaire(1);`  
  
3.  Para definir um ponto de interrupção na linha, na barra de menus, escolha **Depurar**, **Alternar Ponto de Interrupção**, ou use a tecla F9.  Um círculo vermelho aparece à esquerda da linha; ele indica que um ponto de interrupção está definido.  Para remover um ponto de interrupção, você pode escolher o comando de menu ou a tecla F9 novamente.  
  
     Se você estiver usando um mouse, você também poderá definir ou remover um ponto de interrupção ao clicar na margem esquerda.  
  
4.  Na barra de menus, escolha **Depurar**, **Iniciar Depuração** ou aperte a tecla F5.  
  
     Quando o programa atinge a linha que tem o ponto de interrupção, a execução para temporariamente, pois o programa fica no modo de interrupção.  Uma seta amarela à esquerda de uma linha de código indica que é a próxima linha a ser executada.  
  
5.  Para examinar o valor da variável `Cardgame::totalParticipants`, mova o ponteiro sobre `Cardgame` e então mova\-o sobre o controle de expansão à esquerda da janela de dica de ferramenta.  O nome de variável `totalParticipants` e seu valor 12 são exibidos.  
  
     Abra o menu de atalho para a variável `Cardgame::totalParticipants` e então escolha **Adicionar Inspeção** para exibir a variável na janela **Inspeção 1**.  Você também pode selecionar uma variável e arrastá\-la para a janela **Inspeção 1**.  
  
6.  Para ir para a próxima linha de código, na barra de menus, selecione **Depurar**, **Depuração Parcial**, ou use a tecla F10.  
  
     O valor `Cardgame::totalParticipants` na janela **Inspeção 1** é exibido agora como 13.  
  
7.  Abra o menu de atalho do projeto para a instrução `return 0;` e então escolha **Executar para Cursor**.  A seta amarela à esquerda do código aponta para a próxima instrução a ser executada.  
  
8.  O número `Cardgame::totalParticipants` deve diminuir quando um Cardgame é terminado.  Neste ponto, `Cardgame::totalParticipants` deve ser igual a 0 porque todas as instâncias de Cardgame foram excluídas, mas a janela **Inspeção 1** indica que o `Cardgame::totalparticipants` é igual a 18.  Isso indica que há um bug no código, que você pode detectar e corrigir concluindo a próxima explicação passo a passo, [Instruções passo a passo: depurando um projeto \(C\+\+\)](../ide/walkthrough-debugging-a-project-cpp.md).  
  
9. Para interromper o programa, na barra de menus, selecione **Depurar**, **Parar Depuração**, ou use o atalho de teclado Shift\+F5.  
  
## Próximas etapas  
 **Anterior:** [Instruções passo a passo: compilando um projeto \(C\+\+\)](../ide/walkthrough-building-a-project-cpp.md) &#124; **Próxima:** [Instruções passo a passo: depurando um projeto \(C\+\+\)](../ide/walkthrough-debugging-a-project-cpp.md)  
  
## Consulte também  
 [Visual C\+\+ Guided Tour](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)   
 [DELETE\_PENDING\_Building and Debugging](http://msdn.microsoft.com/pt-br/9f6ba537-5ea0-46fb-b6ba-b63d657d84f1)