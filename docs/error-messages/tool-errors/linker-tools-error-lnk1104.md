---
title: Erro das Ferramentas de Vinculador LNK1104
ms.date: 09/06/2019
f1_keywords:
- LNK1104
helpviewer_keywords:
- LNK1104
ms.assetid: 9ca6f929-0efc-4055-8354-3cf5b4e636dc
ms.openlocfilehash: f3effd9054954a90f69c5b18d8f099e6d705d9a3
ms.sourcegitcommit: 7babce70714242cf498ca811eec3695fad3abd03
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/09/2019
ms.locfileid: "70808844"
---
# <a name="linker-tools-error-lnk1104"></a>Erro das Ferramentas de Vinculador LNK1104

> Não é possível abrir o arquivo '*filename*'

O vinculador não pôde abrir o arquivo especificado. As causas mais comuns desse problema são que o arquivo está em uso ou bloqueado por outro processo. Também é possível que o arquivo não exista ou não seja encontrado em um dos diretórios que o vinculador pesquisa. Ou talvez você não tenha permissão suficiente para acessar o arquivo. Com menos frequência, você pode ficar sem espaço em disco, o arquivo pode ser muito grande ou o caminho para o arquivo pode ser muito longo.

## <a name="possible-causes-and-solutions"></a>Possíveis causas e soluções

Esse erro pode ocorrer quando o vinculador tenta abrir um arquivo para leitura ou gravação. Para restringir as possíveis causas, primeiro verifique o tipo de arquivo. Em seguida, use as seções a seguir para ajudar a identificar e corrigir o problema específico.

### <a name="cant-open-your-app-or-its-pdb-file"></a>Não é possível abrir seu aplicativo ou seu arquivo. pdb

Se o nome do arquivo for o executável que seu projeto compila, ou um arquivo. PDB associado, a causa mais comum é que seu aplicativo já está em execução quando você tenta reconstruí-lo ou é carregado em um depurador. Para corrigir esse problema, interrompa o programa e descarregue-o do depurador antes de compilá-lo novamente. Se o aplicativo estiver aberto em outro programa, como um editor de recursos, feche-o. Em casos extremos, talvez seja necessário usar o Gerenciador de tarefas para encerrar o processo ou parar e reiniciar o Visual Studio.

Os programas antivírus geralmente bloqueiam temporariamente o acesso a arquivos recém-criados, especialmente arquivos executáveis. exe e. dll. Para corrigir esse problema, tente excluir os diretórios de Build do projeto do verificador de antivírus.

### <a name="cant-open-a-microsoft-library-file"></a>Não é possível abrir um arquivo de biblioteca da Microsoft

Se o arquivo que não puder ser aberto for um dos arquivos de biblioteca padrão fornecidos pela Microsoft, como Kernel32. lib, você poderá ter um erro de configuração de projeto ou um erro de instalação. Verifique se o SDK do Windows foi instalado e, se o seu projeto exigir outras bibliotecas da Microsoft, como o MFC, verifique se os componentes do MFC também foram instalados pelo instalador do Visual Studio. Você pode executar o instalador novamente para adicionar componentes opcionais a qualquer momento. Para obter mais informações, consulte [Modify Visual Studio](/visualstudio/install/modify-visual-studio). Use a guia componentes individuais no instalador para escolher bibliotecas e SDKs específicos.

Não há bibliotecas Spectre para aplicativos ou componentes do UWP (Universal Windows). Se o relatório de erros mencionar o arquivo *vccorlib. lib* , você poderá ter habilitado o [/Qspectre](../../build/reference/qspectre.md) em um projeto UWP. Desabilite a opção de compilador **/Qspectre** para corrigir esse problema. No Visual Studio, altere a propriedade de **mitigação Spectre** encontrada na página geração **CC++/**  > **código** da caixa de diálogo **páginas de propriedades** do projeto.

Se você estiver criando um projeto que foi criado usando uma versão mais antiga do Visual Studio, o conjunto de ferramentas e as bibliotecas da plataforma para essa versão podem não estar instalados. Se a mensagem de erro ocorrer para um nome de biblioteca com versão, como msvcr100. lib, essa é provavelmente a causa. Para corrigir esse problema, você tem duas opções: você pode atualizar o projeto para usar o conjunto de ferramentas de plataforma atual que você instalou ou pode instalar o conjunto de ferramentas mais antigo e criar o projeto inalterado. Para obter mais informações, consulte [Atualizando projetos de versões anteriores C++ do Visual](../../porting/upgrading-projects-from-earlier-versions-of-visual-cpp.md) e [usar multiplataforma nativa no Visual Studio para criar projetos antigos](../../porting/use-native-multi-targeting.md).

Se você vir esse erro ao compilar para uma nova plataforma ou configuração de destino, as bibliotecas para essa configuração de projeto ou conjunto de ferramentas de plataforma poderão não estar instaladas. Verifique se o **conjunto de ferramentas de plataforma** e a **versão SDK do Windows** especificada na [página de propriedades geral](../../build/reference/general-property-page-project.md) do seu projeto estão instalados e verifique se as bibliotecas necessárias estão disponíveis nos **diretórios de biblioteca** especificados em a [página de propriedades de diretórios do vc + +](../../build/reference/vcpp-directories-property-page.md) para suas definições de configuração. Há configurações separadas para configurações de depuração e de varejo, bem como configurações de 32 bits e de 64 bits, portanto, se uma compilação funcionar, mas outra causar um erro, verifique se as configurações estão corretas e se as ferramentas e bibliotecas necessárias estão instaladas para cada configuração que você cria.

Se você estiver usando o IDE do Visual Studio para criar um projeto que foi copiado de outro computador, os locais de instalação das bibliotecas poderão ser diferentes. Verifique a propriedade **diretórios de biblioteca** na [página de propriedades diretórios vc + +](../../build/reference/vcpp-directories-property-page.md) do projeto e atualize-o se necessário. Para ver e editar os caminhos de biblioteca atuais definidos no IDE, escolha o controle suspenso para a propriedade **diretórios de biblioteca** e escolha **Editar**. A seção **valor avaliado** da caixa de diálogo **diretórios de biblioteca** lista os caminhos atuais pesquisados para arquivos de biblioteca.

Esse erro também pode ocorrer quando o caminho para a SDK do Windows está desatualizado. Se você instalou uma versão do SDK do Windows que é mais recente que a sua versão do Visual Studio, certifique-se de que os caminhos especificados na [página de propriedades de diretórios do vc + +](../../build/reference/vcpp-directories-property-page.md) sejam atualizados para corresponder ao novo SDK. Se você usar o Prompt de Comando do Desenvolvedor, certifique-se de que o arquivo em lotes que inicializa as variáveis de ambiente seja atualizado para os novos caminhos do SDK. Esse problema pode ser evitado usando o instalador do Visual Studio para instalar SDKs atualizados.

### <a name="cannot-open-a-third-party-library-file"></a>Não é possível abrir um arquivo de biblioteca de terceiros

Há várias causas comuns para esse problema:

- O caminho para o arquivo de biblioteca pode estar incorreto ou você pode não tê-lo especificado no vinculador.

- Você pode ter instalado uma versão de 32 bits da biblioteca, mas está compilando para 64 bits ou vice-versa.

- A biblioteca pode ter dependências em outras bibliotecas que não estão instaladas.

Para corrigir um problema de caminho, verifique se a variável de ambiente LIB está definida e contém todos os diretórios para as bibliotecas usadas para cada configuração que você criar. No IDE, a variável LIB é definida pela propriedade **diretórios de biblioteca** na página de [Propriedades diretórios vc + +](../../build/reference/vcpp-directories-property-page.md). Verifique se todos os diretórios que contêm as bibliotecas de que você precisa estão listados aqui para cada configuração que você criar.

Se você precisar fornecer um diretório de biblioteca que substitui um diretório de biblioteca padrão, você pode usar a opção [/LIBPATH](../../build/reference/libpath-additional-libpath.md) na linha de comando ou no IDE, você pode usar a propriedade de **diretórios de biblioteca adicional** nas **Propriedades de configuração > Vinculador >** página de propriedades geral para seu projeto.

Verifique se você instalou todas as versões da biblioteca necessárias para as configurações criadas. Considere o uso do utilitário de gerenciamento de pacotes [vcpkg](../../vcpkg.md) para automatizar a instalação e a configuração de muitas bibliotecas comuns. Quando possível, é melhor criar suas próprias cópias de bibliotecas de terceiros, de modo que você tenha certeza de ter todas as dependências locais exigidas pelas bibliotecas e elas são criadas para as mesmas configurações do seu projeto.

### <a name="cannot-open-a-file-built-by-your-project"></a>Não é possível abrir um arquivo criado por seu projeto

Você poderá ver esse erro se o *nome* de arquivo for compilado por sua solução, mas ainda não existirá quando o vinculador tentar acessá-lo. Isso pode acontecer quando um projeto depende de outro projeto, mas os projetos não são criados na ordem correta. Para corrigir esse problema, verifique se as referências do projeto estão definidas no projeto que usa o arquivo para que o arquivo ausente seja compilado antes de ser necessário. Para obter mais informações, consulte [adicionando referências em projetos C++ do Visual Studio](../../build/adding-references-in-visual-cpp-projects.md) e [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).

### <a name="cannot-open-file-cprogramobj"></a>Não é possível abrir o arquivo\\' C: Program. obj '

Se você vir esse erro ou um erro semelhante que envolva um arquivo. obj inesperado na raiz da unidade, o problema será quase certamente um caminho de biblioteca que não está encapsulado entre aspas duplas.

Para corrigir esse problema para compilações de linha de comando, verifique os parâmetros de opção [/LIBPATH](../../build/reference/libpath-additional-libpath.md) , os caminhos especificados na variável de ambiente lib e os caminhos especificados na linha de comando e certifique-se de usar aspas duplas em torno de quaisquer caminhos que incluam espaços.

Para corrigir esse problema no IDE, verifique a propriedade **diretórios de biblioteca** nas propriedades de configuração > página de propriedades de [diretórios vc + +](../../build/reference/vcpp-directories-property-page.md) , a propriedade **diretórios de biblioteca adicional** no **vinculador de > de propriedades de configuração >** Página de propriedades geral e a propriedade **dependências adicionais** na página de **Propriedades configuração do > vinculador > entrada** do seu projeto. Verifique se todos os caminhos de diretório que contêm as bibliotecas necessárias estão encapsuladas entre aspas duplas, se necessário.

### <a name="other-common-issues"></a>Outros problemas comuns

Esse erro pode ocorrer quando o nome de arquivo da biblioteca ou o caminho especificado para o vinculador na linha de comando ou em uma diretiva [#pragma Comment (lib, "library_name")](../../preprocessor/comment-c-cpp.md) está incorreto ou o caminho tem uma especificação de unidade inválida. Verifique a ortografia e a extensão do arquivo e verifique se o arquivo existe no local especificado.

Outro programa pode ter o arquivo aberto e o vinculador não pode gravar nele. Os programas antivírus geralmente bloqueiam temporariamente o acesso a arquivos recém-criados. Para corrigir esse problema, tente excluir os diretórios de Build do projeto do verificador de antivírus.

Se você estiver usando uma opção de compilação paralela, é possível que o Visual Studio tenha bloqueado o arquivo em outro thread. Para corrigir esse problema, verifique se você não criou o mesmo objeto de código ou biblioteca em vários projetos, e se você usa dependências de compilação ou referências de projeto para pegar binários criados em seu projeto.

Quando você especifica bibliotecas individuais na propriedade **dependências adicionais** diretamente, use espaços para separar os nomes de biblioteca, não vírgulas ou pontos-e-vírgulas. Se você usar o item de menu **Editar** para abrir a caixa de diálogo **dependências adicionais** , use novas linhas para separar os nomes, não vírgulas, ponto-e-vírgula ou espaços. Além disso, use novas linhas ao especificar caminhos de biblioteca nas caixas de diálogo **diretórios** de biblioteca e **diretórios de biblioteca adicionais** .

Você poderá ver esse erro quando o caminho para o *nome de arquivo* expandir para mais de 260 caracteres. Altere os nomes ou reorganize sua estrutura de diretórios, se necessário, para encurtar os caminhos para os arquivos necessários.

Esse erro pode ocorrer porque o arquivo é muito grande. Bibliotecas ou arquivos de objeto com mais de um gigabyte podem causar problemas para o vinculador de 32 bits. Uma possível correção para esse problema é usar o conjunto de ferramentas de 64 bits. Para obter mais informações sobre como fazer isso na linha de comando, consulte [como: Habilite um conjunto de ferramentas C++ do Visual de 64 bits](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md)na linha de comando. Para obter informações sobre como fazer isso no IDE, consulte [usando o MSBuild com as ferramentas e o compilador de 64 bits](../../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md#using-msbuild-to-build-your-project) e este Stack Overflow post: [Como fazer o Visual Studio usar o ferramentas do AMD64 nativo](https://stackoverflow.com/questions/19820718/how-to-make-visual-studio-use-the-native-amd64-toolchain/23793055).

Esse erro pode ocorrer se você tiver permissões de arquivo insuficientes para acessar o *nome do arquivo*. Isso pode acontecer se você usar uma conta de usuário comum e tentar acessar arquivos de biblioteca em diretórios de sistema protegidos ou usar arquivos copiados de outros usuários que tenham suas permissões originais definidas. Para corrigir esse problema, mova o arquivo para um diretório de projeto gravável. Se o arquivo estiver em um diretório gravável, mas tiver permissões inacessíveis, você poderá usar um prompt de comando de administrador e executar o comando takeown. exe para apropriar-se do arquivo.

O erro pode ocorrer quando você não tem espaço em disco suficiente. O vinculador usa arquivos temporários em vários casos. Mesmo que você tenha espaço em disco suficiente, um link muito grande pode depauperam ou fragmentar o espaço em disco disponível. Considere usar a opção [/opt (otimizações)](../../build/reference/opt-optimizations.md) ; fazer a eliminação transitiva de COMDAT lê todos os arquivos de objeto várias vezes.

Se o *nome* do arquivo for chamado de lnk*nnn*, que é um nome de arquivo gerado pelo vinculador para um arquivo temporário, o diretório especificado na variável de ambiente TMP pode não existir ou mais de um diretório pode ser especificado para a variável de ambiente TMP. Somente um caminho de diretório deve ser especificado para a variável de ambiente TMP.
