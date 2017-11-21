---
title: Tecnologia ativa e DLLs | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- in-process server DLLs
- Automation [C++], DLLs
- DLLs [C++], Active Technology
- Active technology [C++]
- MFC DLLs [C++], Active Technology
ms.assetid: 3ed27f8d-164a-4562-ad61-9f2333404cc7
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: fb97e43f589718f79f64483593cfea870258d9f8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="active-technology-and-dlls"></a>Tecnologia ativa e DLLs
Tecnologia ativa permite que os servidores de objeto a ser implementada completamente dentro de uma DLL. Esse tipo de servidor é chamado de um servidor em processo. MFC não suporta completamente servidores em processo para todos os recursos de edição visual, principalmente porque tecnologia ativa não fornecem uma maneira para um servidor para conectar-se em um loop de mensagem principal do contêiner. MFC requer acesso ao loop de mensagens do aplicativo de contêiner para lidar com processamento de tempo ocioso e teclas de aceleração.  
  
 Se você estiver escrevendo um servidor de automação e o servidor não tem nenhuma interface do usuário, você pode fazer o servidor de um servidor em processo e colocá-lo completamente em uma DLL.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Servidores de automação](../mfc/automation-servers.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)