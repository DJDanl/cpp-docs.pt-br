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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f4fff5d7ec20ce052e4d831f1556432186ebc7bb
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42603354"
---
# <a name="incrementing-and-decrementing-pointers"></a>Incrementando e decrementando ponteiros
Use as dicas a seguir:  
  
-   Aponte para o cliente potencial bytes, não rastros bytes. Não é normalmente seguro para ter um ponteiro para um byte final. É geralmente mais segura verificar uma cadeia de caracteres para frente em vez de em ordem inversa.  
  
-   Há funções de aumentar/diminuir de ponteiro e macros disponíveis que se movem sobre um caractere de inteiro:  
  
    ```  
    sz1++;  
    ```  
  
     se torna:  
  
    ```  
    sz1 = _mbsinc( sz1 );  
    ```  
  
     O `_mbsinc` e `_mbsdec` funções corretamente incremento e decréscimo em `character` unidades, independentemente do tamanho do caractere.  
  
-   Para diminui, você precisa de um ponteiro para o início da cadeia de caracteres, da seguinte maneira:  
  
    ```  
    sz2--;  
    ```  
  
     se torna:  
  
    ```  
    sz2 = _mbsdec( sz2Head, sz2 );  
    ```  
  
     Como alternativa, o ponteiro de cabeçalho pode ser um caractere válido na cadeia de caracteres, que:  
  
    ```  
    sz2Head < sz2  
    ```  
  
     Você deve ter um ponteiro para um byte inicial válido conhecido.  
  
-   Você talvez queira manter um ponteiro para o caractere anterior para chamadas mais rápidas para `_mbsdec`.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de programação MBCS](../text/mbcs-programming-tips.md)   
 [Índices de byte](../text/byte-indices.md)