---
title: Opções do vinculador MSVC
ms.date: 08/20/2018
f1_keywords:
- link
helpviewer_keywords:
- linker [C++]
- linker [C++], options listed
- libraries [C++], linking to COFF
- LINK tool [C++], linker options
ms.assetid: c1d51b8a-bd23-416d-81e4-900e02b2c129
ms.openlocfilehash: 7ff8ecd6a607aac59fca6d32fa2784e7e3e4268f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62301754"
---
# <a name="linker-options"></a>Opções do vinculador

LINK.exe vincula arquivos de objeto e bibliotecas de formato COFF (Common Object File Format ) para criar um arquivo executável (.exe) ou uma DLL (biblioteca de vínculo dinâmico).

A tabela a seguir lista opções para LINK.exe. Para obter mais informações sobre LINK, consulte:

- [Opções de LINK controladas pelo compilador](compiler-controlled-link-options.md)

- [Arquivos de entrada de LINK](link-input-files.md)

- [Saída de LINK](link-output.md)

- [Palavras reservadas](reserved-words.md)

Na linha de comando, as opções do vinculador não diferenciam maiusculas de minúsculas; Por exemplo, /base e /BASE significam a mesma coisa. Para obter detalhes sobre como especificar cada opção na linha de comando ou no Visual Studio, consulte a documentação para essa opção.

Você pode usar o [comentário](../../preprocessor/comment-c-cpp.md) pragma para especificar algumas opções de vinculador.

|Opção|Finalidade|
|------------|-------------|
|[@](at-specify-a-linker-response-file.md)|Especifica um arquivo de resposta.|
|[/ALIGN](align-section-alignment.md)|Especifica o alinhamento de cada seção.|
|[/ALLOWBIND](allowbind-prevent-dll-binding.md)|Especifica que não foi possível encontrar uma DLL.|
|[/ALLOWISOLATION](allowisolation-manifest-lookup.md)|Especifica o comportamento da pesquisa de manifesto.|
|[/APPCONTAINER](appcontainer-windows-store-app.md)|Especifica se o aplicativo deve ser executado em um ambiente de processo appcontainer.|
|[/ASSEMBLYDEBUG](assemblydebug-add-debuggableattribute.md)|Adiciona o <xref:System.Diagnostics.DebuggableAttribute> a uma imagem gerenciada.|
|[/ASSEMBLYLINKRESOURCE](assemblylinkresource-link-to-dotnet-framework-resource.md)|Cria um link a um recurso gerenciado.|
|[/ASSEMBLYMODULE](assemblymodule-add-a-msil-module-to-the-assembly.md)|Especifica que um módulo MSIL (Microsoft Intermediate Language) deve ser importado para o assembly.|
|[/ASSEMBLYRESOURCE](assemblyresource-embed-a-managed-resource.md)|Insere um arquivo de recurso gerenciado em um assembly.|
|[/BASE](base-base-address.md)|Define um endereço básico para o programa.|
|[/CGTHREADS](cgthreads-compiler-threads.md)|Define o número de threads cl.exe a serem usados na otimização e na geração do código quando a geração do código de tempo de vinculação é especificada.|
|[/CLRIMAGETYPE](clrimagetype-specify-type-of-clr-image.md)|Define o tipo (IJW, puro ou seguro) de uma imagem do CLR.|
|[/CLRSUPPORTLASTERROR](clrsupportlasterror-preserve-last-error-code-for-pinvoke-calls.md)|Preserva o código de erro mais recente de funções chamadas por meio do mecanismo P/Invoke.|
|[/CLRTHREADATTRIBUTE](clrthreadattribute-set-clr-thread-attribute.md)|Especifica o atributo de threading a ser aplicado ao ponto de entrada do programa do CLR.|
|[/CLRUNMANAGEDCODECHECK](clrunmanagedcodecheck-add-suppressunmanagedcodesecurityattribute.md)|Especifica se o vinculador aplicará o atributo SuppressUnmanagedCodeSecurity aos stubs PInvoke gerados pelo vinculador chamados do código gerenciado para DLLs nativas.|
|[/DEBUG](debug-generate-debug-info.md)|Cria informações de depuração.|
|[/DEBUGTYPE](debugtype-debug-info-options.md)|Especifica quais dados serão incluídos em informações de depuração.|
|[/DEF](def-specify-module-definition-file.md)|Passa um arquivo de definição do módulo (.def) para o vinculador.|
|[/DEFAULTLIB](defaultlib-specify-default-library.md)|Pesquisa a biblioteca especificada quando referências externas são resolvidas.|
|[/DELAY](delay-delay-load-import-settings.md)|Controla o carregamento atrasado de DLLs.|
|[/DELAYLOAD](delayload-delay-load-import.md)|Causa o carregamento atrasado da DLL especificada.|
|[/DELAYSIGN](delaysign-partially-sign-an-assembly.md)|Assina parcialmente um assembly.|
|[/DEPENDENTLOADFLAG](dependentloadflag.md)|Define os sinalizadores de padrão em cargas DLL dependentes.|
|[/DLL](dll-build-a-dll.md)|Compila uma DLL.|
|[/DRIVER](driver-windows-nt-kernel-mode-driver.md)|Cria um driver de modo kernel.|
|[/DYNAMICBASE](dynamicbase-use-address-space-layout-randomization.md)|Especifica se é necessário gerar uma imagem executável que possa ter rebase aleatória no momento do carregamento usando o recurso ASLR (Address Space Layout Randomization).|
|[/ENTRY](entry-entry-point-symbol.md)|Define o endereço inicial.|
|[/errorReport](errorreport-report-internal-linker-errors.md)|Relata erros internos do vinculador para a Microsoft.|
|[/EXPORT](export-exports-a-function.md)|Exporta uma função.|
|[/FILEALIGN](filealign.md)|Alinha seções dentro do arquivo de saída em múltiplos de um valor especificado.|
|[/FIXED](fixed-fixed-base-address.md)|Cria um programa que só pode ser carregado em seu endereço básico preferido.|
|[/FORCE](force-force-file-output.md)|Força a conclusão de um link mesmo com símbolos não resolvidos ou símbolos definidos mais de uma vez.|
|[/FUNCTIONPADMIN](functionpadmin-create-hotpatchable-image.md)|Cria uma imagem que pode receber um hotpatch.|
|[/GENPROFILE, /FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md)|Essas duas opções especificam geração de um arquivo. PGD pelo vinculador para dar suporte à otimização guiada por perfil (PGO). /GENPROFILE e /FASTGENPROFILE usam parâmetros padrão diferentes.|
|[/GUARD](guard-enable-guard-checks.md)|Habilita a proteção da proteção de fluxo de controle.|
|[/HEAP](heap-set-heap-size.md)|Define o tamanho do heap, em bytes.|
|[/HIGHENTROPYVA](highentropyva-support-64-bit-aslr.md)|Especifica o suporte para ASLR (Address Space Layout Randomization) de 64 bits de alta entropia.|
|[/IDLOUT](idlout-name-midl-output-files.md)|Especifica o nome do arquivo .idl e outros arquivos de saída MIDL.|
|[/IGNORE](ignore-ignore-specific-warnings.md)|Suprime a saída de avisos do vinculador especificado.|
|[/IGNOREIDL](ignoreidl-don-t-process-attributes-into-midl.md)|Evita o processamento das informações de atributo em um arquivo .idl.|
|[/IMPLIB](implib-name-import-library.md)|Substitui o nome da biblioteca de importação padrão.|
|[/INCLUDE](include-force-symbol-references.md)|Força referências de símbolo.|
|[/INCREMENTAL](incremental-link-incrementally.md)|Controla a vinculação incremental.|
|[/INTEGRITYCHECK](integritycheck-require-signature-check.md)|Especifica que o módulo requer uma verificação de assinatura no momento do carregamento.|
|[/KEYCONTAINER](keycontainer-specify-a-key-container-to-sign-an-assembly.md)|Especifica um contêiner de chave para assinar um assembly.|
|[/KEYFILE](keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)|Especifica uma chave ou um par de chaves para assinar um assembly.|
|[/LARGEADDRESSAWARE](largeaddressaware-handle-large-addresses.md)|Informa ao compilador que o aplicativo oferece suporte a endereços maiores que dois gigabytes|
|[/LIBPATH](libpath-additional-libpath.md)|Especifica um caminho para pesquisar antes do caminho da biblioteca ambiental.|
|[/LTCG](ltcg-link-time-code-generation.md)|Especifica a geração do código de tempo de vinculação.|
|[/MACHINE](machine-specify-target-platform.md)|Especifica a plataforma de destino.|
|[/MANIFEST](manifest-create-side-by-side-assembly-manifest.md)|Cria um arquivo de manifesto lado a lado e, como opção, o insere no binário.|
|[/MANIFESTDEPENDENCY](manifestdependency-specify-manifest-dependencies.md)|Especifica um \<dependentAssembly > seção no arquivo de manifesto.|
|[/MANIFESTFILE](manifestfile-name-manifest-file.md)|Altera o nome padrão do arquivo de manifesto.|
|[/MANIFESTINPUT](manifestinput-specify-manifest-input.md)|Especifica um arquivo de entrada do manifesto para o vinculador processar e inserir no binário. É possível usar essa opção várias vezes para especificar mais de um arquivo de entrada do manifesto.|
|[/MANIFESTUAC](manifestuac-embeds-uac-information-in-manifest.md)|Especifica se as informações do UAC (Controle de Conta de Usuário) estão inseridas no manifesto do programa.|
|[/MAP](map-generate-mapfile.md)|Cria um arquivo de mapa.|
|[/MAPINFO](mapinfo-include-information-in-mapfile.md)|Inclui as informações especificadas no arquivo de mapa.|
|[/MERGE](merge-combine-sections.md)|Combina seções.|
|[/MIDL](midl-specify-midl-command-line-options.md)|Especifica opções de linha de comando MIDL.|
|[/NATVIS](natvis-add-natvis-to-pdb.md)|Adiciona os visualizadores do depurador de um arquivo Natvis ao PDB.|
|[/NOASSEMBLY](noassembly-create-a-msil-module.md)|Suprime a criação de um assembly do .NET Framework.|
|[/NODEFAULTLIB](nodefaultlib-ignore-libraries.md)|Ignora todas as bibliotecas padrão (ou as especificadas) quando as referências externas são resolvidas.|
|[/NOENTRY](noentry-no-entry-point.md)|Cria uma DLL somente de recursos.|
|[/NOLOGO](nologo-suppress-startup-banner-linker.md)|Suprime a faixa de inicialização.|
|[/NXCOMPAT](nxcompat-compatible-with-data-execution-prevention.md)|Marca um executável como verificado como compatível com o recurso Prevenção de Execução de Dados do Windows.|
|[/OPT](opt-optimizations.md)|Controla otimizações de LINK.|
|[/ORDER](order-put-functions-in-order.md)|Coloca COMDATs na imagem em uma ordem predeterminada.|
|[/OUT](out-output-file-name.md)|Especifica o nome do arquivo de saída.|
|[/PDB](pdb-use-program-database.md)|Cria um arquivo de PDB (banco de dados do programa).|
|[/PDBALTPATH](pdbaltpath-use-alternate-pdb-path.md)|Usa um local alternativo para salvar um arquivo PDB.|
|[/PDBSTRIPPED](pdbstripped-strip-private-symbols.md)|Cria um arquivo de PDB (banco de dados do programa) sem símbolos particulares.|
|[/PGD](pgd-specify-database-for-profile-guided-optimizations.md)|Especifica um arquivo .pgd para otimizações guiadas por perfil.|
|[/POGOSAFEMODE](pogosafemode-linker-option.md)|**Obsoleto** cria uma compilação PGO instrumentado thread-safe.|
|[/PROFILE](profile-performance-tools-profiler.md)|Produz um arquivo de saída que pode ser usado com o criador de perfil de Ferramentas de desempenho.|
|[/RELEASE](release-set-the-checksum.md)|Define a soma de verificação no cabeçalho .exe.|
|[/SAFESEH](safeseh-image-has-safe-exception-handlers.md)|Especifica que a imagem conterá uma tabela de manipuladores de exceção segura.|
|[/ SEÇÃO](section-specify-section-attributes.md)|Substitui os atributos de uma seção.|
|[/SOURCELINK](sourcelink.md)|Especifica um arquivo SourceLink para adicionar ao PDB.|
|[/STACK](stack-stack-allocations.md)|Define o tamanho da pilha, em bytes.|
|[/STUB](stub-ms-dos-stub-file-name.md)|Anexa um programa stub MS-DOS a um programa Win32.|
|[/SUBSYSTEM](subsystem-specify-subsystem.md)|Informa ao sistema operacional como executar o arquivo .exe.|
|[/SWAPRUN](swaprun-load-linker-output-to-swap-file.md)|Pede para o sistema operacional copiar a saída do vinculador em um arquivo de permuta antes de ser executado.|
|[/TLBID](tlbid-specify-resource-id-for-typelib.md)|Especifica a ID de recurso da biblioteca de tipos gerada pelo vinculador.|
|[/TLBOUT](tlbout-name-dot-tlb-file.md)|Especifica o nome do arquivo .tlb e outros arquivos de saída MIDL.|
|[/TSAWARE](tsaware-create-terminal-server-aware-application.md)|Cria um aplicativo projetado especialmente para ser executado no Terminal Server.|
|[/USEPROFILE](useprofile.md)|Dados de treinamento usa guiada por perfil otimização para criar uma imagem otimizada.|
|[/VERBOSE](verbose-print-progress-messages.md)|Imprime mensagens de andamento do vinculador.|
|[/VERSION](version-version-information.md)|Atribui um número de versão.|
|[/WHOLEARCHIVE](wholearchive-include-all-library-object-files.md)|Inclui todos os arquivos de objeto de bibliotecas estáticas especificados.|
|[/WINMD](winmd-generate-windows-metadata.md)|Habilita a geração de um arquivo de Metadados do Tempo de Execução do Windows.|
|[/WINMDFILE](winmdfile-specify-winmd-file.md)|Especifica o nome de arquivo para o arquivo de saída de metadados de tempo de execução do Windows (winmd) que é gerado pelo [/WINMD](winmd-generate-windows-metadata.md) a opção de vinculador.|
|[/WINMDKEYFILE](winmdkeyfile-specify-winmd-key-file.md)|Especifica uma chave ou um par de chaves para assinar um arquivo de Metadados do Tempo de Execução do Windows.|
|[/WINMDKEYCONTAINER](winmdkeycontainer-specify-key-container.md)|Especifica um contêiner de chave para assinar um arquivo de Metadados do Windows.|
|[/WINMDDELAYSIGN](winmddelaysign-partially-sign-a-winmd.md)|Assina parcialmente um arquivo de Metadados de Tempo de Execução do Windows (.winmd) colocando a chave pública no arquivo winmd.|
|[/WX](wx-treat-linker-warnings-as-errors.md)|Trata avisos de vinculador como erros.|

Para obter mais informações, consulte [opções de LINK Compiler-Controlled](compiler-controlled-link-options.md).

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](c-cpp-building-reference.md)<br/>
[Referência de vinculador MSVC](linking.md)
