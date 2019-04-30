---
title: Erro D8016 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D8016
helpviewer_keywords:
- D8016
ms.assetid: eec51312-7471-4f92-94b2-d517cafc8ef5
ms.openlocfilehash: c1e2e3e28f8556416f58d68f8ef1df4b220bc54c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399961"
---
# <a name="command-line-error-d8016"></a>Erro D8016 (linha de comando)

Opções de linha de comando de 'opção 1' e 'option2' são incompatíveis

As opções de linha de comando não podem ser especificadas juntos.

Verifique as variáveis de ambiente, como CL, especificações de opção.

**/CLR** implica **/EHa**, e não é possível especificar qualquer outro **/EH** opção do compilador com **/clr**. Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

Você pode obter D8016 depois de atualizar um projeto do Visual C++ 6.0: pode permitir que o processo do Assistente de atualização de projeto **/RTC** para cada arquivo de código fonte no projeto, que substitui o **/RTC** configuração para o projeto.  Para resolver, altere o **/RTC** definição para cada arquivo de código fonte no projeto para a configuração padrão, que significa que a configuração de projeto para **/RTC** entrará em vigor para cada arquivo.

Ver [/RTC (verificações de erro em tempo de execução)](../../build/reference/rtc-run-time-error-checks.md) para obter informações sobre como alterar a **/RTC** configuração da propriedade.