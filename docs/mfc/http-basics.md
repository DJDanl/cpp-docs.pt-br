---
title: Noções básicas de HTTP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- HTTP [MFC], return codes
- return codes [MFC]
- HTTP requests [MFC], return codes
ms.assetid: 5b7421bf-42c8-4f3a-8566-8ff5957f58cc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 56a2692edd9d41f80023e44f4ca8172cba8f9d00
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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
  
 [http://www.w3.org/pub/WWW/Protocols/](http://www.w3.org/pub/www/protocols/)  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)

