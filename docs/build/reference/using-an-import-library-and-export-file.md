---
title: Usando uma biblioteca de importação e um arquivo de exportação
ms.date: 11/04/2016
helpviewer_keywords:
- circular exports
- import libraries, using
- export files
ms.assetid: 2634256a-8aa5-4495-8c9e-6cde10e4ed76
ms.openlocfilehash: 75a93d97478050718b3f6c32fa83d7320a38954b
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57412972"
---
# <a name="using-an-import-library-and-export-file"></a>Usando uma biblioteca de importação e um arquivo de exportação

Quando um programa (um arquivo executável ou uma DLL) exporta para outro programa que ele também importa de, ou se mais de dois programas exportam para o e importe uns dos outros, os comandos para vincular esses programas devem acomodar exportações circulares.

Em uma situação sem exportações circulares, ao vincular a um programa que usa exporta de outro programa, você deve especificar a biblioteca de importação para o programa de exportação. A biblioteca de importação para o programa de exportação é criada quando você vincula esse programa de exportação. Portanto, você deve vincular o programa de exportação antes do programa de importação. Por exemplo, se TWO.dll importa de ONE.dll, primeiro você deve vincular ONE.dll e obter a biblioteca de importação ONE.lib. Em seguida, especifique ONE.lib ao TWO.dll de vinculação. Quando o vinculador cria TWO.dll, ele também cria sua biblioteca de importação, TWO.lib. Use TWO.lib quando vinculando programas que importa de TWO.dll.

No entanto, em uma situação de exportação circular, não é possível vincular todos os programas interdependentes usando bibliotecas de importação de outros programas. No exemplo discutido anteriormente, se TWO.dll também exporta para ONE.dll, a biblioteca de importação para TWO.dll não existe ainda quando ONE.dll está vinculado. Quando existem exportações circulares, você deve usar LIB para criar uma biblioteca de importação e exportação de arquivo para um dos programas.

Para começar, escolha um dos programas nos quais executar LIB. No comando LIB, listar todos os objetos e bibliotecas para o programa e especifique /DEF. Se o programa usa um arquivo. def ou /EXPORT especificações, especificá-los também.

Depois de criar a biblioteca de importação (. lib) e o arquivo de exportação (. Exp) para o programa, você usar a biblioteca de importação ao vincular o programa ou programas. LINK cria uma biblioteca de importação para cada programa de exportação que ele se baseia. Por exemplo, se você executar LIB nos objetos e exportações para ONE.dll, criar ONE.lib e ONE.exp. Agora você pode usar ONE.lib ao vincular TWO.dll; Esta etapa também cria a biblioteca de importação TWO.lib.

Por fim, vincule o programa com que começa. O comando de LINK, especifique os objetos e bibliotecas para o programa, o arquivo. EXP LIB criado para o programa e a biblioteca de importação ou bibliotecas para as exportações usadas pelo programa. Para continuar o exemplo, o comando LINK para ONE.dll contém ONE.exp e TWO.lib, bem como os objetos e bibliotecas que entram no ONE.dll. Não especifique o arquivo. def ou /EXPORT especificações do comando LINK; eles não são necessários, como as definições de exportação estão contidas no arquivo. Exp. Quando você vincula o uso de um arquivo. EXP, o LINK não cria uma biblioteca de importação, pois ele supõe que um foi criado quando o arquivo. EXP foi criado.

## <a name="see-also"></a>Consulte também

[Trabalhando com bibliotecas de importação e arquivos de exportação](../../build/reference/working-with-import-libraries-and-export-files.md)
