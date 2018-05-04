---
title: Chamadas do sistema | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- c.system
dev_langs:
- C++
helpviewer_keywords:
- Windows [C++], system calls
- system calls
ms.assetid: 0255f2ec-a5a0-487e-8b09-9dad001d81ed
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0cbf9b060f8063345f00a4c5fc9c14df71e9f4c9
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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
