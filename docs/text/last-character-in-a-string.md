---
title: "Último caractere em uma cadeia de caracteres | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- last character in string
- MBCS [C++], last character in string
ms.assetid: 0a180376-4e55-41e8-9c64-539c7b6d8047
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7b766bec977f35f9f346723cbaf3f62e48c8c878
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="last-character-in-a-string"></a>Último caractere em uma cadeia de caracteres
Use as dicas a seguir:  
  
-   Intervalos de bytes de trilha sobreponham conjunto em muitos casos de caracteres ASCII. Exames bytewise podem ser usadas para caracteres de controle (menor que 32).  
  
-   Considere a seguinte linha de código, que pode verificar se o último caractere em uma cadeia de caracteres é um caractere de barra invertida:  
  
    ```  
    if ( sz[ strlen( sz ) - 1 ] == '\\' )    // Is last character a '\'?  
        // . . .  
    ```  
  
     Porque `strlen` não está ciente MBCS, ele retorna o número de bytes, não o número de caracteres, em uma cadeia de caracteres multibyte. Além disso, observe que, em algumas páginas (932, por exemplo), de código '\\' (0x5c) é um byte final válido (`sz` é uma cadeia de caracteres C).  
  
     É uma solução possível reescrever o código desta forma:  
  
    ```  
    char *pLast;  
    pLast = _mbsrchr( sz, '\\' );    // find last occurrence of '\' in sz  
    if ( pLast && ( *_mbsinc( pLast ) == '\0' ) )  
        // . . .  
    ```  
  
     Esse código usa as funções MBCS `_mbsrchr` e `_mbsinc`. Como essas funções são com reconhecimento de MBCS, eles podem distinguir entre um '\\'caractere e um byte final'\\'. O código executa alguma ação se o último caractere na cadeia de caracteres for um valor nulo ('\0').  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de programação MBCS](../text/mbcs-programming-tips.md)   
 [Atribuição de caractere](../text/character-assignment.md)