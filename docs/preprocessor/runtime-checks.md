---
title: Pragma runtime_checks
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.runtime_checks
- runtime_checks_CPP
helpviewer_keywords:
- runtime_checks pragma
- pragmas, runtime_checks
ms.assetid: ae50b43f-f88d-47ad-a2db-3389e9e7df5b
ms.openlocfilehash: a1c8e6cca27e157818e6ec80182f8fefa112daf1
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216613"
---
# <a name="runtime_checks-pragma"></a>Pragma runtime_checks

Desabilita ou restaura as configurações de [/RTC](../build/reference/rtc-run-time-error-checks.md) .

## <a name="syntax"></a>Sintaxe

> **#pragma runtime_checks ("** [ *runtime_checks* ] **",** { **Restore** | **off** } **)**

## <a name="remarks"></a>Comentários

Você não pode habilitar uma verificação de tempo de execução que não foi habilitada por uma opção de compilador. Por exemplo, se você não especificar `/RTCs` na linha de comando, especificar `#pragma runtime_checks( "s", restore)` não habilitará a verificação de quadro de pilha.

O pragma **runtime_checks** deve aparecer fora de uma função e entra em vigor na primeira função definida após o pragma ser visto. Os argumentos Restore e **off** ativam opções especificadas no **runtime_checks** ou off.

O **runtime_checks** pode ser zero ou mais dos parâmetros mostrados na tabela a seguir.

### <a name="parameters-of-the-runtime_checks-pragma"></a>Parâmetros do pragma runtime_checks

| Parâmetro(s) | Tipo de verificação de tempo de execução |
|--------------------|-----------------------------|
| **s** | Habilita a verificação de (registro de) pilha. |
| **c** | Informa quando um valor é atribuído a um tipo de dados menor que resulta em uma perda de dados. |
| **u** | Relata quando uma variável é usada antes de ser definida. |

Esses parâmetros são os mesmos usados com a opção `/RTC` do compilador. Por exemplo:

```cpp
#pragma runtime_checks( "sc", restore )
```

O uso do pragma **runtime_checks** com a cadeia de caracteres vazia ( **""** ) é uma forma especial da diretiva:

- Quando você usa o parâmetro **off** , ele ativa as verificações de erro em tempo de execução listadas na tabela acima, desativada.

- Quando você usa o parâmetro Restore, ele redefine as verificações de erro em tempo de execução para aquelas que você especificou usando a opção do `/RTC` compilador.

```cpp
#pragma runtime_checks( "", off )
/* runtime checks are off in this region */
#pragma runtime_checks( "", restore )
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
