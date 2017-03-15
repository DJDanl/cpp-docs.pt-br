---
title: "Vis&#227;o geral de MSBuild (Visual C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "visão geral MSBuild"
ms.assetid: dd258f6f-ab51-48d9-b274-f7ba911d05ca
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vis&#227;o geral de MSBuild (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O MSBuild é o padrão de sistema de criação para projetos do Visual C++. Quando você cria um projeto no ambiente de desenvolvimento integrado (IDE) do Visual Studio, ele usa a ferramenta msbuild.exe, um arquivo de projeto baseado em XML e arquivos de configurações opcionais. Embora você possa usar msbuild.exe e um arquivo de projeto na linha de comando, o IDE fornece uma interface do usuário para que você pode definir as configurações e compilar um projeto mais facilmente. Esta visão geral descreve como o Visual C++ usa o sistema MSBuild.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Leia os documentos a seguir sobre o MSBuild.  
  
 [MSBuild](MSBuild1.md)  
 Visão geral dos conceitos do MSBuild.  
  
 [Referência do MSBuild](../Topic/MSBuild%20Reference.md)  
 Informações de referência sobre o sistema MSBuild.  
  
 [Referência do esquema de arquivo de projeto](../Topic/MSBuild%20Project%20File%20Schema%20Reference.md)  
 Lista os elementos de esquema XML de MSBuild, juntamente com seus atributos e elementos pai e filho. Observe principalmente a [ItemGroup](../Topic/ItemGroup%20Element%20\(MSBuild\).md), [PropertyGroup](../Topic/PropertyGroup%20Element%20\(MSBuild\).md), [destino](../Topic/Target%20Element%20\(MSBuild\).md), e [tarefa](../Topic/Task%20Element%20\(MSBuild\).md) elementos.  
  
 [Referência de linha de comando](../Topic/MSBuild%20Command-Line%20Reference.md)  
 Descreve as opções que você pode usar com msbuild.exe e argumentos de linha de comando.  
  
 [Referência de tarefas](../Topic/MSBuild%20Task%20Reference.md)  
 Descreve tarefas do MSBuild. Observe principalmente essas tarefas, que são específicas para o Visual C++: [tarefa BscMake](../Topic/BscMake%20Task.md), [tarefa CL](../Topic/CL%20Task.md), [tarefa CPPClean](../Topic/CPPClean%20Task.md), [tarefa LIB](../Topic/LIB%20Task.md), [tarefa Link](../Topic/Link%20Task.md), [tarefa MIDL](../Topic/MIDL%20Task.md), [tarefa MT](../Topic/MT%20Task.md), [tarefa RC](../Topic/RC%20Task.md), [tarefa SetEnv](../Topic/SetEnv%20Task.md), [tarefa VCMessage](../Topic/VCMessage%20Task.md), [tarefa XDCMake](../Topic/XDCMake%20Task.md), [tarefa XSD](../Topic/XSD%20Task.md).  
  
## <a name="msbuild-on-the-command-line"></a>MSBuild na linha de comando  
 A seguinte instrução do [referência de linha de comando](../Topic/MSBuild%20Command-Line%20Reference.md) documento ilustra que a ferramenta msbuild.exe leva um implícita ou explícita `project file` argumento (um arquivo. vcxproj para projetos do Visual C++) e zero ou mais de linha de comando `options`.  
  
 **msbuild.exe [** `project file` **] [** `options` **]**  
  
 Use o **/destino** (ou **/t**) e **/property** (ou **/p**) opções de linha de comando para substituir as propriedades e os destinos são especificados no arquivo de projeto.  
  
 É uma função essencial do arquivo de projeto especificar um *destino*, que é uma operação específica aplicada ao seu projeto e as entradas e saídas que são necessárias para executar essa operação. Um arquivo de projeto pode especificar um ou mais destinos, que podem incluir um destino padrão.  
  
 Cada destino consiste em uma sequência de um ou mais *tarefas*. Cada tarefa é representada por uma classe do .NET Framework que contém um comando executável. Por exemplo, o [tarefa CL](../Topic/CL%20Task.md) contém o [cl.exe](../build/reference/compiling-a-c-cpp-program.md) comando.  
  
 Um *parâmetro de tarefa* é uma propriedade da tarefa de classe e normalmente representa uma opção de linha de comando do comando executável. Por exemplo, o `FavorSizeOrSpeed` parâmetro o `CL` tarefa corresponde ao **/Os** e **/Ot** Opções do compilador.  
  
 Parâmetros de tarefa adicional dar suporte à infraestrutura do MSBuild. Por exemplo, o `Sources` tarefa parâmetro especifica um conjunto de tarefas que podem ser consumidos por outras tarefas. Para obter mais informações sobre tarefas do MSBuild, consulte [referência à tarefa](../Topic/MSBuild%20Task%20Reference.md).  
  
 A maioria das tarefas exigem entradas e saídas, como nomes de arquivos, caminhos e cadeia de caracteres, parâmetros numéricos ou booleanos. Por exemplo, uma entrada comum é o nome de um arquivo de origem. cpp para compilar. Um parâmetro de entrada importante é uma cadeia de caracteres que especifica a configuração de compilação e a plataforma, por exemplo, "Debug &#124; Win32 ". Entradas e saídas são especificadas por um ou mais XML definidos pelo usuário `Item` elementos contidos em um `ItemGroup` elemento.  
  
 Um arquivo de projeto também pode especificar definidos pelo usuário *propriedades* e *item de definição de grupo**itens*. Propriedades e itens formam pares nome/valor que podem ser usados como variáveis na compilação. O componente de nome de um par define um *macro*, e o componente de valor declara o *valor da macro*. Uma macro de propriedade é acessada por meio de $(*nome*) notação e uma macro de item é acessado usando %(*nome*) notação.  
  
 Outros elementos XML em um arquivo de projeto podem testar macros e, em seguida, condicionalmente definir o valor de qualquer macro ou controlar a execução da compilação. Nomes de macro e cadeias de caracteres literais podem ser concatenadas para gerar construções como um nome de arquivo e caminho. Na linha de comando, o **/property** opção define ou substitui uma propriedade do projeto. Itens não podem ser referenciados na linha de comando.  
  
 O sistema MSBuild pode executar condicionalmente um destino antes ou depois de outro destino. Além disso, o sistema pode criar um destino com base em se os arquivos que consome o destino são mais recentes que os arquivos que ele emite.  
  
## <a name="msbuild-in-the-ide"></a>MSBuild no IDE  
 Quando você define propriedades do projeto no IDE e, em seguida, salve o projeto, Visual C++ grava as configurações do projeto para o arquivo de projeto. O arquivo de projeto contém configurações que são exclusivas ao seu projeto, mas não contém todas as configurações que são necessárias para criar seu projeto. O arquivo de projeto contém `Import` elementos que incluem uma rede de outros *arquivos de suporte.* Os arquivos de suporte contêm propriedades, destinos e as configurações necessárias para compilar o projeto restantes.  
  
 A maioria dos destinos e propriedades nos arquivos de suporte existem somente para implementar o sistema de compilação. A seção a seguir aborda alguns destinos útil e propriedades que podem ser especificados na linha de comando do MSBuild. Para descobrir mais destinos e as propriedades, explore os arquivos nos diretórios de arquivos de suporte.  
  
### <a name="support-file-directories"></a>Diretórios de arquivos de suporte  
 Por padrão, os arquivos de suporte do Visual C++ primários estão localizados nos seguintes diretórios.  
  
|Diretório|Descrição|  
|---------------|-----------------|  
|*unidade*: \Program Files\MSBuild\Microsoft.Cpp\v4.0\\*versão*\|Contém os arquivos de destino principal (. targets) e arquivos de propriedade (. Props) que são usados pelos destinos. Por padrão, a macro $(VCTargetsPath) faz referência a esse diretório.|  
|*unidade*: \Program Files\MSBuild\Microsoft.Cpp\v4.0\\*versão*\Platforms\\*plataforma*\|Contém arquivos específicos de plataforma de destino e a propriedade que substituem os destinos e as propriedades em seu diretório pai. Essa pasta também contém um arquivo. dll que define as tarefas que são usadas por destinos neste diretório.<br /><br /> O *plataforma* espaço reservado representa o `ARM`, `Win32`, ou `x64` subdiretório.|  
|*unidade*: \Program Files\MSBuild\Microsoft.Cpp\v4.0\\*versão*\Platforms\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\|Contém os diretórios que permitem a compilação gerar aplicativos Visual C++ com especificado *versão* do conjunto de ferramentas.<br /><br /> O *plataforma* espaço reservado representa o `ARM`, `Win32`, ou `x64` subdiretório. O *toolset* espaço reservado representa o subdiretório do conjunto de ferramentas para criar aplicativos Windows, Windows XP ou Windows Phone.|  
|*unidade*: \Program Files\MSBuild\Microsoft.Cpp\v4.0\Platforms\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\|Contém os diretórios que permitem a compilação gerar 9.0 ou aplicativos Visual C++ 10.0.<br /><br /> O *plataforma* espaço reservado representa o `Itanium`, `Win32`, ou `x64` subdiretório. O *toolset* espaço reservado representa a `v90` ou `v100` subdiretório do conjunto de ferramentas.|  
  
### <a name="support-files"></a>Arquivos de suporte  
 Os diretórios de arquivos de suporte contém arquivos com as seguintes extensões.  
  
|Extensão|Descrição|  
|---------------|-----------------|  
|. targets|Contém `Target` elementos XML que especificam as tarefas que são executadas pelo destino. Também pode conter `Property Group`, `Item Group`, `Item Definition Group`, e definidas pelo usuário `Item` elementos que são usados para atribuir arquivos e opções de linha de comando para parâmetros de tarefa.<br /><br /> Para obter mais informações, consulte [elemento Target (MSBuild)](../Topic/Target%20Element%20\(MSBuild\).md).|  
|. Props|Contém `Property Group` e definidas pelo usuário `Property` elementos XML que especificam as configurações de arquivo e de parâmetro são usadas durante a compilação.<br /><br /> Também pode conter `Item Definition Group` e definidas pelo usuário `Item` elementos XML que especificar configurações adicionais. Itens definidos em um grupo de definição de item se parecem com propriedades, mas não podem ser acessados a partir da linha de comando. Arquivos de projeto do Visual C++ usa com frequência itens em vez de propriedades para representar as configurações.<br /><br /> Para obter mais informações, consulte [elemento ItemGroup (MSBuild)](../Topic/ItemGroup%20Element%20\(MSBuild\).md), [elemento ItemDefinitionGroup (MSBuild)](../Topic/ItemDefinitionGroup%20Element%20\(MSBuild\).md), e [elemento Item (MSBuild)](../Topic/Item%20Element%20\(MSBuild\).md).|  
|. XML|Contém elementos XML que declarar e inicializar os elementos de interface de usuário do IDE, como folhas de propriedades e páginas de propriedade e os controles de caixa de lista e de caixa de texto.<br /><br /> Os arquivos. XML oferece suporte diretamente a IDE, não o MSBuild. No entanto, os valores das propriedades do IDE são atribuídos para itens e as propriedades de compilação.<br /><br /> A maioria dos arquivos. XML estão em um subdiretório específico da localidade. Por exemplo, os arquivos para a região do inglês-EUA estão em $(VCTargetsPath) \1033\\.|  
  
## <a name="user-targets-and-properties"></a>Metas de usuário e propriedades  
 Para usar o MSBuild com mais eficiência na linha de comando, é útil para saber quais propriedades e os destinos são úteis e relevantes. A maioria das propriedades e destinos de ajudar a implementar o sistema de compilação do Visual C++ e, consequentemente, não são relevantes para o usuário. Esta seção descreve algumas propriedades vale a pena orientado por usuário e destinos.  
  
### <a name="platformtoolset-property"></a>Propriedade PlatformToolset  
 O `PlatformToolset` propriedade determina qual conjunto de ferramentas do Visual C++ é usado na compilação. O valor da propriedade é concatenado com cadeias de caracteres literais para formar o caminho de um diretório que contém os arquivos de propriedade e de destino que são necessárias para criar um projeto para uma plataforma específica.  
  
 Definir o `PlatformToolset` propriedade `v110` usar [!INCLUDE[cpp_dev11_long](../build/includes/cpp_dev11_long_md.md)] Ferramentas e bibliotecas para criar seu aplicativo.  
  
 `msbuild myProject.vcxproj /p:PlatformToolset=v110`  
  
 Definir o `PlatformToolset` propriedade `v100` usar [!INCLUDE[cpp_dev10_long](../Token/cpp_dev10_long_md.md)] Ferramentas e bibliotecas para criar seu aplicativo.  
  
 `msbuild myProject.vcxproj /p:PlatformToolset=v100`  
  
 Definir o `PlatformToolset` propriedade `v90` usar ferramentas do Visual C++ 2008 e bibliotecas para criar seu aplicativo. O conjunto de ferramentas do Visual C++ 2008 já deve estar instalado no computador para que essa propriedade seja eficaz.  
  
 `msbuild myProject.vcxproj /p:PlatformToolset=v90`  
  
### <a name="preferredtoolarchitecture-property"></a>Propriedade PreferredToolArchitecture  
 O `PreferredToolArchitecture` propriedade determina se o compilador de 32 bits ou 64 bits e ferramentas são usadas na compilação. Essa propriedade não afeta a configuração ou a arquitetura da plataforma de saída. Por padrão, MSBuild usa o x86 versão do compilador e de ferramentas se essa propriedade não está definida ou é definida como qualquer valor diferente de `x64`.  
  
 Definir o `PreferredToolArchitecture` propriedade `x64` usar o compilador de 64 bits e ferramentas para criar seu aplicativo.  
  
 `msbuild myProject.vcxproj /p:PreferredToolArchitecture=x64`  
  
### <a name="useenv-property"></a>Propriedade UseEnv  
 Por padrão, as configurações específicas da plataforma para o projeto atual substituem as variáveis de ambiente PATH, INCLUDE, LIB, LIBPATH, CONFIGURAÇÃO e PLATAFORMA. Definir o `UseEnv` propriedade `true` para garantir que as variáveis de ambiente não são substituídas.  
  
 `msbuild myProject.vcxproj /p:UseEnv=true`  
  
### <a name="targets"></a>Destinos  
 Há centenas de destinos nos arquivos de suporte do Visual C++. No entanto, a maioria são orientados por sistemas destinos que o usuário pode ignorar. A maioria dos destinos de sistema são precedidos por um sublinhado (_), ou tem um nome que começa com "PrepareFor", "Computação", "Antes", "Depois", "Pre" ou "Post".  
  
 A tabela a seguir lista vários destinos vale a pena orientado por usuário.  
  
|Destino|Descrição|  
|------------|-----------------|  
|BscMake|Executa a ferramenta de manutenção informações Microsoft procurar utilitário bscmake.exe.|  
|Build|Compila o projeto.<br /><br /> Isso é o destino padrão para um projeto.|  
|ClCompile|Executa a ferramenta de compilador do Visual C++, cl.exe.|  
|Limpar|Criar arquivos de exclusões temporárias e de nível intermediárias.|  
|Lib|Executa a ferramenta Gerenciador de biblioteca da Microsoft de 32 bits, lib.exe.|  
|Link|Executa a ferramenta do Vinculador Visual C++, link.exe.|  
|ManifestResourceCompile|Extrai uma lista de recursos de um manifesto e, em seguida, executa a ferramenta de compilador de recurso do Microsoft Windows, rc.exe.|  
|MIDL|Executa a ferramenta de compilador Microsoft Interface Definition Language (MIDL), midl.exe.|  
|Reconstrução|Limpa e compila seu projeto.|  
|ResourceCompile|Executa a ferramenta de compilador de recurso do Microsoft Windows, rc.exe.|  
|XdcMake|Executa a ferramenta de documentação XML, xdcmake.exe.|  
|XSD|Executa a ferramenta de definição de esquema XML, xsd.exe.|  
  
## <a name="see-also"></a>Consulte também  
 [MSBuild (Visual C++)](../Topic/MSBuild%20\(Visual%20C++\).md)