---
title: "Rotinas de depura&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.debug"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "depuração [CRT], usando macros"
  - "macros de depuração com"
  - "rotinas de depuração"
  - "macros de depuração"
  - "depuração [CRT], rotinas de tempo de execução"
ms.assetid: cb4d2664-10f3-42f7-a516-595558075471
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Rotinas de depura&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A versão de depuração da biblioteca de tempo de execução C fornece muitos serviços de diagnóstico que facilitam programas de depuração e permitem aos desenvolvedores:  
  
-   A etapa diretamente em tempo de execução durante a depuração funciona  
  
-   Asserções, erros e exceções de resolução  
  
-   Rastrear alocações do heap e evitar possíveis vazamentos de memória  
  
-   Informar mensagens de depuração para o usuário  
  
 Para usar essas rotinas, o sinalizador de [\_DEBUG](../Topic/_DEBUG.md) deve ser definido.  Todas essas rotinas não faz nada em uma compilação de varejo de um aplicativo.  Para obter mais informações sobre como usar as novas rotinas de depuração, consulte [Técnicas de depuração do CRT](../Topic/CRT%20Debugging%20Techniques.md).  
  
### Depurar versões das rotinas de biblioteca de tempo de execução C  
  
|Rotina|Uso|Equivalente a .NET Framework|  
|------------|---------|----------------------------------|  
|[\_ASSERT](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md)|Avalia uma expressão e gerencia um relatório de depuração quando o resultado será FALSE|[\<caps:sentence id\="tgt15" sentenceid\="14fd9bf776829d73028df00162f7533f" class\="tgtSentence"\>System::Diagnostics::Debug::Assert\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.assert.aspx)|  
|[\_ASSERTE](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md)|Semelhante a `_ASSERT`, mas inclui a expressão no relatório gerado com falha|[\<caps:sentence id\="tgt18" sentenceid\="14fd9bf776829d73028df00162f7533f" class\="tgtSentence"\>System::Diagnostics::Debug::Assert\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.assert.aspx)|  
|[\_CrtCheckMemory](../c-runtime-library/reference/crtcheckmemory.md)|Confirme a integridade dos blocos de memória alocado no heap de depuração|[\<caps:sentence id\="tgt20" sentenceid\="e42975224af21ff11a761e6a6bdbd602" class\="tgtSentence"\>System::Diagnostics::PerformanceCounter\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.performancecounter.aspx)|  
|[\_CrtDbgBreak](../Topic/_CrtDbgBreak.md)|Define um ponto de interrupção.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtDbgReport, \_CrtDbgReportW](../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md)|Gerencia um relatório de depuração com uma mensagem do usuário e enviar o relatório três destinos possíveis|[System::Diagnostics::Debug::Write](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.write.aspx), [System::Diagnostics::Debug::Writeline](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.writeline.aspx), [System::Diagnostics::Debug::WriteIf](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.writeif.aspx), [System::Diagnostics::Debug::WriteLineIf](https://msdn.microsoft.com/en-us/library/system.diagnostics.debug.writelineif.aspx)|  
|[\_CrtDoForAllClientObjects](../c-runtime-library/reference/crtdoforallclientobjects.md)|Chamar uma função de aplicativo fornecida para todos os tipos de `_CLIENT_BLOCK` no heap|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtDumpMemoryLeaks](../c-runtime-library/reference/crtdumpmemoryleaks.md)|Despeje todos os blocos de memória heap de depuração quando um vazamento de memória significativo ocorreu|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtIsMemoryBlock](../c-runtime-library/reference/crtismemoryblock.md)|Verifique se um bloco de memória especificada está localizado no heap e local que tem um identificador em blocos de heap válido de depuração|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtIsValidHeapPointer](../c-runtime-library/reference/crtisvalidheappointer.md)|Verifica se um ponteiro especificado está no heap local|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtIsValidPointer](../c-runtime-library/reference/crtisvalidpointer.md)|Verifique se um intervalo especificado de memória é válida para ler e gravar|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtMemCheckpoint](../c-runtime-library/reference/crtmemcheckpoint.md)|Obtenha o estado atual do heap de depuração e o coloca em uma estrutura de `_CrtMemState` fornecida pelo aplicativo|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtMemDifference](../Topic/_CrtMemDifference.md)|Compara dois estados de memória para diferenças significativas e retornar os resultados|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtMemDumpAllObjectsSince](../Topic/_CrtMemDumpAllObjectsSince.md)|Despeje informações sobre objetos no heap desde que um ponto de verificação especificado foi realizado ou desde o início da execução do programa|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtMemDumpStatistics](../Topic/_CrtMemDumpStatistics.md)|Despeje informações de cabeçalho de depuração para um estado especificado da memória em um formato legível usuário|[\<caps:sentence id\="tgt64" sentenceid\="e42975224af21ff11a761e6a6bdbd602" class\="tgtSentence"\>System::Diagnostics::PerformanceCounter\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.diagnostics.performancecounter.aspx)|  
|[\_CrtReportBlockType](../Topic/_CrtReportBlockType.md)|Retorna o em blocos\/subtipo associado a um ponteiro de bloco fornecido do heap de depuração.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtSetAllocHook](../Topic/_CrtSetAllocHook.md)|Instalar uma função de alocação definida pelo cliente enganchando ao processo de alocação de memória de depuração de tempo de execução C|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtSetBreakAlloc](../c-runtime-library/reference/crtsetbreakalloc.md)|Definir um ponto de interrupção em um número da ordem especificada da alocação de objeto|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtSetDbgFlag](../c-runtime-library/reference/crtsetdbgflag.md)|Recuperar ou modificar o estado do sinalizador de `_crtDbgFlag` para controlar o comportamento de alocação do gerenciador de heap de depuração|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtSetDumpClient](../c-runtime-library/reference/crtsetdumpclient.md)|Instalar uma função definida pelo aplicativo que é chamada sempre que uma função de despejo de depuração é chamada para despejar blocos de memória do tipo de `_CLIENT_BLOCK`|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtSetReportFile](../Topic/_CrtSetReportFile.md)|Identifica o arquivo ou passe para ser usado como um destino para um tipo de relatório específico por `_CrtDbgReport`|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtSetReportHook](../c-runtime-library/reference/crtsetreporthook.md)|Instalar uma função definida pelo cliente de relatório enganchando a no processo de relatório de depuração de tempo de execução C|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtSetReportHook2, \_CrtSetReportHookW2](../c-runtime-library/reference/crtsetreporthook2-crtsetreporthookw2.md)|As instalações ou desinstala uma função definida pelo cliente de relatório enganchando a no processo de relatório de depuração de tempo de execução C.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_CrtSetReportMode](../c-runtime-library/reference/crtsetreportmode.md)|Especifique os destinos gerais para um tipo específico de relatório gerado por `_CrtDbgReport`|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[&#91;\_RPT0,1,2,3,4&#93;](../Topic/_RPT,%20_RPTF,%20_RPTW,%20_RPTFW%20Macros.md)|Controlar o progresso do aplicativo gerando um relatório de depuração `_CrtDbgReport` chamando com uma cadeia de formato e um número variável de argumentos.  Não fornece nenhum arquivo de origem e linha informações de número.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[&#91;\_RPTF0,1,2,3,4&#93;](../Topic/_RPT,%20_RPTF,%20_RPTW,%20_RPTFW%20Macros.md)|Semelhante a macros de `_RPTn` , mas fornece o nome do arquivo de origem e o número da linha em que a solicitação de relatório foi originada|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_calloc\_dbg](../c-runtime-library/reference/calloc-dbg.md)|Atribui um número especificado de blocos de memória heap com espaço adicional para um cabeçalho de depuração e substituir os buffers|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_expand\_dbg](../Topic/_expand_dbg.md)|Redimensiona um bloco de memória especificado no heap a expansão ou redução do bloco|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_free\_dbg](../c-runtime-library/reference/free-dbg.md)|Liberar um bloco de memória heap|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_fullpath\_dbg, \_wfullpath\_dbg](../c-runtime-library/reference/fullpath-dbg-wfullpath-dbg.md)|Crie um absoluta ou um nome de caminho completo para o nome do caminho relativo especificado, usando [\_malloc\_dbg](../c-runtime-library/reference/malloc-dbg.md) para alocar memória.|[\<caps:sentence id\="tgt129" sentenceid\="57f5d14fd2f1847b8e44146f72e48f72" class\="tgtSentence"\>System::IO::File::Create\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.io.file.create.aspx)|  
|[\_getcwd\_dbg, \_wgetcwd\_dbg](../c-runtime-library/reference/getcwd-dbg-wgetcwd-dbg.md)|Obter o diretório de trabalho atual, usando [\_malloc\_dbg](../c-runtime-library/reference/malloc-dbg.md) para alocar memória.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_malloc\_dbg](../c-runtime-library/reference/malloc-dbg.md)|Atribui um bloco de memória heap com espaço adicional para um cabeçalho de depuração e substituir os buffers|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_msize\_dbg](../c-runtime-library/reference/msize-dbg.md)|Calcule o tamanho de um bloco de memória heap|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_realloc\_dbg](../c-runtime-library/reference/realloc-dbg.md)|Realocar um bloco de memória especificado no heap movendo e\/ou redimensionando o bloco|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_strdup\_dbg, \_wcsdup\_dbg](../Topic/_strdup_dbg,%20_wcsdup_dbg.md)|Duplicar uma cadeia de caracteres, usando [\_malloc\_dbg](../c-runtime-library/reference/malloc-dbg.md) para alocar memória.|[\<caps:sentence id\="tgt151" sentenceid\="74a4ca1462af4bfed5950888b5c554e1" class\="tgtSentence"\>System::String::Clone\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/system.string.clone.aspx)|  
|[\_tempnam\_dbg, \_wtempnam\_dbg](../c-runtime-library/reference/tempnam-dbg-wtempnam-dbg.md)|Gerencia nomes que você pode usar para criar arquivos temporários, usando [\_malloc\_dbg](../c-runtime-library/reference/malloc-dbg.md) para alocar memória.|Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).|  
  
 As rotinas de depuração podem ser usadas para percorrer o código\-fonte para a maioria das outras rotinas de tempo de execução C durante o processo de depuração.  No entanto, O considera qualquer tecnologia ser proprietária e, consequentemente, não fornece o código\-fonte para essas rotinas.  A maioria dessas rotinas pertencem à manipulação de exceção ou grupos de ponto flutuante de processamento, mas alguns outros são incluídas também.  A tabela a seguir lista essas rotinas.  
  
### Rotinas de tempo de execução C que não estão disponíveis no formato do código\-fonte  
  
||||  
|-|-|-|  
|[acos, acosf, acosl](../c-runtime-library/reference/acos-acosf-acosl.md)|[\_fpclass](../c-runtime-library/reference/fpclass-fpclassf.md)|[\_nextafter](../c-runtime-library/reference/nextafter-functions.md)|  
|[asin](../c-runtime-library/reference/asin-asinf-asinl.md)|[\_fpieee\_flt](../c-runtime-library/reference/fpieee-flt.md)|[prisioneiro de guerra](../Topic/pow,%20powf,%20powl.md)|  
|[atan, atan2](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)|[\_fpreset](../c-runtime-library/reference/fpreset.md)|[printf, \_printf\_l, wprintf, \_wprintf\_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md), [printf\_s, \_printf\_s\_l, wprintf\_s, \_wprintf\_s\_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)\*|  
|[\_cabs](../Topic/_cabs.md)|[frexp](../c-runtime-library/reference/frexp.md)|[\_scalb](../c-runtime-library/reference/scalb.md)|  
|[ceil](../c-runtime-library/reference/ceil-ceilf-ceill.md)|[\_hypot](../c-runtime-library/reference/hypot-hypotf-hypotl-hypot-hypotf-hypotl.md)|[scanf, \_scanf\_l, wscanf, \_wscanf\_l](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md), [scanf\_s, \_scanf\_s\_l, wscanf\_s, \_wscanf\_s\_l](../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)\*|  
|[\_chgsign, \_chgsignf, \_chgsignl](../c-runtime-library/reference/chgsign-chgsignf-chgsignl.md)|[\_isnan](../c-runtime-library/reference/isnan-isnan-isnanf.md)|[setjmp](../c-runtime-library/reference/setjmp.md)|  
|[\_clear87, \_clearfp](../c-runtime-library/reference/clear87-clearfp.md)|[\_j0](../misc/bessel-functions-j0-j1-jn.md)|[sin](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)|  
|[\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md)|[\_j1](../misc/bessel-functions-j0-j1-jn.md)|[sinh](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)|  
|[copysign, copysignf, copysignl, \_copysign, \_copysignf, \_copysignl](../c-runtime-library/reference/copysign-copysignf-copysignl-copysign-copysignf-copysignl.md)|[\_jn](../misc/bessel-functions-j0-j1-jn.md)|[SQRT](../c-runtime-library/reference/sqrt-sqrtf-sqrtl.md)|  
|[cos](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)|[ldexp](../c-runtime-library/reference/ldexp.md)|[\_status87, \_statusfp](../c-runtime-library/reference/status87-statusfp-statusfp2.md)|  
|[moca](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)|[log](../Topic/log,%20logf,%20log10,%20log10f.md)|[tan](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)|  
|[EXP](../c-runtime-library/reference/exp-expf.md)|[log10](../Topic/log,%20logf,%20log10,%20log10f.md)|[tanh](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)|  
|[fabs](../c-runtime-library/reference/fabs-fabsf-fabsl.md)|[\_logb](../c-runtime-library/reference/logb-logbf-logbl-logb-logbf.md)|[\_y0](../Topic/Bessel%20Functions:%20_y0,%20_y1,%20_yn.md)|  
|[\_finite](../c-runtime-library/reference/finite-finitef.md)|[longjmp](../c-runtime-library/reference/longjmp.md)|[\_y1](../Topic/Bessel%20Functions:%20_y0,%20_y1,%20_yn.md)|  
|[floor](../c-runtime-library/reference/floor-floorf-floorl.md)|[\_matherr](../c-runtime-library/reference/matherr.md)|[\_yn](../Topic/Bessel%20Functions:%20_y0,%20_y1,%20_yn.md)|  
|[fmod](../Topic/fmod,%20fmodf.md)|[modf](../c-runtime-library/reference/modf-modff-modfl.md)||  
  
 \* Embora o código\-fonte está disponível para a maioria dessas rotina, faz uma chamada interno a outra rotina para a qual o código\-fonte não é fornecido.  
  
 Algumas funções de tempo de execução C e os operadores C\+\+ se comportam de maneira diferente quando chamado de uma construção de depuração de um aplicativo. \(Observe que uma compilação de depuração de um aplicativo pode ser feita definir o sinalizador de `_DEBUG` ou vinculando\-os com uma versão de depuração da biblioteca de tempo de execução C\). As diferenças de comportamento geralmente consistem em recursos adicionais ou nas informações fornecidas por rotina para dar suporte ao processo de depuração.  A tabela a seguir lista essas rotinas.  
  
### Rotinas que se comportam diferentemente em uma compilação de depuração de um aplicativo  
  
|||  
|-|-|  
|Rotina de 2.0 [anular](../c-runtime-library/reference/abort.md) C|Operador de [excluir](../cpp/delete-operator-cpp.md) C\+\+|  
|Rotina de 2.0 [assert](../c-runtime-library/reference/assert-macro-assert-wassert.md) C|Operador de [novo](../cpp/new-operator-cpp.md) C\+\+|  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)   
 [Verificação de erros de tempo de execução](../Topic/Run-Time%20Error%20Checking.md)