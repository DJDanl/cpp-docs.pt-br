---
title: Reutilizando arquivos embutidos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- inline files, reusing NMAKE
- revising inline files
- NMAKE program, inline files
ms.assetid: d42dbffb-2cef-4ccb-9a1f-20b8ef81481c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 37544db8076d40e638b6ddf6f340070298229149
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45722456"
---
# <a name="reusing-inline-files"></a>Reutilizando arquivos embutidos

Para reutilizar um arquivo embutido, especifique <<*filename* onde o arquivo é definido e usado pela primeira vez, em seguida, reutilizar *filename* sem << posterior no mesmo ou outro comando. O comando para criar o arquivo embutido deve ser executado antes de todos os comandos que usam o arquivo.

## <a name="see-also"></a>Consulte também

[Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)