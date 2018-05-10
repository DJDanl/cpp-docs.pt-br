---
title: Incrementando e decrementando ponteiros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- incrementing pointers
- MBCS [C++], pointers
- pointers [C++], multibyte characters
- decrementing pointers
ms.assetid: 0872b4a0-e2bd-4004-8319-070efb76f2fd
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 82a6f792ce622481cbbab821b8a5446186bd692d
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="incrementing-and-decrementing-pointers"></a>Incrementando e decrementando ponteiros
Use as dicas a seguir:  
  
-   Aponte para levar bytes, não trilha bytes. Não é normalmente seguro para ter um ponteiro para um byte final. É geralmente mais segura verificar se uma cadeia de caracteres para a frente, em vez de em ordem inversa.  
  
-   Há funções de incremento/decremento do ponteiro e macros disponíveis que se move sobre um caractere inteiro:  
  
    ```  
    sz1++;  
    ```  
  
     Torna-se:  
  
    ```  
    sz1 = _mbsinc( sz1 );  
    ```  
  
     O `_mbsinc` e `_mbsdec` funções corretamente incrementar e decrementar em `character` unidades, independentemente do tamanho de caractere.  
  
-   Diminui, é necessário um ponteiro para o início da cadeia de caracteres, como a seguir:  
  
    ```  
    sz2--;  
    ```  
  
     Torna-se:  
  
    ```  
    sz2 = _mbsdec( sz2Head, sz2 );  
    ```  
  
     Como alternativa, o ponteiro de cabeçalho pode ser um caractere válido na cadeia de caracteres, de forma que:  
  
    ```  
    sz2Head < sz2  
    ```  
  
     Você deve ter um ponteiro para um byte inicial válido conhecido.  
  
-   Talvez você queira manter um ponteiro para o caractere anterior para chamadas mais rápidos para `_mbsdec`.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de programação MBCS](../text/mbcs-programming-tips.md)   
 [Índices de byte](../text/byte-indices.md)