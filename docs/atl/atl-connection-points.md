---
title: Pontos de conexão ATL
ms.date: 11/04/2016
helpviewer_keywords:
- connections, connection points
- ATL, connection points
- connection points [C++], about connection points
ms.assetid: 17d76165-5f83-4f95-b36d-483821c247a1
ms.openlocfilehash: df69496a6d245702a9598d684b25122ca55b1e6d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491806"
---
# <a name="atl-connection-points"></a>Pontos de conexão ATL

Um objeto conectável é aquele que oferece suporte a interfaces de saída. Uma interface de saída permite que o objeto se comunique com um cliente. Para cada interface de saída, o objeto conectável expõe um ponto de conexão. Cada interface de saída é implementada por um cliente em um objeto denominado de um coletor.

![Pontos de conexão](../atl/media/vc2zw31.gif "Pontos de conexão")

Cada ponto de conexão dá suporte à interface [IConnectionPoint](/windows/win32/api/ocidl/nn-ocidl-iconnectionpoint) . O objeto conectável expõe seus pontos de conexão para o cliente por meio da interface [IConnectionPointContainer](/windows/win32/api/ocidl/nn-ocidl-iconnectionpointcontainer) .

## <a name="in-this-section"></a>Nesta seção

[Classes de ponto de conexão da ATL](../atl/atl-connection-point-classes.md)<br/>
Descreve sucintamente as classes ATL que dão suporte aos pontos de conexão.

[Adicionando pontos de conexão a um objeto](../atl/adding-connection-points-to-an-object.md)<br/>
Descreve as etapas usadas para adicionar pontos de conexão para um objeto.

[Exemplo de ponto de conexão da ATL](../atl/atl-connection-point-example.md)<br/>
Fornece um exemplo da declaração de um ponto de conexão.

## <a name="related-sections"></a>Seções relacionadas

[ATL](../atl/active-template-library-atl-concepts.md)<br/>
Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)
