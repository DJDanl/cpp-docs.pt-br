---
title: Manipulando listas de imagens
ms.date: 11/04/2016
helpviewer_keywords:
- image lists [MFC], manipulating
- lists [MFC], image
- CImageList class [MFC], manipulating
ms.assetid: 043418f8-077e-4dce-b8bb-2b7b0d7b5156
ms.openlocfilehash: cb7376241febd6bd1545cd183147e14a15313820
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622454"
---
# <a name="manipulating-image-lists"></a>Manipulando listas de imagens

A função [substituir](reference/cimagelist-class.md#replace) membro substitui uma imagem em uma[CImageList](reference/cimagelist-class.md)(lista de imagens) por uma nova imagem. Essa função também será útil se você precisar aumentar dinamicamente o número de imagens em um objeto de lista de imagens. A função [SetImageCount](reference/cimagelist-class.md#setimagecount) altera dinamicamente o número de imagens armazenadas na lista de imagens. Se você aumentar o tamanho da lista de imagens, chame `Replace` para adicionar imagens aos novos slots de imagem. Se você diminuir o tamanho da lista de imagens, as imagens além do novo tamanho serão liberadas.

A função [remover](reference/cimagelist-class.md#remove) membro remove uma imagem de uma lista de imagens. A função [copiar](reference/cimagelist-class.md#copy) membro pode copiar ou trocar imagens dentro de uma lista de imagens. Essa função permite que você indique se a imagem de origem deve ser copiada para o índice de destino ou se as imagens de origem e destino devem ser trocadas.

Para criar uma nova lista de imagens Mesclando duas listas de imagens, use a sobrecarga apropriada da função [criar](reference/cimagelist-class.md#create) membro. Essa sobrecarga de `Create` mescla a primeira imagem das listas de imagens existentes, armazenando a imagem resultante em um novo objeto de lista de imagens. A nova imagem é criada, desenhando a segunda imagem de forma transparente no primeiro. A máscara da nova imagem é o resultado da execução de uma operação OR lógica nos bits das máscaras para as duas imagens existentes.

Isso é repetido até que todas as imagens sejam mescladas e adicionadas ao novo objeto de lista de imagens.

Você pode gravar as informações da imagem em um arquivo chamando a função de membro de [gravação](reference/cimagelist-class.md#write) e lê-la novamente chamando a função de membro de [leitura](reference/cimagelist-class.md#read) .

As funções de membro [GetSafeHandle](reference/cimagelist-class.md#getsafehandle), [Attach](reference/cimagelist-class.md#attach)e [Detach](reference/cimagelist-class.md#detach) permitem que você manipule o identificador da lista de imagens anexada ao `CImageList` objeto, enquanto a função de membro [DeleteImageList](reference/cimagelist-class.md#deleteimagelist) exclui a lista de imagens sem destruir o `CImageList` objeto.

## <a name="see-also"></a>Consulte também

[Usando CImageList](using-cimagelist.md)<br/>
[Controles](controls-mfc.md)
