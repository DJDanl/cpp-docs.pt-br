---
title: "Passo a passo: Trabalhando com projetos e soluções (C++) | Microsoft Docs"
ms.custom: 
ms.date: 12/13/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- solutions [C++]
- projects [C++], about projects
- projects [C++]
- solutions [C++], about solutions
ms.assetid: 93a3f290-e294-46e3-876e-e3084d9ae833
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a20c0ee933d49465a841b638a8260181d7175ac5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-working-with-projects-and-solutions-c"></a>Instruções passo a passo: trabalhando com projetos e soluções (C++)

Veja como criar um projeto em C++ no Visual Studio, adicionar código e, em seguida, compilar e executar o projeto. O projeto neste passo a passo é um programa que acompanha quantas pessoas estão jogando jogos de cartas diferentes.

No Visual Studio, o trabalho é organizado em projetos e soluções. Uma solução pode conter mais de um projeto, por exemplo, uma DLL e um executável que referencia essa DLL. Para obter mais informações, consulte [Soluções e projetos](/visualstudio/ide/solutions-and-projects-in-visual-studio).

## <a name="before-you-start"></a>Antes de começar

Para concluir este passo a passo, você precisará Visual Studio 2017 versão 15,3 ou posterior. Se você precisar de uma cópia, aqui está um guia curto: [suporte instalar C++ no Visual Studio](../build/vscpp-step-0-installation.md). Se você ainda não fez isso ainda, siga as próximas etapas após a instalação por meio do tutorial "Olá, mundo" para garantir que o Visual C++ está instalado corretamente e tudo funciona.

Isso será útil se você entende os conceitos básicos da linguagem C++ e sabe que um compilador, vinculador e depurador são usadas para. O tutorial também pressupõe que você está familiarizado com o Windows e como usar os menus, caixas de diálogo,

## <a name="create-a-project"></a>Criar um projeto

Para criar um projeto, escolha primeiro um modelo de tipo de projeto. Para cada tipo de projeto, o Visual Studio define as configurações do compilador e, dependendo do tipo — gera o código inicial que podem ser modificados posteriormente.

### <a name="to-create-a-project"></a>Para criar um projeto

1. Na barra de menus, escolha **arquivo > Novo > projeto**.

1. No painel esquerdo do **novo projeto** caixa de diálogo caixa, expanda **instalado** e selecione **Visual C++**, se ainda não estiver aberta.

1. Na lista de modelos instalados no painel central, selecione **aplicativo de Console do Windows**.

1. Insira um nome para o projeto no **nome** caixa. Para este exemplo, digite **jogo**.

   Você pode aceitar o local padrão no **local** lista suspensa, digite um local diferente ou escolha o **procurar** botão para navegar até um diretório onde você deseja salvar o projeto.

   Quando você cria um projeto, o Visual Studio coloca o projeto em uma solução. Por padrão, a solução tem o mesmo nome do projeto. Você pode alterar o nome no **nome da solução** caixa, mas para este exemplo, mantenha o nome padrão.

1. Escolha o botão **OK** para criar o projeto.

   Visual Studio cria a nova solução e os arquivos de projeto e abre o editor para o arquivo de código de origem Game.cpp que ela gerada.

## <a name="organize-projects-and-files"></a>Organizar projetos e arquivos

Você pode usar **Solution Explorer** para organizar e gerenciar projetos, arquivos e outros recursos em sua solução.

Esta parte do passo a passo mostra como adicionar uma classe ao projeto. Quando você adiciona a classe, o Visual Studio adiciona o h correspondente e arquivos. cpp. Você pode ver os resultados no **Gerenciador de soluções**.

### <a name="to-add-a-class-to-a-project"></a>Para adicionar uma classe a um projeto

1. Se o **Solution Explorer** janela não é exibida no Visual Studio, na barra de menus, escolha **exibição > Gerenciador de soluções**.

1. Em **Solution Explorer**, selecione o **jogo** projeto. Na barra de menus, escolha **projeto > Adicionar classe**.

1. No **Adicionar classe** caixa de diálogo, digite *Cardgame* no **nome da classe** caixa. Não altere os nomes de arquivo e as configurações padrão. Escolha o botão **OK**.

   O Visual Studio cria novos arquivos e os adiciona ao seu projeto. Você pode vê-los no **Solution Explorer** janela. Os arquivos Cardgame.h e Cardgame.cpp são abertos no editor.

1. Edite o arquivo Cardgame.h e fazer essas alterações:

   - Adicione dois membros de dados particulares após a chave de abertura da definição de classe.
      <!--      [!code-cpp[NVC_Walkthrough_Working_With_Projects#100](../ide/codesnippet/CPP/walkthrough-working-with-projects-and-solutions-cpp_1.h)] -->

      ```cpp
      int players;
      static int totalParticipants;
      ```

   - Modifique o construtor padrão que o Visual Studio gerou. Após o especificador de acesso `public:`, localize a linha com esta aparência:

      `Cardgame();`

      Modificar esse construtor para receber um parâmetro de tipo `int`, denominado *players*.

      <!--[!code-cpp[NVC_Walkthrough_Working_With_Projects#101](../ide/codesnippet/CPP/walkthrough-working-with-projects-and-solutions-cpp_2.h)]-->
      `Cardgame(int players);`

   - Após o destruidor padrão, adicione uma declaração embutido para um `static int` chamada de função de membro *GetParticipants* que não usa nenhum parâmetro e retorna o `totalParticipants` valor.

      <!--[!code-cpp[NVC_Walkthrough_Working_With_Projects#102](../ide/codesnippet/CPP/walkthrough-working-with-projects-and-solutions-cpp_3.h)]-->
      `static int GetParticipants() { return totalParticipants; }`

   O arquivo Cardgame.h deve ter esta aparência depois de alterado:

   <!--[!code-cpp[NVC_Walkthrough_Working_With_Projects#103](../ide/codesnippet/CPP/walkthrough-working-with-projects-and-solutions-cpp_4.h)]-->
   ```cpp
   #pragma once
   class Cardgame
   {
       int players;
       static int totalParticipants;
   public:
       Cardgame(int players);
       ~Cardgame(void);
       static int GetParticipants() { return totalParticipants; }
   };
   ```

   A linha `#pragma once` informa ao compilador para incluir o arquivo de cabeçalho somente uma vez. Para obter mais informações, consulte [quando](../preprocessor/once.md). Para obter informações sobre outras palavras-chave de C++ nesse arquivo de cabeçalho, consulte [classe](../cpp/class-cpp.md), [int](../cpp/fundamental-types-cpp.md), [estático](../cpp/storage-classes-cpp.md), e [público](../cpp/public-cpp.md).

1. Escolha o **Cardgame.cpp** guia na parte superior do painel de edição para abri-lo para edição.

1. Exclua tudo no arquivo e substitua-o por este código:

   <!--[!code-cpp[NVC_Walkthrough_Working_With_Projects#111](../ide/codesnippet/CPP/walkthrough-working-with-projects-and-solutions-cpp_5.cpp)]-->
   ```cpp
   #include "stdafx.h"
   #include "Cardgame.h"
   #include <iostream>

   using namespace std;

   int Cardgame::totalParticipants = 0;

   Cardgame::Cardgame(int players)
       : players(players)
   {
       totalParticipants += players;
       cout << players << " players have started a new game.  There are now "
            << totalParticipants << " players in total." << endl;
   }

   Cardgame::~Cardgame()
   {
   }
   ```

   > [!NOTE]
   > É possível usar o preenchimento automático quando estiver inserindo o código. Por exemplo, se você digitar esse código no teclado, você pode inserir *pl* ou *tot* e, em seguida, pressione Ctrl + Barra de espaços. Conclusão automática insere `players` ou `totalParticipants` para você.

## <a name="add-test-code-to-your-main-function"></a>Adicione o código de teste para a função principal

Adicione código ao seu aplicativo que verifica as novas funções.

### <a name="to-add-test-code-to-the-project"></a>Para adicionar o código de teste ao projeto

1. Na janela do editor Game.cpp, substitua o código existente com isso:

   <!--[!code-cpp[NVC_Walkthrough_Working_With_Projects#120](../ide/codesnippet/CPP/walkthrough-working-with-projects-and-solutions-cpp_6.cpp)]-->
   ```cpp
   // Game.cpp : Defines the entry point for the console application.
   //

   #include "stdafx.h"
   #include "Cardgame.h"
   #include <iostream>

   using namespace std;

   void PlayGames()
   {
       Cardgame bridge(4);
       Cardgame blackjack(8);
       Cardgame solitaire(1);
       Cardgame poker(5);
   }

   int main()
   {
       PlayGames();
       return 0;
   }
   ```
Esse código adiciona uma função de teste, `PlayGames`, para o código-fonte e chamadas no `main`. 

## <a name="build-and-run-your-app-project"></a>Compilar e executar seu projeto de aplicativo

Em seguida, compile o projeto e executar o aplicativo.

### <a name="to-build-and-run-the-project"></a>Para compilar e executar o projeto

1. Na barra de menus, escolha **Compilar > Compilar Solução**.

   Saída de uma compilação é exibida no **saída** janela. Se a compilação for bem-sucedida, o resultado será semelhante a este:

   ```Output
   1>------ Build started: Project: Game, Configuration: Debug Win32 ------
   1>  stdafx.cpp
   1>  Game.cpp
   1>  Cardgame.cpp
   1>  Generating Code...
   1>  Game.vcxproj -> C:\Users\username\Source\Repos\Game\Debug\Game.exe
   ========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
   ```

   O **saída** janela pode mostrar etapas diferentes, dependendo da configuração de compilação, mas se a compilação de projeto for bem-sucedida, a última linha deve ser semelhante à saída mostrada.

   Se a compilação não foi bem-sucedida, compare seu código para o código que é mostrado nas etapas anteriores.

1. Para executar o projeto, na barra de menus, escolha **Depurar > Iniciar sem depuração**. Aparece uma janela do console e a saída deve ser semelhante a esta:

   ```Output
   4 players have started a new game.  There are now 4 players in total.
   8 players have started a new game.  There are now 12 players in total.
   1 players have started a new game.  There are now 13 players in total.
   5 players have started a new game.  There are now 18 players in total.
   ```
Pressione uma tecla para fechar a janela do console.

Parabéns, você construiu com êxito uma solução e projeto de aplicativo. Continue o passo a passo para saber mais sobre como criar projetos de código C++ no Visual Studio.

## <a name="next-steps"></a>Próximas etapas

**Anterior:** [usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
**Em seguida:** [passo a passo: Criando um projeto (C++)](../ide/walkthrough-building-a-project-cpp.md).

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)  
[Compilando programas do C/C++](../build/building-c-cpp-programs.md)