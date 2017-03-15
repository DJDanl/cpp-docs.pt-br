---
title: "Op&#231;&#245;es de vinculador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "link"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bibliotecas [C++], vinculando a COFF"
  - "ferramenta LINK [C++], opções de vinculador"
  - "vinculador [C++]"
  - "vinculador [C++], opções listadas"
ms.assetid: c1d51b8a-bd23-416d-81e4-900e02b2c129
caps.latest.revision: 37
caps.handback.revision: 37
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Op&#231;&#245;es de vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

LINK.exe vincula os arquivos de objeto de arquivo formato COFF \(Common Object\) e bibliotecas para criar um arquivo executável \(.exe\) ou uma biblioteca de vínculo dinâmico \(DLL\).  
  
 A tabela a seguir lista as opções de LINK.exe. Para obter mais informações sobre LINK, consulte:  
  
-   [Opções LINK controladas por compilador](../../build/reference/compiler-controlled-link-options.md)  
  
-   [Arquivos de entrada LINK](../../build/reference/link-input-files.md)  
  
-   [Saída LINK](../../build/reference/link-output.md)  
  
-   [Palavras reservadas](../../build/reference/reserved-words.md)  
  
 Na linha de comando, opções do vinculador não diferenciam maiúsculas de minúsculas, por exemplo, \/base e \/BASE significam a mesma coisa. Para obter detalhes sobre como especificar cada opção na linha de comando ou no Visual Studio, consulte a documentação para essa opção.  
  
 Você pode usar o [comentário](../../preprocessor/comment-c-cpp.md) pragma para especificar algumas opções do vinculador.  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[@](../../build/reference/at-specify-a-linker-response-file.md)|Especifica um arquivo de resposta.|  
|[\/ ALIGN](../../build/reference/align-section-alignment.md)|Especifica o alinhamento de cada seção.|  
|[\/ALLOWBIND](../../build/reference/allowbind-prevent-dll-binding.md)|Especifica que uma DLL não pode ser associada.|  
|[\/ALLOWISOLATION](../../build/reference/allowisolation-manifest-lookup.md)|Especifica o comportamento de pesquisa de manifesto.|  
|[\/APPCONTAINER](../../build/reference/appcontainer-windows-store-app.md)|Especifica se o aplicativo deve ser executado em um ambiente de processo appcontainer.|  
|[\/ASSEMBLYDEBUG](../Topic/-ASSEMBLYDEBUG%20\(Add%20DebuggableAttribute\).md)|Adiciona o <xref:System.Diagnostics.DebuggableAttribute> a uma imagem gerenciada.|  
|[\/ASSEMBLYLINKRESOURCE](../../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md)|Cria um link para um recurso gerenciado.|  
|[\/ASSEMBLYMODULE](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md)|Especifica que um módulo do Microsoft intermediate language \(MSIL\) deve ser importado para o assembly.|  
|[\/ASSEMBLYRESOURCE](../../build/reference/assemblyresource-embed-a-managed-resource.md)|Insere um arquivo de recurso gerenciado em um assembly.|  
|[BASE](../../build/reference/base-base-address.md)|Define um endereço base para o programa.|  
|[\/CGTHREADS](../../build/reference/cgthreads-compiler-threads.md)|Define o número de threads de cl.exe a ser usado para otimização e geração de código quando a geração de código para link\-time é especificada.|  
|[\/CLRIMAGETYPE](../Topic/-CLRIMAGETYPE%20\(Specify%20Type%20of%20CLR%20Image\).md)|Define o tipo \(IJW, puro ou seguro\) de uma imagem CLR.|  
|[\/CLRSUPPORTLASTERROR](../../build/reference/clrsupportlasterror-preserve-last-error-code-for-pinvoke-calls.md)|Preserva o último código de erro de funções que são chamados pelo mecanismo de P\/Invoke.|  
|[\/CLRTHREADATTRIBUTE](../../build/reference/clrthreadattribute-set-clr-thread-attribute.md)|Especifica o atributo de thread para aplicar ao ponto de entrada de programa do CLR.|  
|[\/CLRUNMANAGEDCODECHECK](../../build/reference/clrunmanagedcodecheck-add-supressunmanagedcodesecurityattribute.md)|Especifica se o vinculador aplicará o atributo SuppressUnmanagedCodeSecurity para stubs PInvoke gerados pelo vinculador que chamam do código gerenciado para DLLs nativas.|  
|[\/DEBUG](../../build/reference/debug-generate-debug-info.md)|Cria informações de depuração.|  
|[\/ DEBUGTYPE](../../build/reference/debugtype-debug-info-options.md)|Especifica quais dados a serem incluídos nas informações de depuração.|  
|[\/ DEF](../../build/reference/def-specify-module-definition-file.md)|Passa um arquivo de definição de módulo \(. def\) para o vinculador.|  
|[\/DEFAULTLIB](../../build/reference/defaultlib-specify-default-library.md)|Pesquisa a biblioteca especificada quando referências externas são resolvidas.|  
|[\/ ATRASO](../../build/reference/delay-delay-load-import-settings.md)|Controla o carregamento atrasado de DLLs.|  
|[\/DELAYLOAD](../../build/reference/delayload-delay-load-import.md)|Faz com que o carregamento atrasado da DLL especificada.|  
|[\/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md)|Assina parcialmente um assembly.|  
|[\/ DLL](../../build/reference/dll-build-a-dll.md)|Cria uma DLL.|  
|[\/ DRIVER](../../build/reference/driver-windows-nt-kernel-mode-driver.md)|Cria um driver de modo kernel.|  
|[\/DYNAMICBASE](../../build/reference/dynamicbase-use-address-space-layout-randomization.md)|Especifica se deve gerar uma imagem executável que possa ter REBASE aleatória no tempo de carregamento usando o recurso de randomização \(ASLR\) de layout de espaço de endereço.|  
|[\/ ENTRADA](../../build/reference/entry-entry-point-symbol.md)|Define o endereço inicial.|  
|[\/errorReport](../Topic/-ERRORREPORT%20\(Report%20Internal%20Linker%20Errors\).md)|Relatórios de erros de vinculador interno à Microsoft.|  
|[\/ EXPORTAÇÃO](../../build/reference/export-exports-a-function.md)|Exporta uma função.|  
|[\/ FIXED](../../build/reference/fixed-fixed-base-address.md)|Cria um programa que pode ser carregado somente em seu endereço base preferido.|  
|[\/FORCE](../../build/reference/force-force-file-output.md)|Força um link para concluir o mesmo com símbolos não resolvidos ou símbolos definidos mais de uma vez.|  
|[\/FUNCTIONPADMIN](../../build/reference/functionpadmin-create-hotpatchable-image.md)|Cria uma imagem que pode ser hotpatch.|  
|[\/ GENPROFILE, \/FASTGENPROFILE](../../build/reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md)|Essas opções especificam a geração de um arquivo. PGD pelo vinculador para dar suporte a Otimização Guiada por perfil \(PGO\). \/ GENPROFILE e \/FASTGENPROFILE usam parâmetros padrão diferentes.|  
|[\/ PROTETOR DE](../../build/reference/guard-enable-guard-checks.md)|Habilita a proteção do controle de fluxo.|  
|[\/HEAP](../../build/reference/heap-set-heap-size.md)|Define o tamanho do heap, em bytes.|  
|[\/HIGHENTROPYVA](../Topic/-HIGHENTROPYVA%20\(Support%2064-Bit%20ASLR\).md)|Especifica o suporte para randomização de layout de espaço de endereço de 64 bits de alta entropia \(ASLR\).|  
|[\/IDLOUT](../Topic/-IDLOUT%20\(Name%20MIDL%20Output%20Files\).md)|Especifica o nome do arquivo. idl e outros arquivos de saída MIDL.|  
|[\/ IGNORAR](../../build/reference/ignore-ignore-specific-warnings.md)|Suprime a saída de avisos do vinculador especificado.|  
|[\/IGNOREIDL](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)|Impede que o processamento das informações de atributo em um arquivo. idl.|  
|[\/IMPLIB](../Topic/-IMPLIB%20\(Name%20Import%20Library\).md)|Substitui o nome padrão da biblioteca de importação.|  
|[\/INCLUDE](../../build/reference/include-force-symbol-references.md)|Força referências de símbolo.|  
|[\/ INCREMENTAL](../../build/reference/incremental-link-incrementally.md)|Controla a vinculação incremental.|  
|[\/INTEGRITYCHECK](../../build/reference/integritycheck-require-signature-check.md)|Especifica que o módulo requer uma verificação de assinatura em tempo de carregamento.|  
|[\/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md)|Especifica um contêiner de chave para assinar um assembly.|  
|[\/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)|Especifica uma chave ou par de chaves para assinar um assembly.|  
|[\/LARGEADDRESSAWARE](../../build/reference/largeaddressaware-handle-large-addresses.md)|Informa ao compilador que o aplicativo oferece suporte a endereços maiores que dois gigabytes|  
|[\/ LIBPATH](../../build/reference/libpath-additional-libpath.md)|Especifica um caminho de pesquisa antes do caminho da biblioteca ambiental.|  
|[\/LTCG](../../build/reference/ltcg-link-time-code-generation.md)|Especifica a geração de código para link\-time.|  
|[\/ MÁQUINA](../../build/reference/machine-specify-target-platform.md)|Especifica a plataforma de destino.|  
|[\/ MANIFEST](../../build/reference/manifest-create-side-by-side-assembly-manifest.md)|Cria um arquivo de manifesto lado a lado e, opcionalmente, o insere no binário.|  
|[\/MANIFESTDEPENDENCY](../../build/reference/manifestdependency-specify-manifest-dependencies.md)|Especifica uma seção \< dependentAssembly \> no arquivo de manifesto.|  
|[\/MANIFESTFILE](../../build/reference/manifestfile-name-manifest-file.md)|Altera o nome padrão do arquivo de manifesto.|  
|[\/MANIFESTINPUT](../../build/reference/manifestinput-specify-manifest-input.md)|Especifica um arquivo de manifesto de entrada para o vinculador processar e inserir no binário. Você pode usar essa opção várias vezes para especificar mais de um arquivo de entrada de manifesto.|  
|[\/MANIFESTUAC](../../build/reference/manifestuac-embeds-uac-information-in-manifest.md)|Especifica se as informações de controle de conta de usuário \(UAC\) estão incorporadas no manifesto do programa.|  
|[\/ MAPA](../../build/reference/map-generate-mapfile.md)|Cria um arquivo de mapa.|  
|[\/ MAPINFO](../../build/reference/mapinfo-include-information-in-mapfile.md)|Inclui as informações especificadas no arquivo de mapa.|  
|[\/ MESCLAGEM](../../build/reference/merge-combine-sections.md)|Combina seções.|  
|[\/ MIDL](../../build/reference/midl-specify-midl-command-line-options.md)|Especifica as opções de linha de comando MIDL.|  
|[\/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)|Suprime a criação de um assembly do .NET Framework.|  
|[\/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md)|Ignora todos \(ou especificado\) bibliotecas padrão quando referências externas são resolvidas.|  
|[\/NOENTRY](../../build/reference/noentry-no-entry-point.md)|Cria uma DLL somente recurso.|  
|[\/NOLOGO](../../build/reference/nologo-suppress-startup-banner-linker.md)|Suprime a faixa de inicialização.|  
|[\/NXCOMPAT](../../build/reference/nxcompat-compatible-with-data-execution-prevention.md)|Marca um executável como verificado como compatível com o recurso prevenção de execução de dados do Windows.|  
|[\/OPT](../../build/reference/opt-optimizations.md)|Controla otimizações de LINK.|  
|[\/ ORDEM](../../build/reference/order-put-functions-in-order.md)|Coloca COMDATs na imagem em uma ordem predeterminada.|  
|[\/OUT](../../build/reference/out-output-file-name.md)|Especifica o nome do arquivo de saída.|  
|[\/ PDB](../../build/reference/pdb-use-program-database.md)|Cria um arquivo de programa \(PDB\) de banco de dados.|  
|[\/ PDBALTPATH](../../build/reference/pdbaltpath-use-alternate-pdb-path.md)|Usa um local alternativo para salvar um arquivo PDB.|  
|[\/PDBSTRIPPED](../../build/reference/pdbstripped-strip-private-symbols.md)|Cria um arquivo de banco de dados \(PDB\) do programa sem símbolos particulares.|  
|[\/PGD](../../build/reference/pgd-specify-database-for-profile-guided-optimizations.md)|Especifica um arquivo. PGD para otimizações guiadas por perfil.|  
|[OU O PERFIL](../../build/reference/profile-performance-tools-profiler.md)|Produz um arquivo de saída que pode ser usado com o criador de perfil de ferramentas de desempenho.|  
|[\/RELEASE](../../build/reference/release-set-the-checksum.md)|Define a soma de verificação no cabeçalho do .exe.|  
|[\/SAFESEH](../Topic/-SAFESEH%20\(Image%20has%20Safe%20Exception%20Handlers\).md)|Especifica que a imagem conterá uma tabela de manipuladores de exceção de segurança.|  
|[\/SECTION](../../build/reference/section-specify-section-attributes.md)|Substitui os atributos de uma seção.|  
|[\/STACK](../../build/reference/stack-stack-allocations.md)|Define o tamanho da pilha em bytes.|  
|[\/ STUB](../../build/reference/stub-ms-dos-stub-file-name.md)|Anexa um programa stub MS\-DOS a um programa Win32.|  
|[\/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md)|Informa ao sistema operacional como executar o arquivo .exe.|  
|[\/SWAPRUN](../../build/reference/swaprun-load-linker-output-to-swap-file.md)|Informa ao sistema operacional para copiar a saída do vinculador para um arquivo de permuta para executá\-lo.|  
|[\/TLBID](../../build/reference/tlbid-specify-resource-id-for-typelib.md)|Especifica a ID de recurso da biblioteca de tipos gerados pelo vinculador.|  
|[\/TLBOUT](../../build/reference/tlbout-name-dot-tlb-file.md)|Especifica o nome do arquivo. tlb e outros arquivos de saída MIDL.|  
|[\/TSAWARE](../../build/reference/tsaware-create-terminal-server-aware-application.md)|Cria um aplicativo desenvolvido especialmente para ser executado no Terminal Server.|  
|[\/VERBOSE](../../build/reference/verbose-print-progress-messages.md)|Imprime mensagens de andamento do vinculador.|  
|[\/VERSION](../Topic/-VERSION%20\(Version%20Information\).md)|Atribui um número de versão.|  
|[\/ WHOLEARCHIVE](../../build/reference/wholearchive-include-all-library-object-files.md)|Inclui todos os arquivos de objeto de bibliotecas estáticas especificados.|  
|[\/WINMD](../../build/reference/winmd-generate-windows-metadata.md)|Habilita a geração de um arquivo de metadados de tempo de execução do Windows.|  
|[\/WINMDFILE](../Topic/-WINMDFILE%20\(Specify%20winmd%20File\).md)|Especifica o nome de arquivo para o arquivo de saída de metadados de tempo de execução do Windows \(winmd\) que é gerado pelo [\/WINMD](../../build/reference/winmd-generate-windows-metadata.md) opção de vinculador.|  
|[\/WINMDKEYFILE](../../build/reference/winmdkeyfile-specify-winmd-key-file.md)|Especifica uma chave ou par de chaves para assinar um arquivo de metadados de tempo de execução do Windows.|  
|[\/WINMDKEYCONTAINER](../../build/reference/winmdkeycontainer-specify-key-container.md)|Especifica um contêiner de chave para assinar um arquivo de metadados do Windows.|  
|[\/WINMDDELAYSIGN](../../build/reference/winmddelaysign-partially-sign-a-winmd.md)|Assina parcialmente um arquivo de metadados de tempo de execução do Windows \(. winmd\) colocando a chave pública no arquivo winmd.|  
|[\/WX](../../build/reference/wx-treat-linker-warnings-as-errors.md)|Trata avisos do vinculador como erros.|  
  
 Para obter mais informações, consulte [Opções LINK controladas por compilador](../../build/reference/compiler-controlled-link-options.md).  
  
## Consulte também  
 [Referência de compilação do C\/C\+\+](../Topic/C-C++%20Building%20Reference.md)   
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Perguntas freqüentes sobre criação](http://msdn.microsoft.com/pt-br/56a3bb8f-0181-4989-bab4-a07ba950ab08)