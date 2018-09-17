---
title: Importando para um aplicativo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- DLLs [C++], importing
- importing DLLs [C++], applications
- applications [C++], importing into
ms.assetid: 9d646466-e12e-4710-8ad9-c819c0375fcc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e88d34ce685e22e561683cc33db25997650ed7fd
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45718374"
---
# <a name="importing-into-an-application"></a>Importando para um aplicativo

Você pode importar funções em um aplicativo usando dois métodos:

- Use as palavras-chave **__declspec(dllimport)** em uma definição de função no aplicativo principal

- Usar um arquivo de definição (. def) do módulo juntamente com **__declspec(dllimport)**

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Importação em um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)

- [Chamadas de função de importação usando __declspec(dllimport)](../build/importing-function-calls-using-declspec-dllimport.md)

- [Importar dados usando __declspec(dllimport)](../build/importing-data-using-declspec-dllimport.md)

- [Importar usando arquivos DEF](../build/importing-using-def-files.md)

## <a name="see-also"></a>Consulte também

[Importando e exportando](../build/importing-and-exporting.md)