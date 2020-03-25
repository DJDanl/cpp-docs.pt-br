---
title: Erro das Ferramentas de Vinculador LNK1181
ms.date: 08/22/2018
f1_keywords:
- LNK1181
helpviewer_keywords:
- LNK1181
ms.assetid: 984b0db6-e331-4284-b2a7-a212fe96c486
ms.openlocfilehash: d2b28af52a2ca2263a7bad77c8c69242396ff2b4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195247"
---
# <a name="linker-tools-error-lnk1181"></a>Erro das Ferramentas de Vinculador LNK1181

Não é possível abrir o arquivo de entrada ' FileName '

O vinculador não pôde localizar `filename` porque ele não existe ou o caminho não foi encontrado.

Algumas causas comuns para o erro LNK1181 incluem:

- `filename` é referenciado como uma dependência adicional na linha do vinculador, mas o arquivo não existe.

- Uma instrução **/LIBPATH** que especifica o diretório que contém `filename` está ausente.

Para resolver os problemas acima, verifique se todos os arquivos referenciados na linha do vinculador estão presentes no sistema.  Além disso, verifique se há uma instrução **/LIBPATH** para cada diretório que contém um arquivo dependente do vinculador.

Para obter mais informações, consulte [arquivos. lib como entrada do vinculador](../../build/reference/dot-lib-files-as-linker-input.md).

Outra causa possível para LNK1181 é que um nome de arquivo longo com espaços incorporados não foi colocado entre aspas.  Nesse caso, o vinculador reconhecerá apenas um nome de arquivo até o primeiro espaço e, em seguida, assumirá uma extensão de arquivo. obj.  A solução para essa situação é colocar o nome de arquivo longo (caminho mais o nome do arquivo) entre aspas.

A compilação com a opção [/p (pré-processar para um arquivo)](../../build/reference/p-preprocess-to-a-file.md) pode resultar em LNK1181 porque essa opção suprime a criação de arquivos. obj.

## <a name="see-also"></a>Confira também

[/LIBPATH (Libpath adicional)](../../build/reference/libpath-additional-libpath.md)
