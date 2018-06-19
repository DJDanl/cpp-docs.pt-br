---
title: Usando uma biblioteca de importação e exportação de arquivo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- circular exports
- import libraries, using
- export files
ms.assetid: 2634256a-8aa5-4495-8c9e-6cde10e4ed76
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 946ef702d17762e6771bad206d0bfa682a61055e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32378591"
---
# <a name="using-an-import-library-and-export-file"></a>Usando uma biblioteca de importação e um arquivo de exportação
Quando um programa (um arquivo executável ou uma DLL) exporta para outro programa que ele também importa de, ou se mais de dois programas exportam para e importar entre si, os comandos para vincular esses programas devem acomodar exportações circulares.  
  
 Em uma situação sem exportações circulares, ao vincular um programa que usa exporta de outro programa, você deve especificar a biblioteca de importação para o programa de exportação. A biblioteca de importação para o programa de exportação é criada quando você vincula o programa a exportação. Portanto, você deve vincular o programa de exportação antes do programa de importação. Por exemplo, se TWO.dll importa de ONE.dll, primeiro você deve vincular ONE.dll e obter a biblioteca de importação ONE.lib. Em seguida, especifique ONE.lib ao TWO.dll de vinculação. Quando o vinculador cria TWO.dll, ele também cria sua biblioteca de importação, TWO.lib. Use TWO.lib quando vinculando programas que importa de TWO.dll.  
  
 No entanto, em uma situação de exportação circular, não é possível vincular a todos os programas interdependentes usando bibliotecas de importação de outros programas. No exemplo discutido anteriormente, se TWO.dll também exporta para ONE.dll, a biblioteca de importação para TWO.dll não existe ainda quando ONE.dll está vinculado. Quando existem exportações circulares, você deve usar LIB para criar uma biblioteca de importação e exportação de arquivo para um dos programas.  
  
 Para começar, escolha um dos programas no qual executar LIB. O comando LIB, listar todos os objetos e bibliotecas do programa e especifique /DEF. Se o programa usa um arquivo. def ou /EXPORT especificações, especificá-los também.  
  
 Depois de criar a biblioteca de importação (. lib) e o arquivo de exportação (. Exp) para o programa, você usar a biblioteca de importação ao vincular a outros programas ou programas. LINK cria uma biblioteca de importação para cada programa de exportação que ele cria. Por exemplo, se você executar LIB nos objetos e exportações de ONE.dll, criar ONE.lib e ONE.exp. Agora você pode usar ONE.lib ao vincular TWO.dll; Esta etapa também cria a biblioteca de importação TWO.lib.  
  
 Por fim, vincule o programa com que começa. O comando de LINK, especifique os objetos e as bibliotecas do programa, o arquivo. EXP LIB criado para o programa e a biblioteca de importação ou bibliotecas para as exportações usadas pelo programa. Para continuar o exemplo, o comando LINK para ONE.dll contém ONE.exp e TWO.lib, bem como os objetos e bibliotecas que entram em ONE.dll. Não especifique o arquivo. def ou especificações /EXPORT no comando LINK; Isso não é necessário, porque as definições de exportação estão contidas no arquivo. Exp. Quando você vincula usando um arquivo. EXP, o LINK não cria uma biblioteca de importação, porque ele pressupõe que um foi criado quando o arquivo. EXP foi criado.  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com bibliotecas de importação e arquivos de exportação](../../build/reference/working-with-import-libraries-and-export-files.md)