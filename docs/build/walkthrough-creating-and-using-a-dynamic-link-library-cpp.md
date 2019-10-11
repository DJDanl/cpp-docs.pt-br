---
title: 'Passo a passo: Criar e usar sua própria Biblioteca de vínculo dinâmico (C++)'
description: Use C++ para criar uma biblioteca de vínculo dinâmico (DLL) do Windows no Visual Studio.
ms.custom: conceptual
ms.date: 08/22/2019
helpviewer_keywords:
- libraries [C++], DLLs
- DLLs [C++], walkthroughs
ms.assetid: 3ae94848-44e7-4955-bbad-7d40f493e941
ms.openlocfilehash: 7bc0cb58cbbe995aa9d74e3ccb627ddc442bd4fb
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2019
ms.locfileid: "70026083"
---
# <a name="walkthrough-create-and-use-your-own-dynamic-link-library-c"></a>Passo a passo: Criar e usar sua própria Biblioteca de vínculo dinâmico (C++)

Este guia passo a passo mostra como usar o IDE do Visual Studio para criar sua própria DLL (biblioteca de vínculo dinâmico) escrita no Microsoft C++ (MSVC). Em seguida, ele mostra como usar a DLL de C++ outro aplicativo. As DLLs (também conhecidas como *bibliotecas compartilhadas* em sistemas operacionais baseados em UNIX) são um dos tipos mais úteis de componentes do Windows. Você pode usá-los como uma maneira de compartilhar código e recursos e reduzir o tamanho dos seus aplicativos. As DLLs podem até mesmo facilitar o serviço e estender seus aplicativos.

Neste tutorial, você criará uma DLL que implementa algumas funções matemáticas. Em seguida, você criará um aplicativo de console que usa as funções da DLL. Você também obterá uma introdução a algumas técnicas de programação e convenções usadas em DLLs do Windows.

Este passo a passo apresenta estas tarefas:

- Crie um projeto de DLL no Visual Studio.

- Adicione variáveis e funções exportadas para a DLL.

- Crie um projeto de aplicativo de console no Visual Studio.

- Use as funções e variáveis importadas da DLL no aplicativo de console.

- Execute o aplicativo finalizado.

Como uma biblioteca vinculada estaticamente, uma DLL _exporta_ variáveis, funções e recursos por nome. Um aplicativo cliente _importa_ os nomes para usar essas variáveis, funções e recursos. Ao contrário de uma biblioteca vinculada estaticamente, o Windows conecta as importações em seu aplicativo às exportações em uma DLL no momento do carregamento ou no tempo de execução, ao invés de conectá-las ao link de vinculação. O Windows requer informações adicionais que não fazem parte do modelo de compilação em C++ padrão para fazer essas conexões. O compilador MSVC implementa algumas extensões específicas da Microsoft para C++ para fornecer essas informações adicionais. Explicaremos essas extensões à medida que avançarmos.

Este passo a passo cria duas soluções do Visual Studio: uma que cria a DLL e outra que compila o aplicativo cliente. A DLL usa a Convenção de chamada C. Ele pode ser chamado a partir de aplicativos escritos em outras linguagens de programação, desde que a plataforma, as convenções de chamada e as convenções de vinculação correspondam. O aplicativo cliente usa a _vinculação implícita_, em que o Windows vincula o aplicativo à DLL no tempo de carregamento. Essa vinculação permite que o aplicativo chame as funções fornecidas pela DLL como as funções de uma biblioteca vinculada estaticamente.

Este passo a passo não aborda algumas situações comuns. O código não mostra o uso de C++ DLLs por outras linguagens de programação. Ele não mostra como [criar uma DLL somente de recursos](creating-a-resource-only-dll.md)ou como usar [vinculação explícita](linking-an-executable-to-a-dll.md#linking-explicitly) para carregar DLLs em tempo de execução em vez de em tempo de carregamento. Com certeza, você pode usar o MSVC e o Visual Studio para fazer todas essas coisas.

Para saber mais sobre DLLs, consulte [Criar DLLs C/C ++ no Visual Studio](dlls-in-visual-cpp.md). Para obter mais informações sobre vinculação implícita e vinculação explícita, consulte [determinar qual método de vinculação usar](linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use). Para obter informações sobre C++ como criar DLLs para uso com linguagens de programação que usam convenções de vinculação de linguagem c, consulte [exportando C++ funções para uso em executáveis de linguagem c](exporting-cpp-functions-for-use-in-c-language-executables.md). Para saber mais sobre como criar DLLs para usar com linguagens .NET, consulte [Chamando funções DLL a partir de aplicativos Visual Basic](calling-dll-functions-from-visual-basic-applications.md).

## <a name="prerequisites"></a>Pré-requisitos

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. Recomendamos o Windows 10 para obter a melhor experiência de desenvolvimento.

::: moniker range=">=vs-2017"

- Uma cópia do Visual Studio. Para saber mais sobre como fazer o download e instalar o Visual Studio, consulte [Instalar o Visual Studio](/visualstudio/install/install-visual-studio). Quando executar o instalador, certifique-se de que a carga de trabalho de **Desenvolvimento para desktop com C++** esteja marcada. Não se preocupe se não tiver instalado essa carga de trabalho quando instalou o Visual Studio. Você pode executar o instalador novamente e instalá-la agora.

   ![Desenvolvimento para desktop com C++](media/desktop-development-with-cpp.png "Desenvolvimento para desktop com C++")

::: moniker-end

::: moniker range="vs-2015"

- Uma cópia do Visual Studio. Para obter informações sobre como baixar e instalar o Visual Studio 2015, consulte [instalar o visual studio 2015](/visualstudio/install/install-visual-studio-2015?view=vs-2015). Use uma instalação **personalizada** para instalar o C++ compilador e as ferramentas, pois elas não são instaladas por padrão.

::: moniker-end

- Um reconhecimento dos princípios básicos do uso do IDE do Visual Studio. Se já tiver usado aplicativos de desktop do Windows, você provavelmente não terá problemas. Para ver uma introdução, consulte [Tour pelos recursos do IDE do Visual Studio](/visualstudio/ide/visual-studio-ide).

- Um reconhecimento dos princípios básicos da linguagem C++ a seguir. Não se preocupe, não faremos nada muito complicado.

::: moniker range="vs-2017"

> [!NOTE]
> Este tutorial pressupõe que você esteja usando o Visual Studio 2017 versão 15,9 ou posterior. Algumas versões anteriores do Visual Studio 2017 tinham defeitos nos modelos de código ou usavam caixas de diálogo de interface do usuário diferentes. Para evitar problemas, use o Instalador do Visual Studio para atualizar o Visual Studio 2017 para a versão 15,9 ou posterior.

::: moniker-end

## <a name="create-the-dll-project"></a>Criar o projeto de DLL

Neste conjunto de tarefas, você cria um projeto para sua DLL, adiciona código e o compila. Para começar, inicie o IDE do Visual Studio e, se necessário, entre. As instruções variam um pouco dependendo da versão do Visual Studio que você está usando. Verifique se tem a versão correta marcada no controle na parte superior esquerda desta página.

::: moniker range=">=vs-2019"

### <a name="to-create-a-dll-project-in-visual-studio-2019"></a>Para criar um projeto de DLL no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto**.

   ![Criar um novo projeto de DLL](media/create-new-dll-project-2019.png "Criar o projeto MathLibrary")

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++** , **Plataforma** como **Windows** e **Tipo de projeto** como **Biblioteca**.

1. Na lista filtrada de tipos de projeto, selecione **biblioteca de vínculo dinâmico (DLL)** e, em seguida, escolha **Avançar**.

1. Na página **configurar seu novo projeto** , digite *MathLibrary* na caixa **nome do projeto** para especificar um nome para o projeto. Deixe os valores de **local** padrão e **nome da solução** . Defina a **solução** para **criar uma nova solução**. Desmarque **a solução e o projeto do local no mesmo diretório** , se estiver marcado.

1. Escolha o botão **Criar** para criar o projeto.

Quando a solução é criada, você pode ver o projeto gerado e os arquivos de origem na janela **Gerenciador de soluções** no Visual Studio.

![Solução gerada no Visual Studio](media/mathlibrary-solution-explorer-162.png "Solução gerada no Visual Studio")

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-dll-project-in-visual-studio-2017"></a>Para criar um projeto de DLL no Visual Studio 2017

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Novo Projeto**.

1. No painel esquerdo da caixa de diálogo  >  **novo projeto** , selecione**Visual C++**  **área de trabalho do Windows** **instalado** > . No painel central, selecione **biblioteca de vínculo dinâmico (DLL)** . Insira *MathLibrary* na caixa **nome** para especificar um nome para o projeto. Deixe os valores de **local** padrão e **nome da solução** . Defina a **solução** para **criar uma nova solução**. Marque **criar diretório para obter a solução** se ela estiver desmarcada.

   ![Nomear o projeto MathLibrary](media/mathlibrary-new-project-name-159.png "Nomear o projeto MathLibrary")

1. Escolha o botão **OK** para criar o projeto.

Quando a solução é criada, você pode ver o projeto gerado e os arquivos de origem na janela **Gerenciador de soluções** no Visual Studio.

![Solução gerada no Visual Studio](media/mathlibrary-solution-explorer-159.png "Solução gerada no Visual Studio")

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-dll-project-in-visual-studio-2015-and-older-versions"></a>Para criar um projeto de DLL no Visual Studio 2015 e versões mais antigas

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto**.

1. No painel esquerdo da caixa de diálogo **Novo Projeto**, expanda **Modelos** > **Instalados** e escolha **Visual C++** . Em seguida, no painel central, escolha **Aplicativo de Console Win32**. Insira *MathLibrary* na caixa de edição de **nome** para especificar um nome para o projeto. Deixe os valores de **local** padrão e **nome da solução** . Defina a **solução** para **criar uma nova solução**. Marque **criar diretório para obter a solução** se ela estiver desmarcada.

   ![Nomear o projeto MathLibrary](media/mathlibrary-project-name.png "Nomear o projeto MathLibrary")

1. Escolha o botão **OK** para ignorar a caixa de diálogo **Novo Projeto** e iniciar o **Assistente de Aplicativo Win32**.

   ![Visão geral do Assistente de Aplicativo Win32](media/mathlibrary-project-wizard-1.png "Visão geral do Assistente de Aplicativo Win32")

1. Escolha o botão **Avançar**. Na página **Configurações do Aplicativo**, em **Tipo de Aplicativo**, escolha **DLL**.

   ![Criar DLL no Assistente de Aplicativo Win32](media/mathlibrary-project-wizard-2.png "Criar DLL no Assistente de Aplicativo Win32")

1. Escolha o botão **Concluir** para criar o projeto.

Quando o assistente concluir a solução, você verá os arquivos de projeto e de origem gerados na janela do **Gerenciador de Soluções** no Visual Studio.

![Solução gerada no Visual Studio](media/mathlibrary-solution-explorer-153.png "Solução gerada no Visual Studio")

::: moniker-end

No momento, essa DLL não faz muita coisa. Em seguida, você criará um arquivo de cabeçalho para declarar as funções exportadas por sua DLL e, em seguida, adicionará as definições de função à DLL para torná-la mais útil.

### <a name="to-add-a-header-file-to-the-dll"></a>Para adicionar um arquivo de cabeçalho à DLL

1. Para criar um arquivo de cabeçalho para suas funções, na barra de menus, escolha **Projeto** > **Adicionar Novo Item**.

1. Na caixa de diálogo **Adicionar Novo Item**, no painel à esquerda, escolha **Visual C++** . No painel central, escolha **Arquivo de Cabeçalho (.h)** . Especifique *MathLibrary. h* como o nome do arquivo de cabeçalho.

   ![Adicionar cabeçalho na caixa de diálogo Adicionar Novo Item](media/mathlibrary-add-new-item-header-file.png "Adicionar arquivo de cabeçalho na caixa de diálogo Adicionar Novo Item")

1. Escolha o botão **Adicionar** para gerar um arquivo de cabeçalho em branco, que é exibido em uma nova janela do editor.

   ![Esvaziar o arquivo MathLibrary.h no editor](media/edit-empty-mathlibrary-header.png "Esvaziar o arquivo MathLibrary.h no editor")

1. Substitua o conteúdo do arquivo de cabeçalho por este código:

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

Este arquivo de cabeçalho declara algumas funções para produzir uma sequência de Fibonacci generalizada, tendo em conta dois valores iniciais. Uma chamada para `fibonacci_init(1, 1)` gera a conhecida sequência de números de Fibonacci.

Observe as instruções do pré-processador na parte superior do arquivo. O novo modelo de projeto para um projeto DLL adiciona **exportações _ProjectName_&#95;exportação** às macros de pré-processador definidas. Neste exemplo, o Visual Studio define **MATHLIBRARY&#95;EXPORTS** quando seu projeto de DLL MathLibrary é compilado.

Quando a macro **MATHLIBRARY&#95;EXPORTS** é definida, a macro **MATHLIBRARY&#95;API** define o modificador `__declspec(dllexport)` nas declarações da função. Esse modificador instrui o compilador e o vinculador a exportar uma função ou variável da DLL para uso por outros aplicativos. Quando **MATHLIBRARY&#95;EXPORTS** está indefinido, por exemplo, quando o arquivo de cabeçalho é incluído por um aplicativo cliente, **MATHLIBRARY&#95;API** aplica o modificador `__declspec(dllimport)` às declarações. Esse modificador otimiza a importação da função ou variáveis em aplicativos. Para saber mais, confira [dllexport, dllimport](../cpp/dllexport-dllimport.md).

### <a name="to-add-an-implementation-to-the-dll"></a>Para adicionar uma implementação à DLL

::: moniker range=">=vs-2019"

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no nó **arquivos de origem** e escolha **Adicionar** > **novo item**. Crie um novo arquivo. cpp chamado *MathLibrary. cpp*, da mesma maneira que você adicionou um novo arquivo de cabeçalho na etapa anterior.

1. Na janela do editor, escolha a guia para **MathLibrary.cpp** se já estiver aberta. Caso contrário, em **Gerenciador de soluções**, clique duas vezes em **MathLibrary. cpp** na pasta **arquivos de origem** do projeto **MathLibrary** para abri-lo.

1. No editor, substitua o conteúdo do arquivo MathLibrary.cpp pelo código a seguir:

   ```cpp
   // MathLibrary.cpp : Defines the exported functions for the DLL.
   #include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
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

::: moniker-end

::: moniker range="<=vs-2017"

1. Na janela do editor, escolha a guia para **MathLibrary.cpp** se já estiver aberta. Caso contrário, em **Gerenciador de soluções**, clique duas vezes em **MathLibrary. cpp** na pasta **arquivos de origem** do projeto **MathLibrary** para abri-lo.

1. No editor, substitua o conteúdo do arquivo MathLibrary.cpp pelo código a seguir:

   ```cpp
   // MathLibrary.cpp : Defines the exported functions for the DLL.
   #include "stdafx.h" // use pch.h in Visual Studio 2019 and later
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

::: moniker-end

Para verificar se tudo está funcionando bem, compile a biblioteca de vínculo dinâmico. Para compilar, escolha **Compilar** > **Compilar solução** na barra de menus. A DLL e a saída do compilador relacionado são colocadas em uma pasta chamada *debug* diretamente abaixo da pasta da solução. Se você criar uma compilação de versão, a saída será colocada em uma pasta chamada *Release*. A saída deve ser semelhante a esta:

::: moniker range=">=vs-2019"

```Output
1>------ Build started: Project: MathLibrary, Configuration: Debug Win32 ------
1>pch.cpp
1>dllmain.cpp
1>MathLibrary.cpp
1>Generating Code...
1>   Creating library C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.lib and object C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.exp
1>MathLibrary.vcxproj -> C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.dll
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```

::: moniker-end

::: moniker range="vs-2017"

```Output
1>------ Build started: Project: MathLibrary, Configuration: Debug Win32 ------
1>stdafx.cpp
1>dllmain.cpp
1>MathLibrary.cpp
1>Generating Code...
1>   Creating library C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.lib and object C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.exp
1>MathLibrary.vcxproj -> C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.dll
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```

::: moniker-end

::: moniker range="vs-2015"

```Output
1>------ Build started: Project: MathLibrary, Configuration: Debug Win32 ------
1>MathLibrary.cpp
1>dllmain.cpp
1>Generating Code...
1>   Creating library C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.lib and object C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.exp
1>MathLibrary.vcxproj -> C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.dll
1>MathLibrary.vcxproj -> C:\Users\username\Source\Repos\MathLibrary\Debug\MathLibrary.pdb (Partial PDB)
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```

::: moniker-end

Parabéns, você criou uma DLL usando o Visual Studio! A seguir, você criará um aplicativo cliente que usa as funções exportadas pela DLL.

## <a name="create-a-client-app-that-uses-the-dll"></a>Criar um aplicativo cliente que usa a DLL

Ao criar uma DLL, pense em como os aplicativos cliente podem usá-la. Para chamar as funções ou acessar os dados exportados por uma DLL, o código-fonte do cliente deve ter as declarações disponíveis no momento da compilação. No momento do link, o vinculador requer informações para resolver as chamadas de função ou os acessos de dados. Uma DLL fornece essas informações em uma *biblioteca de importação*, um arquivo que contém informações sobre como encontrar as funções e os dados, em vez do código real. E no tempo de execução a DLL deve estar disponível para o cliente, em um local que o sistema operacional possa localizá-la.

Seja seu próprio ou de terceiros, seu projeto de aplicativo cliente precisa de várias informações para usar uma DLL. Ele precisa localizar os cabeçalhos que declaram as exportações de DLL, as bibliotecas de importação para o vinculador e a própria DLL. Uma solução é copiar todos esses arquivos em seu projeto de cliente. No caso de DLLs de terceiros que provavelmente não serão alteradas enquanto seu cliente estiver em desenvolvimento, esse método pode ser a melhor maneira de usá-las. No entanto, quando você também compila a DLL, é melhor evitar a duplicação. Se você fizer uma cópia local de arquivos DLL que estão em desenvolvimento, poderá acidentalmente alterar um arquivo de cabeçalho em uma cópia, mas não o outro, ou usar uma biblioteca desatualizada.

Para evitar código fora de sincronia, recomendamos que você defina o caminho de inclusão em seu projeto de cliente para incluir os arquivos de cabeçalho DLL diretamente do seu projeto de DLL. Além disso, defina o caminho da biblioteca em seu projeto de cliente para incluir as bibliotecas de importação de DLLs do projeto da DLL. E, por fim, copie a DLL criada do projeto de DLL para o diretório de saída de compilação do cliente. Esta etapa permite que seu aplicativo cliente use o mesmo código de DLL que você compilou.

::: moniker range=">=vs-2019"

### <a name="to-create-a-client-app-in-visual-studio"></a>Para criar um aplicativo cliente no Visual Studio

1. Na barra de menus, escolha **arquivo** > **novo** > **projeto** para abrir a caixa de diálogo **criar um novo projeto** .

1. Na parte superior da caixa de diálogo, defina **Linguagem** como **C++** , **Plataforma** como **Windows** e **Tipo de projeto** como **Console**.

1. Na lista filtrada de tipos de projeto, escolha **Aplicativo de Console** e, em seguida, escolha **Avançar**.

1. Na página **configurar seu novo projeto** , digite *MathClient* na caixa **nome do projeto** para especificar um nome para o projeto. Deixe os valores de **local** padrão e **nome da solução** . Defina a **solução** para **criar uma nova solução**. Desmarque **a solução e o projeto do local no mesmo diretório** , se estiver marcado.

   ![Nomear o projeto de cliente](media/mathclient-project-name-2019.png "Nomear o projeto de cliente")

1. Escolha o botão **Criar** para criar o projeto do cliente.

Um projeto de aplicativo de console mínimo é criado para você. O nome do arquivo de origem principal é o mesmo nome do projeto inserido anteriormente. Neste exemplo, o nome usado é **MathClient.cpp**. Você pode compilá-lo, mas ele ainda não usa a DLL.

::: moniker-end

::: moniker range="vs-2017"

### <a name="to-create-a-client-app-in-visual-studio-2017"></a>Para criar um aplicativo cliente no Visual Studio 2017

1. Para criar um aplicativo C++ que use a DLL que você criou, escolha **Arquivo** > **Novo** > **Projeto** na barra de menus.

1. No painel esquerdo da caixa de diálogo **Novo Projeto**, escolha **Windows Desktop** em **Visual C++**  > **Instalado**. No painel central, selecione **aplicativo de console do Windows**. Especifique o nome do projeto, *MathClient*, na caixa de edição de **nome** .  Deixe os valores de **local** padrão e **nome da solução** . Defina a **solução** para **criar uma nova solução**. Marque **criar diretório para obter a solução** se ela estiver desmarcada.

   ![Nomear o projeto de cliente](media/mathclient-new-project-name-159.png "Nomear o projeto de cliente")

1. Escolha **OK** para criar o projeto de aplicativo cliente.

Um projeto de aplicativo de console mínimo é criado para você. O nome do arquivo de origem principal é o mesmo nome do projeto inserido anteriormente. Neste exemplo, o nome usado é **MathClient.cpp**. Você pode compilá-lo, mas ele ainda não usa a DLL.

::: moniker-end

::: moniker range="vs-2015"

### <a name="to-create-a-client-app-in-visual-studio-2015"></a>Para criar um aplicativo cliente no Visual Studio 2015

1. Para criar um aplicativo C++ que use a DLL que você criou, escolha **Arquivo** > **Novo** > **Projeto** na barra de menus.

1. No painel esquerdo da caixa de diálogo **Novo Projeto**, escolha **Win32** em **Modelos** > **Instalados do** > **Visual C++** . No painel central, escolha **Aplicativo de Console Win32**. Especifique o nome do projeto, *MathClient*, na caixa de edição de **nome** . Deixe os valores de **local** padrão e **nome da solução** . Defina a **solução** para **criar uma nova solução**. Marque **criar diretório para obter a solução** se ela estiver desmarcada.

   ![Nomear o projeto de cliente](media/mathclient-project-name.png "Nomear o projeto de cliente")

1. Escolha o botão **OK** para ignorar a caixa de diálogo **Novo Projeto** e iniciar o **Assistente de Aplicativo Win32**. Na página **Visão geral** da caixa de diálogo **Assistente de Aplicativo Win32**, clique no botão **Avançar**.

1. Na página **Configurações do Aplicativo**, em **Tipo de Aplicativo**, escolha **Aplicativo de Console**, caso ainda não esteja marcado.

1. Escolha o botão **Concluir** para criar o projeto.

Quando o assistente for concluído, um projeto de aplicativo de console mínimo será criado para você. O nome do arquivo de origem principal é o mesmo nome do projeto inserido anteriormente. Neste exemplo, o nome usado é **MathClient.cpp**. Você pode compilá-lo, mas ele ainda não usa a DLL.

::: moniker-end

Em seguida, para chamar as funções MathLibrary em seu código-fonte, seu projeto deve incluir o arquivo *MathLibrary. h* . Você poderia copiar esse arquivo de cabeçalho para o projeto do aplicativo cliente e adicioná-lo ao projeto como um item existente. Esse método pode ser uma boa opção para bibliotecas de terceiros. No entanto, se você estiver trabalhando no código para sua DLL e seu cliente ao mesmo tempo, os arquivos de cabeçalho poderão ficar fora de sincronia. Para evitar esse problema, defina o caminho de **diretórios de inclusão adicionais** em seu projeto para incluir o caminho para o cabeçalho original.

### <a name="to-add-the-dll-header-to-your-include-path"></a>Para adicionar o cabeçalho da DLL ao caminho de inclusão

1. Clique com botão direito do mouse no nó **MathClient** no **Gerenciador de Soluções** para abrir a caixa de diálogo **Páginas de Propriedades**.

1. Na caixa suspensa **configuração** , selecione **todas as configurações** , se ainda não estiver selecionado.

1. No painel esquerdo, selecione **Propriedades** > de configuração**C/C++**  > **geral**.

1. No painel de propriedades, escolha o controle suspenso ao lado da caixa de edição **Diretórios de Inclusão Adicionais** e, em seguida, escolha **Editar**.

   ![Editar a propriedade Diretórios de Inclusão Adicionais](media/mathclient-additional-include-directories-property.png "Editar a propriedade Diretórios de Inclusão Adicionais")

1. Clique duas vezes no painel superior da caixa de diálogo **Diretórios de Inclusão Adicionais** para ativar um controle de edição. Ou escolha o ícone de pasta para criar uma nova entrada.

1. No controle de edição, especifique o caminho para o local do arquivo de cabeçalho **MathLibrary.h**. Você pode escolher o controle de reticências ( **...** ) para navegar até a pasta correta.

   Você também pode inserir um caminho relativo dos arquivos de origem do cliente para a pasta que contém os arquivos de cabeçalho da DLL. Se você seguiu as instruções para colocar o projeto cliente em uma solução separada da DLL, o caminho relativo deverá ter esta aparência:

   `..\..\MathLibrary\MathLibrary`

   Se os projetos de DLL e de cliente estiverem na mesma solução, o caminho relativo poderá ser assim:

   `..\MathLibrary`

   Quando os projetos de DLL e cliente estiverem em outras pastas, ajuste o caminho relativo para correspondência. Ou use o controle de reticências para procurar a pasta.

   ![Adicionar o local do cabeçalho à propriedade Diretórios de Inclusão Adicionais](media/mathclient-additional-include-directories.png "Adicionar o local do cabeçalho à propriedade Diretórios de Inclusão Adicionais")

1. Depois de inserir o caminho para o arquivo de cabeçalho na caixa de diálogo **outros diretórios de inclusão** , escolha o botão **OK** . Na caixa de diálogo **páginas de propriedades** , escolha o botão **OK** para salvar as alterações.

Agora você pode incluir o arquivo **MathLibrary.h** e usar as funções que ele declara em seu aplicativo cliente. Substitua o conteúdo de **MathClient.cpp** usando este código:

```cpp
// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
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

Esse código pode ser compilado, mas não vinculado. Se você criar o aplicativo cliente agora, a lista de erros mostrará vários erros LNK2019. Isso porque o seu projeto não tem algumas informações: Você não especificou que seu projeto ainda tem uma dependência na biblioteca *MathLibrary. lib* . E você não disse ao vinculador como encontrar o arquivo *MathLibrary. lib* .

Para corrigir esse problema, você pode copiar o arquivo de biblioteca diretamente em seu projeto de aplicativo cliente. O vinculador o encontraria e o usará automaticamente. No entanto, se a biblioteca e o aplicativo cliente estiverem em desenvolvimento, isso poderá levar a alterações em uma cópia que não são mostradas no outro. Para evitar esse problema, você pode definir a propriedade **dependências adicionais** para informar ao sistema de compilação que seu projeto depende de *MathLibrary. lib*. E você pode definir um caminho de **diretórios de biblioteca adicional** em seu projeto para incluir o caminho para a biblioteca original ao vincular.

### <a name="to-add-the-dll-import-library-to-your-project"></a>Para adicionar a biblioteca de importação da DLL ao projeto

1. Clique com o botão direito do mouse no nó **MathClient** em **Gerenciador de soluções** e escolha **Propriedades** para abrir a caixa de diálogo **páginas de propriedades** .

1. Na caixa suspensa **configuração** , selecione **todas as configurações** , se ainda não estiver selecionado. Ele garante que todas as alterações de propriedade se apliquem a compilações de depuração e de versão.

1. No painel esquerdo, selecione **Propriedades** > de configuração**vinculador** > **entrada**. No painel de propriedades, escolha o controle suspenso ao lado da caixa de edição **Dependências Adicionais** e, em seguida, escolha **Editar**.

   ![Editar a propriedade Dependências Adicionais](media/mathclient-additional-dependencies-property.png "Editar a propriedade Dependências Adicionais")

1. Na caixa de diálogo **dependências adicionais** , adicione *MathLibrary. lib* à lista no controle de edição superior.

   ![Adicionar a dependência de biblioteca](media/mathclient-additional-dependencies.png "Adicionar a dependência de biblioteca")

1. Escolha **OK** para voltar para a caixa de diálogo **Páginas de Propriedades**.

1. No painel esquerdo, selecione **Propriedades** > de configuração**vinculador** > **geral**. No painel de propriedades, selecione o controle suspenso ao lado da caixa de edição **Diretórios de Biblioteca Adicionais** e, em seguida, escolha **Editar**.

   ![Editar a propriedade Diretórios de Biblioteca Adicionais](media/mathclient-additional-library-directories-property.png "Editar a propriedade Diretórios de Biblioteca Adicionais")

1. Clique duas vezes no painel superior da caixa de diálogo **Diretórios de Biblioteca Adicionais** para ativar um controle de edição. No controle de edição, especifique o caminho para o local do arquivo **MathLibrary.lib**. Por padrão, ele está em uma pasta chamada *debug* diretamente sob a pasta da solução dll. Se você criar uma compilação de versão, o arquivo será colocado em uma pasta chamada *Release*. Você pode usar a `$(IntDir)` macro para que o vinculador possa encontrar sua dll, não importa qual tipo de compilação você criar. Se você seguiu as instruções para colocar o projeto do cliente em uma solução separada do projeto da DLL, o caminho relativo deverá ter esta aparência:

   `..\..\MathLibrary\$(IntDir)`

   Se os projetos de DLL e de cliente estiverem na mesma solução, o caminho relativo deverá ser assim:

   `..\MathLibrary\$(IntDir)`

   ![Adicionar o diretório de biblioteca](media/mathclient-additional-library-directories.png "Adicionar o diretório de biblioteca")

1. Depois de inserir o caminho para o arquivo de biblioteca na caixa de diálogo **Diretórios de Biblioteca Adicionais**, escolha o botão **OK** para voltar para a caixa de diálogo **Páginas de Propriedades**. Escolha **OK** para salvar as alterações de propriedade.

Seu aplicativo cliente pode compilar e vincular com êxito, mas ainda não tem tudo aquilo que precisa para ser executado. Quando o sistema operacional carrega seu aplicativo, ele procura a DLL MathLibrary. Se não conseguir encontrar a DLL em determinados diretórios do sistema, o caminho do ambiente ou o diretório local do aplicativo, o carregamento falhará. Dependendo do sistema operacional, você verá uma mensagem de erro como esta:

![Erro de dll MathLibrary não encontrado](media/mathclient-system-error-mathlibrary-dll-not-found.png "Erro de dll MathLibrary não encontrado")

Uma maneira de evitar esse problema é copiar a DLL para o diretório que contém o executável do cliente como parte do processo de compilação. Você pode adicionar um **evento de pós-compilação** ao seu projeto, para adicionar um comando que copia a dll para o diretório de saída da compilação. O comando especificado aqui copia o DLL somente se ele estiver ausente ou tiver sido alterado. Ele usa macros para copiar de e para os locais de depuração ou de lançamento, com base em sua configuração de compilação.

### <a name="to-copy-the-dll-in-a-post-build-event"></a>Para copiar a DLL em um evento pós-compilação

1. Clique com o botão direito do mouse no nó **MathClient** em **Gerenciador de soluções** e escolha **Propriedades** para abrir a caixa de diálogo **páginas de propriedades** .

1. Na caixa da lista suspensa **Configuração**, escolha **Todas as Configurações** caso a opção ainda não esteja marcada.

1. No painel esquerdo, selecione **Propriedades** > de configuração eventos de**Build de eventos** > **de**pós-compilação.

1. No painel de propriedades, selecione o controle de edição no campo **linha de comando** . Se você seguiu as instruções para colocar o projeto do cliente em uma solução separada do projeto da DLL, digite este comando:

   `xcopy /y /d "..\..\MathLibrary\$(IntDir)MathLibrary.dll" "$(OutDir)"`

   Se os projetos de DLL e cliente estiverem no mesmo diretório de solução, digite este comando:

   `xcopy /y /d "..\MathLibrary\$(IntDir)MathLibrary.dll" "$(OutDir)"`

   ![Adicionar o comando de pós-compilação](media/mathclient-post-build-command-line.png "Adicionar o comando de pós-compilação")

1. Escolha o botão **OK** para salvar suas alterações nas propriedades do projeto.

Agora, seu aplicativo cliente tem tudo aquilo que precisa para ser compilado e executado. Compile o aplicativo escolhendo **Compilar** > **Compilar Solução** na barra de menus. A janela de **saída** no Visual Studio deve ter algo semelhante ao exemplo a seguir, dependendo da sua versão do Visual Studio:

```Output
1>------ Build started: Project: MathClient, Configuration: Debug Win32 ------
1>MathClient.cpp
1>MathClient.vcxproj -> C:\Users\username\Source\Repos\MathClient\Debug\MathClient.exe
1>1 File(s) copied
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```

Parabéns, você criou um aplicativo que chama as funções na sua DLL. Agora, execute seu aplicativo para ver o que ele faz. Na barra de menus, escolha **Depurar** > **Iniciar Sem Depurar**. O Visual Studio abre uma janela de comando para o programa ser executado. A última parte da saída deverá se parecer com:

![Iniciar o aplicativo cliente sem depuração](media/mathclient-run-without-debugging.png "Iniciar o aplicativo cliente sem depuração")

Pressione qualquer tecla para fechar a janela de comando.

Agora que você criou uma DLL e um aplicativo cliente, comece a fazer experimentos. Tente definir pontos de interrupção no código do aplicativo cliente e executar o aplicativo no depurador. Veja o que acontece quando você entra em uma chamada de biblioteca. Adicione outras funções à biblioteca ou crie outro aplicativo cliente que usa sua DLL.

Quando implantar seu aplicativo, implante também as DLLs que ele usa. A maneira mais simples de fazer as DLLs que você cria ou que você inclui de terceiros, disponível é colocá-las no mesmo diretório que seu aplicativo. Ele é conhecido como *implantação de aplicativo local*. Para saber mais sobre implantação, confira [Implantação no Visual C++](../windows/deployment-in-visual-cpp.md).

## <a name="see-also"></a>Consulte também

[Chamando funções DLL de aplicativos Visual Basic](calling-dll-functions-from-visual-basic-applications.md)
