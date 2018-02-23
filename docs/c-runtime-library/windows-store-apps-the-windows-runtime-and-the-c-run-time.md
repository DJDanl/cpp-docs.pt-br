---
title: "Aplicativos UWP, o Windows Runtime e o tempo de execução do C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 356d6d8d-76ee-4181-9ad0-6f24b2fede38
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 120e02caab735455224ad75f0944ceb25f4baf33
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="uwp-apps-the-windows-runtime-and-the-c-run-time"></a>Aplicativos UWP, o Windows Runtime e o tempo de execução do C

Os aplicativos UWP (Plataforma Universal do Windows) são programas executados no Windows Runtime que é executado no [!INCLUDE[win8](../build/reference/includes/win8_md.md)]. O Windows Runtime é um ambiente confiável que controla as funções, as variáveis e os recursos disponíveis para um aplicativo UWP. No entanto, o design do Windows Runtime apresenta restrições que impedem o uso da maioria dos recursos da biblioteca em CRT (tempo de execução do C) nos aplicativos UWP.

O Windows Runtime não tem suporte para os seguintes recursos de CRT:

- A maioria das funções de CRT que estão relacionados à funcionalidade sem suporte.

   Por exemplo, um aplicativo UWP não pode criar um processo usando as famílias de rotinas `exec` e `spawn`.

   Quando uma função do CRT não é compatível com um aplicativo UWP, esse fato está anotado em seu artigo de referência.

- Maioria das funções de caracteres multibyte e cadeia de caracteres.

   No entanto, há suporte para texto ANSI e Unicode.

- Aplicativos de console e argumentos de linha de comando.

   Entretanto, aplicativos de área de trabalho tradicionais ainda dão suporte ao console e a argumentos de linha de comando.

- Variáveis de ambiente.

- O conceito de um diretório de trabalho atual.

- Os aplicativos UWP e as DLLs que são vinculados estaticamente ao CRT e criados usando as opções do compilador [/MT](../build/reference/md-mt-ld-use-run-time-library.md) ou `/MTd`.

   Ou seja, um aplicativo que usa uma versão estática multithread do CRT.

- Um aplicativo que é criado usando a opção do compilador [/MDd](../build/reference/md-mt-ld-use-run-time-library.md).

   Ou seja, uma versão específica de depuração, multithread e DLL do CRT. Esse tipo de aplicativo não é compatível com o Windows Runtime.

Para obter uma lista completa das funções do CRT que não estão disponíveis em um aplicativo UWP e sugestões de funções alternativas, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="see-also"></a>Consulte também
 [Compatibilidade](../c-runtime-library/compatibility.md) [Funções do CRT sem suporte no Windows Runtime](../c-runtime-library/windows-runtime-unsupported-crt-functions.md) [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)