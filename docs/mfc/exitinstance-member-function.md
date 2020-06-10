---
title: Função de membro ExitInstance
ms.date: 11/04/2016
f1_keywords: []
helpviewer_keywords:
- programs [MFC], terminating
- CWinApp class [MFC], ExitInstance
- ExitInstance method [MFC]
ms.assetid: 5bb597bd-8dab-4d49-8bcf-9c45aa8be4a2
ms.openlocfilehash: 58546d26293ad48a39a36b98ba4bfdabb68385ee
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622692"
---
# <a name="exitinstance-member-function"></a>Função de membro ExitInstance

A função membro [ExitInstance](reference/cwinapp-class.md#exitinstance) da classe [CWinApp](reference/cwinapp-class.md) é chamada cada vez que uma cópia do seu aplicativo é encerrada, geralmente como resultado do encerramento do aplicativo pelo usuário.

Substitua `ExitInstance` se você precisar de processamento de limpeza especial, como a liberação de recursos de interface gráfica de dispositivo (GDI) ou desalocar a memória usada durante a execução do programa. A limpeza de itens padrão, como documentos e exibições, no entanto, é fornecida pela estrutura, com outras funções substituíveis para fazer uma limpeza especial específica para esses objetos.

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](cwinapp-the-application-class.md)
