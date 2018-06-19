---
title: Último caractere em uma cadeia de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- last character in string
- MBCS [C++], last character in string
ms.assetid: 0a180376-4e55-41e8-9c64-539c7b6d8047
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 88cde1d2eb30103462f7ae8f8c06274a2977fc36
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33855637"
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