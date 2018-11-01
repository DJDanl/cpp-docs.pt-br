---
title: Erro D8045 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D8045
helpviewer_keywords:
- D8045
ms.assetid: 01c8808c-bac1-4b4d-8a90-b595f95e9318
ms.openlocfilehash: 7964c2539b5358d2d946e530c4ee75110857446d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50490578"
---
# <a name="command-line-error-d8045"></a>Erro D8045 (linha de comando)

não é possível compilar o arquivo C 'file' com a opção /clr

Somente código arquivos de origem C++ podem ser passados para uma compilação que usa **/clr**.  Use **/TP** para compilar um arquivo. c como um arquivo. cpp; veja [/Tc, /Tp, /TC, /TP (especificar tipo de arquivo de origem)](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) para obter mais informações.

Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

D8045 também pode ocorrer se você compilar um aplicativo ATL usando o Visual C++. Ver [como: migrar para /clr](../../dotnet/how-to-migrate-to-clr.md) para obter mais informações.