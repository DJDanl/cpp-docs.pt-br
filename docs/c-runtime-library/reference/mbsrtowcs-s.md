---
title: "mbsrtowcs_s | Microsoft Docs"
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
  - "mbsrtowcs_s"
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
  - "mbsrtowcs_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função mbsrtowcs_s"
ms.assetid: 4ee084ec-b15d-4e5a-921d-6584ec3b5a60
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# mbsrtowcs_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converta uma cadeia de caracteres multibyte na localidade atual em sua representação de cadeia de caracteres de caractere largo.  Uma versão do [mbsrtowcs](../../c-runtime-library/reference/mbsrtowcs.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t mbsrtowcs_s(  
   size_t * pReturnValue,  
   wchar_t * wcstr,  
   size_t sizeInWords,  
   const char ** mbstr,  
   size_t count,  
   mbstate_t * mbstate  
);  
template <size_t size>  
errno_t mbsrtowcs_s(  
   size_t * pReturnValue,  
   wchar_t (&wcstr)[size],  
   const char ** mbstr,  
   size_t count,  
   mbstate_t * mbstate  
); // C++ only  
```  
  
#### Parâmetros  
 \[out\] `pReturnValue`  
 O número de caracteres convertida.  
  
 \[out\] `wcstr`  
 Endereço do buffer para armazenar resultante convertidos de cadeia de caracteres largos.  
  
 \[out\] `sizeInWords`  
 O tamanho do `wcstr` em palavras \(caracteres largos\).  
  
 \[in, out\] `mbstr`  
 Ponteiro indireto para o local da cadeia de caracteres multibyte a ser convertido.  
  
 \[in\] `count`  
 O número máximo de caracteres largos para armazenar no `wcstr` buffer, não incluindo a terminação nula, ou [\_TRUNCATE](../../c-runtime-library/truncate.md).  
  
 \[in, out\] `mbstate`  
 Um ponteiro para um `mbstate_t` objeto de estado de conversão.  Se esse valor for um ponteiro nulo, um objeto de estado de conversão interna estático é usado.  Porque o interno `mbstate_t` objeto não é thread\-safe, recomendamos que você sempre passa seu próprio `mbstate` parâmetro.  
  
## Valor de retorno  
 Zero se a conversão for bem\-sucedida, ou um código de erro em caso de falha.  
  
|Condição de erro|Valor de retorno e `errno`|  
|----------------------|--------------------------------|  
|`wcstr` é um ponteiro nulo e `sizeInWords` \> 0|`EINVAL`|  
|`mbstr` é um ponteiro nulo|`EINVAL`|  
|A cadeia de caracteres indiretamente apontado pela `mbstr` contém uma seqüência multibyte não é válida para a localidade atual.|`EILSEQ`|  
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida \(a menos que `count` é `_TRUNCATE`; para obter mais informações, consulte comentários\)|`ERANGE`|  
  
 Se qualquer uma destas condições ocorrer, a exceção de parâmetro inválido é invocada como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) .  Se a execução puder continuar, a função retorna um código de erro e define `errno` conforme indicado na tabela.  
  
## Comentários  
 O `mbsrtowcs_s` função converte uma cadeia de caracteres multibyte indiretamente apontado pela `mbstr` em caracteres largos armazenados no buffer apontado por `wcstr`, usando o estado de conversão contido no `mbstate`.  A conversão continuará para cada caractere até que uma destas condições for atendida:  
  
-   Um multibyte caractere nulo é encontrado  
  
-   Um caractere multibyte inválido for encontrado  
  
-   O número de caracteres largos armazenados no `wcstr` buffer é igual a `count`.  
  
 A cadeia de caracteres de destino `wcstr` sempre é terminada em nulo, mesmo no caso de um erro, a menos que `wcstr` é um ponteiro nulo.  
  
 Se `count` é o valor especial [\_TRUNCATE](../../c-runtime-library/truncate.md), `mbsrtowcs_s` converte máximo da cadeia de caracteres como serão caber no buffer de destino, enquanto ainda deixa espaço para um terminador nulo.  
  
 Se `mbsrtowcs_s` com êxito converte a cadeia de caracteres de origem, ele coloca o tamanho em caracteres largos de cadeia de caracteres convertida e o terminador nulo em `*``pReturnValue`, fornecido `pReturnValue` não é um ponteiro nulo.  Isso ocorre mesmo que o `wcstr` argumento é um ponteiro nulo e permite determinar o tamanho do buffer necessário.  Observe que se `wcstr` é um ponteiro nulo, `count` será ignorado.  
  
 Se `wcstr` não é um ponteiro nulo, o objeto de ponteiro apontado por `mbstr` é atribuído um ponteiro nulo se a conversão foi interrompida porque foi atingido um caractere nulo de terminação.  Caso contrário, ela é atribuída passado simplesmente endereço do último caractere multibyte convertido, se houver.  Isso permite que uma chamada de função subsequentes reiniciar a conversão em que essa chamada é interrompido.  
  
 Se `mbstate` for um ponteiro nulo, a biblioteca interna `mbstate_t` objeto estático do estado de conversão é usado.  Como esse objeto estático interno não é thread\-safe, é recomendável que você passe suas próprias `mbstate` valor.  
  
 Se `mbsrtowcs_s` encontra um caractere multibyte não é válido na localidade atual, ele coloca \-1 em `*``pReturnValue`, define o buffer de destino `wcstr` para uma cadeia de caracteres vazia, conjuntos de `errno` para `EILSEQ`, e retorna `EILSEQ`.  
  
 Se as sequências apontada por `mbstr` e `wcstr` se sobrepõem, o comportamento de `mbsrtowcs_s` é indefinido.  `mbsrtowcs_s` é afetado pela categoria LC\_TYPE da localidade atual.  
  
> [!IMPORTANT]
>  Verifique se `wcstr` e `mbstr` não se sobrepõem e que `count` reflete o número de caracteres multibyte para converter corretamente.  
  
 O `mbsrtowcs_s` função difere da [mbstowcs\_s, \_mbstowcs\_s\_l](../../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md) por sua capacidade de reinicialização.  O estado de conversão é armazenado em `mbstate` para chamadas subseqüentes para o mesmo ou outras funções reinicializáveis.  Resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciável.  Por exemplo, um aplicativo deve usar `mbsrlen` em vez de `mbslen`, se uma chamada subsequente `mbsrtowcs_s` é usado em vez de `mbstowcs_s.`  
  
 Em C\+\+, usando essa função é simplificado pela sobrecargas de modelo; as sobrecargas podem inferir o comprimento do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e eles podem substituir automaticamente funções mais antigas, não segura por meio de suas contrapartes mais recentes e seguras.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
## Exceções  
 O `mbsrtowcs_s` função é safe multithread se nenhuma função nas chamadas de thread atual `setlocale` desde que essa função está em execução e o `mbstate` argumento não é um ponteiro nulo.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`mbsrtowcs_s`|\< WCHAR. h \>|  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [mbrtowc](../../c-runtime-library/reference/mbrtowc.md)   
 [mbtowc, \_mbtowc\_l](../Topic/mbtowc,%20_mbtowc_l.md)   
 [mbstowcs\_s, \_mbstowcs\_s\_l](../../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)