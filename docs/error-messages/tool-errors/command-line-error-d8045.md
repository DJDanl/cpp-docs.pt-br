---
title: Erro D8045 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D8045
helpviewer_keywords:
- D8045
ms.assetid: 01c8808c-bac1-4b4d-8a90-b595f95e9318
ms.openlocfilehash: 05a2d3851e58062e1e326781a223e2f4b0346620
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196840"
---
# <a name="command-line-error-d8045"></a>Erro D8045 (linha de comando)

Não é possível compilar o arquivo C ' file ' com a opção/CLR

Somente C++ arquivos de código-fonte podem ser passados para uma compilação que usa **/CLR**.  Use **/TP** para compilar um arquivo. c como um arquivo. cpp; consulte [/TC,/TP,/TC,/TP (especifique o tipo de arquivo de origem)](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) para obter mais informações.

Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

D8045 também pode ocorrer se você compilar um aplicativo ATL usando Visual C++. Consulte [como migrar para/CLR](../../dotnet/how-to-migrate-to-clr.md) para obter mais informações.
