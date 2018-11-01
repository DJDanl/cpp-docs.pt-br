---
title: Marshaling
ms.date: 11/04/2016
helpviewer_keywords:
- marshaling, COM interop
- marshaling
- COM interfaces, marshaling
ms.assetid: 40644b0a-1106-4fc8-9dfb-9bee9915d825
ms.openlocfilehash: a6129ba96cf3ac11339a8ab953e0838127f8fb3f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50569787"
---
# <a name="marshaling"></a>Marshaling

A técnica de COM de marshaling permite que as interfaces expostas por um objeto em um processo a ser usado em outro processo. No marshaling, COM fornece código (ou usa o código fornecido pelo implementador da interface) para o pacote de parâmetros de um método em um formato que pode ser movido entre processos (bem como, pela rede para processos em execução em outros computadores) e descompactar os parâmetros na outra extremidade. Da mesma forma, COM deve executar essas mesmas etapas do retorno da chamada.

> [!NOTE]
>  Marshaling normalmente não é necessário quando uma interface fornecida por um objeto que está sendo usada no mesmo processo que o objeto. No entanto, o empacotamento pode ser necessários entre threads.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[Detalhes de marshaling](/windows/desktop/com/marshaling-details)

