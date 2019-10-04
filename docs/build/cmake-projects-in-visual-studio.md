---
title: Projetos do CMake no Visual Studio
ms.date: 10/01/2019
helpviewer_keywords:
- CMake in Visual C++
ms.assetid: 444d50df-215e-4d31-933a-b41841f186f8
ms.openlocfilehash: 168f5b0aac34757a9c2d73bcebc908a0d58721fe
ms.sourcegitcommit: b85e1db6b7d4919852ac6843a086ba311ae97d40
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2019
ms.locfileid: "71925572"
---
# <a name="cmake-projects-in-visual-studio"></a>Projetos do CMake no Visual Studio

O CMake é uma ferramenta multiplataforma de software livre para definir os processos de build executados em várias plataformas. Esse artigo pressupõe que você está familiarizado com CMake. Você pode aprender mais sobre isso em [Compilar, Testar e Empacotar seu Software com o CMake](https://cmake.org/). 

> [!NOTE]
> O CMake se tornou cada vez mais integrado ao Visual Studio nas últimas versões. Para ver as informações corretas para a versão que você está usando, verifique se o seletor de versão no canto superior esquerdo desta página está definido corretamente. 

::: moniker range="vs-2019"

O  **C++ componente ferramentas do cmake para Windows** usa o recurso [abrir pasta](https://docs.microsoft.com/en-us/cpp/build/open-folder-projects-cpp?view=vs-2019) para consumir arquivos de projeto CMake (como CMakeLists. txt) diretamente para fins de IntelliSense e navegação. Há suporte para geradores Ninja e Visual Studio. Se você usar um gerador do Visual Studio, um arquivo de projeto temporário será gerado e passado para msbuild.exe, mas nunca será carregado para as finalidades do IntelliSense ou de navegação. Você também pode importar um cache CMake existente.

## <a name="installation"></a>Instalação

O CMake Tools for Windows é instalado por padrão como parte do **desenvolvimento de desktop C++ com** carga de trabalho e como parte do **desenvolvimento C++ do Linux com** a carga de trabalho. **C++** Consulte [projetos de CMake de plataforma cruzada](../linux/cmake-linux-project.md) para obter mais informações.

![Componente CMake na carga de trabalho Desktop com C++](media/cmake-install-2019.png)

Para obter mais informações, confira [Instalar a carga de trabalho do Linux em C++ no Visual Studio](../linux/download-install-and-setup-the-linux-development-workload.md).

## <a name="ide-integration"></a>Integração com o IDE

Quando você escolhe **arquivo > abrir > pasta** para abrir uma pasta que contém um arquivo CMakeLists. txt, ocorre o seguinte:

- O Visual Studio adiciona itens **CMake** ao menu **projeto** , com comandos para exibir e editar scripts CMake.

- O **Gerenciador de Soluções** exibe a estrutura de pastas e os arquivos.

- O Visual Studio executa o CMake. exe e gera o cache CMake para a *configuração*padrão, que é a depuração x64. A linha de comando do CMake é exibida na **Janela de Saída**, juntamente com uma saída adicional do CMake.

- Em segundo plano, o Visual Studio começa a indexar os arquivos de origem para habilitar o IntelliSense, as informações de navegação, a refatoração e assim por diante. Conforme você trabalha, o Visual Studio monitora as alterações feitas no editor e também em disco para manter seu índice em sincronia com as fontes.

Você pode abrir pastas que contêm qualquer quantidade de projetos do CMake. O Visual Studio detecta e configura todos os arquivos CMakeLists.txt "raiz" no workspace. As operações do CMake (configuração, build, depuração), bem como o C++ IntelliSense e a navegação, estão disponíveis para todos os projetos do CMake no workspace.

![Projeto do CMake com várias raízes](media/cmake-multiple-roots.png)

Você também pode exibir seus projetos logicamente organizados pelos destinos. Escolha **Exibição de destinos** na lista suspensa na barra de ferramentas do **Gerenciador de Soluções**:

![Botão de exibição de destinos do CMake](media/cmake-targets-view.png)

O Visual Studio usa um arquivo chamado **CMakeSettings. JSON** para armazenar variáveis de ambiente ou opções de linha de comando para CMake. exe. O **CMakeSettings. JSON** também permite que você defina e armazene várias configurações de compilação de CMake e alterne convenientemente entre elas no IDE. No Visual Studio 2019, o **Editor de configurações do cmake** fornece uma maneira conveniente de editar suas configurações. Consulte [Personalizar configurações de CMake](customize-cmake-settings.md) para obter mais informações.

Caso contrário, use **CMakeLists. txt** da mesma forma que faria em qualquer projeto CMake para especificar arquivos de origem, localizar bibliotecas, definir opções de compilador e vinculador e especificar outras informações relacionadas ao sistema de compilação.

Se você precisar passar argumentos para um executável no momento da depuração, poderá usar outro arquivo chamado **Launch. vs. JSON**. Em alguns cenários, o Visual Studio gerará automaticamente esses arquivos e você pode editá-los manualmente. Você também pode criar o arquivo por conta própria.

> [!NOTE]
> Para outros tipos de projetos de pasta aberta, dois arquivos JSON adicionais são usados: **CppProperties. JSON** e **Tasks. vs. JSON**. Nenhum deles é relevante para projetos do CMake.

## <a name="open-an-existing-cache"></a>Abrir um cache existente

Quando você abre um cache CMake existente, o Visual Studio não tentará gerenciar seu cache e criar a árvore para você. Isso dá às suas ferramentas personalizadas ou preferenciais o controle completo sobre como o CMake configura seu projeto. Você pode abrir um cache existente no Visual Studio via **arquivo > abrir > CMake** e navegar para um CMakeCache. txt existente. Como alternativa, se você já tiver aberto o projeto no Visual Studio, poderá adicionar um cache existente a ele da mesma maneira que adicionaria uma nova configuração. Para obter mais informações, consulte nossa postagem de blog sobre como [abrir um cache existente no Visual Studio](https://devblogs.microsoft.com/cppblog/open-existing-cmake-caches-in-visual-studio/).

## <a name="building-cmake-projects"></a>Compilando projetos do CMake

Para compilar um projeto do CMake, você tem estas opções:

1. Na barra de ferramentas geral, localize o menu suspenso **configurações** . Ele provavelmente mostra "x64-debug" por padrão. Selecione a configuração desejada e pressione **F5**ou clique no botão **executar** (triângulo verde) na barra de ferramentas. O projeto será compilado automaticamente pela primeira vez, assim como uma solução do Visual Studio.

1. Clique com o botão direito do mouse em CMakeLists.txt e selecione **Build** no menu de contexto. Se você tiver vários destinos na estrutura de pastas, opte por compilar todos ou apenas um destino específico.

1. No menu principal, selecione **compilar > compilar tudo** (**F7** ou **Ctrl + Shift + B**). Verifique se um destino do CMake já está selecionado na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**.

![Comando de menu de build do CMake](media/cmake-build-menu.png "Menu de comando de build do CMake")

Você pode personalizar configurações de compilação, variáveis de ambiente, argumentos de linha de comando e outras configurações sem modificar o arquivo CMakeLists. txt usando o **Editor de configurações do cmake**. Para obter mais informações, confira [Personalizar configurações do CMake](customize-cmake-settings.md).

Como se esperaria, os resultados do build são mostrados na **Janela de Saída** e na **Lista de Erros**.

![Erros de build do CMake](media/cmake-build-errors.png "CMake build errors")

Em uma pasta com vários destinos de build, escolha o item **Build** no menu do **CMake** ou o menu de contexto **CMakeLists.txt** para especificar qual destino do CMake compilar. Se você pressionar **Ctrl+Shift+B** em um projeto do CMake, isso compilará o documento ativo atual.

## <a name="debugging-cmake-projects"></a>Depurando projetos do CMake

Para depurar um projeto do CMake, escolha a configuração desejada e pressione **F5** ou pressione o botão **Executar** na barra de ferramentas. Se o botão **Executar** indicar "Selecione o Item de Inicialização", selecione a seta suspensa e escolha o destino que deseja executar. (Em um projeto do CMake, a opção "Documento atual" só é válida para arquivos .cpp.)

![Botão de execução do CMake](media/cmake-run-button.png "Botão de execução do CMake")

Os comandos **Executar** ou **F5** primeiro compilam o projeto se as alterações foram feitas desde o build anterior.

Você pode personalizar uma sessão de depuração CMake definindo as propriedades no arquivo **Launch. vs. JSON** . Para obter mais informações, confira [Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md).

## <a name="just-my-code-for-cmake-projects"></a>Apenas Meu Código para projetos CMake

Quando você cria para o Windows usando o compilador MSVC, seus projetos CMake têm suporte apenas para a depuração de meu código no compilador e no vinculador, se a opção estiver habilitada no Visual Studio. Para alterar a configuração, vá para **ferramentas** > **Opções** > **Depurando** > **geral**.

## <a name="vcpkg-integration"></a>Integração do Vcpkg

Se você tiver instalado o [vcpkg](vcpkg.md), os projetos do cmake abertos no Visual Studio integrarão automaticamente o arquivo vcpkg ferramentas. Isso significa que nenhuma configuração adicional é necessária para usar o vcpkg com seus projetos do CMake. Esse suporte funciona para instalações vcpkg locais e instalações do vcpkg em sistemas remotos que você está direcionando. Esse comportamento é desabilitado automaticamente quando você especifica qualquer outro ferramentas na configuração de suas configurações de CMake.

## <a name="customize-configuration-feedback"></a>Personalizar comentários de configuração

Por padrão, a maioria das mensagens de configuração são suprimidas, a menos que haja um erro. Você pode ver todas as mensagens habilitando esse recurso em **ferramentas** > **Opções** > **CMake**.

   ![Configurando opções de diagnóstico do cmake](media/vs2019-cmake-configure-options.png "CMake opções de diagnóstico")

## <a name="editing-cmakeliststxt-files"></a>Editando arquivos CMakeLists.txt

Para editar um arquivo CMakeLists.txt, clique com o botão direito do mouse no arquivo no **Gerenciador de Soluções** e escolha **Abrir**. Se você faz alterações no arquivo, uma barra de status amarela é exibida e informa você que o IntelliSense será atualizado, oferecendo a oportunidade de cancelar a operação de atualização. Para obter informações sobre CMakeLists.txt, confira a [documentação do CMake](https://cmake.org/documentation/).

   ![Edição do arquivo CMakeLists.txt](media/cmake-cmakelists.png "CMakeLists.txt file editing")

Assim que você salva o arquivo, a etapa de configuração é executada novamente de forma automática e exibe as informações na janela de **Saída**. Os erros e avisos são mostrados na **Lista de Erros** ou na janela de **Saída**. Clique duas vezes em um erro na **Lista de Erros** para navegar para a linha incorreta em CMakeLists.txt.

   ![Erros do arquivo CMakeLists.txt](media/cmake-cmakelists-error.png "CMakeLists.txt file errors")


## <a name="cmake-configure-step"></a>Etapa de configuração do CMake

Quando são feitas alterações significativas nos arquivos **CMakeSettings. JSON** ou CMakeLists. txt, o Visual Studio executa automaticamente a etapa de configuração do cmake. Se a etapa de configuração é concluída sem erros, as informações coletadas ficam disponíveis nos serviços de linguagem e no C++ IntelliSense e também nas operações de build e de depuração.

## <a name="troubleshooting-cmake-cache-errors"></a>Solução de problemas de erros do cache do CMake

Se você precisar de mais informações sobre o estado do cache CMake para diagnosticar um problema, abra o menu principal do **projeto** ou o menu de contexto **CMakeLists. txt** no **Gerenciador de soluções** para executar um destes comandos:

- **Exibir Cache** abre o arquivo CMakeCache.txt na pasta raiz de build no editor. (Todas as edições feitas aqui em CMakeCache.txt são apagadas se o cache é limpo. Para fazer alterações que persistam após a limpeza do cache, consulte [Personalizar configurações de CMake](customize-cmake-settings.md).)

- **Abrir Pasta do Cache** abre uma janela do Explorer na pasta raiz de build.

- **Limpar Cache** exclui a pasta raiz de build, de modo que a próxima etapa de configuração do CMake seja iniciada com um cache limpo.

- **Gerar Cache** força a execução da etapa de geração, mesmo se o Visual Studio considera o ambiente atualizado.

A geração de cache automático pode ser desabilitada nas **ferramentas > opções > CMake >** caixa de diálogo geral.

## <a name="run-cmake-from-the-command-line"></a>Executar CMake na linha de comando

Se tiver instalado o CMake do Instalador do Visual Studio, será possível executá-lo na linha de comando seguindo estas etapas:

1. Execute o vsdevcmd.bat (x86/x64) adequado. Consulte [Compilando na linha de comando](building-on-the-command-line.md) para obter mais informações.

1. Alterne para sua pasta de saída.

1. Execute o CMake para criar/configurar seu aplicativo.

::: moniker-end

::: moniker range="vs-2017"

O Visual Studio 2017 tem suporte avançado para CMake, incluindo [projetos CMake de plataforma cruzada](../linux/cmake-linux-project.md). O componente **Ferramentas do Visual C++ para CMake** usa o recurso **Abrir Pasta** para permitir o consumo pelo IDE de arquivos de projeto do CMake (como CMakeLists.txt) diretamente para as finalidades do IntelliSense e de navegação. Há suporte para geradores Ninja e Visual Studio. Se você usar um gerador do Visual Studio, um arquivo de projeto temporário será gerado e passado para msbuild.exe, mas nunca será carregado para as finalidades do IntelliSense ou de navegação. Você também pode importar um cache CMake existente. 

## <a name="installation"></a>Instalação

O recurso **Ferramentas do Visual C++ para CMake** é instalado por padrão como parte da carga de trabalho de **Desenvolvimento para desktop com C++** e como parte da carga de trabalho de **Desenvolvimento para Linux com C++** .

![Componente CMake na carga de trabalho Desktop com C++](media/cmake-install.png)

Para obter mais informações, confira [Instalar a carga de trabalho do Linux em C++ no Visual Studio](../linux/download-install-and-setup-the-linux-development-workload.md).

## <a name="ide-integration"></a>Integração com o IDE

Quando você escolhe **arquivo > abrir > pasta** para abrir uma pasta que contém um arquivo CMakeLists. txt, ocorre o seguinte:

- O Visual Studio adiciona um item de menu **CMake** ao menu principal, com comandos para exibição e edição de scripts do CMake.

- O **Gerenciador de Soluções** exibe a estrutura de pastas e os arquivos.

- O Visual Studio executa CMake.exe e, opcionalmente, gera o cache do CMake para a *configuração* padrão, que é Depuração x86. A linha de comando do CMake é exibida na **Janela de Saída**, juntamente com uma saída adicional do CMake.

- Em segundo plano, o Visual Studio começa a indexar os arquivos de origem para habilitar o IntelliSense, as informações de navegação, a refatoração e assim por diante. Conforme você trabalha, o Visual Studio monitora as alterações feitas no editor e também em disco para manter seu índice em sincronia com as fontes.

Você pode abrir pastas que contêm qualquer quantidade de projetos do CMake. O Visual Studio detecta e configura todos os arquivos CMakeLists.txt "raiz" no workspace. As operações do CMake (configuração, build, depuração), bem como o C++ IntelliSense e a navegação, estão disponíveis para todos os projetos do CMake no workspace.

![Projeto do CMake com várias raízes](media/cmake-multiple-roots.png)

Você também pode exibir seus projetos logicamente organizados pelos destinos. Escolha **Exibição de destinos** na lista suspensa na barra de ferramentas do **Gerenciador de Soluções**:

![Botão de exibição de destinos do CMake](media/cmake-targets-view.png)

O Visual Studio usa um arquivo chamado **CMakeSettings. JSON** para armazenar variáveis de ambiente ou opções de linha de comando para CMake. exe. O **CMakeSettings. JSON** também permite que você defina e armazene várias configurações de compilação de CMake e alterne convenientemente entre elas no IDE. 

Caso contrário, use o **CMakeLists. txt** da mesma forma que faria em qualquer projeto do cmake para especificar arquivos de origem, localizar bibliotecas, definir opções de compilador e vinculador e especificar outras informações relacionadas ao sistema de compilação.

Se você precisar passar argumentos para um executável no momento da depuração, poderá usar outro arquivo chamado **Launch. vs. JSON**. Em alguns cenários, o Visual Studio gerará automaticamente esses arquivos e você pode editá-los manualmente. Você também pode criar o arquivo por conta própria.

> [!NOTE]
> Para outros tipos de projetos de pasta aberta, dois arquivos JSON adicionais são usados: **CppProperties. JSON** e **Tasks. vs. JSON**. Nenhum deles é relevante para projetos do CMake.

## <a name="import-an-existing-cache"></a>Importar um cache existente

Quando você importa um arquivo CMakeCache.txt existente, o Visual Studio extrai as variáveis personalizadas automaticamente e cria um arquivo **CMakeSettings.json** pré-populado baseado nelas. O cache original não é modificado de forma alguma e ainda pode ser usado na linha de comando ou com qualquer ferramenta ou IDE que foi usado para gerá-lo. O novo arquivo **CMakeSettings. JSON** é colocado junto com o CMakeLists. txt raiz do projeto. O Visual Studio gera um novo cache com base no arquivo de configurações. Você pode substituir a geração de cache automática nas **ferramentas > opções > CMake >** caixa de diálogo geral.

Nem tudo no cache é importado.  Propriedades, como o gerador e o local dos compiladores, são substituídas pelos padrões conhecidos por funcionar bem com o IDE.

### <a name="to-import-an-existing-cache"></a>Para importar um cache existente

1. No menu principal, escolha **arquivo > abrir > CMake**:

   ![Abrir o CMake](media/cmake-file-open.png "Arquivo, Abrir, CMake")

   Isso abrirá o assistente para **Importar o CMake do Cache**.

2. Navegue para o arquivo CMakeCache.txt que deseja importar e, em seguida, clique em **OK**. O assistente para **Importar Projeto do CMake do Cache** será exibido:

   ![Importar um cache do CMake](media/cmake-import-wizard.png "Abrir o assistente para importar cache do CMake")

   Quando o assistente for concluído, você poderá ver o novo arquivo CMakeCache.txt no **Gerenciador de Soluções** ao lado do arquivo CMakeLists.txt raiz no projeto.

## <a name="building-cmake-projects"></a>Compilando projetos do CMake

Para compilar um projeto do CMake, você tem estas opções:

1. Na barra de ferramentas geral, localize a lista suspensa **configurações** ; é provável que esteja mostrando "Linux-debug" ou "x64-debug" por padrão. Selecione a configuração desejada e pressione **F5**ou clique no botão **executar** (triângulo verde) na barra de ferramentas. O projeto será compilado automaticamente pela primeira vez, assim como uma solução do Visual Studio.

1. Clique com o botão direito do mouse em CMakeLists.txt e selecione **Build** no menu de contexto. Se você tiver vários destinos na estrutura de pastas, opte por compilar todos ou apenas um destino específico.

1. No menu principal, selecione **compilar > Compilar solução** (**F7** ou **Ctrl + Shift + B**). Verifique se um destino do CMake já está selecionado na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**.

![Comando de menu de build do CMake](media/cmake-build-menu.png "Menu de comando de build do CMake")

Você pode personalizar configurações de compilação, variáveis de ambiente, argumentos de linha de comando e outras configurações sem modificar o arquivo CMakeLists. txt usando o arquivo **CMakeSettings. JSON** . Para obter mais informações, confira [Personalizar configurações do CMake](customize-cmake-settings.md).

Como se esperaria, os resultados do build são mostrados na **Janela de Saída** e na **Lista de Erros**.

![Erros de build do CMake](media/cmake-build-errors.png "CMake build errors")

Em uma pasta com vários destinos de build, escolha o item **Build** no menu do **CMake** ou o menu de contexto **CMakeLists.txt** para especificar qual destino do CMake compilar. Se você pressionar **Ctrl+Shift+B** em um projeto do CMake, isso compilará o documento ativo atual.

## <a name="debugging-cmake-projects"></a>Depurando projetos do CMake

Para depurar um projeto do CMake, escolha a configuração desejada e pressione **F5** ou pressione o botão **Executar** na barra de ferramentas. Se o botão **Executar** indicar "Selecione o Item de Inicialização", selecione a seta suspensa e escolha o destino que deseja executar. (Em um projeto do CMake, a opção "Documento atual" só é válida para arquivos .cpp.)

![Botão de execução do CMake](media/cmake-run-button.png "Botão de execução do CMake")

Os comandos **Executar** ou **F5** primeiro compilam o projeto se as alterações foram feitas desde o build anterior.

Você pode personalizar uma sessão de depuração CMake definindo as propriedades no arquivo **Launch. vs. JSON** . Para obter mais informações, confira [Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md).


## <a name="editing-cmakeliststxt-files"></a>Editando arquivos CMakeLists.txt

Para editar um arquivo CMakeLists.txt, clique com o botão direito do mouse no arquivo no **Gerenciador de Soluções** e escolha **Abrir**. Se você faz alterações no arquivo, uma barra de status amarela é exibida e informa você que o IntelliSense será atualizado, oferecendo a oportunidade de cancelar a operação de atualização. Para obter informações sobre CMakeLists.txt, confira a [documentação do CMake](https://cmake.org/documentation/).

   ![Edição do arquivo CMakeLists.txt](media/cmake-cmakelists.png "CMakeLists.txt file editing")

Assim que você salva o arquivo, a etapa de configuração é executada novamente de forma automática e exibe as informações na janela de **Saída**. Os erros e avisos são mostrados na **Lista de Erros** ou na janela de **Saída**. Clique duas vezes em um erro na **Lista de Erros** para navegar para a linha incorreta em CMakeLists.txt.

   ![Erros do arquivo CMakeLists.txt](media/cmake-cmakelists-error.png "CMakeLists.txt file errors")


## <a name="cmake-configure-step"></a>Etapa de configuração do CMake

Quando são feitas alterações significativas nos arquivos **CMakeSettings. JSON** ou CMakeLists. txt, o Visual Studio executa automaticamente a etapa de configuração do cmake. Se a etapa de configuração é concluída sem erros, as informações coletadas ficam disponíveis nos serviços de linguagem e no C++ IntelliSense e também nas operações de build e de depuração.

Quando vários projetos do CMake usam o mesmo nome de configuração do CMake (por exemplo, x86-Debug), todos eles são configurados e compilados (em sua própria pasta raiz de build) quando essa configuração é selecionada. Depure os destinos de todos os projetos do CMake que participam dessa configuração do CMake.

   ![Item de menu Somente Build do CMake](media/cmake-build-only.png "CMake Build Only menu item")

Para limitar compilações e sessões de depuração a um subconjunto dos projetos no espaço de trabalho, crie uma nova configuração com um nome exclusivo no arquivo **CMakeSettings. JSON** e aplique-a somente a esses projetos. Quando essa configuração é selecionada, os comandos de build, de depuração e do IntelliSense são habilitados apenas para esses projetos especificados.

## <a name="troubleshooting-cmake-cache-errors"></a>Solução de problemas de erros do cache do CMake

Caso precise obter mais informações sobre o estado do cache do CMake para diagnosticar um problema, abra o menu principal do **CMake** ou o menu de contexto de **CMakeLists.txt** no **Gerenciador de Soluções** para executar um destes comandos:

- **Exibir Cache** abre o arquivo CMakeCache.txt na pasta raiz de build no editor. (Todas as edições feitas aqui em CMakeCache.txt são apagadas se o cache é limpo. Para fazer alterações que persistam após a limpeza do cache, consulte [Personalizar configurações de CMake](customize-cmake-settings.md).)

- **Abrir Pasta do Cache** abre uma janela do Explorer na pasta raiz de build.

- **Limpar Cache** exclui a pasta raiz de build, de modo que a próxima etapa de configuração do CMake seja iniciada com um cache limpo.

- **Gerar Cache** força a execução da etapa de geração, mesmo se o Visual Studio considera o ambiente atualizado.

A geração de cache automático pode ser desabilitada nas **ferramentas > opções > CMake >** caixa de diálogo geral.

## <a name="single-file-compilation"></a>Compilação de arquivo único

Para criar um arquivo único em um projeto do CMake, clique com o botão direito do mouse no arquivo no **Gerenciador de Soluções** e escolha **Compilar**. Você também pode criar o arquivo que está aberto no editor no momento usando o menu principal do CMake:

![Compilação de arquivo único do CMake](media/cmake-single-file-compile.png)

## <a name="run-cmake-from-the-command-line"></a>Executar CMake na linha de comando

Se tiver instalado o CMake do Instalador do Visual Studio, será possível executá-lo na linha de comando seguindo estas etapas:

1. Execute o vsdevcmd.bat (x86/x64) adequado. Consulte [Compilando na linha de comando](building-on-the-command-line.md) para obter mais informações.

1. Alterne para sua pasta de saída.

1. Execute o CMake para criar/configurar seu aplicativo.

::: moniker-end

::: moniker range="vs-2015"

No Visual Studio 2015, os usuários do Visual Studio podem usar um [gerador do CMake](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) para gerar arquivos de projeto do MSBuild, que o IDE então consome para IntelliSense, navegação e compilação.

::: moniker-end


## <a name="see-also"></a>Consulte também

[Tutorial: Criar projetos de plataforma cruzada do C++ no Visual Studio](get-started-linux-cmake.md)<br/>
[Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/>
[Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/>
[Personalizar as configurações de compilação do CMake](customize-cmake-settings.md)<br/>
[Referência de CMakeSettings.json](cmakesettings-reference.md)<br/>
[Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)<br/>
