---
title: _cgets_s, _cgetws_s
ms.date: 11/04/2016
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
helpviewer_keywords:
- strings [C++], getting from console
- console, getting strings from
- _cgets_s function
- cget_s function
- _cgetws_s function
- cgetws_s function
ms.assetid: 38b74897-afe6-4dd9-a43f-36a3c0d72c5c
ms.openlocfilehash: 8341b775df3b9cbaececdfaa1f17e075d7c7416c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50588533"
---
# <a name="cgetss-cgetwss"></a>_cgets_s, _cgetws_s

Obtém uma cadeia de caracteres do console. Estas versões de [_cgets e _cgetws](../../c-runtime-library/cgets-cgetws.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
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

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Local de armazenamento de dados.

*numberOfElements*<br/>
O tamanho do buffer em caracteres de byte único ou largos, que também é o número máximo de caracteres a serem lido.

*pSizeRead*<br/>
O número de caracteres de fato lidos.

## <a name="return-value"></a>Valor de retorno

O valor retornado será zero se obtiver sucesso; caso contrário, um código de erro será gerado se ocorrer uma falha.

### <a name="error-conditions"></a>Condições de Erro

|*buffer*|*numberOfElements*|*pSizeRead*|Valor de|Conteúdo de *buffer*|
|--------------|------------------------|-----------------|------------|--------------------------|
|**NULL**|qualquer|qualquer|**EINVAL**|N/D|
|Não **nulo**|zero|qualquer|**EINVAL**|não modificado|
|Não **nulo**|qualquer|**NULL**|**EINVAL**|cadeia de caracteres de comprimento zero|

## <a name="remarks"></a>Comentários

**cgets_s** e **cgetws_s** ler uma cadeia de caracteres do console e copie a cadeia de caracteres (com um terminador nulo) *buffer*. **cgetws_s** a versão de caractere largo da função; não for mais o tamanho de caractere, o comportamento dessas duas funções é idêntico. O tamanho máximo da cadeia de caracteres a ser lido é passado como o *numberOfElements* parâmetro. Esse tamanho deve incluir um caractere extra para a terminação nula. O número real de caracteres lidos é colocado na *pSizeRead*.

Se ocorrer um erro durante a operação ou na validação dos parâmetros, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e **EINVAL** é retornado.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho e podem substituir automaticamente funções mais antigas e menos seguras por equivalentes mais novas e mais seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_cgetts_s**|**_cgets_s**|**_cgets_s**|**_cgetws_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_cgets_s**|\<conio.h>|
|**_cgetws_s**|\<conio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[E/S de porta e console](../../c-runtime-library/console-and-port-i-o.md)<br/>
[_getch, _getwch](getch-getwch.md)<br/>
