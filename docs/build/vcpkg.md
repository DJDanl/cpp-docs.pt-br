---
title: 'vcpkg: um gerenciador de pacotes C++ para Windows, Linux e MacOS'
description: O vcpkg é um gerenciador de pacotes de linha de comando que simplifica muito a aquisição e instalação de bibliotecas C++ de código aberto no Windows, MacOS e Linux.
ms.date: 01/10/2020
ms.technology: cpp-ide
ms.assetid: f50d459a-e18f-4b4e-814b-913e444cedd6
ms.openlocfilehash: 9dbeba1f55164ace01fb8bb26155dd9319ba62db
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335402"
---
# <a name="vcpkg-a-c-package-manager-for-windows-linux-and-macos"></a>vcpkg: um gerenciador de pacotes C++ para Windows, Linux e MacOS

vcpkg é um gerenciador de pacotes de linha de comando para C++. Simplifica muito a aquisição e instalação de bibliotecas de terceiros no Windows, Linux e MacOS. Se seu projeto usa bibliotecas de terceiros, é recomendável que você use o vcpkg para instalá-las. O vcpkg dá suporte a bibliotecas de software livre e proprietárias. Todas as bibliotecas do catálogo do vcpkg no Windows foram testadas quanto à compatibilidade com o Visual Studio 2015, o Visual Studio 2017 e o Visual Studio 2019. Entre os catálogos Windows e Linux/MacOS, o vcpkg agora suporta mais de 1900 bibliotecas. A comunidade do C++ é adicionando mais bibliotecas a ambos os catálogos de forma contínua.

## <a name="simple-yet-flexible"></a>Simples e flexível

Com um único comando, você pode baixar fontes e compilar uma biblioteca. O próprio vcpkg é um projeto de software livre disponível no GitHub. É possível personalizar seus clones vcpkg privados da maneira que você quiser. Por exemplo, especifique bibliotecas diferentes ou versões diferentes das encontradas no catálogo público. Você pode ter vários clones de vcpkg em uma única máquina. Cada uma pode ser definida para produzir uma coleção personalizada de bibliotecas, com seus switches de compilação preferidos. Cada clone é um ambiente autocontido, com sua própria cópia do vcpkg.exe que funciona apenas em sua própria hierarquia. o vcpkg não é adicionado a nenhuma variável de ambiente e não tem dependência do Registro do Windows ou do Visual Studio.

## <a name="sources-not-binaries"></a>Fontes, não binários

Para bibliotecas no catálogo do Windows, o vcpkg baixa fontes em vez de binários<sup>1</sup>. Ele compila essas fontes usando a versão mais recente do Visual Studio que ele possa encontrar. No C++, é importante que tanto o código do aplicativo quanto as bibliotecas que você usa sejam compilados pelo mesmo compilador e versão do compilador. Ao usar o vcpkg, você elimina ou, pelo menos, reduz bastante o potencial de binários não correspondentes e os problemas que eles podem causar. Em equipes padronizadas em uma versão específica de um compilador, um membro da equipe pode usar vcpkg para baixar fontes e compilar um conjunto de binários. Em seguida, eles podem usar o comando de exportação para fechar os binários e cabeçalhos para outros membros da equipe. Para obter mais informações, confira abaixo [Exportação de binários compilados e cabeçalhos](#export_binaries_per_project).

Você também pode criar um clone vcpkg que tem bibliotecas privadas na coleção de portas. Adicione uma porta que baixe seus binários e cabeçalhos pré-construídos. Em seguida, escreva um arquivo portfile.cmake que simplesmente copia esses arquivos para o local preferido.

<sup>1</sup> *Nota: as fontes não estão disponíveis para algumas bibliotecas proprietárias. Nestes casos, o vcpkg baixa binários pré-construídos compatíveis.*

## <a name="installation"></a>Instalação

Clone o repo vcpkg do [https://github.com/Microsoft/vcpkg](https://github.com/Microsoft/vcpkg)GitHub: . Você pode baixar em qualquer local de pasta que você preferir.

Execute o bootstrapper na pasta raiz:

- **bootstrap-vcpkg.bat** (Windows)
- **./bootstrap-vcpkg.sh** (Linux, MacOS)

## <a name="search-the-list-of-available-libraries"></a>Pesquisar a lista de bibliotecas disponíveis

Para ver quais pacotes estão disponíveis, no prompt de comando digite: **vcpkg search**

Este comando enumera os arquivos de controle nas subpastas vcpkg/portas. Você verá uma listagem como esta:

```cmd
ace       6.4.3   The ADAPTIVE Communication Environment
anax      2.1.0-1 An open source C++ entity system. \<https://github...
antlr4    4.6-1   ANother Tool for Language Recognition
apr       1.5.2   The Apache Portable Runtime (APR) is a C library ...
asio      1.10.8  Asio is a cross-platform C++ library for network ...
assimp    3.3.1   The Open Asset import library
atk       2.24.0  GNOME Accessibility Toolkit
...
```

Você pode filtrar em um padrão, por exemplo **vcpkg search ta**:

```cmd
botan       2.0.1      A cryptography library written in C++11
portaudio   19.0.6.00  PortAudio Portable Cross-platform Audio I/O API P...
taglib      1.11.1-2   TagLib Audio Meta-Data Library
```

### <a name="install-a-library-on-your-local-machine"></a>Instalar uma biblioteca em seu computador local

Depois de obter o nome de uma biblioteca usando **vcpkg search**, você usa **vcpkg install** para baixar a biblioteca e compilá-la. O vcpkg usa o portfile da biblioteca no diretório de portas. Se nenhum tripleto for especificado, vcpkg instalará e compilará para o tripleto padrão para a plataforma de destino: x86-windows, x64-linux.cmake ou x64-osx.cmake.

Para bibliotecas do Linux, vcpkg depende da instalação do gcc no computador local. No MacOS, o vcpkg usa Clang.

Quando o arquivo de porta especifica dependências, o vcpkg baixa e as instala também. Após o download, o vcpkg constrói a biblioteca usando o mesmo sistema de compilação que a biblioteca usa. Os projetos CMake e (no Windows) MSBuild são preferidos, mas o MAKE é suportado, juntamente com qualquer outro sistema de compilação. Se o vcpkg não conseguir encontrar o sistema de compilação especificado na máquina local, ele o baixa e o instala.

```cmd
> vcpkg install boost:x86-windows

The following packages will be built and installed:
    boost:x86-windows
  * bzip2:x86-windows
  * zlib:x86-windows
Additional packages (*) will be installed to complete this operation.
```

Para projetos do CMAKE, use CMAKE_TOOLCHAIN_FILE para tornar as bibliotecas disponíveis com `find_package()`. Por exemplo:

```cmd
cmake .. -DCMAKE_TOOLCHAIN_FILE=vcpkg/scripts/buildsystems/vcpkg.cmake (Linux/MacOS)
cmake .. -DCMAKE_TOOLCHAIN_FILE=vcpkg\scripts\buildsystems\vcpkg.cmake (Windows)
```

## <a name="list-the-libraries-already-installed"></a>Listar as bibliotecas já instaladas

Depois de instalar algumas bibliotecas, você pode usar a **lista vcpkg** para ver o que você tem:

```cmd
> vcpkg list

boost:x86-windows       1.64-3   Peer-reviewed portable C++ source libraries
bzip2:x86-windows       1.0.6-1  High-quality data compressor.
cpprestsdk:x86-windows  2.9.0-2  C++11 JSON, REST, and OAuth library The C++ REST ...
openssl:x86-windows     1.0.2k-2 OpenSSL is an open source project that provides a...
websocketpp:x86-windows 0.7.0    Library that implements RFC6455 The WebSocket Pro...
zlib:x86-windows        1.2.11   A compression library
```

## <a name="integrate-with-visual-studio-windows"></a>Integrar com o Visual Studio (Windows)

### <a name="per-user"></a>Por usuário

Executar **vcpkg integrar instalar** para configurar o Visual Studio para localizar todos os arquivos de cabeçalho vcpkg e binários em uma base por usuário. Não há necessidade de edição manual dos caminhos dos diretórios VC++. Se você tiver vários clones, o clone de onde você executa este comando se torna o novo local padrão.

Agora você pode #include cabeçalhos simplesmente digitando a pasta/cabeçalho, e a auto-completação ajuda você. Não será necessária nenhuma etapa adicional para vinculação a bibliotecas ou adição de referências de projeto. A ilustração a seguir mostra como o Visual Studio localiza os cabeçalhos azure-storage-cpp. O vcpkg coloca seus cabeçalhos na subpasta **/installed**, particionada pela plataforma de destino. O diagrama a seguir mostra a lista de arquivos de inclusão na subpasta **/was** para a biblioteca:

![vcpkg e IntelliSense](media/vcpkg-intellisense.png "vcpkg e IntelliSense")

### <a name="per-project"></a>Por projeto

Se você precisar usar uma versão específica de uma biblioteca diferente da versão em sua instância ativa do vcpkg, siga estas etapas:

1. Faça uma cópia nova do vcpkg
1. Modifique o portfile para a biblioteca para obter a versão necessária
1. Execute **vcpkg install \<library>**.
1. Use **vcpkg integrate project** para criar um pacote NuGet que faz referência a essa biblioteca com base em cada projeto.

## <a name="integrate-with-visual-studio-code-linuxmacos"></a>Integrar com o Visual Studio Code (Linux/MacOS)

Executar **vcpkg integrar instalar** para configurar visual studio code no Linux/MacOS. Este comando define a localização do alistamento vcpkg e habilita o IntelliSense em arquivos de origem.

## <a name="target-linux-from-windows-via-wsl"></a>Linux de destino do Windows por meio do WSL

Você pode produzir binários Linux em uma máquina Windows usando o Subsistema Windows para Linux, ou WSL. Siga as instruções para [Configurar o WSL no Windows 10](/windows/wsl/install-win10) e configurá-lo com a [extensão do Visual Studio para Linux](https://blogs.msdn.microsoft.com/vcblog/2017/02/08/targeting-windows-subsystem-for-linux-from-visual-studio/). Não há problema em colocar todas as suas bibliotecas construídas para Windows e Linux na mesma pasta. Eles são acessíveis tanto do Windows quanto do WSL.

## <a name="export-compiled-binaries-and-headers"></a><a name="export_binaries_per_project"></a> Exportar binários compilados e cabeçalhos

É ineficiente fazer com que todos em uma equipe baixem e construam bibliotecas comuns. Um único membro da equipe pode usar o comando **vcpkg export** para criar um arquivo zip comum dos binários e cabeçalhos, ou um pacote NuGet. Então, é fácil compartilhá-lo com outros membros da equipe.

## <a name="updateupgrade-installed-libraries"></a>Atualizar bibliotecas instaladas

O catálogo público é mantido atualizado com as versões mais recentes das bibliotecas. Para determinar qual das suas bibliotecas locais está desatualizada, use **vcpkg update**. Quando estiver pronto para atualizar sua coleção de portas para a versão mais recente do catálogo público, execute o comando **vcpkg upgrade.** Ele baixa e reconstrói automaticamente qualquer ou todas as suas bibliotecas instaladas que estão desatualizadas.

Por padrão, o comando **upgrade** lista apenas as bibliotecas desatualizadas; ele não atualizá-los. Para realmente atualizar as bibliotecas, use a opção **--no-dry-run.**

```cmd
  vcpkg upgrade --no-dry-run
```

### <a name="upgrade-options"></a>Opções de atualização

- **--no-dry-run** Executar a atualização, quando não especificado, o comando apenas lista os pacotes desatualizados.
- **--keep-going**  Continuar a instalar pacotes, mesmo se um falhar.
- **--triplet \<t>** Definir o tripleto padrão para pacotes não qualificados.
- **--vcpkg-root \<path>**  Especificar o diretório vcpkg a ser usado em vez do diretório atual ou do diretório da ferramenta.

### <a name="upgrade-example"></a>Exemplo de atualização

O exemplo a seguir mostra como atualizar somente as bibliotecas especificadas. vcpkg puxa automaticamente em dependências, conforme necessário.

```cmd
c:\users\satyan\vcpkg> vcpkg upgrade tiny-dnn:x86-windows zlib
The following packages are up-to-date:
   tiny-dnn:x86-windows

The following packages will be rebuilt:
    * libpng[core]:x86-windows
    * tiff[core]:x86-windows
      zlib[core]:x86-windows
Additional packages (*) will be modified to complete this operation.
If you are sure you want to rebuild the above packages, run this command with the --no-dry-run option.
```

## <a name="contribute-new-libraries"></a>Contribuir com novas bibliotecas

Você pode incluir todas as biblioteca que quiser em sua coleção de portas particulares. Para sugerir uma nova biblioteca para o catálogo público, abra um problema na [página de problemas do vcpkg do GitHub](https://github.com/Microsoft/vcpkg/issues).

## <a name="remove-a-library"></a>Remover uma biblioteca

Digite **vcpkg remove** para remover uma biblioteca instalada. Se outras bibliotecas dependerem disso, é solicitado que você reexecute o comando com **--recurse**, o que faz com que todas as bibliotecas a jusante sejam removidas.

## <a name="customize-vcpkg"></a>Personalizar o vcpkg

Você pode modificar seu clone do vcpkg da maneira que desejar. Você pode até criar vários clones vcpkg e, em seguida, modificar os arquivos de porta em cada um. Essa é uma maneira simples de obter versões específicas da biblioteca ou especificar parâmetros específicos da linha de comando. Por exemplo, em uma empresa, grupos individuais de desenvolvedores podem trabalhar em softwares que têm um conjunto de dependências específicas para seu grupo. A solução é configurar um clone de vcpkg para cada equipe. Em seguida, modifique os clones para baixar as versões da biblioteca e defina os switches de compilação que cada equipe precisa.

## <a name="uninstall-vcpkg"></a>Desinstalar o vcpkg

Basta excluir o diretório vcpkg. A exclusão deste diretório desinstala a distribuição vcpkg e todas as bibliotecas que o vcpkg instalou.

## <a name="send-feedback-about-vcpkg"></a>Enviar comentários sobre o vcpkg

Use o comando **vcpkg contact --survey** para enviar comentários para a Microsoft sobre o vcpkg, incluindo relatórios de bug e sugestões de recursos.

## <a name="the-vcpkg-folder-hierarchy"></a>A hierarquia de pasta do vcpkg

Todas as funcionalidades e os dados do vcpkg são autocontidos em uma única hierarquia de diretórios, chamada de uma "instância". Não há configurações de Registro ou variáveis de ambiente. Você pode ter qualquer número de instâncias de vcpkg em uma máquina, e eles não vão interferir uns com os outros.

O conteúdo de uma instância de vcpkg é:

- buildtrees – contém subpastas de fontes das quais cada biblioteca é compilada
- documentos – documentação e exemplos
- downloads – cópias em cache de quaisquer ferramentas ou fontes baixadas. vcpkg pesquisa aqui primeiro quando você executa o comando instalar.
- instalado – contém os cabeçalhos e os binários de cada biblioteca instalada. Quando você se integra ao Visual Studio, você está essencialmente dizendo que adiciona esta pasta aos seus caminhos de pesquisa.
- pacotes – pasta interna de preparo entre instalações.
- portas – arquivos que descrevem cada biblioteca no catálogo, sua versão e onde baixá-la. Você pode adicionar suas próprias portas se necessário.
- scripts – scripts (cmake, powershell) usados pelo vcpkg.
- toolsrc – código-fonte C++ para vcpkg e componentes relacionados
- tripletos – contém as configurações para cada plataforma de destino com suporte (por exemplo, Windows x86 ou Uwp x64).

## <a name="command-line-reference"></a>Referência de linha de comando

|Comando|Descrição|
|---------|---------|
|**vcpkg \[search pat]**|Pesquisar pacotes disponíveis para instalação|
|**vcpkg install \<pkg>...**|Instalar um pacote|
|**vcpkg remove \<pkg>...**|Desinstalar um pacote|
|**vcpkg remove --outdated**|Desinstalar todos os pacotes desatualizados|
|**vcpkg list**|Listar os pacotes instalados|
|**vcpkg update**|Exibir a lista de pacotes para atualização|
|**vcpkg upgrade**|Recompilar todos os pacotes desatualizados|
|**arquivo hash \<vcpkg> \[alg]**|Realizar hash de um arquivo por algoritmo específico, o padrão é SHA512|
|**vcpkg integrate install**|Tornar pacotes instalados disponíveis a todos os usuários. Exige privilégios administrativos no primeiro uso|
|**vcpkg integrate remove**|Remover a integração de todos os usuários|
|**vcpkg integrate project**|Gerar um pacote NuGet de referência para uso de projeto individual do VS|
|**vcpkg \<exportação pkg>... \[optar]...**|Exportar um pacote|
|**vcpkg edit \<pkg>**|Abrir uma porta para edição (usa %EDITOR%, o “código” padrão)|
|**vcpkg \<criar pkg \< \[> url> nome de arquivo]**|Criar um novo pacote|
|**vcpkg cache**|Listar pacotes compilados armazenados em cache|
|**vcpkg version**|Exibir informações de versão|
|**vcpkg contact --survey**|Exibir informações de contato para enviar comentários.|

### <a name="options"></a>Opções

|Opção|Descrição|
|---------|---------|
|**--triplet \<t>**|Especificar o tripleto da arquitetura de destino. (padrão: `%VCPKG_DEFAULT_TRIPLET%`, veja também **vcpkg help triplet**)|
|**--vcpkg-root \<path>**|Especificar o diretório raiz do vcpkg (padrão: `%VCPKG_ROOT%`)|
