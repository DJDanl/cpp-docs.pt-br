---
title: "Função CAtlServiceModuleT::Handler | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CServiceModule::Handler
- CServiceModule.Handler
- Handler
dev_langs: C++
helpviewer_keywords: Handler method
ms.assetid: 14db5f2a-be87-4774-a296-445cb6fc7b2e
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9f8c83db3f7834c79656adc3443fd3c8946a4176
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="catlservicemodulethandler-function"></a>Função CAtlServiceModuleT::Handler
`CAtlServiceModuleT::Handler`é a rotina que chama o Gerenciador de controle de serviços (SCM) para recuperar o status do serviço e dê a ele várias instruções (por exemplo, parar ou pausar). O SCM passa um código de operação para `Handler` para indicar que o serviço deve fazer. Um serviço do padrão gerado ATL só trata a instrução stop. Se o SCM passa a instrução stop, o serviço informa o SCM que o programa está prestes a parar. Em seguida, chama o serviço `PostThreadMessage` para postar uma mensagem de saída para si mesmo. Isso encerra o loop de mensagem e o serviço, por fim, será fechado.  
  
 Para lidar com mais instruções, você precisa alterar o `m_status` membro de dados inicializado no `CAtlServiceModuleT` construtor. Este membro de dados informa o SCM quais botões devem habilitar quando o serviço é selecionado no aplicativo do painel de controle de serviços.  
  
## <a name="see-also"></a>Consulte também  
 [Serviços](../atl/atl-services.md)   
 [CAtlServiceModuleT::Handler](../atl/reference/catlservicemodulet-class.md#handler)

