---
title: Erro das Ferramentas de Vinculador LNK1104
ms.date: 05/17/2017
f1_keywords:
- LNK1104
helpviewer_keywords:
- LNK1104
ms.assetid: 9ca6f929-0efc-4055-8354-3cf5b4e636dc
ms.openlocfilehash: eadeeb7ac19e3975a37a1364502b33400018cb05
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62255507"
---
# <a name="linker-tools-error-lnk1104"></a>Erro das Ferramentas de Vinculador LNK1104

> não é possível abrir o arquivo '*filename*'

O vinculador não foi possível abrir o arquivo especificado. As causas mais comuns desse problema são que o arquivo está em uso ou bloqueado por outro processo, não existe, não pode ser encontrado em um dos diretórios que o vinculador procura, ou você pode não ter permissões suficientes para acessar o arquivo. Com menos frequência, você pode ter ficado sem espaço em disco, o arquivo pode ser muito grande ou o caminho para o arquivo pode ser muito longo.

## <a name="possible-causes-and-solutions"></a>Possíveis causas e soluções

Esse erro pode ocorrer quando o vinculador tenta abrir um arquivo para leitura ou para gravação. Para restringir as possíveis causas, primeiro verificar que tipo de arquivo e use as seções a seguir para ajudar a identificar e corrigir o problema específico.

### <a name="cannot-open-your-app-or-its-pdb-file"></a>Não é possível abrir seu aplicativo ou seu arquivo. PDB

Se o nome do arquivo é o executável de seu projeto é compilado ou um arquivo. PDB associado, a causa mais comum é que seu aplicativo já está em execução quando você tentar recriá-lo ou ele é carregado em um depurador. Para corrigir esse problema, pare o programa e descarregue-o do depurador antes de compilá-lo novamente. Se o aplicativo for aberto em outro programa, como um editor de recursos, fechá-lo. Em casos extremos, talvez você precise usar o Gerenciador de tarefas para encerrar o processo, ou parar e reiniciar o Visual Studio.

Programas antivírus geralmente bloquear temporariamente acessam a arquivos recém-criados, especialmente .exe e. dll arquivos executáveis. Para corrigir esse problema, tente excluindo os diretórios de compilação do projeto usando o scanner de antivírus.

### <a name="cannot-open-a-microsoft-library-file"></a>Não é possível abrir um arquivo do Microsoft Library

Se o arquivo que não pode ser aberto é um dos arquivos de biblioteca padrão fornecidos pela Microsoft, como kernel32.lib, você pode ter um erro de configuração do projeto ou um erro de instalação. Verifique se que o SDK do Windows tiver sido instalado e se seu projeto exigir outras bibliotecas da Microsoft, como o MFC, certifique-se de que os componentes MFC também foram instalados pelo instalador do Visual Studio. Você pode executar o instalador novamente para adicionar componentes opcionais a qualquer momento. Para obter mais informações, consulte [modificar o Visual Studio](/visualstudio/install/modify-visual-studio). Use a guia componentes individuais no instalador para escolher específicas bibliotecas e SDKs.

Se você estiver criando um projeto que foi criado usando uma versão anterior do Visual Studio, o conjunto de ferramentas de plataforma e bibliotecas para essa versão não podem ser instaladas. Se a mensagem de erro ocorrer para um nome de biblioteca de controle de versão, como msvcr100.lib, isso provavelmente é a causa. Para corrigir esse problema, você tem duas opções: você pode atualizar o projeto para usar o conjunto de ferramentas de plataforma atual você instalou, ou você pode instalar o conjunto de ferramentas mais antigo e compilar o projeto inalterado. Para obter mais informações, consulte [atualização de projetos de versões anteriores do Visual C++](../../porting/upgrading-projects-from-earlier-versions-of-visual-cpp.md) e [usar multiplataforma nativa no Visual Studio para compilar projetos antigos](../../porting/use-native-multi-targeting.md).

Se você vir esse erro quando você compila para uma nova plataforma de destino ou a configuração, as bibliotecas para esse conjunto de ferramentas de plataforma ou de configuração de projeto não podem ser instaladas. Verificar se o **conjunto de ferramentas de plataforma** e **versão do SDK do Windows** especificado no [página de propriedades geral](../../build/reference/general-property-page-project.md) para seu projeto são instalados e verifique necessários bibliotecas estão disponíveis na **diretórios de biblioteca** especificado na [página de propriedade dos diretórios VC + +](../../build/reference/vcpp-directories-property-page.md) para suas definições de configuração. Existem configurações separadas para depuração e configurações de varejo, bem como as configurações de 32 bits e 64 bits, portanto, se um build funciona, mas outra causa um erro, verifique se as configurações estão corretas e as bibliotecas e ferramentas necessárias são instaladas para cada você compila a configuração.

Se você estiver usando o IDE do Visual Studio para compilar um projeto que foi copiado de outro computador, os locais de instalação de bibliotecas podem ser diferentes. Verifique as **diretórios de biblioteca** propriedade no [página de propriedade dos diretórios VC + +](../../build/reference/vcpp-directories-property-page.md) para o projeto e atualizá-lo se necessário. Para ver e editar os caminhos de biblioteca atual definidos no IDE, escolha o controle de lista suspensa para o **diretórios de biblioteca** propriedade e escolha **editar**. O **avaliado o valor** seção o **diretórios de biblioteca** caixa de diálogo lista os caminhos atuais procurados para os arquivos de biblioteca.

Esse erro também pode ocorrer quando o caminho para o SDK do Windows está desatualizado. Se você instalou uma versão do SDK do Windows mais recente que sua versão do Visual Studio, certifique-se de que os caminhos especificados na [página de propriedade dos diretórios VC + +](../../build/reference/vcpp-directories-property-page.md) são atualizadas de acordo com o novo SDK. Se você usar o Prompt de comando do desenvolvedor, certifique-se de que o arquivo em lotes que inicializa as variáveis de ambiente é atualizado para os novos caminhos SDK. Esse problema pode ser evitado usando o instalador do Visual Studio para instalar os SDKs atualizados.

### <a name="cannot-open-a-third-party-library-file"></a>Não é possível abrir um arquivo de biblioteca de terceiros

Há várias causas comuns para esse problema:

- O caminho para o arquivo de biblioteca pode estar incorreto ou não especificado-lo para o vinculador.

- Você instalou uma versão de 32 bits da biblioteca, mas se você estiver criando para 64 bits ou vice-versa.

- A biblioteca pode ter dependências em outras bibliotecas que não estão instaladas.

Para corrigir um problema de caminho, verifique se a variável de ambiente LIB está definida e contém todos os diretórios para as bibliotecas de que usar, para cada configuração que você criar. No IDE, a variável LIB é definida **diretórios de biblioteca** propriedade no [página de propriedade dos diretórios VC + +](../../build/reference/vcpp-directories-property-page.md). Verifique se todos os diretórios que contêm as bibliotecas que necessárias estão listados aqui, para cada configuração que você criar.

Se você precisa fornecer um diretório de biblioteca que substitui um diretório de biblioteca padrão, você pode usar o [/LIBPATH](../../build/reference/libpath-additional-libpath.md) opção na linha de comando ou no IDE, você pode usar o **diretórios de biblioteca adicionais** propriedade na **propriedades de configuração > vinculador > geral** página de propriedades para o seu projeto.

Verifique se que você instalou todas as versões da biblioteca que você precisa para as configurações que você criar. Considere o uso de [vcpkg](../../vcpkg.md) utilitário de gerenciamento para automatizar a instalação e configuração de muitas bibliotecas comuns do pacote. Quando possível, é melhor criar suas próprias cópias das bibliotecas de terceiros, para que ter certeza de ter todas as dependências locais que exigem as bibliotecas e eles são criados para as mesmas configurações que seu projeto.

### <a name="cannot-open-a-file-built-by-your-project"></a>Não é possível abrir um arquivo criado pelo seu projeto

Você pode ver este erro se o arquivo *filename* é compilado pela sua solução, mas ainda não existir quando o vinculador tenta acessá-lo. Isso pode acontecer quando um projeto depende de outro projeto, mas os projetos não são criados na ordem correta. Para corrigir esse problema, verifique se as referências do projeto estão definidas no projeto que usa o arquivo para que o arquivo está faltando é criado quando for necessário. Para obter mais informações, consulte [adicionando referências em projetos do Visual C++](../../build/adding-references-in-visual-cpp-projects.md) e [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).

### <a name="cannot-open-file-cprogramobj"></a>Não é possível abrir o arquivo ' c:\\Program.obj'

Se você vir esse erro, ou um erro semelhante que envolvem um arquivo. obj inesperado na raiz da unidade, o problema é certamente um caminho de biblioteca que não é encapsulado em aspas duplas.

Para corrigir esse problema para compilações de linha de comando, verifique as [/LIBPATH](../../build/reference/libpath-additional-libpath.md) opção parâmetros, os caminhos especificados na variável de ambiente LIB e os caminhos especificados na linha de comando e certifique-se de usar aspas duplas em torno de todos os caminhos que incluem espaços.

Para corrigir esse problema no IDE, verificar a **diretórios de biblioteca** propriedade no [propriedades de configuração > diretórios VC + +](../../build/reference/vcpp-directories-property-page.md) página de propriedade, o **diretórios de biblioteca adicionais** propriedade no **propriedades de configuração > vinculador > geral** página de propriedades e o **dependências adicionais** propriedade no **configuração Propriedades > vinculador > entrada** página de propriedades para o seu projeto. Verifique se todos os caminhos de diretório que contém as bibliotecas que necessárias são encapsulados em aspas duplas, se necessário.

### <a name="other-common-issues"></a>Outros problemas comuns

Esse erro pode ocorrer quando o nome de arquivo de biblioteca ou o caminho especificado para o vinculador na linha de comando ou em um [#pragma comentário (lib, "nome_da_biblioteca")](../../preprocessor/comment-c-cpp.md) diretiva está incorreta ou o caminho tenha uma especificação de unidade inválida. Verifique a ortografia e a extensão de arquivo e verifique se que o arquivo existe no local especificado.

Outro programa pode ter o arquivo aberto e o vinculador não pode gravar nele. Programas antivírus geralmente bloqueiam temporariamente o acesso a arquivos recém-criados. Para corrigir esse problema, tente excluindo os diretórios de compilação do projeto usando o scanner de antivírus.

Se você estiver usando uma opção de build paralelo, é possível que o Visual Studio bloqueou o arquivo em outro thread. Para corrigir esse problema, verifique se que você não criar o mesmo objeto de código ou a biblioteca em vários projetos e usar as dependências de compilação ou referências de projeto para acompanhar os binários compilados em seu projeto.

Quando você especifica bibliotecas individuais na **dependências adicionais** propriedade diretamente, use espaços para separar os nomes de biblioteca, não vírgulas ou ponto e vírgula. Se você usar o **edite** item de menu para abrir o **dependências adicionais** caixa de diálogo, novas linhas de uso para separar os nomes, não vírgulas, ponto e vírgula ou espaços. Use também novas linhas ao especificar caminhos de biblioteca na **diretórios de biblioteca** e **diretórios de biblioteca adicionais** caixas de diálogo.

Você pode ver este erro quando o caminho para o *filename* se expande para mais de 260 caracteres. Alterar os nomes ou reorganizar sua estrutura de diretório, se necessário, para reduzir os caminhos para os arquivos necessários.

Esse erro pode ocorrer porque o arquivo é muito grande. Objeto ou bibliotecas de arquivos mais do que um gigabyte de tamanho pode causar problemas para o vinculador de 32 bits. Uma correção possíveis para esse problema é usar o conjunto de ferramentas de 64 bits. Para obter mais informações sobre como fazer isso na linha de comando, consulte [como: Habilitar um 64-Bit Visual C++ conjunto de ferramentas na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md). Para obter informações sobre como fazer isso no IDE, consulte [usando o MSBuild com o compilador de 64 bits e ferramentas](../../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md#using-msbuild-to-build-your-project) e esta postagem de Stack Overflow: [Como fazer com que o Visual Studio usa a cadeia de ferramentas nativo amd64](http://stackoverflow.com/questions/19820718/how-to-make-visual-studio-use-the-native-amd64-toolchain/23793055).

Esse erro pode ocorrer se você tiver permissões de arquivo suficientes para acessar *filename*. Isso pode acontecer se você usa uma conta de usuário comum e uma tentativa para acessar arquivos de biblioteca em diretórios protegidos do sistema ou usar os arquivos copiados de outros usuários que têm suas permissões originais definido. Para corrigir esse problema, mova o arquivo para um diretório do projeto gravável. Se o arquivo está em um diretório gravável, mas tem permissões inacessíveis, você pode usar um prompt de comando de administrador e execute o comando de takeown.exe assumir a propriedade do arquivo.

O erro pode ocorrer quando você não tem espaço em disco suficiente. O vinculador usa arquivos temporários em vários casos. Mesmo se você tiver espaço em disco suficiente, um link muito grande pode depauperam ou espaço em disco disponível do fragmento. Considere o uso de [/OPT (otimizações)](../../build/reference/opt-optimizations.md) opção; fazendo leituras de eliminação COMDAT transitivas todos os arquivos de objeto várias vezes.

Se o *filename* é chamado LNK*nnn*, que é um nome de arquivo gerado pelo vinculador para um arquivo temporário, o diretório especificado na variável de ambiente TMP talvez não exista ou pode ser a mais de um diretório especificado para a variável de ambiente TMP. Caminho de diretório somente um deve ser especificado para a variável de ambiente TMP.
