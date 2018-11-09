---
title: Tratamento de erros (CRT)
ms.date: 11/04/2016
f1_keywords:
- c.errors
helpviewer_keywords:
- error handling, C routines for
- logic errors
- error handling, library routines
- testing, for program errors
ms.assetid: 125ac697-9eb0-4152-a440-b7842f23d97f
ms.openlocfilehash: 7b3a5676c9297b1d7805f92b3a15cc71518ecd65
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50551210"
---
# <a name="error-handling-crt"></a>Tratamento de erros (CRT)

Use estas rotinas para tratar erros de programa.

## <a name="error-handling-routines"></a>Rotinas de tratamento de erros

|Rotina|Use|
|-------------|---------|
|[assert](../c-runtime-library/reference/assert-macro-assert-wassert.md) macro|Teste para erros de lógica de programação; disponível nas versões de lançamento e de depuração da biblioteca em tempo de execução.|
|Macros [_ASSERT, _ASSERTE](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)|Similar a **assert**, mas disponível apenas nas versões de depuração da biblioteca em tempo de execução.|
|[clearerr](../c-runtime-library/reference/clearerr.md)|Redefina o indicador de erro. Chamar **rewind** ou fechar um fluxo também redefine o indicador de erro.|
|[_eof](../c-runtime-library/reference/eof.md)|Verifique o fim do arquivo em E/S de baixo nível.|
|[feof](../c-runtime-library/reference/feof.md)|Teste para o final do arquivo. O final do arquivo também é indicado quando **_read** retorna 0.|
|[ferror](../c-runtime-library/reference/ferror.md)|Teste se há erros de E/S de fluxo.|
|Macros [_RPT, _RPTF](../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md)|Gera um relatório similar a **printf**, mas disponível apenas nas versões de depuração da biblioteca em tempo de execução.|
|[_set_error_mode](../c-runtime-library/reference/set-error-mode.md)|Modifica **__error_mode** para determinar um local não padrão em que o tempo de execução C grava uma mensagem de erro para um erro que possivelmente finalizará o programa.|
|[_set_purecall_handler](../c-runtime-library/reference/get-purecall-handler-set-purecall-handler.md)|Define o manipulador para uma chamada de função virtual pura.|

## <a name="see-also"></a>Consulte também

- [Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)
