---
title: Configurar um projeto do C++ Linux no Visual Studio
ms.date: 06/11/2019
ms.assetid: 4d7c6adf-54b9-4b23-bd23-5de0c825b768
ms.openlocfilehash: 1cfaeb6611a27af498325739271d4dba38581dd6
ms.sourcegitcommit: c53a3efcc5d51fc55fa57ac83cca796b33ae888f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2019
ms.locfileid: "71960698"
---
# <a name="configure-a-linux-project"></a>Configurar um projeto do Linux

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

Este tópico descreve como configurar um projeto do C++ Linux, conforme descrito em [Criar um projeto do C++ Linux no Visual Studio](create-a-new-linux-project.md). Para projetos do CMake Linux, confira [Configurar um projeto do CMake Linux](cmake-linux-project.md). 

Configure um projeto do Linux para ter como destino um computador Linux físico, uma máquina virtual ou o [WSL](/windows/wsl/about) (Subsistema do Windows para Linux). 

::: moniker range="vs-2019"

**Visual Studio 2019 versão 16.1**:

- Ao ter o WSL como destino, você pode evitar as operações de cópia necessárias para build e o IntelliSense ao ter como destino sistemas Linux remotos.

- Especifique destinos do Linux separados para build e depuração.

::: moniker-end

## <a name="general-settings"></a>Configurações gerais

Para exibir as opções de configuração, selecione o menu **Projeto > Propriedades** ou clique com o botão direito do mouse no projeto em **Gerenciador de Soluções** e selecione **Propriedades** no menu de contexto. As **Configurações gerais** são exibidas.

![Configuração geral](media/settings_general.png)

Por padrão, um executável (.out) é criado. Para criar uma biblioteca estática ou dinâmica ou usar um Makefile existente, use a configuração **Tipo de Configuração**.

Para obter mais informações sobre as configurações nas páginas de propriedades, confira [Referência da página de propriedades do projeto do Linux](prop-pages-linux.md).

## <a name="remote-settings"></a>Configurações remotas

Para alterar as configurações relacionadas ao computador Linux remoto, defina as configurações remotas exibidas em [Geral](prop-pages/general-linux.md).

- Para especificar um computador Linux de destino remoto, use a entrada **Computador de Build Remoto**. Isso permitirá selecionar uma das conexões criadas anteriormente. Para criar uma entrada, confira a seção [Como se conectar ao computador Linux remoto](connect-to-your-remote-linux-computer.md).

   ![Computador de build](media/remote-build-machine-vs2019.png)

   ::: moniker range="vs-2019"

   **Visual Studio 2019 versão 16.1**: Para ter o Subsistema do Windows para Linux como destino, clique na seta para baixo em **Conjunto de ferramentas da plataforma** e escolha **WSL_1_0**. As outras opções remotas desaparecerão e o caminho para o shell padrão do WSL será exibido em seu lugar:

   ![Computador de build do WSL](media/wsl-remote-vs2019.png)

   Se você tiver instalações do WSL lado a lado, especifique outro caminho aqui. Para obter mais informações sobre como gerenciar várias distribuições, confira [Gerenciar e configurar o Subsistema do Windows para Linux](/windows/wsl/wsl-config#set-a-default-distribution).

   Especifique outro destino para depuração na página **Propriedades de Configuração** > **Depuração**.

   ::: moniker-end

- O **Diretório Raiz de Build Remoto** determina o local raiz de onde o projeto é compilado no computador Linux remoto. Isso definirá **~/projects** como padrão, a menos que tenha sido alterado.

- O **Diretório de Projeto de Build Remoto** é onde esse projeto específico será criado no computador Linux remoto. Isso definirá **$(RemoteRootDir)/$(ProjectName)** como padrão, que será expandido para um diretório nomeado depois do projeto atual, no diretório raiz definido acima.

> [!NOTE]
> Para alterar os compiladores padrão C e C++ ou o Vinculador e o Arquivador usados para compilar o projeto, use as entradas apropriadas nas seções **C/C++ > Geral** e **Vinculador > Geral**. Você pode especificar uma versão específica do GCC ou do Clang, por exemplo. Para obter mais informações, consulte [Propriedades do C/C++ (Linux C++)](prop-pages/c-cpp-linux.md) e [Propriedades de vinculador (Linux C++)](prop-pages/linker-linux.md).

## <a name="copy-sources-remote-systems-only"></a>Copiar fontes (apenas sistemas remotos)

::: moniker range="vs-2019"

Esta seção não se aplica quando o WSL é o destino.

::: moniker-end

Durante o build em sistemas remotos, os arquivos de origem no computador de desenvolvimento são copiados para o computador Linux e compilados nele. Por padrão, todas as fontes no projeto do Visual Studio são copiadas para os locais definidos nas configurações acima. No entanto, outras fontes também podem ser adicionadas à lista ou copiar fontes pode ser totalmente desativado, que é o padrão para um projeto Makefile.

- **Fontes a serem copiadas** determina quais fontes são copiadas para o computador remoto. Por padrão, o **\@(SourcesToCopyRemotely)** define todos os arquivos de código-fonte do projeto como padrão, mas não inclui arquivos de ativo/recurso, como imagens.

- **Copiar fontes** pode ser ativado e desativado para habilitar e desabilitar a cópia de arquivos de origem para o computador remoto.

- **Fontes adicionais a serem copiadas** permite que você adicione outros arquivos de origem que serão copiados para o sistema remoto. É possível especificar uma lista delimitada por ponto-e-vírgula ou usar a sintaxe **:=** para especificar um nome local e remoto a ser usado:

`C:\Projects\ConsoleApplication1\MyFile.cpp:=~/projects/ConsoleApplication1/ADifferentName.cpp;C:\Projects\ConsoleApplication1\MyFile2.cpp:=~/projects/ConsoleApplication1/ADifferentName2.cpp;`

## <a name="build-events"></a>Eventos de build

Como toda a compilação está acontecendo em um computador remoto (ou no WSL), vários outros eventos de build foram adicionados à seção Eventos de Build em Propriedades do Projeto. Eles são os **Evento de pré-build remoto**, **Evento de pré-link remoto** e **Evento de pós-build remoto**, que ocorrerão no computador remoto antes ou após as etapas individuais no processo.

![Compilar Eventos](media/settings_buildevents.png)

## <a name="remote_intellisense"></a> IntelliSense para cabeçalhos em sistemas remotos

Quando você adiciona uma nova conexão no **Gerenciador de Conexões**, o Visual Studio detecta automaticamente os diretórios de inclusão para o compilador no sistema remoto. Visual Studio compacta e copia os arquivos para um diretório no seu computador local do Windows. Depois disso, sempre que você usar essa conexão em um projeto do Visual Studio ou CMake, os cabeçalhos nesses diretórios serão usados para fornecer IntelliSense.

Essa funcionalidade depende de o computador Linux ter zip instalado. Você pode instalar o zip usando este comando apt-get:

```cmd
sudo apt install zip
```

Para gerenciar o cache do cabeçalho, navegue até **Ferramentas > Opções, Plataforma Cruzada > Gerenciador de Conexões > Gerenciador dos Cabeçalhos Remotos IntelliSense**. Para atualizar o cache do cabeçalho depois de fazer alterações no computador Linux, selecione a conexão remota e, em seguida, selecione **Atualizar**. Selecione **Excluir** para remover os cabeçalhos sem excluir a conexão em si. Selecione **Explorar** para abrir o diretório local no **Explorador de Arquivos**. Trate essa pasta como somente leitura. Para baixar os cabeçalhos para uma conexão existente criada antes do Visual Studio 2017 versão 15.3, selecione a conexão e, em seguida, selecione **Baixar**.

::: moniker range="vs-2017"

![Cabeçalho remoto IntelliSense](media/remote-header-intellisense.png)

::: moniker-end

::: moniker range="vs-2019"

![Cabeçalho remoto IntelliSense](media/connection-manager-vs2019.png)

Habilite o log ajudar a solucionar problemas:

![Log remoto](media/remote-logging-vs2019.png)

::: moniker-end

## <a name="see-also"></a>Consulte também

[Defina propriedades de build e compilador](../build/working-with-project-properties.md)<br/>
[Propriedades gerais de C++ (Linux C++)](../linux/prop-pages/general-linux.md)<br/>
[Diretórios VC++ (Linux C++)](../linux/prop-pages/directories-linux.md)<br/>
[Copiar fontes de propriedades do projeto (Linux C++)](../linux/prop-pages/copy-sources-project.md)<br/>
[Propriedades de evento de build (Linux C++)](../linux/prop-pages/build-events-linux.md)
