---
title: Erro BK1513 (BSCMAKE)
ms.date: 11/04/2016
f1_keywords:
- BK1513
helpviewer_keywords:
- BK1513
ms.assetid: 9ba87c09-8d82-4c80-b0cf-a8de63dcf9da
ms.openlocfilehash: 3a16163f33814be18a67833995362ee9b13d8118
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197633"
---
# <a name="bscmake-error-bk1513"></a>Erro BK1513 (BSCMAKE)

a atualização não incremental exige todos os arquivos .SBR

BSCMAKE não pode compilar um novo arquivo de informações (.bsc) do navegador porque um ou mais arquivos .sbr estão truncados. Para localizar os nomes dos arquivos. sbr truncados, leia os avisos do [BK4502](../../error-messages/tool-errors/bscmake-warning-bk4502.md) que acompanham esse erro.

BSCMAKE pode atualizar um arquivo .bsc com um arquivo .sbr truncado, mas não é possível compilar um novo. BSCMAKE pode criar um novo arquivo .bsc pelos seguintes motivos:

- Arquivo .bsc ausente.

- Nome de arquivo especificado incorreto para o arquivo .bsc.

- Arquivo .bsc corrompido.

Para resolver esse problema, exclua os arquivos .sbr truncados e recompile-os ou limpe a solução e refaça a compilação. (No IDE, escolha **Compilar**, **limpar solução**e, em seguida, escolha **Compilar**, **Recompilar solução**.)
