---
title: RESULT_CODE enum
description: O SDK do insights de compilação do C++ RESULT_CODE referência de enumeração.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RESULT_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 3d9d18d535d15d04a2e449bdbbf693364276a518
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922417"
---
# <a name="result_code-enum"></a>RESULT_CODE enum

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `RESULT_CODE` Enumeração descreve as condições de êxito e falha.

## <a name="members"></a>Membros

| Nome | Valor | Descrição |
|--|--|--|
| `RESULT_CODE_SUCCESS` | 0 (0x00000000) | A operação foi bem-sucedida. |
| `RESULT_CODE_FAILURE_ANALYSIS_ERROR` | 1 (0x00000001) | Uma das suas funções de retorno de chamada no [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md) retornou o `CALLBACK_CODE_ANALYSIS_FAILURE` valor. Esse valor é um membro da enumeração [CALLBACK_CODE](callback-code-enum.md) . |
| `RESULT_CODE_FAILURE_CANCELLED` | 2 (0x00000002) | Uma das suas funções de retorno de chamada no [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md) retornou o `CALLBACK_CODE_ANALYSIS_CANCEL` valor. Esse valor é um membro da enumeração [CALLBACK_CODE](callback-code-enum.md) . |
| `RESULT_CODE_FAILURE_INVALID_INPUT_LOG_FILE` | 3 (0x00000003) | O rastreamento do ETW (rastreamento de eventos de entrada para Windows) especificado é inválido. |
| `RESULT_CODE_FAILURE_INVALID_OUTPUT_LOG_FILE` | 4 (0x00000004) | O rastreamento ETW de saída especificado é inválido. |
| `RESULT_CODE_FAILURE_MISSING_ANALYSIS_CALLBACK` | 5 (0x00000005) | A estrutura de [ANALYSIS_CALLBACKS](analysis-callbacks-struct.md) não foi inicializada corretamente. |
| `RESULT_CODE_FAILURE_MISSING_RELOG_CALLBACK` | 6 (0x00000006) | A estrutura de [RELOG_CALLBACKS](relog-callbacks-struct.md) não foi inicializada corretamente. |
| `RESULT_CODE_FAILURE_OPEN_INPUT_TRACE` | 7 (0x00000007) | Falha ao abrir o rastreamento ETW de entrada. |
| `RESULT_CODE_FAILURE_PROCESS_TRACE` | 8 (0x00000008) | Ocorreu um erro ao processar o rastreamento ETW de entrada. |
| `RESULT_CODE_FAILURE_START_RELOGGER` | 9 (0x00000009) | Ocorreu um erro ao tentar iniciar a sessão de reregistro em log. |
| `RESULT_CODE_FAILURE_DROPPED_EVENTS` | 10 (0x0000000A) | O rastreamento ETW de entrada não tem eventos importantes. |
| `RESULT_CODE_FAILURE_UNSUPPORTED_OS` | 11 (0x0000000B) | Você está usando as informações de Build do C++ em uma versão sem suporte do Windows. |
| `RESULT_CODE_FAILURE_INVALID_TRACING_SESSION_NAME` | 12 (0x0000000C) | O nome de sessão fornecido é inválido. |
| `RESULT_CODE_FAILURE_INSUFFICIENT_PRIVILEGES` | 13 (0x0000000D) | Esta operação requer privilégios de administrador. |
| `RESULT_CODE_FAILURE_GENERATE_GUID` | 14 (0x0000000E) | Ocorreu um erro ao gerar um GUID. |
| `RESULT_CODE_FAILURE_OBTAINING_TEMP_DIRECTORY` | 15 (0x0000000F) | Ocorreu um erro ao tentar determinar o caminho do diretório temporário. |
| `RESULT_CODE_FAILURE_CREATE_TEMPORARY_DIRECTORY` | 16 (0x00000010) | Ocorreu um erro ao tentar criar um diretório temporário para a sessão de rastreamento que está sendo iniciada. |
| `RESULT_CODE_FAILURE_START_SYSTEM_TRACE` | 17 (0x00000011) | Ocorreu um erro ao tentar iniciar o rastreamento do sistema. |
| `RESULT_CODE_FAILURE_START_MSVC_TRACE` | 18 (0x00000012) | Ocorreu um erro ao tentar iniciar o rastreamento MSVC. |
| `RESULT_CODE_FAILURE_STOP_MSVC_TRACE` | 19 (0x00000013) | Ocorreu um erro ao tentar parar o rastreamento de MSVC. |
| `RESULT_CODE_FAILURE_STOP_SYSTEM_TRACE` | 20 (0x00000014) | Ocorreu um erro ao tentar iniciar o rastreamento do sistema. |
| `RESULT_CODE_FAILURE_SESSION_DIRECTORY_RESOLUTION` | 21 (0x00000015) | Um rastreamento foi interrompido, mas o diretório temporário da sessão de rastreamento não foi encontrado. |
| `RESULT_CODE_FAILURE_MSVC_TRACE_FILE_NOT_FOUND` | 22 (0x00000016) | O arquivo de rastreamento do rastreamento MSVC que está sendo interrompido não pode ser encontrado. |
| `RESULT_CODE_FAILURE_MERGE_TRACES` | 23 (0x00000017) | Ocorreu um erro ao mesclar rastreamentos usando o controle de rastreamento de kernel. |
| `RESULT_CODE_FAILURE_UNKNOWN_ERROR` | 24 (0x00000018) | Erro desconhecido. |

::: moniker-end
