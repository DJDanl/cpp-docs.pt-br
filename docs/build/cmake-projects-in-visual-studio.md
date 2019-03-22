---
title: Projetos do CMake no Visual Studio
ms.date: 03/05/2019
helpviewer_keywords:
- CMake in Visual C++
ms.assetid: 444d50df-215e-4d31-933a-b41841f186f8
ms.openlocfilehash: 84511c0712fffcacc1f90d4bde808620e0a0ab0f
ms.sourcegitcommit: 42e65c171aaa17a15c20b155d22e3378e27b4642
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2019
ms.locfileid: "58356135"
---
# <a name="cmake-projects-in-visual-studio"></a>Projetos do CMake no Visual Studio

O CMake é uma ferramenta multiplataforma de software livre para definir os processos de build executados em várias plataformas. Esse artigo pressupõe que você está familiarizado com CMake. Você pode aprender mais sobre isso em [Compilar, Testar e Empacotar seu Software com o CMake](https://cmake.org/).

No Visual Studio 2015, os usuários do Visual Studio podem usar um [gerador do CMake](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) para gerar arquivos de projeto do MSBuild, que o IDE então consome para IntelliSense, navegação e compilação.

O Visual Studio 2017 apresenta suporte avançado para CMake, incluindo [projetos do CMake multiplataforma](../linux/cmake-linux-project.md). O componente **Ferramentas do Visual C++ para CMake** usa o recurso **Abrir Pasta** para permitir o consumo pelo IDE de arquivos de projeto do CMake (como CMakeLists.txt) diretamente para as finalidades do IntelliSense e de navegação. Há suporte para geradores Ninja e Visual Studio. Se você usar um gerador do Visual Studio, um arquivo de projeto temporário será gerado e passado para msbuild.exe, mas nunca será carregado para as finalidades do IntelliSense ou de navegação. Você pode importar um cache de CMake existente; Visual Studio automaticamente extrai variáveis personalizadas e cria um pré-populada **Cmakesettings** arquivo. 

## <a name="installation"></a>Instalação

O recurso **Ferramentas do Visual C++ para CMake** é instalado por padrão como parte da carga de trabalho de **Desenvolvimento para desktop com C++** e como parte da carga de trabalho de **Desenvolvimento para Linux com C++**.

![Componente CMake na carga de trabalho Desktop com C++](media/cmake-install.png)

Para obter mais informações, confira [Instalar a carga de trabalho do Linux em C++ no Visual Studio](../linux/download-install-and-setup-the-linux-development-workload.md).

## <a name="ide-integration"></a>Integração com o IDE

Quando você escolhe **Arquivo | Abrir | Pasta** para abrir uma pasta que contém um arquivo CMakeLists.txt, as seguintes ações ocorrem:

- O Visual Studio adiciona um item de menu **CMake** ao menu principal, com comandos para exibição e edição de scripts do CMake.

- O **Gerenciador de Soluções** exibe a estrutura de pastas e os arquivos.

- O Visual Studio executa CMake.exe e, opcionalmente, gera o cache do CMake para a *configuração* padrão, que é Depuração x86. A linha de comando do CMake é exibida na **Janela de Saída**, juntamente com uma saída adicional do CMake.

- Em segundo plano, o Visual Studio começa a indexar os arquivos de origem para habilitar o IntelliSense, as informações de navegação, a refatoração e assim por diante. Conforme você trabalha, o Visual Studio monitora as alterações feitas no editor e também em disco para manter seu índice em sincronia com as fontes.

Você pode abrir pastas que contêm qualquer quantidade de projetos do CMake. O Visual Studio detecta e configura todos os arquivos CMakeLists.txt "raiz" no workspace. As operações do CMake (configuração, build, depuração), bem como o C++ IntelliSense e a navegação, estão disponíveis para todos os projetos do CMake no workspace.

![Projeto do CMake com várias raízes](media/cmake-multiple-roots.png)

Você também pode exibir seus projetos logicamente organizados pelos destinos. Escolha **Exibição de destinos** na lista suspensa na barra de ferramentas do **Gerenciador de Soluções**:

![Botão de exibição de destinos do CMake](media/cmake-targets-view.png)

O Visual Studio usa um arquivo chamado **Cmakesettings** para armazenar as variáveis de ambiente ou as opções de linha de comando para Cmake.exe. **Cmakesettings** também permite que você para definir e armazenar CMake várias configurações de build e alternar convenientemente entre elas no IDE. 

Caso contrário, use o **cmakelists. txt** exatamente como você faria em qualquer projeto de CMake para especificar arquivos de origem, encontrar bibliotecas, defina as opções compilador e vinculador e especifique outro sistema de build informações relacionadas.

Se você precisar passar argumentos para um executável no tempo de depuração, você pode usar outro arquivo chamado **Launch**. Em alguns cenários, o Visual Studio gerará automaticamente esses arquivos e você pode editá-los manualmente. Você também pode criar o arquivo por conta própria.

> [!NOTE]
> Para outros tipos de projetos de pasta aberta, dois arquivos adicionais do JSON são usados: **Cppproperties** e **Tasks**. Nenhum deles é relevante para projetos do CMake.

## <a name="import-an-existing-cache"></a>Importar um cache existente

Quando você importa um arquivo existente de cmakecache. txt, o Visual Studio automaticamente extrai variáveis personalizadas e cria um previamente preenchido [ **Cmakesettings** ](#cmake_settings) arquivo com base neles. O cache original não é modificado de forma alguma e ainda pode ser usado na linha de comando ou com qualquer ferramenta ou IDE que foi usado para gerá-lo. O novo **Cmakesettings** arquivo é colocado ao lado da raiz do projeto cmakelists. txt. O Visual Studio gera um novo cache com base no arquivo de configurações. Você pode substituir a geração automática de cache na caixa de diálogo **Ferramentas | Opções | CMake | Geral**.

Nem tudo no cache é importado.  Propriedades, como o gerador e o local dos compiladores, são substituídas pelos padrões conhecidos por funcionar bem com o IDE.

### <a name="to-import-an-existing-cache"></a>Para importar um cache existente

1. No menu principal, escolha **Arquivo | Abrir | CMake**:

   ![Abrir o CMake](media/cmake-file-open.png "Arquivo, Abrir, CMake")

   Isso abrirá o assistente para **Importar o CMake do Cache**.

2. Navegue para o arquivo CMakeCache.txt que deseja importar e, em seguida, clique em **OK**. O assistente para **Importar Projeto do CMake do Cache** será exibido:

   ![Importar um cache do CMake](media/cmake-import-wizard.png "Abrir o assistente para importar cache do CMake")

   Quando o assistente for concluído, você poderá ver o novo arquivo CMakeCache.txt no **Gerenciador de Soluções** ao lado do arquivo CMakeLists.txt raiz no projeto.

## <a name="building-cmake-projects"></a>Compilando projetos do CMake

Para compilar um projeto do CMake, você tem estas opções:

1. Na barra de ferramentas geral, localize o **configurações** lista suspensa; ele provavelmente está mostrando "Linux-Debug" ou "Debug-x64" por padrão. Selecione a configuração desejada e pressione **F5**, ou clique no **executar** botão (triângulo verde) na barra de ferramentas. O projeto será compilado automaticamente pela primeira vez, assim como uma solução do Visual Studio.

1. Clique com o botão direito do mouse em CMakeLists.txt e selecione **Build** no menu de contexto. Se você tiver vários destinos na estrutura de pastas, opte por compilar todos ou apenas um destino específico.

1. No menu principal, selecione **Build | Compilar Solução** (**F7** ou **Ctrl+Shift+B**). Verifique se um destino do CMake já está selecionado na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**.

![Comando de menu de build do CMake](media/cmake-build-menu.png "Menu de comando de build do CMake")

Você pode personalizar configurações de build, variáveis de ambiente, os argumentos de linha de comando e outras configurações sem modificar o arquivo Cmakelists txt usando o **Cmakesettings** arquivo. Para obter mais informações, confira [Personalizar configurações do CMake](customize-cmake-settings.md).

Como se esperaria, os resultados do build são mostrados na **Janela de Saída** e na **Lista de Erros**.

![Erros de build do CMake](media/cmake-build-errors.png "CMake build errors")

Em uma pasta com vários destinos de build, escolha o item **Build** no menu do **CMake** ou o menu de contexto **CMakeLists.txt** para especificar qual destino do CMake compilar. Se você pressionar **Ctrl+Shift+B** em um projeto do CMake, isso compilará o documento ativo atual.

## <a name="debugging-cmake-projects"></a>Depurando projetos do CMake

Para depurar um projeto do CMake, escolha a configuração desejada e pressione **F5** ou pressione o botão **Executar** na barra de ferramentas. Se o botão **Executar** indicar "Selecione o Item de Inicialização", selecione a seta suspensa e escolha o destino que deseja executar. (Em um projeto do CMake, a opção "Documento atual" só é válida para arquivos .cpp.)

![Botão de execução do CMake](media/cmake-run-button.png "Botão de execução do CMake")

Os comandos **Executar** ou **F5** primeiro compilam o projeto se as alterações foram feitas desde o build anterior.

Você pode personalizar uma sessão de depuração definindo propriedades de CMake a **Launch** arquivo. Para obter mais informações, confira [Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md).


## <a name="editing-cmakeliststxt-files"></a>Editando arquivos CMakeLists.txt

Para editar um arquivo CMakeLists.txt, clique com o botão direito do mouse no arquivo no **Gerenciador de Soluções** e escolha **Abrir**. Se você faz alterações no arquivo, uma barra de status amarela é exibida e informa você que o IntelliSense será atualizado, oferecendo a oportunidade de cancelar a operação de atualização. Para obter informações sobre CMakeLists.txt, confira a [documentação do CMake](https://cmake.org/documentation/).

   ![Edição do arquivo CMakeLists.txt](media/cmake-cmakelists.png "CMakeLists.txt file editing")

Assim que você salva o arquivo, a etapa de configuração é executada novamente de forma automática e exibe as informações na janela de **Saída**. Os erros e avisos são mostrados na **Lista de Erros** ou na janela de **Saída**. Clique duas vezes em um erro na **Lista de Erros** para navegar para a linha incorreta em CMakeLists.txt.

   ![Erros do arquivo CMakeLists.txt](media/cmake-cmakelists-error.png "CMakeLists.txt file errors")


## <a name="cmake-configure-step"></a>Etapa de configuração do CMake

Quando as alterações significativas são feitas para o **Cmakesettings** ou arquivos cmakelists. txt, Visual Studio automaticamente executa novamente o CMake configurar etapa. Se a etapa de configuração é concluída sem erros, as informações coletadas ficam disponíveis nos serviços de linguagem e no C++ IntelliSense e também nas operações de build e de depuração.

Quando vários projetos do CMake usam o mesmo nome de configuração do CMake (por exemplo, x86-Debug), todos eles são configurados e compilados (em sua própria pasta raiz de build) quando essa configuração é selecionada. Depure os destinos de todos os projetos do CMake que participam dessa configuração do CMake.

   ![Item de menu Somente Build do CMake](media/cmake-build-only.png "CMake Build Only menu item")

Para limitar os builds e depurar sessões para um subconjunto dos projetos no espaço de trabalho, criar uma nova configuração com um nome exclusivo na **Cmakesettings** de arquivo e aplicá-lo para apenas esses projetos. Quando essa configuração é selecionada, os comandos de build, de depuração e do IntelliSense são habilitados apenas para esses projetos especificados.

## <a name="troubleshooting-cmake-cache-errors"></a>Solução de problemas de erros do cache do CMake

Caso precise obter mais informações sobre o estado do cache do CMake para diagnosticar um problema, abra o menu principal do **CMake** ou o menu de contexto de **CMakeLists.txt** no **Gerenciador de Soluções** para executar um destes comandos:

- **Exibir Cache** abre o arquivo CMakeCache.txt na pasta raiz de build no editor. (Todas as edições feitas aqui em CMakeCache.txt são apagadas se o cache é limpo. Para fazer alterações que persistem depois que o cache é limpo, confira [Configurações do CMake e configurações personalizadas](#cmake_settings) anteriormente neste artigo.)

- **Abrir Pasta do Cache** abre uma janela do Explorer na pasta raiz de build.

- **Limpar Cache** exclui a pasta raiz de build, de modo que a próxima etapa de configuração do CMake seja iniciada com um cache limpo.

- **Gerar Cache** força a execução da etapa de geração, mesmo se o Visual Studio considera o ambiente atualizado.

A geração automática de cache pode ser desabilitada na caixa de diálogo **Ferramentas | Opções | CMake | Geral**.

## <a name="single-file-compilation"></a>Compilação de arquivo único

Para criar um arquivo único em um projeto do CMake, clique com o botão direito do mouse no arquivo no **Gerenciador de Soluções** e escolha **Compilar**. Você também pode criar o arquivo que está aberto no editor no momento usando o menu principal do CMake:

![Compilação de arquivo único do CMake](media/cmake-single-file-compile.png)

## <a name="run-cmake-from-the-command-line"></a>Executar CMake na linha de comando

Se tiver instalado o CMake do Instalador do Visual Studio, será possível executá-lo na linha de comando seguindo estas etapas:

1. Execute o vsdevcmd.bat (x86/x64) adequado. Consulte [Compilando na linha de comando](building-on-the-command-line.md) para obter mais informações.

1. Alterne para sua pasta de saída.

1. Execute o CMake para criar/configurar seu aplicativo.
  
## <a name="see-also"></a>Consulte também

[Tutorial: Criar projetos de plataforma cruzada do C++ no Visual Studio](get-started-linux-cmake.md)<br/>
[Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/>
[Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/>
[Personalizar as configurações de compilação do CMake](customize-cmake-settings.md)<br/>
[Referência de CMakeSettings.json](cmakesettings-reference.md)<br/>
[Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)<br/>
