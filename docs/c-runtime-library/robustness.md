---
title: Robustez
ms.date: 11/04/2016
f1_keywords:
- c.runtime
helpviewer_keywords:
- robustness [CRT]
ms.assetid: 7f1a87f8-eff9-4b76-ae9b-d133d3de6adf
ms.openlocfilehash: 108b4c9dde08adf1a3c54c810f68be69bf150472
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70739598"
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

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
[SetUnhandledExceptionFilter](/windows/win32/api/errhandlingapi/nf-errhandlingapi-setunhandledexceptionfilter)<br/>
