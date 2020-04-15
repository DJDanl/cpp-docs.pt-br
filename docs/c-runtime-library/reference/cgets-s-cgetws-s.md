---
title: _cgets_s, _cgetws_s
ms.date: 4/2/2020
api_name:
- _cgetws_s
- _cgets_s
- _o__cgets_s
- _o__cgetws_s
api_location:
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: b4871ff2c362e2c6cbe37be6a31bde4e6e258709
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81333541"
---
# <a name="_cgets_s-_cgetws_s"></a>_cgets_s, _cgetws_s

Obtém uma cadeia de caracteres do console. Estas versões de [_cgets e _cgetws](../../c-runtime-library/cgets-cgetws.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*Buffer*<br/>
Local de armazenamento de dados.

*Numberofelements*<br/>
O tamanho do buffer em caracteres de byte único ou largos, que também é o número máximo de caracteres a serem lido.

*pSizeRead*<br/>
O número de caracteres de fato lidos.

## <a name="return-value"></a>Valor retornado

O valor retornado será zero se obtiver sucesso; caso contrário, um código de erro será gerado se ocorrer uma falha.

### <a name="error-conditions"></a>Condições de erro

|*Buffer*|*Numberofelements*|*pSizeRead*|Retorno|Conteúdo de *buffer*|
|--------------|------------------------|-----------------|------------|--------------------------|
|**NULO**|any|any|**Einval**|n/d|
|não **NULO**|zero|any|**Einval**|não modificado|
|não **NULO**|any|**NULO**|**Einval**|cadeia de caracteres de comprimento zero|

## <a name="remarks"></a>Comentários

**_cgets_s** e **_cgetws_s** ler uma seqüência do console e copiar a seqüência (com um exterminador nulo) em *buffer*. **_cgetws_s** é a versão ampla da função; além do tamanho do personagem, o comportamento dessas duas funções é idêntico. O tamanho máximo da string a ser lida é passado como o parâmetro *numberOfElements.* Esse tamanho deve incluir um caractere extra para a terminação nula. O número real de caracteres lidos é colocado em *pSizeRead*.

Se ocorrer um erro durante a operação ou na validação dos parâmetros, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e **EINVAL** é devolvido.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho e podem substituir automaticamente funções mais antigas e menos seguras por equivalentes mais novas e mais seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões da biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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

## <a name="see-also"></a>Confira também

[Console e Porta I/O](../../c-runtime-library/console-and-port-i-o.md)<br/>
[_getch, _getwch](getch-getwch.md)<br/>
