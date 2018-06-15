---
title: 'Passo a passo: Depurando um projeto (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- projects [C++], debugging
- project debugging [C++]
- debugging projects
ms.assetid: a5cade77-ba51-4b03-a7a0-6897e3cd6a59
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ecfda5e2549b3aa9be1f0471e301cc2a21c6fd5a
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33340028"
---
# <a name="walkthrough-debugging-a-project-c"></a>Instruções passo a passo: depurando um projeto (C++)
Neste passo a passo, você modificará o programa para corrigir o problema descoberto durante o teste do projeto.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Este passo a passo pressupõe que você conheça os princípios básicos da linguagem C++.  
  
-   Também pressupõe que você tenha concluído os passos a passos relacionados anteriores listados em [Usando o IDE do Visual Studio para desenvolvimento para desktop com C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
### <a name="to-fix-a-program-that-has-a-bug"></a>Para corrigir um programa com um bug  
  
1.  Para ver o que ocorre quando um objeto `Cardgame` é destruído, exiba o destruidor da classe `Cardgame`.  
  
     Na barra de menus, escolha **Exibir**, **Modo de Exibição de Classe**.  
  
     Na janela **Modo de Exibição de Classe**, expanda a árvore do projeto **Game** e selecione a classe **Cardgame** para exibir os métodos e os membros da classe.  
  
     Abra o menu de atalho do destruidor **~Cardgame(void)** e, em seguida, escolha **Ir para definição**.  
  
2.  Para diminuir o `totalParticipants` quando um Cardgame é encerrado, adicione o código a seguir entre as chaves de abertura e fechamento do destruidor `Cardgame::~Cardgame`.  
  
     [!code-cpp[NVC_Walkthrough_Debugging_A_Project#110](../ide/codesnippet/CPP/walkthrough-debugging-a-project-cpp_1.cpp)]  
  
3.  O arquivo Cardgame.cpp deve ter esta aparência depois de alterado:  
  
     [!code-cpp[NVC_Walkthrough_Debugging_A_Project#111](../ide/codesnippet/CPP/walkthrough-debugging-a-project-cpp_2.cpp)]  
  
4.  Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
5.  Quando o build for concluído, execute-o no modo de Depuração escolhendo **Depuração**, **Iniciar Depuração** na barra de menus ou escolhendo a tecla F5. O programa pausa no primeiro ponto de interrupção.  
  
6.  Para executar o programa em etapas, na barra de menus, escolha **Depuração**, **Depuração Parcial** ou escolha a tecla F10.  
  
     Observe que, após a execução de cada construtor de Cardgame, o valor de `totalParticipants` aumenta. Quando a função `PlayGames` é retornada, cada instância de Cardgame sai do escopo e é excluída (e o destruidor é chamado), diminuindo `totalParticipants`. Logo antes da execução da instrução `return`, `totalParticipants` é igual a 0.  
  
7.  Continue executando o programa em etapas até que ele seja encerrado ou deixe-o em execução escolhendo **Depuração**, **Executar** na barra de menus ou escolhendo a tecla F5.  
  
## <a name="next-steps"></a>Próximas etapas  
 **Anterior:** [Passo a passo: Testando um projeto (C++)](../ide/walkthrough-testing-a-project-cpp.md) &#124; **Próximo:**[Passo a passo: Implantando o programa (C++)](../ide/walkthrough-deploying-your-program-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)