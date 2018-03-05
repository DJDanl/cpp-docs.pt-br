---
title: "Passo a passo: Criar e usar sua própria biblioteca de vínculo dinâmico (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs:
- C++
helpviewer_keywords:
- libraries [C++], DLLs
- DLLs [C++], walkthroughs
ms.assetid: 3ae94848-44e7-4955-bbad-7d40f493e941
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bdcc02cf7c86b85684df0e8d8b7a1f0049ff7e25
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-create-and-use-your-own-dynamic-link-library-c"></a>Passo a passo: Criar e usar sua própria biblioteca de vínculo dinâmico (C++)

Este passo a passo mostra como usar o IDE do Visual Studio para criar sua própria biblioteca de vínculo dinâmico (DLL) escrita em C++ e, em seguida, usá-lo de outro aplicativo de C++. DLLs são um dos tipos mais úteis de componentes do Windows. Você pode usá-los como uma maneira de compartilhar o código e os recursos, para reduzir o tamanho de seus aplicativos e para facilitar a manutenção e estender seus aplicativos. Neste passo a passo, você cria uma DLL que implementa algumas funções matemáticas e, em seguida, cria um aplicativo de console que usa as funções da DLL. Ao longo do caminho, você deve obter uma introdução a algumas das técnicas e as convenções usadas no Windows DLLs programação.

Este passo a passo apresenta estas tarefas:

- Crie um projeto DLL no Visual Studio.

- Adicione variáveis e funções exportadas para a DLL.

- Crie um projeto de aplicativo de console no Visual Studio.

- Use as funções e variáveis importados da DLL no aplicativo do console.

- Execute o aplicativo concluído.

Como uma biblioteca estaticamente vinculada, uma DLL _exporta_ variáveis, funções e recursos por nome e seu aplicativo _importa_ esses nomes para usar essas variáveis, funções e recursos. Ao contrário de uma biblioteca estaticamente vinculada, Windows conecta as importações em seu aplicativo para as exportações em uma DLL em tempo de carregamento ou em tempo de execução, em vez de conectar-se ao tempo de link. O Windows exige informações extras que não faz parte do modelo de compilação de C++ padrão para estabelecer essas conexões. O compilador do Visual C++ implementa algumas extensões específicas do Microsoft c++ para fornecer essas informações extras. Explicaremos essas extensões, visite.

Este passo a passo cria duas soluções do Visual Studio; uma que cria a DLL e outra que cria o aplicativo cliente. A DLL usa a convenção de chamada de C para que ele possa ser chamado de aplicativos criados com outras linguagens, como a plataforma e chamar e convenções de vinculação correspondem. O aplicativo de cliente utiliza _vinculação implícita_, onde o Windows vincula o aplicativo para a DLL no tempo de carregamento. Isso permite que o aplicativo chamar as funções fornecidas pelo DLL assim como as funções em uma biblioteca vinculada estaticamente.

Este passo a passo não aborda algumas situações comuns. Ela não mostra o uso de C++ DLLs por outras linguagens de programação. Ela não mostra como criar uma DLL somente de recursos. Ele também não mostra o uso de vinculação explícita para carregar DLLs em tempo de execução em vez de em tempo de carregamento. Tenha a certeza, você pode usar o Visual C++ para fazer todas estas coisas. Para obter links para obter mais informações sobre DLLs, consulte [DLLs no Visual C++](../build/dlls-in-visual-cpp.md). Para obter mais informações sobre vinculação implícita e explícita de vinculação, consulte [determinar qual vincular método usar](../build/linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use). Para obter informações sobre como criar DLLs de C++ para uso com linguagens de programação que usam convenções de vinculação de linguagem C, consulte [exportar funções C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md). Para obter informações sobre como criar DLLs para uso com linguagens .NET, consulte [chamando funções DLL de aplicativos do Visual Basic](../build/calling-dll-functions-from-visual-basic-applications.md).

Este passo a passo usa o Visual Studio de 2017, mas o código e a maioria das instruções é aplicáveis a versões anteriores. As etapas para criar novos projetos alterado a partir do Visual Studio 2017 versão 15,3. Este passo a passo descreve como criar projetos para versões mais recentes e anteriores. Procure as etapas que correspondem à sua versão do Visual Studio.

## <a name="prerequisites"></a>Pré-requisitos

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. É recomendável Windows 10 para a melhor experiência de desenvolvimento.

- Uma cópia do Visual Studio de 2017. Para obter informações sobre como baixar e instalar o Visual Studio, consulte [instalar o Visual Studio 2017](/visualstudio/install/install-visual-studio). Quando você executar a instalação, verifique se o **desenvolvimento de área de trabalho com C++** é verificada cargas de trabalho. Não se preocupe se você não instalar essa carga de trabalho quando você instalou o Visual Studio. Você pode executar o instalador novamente e instale-o agora.

   ![Desenvolvimento de área de trabalho com C++](media/desktop-development-with-cpp.png "desenvolvimento de área de trabalho com C++")

- Um entendimento dos fundamentos de como usar o Visual Studio IDE. Se você tiver usado a aplicativos de área de trabalho do Windows antes, você provavelmente pode acompanhar. Para obter uma introdução, consulte [tour pelos recursos do Visual Studio IDE](/visualstudio/ide/visual-studio-ide).

- Um entendimento de suficiente os conceitos básicos da linguagem C++ para acompanhar. Não se preocupe, nós não fazer nada muito complicado.

## <a name="create-the-dll-project"></a>Criar o projeto DLL

Este conjunto de tarefas, criar um projeto para a DLL, adicione código e compilá-lo. Para começar, inicie o Visual Studio IDE e entrar se você precisar. As instruções para Visual Studio 2017 versão 15,3 vir primeira. Instruções para versões anteriores posteriormente, portanto Ignorar se você precisa.

### <a name="to-create-a-dll-project-in-visual-studio-2017-version-153-or-later"></a>Para criar um projeto DLL no Visual Studio 2017 versão 15,3 ou posterior

1. Na barra de menus, escolha **arquivo**, **novo**, **projeto** para abrir o **novo projeto** caixa de diálogo.

1. No painel esquerdo do **novo projeto** caixa de diálogo caixa, expanda **instalado** e **Visual C++** se necessário e, em seguida, escolha **Windows Desktop**. No painel central, selecione **Assistente de área de trabalho do Windows**. Digite `MathLibrary` no **nome** caixa para especificar um nome para o projeto.

   ![Nomeie o projeto MathLibrary](media/mathlibrary-new-project-name-153.png "Nomeie o projeto MathLibrary")

1. Escolha o **Okey** botão para ignorar o **novo projeto** caixa de diálogo e iniciar o **projeto de área de trabalho do Windows** assistente.

1. No **projeto de área de trabalho do Windows** assistente em **tipo de aplicativo**, selecione **biblioteca de vínculo dinâmico (. dll)**.

   ![Criar a DLL no Assistente de projeto de área de trabalho do Windows](media/mathlibrary-desktop-project-wizard-dll.png "criar DLL no Assistente de projeto de área de trabalho do Windows")

1. Escolha o botão **OK** para criar o projeto.

> [!NOTE]
> São necessárias etapas adicionais para corrigir um problema no Visual Studio 2017 versão 15,3. Siga estas instruções para verificar se é necessário fazer essa alteração.
>
>1. Em **Solution Explorer**, se ainda não estiver selecionado, selecione o **MathLibrary** projeto em **solução 'MathLibrary'**.
>
>1. Na barra de menus, escolha **Projeto**, **Propriedades**.
>
>1. No painel esquerdo do **páginas de propriedade** caixa de diálogo, selecione **pré-processador** em **propriedades de configuração**, **C/C++**. Verifique o conteúdo do **definições de pré-processador** propriedade.<br/><br/>![Verifique a propriedade de definições de pré-processador](media/mathlibrary-153bug-preprocessor-definitions-check.png "Verifique a propriedade de definições de pré-processador")<br/><br/>Se você vir **MATHLIBRARY &#95; Exportações** no **definições de pré-processador** lista, você não precisa alterar nada. Se você vir **MathLibrary &#95; Exportações** continuar em vez disso, em seguida, siga estas etapas.
>
>1. Na parte superior do **páginas de propriedade** caixa de diálogo, altere o **configuração** lista suspensa para **todas as configurações de**.
>
>1. No painel Propriedades, selecione o controle de lista suspensa ao lado da caixa de edição para **definições de pré-processador**e, em seguida, escolha **editar**.<br/><br/>![Editar a propriedade de definições de pré-processador](media/mathlibrary-153bug-preprocessor-definitions-property.png "editar a propriedade de definições de pré-processador")
>
>1. No painel superior a **definições de pré-processador** caixa de diálogo, adicione um novo símbolo, `MATHLIBRARY_EXPORTS`.<br/><br/>![Adicionar o símbolo MATHLIBRARY_EXPORTS](media/mathlibrary-153bug-preprocessor-definitions-dialog.png "adicionar o símbolo MATHLIBRARY_EXPORTS")
>
>1. Escolha **Okey** para ignorar o **definições de pré-processador** caixa de diálogo e, em seguida, escolha **Okey** para salvar suas alterações para as propriedades do projeto.

### <a name="to-create-a-dll-project-in-older-versions-of-visual-studio"></a>Para criar um projeto DLL em versões mais antigas do Visual Studio

1. Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.

1. No painel esquerdo do **novo projeto** caixa de diálogo caixa, expanda **instalado**, **modelos**e selecione **Visual C++**e, em seguida, no Centro painel, selecione **aplicativo do Console Win32**. Digite `MathLibrary` no **nome** Editar caixa para especificar um nome para o projeto.

   ![Nomeie o projeto MathLibrary](media/mathlibrary-project-name.png "Nomeie o projeto MathLibrary")

1. Escolha o **Okey** botão para ignorar o **novo projeto** caixa de diálogo e iniciar o **Assistente de aplicativo Win32**.

   ![Visão geral do Assistente de aplicativo Win32](media/mathlibrary-project-wizard-1.png "visão geral do Assistente de aplicativo Win32")

1. Escolha o botão **Avançar**. Sobre o **configurações do aplicativo** página em **tipo de aplicativo**, selecione **DLL**.

   ![Criar a DLL no Assistente de aplicativo Win32](media/mathlibrary-project-wizard-2.png "criar DLL no Assistente de aplicativo Win32")

1. Escolha o **concluir** botão para criar o projeto.

Quando o assistente concluir a solução, você pode ver os arquivos de projeto e o código-fonte gerados no **Solution Explorer** janela no Visual Studio.

![Gerou a solução no Visual Studio](media/mathlibrary-solution-explorer-153.png "gerou a solução no Visual Studio")

Direita agora, essa DLL não faz muito. Em seguida, você pode criar um arquivo de cabeçalho para declarar as funções em sua DLL exporta e, em seguida, adicionar as definições de função para a DLL para torná-los mais úteis.

### <a name="to-add-a-header-file-to-the-dll"></a>Para adicionar um arquivo de cabeçalho para a DLL

1. Para criar um arquivo de cabeçalho para suas funções, na barra de menus, escolha **projeto**, **Adicionar Novo Item**.

1. No **Adicionar Novo Item** caixa de diálogo, no painel esquerdo, selecione **Visual C++**. No painel central, selecione **o arquivo de cabeçalho (. h)**. Especifique `MathLibrary.h` como o nome para o arquivo de cabeçalho.

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

Esse arquivo de cabeçalho declara algumas funções para produzir uma sequência Fibonacci generalizada, determinados dois valores iniciais. Uma chamada para `fibonacci_init(1, 1)` gera a sequência de número de Fibonacci familiar.

Observe as instruções de pré-processador na parte superior do arquivo. Por padrão, o modelo de novo projeto para uma DLL adiciona  ***PROJECTNAME*&#95; Exportações** para as macros de pré-processador definidas para o projeto DLL. Neste exemplo, o Visual Studio define **MATHLIBRARY &#95; Exportações** quando seu projeto de DLL MathLibrary for compilado. (O assistente no Visual Studio 2017 versão 15,3 não força essa definição de símbolo para letras maiusculas. Se você nomear o projeto "MathLibrary", em seguida, o símbolo definido é MathLibrary &#95; EXPORTAÇÕES em vez de MATHLIBRARY &#95; EXPORTA. That's por que não há etapas adicionais acima para adicionar este símbolo.)

Quando o **MATHLIBRARY &#95; Exportações** macro for definida, o **MATHLIBRARY &#95; API** macro define o `__declspec(dllexport)` modificador em declarações de função. Esse modificador informa ao compilador e vinculador para exportar uma função ou variável de DLL, para que ele pode ser usado por outros aplicativos. Quando **MATHLIBRARY &#95; Exportações** é indefinido, por exemplo, quando o arquivo de cabeçalho está incluído por um aplicativo cliente, **MATHLIBRARY &#95; API** se aplica a `__declspec(dllimport)` modificador para as declarações. Esse modificador otimiza a importação de função ou variável em um aplicativo. Para obter mais informações, consulte [dllexport, dllimport](../cpp/dllexport-dllimport.md).

### <a name="to-add-an-implementation-to-the-dll"></a>Para adicionar uma implementação para a DLL

1. Na janela do editor, selecione a guia para **MathLibrary.cpp** se ele já está aberto. Se não, em **Solution Explorer**, abra **MathLibrary.cpp** no **arquivos de origem** pasta do **MathLibrary** projeto.

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

Para verificar se tudo funciona até então, compile a biblioteca de vínculo dinâmico. Para compilar, escolha **criar**, **compilar solução** na barra de menus. A saída deve ter esta aparência:

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

Quando você criar uma DLL, você deve pensar em como sua DLL pode ser usado. Para compilar o código que chama as funções exportadas por uma DLL, as declarações devem ser incluídas no código de origem do cliente. Em tempo de link, quando essas chamadas de funções DLL são resolvidas, o vinculador deve ter uma *Importar biblioteca*, um tipo especial de arquivo de biblioteca que contém informações para o Windows sobre como localizar as funções, em vez do código real. E, em tempo de execução, a DLL deve estar disponível para o cliente, em um local que o sistema operacional pode achar.

Para fazer uso de uma DLL, se o proprietário ou uma DLL de terceiros, o projeto de aplicativo cliente deve ser capaz de encontrar os cabeçalhos que declara o DLL exporta, as bibliotecas de importação para o vinculador e a DLL em si. Uma maneira de fazer isso é copiar todos os arquivos em seu projeto de cliente. DLLs de terceiros que não devem mudar enquanto o cliente está em desenvolvimento, isso pode ser a melhor maneira de usá-los. No entanto, quando você também pode criar a DLL, é melhor evitar a duplicação. Se você fizer uma cópia dos arquivos DLL que estão em desenvolvimento, acidentalmente pode alterar um arquivo de cabeçalho em uma cópia, mas não o outro ou usar uma biblioteca desatualizada. Para evitar esse problema, recomendamos que você defina o caminho de inclusão no seu projeto de cliente para incluir os arquivos de cabeçalho DLL do projeto de DLL. Além disso, defina o caminho de biblioteca em seu projeto de cliente para incluir as bibliotecas de importação DLL do projeto de DLL. E, finalmente, copie a DLL compilada do projeto DLL no diretório de saída de compilação. Isso garante que o aplicativo cliente usa o mesmo código DLL que você criar.

### <a name="to-create-a-client-app-in-visual-studio-2017-version-153-or-later"></a>Para criar um aplicativo cliente no Visual Studio 2017 versão 15,3 ou posterior

1. Para criar um aplicativo em C++ que usa a DLL que você acabou de criar, na barra de menus, escolha **arquivo**, **novo**, **projeto**.

1. No painel esquerdo do **novo projeto** caixa de diálogo, selecione **Windows Desktop** em **instalado**, **Visual C++**. No painel central, selecione **Assistente de área de trabalho do Windows**. Especifique o nome do projeto, `MathClient`, no **nome** caixa de edição.

   ![Nomeie o projeto cliente](media/mathclient-new-project-name-153.png "nome do projeto de cliente")

1. Escolha **Okey** para iniciar o **projeto de área de trabalho do Windows** assistente. No assistente, escolha **Okey** para criar o projeto de aplicativo do cliente.

### <a name="to-create-a-client-app-in-older-versions-of-visual-studio-2017"></a>Para criar um aplicativo cliente em versões anteriores do Visual Studio de 2017

1. Para criar um aplicativo em C++ que usa a DLL que você acabou de criar, na barra de menus, escolha **arquivo**, **novo**, **projeto**.

1. No painel esquerdo do **novo projeto** caixa de diálogo, selecione **Win32** em **instalado**, **modelos**, **deVisualC++**. No painel central, selecione **aplicativo do Console Win32**. Especifique o nome do projeto, `MathClient`, no **nome** caixa de edição.

   ![Nomeie o projeto cliente](media/mathclient-project-name.png "nome do projeto de cliente")

1. Escolha o **Okey** botão para ignorar o **novo projeto** caixa de diálogo e iniciar o **Assistente de aplicativo Win32**. No **visão geral** página do **Assistente de aplicativo Win32** caixa de diálogo caixa, escolha o **próximo** botão.

1. No **configurações do aplicativo** página em **tipo de aplicativo**, selecione **aplicativo de Console** se já não estiver selecionada.

1. Escolha o **concluir** botão para criar o projeto.

Quando o assistente for concluído, um projeto de aplicativo de console mínimo é criado para você. O nome do arquivo de origem principal é o mesmo que o nome do projeto que você inseriu anteriormente. Neste exemplo, ele é chamado **MathClient.cpp**. Construí-lo, mas ele não usa a DLL ainda.

Em seguida, para chamar as funções MathLibrary em seu código-fonte, seu projeto deve incluir o arquivo MathLibrary.h. Você pode copiar esse arquivo de cabeçalho para o seu projeto de aplicativo do cliente e adicioná-lo ao projeto como um item existente. Isso pode ser uma boa escolha para bibliotecas de terceiros. No entanto, se você estiver trabalhando no código para a DLL ao mesmo tempo como seu cliente, que pode levar a alterações no arquivo de um cabeçalho que não são refletidas no outro. Para evitar esse problema, você pode alterar o **diretórios de inclusão adicionais** caminho em seu projeto para incluir o caminho para o cabeçalho original.

### <a name="to-add-the-dll-header-to-your-include-path"></a>Para adicionar o cabeçalho DLL para o caminho de inclusão

1. Abra o **páginas de propriedade** caixa de diálogo para o **MathClient** projeto.

1. No **configuração** caixa de lista suspensa, selecione **todas as configurações de** se já não estiver selecionada.

1. No painel esquerdo, selecione **geral** em **propriedades de configuração**, **C/C++**.

1. No painel Propriedades, selecione o controle de lista suspensa ao lado de **diretórios de inclusão adicionais** caixa de edição e, em seguida, escolha **editar**.

   ![Editar a propriedade de diretórios de inclusão adicionais](media/mathclient-additional-include-directories-property.png "editar a propriedade de diretórios de inclusão adicionais")

1. Clique duas vezes no painel superior a **diretórios de inclusão adicionais** caixa de diálogo para habilitar um controle de edição.

1. No controle de edição, especifique o caminho para o local do **MathLibrary.h** arquivo de cabeçalho. Nesse caso, você pode usar um caminho relativo:

   `..\..\MathLibrary\MathLibrary`

   ![Adicionar o local do cabeçalho para a propriedade de diretórios de inclusão adicionais](media/mathclient-additional-include-directories.png "adicionar o local do cabeçalho para a propriedade de diretórios de inclusão adicionais")

1. Depois de inserir o caminho para o arquivo de cabeçalho no **diretórios de inclusão adicionais** caixa de diálogo caixa, escolha o **Okey** botão para voltar para o **páginas de propriedade** caixa de diálogo, e em seguida, escolha o **Okey** botão para salvar suas alterações.

Você pode incluir o **MathLibrary.h** de arquivos e usar as funções que ele declara em seu aplicativo cliente. Substitua o conteúdo do **MathClient.cpp** usando este código:

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

Esse código pode ser compilado, mas não vinculado, porque o vinculador não é possível localizar a biblioteca de importação necessária para compilar o aplicativo ainda. O vinculador deve ser capaz de localizar o arquivo MathLibrary.lib para vincular com êxito. Você deve adicionar o arquivo de MathLibrary.lib para a compilação, definindo o **dependências adicionais** propriedade. Novamente, você poderá copiar o arquivo de biblioteca em seu projeto de aplicativo do cliente, mas se a biblioteca e o aplicativo cliente estão em desenvolvimento, que pode resultar em alterações em uma cópia que não são refletidas no outro. Para evitar esse problema, você pode alterar o **diretórios de biblioteca adicionais** caminho em seu projeto para incluir o caminho para a biblioteca original quando você vincula.

### <a name="to-add-the-dll-import-library-to-your-project"></a>Para adicionar a biblioteca de importação DLL ao seu projeto

1. Abra o **páginas de propriedade** caixa de diálogo para o **MathClient** projeto.

1. No **configuração** caixa de lista suspensa, selecione **todas as configurações de** se já não estiver selecionada.

1. No painel esquerdo, selecione **entrada** em **propriedades de configuração**, **vinculador**. No painel Propriedades, selecione o controle de lista suspensa ao lado de **dependências adicionais** caixa de edição e, em seguida, escolha **editar**.

   ![Editar a propriedade dependências adicionais](media/mathclient-additional-dependencies-property.png "editar a propriedade dependências adicionais")

1. No **dependências adicionais** caixa de diálogo, adicione `MathLibrary.lib` controle de edição para a lista na parte superior.

   ![Adicionar a dependência de biblioteca](media/mathclient-additional-dependencies.png "adicionar a dependência de biblioteca")

1. Escolha **Okey** para voltar para o **páginas de propriedade** caixa de diálogo.

1. No painel esquerdo, selecione **geral** em **propriedades de configuração**, **vinculador**. No painel Propriedades, selecione o controle de lista suspensa ao lado de **diretórios de biblioteca adicionais** caixa de edição e, em seguida, escolha **editar**.

   ![Editar a propriedade de diretórios de biblioteca adicionais](media/mathclient-additional-library-directories-property.png "editar a propriedade de diretórios de biblioteca adicionais")

1. Clique duas vezes no painel superior a **diretórios de biblioteca adicionais** caixa de diálogo para habilitar um controle de edição. No controle de edição, especifique o caminho para o local do **MathLibrary.lib** arquivo. Insira o valor para usar uma macro de compilações funciona para depuração e liberação:

   `..\..\MathLibrary\$(IntDir)`

   ![Adicione o diretório de biblioteca](media/mathclient-additional-library-directories.png "adicionar o diretório de biblioteca")

1. Depois de inserir o caminho para o arquivo de biblioteca no **diretórios de biblioteca adicionais** caixa de diálogo caixa, escolha o **Okey** botão para voltar para o **páginas de propriedade** caixa de diálogo.

O aplicativo cliente pode compilar e vincular com êxito, mas ainda não tem tudo o que precisa para ser executado. Quando o sistema operacional carrega seu aplicativo, ele procura MathLibrary DLL. Se ele não é possível localizar a DLL em determinados diretórios do sistema, o caminho de ambiente ou o diretório de aplicativo local, o carregamento falhará. Uma maneira para evitar esse problema é copiar a DLL para o diretório que contém o executável do cliente como parte do processo de compilação. Para copiar a DLL, você pode adicionar uma **evento de pós-compilação** ao seu projeto, para adicionar um comando que copia a DLL seu diretório de saída de compilação. O comando especificado aqui copia a DLL somente se ele está ausente ou foi alterada e usa as macros para copiar de e para os locais de depuração ou de varejo corretos para sua configuração.

### <a name="to-copy-the-dll-in-a-post-build-event"></a>Para copiar o DLL em um evento de pós-compilação

1. Abra o **páginas de propriedade** caixa de diálogo para o **MathClient** projeto se ainda não estiver aberto.

1. Na caixa de lista suspensa de configuração, selecione **todas as configurações de** se já não estiver selecionada.

1. No painel esquerdo, selecione **evento de pós-compilação** em **propriedades de configuração**, **eventos de Build**.

1. No painel Propriedades, selecione o controle de edição no **linha de comando** campo e, em seguida, digite este comando:

   `xcopy /y /d "..\..\MathLibrary\$(IntDir)MathLibrary.dll" "$(OutDir)"`

   ![Adicione o comando de pós-compilação](media/mathclient-post-build-command-line.png "adicionar o comando de pós-compilação")

1. Escolha o **Okey** botão para salvar as alterações em Propriedades do projeto.

Agora o seu aplicativo cliente tem tudo o que precisa para compilar e executar. Criar o aplicativo escolhendo **criar**, **compilar solução** na barra de menus. O **saída** janela no Visual Studio deve conter algo assim:

```Output
1>------ Build started: Project: MathClient, Configuration: Debug Win32 ------
1>stdafx.cpp
1>MathClient.cpp
1>MathClient.vcxproj -> C:\Users\username\Source\Repos\MathClient\Debug\MathClient.exe
1>MathClient.vcxproj -> C:\Users\username\Source\Repos\MathClient\Debug\MathClient.pdb (Partial PDB)
1>1 File(s) copied
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
```

Parabéns, você criou um aplicativo que chama as funções em sua DLL. Agora execute o aplicativo para ver o que ele faz. Na barra de menus, escolha **depurar**, **Start Without Debugging**. O Visual Studio abrirá uma janela de comando para o programa seja executado. A última parte da saída deve ter esta aparência:

![Iniciar o aplicativo de cliente sem depuração](media/mathclient-run-without-debugging.png "iniciar o aplicativo de cliente sem depuração")

Pressione qualquer tecla para fechar a janela de comando.

Agora que você criou uma DLL e um aplicativo cliente, você pode experimentar. Tente definir pontos de interrupção no código do aplicativo cliente e executar o aplicativo no depurador. Veja o que acontece quando você entra em uma chamada de biblioteca. Adicione outras funções na biblioteca, ou escrever outro aplicativo de cliente que usa a DLL.

Quando você implantar seu aplicativo, você também deve implantar as DLLs que ele usa. A maneira mais simples para tornar as DLLs que você cria ou que você incluir de terceiros disponíveis para seu aplicativo é colocá-los no mesmo diretório do seu aplicativo, também conhecido como *implantação de aplicativo local*. Para obter mais informações sobre a implantação, consulte [implantação no Visual C++](..\ide\deployment-in-visual-cpp.md).

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)  
[Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)  
[Passo a passo: implantando o programa (C++)](../ide/walkthrough-deploying-your-program-cpp.md)  
[Chamando funções DLL de aplicativos Visual Basic](../build/calling-dll-functions-from-visual-basic-applications.md)