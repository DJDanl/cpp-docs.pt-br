---
title: Pontos de conexão ATL
ms.date: 11/04/2016
helpviewer_keywords:
- connections, connection points
- ATL, connection points
- connection points [C++], about connection points
ms.assetid: 17d76165-5f83-4f95-b36d-483821c247a1
ms.openlocfilehash: 4d94396ef8839516d9bfee15a2611cce66baa6bd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62252294"
---
# <a name="atl-connection-points"></a>Pontos de conexão ATL

Um objeto conectável é aquele que oferece suporte a interfaces de saída. Uma interface de saída permite que o objeto se comunique com um cliente. Para cada interface de saída, o objeto conectável expõe um ponto de conexão. Cada interface de saída é implementada por um cliente em um objeto denominado de um coletor.

![Pontos de Conexão](../atl/media/vc2zw31.gif "pontos de Conexão")

Cada ponto de conexão dá suporte a [IConnectionPoint](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint) interface. O objeto conectável expõe seus pontos de conexão para o cliente por meio de [IConnectionPointContainer](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer) interface.

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
