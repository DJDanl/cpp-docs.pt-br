---
title: Projetos do CMake no Visual Studio
description: Como criar e compilar C++ projetos usando o CMake no Visual Studio.
ms.date: 01/08/2020
helpviewer_keywords:
- CMake in Visual C++
ms.assetid: 444d50df-215e-4d31-933a-b41841f186f8
ms.openlocfilehash: be252759e93eb30d4f9b4ff1446dd4217fcdf2a6
ms.sourcegitcommit: 5f276064779d90a4cfda758f89e0c0f1e4d1a188
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/09/2020
ms.locfileid: "75791824"
---
# <a name="cmake-projects-in-visual-studio"></a>Projetos do CMake no Visual Studio

O CMake é uma ferramenta multiplataforma de software livre para definir os processos de build executados em várias plataformas. Este artigo pressupõe que você esteja familiarizado com o CMake. Você pode aprender mais sobre isso em [Compilar, Testar e Empacotar seu Software com o CMake](https://cmake.org/).

> [!NOTE]
> O CMake se tornou cada vez mais integrado ao Visual Studio nas últimas versões. Para ver as informações corretas para a versão que você está usando, verifique se o seletor de versão no canto superior esquerdo desta página está definido corretamente.

::: moniker range="vs-2019"

O  **C++ componente ferramentas do cmake para Windows** usa o recurso [abrir pasta](open-folder-projects-cpp.md) para consumir arquivos de projeto CMake (como *CMakeLists. txt*) diretamente para fins de IntelliSense e navegação. Há suporte para geradores Ninja e Visual Studio. Se você usar um gerador do Visual Studio, ele gerará um arquivo de projeto temporário e o passará para o MSBuild. exe. No entanto, o projeto nunca é carregado para fins de navegação ou IntelliSense. Você também pode importar um cache CMake existente.

## <a name="installation"></a>Instalação

**As ferramentas do cmake para Windows são instaladas como parte do desenvolvimento de desktop com o e do desenvolvimento do Linux com cargas de trabalho. C++**  **C++** **C++** Para obter mais informações, consulte [projetos de CMake de plataforma cruzada](../linux/cmake-linux-project.md).

![Componente CMake na carga de trabalho Desktop com C++](media/cmake-install-2019.png)

Para obter mais informações, confira [Instalar a carga de trabalho do Linux em C++ no Visual Studio](../linux/download-install-and-setup-the-linux-development-workload.md).

## <a name="ide-integration"></a>Integração com o IDE

Quando você escolhe **arquivo > abrir > pasta** para abrir uma pasta que contém um arquivo *CMakeLists. txt* , ocorre o seguinte:

- O Visual Studio adiciona itens **CMake** ao menu **projeto** , com comandos para exibir e editar scripts CMake.

- O **Gerenciador de Soluções** exibe a estrutura de pastas e os arquivos.

- O Visual Studio executa o CMake. exe e gera o arquivo de cache CMake (*CMakeCache. txt*) para a configuração padrão (depuração x64). A linha de comando do CMake é exibida na **Janela de Saída**, juntamente com uma saída adicional do CMake.

- Em segundo plano, o Visual Studio começa a indexar os arquivos de origem para habilitar o IntelliSense, as informações de navegação, a refatoração e assim por diante. Conforme você trabalha, o Visual Studio monitora as alterações feitas no editor e também em disco para manter seu índice em sincronia com as fontes.

Você pode abrir pastas que contêm qualquer quantidade de projetos do CMake. O Visual Studio detecta e configura todos os arquivos *CMakeLists. txt* de "raiz" em seu espaço de trabalho. As operações CMake (configurar, compilar, depurar) C++ , IntelliSense e navegação estão disponíveis para todos os projetos do cmake em seu espaço de trabalho.

![Projeto do CMake com várias raízes](media/cmake-multiple-roots.png)

Você também pode exibir seus projetos logicamente organizados pelos destinos. Escolha **Exibição de destinos** na lista suspensa na barra de ferramentas do **Gerenciador de Soluções**:

![Botão de exibição de destinos do CMake](media/cmake-targets-view.png)

Clique no botão **Mostrar todos os arquivos** na parte superior da **Gerenciador de soluções** para ver todas as saídas geradas pelo CMake nas pastas *out/Build/\<config >* .

O Visual Studio usa um arquivo de configuração chamado **CMakeSettings. JSON**. Esse arquivo permite que você defina e armazene várias configurações de compilação e alterne convenientemente entre elas no IDE. Uma *configuração* é uma construção do Visual Studio que encapsula configurações específicas para um determinado tipo de compilação. As configurações são usadas para configurar as opções de linha de comando padrão que o Visual Studio passa para o CMake. exe. Você também pode especificar opções CMake adicionais aqui e definir quaisquer variáveis adicionais que desejar. Todas as opções são gravadas no cache CMake como variáveis internas ou externas. No Visual Studio 2019, o **Editor de configurações do cmake** fornece uma maneira conveniente de editar suas configurações. Para obter mais informações, confira [Personalizar configurações do CMake](customize-cmake-settings.md).

Uma configuração, `intelliSenseMode` não é passada para CMake, mas é usada somente pelo Visual Studio.

Use o arquivo **CMakeLists. txt** em cada pasta do projeto da mesma forma que faria em qualquer projeto do cmake. Você pode especificar arquivos de origem, localizar bibliotecas, definir opções de compilador e vinculador e especificar outras informações relacionadas ao sistema de compilação.

Para passar argumentos para um executável no momento da depuração, você pode usar outro arquivo chamado **Launch. vs. JSON**. Em alguns cenários, o Visual Studio gera esses arquivos automaticamente. Você pode editá-los manualmente ou até mesmo criar o arquivo por conta própria.

> [!NOTE]
> Para outros tipos de projetos de pasta aberta, dois arquivos JSON adicionais são usados: **CppProperties. JSON** e **Tasks. vs. JSON**. Nenhum deles é relevante para projetos do CMake.

## <a name="open-an-existing-cache"></a>Abrir um cache existente

Quando você abre um arquivo de cache CMake existente (*CMakeCache. txt*), o Visual Studio não tenta gerenciar seu cache e criar a árvore para você. Suas ferramentas personalizadas ou preferenciais têm controle total sobre como o CMake configura seu projeto. Para abrir um cache existente no Visual Studio, escolha **arquivo > abrir > CMake**. Em seguida, navegue até um arquivo *CMakeCache. txt* existente.

Você pode adicionar um cache CMake existente a um projeto aberto. Ele é feito da mesma maneira que você adicionaria uma nova configuração. Para obter mais informações, consulte nossa postagem de blog sobre como [abrir um cache existente no Visual Studio](https://devblogs.microsoft.com/cppblog/open-existing-cmake-caches-in-visual-studio/).

## <a name="building-cmake-projects"></a>Compilando projetos do CMake

Para compilar um projeto do CMake, você tem estas opções:

1. Na barra de ferramentas geral, localize o menu suspenso **configurações** . Ele provavelmente mostra "x64-debug" por padrão. Selecione a configuração preferencial e pressione **F5**ou clique no botão **executar** (triângulo verde) na barra de ferramentas. O projeto será compilado automaticamente pela primeira vez, assim como uma solução do Visual Studio.

1. Clique com o botão direito do mouse em *CMakeLists. txt* e selecione **Compilar** no menu de contexto. Se você tiver vários destinos na estrutura de pastas, opte por compilar todos ou apenas um destino específico.

1. No menu principal, selecione **compilar > compilar tudo** (**F7** ou **Ctrl + Shift + B**). Verifique se um destino do CMake já está selecionado na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**.

![Comando de menu de Build do CMake](media/cmake-build-menu.png "Menu de comando de Build do CMake")

Como se esperaria, os resultados do build são mostrados na **Janela de Saída** e na **Lista de Erros**.

![Erros de compilação de CMake](media/cmake-build-errors.png "Erros de compilação de CMake")

Em uma pasta com vários destinos de compilação, você pode especificar qual destino CMake compilar: escolha o item de **Build** no menu **CMake** ou o menu de contexto *CMakeLists. txt* para especificar o destino. Se você inserir **Ctrl + Shift + B** em um projeto CMake, ele criará o documento ativo atual.

## <a name="debugging-cmake-projects"></a>Depurando projetos do CMake

Para depurar um projeto CMake, escolha a configuração preferencial e pressione **F5**ou pressione o botão **executar** na barra de ferramentas. Se o botão **executar** indicar "selecionar item de inicialização", selecione a seta suspensa. Escolha o destino que você deseja executar. (Em um projeto do CMake, a opção "Documento atual" só é válida para arquivos .cpp.)

![Botão Executar CMake](media/cmake-run-button.png "Botão Executar CMake")

Os comandos **Executar** ou **F5** primeiro compilam o projeto se as alterações foram feitas desde o build anterior. Alterações em *CMakeSettings. JSON* fazem com que o cache CMake seja regenerado.

Você pode personalizar uma sessão de depuração CMake definindo as propriedades no arquivo **Launch. vs. JSON** . Para obter mais informações, confira [Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md).

## <a name="just-my-code-for-cmake-projects"></a>Apenas Meu Código para projetos CMake

Quando você cria para o Windows usando o compilador MSVC, os projetos CMake têm suporte para Apenas Meu Código depuração. Para alterar a configuração de Apenas Meu Código, vá para **ferramentas** > **opções** > **depuração** > **geral**.

## <a name="vcpkg-integration"></a>Integração do Vcpkg

Se você tiver instalado o [vcpkg](vcpkg.md), os projetos do cmake abertos no Visual Studio integrarão automaticamente o arquivo vcpkg ferramentas. Isso significa que nenhuma configuração adicional é necessária para usar o vcpkg com seus projetos do CMake. Esse suporte funciona para instalações locais do vcpkg e para instalações do vcpkg em sistemas remotos que você está direcionando. Esse comportamento é desabilitado automaticamente quando você especifica qualquer outro ferramentas na configuração de suas configurações de CMake.

## <a name="customize-configuration-feedback"></a>Personalizar comentários de configuração

Por padrão, a maioria das mensagens de configuração são suprimidas, a menos que haja um erro. Você pode ver todas as mensagens habilitando esse recurso em **ferramentas** > **Opções** > **CMake**.

   ![Configurando opções de diagnóstico do CMake](media/vs2019-cmake-configure-options.png "Opções de diagnóstico do CMake")

## <a name="editing-cmakeliststxt-files"></a>Editando arquivos CMakeLists.txt

Para editar um arquivo *CMakeLists. txt* , clique com o botão direito do mouse no arquivo em **Gerenciador de soluções** e escolha **abrir**. Se você fizer alterações no arquivo, uma barra de status amarela será exibida e informará que o IntelliSense será atualizado. Ele oferece a oportunidade de cancelar a operação de atualização. Para obter informações sobre o *CMakeLists. txt*, consulte a [documentação do cmake](https://cmake.org/documentation/).

   ![Edição de arquivo CMakeLists. txt](media/cmake-cmakelists.png "Edição de arquivo CMakeLists. txt")

Assim que você salva o arquivo, a etapa de configuração é executada novamente de forma automática e exibe as informações na janela de **Saída**. Os erros e avisos são mostrados na **Lista de Erros** ou na janela de **Saída**. Clique duas vezes em um erro na **lista de erros** para navegar até a linha incorreta em *CMakeLists. txt*.

   ![Erros de arquivo CMakeLists. txt](media/cmake-cmakelists-error.png "Erros de arquivo CMakeLists. txt")

## <a name="cmake-configure-step"></a>Etapa de configuração do CMake

Quando você faz alterações significativas nos arquivos *CMakeSettings. JSON* ou *CMakeLists. txt* , o Visual Studio executa automaticamente a etapa de configuração do cmake. Se a etapa configurar for concluída sem erros, as informações coletadas estarão disponíveis no C++ IntelliSense e nos serviços de linguagem. Ele também é usado em operações de compilação e depuração.

## <a name="troubleshooting-cmake-cache-errors"></a>Solução de problemas de erros do cache do CMake

Se você precisar de mais informações sobre o estado do cache CMake para diagnosticar um problema, abra o menu principal do **projeto** ou o menu de contexto *CMakeLists. txt* no **Gerenciador de soluções** para executar um destes comandos:

- **Exibir cache** abre o arquivo *CMakeCache. txt* na pasta raiz de compilação no editor. (As edições feitas aqui para *CMakeCache. txt* serão apagadas se você limpar o cache. Para fazer alterações que persistam após a limpeza do cache, consulte [Personalizar configurações de CMake](customize-cmake-settings.md).)

- **Abrir Pasta do Cache** abre uma janela do Explorer na pasta raiz de build.

- **Limpar Cache** exclui a pasta raiz de build, de modo que a próxima etapa de configuração do CMake seja iniciada com um cache limpo.

- **Gerar cache** força a etapa de geração a ser executada mesmo que o Visual Studio considere o ambiente atualizado.

A geração de cache automático pode ser desabilitada nas **ferramentas > opções > CMake >** caixa de diálogo geral.

## <a name="run-cmake-from-the-command-line"></a>Executar CMake na linha de comando

Se tiver instalado o CMake do Instalador do Visual Studio, será possível executá-lo na linha de comando seguindo estas etapas:

1. Execute o vsdevcmd.bat (x86/x64) adequado. Para obter mais informações, consulte [criando na linha de comando](building-on-the-command-line.md).

1. Alterne para sua pasta de saída.

1. Execute o CMake para criar/configurar seu aplicativo.

::: moniker-end

::: moniker range="vs-2017"

O Visual Studio 2017 tem suporte avançado para CMake, incluindo [projetos CMake de plataforma cruzada](../linux/cmake-linux-project.md). O **componente C++ ferramentas visuais para CMake** usa o recurso **abrir pasta** para permitir que o IDE consuma arquivos de projeto CMake (como *CMakeLists. txt*) diretamente para fins de IntelliSense e navegação. Há suporte para geradores Ninja e Visual Studio. Se você usar um gerador do Visual Studio, ele gerará um arquivo de projeto temporário e o passará para o MSBuild. exe. No entanto, o projeto nunca é carregado para fins de navegação ou IntelliSense. Você também pode importar um cache CMake existente.

## <a name="installation"></a>Instalação

**As C++ ferramentas visuais para CMake** são instaladas como parte do desenvolvimento de **desktop com C++**  o e do **desenvolvimento do Linux com C++**  cargas de trabalho.

![Componente CMake na carga de trabalho Desktop com C++](media/cmake-install.png)

Para obter mais informações, confira [Instalar a carga de trabalho do Linux em C++ no Visual Studio](../linux/download-install-and-setup-the-linux-development-workload.md).

## <a name="ide-integration"></a>Integração de IDE

Quando você escolhe **arquivo > abrir > pasta** para abrir uma pasta que contém um arquivo *CMakeLists. txt* , ocorre o seguinte:

- O Visual Studio adiciona um item de menu **CMake** ao menu principal, com comandos para exibição e edição de scripts do CMake.

- O **Gerenciador de Soluções** exibe a estrutura de pastas e os arquivos.

- O Visual Studio executa CMake.exe e, opcionalmente, gera o cache do CMake para a *configuração* padrão, que é Depuração x86. A linha de comando do CMake é exibida na **Janela de Saída**, juntamente com uma saída adicional do CMake.

- Em segundo plano, o Visual Studio começa a indexar os arquivos de origem para habilitar o IntelliSense, as informações de navegação, a refatoração e assim por diante. Conforme você trabalha, o Visual Studio monitora as alterações feitas no editor e também em disco para manter seu índice em sincronia com as fontes.

Você pode abrir pastas que contêm qualquer quantidade de projetos do CMake. O Visual Studio detecta e configura todos os arquivos *CMakeLists. txt* de "raiz" em seu espaço de trabalho. As operações CMake (configurar, compilar, depurar) C++ , IntelliSense e navegação estão disponíveis para todos os projetos do cmake em seu espaço de trabalho.

![Projeto do CMake com várias raízes](media/cmake-multiple-roots.png)

Você também pode exibir seus projetos logicamente organizados pelos destinos. Escolha **Exibição de destinos** na lista suspensa na barra de ferramentas do **Gerenciador de Soluções**:

![Botão de exibição de destinos do CMake](media/cmake-targets-view.png)

O Visual Studio usa um arquivo chamado *CMakeSettings. JSON* para armazenar variáveis de ambiente ou opções de linha de comando para CMake. exe. O *CMakeSettings. JSON* também permite que você defina e armazene várias configurações de compilação do cmake. Você pode alternar de forma conveniente entre eles no IDE.

Caso contrário, use o *CMakeLists. txt* da mesma forma que faria em qualquer projeto do cmake para especificar arquivos de origem, localizar bibliotecas, definir opções de compilador e vinculador e especificar outras informações relacionadas ao sistema de compilação.

Se você precisar passar argumentos para um executável no momento da depuração, poderá usar outro arquivo chamado **Launch. vs. JSON**. Em alguns cenários, o Visual Studio gera esses arquivos automaticamente. Você pode editá-los manualmente ou até mesmo criar o arquivo por conta própria.

> [!NOTE]
> Para outros tipos de projetos de pasta aberta, dois arquivos JSON adicionais são usados: **CppProperties. JSON** e **Tasks. vs. JSON**. Nenhum deles é relevante para projetos do CMake.

## <a name="import-an-existing-cache"></a>Importar um cache existente

Quando você importa um arquivo *CMakeCache. txt* existente, o Visual Studio extrai automaticamente as variáveis personalizadas e cria um arquivo *CMakeSettings. JSON* previamente populado com base neles. O cache original não é modificado de forma alguma. Ele ainda pode ser usado na linha de comando ou com qualquer ferramenta ou IDE usado para gerá-lo. O novo arquivo *CMakeSettings. JSON* é colocado junto com o *CMakeLists. txt*raiz do projeto. O Visual Studio gera um novo cache com base no arquivo de configurações. Você pode substituir a geração de cache automática nas **ferramentas > opções > CMake >** caixa de diálogo geral.

Nem tudo no cache é importado.  Propriedades, como o gerador e o local dos compiladores, são substituídas pelos padrões conhecidos por funcionar bem com o IDE.

### <a name="to-import-an-existing-cache"></a>Para importar um cache existente

1. No menu principal, escolha **arquivo > abrir > CMake**:

   ![Abrir CMake](media/cmake-file-open.png "Arquivo, abrir, CMake")

   Esse comando abre o assistente de **importação de CMake do cache** .

2. Navegue até o arquivo *CMakeCache. txt* que você deseja importar e clique em **OK**. O assistente para **Importar Projeto do CMake do Cache** será exibido:

   ![Importar um cache CMake](media/cmake-import-wizard.png "Abrir o assistente de cache de importação CMake")

   Quando o assistente for concluído, você poderá ver o novo arquivo *CMakeCache. txt* em **Gerenciador de soluções** ao lado do arquivo *CMakeLists. txt* raiz em seu projeto.

## <a name="building-cmake-projects"></a>Compilando projetos do CMake

Para compilar um projeto do CMake, você tem estas opções:

1. Na barra de ferramentas geral, localize o menu suspenso **configurações** . É provável que esteja mostrando "Linux-debug" ou "x64-debug" por padrão. Selecione a configuração preferencial e pressione **F5**ou clique no botão **executar** (triângulo verde) na barra de ferramentas. O projeto será compilado automaticamente pela primeira vez, assim como uma solução do Visual Studio.

1. Clique com o botão direito do mouse em *CMakeLists. txt* e selecione **Compilar** no menu de contexto. Se você tiver vários destinos na estrutura de pastas, opte por compilar todos ou apenas um destino específico.

1. No menu principal, selecione **compilar > Compilar solução** (**F7** ou **Ctrl + Shift + B**). Verifique se um destino do CMake já está selecionado na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**.

![Comando de menu de Build do CMake](media/cmake-build-menu.png "Menu de comando de Build do CMake")

Você pode personalizar configurações de compilação, variáveis de ambiente, argumentos de linha de comando e outras configurações no arquivo *CMakeSettings. JSON* . Ele permite que você faça alterações sem modificar o arquivo *CMakeLists. txt* . Para obter mais informações, confira [Personalizar configurações do CMake](customize-cmake-settings.md).

Como se esperaria, os resultados do build são mostrados na **Janela de Saída** e na **Lista de Erros**.

![Erros de compilação de CMake](media/cmake-build-errors.png "Erros de compilação de CMake")

Em uma pasta com vários destinos de compilação, você pode especificar qual destino CMake compilar: escolha o item de **Build** no menu **CMake** ou o menu de contexto *CMakeLists. txt* para especificar o destino. Se você inserir **Ctrl + Shift + B** em um projeto CMake, ele criará o documento ativo atual.

## <a name="debugging-cmake-projects"></a>Depurando projetos do CMake

Para depurar um projeto CMake, escolha a configuração preferencial e pressione **F5**. Ou então, pressione o botão **executar** na barra de ferramentas. Se o botão **Executar** indicar "Selecione o Item de Inicialização", selecione a seta suspensa e escolha o destino que deseja executar. (Em um projeto do CMake, a opção "Documento atual" só é válida para arquivos .cpp.)

![Botão Executar CMake](media/cmake-run-button.png "Botão Executar CMake")

Os comandos **Executar** ou **F5** primeiro compilam o projeto se as alterações foram feitas desde o build anterior.

Você pode personalizar uma sessão de depuração CMake definindo as propriedades no arquivo **Launch. vs. JSON** . Para obter mais informações, confira [Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md).

## <a name="editing-cmakeliststxt-files"></a>Editando arquivos CMakeLists.txt

Para editar um arquivo *CMakeLists. txt* , clique com o botão direito do mouse no arquivo em **Gerenciador de soluções** e escolha **abrir**. Se você fizer alterações no arquivo, uma barra de status amarela será exibida e informará que o IntelliSense será atualizado. Ele oferece a oportunidade de cancelar a operação de atualização. Para obter informações sobre o *CMakeLists. txt*, consulte a [documentação do cmake](https://cmake.org/documentation/).

   ![Edição de arquivo CMakeLists. txt](media/cmake-cmakelists.png "Edição de arquivo CMakeLists. txt")

Assim que você salva o arquivo, a etapa de configuração é executada novamente de forma automática e exibe as informações na janela de **Saída**. Os erros e avisos são mostrados na **Lista de Erros** ou na janela de **Saída**. Clique duas vezes em um erro na **lista de erros** para navegar até a linha incorreta em *CMakeLists. txt*.

   ![Erros de arquivo CMakeLists. txt](media/cmake-cmakelists-error.png "Erros de arquivo CMakeLists. txt")

## <a name="cmake-configure-step"></a>Etapa de configuração do CMake

Quando são feitas alterações significativas nos arquivos *CMakeSettings. JSON* ou *CMakeLists. txt* , o Visual Studio executa automaticamente a etapa de configuração do cmake. Se a etapa configurar for concluída sem erros, as informações coletadas estarão disponíveis no C++ IntelliSense e nos serviços de linguagem. Ele também é usado em operações de compilação e depuração.

Vários projetos CMake podem usar o mesmo nome de configuração CMake (por exemplo, x86-Debug). Todos eles são configurados e compilados (em sua própria pasta raiz de compilação) quando essa configuração é selecionada. Depure os destinos de todos os projetos do CMake que participam dessa configuração do CMake.

   ![Item de menu somente Build do CMake](media/cmake-build-only.png "Item de menu somente Build do CMake")

Você pode limitar compilações e sessões de depuração a um subconjunto dos projetos no espaço de trabalho. Crie uma nova configuração com um nome exclusivo no arquivo *CMakeSettings. JSON* . Em seguida, aplique a configuração somente a esses projetos. Quando essa configuração é selecionada, o IntelliSense e os comandos de compilação e depuração se aplicam somente a esses projetos especificados.

## <a name="troubleshooting-cmake-cache-errors"></a>Solução de problemas de erros do cache do CMake

Caso precise obter mais informações sobre o estado do cache do CMake para diagnosticar um problema, abra o menu principal do **CMake** ou o menu de contexto de *CMakeLists.txt* no **Gerenciador de Soluções** para executar um destes comandos:

- **Exibir cache** abre o arquivo *CMakeCache. txt* na pasta raiz de compilação no editor. (As edições feitas aqui para *CMakeCache. txt* serão apagadas se você limpar o cache. Para fazer alterações que persistam após a limpeza do cache, consulte [Personalizar configurações de CMake](customize-cmake-settings.md).)

- **Abrir Pasta do Cache** abre uma janela do Explorer na pasta raiz de build.

- **Limpar Cache** exclui a pasta raiz de build, de modo que a próxima etapa de configuração do CMake seja iniciada com um cache limpo.

- **Gerar cache** força a etapa de geração a ser executada mesmo que o Visual Studio considere o ambiente atualizado.

A geração de cache automático pode ser desabilitada nas **ferramentas > opções > CMake >** caixa de diálogo geral.

## <a name="single-file-compilation"></a>Compilação de arquivo único

Para criar um único arquivo em um projeto CMake, clique com o botão direito do mouse no arquivo em **Gerenciador de soluções**. Escolha **Compilar** no menu pop-up. Você também pode criar o arquivo aberto no editor usando o menu **CMake** principal:

![Compilação de arquivo único do CMake](media/cmake-single-file-compile.png)

## <a name="run-cmake-from-the-command-line"></a>Executar CMake na linha de comando

Se tiver instalado o CMake do Instalador do Visual Studio, será possível executá-lo na linha de comando seguindo estas etapas:

1. Execute o vsdevcmd.bat (x86/x64) adequado. Para obter mais informações, consulte [criando na linha de comando](building-on-the-command-line.md) .

1. Alterne para sua pasta de saída.

1. Execute o CMake para criar/configurar seu aplicativo.

::: moniker-end

::: moniker range="vs-2015"

No Visual Studio 2015, os usuários do Visual Studio podem usar um [gerador do CMake](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) para gerar arquivos de projeto do MSBuild, que o IDE então consome para IntelliSense, navegação e compilação.

::: moniker-end

## <a name="see-also"></a>Veja também

[Tutorial: criar C++ projetos de plataforma cruzada no Visual Studio](get-started-linux-cmake.md)\
[Configurar um projeto CMake do Linux](../linux/cmake-linux-project.md)\
[Conecte-se ao seu computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)\
[Personalizar as configurações de compilação do CMake](customize-cmake-settings.md)\
[Referência de esquema CMakeSettings. json](cmakesettings-reference.md)\
[Configurar sessões de depuração CMake](configure-cmake-debugging-sessions.md)\
[Implante, execute e depure seu projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)\
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)
