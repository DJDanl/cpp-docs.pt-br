---
title: "Opções do compilador listadas por categoria | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: compiler options, C++
ms.assetid: c4750dcf-dba0-4229-99b6-45cdecc11729
caps.latest.revision: "64"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ec2b8f0f05da535fd6a4f212a08af847c997a860
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-options-listed-by-category"></a>Opções de compilador listadas por categoria
Este artigo contém uma lista categórica de opções do compilador. Para obter uma lista, consulte [compilador opções listadas em ordem alfabética](../../build/reference/compiler-options-listed-alphabetically.md).  
  
### <a name="optimization"></a>Otimização  
  
|Opção|Finalidade|  
|------------|-------------|  
|[/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md)|Cria um código pequeno.|  
|[/ O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md)|Cria um código rápido.|  
|[/Ob](../../build/reference/ob-inline-function-expansion.md)|Controla a expansão embutida.|  
|[/Od](../../build/reference/od-disable-debug.md)|Desabilita a otimização.|  
|[/Og](../../build/reference/og-global-optimizations.md)|Preterido. Usa otimizações globais.|  
|[/Oi](../../build/reference/oi-generate-intrinsic-functions.md)|Gera funções intrínsecas.|  
|[/Os](../../build/reference/os-ot-favor-small-code-favor-fast-code.md)|Favorece código pequeno.|  
|[/OT](../../build/reference/os-ot-favor-small-code-favor-fast-code.md)|Favorece código rápido.|  
|[/OX](../../build/reference/ox-full-optimization.md)|Usa a otimização máxima (/Ob2gity /Gs).|  
|[/Oy](../../build/reference/oy-frame-pointer-omission.md)|Omita o ponteiro do quadro. (apenas x86)|  
|[/favor](../../build/reference/favor-optimize-for-architecture-specifics.md)|Produz código otimizado para uma arquitetura específica ou um intervalo de arquiteturas.|  
  
### <a name="code-generation"></a>Geração de código  
  
|Opção|Finalidade|  
|------------|-------------|  
|[/arch](../../build/reference/arch-x86.md)|Usa instruções SSE ou SSE2 na geração do código. (apenas x86)|  
|[/clr](../../build/reference/clr-common-language-runtime-compilation.md)|Produz um arquivo de saída a ser executado no Common Language Runtime.|  
|[/EH](../../build/reference/eh-exception-handling-model.md)|Especifica o modelo de tratamento de exceções.|  
|[/FP](../../build/reference/fp-specify-floating-point-behavior.md)|Especifica o comportamento de ponto flutuante.|  
|[/GA](../../build/reference/ga-optimize-for-windows-application.md)|Otimiza para aplicativos do Windows.|  
|[/Gd](../../build/reference/gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__cdecl`. (apenas x86)|  
|[/GE](../../build/reference/ge-enable-stack-probes.md)|Preterido. Ativa investigações de pilha.|  
|[/GF](../../build/reference/gf-eliminate-duplicate-strings.md)|Habilita pooling de cadeia de caracteres.|  
|[/GH](../../build/reference/gh-enable-penter-hook-function.md)|Chama a função de gancho `_penter`.|  
|[/GH](../../build/reference/gh-enable-pexit-hook-function.md)|Chama a função de gancho `_pexit`.|  
|[/GL](../../build/reference/gl-whole-program-optimization.md)|Habilita a otimização de todo o programa.|  
|[/GM manual](../../build/reference/gm-enable-minimal-rebuild.md)|Habilita recompilação mínima.|  
|[/GR](../../build/reference/gr-enable-run-time-type-information.md)|Habilita RTTI (informações de tipo de tempo de execução).|  
|[/GR](../../build/reference/gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__fastcall`. (apenas x86)|  
|[/GS](../../build/reference/gs-buffer-security-check.md)|Verifica a segurança do buffer.|  
|[/GS](../../build/reference/gs-control-stack-checking-calls.md)|Controla investigações de pilha.|  
|[/GT](../../build/reference/gt-support-fiber-safe-thread-local-storage.md)|Dá suporte à segurança de fibra para dados alocados usando armazenamento de thread local estático.|  
|[/Guard: CF](../../build/reference/guard-enable-control-flow-guard.md)|Adiciona verificações de segurança de proteção de fluxo de controle.|  
|[/GV](../../build/reference/gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__vectorcall`. (somente x86 e x64)|  
|[/GW](../../build/reference/gw-optimize-global-data.md)|Habilita a otimização de dados globais de todo o programa.|  
|[/GX](../../build/reference/gx-enable-exception-handling.md)|Preterido. Habilita o tratamento síncrono de exceções. Use [/EH](../../build/reference/eh-exception-handling-model.md) em vez disso.|  
|[/Gy](../../build/reference/gy-enable-function-level-linking.md)|Habilita a vinculação no nível de função.|  
|[/GZ](../../build/reference/gz-enable-stack-frame-run-time-error-checking.md)|Preterido. Habilita as verificações rápidas. (Mesmo que [/RTC1](../../build/reference/rtc-run-time-error-checks.md))|  
|[/Gz](../../build/reference/gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__stdcall`. (apenas x86)|  
|[/homeparams](../../build/reference/homeparams-copy-register-parameters-to-stack.md)|Força os parâmetros passados em registros a serem gravados em seus locais na pilha mediante a entrada da função. Esta opção do compilador se destina apenas aos compiladores [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] (nativos e de compilação cruzada).|  
|[/hotpatch](../../build/reference/hotpatch-create-hotpatchable-image.md)|Cria uma imagem capaz de aplicar patches sob demanda.|  
|[/Qfast_transcendentals](../../build/reference/qfast-transcendentals-force-fast-transcendentals.md)|Gera transcendentais rápidos.|  
|[QIfist](../../build/reference/qifist-suppress-ftol.md)|Preterido. Suprime a chamada da função auxiliar `_ftol` quando é necessária uma conversão de um tipo de ponto flutuante para um tipo integral. (apenas x86)|  
|[/Qimprecise_fwaits](../../build/reference/qimprecise-fwaits-remove-fwaits-inside-try-blocks.md)|Remove comandos `fwait` dentro de blocos `try`.|  
|[/Qpar](../../build/reference/qpar-auto-parallelizer.md)|Habilita a paralelização automática de loops.|  
|[/Qpar-Report](../../build/reference/qpar-report-auto-parallelizer-reporting-level.md)|Habilita os níveis de relatório para paralelização automática.|  
|[/Qsafe_fp_loads](../../build/reference/qsafe-fp-loads.md)|Usa instruções de movimento de inteiro para valores de ponto flutuante e desabilita determinadas otimizações de carregamento de ponto flutuante.|  
|[/Qvec-Report (nível de Vetorizador automático relatórios)](../../build/reference/qvec-report-auto-vectorizer-reporting-level.md)|Habilita níveis de relatório para vetorização automática.|  
|[/RTC](../../build/reference/rtc-run-time-error-checks.md)|Habilita a verificação de erro em tempo de execução.|  
|[/ volátil](../../build/reference/volatile-volatile-keyword-interpretation.md)|Seleciona como a palavra-chave volátil é interpretada.|  
  
### <a name="output-files"></a>Arquivos de saída  
  
|Opção|Finalidade|  
|------------|-------------|  
|[/doc](../../build/reference/doc-process-documentation-comments-c-cpp.md)|Processa comentários de documentação para um arquivo XML.|  
|[/FA](../../build/reference/fa-fa-listing-file.md)|Configura um arquivo de listagem de assembly.|  
|[/FA](../../build/reference/fa-fa-listing-file.md)|Cria um arquivo de listagem de assembly.|  
|[/FD](../../build/reference/fd-program-database-file-name.md)|Renomeia o arquivo de banco de dados do programa.|  
|[/FE](../../build/reference/fe-name-exe-file.md)|Renomeia o arquivo executável.|  
|[/Fi](../../build/reference/fi-preprocess-output-file-name.md)|Especifica o nome do arquivo de saída pré-processado.|  
|[/FM](../../build/reference/fm-name-mapfile.md)|Cria um arquivo de mapa.|  
|[/FO](../../build/reference/fo-object-file-name.md)|Cria um arquivo de objeto.|  
|[/FP](../../build/reference/fp-name-dot-pch-file.md)|Especifica um nome de arquivo de cabeçalho pré-compilado.|  
|[/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) [/Fr](../../build/reference/fr-fr-create-dot-sbr-file.md)|Gera arquivos de navegador.|  
  
### <a name="preprocessor"></a>Pré-processador  
  
|Opção|Finalidade|  
|------------|-------------|  
|[/AI](../../build/reference/ai-specify-metadata-directories.md)|Especifica um diretório a pesquisar para resolver as referências do arquivo passado para o [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva.|  
|[/C](../../build/reference/c-preserve-comments-during-preprocessing.md)|Preserva comentários durante o pré-processamento.|  
|[/D](../../build/reference/d-preprocessor-definitions.md)|Define constantes e macros.|  
|[/E](../../build/reference/e-preprocess-to-stdout.md)|Copia a saída do pré-processador para a saída padrão.|  
|[/EP](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md)|Copia a saída do pré-processador para a saída padrão.|  
|[/FI](../../build/reference/fi-name-forced-include-file.md)|Pré-processa o arquivo de inclusão especificado.|  
|[/FU](../../build/reference/fu-name-forced-hash-using-file.md)|Força o uso de um nome de arquivo, como se ele tivesse foi passado para o [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva.|  
|[/FX](../../build/reference/fx-merge-injected-code.md)|Mescla o código injetado com o arquivo de origem.|  
|[/I](../../build/reference/i-additional-include-directories.md)|Pesquisa um diretório para incluir arquivos.|  
|[/ P](../../build/reference/p-preprocess-to-a-file.md)|Grava a saída do pré-processador em um arquivo.|  
|[/ U](../../build/reference/u-u-undefine-symbols.md)|Remove uma macro predefinida.|  
|[/u](../../build/reference/u-u-undefine-symbols.md)|Remove todas as macros predefinidas.|  
|[/X](../../build/reference/x-ignore-standard-include-paths.md)|Ignora o diretório de inclusão padrão.|  
  
### <a name="language"></a>Idioma  
  
|Opção|Finalidade|  
|------------|-------------|  
|[/constexpr](constexpr-control-constexpr-evaluation.md)|Avaliação de constexpr de controle em tempo de compilação.|  
|[/OpenMP](../../build/reference/openmp-enable-openmp-2-0-support.md)|Permite [#pragma omp](../../preprocessor/omp.md) no código-fonte.|  
|[/VD](../../build/reference/vd-disable-construction-displacements.md)|Suprime ou habilita membros da classe `vtordisp` ocultos.|  
|[/vmb](../../build/reference/vmb-vmg-representation-method.md)|Usa a melhor base de ponteiros para membros.|  
|[/vmg](../../build/reference/vmb-vmg-representation-method.md)|Usa a generalidade completa de ponteiros para membros.|  
|[/VMM](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)|Declara a herança múltipla.|  
|[/VMs](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)|Declara a herança única.|  
|[/vmv](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)|Declara a herança virtual.|  
|[/Z7](../../build/reference/z7-zi-zi-debug-information-format.md)|Gera C compatível com 7.0 informações de depuração.|  
|[/Za](../../build/reference/za-ze-disable-language-extensions.md)|Desabilita extensões de linguagem.|  
|[/ZC](../../build/reference/zc-conformance.md)|Especifica o comportamento padrão em [/Ze](../../build/reference/za-ze-disable-language-extensions.md).|  
|[/Ze](../../build/reference/za-ze-disable-language-extensions.md)|Preterido. Habilita extensões de linguagem.|  
|[/ZI](../../build/reference/z7-zi-zi-debug-information-format.md)|Inclui informações de depuração em um banco de dados do programa compatível com Editar e Continuar. (apenas x86)|  
|[/Zi](../../build/reference/z7-zi-zi-debug-information-format.md)|Gera informações completas de depuração.|  
|[/ZL](../../build/reference/zl-omit-default-library-name.md)|Remove o nome da biblioteca padrão do arquivo .obj.|  
|[/ZP](../../build/reference/zp-struct-member-alignment.md)*n*|Empacota membros da estrutura.|  
|[/ZS](../../build/reference/zs-syntax-check-only.md)|Verifica apenas a sintaxe.|  
|[/ZW](../../build/reference/zw-windows-runtime-compilation.md)|Produz um arquivo de saída para ser executado no tempo de execução do Windows.|  
  
### <a name="linking"></a>Vinculação  
  
|Opção|Finalidade|  
|------------|-------------|  
|[/F](../../build/reference/f-set-stack-size.md)|Define o tamanho da pilha.|  
|[/LD](../../build/reference/md-mt-ld-use-run-time-library.md)|Cria uma biblioteca de vínculo dinâmico.|  
|[/Ldd](../../build/reference/md-mt-ld-use-run-time-library.md)|Cria uma biblioteca de vínculo dinâmico de depuração.|  
|[/link](../../build/reference/link-pass-options-to-linker.md)|Passa a opção especificada para LINK.|  
|[/LN](../../build/reference/ln-create-msil-module.md)|Cria um módulo MSIL.|  
|[/MD](../../build/reference/md-mt-ld-use-run-time-library.md)|Compila para criar DLL com multithread usando MSVCRT.lib.|  
|[/MDd](../../build/reference/md-mt-ld-use-run-time-library.md)|Compila para criar DLL com multithread de depuração usando MSVCRTD.lib.|  
|[/MT](../../build/reference/md-mt-ld-use-run-time-library.md)|Compila para criar um arquivo executável com multithread usando LIBCMT.lib.|  
|[/MTd](../../build/reference/md-mt-ld-use-run-time-library.md)|Compila para criar um arquivo executável com multithread de depuração usando LIBCMTD.lib.|  
  
### <a name="miscellaneous"></a>Diversos  
  
|Opção|Finalidade|  
|------------|-------------|  
|[/?](../../build/reference/help-compiler-command-line-help.md)|Lista as opções do compilador.|  
|[@](../../build/reference/at-specify-a-compiler-response-file.md)|Especifica um arquivo de resposta.|  
|[/ANALYZE](../../build/reference/analyze-code-analysis.md)|Habilita a análise de código.|  
|[/bigobj](../../build/reference/bigobj-increase-number-of-sections-in-dot-obj-file.md)|Aumenta o número de seções endereçáveis em um arquivo .obj.|  
|[/c](../../build/reference/c-compile-without-linking.md)|Compila sem vinculação.|  
|[/cgthreads](../../build/reference/cgthreads-code-generation-threads.md)|Especifica o número de threads cl.exe a serem usados na otimização e na geração de código.|  
|[/errorReport](../../build/reference/errorreport-report-internal-compiler-errors.md)|Permite fornecer informações de ICE (erro interno do compilador) diretamente à equipe do Visual C++.|  
|[/FC](../../build/reference/fc-full-path-of-source-code-file-in-diagnostics.md)|Exibe o caminho completo dos arquivos de código-fonte passados para cl.exe em texto de diagnóstico.|  
|[/FS](../../build/reference/fs-force-synchronous-pdb-writes.md)|Força a serialização de gravações no arquivo de PDB (banco de dados do programa) por meio de MSPDBSRV.EXE.|  
|[/H](../../build/reference/h-restrict-length-of-external-names.md)|Preterido. Restringe o tamanho de nomes externos (públicos).|  
|[/ AJUDA](../../build/reference/help-compiler-command-line-help.md)|Lista as opções do compilador.|  
|[/J](../../build/reference/j-default-char-type-is-unsigned.md)|Altera o tipo `char` padrão.|  
|[/kernel](../../build/reference/kernel-create-kernel-mode-binary.md)|O compilador e o vinculador criará um binário que pode ser executado no kernel do Windows.|  
|[/MP](../../build/reference/mp-build-with-multiple-processes.md)|Cria vários arquivos de origem ao mesmo tempo.|  
|[/nologo](../../build/reference/nologo-suppress-startup-banner-c-cpp.md)|Suprime a exibição da faixa de logon.|  
|[/SDL](../../build/reference/sdl-enable-additional-security-checks.md)|Habilita os recursos e os avisos de segurança adicionais.|  
|[/showIncludes](../../build/reference/showincludes-list-include-files.md)|Exibe uma lista de todos os arquivos de inclusão durante a compilação.|  
|[/TC](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md)|Especifica um arquivo de origem do C.|  
|[/TC](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md)|Especifica que todos os arquivos de origem estão C.|  
|[/TP](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md)|Especifica um arquivo de origem do C++.|  
|[/TP](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md)|Especifica todos os arquivos de origem C++.|  
|[/V](../../build/reference/v-version-number.md)|Preterido. Define a cadeia de caracteres da versão.|  
|[/w](../../build/reference/compiler-option-warning-level.md)|Desabilita todos os avisos.|  
|[/ W0, /W1, /W2, /W3, /W4](../../build/reference/compiler-option-warning-level.md)|Define o nível de aviso de saída.|  
|[/W1, /w2, /w3, /w4](../../build/reference/compiler-option-warning-level.md)|Define o aviso de nível de aviso especificado.|  
|[/ Parede](../../build/reference/compiler-option-warning-level.md)|Habilita todos os avisos, inclusive avisos desabilitados por padrão.|  
|[/WD](../../build/reference/compiler-option-warning-level.md)|Desabilita o aviso especificado.|  
|[/We<n>](../../build/reference/compiler-option-warning-level.md)|Trata o aviso especificado como um erro.|  
|[/WL](../../build/reference/wl-enable-one-line-diagnostics.md)|Habilita o diagnóstico em uma linha para mensagens de erro e aviso durante a compilação do código-fonte do C++ da linha de comando.|  
|[/WO](../../build/reference/compiler-option-warning-level.md)|Exibe o aviso especificado somente uma vez.|  
|[/WV](../../build/reference/compiler-option-warning-level.md)|Desabilita avisos introduzidos em versões posteriores do compilador.|  
|[/WX](../../build/reference/compiler-option-warning-level.md)|Trata avisos como erros.|  
|[/Yc](../../build/reference/yc-create-precompiled-header-file.md)|Crie. Arquivo PCH.|  
|[/Yd](../../build/reference/yd-place-debug-information-in-object-file.md)|Preterido. Coloca informações de depuração completas em todos os arquivos de objeto. Use [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) em vez disso.|  
|[/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md)|Injeta uma referência PCH durante a criação de uma biblioteca de depuração.|  
|[/Yu](../../build/reference/yu-use-precompiled-header-file.md)|Usa um arquivo de cabeçalho pré-compilado durante a compilação.|  
|[/Y-](../../build/reference/y-ignore-precompiled-header-options.md)|Ignora todas as outras opções de compilador do cabeçalho pré-compilado na compilação atual.|  
|[/ZM](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md)|Especifica o limite de alocação da memória do cabeçalho pré-compilado.|  
|[/ await](await-enable-coroutine-support.md)|Habilite extensões co-rotinas (funções retomáveis).|  
|[/Source-CharSet](source-charset-set-source-character-set.md)|Conjunto de caracteres do conjunto de origem.|
|[/Execution-CharSet](execution-charset-set-execution-character-set.md)|Conjunto de caracteres de execução do conjunto.|
|[/UTF-8](utf-8-set-source-and-executable-character-sets-to-utf-8.md)|Conjuntos de caracteres de origem e a execução de conjunto UTF-8.|
|[/Validate-CharSet](validate-charset-validate-for-compatible-characters.md)|Valide arquivos UTF-8 para apenas caracteres compatíveis.|
|[/Diagnostics](diagnostics-compiler-diagnostic-options.md)|Controla o formato de mensagens de diagnóstico.|
|[/ permissivo-](permissive-standards-conformance.md)|Definir o modo de conformidade do padrão.|
|[/STD](std-specify-language-standard-version.md)|Seletor de compatibilidade de versão padrão do C++.|
  
### <a name="deprecated-and-removed-compiler-options"></a>Opções do compilador removidos e preteridos  
  
|Opção|Finalidade|  
|------------|-------------|  
|[/CLR:noAssembly](../../build/reference/clr-common-language-runtime-compilation.md)|Preterido. Use [/LN (criar o módulo MSIL)](../../build/reference/ln-create-msil-module.md) em vez disso.|  
|[/FR](../../build/reference/fr-fr-create-dot-sbr-file.md)|Preterido. Cria um arquivo de informações de procura sem variáveis locais.|  
|[/GE](../../build/reference/ge-enable-stack-probes.md)|Preterido. Ativa investigações de pilha. Em por padrão.|  
|[/GX](../../build/reference/gx-enable-exception-handling.md)|Preterido. Habilita o tratamento síncrono de exceções. Use [/EH](../../build/reference/eh-exception-handling-model.md) em vez disso.|  
|[/GZ](../../build/reference/gz-enable-stack-frame-run-time-error-checking.md)|Preterido. Habilita as verificações rápidas. Use [/RTC1](../../build/reference/rtc-run-time-error-checks.md) em vez disso.|  
|[/H](../../build/reference/h-restrict-length-of-external-names.md)|Preterido. Restringe o tamanho de nomes externos (públicos).|  
|[/Og](../../build/reference/og-global-optimizations.md)|Preterido. Usa otimizações globais.|  
|[QIfist](../../build/reference/qifist-suppress-ftol.md)|Preterido. Uma vez é usado para especificar como converter de um tipo de ponto flutuante para um tipo integral.|  
|[/V](../../build/reference/v-version-number.md)|Preterido. Define a cadeia de caracteres de versão de arquivo. obj.|  
|[/Wp64](../../build/reference/wp64-detect-64-bit-portability-issues.md)|Obsoleto. Detecta problemas de portabilidade de 64 bits.|  
|[/Yd](../../build/reference/yd-place-debug-information-in-object-file.md)|Preterido. Coloca informações de depuração completas em todos os arquivos de objeto. Use [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) em vez disso.|  
|[/ZC:forScope-](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md)|Preterido. Desabilita a conformidade para escopo de loop.|  
|[/Ze](../../build/reference/za-ze-disable-language-extensions.md)|Preterido. Habilita extensões de linguagem.|  
|[/ZG](../../build/reference/zg-generate-function-prototypes.md)|Removido no Visual C++ 2015. Gera protótipos de função.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de build do C/C++](../../build/reference/c-cpp-building-reference.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)