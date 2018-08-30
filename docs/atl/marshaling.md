---
title: Marshaling | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- marshaling, COM interop
- marshaling
- COM interfaces, marshaling
ms.assetid: 40644b0a-1106-4fc8-9dfb-9bee9915d825
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ac4bb35d29d74f0e66337dc6c3999df66a63d254
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43212685"
---
# <a name="marshaling"></a>Marshaling
A técnica de COM de marshaling permite que as interfaces expostas por um objeto em um processo a ser usado em outro processo. No marshaling, COM fornece código (ou usa o código fornecido pelo implementador da interface) para o pacote de parâmetros de um método em um formato que pode ser movido entre processos (bem como, pela rede para processos em execução em outros computadores) e descompactar os parâmetros na outra extremidade. Da mesma forma, COM deve executar essas mesmas etapas do retorno da chamada.  
  
> [!NOTE]
>  Marshaling normalmente não é necessário quando uma interface fornecida por um objeto que está sendo usada no mesmo processo que o objeto. No entanto, o empacotamento pode ser necessários entre threads.  
  
## <a name="see-also"></a>Consulte também  
 [Introdução a COM](../atl/introduction-to-com.md)   
 [Detalhes de marshaling](/windows/desktop/com/marshaling-details)

