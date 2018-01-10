---
title: Caracteres largos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: wide characters
ms.assetid: 165c4a12-8ab9-45fb-9964-c55e9956194c
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ab885d5d807fe81b3058d533a70cdbaa9e3e523a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="wide-characters"></a>Caracteres largos
**ANSI 3.1.3.4** O valor de uma constante de caractere de inteiro que contém mais de um caractere ou uma constante de caractere largo que contém mais de um caractere multibyte  
  
 A constante de caractere comum, 'ab' tem o valor inteiro (int)0x6162. Quando houver mais de um byte, os bytes lidos anteriormente são deslocados para a esquerda pelo valor de **CHAR_BIT** e o próximo byte é comparado usando o operador bitwise-OR com baixos bits **CHAR_BIT**. O número de bytes na constante de caracteres multibyte não pode exceder sizeof(int), que é 4 para o código de 32 bits de destino.  
  
 A constante de caracteres multibyte é lida como acima e é convertida em uma constante de caractere largo usando a função de tempo de execução `mbtowc`. Se o resultado não for uma constante de caractere largo válida, um erro será emitido. Em todo caso, o número de bytes examinados pela função `mbtowc` é limitado ao valor de `MB_CUR_MAX`.  
  
## <a name="see-also"></a>Consulte também  
 [Caracteres](../c-language/characters.md)