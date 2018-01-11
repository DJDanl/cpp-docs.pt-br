---
title: 'Como: migrar para o clr-| Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
helpviewer_keywords:
- upgrading Visual C++ applications, /clr compiler option
- compiling native code [C++]
- interoperability [C++], /clr compiler option
- interop [C++], /clr compiler option
- migration [C++], /clr compiler option
- /clr compiler option [C++], porting to
ms.assetid: c9290b8b-436a-4510-8b56-eae51f4a9afc
caps.latest.revision: "37"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f38450831ad85a09d3a43173f8febc7841f02c09
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-migrate-to-clr"></a>Como migrar para /clr
Este tópico aborda problemas que surgem durante a compilação de código nativo com **/clr** (consulte [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações). **/CLR** permite que os módulos do Visual C++ invocar e ser chamado de assemblies .NET enquanto mantém a compatibilidade com módulos não gerenciados. Consulte [Assemblies misto (nativo e gerenciado)](../dotnet/mixed-native-and-managed-assemblies.md) e [nativo e interoperabilidade .NET](../dotnet/native-and-dotnet-interoperability.md) para obter mais informações sobre as vantagens de compilação com **/clr**.  
  
## <a name="known-issues-compiling-library-projects-with-clr"></a>Conhecidos problemas de compilação de projetos de biblioteca com /clr  
 O Visual Studio contém alguns problemas conhecidos quando se estiver compilando projetos de biblioteca com **/clr**:  
  
-   Seu código pode consultar tipos em tempo de execução com [CRuntimeClass::FromName](../mfc/reference/cruntimeclass-structure.md#fromname). No entanto, se for um tipo em uma. dll MSIL (compilado com **/clr**), a chamada para `FromName` pode falhar se ocorrer antes de executar os construtores estáticos na gerenciado. dll (você não verá esse problema se a chamada FromName acontece depois que tiver código executado na gerenciado. dll). Para contornar esse problema, você pode forçar a construção do construtor estático gerenciado definindo uma função no arquivo. dll gerenciada, exportá-lo e chamá-la do aplicativo nativo do MFC. Por exemplo:  
  
    ```  
    // MFC extension DLL Header file:  
    __declspec( dllexport ) void EnsureManagedInitialization () {  
       // managed code that won't be optimized away  
       System::GC::KeepAlive(System::Int32::MaxValue);  
    }  
    ```  
  
## <a name="compile-with-visual-c"></a>Compilar com o Visual C++  
 Antes de usar **/clr** em qualquer módulo em seu projeto, primeiro compilar e vincular o projeto nativo com o Visual Studio 2010.  
  
 As etapas a seguir, seguidas na ordem, fornecem o caminho mais fácil para um **/clr** compilação. É importante compilar e executar seu projeto depois de cada uma dessas etapas.  
  
### <a name="versions-prior-to-visual-c-2003"></a>Versões anteriores do Visual C++ 2003  
 Se você estiver atualizando para o Visual Studio 2010 de uma versão anterior à 2003 do Visual C++, você pode ver erros de compilador relacionados à conformidade standard C++ aprimorada no Visual C++ 2003  
  
### <a name="upgrading-from-visual-c-2003"></a>Atualização do Visual C++ 2003  
 Anteriores de projetos criados com Visual C++ 2003 devem ser compilados primeiro sem **/clr** Visual Studio agora tem maior conformidade com ANSI/ISO e algumas alterações. A alteração que provavelmente exigirá mais atenção é [recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md). O código que usa o CRT é muito provável gerar avisos de depreciação. Esses avisos podem ser suprimidos, mas a migração para o novo [Security-Enhanced versões de funções de CRT](../c-runtime-library/security-enhanced-versions-of-crt-functions.md) é preferencial, pois eles fornecem maior segurança e podem revelar problemas de segurança em seu código.  
  
### <a name="upgrading-from-managed-extensions-for-c"></a>Atualizando a partir de extensões gerenciadas para C++  
 Código gravado com extensões gerenciadas para C++ a partir do Visual Studio 2005, não será compilado em **/clr**.  
  
## <a name="convert-c-code-to-c"></a>Converter o código C em C++  
 Embora o Visual Studio compilará arquivos C, é necessário convertê-las em C++ para um **/clr** compilação. O nome do arquivo real não precisa ser alterado; Você pode usar **/Tp** (consulte [/Tc, /Tp, /TC, /TP (especificar o tipo de arquivo de origem)](../build/reference/tc-tp-tc-tp-specify-source-file-type.md).) Observe que, embora os arquivos de código fonte C++ são necessários para **/clr**, não é necessário refatorar o código para usar paradigmas orientada a objeto.  
  
 Código C é muito provavelmente exigirá alterações quando compilado como um arquivo C++. As regras de segurança de tipo C++ são estritos, para que conversões de tipo devem ser tornadas explícitas com conversões. Por exemplo, malloc retorna um ponteiro nulo, mas pode ser atribuído a um ponteiro para qualquer tipo em C com uma conversão:  
  
```  
int* a = malloc(sizeof(int));   // C code  
int* b = (int*)malloc(sizeof(int));   // C++ equivalent  
```  
  
 Ponteiros de função também são estritamente fortemente tipado em C++, o código a seguir C requer modificação. Em C++, convém criar um `typedef` que define o tipo de ponteiro de função e, em seguida, use esse tipo para converter ponteiros de função:  
  
```  
NewFunc1 = GetProcAddress( hLib, "Func1" );   // C code  
typedef int(*MYPROC)(int);   // C++ equivalent  
NewFunc2 = (MYPROC)GetProcAddress( hLib, "Func2" );  
```  
  
 C++ também requer que funções ser prototipada ou totalmente definido antes que possam ser referenciados ou invocados.  
  
 Identificadores usados no código C que são palavras-chave em C++ (como `virtual`, `new`, `delete`, `bool`, `true`, `false`, etc.) deve ser renomeado. Em geral, isso pode ser feito com operações de pesquisa e substituição simples.  
  
 Por fim, ao passo que as chamadas de estilo C COM exigem o uso explícito da tabela v e `this` ponteiro, C++ não:  
  
```  
COMObj1->lpVtbl->Method(COMObj, args);  // C code  
COMObj2->Method(args);  // C++ equivalent  
```  
  
## <a name="reconfigure-project-settings"></a>Reconfigurar as configurações do projeto  
 Depois que o projeto compila e executa no Visual Studio 2010, você deve criar novas configurações de projeto para **/clr** em vez de modificar as configurações padrão. **/CLR** é incompatível com algumas opções de compilador e criar configurações separadas permite que você compilar o projeto como nativo ou gerenciado. Quando **/clr** está selecionado na caixa de diálogo de páginas de propriedade, configurações do projeto não é compatíveis com **/clr** estão desabilitados (e opções desabilitadas não são restauradas automaticamente se **/clr** é subsequentemente desmarcada).  
  
### <a name="create-new-project-configurations"></a>Criar novas configurações de projeto  
 Você pode usar **copiar as configurações de** opção o [caixa de diálogo de configuração do novo projeto](http://msdn.microsoft.com/en-us/cca616dc-05a6-4fe3-bdc1-40c72a66f2be) para criar uma configuração de projeto com base em suas configurações de projeto existente. Fazer isso vez para a configuração de depuração e uma vez para a configuração de versão. Alterações subsequentes, em seguida, podem ser aplicadas para o **/clr** -configurações específicas, deixando as configurações de projeto original intacta.  
  
 Projetos que usam regras de compilação personalizadas podem exigir atenção extra.  
  
 Esta etapa tem implicações diferentes para projetos que usam makefiles. Nesse caso, um destino de compilação separado pode ser configurado ou versão específica **/clr** compilação pode ser criada a partir de uma cópia do original.  
  
### <a name="change-project-settings"></a>Alterar as configurações de projeto  
 **/CLR** pode ser selecionado no ambiente de desenvolvimento, seguindo as instruções em [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md). Conforme mencionado anteriormente, esta etapa desabilitará automaticamente as configurações conflitantes do projeto.  
  
> [!NOTE]
>  Ao atualizar uma biblioteca gerenciada ou um projeto de serviço web do Visual C++ 2003, o **/Zl** será de opção de compilador adicionado para o **linha de comando** página de propriedades. Isso fará com que LNK2001. Remover **/Zl** do **linha de comando** página de propriedades para resolver. Consulte [/Zl (omitir a nome de biblioteca padrão)](../build/reference/zl-omit-default-library-name.md) e [trabalhando com propriedades de projeto](../ide/working-with-project-properties.md) para obter mais informações. Ou, adicionar msvcrt.lib e msvcmrt.lib para o vinculador **dependências adicionais** propriedade.  
  
 Para projetos criados com makefiles, opções de compilador incompatível devem ser desabilitadas manualmente uma vez **/clr** é adicionado. Consulte /[/clr restrições](../build/reference/clr-restrictions.md) para obter informações sobre opções de compilador que não são compatíveis com **/clr**.  
  
### <a name="precompiled-headers"></a>Cabeçalhos Pré-compilados  
 Cabeçalhos pré-compilados têm suporte em **/clr**. No entanto, se você compilar apenas alguns de seus arquivos CPP com **/clr** (compilação o restante como nativa) algumas alterações será necessárias porque pré-compilado cabeçalhos gerados com **/clr** não são compatíveis com os gerado sem **/clr**. Essa incompatibilidade é devido ao fato de que **/clr** gera e requer metadados. Módulos compilados **/clr** , portanto, não pode usar cabeçalhos pré-compilados que não incluem metadados e não **/clr** módulos não é possível usar arquivos de cabeçalho pré-compilado que contêm metadados.  
  
 A maneira mais fácil para compilar um projeto que alguns módulos são compilados **/clr** é desabilitar completamente a cabeçalhos pré-compilados. (Na caixa de diálogo páginas de propriedades projeto, abra o nó C/C++ e selecione cabeçalhos pré-compilados. Em seguida, altere a propriedade criar/usar cabeçalhos pré-compilados para "Não usar cabeçalhos pré-compilados".)  
  
 No entanto, particularmente para projetos grandes, cabeçalhos pré-compilados fornecem muito maior velocidade de compilação, para que desativar esse recurso não é desejável. Nesse caso, convém configurar o **/clr** e não **/clr** arquivos para usar cabeçalhos pré-compilados separados. Isso pode ser feito em uma etapa por multisseleção módulos a ser compilado **/clr** usando o Gerenciador de soluções, clicando duas vezes no grupo e selecionar propriedades. Em seguida, altere as propriedades a criar/usar PCH através de arquivo e o arquivo de cabeçalho pré-compilado para usar um nome de arquivo de cabeçalho diferente e o arquivo PCH, respectivamente.  
  
## <a name="fixing-errors"></a>Corrigir erros  
 Compilando com **/clr** pode resultar em erros de compilador, vinculador ou tempo de execução. Esta seção discute os problemas mais comuns.  
  
### <a name="metadata-merge"></a>Metadados de mesclagem  
 Versões diferentes dos tipos de dados podem causar o vinculador falha porque os metadados gerados para os dois tipos não correspondem. (Isso é normalmente causado quando os membros de um tipo condicionalmente são definidos, mas as condições não forem as mesmas para todos os arquivos CPP que usam o tipo.) Nesse caso o vinculador falha, relatórios somente o nome de símbolo e o nome do segundo arquivo OBJ onde o tipo foi definido. Geralmente é útil girar a ordem que os arquivos OBJ sejam enviados para o vinculador para descobrir o local da outra versão do tipo de dados.  
  
### <a name="loader-lock-deadlock"></a>Deadlock de bloqueio do carregador  
 No Visual Studio 2010 e posterior, o "deadlock de bloqueio do carregador" ainda pode ocorrer como nas versões anteriores, mas é determinística e é detectado e relatadas em tempo de execução. Consulte [inicialização de Assemblies mistos](../dotnet/initialization-of-mixed-assemblies.md) para orientação, detalhadas e soluções.  
  
### <a name="data-exports"></a>Exporta dados  
 Exportando dados do DLL é propenso a erros e não é recomendado. Isso ocorre porque a seção de dados de uma DLL não é garantida para ser inicializado até que alguma parte gerenciado da DLL foi executado. Metadados de referência com [#using diretiva](../preprocessor/hash-using-directive-cpp.md).  
  
### <a name="type-visibility"></a>Visibilidade de tipo  
 Tipos nativos são private por padrão. Isso pode resultar em um tipo nativo que não seja visível fora da DLL. Resolver esse erro, adicionando `public` a esses tipos.  
  
### <a name="floating-point-and-alignment-issues"></a>Flutuante ponto e problemas de alinhamento  
 `__controlfp`Não há suporte para o common language runtime (consulte [control87, controlfp, \__control87_2](../c-runtime-library/reference/control87-controlfp-control87-2.md) para obter mais informações). O CLR também respeitará [alinhar](../cpp/align-cpp.md).  
  
### <a name="com-initialization"></a>Inicialização do COM  
 O Common Language Runtime inicializa COM automaticamente quando um módulo é inicializado (quando COM é inicializado automaticamente ele tenha feito isso como MTA). Como resultado, a inicialização explicitamente COM gera códigos de retorno que indica que COM já foi inicializado. Tentando inicializar explicitamente COM um modelo de threading quando o CLR já foi inicializado COM para outro modelo de threading pode causar o aplicativo falhar.  
  
 O common language runtime começa COM como MTA por padrão. Use [/CLRTHREADATTRIBUTE (Definir Thread atributo CLR)](../build/reference/clrthreadattribute-set-clr-thread-attribute.md) modificar isso.  
  
### <a name="performance-issues"></a>Problemas de desempenho  
 Você pode ver o desempenho reduzido quando os métodos de C++ nativo gerados para MSIL são chamados indiretamente (chamadas de função virtual ou usar ponteiros de função). Para saber mais sobre isso, consulte [dupla](../dotnet/double-thunking-cpp.md).  
  
 Ao mover de nativo para MSIL, você irá notar um aumento no tamanho do seu conjunto de trabalho. Isso ocorre porque o common language runtime fornece muitos recursos para garantir que programas sejam executados corretamente. Se seu **/clr** aplicativo não está funcionando corretamente, talvez você queira habilitar C4793 (desativado por padrão), consulte [aviso do compilador (nível 1 e 3) C4793](../error-messages/compiler-warnings/compiler-warning-level-1-and-3-c4793.md) para obter mais informações.  
  
### <a name="program-crashes-on-shutdown"></a>Programa falha no desligamento  
 Em alguns casos, o CLR pode encerrar antes da conclusão do seu código gerenciado em execução. Usando `std::set_terminate` e `SIGTERM` podem causar isso. Consulte [constantes de sinal](../c-runtime-library/signal-constants.md) e [set_terminate](../c-runtime-library/abnormal-termination.md) para obter mais informações.  
  
## <a name="using-new-visual-c-features"></a>Usar os novos recursos do Visual C++  
 Depois que o aplicativo compila, links e é executado, você pode começar a usar os recursos do .NET em qualquer módulo compilado com **/clr**. Para obter mais informações, consulte [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md).  
  
 Se você usou das extensões gerenciadas para C++, você pode converter seu código para usar a nova sintaxe. Para obter um resumo das diferenças sintáticas, consulte o [(NOTINBUILD) das extensões gerenciadas para verificação de atualização de sintaxe de C++](http://msdn.microsoft.com/en-us/edbded88-7ef3-4757-bd9d-b8f48ac2aada). Para obter detalhes sobre a conversão das extensões gerenciadas para C++, consulte [C + + Primer de migração de CLI](../dotnet/cpp-cli-migration-primer.md).  
  
 Para obter informações sobre programação no Visual C++ .NET, consulte:  
  
-   [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)  
  
-   [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)  
  
-   [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)  
  
## <a name="see-also"></a>Consulte também  
 [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)