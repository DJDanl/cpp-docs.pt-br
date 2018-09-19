---
title: Verificação de erros em tempo de execução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- c.runtime
dev_langs:
- C++
helpviewer_keywords:
- run-time error checking
- run-time errors, checking
ms.assetid: c965dd01-57ad-4a3c-b1d6-5aa04f920501
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eaa4972a12729a5697db3574fcf89b0fb2b252ff
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46068449"
---
# <a name="run-time-error-checking"></a>Verificação de erros de tempo de execução

A biblioteca em tempo de execução C contém as funções que oferecem suporte a verificações de erro em tempo de execução (RTC). Verificação de erros em tempo de execução permite que você compilar o programa, de modo que determinados tipos de erros em tempo de execução são relatados. Especifique como os erros são relatados e quais tipos de erros são relatados. Para saber mais, confira [Como usar verificações de tempo de execução nativas](/visualstudio/debugger/how-to-use-native-run-time-checks).

Use as funções a seguir para personalizar a forma como o seu programa faz a verificação de erros em tempo de execução.

## <a name="run-time-error-checking-functions"></a>Funções de verificação de erros em tempo de execução

|Função|Use|
|--------------|---------|
|[_RTC_GetErrDesc](../c-runtime-library/reference/rtc-geterrdesc.md)|Retorna uma breve descrição de um tipo de verificação de erro em tempo de execução.|
|[_RTC_NumErrors](../c-runtime-library/reference/rtc-numerrors.md)|Retorna o número total de erros que podem ser detectados por verificação de erro em tempo de execução.|
|[_RTC_SetErrorFunc](../c-runtime-library/reference/rtc-seterrorfunc.md)|Designa uma função como o manipulador para verificações de erro em tempo de execução.|
|[_RTC_SetErrorType](../c-runtime-library/reference/rtc-seterrortype.md)|Associa um erro que é detectado pelas verificações de erro em tempo de execução com um tipo.|

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
[/RTC (verificações de erro em tempo de execução)](../build/reference/rtc-run-time-error-checks.md)<br/>
[runtime_checks](../preprocessor/runtime-checks.md)<br/>
[Rotinas de depuração](../c-runtime-library/debug-routines.md)<br/>
