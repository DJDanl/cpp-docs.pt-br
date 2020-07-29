---
title: 'Instruções passo a passo: depurando um projeto (C++)'
ms.date: 04/25/2019
helpviewer_keywords:
- projects [C++], debugging
- project debugging [C++]
- debugging projects
ms.assetid: a5cade77-ba51-4b03-a7a0-6897e3cd6a59
ms.openlocfilehash: 61433213619c16caf67de905a6da93c7360db298
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219671"
---
# <a name="walkthrough-debugging-a-project-c"></a>Instruções passo a passo: depurando um projeto (C++)

Neste passo a passo, você modificará o programa para corrigir o problema encontrado durante o teste do projeto.

## <a name="prerequisites"></a>Pré-requisitos

- Este passo a passo pressupõe que você conheça os princípios básicos da linguagem C++.

- Também pressupõe que você tenha concluído os passos a passos relacionados anteriores listados em [Usando o IDE do Visual Studio para Desenvolvimento para Desktop com C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).

### <a name="to-fix-a-program-that-has-a-bug"></a>Para corrigir um programa com um bug

1. Para ver o que ocorre quando um objeto `Cardgame` é destruído, exiba o destruidor da classe `Cardgame`.

   Na barra de menus, escolha **Exibir**  >  **modo de exibição de classe**.

   Na janela **Modo de Exibição de Classe**, expanda a árvore do projeto **Game** e selecione a classe **Cardgame** para exibir os métodos e os membros da classe.

   Abra o menu de atalho do destruidor **~Cardgame(void)** e, em seguida, escolha **Ir para definição**.

1. Para diminuir o `totalParticipants` quando um Cardgame é encerrado, adicione o código a seguir entre as chaves de abertura e fechamento do destruidor `Cardgame::~Cardgame`.

   [!code-cpp[NVC_Walkthrough_Debugging_A_Project#110](../ide/codesnippet/CPP/walkthrough-debugging-a-project-cpp_1.cpp)]

1. O arquivo Cardgame.cpp deve ter a aparência do código abaixo depois de alterado:

   [!code-cpp[NVC_Walkthrough_Debugging_A_Project#111](../ide/codesnippet/CPP/walkthrough-debugging-a-project-cpp_2.cpp)]

1. Na barra de menus, escolha **Compilar**compilar  >  **solução**.

1. Quando a compilação for concluída, execute-a no modo de depuração escolhendo **depurar**  >  **Iniciar Depuração** na barra de menus ou escolhendo a tecla **F5** . O programa pausa no primeiro ponto de interrupção.

1. Para percorrer o programa, na barra de menus, escolha **depurar**  >  **etapa acima**ou escolha a tecla **F10** .

   Observe que, após a execução de cada construtor `Cardgame`, o valor de `totalParticipants` aumenta. Quando a função `PlayGames` é retornada, à medida que cada instância `Cardgame` sai do escopo e é excluída (e o destruidor é chamado), `totalParticipants` diminui. Logo antes da **`return`** execução da instrução, é `totalParticipants` igual a 0.

1. Continue percorrendo o programa até que ele saia ou deixe-o em execução escolhendo **depurar**  >  **executar** na barra de menus ou escolhendo a tecla **F5** .

## <a name="next-steps"></a>Próximas etapas

**Anterior:** [Passo a passo: testando um projeto (C++)](../ide/walkthrough-testing-a-project-cpp.md)<br/>
**Próximo:** [Passo a passo: implantando seu programa (C++)](../ide/walkthrough-deploying-your-program-cpp.md)

## <a name="see-also"></a>Confira também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Sistemas de build e projetos](../build/projects-and-build-systems-cpp.md)<br/>
