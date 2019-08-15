---
title: Marshaling
ms.date: 11/04/2016
helpviewer_keywords:
- marshaling, COM interop
- marshaling
- COM interfaces, marshaling
ms.assetid: 40644b0a-1106-4fc8-9dfb-9bee9915d825
ms.openlocfilehash: 9963e261f26daa57cb58e30ffc404b431d781bfa
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492040"
---
# <a name="marshaling"></a>Marshaling

A técnica COM de marshaling permite que as interfaces expostas por um objeto em um processo sejam usadas em outro processo. No marshaling, COM fornece código (ou usa código fornecido pelo implementador de interface) para empacotar os parâmetros de um método em um formato que pode ser movido entre processos (bem como, na conexão com os processos em execução em outros computadores) e para desempacotar esses parâmetros na outra extremidade. Da mesma forma, COM deve executar essas mesmas etapas no retorno da chamada.

> [!NOTE]
>  O marshaling normalmente não é necessário quando uma interface fornecida por um objeto está sendo usada no mesmo processo que o objeto. No entanto, o marshaling pode ser necessário entre os threads.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[Detalhes de marshaling](/windows/win32/com/marshaling-details)
