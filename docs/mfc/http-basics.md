---
title: "Noções básicas de HTTP | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- HTTP [MFC], return codes
- return codes [MFC]
- HTTP requests [MFC], return codes
ms.assetid: 5b7421bf-42c8-4f3a-8566-8ff5957f58cc
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 67921e0667267b99b3787d55fa7ff564aa543ae7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="http-basics"></a>Noções básicas de HTTP
Ao escrever um aplicativo de internet, você geralmente examina e adicionar as informações no cabeçalho HTTP. Códigos de retorno indicam o êxito ou falha do evento solicitado. Vários códigos de retorno comuns estão listados na tabela a seguir.  
  
|Código de retorno|Significado|  
|-----------------|-------------|  
|200|URL localizado, a maneira de transmissão|  
|400|Solicitação ininteligível|  
|404|Solicitou a URL não encontrado|  
|405|Servidor não suporta o método solicitado|  
|500|Erro de servidor desconhecido|  
|503|Serviço indisponível|  
  
 As respostas HTTP são agrupadas, conforme mostrado na tabela a seguir.  
  
|Grupo|Significado|  
|-----------|-------------|  
|200-299|Êxito|  
|300-399|Informações|  
|400-499|Erro de solicitação|  
|500-599|Erro de servidor|  
  
 O protocolo HTTP (Hypertext Transfer) é um protocolo de nível de aplicativo para sistemas de informação de hipermídia. Para obter mais informações sobre HTTP e como os servidores e navegadores da Web se comunicam, consulte a especificação do protocolo HTTP (Hypertext Transfer):  
  
 [http://www.w3.org/pub/www/Protocols/](http://www.w3.org/pub/www/protocols/)  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)

