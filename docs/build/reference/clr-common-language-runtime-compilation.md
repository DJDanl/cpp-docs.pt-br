---
title: -clr (Common Language Runtime Compilation) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /CLR
- VC.Project.VCNMakeTool.CompileAsManaged
- VC.Project.VCCLCompilerTool.CompileAsManaged
dev_langs: C++
helpviewer_keywords:
- cl.exe compiler, common language runtime option
- -clr compiler option [C++]
- clr compiler option [C++]
- /clr compiler option [C++]
- Managed Extensions for C++, compiling
- common language runtime, /clr compiler option
ms.assetid: fec5a8c0-40ec-484c-a213-8dec918c1d6c
caps.latest.revision: "72"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6a867203585a66bd07eb9f95e289557e82e0553a
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="clr-common-language-runtime-compilation"></a>/clr (compilação do Common Language Runtime)
Permite que aplicativos e componentes usem recursos do CLR (Common Language Runtime).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/clr[:options]  
```  
  
## <a name="arguments"></a>Arguments  
 `options`  
 Uma ou mais das seguintes opções, separados por vírgulas.  
  
 **/clr**  
 Cria os metadados para o aplicativo. Os metadados podem ser consumidos por outros aplicativos CLR e permite que o aplicativo consuma tipos e dados nos metadados de outros componentes do CLR.  
  
 Para saber mais, veja  
  
 [Misto (gerenciados e nativos) Assemblies](../../dotnet/mixed-native-and-managed-assemblies.md) e  
  
 [Como: migrar para /clr](../../dotnet/how-to-migrate-to-clr.md).  
  
 **/clr:pure**  
 Produz um Microsoft Intermediate Language (MSIL)-somente o arquivo de saída que tem sem código executável nativo. No entanto, ela pode conter tipos nativos compilados para MSIL.  
  
 Para obter mais informações, consulte [puro e código verificável (C + + CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
 /CLR: pure foi preterido. Uma versão futura do compilador pode não dar suporte a essa opção. É recomendável que você porta código que deve ser MSIL puro para c#.  
  
 **/CLR: safe**  
 Produz um MSIL somente (sem código executável nativo), arquivo de saída verificável. **/CLR: safe** permitem o diagnóstico de verificação ([ferramenta PEVerify (Peverify.exe)](/dotnet/framework/tools/peverify-exe-peverify-tool)).  
  

 /CLR: safe foi preterido. Uma versão futura do compilador pode não dar suporte a essa opção. É recomendável que você porta código que deve ser MSIL puro, pode ser verificada para c#.  
  
 **/CLR:noAssembly**  
 Especifica que um manifesto do assembly não deve ser inserido no arquivo de saída. Por padrão, o **noAssembly** opção não está em vigor.  
  
 O **noAssembly** opção é preterida. Use [/LN (criar o módulo MSIL)](../../build/reference/ln-create-msil-module.md) em vez disso.  
  
 Um programa gerenciado que não tem metadados de assembly no manifesto é conhecido como um *módulo*. O **noAssembly** opção pode ser usada somente para produzir um módulo. Se você compila usando [/c](../../build/reference/c-compile-without-linking.md) e **/clr:noAssembly**, em seguida, especifique o [/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md) opção na fase de vinculador para criar um módulo.  
  
 Antes de Visual C++ 2005, **/clr:noAssembly** necessária **/LD**. **/LD** agora está implícita quando você especificar **/clr:noAssembly**.  
  
 **/CLR:initialAppDomain**  
 Permite que um [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] aplicativo para ser executado na versão 1 do CLR. Se você usar **initialAppDomain**, em seguida, você poderá ver alguns dos problemas que são discutidos em [BUG: exceção AppDomainUnloaded quando você usa do managed extensions para componentes do Visual C++](http://go.microsoft.com/fwlink/p/?linkid=169465) no Microsoft Site de suporte.  
  
 Um aplicativo que é compilado usando **initialAppDomain** não deve ser usado por um aplicativo que usa o ASP.NET porque não há suporte na versão 1 do CLR.  
  
 **/CLR:nostdlib**  
 Instrui o compilador ignorar o diretório \clr padrão. O compilador gera erros se você estiver incluindo várias versões de uma DLL como System. dll. O uso dessa opção permite que você especifique o framework específico a ser usado durante a compilação.  
  
## <a name="remarks"></a>Comentários  
 Código gerenciado é um código que pode ser inspecionado e gerenciado pelo CLR. Código gerenciado pode acessar objetos gerenciados. Para obter mais informações, consulte [/clr Restrições](../../build/reference/clr-restrictions.md).  
  
 Para obter informações sobre como desenvolver aplicativos que definem e consumam tipos gerenciados, consulte [extensões de componentes para plataformas de tempo de execução](../../windows/component-extensions-for-runtime-platforms.md).  
  
 Um aplicativo compilado usando **/clr** pode ou não pode conter dados gerenciados.  
  
 Para habilitar a depuração em um aplicativo gerenciado, consulte [/ASSEMBLYDEBUG (Adicionar DebuggableAttribute)](../../build/reference/assemblydebug-add-debuggableattribute.md).  
  
 Somente os tipos CLR serão instanciados no heap coletado como lixo. Para obter mais informações, consulte [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md). Para compilar uma função em código nativo, use o `unmanaged` pragma. Para obter mais informações, consulte [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md).  
  
 Por padrão, **/clr** não está em vigor. Quando **/clr** está em vigor, **/MD** também está em vigor. Para obter mais informações, consulte [/MD, /MT, /LD (usar biblioteca em tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md). **/MD** garante que as versões dinamicamente vinculadas, multithread das rotinas de tempo de execução são selecionadas dos arquivos de cabeçalho padrão (h). Multithreading é necessário para porque o coletor de lixo CLR executa os finalizadores em um thread auxiliar de programação gerenciada.  
  
 Se você compila usando **/c**, você pode especificar o tipo CLR (IJW, confiável ou puro) do arquivo de saída resultante com [/CLRIMAGETYPE](../../build/reference/clrimagetype-specify-type-of-clr-image.md).  
  
 **/CLR** implica **/EHa**e nenhum outro **/EH** opções têm suporte para **/clr**. Para obter mais informações, consulte [/EH (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md).  
  
 Para obter informações sobre como determinar o tipo de imagem CLR de um arquivo, consulte [/CLRHEADER](../../build/reference/clrheader.md).  
  
 Todos os módulos passados para uma determinada invocação do vinculador devem ser compilados usando a mesma opção de compilador de biblioteca de tempo de execução (**/MD** ou **/LD**).  
  
 Use o [/ASSEMBLYRESOURCE.](../../build/reference/assemblyresource-embed-a-managed-resource.md) opção de vinculador para inserir um recurso em um assembly. [/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md), [/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md), e [/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md) opções do vinculador também permitem que você personalize como um assembly é criado.  
  
 Quando **/clr** for usado, o `_MANAGED` símbolo é definido como 1. Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).  
  
 As variáveis globais em um arquivo de objeto nativo são inicializadas primeiro (durante DllMain se o executável é uma DLL) e, em seguida, as variáveis globais na seção gerenciada são inicializadas (antes de qualquer código gerenciado é executado). `#pragma`[init_seg](../../preprocessor/init-seg.md) só afeta a ordem de inicialização nas categorias gerenciadas e não gerenciados.  
  
 Compilando usando **/CLR: safe** é análogo a compilação usando [/platform:anycpu](/dotnet/csharp/language-reference/compiler-options/platform-compiler-option) em linguagens como c#.  
  
## <a name="safe-and-pure-images"></a>Imagens puras e seguras  
 Uma imagem pura usa uma versão do CLR da biblioteca C Runtime (CRT). No entanto, CRT não é verificável, portanto você não pode usar o CRT quando você compila usando **/CLR: safe**. Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
 Exemplos de código nativo que não pode aparecer em uma imagem pura assembly embutido, [setjmp](../../c-runtime-library/reference/setjmp.md), e [longjmp](../../c-runtime-library/reference/longjmp.md).  
  
 Cada ponto de entrada de uma imagem simples ou segurança é gerenciado. Quando você compila usando **/clr**, o ponto de entrada é nativo. Para obter mais informações, consulte [clrcall](../../cpp/clrcall.md).  
  
 Quando você compila usando **/CLR: safe**, por padrão, as variáveis são [appdomain](../../cpp/appdomain.md) e não pode ser por processo. Para **/clr: pure**, embora **appdomain** é o padrão, você pode usar [processo](../../cpp/process.md) variáveis.  
  
 Ao executar um arquivo de 32 bits .exe que foi compilado usando **/clr** ou **/clr: pure** em um sistema operacional de 64 bits, o aplicativo será executado no WOW64, que permite que um aplicativo de 32 bits executar em 32 bits CLR em um sistema operacional de 64 bits. Por padrão, um arquivo .exe que é compilado usando **/CLR: safe** será executado no CLR 64 bits em um computador que esteja executando um sistema operacional de 64 bits. (Em um sistema operacional de 32 bits, o mesmo arquivo .exe será executado no CLR de 32 bits.) No entanto, um aplicativo de seguro foi possível carregar um componente de 32 bits. Nesse caso, uma imagem de segurança em execução com suporte de 64 bits do sistema operacional falhará quando ele carrega o aplicativo de 32 bits (BadFormatException). Para garantir que uma imagem de segurança continuará a ser executado quando ele carrega uma imagem de 32 bits em um sistema operacional de 64 bits, você deve usar [/CLRIMAGETYPE](../../build/reference/clrimagetype-specify-type-of-clr-image.md) para alterar os metadados (.corflags) e marcá-la para ser executado no WOW64. A linha de comando a seguir é um exemplo. (Substitua seu próprio símbolo de entrada).  
  
 **Cl /CLR: safe t.cpp /link /clrimagetype: pure /entry:?main@@$$HYMHXZ /Subsystem**  
  
 Para obter informações sobre como obter um nome decorado, consulte [nomes decorados](../../build/reference/decorated-names.md). Para obter mais informações sobre os destinos de 64 bits, consulte [configurar Visual C++ para x64 de 64 bits, destinos](../../build/configuring-programs-for-64-bit-visual-cpp.md). Para obter informações sobre como usar código puro do CLR, consulte [como: migrar para /clr: pure (C + + CLI)](../../dotnet/how-to-migrate-to-clr-pure-cpp-cli.md) e [puro e código verificável (C + + CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
## <a name="metadata-and-unnamed-classes"></a>Metadados e Classes sem nome  
 Classes sem nome serão exibido nos metadados nomeados da seguinte maneira: `$UnnamedClass$` *crc-de-atual-nome de arquivo*`$`*índice*`$`, onde *índice*é uma contagem sequencial das classes sem nome na compilação. Por exemplo, o exemplo de código a seguir gera uma classe sem nome nos metadados.  
  
```  
// clr_unnamed_class.cpp  
// compile by using: /clr /LD  
class {} x;  
```  
  
 Use ildasm.exe para exibir os metadados.  
  
## <a name="managed-extensions-for-c"></a>Extensões gerenciadas do C++  
 Visual C++ não suporta o **/CLR: oldSyntax** opção. Essa opção foi preterida no Visual Studio 2005. A sintaxe com suporte para escrever um código gerenciado em C++ é C + + CLI. Para obter mais informações, consulte [Extensões de componentes para plataformas de tempo de execução](../../windows/component-extensions-for-runtime-platforms.md).  
  
 Se você tiver código que usa extensões gerenciadas para C++, é recomendável a porta para usar C + + sintaxe da CLI. Para obter informações sobre como a porta de seu código, consulte [C + + Primer de migração de CLI](../../dotnet/cpp-cli-migration-primer.md).  
  
#### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio  
  
1.  Em **Solution Explorer**, clique no nome do projeto e, em seguida, clique em **propriedades** para abrir o projeto **páginas de propriedade** caixa de diálogo.  
  
2.  Selecione o **propriedades de configuração** pasta.  
  
3.  Sobre o **geral** propriedade, modifique o **suporte a Common Language Runtime** propriedade.  
  
    > [!NOTE]
    >  Quando **/clr** está habilitada no **páginas de propriedade** caixa de diálogo, propriedades de opção de compilador que não são compatíveis com **/clr** também são ajustados, conforme necessário. Por exemplo, se **/RTC** é definido e, em seguida, **/clr** estiver habilitado, **/RTC** serão desativadas.  
    >   
    >  Além disso, quando você depurar um **/clr** aplicativo, defina o **tipo de depurador** propriedade **Mixed** ou **somente gerenciado**. Para obter mais informações, consulte [configurações de projeto para uma configuração de depuração de C++](/visualstudio/debugger/project-settings-for-a-cpp-debug-configuration).  
  
     Para obter informações sobre como criar um módulo, consulte [/NOASSEMBLY (criar um módulo MSIL)](../../build/reference/noassembly-create-a-msil-module.md).  
  
#### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CompileAsManaged%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)