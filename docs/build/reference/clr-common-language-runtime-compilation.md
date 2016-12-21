---
title: "-clr (Common Language Runtime Compilation) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/CLR"
  - "VC.Project.VCNMakeTool.CompileAsManaged"
  - "VC.Project.VCCLCompilerTool.CompileAsManaged"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "compilador cl.exe, opção common language runtime"
  - "Opção de compilador -clr [C++]"
  - "Opção de compilador clr [C++]"
  - "Opção de compilador /clr [C++]"
  - "Extensões gerenciadas para C++, compilação"
  - "Common language runtime, opção de compilador /clr"
ms.assetid: fec5a8c0-40ec-484c-a213-8dec918c1d6c
caps.latest.revision: 72
caps.handback.revision: 72
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /clr (compila&#231;&#227;o do Common Language Runtime)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que aplicativos e componentes para usar os recursos do que o common language runtime \(CLR\).  
  
## Sintaxe  
  
```  
/clr[:options]  
```  
  
## Arguments  
 `options`  
 Uma ou mais das seguintes opções, separados por vírgulas.  
  
 **\/CLR**  
 Cria os metadados para o aplicativo. Os metadados podem ser consumidos por outros aplicativos do CLR e permite que o aplicativo consumir dados nos metadados de outros componentes do CLR e tipos.  
  
 Para saber mais, veja  
  
 [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md) e  
  
 [Como migrar para \/clr](../../dotnet/how-to-migrate-to-clr.md).  
  
 **\/CLR: puro**  
 Produz um Microsoft Intermediate Language \(MSIL\)\-somente o arquivo de saída que não tem nenhum código executável nativo. No entanto, ele pode conter tipos nativos compilados para MSIL.  
  
 Para obter mais informações, consulte [Código puro e verificável](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
 \/CLR: puro foi preterido. Uma versão futura do compilador pode não oferecer suporte a essa opção. É recomendável que você portar o código que deve ser a MSIL puro para c\#.  
  
 **\/CLR: safe**  
 Produz um MSIL somente \(sem executável código nativo\), o arquivo de saída pode ser verificada.**\/CLR: safe** habilita o diagnóstico de verificação \([ferramenta PEVerify \(Peverify.exe\)](../Topic/Peverify.exe%20\(PEVerify%20Tool\).md)\).  
  
 Para obter mais informações, consulte [PONTA: código de tipos seguros verificável escrita](http://msdn.microsoft.com/pt-br/d18f10ef-3b48-4f47-8726-96714021547b).  
  
 \/CLR: safe é preterido. Uma versão futura do compilador pode não oferecer suporte a essa opção. É recomendável que você porta o código que deve ser a MSIL puro, pode ser verificada em c\#.  
  
 **\/CLR:noAssembly**  
 Especifica que um manifesto do assembly não deve ser inserido no arquivo de saída. Por padrão, o **noAssembly** opção não está em vigor.  
  
 O **noAssembly** opção é preterida. Use [\/LN \(criar módulo MSIL\)](../../build/reference/ln-create-msil-module.md) em vez disso.  
  
 Um programa gerenciado que não tem metadados de assembly do manifesto é conhecido como um *módulo*. O **noAssembly** opção pode ser usada somente para produzir um módulo. Se você compilar usando [\/c](../../build/reference/c-compile-without-linking.md) e **\/clr:noAssembly**, em seguida, especifique o [\/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md) opção na fase de vinculador para criar um módulo.  
  
 Antes do Visual C\+\+ 2005, **\/clr:noAssembly** necessária **\/LD**.**\/LD** agora é inferido quando você especificar **\/clr:noAssembly**.  
  
 **\/CLR:initialAppDomain**  
 Permite que um [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] aplicativo para ser executado na versão 1 do CLR. Se você usar **initialAppDomain**, em seguida, você pode ver alguns dos problemas descritos no [BUG: exceção AppDomainUnloaded quando você usa do managed extensions para componentes do Visual C\+\+](http://go.microsoft.com/fwlink/?LinkID=169465) no site de suporte da Microsoft.  
  
 Um aplicativo é compilado usando **initialAppDomain** não deve ser usado por um aplicativo que usa o ASP.NET porque não há suporte na versão 1 do CLR.  
  
 **\/CLR:nostdlib**  
 Instrui o compilador a ignorar o diretório de \\clr padrão. O compilador gera erros se você estiver incluindo várias versões de uma DLL como System. dll. Usando essa opção permite que você especifique a estrutura específica para usar durante a compilação.  
  
## Comentários  
 Código gerenciado é o código que pode ser inspecionado e gerenciado pelo CLR. Código gerenciado pode acessar objetos gerenciados. Para obter mais informações, consulte [\/clr Restrições](../../build/reference/clr-restrictions.md).  
  
 Para obter informações sobre como desenvolver aplicativos que definem e consumam tipos gerenciados, consulte [Component Extensions for Runtime Platforms](../../windows/component-extensions-for-runtime-platforms.md).  
  
 Um aplicativo compilado usando **\/clr** pode ou não pode conter dados gerenciados.  
  
 Para habilitar a depuração em um aplicativo gerenciado, consulte [\/ASSEMBLYDEBUG \(Adicionar DebuggableAttribute\)](../Topic/-ASSEMBLYDEBUG%20\(Add%20DebuggableAttribute\).md).  
  
 Somente os tipos CLR serão instanciados no heap coletado como lixo. Para obter mais informações, consulte [Classes and Structs](../../windows/classes-and-structs-cpp-component-extensions.md). Para compilar uma função para código nativo, use o `unmanaged` pragma. Para obter mais informações, consulte [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md).  
  
 Por padrão, **\/clr** não está em vigor. Quando **\/clr** está em vigor, **\/MD** também está em vigor. Para obter mais informações, consulte [\/MD, \/MT, \/LD \(usar biblioteca em tempo de execução\)](../../build/reference/md-mt-ld-use-run-time-library.md).**\/MD** garante que as versões dinamicamente vinculadas, multithread das rotinas de tempo de execução são selecionadas dos arquivos de cabeçalho padrão \(. h\). Multithreading é necessário para a programação porque o coletor de lixo do CLR executa os finalizadores em um thread auxiliar gerenciada.  
  
 Se você compilar usando **\/c**, você pode especificar o tipo CLR \(IJW, puro ou seguro\) do arquivo de saída resultante com [\/CLRIMAGETYPE](../Topic/-CLRIMAGETYPE%20\(Specify%20Type%20of%20CLR%20Image\).md).  
  
 **\/clr** implica **\/EHa**, e nenhum outro **\/EH** opções têm suporte para **\/clr**. Para obter mais informações, consulte [\/EH \(modelo de tratamento de exceções\)](../../build/reference/eh-exception-handling-model.md).  
  
 Para obter informações sobre como determinar o tipo de imagem CLR de um arquivo, consulte [\/CLRHEADER](../../build/reference/clrheader.md).  
  
 Todos os módulos passados para determinada invocação do vinculador devem ser compilados usando a mesma opção de compilador de biblioteca de tempo de execução \(**\/MD** ou **\/LD**\).  
  
 Use o [\/ASSEMBLYRESOURCE.](../../build/reference/assemblyresource-embed-a-managed-resource.md) opção de vinculador para incorporar um recurso em um assembly.[\/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md), [\/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md), e [\/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md) opções do vinculador também permitem que você personalize como um assembly é criado.  
  
 Quando **\/clr** for usado, o `_MANAGED` símbolo é definido como 1. Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).  
  
 As variáveis globais em um arquivo de objeto nativo são inicializadas primeiro \(durante DllMain se o executável é uma DLL\) e, em seguida, as variáveis globais na seção gerenciada são inicializados \(antes de qualquer código gerenciado é executado\).`#pragma`[init\_seg](../../preprocessor/init-seg.md) só afeta a ordem de inicialização nas categorias gerenciadas e não gerenciadas.  
  
 Compilando com **\/CLR: safe** é análogo ao compilar usando [\/platform:anycpu](../Topic/-platform%20\(C%23%20Compiler%20Options\).md) em linguagens como c\#.  
  
## Imagens puras e seguras  
 Uma imagem pura usa uma versão do CLR da biblioteca C Runtime \(CRT\). No entanto, o CRT não é verificável, é possível usar o CRT quando você compila usando **\/CLR: safe**. Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
 Exemplos de código nativo que não podem aparecer em uma imagem pura assembly embutido, [setjmp](../../c-runtime-library/reference/setjmp.md), e [longjmp](../../c-runtime-library/reference/longjmp.md).  
  
 Cada ponto de entrada de uma imagem puro ou seguro é gerenciado. Quando você compila usando **\/clr**, o ponto de entrada é nativo. Para obter mais informações, consulte [\_\_clrcall](../../cpp/clrcall.md).  
  
 Quando você compila usando **\/CLR: safe**, por padrão, as variáveis são [appdomain](../Topic/appdomain.md) e não pode ser por processo. Para **\/clr: puro**, embora **appdomain** é o padrão, você pode usar [processo](../../cpp/process.md) variáveis.  
  
 Quando a execução de um arquivo de 32 bits .exe que foi compilado usando **\/clr** ou **\/clr: puro** em um sistema operacional de 64 bits, o aplicativo será executado no WOW64, que permite que um aplicativo de 32 bits executados no CLR de 32 bits em um sistema operacional de 64 bits. Por padrão, um arquivo .exe que é compilado usando **\/CLR: safe** será executado no CLR de 64 bits em um computador que esteja executando um sistema operacional de 64 bits. \(Em um sistema operacional de 32 bits, o mesmo arquivo .exe será executado no CLR de 32 bits\). No entanto, um aplicativo seguro foi possível carregar um componente de 32 bits. Nesse caso, uma imagem de segurança com suporte de 64 bits do sistema operacional falhará quando ele carrega o aplicativo de 32 bits \(BadFormatException\). Para garantir que uma imagem de segurança continua a ser executado quando ele carrega uma imagem de 32 bits em um sistema operacional de 64 bits, você deve usar [\/CLRIMAGETYPE](../Topic/-CLRIMAGETYPE%20\(Specify%20Type%20of%20CLR%20Image\).md) para alterar os metadados \(.corflags\) e marcá\-lo para ser executado no WOW64. A seguinte linha de comando é um exemplo. \(Substitua seu próprio símbolo de entrada\).  
  
 **Cl \/CLR: safe t.cpp \/link \/clrimagetype: puro \/entry:?main@@$$HYMHXZ \/Subsystem: console**  
  
 Para obter informações sobre como obter um nome decorado, consulte [Nomes decorados](../Topic/Decorated%20Names.md). Para obter mais informações sobre programação de 64 bits, consulte [Configurando programas para 64 bits](../../build/configuring-programs-for-64-bit-visual-cpp.md). Para obter informações sobre como usar código puro do CLR, consulte [Como migrar para \/clr:pure](../../dotnet/how-to-migrate-to-clr-pure-cpp-cli.md) e [Código puro e verificável](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
## Metadados e Classes sem nome  
 Classes sem nome aparecerá nos metadados nomeados da seguinte forma: `$UnnamedClass$`*crc\-de\-atual\-nome de arquivo*`$`*índice*`$`, onde *índice* é uma contagem sequencial das classes não nomeadas na compilação. Por exemplo, o exemplo de código a seguir gera uma classe sem nome nos metadados.  
  
```  
// clr_unnamed_class.cpp  
// compile by using: /clr /LD  
class {} x;  
```  
  
 Use ildasm.exe para exibir os metadados.  
  
## Extensões gerenciadas do C\+\+  
 Visual C\+\+ não oferece suporte a **\/CLR: oldSyntax** opção. Essa opção foi preterida no Visual Studio 2005. A sintaxe com suporte para escrever código gerenciado em C\+\+ é C \+ \+ \/ CLI. Para obter mais informações, consulte [Component Extensions for Runtime Platforms](../../windows/component-extensions-for-runtime-platforms.md).  
  
 Se você tiver um código que usa extensões gerenciadas para C\+\+, é recomendável que você portar para usar C \+ \+ sintaxe CLI. Para obter informações sobre como portar seu código, consulte [Primer de migração C\+\+\/CLI](../../dotnet/cpp-cli-migration-primer.md).  
  
#### Para definir essa opção de compilador no Visual Studio  
  
1.  Em **Solution Explorer**, clique no nome do projeto e, em seguida, clique em **propriedades** para abrir o projeto **páginas de propriedade** caixa de diálogo.  
  
2.  Selecione o **Propriedades de configuração** pasta.  
  
3.  Sobre o **geral** propriedade, modifique o **suporte a Common Language Runtime** propriedade.  
  
    > [!NOTE]
    >  Quando **\/clr** está habilitada no **páginas de propriedade** caixa de diálogo, propriedades de opção de compilador que não são compatíveis com **\/clr** também são ajustados, conforme necessário. Por exemplo, se **\/RTC** é definido e, em seguida, **\/clr** estiver habilitado, **\/RTC** serão desativadas.  
    >   
    >  Além disso, quando você depura um **\/clr** aplicativo, defina o **tipo de depurador** propriedade **Mixed** ou **somente gerenciado**. Para obter mais informações, consulte [Definições do projeto para uma configuração de depuração do C\+\+](../Topic/Project%20Settings%20for%20a%20C++%20Debug%20Configuration.md).  
  
     Para obter informações sobre como criar um módulo, consulte [\/NOASSEMBLY \(criar um módulo MSIL\)](../../build/reference/noassembly-create-a-msil-module.md).  
  
#### Para definir essa opção de compilador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CompileAsManaged%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)