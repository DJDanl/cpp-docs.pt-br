---
title: Arquivos .Ilk como entrada de vinculador
ms.date: 11/04/2016
helpviewer_keywords:
- ILK files
- .ilk files
ms.assetid: 7324c104-9e5d-423d-b268-b59f92607bf2
ms.openlocfilehash: 252c1cd6e17346954fce7ebf16134246da76ba57
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62293843"
---
# <a name="ilk-files-as-linker-input"></a>Arquivos .Ilk como entrada de vinculador

Ao vincular incrementalmente, LINK atualiza o arquivo de status. ilk que criou durante o primeiro link incremental. Este arquivo tem o mesmo nome base que o arquivo de .exe ou o arquivo. dll e tem o. ilk de extensão. Durante os links incrementais subsequentes, o LINK atualiza o arquivo. ilk. Se o arquivo. ilk estiver ausente, o LINK executa uma vinculação completa e cria um novo arquivo. ilk. Se o arquivo. ilk inutilizável, o LINK executa uma vinculação não incremental. Para obter detalhes sobre a vinculação incremental, consulte o [vincular de maneira incremental (/incremental)](incremental-link-incrementally.md) opção.

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](link-input-files.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
