---
title: Robustez
ms.date: 11/04/2016
helpviewer_keywords:
- robustness [CRT]
ms.assetid: 7f1a87f8-eff9-4b76-ae9b-d133d3de6adf
ms.openlocfilehash: 5e13152b2c31511cce4df9976d6c800960c099a5
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444881"
---
# <a name="robustness"></a>Robustez

Use as funções da biblioteca de tempo de execução C para deixar seu programa mais robusto.

## <a name="run-time-robustness-functions"></a>Funções que conferem robustez ao tempo de execução

|Função|Use|
|--------------|---------|
|[_set_new_handler](../c-runtime-library/reference/set-new-handler.md)|Transfere o controle ao mecanismo de gerenciamento de erros caso o operador **new** não consiga alocar memória.|
|[_set_se_translator](../c-runtime-library/reference/set-se-translator.md)|Trata exceções do Win32 (exceções C estruturadas) como exceções C++.|
|[set_terminate](../c-runtime-library/reference/set-terminate-crt.md)|Instala sua próprio função de terminação a ser chamada por [terminate](../c-runtime-library/reference/terminate-crt.md).|
|[set_unexpected](../c-runtime-library/reference/set-unexpected-crt.md)|Instala sua próprio função de terminação a ser chamada por [unexpected](../c-runtime-library/reference/unexpected-crt.md).|

## <a name="see-also"></a>Consulte também

[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
[SetUnhandledExceptionFilter](/windows/win32/api/errhandlingapi/nf-errhandlingapi-setunhandledexceptionfilter)<br/>
