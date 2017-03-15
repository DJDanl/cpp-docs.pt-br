---
title: Aviso LNK4006 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4006
dev_langs:
- C++
helpviewer_keywords:
- LNK4006
ms.assetid: 3a637d17-1676-4ea6-bd8b-290137d28d3b
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 43415e1e9cbfd26d47bb6812d469fa353ddee9ca
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4006"></a>Aviso LNK4006 (Ferramentas de Vinculador)
símbolo já definido no objeto; segunda definição ignorada  
  
 O `symbol` determinado, exibido na sua forma decorada, foi definido por multiplicação. Quando esse aviso é encontrado, `symbol` será adicionado duas vezes, mas somente o primeiro formulário será usado.  
  
 Você pode obter esse aviso se você tentar mesclar duas bibliotecas de importação em um.  
  
 Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir, usando as seguintes soluções possíveis  
  
1.  O determinado `symbol` pode ser uma função compactada, criada compilando com [/Gy](../../build/reference/gy-enable-function-level-linking.md). Esse símbolo foi incluído em mais de um arquivo, mas foi alterado entre compilações. Recompilar todos os arquivos que incluem o `symbol`.  
  
2.  O determinado `symbol` definidas diferentemente em dois objetos de membro em bibliotecas diferentes.  
  
3.  Um absoluto definido duas vezes, com um valor diferente em cada definição.  
  
4.  Se a mensagem de erro é recebida ao combinar bibliotecas, `symbol` já existe na biblioteca que está sendo adicionada ao.
