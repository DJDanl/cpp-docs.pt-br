---
title: Erro de linha de comando D8016 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- D8016
dev_langs:
- C++
helpviewer_keywords:
- D8016
ms.assetid: eec51312-7471-4f92-94b2-d517cafc8ef5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ee16542b2f0cf9842e351813ed2e0b0d22cccaa
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46056983"
---
# <a name="command-line-error-d8016"></a>Erro D8016 (linha de comando)

Opções de linha de comando de 'opção 1' e 'option2' são incompatíveis

As opções de linha de comando não podem ser especificadas juntos.

Verifique as variáveis de ambiente, como CL, especificações de opção.

**/CLR** implica **/EHa**, e não é possível especificar qualquer outro **/EH** opção do compilador com **/clr**. Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

Você pode obter D8016 depois de atualizar um projeto do Visual C++ 6.0: pode permitir que o processo do Assistente de atualização de projeto **/RTC** para cada arquivo de código fonte no projeto, que substitui o **/RTC** configuração para o projeto.  Para resolver, altere o **/RTC** definição para cada arquivo de código fonte no projeto para a configuração padrão, que significa que a configuração de projeto para **/RTC** entrará em vigor para cada arquivo.

Ver [/RTC (verificações de erro em tempo de execução)](../../build/reference/rtc-run-time-error-checks.md) para obter informações sobre como alterar a **/RTC** configuração da propriedade.