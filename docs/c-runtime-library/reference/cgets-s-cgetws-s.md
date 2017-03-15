---
title: _cgets_s, _cgetws_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _cgetws_s
- _cgets_s
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
- api-ms-win-crt-conio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _cgets_s
- cgets_s
- cgetws_s
- _cgetws_s
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], getting from console
- console, getting strings from
- _cgets_s function
- cget_s function
- _cgetws_s function
- cgetws_s function
ms.assetid: 38b74897-afe6-4dd9-a43f-36a3c0d72c5c
caps.latest.revision: 31
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 267963b8f9344cef67788726bd2c6f082c7953ac
ms.lasthandoff: 02/25/2017

---
# <a name="cgetss-cgetwss"></a>_cgets_s, _cgetws_s
Obtém uma cadeia de caracteres do console. Estas versões de [_cgets e _cgetws](../../c-runtime-library/cgets-cgetws.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _cgets_s(   
   char *buffer,  
   size_t numberOfElements,  
   size_t *pSizeRead  
);  
errno_t _cgetws_s(  
   wchar_t *buffer  
   size_t numberOfElements,  
   size_t *pSizeRead  
);  
template <size_t size>  
errno_t _cgets_s(   
   char (&buffer)[size],  
   size_t *pSizeRead  
); // C++ only  
template <size_t size>  
errno_t _cgetws_s(  
   wchar_t (&buffer)[size],  
   size_t *pSizeRead  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `buffer`  
 Local de armazenamento de dados.  
  
 [in] `numberOfElements`  
 O tamanho do buffer em caracteres de byte único ou largos, que também é o número máximo de caracteres a serem lido.  
  
 [in] `pSizeRead`  
 O número de caracteres de fato lidos.  
  
## <a name="return-value"></a>Valor retornado  
 O valor retornado será zero se obtiver sucesso; caso contrário, um código de erro será gerado se ocorrer uma falha.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`buffer`|`numberOfElements`|`pSizeRead`|Valor de|Conteúdo de `buffer`|  
|--------------|------------------------|-----------------|------------|--------------------------|  
|`NULL`|qualquer|qualquer|`EINVAL`|N/D|  
|não é `NULL`|zero|qualquer|`EINVAL`|não modificado|  
|não é `NULL`|qualquer|`NULL`|`EINVAL`|cadeia de caracteres de comprimento zero|  
  
## <a name="remarks"></a>Comentários  
 `_cgets_s` e `_cgetws_s` leem uma cadeia de caracteres do console e copiam a cadeia de caracteres (com um terminador nulo) para `buffer`. `_cgetws_s` é a versão de caractere largo da função; além do tamanho de caractere, o comportamento dessas duas funções é idêntico. O tamanho máximo da cadeia de caracteres a ser lido é passado como no parâmetro `numberOfElements`. Esse tamanho deve incluir um caractere extra para a terminação nula. O número real de caracteres lidos é colocado em `pSizeRead`.  
  
 Se ocorrer um erro durante a operação ou na validação dos parâmetros, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se for permitido que a execução continue, `errno` é definido como `EINVAL` e `EINVAL` é retornado.  
  
 No C++, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho e podem substituir automaticamente funções mais antigas e menos seguras por equivalentes mais novas e mais seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_cgetts_s`|`_cgets_s`|`_cgets_s`|`_cgetws_s`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_cgets_s`|\<conio.h>|  
|`_cgetws_s`|\<conio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [E/S de porta e console](../../c-runtime-library/console-and-port-i-o.md)   
 [_getch, _getwch](../../c-runtime-library/reference/getch-getwch.md)
