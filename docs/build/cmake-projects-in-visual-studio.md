---
title: Projetos do CMake no Visual Studio
description: Como criar e construir projetos C++ usando o CMake no Visual Studio.
ms.date: 01/08/2020
helpviewer_keywords:
- CMake in Visual C++
ms.assetid: 444d50df-215e-4d31-933a-b41841f186f8
ms.openlocfilehash: 49ba53eaa8ac075ab6d3b2a66f33160c5c3ec410
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329169"
---
# <a name="cmake-projects-in-visual-studio"></a>Projetos do CMake no Visual Studio

O CMake é uma ferramenta multiplataforma de software livre para definir os processos de build executados em várias plataformas. Este artigo pressupõe que você está familiarizado com cMake. Você pode aprender mais sobre isso em [Compilar, Testar e Empacotar seu Software com o CMake](https://cmake.org/).

> [!NOTE]
> O CMake se tornou cada vez mais integrado com o Visual Studio nos últimos lançamentos. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker range="vs-2019"

As **ferramentas C++ CMake para** componente Windows usam o recurso Open [Folder](open-folder-projects-cpp.md) para consumir arquivos de projeto CMake (como *CMakeLists.txt)* diretamente para fins de IntelliSense e navegação. Há suporte para geradores Ninja e Visual Studio. Se você usar um gerador Visual Studio, ele gera um arquivo de projeto temporário e o passa para msbuild.exe. No entanto, o projeto nunca é carregado para fins de IntelliSense ou navegação. Você também pode importar um cache CMake existente.

## <a name="installation"></a>Instalação

**As ferramentas C++ CMake para Windows** são instaladas como parte do desenvolvimento de **desktop com C++** e Desenvolvimento Linux com cargas de trabalho **C++.** Para obter mais informações, consulte [projetos CMake multiplataforma .](../linux/cmake-linux-project.md)

![Componente CMake na carga de trabalho Desktop com C++](media/cmake-install-2019.png)

Para obter mais informações, confira [Instalar a carga de trabalho do Linux em C++ no Visual Studio](../linux/download-install-and-setup-the-linux-development-workload.md).

## <a name="ide-integration"></a>Integração com o IDE

Quando você escolhe **Arquivo > Abrir pasta >** para abrir uma pasta contendo um arquivo *CMakeLists.txt,* as seguintes coisas acontecem:

- O Visual Studio adiciona itens **CMake** ao menu **Project,** com comandos para visualização e edição de scripts CMake.

- O **Gerenciador de Soluções** exibe a estrutura de pastas e os arquivos.

- O Visual Studio executa cmake.exe e gera o arquivo cMake cache *(CMakeCache.txt)* para a configuração padrão (x64 Debug). A linha de comando do CMake é exibida na **Janela de Saída**, juntamente com uma saída adicional do CMake.

- Em segundo plano, o Visual Studio começa a indexar os arquivos de origem para habilitar o IntelliSense, as informações de navegação, a refatoração e assim por diante. Conforme você trabalha, o Visual Studio monitora as alterações feitas no editor e também em disco para manter seu índice em sincronia com as fontes.

Você pode abrir pastas que contêm qualquer quantidade de projetos do CMake. O Visual Studio detecta e configura todos os arquivos *CMakeLists.txt* "raiz" em seu espaço de trabalho. As operações CMake (configurar, construir, depurar), C++ IntelliSense e navegação estão disponíveis para todos os projetos CMake em seu espaço de trabalho.

![Projeto do CMake com várias raízes](media/cmake-multiple-roots.png)

Você também pode exibir seus projetos logicamente organizados pelos destinos. Escolha **Exibição de destinos** na lista suspensa na barra de ferramentas do **Gerenciador de Soluções**:

![Botão de exibição de destinos do CMake](media/cmake-targets-view.png)

Clique no botão **Mostrar todos os arquivos** na parte superior do Solution **Explorer** para ver toda a saída gerada pelo CMake nas pastas *out/build/config\<>.*

O Visual Studio usa um arquivo de configuração chamado **CMakeSettings.json**. Este arquivo permite definir e armazenar várias configurações de compilação e, convenientemente, alternar entre elas no IDE. Uma *configuração* é uma construção do Visual Studio que encapsula configurações específicas para um determinado tipo de compilação. As configurações são usadas para configurar as opções padrão de linha de comando que o Visual Studio passa para cmake.exe. Você também pode especificar opções adicionais de CMake aqui e definir quaisquer variáveis adicionais que você goste. Todas as opções são escritas no cache CMake como variáveis internas ou externas. No Visual Studio 2019, o **CMake Settings Editor** fornece uma maneira conveniente de editar suas configurações. Para obter mais informações, confira [Personalizar configurações do CMake](customize-cmake-settings.md).

Uma configuração, `intelliSenseMode` não é passada para CMake, mas é usada apenas pelo Visual Studio.

Use o arquivo **CMakeLists.txt** em cada pasta de projeto, assim como faria em qualquer projeto CMake. Você pode especificar arquivos de origem, encontrar bibliotecas, definir opções de compilador e linker e especificar outras informações relacionadas ao sistema de compilação.

Para passar argumentos para um executável na hora da depuração, você pode usar outro arquivo chamado **launch.vs.json**. Em alguns cenários, o Visual Studio gera automaticamente esses arquivos. Você pode editá-los manualmente, ou até mesmo criar o arquivo você mesmo.

> [!NOTE]
> Para outros tipos de projetos de Pasta Aberta, dois arquivos JSON adicionais são **usados: CppProperties.json** e **tasks.vs.json**. Nenhum deles é relevante para projetos do CMake.

## <a name="open-an-existing-cache"></a>Abra um cache existente

Quando você abre um arquivo de cache CMake existente *(CMakeCache.txt),* o Visual Studio não tenta gerenciar seu cache e construir árvore para você. Suas ferramentas personalizadas ou preferidas têm controle completo sobre como o CMake configura seu projeto. Para abrir um cache existente no Visual Studio, escolha **Arquivo > Abrir > CMake**. Em seguida, navegue até um arquivo *CMakeCache.txt* existente.

Você pode adicionar um cache CMake existente a um projeto aberto. É feito da mesma maneira que você adicionaria uma nova configuração. Para obter mais informações, consulte nosso post no blog sobre [a abertura de um cache existente no Visual Studio](https://devblogs.microsoft.com/cppblog/open-existing-cmake-caches-in-visual-studio/).

## <a name="building-cmake-projects"></a>Compilando projetos do CMake

Para compilar um projeto do CMake, você tem estas opções:

1. Na barra de ferramentas Geral, localize a **parada Configurações.** Provavelmente mostra "x64-Debug" por padrão. Selecione a configuração preferida e **pressione F5**ou clique no botão **Executar** (triângulo verde) na barra de ferramentas. O projeto será compilado automaticamente pela primeira vez, assim como uma solução do Visual Studio.

1. Clique com o botão direito do mouse em *CMakeLists.txt* e selecione **Build** no menu de contexto. Se você tiver vários destinos na estrutura de pastas, opte por compilar todos ou apenas um destino específico.

1. No menu principal, **selecione Build > Build All** **(F7** ou **Ctrl+Shift+B**). Verifique se um destino do CMake já está selecionado na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**.

![CMake criar comando de menu](media/cmake-build-menu.png "CCriar menu de comando de compilação")

Como se esperaria, os resultados do build são mostrados na **Janela de Saída** e na **Lista de Erros**.

![Erros de compilação do CMake](media/cmake-build-errors.png "Erros de compilação do CMake")

Em uma pasta com vários alvos de compilação, você pode especificar qual destino CMake a ser construído: Escolha o item **Build** no menu **CMake** ou no menu de contexto *CMakeLists.txt* para especificar o destino. Se você inserir **Ctrl+Shift+B** em um projeto CMake, ele será o documento ativo atual.

## <a name="debugging-cmake-projects"></a>Depurando projetos do CMake

Para depurar um projeto CMake, escolha a configuração preferida e pressione **F5**ou **pressione** o botão Executar na barra de ferramentas. Se o botão **Executar** disser "Selecionar item de inicialização", selecione a seta de isto. Escolha o alvo que deseja executar. (Em um projeto do CMake, a opção "Documento atual" só é válida para arquivos .cpp.)

![CMake botão de execução](media/cmake-run-button.png "CMake botão de execução")

Os comandos **Executar** ou **F5** primeiro compilam o projeto se as alterações foram feitas desde o build anterior. Alterações em *CMakeSettings.json* fazem com que o cache CMake seja regenerado.

Você pode personalizar uma sessão de depuração CMake definindo propriedades no arquivo **launch.vs.json.** Para obter mais informações, confira [Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md).

## <a name="just-my-code-for-cmake-projects"></a>Just My Code for CMake projects

Quando você constrói para windows usando o compilador MSVC, os projetos CMake têm suporte para depuração do Just My Code. Para alterar a configuração Just My Code, vá para O General**de depuração de** > **opções** >  **de** > **ferramentas**.

## <a name="vcpkg-integration"></a>Integração vcpkg

Se você tiver instalado [vcpkg,](vcpkg.md)os projetos CMake abertos no Visual Studio integrem automaticamente o arquivo vcpkg toolchain. Isso significa que nenhuma configuração adicional é necessária para usar vcpkg com seus projetos CMake. Este suporte funciona tanto para instalações locais de vcpkg quanto para instalações vcpkg em sistemas remotos que você está mirando. Esse comportamento é desativado automaticamente quando você especifica qualquer outra cadeia de ferramentas na configuração CMake Configurações.

## <a name="customize-configuration-feedback"></a>Personalize o feedback da configuração

Por padrão, a maioria das mensagens de configuração são suprimidas a menos que haja um erro. Você pode ver todas as mensagens ativando esse recurso no **Tools** > **Options** > **CMake**.

   ![Configuração de opções de diagnóstico CMake](media/vs2019-cmake-configure-options.png "CFaça opções de diagnóstico")

## <a name="editing-cmakeliststxt-files"></a>Editando arquivos CMakeLists.txt

Para editar um arquivo *CMakeLists.txt,* clique com o botão direito do mouse no arquivo no **Solution Explorer** e escolha **Abrir**. Se você fizer alterações no arquivo, uma barra de status amarela será exibida e informará que o IntelliSense será atualizado. Isso lhe dá a chance de cancelar a operação de atualização. Para obter informações sobre *CMakeLists.txt,* consulte a [documentação CMake](https://cmake.org/documentation/).

   ![Edição de arquivos CMakeLists.txt](media/cmake-cmakelists.png "Edição de arquivos CMakeLists.txt")

Assim que você salva o arquivo, a etapa de configuração é executada novamente de forma automática e exibe as informações na janela de **Saída**. Os erros e avisos são mostrados na **Lista de Erros** ou na janela de **Saída**. Clique duas vezes em um erro na **Lista de erros** para navegar até a linha ofensiva em *CMakeLists.txt*.

   ![Erros de arquivo CMakeLists.txt](media/cmake-cmakelists-error.png "Erros de arquivo CMakeLists.txt")

## <a name="cmake-configure-step"></a>Etapa de configuração do CMake

Quando você faz alterações significativas nos arquivos *CMakeSettings.json* ou *CMakeLists.txt,* o Visual Studio refaz automaticamente a etapa de configuração do CMake. Se a etapa configurar terminar sem erros, as informações coletadas estarão disponíveis no C++ IntelliSense e nos serviços de idiomas. Também é usado em operações de construção e depuração.

## <a name="troubleshooting-cmake-cache-errors"></a>Solução de problemas de erros do cache do CMake

Se você precisar de mais informações sobre o estado do cache CMake para diagnosticar um problema, abra o menu principal do **Projeto** ou o menu de contexto *CMakeLists.txt* no **Solution Explorer** para executar um desses comandos:

- **O Cache de exibição** abre o arquivo *CMakeCache.txt* a partir da pasta raiz de compilação no editor. (Todas as edições que você fizer aqui para *CMakeCache.txt* são eliminadas se você limpar o cache. Para fazer alterações que persistam após a limpeza do cache, consulte [Personalizar configurações CMake](customize-cmake-settings.md).)

- **Abrir Pasta do Cache** abre uma janela do Explorer na pasta raiz de build.

- **Limpar Cache** exclui a pasta raiz de build, de modo que a próxima etapa de configuração do CMake seja iniciada com um cache limpo.

- **Gerar cache** força a geração de passos a serem executados mesmo que o Visual Studio considere o ambiente atualizado.

A geração automática de cache pode ser desativada nas opções de > ferramentas > caixa de diálogo **CMake > General.**

## <a name="run-cmake-from-the-command-line"></a>Executar CMake na linha de comando

Se tiver instalado o CMake do Instalador do Visual Studio, será possível executá-lo na linha de comando seguindo estas etapas:

1. Execute o vsdevcmd.bat (x86/x64) adequado. Para obter mais informações, consulte [Building on the Command Line](building-on-the-command-line.md).

1. Alterne para sua pasta de saída.

1. Execute o CMake para criar/configurar seu aplicativo.

::: moniker-end

::: moniker range="vs-2017"

Visual Studio 2017 tem rico suporte para CMake, incluindo [projetos CMake multiplataforma](../linux/cmake-linux-project.md). O **componente Visual C++ Tools for CMake** usa o recurso **Open Folder** para permitir que o IDE consuma arquivos de projeto CMake (como *CMakeLists.txt)* diretamente para fins de IntelliSense e navegação. Há suporte para geradores Ninja e Visual Studio. Se você usar um gerador Visual Studio, ele gera um arquivo de projeto temporário e o passa para msbuild.exe. No entanto, o projeto nunca é carregado para fins de IntelliSense ou navegação. Você também pode importar um cache CMake existente.

## <a name="installation"></a>Instalação

**Visual C++ Tools for CMake** é instalado como parte do desenvolvimento de **Desktop com C++** e Desenvolvimento Linux com cargas de trabalho **C++.**

![Componente CMake na carga de trabalho Desktop com C++](media/cmake-install.png)

Para obter mais informações, confira [Instalar a carga de trabalho do Linux em C++ no Visual Studio](../linux/download-install-and-setup-the-linux-development-workload.md).

## <a name="ide-integration"></a>Integração de IDE

Quando você escolhe **Arquivo > Abrir pasta >** para abrir uma pasta contendo um arquivo *CMakeLists.txt,* as seguintes coisas acontecem:

- O Visual Studio adiciona um item de menu **CMake** ao menu principal, com comandos para exibição e edição de scripts do CMake.

- O **Gerenciador de Soluções** exibe a estrutura de pastas e os arquivos.

- O Visual Studio executa CMake.exe e, opcionalmente, gera o cache do CMake para a *configuração* padrão, que é Depuração x86. A linha de comando do CMake é exibida na **Janela de Saída**, juntamente com uma saída adicional do CMake.

- Em segundo plano, o Visual Studio começa a indexar os arquivos de origem para habilitar o IntelliSense, as informações de navegação, a refatoração e assim por diante. Conforme você trabalha, o Visual Studio monitora as alterações feitas no editor e também em disco para manter seu índice em sincronia com as fontes.

Você pode abrir pastas que contêm qualquer quantidade de projetos do CMake. O Visual Studio detecta e configura todos os arquivos *CMakeLists.txt* "raiz" em seu espaço de trabalho. As operações CMake (configurar, construir, depurar), C++ IntelliSense e navegação estão disponíveis para todos os projetos CMake em seu espaço de trabalho.

![Projeto do CMake com várias raízes](media/cmake-multiple-roots.png)

Você também pode exibir seus projetos logicamente organizados pelos destinos. Escolha **Exibição de destinos** na lista suspensa na barra de ferramentas do **Gerenciador de Soluções**:

![Botão de exibição de destinos do CMake](media/cmake-targets-view.png)

O Visual Studio usa um arquivo chamado *CMakeSettings.json* para armazenar variáveis de ambiente ou opções de linha de comando para Cmake.exe. *CMakeSettings.json* também permite definir e armazenar várias configurações de compilação CMake. Você pode convenientemente alternar entre eles no IDE.

Caso contrário, use o *CMakeLists.txt* assim como faria em qualquer projeto CMake para especificar arquivos de origem, encontrar bibliotecas, definir opções de compilador e linker e especificar outras informações relacionadas ao sistema de compilação.

Se você precisar passar argumentos para um executável na hora da depuração, você pode usar outro arquivo chamado **launch.vs.json**. Em alguns cenários, o Visual Studio gera automaticamente esses arquivos. Você pode editá-los manualmente, ou até mesmo criar o arquivo você mesmo.

> [!NOTE]
> Para outros tipos de projetos de Pasta Aberta, dois arquivos JSON adicionais são **usados: CppProperties.json** e **tasks.vs.json**. Nenhum deles é relevante para projetos do CMake.

## <a name="import-an-existing-cache"></a>Importar um cache existente

Quando você importa um arquivo *CMakeCache.txt* existente, o Visual Studio extrai automaticamente variáveis personalizadas e cria um arquivo *CMakeSettings.json* pré-preenchido com base nelas. O cache original não é modificado de forma alguma. Ele ainda pode ser usado a partir da linha de comando, ou com qualquer ferramenta ou IDE usado para gerá-lo. O novo arquivo *CMakeSettings.json* é colocado ao lado do *cmakelists.txt*raiz do projeto . O Visual Studio gera um novo cache com base no arquivo de configurações. Você pode substituir a geração automática de cache nas opções > ferramentas > caixa de diálogo **CMake > General.**

Nem tudo no cache é importado.  Propriedades, como o gerador e o local dos compiladores, são substituídas pelos padrões conhecidos por funcionar bem com o IDE.

### <a name="to-import-an-existing-cache"></a>Para importar um cache existente

1. No menu principal, escolha **Arquivo > Abrir > CMake**:

   ![Abrir CMake](media/cmake-file-open.png "Arquivo, Abrir, CMake")

   Este comando traz à tona o **assistente Import CMake from Cache.**

2. Navegue até o arquivo *CMakeCache.txt* que deseja importar e clique em **OK**. O assistente para **Importar Projeto do CMake do Cache** será exibido:

   ![Importe um cache CMake](media/cmake-import-wizard.png "Abra o assistente de cache de importação CMake")

   Quando o assistente for concluído, você poderá ver o novo arquivo *CMakeCache.txt* no **Solution Explorer** ao lado do arquivo *CMakeLists.txt* raiz em seu projeto.

## <a name="building-cmake-projects"></a>Compilando projetos do CMake

Para compilar um projeto do CMake, você tem estas opções:

1. Na barra de ferramentas Geral, localize a **parada Configurações.** Provavelmente está mostrando "Linux-Debug" ou "x64-Debug" por padrão. Selecione a configuração preferida e **pressione F5**ou clique no botão **Executar** (triângulo verde) na barra de ferramentas. O projeto será compilado automaticamente pela primeira vez, assim como uma solução do Visual Studio.

1. Clique com o botão direito do mouse no *CMakeLists.txt* e selecione **Build** no menu de contexto. Se você tiver vários destinos na estrutura de pastas, opte por compilar todos ou apenas um destino específico.

1. No menu principal, **selecione Build > Build Solution** **(F7** ou **Ctrl+Shift+B).** Verifique se um destino do CMake já está selecionado na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**.

![CMake criar comando de menu](media/cmake-build-menu.png "CCriar menu de comando de compilação")

Você pode personalizar configurações de compilação, variáveis de ambiente, argumentos de linha de comando e outras configurações no arquivo *CMakeSettings.json.* Ele permite que você faça alterações sem modificar o arquivo *CMakeLists.txt.* Para obter mais informações, confira [Personalizar configurações do CMake](customize-cmake-settings.md).

Como se esperaria, os resultados do build são mostrados na **Janela de Saída** e na **Lista de Erros**.

![Erros de compilação do CMake](media/cmake-build-errors.png "Erros de compilação do CMake")

Em uma pasta com vários alvos de compilação, você pode especificar qual destino CMake a ser construído: Escolha o item **Build** no menu **CMake** ou no menu de contexto *CMakeLists.txt* para especificar o destino. Se você inserir **Ctrl+Shift+B** em um projeto CMake, ele será o documento ativo atual.

## <a name="debugging-cmake-projects"></a>Depurando projetos do CMake

Para depurar um projeto CMake, escolha a configuração preferida e pressione **F5**. Ou **pressione** o botão Executar na barra de ferramentas. Se o botão **Executar** indicar "Selecione o Item de Inicialização", selecione a seta suspensa e escolha o destino que deseja executar. (Em um projeto do CMake, a opção "Documento atual" só é válida para arquivos .cpp.)

![CMake botão de execução](media/cmake-run-button.png "CMake botão de execução")

Os comandos **Executar** ou **F5** primeiro compilam o projeto se as alterações foram feitas desde o build anterior.

Você pode personalizar uma sessão de depuração CMake definindo propriedades no arquivo **launch.vs.json.** Para obter mais informações, confira [Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md).

## <a name="editing-cmakeliststxt-files"></a>Editando arquivos CMakeLists.txt

Para editar um arquivo *CMakeLists.txt,* clique com o botão direito do mouse no arquivo no **Solution Explorer** e escolha **Abrir**. Se você fizer alterações no arquivo, uma barra de status amarela será exibida e informará que o IntelliSense será atualizado. Isso lhe dá a chance de cancelar a operação de atualização. Para obter informações sobre *CMakeLists.txt,* consulte a [documentação CMake](https://cmake.org/documentation/).

   ![Edição de arquivos CMakeLists.txt](media/cmake-cmakelists.png "Edição de arquivos CMakeLists.txt")

Assim que você salva o arquivo, a etapa de configuração é executada novamente de forma automática e exibe as informações na janela de **Saída**. Os erros e avisos são mostrados na **Lista de Erros** ou na janela de **Saída**. Clique duas vezes em um erro na **Lista de erros** para navegar até a linha ofensiva em *CMakeLists.txt*.

   ![Erros de arquivo CMakeLists.txt](media/cmake-cmakelists-error.png "Erros de arquivo CMakeLists.txt")

## <a name="cmake-configure-step"></a>Etapa de configuração do CMake

Quando mudanças significativas são feitas nos arquivos *CMakeSettings.json* ou *CMakeLists.txt,* o Visual Studio refaz automaticamente a etapa de configuração do CMake. Se a etapa configurar terminar sem erros, as informações coletadas estarão disponíveis no C++ IntelliSense e nos serviços de idiomas. Também é usado em operações de construção e depuração.

Vários projetos CMake podem usar o mesmo nome de configuração CMake (por exemplo, x86-Debug). Todos eles são configurados e construídos (em sua própria pasta raiz de compilação) quando essa configuração é selecionada. Depure os destinos de todos os projetos do CMake que participam dessa configuração do CMake.

   ![CMake Build Only item de menu](media/cmake-build-only.png "CMake Build Only item de menu")

Você pode limitar as compilações e depurar sessões a um subconjunto dos projetos no espaço de trabalho. Crie uma nova configuração com um nome exclusivo no arquivo *CMakeSettings.json.* Em seguida, aplique a configuração apenas a esses projetos. Quando essa configuração é selecionada, o IntelliSense e os comandos build and debug só se aplicam a esses projetos especificados.

## <a name="troubleshooting-cmake-cache-errors"></a>Solução de problemas de erros do cache do CMake

Caso precise obter mais informações sobre o estado do cache do CMake para diagnosticar um problema, abra o menu principal do **CMake** ou o menu de contexto de *CMakeLists.txt* no **Gerenciador de Soluções** para executar um destes comandos:

- **O Cache de exibição** abre o arquivo *CMakeCache.txt* a partir da pasta raiz de compilação no editor. (Todas as edições que você fizer aqui para *CMakeCache.txt* são eliminadas se você limpar o cache. Para fazer alterações que persistam após a limpeza do cache, consulte [Personalizar configurações CMake](customize-cmake-settings.md).)

- **Abrir Pasta do Cache** abre uma janela do Explorer na pasta raiz de build.

- **Limpar Cache** exclui a pasta raiz de build, de modo que a próxima etapa de configuração do CMake seja iniciada com um cache limpo.

- **Gerar cache** força a geração de passos a serem executados mesmo que o Visual Studio considere o ambiente atualizado.

A geração automática de cache pode ser desativada nas opções de > ferramentas > caixa de diálogo **CMake > General.**

## <a name="single-file-compilation"></a>Compilação de arquivos únicos

Para construir um único arquivo em um projeto CMake, clique com o botão direito do mouse no arquivo no **Solution Explorer**. Escolha **Compilar** no menu pop-up. Você também pode construir o arquivo aberto no momento no editor usando o menu **principal do CMake:**

![Compilação de arquivo único do CMake](media/cmake-single-file-compile.png)

## <a name="run-cmake-from-the-command-line"></a>Executar CMake na linha de comando

Se tiver instalado o CMake do Instalador do Visual Studio, será possível executá-lo na linha de comando seguindo estas etapas:

1. Execute o vsdevcmd.bat (x86/x64) adequado. Para obter mais informações, consulte [Building na linha de comando](building-on-the-command-line.md) .

1. Alterne para sua pasta de saída.

1. Execute o CMake para criar/configurar seu aplicativo.

::: moniker-end

::: moniker range="vs-2015"

No Visual Studio 2015, os usuários do Visual Studio podem usar um [gerador do CMake](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) para gerar arquivos de projeto do MSBuild, que o IDE então consome para IntelliSense, navegação e compilação.

::: moniker-end

## <a name="see-also"></a>Confira também

[Tutorial: Crie projetos multiplataforma C++ no Visual Studio](get-started-linux-cmake.md)\
[Configure um projeto Linux CMake](../linux/cmake-linux-project.md)\
[Conecte-se ao seu computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)\
[Personalizar configurações de compilação cMake](customize-cmake-settings.md)\
[Referência de esquema CMakeSettings.json](cmakesettings-reference.md)\
[Configurar sessões de depuração CMake](configure-cmake-debugging-sessions.md)\
[Implantar, executar e depurar seu projeto Linux](../linux/deploy-run-and-debug-your-linux-project.md)\
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)
