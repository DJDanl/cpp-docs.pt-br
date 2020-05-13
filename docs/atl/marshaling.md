---
title: Marshaling
ms.date: 11/04/2016
helpviewer_keywords:
- marshaling, COM interop
- marshaling
- COM interfaces, marshaling
ms.assetid: 40644b0a-1106-4fc8-9dfb-9bee9915d825
ms.openlocfilehash: 83cf29fb45347b7bfcfc1644546684f074061d25
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319347"
---
# <a name="marshaling"></a>Marshaling

A técnica COM de empacotamento permite que interfaces expostas por um objeto em um processo sejam usadas em outro processo. No marshaling, o COM fornece código (ou usa código fornecido pelo implementador de interface) tanto para embalar os parâmetros de um método em um formato que pode ser movido através de processos (bem como, através do fio para processos em execução em outras máquinas) e para desempacotar esses parâmetros na outra extremidade. Da mesma forma, o COM deve executar esses mesmos passos no retorno da chamada.

> [!NOTE]
> O marshaling normalmente não é necessário quando uma interface fornecida por um objeto está sendo usada no mesmo processo que o objeto. No entanto, o empacotamento pode ser necessário entre os fios.

## <a name="see-also"></a>Confira também

[Introdução ao COM](../atl/introduction-to-com.md)<br/>
[Detalhes de marshaling](/windows/win32/com/marshaling-details)
