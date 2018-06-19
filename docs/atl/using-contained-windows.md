---
title: Usando o Windows independente | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ATL, windows
- windows [C++], ATL
- contained windows in ATL
ms.assetid: 7b3d79e5-b569-413f-9b98-df4f14efbe2b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f6c3b439baf05c4e4287613e9b6b5a9b1c2546b6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32357915"
---
# <a name="using-contained-windows"></a>Usando o Windows independente
ATL implementa windows independentes com [CContainedWindowT](../atl/reference/ccontainedwindowt-class.md). Uma janela contida representa uma janela que delega suas mensagens para um objeto de contêiner em vez de tratá-las na sua própria classe.  
  
> [!NOTE]
>  Você não precisa derivar uma classe de `CContainedWindowT` para usar o windows independentes.  
  
 Com o windows independentes, você pode ou superclasse uma classe existente do Windows ou uma subclasse de uma janela existente. Para criar uma janela que superclasse existentes do Windows de classe, primeiro especifique o nome de classe existente no construtor para o `CContainedWindowT` objeto. Em seguida, chame `CContainedWindowT::Create`. A subclasse uma janela existente, você não precisa especificar um nome de classe do Windows (passar **nulo** ao construtor). Basta chamar o `CContainedWindowT::SubclassWindow` método com o identificador para a janela que está sendo derivado.  
  
 Geralmente você usa o windows independentes como membros de uma classe de contêiner de dados. O contêiner não precisa ser uma janela. No entanto, ele deve derivar de [CMessageMap](../atl/reference/cmessagemap-class.md).  
  
 Uma janela independente pode usar mapas de mensagem alternativo para lidar com suas mensagens. Se você tiver mais de uma janela independente, você deve declarar que várias alternam mapas de mensagem, cada correspondente a uma janela independente.  
  
## <a name="example"></a>Exemplo  
 A seguir está um exemplo de uma classe de contêiner com duas janelas independentes:  
  
 [!code-cpp[NVC_ATL_Windowing#67](../atl/codesnippet/cpp/using-contained-windows_1.h)]  
  
 Para obter mais informações sobre o windows independentes, consulte o [SUBEDIT](../visual-cpp-samples.md) exemplo.  
  
## <a name="see-also"></a>Consulte também  
 [Classes de janela](../atl/atl-window-classes.md)

