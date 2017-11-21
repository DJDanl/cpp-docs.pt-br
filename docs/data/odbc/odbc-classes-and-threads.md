---
title: Classes e Threads ODBC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ODBC classes, and threads
- ODBC, multithreaded applications
- threading [MFC], ODBC support
ms.assetid: 16543926-7331-41a6-ba50-72288f2a61b7
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: c71005e4cce6f62ca4dceb1c618f2ffd18b2bbab
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="odbc-classes-and-threads"></a>Classes e threads ODBC
A partir do MFC 4.2, há suporte multithread para as classes MFC ODBC. No entanto, observe que MFC não fornece suporte multithread para as classes DAO.  
  
 O suporte multithread para as classes ODBC tem algumas limitações. Porque essas classes encapsula a API de ODBC, eles são restritos para o suporte a multithreading dos componentes no qual eles são criados. Por exemplo, muitos drivers ODBC não são thread-safe; Portanto, as classes MFC ODBC não são thread-safe se você usá-los com um desses drivers. Você deve verificar se o seu driver específico é thread-safe.  
  
 Ao criar um aplicativo multithread, você deve ter muito cuidado ao usando vários threads para manipular o mesmo objeto. Por exemplo, usando a mesma `CRecordset` objeto em dois threads pode causar problemas ao recuperar dados, uma operação de busca em um thread pode substituir os dados buscados no thread de. É um uso mais comum de classes ODBC MFC em threads separados para compartilhar um aberto `CDatabase` objeto entre threads para usar a mesma conexão ODBC, com um separado `CRecordset` objeto em cada thread. Observe que você não deve transmitir um não aberta `CDatabase` o objeto para um `CRecordset` objeto em outro thread.  
  
> [!NOTE]
>  Se você deve ter vários threads manipular o mesmo objeto, você deve implementar os mecanismos de sincronização apropriado, como seções críticas. Esteja ciente que certas operações, como **abrir**, não estão protegidos. Você deve certificar-se de que essas operações não serão chamadas simultaneamente de threads separados.  
  
 Para obter mais informações sobre como criar aplicativos multithread, consulte [Multithreading tópicos](../../parallel/multithreading-support-for-older-code-visual-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Open Database Connectivity (ODBC)](../../data/odbc/open-database-connectivity-odbc.md)   
 [Acesso a dados (MFC/ATL) de programação](../../data/data-access-programming-mfc-atl.md)