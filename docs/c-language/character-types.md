---
title: Tipos de caractere | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- character data types [C]
- types [C], character
ms.assetid: d3ca8cda-c0d7-43af-9472-697e8ef015ce
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a48382f5f7a3ab64518c44ec953005cd54a4fe03
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="character-types"></a>Tipos de caractere
Uma constante de caractere inteiro não precedida pela letra **L** tem o tipo `int`. O valor de uma constante de caractere inteiro que contém um único caractere é o valor numérico do caractere interpretado como um inteiro. Por exemplo, o valor numérico do caractere `a` é 97 em decimal e 61 em hexadecimal.  
  
 Sintaticamente, “uma constante de caractere largo” é uma constante de caractere com a letra **L** de prefixo. Uma constante de caractere largo tem o tipo `wchar_t`, um tipo de inteiro definido no arquivo de cabeçalho STDDEF.H. Por exemplo:  
  
```  
char    schar =  'x';   /* A character constant          */  
wchar_t wchar = L'x';   /* A wide-character constant for   
                            the same character           */  
```  
  
 As constantes de caractere largo têm 16 bits de largura e especificam membros do conjunto estendido de caracteres de execução. Elas permitem que você expresse caracteres em alfabetos que são muito grandes para serem representados pelo tipo `char`. Consulte [Multibyte e caracteres largos](../c-language/multibyte-and-wide-characters.md) para obter mais informações sobre os caracteres largos.  
  
## <a name="see-also"></a>Consulte também  
 [Constantes de caractere C](../c-language/c-character-constants.md)