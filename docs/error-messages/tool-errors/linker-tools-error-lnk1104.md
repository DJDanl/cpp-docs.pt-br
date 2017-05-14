---
title: Ferramentas de vinculador LNK1104 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1104
dev_langs:
- C++
helpviewer_keywords:
- LNK1104
ms.assetid: 9ca6f929-0efc-4055-8354-3cf5b4e636dc
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 128bd124c2536d86c8b673b54abc4b5505526b41
ms.openlocfilehash: c6121f598bc2913b65fe781b07bcc27e6b55375b
ms.contentlocale: pt-br
ms.lasthandoff: 05/10/2017

---
# <a name="linker-tools-error-lnk1104"></a>Erro das Ferramentas de Vinculador LNK1104
não é possível abrir o arquivo '*filename*'  
  
O vinculador não foi possível abrir o arquivo especificado.  
  
## <a name="possible-causes-and-solutions"></a>Possíveis causas e soluções
  
Esse erro pode ocorrer quando o vinculador tenta abrir um arquivo para leitura ou gravação. As causas mais comuns desse problema são que o arquivo não existe, não pode ser encontrado em um dos diretórios de vinculador pesquisa, ou está em uso e bloqueado por outro processo. Menor frequência, você pode ter sido executado sem espaço em disco, o arquivo pode ser muito grande, o caminho para o arquivo pode ser muito longo ou talvez você não tenha permissão para acessar o arquivo.  

Verifique se há um desses problemas comuns:  

-   O aplicativo já está em execução quando você tenta recriá-lo. Se o arquivo que não é possível abrir o arquivo executável ou um arquivo de depuração, como um. PDB, essa é uma causa comum. Para corrigir esse problema, pare o programa e descarregá-la a partir do depurador antes de criá-lo novamente.  
  
-   O arquivo *filename* é criada com a sua solução, mas ainda não existir quando o vinculador tenta acessá-lo. Isso pode acontecer quando um projeto depende de outro projeto para gerar esse arquivo, mas os projetos não são criados na ordem correta. Para corrigir esse problema, verifique se as referências do projeto são definidas no projeto que usa o arquivo para que o arquivo ausente é criado quando for necessário. Para obter mais informações, consulte [adicionando referências em projetos do Visual C++](../../ide/adding-references-in-visual-cpp-projects.md) e [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).  
  
-   O nome do arquivo ou o caminho especificado na linha de comando ou em uma diretiva de lib #pragma está incorreto ou o caminho tem uma especificação de unidade inválida. Verifique a ortografia e verifique se que o arquivo existe no local especificado.  
  
-   Se você estiver usando o Visual Studio IDE para compilar um projeto que foi copiado de outro computador, os locais de instalação de bibliotecas podem ser diferentes. Verificar a propriedade de diretórios de biblioteca de [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md) e atualizá-lo se necessário. Para ver e editar os caminhos de biblioteca atual definido no IDE, escolha o controle de lista suspensa para a propriedade de diretórios de biblioteca e escolha **editar**. O **avaliada valor** seção da caixa de diálogo diretórios de biblioteca lista os caminhos atuais pesquisados em busca de arquivos de biblioteca.  
  
-   Se você estiver criando um projeto que foi criado usando uma versão anterior do Visual Studio, o conjunto de ferramentas de plataforma e bibliotecas para essa versão podem não não ser instaladas. Para corrigir esse problema, você tem duas opções: você pode atualizar o projeto para usar o conjunto de ferramentas de plataforma atual tiver instalado ou você pode instalar o conjunto de ferramentas mais antigo e compilar o projeto inalterado. Para obter mais informações, consulte [Atualizando projetos a partir de versões anteriores do Visual C++](../../porting/upgrading-projects-from-earlier-versions-of-visual-cpp.md) e [usar nativo multiplataforma no Visual Studio para criar projetos antigos](../../porting/use-native-multi-targeting.md).
  
-   As bibliotecas para a configuração do projeto atual ou o conjunto de ferramentas da plataforma não estão instaladas. Verifique se o conjunto de ferramentas de plataforma e o SDK do Windows especificado no [página de propriedades geral](../../ide/general-property-page-project.md) para seu projeto estão instalados e verificar se as bibliotecas necessárias estão disponíveis nos diretórios de biblioteca especificados no [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md) para as configurações. Existem configurações separadas para as configurações de depuração e de varejo, portanto se uma criar funciona, mas a outra causa um erro, verifique se as configurações estão corretas e as ferramentas necessárias e bibliotecas estão instaladas para ambas as configurações.  
  
-   O caminho para o SDK do Windows está desatualizado. Se você instalou uma versão do SDK do Windows mais recente que a versão do Visual Studio, certifique-se de que os caminhos especificados no [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md) são atualizadas de acordo com o novo SDK. Se você usar o Prompt de comando do desenvolvedor, verifique se o arquivo em lotes que inicializa as variáveis de ambiente é atualizado para os novos caminhos SDK.  
  
-   Outro programa pode ter o arquivo aberto e não é possível gravar o vinculador a ele. Programas antivírus geralmente bloqueiam temporariamente o acesso a arquivos recém-criados. Para corrigir esse problema, tente excluir seus diretórios de compilação de projeto do scanner antivírus.  
  
-   Se você estiver usando uma opção de compilação paralela, é possível que o Visual Studio bloqueou o arquivo em outro thread. Para corrigir esse problema, verifique se que você não cria o mesmo objeto de código ou a biblioteca em vários projetos, e que você use as dependências de compilação ou referências de projeto para acompanhar binários criados em seu projeto.  
  
-   Você tem uma variável de ambiente LIB incorretova. Em compilações de linha de comando, verifique se a variável de ambiente LIB está definida e contém todos os diretórios para as bibliotecas que você usa. No IDE, a variável LIB é definida pela propriedade diretórios de biblioteca no [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md). Verifique se todos os diretórios que contêm as bibliotecas que necessárias estão listados aqui. Se você precisa fornecer um diretório de biblioteca que substitui uma pasta de biblioteca padrão, você pode usar o [/LIBPATH](../../build/reference/libpath-additional-libpath.md)) opção na linha de comando ou a propriedade de diretórios de biblioteca adicionais na página de propriedade de vinculador para seu projeto.  
  
-   Ao especificar bibliotecas individuais na caixa de diálogo páginas de propriedades do projeto, os nomes de biblioteca devem ser separados por espaços, vírgulas não.  
  
-   O caminho para *filename* expande a mais do que 260 caracteres. Alterar os nomes ou reorganizar a estrutura de diretório, se necessário para encurtar caminhos para os arquivos necessários.  
  
-   O arquivo é muito grande. Objeto ou bibliotecas de arquivos mais do que um gigabyte no tamanho pode causar problemas para o vinculador de 32 bits. Possíveis para corrigir esse problema é usar o conjunto de ferramentas de 64 bits. Para obter mais informações sobre como fazer isso na linha de comando, consulte [como: habilitar um 64-Bit Visual C++ conjunto de ferramentas na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md). Para obter informações sobre como fazer isso no IDE, consulte [usando MSBuild com o compilador de 64 bits e ferramentas](../../build/walkthrough-using-msbuild-to-create-a-visual-cpp-project.md#using-msbuild-to-build-your-project) e esta postagem de estouro de pilha: [como fazer com que o Visual Studio usa a cadeia de ferramentas nativas amd64](http://stackoverflow.com/questions/19820718/how-to-make-visual-studio-use-the-native-amd64-toolchain/23793055).  
  
-   Você tem permissões de arquivo suficientes para acessar *filename*. Isso pode acontecer se você acessar os arquivos de biblioteca em diretórios protegidos do sistema ou usa os arquivos copiados de outros usuários que têm as permissões originais definido. Para corrigir esse problema, mova o arquivo para um diretório do projeto gravável. Se o arquivo está em um diretório gravável, mas tem permissões inacessíveis, você pode usar um prompt de comando do administrador e execute o comando de takeown.exe se apropriar do arquivo.  
  
-   Você não tem espaço em disco suficiente. O vinculador usa arquivos temporários em vários casos. Mesmo se você tiver espaço suficiente em disco, um link muito grande pode depauperam ou fragmento de espaço em disco disponível. Considere o uso de [/OPÇ (otimizações)](../../build/reference/opt-optimizations.md) opção; fazendo leituras de eliminação de comdat transitiva todos os arquivos de objeto várias vezes.  
  
-   Se o *filename* chamado LNK*n*, que é um nome de arquivo gerado pelo vinculador para um arquivo temporário, o diretório especificado na variável de ambiente TMP pode não existir ou pode ser especificado mais de um diretório para a variável de ambiente TMP. Apenas um caminho deve ser especificado para a variável de ambiente TMP.  
  
-   Se a mensagem de erro ocorre para um nome de biblioteca, e você recentemente movido o arquivo .mak de um sistema de desenvolvimento Microsoft Visual C++ anterior, a biblioteca pode não ser mais válida. Certifique-se de que o nome da biblioteca está correto e ainda existe no local especificado, ou atualize o caminho de biblioteca para apontar para o novo local.  

