---
title: Opções do compilador listadas em ordem alfabética
ms.date: 01/08/2020
helpviewer_keywords:
- compiler options, C++
ms.openlocfilehash: 72441692869dbed806474a7054fedff53b923d42
ms.sourcegitcommit: a930a9b47bd95599265d6ba83bb87e46ae748949
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2020
ms.locfileid: "76518368"
---
# <a name="compiler-options-listed-alphabetically"></a>Opções do compilador listadas em ordem alfabética

Esta é uma lista alfabética abrangente das opções de compilador. Para uma lista categórica, consulte as [Opções de compilador listadas por categoria](compiler-options-listed-by-category.md).

|Opção|Finalidade|
|------------|-------------|
|[@](at-specify-a-compiler-response-file.md)|Especifica um arquivo de resposta.|
|[/?](help-compiler-command-line-help.md)|Lista as opções do compilador.|
|[/AI](ai-specify-metadata-directories.md)|Especifica um diretório a ser pesquisado para resolver as referências de arquivo passadas para a diretiva [#using](../../preprocessor/hash-using-directive-cpp.md) .|
|[/analyze](analyze-code-analysis.md)|Habilita a análise de código.|
|[/arch](arch-minimum-cpu-architecture.md)|Especifica a arquitetura da geração de código.|
|[/await](await-enable-coroutine-support.md)|Habilite as extensões de corrotinas (funções retomáveis).|
|[/bigobj](bigobj-increase-number-of-sections-in-dot-obj-file.md)|Aumenta o número de seções endereçáveis em um arquivo .obj.|
|[/C](c-preserve-comments-during-preprocessing.md)|Preserva comentários durante o pré-processamento.|
|[/c](c-compile-without-linking.md)|Compila sem vinculação.|
|[/cgthreads](cgthreads-code-generation-threads.md)|Especifica o número de threads cl.exe a serem usados na otimização e na geração de código.|
|[/clr](clr-common-language-runtime-compilation.md)|Produz um arquivo de saída a ser executado no Common Language Runtime.|
|[/constexpr](constexpr-control-constexpr-evaluation.md)|Controlar a avaliação de constexpr em tempo de compilação.|
|[/D](d-preprocessor-definitions.md)|Define constantes e macros.|
|[/diagnostics](diagnostics-compiler-diagnostic-options.md)|Controla o formato das mensagens de diagnóstico.|
|[/doc](doc-process-documentation-comments-c-cpp.md)|Processa comentários de documentação em um arquivo XML.|
|[/E](e-preprocess-to-stdout.md)|Copia a saída do pré-processador para a saída padrão.|
|[/EH](eh-exception-handling-model.md)|Especifica o modelo de tratamento de exceções.|
|[/EP](ep-preprocess-to-stdout-without-hash-line-directives.md)|Copia a saída do pré-processador para a saída padrão.|
|[/errorReport](errorreport-report-internal-compiler-errors.md)|Permite que você forneça informações de erro interno do compilador (ICE) diretamente para C++ a equipe da Microsoft.|
|[/execution-charset](execution-charset-set-execution-character-set.md)|Definir conjunto de caracteres de execução.|
|[/experimental: módulo](experimental-module.md)|Habilita o suporte a módulo experimental.|
|[/experimental: pré-processador](experimental-preprocessor.md)|Habilita o suporte a pré-processador de conformidade experimental.|
|[/F](f-set-stack-size.md)|Define o tamanho da pilha.|
|[/favor](favor-optimize-for-architecture-specifics.md)|Produz o código que é otimizado para uma arquitetura x64 específica ou para as especificações de microarquiteturas nas arquiteturas AMD64 e memória estendida da tecnologia 64 (EM64T).|
|[/FA](fa-fa-listing-file.md)|Cria um arquivo de listagem.|
|[/Fa](fa-fa-listing-file.md)|Define o nome do arquivo de listagem.|
|[/FC](fc-full-path-of-source-code-file-in-diagnostics.md)|Exibe o caminho completo dos arquivos de código-fonte passados para cl.exe em texto de diagnóstico.|
|[/Fd](fd-program-database-file-name.md)|Renomeia o arquivo de banco de dados do programa.|
|[/Fe](fe-name-exe-file.md)|Renomeia o arquivo executável.|
|[/FI](fi-name-forced-include-file.md)|Pré-processa o arquivo de inclusão especificado.|
|[/Fi](fi-preprocess-output-file-name.md)|Define o nome do arquivo de saída pré-processado.|
|[/Fm](fm-name-mapfile.md)|Cria um arquivo de mapa.|
|[/Fo](fo-object-file-name.md)|Cria um arquivo de objeto.|
|[/fp](fp-specify-floating-point-behavior.md)|Especifica o comportamento de ponto flutuante.|
|[/Fp](fp-name-dot-pch-file.md)|Especifica um nome de arquivo de cabeçalho pré-compilado.|
|[/FR](fr-fr-create-dot-sbr-file.md)<br /><br /> [/Fr](fr-fr-create-dot-sbr-file.md)|Gera arquivos de navegador. **/Fr** foi preterido.|
|[/FS](fs-force-synchronous-pdb-writes.md)|Força a serialização de gravações no arquivo de PDB (banco de dados do programa) por meio de MSPDBSRV.EXE.|
|[/FU](fu-name-forced-hash-using-file.md)|Força o uso de um nome de arquivo como se ele tivesse sido passado para a diretiva [#using](../../preprocessor/hash-using-directive-cpp.md) .|
|[/Fx](fx-merge-injected-code.md)|Mescla o código injetado com o arquivo de origem.|
|[/GA](ga-optimize-for-windows-application.md)|Otimiza o código do aplicativo do Windows.|
|[/Gd](gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__cdecl` (somente x86).|
|[/Ge](ge-enable-stack-probes.md)|Preterido. Ativa investigações de pilha.|
|[/GF](gf-eliminate-duplicate-strings.md)|Habilita pooling de cadeia de caracteres.|
|[/GH](gh-enable-pexit-hook-function.md)|Chama a função de gancho `_pexit`.|
|[/Gh](gh-enable-penter-hook-function.md)|Chama a função de gancho `_penter`.|
|[/GL](gl-whole-program-optimization.md)|Habilita a otimização de todo o programa.|
|[/Gm](gm-enable-minimal-rebuild.md)|Preterido. Habilita recompilação mínima.|
|[/GR](gr-enable-run-time-type-information.md)|Habilita RTTI (informações de tipo de tempo de execução).|
|[/Gr](gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__fastcall` (somente x86).|
|[/GS](gs-buffer-security-check.md)|Armazena a verificação de segurança em buffer.|
|[/Gs](gs-control-stack-checking-calls.md)|Controla investigações de pilha.|
|[/GT](gt-support-fiber-safe-thread-local-storage.md)|Dá suporte à segurança de fibra para dados alocados usando armazenamento de thread local estático.|
|[/guard:cf](guard-enable-control-flow-guard.md)|Adiciona verificações de segurança de proteção de fluxo de controle.|
|[/Gv](gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__vectorcall`. (somente x86 e x64)|
|[/Gw](gw-optimize-global-data.md)|Habilita a otimização de dados globais de todo o programa.|
|[/GX](gx-enable-exception-handling.md)|Preterido. Habilita o tratamento síncrono de exceções. Use [/eh](eh-exception-handling-model.md) em vez disso.|
|[/Gy](gy-enable-function-level-linking.md)|Habilita a vinculação no nível de função.|
|[/GZ](gz-enable-stack-frame-run-time-error-checking.md)|Preterido. O mesmo que [/RTC1](rtc-run-time-error-checks.md).|
|[/Gz](gd-gr-gv-gz-calling-convention.md)|Usa a convenção de chamada `__stdcall` (somente x86).|
|[/H](h-restrict-length-of-external-names.md)|Preterido. Restringe o tamanho de nomes externos (públicos).|
|[/HELP](help-compiler-command-line-help.md)|Lista as opções do compilador.|
|[/homeparams](homeparams-copy-register-parameters-to-stack.md)|Força os parâmetros passados em registros a serem gravados em seus locais na pilha mediante a entrada da função. Essa opção de compilador é apenas para compiladores x64 (nativa e de compilação cruzada).|
|[/hotpatch](hotpatch-create-hotpatchable-image.md)|Cria uma imagem com patches quentes.|
|[/I](i-additional-include-directories.md)|Pesquisa um diretório para incluir arquivos.|
|[/J](j-default-char-type-is-unsigned.md)|Altera o tipo `char` padrão.|
|[/JMC](jmc.md)|Dá suporte C++ à depuração de apenas meu código nativo.|
|[/kernel](kernel-create-kernel-mode-binary.md)|O compilador e o vinculador criará um binário que pode ser executado no kernel do Windows.|
|[/LD](md-mt-ld-use-run-time-library.md)|Cria uma biblioteca de vínculo dinâmico.|
|[/LDd](md-mt-ld-use-run-time-library.md)|Cria uma biblioteca de vínculo dinâmico de depuração.|
|[/link](link-pass-options-to-linker.md)|Passa a opção especificada para LINK.|
|[/LN](ln-create-msil-module.md)|Cria um módulo MSIL.|
|[/MD](md-mt-ld-use-run-time-library.md)|Cria uma DLL de vários threads usando MSVCRT.lib.|
|[/MDd](md-mt-ld-use-run-time-library.md)|Cria uma DLL de vários threads de depuração usando MSVCRTD.lib.|
|[/MP](mp-build-with-multiple-processes.md)|Compila vários arquivos de origem usando vários processos.|
|[/MT](md-mt-ld-use-run-time-library.md)|Cria um arquivo executável de vários threads usando LIBCMT.lib.|
|[/MTd](md-mt-ld-use-run-time-library.md)|Cria um arquivo executável de vários threads de depuração usando LIBCMT.lib.|
|[/nologo](nologo-suppress-startup-banner-c-cpp.md)|Suprime a exibição da faixa de logon.|
|[/O1](o1-o2-minimize-size-maximize-speed.md)|Cria um código pequeno.|
|[/O2](o1-o2-minimize-size-maximize-speed.md)|Cria um código rápido.|
|[/Ob](ob-inline-function-expansion.md)|Controla a expansão embutida.|
|[/OD](od-disable-debug.md)|Desabilita a otimização.|
|[/Og](og-global-optimizations.md)|Preterido. Usa otimizações globais.|
|[/Oi](oi-generate-intrinsic-functions.md)|Gera funções intrínsecas.|
|[/openmp](openmp-enable-openmp-2-0-support.md)|Habilita a diretiva [`#pragma omp`](../../preprocessor/omp.md) no código-fonte.|
|[/Os](os-ot-favor-small-code-favor-fast-code.md)|Favorece código pequeno.|
|[/Ot](os-ot-favor-small-code-favor-fast-code.md)|Favorece código rápido.|
|[/Ox](ox-full-optimization.md)|Um subconjunto de/O2 que não inclui/GF ou/GY.|
|[/Oy](oy-frame-pointer-omission.md)|Omite o ponteiro de quadro (somente x86).|
|[/P](p-preprocess-to-a-file.md)|Grava a saída do pré-processador em um arquivo.|
|[/permissive-](permissive-standards-conformance.md)|Definir o modo de conformidade padrão.|
|[/Qfast_transcendentals](qfast-transcendentals-force-fast-transcendentals.md)|Gera transcendentais rápidos.|
|[/QIfist](qifist-suppress-ftol.md)|Preterido. Suprime `_ftol` quando é necessária uma conversão de um tipo de ponto flutuante em um tipo integral (somente x86).|
|[/Qimprecise_fwaits](qimprecise-fwaits-remove-fwaits-inside-try-blocks.md)|Remove comandos `fwait` dentro de blocos `try`.|
|[/QIntel-jcc-erratum](qintel-jcc-erratum.md)|Atenua o impacto no desempenho da atualização do microcódigo da Errata do Intel JCC.|
|[/Qpar (paralelizador automático)](qpar-auto-parallelizer.md)|Habilita a paralelização automática de loops que são marcados com a diretiva [loop de #pragma ()](../../preprocessor/loop.md) .|
|[/Qsafe_fp_loads](qsafe-fp-loads.md)|Usa instruções de movimento de inteiro para valores de ponto flutuante e desabilita determinadas otimizações de carregamento de ponto flutuante.|
|[/Qspectre](qspectre.md)|Especifica a geração do compilador de instruções para atenuar algumas vulnerabilidades de segurança da variante 1 de Espectro.|
|[/Qvec-report (nível de relatórios do vetorizador automático)](qvec-report-auto-vectorizer-reporting-level.md)|Habilita níveis de relatório para vetorização automática.|
|[/RTC](rtc-run-time-error-checks.md)|Habilita a verificação de erro em tempo de execução.|
|[/sdl](sdl-enable-additional-security-checks.md)|Habilita os recursos e os avisos de segurança adicionais.|
|[/showIncludes](showincludes-list-include-files.md)|Exibe uma lista de arquivos de inclusão durante a compilação.|
|[/source-charset](source-charset-set-source-character-set.md)|Definir conjunto de caracteres de origem.|
|[/std](std-specify-language-standard-version.md)|C++seletor de compatibilidade de versão padrão.|
|[/Tc](tc-tp-tc-tp-specify-source-file-type.md)|Especifica um arquivo de origem do C.|
|[/TC](tc-tp-tc-tp-specify-source-file-type.md)|Especifica que todos os arquivos de origem são C.|
|[/Tp](tc-tp-tc-tp-specify-source-file-type.md)|Especifica um arquivo de origem do C++.|
|[/TP](tc-tp-tc-tp-specify-source-file-type.md)|Especifica que todos os arquivos C++de origem são.|
|[/U](u-u-undefine-symbols.md)|Remove uma macro predefinida.|
|[/u](u-u-undefine-symbols.md)|Remove todas as macros predefinidas.|
|[/utf-8](utf-8-set-source-and-executable-character-sets-to-utf-8.md)|Defina os conjuntos de caracteres de origem e de execução como UTF-8.|
|[/V](v-version-number.md)|Preterido. Define a cadeia de caracteres da versão do arquivo. obj.|
|[/validate-charset](validate-charset-validate-for-compatible-characters.md)|Valide os arquivos UTF-8 somente para caracteres compatíveis.|
|[/vd](vd-disable-construction-displacements.md)|Suprime ou habilita membros da classe vtordisp ocultos.|
|[/vmb](vmb-vmg-representation-method.md)|Usa a melhor base de ponteiros para membros.|
|[/vmg](vmb-vmg-representation-method.md)|Usa a generalidade completa de ponteiros para membros.|
|[/vmm](vmm-vms-vmv-general-purpose-representation.md)|Declara a herança múltipla.|
|[/vms](vmm-vms-vmv-general-purpose-representation.md)|Declara a herança única.|
|[/vmv](vmm-vms-vmv-general-purpose-representation.md)|Declara a herança virtual.|
|[/volatile](volatile-volatile-keyword-interpretation.md)|Seleciona como a palavra-chave volátil é interpretada.|
|[/w](compiler-option-warning-level.md)|Desabilita todos os avisos.|
|[/W0, /W1, /W2, /W3, /W4](compiler-option-warning-level.md)|Define o nível de aviso para saída.|
|[/w1, /w2, /w3, /w4](compiler-option-warning-level.md)|Define o nível de aviso para o aviso especificado.|
|[/Wall](compiler-option-warning-level.md)|Habilita todos os avisos, inclusive avisos desabilitados por padrão.|
|[/wd](compiler-option-warning-level.md)|Desabilita o aviso especificado.|
|[/we](compiler-option-warning-level.md)|Trata o aviso especificado como um erro.|
|[/WL](wl-enable-one-line-diagnostics.md)|Habilita o diagnóstico em uma linha para mensagens de erro e aviso durante a compilação do código-fonte do C++ da linha de comando.|
|[/wo](compiler-option-warning-level.md)|Exibe o aviso especificado apenas uma vez.|
|[/Wp64](wp64-detect-64-bit-portability-issues.md)|{1&gt;{2&gt;Obsoleta. &lt;2}&lt;1} Detecta problemas de portabilidade de 64 bits.|
|[/Wv](compiler-option-warning-level.md)|Não exibe nenhum aviso introduzido após a versão especificada do compilador.|
|[/WX](compiler-option-warning-level.md)|Trata todos os avisos como erros.|
|[/X](x-ignore-standard-include-paths.md)|Ignora o diretório de inclusão padrão.|
|[/Y-](y-ignore-precompiled-header-options.md)|Ignora todas as outras opções de compilador do cabeçalho pré-compilado na compilação atual.|
|[/Yc](yc-create-precompiled-header-file.md)|Cria um arquivo de cabeçalho pré-compilado.|
|[/Yd](yd-place-debug-information-in-object-file.md)|Preterido. Coloca informações de depuração completas em todos os arquivos de objeto. Em vez disso, use [/Zi](z7-zi-zi-debug-information-format.md) .|
|[/Yl](yl-inject-pch-reference-for-debug-library.md)|Injeta uma referência PCH durante a criação de uma biblioteca de depuração|
|[/Yu](yu-use-precompiled-header-file.md)|Usa um arquivo de cabeçalho pré-compilado durante a compilação.|
|[/Z7](z7-zi-zi-debug-information-format.md)|Gera informações de depuração compatíveis com o C 7,0.|
|[/Za](za-ze-disable-language-extensions.md)|Desabilita extensões de linguagem.|
|[/Zc](zc-conformance.md)|Especifica o comportamento padrão em [/ze](za-ze-disable-language-extensions.md). [/Za,/Ze (desabilitar extensões de linguagem)](za-ze-disable-language-extensions.md)|
|[/Ze](za-ze-disable-language-extensions.md)|Preterido. Habilita extensões de linguagem.|
|[/Zf](zf.md)|Melhora o tempo de geração de PDB em compilações paralelas.|
|[/Zg](zg-generate-function-prototypes.md)|Removido no Visual Studio 2015. Gera protótipos de função.|
|[/ZH](zh.md)|Especifica MD5, SHA-1 ou SHA-256 para somas de verificação nas informações de depuração.|
|[/ZI](z7-zi-zi-debug-information-format.md)|Inclui informações de depuração em um banco de dados do programa compatível com Editar e Continuar.|
|[/Zi](z7-zi-zi-debug-information-format.md)|Gera informações completas de depuração.|
|[/Zl](zl-omit-default-library-name.md)|Remove o nome da biblioteca padrão do arquivo .obj (somente x86).|
|[/Zm](zm-specify-precompiled-header-memory-allocation-limit.md)|Especifica o limite de alocação da memória do cabeçalho pré-compilado.|
|[/Zo](zo-enhance-optimized-debugging.md)|Gera informações de depuração aprimoradas para código otimizado.|
|[/Zp](zp-struct-member-alignment.md)|Empacota membros da estrutura.|
|[/Zs](zs-syntax-check-only.md)|Verifica apenas a sintaxe.|
|[/ZW](zw-windows-runtime-compilation.md)|Produz um arquivo de saída para ser executado no Windows Runtime.|

## <a name="see-also"></a>Veja também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
