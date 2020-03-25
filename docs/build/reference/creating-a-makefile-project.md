---
title: Criar um projeto de makefile C++ no Visual Studio
ms.date: 08/05/2019
f1_keywords:
- vc.appwiz.makefile.project
helpviewer_keywords:
- Makefile projects [C++]
ms.assetid: dd077af3-97a8-48fb-baaa-cf7e07ddef61
ms.openlocfilehash: b96b7a1663e5d5886615dd976900f8eda9daeccc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169884"
---
# <a name="create-a-c-makefile-project"></a>Criar um projeto de makefile C++

Um *makefile* é um arquivo de texto que contém instruções sobre como criar e vincular (ou *compilar*) um conjunto de arquivos de código-fonte do C++. Um programa *make* lê o makefile e invoca um compilador, vinculador e possivelmente outros programas para criar um arquivo executável. A implementação do programa *make* pela Microsoft é chamada [NMAKE](nmake-reference.md).

Se tiver um projeto makefile existente, você terá estas opções se desejar codificar e/ou depurá-lo no Visual Studio IDE:

- Crie um projeto de makefile no Visual Studio que usa o makefile existente para configurar um arquivo .vcxproj que será usado pelo Visual Studio para o IntelliSense. (Você não terá todos os recursos de IDE que obtém com um projeto nativo do MSBuild.) Consulte [para criar um projeto de makefile](#create_a_makefile_project) abaixo.
- Use o assistente para **Criar Novo Projeto com base em Arquivos de Código Existentes** para criar um projeto nativo do MSBuild com base no código-fonte. O makefile original não será usado depois disso. Para obter mais informações, consulte [Como criar um projeto do C++ com base no código existente](../how-to-create-a-cpp-project-from-existing-code.md).
- **Visual Studio 2017 e posterior**: Use o recurso **abrir pasta** para editar e compilar um projeto makefile como está sem qualquer envolvimento do sistema MSBuild. Para saber mais, veja [Projetos Open Folder para C++](../open-folder-projects-cpp.md).
- **Visual Studio 2019 e posterior**: criar um projeto de makefile do UNIX para Linux.

## <a name="a-namecreate_a_makefile_project-to-create-a-makefile-project-with-the-makefile-project-template"></a><a name="create_a_makefile_project"> Para criar um projeto de makefile com o modelo de projeto de makefile

No Visual Studio 2017 e posterior, o modelo de projeto Makefile estará disponível quando a carga de trabalho de Desenvolvimento do C++ da área de trabalho for instalada.

Siga o assistente para especificar os comandos e o ambiente usado pelo seu makefile. Em seguida, use esse projeto para compilar o código no Visual Studio.

Por padrão, o projeto de makefile não exibe nenhum arquivo no Gerenciador de Soluções. O projeto de makefile especifica as configurações de build, que são refletidas na página de propriedades do projeto.

O arquivo de saída que você especifica no projeto não tem efeito no nome que o script de compilação gera; ele declara apenas uma intenção. O makefile ainda controla o processo de build e especifica os destinos de build.

::: moniker range="vs-2019"

### <a name="to-create-a-makefile-project-in-visual-studio-2019"></a>Para criar um projeto de makefile no Visual Studio 2019

1. No menu principal do Visual Studio, escolha **Arquivo** > **Novo** > **Projeto** e digite "makefile" na caixa de pesquisa. Ou, na caixa de diálogo **Novo Projeto**, expanda **Visual C++**  > **Geral** (Visual Studio 2015) ou **Outros** (Visual Studio 2017) e, em seguida, selecione uma das duas opções, dependendo se o Windows ou o Linux será direcionado.

1. **Somente Windows**: na página **definições de configuração de depuração** , forneça as informações de comando, saída, limpar e recompilar para compilações de depuração e de varejo. Clique em **Avançar** se desejar especificar configurações diferentes para uma configuração de Versão.

1. Clique em **Concluir** para fechar a caixa de diálogo e abra o projeto recém-criado no **Gerenciador de Soluções**.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-create-a-makefile-project-in-visual-studio-2015-or-visual-studio-2017"></a>Para criar um projeto de makefile no Visual Studio 2015 ou no Visual Studio 2017

1. Na página inicial do Visual Studio, digite "makefile" na caixa de pesquisa **Novo projeto**. Ou, na caixa de diálogo **Novo Projeto**, expanda **Visual C++**  > **Geral** (Visual Studio 2015) ou **Outro** (Visual Studio 2017) e, em seguida, selecione **Projeto Makefile** no painel Modelos para abrir o assistente de projeto.

1. Na página **Configurações de Aplicativo**, forneça as informações de comando, saída, limpeza e recompilação para builds de depuração e varejo.

1. Clique em **Concluir** para fechar o assistente e abrir o projeto recém-criado no **Gerenciador de Soluções**.

::: moniker-end

Você pode ver e editar as propriedades do projeto em sua página de propriedades. Confira [Definir propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md) para obter informações sobre como exibir a página de propriedades.

## <a name="makefile-project-wizard"></a>Assistente de projeto de makefile

Depois de criar um projeto de makefile, exiba e edite cada uma das opções a seguir na página **NMake** da página de propriedades do projeto.

- **Linha de comando de compilação:** Especifica a linha de comando a ser executada quando o usuário seleciona Compilar no menu Compilar. Exibida no campo Linha de comando de build na página NMake da página de propriedades do projeto.

- **Saída:** Especifica o nome do arquivo que conterá a saída para a linha de comando. Por padrão, essa opção baseia-se no nome do projeto. Exibida no campo Saída na página NMake da página de propriedades do projeto.

- **Limpar comandos:** Especifica a linha de comando a ser executada quando o usuário seleciona limpar no menu Compilar. Exibida no campo Linha de comando de limpeza na página NMake da página de propriedades do projeto.

- **Linha de comando de recompilação:** Especifica a linha de comando a ser executada quando o usuário seleciona recriar no menu Compilar. Exibida no campo Linha de comando de Recompilar tudo na página NMake da página de propriedades do projeto.

## <a name="how-to-enable-intellisense-for-makefile-projects"></a>Como habilitar o IntelliSense para projetos de makefile

O IntelliSense falha em projetos de makefile quando algumas configurações de projeto ou opções do compilador estão definidas incorretamente. Siga estas etapas para configurar projetos de makefile para que o IntelliSense funcione conforme o esperado:

1. Abra a caixa de diálogo **Páginas de Propriedades**. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Selecione a página de propriedades de **NMake** e, em seguida, modifique as propriedades em **IntelliSense**, conforme apropriado.

   - Defina a propriedade **Definições do Pré-processador** para definir os símbolos do pré-processador no projeto makefile. Confira [/D (Definições do Pré-processador)](d-preprocessor-definitions.md) para obter mais informações.

   - Defina a propriedade **Caminho de Pesquisa de Inclusão** para especificar a lista de diretórios que o compilador pesquisará para resolver as referências de arquivo passadas para as diretivas do pré-processador no projeto makefile. Confira [/I (Diretórios de Inclusão Adicionais)](i-additional-include-directories.md) para obter mais informações.

   - Nos projetos criados usando CL.EXE em uma Janela Comando, defina a variável de ambiente **INCLUDE** para especificar os diretórios que o compilador pesquisará para resolver as referências de arquivo passadas para as diretivas do pré-processador no projeto makefile.

   - Defina a propriedade **Inclusões Forçadas** para especificar quais arquivos de cabeçalho serão processados durante o build do projeto makefile. Confira [/FI (Nomear Arquivo de Inclusão Forçada)](fi-name-forced-include-file.md) para obter mais informações.

   - Defina a propriedade **Caminho de Pesquisa de Assembly** para especificar a lista de diretórios que o compilador pesquisará para resolver as referências a assemblies .NET no projeto. Confira [/AI (Especificar Diretórios de Metadados)](ai-specify-metadata-directories.md) para obter mais informações.

   - Defina a propriedade **Assemblies de Uso Forçado** para especificar quais assemblies .NET serão processados durante o build do projeto makefile. Confira [/FU (Nomear Arquivo #using Forçado)](fu-name-forced-hash-using-file.md) para obter mais informações.

   - Defina a propriedade **Opções Adicionais** para especificar as opções adicionais do compilador a serem usadas pelo IntelliSense durante a análise de arquivos do C++.

1. Clique em **OK** para fechar as páginas de propriedades.

1. Use o comando **Salvar Tudo** para salvar as configurações de projeto modificadas.

Na próxima vez que você abrir o projeto makefile no ambiente de desenvolvimento do Visual Studio, execute o comando **Limpar Solução** e, em seguida, o comando **Compilar Solução** no projeto makefile. O IntelliSense deverá funcionar corretamente no IDE.

## <a name="see-also"></a>Confira também

[Usando o IntelliSense](/visualstudio/ide/using-intellisense)<br>
[Referência a NMAKE](nmake-reference.md)<br>
[Como criar um C++ projeto de código existente](../how-to-create-a-cpp-project-from-existing-code.md)
[caracteres especiais em um makefile](special-characters-in-a-makefile.md)<br/>
[Conteúdo de um makefile](contents-of-a-makefile.md)<br/>
