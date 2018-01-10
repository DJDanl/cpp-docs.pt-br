---
title: NMAKE Erro Fatal U1095 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: U1095
dev_langs: C++
helpviewer_keywords: U1095
ms.assetid: a392582b-06db-4568-9c13-450293a4fbda
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 81d93635c50b304a5a2df027691470093d23bdbd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-fatal-error-u1095"></a>Erro fatal U1095 (NMAKE)
linha de comando expandida 'commandline' muito longo  
  
 Após a expansão de macro, a linha de comando fornecida excedeu o limite no tamanho das linhas de comando para o sistema operacional.  
  
 MS-DOS permite até 128 caracteres em uma linha de comando.  
  
 Se o comando é um programa que pode aceitar a entrada de linha de comando de um arquivo, altere o comando e forneça a entrada de um arquivo em disco ou um arquivo embutido. Por exemplo, o LINK e LIB aceitar entrada de um arquivo de resposta.