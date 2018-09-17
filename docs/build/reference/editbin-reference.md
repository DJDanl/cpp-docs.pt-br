---
title: Referência de EDITBIN | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- editbin
dev_langs:
- C++
helpviewer_keywords:
- binary data, editing
- object files, modifying
- EDITBIN program
- COFF files, editing
ms.assetid: efdda03b-3dfc-4d31-90e6-caf5b3977914
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 809d1d4f25611b2310d651702f01e1e98888ad4a
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45699941"
---
# <a name="editbin-reference"></a>Referência de EDITBIN

O Editor de arquivo binário COFF da Microsoft (EDITBIN. EXE) modifica arquivos binários do Common objeto COFF (File Format). Você pode usar (editbin) para modificar os arquivos de objeto, arquivos executáveis e bibliotecas de vínculo dinâmico (DLL).

> [!NOTE]
>  Você pode iniciar essa ferramenta apenas de prompt de comando do Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.

EDITBIN não está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador. Quaisquer modificações em arquivos binários produzidos com /GL precisará ser obtido ao recompilar e vinculação.

- [Linha de comando EDITBIN](../../build/reference/editbin-command-line.md)

- [Opções de EDITBIN](../../build/reference/editbin-options.md)

## <a name="see-also"></a>Consulte também

[Ferramentas de build de C/C++](../../build/reference/c-cpp-build-tools.md)