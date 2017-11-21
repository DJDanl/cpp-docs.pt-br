---
title: "Visão geral do MSBuild (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: MSBuild overview
ms.assetid: dd258f6f-ab51-48d9-b274-f7ba911d05ca
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 2c238aabdfee5de1896e24934edee1ebec135be4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="msbuild-visual-c-overview"></a>Visão geral de MSBuild (Visual C++)  
  
MSBuild é o padrão de criar o sistema para projetos do Visual C++. Quando você compila um projeto no ambiente de desenvolvimento integrado (IDE) do Visual Studio, ele usa a ferramenta msbuild.exe, um arquivo de projeto com base em XML e arquivos de configuração opcional. Embora você possa usar msbuild.exe e um arquivo de projeto na linha de comando, o IDE fornece uma interface de usuário para que você pode definir as configurações e compilar um projeto mais facilmente. Esta visão geral descreve como o Visual C++ usa o sistema do MSBuild.  
  
## <a name="prerequisites"></a>Pré-requisitos  
  
Leia os documentos a seguir sobre o MSBuild.  
  
- [MSBuild](/visualstudio/msbuild/msbuild)  
 Visão geral dos conceitos do MSBuild.  
  
- [Referência do MSBuild](/visualstudio/msbuild/msbuild-reference)  
 Informações de referência sobre o sistema do MSBuild.  
  
- [Referência do esquema de arquivos de projeto](/visualstudio/msbuild/msbuild-project-file-schema-reference)  
 Lista os elementos de esquema de XML do MSBuild, junto com seus atributos e elementos pai e filho. Observe especialmente o [ItemGroup](/visualstudio/msbuild/itemgroup-element-msbuild), [PropertyGroup](/visualstudio/msbuild/propertygroup-element-msbuild), [destino](/visualstudio/msbuild/target-element-msbuild), e [tarefa](/visualstudio/msbuild/task-element-msbuild) elementos.  
  
- [Referência de linha de comando](/visualstudio/msbuild/msbuild-command-line-reference)  
 Descreve as opções que você pode usar com o msbuild.exe e argumentos de linha de comando.  
  
- [Referência de tarefas](/visualstudio/msbuild/msbuild-task-reference)  
 Descreve as tarefas do MSBuild. Observe especialmente essas tarefas, que são específicas para o Visual C++: [tarefa BscMake](/visualstudio/msbuild/bscmake-task), [tarefa CL](/visualstudio/msbuild/cl-task), [tarefa CPPClean](/visualstudio/msbuild/cppclean-task), [tarefa LIB](/visualstudio/msbuild/lib-task), [Vincular tarefa](/visualstudio/msbuild/link-task), [tarefa MIDL](/visualstudio/msbuild/midl-task), [tarefa MT](/visualstudio/msbuild/mt-task), [tarefa RC](/visualstudio/msbuild/rc-task), [tarefa SetEnv](/visualstudio/msbuild/setenv-task), [ Tarefa VCMessage](/visualstudio/msbuild/vcmessage-task), [tarefa XDCMake](/visualstudio/msbuild/xdcmake-task), [tarefa XSD](/visualstudio/msbuild/xsd-task).  
  
## <a name="msbuild-on-the-command-line"></a>MSBuild na linha de comando  
  
A instrução a seguir do [referência de linha de comando do MSBuild](/visualstudio/msbuild/msbuild-command-line-reference) ilustra que a ferramenta msbuild.exe leva um implícita ou explícita *project_file* argumento (um arquivo. vcxproj para projetos do Visual C++) e zero ou mais de linha de comando *opções* argumentos.  
  
> **MSBuild.exe** [ *project_file* ] [ *opções* ]  
  
Use o **/destino** (ou **/t**) e **/property** (ou **/p**) opções de linha de comando para substituir propriedades específicas e destinos especificado no arquivo de projeto.  
  
É uma função essencial do arquivo do projeto especificar um *destino*, que é uma operação específica aplicada ao seu projeto e as entradas e saídas que são necessárias para executar essa operação. Um arquivo de projeto pode especificar um ou mais destinos, que podem incluir um destino padrão.  
  
Cada destino consiste em uma sequência de um ou mais *tarefas*. Cada tarefa é representada por uma classe do .NET Framework que contém um comando executável. Por exemplo, o [tarefa CL](/visualstudio/msbuild/cl-task) contém o [cl.exe](../build/reference/compiling-a-c-cpp-program.md) comando.  
  
Um *parâmetro de tarefa* é uma propriedade da tarefa de classe e normalmente representa uma opção de linha de comando do comando executável. Por exemplo, o `FavorSizeOrSpeed` parâmetro o `CL` tarefa corresponde ao **/Os** e **/Ot** opções do compilador.  
  
Parâmetros de tarefa adicional oferecem suporte a infraestrutura do MSBuild. Por exemplo, o `Sources` tarefa especifica um conjunto de tarefas que podem ser consumidos por outras tarefas. Para obter mais informações sobre tarefas do MSBuild, consulte [referência à tarefa](/visualstudio/msbuild/msbuild-task-reference).  
  
A maioria das tarefas exigem entradas e saídas, tais como a cadeia de caracteres, numéricos ou booleanos parâmetros, caminhos e nomes de arquivo. Por exemplo, uma entrada comum é o nome de um arquivo de origem. cpp para compilar. Um parâmetro de entrada importante é uma cadeia de caracteres que especifica a configuração de compilação e a plataforma, por exemplo, "Debug\|Win32". Entradas e saídas são especificadas por um ou mais XML definido pelo usuário `Item` elementos contidos em um `ItemGroup` elemento.  
  
Um arquivo de projeto também pode especificar definidos pelo usuário *propriedades* e `ItemDefinitionGroup` *itens*. Propriedades e itens formam pares de nome/valor que podem ser usados como variáveis no build. Define o componente de um par de nome de um *macro*, e o componente de valor declara o *valor macro*. Uma macro de propriedade é acessada por meio de $(*nome*) notação e uma macro de item é acessado usando %(*nome*) notação.  
  
Outros elementos XML em um arquivo de projeto podem testar macros e, em seguida, defina o valor de qualquer macro ou condicionalmente controlar a execução da compilação. Nomes de macro e cadeias de caracteres literais podem ser concatenadas para gerar construções, como um nome de arquivo e caminho. Na linha de comando, o **/property** opção define ou substitui uma propriedade de projeto. Itens não podem ser referenciados na linha de comando.  
  
O sistema MSBuild condicionalmente pode executar um destino antes ou depois de outro destino. Além disso, o sistema pode criar um destino com base em se os arquivos que o destino consome são mais recentes que os arquivos que ele emite.  
  
## <a name="msbuild-in-the-ide"></a>MSBuild no IDE  
  
Quando você define as propriedades do projeto no IDE e, em seguida, salve o projeto, o Visual C++ grava as configurações de projeto para o arquivo de projeto. O arquivo de projeto contém configurações que são exclusivas ao seu projeto, mas ele não contém todas as configurações que são necessários para compilar seu projeto. O arquivo de projeto contém `Import` elementos que incluem uma rede adicionais *arquivos de suporte.* Os arquivos de suporte contém propriedades, destinos e as configurações necessárias para compilar o projeto restantes.  
  
A maioria dos destinos e propriedades nos arquivos de suporte existem somente para implementar o sistema de compilação. Esta seção discute alguns destinos útil e propriedades que podem ser especificados na linha de comando do MSBuild. Para descobrir mais destinos e as propriedades, explore os arquivos nos diretórios de arquivos de suporte.  
  
### <a name="support-file-directories"></a>Diretórios de arquivos de suporte  
  
Por padrão, os arquivos de suporte do Visual C++ primários estão localizados nos seguintes diretórios. Os diretórios no Microsoft Visual Studio são usados pelo Visual Studio de 2017 e versões posteriores, enquanto os diretórios sob o MSBuild são usados pelo Visual Studio 2015 e versões anteriores.  
  
|Diretório|Descrição|  
|---------------|-----------------|  
|*unidade*: \Program Files *(x86)*\Microsoft Visual Studio\\*ano*\\*edição*\Common7\IDE\VC\VCTargets\ <br /><br />*unidade*: \Program Files *(x86)*\MSBuild\Microsoft.Cpp (x86) \v4.0\\*versão*\ |Contém os arquivos de destino principal (. targets) e arquivos de propriedade (.props) que são usados pelos destinos. Por padrão, a macro $(VCTargetsPath) faz referência a esse diretório.|  
|*unidade*: \Program Files *(x86)*\Microsoft Visual Studio\\*ano*\\*edição*\Common7\IDE\VC\VCTargets\ Plataformas\\*plataforma*\ <br /><br />*unidade*: \Program Files *(x86)*\MSBuild\Microsoft.Cpp\v4.0\\*versão*\Platforms\\*plataforma*\ |Contém os arquivos de destino e a propriedade específica de plataforma que substituem os destinos e as propriedades na sua pasta pai. Este diretório contém também uma DLL que define as tarefas que são usadas por destinos neste diretório.<br /><br /> O *plataforma* espaço reservado representa o ARM, Win32 ou x64 subdiretório.|  
|*unidade*: \Program Files *(x86)*\Microsoft Visual Studio\\*ano*\\*edição*\Common7\IDE\VC\VCTargets\ Plataformas\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\ <br /><br />*unidade*: \Program Files *(x86)*\MSBuild\Microsoft.Cpp\v4.0\\*versão*\Platforms\\*plataforma*\ PlatformToolsets\\*conjunto de ferramentas*\ <br /><br />*unidade*: \Program Files *(x86)*\MSBuild\Microsoft.Cpp\v4.0\Platforms\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\ |Contém os diretórios que permitem a compilação gerar aplicativos Visual C++ usando especificado *toolset*.<br /><br /> O *ano* e *edição* espaços reservados são usados pelo Visual Studio de 2017 e edições posteriores. O *versão* espaço reservado é V110 para Visual Studio 2012, V120 para Visual Studio 2013 ou V140 para Visual Studio 2015. O *plataforma* espaço reservado representa o ARM, Win32 ou x64 subdiretório. O *toolset* espaço reservado representa o subdiretório do conjunto de ferramentas, por exemplo, v140 para a criação de aplicativos do Windows usando o conjunto de ferramentas do Visual Studio 2015, v120_xp para criar para o Windows XP usando o conjunto de ferramentas do Visual Studio 2013 ou v110_wp80 para Crie aplicativos do Windows Phone 8.0, usando o conjunto de ferramentas do Visual Studio 2012.<br /><br />O caminho que contém os diretórios que permitem a compilação gerar aplicativos Visual C++ 2008 ou Visual C++ 2010 não inclui o *versão*e o *plataforma* espaço reservado representa o Itanium, Win32 ou x64 subdiretório. O *toolset* espaço reservado representa o subdiretório v90 ou v100 do conjunto de ferramentas.|  
  
### <a name="support-files"></a>Arquivos de suporte  
  
Os diretórios de arquivos de suporte contém arquivos com essas extensões:  
  
|Extensão|Descrição|  
|---------------|-----------------|  
|. targets|Contém `Target` elementos XML que especificam as tarefas que são executadas pelo destino. Também pode conter `PropertyGroup`, `ItemGroup`, `ItemDefinitionGroup`, definidas pelo usuário `Item` elementos que são usados para atribuir os arquivos e as opções de linha de comando para os parâmetros da tarefa.<br /><br /> Para obter mais informações, consulte [elemento Target (MSBuild)](/visualstudio/msbuild/target-element-msbuild).|  
|.Props|Contém `Property Group` e definidas pelo usuário `Property` elementos XML que especificam as configurações de arquivo e parâmetros que são usadas durante uma compilação.<br /><br /> Também pode conter `ItemDefinitionGroup` e definidas pelo usuário `Item` elementos XML que especificar configurações adicionais. Itens definidos em um grupo de definição do item se parecem com propriedades, mas não podem ser acessados a partir da linha de comando. Arquivos de projeto do Visual C++ usa com frequência itens em vez de propriedades para representar as configurações.<br /><br /> Para obter mais informações, consulte [elemento ItemGroup (MSBuild)](/visualstudio/msbuild/itemgroup-element-msbuild), [elemento ItemDefinitionGroup (MSBuild)](/visualstudio/msbuild/itemdefinitiongroup-element-msbuild), e [elemento Item (MSBuild)](/visualstudio/msbuild/item-element-msbuild).|  
|. XML|Contém elementos XML que declarar e inicializar os elementos de interface de usuário do IDE como folhas de propriedades e páginas de propriedade e os controles de caixa de lista e caixa de texto.<br /><br /> Os arquivos. XML diretamente suportam o IDE não MSBuild. No entanto, os valores das propriedades IDE são atribuídos para criar propriedades e itens.<br /><br /> A maioria dos arquivos. XML estão em um subdiretório específico de localidade. Por exemplo, os arquivos para a região do inglês-EUA estão em $(VCTargetsPath) \1033\\.|  
  
## <a name="user-targets-and-properties"></a>Propriedades e os destinos de usuário  
  
Para usar o MSBuild com mais eficiência na linha de comando, é útil para saber quais propriedades e os destinos são úteis e relevantes. A maioria das propriedades e destinos ajudam a implementar o sistema de compilação do Visual C++ e, consequentemente, não são relevantes para o usuário. Esta seção descreve algumas propriedades vale a pena orientado ao usuário e destinos.  

### <a name="platformtoolset-property"></a>Propriedade PlatformToolset  
  
O `PlatformToolset` propriedade determina qual conjunto de ferramentas do Visual C++ é usado na compilação. Por padrão, o conjunto de ferramentas atual é usado. Quando essa propriedade for definida, o valor da propriedade é concatenado com cadeias de caracteres literal para formar o caminho de um diretório que contém os arquivos de propriedade e de destino que são necessários para compilar um projeto para uma plataforma específica. O conjunto de ferramentas de plataforma deve ser instalado para criar usando essa versão do conjunto de ferramentas de plataforma.  
  
Por exemplo, definir a `PlatformToolset` propriedade `v140` usar ferramentas do Visual C++ 2015 e bibliotecas para criar seu aplicativo:  
  
`msbuild myProject.vcxproj /p:PlatformToolset=v140`  
  
### <a name="preferredtoolarchitecture-property"></a>Propriedade PreferredToolArchitecture  
  
O `PreferredToolArchitecture` propriedade determina se o compilador de 32 bits ou 64 bits e as ferramentas são usadas na compilação. Essa propriedade não afeta a configuração ou a arquitetura da plataforma de saída. Por padrão, o MSBuild usa x86 versão do compilador e ferramentas se essa propriedade não está definida.  
  
Por exemplo, definir a `PreferredToolArchitecture` propriedade `x64` para usar o compilador de 64 bits e as ferramentas para criar seu aplicativo:  
  
`msbuild myProject.vcxproj /p:PreferredToolArchitecture=x64`  
  
### <a name="useenv-property"></a>Propriedade UseEnv  
  
Por padrão, as configurações específicas de plataforma para o projeto atual substituem as variáveis de ambiente PATH, INCLUDE, LIB, LIBPATH, configuração e plataforma. Definir o `UseEnv` propriedade `true` para garantir que as variáveis de ambiente não são substituídas.  
  
`msbuild myProject.vcxproj /p:UseEnv=true`  
  
### <a name="targets"></a>Destinos  
  
Há centenas de destinos em arquivos de suporte do Visual C++. No entanto, a maioria são destinos orientado pelo sistema que o usuário pode ignorar. A maioria dos destinos de sistema são precedidos por um sublinhado (_) ou tem um nome que começa com "PrepareFor", "Computação", "Antes", "Depois", "Pre" ou "Post".  
  
A tabela a seguir lista vários destinos útil orientado ao usuário.  
  
|Destino|Descrição|  
|------------|-----------------|  
|BscMake|Executa a ferramenta de manutenção informações Microsoft procurar utilitário bscmake.exe.|  
|Build|Compila o projeto.<br /><br /> Este é o destino padrão para um projeto.|  
|ClCompile|Executa a ferramenta do compilador Visual C++, cl.exe.|  
|Limpar|Criar arquivos de exclusões temporárias e intermediárias.|  
|Lib|Executa a ferramenta Gerenciador de biblioteca da Microsoft de 32 bits, lib.exe.|  
|Link|Executa a ferramenta de vinculador do Visual C++, link.exe.|  
|ManifestResourceCompile|Extrai uma lista de recursos de um manifesto e, em seguida, executa a ferramenta do compilador de recurso do Microsoft Windows, rc.exe.|  
|MIDL|Executa a ferramenta do compilador de linguagem de definição de Interface da Microsoft (MIDL), midl.exe.|  
|recriar|Limpa e compila seu projeto.|  
|ResourceCompile|Executa a ferramenta do compilador de recurso do Microsoft Windows, rc.exe.|  
|XdcMake|Executa a ferramenta de documentação XML, xdcmake.exe.|  
|XSD|Executa a ferramenta de definição de esquema XML, xsd.exe.|  
  
## <a name="see-also"></a>Consulte também  
  
[MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)
