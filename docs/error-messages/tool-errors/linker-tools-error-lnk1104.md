---
title: Erro das Ferramentas de Vinculador LNK1104
description: Descreve o erro LNK1104 do vinculador do Microsoft C e C++ (MSVC), suas causas e possíveis soluções.
ms.date: 12/13/2019
f1_keywords:
- LNK1104
helpviewer_keywords:
- LNK1104
ms.assetid: 9ca6f929-0efc-4055-8354-3cf5b4e636dc
ms.openlocfilehash: aa7bcf34cddfa24956d807131b3c484e7d580e73
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91506037"
---
# <a name="linker-tools-error-lnk1104"></a>Erro das Ferramentas de Vinculador LNK1104

> Não é possível abrir o arquivo '*filename*'

Esse erro é relatado quando o vinculador falha ao abrir um arquivo, seja para leitura ou gravação. As duas causas mais comuns do problema são:

- seu programa já está em execução ou está carregado no depurador e

- os caminhos de biblioteca estão incorretos ou não são encapsulados em aspas duplas.

Há muitas outras causas possíveis para esse erro. Para limitá-los, primeiro verifique qual tipo de *nome* de arquivo é. Em seguida, use as seções a seguir para ajudar a identificar e corrigir o problema específico.

## <a name="cant-open-your-app-or-its-pdb-file"></a>Não é possível abrir seu aplicativo ou seu arquivo. pdb

### <a name="your-app-is-running-or-its-loaded-in-the-debugger"></a>Seu aplicativo está em execução ou está carregado no depurador

Quando nome do *arquivo* for o nome do seu executável ou um arquivo. PDB associado, veja se seu aplicativo já está em execução. Em seguida, verifique se ele está carregado em um depurador. Para corrigir esse problema, interrompa o programa e descarregue-o do depurador antes de compilá-lo novamente. Se o aplicativo estiver aberto em outro programa, como um editor de recursos, feche-o. Se o seu programa não estiver respondendo, talvez seja necessário usar o Gerenciador de tarefas para encerrar o processo. Talvez você também precise fechar e reiniciar o Visual Studio.

### <a name="your-app-is-locked-by-an-antivirus-scan"></a>Seu aplicativo está bloqueado por uma verificação antivírus

Os programas antivírus geralmente bloqueiam temporariamente o acesso a arquivos recém-criados, especialmente arquivos executáveis. exe e. dll. Para corrigir esse problema, tente excluir os diretórios de Build do projeto do verificador de antivírus.

## <a name="cant-open-a-microsoft-library-file"></a>Não é possível abrir um arquivo de biblioteca da Microsoft

### <a name="windows-libraries-such-as-kernel32lib"></a>Bibliotecas do Windows, como Kernel32. lib

Se o arquivo que não puder ser aberto for um dos arquivos de biblioteca padrão fornecidos pela Microsoft, como *Kernel32. lib*, você poderá ter um erro de configuração de projeto ou um erro de instalação. Verifique se o SDK do Windows foi instalado. Se seu projeto exigir outras bibliotecas da Microsoft, como o MFC, verifique se os componentes do MFC também foram instalados pelo instalador do Visual Studio. Você pode executar o instalador novamente para adicionar componentes opcionais a qualquer momento. Para obter mais informações, consulte [Modify Visual Studio](/visualstudio/install/modify-visual-studio). Use a guia **componentes individuais** no instalador para escolher bibliotecas e SDKs específicos.

### <a name="versioned-vcruntime-libraries"></a>Bibliotecas de vcruntime com controle de versão

Se a mensagem de erro tiver uma biblioteca da Microsoft com versão, como *msvcr120. lib*, o conjunto de ferramentas da plataforma para essa versão do compilador poderá não estar instalado. Para corrigir esse problema, você tem duas opções: atualizar o projeto para usar o conjunto de ferramentas da plataforma atual ou instalar o conjunto de ferramentas mais antigo e criar o projeto inalterado. Para obter mais informações, consulte [Atualizando projetos de versões anteriores do Visual C++](../../porting/upgrading-projects-from-earlier-versions-of-visual-cpp.md) e [usar multiplataforma nativa no Visual Studio para criar projetos antigos](../../porting/use-native-multi-targeting.md).

### <a name="retail-debug-or-platform-specific-libraries"></a>Bibliotecas específicas de varejo, depuração ou plataforma

O erro pode ocorrer quando você cria pela primeira vez uma nova plataforma ou configuração de destino, como varejo ou ARM64. No IDE, verifique se o **conjunto de ferramentas de plataforma** e a **versão SDK do Windows** especificada na [página de propriedades geral](../../build/reference/general-property-page-project.md) estão instalados. Verifique também se as bibliotecas necessárias estão disponíveis nos **diretórios de biblioteca** especificados na [página de propriedades diretórios do vc + +](../../build/reference/vcpp-directories-property-page.md). Verifique as propriedades de cada configuração, como Debug, Retail, x86 ou ARM64. Se um Build funcionar, mas outro não, compare as configurações para ambos. Instale todas as bibliotecas e ferramentas necessárias ausentes.

### <a name="the-vccorliblib-library"></a>A biblioteca vccorlib. lib

Não há bibliotecas Spectre para aplicativos ou componentes do UWP (Universal Windows). Se a mensagem de erro incluir *vccorlib. lib*, você poderá ter habilitado [/Qspectre](../../build/reference/qspectre.md) em um projeto UWP. Desabilite a opção de compilador **/Qspectre** para corrigir esse problema. No Visual Studio, altere a propriedade de **mitigação Spectre** . Ele é encontrado na página de geração de código **C/C++**  >  **Code Generation** da caixa de diálogo **páginas de propriedades** do projeto.

### <a name="libraries-in-projects-from-online-or-other-sources"></a>Bibliotecas em projetos de online ou outras fontes

Se você criar um projeto copiado de outro computador, os locais de instalação da biblioteca poderão ser diferentes. Para compilações de linha de comando, verifique se a variável de ambiente LIB e os caminhos de biblioteca estão definidos corretamente para a compilação. No Visual Studio, você pode ver e editar os caminhos de biblioteca atuais definidos nas páginas de propriedades do seu projeto. Na página **diretórios do vc + +** , escolha o controle suspenso para a propriedade **diretórios de biblioteca** e escolha **Editar**. A seção **valor avaliado** da caixa de diálogo **diretórios de biblioteca** lista os caminhos atuais pesquisados para arquivos de biblioteca. Atualize esses caminhos para apontar para suas bibliotecas locais.

### <a name="updated-windows-sdk-libraries"></a>Bibliotecas de SDK do Windows atualizadas

Esse erro pode ocorrer quando o caminho do Visual Studio para a SDK do Windows está desatualizado. Isso pode acontecer se você instalar uma SDK do Windows mais recente independentemente do instalador do Visual Studio. Para corrigi-lo no IDE, atualize os caminhos especificados na [página de propriedades diretórios do vc + +](../../build/reference/vcpp-directories-property-page.md). Defina a versão no caminho para corresponder ao novo SDK. Se você usar o Prompt de Comando do Desenvolvedor, atualize o arquivo em lotes que inicializa as variáveis de ambiente com os novos caminhos do SDK. Esse problema pode ser evitado usando o instalador do Visual Studio para instalar SDKs atualizados.

## <a name="cant-open-a-third-party-library-file"></a>Não é possível abrir um arquivo de biblioteca de terceiros

Há várias causas comuns para esse problema:

- O caminho para o arquivo de biblioteca pode estar incorreto ou não ser encapsulado entre aspas duplas. Ou talvez você não o tenha especificado para o vinculador.

- Você pode ter instalado uma versão de 32 bits da biblioteca, mas está compilando para 64 bits ou o contrário.

- A biblioteca pode ter dependências em outras bibliotecas que não estão instaladas.

Para corrigir um problema de caminho para compilações de linha de comando, verifique se a variável de ambiente LIB está definida. Certifique-se de que ele inclui caminhos para todas as bibliotecas que você usa e para cada configuração que você criar. No IDE, os caminhos de biblioteca são definidos pela propriedade diretórios de biblioteca de **diretórios vc + +**  >  **Library Directories** . Verifique se todos os diretórios que contêm as bibliotecas de que você precisa estão listados aqui para cada configuração que você criar.

Talvez seja necessário fornecer um diretório de biblioteca que substitua um diretório de biblioteca padrão. Na linha de comando, use a opção [/LIBPATH](../../build/reference/libpath-additional-libpath.md) . No IDE, use a propriedade **diretórios de biblioteca adicionais** na página de **Propriedades configuração > vinculador > geral** para seu projeto.

Certifique-se de instalar todas as versões da biblioteca necessárias para as configurações que você criar. Considere o uso do utilitário de gerenciamento de pacotes [vcpkg](../../build/vcpkg.md) para automatizar a instalação e a configuração de muitas bibliotecas comuns. Quando possível, é melhor criar suas próprias cópias de bibliotecas de terceiros. Em seguida, você tem certeza de ter todas as dependências locais das bibliotecas, criadas para as mesmas configurações do seu projeto.

## <a name="cant-open-a-file-built-by-your-project"></a>Não é possível abrir um arquivo criado por seu projeto

Você poderá ver esse erro se o *nome do arquivo* ainda não existir quando o vinculador tentar acessá-lo. Isso pode acontecer quando um projeto depende de outro na solução, mas os projetos são criados na ordem errada. Para corrigir esse problema, verifique se as referências do projeto estão definidas no projeto que usa o arquivo. Em seguida, o arquivo ausente é compilado antes de ser necessário. Para obter mais informações, consulte [adicionando referências em projetos do Visual Studio C++](../../build/adding-references-in-visual-cpp-projects.md) e [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).

## <a name="cannot-open-file-cprogramobj"></a>Não é possível abrir o arquivo ' C: \\ Program. obj '

Se você vir o nome do arquivo *C: \\ Program. obj* na mensagem de erro, empacote os caminhos da biblioteca entre aspas duplas. Esse erro ocorre quando um caminho não encapsulado que começa com *C: \\ arquivos de programa* é passado para o vinculador. Os caminhos não encapsulados também podem causar erros semelhantes. Normalmente, eles mostram um arquivo. obj inesperado na raiz da unidade.

Para corrigir esse problema para compilações de linha de comando, verifique os parâmetros da opção [/LIBPATH](../../build/reference/libpath-additional-libpath.md) . Verifique também os caminhos especificados na variável de ambiente LIB e os caminhos especificados na linha de comando. Certifique-se de usar aspas duplas em qualquer caminho que inclua espaços.

Para corrigir esse problema no IDE, adicione aspas duplas conforme necessário para as seguintes propriedades para seu projeto:

- A propriedade **diretórios de biblioteca** na página de propriedades [configuração > diretórios vc + +](../../build/reference/vcpp-directories-property-page.md) ,

- A propriedade de **diretórios de biblioteca adicional** na página de **propriedades configuração do > vinculador > geral** ,

- A propriedade **Dependencies adicional** na página **propriedades de configuração > vinculador >** propriedade de entrada.

## <a name="other-common-issues"></a>Outros problemas comuns

### <a name="path-or-filename-issues"></a>Problemas de caminho ou nome de arquivo

Esse erro pode ocorrer quando o nome de arquivo da biblioteca ou o caminho especificado para o vinculador está incorreto. Ou, quando o caminho tem uma especificação de unidade inválida. Procure na linha de comando ou em qualquer diretiva [#pragma Comment (lib, "library_name")](../../preprocessor/comment-c-cpp.md) para problemas. Verifique a ortografia e a extensão do arquivo e verifique se o arquivo existe no local especificado.

### <a name="parallel-build-synchronization"></a>Sincronização de compilação paralela

Se você estiver usando uma opção de compilação paralela, o Visual Studio poderá ter bloqueado o arquivo em outro thread. Para corrigir esse problema, verifique se o mesmo objeto de código ou biblioteca não é criado em vários projetos. Use dependências de compilação ou referências de projeto para pegar binários criados em seu projeto.

### <a name="additional-dependencies-specified-in-the-ide"></a>Dependências adicionais especificadas no IDE

Quando você especifica bibliotecas individuais na propriedade **dependências adicionais** diretamente, use espaços para separar os nomes de biblioteca. Não use vírgulas ou pontos-e-vírgulas. Se você usar o item de menu **Editar** para abrir a caixa de diálogo **dependências adicionais** , use novas linhas para separar os nomes, não vírgulas, ponto-e-vírgula ou espaços. Além disso, use novas linhas ao especificar caminhos de biblioteca nas caixas de diálogo **diretórios** de biblioteca e **diretórios de biblioteca adicionais** .

### <a name="paths-that-are-too-long"></a>Caminhos muito longos

Você poderá ver esse erro quando o caminho para o *nome de arquivo* expandir para mais de 260 caracteres. Se necessário, reorganize sua estrutura de diretório ou diminua os nomes de arquivos e pastas para encurtar os caminhos.

### <a name="files-that-are-too-large"></a>Arquivos que são muito grandes

Esse erro pode ocorrer porque o arquivo é muito grande. Bibliotecas ou arquivos de objeto com mais de um gigabyte podem causar problemas para o vinculador de 32 bits. Uma possível correção para esse problema é usar o conjunto de ferramentas de 64 bits. Para obter mais informações sobre como usar o conjunto de ferramentas de 64 bits na linha de comando, consulte [como habilitar um conjunto de ferramentas de Visual C++ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md). Para obter informações sobre como usar o conjunto de ferramentas de 64 bits no IDE, consulte [usando o MSBuild com o compilador e as ferramentas de 64 bits](../../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md#using-msbuild-to-build-your-project). Consulte também esta Stack Overflow post: [como fazer com que o Visual Studio use o ferramentas do AMD64 nativo](https://stackoverflow.com/questions/19820718/how-to-make-visual-studio-use-the-native-amd64-toolchain/23793055).

### <a name="incorrect-file-permissions"></a>Permissões de arquivo incorretas

Esse erro pode ocorrer se você tiver permissões de arquivo insuficientes para acessar o *nome do arquivo*. Isso pode acontecer se você usar uma conta de usuário comum para acessar arquivos de biblioteca em diretórios de sistema protegidos. Ou, se você usar arquivos copiados de outros usuários que ainda têm suas permissões originais definidas. Para corrigir esse problema, mova o arquivo para um diretório de projeto gravável. Se o arquivo movido tiver permissões inacessíveis, execute o comando takeown.exe em uma janela de comando do administrador para apropriar-se do arquivo.

### <a name="insufficient-disk-space"></a>Espaço insuficiente em disco

O erro pode ocorrer quando você não tem espaço em disco suficiente. O vinculador usa arquivos temporários em vários casos. Mesmo que você tenha espaço em disco suficiente, um link grande pode depauperam ou fragmentar o espaço em disco disponível. Considere usar a opção [/opt (otimizações)](../../build/reference/opt-optimizations.md) ; fazer a eliminação transitiva de COMDAT lê todos os arquivos de objeto várias vezes.

### <a name="problems-in-the-tmp-environment-variable"></a>Problemas na variável de ambiente TMP

Se o *nome do arquivo* for chamado de lnk*nnn*, ele será um nome de arquivo gerado pelo vinculador para um ficheiro temporário. O diretório especificado na variável de ambiente TMP pode não existir. Ou, mais de um diretório pode ser especificado para a variável de ambiente TMP. Somente um caminho de diretório deve ser especificado para a variável de ambiente TMP.

## <a name="help-my-issue-isnt-listed-here"></a>Ajuda, meu problema não está listado aqui!

Quando nenhum dos problemas listados aqui se aplicar, você poderá usar as ferramentas de comentários no Visual Studio para obter ajuda. No IDE, vá para a barra de menus e escolha **ajuda > enviar comentários > relatar um problema**. Ou envie uma sugestão usando **a ajuda > enviar comentários > enviar uma sugestão**. Você também pode usar o site do Visual Studio C++ [Developer Community](https://developercommunity.visualstudio.com/spaces/62/index.html)). Use-o para procurar respostas para perguntas e pedir ajuda. Para obter mais informações, consulte [como relatar um problema com o conjunto de ferramentas Visual C++ ou a documentação](../../overview/how-to-report-a-problem-with-the-visual-cpp-toolset.md).

Se você descobriu uma nova maneira de corrigir esse problema que devemos adicionar a este artigo, avise-nos. Você pode enviar comentários para nós usando o botão abaixo para **esta página**. Use-o para criar um novo problema em nosso [repositório GitHub de documentação do C++](https://github.com/MicrosoftDocs/cpp-docs/issues). Obrigado!
