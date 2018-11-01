---
title: Erro BK1513 (BSCMAKE)
ms.date: 11/04/2016
f1_keywords:
- BK1513
helpviewer_keywords:
- BK1513
ms.assetid: 9ba87c09-8d82-4c80-b0cf-a8de63dcf9da
ms.openlocfilehash: c02e9b47b3d32e4d21914188b96913d6dff03127
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50477214"
---
# <a name="bscmake-error-bk1513"></a>Erro BK1513 (BSCMAKE)

a atualização não incremental exige todos os arquivos .SBR

BSCMAKE não pode compilar um novo arquivo de informações (.bsc) do navegador porque um ou mais arquivos .sbr estão truncados. Para obter os nomes dos arquivos. SBR truncados, leia as [BK4502](../../error-messages/tool-errors/bscmake-warning-bk4502.md) avisos que acompanham esse erro.

BSCMAKE pode atualizar um arquivo .bsc com um arquivo .sbr truncado, mas não é possível compilar um novo. BSCMAKE pode criar um novo arquivo .bsc pelos seguintes motivos:

- Arquivo .bsc ausente.

- Nome de arquivo especificado incorreto para o arquivo .bsc.

- Arquivo .bsc corrompido.

Para resolver esse problema, exclua os arquivos .sbr truncados e recompile-os ou limpe a solução e refaça a compilação. (No IDE, escolha **construir**, **limpar solução**e, em seguida, escolha **Build**, **recompilar solução**.)