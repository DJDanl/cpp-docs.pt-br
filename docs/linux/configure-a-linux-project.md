---
title: Configurar um projeto C++ do MSBuild do Linux no Visual Studio
ms.date: 10/16/2020
description: Configure um projeto do Linux baseado em MSBuild no Visual Studio para que você possa compilá-lo.
ms.assetid: 4d7c6adf-54b9-4b23-bd23-5de0c825b768
ms.openlocfilehash: 51837dc86d041b9120f984cc01f8db06d696b292
ms.sourcegitcommit: f19f02f217b80804ab321d463c76ce6f681abcc6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/19/2020
ms.locfileid: "92176336"
---
# <a name="configure-a-linux-msbuild-c-project-in-visual-studio"></a>Configurar um projeto C++ do MSBuild do Linux no Visual Studio

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

Este tópico descreve como configurar um projeto do Linux baseado em MSBuild, conforme descrito em [criar um projeto C++ do MSBuild do Linux no Visual Studio](create-a-new-linux-project.md). Para projetos CMake do Linux, consulte [configurar um projeto CMake do Linux](cmake-linux-project.md).

Configure um projeto do Linux para ter como destino um computador Linux físico, uma máquina virtual ou o [WSL](/windows/wsl/about) (Subsistema do Windows para Linux).

::: moniker range="vs-2019"

**Visual Studio 2019 versão 16,1**:

- Ao direcionar WSL, você pode evitar as operações de cópia necessárias para compilar e obter o IntelliSense necessário ao direcionar um sistema Linux remoto.

- Especifique destinos do Linux separados para build e depuração.

::: moniker-end

## <a name="general-settings"></a>Configurações gerais

Para exibir as opções de configuração, selecione o menu **Propriedades do projeto >** ou clique com o botão direito do mouse no projeto em **Gerenciador de soluções** e selecione **Propriedades** no menu de contexto. As **Configurações gerais** são exibidas.

![Configuração geral](media/settings_general.png)

Por padrão, um executável (.out) é criado. Para criar uma biblioteca estática ou dinâmica ou usar um Makefile existente, use a configuração **Tipo de Configuração**.

Se você estiver criando um subsistema do Windows para Linux (WSL), a versão 1 do WSL será limitada a 64 processos de compilação paralela. Isso é regido pela configuração **máximo de trabalhos de compilação paralela** nas **propriedades de configuração > C/C++ > geral**.

Independentemente da versão do WSL que você está usando, se você pretende usar mais de 64 processos de compilação paralela, recomendamos que você crie com o ninja, que geralmente será mais rápido e confiável. Para criar com o ninja, use a configuração **habilitar compilação incremental** nas **propriedades de configuração > geral**.

Para obter mais informações sobre as configurações nas páginas de propriedades, confira [Referência da página de propriedades do projeto do Linux](prop-pages-linux.md).

## <a name="remote-settings"></a>Configurações remotas

Para alterar as configurações relacionadas ao computador Linux remoto, defina as configurações remotas que aparecem em [geral](prop-pages/general-linux.md).

- Para especificar um computador Linux de destino remoto, use a entrada **Computador de Build Remoto**. Isso permitirá selecionar uma das conexões criadas anteriormente. Para criar uma entrada, confira a seção [Como se conectar ao computador Linux remoto](connect-to-your-remote-linux-computer.md).

   ![Computador de build](media/remote-build-machine-vs2019.png)

   ::: moniker range="vs-2019"

   **Visual Studio 2019 versão 16,7**: para direcionar o subsistema do Windows para Linux (WSL), defina a lista suspensa do **conjunto de ferramentas de plataforma** para **gcc para o subsistema do Windows para Linux**. As outras opções remotas desaparecerão e o caminho para o shell padrão do WSL será exibido em seu lugar:

   ![Computador de build do WSL](media/wsl-remote-vs2019.png)

   Se você tiver instalações do WSL lado a lado, especifique outro caminho aqui. Para obter mais informações sobre como gerenciar várias distribuições, confira [Gerenciar e configurar o Subsistema do Windows para Linux](/windows/wsl/wsl-config#set-a-default-distribution).

   Especifique outro destino para depuração na página **Propriedades de Configuração** > **Depuração**.

   ::: moniker-end

- O **Diretório Raiz de Build Remoto** determina o local raiz de onde o projeto é compilado no computador Linux remoto. Isso definirá **~/projects** como padrão, a menos que tenha sido alterado.

- O **Diretório de Projeto de Build Remoto** é onde esse projeto específico será criado no computador Linux remoto. Isso definirá **$(RemoteRootDir)/$(ProjectName)** como padrão, que será expandido para um diretório nomeado depois do projeto atual, no diretório raiz definido acima.

> [!NOTE]
> Para alterar os compiladores padrão C e C++ ou o Vinculador e o Arquivador usados para compilar o projeto, use as entradas apropriadas nas seções **C/C++ > Geral** e **Vinculador > Geral**. Você pode especificar uma versão específica do GCC ou do Clang, por exemplo. Para obter mais informações, consulte [Propriedades do C/C++ (Linux c++)](prop-pages/c-cpp-linux.md) e [Propriedades do vinculador (Linux c++)](prop-pages/linker-linux.md).

## <a name="copy-sources-remote-systems-only"></a>Copiar fontes (apenas sistemas remotos)

::: moniker range="vs-2019"

Esta seção não se aplica ao direcionamento de WSL.

::: moniker-end

Durante o build em sistemas remotos, os arquivos de origem no computador de desenvolvimento são copiados para o computador Linux e compilados nele. Por padrão, todas as fontes no projeto do Visual Studio são copiadas para os locais definidos nas configurações acima. No entanto, outras fontes também podem ser adicionadas à lista ou copiar fontes pode ser totalmente desativado, que é o padrão para um projeto Makefile.

- **Fontes a serem copiadas** determina quais fontes são copiadas para o computador remoto. Por padrão, o ** \@ (SourcesToCopyRemotely)** usa como padrão todos os arquivos de código-fonte no projeto, mas não inclui nenhum arquivo de recurso/ativo, como imagens.

- **Copiar fontes** pode ser ativado e desativado para habilitar e desabilitar a cópia de arquivos de origem para o computador remoto.

- As **fontes adicionais a serem copiadas** permitem que você adicione arquivos de origem adicionais, que serão copiados para o sistema remoto. É possível especificar uma lista delimitada por ponto-e-vírgula ou usar a sintaxe **:=** para especificar um nome local e remoto a ser usado:

`C:\Projects\ConsoleApplication1\MyFile.cpp:=~/projects/ConsoleApplication1/ADifferentName.cpp;C:\Projects\ConsoleApplication1\MyFile2.cpp:=~/projects/ConsoleApplication1/ADifferentName2.cpp;`

## <a name="build-events"></a>Eventos de build

Como toda a compilação está acontecendo em um computador remoto (ou no WSL), vários outros eventos de build foram adicionados à seção Eventos de Build em Propriedades do Projeto. Eles são os **Evento de pré-build remoto**, **Evento de pré-link remoto** e **Evento de pós-build remoto**, que ocorrerão no computador remoto antes ou após as etapas individuais no processo.

![Eventos de compilação](media/settings_buildevents.png)

## <a name="intellisense-for-headers-on-remote-systems"></a><a name="remote_intellisense"></a> IntelliSense para cabeçalhos em sistemas remotos

Quando você adiciona uma nova conexão no **Gerenciador de Conexões**, o Visual Studio detecta automaticamente os diretórios de inclusão para o compilador no sistema remoto. Visual Studio compacta e copia os arquivos para um diretório no seu computador local do Windows. Depois disso, sempre que você usar essa conexão em um projeto do Visual Studio ou CMake, os cabeçalhos nesses diretórios serão usados para fornecer IntelliSense.

> [!NOTE]
> No Visual Studio 2019 versão 16,5 e posterior, a cópia de cabeçalho remoto foi otimizada. Os cabeçalhos agora são copiados sob demanda ao abrir um projeto do Linux ou configurar o CMake para um destino do Linux. A cópia ocorre em segundo plano em uma base por projeto, com base nos compiladores especificados do projeto. Para obter mais informações, consulte [melhorias na precisão e no desempenho do Linux IntelliSense](https://devblogs.microsoft.com/cppblog/improvements-to-accuracy-and-performance-of-linux-intellisense/).

Essa funcionalidade depende de o computador Linux ter zip instalado. Você pode instalar o zip usando este comando apt-get:

```cmd
sudo apt install zip
```

Para gerenciar o cache do cabeçalho, navegue até **Ferramentas > Opções, Plataforma Cruzada > Gerenciador de Conexões > Gerenciador dos Cabeçalhos Remotos IntelliSense**. Para atualizar o cache do cabeçalho depois de fazer alterações no computador Linux, selecione a conexão remota e, em seguida, selecione **Atualizar**. Selecione **Excluir** para remover os cabeçalhos sem excluir a conexão em si. Selecione **Explorar** para abrir o diretório local no **Explorador de Arquivos**. Trate essa pasta como somente leitura. Para baixar cabeçalhos para uma conexão existente que foi criada antes do Visual Studio 2017 versão 15,3, selecione a conexão e, em seguida, selecione **baixar**.

::: moniker range="vs-2017"

![Captura de tela mostrando a caixa de diálogo opções com plataforma cruzada > Gerenciador de conexões > cabeçalhos remotos Gerenciador do IntelliSense selecionados.](media/remote-header-intellisense.png)

::: moniker-end

::: moniker range="vs-2019"

![Captura de tela mostrando a caixa de diálogo opções com a plataforma cruzada > Gerenciador de conexões selecionado.](media/connection-manager-vs2019.png)

Habilite o log ajudar a solucionar problemas:

![Log remoto](media/remote-logging-vs2019.png)

::: moniker-end

## <a name="linux-target-locale"></a><a name="locale"></a> Localidade de destino do Linux

As configurações de linguagem do Visual Studio não são propagadas para destinos do Linux porque o Visual Studio não gerencia nem configura pacotes instalados. As mensagens mostradas na janela de **saída** , como erros de compilação, são mostradas usando o idioma e a localidade do destino do Linux. Você precisará configurar seus destinos do Linux para a localidade desejada.

## <a name="see-also"></a>Confira também

[Defina propriedades de build e compilador](../build/working-with-project-properties.md)<br/>
[Propriedades gerais de C++ (Linux C++)](prop-pages/general-linux.md)<br/>
[Diretórios VC++ (Linux C++)](prop-pages/directories-linux.md)<br/>
[Copiar propriedades do projeto de origem (Linux C++)](prop-pages/copy-sources-project.md)<br/>
[Propriedades de evento de build (Linux C++)](prop-pages/build-events-linux.md)
