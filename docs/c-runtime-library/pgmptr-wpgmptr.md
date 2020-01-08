---
title: _pgmptr, _wpgmptr
ms.date: 11/04/2016
f1_keywords:
- pgmptr
- _pgmptr
- wpgmptr
- _wpgmptr
helpviewer_keywords:
- wpgmptr function
- _wpgmptr function
- _pgmptr function
- pgmptr function
ms.assetid: 4d44b515-0eff-4136-8bc4-684195f218f5
ms.openlocfilehash: beff0401d0aa2aa21819e58618ef4c02795d4393
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75300151"
---
# <a name="_pgmptr-_wpgmptr"></a>_pgmptr, _wpgmptr

O caminho do arquivo executável. Preterido; use [_get_pgmptr](../c-runtime-library/reference/get-pgmptr.md) e [_get_wpgmptr](../c-runtime-library/reference/get-wpgmptr.md).

## <a name="syntax"></a>Sintaxe

```
extern char *_pgmptr;
extern wchar_t *_wpgmptr;
```

## <a name="remarks"></a>Comentários

Quando um programa é executado do interpretador de comandos (Cmd.exe), o `_pgmptr` é inicializado automaticamente para o caminho completo do arquivo executável. Por exemplo, quando Hello.exe está em C:\BIN e C:\BIN está no caminho, o `_pgmptr` é definido como C:\BIN\Hello.exe durante a execução:

```
C> hello
```

Quando um programa não é executado da linha de comando, o `_pgmptr` pode ser inicializado para o nome do programa (nome base do arquivo sem a extensão de nome de arquivo) ou para um nome de arquivo, caminho relativo ou caminho completo.

`_wpgmptr` é a contraparte de caractere largo de `_pgmptr` para uso com programas que utilizam `wmain`.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|`_tpgmptr`|`_pgmptr`|`_pgmptr`|`_wpgmptr`|

## <a name="requirements"></a>Requisitos do

|Variável|Cabeçalho necessário|
|--------------|---------------------|
|`_pgmptr`, `_wpgmptr`|\<stdlib.h>|

## <a name="example"></a>Exemplo

O programa a seguir demonstra o uso de `_pgmptr`.

```c
// crt_pgmptr.c
// compile with: /W3
// The following program demonstrates the use of _pgmptr.
//
#include <stdio.h>
#include <stdlib.h>
int main( void )
{
   printf("The full path of the executing program is : %Fs\n",
     _pgmptr); // C4996
   // Note: _pgmptr is deprecated; use _get_pgmptr instead
}
```

É possível usar `_wpgmptr` alterando `%Fs` para `%S` e `main` para `wmain`.

## <a name="see-also"></a>Veja também

[Variáveis globais](../c-runtime-library/global-variables.md)
