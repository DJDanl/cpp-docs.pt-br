---
title: 'Passo a passo: Criando um projeto (C++) | Microsoft Docs'
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
- building projects [C++]
- projects [C++], building
- project building [C++]
ms.assetid: d459bc03-88ef-48d0-9f9a-82d17f0b6a4d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 65d7a4bf7e4b3fd519911a2a127ec0ac2723b630
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-building-a-project-c"></a>Instruções passo a passo: compilando um projeto (C++)
Neste passo a passo, você deliberadamente apresentar um erro de sintaxe do Visual C++ em seu código para saber a aparência de um erro de compilação e como corrigi-lo. Quando você compila o projeto, uma mensagem de erro indica qual é o problema e qual ele ocorreu.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
-   Este passo a passo pressupõe que você entender os conceitos básicos da linguagem C++.  
  
-   Ele também pressupõe que você tenha concluído as orientações relacionadas anteriormente listados na [usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
### <a name="to-fix-compilation-errors"></a>Para corrigir erros de compilação  
  
1.  No TestGames.cpp, exclua o ponto e vírgula na última linha para que ele é semelhante a isto:  
  
     `return 0`  
  
2.  Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
3.  Uma mensagem no **lista de erros** janela indica que houve um erro na criação do projeto. A descrição pode ter esta aparência:  
  
     `error C2143: syntax error : missing ';' before '}'`  
  
     Para exibir informações de ajuda sobre este erro, realce-na **lista de erros** janela e, em seguida, escolha a tecla F1.  
  
4.  Adicione o ponto e vírgula para o fim da linha que contém o erro de sintaxe:  
  
     `return 0;`  
  
5.  Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
     Uma mensagem no **saída** janela indica que o projeto foi compilado com êxito.  
  
    ```Output  
    1>------ Build started: Project: Game, Configuration: Debug Win32 ------  
    1>  TestGames.cpp  
    1>  Game.vcxproj -> C:\Users\<username>\Documents\Visual Studio <version>\Projects\Game\Debug\Game.exe  
    ========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========  
    ```  
  
## <a name="next-steps"></a>Próximas etapas  
 **Anterior:** [passo a passo: Trabalhando com projetos e soluções (C++)](../ide/walkthrough-working-with-projects-and-solutions-cpp.md) &#124; **Próximo:**[passo a passo: Testando um projeto (C++)](../ide/walkthrough-testing-a-project-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)