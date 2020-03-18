---
title: E/S de fluxo
ms.date: 11/04/2016
helpviewer_keywords:
- I/O routines, stream I/O
- I/O [CRT], stream
- stream I/O
ms.assetid: dc7874d3-a91b-456a-9015-4748bb358217
ms.openlocfilehash: 0fc49d4cd26593cb02a2ff05c3205cc630ef848c
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444611"
---
# <a name="stream-io"></a>E/S de fluxo

Essas funções processam os dados em diferentes tamanhos e formatos, desde caracteres únicos até grandes estruturas de dados. Elas também fornecem o armazenamento em buffer, o que pode melhorar o desempenho. O tamanho padrão de um buffer de fluxo é de 4 K. Essas rotinas afetam apenas os buffers criados por rotinas de biblioteca de tempo de execução e não têm efeito nos buffers criados pelo sistema operacional.

## <a name="stream-io-routines"></a>Rotinas de E/S de fluxo

|Rotina|Use|
|-------------|---------|
|[clearerr](../c-runtime-library/reference/clearerr.md), [clearerr_s](../c-runtime-library/reference/clearerr-s.md)|Limpar o indicador de erro do fluxo|
|[fclose](../c-runtime-library/reference/fclose-fcloseall.md)|Fechar o fluxo|
|[_fcloseall](../c-runtime-library/reference/fclose-fcloseall.md)|Fechar todos os fluxos abertos exceto **stdin**, **stdout** e **stderr**|
|[_fdopen, wfdopen](../c-runtime-library/reference/fdopen-wfdopen.md)|Associar o fluxo ao descritor de arquivo do arquivo aberto|
|[feof](../c-runtime-library/reference/feof.md)|Testar o final do arquivo no fluxo|
|[ferror](../c-runtime-library/reference/ferror.md)|Testar o erro no fluxo|
|[fflush](../c-runtime-library/reference/fflush.md)|Liberar o fluxo no buffer ou dispositivo de armazenamento|
|[fgetc, fgetwc](../c-runtime-library/reference/fgetc-fgetwc.md)|Ler caracteres do fluxo (versões de função de **getc** e **getwc**)|
|[_fgetchar, _fgetwchar](../c-runtime-library/reference/fgetc-fgetwc.md)|Ler caracteres de **stdin** (versões de função de **getchar** e **getwchar**)|
|[fgetpos](../c-runtime-library/reference/fgetpos.md)|Obter o indicador de posição do fluxo|
|[fgets, fgetws](../c-runtime-library/reference/fgets-fgetws.md)|Ler a cadeia de caracteres do fluxo|
|[_fileno](../c-runtime-library/reference/fileno.md)|Obter o descritor de arquivo associado ao fluxo|
|[_flushall](../c-runtime-library/reference/flushall.md)|Liberar todos os fluxos no buffer ou dispositivo de armazenamento|
|[fopen, _wfopen](../c-runtime-library/reference/fopen-wfopen.md), [fopen_s, _wfopen_s](../c-runtime-library/reference/fopen-s-wfopen-s.md)|Abrir fluxo|
|[fprintf, _fprintf_l, fwprintf, _fwprintf_l](../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md), [fprintf_s, _fprintf_s_l, fwprintf_s, _fwprintf_s_l](../c-runtime-library/reference/fprintf-s-fprintf-s-l-fwprintf-s-fwprintf-s-l.md)|Gravar os dados formatados no fluxo|
|[fputc, fputwc](../c-runtime-library/reference/fputc-fputwc.md)|Gravar um caractere em um fluxo (versões de função de **putc** e **putwc**)|
|[_fputchar, _fputwchar](../c-runtime-library/reference/fputc-fputwc.md)|Gravar caractere em **stdout** (versões de função de **putchar** e **putwchar**)|
|[fputs, fputws](../c-runtime-library/reference/fputs-fputws.md)|Gravar a cadeia de caracteres no fluxo|
|[fread](../c-runtime-library/reference/fread.md)|Ler dados não formatados no fluxo|
|[freopen, _wfreopen](../c-runtime-library/reference/freopen-wfreopen.md), [freopen_s, _wfreopen_s](../c-runtime-library/reference/freopen-s-wfreopen-s.md)|Reatribuir o ponteiro de fluxo **FILE** para o novo arquivo ou dispositivo|
|[fscanf, fwscanf](../c-runtime-library/reference/fscanf-fscanf-l-fwscanf-fwscanf-l.md), [fscanf_s, _fscanf_s_l, fwscanf_s, _fwscanf_s_l](../c-runtime-library/reference/fscanf-s-fscanf-s-l-fwscanf-s-fwscanf-s-l.md)|Ler dados formatados no fluxo|
|[fseek, _fseeki64](../c-runtime-library/reference/fseek-fseeki64.md)|Mover posição do arquivo para um determinado local|
|[fsetpos](../c-runtime-library/reference/fsetpos.md)|Definir o indicador de posição do fluxo|
|[_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md)|Abrir um fluxo com compartilhamento de arquivos|
|[ftell, _ftelli64](../c-runtime-library/reference/ftell-ftelli64.md)|Obter a posição atual do arquivo|
|[fwrite](../c-runtime-library/reference/fwrite.md)|Gravar itens de dados não formatados no fluxo|
|[getc, getwc](../c-runtime-library/reference/getc-getwc.md)|Ler caracteres do fluxo (versões macro de **fgetc** e **fgetwc**)|
|[getchar, getwchar](../c-runtime-library/reference/getc-getwc.md)|Ler caracteres de **stdin** (versões macro de **fgetchar** e **fgetwchar**)|
|[_getmaxstdio](../c-runtime-library/reference/getmaxstdio.md)|Retorna o número permitido de arquivos abertos simultaneamente no nível de E/S do fluxo.|
|[gets_s, _getws_s](../c-runtime-library/reference/gets-s-getws-s.md)|Ler linha de **stdin**|
|[_getw](../c-runtime-library/reference/getw.md)|Ler binário **int** do fluxo|
|[printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md),[printf_s, _printf_s_l, wprintf_s, _wprintf_s_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)|Gravar dados formatados em **stdout**|
|[putc, putwc](../c-runtime-library/reference/putc-putwc.md)|Gravar caracteres em um fluxo (versões macro de **fputc** e **fputwc**)|
|[putchar, putwchar](../c-runtime-library/reference/putc-putwc.md)|Gravar caracteres em **stdout** (versões macro de **fputchar** e **fputwchar**)|
|[puts, _putws](../c-runtime-library/reference/puts-putws.md)|Gravar linha no fluxo|
|[_putw](../c-runtime-library/reference/putw.md)|Gravar binário **int** em fluxo|
|[rewind](../c-runtime-library/reference/rewind.md)|Mover a posição do arquivo para o começo do fluxo|
|[_rmtmp](../c-runtime-library/reference/rmtmp.md)|Remover arquivos temporários criados por **tmpfile**|
|[scanf, _scanf_l, wscanf, _wscanf_l](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md),[scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l](../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)|Ler dados formatados de **stdin**|
|[setbuf](../c-runtime-library/reference/setbuf.md)|Controlar o buffer de fluxo|
|[_setmaxstdio](../c-runtime-library/reference/setmaxstdio.md)|Definir o máximo de arquivos abertos simultaneamente no nível de E/S de fluxo.|
|[setvbuf](../c-runtime-library/reference/setvbuf.md)|Controlar o tamanho do buffer e o buffer de fluxo|
|[_snprintf, _snwprintf](../c-runtime-library/reference/snprintf-snprintf-snprintf-l-snwprintf-snwprintf-l.md), [_snprintf_s, _snprintf_s_l, _snwprintf_s, _snwprintf_s_l](../c-runtime-library/reference/snprintf-s-snprintf-s-l-snwprintf-s-snwprintf-s-l.md)|Gravar dados formatados de comprimento especificado na cadeia de caracteres|
|[_snscanf, _snwscanf](../c-runtime-library/reference/snscanf-snscanf-l-snwscanf-snwscanf-l.md), [_snscanf_s, _snscanf_s_l, _snwscanf_s, _snwscanf_s_l](../c-runtime-library/reference/snscanf-s-snscanf-s-l-snwscanf-s-snwscanf-s-l.md)|Ler os dados formatados de um comprimento especificado do fluxo de entrada padrão.|
|[sprintf, swprintf](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md), [sprintf_s, _sprintf_s_l, swprintf_s, _swprintf_s_l](../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md)|Gravar dados formatados na cadeia de caracteres|
|[sscanf, swscanf](../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md), [sscanf_s, _sscanf_s_l, swscanf_s, _swscanf_s_l](../c-runtime-library/reference/sscanf-s-sscanf-s-l-swscanf-s-swscanf-s-l.md)|Ler dados formatados na cadeia de caracteres|
|[_tempnam, _wtempnam](../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)|Gerar o nome de arquivo temporário no diretório fornecido|
|[tmpfile](../c-runtime-library/reference/tmpfile.md), [tmpfile_s](../c-runtime-library/reference/tmpfile-s.md)|Criar arquivo temporário|
|[tmpnam, _wtmpnam](../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md), [tmpnam_s, _wtmpnam_s](../c-runtime-library/reference/tmpnam-s-wtmpnam-s.md)|Gerar nome de arquivo temporário|
|[ungetc, ungetwc](../c-runtime-library/reference/ungetc-ungetwc.md)|Enviar caractere por push para o fluxo|
|[_vcprintf, _vcwprintf](../c-runtime-library/reference/vcprintf-vcprintf-l-vcwprintf-vcwprintf-l.md), [_vcprintf_s, _vcprintf_s_l, _vcwprintf_s, _vcwprintf_s_l](../c-runtime-library/reference/vcprintf-s-vcprintf-s-l-vcwprintf-s-vcwprintf-s-l.md)|Gravar os dados formatados no console.|
|[vfprintf, vfwprintf](../c-runtime-library/reference/vfprintf-vfprintf-l-vfwprintf-vfwprintf-l.md), [vfprintf_s, _vfprintf_s_l, vfwprintf_s, _vfwprintf_s_l](../c-runtime-library/reference/vfprintf-s-vfprintf-s-l-vfwprintf-s-vfwprintf-s-l.md)|Gravar os dados formatados no fluxo|
|[vprintf, vwprintf](../c-runtime-library/reference/vprintf-vprintf-l-vwprintf-vwprintf-l.md), [vprintf_s, _vprintf_s_l, vwprintf_s, _vwprintf_s_l](../c-runtime-library/reference/vprintf-s-vprintf-s-l-vwprintf-s-vwprintf-s-l.md)|Gravar dados formatados em **stdout**|
|[_vsnprintf, _vsnwprintf](../c-runtime-library/reference/vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l.md), [vsnprintf_s, _vsnprintf_s, _vsnprintf_s_l, _vsnwprintf_s, _vsnwprintf_s_l](../c-runtime-library/reference/vsnprintf-s-vsnprintf-s-vsnprintf-s-l-vsnwprintf-s-vsnwprintf-s-l.md)|Gravar dados formatados de comprimento especificado no buffer|
|[vsprintf, vswprintf](../c-runtime-library/reference/vsprintf-vsprintf-l-vswprintf-vswprintf-l-vswprintf-l.md), [vsprintf_s, _vsprintf_s_l, vswprintf_s, _vswprintf_s_l](../c-runtime-library/reference/vsprintf-s-vsprintf-s-l-vswprintf-s-vswprintf-s-l.md)|Gravar dados formatados no buffer|

Quando um programa começa a execução, o código de inicialização abre automaticamente vários fluxos: entrada padrão (apontada por **stdin**), saída padrão (apontada por **stdout**) e o erro padrão (apontado por **stderr**). Esses fluxos são direcionados ao console (tela e teclado) por padrão. Use **freopen** para redirecionar **stdin**, **stdout** ou **stderr** para um arquivo de disco ou um dispositivo.

Por padrão, os arquivos abertos usando as rotinas de fluxo serão armazenados em buffer. As funções **stdout** e **stderr** são liberadas sempre que estão cheias ou, caso você esteja gravando em um dispositivo de caractere, após cada chamada de biblioteca. Se um programa for encerrado de forma anormal, talvez os buffers de saída não esvaziem, resultando na perda de dados. Use **fflush** ou **_flushall** para garantir que o buffer associado a um arquivo especificado, ou todos os buffers abertos, seja liberado para o sistema operacional, que pode armazenar dados em cache antes de gravar no disco. O recurso de confirmação em disco garante que o conteúdo liberado do buffer não seja perdido em caso de falha do sistema.

Há duas maneiras de confirmar o conteúdo do buffer no disco:

- Vincular com o arquivo COMMODE.OBJ para definir um sinalizador de confirmação global. A configuração padrão do sinalizador global é **n**, para "sem confirmação".

- Defina o sinalizador de modo **c** com **fopen** ou **_fdopen**.

Qualquer arquivo aberto especificamente com o sinalizador **c** ou **n** se comportará de acordo com o sinalizador, independentemente do estado do sinalizador de confirmação/sem confirmação global.

Se o seu programa não fechar explicitamente um fluxo, ele será automaticamente fechado quando o programa for encerrado. No entanto, é necessário fechar um fluxo quando seu programa deixar de usá-lo, pois o número de fluxos que podem ser abertos ao mesmo tempo é limitado. Confira [_setmaxstdio](../c-runtime-library/reference/setmaxstdio.md) para obter informações sobre esse limite.

A entrada pode seguir a saída diretamente apenas com uma chamada intermediária para **fflush** ou para uma função de posicionamento de arquivos (**fseek**, **fsetpos** ou **rewind**). A saída pode seguir a entrada sem uma chamada intermediária para uma função de posicionamento de arquivo se a operação de entrada encontrar o final do arquivo.

## <a name="see-also"></a>Consulte também

[Entrada e saída](../c-runtime-library/input-and-output.md)<br/>
[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
