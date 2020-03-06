---
title: 'C++SDK de informações de compilação: tabela de eventos'
description: Referência de evento para o SDK C++ do insights do Visual Studio Build
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Events
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 2ccc8a4ef707942963b85edc6db9e21e05610b54
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332953"
---
# <a name="c-build-insights-sdk-event-table"></a>C++SDK de informações de compilação: tabela de eventos

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

## <a name="compiler-events"></a>Eventos do compilador

\ do [compilador](#compiler)
[COMMAND_LINE](#command-line)\
[ENVIRONMENT_VARIABLE](#environment-variable)\
[FILE_INPUT](#file-input)\
[OBJ_OUTPUT](#obj-output)\
[FRONT_END_PASS](#front-end-pass)\
[BACK_END_PASS](#back-end-pass)

## <a name="compiler-front-end-events"></a>Eventos de front-end do compilador

[C1_DLL](#c1-dll)\
[FRONT_END_FILE](#front-end-file)\
[TEMPLATE_INSTANTIATION](#template-instantiation)\
[SYMBOL_NAME](#symbol-name)

## <a name="compiler-back-end-events"></a>Eventos de back-end do compilador

[C2_DLL](#c2-dll)\
[WHOLE_PROGRAM_ANALYSIS](#whole-program-analysis)\
[TOP_DOWN](#top-down)\
[BOTTOM_UP](#bottom-up)\
[CODE_GENERATION](#code-generation)\
\ de [thread](#thread)
[Função](#function)\
[FORCE_INLINEE](#force-inlinee)

## <a name="linker-events"></a>Eventos do vinculador

\ do [vinculador](#linker)
[COMMAND_LINE](#command-line)\
[ENVIRONMENT_VARIABLE](#environment-variable)\
[FILE_INPUT](#file-input)\
[EXECUTABLE_IMAGE_OUTPUT](#executable-image-output)\
[EXP_OUTPUT](#exp-output)\
[IMP_LIB_OUTPUT](#imp-lib-output)\
[LIB_OUTPUT](#lib-output)\
\ [PASS1](#pass1)
[PRE_LTCG_OPT_REF](#pre-ltcg-opt-ref)\
\ [LTCG](#ltcg)
[OPT_REF](#opt-ref)\
[OPT_ICF](#opt-icf)\
[OPT_LBR](#opt-lbr)\
[PASS2](#pass2)

## <a name="event-table"></a>Tabela de eventos

| {1&gt;Evento&lt;1} | Propriedade | Descrição |
|--|--|--|
| <a name="back-end-pass"></a>BACK_END_PASS | Tipo | Atividade |
|  | Pais | [COMPILER](#compiler) |
|  | Children | [C2_DLL](#c2-dll) |
|  | {1&gt;Propriedades&lt;1} | -Caminho absoluto para o arquivo de origem de entrada<br/>-Caminho absoluto para o arquivo de objeto de saída |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[CompilerPass](cpp-event-data-types/compiler-pass.md)<br/>[BackEndPass](cpp-event-data-types/back-end-pass.md) |
|  | Descrição | Ocorre no início e na parada da passagem de back-end do compilador. Essa passagem é responsável por otimizar o código C/C++ Source analisado e convertê-lo no código da máquina. |
| <a name="bottom-up"></a>BOTTOM_UP | Tipo | Atividade |
|  | Pais | [WHOLE_PROGRAM_ANALYSIS](#whole-program-analysis) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[BottomUp](cpp-event-data-types/bottom-up.md) |
|  | Descrição | Ocorre no início e na parada da aprovação de baixo para toda a análise do programa. |
| <a name="c1-dll"></a>C1_DLL | Tipo | Atividade |
|  | Pais | [FRONT_END_PASS](#front-end-pass) |
|  | Children | [FRONT_END_FILE](#front-end-file)<br/>[SYMBOL_NAME](#symbol-name)<br/>[TEMPLATE_INSTANTIATION](#template-instantiation) |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[C1DLL](cpp-event-data-types/c1-dll.md) |
|  | Descrição | Ocorre no início e na parada de uma invocação *C1. dll* ou *c1xx. dll* . Essas DLLs são o C e C++ o front-end do compilador. Eles são invocados unicamente pelo driver do compilador (*CL. exe*). |
| <a name="c2-dll"></a>C2_DLL | Tipo | Atividade |
|  | Pais | [BACK_END_PASS](#back-end-pass)<br/>[LTCG](#ltcg) |
|  | Children | [CODE_GENERATION](#code-generation)<br/>[WHOLE_PROGRAM_ANALYSIS](#whole-program-analysis) |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[C2DLL](cpp-event-data-types/c2-dll.md) |
|  | Descrição | Ocorre no início e na parada de uma invocação de *C2. dll* . Essa DLL é o back-end do compilador. Ele é chamado pelo driver do compilador (*CL. exe*). Ele também é invocado pelo vinculador (*link. exe*) quando a geração de código de tempo de vinculação é usada. |
| <a name="code-generation"></a>CODE_GENERATION | Tipo | Atividade |
|  | Pais | [C2_DLL](#c2-dll) |
|  | Children | [FUNCTION](#function)<br/>[PROCESSO](#thread) |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[CodeGeneration](cpp-event-data-types/code-generation.md) |
|  | Descrição | Ocorre no início e na parada da fase de geração de código do back-end. |
| <a name="command-line"></a>COMMAND_LINE | Tipo | Evento Simples |
|  | Pais | [COMPILER](#compiler)<br/>[VINCULADOR](#linker) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | -A linha de comando usada para invocar *CL. exe* ou *link. exe* |
|  | Capturar classes | [SimpleEvent](cpp-event-data-types/simple-event.md)<br/>[CommandLine](cpp-event-data-types/command-line.md) |
|  | Descrição | Ocorre quando o compilador e o vinculador são concluídos avaliando a linha de comando. A linha de comando avaliada inclui todos os parâmetros *CL. exe* e *link. exe* passados por meio de um arquivo de resposta. Ele também inclui parâmetros para *CL. exe* e *link. exe* passados por meio de variáveis de ambiente, como cl, \_CL\_, link e \_link\_. |
| <a name="compiler"></a>COMPILER | Tipo | Atividade |
|  | Pais | Nenhum |
|  | Children | [BACK_END_PASS](#back-end-pass)<br/>[COMMAND_LINE](#command-line)<br/>[ENVIRONMENT_VARIABLE](#environment-variable)<br/>[FILE_INPUT](#file-input)<br/>[OBJ_OUTPUT](#obj-output)<br/>[FRONT_END_PASS](#front-end-pass) |
|  | {1&gt;Propriedades&lt;1} | -Versão do compilador<br/>-Diretório de trabalho<br/>-Caminho absoluto para o *CL. exe* invocado |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[Invocação](cpp-event-data-types/invocation.md)<br/>[Compiler](cpp-event-data-types/compiler.md) |
|  | Descrição | Ocorre no início e na parada de uma invocação *CL. exe* . |
| <a name="environment-variable"></a>ENVIRONMENT_VARIABLE | Tipo | Evento Simples |
|  | Pais | [COMPILER](#compiler)<br/>[VINCULADOR](#linker) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | -O nome da variável de ambiente<br/>-O valor da variável de ambiente. |
|  | Capturar classes | [SimpleEvent](cpp-event-data-types/simple-event.md)<br/>[EnvironmentVariable](cpp-event-data-types/environment-variable.md) |
|  | Descrição | Ocorre uma vez para cada variável de ambiente existente no momento em que *CL. exe* ou *link. exe* é invocado. |
| <a name="executable-image-output"></a>EXECUTABLE_IMAGE_OUTPUT | Tipo | Evento Simples |
|  | Pais | [VINCULADOR](#linker) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | -O caminho absoluto para um arquivo de saída DLL ou executável. |
|  | Capturar classes | [SimpleEvent](cpp-event-data-types/simple-event.md)<br/>[Saída de](cpp-event-data-types/file-output.md)<br/>[ExecutableImageOutput](cpp-event-data-types/executable-image-output.md) |
|  | Descrição | Ocorre quando uma das entradas do vinculador é uma DLL ou um arquivo de imagem executável. |
| <a name="exp-output"></a>EXP_OUTPUT | Tipo | Evento Simples |
|  | Pais | [VINCULADOR](#linker) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | -O caminho absoluto para um arquivo de saída *. exp* . |
|  | Capturar classes | [SimpleEvent](cpp-event-data-types/simple-event.md)<br/>[Saída de](cpp-event-data-types/file-output.md)<br/>[ExpOutput](cpp-event-data-types/exp-output.md) |
|  | Descrição | Ocorre quando uma das saídas do vinculador é um arquivo *. exp* . |
| <a name="file-input"></a>FILE_INPUT | Tipo | Evento Simples |
|  | Pais | [COMPILER](#compiler)<br/>[VINCULADOR](#linker) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | -O caminho absoluto para o arquivo de entrada<br/>-O tipo de arquivo de entrada |
|  | Capturar classes | [SimpleEvent](cpp-event-data-types/simple-event.md)<br/>[Entrada de dados](cpp-event-data-types/file-input.md) |
|  | Descrição | Ocorre ao anunciar uma entrada do *CL. exe* ou do *link. exe* . |
| <a name="force-inlinee"></a>FORCE_INLINEE | Tipo | Evento Simples |
|  | Pais | [FUNCTION](#function) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | -O nome da função forçada/embutida.<br/>-O tamanho da função de força embutida, representado como uma contagem de instruções intermediárias. |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[ForceInlinee](cpp-event-data-types/force-inlinee.md) |
|  | Descrição | Ocorre quando uma função está sendo imposta-embutida em outra função por meio do uso da palavra-chave `__forceinline`. |
| <a name="front-end-file"></a>FRONT_END_FILE | Tipo | Atividade |
|  | Pais | [C1_DLL](#c1-dll)<br/>[FRONT_END_FILE](#front-end-file) |
|  | Children | [FRONT_END_FILE](#front-end-file)<br/>[TEMPLATE_INSTANTIATION](#template-instantiation) |
|  | {1&gt;Propriedades&lt;1} | -Caminho absoluto para o arquivo. |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[FrontEndfile](cpp-event-data-types/front-end-file.md) |
|  | Descrição | Ocorre quando o front-end do compilador é iniciado e interrompe o processamento de um arquivo. Esse evento é recursivo. A recursão acontece quando o front-end está analisando os arquivos incluídos. |
| <a name="front-end-pass"></a>FRONT_END_PASS | Tipo | Atividade |
|  | Pais | [COMPILER](#compiler) |
|  | Children | [C1_DLL](#c1-dll) |
|  | {1&gt;Propriedades&lt;1} | -Caminho absoluto para o arquivo de origem de entrada<br/>-Caminho absoluto para o arquivo de objeto de saída |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[CompilerPass](cpp-event-data-types/compiler-pass.md)<br/>[FrontEndPass](cpp-event-data-types/front-end-pass.md) |
|  | Descrição | Ocorre no início e na parada da passagem de front-end do compilador. Essa passagem é responsável por analisar o código-C++ fonte C/Source e convertê-lo em linguagem intermediária. |
| <a name="function"></a>FUNCIONAMENTO | Tipo | Atividade |
|  | Pais | [CODE_GENERATION](#code-generation)<br/>[PROCESSO](#thread)<br/>[TOP_DOWN](#top-down) |
|  | Children | [FORCE_INLINEE](#force-inlinee) |
|  | {1&gt;Propriedades&lt;1} | -Nome da função |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[Função](cpp-event-data-types/function.md) |
|  | Descrição | Ocorre ao iniciar e terminar a geração do código para uma função. |
| <a name="imp-lib-output"></a>IMP_LIB_OUTPUT | Tipo | Evento Simples |
|  | Pais | [VINCULADOR](#linker) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | -O caminho absoluto para um arquivo de saída da biblioteca de importação. |
|  | Capturar classes | [SimpleEvent](cpp-event-data-types/simple-event.md)<br/>[Saída de](cpp-event-data-types/file-output.md)<br/>[ImpLibOutput](cpp-event-data-types/imp-lib-output.md) |
|  | Descrição | Ocorre quando uma das saídas do vinculador é uma biblioteca de importação. |
| <a name="lib-output"></a>LIB_OUTPUT | Tipo | Evento Simples |
|  | Pais | [VINCULADOR](#linker) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | -O caminho absoluto para um arquivo de saída da biblioteca estática. |
|  | Capturar classes | [SimpleEvent](cpp-event-data-types/simple-event.md)<br/>[Saída de](cpp-event-data-types/file-output.md)<br/>[LibOutput](cpp-event-data-types/lib-output.md) |
|  | Descrição | Ocorre quando uma das saídas do vinculador é a biblioteca estática. |
| <a name="linker"></a>VINCULADOR | Tipo | Atividade |
|  | Pais | Nenhum |
|  | Children | [COMMAND_LINE](#command-line)<br/>[ENVIRONMENT_VARIABLE](#environment-variable)<br/>[EXECUTABLE_IMAGE_OUTPUT](#executable-image-output)<br/>[EXP_OUTPUT](#exp-output)<br/>[FILE_INPUT](#file-input)<br/>[IMP_LIB_OUTPUT](#imp-lib-output)<br/>[LIB_OUTPUT](#lib-output)<br/>[PASS1](#pass1)<br/>[PASS2](#pass2) |
|  | {1&gt;Propriedades&lt;1} | -Versão do vinculador<br/>-Diretório de trabalho<br/>-Caminho absoluto para o *link. exe* invocado |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[Invocação](cpp-event-data-types/invocation.md)<br/>[Vinculador](cpp-event-data-types/linker.md) |
|  | Descrição | Ocorre no início e na parada de uma invocação de *link. exe* . |
| <a name="ltcg"></a>LTCG | Tipo | Atividade |
|  | Pais | [PASS1](#pass1) |
|  | Children | [C2_DLL](#c2-dll) |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[LTCG](cpp-event-data-types/ltcg.md) |
|  | Descrição | Ocorre no início e na parada da geração de código de tempo de vinculação. |
| <a name="obj-output"></a>OBJ_OUTPUT | Tipo | Evento Simples |
|  | Pais | [COMPILER](#compiler) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | -O caminho absoluto para o arquivo de saída *. obj* |
|  | Capturar classes | [SimpleEvent](cpp-event-data-types/simple-event.md)<br/>[Saída de](cpp-event-data-types/file-output.md)<br/>[ObjOutput](cpp-event-data-types/obj-output.md) |
|  | Descrição | Ocorre uma vez para cada saída *. obj* produzida pelo *CL. exe*. |
| <a name="opt-icf"></a>OPT_ICF | Tipo | Atividade |
|  | Pais | [PASS1](#pass1) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[OptICF](cpp-event-data-types/opt-icf.md) |
|  | Descrição | Ocorre no início e na parada da otimização do vinculador de COMDAT idêntico (/OPT: ICF). |
| <a name="opt-lbr"></a>OPT_LBR | Tipo | Atividade |
|  | Pais | [PASS1](#pass1) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[OptLBR](cpp-event-data-types/opt-lbr.md) |
|  | Descrição | Ocorre no início e na parada da otimização do vinculador da ramificação longa (/OPT: LBR). |
| <a name="opt-ref"></a>OPT_REF | Tipo | Atividade |
|  | Pais | [PASS1](#pass1) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[OptRef](cpp-event-data-types/opt-ref.md) |
|  | Descrição | Ocorre no início e na parada da otimização do vinculador de funções não referenciadas e de eliminação de dados (/OPT: REF). |
| <a name="pass1"></a>PASS1 | Tipo | Atividade |
|  | Pais | [VINCULADOR](#linker) |
|  | Children | [LTCG](#ltcg)<br/>[OPT_ICF](#opt-icf)<br/>[OPT_LBR](#opt-lbr)<br/>[OPT_REF](#opt-ref) |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[Pass1](cpp-event-data-types/pass1.md) |
|  | Descrição | Ocorre no início e na parada da passagem 1 do vinculador. |
| <a name="pass2"></a>PASS2 | Tipo | Atividade |
|  | Pais | [VINCULADOR](#linker) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[Pass2](cpp-event-data-types/pass2.md) |
|  | Descrição | Ocorre no início e na parada da passagem 2 do vinculador. |
| <a name="pre-ltcg-opt-ref"></a>PRE_LTCG_OPT_REF | Tipo | Atividade |
|  | Pais | [PASS1](#pass1) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[PreLTCGOptRef](cpp-event-data-types/pre-ltcg-opt-ref.md) |
|  | Descrição | Ocorre no início e na parada do passo de otimização do vinculador que elimina as funções e os dados não referenciados (/OPT: REF). Isso é feito antes da geração de código de tempo de vinculação. |
| <a name="symbol-name"></a>SYMBOL_NAME | Tipo | Evento Simples |
|  | Pais | [C1_DLL](#c1-dll) |
|  | Children | Nenhum |
|  | {1&gt;Propriedades&lt;1} | -Uma chave de tipo<br/> -O nome do tipo |
|  | Capturar classes | [SimpleEvent](cpp-event-data-types/simple-event.md)<br/>[Symbolname](cpp-event-data-types/symbol-name.md) |
|  | Descrição | Ocorre ao final da passagem de front-end: uma vez para cada tipo envolvido em instanciações de modelo. A chave é um identificador numérico para o tipo, enquanto o nome é sua representação de texto. As chaves de tipo são exclusivas dentro do rastreamento que está sendo analisado. No entanto, chaves diferentes provenientes de diferentes passagens de front-end do compilador podem apontar para o mesmo tipo. Comparar tipos entre diferentes passagens de front-end de compilador requer o uso de seus nomes. SYMBOL_NAME eventos são emitidos no final de uma passagem de front-end do compilador, após a ocorrência de todas as instanciações de modelo. |
| <a name="template-instantiation"></a>TEMPLATE_INSTANTIATION | Tipo | Atividade |
|  | Pais | [C1_DLL](#c1-dll)<br/>[FRONT_END_FILE](#front-end-file)<br/>[TEMPLATE_INSTANTIATION](#template-instantiation) |
|  | Children | [TEMPLATE_INSTANTIATION](#template-instantiation) |
|  | {1&gt;Propriedades&lt;1} | -A chave para o tipo especializado<br/>-A chave para o tipo do modelo primário<br/>-O tipo de modelo que foi instanciado |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[TemplateInstantiation](cpp-event-data-types/template-instantiation.md) |
|  | Descrição | Ocorre no início e no final de uma instanciação de modelo. Um tipo de modelo primário (como `vector`) é instanciado, resultando em um tipo especializado (como `std::vector<int>`). Uma chave é fornecida para ambos os tipos. Use o evento [SYMBOL_NAME](#symbol-name) para converter uma chave no nome do tipo. As chaves de tipo são exclusivas dentro do rastreamento que está sendo analisado. No entanto, chaves diferentes provenientes de diferentes passagens de front-end do compilador podem apontar para o mesmo tipo. Comparar tipos entre diferentes passagens de front-end de compilador requer o uso de nomes de símbolo. Esse evento é recursivo. A recursão ocorre em alguns casos quando o front-end está instanciando modelos aninhados. |
| <a name="thread"></a>PROCESSO | Tipo | Atividade |
|  | Pais | [CODE_GENERATION](#code-generation)<br/>[TOP_DOWN](#top-down) |
|  | Children | [FUNCTION](#function) |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[Thread](cpp-event-data-types/thread.md) |
|  | Descrição | Ocorre no início e no final de uma execução de thread de back-end do compilador. Um thread que está sendo suspenso é considerado encerrado. Um thread que está sendo ativadosdo é considerado iniciado. |
| <a name="top-down"></a>TOP_DOWN | Tipo | Atividade |
|  | Pais | [WHOLE_PROGRAM_ANALYSIS](#whole-program-analysis) |
|  | Children | [FUNCTION](#function)<br/>[PROCESSO](#thread) |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[TopDown](cpp-event-data-types/top-down.md) |
|  | Descrição | Ocorre no início e na interrupção da aprovação completa da análise do programa. |
| <a name="whole-program-analysis"></a>WHOLE_PROGRAM_ANALYSIS | Tipo | Atividade |
|  | Pais | [C2_DLL](#c2-dll) |
|  | Children | [BOTTOM_UP](#bottom-up)<br/>[TOP_DOWN](#top-down) |
|  | {1&gt;Propriedades&lt;1} | Nenhum |
|  | Capturar classes | [Atividade](cpp-event-data-types/activity.md)<br/>[WholeProgramAnalysis](cpp-event-data-types/whole-program-analysis.md) |
|  | Descrição | Ocorre no início e na parada da fase de análise completa do programa da geração de código de tempo de vinculação. |

::: moniker-end
