---
title: "Função de membro ExitInstance | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: []
dev_langs:
- C++
helpviewer_keywords:
- programs [MFC], terminating
- CWinApp class [MFC], ExitInstance
- ExitInstance method [MFC]
ms.assetid: 5bb597bd-8dab-4d49-8bcf-9c45aa8be4a2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 99898a5e80c3f487c7f53fe81d13d3d1eb55ebd5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exitinstance-member-function"></a>Função de membro ExitInstance
O [ExitInstance](../mfc/reference/cwinapp-class.md#exitinstance) função de membro de classe [CWinApp](../mfc/reference/cwinapp-class.md) é chamado sempre que uma cópia do seu aplicativo termina, geralmente como resultado do usuário fechar o aplicativo.  
  
 Substituir `ExitInstance` se precisar de processamento de limpeza especiais, como liberar recursos de interface (GDI) do dispositivo de gráficos ou desalocar memória usada durante a execução do programa. Limpeza de itens padrão, como documentos e exibições, no entanto, é fornecida pelo framework, com outras funções substituíveis para fazer a limpeza especial específica a esses objetos.  
  
## <a name="see-also"></a>Consulte também  
 [CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
