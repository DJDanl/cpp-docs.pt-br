---
title: "Instru&#231;&#245;es passo a passo: depurando um projeto (C++) | Microsoft Docs"
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
  - "depurando projetos"
  - "depuração de projetos [C++]"
  - "projetos [C++], depuração"
ms.assetid: a5cade77-ba51-4b03-a7a0-6897e3cd6a59
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: depurando um projeto (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Nessa explicação passo a passo, você altera o programa para corrigir o problema que você descobrisse quando você testou o projeto.  
  
## Pré-requisitos  
  
-   Esta explicação passo a passo pressupõe que você compreenda os fundamentos da linguagem C\+\+.  
  
-   Também pressupõe que você tenha concluído os passo a passo relacionados anteriormente, que estão listados em [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C\+\+](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
### Para corrigir um programa que tenha um bug  
  
1.  Para ver o que ocorre quando um objeto de `Cardgame` é destruído, exibir o destrutor para a classe de `Cardgame` .  
  
     Na barra de menus, escolha **Modo de Visualização**, **Modo de Exibição de Classe**.  
  
     Na janela de **Modo de Exibição de Classe** , expanda a árvore de projeto de **Jogo** e selecione a classe de **Cardgame** para exibir os membros e métodos da classe.  
  
     Abra o menu de atalho para o destrutor de **~Cardgame \(vácuo\)** e então escolha **Ir Para Definição**.  
  
2.  Para reduzir `totalParticipants` quando um Cardgame finaliza, adicione o seguinte código entre a chaves de abertura e fechamento do destrutor de `Cardgame::~Cardgame` .  
  
     [!code-cpp[NVC_Walkthrough_Debugging_A_Project#110](../ide/codesnippet/CPP/walkthrough-debugging-a-project-cpp_1.cpp)]  
  
3.  O arquivo de Cardgame.cpp deve se parecer com a este depois que você altera o:  
  
     [!code-cpp[NVC_Walkthrough_Debugging_A_Project#111](../ide/codesnippet/CPP/walkthrough-debugging-a-project-cpp_2.cpp)]  
  
4.  Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
5.  Quando a compilação terminar, execute\-a no modo de depuração escolhendo **Depurar**, **Iniciar Depuração** na barra de menus, ou escolhendo tecla F5.  O programa pára no ponto de interrupção.  
  
6.  Para percorrer o programa, na barra de menus, escolha **Depurar**, **Depuração Parcial**, ou escolha tecla F10.  
  
     Observe que depois que cada construtor de Cardgame é executado, o valor de `totalParticipants` aumenta.  Quando a função de `PlayGames` retornar, porque cada instância de Cardgame sai do escopo e é excluída \(e o destrutor é chamado\), `totalParticipants` diminui.  Imediatamente antes da declaração de `return` é executada, os igual 0 de `totalParticipants` .  
  
7.  Continue a depuração com o programa até que sair, ou deixou\-a executar escolhendo **Depurar**, **Executar** na barra de menus, ou escolhendo tecla F5.  
  
## Próximas etapas  
 **Anterior:** [Instruções passo a passo: testando um projeto \(C\+\+\)](../ide/walkthrough-testing-a-project-cpp.md) &#124; **Próxima:** [Instruções passo a passo: implantando o programa \(C\+\+\)](../ide/walkthrough-deploying-your-program-cpp.md)  
  
## Consulte também  
 [Visual C\+\+ Guided Tour](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)   
 [DELETE\_PENDING\_Building and Debugging](http://msdn.microsoft.com/pt-br/9f6ba537-5ea0-46fb-b6ba-b63d657d84f1)