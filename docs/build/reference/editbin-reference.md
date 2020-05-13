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
ms.openlocfilehash: 266347de063b4e050cb032aa2d8d74e7934b8081
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328343"
---
# <a name="editbin-reference"></a>Referência de EDITBIN

O Editor de Arquivos Binários do Microsoft COFF (EDITBIN. EXE) modifica arquivos binários Common Object File Format (COFF). Você pode usar o EDITBIN para modificar arquivos de objetos, arquivos executáveis e bibliotecas de link dinâmico (DLL).

> [!NOTE]
> Você só pode iniciar esta ferramenta a partir do prompt de comando do Visual Studio. Não é possível iniciá-lo a partir de um prompt de comando do sistema ou do Explorador de Arquivos.

EDITBIN não está disponível para uso em arquivos produzidos com a opção [/GL](gl-whole-program-optimization.md) compilador. Quaisquer modificações em arquivos binários produzidos com /GL terão que ser alcançadas recompilando e vinculando.

- [Linha de comando EDITBIN](editbin-command-line.md)

- [Opções EDITBIN](editbin-options.md)

## <a name="see-also"></a>Confira também

[Ferramentas adicionais de construção de MSVC](c-cpp-build-tools.md)
