---
title: Erro das Ferramentas de Vinculador LNK1181
ms.date: 08/22/2018
f1_keywords:
- LNK1181
helpviewer_keywords:
- LNK1181
ms.assetid: 984b0db6-e331-4284-b2a7-a212fe96c486
ms.openlocfilehash: 657e78ece2ce4039eb8dc8561abd455c60aaff75
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59035066"
---
# <a name="linker-tools-error-lnk1181"></a>Erro das Ferramentas de Vinculador LNK1181

não é possível abrir o arquivo de entrada 'filename'

Não foi possível encontrar o vinculador `filename` porque ele não existe ou o caminho não foi encontrado.

Algumas causas comuns para erro LNK1181 incluem:

- `filename` é referenciado como uma dependência adicional na linha do vinculador, mas o arquivo não existe.

- Um **/LIBPATH** declaração que especifica o diretório que contém `filename` está ausente.

Para resolver os problemas acima, verifique se todos os arquivos referenciados na linha do vinculador estão presentes no sistema.  Também verifique se há um **/LIBPATH** instrução para cada diretório que contém um arquivo dependente do vinculador.

Para obter mais informações, consulte [arquivos. lib como entrada de vinculador](../../build/reference/dot-lib-files-as-linker-input.md).

Outra causa possível para LNK1181 é que um nome de arquivo longo com espaços incorporados não foi colocado entre aspas.  Nesse caso, o vinculador reconhecerá apenas um nome de arquivo até o primeiro espaço e, em seguida, suponha que uma extensão de arquivo. obj.  A solução para essa situação é para delimitar o nome de arquivo longos (nome de caminho e arquivo) entre aspas.

Compilar com o [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md) opção pode resultar em LNK1181 porque essa opção suprime a criação de arquivos. obj.

## <a name="see-also"></a>Consulte também

[/LIBPATH (Libpath adicional)](../../build/reference/libpath-additional-libpath.md)