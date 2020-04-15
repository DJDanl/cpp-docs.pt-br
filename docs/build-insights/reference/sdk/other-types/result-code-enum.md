---
title: RESULT_CODE enum
description: O C++ Build Insights SDK RESULT_CODE referência enum.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RESULT_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 62874e176c3f3e8f9df1ca64e7b593b7a0ef5c01
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323630"
---
# <a name="result_code-enum"></a>RESULT_CODE enum

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

O `RESULT_CODE` enum descreve as condições de sucesso e fracasso.

## <a name="members"></a>Membros

| Nome | Valor | Descrição |
|--|--|--|
| `RESULT_CODE_SUCCESS` | 0 (0x0000000000) | A operação foi bem-sucedida. |
| `RESULT_CODE_FAILURE_ANALYSIS_ERROR` | 1 (0x00000001) | Uma de suas funções de retorno de `CALLBACK_CODE_ANALYSIS_FAILURE` chamada em [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md) devolveu o valor. Este valor é um membro do [CALLBACK_CODE](callback-code-enum.md) enum. |
| `RESULT_CODE_FAILURE_CANCELLED` | 2 (0x000000002) | Uma de suas funções de retorno de `CALLBACK_CODE_ANALYSIS_CANCEL` chamada em [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md) devolveu o valor. Este valor é um membro do [CALLBACK_CODE](callback-code-enum.md) enum. |
| `RESULT_CODE_FAILURE_INVALID_INPUT_LOG_FILE` | 3 (0x0000000003) | O rastreamento de evento de entrada para Windows (ETW) especificado é inválido. |
| `RESULT_CODE_FAILURE_INVALID_OUTPUT_LOG_FILE` | 4 (0x0000000004) | O traço etw de saída especificado é inválido. |
| `RESULT_CODE_FAILURE_MISSING_ANALYSIS_CALLBACK` | 5 (0x000000005) | A estrutura [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) não foi iniciada corretamente. |
| `RESULT_CODE_FAILURE_MISSING_RELOG_CALLBACK` | 6 (0x000000006) | A [estrutura RELOG_CALLBACKS](relog-callbacks-struct.md) não foi iniciada corretamente. |
| `RESULT_CODE_FAILURE_OPEN_INPUT_TRACE` | 7 (0x000000007) | Falha ao abrir o rastreamento de ETW de entrada. |
| `RESULT_CODE_FAILURE_PROCESS_TRACE` | 8 (0x000000008) | Ocorreu um erro durante o processamento do rastreamento eTW de entrada. |
| `RESULT_CODE_FAILURE_START_RELOGGER` | 9 (0x000000009) | Ocorreu um erro ao tentar iniciar a sessão de relogamento. |
| `RESULT_CODE_FAILURE_DROPPED_EVENTS` | 10 (0x0000000A) | O rastreamento de ETW de entrada está faltando eventos importantes. |
| `RESULT_CODE_FAILURE_UNSUPPORTED_OS` | 11 (0x0000000B) | Você está usando C++ Build Insights em uma versão sem suporte do Windows. |
| `RESULT_CODE_FAILURE_INVALID_TRACING_SESSION_NAME` | 12 (0x0000000C) | O nome da sessão fornecido é inválido. |
| `RESULT_CODE_FAILURE_INSUFFICIENT_PRIVILEGES` | 13 (0x0000000D) | Esta operação requer privilégios de administrador. |
| `RESULT_CODE_FAILURE_GENERATE_GUID` | 14 (0x0000000E) | Ocorreu um erro ao gerar um GUID. |
| `RESULT_CODE_FAILURE_OBTAINING_TEMP_DIRECTORY` | 15 (0x0000000F) | Ocorreu um erro ao tentar determinar o caminho do diretório temporário. |
| `RESULT_CODE_FAILURE_CREATE_TEMPORARY_DIRECTORY` | 16 (0x00000010) | Ocorreu um erro ao tentar criar um diretório temporário para a sessão de rastreamento que está sendo iniciada. |
| `RESULT_CODE_FAILURE_START_SYSTEM_TRACE` | 17 (0x00000011) | Ocorreu um erro ao tentar iniciar o rastreamento do sistema. |
| `RESULT_CODE_FAILURE_START_MSVC_TRACE` | 18 (0x00000012) | Ocorreu um erro ao tentar iniciar o rastreamento do MSVC. |
| `RESULT_CODE_FAILURE_STOP_MSVC_TRACE` | 19 (0x00000013) | Ocorreu um erro ao tentar parar o rastreamento do MSVC. |
| `RESULT_CODE_FAILURE_STOP_SYSTEM_TRACE` | 20 (0x00000014) | Ocorreu um erro ao tentar iniciar o rastreamento do sistema. |
| `RESULT_CODE_FAILURE_SESSION_DIRECTORY_RESOLUTION` | 21 (0x00000015) | Um rastreamento foi interrompido, mas o diretório temporário da sessão de rastreamento não pode ser encontrado. |
| `RESULT_CODE_FAILURE_MSVC_TRACE_FILE_NOT_FOUND` | 22 (0x00000016) | O arquivo de rastreamento do rastreamento do MSVC que está sendo parado não pode ser encontrado. |
| `RESULT_CODE_FAILURE_MERGE_TRACES` | 23 (0x00000017) | Ocorreu um erro ao mesclar traços usando o Kernel Trace Control. |
| `RESULT_CODE_FAILURE_UNKNOWN_ERROR` | 24 (0x00000018) | Erro desconhecido. |

::: moniker-end
