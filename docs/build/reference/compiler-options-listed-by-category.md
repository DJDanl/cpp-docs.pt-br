---
title: "Op&#231;&#245;es de compilador listadas por categoria | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
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
  - "Opções do compilador C++"
ms.assetid: c4750dcf-dba0-4229-99b6-45cdecc11729
caps.latest.revision: 64
caps.handback.revision: 64
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Op&#231;&#245;es de compilador listadas por categoria
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este artigo contém uma lista categórica de opções do compilador. Para obter uma lista alfabética, consulte [Opções do compilador listadas em ordem alfabética](../../build/reference/compiler-options-listed-alphabetically.md).  
  
### Otimização  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[\/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md)|Cria um código pequeno.|  
|[\/ O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md)|Cria um código rápido.|  
|[\/Ob](../../build/reference/ob-inline-function-expansion.md)|Controla a expansão embutida.|  
|[\/Od](../../build/reference/od-disable-debug.md)|Desabilita a otimização.|  
|[\/Og](../../build/reference/og-global-optimizations.md)|Preterido. Usa otimizações globais.|  
|[\/Oi](../Topic/-Oi%20\(Generate%20Intrinsic%20Functions\).md)|Gera funções intrínsecas.|  
|[\/Os](../../build/reference/os-ot-favor-small-code-favor-fast-code.md)|Favorece código pequeno.|  
|[\/OT](../../build/reference/os-ot-favor-small-code-favor-fast-code.md)|Favorece código rápido.|  
|[\/OX](../../build/reference/ox-full-optimization.md)|Usa a otimização máxima \(\/ Ob2gity \/Gs\).|  
|[\/Oy](../../build/reference/oy-frame-pointer-omission.md)|Omite o ponteiro de quadro. \(somente x86\)|  
|[\/favor](../../build/reference/favor-optimize-for-architecture-specifics.md)|Produz código otimizado para uma arquitetura específica ou um intervalo de arquiteturas.|  
  
### Geração de código  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[\/arch](../../build/reference/arch-x86.md)|Use as instruções SSE ou SSE2 na geração de código. \(somente x86\)|  
|[\/CLR](../../build/reference/clr-common-language-runtime-compilation.md)|Produz um arquivo de saída para ser executado no common language runtime.|  
|[\/EH](../../build/reference/eh-exception-handling-model.md)|Especifica o modelo de tratamento de exceções.|  
|[\/FP](../../build/reference/fp-specify-floating-point-behavior.md)|Especifica o comportamento de ponto flutuante.|  
|[\/GA](../../build/reference/ga-optimize-for-windows-application.md)|Otimiza para aplicativos do Windows.|  
|[\/Gd](../../build/reference/gd-gr-gv-gz-calling-convention.md)|Usa o `__cdecl` convenção de chamada. \(somente x86\)|  
|[\/GE](../Topic/-Ge%20\(Enable%20Stack%20Probes\).md)|Preterido. Ativa sondas de pilha.|  
|[\/GF](../Topic/-GF%20\(Eliminate%20Duplicate%20Strings\).md)|Habilita pooling de cadeia de caracteres.|  
|[\/GH](../../build/reference/gh-enable-penter-hook-function.md)|Chamadas de função de gancho `_penter`.|  
|[\/GH](../../build/reference/gh-enable-pexit-hook-function.md)|Chamadas de função de gancho `_pexit`.|  
|[\/GL](../../build/reference/gl-whole-program-optimization.md)|Habilita a otimização de programa total.|  
|[\/GM](../../build/reference/gm-enable-minimal-rebuild.md)|Habilita recompilação mínima.|  
|[\/GR](../Topic/-GR%20\(Enable%20Run-Time%20Type%20Information\).md)|Permite que as informações de tipo de tempo de execução \(RTTI\).|  
|[\/GR](../../build/reference/gd-gr-gv-gz-calling-convention.md)|Usa o `__fastcall` convenção de chamada. \(somente x86\)|  
|[\/GS](../Topic/-GS%20\(Buffer%20Security%20Check\).md)|Verificações de segurança do buffer.|  
|[\/GS](../../build/reference/gs-control-stack-checking-calls.md)|Controla investigações de pilha.|  
|[\/GT](../../build/reference/gt-support-fiber-safe-thread-local-storage.md)|Oferece suporte à segurança de fibra para dados alocados usando armazenamento de thread local estático.|  
|[\/Guard:CF](../../build/reference/guard-enable-control-flow-guard.md)|Adiciona verificações de segurança do protetor de fluxo de controle.|  
|[\/GV](../../build/reference/gd-gr-gv-gz-calling-convention.md)|Usa o `__vectorcall` convenção de chamada. \(x86 e x64 apenas\)|  
|[\/GW](../../build/reference/gw-optimize-global-data.md)|Habilita a otimização de dados globais de todo o programa.|  
|[\/GX](../Topic/-GX%20\(Enable%20Exception%20Handling\).md)|Preterido. Permite a manipulação de exceções síncronas. Use [\/EH](../../build/reference/eh-exception-handling-model.md) em vez disso.|  
|[\/Gy](../../build/reference/gy-enable-function-level-linking.md)|Habilita o nível de função de vinculação.|  
|[\/GZ](../../build/reference/gz-enable-stack-frame-run-time-error-checking.md)|Preterido. Habilita as verificações rápidas. \(Mesmo que [\/RTC1](../../build/reference/rtc-run-time-error-checks.md)\)|  
|[\/Gz](../../build/reference/gd-gr-gv-gz-calling-convention.md)|Usa o `__stdcall` convenção de chamada. \(somente x86\)|  
|[\/homeparams](../../build/reference/homeparams-copy-register-parameters-to-stack.md)|Força os parâmetros passados em registros a serem gravados em seus locais na pilha mediante a entrada da função. Essa opção de compilador é somente para o [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] compiladores \(nativos e compilação cruzada\).|  
|[\/hotpatch](../../build/reference/hotpatch-create-hotpatchable-image.md)|Cria uma imagem de patch sob demanda.|  
|[\/Qfast\_transcendentals](../../build/reference/qfast-transcendentals-force-fast-transcendentals.md)|Gera transcendentais rápidos.|  
|[QIfist](../../build/reference/qifist-suppress-ftol.md)|Preterido. Suprime a chamada da função auxiliar `_ftol` quando é necessária uma conversão de um tipo de ponto flutuante em um tipo integral. \(somente x86\)|  
|[\/Qimprecise\_fwaits](../../build/reference/qimprecise-fwaits-remove-fwaits-inside-try-blocks.md)|Remove `fwait` comandos dentro de `try` blocos.|  
|[\/Qpar](../Topic/-Qpar%20\(Auto-Parallelizer\).md)|Habilita a paralelização automática de loops.|  
|[\/Qpar\-Report](../../build/reference/qpar-report-auto-parallelizer-reporting-level.md)|Habilita níveis de relatório para paralelização automática.|  
|[\/Qsafe\_fp\_loads](../../build/reference/qsafe-fp-loads.md)|Usa instruções de movimentação de inteiro para valores de ponto flutuante e desabilita determinadas flutuante otimizações de carregamento de ponto.|  
|[\/Qvec\-report \(nível de relatórios do vetorizador automático\)](../../build/reference/qvec-report-auto-vectorizer-reporting-level.md)|Habilita níveis de relatório para vetorização automática.|  
|[\/ RTC](../../build/reference/rtc-run-time-error-checks.md)|Habilita a verificação de erros de tempo de execução.|  
|[\/ volátil](../../build/reference/volatile-volatile-keyword-interpretation.md)|Seleciona como a palavra\-chave volátil é interpretada.|  
  
### Arquivos de saída  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[\/doc](../../build/reference/doc-process-documentation-comments-c-cpp.md)|Processa comentários de documentação para um arquivo XML.|  
|[\/FA](../../build/reference/fa-fa-listing-file.md)|Configura um arquivo de listagem do assembly.|  
|[\/FA](../../build/reference/fa-fa-listing-file.md)|Cria um arquivo de listagem do assembly.|  
|[\/FD](../../build/reference/fd-program-database-file-name.md)|Renomeia o arquivo de banco de dados do programa.|  
|[\/FE](../../build/reference/fe-name-exe-file.md)|Renomeia o arquivo executável.|  
|[\/Fi](../../build/reference/fi-preprocess-output-file-name.md)|Especifica o nome do arquivo de saída pré\-processado.|  
|[\/FM](../Topic/-Fm%20\(Name%20Mapfile\).md)|Cria um arquivo de mapa.|  
|[\/FO](../../build/reference/fo-object-file-name.md)|Cria um arquivo de objeto.|  
|[\/FP](../Topic/-Fp%20\(Name%20.Pch%20File\).md)|Especifica um nome de arquivo de cabeçalho pré\-compilado.|  
|[\/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) [\/Fr](../../build/reference/fr-fr-create-dot-sbr-file.md)|Gera arquivos de navegador.|  
  
### Pré\-processador  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[\/AI](../../build/reference/ai-specify-metadata-directories.md)|Especifica um diretório de pesquisa para resolver referências de arquivo passadas para o [\#using](../../preprocessor/hash-using-directive-cpp.md) diretiva.|  
|[\/C](../../build/reference/c-preserve-comments-during-preprocessing.md)|Preserva comentários durante o pré\-processamento.|  
|[\/D](../../build/reference/d-preprocessor-definitions.md)|Define constantes e macros.|  
|[\/E](../../build/reference/e-preprocess-to-stdout.md)|Saída de pré\-processador de cópias para a saída padrão.|  
|[\/EP](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md)|Saída de pré\-processador de cópias para a saída padrão.|  
|[\/FI](../Topic/-FI%20\(Name%20Forced%20Include%20File\).md)|Pré\-processa o arquivo de inclusão especificado.|  
|[\/FU](../../build/reference/fu-name-forced-hash-using-file.md)|Força o uso de um nome de arquivo, como se ele tivesse sido passado para o [\#using](../../preprocessor/hash-using-directive-cpp.md) diretiva.|  
|[\/FX](../../build/reference/fx-merge-injected-code.md)|Mescla o código injetado com o arquivo de origem.|  
|[\/I](../../build/reference/i-additional-include-directories.md)|Pesquisa um diretório para arquivos de inclusão.|  
|[\/ P](../../build/reference/p-preprocess-to-a-file.md)|Grava a saída de pré\-processador para um arquivo.|  
|[\/ U](../Topic/-U,%20-u%20\(Undefine%20Symbols\).md)|Remove uma macro predefinida.|  
|[\/ u](../Topic/-U,%20-u%20\(Undefine%20Symbols\).md)|Remove todas as macros predefinidas.|  
|[\/X](../../build/reference/x-ignore-standard-include-paths.md)|Ignora o padrão de diretório de inclusão.|  
  
### Idioma  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[\/OpenMP](../../build/reference/openmp-enable-openmp-2-0-support.md)|Permite [\#pragma omp](../../preprocessor/omp.md) no código\-fonte.|  
|[\/VD](../../build/reference/vd-disable-construction-displacements.md)|Suprime ou habilita oculto `vtordisp` membros de classe.|  
|[\/vmb](../../build/reference/vmb-vmg-representation-method.md)|Usa a melhor base de ponteiros para membros.|  
|[\/vmg](../../build/reference/vmb-vmg-representation-method.md)|Usa a generalidade completa de ponteiros para membros.|  
|[\/VMM](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)|Declara a herança múltipla.|  
|[\/VMs](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)|Declara a herança única.|  
|[\/vmv](../../build/reference/vmm-vms-vmv-general-purpose-representation.md)|Declara a herança virtual.|  
|[\/Z7](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md)|Gera informações de depuração compatível com 7.0 C.|  
|[\/Za](../../build/reference/za-ze-disable-language-extensions.md)|Desabilita extensões de linguagem.|  
|[\/ZC](../../build/reference/zc-conformance.md)|Especifica o comportamento padrão em [\/Ze](../../build/reference/za-ze-disable-language-extensions.md).|  
|[\/Ze](../../build/reference/za-ze-disable-language-extensions.md)|Preterido. Permite que extensões de linguagem.|  
|[\/ZI](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md)|Inclui informações de depuração em um banco de dados do programa compatível com editar e continuar. \(somente x86\)|  
|[\/Zi](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md)|Gera informações completas de depuração.|  
|[\/ZL](../../build/reference/zl-omit-default-library-name.md)|Remove o nome da biblioteca padrão do arquivo. obj.|  
|[\/ZP](../Topic/-Zp%20\(Struct%20Member%20Alignment\).md) *n*|Membros da estrutura de pacotes.|  
|[\/ZS](../../build/reference/zs-syntax-check-only.md)|Verifica apenas a sintaxe.|  
|[\/ZW](../../build/reference/zw-windows-runtime-compilation.md)|Produz um arquivo de saída para ser executado no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].|  
  
### Vinculação  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[\/F](../../build/reference/f-set-stack-size.md)|Define o tamanho da pilha.|  
|[\/LD](../../build/reference/md-mt-ld-use-run-time-library.md)|Cria uma biblioteca de vínculo dinâmico.|  
|[\/ LDd](../../build/reference/md-mt-ld-use-run-time-library.md)|Cria uma biblioteca de vínculo dinâmico de depuração.|  
|[\/link](../Topic/-link%20\(Pass%20Options%20to%20Linker\).md)|Passa a opção especificada para LINK.|  
|[\/LN](../../build/reference/ln-create-msil-module.md)|Cria um módulo MSIL.|  
|[\/MD](../../build/reference/md-mt-ld-use-run-time-library.md)|Compila para criar uma DLL com multithread usando Msvcrt.|  
|[\/ MDd](../../build/reference/md-mt-ld-use-run-time-library.md)|Compila para criar uma depuração DLL com multithread usando Msvcrtd.|  
|[\/MT](../../build/reference/md-mt-ld-use-run-time-library.md)|Compila para criar um arquivo executável com multithread usando libcmt.|  
|[\/ MTd](../../build/reference/md-mt-ld-use-run-time-library.md)|Compila para criar um arquivo executável com multithread de depuração, usando Libcmtd.|  
  
### Cabeçalho pré\-compilado  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[\/Y\-](../Topic/-Y-%20\(Ignore%20Precompiled%20Header%20Options\).md)|Ignora todas as outras opções de compilador do cabeçalho pré\-compilado na compilação atual.|  
|[\/Yc](../../build/reference/yc-create-precompiled-header-file.md)|Cria um arquivo de cabeçalho pré\-compilado.|  
|[\/Yd](../../build/reference/yd-place-debug-information-in-object-file.md)|Locais de concluir as informações de depuração em todos os arquivos de objeto.|  
|[\/Yu](../../build/reference/yu-use-precompiled-header-file.md)|Usa um arquivo de cabeçalho pré\-compilado durante a compilação.|  
  
### Diversos  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[\/?](../../build/reference/help-compiler-command-line-help.md)|Lista as opções do compilador.|  
|[@](../../build/reference/at-specify-a-compiler-response-file.md)|Especifica um arquivo de resposta.|  
|[\/ANALYZE](../../build/reference/analyze-code-analysis.md)|Habilita a análise de código.|  
|[\/bigobj](../../build/reference/bigobj-increase-number-of-sections-in-dot-obj-file.md)|Aumenta o número de seções endereçáveis em um arquivo. obj.|  
|[\/c](../../build/reference/c-compile-without-linking.md)|Compila sem vinculação.|  
|[\/cgthreads](../../build/reference/cgthreads-code-generation-threads.md)|Especifica o número de threads de cl.exe a ser usado para a otimização e geração de código.|  
|[\/errorReport](../Topic/-errorReport%20\(Report%20Internal%20Compiler%20Errors\).md)|Permite que você forneça informações de erro \(ICE\) interno do compilador diretamente para a equipe do Visual C\+\+.|  
|[\/FC](../Topic/-FC%20\(Full%20Path%20of%20Source%20Code%20File%20in%20Diagnostics\).md)|Exibe o caminho completo dos arquivos de código de origem passado para cl.exe em texto de diagnóstico.|  
|[\/FS](../../build/reference/fs-force-synchronous-pdb-writes.md)|Força grava o arquivo de programa \(PDB\) de banco de dados por meio de MSPDBSRV. EXE.|  
|[\/H](../../build/reference/h-restrict-length-of-external-names.md)|Preterido. Restringe o comprimento de nomes \(públicos\) externos.|  
|[\/ AJUDA](../../build/reference/help-compiler-command-line-help.md)|Lista as opções do compilador.|  
|[\/J](../../build/reference/j-default-char-type-is-unsigned.md)|Altera o padrão `char` tipo.|  
|[\/kernel](../../build/reference/kernel-create-kernel-mode-binary.md)|O compilador e vinculador criará um binário que pode ser executado no kernel do Windows.|  
|[\/MP](../../build/reference/mp-build-with-multiple-processes.md)|Cria vários arquivos de origem ao mesmo tempo.|  
|[\/nologo](../../build/reference/nologo-suppress-startup-banner-c-cpp.md)|Suprime a exibição da faixa de logon.|  
|[\/SDL](../../build/reference/sdl-enable-additional-security-checks.md)|Habilita recursos de segurança adicionais e avisos.|  
|[\/showIncludes](../Topic/-showIncludes%20\(List%20Include%20Files\).md)|Exibe uma lista de todos os incluem arquivos durante a compilação.|  
|[\/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) [\/TC](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md)|Especifica um arquivo de código\-fonte C.|  
|[\/Tp](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) [\/TP](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md)|Especifica um arquivo de origem C\+\+.|  
|[\/V](../../build/reference/v-version-number.md)|Preterido. Define a cadeia de caracteres de versão.|  
|[\/w](../../build/reference/compiler-option-warning-level.md)|Desabilita todos os avisos.|  
|[\/ W0, \/W1, \/W2, \/W3, \/W4](../../build/reference/compiler-option-warning-level.md)|Define o nível de aviso de saída.|  
|[\/W1, \/w2, \/w3, \/w4](../../build/reference/compiler-option-warning-level.md)|Define o nível de aviso especificado de aviso.|  
|[\/ Parede](../../build/reference/compiler-option-warning-level.md)|Habilita todos os avisos, inclusive avisos desabilitados por padrão.|  
|[\/WD](../../build/reference/compiler-option-warning-level.md)|Desabilita o aviso especificado.|  
|[\/We](../../build/reference/compiler-option-warning-level.md)|Trata o aviso especificado como um erro.|  
|[\/WL](../../build/reference/wl-enable-one-line-diagnostics.md)|Habilita o diagnóstico de uma linha para mensagens de erro e aviso durante a compilação de código\-fonte C\+\+ na linha de comando.|  
|[\/WO](../../build/reference/compiler-option-warning-level.md)|Exibe o aviso especificado somente uma vez.|  
|[\/Wp64](../../build/reference/wp64-detect-64-bit-portability-issues.md)|Obsoleta. Detecta os problemas de portabilidade de 64 bits.|  
|[\/WV](../../build/reference/compiler-option-warning-level.md)|Desabilita os avisos introduzidos por versões mais recentes do compilador.|  
|[\/WX](../../build/reference/compiler-option-warning-level.md)|Trata avisos como erros.|  
|[\/Yd](../../build/reference/yd-place-debug-information-in-object-file.md)|Preterido. Locais de concluir as informações de depuração em todos os arquivos de objeto. Use [\/Zi](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) em vez disso.|  
|[\/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md)|Injeta uma referência PCH durante a criação de uma biblioteca de depuração.|  
|[\/ZM](../Topic/-Zm%20\(Specify%20Precompiled%20Header%20Memory%20Allocation%20Limit\).md)|Especifica o limite de alocação de memória de cabeçalho pré\-compilado.|  
  
### Opções do compilador preteridos e removidos  
  
|Opção|Finalidade|  
|-----------|----------------|  
|[\/CLR:noAssembly](../../build/reference/clr-common-language-runtime-compilation.md)|Preterido. Use [\/LN \(criar módulo MSIL\)](../../build/reference/ln-create-msil-module.md) em vez disso.|  
|[\/FR](../../build/reference/fr-fr-create-dot-sbr-file.md)|Preterido. Cria um arquivo de informações de procura sem variáveis locais.|  
|[\/GE](../Topic/-Ge%20\(Enable%20Stack%20Probes\).md)|Preterido. Ativa sondas de pilha. Em por padrão.|  
|[\/GX](../Topic/-GX%20\(Enable%20Exception%20Handling\).md)|Preterido. Permite a manipulação de exceções síncronas. Use [\/EH](../../build/reference/eh-exception-handling-model.md) em vez disso.|  
|[\/GZ](../../build/reference/gz-enable-stack-frame-run-time-error-checking.md)|Preterido. Habilita as verificações rápidas. Use [\/RTC1](../../build/reference/rtc-run-time-error-checks.md) em vez disso.|  
|[\/H](../../build/reference/h-restrict-length-of-external-names.md)|Preterido. Restringe o comprimento de nomes \(públicos\) externos.|  
|[\/Og](../../build/reference/og-global-optimizations.md)|Preterido. Usa otimizações globais.|  
|[QIfist](../../build/reference/qifist-suppress-ftol.md)|Preterido. Uma vez é usado para especificar como converter de um tipo de ponto flutuante para um tipo integral.|  
|[\/V](../../build/reference/v-version-number.md)|Preterido. Define a cadeia de caracteres de versão de arquivo. obj.|  
|[\/Yd](../../build/reference/yd-place-debug-information-in-object-file.md)|Preterido. Locais de concluir as informações de depuração em todos os arquivos de objeto. Use [\/Zi](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) em vez disso.|  
|[\/ZC:forScope\-](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md)|Preterido. Desabilita a conformidade para escopo de loop.|  
|[\/Ze](../../build/reference/za-ze-disable-language-extensions.md)|Preterido. Permite que extensões de linguagem.|  
|[\/ZG](../../build/reference/zg-generate-function-prototypes.md)|Removido do Visual C\+\+ 2015. Gera protótipos de função.|  
  
## Consulte também  
 [Referência de compilação do C\/C\+\+](../Topic/C-C++%20Building%20Reference.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)