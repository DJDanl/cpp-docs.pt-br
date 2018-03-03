---
title: 'Passo a passo: Depurando um projeto (C++) | Microsoft Docs'
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
- projects [C++], debugging
- project debugging [C++]
- debugging projects
ms.assetid: a5cade77-ba51-4b03-a7a0-6897e3cd6a59
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6c9789a7deafacf09ad615f416a446da4eba8150
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-debugging-a-project-c"></a>Instruções passo a passo: depurando um projeto (C++)
Neste passo a passo, você deve modificar o programa para corrigir o problema que você descobertos quando você testar o projeto.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Este passo a passo pressupõe que você entender os conceitos básicos da linguagem C++.  
  
-   Ele também pressupõe que você tenha concluído as orientações relacionadas anteriormente listados na [usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
### <a name="to-fix-a-program-that-has-a-bug"></a>Para corrigir um programa que tenha um bug  
  
1.  Para ver o que ocorre quando um `Cardgame` objeto é destruído, exiba o destruidor para o `Cardgame` classe.  
  
     Na barra de menus, escolha **exibição**, **exibição de classe**.  
  
     No **exibição de classe** janela, expanda o **jogo** árvore do projeto e selecione o **Cardgame** classe para exibir os métodos e membros de classe.  
  
     Abra o menu de atalho para o **~Cardgame(void)** destruidor e, em seguida, escolha **ir para definição**.  
  
2.  Para diminuir o `totalParticipants` quando um Cardgame termina, adicione o seguinte código entre as chaves de abertura e fechamento do `Cardgame::~Cardgame` destruidor.  
  
     [!code-cpp[NVC_Walkthrough_Debugging_A_Project#110](../ide/codesnippet/CPP/walkthrough-debugging-a-project-cpp_1.cpp)]  
  
3.  O arquivo Cardgame.cpp deve se parecer com isso depois que você alterá-lo:  
  
     [!code-cpp[NVC_Walkthrough_Debugging_A_Project#111](../ide/codesnippet/CPP/walkthrough-debugging-a-project-cpp_2.cpp)]  
  
4.  Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
5.  Quando a compilação for concluída, executá-lo no modo de depuração, escolhendo **depurar**, **iniciar depuração** na barra de menus ou escolhendo a tecla F5. O programa faz uma pausa no primeiro ponto de interrupção.  
  
6.  Para depurar o programa, na barra de menus, escolha **depurar**, **passar por**, ou escolha a tecla F10.  
  
     Observe que depois de cada construtor Cardgame é executado, o valor de `totalParticipants` aumenta. Quando o `PlayGames` funcionando retorna, cada instância Cardgame sai do escopo e será excluída (e o destruidor é chamado), `totalParticipants` diminui. Antes de `return` instrução é executada, `totalParticipants` é igual a 0.  
  
7.  Continuar a depuração por meio do programa, até que ela sai ou deixá-lo a executar escolhendo **depurar**, **executar** na barra de menus ou escolhendo a tecla F5.  
  
## <a name="next-steps"></a>Próximas etapas  
 **Anterior:** [passo a passo: Testando um projeto (C++)](../ide/walkthrough-testing-a-project-cpp.md) &#124; **Próximo:**[passo a passo: Implantando o programa (C++)](../ide/walkthrough-deploying-your-program-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)