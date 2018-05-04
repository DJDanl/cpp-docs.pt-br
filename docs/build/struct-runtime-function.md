---
title: struct RUNTIME_FUNCTION | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 84386527-d3aa-41c5-871d-78e3e1913704
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3c2f28380d4a14cf7617653ede20468c45649a8b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="struct-runtimefunction"></a>struct RUNTIME_FUNCTION
Tratamento de exceções com base em tabela requer uma entrada de tabela para todas as funções que alocar espaço de pilha ou chamar outra função (por exemplo, funções de não-folha). Entradas de tabela da função têm o formato:  
  
|||  
|-|-|  
|ULONG|Endereço inicial de função|  
|ULONG|Endereço de final de função|  
|ULONG|Endereço de informações de liberação|  
  
 A estrutura RUNTIME_FUNCTION deve ser DWORD alinhado na memória. Todos os endereços são imagem relativa, ou seja, eles são os deslocamentos de 32 bits do endereço inicial da imagem que contém a entrada da tabela de função. Essas entradas são classificadas e colocadas na seção de uma imagem PE32 +. pData. Para funções geradas dinamicamente [compiladores JIT], o tempo de execução para dar suporte a essas funções deve usar RtlInstallFunctionTableCallback ou RtlAddFunctionTable para fornecer essas informações para o sistema operacional. Falha ao fazer isso resulta em confiável manipuladores de exceção e depuração de processos.  
  
## <a name="see-also"></a>Consulte também  
 [Desenrolar dados para tratamento de exceção, suporte do depurador](../build/unwind-data-for-exception-handling-debugger-support.md)