---
title: Marshaling
ms.date: 11/04/2016
helpviewer_keywords:
- marshaling, COM interop
- marshaling
- COM interfaces, marshaling
ms.assetid: 40644b0a-1106-4fc8-9dfb-9bee9915d825
ms.openlocfilehash: 0661a4cdde0a3a875cf27221e884f6c65b9fea55
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62262379"
---
# <a name="marshaling"></a>Marshaling

A técnica de COM de marshaling permite que as interfaces expostas por um objeto em um processo a ser usado em outro processo. No marshaling, COM fornece código (ou usa o código fornecido pelo implementador da interface) para o pacote de parâmetros de um método em um formato que pode ser movido entre processos (bem como, pela rede para processos em execução em outros computadores) e descompactar os parâmetros na outra extremidade. Da mesma forma, COM deve executar essas mesmas etapas do retorno da chamada.

> [!NOTE]
>  Marshaling normalmente não é necessário quando uma interface fornecida por um objeto que está sendo usada no mesmo processo que o objeto. No entanto, o empacotamento pode ser necessários entre threads.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[Detalhes de marshaling](/windows/desktop/com/marshaling-details)
