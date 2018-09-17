---
title: . Arquivos PDB como entrada de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- .pdb files, as linker input
- PDB files, as linker input
ms.assetid: c1071478-2369-4b03-9df8-71761cf82f3b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d6b728903d2a270efc6b3eb736e45540651dae8c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45706180"
---
# <a name="pdb-files-as-linker-input"></a>Arquivos .Pdb como entrada de vinculador

Os arquivos (. obj) compilados usando a opção /Zi contém o nome de um banco de dados do programa (PDB) do objeto. Você não especificar o nome do arquivo PDB do objeto para o vinculador; LINK usa o nome inserido para localizar o PDB se ela for necessária. Isso também se aplica a objetos depuráveis contidos em uma biblioteca; o PDB para uma biblioteca depurável deve estar disponível para o vinculador junto com a biblioteca.

LINK também usa um PDB para armazenar informações de depuração para o arquivo de .exe ou o arquivo. dll. PDB do programa é um arquivo de saída e um arquivo de entrada, porque o LINK atualiza o PDB quando ela recria o programa.

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](../../build/reference/link-input-files.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)