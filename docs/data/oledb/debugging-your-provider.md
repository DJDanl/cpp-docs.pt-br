---
title: Depurando o provedor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- debugging [C++], providers
- OLE DB providers, debugging
- Visual C++ debugger, debugging providers
- Visual C++ debugger
ms.assetid: 90d4e7db-06ea-4de0-a7f4-4f3751d50d93
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6cfcb90daaf23a5fd8e248d43b920340e38d8057
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="debugging-your-provider"></a>Depurando o provedor
Há duas maneiras para depurar seu provedor:  
  
-   Como provedores são criados no processo, você pode criar um código de consumidor usando os modelos de consumidor OLE DB e a etapa no provedor normalmente.  
  
-   Você pode usar o utilitário ITEST que vem com o Visual C++.  
  
### <a name="to-use-the-itest-utility"></a>Usar o utilitário ITEST  
  
1.  Abra o projeto de provedor.  
  
2.  Sobre o **projetos** menu, clique em **configurações**.  
  
3.  No **páginas de propriedade** caixa de diálogo, clique o **depurar** guia.  
  
4.  No **executável para sessão de depuração** , selecione o aplicativo ITEST.  
  
5.  Definir pontos de interrupção e, em seguida, depuração normalmente.  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)