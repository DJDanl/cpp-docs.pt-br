---
title: Ferramentas de vinculador LNK1104 erro | Microsoft Docs
ms.custom: 
ms.date: 05/17/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1104
dev_langs:
- C++
helpviewer_keywords:
- LNK1104
ms.assetid: 9ca6f929-0efc-4055-8354-3cf5b4e636dc
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c91853fe3310d8e577ac884545f86d1f4e1d4521
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1104"></a>Erro das Ferramentas de Vinculador LNK1104

> não é possível abrir o arquivo '*filename*'

O vinculador não foi possível abrir o arquivo especificado. As causas mais comuns desse problema são que o arquivo está em uso ou bloqueado por outro processo, não existe, não pode ser encontrado em um dos diretórios de pesquisa do vinculador, ou você pode não ter permissões suficientes para acessar o arquivo. Menor frequência, você pode ter sido executado sem espaço em disco, o arquivo pode ser muito grande ou o caminho para o arquivo pode ser muito longo.

## <a name="possible-causes-and-solutions"></a>Possíveis causas e soluções

Esse erro pode ocorrer quando o vinculador tenta abrir um arquivo para leitura ou gravação. Para restringir as possíveis causas, primeiro verifique o tipo de arquivo e use as seções a seguir para ajudar a identificar e corrigir o problema específico.

### <a name="cannot-open-your-app-or-its-pdb-file"></a>Não é possível abrir o aplicativo ou seu arquivo. PDB

Se o nome do arquivo é o executável compila seu projeto, ou um arquivo. PDB associado, a causa mais comum é que o aplicativo já está em execução quando você tenta recriá-lo ou ele é carregado em um depurador. Para corrigir esse problema, pare o programa e descarregá-la a partir do depurador antes de criá-lo novamente. Se o aplicativo for aberto em outro programa, como um editor de recurso, fechá-lo. Em casos extremos, talvez seja necessário usar o Gerenciador de tarefas para encerrar o processo, ou parar e reiniciar o Visual Studio.

Programas antivírus geralmente temporariamente bloquear acessam a arquivos recém-criados, especialmente .exe e. dll arquivos executáveis. Para corrigir esse problema, tente excluir seus diretórios de compilação de projeto do scanner antivírus.

### <a name="cannot-open-a-microsoft-library-file"></a>Não é possível abrir um arquivo Microsoft Library

Se o arquivo não pode ser aberto é um dos arquivos de biblioteca padrão fornecidos pela Microsoft, como Kernel32, você pode ter um erro de configuração de projeto ou um erro de instalação. Verifique se que o SDK do Windows tiver sido instalado e se o projeto exige outras bibliotecas Microsoft como o MFC, certifique-se de que os componentes MFC também foram instalados pelo instalador do Visual Studio. Você pode executar o instalador novamente para adicionar componentes opcionais a qualquer momento. Para obter mais informações, consulte [modificar Visual Studio](/visualstudio/install/modify-visual-studio). Use a guia componentes individuais do instalador para escolher bibliotecas específicas e SDKs.

Se você estiver criando um projeto que foi criado usando uma versão anterior do Visual Studio, o conjunto de ferramentas de plataforma e bibliotecas para essa versão não podem ser instaladas. Se a mensagem de erro ocorrer para um nome de biblioteca com controle de versão, como msvcr100.lib, isso provavelmente é a causa. Para corrigir esse problema, você tem duas opções: você pode atualizar o projeto para usar o conjunto de ferramentas de plataforma atual tiver instalado ou você pode instalar o conjunto de ferramentas mais antigo e compilar o projeto inalterado. Para obter mais informações, consulte [Atualizando projetos a partir de versões anteriores do Visual C++](../../porting/upgrading-projects-from-earlier-versions-of-visual-cpp.md) e [usar nativo multiplataforma no Visual Studio para criar projetos antigos](../../porting/use-native-multi-targeting.md).

Se você vir esse erro quando você cria para uma nova plataforma de destino ou a configuração, as bibliotecas para esse conjunto de ferramentas de plataforma ou configuração de projeto não podem ser instaladas. Verifique o **conjunto de ferramentas de plataforma** e **versão do SDK do Windows** especificado no [página de propriedades geral](../../ide/general-property-page-project.md) para seu projeto estão instalados e verificar se necessário bibliotecas estão disponíveis no **diretórios de biblioteca** especificado no [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md) para as definições de configuração. Existem configurações separadas para depuração e configurações de varejo, bem como configurações de 32 bits e 64 bits, assim se uma criar funciona, mas outra causa um erro, verifique se as configurações estão corretas e as ferramentas necessárias e bibliotecas estão instaladas para cada criar a configuração.

Se você estiver usando o Visual Studio IDE para compilar um projeto que foi copiado de outro computador, os locais de instalação de bibliotecas podem ser diferentes. Verifique o **diretórios de biblioteca** propriedade o [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md) para o projeto e atualizá-lo se necessário. Para ver e editar os caminhos de biblioteca atual definido no IDE, escolha o controle de lista suspensa para o **diretórios de biblioteca** propriedade e escolha **editar**. O **avaliada valor** seção o **diretórios de biblioteca** caixa de diálogo lista os caminhos atuais pesquisados em busca de arquivos de biblioteca.

Esse erro também pode ocorrer quando o caminho para o SDK do Windows está desatualizado. Se você instalou uma versão do SDK do Windows mais recente que a versão do Visual Studio, certifique-se de que os caminhos especificados no [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md) são atualizadas de acordo com o novo SDK. Se você usar o Prompt de comando do desenvolvedor, verifique se o arquivo em lotes que inicializa as variáveis de ambiente é atualizado para os novos caminhos SDK. Esse problema pode ser evitado usando-se o instalador do Visual Studio para instalar os SDKs atualizados.

### <a name="cannot-open-a-third-party-library-file"></a>Não é possível abrir um arquivo de biblioteca de terceiros

Há várias causas comuns para esse problema:

- O caminho para o arquivo de biblioteca pode estar incorreto, ou talvez você não tenha especificado-lo para o vinculador.

- Você instalou uma versão de 32 bits da biblioteca, mas se você estiver criando para 64 bits, ou vice-versa.

- A biblioteca pode ter dependências em outras bibliotecas que não estão instaladas.

Para corrigir um problema de caminho, verifique se a variável de ambiente LIB está definida e contém todos os diretórios para as bibliotecas de que usar, para todas as configurações que você criar. No IDE, a variável LIB é definida **diretórios de biblioteca** propriedade o [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md). Verifique se todos os diretórios que contêm as bibliotecas que necessárias estão listados aqui, para todas as configurações que você criar.

Se você precisa fornecer um diretório de biblioteca que substitui uma pasta de biblioteca padrão, você pode usar o [/LIBPATH](../../build/reference/libpath-additional-libpath.md) opção na linha de comando ou no IDE, você pode usar o **diretórios de biblioteca adicionais** propriedade de **propriedades de configuração > vinculador > geral** página de propriedades de seu projeto.

Certifique-se de que ter instalado todas as versões da biblioteca que é necessário para as configurações que você criar. Considere o uso de [vcpkg](../../vcpkg.md) utilitário de gerenciamento para automatizar a instalação e configuração de muitas bibliotecas comuns do pacote. Quando possível, é melhor criar suas próprias cópias das bibliotecas de terceiros, para que ter certeza de ter todas as dependências de locais que exigem as bibliotecas e elas são criadas para as mesmas configurações do seu projeto.

### <a name="cannot-open-a-file-built-by-your-project"></a>Não é possível abrir um arquivo criado pelo seu projeto

Você pode ver este erro se o arquivo *filename* é criada com a sua solução, mas ainda não existir quando o vinculador tenta acessá-lo. Isso pode acontecer quando um projeto depende de outro projeto, mas os projetos não são criados na ordem correta. Para corrigir esse problema, verifique se as referências do projeto são definidas no projeto que usa o arquivo para que o arquivo ausente é criado quando for necessário. Para obter mais informações, consulte [adicionando referências em projetos do Visual C++](../../ide/adding-references-in-visual-cpp-projects.md) e [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).

### <a name="cannot-open-file-cprogramobj"></a>Não é possível abrir o arquivo ' c:\\Program.obj'

Se você vir esse erro, ou um erro semelhante que envolve um arquivo. obj inesperado na raiz da unidade de disco, o problema é provavelmente um caminho de biblioteca não está entre aspas duplas.

Para corrigir esse problema para compilações de linha de comando, verifique o [/LIBPATH](../../build/reference/libpath-additional-libpath.md) opção parâmetros, os caminhos especificados na variável de ambiente LIB e os caminhos especificados na linha de comando e certifique-se de usar aspas duplas em torno de todos os caminhos que incluem espaços.

Para corrigir esse problema no IDE, verifique o **diretórios de biblioteca** propriedade o [propriedades de configuração > diretórios VC + +](../../ide/vcpp-directories-property-page.md) página de propriedade, o **diretórios de biblioteca adicionais** propriedade no **propriedades de configuração > vinculador > geral** página de propriedades e o **dependências adicionais** propriedade o **configuração Propriedades > vinculador > entrada** página de propriedades de seu projeto. Verifique se todos os caminhos de diretório que contém as bibliotecas que necessárias são encapsulados em aspas duplas, se necessário.

### <a name="other-common-issues"></a>Outros problemas comuns

Esse erro pode ocorrer quando o nome do arquivo de biblioteca ou o caminho especificado para o vinculador na linha de comando ou em um [#pragma comentário (lib, "nome_da_biblioteca")](../../preprocessor/comment-c-cpp.md) diretiva está incorreta ou o caminho tem uma especificação de unidade inválida. Verifique a ortografia e a extensão de arquivo e verifique se que o arquivo existe no local especificado.

Outro programa pode ter o arquivo aberto e não é possível gravar o vinculador a ele. Programas antivírus geralmente bloqueiam temporariamente o acesso a arquivos recém-criados. Para corrigir esse problema, tente excluir seus diretórios de compilação de projeto do scanner antivírus.

Se você estiver usando uma opção de compilação paralela, é possível que o Visual Studio bloqueou o arquivo em outro thread. Para corrigir esse problema, verifique se que você não cria o mesmo objeto de código ou a biblioteca em vários projetos, e que você use as dependências de compilação ou referências de projeto para acompanhar binários criados em seu projeto.

Quando você especifica bibliotecas individuais no **dependências adicionais** propriedade diretamente, use espaços para separar os nomes de biblioteca, não vírgulas ou ponto e vírgula. Se você usar o **editar** item de menu para abrir o **dependências adicionais** caixa de diálogo, use novas linhas para separar os nomes, não vírgulas, ponto e vírgula ou espaços. Use também novas linhas quando você especificar caminhos de biblioteca no **diretórios de biblioteca** e **diretórios de biblioteca adicionais** caixas de diálogo.

Você pode ver este erro quando o caminho para *filename* expande a mais do que 260 caracteres. Alterar os nomes ou reorganizar a estrutura de diretório, se necessário para encurtar caminhos para os arquivos necessários.

Esse erro pode ocorrer porque o arquivo é muito grande. Objeto ou bibliotecas de arquivos mais do que um gigabyte no tamanho pode causar problemas para o vinculador de 32 bits. Possíveis para corrigir esse problema é usar o conjunto de ferramentas de 64 bits. Para obter mais informações sobre como fazer isso na linha de comando, consulte [como: habilitar um 64-Bit Visual C++ conjunto de ferramentas na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md). Para obter informações sobre como fazer isso no IDE, consulte [usando MSBuild com o compilador de 64 bits e ferramentas](../../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md#using-msbuild-to-build-your-project) e esta postagem de estouro de pilha: [como fazer com que o Visual Studio usa a cadeia de ferramentas nativas amd64](http://stackoverflow.com/questions/19820718/how-to-make-visual-studio-use-the-native-amd64-toolchain/23793055).

Esse erro pode ocorrer se você tiver permissões de arquivo suficientes para acessar *filename*. Isso pode acontecer se você usa uma conta de usuário comum e uma tentativa para acessar arquivos de biblioteca em diretórios protegidos do sistema ou usa os arquivos copiados de outros usuários que têm as permissões originais definido. Para corrigir esse problema, mova o arquivo para um diretório do projeto gravável. Se o arquivo está em um diretório gravável, mas tem permissões inacessíveis, você pode usar um prompt de comando do administrador e execute o comando de takeown.exe se apropriar do arquivo.

O erro pode ocorrer quando não há espaço em disco suficiente. O vinculador usa arquivos temporários em vários casos. Mesmo se você tiver espaço suficiente em disco, um link muito grande pode depauperam ou fragmento de espaço em disco disponível. Considere o uso de [/OPÇ (otimizações)](../../build/reference/opt-optimizations.md) opção; fazendo leituras de eliminação de COMDAT transitivas todos os arquivos de objeto várias vezes.

Se o *filename* chamado LNK*nnn*, que é um nome de arquivo gerado pelo vinculador para um arquivo temporário, o diretório especificado na variável de ambiente TMP pode não existir, ou mais de um diretório pode ser especificado para a variável de ambiente TMP. Apenas um caminho deve ser especificado para a variável de ambiente TMP.
