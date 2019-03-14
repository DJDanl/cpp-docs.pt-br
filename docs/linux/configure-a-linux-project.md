---
title: Configurar um projeto do C++ Linux no Visual Studio
ms.date: 11/12/2018
ms.assetid: 4d7c6adf-54b9-4b23-bd23-5de0c825b768
ms.openlocfilehash: 0d0825a3aca8ca03759d7f7b42db90ce9700c10b
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57745192"
---
# <a name="configure-a-linux-project"></a>Configurar um projeto do Linux

Este tópico descreve como configurar um projeto do C++ Linux com base em um modelo de projeto do Linux no Visual Studio. Para obter mais informações sobre Projetos CMake do Linux no Visual Studio, consulte [Configurar um Projeto CMake do Linux ](cmake-linux-project.md).

## <a name="general-settings"></a>Configurações gerais

Uma variedade de opções podem ser configurada para um projeto do Linux com o Visual Studio.  Para exibir essas opções, selecione o menu **Projeto > Propriedades** ou clique com o botão direito do mouse em **Gerenciador de Soluções** e selecione **Propriedades** no menu de contexto. As **Configurações gerais** são exibidas.

![Configuração geral](media/settings_general.png)

Por padrão, um executável (.out) é criado com a ferramenta.  Para criar uma biblioteca estática ou dinâmica ou para usar um Makefile existente, use a seleção **Tipo de Configuração**.

Para obter mais informações sobre as opções nas páginas de propriedades, consulte [Linux Project Property Page Reference](prop-pages-linux.md) (Referência de página de propriedades do projeto do Linux).

## <a name="remote-settings"></a>Configurações remotas

Para alterar as configurações relacionadas ao computador Linux remoto, defina as opções remotas exibidas nas [Configurações gerais](prop-pages/general-linux.md):

- Para alterar o computador Linux de destino, use a entrada **Computador de Build Remoto**.  Isso permitirá selecionar uma das conexões criadas anteriormente.  Para criar uma nova entrada, consulte a seção [Connecting to Your Remote Linux Computer (Conectando-se ao seu computador Linux remoto)](connect-to-your-remote-linux-computer.md).

- O **Diretório Raiz de Build Remoto** determina o local raiz de onde o projeto é compilado no computador Linux remoto.  Isso definirá **~/projects** como padrão, a menos que tenha sido alterado.

- O **Diretório de Projeto de Build Remoto** é onde esse projeto específico será criado no computador Linux remoto.  Isso definirá **$(RemoteRootDir)/$(ProjectName)** como padrão, que será expandido para um diretório nomeado depois do projeto atual, no diretório raiz definido acima.

> [!NOTE]
> Para alterar os compiladores padrão C e C++ ou o Vinculador e o Arquivador usados para compilar o projeto, use as entradas apropriadas nas seções **C/C++ > Geral** e **Vinculador > Geral**.  Isso pode ser definido para usar uma determinada versão de GCC ou até mesmo o compilador Clang, por exemplo. Para obter mais informações, consulte [Propriedades do C/C++ (Linux C++)](prop-pages/c-cpp-linux.md) e [Propriedades de vinculador (Linux C++)](prop-pages/linker-linux.md).

## <a name="include-directories-and-intellisense-support"></a>Diretórios de inclusão e suporte do IntelliSense

**Visual Studio 2017 versão 15.6 e anterior:**<br/>
Por padrão, o Visual Studio não inclui os arquivos de inclusão de nível de sistema do computador Linux.  Por exemplo, os itens no diretório **/usr/incluem** não estão presentes no Visual Studio.
Para obter suporte [IntelliSense](/visualstudio/ide/using-intellisense) completo, será necessário copiar esses arquivos para algum local em seu computador de desenvolvimento e apontar o Visual Studio para esse local.  Uma opção é usar scp (Cópia Segura) para copiar os arquivos.  No Windows 10, é possível usar [Bash no Windows](https://msdn.microsoft.com/commandline/wsl/about) para executar o scp.  Para versões anteriores do Windows, seria possível usar algo como [PSCP (Cópia segura PuTTY)](http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html).

É possível copiar os arquivos usando um comando semelhante ao seguinte:

`scp -r linux_username@remote_host:/usr/include .`

É claro, substitua os valores **linux_username** e **remote_host** acima pelo que for adequado em seu próprio ambiente.

Quando os arquivos forem copiados, use o item **Diretórios VC ++** item nas Propriedades do projeto para informar ao Visual Studio onde encontrar os arquivos de inclusão adicionais que acabaram de ser copiados.

![Diretórios VC++](media/settings_directories.png)

**Visual Studio 2017 versão 15.7 e posteriores:**<br/>
Consulte [Manage Remote Headers for IntelliSense](#remote_intellisense) (Gerenciar cabeçalhos remotos para o IntelliSense).

## <a name="copy-sources"></a>Copiar fontes

Durante a criação, os arquivos de origem em seu computador de desenvolvimento são copiados para o computador Linux e compilados lá.  Por padrão, todas as fontes no projeto do Visual Studio são copiadas para os locais definidos nas configurações acima.  No entanto, outras fontes também podem ser adicionadas à lista ou copiar fontes pode ser totalmente desativado, que é o padrão para um projeto Makefile.

- **Fontes a serem copiadas** determina quais fontes são copiadas para o computador remoto.  Por padrão, o **\@(SourcesToCopyRemotely)** define todos os arquivos de código-fonte do projeto como padrão, mas não inclui arquivos de ativo/recurso, como imagens.

- **Copiar fontes** pode ser ativado e desativado para habilitar e desabilitar a cópia de arquivos de origem para o computador remoto.

- **Fontes adicionais a serem copiadas** permite que você adicione outros arquivos de origem que serão copiados para o sistema remoto.  É possível especificar uma lista delimitada por ponto-e-vírgula ou usar a sintaxe **:=** para especificar um nome local e remoto a ser usado:

`C:\Projects\ConsoleApplication1\MyFile.cpp:=~/projects/ConsoleApplication1/ADifferentName.cpp;C:\Projects\ConsoleApplication1\MyFile2.cpp:=~/projects/ConsoleApplication1/ADifferentName2.cpp;`

## <a name="build-events"></a>Eventos de build

Como toda o build está acontecendo em um computador remoto, vários outros eventos de build foram adicionados à seção Eventos de Build nas Propriedades do Projeto.  Eles são os **Evento de pré-build remoto**, **Evento de pré-link remoto** e **Evento de pós-build remoto**, que ocorrerão no computador remoto antes ou após as etapas individuais no processo.

![Compilar Eventos](media/settings_buildevents.png)

## <a name="remote_intellisense"></a> IntelliSense para cabeçalhos remotos (Visual Studio 2017 versão 15.7 e posterior)

Quando você adiciona uma nova conexão no **Gerenciador de Conexões**, o Visual Studio detecta automaticamente os diretórios de inclusão para o compilador no sistema remoto. Visual Studio compacta e copia os arquivos para um diretório no seu computador local do Windows. Depois disso, sempre que você usar essa conexão em um projeto do Visual Studio ou CMake, os cabeçalhos nesses diretórios serão usados para fornecer IntelliSense.

Essa funcionalidade depende de o computador Linux ter zip instalado. Você pode instalar o zip usando este comando apt-get:

```cmd
apt install zip
```

Para gerenciar o cache do cabeçalho, navegue até **Ferramentas > Opções, Plataforma Cruzada > Gerenciador de Conexões > Gerenciador dos Cabeçalhos Remotos IntelliSense**. Para atualizar o cache do cabeçalho depois de fazer alterações no computador Linux, selecione a conexão remota e, em seguida, selecione **Atualizar**. Selecione **Excluir** para remover os cabeçalhos sem excluir a conexão em si. Selecione **Explorar** para abrir o diretório local no **Explorador de Arquivos**. Trate essa pasta como somente leitura. Para baixar os cabeçalhos para uma conexão existente criada antes da versão 15.3, selecione a conexão e selecione **Baixar**.

![Cabeçalho remoto IntelliSense](media/remote-header-intellisense.png)

## <a name="see-also"></a>Consulte também

[Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)<br/>
[Propriedades gerais de C++ (Linux C++)](prop-pages/general-linux.md)<br/>
[Diretórios VC++ (Linux C++)](prop-pages/directories-linux.md)<br/>
[Copiar fontes de propriedades do projeto (Linux C++)](prop-pages/copy-sources-project.md)<br/>
[Propriedades de evento de build (Linux C++)](prop-pages/build-events-linux.md)
