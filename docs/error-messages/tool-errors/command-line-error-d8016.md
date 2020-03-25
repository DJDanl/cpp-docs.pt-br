---
title: Erro D8016 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D8016
helpviewer_keywords:
- D8016
ms.assetid: eec51312-7471-4f92-94b2-d517cafc8ef5
ms.openlocfilehash: 1bdef16b14488be86aff880db7c049f4bcddcdb5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196957"
---
# <a name="command-line-error-d8016"></a>Erro D8016 (linha de comando)

as opções de linha de comando ' opção 1 ' e ' opção 2 ' são incompatíveis

As opções de linha de comando não podem ser especificadas juntas.

Verifique as variáveis de ambiente, como CL, para obter as especificações de opção.

o **/CLR** implica **/EHA**e você não pode especificar nenhuma outra opção de compilador **/eh** com **/CLR**. Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

Você pode obter D8016 depois de atualizar um C++ projeto do Visual 6,0: o processo do assistente de atualização de projeto pode habilitar o **/RTC** para cada arquivo de código-fonte no projeto, que substitui a configuração **/RTC** do projeto.  Para resolver, altere a configuração **/RTC** para cada arquivo de código-fonte no projeto para a configuração padrão, o que significa que a configuração do projeto para **/RTC** estará em vigor para cada arquivo.

Consulte [/RTC (verificações de erro em tempo de execução)](../../build/reference/rtc-run-time-error-checks.md) para obter informações sobre como alterar a configuração da propriedade **/RTC** .
