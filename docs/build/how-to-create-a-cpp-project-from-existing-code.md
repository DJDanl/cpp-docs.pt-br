---
title: 'Como: Criar um projeto em C++ de um código existente'
ms.date: 01/15/2019
helpviewer_keywords:
- C++, creating projects from existing code
- Create New Project From Existing Code Files Wizard, project settings
f1_keywords:
- vc.appwiz.importwiz.location
- vc.appwiz.importwiz.appsettings
- vc.appwiz.importwiz.debugsettings
- vc.appwiz.importwiz.releasesettings
ms.assetid: e328a938-395c-48ea-9e35-dd433de12b31
ms.openlocfilehash: 1658e19595d8cfc7966ca881abfdd2aa8acf76ab
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62189002"
---
# <a name="how-to-create-a-c-project-from-existing-code"></a>Como: Criar um projeto em C++ de um código existente

No Visual Studio, você pode mover seus arquivos de código existentes para um projeto em C++ usando o assistente **Criar Novo Projeto de Arquivos de Código Existentes**. Esse assistente cria uma solução do projeto que usa o sistema do MSBuild para gerenciar os arquivos de origem e a configuração de build. Ele funciona melhor com projetos relativamente simples que não têm hierarquias de pasta complexas. O assistente não está disponível nas edições Express mais antigas do Visual Studio. 

A portabilidade dos arquivos de código existentes para um projeto em C++ permite usar as funcionalidades nativas de gerenciamento de projetos do MSBuild internos do IDE. Se preferir usar o sistema de build existente, como makefiles NMake, CMake ou outras alternativas, use a opção Abrir Pasta ou CMake. Para obter mais informações, consulte [projetos de pasta aberta para C++](open-folder-projects-cpp.md) ou [projetos de CMake no Visual Studio](cmake-projects-in-visual-studio.md). Ambas as opções permitem que você use funcionalidades do IDE, como [IntelliSense](/visualstudio/ide/using-intellisense) e [Propriedades do Projeto](working-with-project-properties.md).

### <a name="to-create-a-c-project-from-existing-code"></a>Para criar um projeto em C++ a partir de um código existente

1. No menu **Arquivo**, selecione **Novo** > **Projeto de Código Existente**.

1. Na primeira página do assistente para **Criar Novo Projeto com base em Arquivos de Código Existentes**, selecione **Visual C++** na lista **Que tipo de projeto deseja criar?**. Escolha **Avançar** para continuar.

1. Especifique o local do projeto, o diretório para os arquivos de origem e os tipos de arquivos que o assistente importa para o novo projeto. Escolha **Avançar** para continuar.

    | Configuração | Descrição |
    | --- | --- |
    | **Local do arquivo de projeto** | Especifica o caminho do diretório do novo projeto. Esse é o local em que o assistente colocará todos os arquivos (e subdiretórios) do novo projeto.<br/><br/>Selecione **Navegar** para exibir a caixa de diálogo **Local do arquivo de projeto**. Navegue até a pasta à direita e especifique o diretório que contém o novo projeto. |
    | **Nome do projeto** | Especifica o nome do novo projeto. Arquivos de projeto, que têm extensões de arquivo como. vcxproj, adotam esse nome, e arquivos de código existentes mantêm seu nome original. |
    | **Adicionar arquivos ao projeto destas pastas** | Marque para definir o assistente para copiar os arquivos de código existentes de seus diretórios originais (que são especificados na caixa de listagem abaixo desse controle) para o novo projeto.<br/><br/>Marque **Adicionar Subpastas** para especificar a cópia de arquivos de código de todos os subdiretórios no projeto. Os diretórios são listados na coluna **Pasta**.<br/>- Selecione **Adicionar** para exibir a caixa de diálogo **Adicionar arquivos ao projeto desta pasta** para especificar os diretórios nos quais o assistente pesquisa por arquivos de código existentes.<br/>- Selecione **Remover** para excluir o caminho do diretório selecionado na caixa de listagem.<br/><br/>Na caixa **Tipos de arquivo a serem adicionados ao projeto**, especifique os tipos de arquivos que o assistente adiciona ao novo projeto com base nas extensões de arquivo fornecidas. As extensões de arquivos são precedidas com o caractere curinga asterisco e delimitadas por ponto e vírgula na lista de extensões de arquivo. |
    | **Mostrar todos os arquivos no Gerenciador de Soluções** | Especifica que todos os arquivos do novo projeto estarão visíveis e serão exibidos na janela **Gerenciador de Soluções**. Essa opção é habilitada por padrão. |

    ![Local do projeto](media/location.png)

1. Especifique as configurações do projeto a ser usado como o ambiente de build para o novo projeto e as configurações de build para corresponder a um tipo específico de novo projeto a ser gerado. Escolha **Avançar** para continuar.

    | Configuração | Descrição |
    | --- | --- |
    | **Usar o Visual Studio** | Especifica o uso das ferramentas de build incluídas no Visual Studio para compilar o novo projeto. Essa opção é habilitada por padrão.<br/><br/>Selecione **Tipo de Projeto** para especificar o tipo de projeto que o assistente gera. Escolha **Projeto de aplicativos do Windows**, **Projeto de aplicativo de console**, **Projeto de DLL (biblioteca de vínculos dinâmicos)** ou **Projeto de LIB (biblioteca estática)**.<br/><br/>Marque **Adicionar suporte para ATL** para adicionar suporte de ATL ao novo projeto.<br/><br/>Marque **Adicionar suporte para MFC** para adicionar suporte de MFC ao novo projeto.<br/><br/>Marque **Adicionar suporte a Common Language Runtime** para adicionar suporte de programação CLR ao projeto. Escolha o **Suporte a Common Language Runtime** para o tipo de conformidade, como **Common Language Runtime (sintaxe antiga)** para conformidade com a sintaxe Managed Extensions for C++, a sintaxe de programação CLR anterior ao Visual C++ 2005. |
    | **Usar sistema de build externo** | Especifica o uso das ferramentas de build não incluídas no Visual Studio para compilar o novo projeto. Quando essa opção é selecionada, você pode especificar as linhas de comando de build nas páginas **Especificar Definições de Configuração de Depuração** e **Especificar Configurações de Versão**. |

    ![Configurações de projeto](media/settings.png)

    > [!NOTE]
    > Quando a opção **Usar Sistema de Build Externo** é marcada, o IDE não compila o projeto e, portanto, as opções /D, /I, /FI, /AI ou /FU não são necessárias para a compilação. No entanto, essas opções precisam ser definidas corretamente para o funcionamento correto do IntelliSense.

1. Especifique as definições de configuração de Depuração a serem usadas. Escolha **Avançar** para continuar.

    | Configuração | Descrição |
    | --- | --- |
    | **Linha de comando de Build** | Especifica a linha de comando que compila o projeto. Insira o nome do compilador (além de opções ou argumentos) ou os scripts de build que deseja usar para compilar o projeto. |
    | **Linha de comando de Recompilar** | Especifica a linha de comando que recompila o novo projeto. |
    | **Linha de comando de Limpar** | Especifica a linha de comando para excluir os arquivos de suporte gerados pelas ferramentas de build para o projeto. |
    | **Saída (para depuração)** | Especifica o caminho do diretório dos arquivos de saída para a configuração de Depuração do projeto. |
    | **Definições de pré-processador (/D)** | Define símbolos de pré-processador para o projeto. Veja [/D (definições de pré-processador)](../build/reference/d-preprocessor-definitions.md). |
    | **Caminho de pesquisa de inclusão (/I)** | Especifica os caminhos do diretório que o compilador pesquisa para resolver as referências de arquivo passadas para as diretivas do pré-processador no projeto. Veja [/I (Diretórios de inclusão adicional)](../build/reference/i-additional-include-directories.md). |
    | **Arquivos de inclusão forçada (/FI)** | Especifica os arquivos de cabeçalho a serem processados ao compilar o projeto. Veja [/FI (Nomear arquivo de inclusão forçada)](../build/reference/fi-name-forced-include-file.md). |
    | **Caminho de pesquisa de assembly .NET (/AI)** | Especifica os caminhos do diretório que o compilador pesquisa para resolver as referências de assembly .NET passadas para as diretivas do pré-processador no projeto. Veja [/AI (Especificar diretórios de metadados)](../build/reference/ai-specify-metadata-directories.md). |
    | **Uso forçado de assemblies .NET (/FU)** | Especifica os assemblies .NET a serem processados ao compilar o projeto. Veja [/FU (Nomear arquivo #using forçado)](../build/reference/fu-name-forced-hash-using-file.md). |

    ![Configuração do projeto](media/config.png)

    > [!NOTE]
    > A linha de comando **Compilar**, **Recompilar**, **Clean** e as configurações **Saída (para depuração)** serão habilitadas apenas se a opção **Usar sistema de build externo** estiver selecionada na página **Especificar Configurações do Projeto**.

1. Especifique as definições de configuração de versão a serem usadas. Essas configurações são as mesmas das definições de configuração de Depuração. Escolha **Concluir** para gerar o novo projeto.

    > [!NOTE]
    > Aqui você pode marcar **Mesmo que a configuração de Depuração** para especificar que o assistente gerará configurações de projeto da configuração de Versão idênticas às configurações de projeto da configuração de Depuração. Essa opção está marcada por padrão. Todas as outras opções dessa página ficam inativas, a menos que você desmarque essa caixa.
