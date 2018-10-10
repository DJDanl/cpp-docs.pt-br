---
title: 'Passo a passo: Depurando um projeto (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 09/14/2018
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
ms.openlocfilehash: 04bec9c0de7734ae2c78dd3e9c124eac3d0a55d8
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48234302"
---
# <a name="walkthrough-debugging-a-project-c"></a>Instruções passo a passo: depurando um projeto (C++)

Neste passo a passo, você modificará o programa para corrigir o problema encontrado durante o teste do projeto.

## <a name="prerequisites"></a>Pré-requisitos

- Este passo a passo pressupõe que você conheça os princípios básicos da linguagem C++.

- Também pressupõe que você tenha concluído os passos a passos relacionados anteriores listados em [Usando o IDE do Visual Studio para Desenvolvimento para Desktop com C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).

### <a name="to-fix-a-program-that-has-a-bug"></a>Para corrigir um programa com um bug

1. Para ver o que ocorre quando um objeto `Cardgame` é destruído, exiba o destruidor da classe `Cardgame`.

   Na barra de menus, escolha **Exibir** > **Modo de Exibição de Classe**.

   Na janela **Modo de Exibição de Classe**, expanda a árvore do projeto **Game** e selecione a classe **Cardgame** para exibir os métodos e os membros da classe.

   Abra o menu de atalho do destruidor **~Cardgame(void)** e, em seguida, escolha **Ir para definição**.

1. Para diminuir o `totalParticipants` quando um Cardgame é encerrado, adicione o código a seguir entre as chaves de abertura e fechamento do destruidor `Cardgame::~Cardgame`.

     [!code-cpp[NVC_Walkthrough_Debugging_A_Project#110](../ide/codesnippet/CPP/walkthrough-debugging-a-project-cpp_1.cpp)]

1. O arquivo Cardgame.cpp deve ter a aparência do código abaixo depois de alterado:

     [!code-cpp[NVC_Walkthrough_Debugging_A_Project#111](../ide/codesnippet/CPP/walkthrough-debugging-a-project-cpp_2.cpp)]

1. Na barra de menus, escolha **Compilar** > **Compilar Solução**.

1. Quando o build for concluído, execute-o no modo de Depuração escolhendo **Depurar** > **Iniciar depuração** na barra de menus ou escolhendo a tecla **F5**. O programa pausa no primeiro ponto de interrupção.

1. Para executar programa em etapas, na barra de menus, escolha **Depurar** > **Depuração Parcial** ou escolha a tecla **F10**.

   Observe que, após a execução de cada construtor `Cardgame`, o valor de `totalParticipants` aumenta. Quando a função `PlayGames` é retornada, à medida que cada instância `Cardgame` sai do escopo e é excluída (e o destruidor é chamado), `totalParticipants` diminui. Logo antes da execução da instrução `return`, `totalParticipants` é igual a 0.

1. Continue executando o programa em etapas até que ele seja encerrado ou deixe-o em execução escolhendo **Depurar** > **Executar** na barra de menus ou escolhendo a tecla **F5**.

## <a name="next-steps"></a>Próximas etapas

**Anterior:** [Passo a passo: testando um projeto (C++)](../ide/walkthrough-testing-a-project-cpp.md)<br/>
**Próximo:** [Passo a passo: implantando seu programa (C++)](../ide/walkthrough-deploying-your-program-cpp.md)<br/>

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Compilando programas do C/C++](../build/building-c-cpp-programs.md)<br/>
