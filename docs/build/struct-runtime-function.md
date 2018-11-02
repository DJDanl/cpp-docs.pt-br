---
title: struct RUNTIME_FUNCTION
ms.date: 11/04/2016
ms.assetid: 84386527-d3aa-41c5-871d-78e3e1913704
ms.openlocfilehash: 6b113f6cf1e9951f9e4578e15c9ed0af3d036fa6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50520235"
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