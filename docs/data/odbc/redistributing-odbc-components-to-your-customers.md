---
title: Redistribuindo componentes ODBC para seus clientes | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ODBC components, redistributing
- ODBC, distributing components
- components [C++], distributing
- ODBC Administrator
- components [C++]
- components [C++], redistributing
ms.assetid: 17b065b4-a307-4b89-99ac-d05831cfab87
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: aad9f1dbd4542ad763e7303d9a750f1856208025
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="redistributing-odbc-components-to-your-customers"></a>Redistribuindo componentes ODBC para os clientes
Se você incorporar a funcionalidade dos programas administrador ODBC em seu aplicativo, você também deve distribuir para seus usuários os arquivos que executam esses programas. Esses arquivos ODBC residem no diretório \OS\System do CD-ROM do Visual C++. O contrato de licença no mesmo diretório e o arquivo Redistrb.wri contém uma lista de arquivos ODBC que você pode redistribuir.  
  
 Consulte a documentação para drivers ODBC que você pretende fornecer. Você precisa determinar quais DLLs e outros arquivos para enviar. Você também deve ler [redistribuindo componentes ODBC para seus clientes](../../data/odbc/redistributing-odbc-components-to-your-customers.md), que explica como redistribuir componentes ODBC.  
  
 Além disso, você precisa incluir um arquivo de outros na maioria dos casos. O Odbccr32.dll é a biblioteca de cursores ODBC. Essa biblioteca fornece a capacidade de rolagem para frente e para trás de drivers de nível 1. Ele também fornece a capacidade de dar suporte a instantâneos. Para obter mais informações sobre a biblioteca de cursores ODBC, consulte [ODBC: A biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).  
  
 Os tópicos a seguir fornecem mais informações sobre como usar o ODBC com as classes de banco de dados:  
  
-   [ODBC: a biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md)  
  
-   [ODBC: configurando uma fonte de dados ODBC](../../data/odbc/odbc-configuring-an-odbc-data-source.md)  
  
-   [ODBC: chamando funções de API ODBC diretamente](../../data/odbc/odbc-calling-odbc-api-functions-directly.md)  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)   
 [Administrador do ODBC](../../data/odbc/odbc-administrator.md)