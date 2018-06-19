---
title: Função de membro ExitInstance | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords: []
dev_langs:
- C++
helpviewer_keywords:
- programs [MFC], terminating
- CWinApp class [MFC], ExitInstance
- ExitInstance method [MFC]
ms.assetid: 5bb597bd-8dab-4d49-8bcf-9c45aa8be4a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 954d2248061ec571d9d2ba8804c1f7c97275cbfc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33343493"
---
# <a name="exitinstance-member-function"></a>Função de membro ExitInstance
O [ExitInstance](../mfc/reference/cwinapp-class.md#exitinstance) função de membro de classe [CWinApp](../mfc/reference/cwinapp-class.md) é chamado sempre que uma cópia do seu aplicativo termina, geralmente como resultado do usuário fechar o aplicativo.  
  
 Substituir `ExitInstance` se precisar de processamento de limpeza especiais, como liberar recursos de interface (GDI) do dispositivo de gráficos ou desalocar memória usada durante a execução do programa. Limpeza de itens padrão, como documentos e exibições, no entanto, é fornecida pelo framework, com outras funções substituíveis para fazer a limpeza especial específica a esses objetos.  
  
## <a name="see-also"></a>Consulte também  
 [CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
