---
title: Estados de fluxo
ms.date: 11/19/2018
helpviewer_keywords:
- streams, states
ms.assetid: 5f28c968-f132-403f-968c-8417ff315e52
ms.openlocfilehash: 43d28fa504c64fcb25d5c7cd3ee2c6ed906acd7e
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52175555"
---
# <a name="stream-states"></a>Estados de fluxo

Os estados válidos e transições de estado para um fluxo são mostrados na figura a seguir.

![Diagrama dos estados de fluxo](../c-runtime-library/media/stream.gif "Diagrama dos estados de fluxo")

Cada um dos círculos indica um estado estável. Cada uma das linhas denota uma transição que pode ocorrer como resultado de uma chamada de função que opera no fluxo. Cinco grupos de funções podem causar transições de estado.

Funções nos três primeiros grupos são declaradas no \<stdio.h>:

- As funções de leitura de byte — [fgetc](../c-runtime-library/reference/fgetc-fgetwc.md), [fgets](../c-runtime-library/reference/fgets-fgetws.md), [fread](../c-runtime-library/reference/fread.md), [fscanf](../c-runtime-library/reference/fscanf-fscanf-l-fwscanf-fwscanf-l.md), [getc](../c-runtime-library/reference/getc-getwc.md), [getchar](../c-runtime-library/reference/getc-getwc.md), [gets](../c-runtime-library/gets-getws.md), [scanf](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md) e [ungetc](../c-runtime-library/reference/ungetc-ungetwc.md)

- As funções de gravação de byte — [fprintf](../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md), [fputc](../c-runtime-library/reference/fputc-fputwc.md), [fputs](../c-runtime-library/reference/fputs-fputws.md), [fwrite](../c-runtime-library/reference/fwrite.md), [printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md), [putc](../c-runtime-library/reference/putc-putwc.md), [putchar](../c-runtime-library/reference/putc-putwc.md), [puts](../c-runtime-library/reference/puts-putws.md), [vfprintf](../c-runtime-library/reference/vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md) e [vprintf](../c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l.md)

- As funções de posição — [fflush](../c-runtime-library/reference/fflush.md), [fseek](../c-runtime-library/reference/fseek-fseeki64.md), [fsetpos](../c-runtime-library/reference/fsetpos.md) e [rewind](../c-runtime-library/reference/rewind.md)

Funções em dois grupos restantes são declaradas no \<wchar.h>:

- As funções de leitura ampla — [fgetwc](../c-runtime-library/reference/fgetc-fgetwc.md), [fgetws](../c-runtime-library/reference/fgets-fgetws.md), [fwscanf](../c-runtime-library/reference/fscanf-fscanf-l-fwscanf-fwscanf-l.md), [getwc](../c-runtime-library/reference/getc-getwc.md), [getwchar](../c-runtime-library/reference/getc-getwc.md), [ungetwc](../c-runtime-library/reference/ungetc-ungetwc.md) e [wscanf](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md),

- As funções de gravação ampla — [fwprintf](../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md), [fputwc](../c-runtime-library/reference/fputc-fputwc.md), [fputws](../c-runtime-library/reference/fputs-fputws.md), [putwc](../c-runtime-library/reference/putc-putwc.md), [putwchar](../c-runtime-library/reference/fputc-fputwc.md), [vfwprintf](../c-runtime-library/reference/vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md), [vwprintf](../c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l.md) e [wprintf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md),

O diagrama de estado mostra que você deve chamar uma das funções de posição entre a maioria das operações de leitura e gravação:

- Você não pode chamar uma função de leitura se a última operação no fluxo foi uma gravação.

- Você não pode chamar uma função de gravação se a última operação no fluxo foi uma leitura, a menos que a operação de leitura tenha definido o indicador de final de arquivo.

Por fim, o diagrama de estado mostra que uma operação de posição nunca diminui o número de chamadas de função válido que pode seguir.

## <a name="see-also"></a>Consulte também

[Arquivos e fluxos](../c-runtime-library/files-and-streams.md)