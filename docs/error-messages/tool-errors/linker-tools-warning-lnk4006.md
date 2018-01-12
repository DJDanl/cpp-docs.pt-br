---
title: Aviso LNK4006 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4006
dev_langs: C++
helpviewer_keywords: LNK4006
ms.assetid: 3a637d17-1676-4ea6-bd8b-290137d28d3b
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 021961029d274172119ae92aa10cc6a236dd973b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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