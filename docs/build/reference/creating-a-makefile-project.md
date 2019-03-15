---
title: Criar um projeto de makefile do C++ no Visual Studio
ms.date: 12/08/2018
f1_keywords:
- vc.appwiz.makefile.project
helpviewer_keywords:
- Makefile projects, creating
- project files [C++], Makefile projects
ms.assetid: dd077af3-97a8-48fb-baaa-cf7e07ddef61
ms.openlocfilehash: bb28d76b0ec459b5fd63f6a00dedff723274e90f
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824569"
---
# <a name="create-a-c-makefile-project"></a>Criar um projeto de makefile do C++

Um *makefile* é um arquivo de texto que contém instruções sobre como criar e vincular (ou *compilar*) um conjunto de arquivos de código-fonte do C++. Um programa *make* lê o makefile e invoca um compilador, vinculador e possivelmente outros programas para criar um arquivo executável. Implementação da Microsoft a *tornar* programa é chamado [NMAKE](nmake-reference.md);

Se tiver um projeto makefile existente, você terá estas opções se desejar codificar e/ou depurá-lo no Visual Studio IDE:

- Crie um projeto do makefile do Visual Studio que usa o makefile existente para configurar um arquivo. vcxproj que usará o Visual Studio para o IntelliSense. (Você não terá todos os recursos do IDE que tem com um projeto MSBuild nativo). Consulte [Para criar um projeto makefile](#create_a_makefile_project) abaixo.
- Use o assistente para **Criar Novo Projeto com base em Arquivos de Código Existentes** para criar um projeto nativo do MSBuild com base no código-fonte. O makefile original não será usado depois de fazer isso. Para obter mais informações, confira [Como: Criar um projeto em C++ de um código existente](../how-to-create-a-cpp-project-from-existing-code.md).
- **Visual Studio 2017 e posterior**: Use o **Abrir pasta** recurso Editar e compilar um projeto do makefile como-está, sem qualquer envolvimento do sistema MSBuild. Para obter mais informações, consulte [projetos de pasta aberta para C++](../open-folder-projects-cpp.md).

## <a name="a-namecreateamakefileproject-to-create-a-makefile-project-with-the-makefile-project-template"></a><a name="create_a_makefile_project"> Para criar um projeto do makefile com o modelo de projeto makefile

No Visual Studio 2017 e posterior, o modelo de projeto Makefile estará disponível quando a carga de trabalho de Desenvolvimento do C++ da área de trabalho for instalada.

Siga o assistente para especificar os comandos e o ambiente usado pelo seu makefile. Em seguida, você pode usar esse projeto para compilar seu código no Visual Studio.

Por padrão, o projeto de makefile não exibe nenhum arquivo no Gerenciador de Soluções. O projeto de makefile especifica as configurações de build, que são refletidas na página de propriedades do projeto.

O arquivo de saída que você especifica no projeto não tem efeito no nome que o script de compilação gera; ele declara apenas uma intenção. O makefile ainda controla o processo de build e especifica os destinos de build.

1. Na página inicial do Visual Studio, digite "makefile" na caixa de pesquisa **Novo projeto**. Ou, na caixa de diálogo **Novo Projeto**, expanda **Visual C++** > **Geral** (Visual Studio 2015) ou **Outro** (Visual Studio 2017) e, em seguida, selecione **Projeto Makefile** no painel Modelos para abrir o assistente de projeto.

1. Na página **Configurações de Aplicativo**, forneça as informações de comando, saída, limpeza e recompilação para builds de depuração e varejo.

1. Clique em **Concluir** para fechar o assistente e abrir o projeto recém-criado no **Gerenciador de Soluções**.

Você pode ver e editar as propriedades do projeto em sua página de propriedades. Ver [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md) para obter informações sobre como exibir a página de propriedades.

## <a name="makefile-project-wizard"></a>Assistente de projeto makefile

Depois de criar um projeto makefile, você pode exibir e editar cada uma das seguintes opções de **Nmake** página da página de propriedades do projeto.

- **Linha de comando de compilação:** Especifica a linha de comando para executar quando o usuário seleciona o Build no menu Build. Exibido no campo de linha de comando de compilação na página de Nmake da página de propriedades do projeto.

- **Saída:** Especifica o nome do arquivo de saída que conterá a saída da linha de comando. Por padrão, essa opção baseia-se no nome do projeto. Exibido no campo de saída na página de Nmake da página de propriedades do projeto.

- **Comandos de limpo:** Especifica a linha de comando para executar quando o usuário seleciona Limpar no menu Build. Exibido no campo de linha de comando de limpeza na página de Nmake da página de propriedades do projeto.

- **Recrie a linha de comando:** Especifica a linha de comando para executar quando o usuário seleciona a recompilação no menu Build. Exibido na recompilação de todos os campos de linha de comando na página de Nmake da página de propriedades do projeto.

## <a name="how-to-enable-intellisense-for-makefile-projects"></a>Como: Habilitar o IntelliSense para projetos Makefile

Falha do IntelliSense em projetos makefile quando determinadas configurações do projeto ou as opções do compilador estiverem configuradas incorretamente. Siga estas etapas para configurar projetos makefile para que o IntelliSense funcione conforme o esperado:

1. Abra a caixa de diálogo **Páginas de Propriedades**. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

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

## <a name="see-also"></a>Consulte também

[Usando o IntelliSense](/visualstudio/ide/using-intellisense)<br>
[Referência a NMAKE](nmake-reference.md)<br>
[Como: Criar um projeto C++ de código existente](../how-to-create-a-cpp-project-from-existing-code.md)
[caracteres especiais em um Makefile](special-characters-in-a-makefile.md)<br/>
[Conteúdo de um makefile](contents-of-a-makefile.md)<br/>
