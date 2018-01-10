---
title: Marshaling | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- marshaling, COM interop
- marshaling
- COM interfaces, marshaling
ms.assetid: 40644b0a-1106-4fc8-9dfb-9bee9915d825
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f89b64794c50e381c07749984ce61579951fa02f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="marshaling"></a>realização de marshaling
A técnica de COM de marshaling permite interfaces expostas por um objeto em um processo a ser usado em outro processo. Empacotamento, COM fornece código (ou usa o código fornecido pela implementação de interface) para o pacote de parâmetros do método em um formato que pode ser movido entre processos (bem como, pela conexão para processos em execução em outros computadores) e descompactar os parâmetros na outra extremidade. Da mesma forma, COM deve executar essas mesmas etapas no retorno de chamada.  
  
> [!NOTE]
>  Marshaling normalmente não é necessário quando uma interface fornecida por um objeto que está sendo usada no mesmo processo que o objeto. No entanto, o empacotamento pode ser necessário entre threads.  
  
## <a name="see-also"></a>Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [Detalhes de marshaling](http://msdn.microsoft.com/library/windows/desktop/ms692621)

