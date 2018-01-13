---
title: "vcpkg – um gerenciador de pacotes do C++ para Windows | Microsoft Docs"
description: "O vcpkg é um gerenciador de pacote de linha de comando que simplifica bastante a aquisição e instalação de bibliotecas de C++ de software livre no Windows."
keywords: vcpkg
author: mikeblome
ms.author: mblome
ms.date: 05/30/2017
ms.technology: cpp-ide
ms.tgt_pltfrm: windows
ms.assetid: f50d459a-e18f-4b4e-814b-913e444cedd6
ms.topic: article
dev_langs: C++
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0728827cb2cd604ec4e7ff1ef58b68ed8fb64532
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="vcpkg-c-package-manager-for-windows"></a>vcpkg: gerenciador de pacotes de C++ para Windows 
O vcpkg é um gerenciador de pacote de linha de comando que simplifica bastante a aquisição e instalação de bibliotecas de C++ de terceiros no Windows. Se seu projeto usa bibliotecas de terceiros, é recomendável que você use o vcpkg para instalá-las. O vcpkg dá suporte a bibliotecas de software livre e proprietárias. Todas as bibliotecas do catálogo público do vcpkg foram testadas quanto à compatibilidade com o Visual Studio 2015 e Visual Studio 2017. Desde de maio de 2017 há mais 238 bibliotecas no catálogo e a comunidade do C++ está continuamente adicionando mais bibliotecas.

## <a name="simple-yet-flexible"></a>Simples e flexível
Com um único comando, você pode baixar fontes e compilar uma biblioteca. O próprio vcpkg é um projeto de software livre disponível no GitHub. Você pode personalizar seu(s) clone(s) particular(es) da maneira que desejar, por exemplo, especificando bibliotecas diferentes ou versões das bibliotecas diferentes das que são encontradas no catálogo do público. Você pode ter vários clones de vcpkg em um único computador, cada um gerando conjuntos personalizados de bibliotecas e/ou opções de compilação, etc. Cada clone é um ambiente x-copiável totalmente autocontido, com sua própria cópia do vcpkg.exe que funciona apenas em sua própria hierarquia. O vcpkg não é adicionado a nenhuma variável de ambiente e não tem nenhuma dependência no Registro do Windows ou no Visual Studio.

## <a name="sources-not-binaries"></a>Fontes não binárias
Para bibliotecas no catálogo do público, o vcpkg baixa fontes em vez de binários[1]. Ele compila essas fontes usando o Visual Studio 2017 ou o Visual Studio 2015 se o 2017 não estiver instalado. No C++, é muito importante que todas bibliotecas que você usar sejam compiladas com o mesmo compilador e com a mesma versão de compilador que o código de aplicativo que vincula-se a ela. Ao usar o vcpkg você elimina ou, pelo menos, reduz bastante o potencial de binários não correspondentes e os problemas que eles podem causar. Em equipes que são padronizadas com uma versão específica do compilador Visual C++, um membro da equipe pode usar o vcpkg para baixar fontes e compilar um conjunto de binários e, em seguida, usar o comando de exportação para compactar os binários e os cabeçalhos para outros membros da equipe. Para obter mais informações, confira abaixo a Exportação de binários compilados e cabeçalhos. 

Se você criar um clone de vcpkg com bibliotecas particulares na coleção de portas, você poderá adicionar uma porta que baixa os cabeçalhos e os binários pré-criados e grave um arquivo portfile.cmake que simplesmente copia esses arquivos para o local desejado.

[1] *Observação: as fontes não estão disponíveis para algumas bibliotecas proprietárias. O vcpkg baixará binários pré-criados compatíveis nesses casos.*

## <a name="installation"></a>Instalação
Faça o clone do repositório vcpkg do GitHub: https://github.com/Microsoft/vcpkg. Você pode baixar em qualquer local de pasta que você preferir.

Execute o bootstrapper na pasta raiz: bootstrap-vcpkg.bat.

## <a name="basic-tasks"></a>Tarefas básicas
  
### <a name="search-the-list-of-available-libraries"></a>Pesquisar a lista de bibliotecas disponíveis
Para ver quais pacotes estão disponíveis, no prompt de comando digite:`vcpkg search`

Este comando enumera os arquivos de controle nas subpastas vcpkg/portas. Você verá uma listagem como essa:

```cmd
ace       6.4.3   The ADAPTIVE Communication Environment
anax      2.1.0-1 An open source C++ entity system. <https://github...
antlr4    4.6-1   ANother Tool for Language Recognition
apr       1.5.2   The Apache Portable Runtime (APR) is a C library ...
asio      1.10.8  Asio is a cross-platform C++ library for network ...
assimp    3.3.1   The Open Asset import library
atk       2.24.0  GNOME Accessibility Toolkit
...
```

  Você pode filtrar em um padrão, por exemplo `vcpkg search ta`:

```cmd
botan       2.0.1      A cryptography library written in C++11
portaudio   19.0.6.00  PortAudio Portable Cross-platform Audio I/O API P...
taglib      1.11.1-2   TagLib Audio Meta-Data Library

```

### <a name="install-a-library-on-your-local-machine"></a>Instalar uma biblioteca em seu computador local
Depois de obter o nome de uma biblioteca usando `vcpkg search`, você usa `vcpkg install` para baixar a biblioteca e compilá-la. O vcpkg usa o portfile da biblioteca no diretório de portas. Se nenhum tripleto for especificado, o vcpkg instalará e compilará para Windows x86. Se o portfile especificar dependências, o vcpkg baixará e instalará as dependências também. Depois de baixar, o vcpkg compila a biblioteca usando qualquer sistema de build que a biblioteca usa. Os arquivos de projetos CMake e MSBuild são preferenciais, mas há suporte para MAKE juntamente com qualquer outro sistema de build. Se o vcpkg não puder localizar o sistema de build especificado no computador local, ele vai baixá-lo e instalá-lo.

```cmd
> vcpkg install boost:x86-windows

The following packages will be built and installed:
    boost:x86-windows
  * bzip2:x86-windows
  * zlib:x86-windows
Additional packages (*) will be installed to complete this operation.
```

### <a name="list-the-libraries-already-installed"></a>Listar as bibliotecas já instaladas
Depois de instalar algumas bibliotecas, você pode usar `vcpkg list` para ver o que você tem:

```cmd
> vcpkg list

boost:x86-windows       1.64-3   Peer-reviewed portable C++ source libraries
bzip2:x86-windows       1.0.6-1  High-quality data compressor.
cpprestsdk:x86-windows  2.9.0-2  C++11 JSON, REST, and OAuth library The C++ REST ...
openssl:x86-windows     1.0.2k-2 OpenSSL is an open source project that provides a...
websocketpp:x86-windows 0.7.0    Library that implements RFC6455 The WebSocket Pro...
zlib:x86-windows        1.2.11   A compression library
```

### <a name="integrate-with-visual-studio"></a>Integrar com o Visual Studio
#### <a name="per-user"></a>Por usuário
Execute `vcpkg integrate install` para configurar o Visual Studio para localizar todos os arquivos de cabeçalho e binários de vcpkg para cada usuário, sem a necessidade de edição manual dos caminhos de diretórios do VC++. Se você tiver vários clones, o clone do qual você executa este comando se tornará o novo local padrão.

Agora você pode #incluir cabeçalhos simplesmente digitando pasta/cabeçalho e o preenchimento automático vai ajudá-lo. Não será necessária nenhuma etapa adicional para vinculação a bibliotecas ou adição de referências de projeto. A ilustração a seguir mostra como o Visual Studio localiza os cabeçalhos azure-storage-cpp. O vcpkg coloca seus cabeçalhos na subpasta \installed, particionada por plataforma de destino. O diagrama a seguir mostra a lista de arquivos de inclusão na subpasta `/was` para a biblioteca:

 ![Integração do vcpkg e IntelliSense](media/vcpkg-intellisense.png "vcpkg e IntelliSense")  

#### <a name="per-project"></a>Por projeto
Se você precisar usar uma versão específica de uma biblioteca que seja diferente da versão em sua instância vcpkg ativa, você poderá fazer um novo clone do vcpkg, modificar o portfile para a biblioteca a fim de obter a versão necessária e, em seguida, executar `vcpkg install <library>`. Depois disso, você pode usar `vcpkg integrate project` para criar um pacote NuGet que faça referência a essa biblioteca com base em cada projeto.

### <a name="export-compiled-binaries-and-headers"></a>Exportar binários compilados e cabeçalhos
Exigir que todos os membros de uma equipe baixem e compilem bibliotecas poderá ser ineficiente. Um único membro da equipe pode realizar esse trabalho e, em seguida, usar `vcpkg export` para criar um arquivo zip dos binários e dos cabeçalhos, que podem ser facilmente compartilhados com outros membros da equipe. 

### <a name="update-installed-libraries"></a>Atualizar bibliotecas instaladas
O catálogo público é mantido atualizado com as versões mais recentes das bibliotecas. Para determinar qual das suas bibliotecas locais está desatualizada, use `vcpkg update`. Quando você estiver pronto para atualizar sua coleção de portas para a versão mais recente do catálogo público, é só fazer uma operação de pull de git no repositório GitHub ou criar um novo clone e manter o antigo, se ele ainda for necessário.

### <a name="contribute-new-libraries"></a>Contribuir com novas bibliotecas
Você pode incluir todas as biblioteca que quiser em sua coleção de portas particulares. Para sugerir uma nova biblioteca para o catálogo público, abra um problema na [página de problemas do vcpkg do GitHub](https://github.com/Microsoft/vcpkg/issues).

### <a name="remove-a-library"></a>Remover uma biblioteca
Digite `vcpkg remove` para remover uma biblioteca instalada. Se houver outras bibliotecas que dependem dela, você será solicitado a executar novamente o comando com `--recurse`, o que fará com que todas as bibliotecas dependentes sejam removidas.

### <a name="customize-vcpkg"></a>Personalizar o vcpkg
Você pode modificar seu clone do vcpkg da maneira que desejar. Você pode criar vários clones de vcpkg e modificar os portfiles em cada um para obter versões específicas de bibliotecas ou especificar parâmetros de linha de comando. Por exemplo, em uma empresa, um grupo de desenvolvedores pode estar trabalhando em um software que tenha um conjunto de dependências e outro grupo pode ter outro conjunto de dependências. Você pode configurar dois clones de vcpkg e modificar cada um para baixar as versões das bibliotecas e as opções de compilação, etc., de acordo com suas necessidades. 

### <a name="uninstall-vcpkg"></a>Desinstalar o vcpkg
Basta excluir o diretório. 

## <a name="the-vcpkg-folder-hierarchy"></a>A hierarquia de pasta do vcpkg
Todas as funcionalidades e os dados do vcpkg são completamente autocontidos em uma única hierarquia de diretórios; isso é chamado de uma "instância". Não há configurações de Registro ou variáveis de ambiente. Você pode ter qualquer quantidade de instâncias de vcpkg em um computador e elas não causarão interferência umas nas outras. 

O conteúdo de uma instância de vcpkg é: 
- buildtrees – contém subpastas de fontes das quais cada biblioteca é compilada
- documentos – documentação e exemplos
- downloads – cópias em cache de quaisquer ferramentas ou fontes baixadas. O vcpkg pesquisa aqui primeiro quando você executa o comando de instalação.
- instalado – contém os cabeçalhos e os binários de cada biblioteca instalada. Ao integrar com o Visual Studio, você está basicamente informando para que essa pasta seja adicionada ao seus caminhos de pesquisa.
- pacotes – pasta interna de preparo entre instalações.
- portas – arquivos que descrevem cada biblioteca no catálogo, sua versão e onde baixá-la. Você pode adicionar suas próprias portas se necessário.
- scripts – scripts (cmake, powershell) usados pelo vcpkg.
- toolsrc – código-fonte C++ para vcpkg e componentes relacionados
- tripletos – contém as configurações para cada plataforma de destino com suporte (por exemplo, Windows x86 ou Uwp x64).

## <a name="command-line-reference"></a>Referência de linha de comando
- vcpkg search [pat]        Pesquisar pacotes disponíveis para serem compilados
- vcpkg install <pkg>...    Instalar um pacote
- vcpkg remove <pkg>...  Desinstalar um pacote
- vcpkg remove --outdated   Desinstalar todos os pacotes desatualizados
- vcpkg list            Listar os pacotes instalados
- vcpkg update          Exibir lista de pacotes para atualização
- vcpkg hash <file> [alg]       Realizar hash de um arquivo por algoritmo específico, o padrão é SHA512
- vcpkg integrate install       Tornar pacotes instalados disponíveis a todos os usuários. Exige privilégios administrativos no primeiro uso
- vcpkg integrate remove        Remover a integração de todos os usuários
- vcpkg integrate project        Gerar um pacote NuGet de referência para uso de projeto individual do VS
- vcpkg export <pkg>... [opt]...    Exporta um pacote
- vcpkg edit <pkg>      Abrir uma porta para edição (usa o código "padrão" do %EDITOR %)
- vcpkg import <pkg>        Importar uma biblioteca pré-criada
- vcpkg create <pkg> <url>   [archivename]        Criar um novo pacote
- vcpkg owns <pat>      Pesquisar arquivos em pacotes instalados
- vcpkg cache           Lista pacotes compilados em cache
- vcpkg version         Exibe informações de versão
- vcpkg contact         Exibe informações de contato para enviar comentários

### <a name="options"></a>Opções:
  **`--triplet <t>`** Especificar o tripleto da arquitetura de destino. (padrão: `%VCPKG_DEFAULT_TRIPLET%`, consulte também `vcpkg help triplet`)

  **`--vcpkg-root <path>`** Especificar o diretório raiz do vcpkg (padrão: `%VCPKG_ROOT%`)
