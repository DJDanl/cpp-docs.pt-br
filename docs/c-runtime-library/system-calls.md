---
title: Chamadas do sistema
ms.date: 11/04/2016
f1_keywords:
- c.system
helpviewer_keywords:
- Windows [C++], system calls
- system calls
ms.assetid: 0255f2ec-a5a0-487e-8b09-9dad001d81ed
ms.openlocfilehash: 2d86a35718ab6c1aab941149c9707004b1532d24
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57749198"
---
# <a name="system-calls"></a>Chamadas do sistema

As seguintes funções são chamadas do sistema operacional Windows.

## <a name="system-call-functions"></a>Funções de chamada do sistema

|Função|Use|
|--------------|---------|
|[_findclose](../c-runtime-library/reference/findclose.md)|Liberar recursos de operações anteriores de localização|
|[_findfirst, _findfirst32, _findfirst64, _findfirsti64, _findfirst32i64, _findfirst64i32, _wfindfirst, _wfindfirst32, _wfindfirst64, _wfindfirsti64, _wfindfirst32i64, _wfindfirst64i32](../c-runtime-library/reference/findfirst-functions.md)|Localize o arquivo com os atributos especificados|
|[_findnext, _findnext32, _findnext64, _findnexti64, _findnext32i64, _findnext64i32, _wfindnext, _wfindnext32, _wfindnexti64, _wfindnext64, _wfindnexti64](../c-runtime-library/reference/findnext-functions.md)|Localize o próximo arquivo com os atributos especificados|

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
[Manipulação de Arquivos](../c-runtime-library/file-handling.md)<br/>
[Controle de diretório](../c-runtime-library/directory-control.md)<br/>
[E/S de nível inferior](../c-runtime-library/low-level-i-o.md)<br/>
