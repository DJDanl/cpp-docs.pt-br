---
title: Opções de compilador listadas por categoria
description: Listagem de referência por categoria das opções de linhaC++ de comando do Microsoft C/Compiler.
ms.date: 02/09/2020
helpviewer_keywords:
- compiler options, C++
ms.assetid: c4750dcf-dba0-4229-99b6-45cdecc11729
ms.openlocfilehash: d29076e6eae4bcbd15a4bc50bb48477e3f93152d
ms.sourcegitcommit: 8414cd91297dea88c480e208c7b5301db9972f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2020
ms.locfileid: "77257709"
---
# <a name="compiler-options-listed-by-category"></a>Opções de compilador listadas por categoria

Este artigo contém uma lista categórica de opções do compilador. Para uma lista alfabética, consulte [Opções de compilador listadas em ordem alfabética](compiler-options-listed-alphabetically.md).

## <a name="optimization"></a>Optimization

|Opção|Finalidade|
|------------|-------------|
|[/O1](o1-o2-minimize-size-maximize-speed.md)|Cria um código pequeno.|
|[/O2](o1-o2-minimize-size-maximize-speed.md)|Cria um código rápido.|
|[/Ob](ob-inline-function-expansion.md)|Controla a expansão embutida.|
|[/OD](od-disable-debug.md)|Desabilita a otimização.|
|[/Og](og-global-optimizations.md)|Preterido. Usa otimizações globais.|
|[/Oi](oi-generate-intrinsic-functions.md)|Gera funções intrínsecas.|
|[/Os](os-ot-favor-small-code-favor-fast-code.md)|Favorece código pequeno.|
|[/OT](os-ot-favor-small-code-favor-fast-code.md)|Favorece código rápido.|
|[/Ox](ox-full-optimization.md)|Um subconjunto de/O2 que não inclui/GF ou/GY.|
|[/Oy](oy-frame-pointer-omission.md)|Omita o ponteiro do quadro. (apenas x86)|
|[/favor](favor-optimize-for-architecture-specifics.md)|Produz código otimizado para uma arquitetura específica ou um intervalo de arquiteturas.|

## <a name="code-generation"></a>Geração de código

|Opção|Finalidade|
|------------|-------------|
|[/Arch](arch-x86.md)|Usa instruções SSE ou SSE2 na geração do código. (apenas x86)|
|[/clr](clr-common-language-runtime-compilation.md)|Produz um arquivo de saída a ser executado no Common Language Runtime.|
|[/EH](eh-exception-handling-model.md)|Especifica o modelo de tratamento de exceções.|
|[/FP](fp-specify-floating-point-behavior.md)|Especifica o comportamento de ponto flutuante.|
|[/GA](ga-optimize-for-windows-application.md)|Otimiza para aplicativos do Windows.|
|[/Gd](gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__cdecl`. (apenas x86)|
|[/GE](ge-enable-stack-probes.md)|Preterido. Ativa investigações de pilha.|
|[/GF](gf-eliminate-duplicate-strings.md)|Habilita pooling de cadeia de caracteres.|
|[/GH](gh-enable-penter-hook-function.md)|Chama a função de gancho `_penter`.|
|[/GH](gh-enable-pexit-hook-function.md)|Chama a função de gancho `_pexit`.|
|[/GL](gl-whole-program-optimization.md)|Habilita a otimização de todo o programa.|
|[/Gm](gm-enable-minimal-rebuild.md)|Preterido. Habilita recompilação mínima.|
|[/GR](gr-enable-run-time-type-information.md)|Habilita RTTI (informações de tipo de tempo de execução).|
|[/Gr](gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__fastcall`. (apenas x86)|
|[/GS](gs-buffer-security-check.md)|Verifica a segurança do buffer.|
|[/GS](gs-control-stack-checking-calls.md)|Controla investigações de pilha.|
|[/GT](gt-support-fiber-safe-thread-local-storage.md)|Dá suporte à segurança de fibra para dados alocados usando armazenamento de thread local estático.|
|[/Guard: cf](guard-enable-control-flow-guard.md)|Adiciona verificações de segurança de proteção de fluxo de controle.|
|[/Gv](gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__vectorcall`. (somente x86 e x64)|
|[/GW](gw-optimize-global-data.md)|Habilita a otimização de dados globais de todo o programa.|
|[/GX](gx-enable-exception-handling.md)|Preterido. Habilita o tratamento síncrono de exceções. Use [/eh](eh-exception-handling-model.md) em vez disso.|
|[/GY](gy-enable-function-level-linking.md)|Habilita a vinculação no nível de função.|
|[/GZ](gz-enable-stack-frame-run-time-error-checking.md)|Preterido. Habilita as verificações rápidas. (O mesmo que [/RTC1](rtc-run-time-error-checks.md))|
|[/Gz](gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__stdcall`. (apenas x86)|
|[/homeparams](homeparams-copy-register-parameters-to-stack.md)|Força os parâmetros passados em registros a serem gravados em seus locais na pilha mediante a entrada da função. Essa opção de compilador é apenas para compiladores x64 (nativa e de compilação cruzada).|
|[/hotpatch](hotpatch-create-hotpatchable-image.md)|Cria uma imagem capaz de aplicar patches sob demanda.|
|[/Qfast_transcendentals](qfast-transcendentals-force-fast-transcendentals.md)|Gera transcendentais rápidos.|
|[/QIfist](qifist-suppress-ftol.md)|Preterido. Suprime a chamada da função auxiliar `_ftol` quando é necessária uma conversão de um tipo de ponto flutuante para um tipo integral. (apenas x86)|
|[/Qimprecise_fwaits](qimprecise-fwaits-remove-fwaits-inside-try-blocks.md)|Remove comandos `fwait` dentro de blocos `try`.|
|[/QIntel-jcc-erratum](qintel-jcc-erratum.md)|Atenua o impacto no desempenho da atualização do microcódigo da Errata do Intel JCC.|
|[/Qpar](qpar-auto-parallelizer.md)|Habilita a paralelização automática de loops.|
|[/Qpar-Report](qpar-report-auto-parallelizer-reporting-level.md)|Habilita os níveis de relatório para paralelização automática.|
|[/Qsafe_fp_loads](qsafe-fp-loads.md)|Usa instruções de movimento de inteiro para valores de ponto flutuante e desabilita determinadas otimizações de carregamento de ponto flutuante.|
|[/Qspectre](qspectre.md)|Habilitar mitigações para o CVE 2017-5753, para uma classe de ataques de Spectre.|
|[/Qspectre-load](qspectre-load.md)|Gerar instruções de serialização para cada instrução de carga.|
|[/Qspectre-load-cf](qspectre-load-cf.md)|Gere instruções de serialização para cada instrução de fluxo de controle que carregue a memória.|
|[/Qvec-Report](qvec-report-auto-vectorizer-reporting-level.md)|Habilita níveis de relatório para vetorização automática.|
|[/RTC](rtc-run-time-error-checks.md)|Habilita a verificação de erro em tempo de execução.|
|[/volatile](volatile-volatile-keyword-interpretation.md)|Seleciona como a palavra-chave volátil é interpretada.|

## <a name="output-files"></a>Arquivos de saída

|Opção|Finalidade|
|------------|-------------|
|[/doc](doc-process-documentation-comments-c-cpp.md)|Processa comentários de documentação para um arquivo XML.|
|[/FA](fa-fa-listing-file.md)|Configura um arquivo de listagem de assembly.|
|[/FA](fa-fa-listing-file.md)|Cria um arquivo de listagem de assembly.|
|[/FD](fd-program-database-file-name.md)|Renomeia o arquivo de banco de dados do programa.|
|[/Fe](fe-name-exe-file.md)|Renomeia o arquivo executável.|
|[/Fi](fi-preprocess-output-file-name.md)|Especifica o nome do arquivo de saída pré-processado.|
|[/FM](fm-name-mapfile.md)|Cria um arquivo de mapa.|
|[/Fo](fo-object-file-name.md)|Cria um arquivo de objeto.|
|[/FP](fp-name-dot-pch-file.md)|Especifica um nome de arquivo de cabeçalho pré-compilado.|
|[/FR,/fr](fr-fr-create-dot-sbr-file.md)|Nome gerado *`.sbr`* arquivos de navegador.|

## <a name="preprocessor"></a>Pré-processador

|Opção|Finalidade|
|------------|-------------|
|[/AI](ai-specify-metadata-directories.md)|Especifica um diretório a ser pesquisado para resolver as referências de arquivo passadas para a diretiva [#using](../../preprocessor/hash-using-directive-cpp.md) .|
|[/C](c-preserve-comments-during-preprocessing.md)|Preserva comentários durante o pré-processamento.|
|[/D](d-preprocessor-definitions.md)|Define constantes e macros.|
|[/E](e-preprocess-to-stdout.md)|Copia a saída do pré-processador para a saída padrão.|
|[/EP](ep-preprocess-to-stdout-without-hash-line-directives.md)|Copia a saída do pré-processador para a saída padrão.|
|[/FI](fi-name-forced-include-file.md)|Pré-processa o arquivo de inclusão especificado.|
|[/FU](fu-name-forced-hash-using-file.md)|Força o uso de um nome de arquivo, como se ele tivesse sido passado para a diretiva [#using](../../preprocessor/hash-using-directive-cpp.md) .|
|[/FX](fx-merge-injected-code.md)|Mescla o código injetado com o arquivo de origem.|
|[/I](i-additional-include-directories.md)|Pesquisa um diretório para incluir arquivos.|
|[/P](p-preprocess-to-a-file.md)|Grava a saída do pré-processador em um arquivo.|
|[/U](u-u-undefine-symbols.md)|Remove uma macro predefinida.|
|[/u](u-u-undefine-symbols.md)|Remove todas as macros predefinidas.|
|[/X](x-ignore-standard-include-paths.md)|Ignora o diretório de inclusão padrão.|

## <a name="language"></a>Linguagem

|Opção|Finalidade|
|------------|-------------|
|[/constexpr](constexpr-control-constexpr-evaluation.md)|Controle a avaliação **constexpr** no momento da compilação.|
|[/OpenMP](openmp-enable-openmp-2-0-support.md)|Habilita [#pragma OMP](../../preprocessor/omp.md) no código-fonte.|
|[/vd](vd-disable-construction-displacements.md)|Suprime ou habilita membros da classe `vtordisp` ocultos.|
|[/VMB](vmb-vmg-representation-method.md)|Usa a melhor base de ponteiros para membros.|
|[/VMG](vmb-vmg-representation-method.md)|Usa a generalidade completa de ponteiros para membros.|
|[/VMM](vmm-vms-vmv-general-purpose-representation.md)|Declara a herança múltipla.|
|[/VMs](vmm-vms-vmv-general-purpose-representation.md)|Declara a herança única.|
|[/vmv](vmm-vms-vmv-general-purpose-representation.md)|Declara a herança virtual.|
|[/Z7](z7-zi-zi-debug-information-format.md)|Gera informações de depuração compatíveis com o C 7,0.|
|[/Za](za-ze-disable-language-extensions.md)|Desabilita as extensões de linguagem C89.|
|[/Zc](zc-conformance.md)|Especifica o comportamento padrão em [/ze](za-ze-disable-language-extensions.md).|
|[/Ze](za-ze-disable-language-extensions.md)|Preterido. Habilita extensões de linguagem C89.|
|[/ZF](zf.md)|Melhora o tempo de geração de PDB em compilações paralelas.|
|[/ZH](zh.md)|Especifica MD5, SHA-1 ou SHA-256 para somas de verificação nas informações de depuração.|
|[/ZI](z7-zi-zi-debug-information-format.md)|Inclui informações de depuração em um banco de dados do programa compatível com Editar e Continuar. (apenas x86)|
|[/Zi](z7-zi-zi-debug-information-format.md)|Gera informações completas de depuração.|
|[/Zl](zl-omit-default-library-name.md)|Remove o nome da biblioteca padrão do arquivo *`.obj`* .|
|[/ZP](zp-struct-member-alignment.md) *n*|Empacota membros da estrutura.|
|[/ZS](zs-syntax-check-only.md)|Verifica apenas a sintaxe.|
|[/ZW](zw-windows-runtime-compilation.md)|Produz um arquivo de saída para ser executado no Windows Runtime.|

## <a name="linking"></a>Vinculação

|Opção|Finalidade|
|------------|-------------|
|[F](f-set-stack-size.md)|Define o tamanho da pilha.|
|[/LD](md-mt-ld-use-run-time-library.md)|Cria uma biblioteca de vínculo dinâmico.|
|[/LDd](md-mt-ld-use-run-time-library.md)|Cria uma biblioteca de vínculo dinâmico de depuração.|
|[/link](link-pass-options-to-linker.md)|Passa a opção especificada para LINK.|
|[/LN](ln-create-msil-module.md)|Cria um módulo MSIL.|
|[/MD](md-mt-ld-use-run-time-library.md)|Compila para criar uma DLL multithread, usando *msvcrt. lib*.|
|[/MDd](md-mt-ld-use-run-time-library.md)|Compila para criar uma DLL de depuração multithread, usando *MSVCRTD. lib*.|
|[/MT](md-mt-ld-use-run-time-library.md)|Compila para criar um arquivo executável multi-threaded, usando *LIBCMT. lib*.|
|[/MTd](md-mt-ld-use-run-time-library.md)|Compila para criar um arquivo executável com vários threads de depuração, usando *LIBCMTD. lib*.|

## <a name="miscellaneous"></a>Diversos

|Opção|Finalidade|
|------------|-------------|
|[/?](help-compiler-command-line-help.md)|Lista as opções do compilador.|
|[@](at-specify-a-compiler-response-file.md)|Especifica um arquivo de resposta.|
|[/Analyze](analyze-code-analysis.md)|Habilita a análise de código.|
|[/bigobj](bigobj-increase-number-of-sections-in-dot-obj-file.md)|Aumenta o número de seções endereçáveis em um arquivo .obj.|
|[/c](c-compile-without-linking.md)|Compila sem vinculação.|
|[/cgthreads](cgthreads-code-generation-threads.md)|Especifica o número de threads *CL. exe* a serem usados para otimização e geração de código.|
|[/errorReport](errorreport-report-internal-compiler-errors.md)| Preterido. O relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) . |
|[/FC](fc-full-path-of-source-code-file-in-diagnostics.md)|Exibe o caminho completo dos arquivos de código-fonte passados para *CL. exe* no texto de diagnóstico.|
|[/FS](fs-force-synchronous-pdb-writes.md)|Força as gravações no arquivo PDB a serem serializadas por meio de *MSPDBSRV. EXE*.|
|[/H](h-restrict-length-of-external-names.md)|Preterido. Restringe o tamanho de nomes externos (públicos).|
|[/HELP](help-compiler-command-line-help.md)|Lista as opções do compilador.|
|[/J](j-default-char-type-is-unsigned.md)|Altera o tipo `char` padrão.|
|[/JMC](jmc.md)|Dá suporte C++ à depuração de apenas meu código nativo.|
|[/kernel](kernel-create-kernel-mode-binary.md)|O compilador e o vinculador criará um binário que pode ser executado no kernel do Windows.|
|[/MP](mp-build-with-multiple-processes.md)|Cria vários arquivos de origem ao mesmo tempo.|
|[/nologo](nologo-suppress-startup-banner-c-cpp.md)|Suprime a exibição da faixa de logon.|
|[/SDL](sdl-enable-additional-security-checks.md)|Habilita os recursos e os avisos de segurança adicionais.|
|[/showIncludes](showincludes-list-include-files.md)|Exibe uma lista de todos os arquivos de inclusão durante a compilação.|
|[/TC](tc-tp-tc-tp-specify-source-file-type.md)|Especifica um arquivo de origem do C.|
|[/TC](tc-tp-tc-tp-specify-source-file-type.md)|Especifica que todos os arquivos de origem são C.|
|[/TP](tc-tp-tc-tp-specify-source-file-type.md)|Especifica um arquivo de origem do C++.|
|[/TP](tc-tp-tc-tp-specify-source-file-type.md)|Especifica que todos os arquivos C++de origem são.|
|[/V](v-version-number.md)|Preterido. Define a cadeia de caracteres da versão.|
|[/w](compiler-option-warning-level.md)|Desabilita todos os avisos.|
|[/W0,/W1,/W2,/W3,/W4](compiler-option-warning-level.md)|Define o nível de aviso de saída.|
|[/W1,/W2,/W3,/W4](compiler-option-warning-level.md)|Define o nível de aviso para o aviso especificado.|
|[/Wall](compiler-option-warning-level.md)|Habilita todos os avisos, inclusive avisos desabilitados por padrão.|
|[/WD](compiler-option-warning-level.md)|Desabilita o aviso especificado.|
|[/we](compiler-option-warning-level.md)|Trata o aviso especificado como um erro.|
|[/WL](wl-enable-one-line-diagnostics.md)|Habilita o diagnóstico em uma linha para mensagens de erro e aviso durante a compilação do código-fonte do C++ da linha de comando.|
|[/wo](compiler-option-warning-level.md)|Exibe o aviso especificado apenas uma vez.|
|[/WV](compiler-option-warning-level.md)|Desabilita os avisos introduzidos pelas versões posteriores do compilador.|
|[/WX](compiler-option-warning-level.md)|Trata avisos como erros.|
|[/Yc](yc-create-precompiled-header-file.md)|Criar *`.PCH`* arquivo.|
|[/YD](yd-place-debug-information-in-object-file.md)|Preterido. Coloca informações de depuração completas em todos os arquivos de objeto. Em vez disso, use [/Zi](z7-zi-zi-debug-information-format.md) .|
|[/YL](yl-inject-pch-reference-for-debug-library.md)|Injeta uma referência PCH durante a criação de uma biblioteca de depuração.|
|[/Yu](yu-use-precompiled-header-file.md)|Usa um arquivo de cabeçalho pré-compilado durante a compilação.|
|[/Y-](y-ignore-precompiled-header-options.md)|Ignora todas as outras opções de compilador do cabeçalho pré-compilado na compilação atual.|
|[/ZM](zm-specify-precompiled-header-memory-allocation-limit.md)|Especifica o limite de alocação da memória do cabeçalho pré-compilado.|
|[/Await](await-enable-coroutine-support.md)|Habilite as extensões de corrotinas (funções retomáveis).|
|[/Source-charset](source-charset-set-source-character-set.md)|Definir conjunto de caracteres de origem.|
|[/Execution-charset](execution-charset-set-execution-character-set.md)|Definir conjunto de caracteres de execução.|
|[/UTF-8](utf-8-set-source-and-executable-character-sets-to-utf-8.md)|Defina os conjuntos de caracteres de origem e de execução como UTF-8.|
|[/Validate-charset](validate-charset-validate-for-compatible-characters.md)|Valide os arquivos UTF-8 somente para caracteres compatíveis.|
|[/diagnostics](diagnostics-compiler-diagnostic-options.md)|Controla o formato das mensagens de diagnóstico.|
|[/permissive-](permissive-standards-conformance.md)|Definir o modo de conformidade padrão.|
|[/STD](std-specify-language-standard-version.md)|C++seletor de compatibilidade de versão padrão.|

## <a name="experimental-options"></a>Opções experimentais

As opções experimentais só podem ser suportadas por determinadas versões do compilador. Eles também podem se comportar de forma diferente em versões diferentes do compilador. Geralmente, a melhor documentação, ou apenas, para opções experimentais está [no C++ blog da equipe da Microsoft](https://devblogs.microsoft.com/cppblog/).

|Opção|Finalidade|
|------------|-------------|
|[/experimental: módulo](experimental-module.md)|Habilita o suporte a módulo experimental.|
|[/experimental: pré-processador](experimental-preprocessor.md)|Habilita o suporte a pré-processador de conformidade experimental.|

## <a name="deprecated-and-removed-compiler-options"></a>Opções de compilador preteridas e removidas

|Opção|Finalidade|
|------------|-------------|
|[/CLR: noAssembly](clr-common-language-runtime-compilation.md)|Preterido. Use [/LN (Criar módulo da MSIL)](ln-create-msil-module.md).|
|[/errorReport](errorreport-report-internal-compiler-errors.md)| Preterido. O relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) . |
|[/Fr](fr-fr-create-dot-sbr-file.md)|Preterido. Cria um arquivo de informações de procura sem variáveis locais.|
|[/GE](ge-enable-stack-probes.md)|Preterido. Ativa investigações de pilha. Ativado por padrão.|
|[/Gm](gm-enable-minimal-rebuild.md)|Preterido. Habilita recompilação mínima.|
|[/GX](gx-enable-exception-handling.md)|Preterido. Habilita o tratamento síncrono de exceções. Use [/eh](eh-exception-handling-model.md) em vez disso.|
|[/GZ](gz-enable-stack-frame-run-time-error-checking.md)|Preterido. Habilita as verificações rápidas. Use [/RTC1](rtc-run-time-error-checks.md) em vez disso.|
|[/H](h-restrict-length-of-external-names.md)|Preterido. Restringe o tamanho de nomes externos (públicos).|
|[/Og](og-global-optimizations.md)|Preterido. Usa otimizações globais.|
|[/QIfist](qifist-suppress-ftol.md)|Preterido. Uma vez usado para especificar como converter de um tipo de ponto flutuante para um tipo integral.|
|[/V](v-version-number.md)|Preterido. Define a cadeia de caracteres de versão do arquivo *`.obj`* .|
|[/Wp64](wp64-detect-64-bit-portability-issues.md)|Obsoleto. Detecta problemas de portabilidade de 64 bits.|
|[/YD](yd-place-debug-information-in-object-file.md)|Preterido. Coloca informações de depuração completas em todos os arquivos de objeto. Em vez disso, use [/Zi](z7-zi-zi-debug-information-format.md) .|
|[/Zc: forScope-](zc-forscope-force-conformance-in-for-loop-scope.md)|Preterido. Desabilita a conformidade no escopo do loop for.|
|[/Ze](za-ze-disable-language-extensions.md)|Preterido. Habilita extensões de linguagem.|
|[/Zg](zg-generate-function-prototypes.md)|Removido no Visual Studio 2015. Gera protótipos de função.|

## <a name="see-also"></a>Confira também

[C/C++ compilando](c-cpp-building-reference.md)\ de referência
[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
