---
title: Aviso LNK4006 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4006
dev_langs:
- C++
helpviewer_keywords:
- LNK4006
ms.assetid: 3a637d17-1676-4ea6-bd8b-290137d28d3b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 261d5dcc27c44291ddc6de4a6440cde040a84ed7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33302549"
---
# <a name="linker-tools-warning-lnk4006"></a>Aviso LNK4006 (Ferramentas de Vinculador)
símbolo já definido no objeto. segunda definição ignorada  
  
 O `symbol` determinado, exibido na sua forma decorada, foi definido por multiplicação. Quando este aviso for encontrado, `symbol` será adicionado duas vezes, mas apenas o primeiro formulário será usado.  
  
 Você pode obter este aviso se você tentar mesclar duas bibliotecas de importação em uma.  
  
 Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  O determinado `symbol` pode ser uma função empacotada, criada pela compilação com [/Gy](../../build/reference/gy-enable-function-level-linking.md). Este símbolo foi incluído em mais de um arquivo, mas foi alterado entre as compilações. Recompilar todos os arquivos que incluem o `symbol`.  
  
2.  O determinado `symbol` podem ter sido definidas diferentemente em dois objetos de membro em bibliotecas diferentes.  
  
3.  Um absoluto pode ter sido definido duas vezes, com um valor diferente de cada definição.  
  
4.  Se a mensagem de erro é recebida ao combinar bibliotecas, `symbol` já existe na biblioteca que está sendo adicionada ao.