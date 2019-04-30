---
title: Unicode e MBCS
ms.date: 11/04/2016
helpviewer_keywords:
- MBCS [C++], Unicode
- MFC [C++], character sets
- character sets [C++], multibyte
- run-time libraries [C++], language portability
- character sets [C++], Unicode
- Unicode [C++], MFC and C run-time functions
- multibyte characters [C++]
- runtime [C++], language portability
ms.assetid: 677baec6-71b4-4579-94df-64f18bc117c4
ms.openlocfilehash: e884dcfaa22bf720e9579bf2d5d866d595501887
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410519"
---
# <a name="unicode-and-mbcs"></a>Unicode e MBCS

A biblioteca Microsoft Foundation Classes (MFC), a biblioteca de tempo de execução C para o Visual C++ e o ambiente de desenvolvimento do Visual C++ são habilitados para ajudar a sua programação internacional. Eles fornecem:

- Suporte para o padrão Unicode no Windows. Unicode é o padrão atual e deve ser usado sempre que possível.

   O Unicode é um caractere de 16 bits de codificação, fornecendo suficiente codificações para todos os idiomas. Todos os caracteres ASCII são incluídos em Unicode como caracteres largo.

- Suporte para um formulário de conjunto de caracteres multibyte (MBCS) chamado conjunto de caracteres de byte duplo (DBCS) em todas as plataformas.

   Caracteres DBCS são compostos de 1 ou 2 bytes. Alguns intervalos de bytes são definidos à parte para uso como bytes iniciais. Um byte inicial Especifica que ele e o byte final seguir compõem um único caractere de 2 bytes de largura. Você deve controlar de quais bytes são bytes iniciais. Em um conjunto de caracteres multibyte, os bytes iniciais ficam dentro de um determinado intervalo, assim como os bytes finais. Quando esses intervalos se sobrepõem, pode ser necessário avaliar o contexto para determinar se um byte está funcionando como um byte inicial ou um byte final.

- Suporte para as ferramentas que simplificam a programação do MBCS dos aplicativos escritos para mercados internacionais.

   Quando executado em uma versão habilitada para MBCS do sistema operacional Windows, o sistema de desenvolvimento do Visual C++ — incluindo o editor de códigos do código-fonte integrado, depurador e ferramentas de linha de comando — é habilitada completamente MBCS. Para obter mais informações, consulte [suporte de MBCS no Visual C++](../text/mbcs-support-in-visual-cpp.md).

> [!NOTE]
>  Nesta documentação, MBCS é usado para descrever todo o suporte de não-Unicode para caracteres multibyte. No Visual C++, o MBCS sempre significa DBCS. Conjuntos de caracteres maior do que os 2 bytes não são suportados.

Por definição, o conjunto de caracteres ASCII é um subconjunto de todos os conjuntos de caracteres multibyte. Em muitos conjuntos de caracteres multibyte, cada caractere no intervalo 0x00 – 0x7F é idêntico ao caractere que tem o mesmo valor no conjunto de caracteres ASCII. Por exemplo, nas cadeias de caracteres ASCII e MBCS, o caractere de 1 byte nulo ('\0') tem valor 0x00 e indica o caractere nulo de terminação.

## <a name="see-also"></a>Consulte também

[Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)<br/>
[Habilitação internacional](../text/international-enabling.md)
