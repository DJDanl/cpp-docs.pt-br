---
title: Arquivos .Pdb como entrada de vinculador
ms.date: 11/04/2016
helpviewer_keywords:
- .pdb files, as linker input
- PDB files, as linker input
ms.assetid: c1071478-2369-4b03-9df8-71761cf82f3b
ms.openlocfilehash: 365f2955f5bc9e8082221a070af454c820c665f1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62273281"
---
# <a name="pdb-files-as-linker-input"></a>Arquivos .Pdb como entrada de vinculador

Os arquivos (. obj) compilados usando a opção /Zi contém o nome de um banco de dados do programa (PDB) do objeto. Você não especificar o nome do arquivo PDB do objeto para o vinculador; LINK usa o nome inserido para localizar o PDB se ela for necessária. Isso também se aplica a objetos depuráveis contidos em uma biblioteca; o PDB para uma biblioteca depurável deve estar disponível para o vinculador junto com a biblioteca.

LINK também usa um PDB para armazenar informações de depuração para o arquivo de .exe ou o arquivo. dll. PDB do programa é um arquivo de saída e um arquivo de entrada, porque o LINK atualiza o PDB quando ela recria o programa.

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](link-input-files.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
