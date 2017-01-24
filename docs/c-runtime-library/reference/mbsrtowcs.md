---
title: "mbsrtowcs | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "mbsrtowcs"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-convert-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "mbsrtowcs"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função mbsrtowcs"
ms.assetid: f3a29de8-e36e-425b-a7fa-a258e6d7909d
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# mbsrtowcs
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte uma cadeia de caracteres multibyte na localidade atual para uma cadeia de caracteres largos correspondente, com a capacidade de reinicialização no meio de um caractere multibyte.  Uma versão mais segura dessa função está disponível. consulte [mbsrtowcs\_s](../../c-runtime-library/reference/mbsrtowcs-s.md).  
  
## Sintaxe  
  
```  
size_t mbsrtowcs(  
   wchar_t *wcstr,  
   const char **mbstr,  
   sizeof count,  
   mbstate_t *mbstate  
);  
template <size_t size>  
size_t mbsrtowcs(  
   wchar_t (&wcstr)[size],  
   const char **mbstr,  
   sizeof count,  
   mbstate_t *mbstate  
); // C++ only  
```  
  
#### Parâmetros  
 \[out\] `wcstr`  
 Endereço para armazenar a cadeia de caracteres largos convertido resultante.  
  
 \[in, out\] `mbstr`  
 Ponteiro indireto para o local da cadeia de caracteres multibyte para converter.  
  
 \[in\] `count`  
 O número máximo de caracteres \(não em bytes\) para converter e armazenar em `wcstr`.  
  
 \[in, out\] `mbstate`  
 Um ponteiro para um `mbstate_t` objeto de estado de conversão.  Se esse valor for um ponteiro nulo, um objeto de estado de conversão interna estático é usado.  Porque o interno `mbstate_t` objeto não é thread\-safe, recomendamos que você sempre passa seu próprio `mbstate` parâmetro.  
  
## Valor de retorno  
 Retorna o número de caracteres convertida com êxito, não incluindo o caractere de terminação nula, se houver.  Retorna \(size\_t\)\(\-1\) se ocorreu um erro e define `errno` para EILSEQ.  
  
## Comentários  
 O `mbsrtowcs` função converte uma cadeia de caracteres multibyte indiretamente apontada por `mbstr`, em caracteres largos armazenados no buffer apontado por `wcstr`, usando o estado de conversão contido no `mbstate`.  A conversão continua para cada caractere até encontrar qualquer uma terminação nula caracteres multibyte, uma seqüência multibyte não corresponde a um caractere válido na localidade atual for encontrada, ou até `count` caracteres tiverem sido convertidos.  Se `mbsrtowcs` encontra o caractere nulo multibyte \('\\0'\) antes ou quando `count` ocorre, ele converte em um caractere nulo de terminação 16 bits e pára.  
  
 Assim, a cadeia de caracteres largos em `wcstr` é terminada em nulo apenas se `mbsrtowcs` encontra um multibyte caractere nulo durante a conversão.  Se as sequências apontada por `mbstr` e `wcstr` se sobrepõem, o comportamento de `mbsrtowcs` é indefinido.  `mbsrtowcs` é afetado pela categoria LC\_TYPE da localidade atual.  
  
 O `mbsrtowcs` função difere da [mbstowcs, \_mbstowcs\_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md) por sua capacidade de reinicialização.  O estado de conversão é armazenado em `mbstate` para chamadas subseqüentes para o mesmo ou outras funções reinicializáveis.  Resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciável.  Por exemplo, um aplicativo deve usar `mbsrlen` em vez de `mbslen`, se uma chamada subsequente `mbsrtowcs` é usado em vez de `mbstowcs.`  
  
 Se `wcstr` não é um ponteiro nulo, o objeto de ponteiro apontado por `mbstr` é atribuído um ponteiro nulo se a conversão foi interrompida porque foi atingido um caractere nulo de terminação.  Caso contrário, ela é atribuída passado simplesmente endereço do último caractere multibyte convertido, se houver.  Isso permite que uma chamada de função subsequentes reiniciar a conversão em que essa chamada é interrompido.  
  
 Se o `wcstr` argumento é um ponteiro nulo, o `count` argumento é ignorado e `mbsrtowcs` retorna o tamanho necessário em caracteres largos para a cadeia de caracteres de destino.  Se `mbstate` for um ponteiro nulo, a função usa um estático thread safe interno `mbstate_t` objeto de estado de conversão.  Se a seqüência de caracteres `mbstr` não tem um multibyte correspondente a representação de caracteres, \-1 será retornado e a `errno` é definido como `EILSEQ`.  
  
 Se `mbstr` isa ponteiro nulo, o manipulador de parâmetro inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função define `errno` para `EINVAL` e retorna \-1.  
  
 Em C\+\+, essa função tem uma sobrecarga de modelo que invoca a contrapartida mais recente e segura dessa função.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Exceções  
 O `mbsrtowcs` função é safe multithread desde que nenhuma função no thread atual chama `setlocale` desde que essa função está em execução e o `mbstate` argumento não é um ponteiro nulo.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`mbsrtowcs`|\< WCHAR. h \>|  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [mbrtowc](../../c-runtime-library/reference/mbrtowc.md)   
 [mbtowc, \_mbtowc\_l](../Topic/mbtowc,%20_mbtowc_l.md)   
 [mbstowcs, \_mbstowcs\_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)