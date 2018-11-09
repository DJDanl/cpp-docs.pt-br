---
title: 'Instruções passo a passo: compilando um projeto (C++)'
ms.date: 09/14/2018
helpviewer_keywords:
- building projects [C++]
- projects [C++], building
- project building [C++]
ms.assetid: d459bc03-88ef-48d0-9f9a-82d17f0b6a4d
ms.openlocfilehash: 53f9d1ca823385c17bf2b235d844e40886092e44
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50618355"
---
# <a name="walkthrough-building-a-project-c"></a>Instruções passo a passo: compilando um projeto (C++)

Neste passo a passo, você introduzirá um erro de sintaxe do Visual C++ no código deliberadamente para saber o que é um erro de compilação e como corrigi-lo. Quando você compila o projeto, uma mensagem de erro indica qual é o problema e em que local ele ocorreu.

## <a name="prerequisites"></a>Pré-requisitos

- Este passo a passo pressupõe que você conheça os princípios básicos da linguagem C++.

- Também pressupõe que você tenha concluído os passos a passos relacionados anteriores listados em [Usando o IDE do Visual Studio para Desenvolvimento para Desktop com C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).

### <a name="to-fix-compilation-errors"></a>Para corrigir erros de compilação

1. Em Game.cpp, exclua o ponto e vírgula na última linha, de modo que ele fique parecido com a instrução:

    `return 0`

1. Na barra de menus, escolha **Compilar** > **Compilar Solução**.

1. Uma mensagem na janela **Lista de Erros** indica que houve um erro na compilação do projeto. A descrição é parecida com esta mensagem de erro:

    `error C2143: syntax error: missing ';' before '}'`

  Para ver informações de ajuda sobre esse erro, realce-o na janela **Lista de Erros** e escolha a tecla **F1**.

1. Adicione o ponto-e-vírgula novamente ao fim da linha que contém o erro de sintaxe:

   `return 0;`

1. Na barra de menus, escolha **Compilar** > **Compilar Solução**.

  Uma mensagem na janela de **Saída** indica que o projeto foi compilado com êxito.

    ```Output
    1>------ Build started: Project: Game, Configuration: Debug Win32 ------
    1>Game.cpp
    1>Game.vcxproj -> C:\Users\<username>\source\repos\Game\Debug\Game.exe
    ========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
    ```

## <a name="next-steps"></a>Próximas etapas

**Anterior:** [Passo a passo: trabalhando com projetos e soluções (C++)](../ide/walkthrough-working-with-projects-and-solutions-cpp.md)<br/>
**Próximo:** [Passo a passo: testando um projeto (C++)](../ide/walkthrough-testing-a-project-cpp.md)<br/>

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Compilando programas do C/C++](../build/building-c-cpp-programs.md)<br/>
