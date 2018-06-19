---
title: NMAKE Erro Fatal U1095 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1095
dev_langs:
- C++
helpviewer_keywords:
- U1095
ms.assetid: a392582b-06db-4568-9c13-450293a4fbda
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 13c819d18149e61bca71f6a4cb10ea851a2d485d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33317239"
---
# <a name="nmake-fatal-error-u1095"></a>Erro fatal U1095 (NMAKE)
linha de comando expandida 'commandline' muito longo  
  
 Após a expansão de macro, a linha de comando fornecida excedeu o limite no tamanho das linhas de comando para o sistema operacional.  
  
 MS-DOS permite até 128 caracteres em uma linha de comando.  
  
 Se o comando é um programa que pode aceitar a entrada de linha de comando de um arquivo, altere o comando e forneça a entrada de um arquivo em disco ou um arquivo embutido. Por exemplo, o LINK e LIB aceitar entrada de um arquivo de resposta.