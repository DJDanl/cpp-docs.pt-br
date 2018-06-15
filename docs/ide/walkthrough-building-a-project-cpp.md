---
title: 'Passo a passo: Compilando um projeto (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- building projects [C++]
- projects [C++], building
- project building [C++]
ms.assetid: d459bc03-88ef-48d0-9f9a-82d17f0b6a4d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0c8d04dc3692076b867302af0e793eaac7ed25cb
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33332449"
---
# <a name="walkthrough-building-a-project-c"></a>Instruções passo a passo: compilando um projeto (C++)
Neste passo a passo, você introduzirá um erro de sintaxe do Visual C++ no código deliberadamente para saber o que é um erro de compilação e como corrigi-lo. Quando você compila o projeto, uma mensagem de erro indica qual é o problema e em que local ele ocorreu.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Este passo a passo pressupõe que você conheça os princípios básicos da linguagem C++.  
  
-   Também pressupõe que você tenha concluído os passos a passos relacionados anteriores listados em [Usando o IDE do Visual Studio para desenvolvimento para desktop com C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
### <a name="to-fix-compilation-errors"></a>Para corrigir erros de compilação  
  
1.  Em TestGames.cpp, exclua o ponto-e-vírgula na última linha, de modo que ele fique parecido com isto:  
  
     `return 0`  
  
2.  Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
3.  Uma mensagem na janela **Lista de Erros** indica que houve um erro na compilação do projeto. A descrição é parecida com esta:  
  
     `error C2143: syntax error : missing ';' before '}'`  
  
     Para exibir informações da Ajuda sobre este erro, realce-o na janela **Lista de Erros** e, em seguida, escolha a tecla F1.  
  
4.  Adicione o ponto-e-vírgula novamente ao fim da linha que contém o erro de sintaxe:  
  
     `return 0;`  
  
5.  Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
     Uma mensagem na janela de **Saída** indica que o projeto foi compilado com êxito.  
  
    ```Output  
    1>------ Build started: Project: Game, Configuration: Debug Win32 ------  
    1>  TestGames.cpp  
    1>  Game.vcxproj -> C:\Users\<username>\Documents\Visual Studio <version>\Projects\Game\Debug\Game.exe  
    ========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========  
    ```  
  
## <a name="next-steps"></a>Próximas etapas  
 **Anterior:** [Passo a passo: Trabalhando com projetos e soluções (C++)](../ide/walkthrough-working-with-projects-and-solutions-cpp.md) &#124; **Próximo:**[Passo a passo: Testando um projeto (C++)](../ide/walkthrough-testing-a-project-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)