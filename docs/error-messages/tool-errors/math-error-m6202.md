---
title: Erro M6202 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- M6202
dev_langs:
- C++
helpviewer_keywords:
- M6202
ms.assetid: 4d17045f-c6dc-4705-9512-e9af12c35fb4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4596b9782bc1de0e6ccd52bfcd03965415adb353
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="math-error-m6202"></a>Erro M6202 (Math)
'function': erro de sing  
  
 Um argumento para a função fornecida era um valor de singularidade para esta função. A função não está definida para o argumento.  
  
 Esse erro chama o `_matherr` função com o tipo de erro, o nome da função e seus argumentos. Você pode reescrever o `_matherr` função para personalizar o tratamento de certos erros de matemática de ponto flutuante de tempo de execução.