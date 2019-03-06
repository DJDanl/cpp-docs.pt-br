---
title: Arquivos .Ilk como entrada de vinculador
ms.date: 11/04/2016
helpviewer_keywords:
- ILK files
- .ilk files
ms.assetid: 7324c104-9e5d-423d-b268-b59f92607bf2
ms.openlocfilehash: 6c0eb5627d7dd1b414351dc65685c0c5071d249e
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422501"
---
# <a name="ilk-files-as-linker-input"></a>Arquivos .Ilk como entrada de vinculador

Ao vincular incrementalmente, LINK atualiza o arquivo de status. ilk que criou durante o primeiro link incremental. Este arquivo tem o mesmo nome base que o arquivo de .exe ou o arquivo. dll e tem o. ilk de extensão. Durante os links incrementais subsequentes, o LINK atualiza o arquivo. ilk. Se o arquivo. ilk estiver ausente, o LINK executa uma vinculação completa e cria um novo arquivo. ilk. Se o arquivo. ilk inutilizável, o LINK executa uma vinculação não incremental. Para obter detalhes sobre a vinculação incremental, consulte o [vincular de maneira incremental (/incremental)](../../build/reference/incremental-link-incrementally.md) opção.

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](../../build/reference/link-input-files.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
