---
title: Rotinas de depuração | Microsoft Docs
ms.custom: ''
ms.date: 04/10/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- c.debug
dev_langs:
- C++
helpviewer_keywords:
- debugging [CRT], using macros
- macros, debugging with
- debug routines
- debug macros
- debugging [CRT], runtime routines
ms.assetid: cb4d2664-10f3-42f7-a516-595558075471
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4efef4c7dfb907120778390874a5e56222889350
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="debug-routines"></a>Rotinas de depuração

A versão de depuração da biblioteca em tempo de execução C fornece vários serviços de diagnóstico que facilitam a depuração de programas e permitem aos desenvolvedores:

- Ir diretamente para as funções em tempo de execução durante a depuração

- Resolver declarações, erros e exceções

- Rastrear alocações de heap e prevenir perdas de memória

- Relatar mensagens de depuração para o usuário

## <a name="debug-versions-of-the-c-runtime-library-routines"></a>Versões de depuração das rotinas da biblioteca em tempo de execução C

Para usar essas rotinas, o sinalizador [_DEBUG](../c-runtime-library/debug.md) deve ser definido. Todas essas rotinas não executam nenhuma ação em um build de varejo de um aplicativo. Para obter mais informações sobre como usar as novas rotinas de depuração, consulte [Técnicas de depuração do CRT](/visualstudio/debugger/crt-debugging-techniques).

|Rotina|Uso|
|-------------|---------|
|[_ASSERT](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)|Avalia uma expressão e gera um relatório de depuração quando o resultado é FALSE|
|[_ASSERTE](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)|Semelhante a **_ASSERT**, mas inclui a expressão com falha no relatório gerado|
|[_CrtCheckMemory](../c-runtime-library/reference/crtcheckmemory.md)|Confirma a integridade dos blocos de memória alocados no heap de depuração|
|[_CrtDbgBreak](../c-runtime-library/reference/crtdbgbreak.md)|Define um ponto de interrupção.|
|[_CrtDbgReport, _CrtDbgReportW](../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md)|Gera um relatório de depuração com uma mensagem do usuário e envia o relatório para três destinos possíveis|
|[_CrtDoForAllClientObjects](../c-runtime-library/reference/crtdoforallclientobjects.md)|Chamar uma função fornecida pelo aplicativo para todos os tipos **_CLIENT_BLOCK** no heap|
|[_CrtDumpMemoryLeaks](../c-runtime-library/reference/crtdumpmemoryleaks.md)|Despeja todos os blocos de memória no heap de depuração quando ocorre uma perda de memória significativa|
|[_CrtIsMemoryBlock](../c-runtime-library/reference/crtismemoryblock.md)|Verifica se um bloco de memória especificado está localizado no heap local e se ele tem um identificador de tipo de bloco de heap de depuração válido|
|[_CrtIsValidHeapPointer](../c-runtime-library/reference/crtisvalidheappointer.md)|Verifica se um ponteiro especificado está no heap local|
|[_CrtIsValidPointer](../c-runtime-library/reference/crtisvalidpointer.md)|Verifica se um intervalo de memória especificado é válido para leitura e gravação|
|[_CrtMemCheckpoint](../c-runtime-library/reference/crtmemcheckpoint.md)|Obter o estado atual do heap de depuração e o armazena em uma estrutura **_CrtMemState** fornecida pelo aplicativo|
|[_CrtMemDifference](../c-runtime-library/reference/crtmemdifference.md)|Compara dois estados de memória em busca de diferenças significativas e retorna os resultados|
|[_CrtMemDumpAllObjectsSince](../c-runtime-library/reference/crtmemdumpallobjectssince.md)|Despeja informações sobre objetos no heap desde a realização de um ponto de verificação especificado ou do início da execução do programa|
|[_CrtMemDumpStatistics](../c-runtime-library/reference/crtmemdumpstatistics.md)|Despeja as informações do cabeçalho de depuração de um estado de memória especificado em um formato legível pelo usuário|
|[_CrtReportBlockType](../c-runtime-library/reference/crtreportblocktype.md)|Retorna o tipo/subtipo do bloco associado a determinado ponteiro de bloco do heap de depuração.|
|[_CrtSetAllocHook](../c-runtime-library/reference/crtsetallochook.md)|Instala uma função de alocação definida pelo cliente vinculando-a ao processo de alocação de memória de depuração em tempo de execução C|
|[_CrtSetBreakAlloc](../c-runtime-library/reference/crtsetbreakalloc.md)|Define um ponto de interrupção em um número de ordem de alocação de objeto especificado|
|[_CrtSetDbgFlag](../c-runtime-library/reference/crtsetdbgflag.md)|Recuperar ou modificar o estado do sinalizador **_crtDbgFlag** para controlar o comportamento de alocação do gerenciador de heap de depuração|
|[_CrtSetDumpClient](../c-runtime-library/reference/crtsetdumpclient.md)|Instalar uma função definida pelo aplicativo que é chamada sempre que uma função de despejo de depuração é chamada para despejar blocos de memória do tipo **_CLIENT_BLOCK**|
|[_CrtSetReportFile](../c-runtime-library/reference/crtsetreportfile.md)|Identificar o arquivo ou o fluxo a ser usado como um destino para um tipo de relatório específico por **_CrtDbgReport**|
|[_CrtSetReportHook](../c-runtime-library/reference/crtsetreporthook.md)|Instala uma função de relatório definida pelo cliente vinculando-a ao processo de relatório de depuração em tempo de execução C|
|[_CrtSetReportHook2, _CrtSetReportHookW2](../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md)|Instala ou desinstala uma função de relatório definida pelo cliente vinculando-a ao processo de relatório de depuração em tempo de execução C.|
|[_CrtSetReportMode](../c-runtime-library/reference/crtsetreportmode.md)|Especificar os destinos gerais para um tipo de relatório específico gerado por **_CrtDbgReport**|
|[_RPT&#91;0,1,2,3,4&#93;](../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md)|Acompanhar o progresso do aplicativo gerando um relatório de depuração por meio da chamada a **_CrtDbgReport** com uma cadeia de caracteres de formato e um número variável de argumentos. Não fornece informações sobre o arquivo de origem e o número de linha.|
|[_RPTF&#91;0,1,2,3,4&#93;](../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md)|Semelhante às macros **_RPTn**, mas fornece o nome do arquivo de origem e o número de linha que deu origem à solicitação de relatório|
|[_calloc_dbg](../c-runtime-library/reference/calloc-dbg.md)|Aloca um número especificado de blocos de memória no heap com espaço adicional para um cabeçalho de depuração e buffers de substituição|
|[_expand_dbg](../c-runtime-library/reference/expand-dbg.md)|Redimensiona um bloco especificado de memória no heap pela expansão ou contração do bloco|
|[_free_dbg](../c-runtime-library/reference/free-dbg.md)|Libera um bloco de memória no heap|
|[_fullpath_dbg, _wfullpath_dbg](../c-runtime-library/reference/fullpath-dbg-wfullpath-dbg.md)|Cria um nome de caminho absoluto ou completo para o nome de caminho relativo especificado, usando [_malloc_dbg](../c-runtime-library/reference/malloc-dbg.md) para alocar memória.|[System::IO::File::Create](https://msdn.microsoft.com/en-us/library/system.io.file.create.aspx)|
|[_getcwd_dbg, _wgetcwd_dbg](../c-runtime-library/reference/getcwd-dbg-wgetcwd-dbg.md)|Obtém o diretório de trabalho atual, usando [_malloc_dbg](../c-runtime-library/reference/malloc-dbg.md) para alocar memória.|
|[_malloc_dbg](../c-runtime-library/reference/malloc-dbg.md)|Aloca um bloco de memória no heap com espaço adicional para um cabeçalho de depuração e buffers de substituição|
|[_msize_dbg](../c-runtime-library/reference/msize-dbg.md)|Calcula o tamanho de um bloco de memória no heap|
|[_realloc_dbg](../c-runtime-library/reference/realloc-dbg.md)|Realoca um bloco de memória especificado no heap pela movimentação e/ou pelo redimensionamento do bloco|
|[_strdup_dbg, _wcsdup_dbg](../c-runtime-library/reference/strdup-dbg-wcsdup-dbg.md)|Duplica uma cadeia de caracteres, usando [_malloc_dbg](../c-runtime-library/reference/malloc-dbg.md) para alocar memória.|
|[_tempnam_dbg, _wtempnam_dbg](../c-runtime-library/reference/tempnam-dbg-wtempnam-dbg.md)|Gera nomes que podem ser usados para criar arquivos temporários, usando [_malloc_dbg](../c-runtime-library/reference/malloc-dbg.md) para alocar memória.|

## <a name="c-runtime-routines-that-are-not-available-in-source-code-form"></a>Rotinas em tempo de execução C que não estão disponíveis na forma de código-fonte

O depurador pode ser usado para executar em etapas o código-fonte da maioria das rotinas em tempo de execução C durante o processo de depuração. No entanto, a Microsoft considera algumas tecnologias proprietárias e, portanto, não fornece o código-fonte para um subconjunto dessas rotinas. A maioria dessas rotinas pertence a grupos de tratamento de exceção ou de processamento de ponto flutuante, mas algumas outras também são incluídas. A tabela a seguir lista essas rotinas.

||||
|-|-|-|
|[acos](../c-runtime-library/reference/acos-acosf-acosl.md)|[acosh](../c-runtime-library/reference/acosh-acoshf-acoshl.md)|[asin](../c-runtime-library/reference/asin-asinf-asinl.md)|
|[asinh](../c-runtime-library/reference/asinh-asinhf-asinhl.md)|[atan, atan2](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)|[atanh](../c-runtime-library/reference/atanh-atanhf-atanhl.md)|
|[Funções Bessel](../c-runtime-library/reference/bessel-functions-j0-j1-jn-y0-y1-yn.md)|[_cabs](../c-runtime-library/reference/cabs.md)|[ceil](../c-runtime-library/reference/ceil-ceilf-ceill.md)|
|[_chgsign](../c-runtime-library/reference/chgsign-chgsignf-chgsignl.md)|[_clear87, _clearfp](../c-runtime-library/reference/clear87-clearfp.md)|[_control87, _controlfp](../c-runtime-library/reference/control87-controlfp-control87-2.md)|
|[copysign](../c-runtime-library/reference/copysign-copysignf-copysignl-copysign-copysignf-copysignl.md)|[cos](../c-runtime-library/reference/cos-cosf-cosl.md)|[cosh](../c-runtime-library/reference/cosh-coshf-coshl.md)|
|[Exp](../c-runtime-library/reference/exp-expf.md)|[fabs](../c-runtime-library/reference/fabs-fabsf-fabsl.md)|[_finite](../c-runtime-library/reference/finite-finitef.md)|
|[floor](../c-runtime-library/reference/floor-floorf-floorl.md)|[fmod](../c-runtime-library/reference/fmod-fmodf.md)|[_fpclass](../c-runtime-library/reference/fpclass-fpclassf.md)|
|[_fpieee_flt](../c-runtime-library/reference/fpieee-flt.md)|[_fpreset](../c-runtime-library/reference/fpreset.md)|[frexp](../c-runtime-library/reference/frexp.md)|
|[_hypot](../c-runtime-library/reference/hypot-hypotf-hypotl-hypot-hypotf-hypotl.md)|[_isnan](../c-runtime-library/reference/isnan-isnan-isnanf.md)|[ldexp](../c-runtime-library/reference/ldexp.md)|
|[log](../c-runtime-library/reference/log-logf-log10-log10f.md)|[_logb](../c-runtime-library/reference/logb-logbf-logbl-logb-logbf.md)|[log10](../c-runtime-library/reference/log-logf-log10-log10f.md)|
|[longjmp](../c-runtime-library/reference/longjmp.md)|[_matherr](../c-runtime-library/reference/matherr.md)|[modf](../c-runtime-library/reference/modf-modff-modfl.md)|
|[_nextafter](../c-runtime-library/reference/nextafter-functions.md)|[pow](../c-runtime-library/reference/pow-powf-powl.md)|[printf_s](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)|
|[printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)|[_scalb](../c-runtime-library/reference/scalb.md)|[scanf_s](../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)|
|[scanf](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)|[setjmp](../c-runtime-library/reference/setjmp.md)|[sin](../c-runtime-library/reference/sin-sinf-sinl.md)|
|[sinh](../c-runtime-library/reference/sinh-sinhf-sinhl.md)|[sqrt](../c-runtime-library/reference/sqrt-sqrtf-sqrtl.md)|[_status87, _statusfp](../c-runtime-library/reference/status87-statusfp-statusfp2.md)|
|[tan](../c-runtime-library/reference/tan-tanf-tanl.md)|[tanh](../c-runtime-library/reference/tanh-tanhf-tanhl.md)||

Embora o código-fonte esteja disponível para a maior parte das rotinas **printf** e **scanf**, ele faz uma chamada interna a outra rotina para a qual o código-fonte não é fornecido.

## <a name="routines-that-behave-differently-in-a-debug-build-of-an-application"></a>Rotinas que se comportam de maneira diferente em um build de depuração de um aplicativo

Algumas funções em tempo de execução C e alguns operadores do C++ se comportam de maneira diferente quando chamados por meio de um build de depuração de um aplicativo. (Observe que é possível fazer um build de depuração de um aplicativo definindo o sinalizador `_DEBUG` ou vinculando a uma versão de depuração da biblioteca em tempo de execução C.) Geralmente, as diferenças de comportamento consistem em recursos extras ou informações fornecidas pela rotina para dar suporte ao processo de depuração. A tabela a seguir lista essas rotinas.

|||
|-|-|
|Rotina [abort](../c-runtime-library/reference/abort.md) do C|Operador [delete](../cpp/delete-operator-cpp.md) do C++|
|Rotina [assert](../c-runtime-library/reference/assert-macro-assert-wassert.md) do C|Operador [new](../cpp/new-operator-cpp.md) do C++|

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
[Verificação de erros em tempo de execução](../c-runtime-library/run-time-error-checking.md)<br/>
