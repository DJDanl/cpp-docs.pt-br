---
title: Rotinas do tratamento de exceções
ms.date: 11/04/2016
f1_keywords:
- c.exceptions
helpviewer_keywords:
- exception handling, routines
ms.assetid: f60548c6-850a-4e1e-a79b-a2a6a541ab62
ms.openlocfilehash: 8def356793906074e6fc4b8d7a139ce1915a5f9b
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57749133"
---
# <a name="exception-handling-routines"></a>Rotinas do tratamento de exceções

Use as funções de tratamento de exceção do C++ para recuperar eventos inesperados durante a execução do programa.

## <a name="exception-handling-functions"></a>Funções de tratamento de exceção

|Função|Use|
|--------------|---------|
|[_set_se_translator](../c-runtime-library/reference/set-se-translator.md)|Trata exceções do Win32 (exceções de C estruturadas) como exceções C++|
|[set_terminate](../c-runtime-library/reference/set-terminate-crt.md)|Instalar sua própria rotina de terminação a ser chamada por **terminate**|
|[set_unexpected](../c-runtime-library/reference/set-unexpected-crt.md)|Instalar sua própria função de terminação a ser chamada por **unexpected**|
|[terminate](../c-runtime-library/reference/terminate-crt.md)|Chamado automaticamente em determinadas circunstâncias após a exceção ser lançada. A função **terminate** chama **abort** ou uma função especificada usando **set_terminate**|
|[unexpected](../c-runtime-library/reference/unexpected-crt.md)|Chama **terminate** ou uma função especificada usando **set_unexpected**. A função **unexpected** não é usada na implementação atual de tratamento de exceção em Microsoft C++|

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
