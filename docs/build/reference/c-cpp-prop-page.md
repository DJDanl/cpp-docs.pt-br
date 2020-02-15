---
title: Propriedades deC++ projeto/C (Visual Studio)
description: Guia de referência para as propriedades de páginas deC++ Propriedades do Microsoft C/Project do Visual Studio.
ms.date: 02/09/2020
ms.topic: article
ms.assetid: 16375038-4917-4bd0-9a2a-26343c1708b7
ms.openlocfilehash: fdfcaaebe8394fedd160c6c02e8c938543f845e2
ms.sourcegitcommit: 8414cd91297dea88c480e208c7b5301db9972f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2020
ms.locfileid: "77257748"
---
# <a name="cc-property-pages"></a>Páginas CC++ /Property

As páginas de propriedades a seguir são encontradas em **Propriedades** de > de **projeto** > **Propriedades de configuração** > **C/C++** :

## <a name="cc-general-properties"></a>Propriedades CC++ /General

### <a name="additional-include-directories"></a>Diretórios de Inclusão Adicionais

Especifica um ou mais diretórios a serem adicionados ao caminho de inclusão, separados por ponto e vírgula no caso de mais de um. Define [/i (diretórios de inclusão adicionais)](i-additional-include-directories.md).

### <a name="additional-using-directories"></a>Diretórios #using adicionais

Especifica um ou mais diretórios (nomes de diretório separados com ponto e vírgula) a serem pesquisados para resolver nomes passados para uma diretiva de #using. Define [/ai](ai-specify-metadata-directories.md).

### <a name="debug-information-format"></a>Formato de informações de depuração

Especifica o tipo de informações de depuração geradas pelo compilador.  Essa propriedade requer configurações de vinculador compatíveis. Define [/Z7,/Zi,/Zi (formato de informações de depuração)](z7-zi-zi-debug-information-format.md).

#### <a name="choices"></a>Opções

- **Nenhum** – não produz nenhuma informação de depuração, portanto, a compilação pode ser mais rápida.
- **Compatível com C7** – selecione o tipo de informações de depuração criadas para o seu programa e se essas informações são mantidas em arquivos de objeto (. obj) ou em um banco de dados de programa (PDB).
- **Programa de banco de dados** – produz um banco de dados de programa (PDB) que contém informações de tipo e informações de depuração simbólicas para uso com o depurador. As informações de depuração simbólicas incluem os nomes e tipos de variáveis e funções e números de linha.
- **Banco de dados do programa para editar e continuar** – produz um banco de dados do programa, conforme descrito acima, em um formato que dá suporte ao recurso [Editar e continuar](/visualstudio/debugger/edit-and-continue) .

### <a name="support-just-my-code-debugging"></a>Suporte à depuração de Apenas Meu Código

Adiciona o código de suporte para habilitar a depuração de [apenas meu código](/visualstudio/debugger/just-my-code) nesta unidade de compilação. Define [/JMC](jmc.md).

### <a name="common-language-runtime-support"></a>Suporte a Common Language RunTime

Use o serviço de tempo de execução do .NET.  Essa opção é incompatível com algumas outras opções; consulte a documentação na família de opções do [/CLR](clr-common-language-runtime-compilation.md) para obter detalhes.

#### <a name="choices"></a>Opções

- **Não há suporte a Common Language Runtime** -sem suporte a Common Language Runtime
- **Suporte a Common Language Runtime** – cria metadados para seu aplicativo que podem ser consumidos por outros aplicativos CLR. Também permite que seu aplicativo consuma tipos e dados nos metadados de outros componentes do CLR.
- **Suporte a Common Language Runtime MSIL puro** – produz um arquivo de saída somente [MSIL](/dotnet/standard/managed-code)sem código executável nativo, embora possa conter tipos nativos compilados para MSIL.
- **Suporte a Common Language Runtime do MSIL seguro** – produz um arquivo de saída MSIL-only (sem código executável nativo) e verificável.

### <a name="consume-windows-runtime-extension"></a>Consumir extensão de Windows Runtime

Consuma as extensões de idiomas de tempo de execução do Windows. Define [/zw](zw-windows-runtime-compilation.md).

### <a name="suppress-startup-banner"></a>Suprimir Faixa de Inicialização

Suprime a exibição da faixa de logon quando o compilador é iniciado e exibe mensagens informativas durante a compilação.

### <a name="warning-level"></a>Nível de aviso

Selecione o rigor que você deseja que o compilador aplique aos erros de código. Define [/W0-/W4](compiler-option-warning-level.md).

#### <a name="choices"></a>Opções

- Desativar **todos os avisos** -nível 0 Desabilita todos os avisos.
- **Level1** -Level 1 exibe avisos graves. Nível 1 é o nível de aviso padrão na linha de comando.
- **Level2** -Level 2 exibe todos os avisos de nível 1 e avisos menos graves que o nível 1.
- O **Level3** -Level 3 exibe todos os avisos de nível 2 e todos os outros avisos recomendados para fins de produção.
- **Level4** -Level 4 exibe todos os avisos de nível 3, além de avisos informativos, que, na maioria dos casos, podem ser ignorados com segurança.
- **EnableAllWarnings** – habilita todos os avisos, incluindo aqueles desabilitados por padrão.

### <a name="treat-warnings-as-errors"></a>Tratar avisos como erros

Trata avisos do compilador como erros. Para um novo projeto, pode ser melhor usar [/WX](wx-treat-linker-warnings-as-errors.md) em cada compilação. Resolva todos os avisos para minimizar os defeitos de código difíceis de encontrar.

### <a name="warning-version"></a>Versão de aviso

Ocultar avisos introduzidos após uma versão específica do compilador. Define [/WV: xx\[. yy\[. zzzzz\]\]](wx-treat-linker-warnings-as-errors.md).

### <a name="diagnostics-format"></a>Formato de diagnóstico

Habilita o diagnóstico avançado, com informações de coluna e contexto de origem em mensagens de diagnóstico.

#### <a name="choices"></a>Opções

- **Cursor** -fornece informações de coluna na mensagem de diagnóstico. E, gera a linha relevante do código-fonte com um cursor que indica a coluna incorreta.
- **Informações da coluna** – fornece adicionalmente o número da coluna dentro da linha em que o diagnóstico é emitido, quando aplicável.
- **Clássico** -gera apenas as mensagens de diagnósticos anteriores e concisas com o número de linha.

### <a name="sdl-checks"></a>Verificações do SDL

Verificações recomendadas do SDL (ciclo de vida de desenvolvimento de segurança) adicionais; inclui a habilitação de recursos adicionais de geração de código seguro e permite avisos extras relevantes de segurança como erros. Define [/SDL,/SDL-](sdl-enable-additional-security-checks.md).

### <a name="multi-processor-compilation"></a>Compilação de multiprocessador

Compilação de multiprocessador.

## <a name="cc-optimization-properties"></a>Propriedades deC++ otimização/C

### <a name="optimization"></a>Optimization

Selecione a opção para otimização de código; escolha personalizado para usar opções de otimização específicas. Define [/OD](od-disable-debug.md), [/O1,/O2](o-options-optimize-code.md).

#### <a name="choices"></a>Opções

- **Personalizar** – otimização personalizada.
- **Desabilitado** – desabilitar a otimização.
- **Otimização máxima (favorecer tamanho)** -equivalente a/og/os/Oy/Ob2/GS/GF/GY
- **Otimização máxima (favorecer velocidade)** -equivalente a/og/Oi/OT/Oy/Ob2/GS/GF/GY
- **Otimizações (favorecer velocidade)** -equivalente a/og/Oi/OT/Oy/Ob2

### <a name="inline-function-expansion"></a>Expansão de função embutida

Selecione o nível de expansão de [função embutida](../../cpp/inline-functions-cpp.md) para a compilação. Define [/Ob1,/Ob2](ob-inline-function-expansion.md).

#### <a name="choices"></a>Opções

- **Padrão**
- **Disabled-desabilita** a expansão embutida, que está ativada por padrão.
- **Somente __inline** -expande apenas as funções marcadas como **embutidas**, `__inline`, `__forceinline`ou `__inline`. Ou, em uma C++ função de membro, definida em uma declaração de classe.
- **Qualquer função adequada** -expande as funções marcadas como **embutidas** ou `__inline` e quaisquer outras funções que o compilador escolha. (A expansão ocorre no critério do compilador, muitas vezes conhecida como *autolinhar*.)

### <a name="enable-intrinsic-functions"></a>Habilitar funções intrínsecas

Habilita funções intrínsecas.  O uso de funções intrínsecas gera um código mais rápido, mas possivelmente maior. Define [/Oi](oi-generate-intrinsic-functions.md).

### <a name="favor-size-or-speed"></a>Favorecer tamanho ou velocidade

Se deseja favorecer o tamanho do código ou a velocidade do código; ' Otimização global ' deve estar ativada. Define [/OT,/os](os-ot-favor-small-code-favor-fast-code.md).

#### <a name="choices"></a>Opções

- **Favorecer** código pequeno-favorecer pequenos códigos. Minimiza o tamanho de EXEs e DLLs instruindo o compilador a favorecer o tamanho em velocidade.
- **Favorecer** código rápido de código-favorecer rapidamente. Maximiza a velocidade de EXEs e DLLs instruindo o compilador a favorecer a velocidade em relação ao tamanho. (Esse valor é o padrão.)
- **Nenhum-sem** otimização de tamanho e velocidade.

### <a name="omit-frame-pointers"></a>Omitir ponteiros de quadro

Inibe a criação de ponteiros de quadros na pilha de chamadas.

### <a name="enable-fiber-safe-optimizations"></a>Habilitar otimizações de fibra segura

Habilita a otimização de espaço de memória ao usar fibras e acesso de armazenamento local de thread. Define [/gt](gt-support-fiber-safe-thread-local-storage.md).

### <a name="whole-program-optimization"></a>Otimização do programa inteiro

Permite otimizações entre módulos atrasando a geração de código para o tempo de vinculação. Requer a opção de vinculador "geração de código do tempo de vinculação". Define [/GL](gl-whole-program-optimization.md).

## <a name="cc-preprocessor-properties"></a>Propriedades deC++ C/pré-processador

### <a name="preprocessor-definitions"></a>Definições do Pré-processador

Define os símbolos de pré-processamento para o arquivo de origem.

### <a name="undefine-preprocessor-definitions"></a>Excluir as definições do pré-processador

Especifica uma ou mais exclusões de definição do pré-processador. Define [/u](u-u-undefine-symbols.md).

### <a name="undefine-all-preprocessor-definitions"></a>Excluir todas as definições do pré-processador

Exclua as definições de todos os valores do pré-processador definidos anteriormente. Define [/u](u-u-undefine-symbols.md).

### <a name="ignore-standard-include-paths"></a>Ignorar caminhos de inclusão padrão

Impede que o compilador procure arquivos de inclusão em diretórios especificados nas variáveis de ambiente INCLUDE.

### <a name="preprocess-to-a-file"></a>Pré-processar para um arquivo

Pré-processa arquivos C C++ e Source e grava a saída pré-processada em um arquivo. Essa opção suprime a compilação e não produz um arquivo de *`.obj`* .

### <a name="preprocess-suppress-line-numbers"></a>Pré-processar suprimir números de linha

Pré-processar sem diretivas de #line.

### <a name="keep-comments"></a>Manter comentários

Suprime a faixa de comentário do código-fonte; requer que uma das opções de ' pré-processamento ' seja definida. Define [/c](c-preserve-comments-during-preprocessing.md).

## <a name="cc-code-generation-properties"></a>Propriedades deC++ geração de código C/Code

### <a name="enable-string-pooling"></a>Habilitar pool de cadeias de caracteres

O compilador cria apenas uma cópia somente leitura de cadeias de caracteres idênticas na imagem do programa. Ele resulta em programas menores, uma otimização chamada *pool de cadeias de caracteres*. [/O1,/O2](o-options-optimize-code.md)e [/Zi](z7-zi-zi-debug-information-format.md) definem automaticamente a opção [/GF](gf-eliminate-duplicate-strings.md) .

### <a name="enable-minimal-rebuild"></a>Habilitar recompilação mínima

Habilita a recompilação mínima, que determina se os C++ arquivos de origem devem ser C++ recompilados que incluem definições de classe alteradas, armazenadas em arquivos de *`.h`* de cabeçalho.

### <a name="enable-c-exceptions"></a>Habilitar exceções C++

Especifica o modelo de tratamento de exceções a ser utilizado pelo compilador.

#### <a name="choices"></a>Opções

- **Sim com Exceções SEH** – o modelo de tratamento de exceções que captura exceções assíncronas (estruturadasC++) e síncronas (). Define [/EHA](eh-exception-handling-model.md).
- **Sim** – o modelo de tratamento de exceção que captura C++ exceções apenas e informa o compilador para assumir que as funções externas do C nunca C++ lançam uma exceção. Define [/EHsc](eh-exception-handling-model.md).
- **Sim com as funções extern C** – o modelo de tratamento de exceção C++ que captura apenas exceções e informa o compilador para assumir que as funções externas do C geram uma exceção. Define [o/EHS](eh-exception-handling-model.md).
- **Não** -nenhuma manipulação de exceção.

### <a name="smaller-type-check"></a>Verificação de tipo menor

Habilite a verificação de conversão para tipos menores, incompatível com qualquer tipo de otimização diferente de depuração. Define [/RTCc](rtc-run-time-error-checks.md).

### <a name="basic-runtime-checks"></a>Verificações básicas de tempo de execução

Habilitar verificações de erro básicas de tempo de execução, incompatível com qualquer tipo de otimização diferente de Debug. Define [/RTCs,/RTCu,/RTC1](rtc-run-time-error-checks.md).

#### <a name="choices"></a>Opções

- **Quadros de pilha** – habilita a verificação de erros em tempo de execução de quadro de pilha.
- **Variáveis não inicializadas** – relata quando uma variável é usada sem ter sido inicializada.
- **Ambos (/RTC1, equiv. to/RTCsu)** -equivalente de/RTCsu.
- **Padrão** -verificações de tempo de execução padrão.

### <a name="runtime-library"></a>Biblioteca em Runtime

Especifique a biblioteca de runtime para vinculação. Define [/MT,/MTD,/MD,/MDD](md-mt-ld-use-run-time-library.md).

#### <a name="choices"></a>Opções

- **Multithread** -faz com que seu aplicativo use a versão estática e multithread da biblioteca de tempo de execução.
- **Depuração** multi-threaded-define _DEBUG e _MT. Essa opção também faz com que o compilador Coloque o nome da biblioteca *LIBCMTD. lib* no arquivo *`.obj`* para que o vinculador use *LIBCMTD. lib* para resolver símbolos externos.
- **Dll** multi-threaded – faz com que seu aplicativo use a versão específica de MULTITHREAD e dll da biblioteca de tempo de execução. Define _MT e _DLL e faz com que o compilador Coloque o nome da biblioteca *msvcrt. lib* no arquivo *`.obj`* .
- **Dll de depuração** multi-threaded-define _DEBUG, _MT e _DLL e faz com que seu aplicativo use a versão específica de MULTITHREAD e dll da biblioteca de tempo de execução. Ele também faz com que o compilador Coloque o nome da biblioteca *MSVCRTD. lib* no arquivo *`.obj`* .

### <a name="struct-member-alignment"></a>Alinhamento de membro de struct

Especifica limites de 1, 2, 4 ou 8 bytes para alinhamento de membro de struct. Define [/ZP](zp-struct-member-alignment.md).

#### <a name="choices"></a>Opções

- **1 byte** -pacotes estruturas em limites de 1 byte. O mesmo que **`/Zp`** .
- **2 bytes** -pacotes de estruturas em limites de 2 bytes.
- **4 bytes** -pacotes de estruturas em limites de 4 bytes.
- **8 bytes** -pacotes de estruturas em limites de 8 bytes (padrão).
- **16 bytes** -pacotes de estruturas em limites de 16 bytes.
- **Padrão** -configurações de alinhamento padrão.

### <a name="security-check"></a>Verificação de segurança

A Verificação de Segurança ajuda a detectar saturações de buffer de pilha, uma tentativa de ataque comum à segurança de um programa.

#### <a name="choices"></a>Opções

- **Desabilitar verificação de segurança** – Desabilitar a verificação de segurança. Define [/GS-](gs-buffer-security-check.md).
- **Habilitar verificação de segurança** – Habilitar a verificação de segurança. Define [/GS](gs-buffer-security-check.md).

### <a name="control-flow-guard"></a>Proteção de fluxo de controle

A verificação de segurança de proteção ajuda a detectar tentativas de expedição para um bloco de código ilegal.

#### <a name="choices"></a>Opções

- **Sim** – habilite a verificação de segurança com os conjuntos de proteção [/Guard: CF](guard-enable-control-flow-guard.md).
- **Não**

### <a name="enable-function-level-linking"></a>Habilitar vinculação no nível da função

Permite que o compilador empacote funções individuais no formato de funções empacotadas (COMDATs). Necessário para editar e continuar a trabalhar. Define [/GY](gy-enable-function-level-linking.md).

### <a name="enable-parallel-code-generation"></a>Habilitar geração de código paralelo

Permite que o compilador gere código paralelo para loops identificados usando `#pragma loop(hint_parallel[(n)])` quando a otimização está habilitada.

### <a name="enable-enhanced-instruction-set"></a>Habilitar conjunto de instruções avançado

Habilite o uso de instruções encontradas em processadores que dão suporte a conjuntos de instruções aprimoradas. Por exemplo, os aprimoramentos de SSE, SSE2, AVX e AVX2 para IA-32. E os aprimoramentos do AVX e do AVX2 para x64. Atualmente **`/arch:SSE`** e **`/arch:SSE2`** estão disponíveis apenas ao compilar para a arquitetura x86. Se nenhuma opção for especificada, o compilador usará as instruções encontradas em processadores que dão suporte a SSE2. O uso de instruções avançadas pode ser desabilitado com **`/arch:IA32`** . Para obter mais informações, consulte [/Arch (x86)](arch-x86.md), [/Arch (x64)](arch-x64.md) e [/Arch (ARM)](arch-arm.md).

#### <a name="choices"></a>Opções

- **Extensões SIMD de streaming** – extensões SIMD de streaming. Define **`/arch:SSE`**
- **Extensões SIMD de streaming 2** -Streaming SIMD Extensions 2. Define **`/arch:SSE2`**
- **Extensões de vetor avançadas** -extensões de vetor avançadas. Define **`/arch:AVX`**
- **Extensões de vetor avançadas 2** -extensões de vetor avançadas 2. Define **`/arch:AVX2`**
- **Nenhuma instrução avançada** -nenhuma instrução aprimorada. Define **`/arch:IA32`**
- **Não definido** -não definido.

### <a name="floating-point-model"></a>Modelo de ponto flutuante

Define o modelo de ponto flutuante. Define [/fp: preciso,/fp: strict,/fp: Fast](fp-specify-floating-point-behavior.md).

#### <a name="choices"></a>Opções

- **Preciso** -padrão. Melhora a consistência de testes de ponto flutuante para igualdade e desigualdade.
- **Estrito** -o modelo de ponto flutuante mais estrito. **`/fp:strict`** faz **`fp_contract`** ficar desligadas e **`fenv_access`** ser ativadas. o **`/fp:except`** é implícito e pode ser desabilitado especificando-se explicitamente **`/fp:except-`** . Quando usado com **`/fp:except-`** , **`/fp:strict`** impõe semântica estrita de ponto flutuante, mas sem respeitar eventos excepcionais.
- **Rápido** – cria o código mais rápido na maioria dos casos.

### <a name="enable-floating-point-exceptions"></a>Habilitar exceções de ponto flutuante

Modelo de exceção de ponto flutuante confiável. As exceções serão geradas imediatamente depois que forem disparadas. Define [/fp: except](fp-specify-floating-point-behavior.md).

### <a name="create-hotpatchable-image"></a>Criar imagem Hotpatchable

Quando HotPatching está ativado, o compilador garante que a primeira instrução de cada função seja de dois bytes, conforme necessário para a aplicação de patches. Define [/hotpatch](hotpatch-create-hotpatchable-image.md).

### <a name="spectre-mitigation"></a>Mitigação de Spectre

Spectre atenuações para o CVE 2017-5753. Define [/Qspectre](qspectre.md).

#### <a name="choices"></a>Opções

- **Habilitado** -habilitar o recurso de mitigação de Spectre para CVE 2017-5753
- **Desabilitado** -não definido.

## <a name="cc-language-properties"></a>Propriedades deC++ C/Language

### <a name="disable-language-extensions"></a>Desabilitar extensões de linguagem

Suprime ou habilita extensões de linguagem. Define [/za](za-ze-disable-language-extensions.md).

### <a name="conformance-mode"></a>Modo de conformidade

Habilita ou suprime o modo de conformidade. Define [/permissive-](permissive-standards-conformance.md).

### <a name="treat-wchar_t-as-built-in-type"></a>Tratar WChar_t como tipo interno

Quando especificado, o tipo **wchar_t** se torna um tipo nativo que mapeia para `__wchar_t` da mesma forma que os **pequenos** mapas para `__int16`. [/Zc: a wchar_t](zc-wchar-t-wchar-t-is-native-type.md) está ativada por padrão.

### <a name="force-conformance-in-for-loop-scope"></a>Forçar conformidade no escopo do loop for

Usado para implementar o C++ comportamento padrão para a instrução for loops com extensões da Microsoft. Define [/za,/Ze (Desabilite as extensões de linguagem](za-ze-disable-language-extensions.md). [/Zc: forScope](zc-forscope-force-conformance-in-for-loop-scope.md) está ativado por padrão.

### <a name="remove-unreferenced-code-and-data"></a>Remover dados e código sem referência

Quando especificado, o compilador não gera mais informações de símbolo para dados e código sem referência.

### <a name="enforce-type-conversion-rules"></a>Aplicar regras de conversão de tipo

Usado para identificar um tipo de referência rvalue como resultado de uma operação de conversão de acordo com o padrão C++ 11.

### <a name="enable-run-time-type-information"></a>Habilitar informações de tipo de tempo de execução

Adiciona um código para verificar os tipos de objeto C++ no runtime (informações de tipo de runtime). Define [/gr,/GR-](gr-enable-run-time-type-information.md).

### <a name="open-mp-support"></a>Abrir o suporte do MP

Habilita extensões de linguagem OpenMP 2,0. Define [/OpenMP](openmp-enable-openmp-2-0-support.md).

### <a name="c-language-standard"></a>Padrão de linguagem C++

Determina o C++ padrão de idioma que o compilador habilita. Use a versão mais recente quando possível. Define [/std: c++ 14,/std: c++ 17,/std: c + + mais recente](std-specify-language-standard-version.md).

#### <a name="choices"></a>Opções

- **Padrão**
- **Padrão ISO C++ 14**
- **Padrão ISO C++ 17**
- **Visualização-recursos do último C++ rascunho de trabalho**

### <a name="enable-c-modules-experimental"></a>Habilitar C++ módulos (experimental)

Suporte experimental para os C++ módulos TS e biblioteca padrão.

## <a name="cc-precompiled-headers-properties"></a>Propriedades deC++ cabeçalhos C/pré-compilado

### <a name="createuse-precompiled-header"></a>Criar/usar cabeçalho pré-compilado

Habilita a criação ou o uso de um cabeçalho pré-compilado durante o build. Define [/YC](yc-create-precompiled-header-file.md), [/Yu](yu-use-precompiled-header-file.md).

#### <a name="choices"></a>Opções

- **Create** -instrui o compilador a criar um arquivo de cabeçalho pré-compilado (. pch) que representa o estado de compilação em um determinado ponto.
- **Use** -instrui o compilador para usar um arquivo de cabeçalho pré-compilado (. pch) existente na compilação atual.
- **Não usar cabeçalhos pré-compilados** -não está usando cabeçalhos pré-compilados.

### <a name="precompiled-header-file"></a>Arquivo de cabeçalho pré-compilado

Especifica o nome do arquivo de cabeçalho a ser usado ao criar ou usar um arquivo de cabeçalho pré-compilado. Define [/YC](yc-create-precompiled-header-file.md), [/Yu]] (Yu-Use-pré-compilado-header-File.MD).

### <a name="precompiled-header-output-file"></a>Arquivo de saída de cabeçalho pré-compilado

Especifica o caminho ou o nome do arquivo de cabeçalho pré-compilado gerado. Define [/FP](fp-name-dot-pch-file.md).

## <a name="cc-output-files-properties"></a>Propriedades deC++ arquivos de saída/C

### <a name="expand-attributed-source"></a>Expandir fonte atribuída

Criar arquivo de listagem com atributos expandidos injetados no arquivo de origem. Define [/FX](fx-merge-injected-code.md).

### <a name="assembler-output"></a>Saída do Assembler

Especifica o conteúdo do arquivo de saída de linguagem assembly. Define [/FA,/fac,/FAS,/FACS](fa-fa-listing-file.md).

#### <a name="choices"></a>Opções

- **Sem listagem** -sem listagem.
- **Listagem somente de assembly** -código de assembly; *`.asm`*
- **Assembly com código de máquina** -código de máquina e assembly; *`.cod`*
- **Assembly com** código-fonte de código-fonte e assembly; *`.asm`*
- **Assembly, código do computador e origem** -assembly, código do computador e código-fonte; *`.cod`*

### <a name="use-unicode-for-assembler-listing"></a>Usar Unicode para listagem do Assembler

Faz com que o arquivo de saída seja criado no formato UTF-8.

### <a name="asm-list-location"></a>Local da lista de ASM

Especifica o caminho relativo ou o nome do arquivo de listagem ASM; pode ser um nome de arquivo ou diretório. Define [/FA](fa-fa-listing-file.md).

### <a name="object-file-name"></a>Nome do arquivo-objeto

Especifica um nome para substituir o nome do arquivo-objeto padrão. Pode ser um nome de arquivo ou de diretório. Define [/fo](fo-object-file-name.md).

### <a name="program-database-file-name"></a>Nome do arquivo de banco de dados do programa

Especifica um nome para um arquivo PDB gerado pelo compilador; também especifica o nome base para o arquivo IDB gerado pelo compilador necessário; pode ser um nome de arquivo ou diretório. Define [/FD](fd-program-database-file-name.md).

### <a name="generate-xml-documentation-files"></a>Gerar arquivos de documentação XML

Especifica que o compilador deve gerar arquivos de comentário de documentação XML (. XDC). Define [/Doc](doc-process-documentation-comments-c-cpp.md).

### <a name="xml-documentation-file-name"></a>Nome do arquivo de documentação XML

Especifica o nome dos arquivos de documentação XML gerados; pode ser um nome de arquivo ou diretório. Define [/doc:\<name >](doc-process-documentation-comments-c-cpp.md).

## <a name="cc-browse-information-properties"></a>C/C++ Propriedades de informações de procura

### <a name="enable-browse-information"></a>Habilitar informações de procura

Especifica o nível de informações de procura no arquivo *`.bsc`* . Define [/fr](fr-fr-create-dot-sbr-file.md).

### <a name="browse-information-file"></a>Procurar arquivo de informações

Especifica o nome opcional para o arquivo de informações do navegador. Define o [nome de\<de/FR >](fr-fr-create-dot-sbr-file.md).

## <a name="cc-advanced-properties"></a>Propriedades deC++ C/Advanced

### <a name="calling-convention"></a>Convenção de chamada

Selecione a Convenção de chamada padrão para seu aplicativo (pode ser substituída por função). Define [/gd,/GR,/gz,/GV](gd-gr-gv-gz-calling-convention.md).

#### <a name="choices"></a>Opções

- **__cdecl** -especifica a Convenção de chamada __cdecl para todas as C++ funções, exceto funções de membro e funções marcadas __stdcall ou __fastcall.
- **__fastcall** -especifica a Convenção de chamada __fastcall para todas as C++ funções, exceto funções de membro e funções marcadas __cdecl ou __stdcall. Todas as funções de __fastcall devem ter protótipos.
- **__stdcall** -especifica a Convenção de chamada __stdcall para todas as C++ funções, exceto funções de membro e funções marcadas __cdecl ou __fastcall. Todas as funções de __stdcall devem ter protótipos.
- **__vectorcall** -especifica a Convenção de chamada de __vectorcall para todas C++ as funções, exceto funções de membro e funções marcadas __cdecl, __fastcall ou __stdcall. Todas as funções de __vectorcall devem ter protótipos.

### <a name="compile-as"></a>Compilar como

Selecione a opção de linguagem de compilação para arquivos de *`.c`* e *`.cpp`* . Define [/TC,/TP](tc-tp-tc-tp-specify-source-file-type.md).

#### <a name="choices"></a>Opções

- **Padrão** – padrão.
- **Compilar como código C** – compilar como código C.
- **Compilar como código C++** – compilar como código C++.

### <a name="disable-specific-warnings"></a>Desabilitar avisos específicos

Desabilitar os números de aviso especificados. Coloque os números de aviso em uma lista delimitada por ponto e vírgula. Define [/wd\<num >](compiler-option-warning-level.md).

### <a name="forced-include-file"></a>Arquivo de inclusão forçado

um ou mais arquivos de inclusão forçados. Define o [nome de/fi\<>](fi-name-forced-include-file.md).

### <a name="forced-using-file"></a>Arquivo de #using forçado

Especifica um ou mais arquivos de #using forçados. Define o [nome de\<de/FU >](fu-name-forced-hash-using-file.md).

### <a name="show-includes"></a>Mostrar inclusões

Gera uma lista de arquivos de inclusão com a saída do compilador. Define [/showIncludes](showincludes-list-include-files.md).

### <a name="use-full-paths"></a>Usar caminhos completos

Use caminhos completos em mensagens de diagnóstico. Define [/FC](fc-full-path-of-source-code-file-in-diagnostics.md).

### <a name="omit-default-library-name"></a>Omitir nome da biblioteca padrão

Não inclui nomes de biblioteca padrão em arquivos *`.obj`* . Define [/zl](zl-omit-default-library-name.md).

### <a name="internal-compiler-error-reporting"></a>Relatório de erros do compilador interno

> [!NOTE]
> Essa opção foi preterida. A partir do Windows Vista, o relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) .

### <a name="treat-specific-warnings-as-errors"></a>Tratar avisos específicos como erros

Trata o aviso específico do compilador como um erro em que n é um aviso do compilador.

### <a name="additional-options"></a>Opções adicionais

Opções Adicionais.
