---
title: strict_gs_check | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- strict_gs_check
- strict_gs_check_CPP
dev_langs:
- C++
helpviewer_keywords:
- strict_gs_check pragma
ms.assetid: decfec81-c916-42e0-a07f-8cc26df6a7ce
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6b58b02781f266b24fa321b3849f42b2e090b860
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="strictgscheck"></a>strict_gs_check
Este pragma fornece verificação de segurança aprimorada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma strict_gs_check([push,] on )   
#pragma strict_gs_check([push,] off )   
#pragma strict_gs_check(pop)  
```  
  
## <a name="remarks"></a>Comentários  
 Ele instrui o compilador a inserir um cookie aleatório na pilha de função para ajudar a detectar algumas categorias de saturação de buffer baseada em fila. Por padrão, a opção /GS (verificação de segurança do buffer) do compilador não insere um cookie para todas as funções. Para obter mais informações, consulte [/GS (verificação de segurança do buffer)](../build/reference/gs-buffer-security-check.md).  
  
 Você deve compilar com /GS (verificação de segurança do buffer) para habilitar strict_gs_check.  
  
 Use este pragma em módulos de código que são expostos a dados potencialmente nocivos. Este pragma é muito agressivo. Ele é aplicado às funções que podem não precisar dessa defesa, mas é otimizado para minimizar seu efeito no desempenho do aplicativo resultante.  
  
 Mesmo ao usar esse pragma, o ideal é escrever um código seguro. Ou seja, certifique-se de que seu código não tenha nenhum saturações de buffer. strict_gs_check pode proteger seu aplicativo contra saturações de buffer que permanecem em seu código.  
  
## <a name="example"></a>Exemplo  
 No código a seguir, uma saturação de buffer ocorre quando copiamos uma matriz para uma matriz local. Quando você cria este código com /GS, nenhum cookie é inserido na pilha, pois o tipo de dados da matriz é um ponteiro. A adição do pragma strict_gs_check força o cookie da pilha na pilha da função.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Diretivas pragma e a palavra-chave pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)   
 [/GS (verificação de segurança do buffer)](../build/reference/gs-buffer-security-check.md)