---
title: 'C++ Build Insights SDK: tabela de eventos'
description: Referência de eventos para o Visual Studio C++ Build Insights SDK
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Events
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 932b78347e05d313e7962da2fdff8c3454dec963
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324127"
---
# <a name="c-build-insights-sdk-event-table"></a>C++ Build Insights SDK: tabela de eventos

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

## <a name="compiler-events"></a>Eventos de compilador

[Compilador](#compiler)\
[COMMAND_LINE](#command-line)\
[ENVIRONMENT_VARIABLE](#environment-variable)\
[FILE_INPUT](#file-input)\
[OBJ_OUTPUT](#obj-output)\
[FRONT_END_PASS](#front-end-pass)\
[BACK_END_PASS](#back-end-pass)

## <a name="compiler-front-end-events"></a>Eventos front-end do compilador

[C1_DLL](#c1-dll)\
[FRONT_END_FILE](#front-end-file)\
[TEMPLATE_INSTANTIATION](#template-instantiation)\
[SYMBOL_NAME](#symbol-name)

## <a name="compiler-back-end-events"></a>Eventos back-end do compilador

[C2_DLL](#c2-dll)\
[WHOLE_PROGRAM_ANALYSIS](#whole-program-analysis)\
[TOP_DOWN](#top-down)\
[BOTTOM_UP](#bottom-up)\
[CODE_GENERATION](#code-generation)\
[Thread](#thread)\
[Função](#function)\
[FORCE_INLINEE](#force-inlinee)

## <a name="linker-events"></a>Eventos linker

[Vinculador](#linker)\
[COMMAND_LINE](#command-line)\
[ENVIRONMENT_VARIABLE](#environment-variable)\
[FILE_INPUT](#file-input)\
[EXECUTABLE_IMAGE_OUTPUT](#executable-image-output)\
[EXP_OUTPUT](#exp-output)\
[IMP_LIB_OUTPUT](#imp-lib-output)\
[LIB_OUTPUT](#lib-output)\
[PASSE1](#pass1)\
[PRE_LTCG_OPT_REF](#pre-ltcg-opt-ref)\
[Ltcg](#ltcg)\
[OPT_REF](#opt-ref)\
[OPT_ICF](#opt-icf)\
[OPT_LBR](#opt-lbr)\
[PASSE2](#pass2)

## <a name="event-table"></a>Tabela de eventos

| Evento | Propriedade | Descrição |
|--|--|--|
| <a name="back-end-pass"></a>BACK_END_PASS | Type | Atividade |
|  | Pais | [Compilador](#compiler) |
|  | Children | [C2_DLL](#c2-dll) |
|  | Propriedades | - Caminho absoluto para o arquivo de origem de entrada<br/>- Caminho absoluto para o arquivo objeto de saída |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[CompilerPass](cpp-event-data-types/compiler-pass.md)<br/>[BackEndPass](cpp-event-data-types/back-end-pass.md) |
|  | Descrição | Ocorre no início e parada do passe back-end do compilador. Este passe é responsável por otimizar o código-fonte C/C++ analisado e convertê-lo em código de máquina. |
| <a name="bottom-up"></a>BOTTOM_UP | Type | Atividade |
|  | Pais | [WHOLE_PROGRAM_ANALYSIS](#whole-program-analysis) |
|  | Children | Nenhum |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Bottomup](cpp-event-data-types/bottom-up.md) |
|  | Descrição | Ocorre no início e parada de toda a análise do programa passe de baixo para cima. |
| <a name="c1-dll"></a>C1_DLL | Type | Atividade |
|  | Pais | [FRONT_END_PASS](#front-end-pass) |
|  | Children | [FRONT_END_FILE](#front-end-file)<br/>[SYMBOL_NAME](#symbol-name)<br/>[TEMPLATE_INSTANTIATION](#template-instantiation) |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[C1DLL](cpp-event-data-types/c1-dll.md) |
|  | Descrição | Ocorre no início e parada de uma invocação *c1.dll* ou *c1xx.dll.* Estes DLLs são a extremidade frontal C e C++ do compilador. Eles são invocados exclusivamente pelo motorista compilador *(cl.exe*). |
| <a name="c2-dll"></a>C2_DLL | Type | Atividade |
|  | Pais | [BACK_END_PASS](#back-end-pass)<br/>[Ltcg](#ltcg) |
|  | Children | [CODE_GENERATION](#code-generation)<br/>[WHOLE_PROGRAM_ANALYSIS](#whole-program-analysis) |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[C2DLL](cpp-event-data-types/c2-dll.md) |
|  | Descrição | Ocorre no início e parada de uma invocação *c2.dll.* Este DLL é a parte de trás do compilador. É chamado pelo motorista do compilador *(cl.exe).* Ele também é invocado pelo linker *(link.exe*) quando a geração de código de tempo de link é usada. |
| <a name="code-generation"></a>CODE_GENERATION | Type | Atividade |
|  | Pais | [C2_DLL](#c2-dll) |
|  | Children | [Função](#function)<br/>[Thread](#thread) |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Codegeneration](cpp-event-data-types/code-generation.md) |
|  | Descrição | Ocorre no início e parada da fase de geração de código do back-end. |
| <a name="command-line"></a>COMMAND_LINE | Type | Evento Simples |
|  | Pais | [Compilador](#compiler)<br/>[Vinculador](#linker) |
|  | Children | Nenhum |
|  | Propriedades | - A linha de comando que foi usada para invocar *cl.exe* ou *link.exe* |
|  | Classes de captura | [Evento simples](cpp-event-data-types/simple-event.md)<br/>[Commandline](cpp-event-data-types/command-line.md) |
|  | Descrição | Ocorre quando o compilador e o linker são feitos avaliando a linha de comando. A linha de comando avaliada inclui todos os parâmetros *cl.exe* e *link.exe* aprovados através de um arquivo de resposta. Também inclui parâmetros para *cl.exe* e *link.exe* passados \_através\_de variáveis \_\_de ambiente como CL, CL, LINK e LINK . |
| <a name="compiler"></a>Compilador | Type | Atividade |
|  | Pais | Nenhum |
|  | Children | [BACK_END_PASS](#back-end-pass)<br/>[COMMAND_LINE](#command-line)<br/>[ENVIRONMENT_VARIABLE](#environment-variable)<br/>[FILE_INPUT](#file-input)<br/>[OBJ_OUTPUT](#obj-output)<br/>[FRONT_END_PASS](#front-end-pass) |
|  | Propriedades | - Versão do compilador<br/>- Diretório de trabalho<br/>- Caminho absoluto para o *invocado cl.exe* |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Invocação](cpp-event-data-types/invocation.md)<br/>[Compilador](cpp-event-data-types/compiler.md) |
|  | Descrição | Ocorre no início e parada de uma invocação *cl.exe.* |
| <a name="environment-variable"></a>ENVIRONMENT_VARIABLE | Type | Evento Simples |
|  | Pais | [Compilador](#compiler)<br/>[Vinculador](#linker) |
|  | Children | Nenhum |
|  | Propriedades | - O nome da variável ambiente<br/>- O valor da variável ambiente. |
|  | Classes de captura | [Evento simples](cpp-event-data-types/simple-event.md)<br/>[EnvironmentVariable](cpp-event-data-types/environment-variable.md) |
|  | Descrição | Ocorre uma vez para cada variável de ambiente existente no momento em *que cl.exe* ou *link.exe* é invocado. |
| <a name="executable-image-output"></a>EXECUTABLE_IMAGE_OUTPUT | Type | Evento Simples |
|  | Pais | [Vinculador](#linker) |
|  | Children | Nenhum |
|  | Propriedades | - O caminho absoluto para um arquivo de saída DLL ou executável. |
|  | Classes de captura | [Evento simples](cpp-event-data-types/simple-event.md)<br/>[Saída de arquivos](cpp-event-data-types/file-output.md)<br/>[ExecutávelImageOutput](cpp-event-data-types/executable-image-output.md) |
|  | Descrição | Ocorre quando uma das entradas do linker é um DLL ou um arquivo de imagem executável. |
| <a name="exp-output"></a>EXP_OUTPUT | Type | Evento Simples |
|  | Pais | [Vinculador](#linker) |
|  | Children | Nenhum |
|  | Propriedades | - O caminho absoluto para um arquivo de saída *.exp.* |
|  | Classes de captura | [Evento simples](cpp-event-data-types/simple-event.md)<br/>[Saída de arquivos](cpp-event-data-types/file-output.md)<br/>[ExpOutput](cpp-event-data-types/exp-output.md) |
|  | Descrição | Ocorre quando uma das saídas do linker é um arquivo *.exp.* |
| <a name="file-input"></a>FILE_INPUT | Type | Evento Simples |
|  | Pais | [Compilador](#compiler)<br/>[Vinculador](#linker) |
|  | Children | Nenhum |
|  | Propriedades | - O caminho absoluto para o arquivo de entrada<br/>- O tipo de arquivo de entrada |
|  | Classes de captura | [Evento simples](cpp-event-data-types/simple-event.md)<br/>[Entrada de arquivos](cpp-event-data-types/file-input.md) |
|  | Descrição | Ocorre para anunciar uma *entrada cl.exe* ou *link.exe.* |
| <a name="force-inlinee"></a>FORCE_INLINEE | Type | Evento Simples |
|  | Pais | [Função](#function) |
|  | Children | Nenhum |
|  | Propriedades | - O nome da função forrada.<br/>- O tamanho da função forrada, representada como uma contagem intermediária de instruções. |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[ForceInlinee](cpp-event-data-types/force-inlinee.md) |
|  | Descrição | Ocorre quando uma função está sendo forrada em `__forceinline` outra função através do uso da palavra-chave. |
| <a name="front-end-file"></a>FRONT_END_FILE | Type | Atividade |
|  | Pais | [C1_DLL](#c1-dll)<br/>[FRONT_END_FILE](#front-end-file) |
|  | Children | [FRONT_END_FILE](#front-end-file)<br/>[TEMPLATE_INSTANTIATION](#template-instantiation) |
|  | Propriedades | - Caminho absoluto para o arquivo. |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[FrontEndFile](cpp-event-data-types/front-end-file.md) |
|  | Descrição | Ocorre quando o front-end do compilador inicia e para de processar um arquivo. Este evento é recursivo. A recursão acontece quando a parte frontal está análisendo arquivos incluídos. |
| <a name="front-end-pass"></a>FRONT_END_PASS | Type | Atividade |
|  | Pais | [Compilador](#compiler) |
|  | Children | [C1_DLL](#c1-dll) |
|  | Propriedades | - Caminho absoluto para o arquivo de origem de entrada<br/>- Caminho absoluto para o arquivo objeto de saída |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[CompilerPass](cpp-event-data-types/compiler-pass.md)<br/>[FrontendPass](cpp-event-data-types/front-end-pass.md) |
|  | Descrição | Ocorre no início e parada do passe front-end do compilador. Este passe é responsável por analisar o código fonte C/C++ e convertê-lo em linguagem intermediária. |
| <a name="function"></a>Função | Type | Atividade |
|  | Pais | [CODE_GENERATION](#code-generation)<br/>[Thread](#thread)<br/>[TOP_DOWN](#top-down) |
|  | Children | [FORCE_INLINEE](#force-inlinee) |
|  | Propriedades | - Nome da função |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Função](cpp-event-data-types/function.md) |
|  | Descrição | Ocorre ao iniciar e terminar gerando o código para uma função. |
| <a name="imp-lib-output"></a>IMP_LIB_OUTPUT | Type | Evento Simples |
|  | Pais | [Vinculador](#linker) |
|  | Children | Nenhum |
|  | Propriedades | - O caminho absoluto para um arquivo de saída de biblioteca de importação. |
|  | Classes de captura | [Evento simples](cpp-event-data-types/simple-event.md)<br/>[Saída de arquivos](cpp-event-data-types/file-output.md)<br/>[Saída implib](cpp-event-data-types/imp-lib-output.md) |
|  | Descrição | Ocorre quando uma das saídas do linker é uma biblioteca de importação. |
| <a name="lib-output"></a>LIB_OUTPUT | Type | Evento Simples |
|  | Pais | [Vinculador](#linker) |
|  | Children | Nenhum |
|  | Propriedades | - O caminho absoluto para um arquivo de saída de biblioteca estática. |
|  | Classes de captura | [Evento simples](cpp-event-data-types/simple-event.md)<br/>[Saída de arquivos](cpp-event-data-types/file-output.md)<br/>[LibOutput](cpp-event-data-types/lib-output.md) |
|  | Descrição | Ocorre quando uma das saídas do linker é biblioteca estática. |
| <a name="linker"></a>Vinculador | Type | Atividade |
|  | Pais | Nenhum |
|  | Children | [COMMAND_LINE](#command-line)<br/>[ENVIRONMENT_VARIABLE](#environment-variable)<br/>[EXECUTABLE_IMAGE_OUTPUT](#executable-image-output)<br/>[EXP_OUTPUT](#exp-output)<br/>[FILE_INPUT](#file-input)<br/>[IMP_LIB_OUTPUT](#imp-lib-output)<br/>[LIB_OUTPUT](#lib-output)<br/>[PASSE1](#pass1)<br/>[PASSE2](#pass2) |
|  | Propriedades | - Versão linker<br/>- Diretório de trabalho<br/>- Caminho absoluto para o *link invocado.exe* |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Invocação](cpp-event-data-types/invocation.md)<br/>[Vinculador](cpp-event-data-types/linker.md) |
|  | Descrição | Ocorre no início e parada de uma invocação *link.exe.* |
| <a name="ltcg"></a>Ltcg | Type | Atividade |
|  | Pais | [PASSE1](#pass1) |
|  | Children | [C2_DLL](#c2-dll) |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Ltcg](cpp-event-data-types/ltcg.md) |
|  | Descrição | Ocorre no início e parada da geração de código de tempo de link. |
| <a name="obj-output"></a>OBJ_OUTPUT | Type | Evento Simples |
|  | Pais | [Compilador](#compiler) |
|  | Children | Nenhum |
|  | Propriedades | - O caminho absoluto para o arquivo de saída *.obj* |
|  | Classes de captura | [Evento simples](cpp-event-data-types/simple-event.md)<br/>[Saída de arquivos](cpp-event-data-types/file-output.md)<br/>[ObjOutput](cpp-event-data-types/obj-output.md) |
|  | Descrição | Ocorre uma vez para cada *.obj* produzido por *cl.exe*. |
| <a name="opt-icf"></a>OPT_ICF | Type | Atividade |
|  | Pais | [PASSE1](#pass1) |
|  | Children | Nenhum |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[OptICF](cpp-event-data-types/opt-icf.md) |
|  | Descrição | Ocorre no início e parada da otimização do linkde comda COMDAT idêntica (/OPT:ICF). |
| <a name="opt-lbr"></a>OPT_LBR | Type | Atividade |
|  | Pais | [PASSE1](#pass1) |
|  | Children | Nenhum |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[OptLBR](cpp-event-data-types/opt-lbr.md) |
|  | Descrição | Ocorre no início e parada da otimização do linker do ramo longo (/OPT:LBR). |
| <a name="opt-ref"></a>OPT_REF | Type | Atividade |
|  | Pais | [PASSE1](#pass1) |
|  | Children | Nenhum |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[OptRef](cpp-event-data-types/opt-ref.md) |
|  | Descrição | Ocorre no início e parada das funções não referenciadas e otimização do linker de eliminação de dados (/OPT:REF). |
| <a name="pass1"></a>PASSE1 | Type | Atividade |
|  | Pais | [Vinculador](#linker) |
|  | Children | [Ltcg](#ltcg)<br/>[OPT_ICF](#opt-icf)<br/>[OPT_LBR](#opt-lbr)<br/>[OPT_REF](#opt-ref) |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Passe1](cpp-event-data-types/pass1.md) |
|  | Descrição | Ocorre no início e parada do passe 1 do linker. |
| <a name="pass2"></a>PASSE2 | Type | Atividade |
|  | Pais | [Vinculador](#linker) |
|  | Children | Nenhum |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Passe2](cpp-event-data-types/pass2.md) |
|  | Descrição | Ocorre no início e parada do passe 2 do linker. |
| <a name="pre-ltcg-opt-ref"></a>PRE_LTCG_OPT_REF | Type | Atividade |
|  | Pais | [PASSE1](#pass1) |
|  | Children | Nenhum |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[PreLTCGOptRef](cpp-event-data-types/pre-ltcg-opt-ref.md) |
|  | Descrição | Ocorre no início e parada do passe de otimização do linker que elimina funções e dados não referenciados (/OPT:REF). É feito antes da geração de código de tempo de link. |
| <a name="symbol-name"></a>SYMBOL_NAME | Type | Evento Simples |
|  | Pais | [C1_DLL](#c1-dll) |
|  | Children | Nenhum |
|  | Propriedades | - Uma chave de tipo<br/> - O nome do tipo |
|  | Classes de captura | [Evento simples](cpp-event-data-types/simple-event.md)<br/>[Nome do Símbolo](cpp-event-data-types/symbol-name.md) |
|  | Descrição | Ocorre no final do passe front-end: uma vez para cada tipo envolvido em instanciações de modelo. A chave é um identificador numérico para o tipo, enquanto o nome é sua representação de texto. As teclas de tipo são únicas dentro do traço que está sendo analisado. No entanto, diferentes teclas provenientes de passes front-end de compilador diferentes podem apontar para o mesmo tipo. Comparar tipos entre diferentes passes front-end do compilador requer o uso de seus nomes. SYMBOL_NAME eventos são emitidos no final de um passe front-end do compilador, depois de todas as instanciações do modelo terem ocorrido. |
| <a name="template-instantiation"></a>TEMPLATE_INSTANTIATION | Type | Atividade |
|  | Pais | [C1_DLL](#c1-dll)<br/>[FRONT_END_FILE](#front-end-file)<br/>[TEMPLATE_INSTANTIATION](#template-instantiation) |
|  | Children | [TEMPLATE_INSTANTIATION](#template-instantiation) |
|  | Propriedades | - A chave para o tipo especializado<br/>- A chave para o tipo do modelo principal<br/>- O tipo de modelo que foi instanciado |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Instantiação do modelo](cpp-event-data-types/template-instantiation.md) |
|  | Descrição | Ocorre no início e no final de uma instanciação de modelo. Um tipo de modelo `vector`primário (como ) é instanciado, resultando em um tipo especializado (como `std::vector<int>`). Uma chave é dada para ambos os tipos. Use o evento [SYMBOL_NAME](#symbol-name) para converter uma chave no nome do tipo. As teclas de tipo são únicas dentro do traço que está sendo analisado. No entanto, diferentes teclas provenientes de passes front-end de compilador diferentes podem apontar para o mesmo tipo. Comparar tipos entre diferentes passes front-end do compilador requer o uso de nomes de símbolos. Este evento é recursivo. A recursão acontece em alguns casos quando a parte frontal está instanciando modelos aninhados. |
| <a name="thread"></a>Thread | Type | Atividade |
|  | Pais | [CODE_GENERATION](#code-generation)<br/>[TOP_DOWN](#top-down) |
|  | Children | [Função](#function) |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Thread](cpp-event-data-types/thread.md) |
|  | Descrição | Ocorre no início e no final da execução do segmento back-end do compilador. Um fio suspenso é considerado encerrado. Um fio sendo acordado é considerado iniciado. |
| <a name="top-down"></a>TOP_DOWN | Type | Atividade |
|  | Pais | [WHOLE_PROGRAM_ANALYSIS](#whole-program-analysis) |
|  | Children | [Função](#function)<br/>[Thread](#thread) |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Topdown](cpp-event-data-types/top-down.md) |
|  | Descrição | Ocorre no início e parada de todo o passe de cima para baixo da análise do programa. |
| <a name="whole-program-analysis"></a>WHOLE_PROGRAM_ANALYSIS | Type | Atividade |
|  | Pais | [C2_DLL](#c2-dll) |
|  | Children | [BOTTOM_UP](#bottom-up)<br/>[TOP_DOWN](#top-down) |
|  | Propriedades | Nenhum |
|  | Classes de captura | [Atividade](cpp-event-data-types/activity.md)<br/>[Análise de Programas Inteiros](cpp-event-data-types/whole-program-analysis.md) |
|  | Descrição | Ocorre no início e parada da fase de análise de todo o programa da geração de código de tempo de link. |

::: moniker-end
