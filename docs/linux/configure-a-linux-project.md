---
title: Configurar um projeto do Linux | Microsoft Docs
ms.custom: 
ms.date: 11/16/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 4d7c6adf-54b9-4b23-bd23-5de0c825b768
author: BrianPeek
ms.author: brpeek
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: dff1e9e03911f65dfcffcd078e0739224f73f4aa
ms.openlocfilehash: b110994cab92d2151f63912d2b08af56059b82d7
ms.lasthandoff: 02/25/2017

---

# <a name="configure-a-linux-project"></a>Configurar um projeto do Linux

## <a name="general-settings"></a>Configurações Gerais
Uma variedade de opções podem ser configurada para um projeto do Linux com o Visual Studio.  Para exibir essas opções, selecione o menu **Projeto > Propriedades** ou clique com o botão direito do mouse em **Gerenciador de Soluções** e selecione **Propriedades** no menu de contexto:

![Configuração geral](media/settings_general.png)

Por padrão, um executável (.out) é criado com a ferramenta.  Para criar uma biblioteca estática ou dinâmica ou para usar um Makefile existente, use a seleção **Tipo de Configuração**.

## <a name="remote-settings"></a>Configurações Remotas
Para alterar as configurações pertencentes ao computador Linux remoto, selecione o item **Configurações remotas**:

![Configurações remotas](media/settings_remote.png)

* Para alterar o computador Linux de destino, use a entrada **Computador de Destino**.  Isso permitirá selecionar uma das conexões criadas anteriormente.  Para criar uma nova entrada, consulte a seção [Connecting to Your Remote Linux Computer (Conectando-se ao seu computador Linux remoto)](connect-to-your-remote-linux-computer.md).

* O **Diretório Raiz Remoto** determina o local raiz de onde o projeto é criado no computador Linux remoto.  Isso definirá **~/projects** como padrão, a menos que tenha sido alterado.

* O **Diretório de Projeto Remoto** é onde esse projeto específico será criado no computador Linux remoto.  Isso definirá **$(RemoteRootDir)/$(ProjectName)** como padrão, que será expandido para um diretório nomeado depois do projeto atual, no diretório raiz definido acima.

* Por fim, para alterar os compiladores padrão C e C++ ou o Vinculador e o Arquivador usados para criar o projeto, use as entradas apropriadas na seção **Padrões de Ferramenta**.  Isso pode ser definido para usar uma determinada versão de GCC ou até mesmo o compilador Clang, por exemplo.

## <a name="vc-directories"></a>Diretórios VC++
Por padrão, o Visual Studio não inclui os arquivos de inclusão de nível de sistema do computador Linux.  Por exemplo, os itens no diretório **/usr/incluem** não estão presentes no Visual Studio.  Para obter suporte [IntelliSense](/visualstudio/ide/using-intellisense) completo, será necessário copiar esses arquivos para algum local em seu computador de desenvolvimento e apontar o Visual Studio para esse local.  Uma opção é usar scp (Cópia Segura) para copiar os arquivos.  No Windows 10, é possível usar [Bash no Windows](https://msdn.microsoft.com/commandline/wsl/about) para executar o scp.  Para versões anteriores do Windows, seria possível usar algo como [PSCP (Cópia segura PuTTY)](http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html).

É possível copiar os arquivos usando um comando semelhante ao seguinte:

`scp -r linux_username@remote_host:/usr/include .`

É claro, substitua os valores **linux_username** e **remote_host** acima pelo que for adequado em seu próprio ambiente.

Quando os arquivos forem copiados, use o item **Diretórios VC ++** item nas Propriedades do projeto para informar ao Visual Studio onde encontrar os arquivos de inclusão adicionais que acabaram de ser copiados.

![Diretórios VC++](media/settings_directories.png)

## <a name="copy-sources"></a>Fontes de dados
Durante a criação, os arquivos de origem em seu computador de desenvolvimento são copiados para o computador Linux e compilados lá.  Por padrão, todas as fontes no projeto do Visual Studio são copiadas para os locais definidos nas configurações acima.  No entanto, outras fontes também podem ser adicionadas à lista ou copiar fontes pode ser totalmente desativado, que é o padrão para um projeto Makefile.

* **Fontes a serem copiadas** determina quais fontes são copiadas para o computador remoto.  Por padrão, o **@(SourcesToCopyRemotely)** define todos os arquivos como padrão no projeto.

* **Copiar fontes** pode ser ativado e desativado para habilitar e desabilitar a cópia de arquivos de origem para o computador remoto.

* **Fontes adicionais a serem copiadas** permite que você adicione outros arquivos de origem que serão copiados para o sistema remoto.  É possível especificar uma lista delimitada por ponto-e-vírgula ou usar a sintaxe **:=** para especificar um nome local e remoto a ser usado:

  `C:\Projects\ConsoleApplication1\MyFile.cpp:=~/projects/ConsoleApplication1/ADifferentName.cpp;C:\Projects\ConsoleApplication1\MyFile2.cpp:=~/projects/ConsoleApplication1/ADifferentName2.cpp;`

## <a name="build-events"></a>Compilar Eventos
Como toda o build está acontecendo em um computador remoto, vários outros eventos de build foram adicionados à seção Eventos de Build nas Propriedades do Projeto.  Esses são **Evento de Pré-build Remoto**, **Evento Pré-vínculo Remoto** e **Remover Evento de Pós-build** e ocorrerão no computador remoto antes ou após as etapas individuais no processo.

![Compilar Eventos](media/settings_buildevents.png)

## <a name="see-also"></a>Consulte também
[Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)
