---
title: Validação de parâmetro
description: Uma descrição da validação de parâmetro na biblioteca de tempo de execução do Microsoft C.
ms.date: 11/04/2016
ms.topic: conceptual
helpviewer_keywords:
- parameters, validation
ms.assetid: 019dd5f0-dc61-4d2e-b4e9-b66409ddf1f2
ms.openlocfilehash: 8378e4bf9bdfc950002c3ed8c3ef50c27a3c162d
ms.sourcegitcommit: 30792632548d1c71894f9fecbe2f554294b86020
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/06/2020
ms.locfileid: "91765253"
---
# <a name="parameter-validation"></a>Validação de parâmetro

A maioria das funções CRT com segurança avançada, e muitas que não são, validam seus parâmetros para coisas como verificação de ponteiros para **NULL**, que os inteiros se enquadram em um intervalo válido ou que os valores de enumeração são válidos. Se um parâmetro inválido for encontrado, o manipulador de parâmetro inválido será chamado.

## <a name="invalid-parameter-handler-routine"></a>Rotina do manipulador de parâmetro inválido

Quando uma função de biblioteca de tempo de execução C detecta um parâmetro inválido, ele captura algumas informações sobre o erro e, em seguida, chama uma macro que encapsula uma função de expedição de manipulador de parâmetro inválida. Que será uma das [_invalid_parameter](../c-runtime-library/reference/invalid-parameter-functions.md), [_invalid_parameter_noinfo](../c-runtime-library/reference/invalid-parameter-functions.md)ou [_invalid_parameter_noinfo_noreturn](../c-runtime-library/reference/invalid-parameter-functions.md). A função de expedição é chamada depende se o seu código é, respectivamente, uma compilação de depuração, uma compilação de varejo ou se o erro não é considerado recuperável.

Em compilações de depuração, a macro de parâmetro inválida geralmente gera uma asserção com falha e um ponto de interrupção do depurador antes que a função de expedição seja chamada. Quando o código é executado, a asserção pode ser relatada ao usuário em uma caixa de diálogo que tem "abortar", "repetir" e "continuar" ou opções semelhantes, dependendo do sistema operacional e da versão da biblioteca de tempo de execução. Essas opções permitem que o usuário encerre imediatamente o programa, anexe um depurador ou permita que o código existente continue a ser executado, o que chama a função de expedição.

A função de expedição de manipulador de parâmetro inválida chama o manipulador de parâmetro inválido atribuído no momento. Por padrão, as chamadas de parâmetro inválidas `_invoke_watson` , que fazem com que o aplicativo feche e gere um minidespejo. Se habilitado pelo sistema operacional, uma caixa de diálogo perguntará ao usuário se deseja enviar o despejo de memória para a Microsoft para análise.

Você pode alterar esse comportamento usando as funções [_set_invalid_parameter_handler](../c-runtime-library/reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md) ou [_set_thread_local_invalid_parameter_handler](../c-runtime-library/reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md) para definir o manipulador de parâmetro inválido para sua própria função. Se a função que você especificar não terminar o aplicativo, o controle será retornado para a função que recebeu os parâmetros inválidos. No CRT, essas funções normalmente interrompem a execução da função, são definidas `errno` como um código de erro e retornam um código de erro. Em muitos casos, o `errno` valor e o valor de retorno são ambos `EINVAL` , para indicar um parâmetro inválido. Em alguns casos, um código de erro mais específico é retornado, tal como `EBADF` para um ponteiro de arquivo inválido passado como um parâmetro.

Para obter mais informações sobre `errno`, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="see-also"></a>Confira também

[Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md)\
[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
