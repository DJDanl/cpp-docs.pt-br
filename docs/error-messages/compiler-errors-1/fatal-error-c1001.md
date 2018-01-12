---
title: Erro fatal C1001 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C1001
dev_langs: C++
helpviewer_keywords: C1001
ms.assetid: 5736cdb3-22c8-4fad-aa85-d5e0d2b232f4
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4a72a99e566474145857e265edde548ebf38e180
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1001"></a>Erro fatal C1001

> INTERNO COMPILADOR ERROR(compiler file *file*, line *number*)  
  
O compilador não pode gerar o código correto para uma construção, geralmente devido à combinação de uma determinada expressão e uma opção de otimização ou um problema na análise. Se o arquivo de compilador listado tem um utc ou segmento de caminho de C2, provavelmente é um erro de otimização. Se o arquivo tem um segmento de caminho cxxfe ou c1xx ou é msc1.cpp, provavelmente é um erro do analisador. Se o arquivo denominado cl.exe, nenhuma outra informação está disponível.  

Geralmente, você pode corrigir um problema de otimização, removendo uma ou mais opções de otimização. Para determinar qual opção está com defeito, remova uma opção em uma hora e recompile até que a mensagem de erro desaparecerá. As opções mais comumente responsáveis são [/Og (otimizações globais)](../../build/reference/og-global-optimizations.md) e [/Oi (gerar funções intrínsecas)](../../build/reference/oi-generate-intrinsic-functions.md). Depois de determinar qual opção de otimização é responsável, você pode desabilitá-lo em torno de função em que o erro ocorre usando o [otimizar](../../preprocessor/optimize.md) pragma e continuar a usar a opção para o restante do módulo. Para obter mais informações sobre as opções de otimização, consulte [práticas recomendadas de otimização](../../build/reference/optimization-best-practices.md).

Se otimizações não estão responsáveis pelo erro, tente reescrever a linha onde o erro é relatado ou várias linhas de código ao redor dessa linha. Para ver o código a maneira que o compilador vê-lo depois de pré-processamento, você pode usar o [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md) opção.

Para obter mais informações sobre como identificar a origem do erro e como relatar um erro interno do compilador para a Microsoft, consulte [como relatar um problema com o conjunto de ferramentas do Visual C++](../../how-to-report-a-problem-with-the-visual-cpp-toolset.md).