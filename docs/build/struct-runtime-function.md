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
ms.openlocfilehash: 7f3831dc36664c556cf0a020ed87c60200443fd3
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45718231"
---
# <a name="struct-runtimefunction"></a>struct RUNTIME_FUNCTION

Tratamento de exceções baseado em tabela requer uma entrada de tabela para todas as funções que alocam espaço na pilha ou chamar outra função (por exemplo, funções de não-folha). Entradas da tabela de função têm o formato:

|||
|-|-|
|ULONG|Endereço de início da função|
|ULONG|Endereço final da função|
|ULONG|Endereço de informações de desenrolamento|

A estrutura RUNTIME_FUNCTION deve ser DWORD alinhado na memória. Todos os endereços são imagem relativa, ou seja, eles são deslocamentos de 32 bits do endereço inicial da imagem que contém a entrada da tabela de função. Essas entradas são classificadas e colocadas na seção. pData de uma imagem PE32 +. Para funções geradas dinamicamente [compiladores JIT], o tempo de execução para dar suporte a essas funções deve usar RtlInstallFunctionTableCallback ou RtlAddFunctionTable para fornecer essas informações para o sistema operacional. Falha ao fazer isso resulta em não-confiável manipulação de exceção e depuração dos processos.

## <a name="see-also"></a>Consulte também

[Desenrolar dados para tratamento de exceção, suporte do depurador](../build/unwind-data-for-exception-handling-debugger-support.md)