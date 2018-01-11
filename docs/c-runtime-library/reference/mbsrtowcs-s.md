---
title: mbsrtowcs_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: mbsrtowcs_s
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords: mbsrtowcs_s
dev_langs: C++
helpviewer_keywords: mbsrtowcs_s function
ms.assetid: 4ee084ec-b15d-4e5a-921d-6584ec3b5a60
caps.latest.revision: "24"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b701362fd8ed19575f5de34f998bc8fd4f7e6de1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mbsrtowcss"></a>mbsrtowcs_s
Converte uma cadeia de caracteres multibyte na localidade atual para sua representação de cadeia de caracteres largos. Uma versão de [mbsrtowcs](../../c-runtime-library/reference/mbsrtowcs.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pReturnValue`  
 O número de caracteres convertidos.  
  
 [out] `wcstr`  
 Endereço do buffer para armazenar a cadeia de caracteres largos convertida resultante.  
  
 [out] `sizeInWords`  
 O tamanho do `wcstr` em palavras (caracteres largos).  
  
 [in, out] `mbstr`  
 O ponteiro indireto para o local da cadeia de caracteres multibyte a ser convertida.  
  
 [in] `count`  
 O número máximo de caracteres largos a serem armazenados no buffer `wcstr`, não incluindo o caractere nulo de terminação ou [_TRUNCATE](../../c-runtime-library/truncate.md).  
  
 [in, out] `mbstate`  
 Um ponteiro para um objeto do estado da conversão `mbstate_t`. Se esse valor for um ponteiro nulo, um objeto de estado de conversão interno estático será usado. Como o objeto `mbstate_t` interno não é thread-safe, é recomendável que você sempre passe seu próprio parâmetro `mbstate`.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se a conversão for bem-sucedida ou um código de erro em caso de falha.  
  
|Condição de erro|Valor retornado e `errno`|  
|---------------------|------------------------------|  
|`wcstr` é um ponteiro nulo e `sizeInWords` > 0|`EINVAL`|  
|`mbstr` é um ponteiro nulo|`EINVAL`|  
|A cadeia de caracteres indiretamente apontada por `mbstr` contém uma sequência multibyte que não é válida para a localidade atual.|`EILSEQ`|  
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que `count` seja `_TRUNCATE`, para obter mais informações, consulte Comentários abaixo)|`ERANGE`|  
  
 Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará um código de erro e definirá `errno` conforme indicado na tabela.  
  
## <a name="remarks"></a>Comentários  
 A função `mbsrtowcs_s` converte uma cadeia de caracteres multibyte apontada indiretamente por `mbstr` em caracteres largos armazenados no buffer apontado por `wcstr` usando o estado de conversão contido em `mbstate`. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:  
  
-   Um caractere nulo multibyte é encontrado  
  
-   Um caractere multibyte inválido é encontrado  
  
-   O número de caracteres largos armazenados no buffer `wcstr` é igual a `count`.  
  
 A cadeia de caracteres de destino `wcstr` sempre é terminada em nulo, mesmo no caso de um erro, a menos que `wcstr` seja um ponteiro nulo.  
  
 Se `count` for o valor especial [_TRUNCATE](../../c-runtime-library/truncate.md), `mbsrtowcs_s` converterá o máximo da cadeia de caracteres que caberá no buffer de destino ainda deixando espaço para um terminador nulo.  
  
 Se `mbsrtowcs_s` converter com êxito a cadeia de caracteres de origem, ela colocará o tamanho em caracteres largos da cadeia de caracteres convertidas e o terminador nulo em `*pReturnValue`, desde que `pReturnValue` não seja um ponteiro nulo. Isso ocorrerá mesmo se o argumento `wcstr` for um ponteiro nulo e permitirá que você determine o tamanho do buffer. Observe que se `wcstr` for um ponteiro nulo, `count` será ignorado.  
  
 Se `wcstr` não for um ponteiro nulo, será atribuído um ponteiro nulo ao objeto de ponteiro apontado por `mbstr` se a conversão tiver parado porque um caractere nulo de terminação foi atingido. Caso contrário, será atribuído o endereço logo depois do último caractere multibyte convertido, se houver. Isso permite que uma chamada de função subsequente reinicie a conversão em que essa chamada é interrompida.  
  
 Se `mbstate` for um ponteiro nulo, um objeto estático de estado de conversão `mbstate_t` interno da biblioteca será usado. Como o objeto estático interno não é thread-safe, é recomendável que você sempre passe seu próprio valor `mbstate`.  
  
 Se `mbsrtowcs_s` encontrar um caractere multibyte que não é válido na localidade atual, ele colocará -1 em `*pReturnValue`, definirá o buffer de destino `wcstr` para uma cadeia de caracteres vazia, definirá `errno` como `EILSEQ` e retornará `EILSEQ`.  
  
 Se as sequências apontadas por `mbstr` e por `wcstr` se sobrepuserem, o comportamento de `mbsrtowcs_s` será indefinido. `mbsrtowcs_s` é afetado pela categoria LC_TYPE da localidade atual.  
  
> [!IMPORTANT]
>  Verifique se `wcstr` e `mbstr` não se sobrepõem e se `count` reflete corretamente o número de caracteres multibyte a ser convertido.  
  
 A função `mbsrtowcs_s` difere da [mbstowcs_s, _mbstowcs_s_l](../../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md) por sua capacidade de reinicialização. O estado da conversão é armazenado em `mbstate` para chamadas posteriores às mesmas funções ou a outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo deverá usar `mbsrlen` em vez de `mbslen` se uma chamada subsequente para `mbsrtowcs_s` for usada em vez de `mbstowcs_s.`  
  
 Em C++, o uso dessa função é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando o requisito de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras usando suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
## <a name="exceptions"></a>Exceções  
 A função `mbsrtowcs_s` será multithread-safe se nenhuma função no thread atual chamar `setlocale` enquanto essa função estiver em execução e o argumento `mbstate` não for um ponteiro nulo.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`mbsrtowcs_s`|\<wchar.h>|  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [mbrtowc](../../c-runtime-library/reference/mbrtowc.md)   
 [mbtowc, _mbtowc_l](../../c-runtime-library/reference/mbtowc-mbtowc-l.md)   
 [mbstowcs_s, _mbstowcs_s_l](../../c-runtime-library/reference/mbstowcs-s-mbstowcs-s-l.md)   
 [mbsinit](../../c-runtime-library/reference/mbsinit.md)