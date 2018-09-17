---
title: . Arquivos ilk como entrada de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ILK files
- .ilk files
ms.assetid: 7324c104-9e5d-423d-b268-b59f92607bf2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f3b8de3758daf59a543cdcc9f3b73e1d6c6f0ce8
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45720584"
---
# <a name="ilk-files-as-linker-input"></a>Arquivos .Ilk como entrada de vinculador

Ao vincular incrementalmente, LINK atualiza o arquivo de status. ilk que criou durante o primeiro link incremental. Este arquivo tem o mesmo nome base que o arquivo de .exe ou o arquivo. dll e tem o. ilk de extensão. Durante os links incrementais subsequentes, o LINK atualiza o arquivo. ilk. Se o arquivo. ilk estiver ausente, o LINK executa uma vinculação completa e cria um novo arquivo. ilk. Se o arquivo. ilk inutilizável, o LINK executa uma vinculação não incremental. Para obter detalhes sobre a vinculação incremental, consulte o [vincular de maneira incremental (/incremental)](../../build/reference/incremental-link-incrementally.md) opção.

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](../../build/reference/link-input-files.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)