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
ms.openlocfilehash: da411fbecdea0a1e7b8976ca119057204693a9bd
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46387855"
---
# <a name="exitinstance-member-function"></a>Função de membro ExitInstance

O [ExitInstance](../mfc/reference/cwinapp-class.md#exitinstance) função de membro da classe [CWinApp](../mfc/reference/cwinapp-class.md) é chamado sempre que uma cópia do seu aplicativo é encerrado, geralmente como resultado do encerramento do aplicativo de usuário.

Substituir `ExitInstance` se precisar de processamento de limpeza especial, como liberar recursos de interface (GDI) do dispositivo de gráficos ou desalocar a memória usada durante a execução do programa. Limpeza de itens padrão como documentos e exibições, no entanto, é fornecida pela estrutura, com outras funções substituíveis para fazer a limpeza especial específica a esses objetos.

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
