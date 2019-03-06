---
title: Referência de EDITBIN
ms.date: 11/04/2016
f1_keywords:
- editbin
helpviewer_keywords:
- binary data, editing
- object files, modifying
- EDITBIN program
- COFF files, editing
ms.assetid: efdda03b-3dfc-4d31-90e6-caf5b3977914
ms.openlocfilehash: 39fdcfd3221599f20617092118e5cef5267e3d2b
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57418783"
---
# <a name="editbin-reference"></a>Referência de EDITBIN

O Editor de arquivo binário COFF da Microsoft (EDITBIN. EXE) modifica arquivos binários do Common objeto COFF (File Format). Você pode usar (editbin) para modificar os arquivos de objeto, arquivos executáveis e bibliotecas de vínculo dinâmico (DLL).

> [!NOTE]
>  Você pode iniciar essa ferramenta apenas de prompt de comando do Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.

EDITBIN não está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador. Quaisquer modificações em arquivos binários produzidos com /GL precisará ser obtido ao recompilar e vinculação.

- [Linha de comando EDITBIN](../../build/reference/editbin-command-line.md)

- [Opções de EDITBIN](../../build/reference/editbin-options.md)

## <a name="see-also"></a>Consulte também

[Ferramentas de build do C/C++](../../build/reference/c-cpp-build-tools.md)
