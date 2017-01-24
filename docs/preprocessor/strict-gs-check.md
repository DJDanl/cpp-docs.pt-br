---
title: "strict_gs_check | Microsoft Docs"
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
  - "strict_gs_check"
  - "strict_gs_check_CPP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "strict_gs_check (pragma)"
ms.assetid: decfec81-c916-42e0-a07f-8cc26df6a7ce
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strict_gs_check
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este pragma fornece verificação de segurança aprimorada.  
  
## Sintaxe  
  
```  
#pragma strict_gs_check([push,] on )   
#pragma strict_gs_check([push,] off )   
#pragma strict_gs_check(pop)  
```  
  
## Comentários  
 Ele instrui o compilador a inserir um cookie aleatório na pilha de função para ajudar a detectar algumas categorias de saturação de buffer baseada em fila.  Por padrão, a opção \/GS \(verificação de segurança do buffer\) do compilador não insere um cookie para todas as funções.  Para obter mais informações, consulte [\/GS \(verificação de segurança do buffer\)](../Topic/-GS%20\(Buffer%20Security%20Check\).md).  
  
 Você deve compilar com \/GS \(verificação de segurança do buffer\) para habilitar strict\_gs\_check.  
  
 Use este pragma em módulos de código que são expostos a dados potencialmente nocivos.  Este pragma é muito agressivo. Ele é aplicado às funções que podem não precisar dessa defesa, mas é otimizado para minimizar seu efeito no desempenho do aplicativo resultante.  
  
 Mesmo ao usar esse pragma, o ideal é escrever um código seguro.  Ou seja, certifique\-se de que seu código não tem saturações de buffer. O strict\_gs\_check pode proteger seu aplicativo de saturações de buffer remanescentes em seu código.  
  
## Exemplo  
 No código a seguir, uma saturação de buffer ocorre quando copiamos uma matriz para uma matriz local.  Quando você cria este código com \/GS, nenhum cookie é inserido na pilha, pois o tipo de dados da matriz é um ponteiro.  A adição do pragma strict\_gs\_check força o cookie da pilha na pilha da função.  
  
```cpp  
// pragma_strict_gs_check.cpp  
// compile with: /c  
  
#pragma strict_gs_check(on)  
  
void ** ReverseArray(void **pData,  
                     size_t cData)  
{  
    // *** This buffer is subject to being overrun!! ***  
    void *pReversed[20];  
  
    // Reverse the array into a temporary buffer  
    for (size_t j = 0, i = cData; i ; --i, ++j)  
        // *** Possible buffer overrun!! ***  
            pReversed[j] = pData[i];   
  
    // Copy temporary buffer back into input/output buffer  
    for (size_t i = 0; i < cData ; ++i)   
        pData[i] = pReversed[i];  
  
    return pData;  
}  
  
```  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)   
 [\/GS \(verificação de segurança do buffer\)](../Topic/-GS%20\(Buffer%20Security%20Check\).md)