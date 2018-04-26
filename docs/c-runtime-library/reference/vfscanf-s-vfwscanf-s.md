---
title: vfscanf_s, vfwscanf_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- vfscanf_s
- vfwscanf_s
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
apitype: DLLExport
f1_keywords:
- vfscanf_s
- vfwscanf_s
- _vftscanf_s
dev_langs:
- C++
ms.assetid: 9b0133f0-9a18-4581-b24b-3b72683ad432
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 24f4797cab8b01f45c00c38da31bc2fcf67fc957
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="vfscanfs-vfwscanfs"></a>vfscanf_s, vfwscanf_s

Lê dados formatados de um fluxo. Essas versões de vfscanf, vfwscanf têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
int vfscanf_s(
   FILE *stream,
   const char *format,
   va_list arglist
);
int vfwscanf_s(
   FILE *stream,
   const wchar_t *format,
   va_list arglist
);

```

### <a name="parameters"></a>Parâmetros

*Fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*format*<br/>
Cadeia de caracteres de controle de formato.

*arglist*<br/>
Lista de argumentos variáveis.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna o número de campos que são convertidos e atribuídos com êxito; o valor retornado não inclui campos que foram lidos, mas não atribuídos. Um valor retornado igual a 0 indica que nenhum campo foi atribuído. Se ocorrer um erro ou se o final do fluxo de arquivo for atingido antes da primeira conversão, o valor de retorno é **EOF** para **vfscanf_s** e **vfwscanf_s**.

Essas funções validam seus parâmetros. Se *fluxo* é um ponteiro de arquivo inválido ou *formato* é um ponteiro nulo, essas funções invocam o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam **EOF** e defina **errno** para **EINVAL**.

## <a name="remarks"></a>Comentários

O **vfscanf_s** função lê dados da posição atual do *fluxo* para os locais que são fornecidos pelo *arglist* lista de argumentos (se houver). Cada argumento na lista deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo na *formato*. *formato* controla a interpretação da entrada de campos e tem o mesmo formulário e funcionar como o *formato* argumento **scanf_s**; consulte [campos de especificação de formato: Funções scanf e wscanf](../../c-runtime-library/format-specification-fields-scanf-and-wscanf-functions.md) para obter uma descrição de *formato*. **vfwscanf_s** é uma versão de caractere largo de **vfscanf_s**; o argumento de formato para **vfwscanf_s** é uma cadeia de caracteres largos. Essas funções terão comportamento idêntico se o fluxo for aberto no modo ANSI. **vfscanf_s** atualmente não dá suporte a entrada de um fluxo UNICODE.

A principal diferença entre as funções mais seguras (que têm o **t** sufixo) e as outras versões é que as funções mais seguras requerem que o tamanho em caracteres de cada **c**, **C**, **s**, **S**, e **[** campo de tipo a ser passado como um argumento imediatamente após a variável. Para obter mais informações, consulte [scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l](scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md) e [Especificação de largura scanf](../../c-runtime-library/scanf-width-specification.md).

> [!NOTE]
> O parâmetro de tamanho é do tipo **sem sinal**, não **size_t**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_vftscanf_s**|**vfscanf_s**|**vfscanf_s**|**vfwscanf_s**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**vfscanf_s**|\<stdio.h>|
|**vfwscanf_s**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_vfscanf_s.c
// compile with: /W3
// This program writes formatted
// data to a file. It then uses vfscanf_s to
// read the various data back from the file.

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

FILE *stream;

int call_vfscanf_s(FILE * istream, char * format, ...)
{
    int result;
    va_list arglist;
    va_start(arglist, format);
    result = vfscanf_s(istream, format, arglist);
    va_end(arglist);
    return result;
}

int main(void)
{
    long l;
    float fp;
    char s[81];
    char c;

    if (fopen_s(&stream, "vfscanf_s.out", "w+") != 0)
    {
        printf("The file vfscanf_s.out was not opened\n");
    }
    else
    {
        fprintf(stream, "%s %ld %f%c", "a-string",
            65000, 3.14159, 'x');
        // Security caution!
        // Beware loading data from a file without confirming its size,
        // as it may lead to a buffer overrun situation.

        // Set pointer to beginning of file:
        fseek(stream, 0L, SEEK_SET);

        // Read data back from file:
        call_vfscanf_s(stream, "%s %ld %f%c", s, _countof(s), &l, &fp, &c, 1);

        // Output data read:
        printf("%s\n", s);
        printf("%ld\n", l);
        printf("%f\n", fp);
        printf("%c\n", c);

        fclose(stream);
    }
}

```

```Output
a-string
65000
3.141590
x
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_cscanf_s, _cscanf_s_l, _cwscanf_s, _cwscanf_s_l](cscanf-s-cscanf-s-l-cwscanf-s-cwscanf-s-l.md)<br/>
[fprintf_s, _fprintf_s_l, fwprintf_s, _fwprintf_s_l](fprintf-s-fprintf-s-l-fwprintf-s-fwprintf-s-l.md)<br/>
[scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l](scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)<br/>
[sscanf_s, _sscanf_s_l, swscanf_s, _swscanf_s_l](sscanf-s-sscanf-s-l-swscanf-s-swscanf-s-l.md)<br/>
[fscanf, _fscanf_l, fwscanf, _fwscanf_l](fscanf-fscanf-l-fwscanf-fwscanf-l.md)<br/>
[vfscanf, vfwscanf](vfscanf-vfwscanf.md)<br/>
