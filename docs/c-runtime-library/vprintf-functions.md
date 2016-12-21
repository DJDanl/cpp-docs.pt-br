---
title: "Fun&#231;&#245;es vprintf | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr110.dll"
  - "msvcr120.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr80.dll"
apitype: "DLLExport"
f1_keywords: 
  - "vprintf"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "texto formatado [C++]"
  - "Função vprintf"
ms.assetid: 02ac7c51-eab1-4bf0-bf4c-77065e3fa744
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es vprintf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada uma das funções de `vprintf` usa um ponteiro para uma lista de argumentos, então em formatos e grava os dados dados para um destino específico.  As funções difere na validação de parâmetro executada, se as funções usam largura ou cadeias de caracteres de um byte, o destino de saída, e o suporte para especificar a ordem em que os parâmetros são usados na cadeia de caracteres de formato.  
  
|||  
|-|-|  
|[\_vcprintf, \_vcwprintf](../c-runtime-library/reference/vcprintf-vcprintf-l-vcwprintf-vcwprintf-l.md)|[vfprintf, vfwprintf](../c-runtime-library/reference/vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md)|  
|[\_vfprintf\_p, \_vfprintf\_p\_l, \_vfwprintf\_p, \_vfwprintf\_p\_l](../c-runtime-library/reference/vfprintf-p-vfprintf-p-l-vfwprintf-p-vfwprintf-p-l.md)|[vfprintf\_s, \_vfprintf\_s\_l, vfwprintf\_s, \_vfwprintf\_s\_l](../Topic/vfprintf_s,%20_vfprintf_s_l,%20vfwprintf_s,%20_vfwprintf_s_l.md)|  
|[vprintf, vwprintf](../c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l.md)|[\_vprintf\_p, \_vprintf\_p\_l, \_vwprintf\_p, \_vwprintf\_p\_l](../c-runtime-library/reference/vprintf-p-vprintf-p-l-vwprintf-p-vwprintf-p-l.md)|  
|[vprintf\_s, \_vprintf\_s\_l, vwprintf\_s, \_vwprintf\_s\_l](../c-runtime-library/reference/vprintf-s-vprintf-s-l-vwprintf-s-vwprintf-s-l.md)|[vsprintf, vswprintf](../c-runtime-library/reference/vsprintf-vsprintf-l-vswprintf-vswprintf-l-vswprintf-l.md)|  
|[\_vsprintf\_p, \_vsprintf\_p\_l, \_vswprintf\_p, \_vswprintf\_p\_l](../Topic/_vsprintf_p,%20_vsprintf_p_l,%20_vswprintf_p,%20_vswprintf_p_l.md)|[vsprintf\_s, \_vsprintf\_s\_l, vswprintf\_s, \_vswprintf\_s\_l](../c-runtime-library/reference/vsprintf-s-vsprintf-s-l-vswprintf-s-vswprintf-s-l.md)|  
|[\_vscprintf, \_vscprintf\_l, \_vscwprintf, \_vscwprintf\_l](../c-runtime-library/reference/vscprintf-vscprintf-l-vscwprintf-vscwprintf-l.md)|[\_vsnprintf, \_vsnwprintf](../c-runtime-library/reference/vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l.md)|  
  
## Comentários  
 As funções de `vprintf` são semelhantes às funções de contraparte como listado na tabela a seguir.  No entanto, cada função de `vprintf` aceita um ponteiro para uma lista de argumentos, enquanto cada uma das funções de contraparte aceita uma lista de argumentos.  
  
 Essas funções formatar dados para saída aos destinos da seguinte maneira.  
  
|Função|Função de contraparte|Destino de saída|Validação de parâmetro|Suporte de parâmetro posicional|  
|------------|---------------------------|----------------------|----------------------------|-------------------------------------|  
|`_vcprintf`|[\_cprintf](../c-runtime-library/reference/cprintf-cprintf-l-cwprintf-cwprintf-l.md)|console|Verificação do zero.|não|  
|`_vcwprintf`|[\_cwprintf](../c-runtime-library/reference/cprintf-cprintf-l-cwprintf-cwprintf-l.md)|console|Verificação do zero.|não|  
|`vfprintf`|[fprintf](../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)|*Fluxo*|Verificação do zero.|não|  
|**vfprintf\_p**|[fprintf\_p](../c-runtime-library/reference/fprintf-p-fprintf-p-l-fwprintf-p-fwprintf-p-l.md)|*Fluxo*|Verificação para o formato nulo e é válida.|sim|  
|`vfprintf_s`|[fprintf\_s](../c-runtime-library/reference/fprintf-s-fprintf-s-l-fwprintf-s-fwprintf-s-l.md)|*Fluxo*|Verificação para o formato nulo e é válida.|não|  
|`vfwprintf`|[fwprintf](../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)|*Fluxo*|Verificação do zero.|não|  
|**vfwprintf\_p**|[fwprintf\_p](../c-runtime-library/reference/fprintf-p-fprintf-p-l-fwprintf-p-fwprintf-p-l.md)|*Fluxo*|Verificação para o formato nulo e é válida.|sim|  
|`vfwprintf_s`|[fwprintf\_s](../c-runtime-library/reference/fprintf-s-fprintf-s-l-fwprintf-s-fwprintf-s-l.md)|*Fluxo*|Verificação para o formato nulo e é válida.|não|  
|`vprintf`|[printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)|`Stdout`|Verificação do zero.|não|  
|**vprintf\_p**|[printf\_p](../c-runtime-library/reference/printf-p-printf-p-l-wprintf-p-wprintf-p-l.md)|`Stdout`|Verificação para o formato nulo e é válida.|sim|  
|`vprintf_s`|[printf\_s](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)|`Stdout`|Verificação para o formato nulo e é válida.|não|  
|`vwprintf`|[wprintf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)|`Stdout`|Verificação do zero.|não|  
|**vwprintf\_p**|[wprintf\_p](../c-runtime-library/reference/printf-p-printf-p-l-wprintf-p-wprintf-p-l.md)|`Stdout`|Verificação para o formato nulo e é válida.|sim|  
|`vwprintf_s`|[wprintf\_s](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)|`Stdout`|Verificação para o formato nulo e é válida.|não|  
|**vsprintf**|[sprintf](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)|memória apontada pelo *buffer*|Verificação do zero.|não|  
|**vsprintf\_p**|[sprintf\_p](../c-runtime-library/reference/sprintf-p-sprintf-p-l-swprintf-p-swprintf-p-l.md)|memória apontada pelo *buffer*|Verificação para o formato nulo e é válida.|sim|  
|`vsprintf_s`|[sprintf\_s](../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md)|memória apontada pelo *buffer*|Verificação para o formato nulo e é válida.|não|  
|`vswprintf`|[swprintf](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)|memória apontada pelo *buffer*|Verificação do zero.|não|  
|**vswprintf\_p**|[swprintf\_p](../c-runtime-library/reference/sprintf-p-sprintf-p-l-swprintf-p-swprintf-p-l.md)|memória apontada pelo *buffer*|Verificação para o formato nulo e é válida.|sim|  
|`vswprintf_s`|[swprintf\_s](../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md)|memória apontada pelo *buffer*|Verificação para o formato nulo e é válida.|não|  
|`_vscprintf`|[\_vscprintf](../c-runtime-library/reference/vscprintf-vscprintf-l-vscwprintf-vscwprintf-l.md)|memória apontada pelo *buffer*|Verificação do zero.|não|  
|`_vscwprintf`|[\_vscwprintf](../c-runtime-library/reference/vscprintf-vscprintf-l-vscwprintf-vscwprintf-l.md)|memória apontada pelo *buffer*|Verificação do zero.|não|  
|`_vsnprintf`|[\_snprintf](../c-runtime-library/reference/snprintf-snprintf-snprintf-l-snwprintf-snwprintf-l.md)|memória apontada pelo *buffer*|Verificação do zero.|não|  
|`_vsnwprintf`|[\_snwprintf](../c-runtime-library/reference/snprintf-snprintf-snprintf-l-snwprintf-snwprintf-l.md)|memória apontada pelo *buffer*|Verificação do zero.|não|  
  
 O argumento de `argptr` tem o tipo `va_list`, que é definido em VARARGS.H e em. STDARG.H.  A variável de `argptr` deve ser inicializado por **va\_start,** e pode ser reinicializado por chamadas subsequentes de `va_arg` ; pontos de `argptr` no início de uma lista de argumentos que são convertidos e passados para saída de acordo com as especificações correspondentes no argumento *de formato* .  *o formato* tem o mesmo formulário e função que o argumento *de formato* para [printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md).  Nenhuma dessas funções invoca `va_end`.  Para obter uma descrição mais completo de cada função de `vprintf` , consulte a descrição de suas contrapartes funcionar como listado na tabela acima.  
  
 `_vsnprintf` difere de **vsprintf** que grava não mais do que bytes *de contagem* no *buffer*.  
  
 As versões dessas funções com o infixo de **w** no nome são versões ampla de caracteres das funções correspondentes sem o infixo de **w** ; em cada uma dessas funções ampla de caracteres, *o buffer* e *o formato* são cadeias de caracteres de ampla caractere.  Se não, cada função ampla de caracteres se comporta idêntica à função de contraparte de SBCS.  
  
 As versões dessas funções com **\_s** e sufixos do **\_p** são mais seguros versões.  Essas versões validará as cadeias de formato e gerarão uma exceção se a cadeia de caracteres de formato não é boa formada \(por exemplo, se os caracteres de formatação inválidos são usados\).  
  
 As versões dessas funções com o sufixo de **\_p** fornecem a capacidade de especificar a ordem em que os argumentos fornecidos são substituídos na cadeia de caracteres de formato.  Para obter mais informações, consulte [Parâmetros posicionais printf\_p](../c-runtime-library/printf-p-positional-parameters.md).  
  
 Para **vsprintf**, `vswprintf`, `_vsnprintf` e `_vsnwprintf`, se copiar ocorre entre as cadeias de caracteres que sobrepõem, o comportamento será indefinido.  
  
> [!IMPORTANT]
>  Verifique se *o formato* não seja uma cadeia de caracteres definida pelo usuário.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  Se usar as versões seguro dessas funções \(sufixos de **\_s** ou de **\_p** \), uma cadeia de formato fornecida pelo usuário pode disparar uma exceção inválido do parâmetro se a cadeia de caracteres fornecida por contém caracteres de formatação inválidos.  
  
## Consulte também  
 [E\/S de fluxo](../c-runtime-library/stream-i-o.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [va\_arg, va\_copy, va\_end, va\_start](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)