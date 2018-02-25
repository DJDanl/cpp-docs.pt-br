---
title: inline_depth | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- inline_depth_CPP
- vc-pragma.inline_depth
dev_langs:
- C++
helpviewer_keywords:
- pragmas, inline_depth
- inline_depth pragma
ms.assetid: 2bba60fe-43ea-4d09-90f7-aafaba3bad07
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a3738e1e2217de7e8617f91a36218718cf756ca3
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="inlinedepth"></a>inline_depth
Especifica a profundidade da pesquisa heurística embutida, de modo que nenhuma função seja embutida se estiver em uma profundidade (no grafo de chamadas) maior que `n`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma inline_depth( [n] )  
```  
  
## <a name="remarks"></a>Comentários  
 Esse pragma controla o inlining de funções assinaladas como [embutido](../cpp/inline-functions-cpp.md) e [inline](../cpp/inline-functions-cpp.md) ou embutida automaticamente na opção /Ob2.  
  
 `n` pode ser um valor entre 0 e 255, onde 255 significa profundidade ilimitada no gráfico de chamadas, e zero inibe a expansão da tabela embutida.  Quando `n` não é especificado, o padrão (254) é usado.  
  
 O **inline_depth** pragma controla o número de vezes que uma série de chamadas de função pode ser expandida. Por exemplo, se a profundidade embutida for quatro, e se A chamar B e B chamar C, as três chamadas serão embutidas expandidas. No entanto, se a expansão embutida mais próxima for dois, somente A e B serão expandidos, e C permanecerá como uma chamada de função.  
  
 Para usar esse pragma, você deve definir a opção do compilador /Ob para 1 ou 2. A profundidade definida com esse pragma entra em vigor na primeira chamada de função após o pragma.  
  
 A profundidade embutida pode ser diminuída durante a expansão, mas não pode ser aumentada. Se a profundidade de embutido é seis e durante a expansão do pré-processador encontra um **inline_depth** pragma com um valor de oito, a profundidade permanece seis.  
  
 O **inline_depth** pragma não tem nenhum efeito em funções marcado com `__forceinline`.  
  
> [!NOTE]
>  As funções recursivas podem ser substituídas embutidas até a profundidade máxima de 16 chamadas.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas pragma e a palavra-chave pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)   
 [inline_recursion](../preprocessor/inline-recursion.md)