---
title: "_mbccpy_s, _mbccpy_s_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_mbccpy_s"
  - "_mbccpy_s_l"
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
  - "api-ms-win-crt-multibyte-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_mbccpy_s_l"
  - "mbccpy_s_l"
  - "mbccpy_s"
  - "_mbccpy_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbccpy_s"
  - "Função _mbccpy_s_l"
  - "Função _tccpy_s"
  - "Função _tccpy_s_l"
  - "Função mbccpy_s"
  - "Função mbccpy_s_l"
  - "Função tccpy_s"
  - "Função tccpy_s_l"
ms.assetid: b6e965fa-53c1-4ec3-85ef-a1c4b4f2b2da
caps.latest.revision: 30
caps.handback.revision: 30
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbccpy_s, _mbccpy_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Copia um caractere de multibyte de uma cadeia de caracteres para outra cadeia de caracteres.  Essas versões de [\_mbccpy, \_mbccpy\_l](../Topic/_mbccpy,%20_mbccpy_l.md) têm aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
errno_t _mbccpy_s(  
   unsigned char *dest,  
   size_t buffSizeInBytes,  
   int * pCopied,  
   const unsigned char *src   
);  
errno_t _mbccpy_s_l(  
   unsigned char *dest,  
   size_t buffSizeInBytes,  
   int * pCopied,  
   const unsigned char *src,  
   locale_t locale  
);  
template <size_t size>  
errno_t _mbccpy_s(  
   unsigned char (&dest)[size],  
   int * pCopied,  
   const unsigned char *src   
); // C++ only  
template <size_t size>  
errno_t _mbccpy_s_l(  
   unsigned char (&dest)[size],  
   int * pCopied,  
   const unsigned char *src,  
   locale_t locale  
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `dest`  
 Destino de impressão.  
  
 \[entrada\] `buffSizeInBytes`  
 Tamanho do buffer de destino.  
  
 \[saída\] `pCopied`  
 Preenchido com o número de bytes copiados \(1 ou 2 se bem\-sucedido\).  Passe `NULL` se o número for indiferente para você.  
  
 \[entrada\] `src`  
 Caractere de multibyte a ser copiado.  
  
 \[entrada\] `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Zero se tiver êxito; um código de erro em falha.  Se `src` ou `dest` for `NULL`, ou se mais que `buffSizeinBytes` bytes forem copiados para `dest`, o manipulador de parâmetro inválido será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, as funções retornarão `EINVAL` e `errno` será definido como `EINVAL`.  
  
## Comentários  
 A função de `_mbccpy_s` copia um caractere de multibyte de `src` para `dest`.  Se `src` não apontar para o byte inicial de um caractere de multibyte conforme determinado por uma chamada implícita a [\_ismbblead](../../c-runtime-library/reference/ismbblead-ismbblead-l.md), o byte único para o qual `src` aponta é copiado.  Se `src` apontar para um byte inicial, mas o byte seguinte for 0 e, portanto, inválido, então 0 é copiado para `dest`, `errno` é definido como `EILSEQ`, e a função retorna `EILSEQ`.  
  
 `_mbccpy_s` não acrescente um terminador nulo; no entanto, se `src` apontar para um caractere nulo, esse nulo será copiado em `dest` \(esta é apenas uma cópia de byte único normal\).  
  
 O valor em `pCopied` é preenchido com o número de bytes copiados.  Os valores possíveis são 1 e 2 se a operação for bem\-sucedida.  Se `NULL` for passado, este parâmetro será ignorado.  
  
|`src`|copiado para `dest`|`pCopied`|Valor de retorno|  
|-----------|-------------------------|---------------|----------------------|  
|sem byte inicial|sem byte inicial|1|0|  
|0|0|1|0|  
|byte inicial não seguido por 0|byte inicial não seguido por 0|2|0|  
|byte inicial seguido por 0|0|1|`EILSEQ`|  
  
 Observe que a segunda linha é apenas um caso especial da primeira.  Observe também que a tabela pressupõe `buffSizeInBytes` \>\= `pCopied`.  
  
 `_mbccpy_s` usa a localidade atual para qualquer comportamento dependente de local.  `_mbccpy_s_l` é idêntico a `_mbccpy_s`, exceto que `_mbccpy_s_l` usa a localidade passada em qualquer comportamento dependente da localidade.  
  
 No C\+\+, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tccpy_s`|Mapeia para a função macro ou embutida.|`_mbccpy_s`|Mapeia para a função macro ou embutida.|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mbccpy_s`|\<mbstring.h\>|  
|`_mbccpy_s_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [\_mbclen, mblen, \_mblen\_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)