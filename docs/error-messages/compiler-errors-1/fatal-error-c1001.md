---
title: Erro fatal C1001
ms.date: 11/04/2016
f1_keywords:
- C1001
helpviewer_keywords:
- C1001
ms.assetid: 5736cdb3-22c8-4fad-aa85-d5e0d2b232f4
ms.openlocfilehash: e1255578883c8d2bc278184a02575a0a51ed9b6c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204952"
---
# <a name="fatal-error-c1001"></a>Erro fatal C1001

> ERRO interno do compilador ( *arquivo*de arquivo do compilador, *número*da linha)

O compilador não pode gerar o código correto para um constructo, geralmente devido à combinação de uma expressão específica e uma opção de otimização, ou um problema na análise. Se o arquivo do compilador listado tiver um segmento de caminho UTC ou C2, provavelmente será um erro de otimização. Se o arquivo tiver um segmento de caminho cxxfe ou c1xx, ou for msc1. cpp, provavelmente será um erro do analisador. Se o arquivo chamado for CL. exe, não há outras informações disponíveis.

Geralmente, você pode corrigir um problema de otimização removendo uma ou mais opções de otimização. Para determinar qual opção está com defeito, remova as opções uma de cada vez e recompile até que a mensagem de erro desapareça. As opções mais comumente responsáveis são [/og (otimizações globais)](../../build/reference/og-global-optimizations.md) e [/Oi (gerar funções intrínsecas)](../../build/reference/oi-generate-intrinsic-functions.md). Depois de determinar qual opção de otimização é responsável, você pode desabilitá-la em relação à função em que o erro ocorre usando o pragma de [otimização](../../preprocessor/optimize.md) e continuar a usar a opção para o restante do módulo. Para obter mais informações sobre as opções de otimização, consulte [práticas recomendadas de otimização](../../build/optimization-best-practices.md).

Se as otimizações não forem responsáveis pelo erro, tente reescrever a linha em que o erro é relatado ou várias linhas de código que estejam relacionadas a essa linha. Para ver o código da forma como o compilador o vê após o pré-processamento, você pode usar a opção [/p (pré-processar para um arquivo)](../../build/reference/p-preprocess-to-a-file.md) .

Para obter mais informações sobre como isolar a origem do erro e como relatar um erro de compilador interno à Microsoft, consulte [como relatar um problema com o conjunto de C++ ferramentas Visual](../../overview/how-to-report-a-problem-with-the-visual-cpp-toolset.md).
