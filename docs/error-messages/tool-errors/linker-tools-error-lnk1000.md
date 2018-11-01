---
title: Erro das Ferramentas de Vinculador LNK1000
ms.date: 06/18/2018
f1_keywords:
- LNK1000
helpviewer_keywords:
- LNK1000
ms.assetid: 86421b9a-460a-4285-8dce-9b8257d78122
ms.openlocfilehash: 8e53dc898addb4adeec63027c358b42a6a836b50
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50501719"
---
# <a name="linker-tools-error-lnk1000"></a>Erro das Ferramentas de Vinculador LNK1000

> Erro desconhecido; Consulte a documentação para opções de suporte técnico

Observe as circunstâncias do erro e, em seguida, tentar isolar o problema e criar um caso de teste pode ser reproduzido. Para obter informações sobre como investigar e relatar esses erros, consulte [como relatar um problema com o conjunto de ferramentas do Visual C++ ou documentação](../../how-to-report-a-problem-with-the-visual-cpp-toolset.md).

Você pode obter esse erro se você mesclar arquivos de cabeçalho padrão (por exemplo, Windows. h) e seus próprios arquivos. Inclua um cabeçalho pré-compilado, se qualquer um, primeiro, em seguida, os cabeçalhos padrão, seguido por seus próprios arquivos de cabeçalho.