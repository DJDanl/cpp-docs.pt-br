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
ms.openlocfilehash: 45c2967a55e85ae31bb77bb2e8d50415eafbea46
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62293024"
---
# <a name="editbin-reference"></a>Referência de EDITBIN

O Editor de arquivo binário COFF da Microsoft (EDITBIN. EXE) modifica arquivos binários do Common objeto COFF (File Format). Você pode usar (editbin) para modificar os arquivos de objeto, arquivos executáveis e bibliotecas de vínculo dinâmico (DLL).

> [!NOTE]
>  Você pode iniciar essa ferramenta apenas de prompt de comando do Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.

EDITBIN não está disponível para uso em arquivos produzidos com o [/GL](gl-whole-program-optimization.md) opção de compilador. Quaisquer modificações em arquivos binários produzidos com /GL precisará ser obtido ao recompilar e vinculação.

- [Linha de comando EDITBIN](editbin-command-line.md)

- [Opções de EDITBIN](editbin-options.md)

## <a name="see-also"></a>Consulte também

[Ferramentas de Build do MSVC adicionais](c-cpp-build-tools.md)
