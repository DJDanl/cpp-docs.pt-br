---
title: /WHOLEARCHIVE (incluir todos os arquivos de objeto de biblioteca)
ms.date: 02/12/2020
ms.assetid: ee92d12f-18af-4602-9683-d6223be62ac9
ms.openlocfilehash: 95685c9c0dfde45c42449bbcad67228a0e21b36a
ms.sourcegitcommit: 8414cd91297dea88c480e208c7b5301db9972f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2020
ms.locfileid: "77257527"
---
# <a name="wholearchive-include-all-library-object-files"></a>/WHOLEARCHIVE (incluir todos os arquivos de objeto de biblioteca)

Force o vinculador a incluir todos os arquivos de objeto na biblioteca estática no executável vinculado.

## <a name="syntax"></a>Sintaxe

> \ **/WHOLEARCHIVE**
> **/WHOLEARCHIVE:** _biblioteca_

### <a name="arguments"></a>Argumentos

\ de *biblioteca*
Um nome de caminho opcional para uma biblioteca estática. O vinculador inclui todos os arquivos de objeto desta biblioteca.

## <a name="remarks"></a>Comentários

A opção/WHOLEARCHIVE força o vinculador a incluir todos os arquivos de objeto de uma biblioteca estática especificada ou, se nenhuma biblioteca for especificada, de todas as bibliotecas estáticas especificadas para o comando de LINK. Para especificar a opção/WHOLEARCHIVE para várias bibliotecas, você pode usar mais de uma opção/WHOLEARCHIVE na linha de comando do vinculador. Por padrão, o vinculador inclui arquivos de objeto na saída vinculada somente se eles exportarem símbolos referenciados por outros arquivos de objeto no executável. A opção/WHOLEARCHIVE faz com que o vinculador trate todos os arquivos de objeto arquivados em uma biblioteca estática como se eles fossem especificados individualmente na linha de comando do vinculador.

A opção/WHOLEARCHIVE pode ser usada para exportar novamente todos os símbolos de uma biblioteca estática. Isso permite que você verifique se todos os seus códigos de biblioteca, recursos e metadados estão incluídos quando você cria um componente de mais de uma biblioteca estática. Se você vir aviso LNK4264 quando criar uma biblioteca estática que contenha componentes Windows Runtime para exportação, use a opção/WHOLEARCHIVE ao vincular essa biblioteca em outro componente ou aplicativo.

A opção/WHOLEARCHIVE foi introduzida no Visual Studio 2015 atualização 2.

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **linha de comando** em **Propriedades de configuração**, **vinculador**.

1. Adicione a opção/WHOLEARCHIVE à caixa de texto **Opções adicionais** .

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
