---
title: 'Passo a passo: Criar e usar sua própria biblioteca de vínculo dinâmico (C++) | Microsoft Docs'
ms.custom: conceptual
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- libraries [C++], DLLs
- DLLs [C++], walkthroughs
ms.assetid: 3ae94848-44e7-4955-bbad-7d40f493e941
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5175d89925ddc09fdcd552aa57d2967071e750f7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46376961"
---
# <a name="walkthrough-create-and-use-your-own-dynamic-link-library-c"></a>Passo a passo: Criar e usar sua própria biblioteca de vínculo dinâmico (C++)

Este passo a passo mostra como usar o IDE do Visual Studio para criar sua própria biblioteca de vínculo dinâmico (DLL) escrita em C++ e, em seguida, usá-la de outro aplicativo C++. DLLs são um dos tipos mais úteis dos componentes do Windows. Você pode usá-los como uma maneira de compartilhar código e recursos, para reduzir o tamanho de seus aplicativos e para torná-lo mais fácil de serviço e estenda seus aplicativos. Neste passo a passo, você cria uma DLL que implementa algumas funções matemáticas e, em seguida, cria um aplicativo de console que usa as funções da DLL. Ao longo do caminho, você obter uma introdução a algumas das técnicas de programação e convenções usadas nas DLLs do Windows.

Este passo a passo apresenta estas tarefas:

- Crie um projeto de DLL no Visual Studio.

- Adicione variáveis e funções exportadas para a DLL.

- Crie um projeto de aplicativo de console no Visual Studio.

- Use as funções e variáveis importadas da DLL no aplicativo de console.

- Execute o aplicativo concluído.

Como uma biblioteca vinculada estaticamente, uma DLL _exporta_ variáveis, funções e recursos por nome e o seu aplicativo _importa_ esses nomes para usar essas variáveis, funções e recursos. Ao contrário de uma biblioteca vinculada estaticamente, o Windows se conecta as importações em seu aplicativo para as exportações em uma DLL em tempo de carga ou em tempo de execução, em vez de conectá-las em tempo de vinculação. Windows requer que informações adicionais que não faz parte do modelo de compilação C++ padrão para fazer essas conexões. O compilador do Visual C++ implementa algumas extensões específicas da Microsoft para C++ para fornecer essas informações extras. À medida que avançarmos, vamos explicar essas extensões.

Este passo a passo cria duas soluções do Visual Studio; uma que cria a DLL e outra que compila o aplicativo cliente. A DLL usa a convenção de chamada de C para que ele pode ser chamado de aplicativos criados usando outras linguagens, desde que a plataforma e chamar e convenções de vinculação coincidam. O aplicativo de cliente usa _vinculação implícita_, em que o Windows vincula o aplicativo para a DLL no tempo de carregamento. Isso permite que o aplicativo chamar as funções fornecidas pelo DLL assim como as funções em uma biblioteca vinculada estaticamente.

Este passo a passo não cobre algumas situações comuns. Ele não mostra o uso de DLLs em C++ por outras linguagens de programação. Ele não mostra como criar uma DLL somente recurso. Ele também não mostra o uso da vinculação explícita para carregar DLLs em tempo de execução em vez de em tempo de carregamento. Fique tranquilo, você pode usar o Visual C++ para fazer todas essas coisas. Para obter links para obter mais informações sobre DLLs, consulte [DLLs no Visual C++](../build/dlls-in-visual-cpp.md). Para obter mais informações sobre vinculação implícita e explícita de vinculação, consulte [determinar qual vincular método Use](../build/linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use). Para obter informações sobre como criar DLLs em C++ para uso com linguagens de programação que usam convenções de vinculação da linguagem C, consulte [exportar funções de C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md). Para obter informações sobre como criar DLLs para uso com linguagens .NET, consulte [chamando funções de DLL de aplicativos Visual Basic](../build/calling-dll-functions-from-visual-basic-applications.md).

Este passo a passo usa o Visual Studio 2017, mas o código e a maioria das instruções é aplicáveis a versões anteriores. As etapas para criar novos projetos alterado a partir do Visual Studio 2017 versão 15.3. Este passo a passo descreve como criar projetos para versões mais recentes e anteriores. Procure as etapas que correspondem à sua versão do Visual Studio.

## <a name="prerequisites"></a>Pré-requisitos

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. Recomendamos o Windows 10 para uma melhor experiência de desenvolvimento.

- Uma cópia do Visual Studio 2017. Para obter informações sobre como baixar e instalar o Visual Studio, consulte [instalar o Visual Studio 2017](/visualstudio/install/install-visual-studio). Ao executar o instalador, certifique-se de que o **desenvolvimento para Desktop com C++** carga de trabalho está marcada. Não se preocupe se você não instalou essa carga de trabalho quando você instalou o Visual Studio. Você pode executar o instalador novamente e instale-o agora.

   ![Desenvolvimento para desktop com C++](media/desktop-development-with-cpp.png "desenvolvimento para Desktop com C++")

- Um entendimento dos fundamentos de como usar o IDE do Visual Studio. Se você já usou os aplicativos da área de trabalho do Windows antes, você provavelmente pode manter-se. Para obter uma introdução, consulte [tour pelos recursos do IDE do Visual Studio](/visualstudio/ide/visual-studio-ide).

- Uma compreensão de suficiente dos fundamentos da linguagem C++ acompanhá-los. Não se preocupe, não fazemos nada muito complicado.

## <a name="create-the-dll-project"></a>Criar o projeto DLL

Neste conjunto de tarefas, crie um projeto para a sua DLL, adicione o código e compilá-lo. Para começar, inicie o IDE do Visual Studio e entrar se você precisar. As instruções para o Visual Studio 2017 versão 15.3 vir primeiros. Instruções para versões anteriores posteriormente, então pule se for necessário.

### <a name="to-create-a-dll-project-in-visual-studio-2017-version-153-or-later"></a>Para criar um projeto de DLL no Visual Studio 2017 versão 15.3 ou posterior

1. Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto** para abrir a caixa de diálogo **Novo Projeto**.

1. No painel esquerdo do **novo projeto** diálogo caixa, expanda **instalado** e **Visual C++** se necessário e, em seguida, escolha **Windows Desktop**. No painel central, selecione **Assistente de área de trabalho do Windows**. Insira `MathLibrary` no **nome** caixa para especificar um nome para o projeto.

   ![Nomeie o projeto MathLibrary](media/mathlibrary-new-project-name-153.png "Nomeie o projeto MathLibrary")

1. Escolha o **Okey** botão para ignorar a **novo projeto** caixa de diálogo e iniciar o **projeto de área de trabalho do Windows** assistente.

1. No **projeto de área de trabalho do Windows** do assistente, sob **tipo de aplicativo**, selecione **biblioteca de vínculo dinâmico (. dll)**.

   ![Criar a DLL no Assistente de projeto da área de trabalho do Windows](media/mathlibrary-desktop-project-wizard-dll.png "criar DLL no Assistente de projeto para desktops Windows")

1. Escolha o botão **OK** para criar o projeto.

> [!NOTE]
> Etapas adicionais são necessárias para corrigir um problema no Visual Studio 2017 versão 15.3. Siga estas instruções para verificar se é necessário fazer essa alteração.
>
>1. Na **Gerenciador de soluções**, se ele não ainda estiver selecionado, selecione o **MathLibrary** projeto **solução 'MathLibrary'**.
>
>1. Na barra de menus, escolha **Projeto**, **Propriedades**.
>
>1. No painel esquerdo do **páginas de propriedades** caixa de diálogo, selecione **pré-processador** sob **propriedades de configuração**, **C/C++**. Verifique o conteúdo do **definições de pré-processador** propriedade.<br/><br/>![Verifique a propriedade de definições de pré-processador](media/mathlibrary-153bug-preprocessor-definitions-check.png "Verifique a propriedade de definições de pré-processador")<br/><br/>Se você vir **MATHLIBRARY&#95;exportações** no **definições de pré-processador** listar, então você não precisa alterar nada. Se você vir **MathLibrary&#95;exportações** em vez disso, em seguida, continue seguindo estas etapas.
>
>1. Na parte superior dos **páginas de propriedades** caixa de diálogo, altere o **Configuration** lista suspensa para **todas as configurações de**.
>
>1. No painel de propriedade, selecione o controle de lista suspensa ao lado da caixa de edição para **definições de pré-processador**e, em seguida, escolha **editar**.<br/><br/>![Editar a propriedade de definições de pré-processador](media/mathlibrary-153bug-preprocessor-definitions-property.png "editar a propriedade de definições de pré-processador")
>
>1. No painel de superior a **definições de pré-processador** caixa de diálogo, adicionar um novo símbolo, `MATHLIBRARY_EXPORTS`.<br/><br/>![Adicionar o símbolo MATHLIBRARY_EXPORTS](media/mathlibrary-153bug-preprocessor-definitions-dialog.png "adicionar o símbolo MATHLIBRARY_EXPORTS")
>
>1. Escolher **Okey** para ignorar a **definições de pré-processador** caixa de diálogo e, em seguida, escolha **Okey** para salvar suas alterações às propriedades do projeto.

### <a name="to-create-a-dll-project-in-older-versions-of-visual-studio"></a>Para criar um projeto DLL em versões mais antigas do Visual Studio

1. Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.

1. No painel esquerdo do **novo projeto** diálogo caixa, expanda **instalado**, **modelos**e selecione **Visual C++** e, em seguida, no Centro painel, selecione **aplicativo do Console Win32**. Insira `MathLibrary` no **nome** caixa para especificar um nome para o projeto de edição.

   ![Nomeie o projeto MathLibrary](media/mathlibrary-project-name.png "Nomeie o projeto MathLibrary")

1. Escolha o **Okey** botão para ignorar a **novo projeto** caixa de diálogo e iniciar o **Assistente de aplicativo Win32**.

   ![Visão geral do Assistente de aplicativo Win32](media/mathlibrary-project-wizard-1.png "visão geral do Assistente de aplicativo Win32")

1. Escolha o botão **Avançar**. Sobre o **configurações do aplicativo** página, em **tipo de aplicativo**, selecione **DLL**.

   ![Criar a DLL no Assistente de aplicativo Win32](media/mathlibrary-project-wizard-2.png "criar DLL no Assistente de aplicativo Win32")

1. Escolha o **concluir** botão para criar o projeto.

Quando o assistente concluir a solução, você pode ver os arquivos de projeto e código-fonte gerados na **Gerenciador de soluções** janela no Visual Studio.

![Gerado solução no Visual Studio](media/mathlibrary-solution-explorer-153.png "gerado solução no Visual Studio")

Direita agora, essa DLL não faz muita coisa. Em seguida, você cria um arquivo de cabeçalho para declarar as funções de DLL exporta e, em seguida, adicione as definições de função para a DLL para torná-lo mais útil.

### <a name="to-add-a-header-file-to-the-dll"></a>Para adicionar um arquivo de cabeçalho para a DLL

1. Para criar um arquivo de cabeçalho para suas funções, na barra de menus, escolha **Project**, **Adicionar Novo Item**.

1. No **Adicionar Novo Item** caixa de diálogo, no painel esquerdo, selecione **Visual C++**. No painel central, selecione **arquivo de cabeçalho (. h)**. Especificar `MathLibrary.h` como o nome para o arquivo de cabeçalho.

   ![Adicionar cabeçalho na caixa de diálogo Adicionar Novo Item](media/mathlibrary-add-new-item-header-file.png "adicionar o arquivo de cabeçalho na caixa de diálogo Adicionar Novo Item")

1. Escolha o **adicionar** botão para gerar um arquivo de cabeçalho em branco, que é exibido em uma nova janela do editor.

   ![Arquivo MathLibrary.h vazio no editor](media/edit-empty-mathlibrary-header.png "MathLibrary.h vazio o arquivo no editor")

1. Substitua o conteúdo do arquivo de cabeçalho com este código:

   ```cpp
   // MathLibrary.h - Contains declarations of math functions
   #pragma once

   #ifdef MATHLIBRARY_EXPORTS
   #define MATHLIBRARY_API __declspec(dllexport)
   #else
   #define MATHLIBRARY_API __declspec(dllimport)
   #endif

   // The Fibonacci recurrence relation describes a sequence F
   // where F(n) is { n = 0, a
   //               { n = 1, b
   //               { n > 1, F(n-2) + F(n-1)
   // for some initial integral values a and b.
   // If the sequence is initialized F(0) = 1, F(1) = 1,
   // then this relation produces the well-known Fibonacci
   // sequence: 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

   // Initialize a Fibonacci relation sequence
   // such that F(0) = a, F(1) = b.
   // This function must be called before any other function.
   extern "C" MATHLIBRARY_API void fibonacci_init(
       const unsigned long long a, const unsigned long long b);

   // Produce the next value in the sequence.
   // Returns true on success and updates current value and index;
   // false on overflow, leaves current value and index unchanged.
   extern "C" MATHLIBRARY_API bool fibonacci_next();

   // Get the current value in the sequence.
   extern "C" MATHLIBRARY_API unsigned long long fibonacci_current();

   // Get the position of the current value in the sequence.
   extern "C" MATHLIBRARY_API unsigned fibonacci_index();
   ```

Esse arquivo de cabeçalho declara algumas funções para produzir uma sequência de Fibonacci generalizada, determinados dois valores iniciais. Uma chamada para `fibonacci_init(1, 1)` gera a sequência de número de Fibonacci familiarizado.

Observe as instruções do pré-processador na parte superior do arquivo. Por padrão, o modelo de novo projeto para uma DLL adiciona  **<em>PROJECTNAME</em>&#95;exportações** para as macros de pré-processador definidas para o projeto DLL. Neste exemplo, o Visual Studio define **MATHLIBRARY&#95;exportações** quando seu projeto de DLL MathLibrary é compilado. (O assistente no Visual Studio 2017 versão 15.3 não força a essa definição de símbolo em letras maiusculas. Se você nomear o projeto "MathLibrary", o símbolo definido é MathLibrary&#95;exportações em vez de MATHLIBRARY&#95;exportações. That's por isso que há etapas adicionais acima para adicionar esse símbolo.)

Quando o **MATHLIBRARY&#95;exportações** macro é definida, o **MATHLIBRARY&#95;API** conjuntos de macro a `__declspec(dllexport)` modificador em declarações de função. Esse modificador informa ao compilador e vinculador para exportar uma função ou variável da DLL para que ele pode ser usado por outros aplicativos. Quando **MATHLIBRARY&#95;exportações** é indefinido, por exemplo, quando o arquivo de cabeçalho é incluído por um aplicativo de cliente **MATHLIBRARY&#95;API** aplica-se a `__declspec(dllimport)` modificador para o declarações. Esse modificador otimiza a importação da função ou variável em um aplicativo. Para obter mais informações, consulte [dllexport, dllimport](../cpp/dllexport-dllimport.md).

### <a name="to-add-an-implementation-to-the-dll"></a>Para adicionar uma implementação para a DLL

1. Na janela do editor, selecione a guia para **MathLibrary.cpp** se já estiver aberto. Caso contrário, na **Gerenciador de soluções**, abra **MathLibrary.cpp** no **arquivos de origem** pasta do **MathLibrary** projeto.

1. No editor, substitua o conteúdo do arquivo MathLibrary.cpp com o código a seguir:

   ```cpp
   // MathLibrary.cpp : Defines the exported functions for the DLL.
   #include "stdafx.h"
   #include <utility>
   #include <limits.h>
   #include "MathLibrary.h"

   // DLL internal state variables:
   static unsigned long long previous_;  // Previous value, if any
   static unsigned long long current_;   // Current sequence value
   static unsigned index_;               // Current seq. position

   // Initialize a Fibonacci relation sequence
   // such that F(0) = a, F(1) = b.
   // This function must be called before any other function.
   void fibonacci_init(
       const unsigned long long a,
       const unsigned long long b)
   {
       index_ = 0;
       current_ = a;
       previous_ = b; // see special case when initialized
   }

   // Produce the next value in the sequence.
   // Returns true on success, false on overflow.
   bool fibonacci_next()
   {
       // check to see if we'd overflow result or position
       if ((ULLONG_MAX - previous_ < current_) ||
           (UINT_MAX == index_))
       {
           return false;
       }

       // Special case when index == 0, just return b value
       if (index_ > 0)
       {
           // otherwise, calculate next sequence value
           previous_ += current_;
       }
       std::swap(current_, previous_);
       ++index_;
       return true;
   }

   // Get the current value in the sequence.
   unsigned long long fibonacci_current()
   {
       return current_;
   }

   // Get the current index position in the sequence.
   unsigned fibonacci_index()
   {
       return index_;
   }
   ```

Para verificar se tudo funciona até agora, compile a biblioteca de vínculo dinâmico. Para compilar, escolha **construir**, **compilar solução** na barra de menus. A saída deve ter esta aparência:

```Output
1>------ Build started: Project: MathLibrary, Configuration: Debug Win32 ------
1>stdafx.cpp
1>MathLibrary.cpp
1>dllmain.cpp
1>Generating Code...
1>   Creating library C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.lib and object C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.exp
1>MathLibrary.vcxproj -> C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.dll
1>MathLibrary.vcxproj -> C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.pdb (Partial PDB)
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```

Parabéns, você criou uma DLL usando o Visual C++! Em seguida, você criará um aplicativo cliente que usa as funções exportadas pela DLL.

## <a name="create-a-client-app-that-uses-the-dll"></a>Criar um aplicativo cliente que usa a DLL

Quando você cria uma DLL, você deve pensar sobre como a sua DLL pode ser usado. Para compilar o código que chama as funções exportadas por uma DLL, as declarações devem ser incluídas no código de origem do cliente. Em tempo de vinculação, quando essas chamadas de funções de DLL são resolvidas, o vinculador deve ter uma *biblioteca de importação*, um tipo especial de arquivo de biblioteca que contém informações para o Windows sobre como localizar as funções, em vez do código real. E, em tempo de execução, a DLL deve estar disponível para o cliente, em um local que o sistema operacional pode encontrar.

Para fazer uso de uma DLL, se seu proprietário ou uma DLL de terceiros, seu projeto de aplicativo cliente deve ser capaz de encontrar os cabeçalhos que declarar a DLL exporta, as bibliotecas de importação para o vinculador e a própria DLL. Uma maneira de fazer isso é copiar todos esses arquivos em seu projeto de cliente. DLLs de terceiros que são improvável de ser alterado enquanto seu cliente está em desenvolvimento, isso pode ser a melhor maneira de usá-los. No entanto, quando você também pode criar a DLL, é melhor evitar a duplicação. Se você fizer uma cópia dos arquivos DLL que estão em desenvolvimento, pode acidentalmente alterar um arquivo de cabeçalho em uma cópia, mas não o outro ou usar uma biblioteca desatualizada. Para evitar esse problema, recomendamos que você defina o caminho de inclusão no seu projeto de cliente para incluir os arquivos de cabeçalho DLL do projeto de DLL. Além disso, defina o caminho da biblioteca em seu projeto de cliente para incluir as bibliotecas de importação DLL do projeto de DLL. E, por fim, copie a DLL compilada do projeto de DLL em seu diretório de saída de compilação. Isso garante que seu aplicativo cliente usa o mesmo código DLL que você criar.

### <a name="to-create-a-client-app-in-visual-studio-2017-version-153-or-later"></a>Para criar um aplicativo cliente no Visual Studio 2017 versão 15.3 ou posterior

1. Para criar um aplicativo em C++ que usa a DLL que você acabou de criar, na barra de menus, escolha **arquivo**, **New**, **projeto**.

1. No painel esquerdo do **novo projeto** caixa de diálogo, selecione **área de trabalho do Windows** sob **instalado**, **Visual C++**. No painel central, selecione **Assistente de área de trabalho do Windows**. Especifique o nome do projeto `MathClient`, no **nome** caixa de edição.

   ![Nomeie o projeto de cliente](media/mathclient-new-project-name-153.png "Nomeie o projeto de cliente")

1. Escolher **Okey** para iniciar o **projeto de área de trabalho do Windows** assistente. No assistente, escolha **Okey** para criar o projeto de aplicativo do cliente.

### <a name="to-create-a-client-app-in-older-versions-of-visual-studio-2017"></a>Para criar um aplicativo cliente em versões mais antigas do Visual Studio 2017

1. Para criar um aplicativo em C++ que usa a DLL que você acabou de criar, na barra de menus, escolha **arquivo**, **New**, **projeto**.

1. No painel esquerdo do **novo projeto** caixa de diálogo, selecione **Win32** sob **instalado**, **modelos**, **deVisualC++**. No painel central, selecione **aplicativo do Console Win32**. Especifique o nome do projeto `MathClient`, no **nome** caixa de edição.

   ![Nomeie o projeto de cliente](media/mathclient-project-name.png "Nomeie o projeto de cliente")

1. Escolha o **Okey** botão para ignorar a **novo projeto** caixa de diálogo e iniciar o **Assistente de aplicativo Win32**. No **visão geral** página do **Assistente de aplicativo Win32** caixa de diálogo, escolha o **próxima** botão.

1. Sobre o **configurações do aplicativo** página em **tipo de aplicativo**, selecione **aplicativo de Console** se ainda não estiver selecionado.

1. Escolha o **concluir** botão para criar o projeto.

Quando o assistente for concluído, um projeto de aplicativo de console mínimo é criado para você. O nome do arquivo de origem principal é o mesmo que o nome do projeto que você inseriu anteriormente. Neste exemplo, ela é nomeada **MathClient.cpp**. Você pode compilá-lo, mas ele não usa a DLL ainda.

Em seguida, para chamar as funções MathLibrary em seu código-fonte, seu projeto deve incluir o arquivo MathLibrary.h. Você poderia copiar esse arquivo de cabeçalho para o projeto de aplicativo do cliente e adicioná-lo ao projeto como um item existente. Isso pode ser uma boa opção para bibliotecas de terceiros. No entanto, se você estiver trabalhando no código para seu DLL ao mesmo tempo como seu cliente, que pode levar a alterações no arquivo de um cabeçalho que não são refletidas no outro. Para evitar esse problema, você pode alterar o **diretórios de inclusão adicionais** caminho em seu projeto para incluir o caminho para o cabeçalho original.

### <a name="to-add-the-dll-header-to-your-include-path"></a>Para adicionar o cabeçalho DLL a seu caminho de inclusão

1. Abra o **páginas de propriedades** caixa de diálogo para o **MathClient** projeto.

1. No **Configuration** caixa de lista suspensa, selecione **todas as configurações de** se ainda não estiver selecionado.

1. No painel esquerdo, selecione **gerais** sob **propriedades de configuração**, **C/C++**.

1. No painel de propriedades, selecione o controle de lista suspensa ao lado de **diretórios de inclusão adicionais** caixa de edição e, em seguida, escolha **editar**.

   ![Editar a propriedade de diretórios de inclusão adicionais](media/mathclient-additional-include-directories-property.png "editar a propriedade de diretórios de inclusão adicionais")

1. Clique duas vezes no painel de superior a **diretórios de inclusão adicionais** caixa de diálogo para habilitar um controle de edição.

1. No controle de edição, especifique o caminho para o local do **MathLibrary.h** arquivo de cabeçalho. Nesse caso, você pode usar um caminho relativo:

   `..\..\MathLibrary\MathLibrary`

   ![Adicione o local do cabeçalho para a propriedade de diretórios de inclusão adicionais](media/mathclient-additional-include-directories.png "adicionar o local do cabeçalho para a propriedade de diretórios de inclusão adicionais")

1. Depois de inserir o caminho para o arquivo de cabeçalho na **diretórios de inclusão adicionais** diálogo caixa, escolha o **Okey** botão Voltar para o **páginas de propriedades** caixa de diálogo, e em seguida, escolha o **Okey** botão para salvar suas alterações.

Agora você pode incluir a **MathLibrary.h** de arquivo e usar as funções que ele declara em seu aplicativo cliente. Substitua o conteúdo do **MathClient.cpp** usando este código:

```cpp
// MathClient.cpp : Client app for MathLibrary DLL.
#include "stdafx.h"
#include <iostream>
#include "MathLibrary.h"

int main()
{
    // Initialize a Fibonacci relation sequence.
    fibonacci_init(1, 1);
    // Write out the sequence values until overflow.
    do {
        std::cout << fibonacci_index() << ": "
            << fibonacci_current() << std::endl;
    } while (fibonacci_next());
    // Report count of values written before overflow.
    std::cout << fibonacci_index() + 1 <<
        " Fibonacci sequence values fit in an " <<
        "unsigned 64-bit integer." << std::endl;
}
```

Esse código pode ser compilado, mas não vinculado, porque o vinculador não pode localizar a biblioteca de importação necessária para compilar o aplicativo ainda. O vinculador deve ser capaz de encontrar o arquivo MathLibrary.lib para vincular com êxito. Você deve adicionar o arquivo MathLibrary.lib ao build definindo a **dependências adicionais** propriedade. Mais uma vez, você pode copiar o arquivo de biblioteca em seu projeto de aplicativo do cliente, mas se a biblioteca e o aplicativo cliente estão em desenvolvimento, que pode resultar em alterações em uma cópia que não são refletidas no outro. Para evitar esse problema, você pode alterar o **diretórios de biblioteca adicionais** caminho em seu projeto para incluir o caminho para a biblioteca original quando você os vincula.

### <a name="to-add-the-dll-import-library-to-your-project"></a>Para adicionar a biblioteca de importação DLL ao seu projeto

1. Abra o **páginas de propriedades** caixa de diálogo para o **MathClient** projeto.

1. No **Configuration** caixa de lista suspensa, selecione **todas as configurações de** se ainda não estiver selecionado.

1. No painel esquerdo, selecione **entrada** sob **propriedades de configuração**, **vinculador**. No painel de propriedades, selecione o controle de lista suspensa ao lado de **dependências adicionais** caixa de edição e, em seguida, escolha **editar**.

   ![Edite a propriedade dependências adicionais](media/mathclient-additional-dependencies-property.png "editar a propriedade dependências adicionais")

1. No **dependências adicionais** caixa de diálogo Adicionar `MathLibrary.lib` controle de edição à lista na parte superior.

   ![Adicione a dependência de biblioteca](media/mathclient-additional-dependencies.png "adicionar a dependência de biblioteca")

1. Escolher **Okey** para voltar para o **páginas de propriedade** caixa de diálogo.

1. No painel esquerdo, selecione **gerais** sob **propriedades de configuração**, **vinculador**. No painel de propriedades, selecione o controle de lista suspensa ao lado de **diretórios de biblioteca adicionais** caixa de edição e, em seguida, escolha **editar**.

   ![Editar a propriedade de diretórios de biblioteca adicionais](media/mathclient-additional-library-directories-property.png "editar a propriedade de diretórios de biblioteca adicionais")

1. Clique duas vezes no painel de superior a **diretórios de biblioteca adicionais** caixa de diálogo para habilitar um controle de edição. No controle de edição, especifique o caminho para o local do **MathLibrary.lib** arquivo. Insira esse valor para usar uma macro que funciona para depuração e lançamento cria:

   `..\..\MathLibrary\$(IntDir)`

   ![Adicione o diretório de biblioteca](media/mathclient-additional-library-directories.png "adicionar o diretório de biblioteca")

1. Depois de inserir o caminho para o arquivo de biblioteca na **diretórios de biblioteca adicionais** diálogo caixa, escolha o **Okey** botão Voltar para o **páginas de propriedade** caixa de diálogo.

Seu aplicativo cliente pode compilar e vincular com êxito, mas ele ainda não tem tudo o que precisa para ser executado. Quando o sistema operacional carregará seu aplicativo, ele procura a DLL MathLibrary. Se ele não é possível localizar a DLL em determinados diretórios do sistema, o caminho de ambiente ou o diretório de aplicativo local, o carregamento falha. Uma maneira para evitar esse problema é copiar a DLL para o diretório que contém o executável do cliente como parte do processo de compilação. Para copiar a DLL, você pode adicionar um **evento pós-compilação** ao seu projeto, adicionar um comando que copia a DLL seu diretório de saída de compilação. O comando especificado aqui copia a DLL somente se ele está ausente ou foi alterada e usa as macros para copiar entre os locais de depuração ou de varejo correto para sua configuração.

### <a name="to-copy-the-dll-in-a-post-build-event"></a>Para copiar a DLL em um evento de pós-compilação

1. Abra o **páginas de propriedades** caixa de diálogo para o **MathClient** projeto se ainda não estiver aberto.

1. Na caixa de lista suspensa de configuração, selecione **todas as configurações de** se ainda não estiver selecionado.

1. No painel esquerdo, selecione **evento de pós-build** sob **propriedades de configuração**, **eventos de Build**.

1. No painel de propriedades, selecione o controle de edição na **linha de comando** campo e, em seguida, digite este comando:

   `xcopy /y /d "..\..\MathLibrary\$(IntDir)MathLibrary.dll" "$(OutDir)"`

   ![Adicione o comando de pós-compilação](media/mathclient-post-build-command-line.png "adicionar o comando de pós-compilação")

1. Escolha o **Okey** botão para salvar suas alterações às propriedades do projeto.

Agora o aplicativo cliente tem tudo o que precisa para compilar e executar. Compile o aplicativo escolhendo **construir**, **compilar solução** na barra de menus. O **saída** janela no Visual Studio deve conter algo parecido com isto:

```Output
1>------ Build started: Project: MathClient, Configuration: Debug Win32 ------
1>stdafx.cpp
1>MathClient.cpp
1>MathClient.vcxproj -> C:\Users\username\Source\Repos\MathClient\Debug\MathClient.exe
1>MathClient.vcxproj -> C:\Users\username\Source\Repos\MathClient\Debug\MathClient.pdb (Partial PDB)
1>1 File(s) copied
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```

Parabéns, você criou um aplicativo que chama as funções na DLL. Agora execute seu aplicativo para ver o que ele faz. Na barra de menus, escolha **Debug**, **Start Without Debugging**. Visual Studio abre uma janela de comando para o programa seja executado. A última parte da saída deve ter esta aparência:

![Iniciar o aplicativo cliente sem depuração](media/mathclient-run-without-debugging.png "iniciar o aplicativo cliente sem depuração")

Pressione qualquer tecla para fechar a janela de comando.

Agora que você criou uma DLL e um aplicativo cliente, você pode experimentar. Tente definir pontos de interrupção no código do aplicativo cliente e executar o aplicativo no depurador. Veja o que acontece quando você entra em uma chamada de biblioteca. Adicione outras funções na biblioteca, ou escrever outro aplicativo de cliente que usa sua DLL.

Quando você implanta seu aplicativo, você também deve implantar as DLLs que ele usa. A maneira mais simples para disponibilizar as DLLs que você cria ou que você incluir de terceiros para seu aplicativo é colocá-los no mesmo diretório que seu aplicativo, também conhecido como *implantação de aplicativo local*. Para obter mais informações sobre a implantação, consulte [implantação no Visual C++](..\ide\deployment-in-visual-cpp.md).

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)<br/>
[Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)<br/>
[Passo a passo: implantando o programa (C++)](../ide/walkthrough-deploying-your-program-cpp.md)<br/>
[Chamando funções DLL de aplicativos Visual Basic](../build/calling-dll-functions-from-visual-basic-applications.md)