---
title: "inline_depth | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "inline_depth_CPP"
  - "vc-pragma.inline_depth"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "inline_depth (pragma)"
  - "pragmas, inline_depth"
ms.assetid: 2bba60fe-43ea-4d09-90f7-aafaba3bad07
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# inline_depth
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica a profundidade da pesquisa heurística embutida, de modo que nenhuma função seja embutida se estiver em uma profundidade \(no gráfico de chamadas\) maior que `n`.  
  
## Sintaxe  
  
```  
  
#pragma inline_depth( [n] )  
```  
  
## Comentários  
 Este pragma controla o processo de embutir das funções marcadas com [inline](../misc/inline-inline-forceinline.md) e [\_\_inline](../misc/inline-inline-forceinline.md) ou embutidas automaticamente sob a opção \/Ob2.  
  
 `n` pode ser um valor entre 0 e 255, onde 255 significa profundidade ilimitada no gráfico de chamadas, e zero inibe a expansão da tabela embutida.  Quando `n` não é especificado, o padrão \(254\) é usado.  
  
 O pragma **inline\_depth** controla o número de vezes que uma série das chamadas de função pode ser expandida.  Por exemplo, se a profundidade embutida for quatro, e se A chamar B e B chamar C, as três chamadas serão embutidas expandidas.  No entanto, se a expansão embutida mais próxima for dois, somente A e B serão expandidos, e C permanecerá como uma chamada de função.  
  
 Para usar esse pragma, você deve definir a opção do compilador \/Ob para 1 ou 2.  A profundidade definida com esse pragma entra em vigor na primeira chamada de função após o pragma.  
  
 A profundidade embutida pode ser diminuída durante a expansão, mas não pode ser aumentada.  Se a profundidade embutida for seis e, durante a expansão, o pré\-processador encontrar um pragma **inline\_depth** com um valor de oito, a profundidade permanecerá seis.  
  
 O pragma **inline\_depth** não tem nenhum efeito em funções marcadas com `__forceinline`.  
  
> [!NOTE]
>  As funções recursivas podem ser substituídas embutidas até a profundidade máxima de 16 chamadas.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)   
 [inline\_recursion](../preprocessor/inline-recursion.md)