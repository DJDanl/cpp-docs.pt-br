---
title: Arquivos .Ilk como entrada de vinculador
ms.date: 11/04/2016
helpviewer_keywords:
- ILK files
- .ilk files
ms.assetid: 7324c104-9e5d-423d-b268-b59f92607bf2
ms.openlocfilehash: 012ca9aaa50ac2f8bb9d95ef77df5bb7127c5b79
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50595969"
---
# <a name="ilk-files-as-linker-input"></a>Arquivos .Ilk como entrada de vinculador

Ao vincular incrementalmente, LINK atualiza o arquivo de status. ilk que criou durante o primeiro link incremental. Este arquivo tem o mesmo nome base que o arquivo de .exe ou o arquivo. dll e tem o. ilk de extensão. Durante os links incrementais subsequentes, o LINK atualiza o arquivo. ilk. Se o arquivo. ilk estiver ausente, o LINK executa uma vinculação completa e cria um novo arquivo. ilk. Se o arquivo. ilk inutilizável, o LINK executa uma vinculação não incremental. Para obter detalhes sobre a vinculação incremental, consulte o [vincular de maneira incremental (/incremental)](../../build/reference/incremental-link-incrementally.md) opção.

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](../../build/reference/link-input-files.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)