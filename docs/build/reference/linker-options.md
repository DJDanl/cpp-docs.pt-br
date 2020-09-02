---
title: Opções do vinculador MSVC
description: Uma lista das opções com suporte pelo vinculador de LINK da Microsoft.
ms.date: 09/01/2020
f1_keywords:
- link
helpviewer_keywords:
- linker [C++]
- linker [C++], options listed
- libraries [C++], linking to COFF
- LINK tool [C++], linker options
ms.assetid: c1d51b8a-bd23-416d-81e4-900e02b2c129
ms.openlocfilehash: 0d85361b8d4b5896d9ed7beae0d310fe28dc98e9
ms.sourcegitcommit: e58918c45316d799c1952ca7797a85adbcd0c472
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/01/2020
ms.locfileid: "89281790"
---
# <a name="linker-options"></a>Opções do vinculador

LINK.exe vincula arquivos de objeto e bibliotecas de formato COFF (Common Object File Format ) para criar um arquivo executável (.exe) ou uma DLL (biblioteca de vínculo dinâmico).

A tabela a seguir lista opções para LINK.exe. Para obter mais informações sobre LINK, consulte:

- [Opções de LINK controladas por compilador](compiler-controlled-link-options.md)

- [Arquivos de entrada de LINK](link-input-files.md)

- [Saída do LINK](link-output.md)

- [Palavras reservadas](reserved-words.md)

Na linha de comando, as opções de vinculador não diferenciam maiúsculas de minúsculas; por exemplo, `/base` e `/BASE` significam a mesma coisa. Para obter detalhes sobre como especificar cada opção na linha de comando ou no Visual Studio, consulte a documentação para essa opção.

Você pode usar o [Comentário](../../preprocessor/comment-c-cpp.md) pragma para especificar algumas opções de vinculador.

## <a name="linker-options-listed-alphabetically"></a>Opções do vinculador listadas em ordem alfabética

|Opção|Finalidade|
|------------|-------------|
|[@](at-specify-a-linker-response-file.md)|Especifica um arquivo de resposta.|
|[/ALIGN](align-section-alignment.md)|Especifica o alinhamento de cada seção.|
|[/ALLOWBIND](allowbind-prevent-dll-binding.md)|Especifica que uma DLL não pode ser associada.|
|[/ALLOWISOLATION](allowisolation-manifest-lookup.md)|Especifica o comportamento da pesquisa de manifesto.|
|[/APPCONTAINER](appcontainer-windows-store-app.md)|Especifica se o aplicativo deve ser executado em um ambiente de processo appcontainer.|
|[/ASSEMBLYDEBUG](assemblydebug-add-debuggableattribute.md)|Adiciona o <xref:System.Diagnostics.DebuggableAttribute> a uma imagem gerenciada.|
|[/ASSEMBLYLINKRESOURCE](assemblylinkresource-link-to-dotnet-framework-resource.md)|Cria um link a um recurso gerenciado.|
|[/ASSEMBLYMODULE](assemblymodule-add-a-msil-module-to-the-assembly.md)|Especifica que um módulo MSIL (Microsoft Intermediate Language) deve ser importado para o assembly.|
|[/ASSEMBLYRESOURCE](assemblyresource-embed-a-managed-resource.md)|Insere um arquivo de recurso gerenciado em um assembly.|
|[/BASE](base-base-address.md)|Define um endereço básico para o programa.|
|[/CETCOMPAT](cetcompat.md)|Marca o binário como compatível com a pilha de sombra CET.|
|[/CGTHREADS](cgthreads-compiler-threads.md)|Define o número de threads cl.exe a serem usados na otimização e na geração do código quando a geração do código de tempo de vinculação é especificada.|
|[/CLRIMAGETYPE](clrimagetype-specify-type-of-clr-image.md)|Define o tipo (IJW, puro ou seguro) de uma imagem do CLR.|
|[/CLRSUPPORTLASTERROR](clrsupportlasterror-preserve-last-error-code-for-pinvoke-calls.md)|Preserva o código de erro mais recente de funções chamadas por meio do mecanismo P/Invoke.|
|[/CLRTHREADATTRIBUTE](clrthreadattribute-set-clr-thread-attribute.md)|Especifica o atributo de threading a ser aplicado ao ponto de entrada do programa do CLR.|
|[/CLRUNMANAGEDCODECHECK](clrunmanagedcodecheck-add-suppressunmanagedcodesecurityattribute.md)|Especifica se o vinculador aplicará o atributo SuppressUnmanagedCodeSecurity aos stubs PInvoke gerados pelo vinculador chamados do código gerenciado para DLLs nativas.|
|[/DEBUG](debug-generate-debug-info.md)|Cria informações de depuração.|
|[/DEBUGtype](debugtype-debug-info-options.md)|Especifica quais dados incluir nas informações de depuração.|
|[/DEF](def-specify-module-definition-file.md)|Passa um arquivo de definição do módulo (.def) para o vinculador.|
|[/DEFAULTLIB](defaultlib-specify-default-library.md)|Pesquisa a biblioteca especificada quando referências externas são resolvidas.|
|[/DELAY](delay-delay-load-import-settings.md)|Controla o carregamento atrasado de DLLs.|
|[/DELAYLOAD](delayload-delay-load-import.md)|Causa o carregamento atrasado da DLL especificada.|
|[/DELAYSIGN](delaysign-partially-sign-an-assembly.md)|Assina parcialmente um assembly.|
|[/DEPENDENTLOADFLAG](dependentloadflag.md)|Define sinalizadores padrão em cargas de DLL dependentes.|
|[/DLL](dll-build-a-dll.md)|Compila uma DLL.|
|[/DRIVER](driver-windows-nt-kernel-mode-driver.md)|Cria um driver de modo kernel.|
|[/DYNAMICBASE](dynamicbase-use-address-space-layout-randomization.md)|Especifica se deve gerar uma imagem executável com base no tempo de carregamento usando o recurso ASLR (Address Space layout Randomization).|
|[/ENTRY](entry-entry-point-symbol.md)|Define o endereço inicial.|
|[/ERRORREPORT](errorreport-report-internal-linker-errors.md)| Preterido. O relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) . |
|[/EXPORT](export-exports-a-function.md)|Exporta uma função.|
|[/FILEALIGN](filealign.md)|Alinha seções dentro do arquivo de saída em múltiplos de um valor especificado.|
|[/FIXED](fixed-fixed-base-address.md)|Cria um programa que só pode ser carregado em seu endereço básico preferido.|
|[/FORCE](force-force-file-output.md)|Força a conclusão de um link mesmo com símbolos não resolvidos ou símbolos definidos mais de uma vez.|
|[/FUNCTIONPADMIN](functionpadmin-create-hotpatchable-image.md)|Cria uma imagem que pode receber um hotpatch.|
|[/GENPROFILE,/FASTGENPROFILE](genprofile-fastgenprofile-generate-profiling-instrumented-build.md)|Essas duas opções especificam a geração de um *`.pgd`* arquivo pelo vinculador para dar suporte à otimização guiada por perfil (PGO). /GENPROFILE e/FASTGENPROFILE usam parâmetros padrão diferentes.|
|[/GUARD](guard-enable-guard-checks.md)|Habilita a proteção do protetor de fluxo de controle.|
|[/HEAP](heap-set-heap-size.md)|Define o tamanho do heap, em bytes.|
|[/HIGHENTROPYVA](highentropyva-support-64-bit-aslr.md)|Especifica o suporte para ASLR (Address Space Layout Randomization) de 64 bits de alta entropia.|
|[/IDLOUT](idlout-name-midl-output-files.md)|Especifica o nome do *`.idl`* arquivo e outros arquivos de saída de MIDL.|
|[/IGNORE](ignore-ignore-specific-warnings.md)|Suprime a saída de avisos do vinculador especificado.|
|[/IGNOREIDL](ignoreidl-don-t-process-attributes-into-midl.md)|Impede o processamento de informações de atributo em um *`.idl`* arquivo.|
|[/IMPLIB](implib-name-import-library.md)|Substitui o nome da biblioteca de importação padrão.|
|[/INCLUDE](include-force-symbol-references.md)|Força referências de símbolo.|
|[/INCREMENTAL](incremental-link-incrementally.md)|Controla a vinculação incremental.|
|[/INTEGRITYCHECK](integritycheck-require-signature-check.md)|Especifica que o módulo requer uma verificação de assinatura no momento do carregamento.|
|[/KEYCONTAINER](keycontainer-specify-a-key-container-to-sign-an-assembly.md)|Especifica um contêiner de chave para assinar um assembly.|
|[/KEYFILE](keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)|Especifica uma chave ou um par de chaves para assinar um assembly.|
|[/LARGEADDRESSAWARE](largeaddressaware-handle-large-addresses.md)|Informa ao compilador que o aplicativo oferece suporte a endereços maiores que dois gigabytes|
|[/LIBPATH](libpath-additional-libpath.md)|Especifica um caminho para pesquisar antes do caminho da biblioteca ambiental.|
|[/LINKREPRO](linkrepro.md)|Especifica um caminho para gerar artefatos de reprodução de link no.|
|[/LINKREPROTARGET](linkreprotarget.md)|Gera uma reprodução de link somente ao produzir o destino especificado. <sup>16,1</sup>|
|[/LTCG](ltcg-link-time-code-generation.md)|Especifica a geração do código de tempo de vinculação.|
|[/MACHINE](machine-specify-target-platform.md)|Especifica a plataforma de destino.|
|[/MANIFEST](manifest-create-side-by-side-assembly-manifest.md)|Cria um arquivo de manifesto lado a lado e, como opção, o insere no binário.|
|[/MANIFESTDEPENDENCY](manifestdependency-specify-manifest-dependencies.md)|Especifica uma \<dependentAssembly> seção no arquivo de manifesto.|
|[/MANIFESTFILE](manifestfile-name-manifest-file.md)|Altera o nome padrão do arquivo de manifesto.|
|[/MANIFESTINPUT](manifestinput-specify-manifest-input.md)|Especifica um arquivo de entrada do manifesto para o vinculador processar e inserir no binário. É possível usar essa opção várias vezes para especificar mais de um arquivo de entrada do manifesto.|
|[/MANIFESTUAC](manifestuac-embeds-uac-information-in-manifest.md)|Especifica se as informações do UAC (Controle de Conta de Usuário) estão inseridas no manifesto do programa.|
|[/MAP](map-generate-mapfile.md)|Cria um arquivo de mapa.|
|[/MAPINFO](mapinfo-include-information-in-mapfile.md)|Inclui as informações especificadas no arquivo de mapa.|
|[/MERGE](merge-combine-sections.md)|Combina seções.|
|[/MIDL](midl-specify-midl-command-line-options.md)|Especifica opções de linha de comando MIDL.|
|[/NATVIS](natvis-add-natvis-to-pdb.md)|Adiciona visualizadores de depurador de um arquivo Natvis ao banco de dados do programa (PDB).|
|[/NOASSEMBLY](noassembly-create-a-msil-module.md)|Suprime a criação de um assembly do .NET Framework.|
|[/NODEFAULTLIB](nodefaultlib-ignore-libraries.md)|Ignora todas as bibliotecas padrão (ou as especificadas) quando as referências externas são resolvidas.|
|[/NOENTRY](noentry-no-entry-point.md)|Cria uma DLL somente de recursos.|
|[/NOLOGO](nologo-suppress-startup-banner-linker.md)|Suprime a faixa de inicialização.|
|[/NXCOMPAT](nxcompat-compatible-with-data-execution-prevention.md)|Marca um executável como verificado como compatível com o recurso Prevenção de Execução de Dados do Windows.|
|[/OPT](opt-optimizations.md)|Controla otimizações de LINK.|
|[/ORDER](order-put-functions-in-order.md)|Coloca COMDATs na imagem em uma ordem predeterminada.|
|[/OUT](out-output-file-name.md)|Especifica o nome do arquivo de saída.|
|[/PDB](pdb-use-program-database.md)|Cria um arquivo PDB.|
|[/PDBALTPATH](pdbaltpath-use-alternate-pdb-path.md)|Usa um local alternativo para salvar um arquivo PDB.|
|[/PDBSTRIPPED](pdbstripped-strip-private-symbols.md)|Cria um arquivo PDB que não tem nenhum símbolo privado.|
|[/PGD](pgd-specify-database-for-profile-guided-optimizations.md)|Especifica um *`.pgd`* arquivo para otimizações guiadas por perfil.|
|[/POGOSAFEMODE](pogosafemode-linker-option.md)|**Obsoleto** Cria uma compilação instrumentada PGO thread-safe.|
|[/PROFILE](profile-performance-tools-profiler.md)|Produz um arquivo de saída que pode ser usado com o criador de perfil de Ferramentas de desempenho.|
|[/RELEASE](release-set-the-checksum.md)|Define a soma de verificação no *`.exe`* cabeçalho.|
|[/SAFESEH](safeseh-image-has-safe-exception-handlers.md)|Especifica que a imagem conterá uma tabela de manipuladores de exceção segura.|
|[/SECTION](section-specify-section-attributes.md)|Substitui os atributos de uma seção.|
|[/SOURCELINK](sourcelink.md)|Especifica um arquivo funcionalidade sourcelink a ser adicionado ao PDB.|
|[/STACK](stack-stack-allocations.md)|Define o tamanho da pilha, em bytes.|
|[/STUB](stub-ms-dos-stub-file-name.md)|Anexa um programa stub MS-DOS a um programa Win32.|
|[/SUBSYSTEM](subsystem-specify-subsystem.md)|Informa ao sistema operacional como executar o *`.exe`* arquivo.|
|[/SWAPRUN](swaprun-load-linker-output-to-swap-file.md)|Instrui o sistema operacional a copiar a saída do vinculador para um arquivo de permuta antes de ser executado.|
|[/TLBID](tlbid-specify-resource-id-for-typelib.md)|Especifica a ID de recurso da biblioteca de tipos gerada pelo vinculador.|
|[/TLBOUT](tlbout-name-dot-tlb-file.md)|Especifica o nome do *`.tlb`* arquivo e outros arquivos de saída de MIDL.|
|[/TSAWARE](tsaware-create-terminal-server-aware-application.md)|Cria um aplicativo projetado especialmente para ser executado no Terminal Server.|
|[/USEPROFILE](useprofile.md)|Usa dados de treinamento de Otimização Guiada por perfil para criar uma imagem otimizada.|
|[/VERBOSE](verbose-print-progress-messages.md)|Imprime mensagens de andamento do vinculador.|
|[/VERSION](version-version-information.md)|Atribui um número de versão.|
|[/WHOLEARCHIVE](wholearchive-include-all-library-object-files.md)|Inclui todos os arquivos de objeto das bibliotecas estáticas especificadas.|
|[/WINMD](winmd-generate-windows-metadata.md)|Habilita a geração de um arquivo de Metadados do Windows Runtime.|
|[/WINMDFILE](winmdfile-specify-winmd-file.md)|Especifica o nome de arquivo para o arquivo de saída de Windows Runtime de metadados (winmd) gerado pela opção de vinculador [/WINMD](winmd-generate-windows-metadata.md) .|
|[/WINMDKEYFILE](winmdkeyfile-specify-winmd-key-file.md)|Especifica uma chave ou um par de chaves para assinar um arquivo de Metadados do Windows Runtime.|
|[/WINMDKEYCONTAINER](winmdkeycontainer-specify-key-container.md)|Especifica um contêiner de chave para assinar um arquivo de Metadados do Windows.|
|[/WINMDDELAYSIGN](winmddelaysign-partially-sign-a-winmd.md)|Assina parcialmente um arquivo de Metadados de Windows Runtime (.winmd) colocando a chave pública no arquivo winmd.|
|[/WX](wx-treat-linker-warnings-as-errors.md)|Trata avisos de vinculador como erros.|

<sup>16,1</sup> essa opção está disponível a partir do Visual Studio 2019 versão 16,1.

## <a name="see-also"></a>Confira também

[Referência de compilação do C/C++](c-cpp-building-reference.md)\
[Referência de vinculador MSVC](linking.md)
