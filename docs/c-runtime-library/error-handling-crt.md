---
title: Tratamento de erros (CRT)
ms.date: 11/04/2016
helpviewer_keywords:
- error handling, C routines for
- logic errors
- error handling, library routines
- testing, for program errors
ms.assetid: 125ac697-9eb0-4152-a440-b7842f23d97f
ms.openlocfilehash: d38aaf76a4901b12290782957db90049d815d278
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79443312"
---
# <a name="error-handling-crt"></a>Tratamento de erros (CRT)

Use estas rotinas para tratar erros de programa.

## <a name="error-handling-routines"></a>Rotinas de tratamento de erros

|Rotina|Use|
|-------------|---------|
|[assert](../c-runtime-library/reference/assert-macro-assert-wassert.md) macro|Teste para erros de lógica de programação; disponível nas versões de lançamento e de depuração da biblioteca em tempo de execução.|
|macros [_ASSERT, _ASSERTE](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md)|Similar a **assert**, mas disponível apenas nas versões de depuração da biblioteca em tempo de execução.|
|[clearerr](../c-runtime-library/reference/clearerr.md)|Redefina o indicador de erro. Chamar **rewind** ou fechar um fluxo também redefine o indicador de erro.|
|[_eof](../c-runtime-library/reference/eof.md)|Verifique o fim do arquivo em E/S de baixo nível.|
|[feof](../c-runtime-library/reference/feof.md)|Teste para o final do arquivo. O final do arquivo também é indicado quando **_read** retorna 0.|
|[ferror](../c-runtime-library/reference/ferror.md)|Teste se há erros de E/S de fluxo.|
|Macros [_RPT, _RPTF](../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md)|Gera um relatório similar a **printf**, mas disponível apenas nas versões de depuração da biblioteca em tempo de execução.|
|[_set_error_mode](../c-runtime-library/reference/set-error-mode.md)|Modifica **__error_mode** para determinar um local não padrão em que o tempo de execução C grava uma mensagem de erro para um erro que possivelmente finalizará o programa.|
|[_set_purecall_handler](../c-runtime-library/reference/get-purecall-handler-set-purecall-handler.md)|Define o manipulador para uma chamada de função virtual pura.|

## <a name="see-also"></a>Consulte também

- [Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)
