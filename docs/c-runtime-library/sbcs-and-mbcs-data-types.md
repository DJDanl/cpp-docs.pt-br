---
title: Tipos de dados SBCS e MBCS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- MBCS
- SBCS
dev_langs:
- C++
helpviewer_keywords:
- SBCS and MBCS data types
- data types [C], MBCS and SBCS
ms.assetid: 4c3ef9da-e397-48d4-800e-49dba36db171
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 431f89c26a36fdcc723588ba317979bcd39c7521

---
# <a name="sbcs-and-mbcs-data-types"></a>Tipos de dados SBCS e MBCS
Qualquer rotina de biblioteca em tempo de execução `MBCS` da Microsoft que manipula apenas um caractere multibyte ou um byte de um caractere multibyte espera um argumento `unsigned``int` (em que 0x00 <= valor de caractere <= 0xFFFF e 0x00 <= valor de byte <= 0xFF ). Uma rotina `MBCS` que lida com caracteres em um contexto de cadeia de caracteres ou bytes multibyte espera que uma cadeia de caracteres multibyte seja representada como um ponteiro `unsigned``char`.  
  
> [!CAUTION]
>  Cada byte de um caractere multibyte pode ser representado em um `char` de 8 bits. No entanto, um caractere de byte único `SBCS` ou `MBCS` do tipo `char` com um valor maior que 0x7F é negativo. Quando esse caractere é convertido diretamente para um `int` ou `long`, o resultado é estendido com sinal pelo compilador e, portanto, pode gerar resultados inesperados.  
  
 Portanto, é melhor representar um byte de um caractere multibyte como um `unsigned char` de 8 bits. Ou, para evitar um resultado negativo, simplesmente converter um caractere de byte único do tipo `char` em um `unsigned char` antes de convertê-lo em um `int` ou um `long`.  
  
 Devido a algumas funções de manipulação de cadeia de caracteres `SBCS` aceitarem parâmetros `char*` (assinados), definir `_MBCS` resultará em um aviso do compilador sobre tipos incompatíveis. Há três maneiras de evitar esse aviso, listados em ordem de eficiência:  
  
1.  Use as funções embutidas "fortemente tipadas" em TCHAR.H. Este é o comportamento padrão.  
  
2.  Use as macros "diretas" em TCHAR.H definindo `_MB_MAP_DIRECT` na linha de comando. Se você fizer isso, você deverá realizar a correspondência de tipos manualmente. Esse é o método mais rápido, mas não é fortemente tipado.  
  
3.  Use as funções de biblioteca vinculada estaticamente "fortemente tipados" em TCHAR.H. Para fazer isso, defina a constante `_NO_INLINING` na linha de comando. Esse é o método mais lento, no entanto, é o mais fortemente tipado.  
  
## <a name="see-also"></a>Consulte também  
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)


<!--HONumber=Feb17_HO4-->


