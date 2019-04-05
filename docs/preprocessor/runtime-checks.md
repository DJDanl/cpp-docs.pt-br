---
title: runtime_checks
ms.date: 11/04/2016
f1_keywords:
- vc-pragma.runtime_checks
- runtime_checks_CPP
helpviewer_keywords:
- runtime_checks pragma
- pragmas, runtime_checks
ms.assetid: ae50b43f-f88d-47ad-a2db-3389e9e7df5b
ms.openlocfilehash: 44c26fb90a2d2f9ba78ec7dba7cceed65a4b4ed7
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59027075"
---
# <a name="runtimechecks"></a>runtime_checks
Desativa ou restaura os [/RTC](../build/reference/rtc-run-time-error-checks.md) configurações.

## <a name="syntax"></a>Sintaxe

```
#pragma runtime_checks( "[runtime_checks]", {restore | off} )
```

## <a name="remarks"></a>Comentários

Não é possível habilitar uma verificação de tempo de execução que não foi habilitada com uma opção de compilador. Por exemplo, se você não especificar `/RTCs`, especificando `#pragma runtime_checks( "s", restore)` não habilitará a verificação de quadro de pilha.

O **runtime_checks** pragma deve aparecer fora de uma função e entra em vigor na primeira função definida depois que o pragma é considerado. O *restaurar* e *off* argumentos ativar as opções especificadas no **runtime_checks** ativada ou desativada.

O **runtime_checks** pode ser zero ou mais dos parâmetros mostrados na tabela a seguir.

### <a name="parameters-of-the-runtimechecks-pragma"></a>Parâmetros do pragma runtime_checks

|Parâmetro(s)|Tipo de verificação de tempo de execução|
|--------------------|-----------------------------|
|*s*|Habilita a verificação de (registro de) pilha.|
|*c*|Informa quando um valor é atribuído a um tipo de dados menor que resulta em uma perda de dados.|
|*u*|Informa quando uma variável é usada antes de ser definida.|

Essas são as mesmas letras usadas com o `/RTC` opção de compilador. Por exemplo:

```
#pragma runtime_checks( "sc", restore )
```

Usando o **runtime_checks** pragma com a cadeia de caracteres vazia (**""**) é uma forma especial de política:

- Quando você usa o *desativar* parâmetro, ele transforma as verificações de erro de tempo de execução, listadas na tabela acima, off.

- Quando você usa o *restaurar* parâmetro, ele redefine as verificações de erro de tempo de execução para que você especificou com o `/RTC` opção de compilador.

```
#pragma runtime_checks( "", off )
.
.
.
#pragma runtime_checks( "", restore )
```

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)