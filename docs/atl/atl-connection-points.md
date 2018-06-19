---
title: Pontos de Conexão de ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- connections, connection points
- ATL, connection points
- connection points [C++], about connection points
ms.assetid: 17d76165-5f83-4f95-b36d-483821c247a1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 179f4329d55261d71d3d122e6a2601ce7e805c0f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32354662"
---
# <a name="atl-connection-points"></a>Pontos de conexão ATL
Um objeto conectável é aquele que oferece suporte a interfaces de saída. Uma interface de saída permite que o objeto se comunique com um cliente. Para cada interface de saída, o objeto conectável expõe um ponto de conexão. Cada interface de saída é implementada por um cliente em um objeto denominado de um coletor.  
  
 ![Pontos de Conexão](../atl/media/vc2zw31.gif "vc2zw31")  
  
 Dá suporte a cada ponto de conexão a [IConnectionPoint](http://msdn.microsoft.com/library/windows/desktop/ms694318) interface. O objeto conectável expõe seus pontos de conexão para o cliente por meio de [IConnectionPointContainer](http://msdn.microsoft.com/library/windows/desktop/ms683857) interface.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Classes de ponto de conexão da ATL](../atl/atl-connection-point-classes.md)  
 Descreve sucintamente as classes ATL que dão suporte aos pontos de conexão.  
  
 [Adicionando pontos de conexão a um objeto](../atl/adding-connection-points-to-an-object.md)  
 Descreve as etapas usadas para adicionar pontos de conexão para um objeto.  
  
 [Exemplo de ponto de conexão da ATL](../atl/atl-connection-point-example.md)  
 Fornece um exemplo da declaração de um ponto de conexão.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [ATL](../atl/active-template-library-atl-concepts.md)  
 Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)

