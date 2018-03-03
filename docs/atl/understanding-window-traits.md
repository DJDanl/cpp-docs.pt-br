---
title: "Características de janela ATL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- window traits
ms.assetid: c90cf850-9e91-49da-9cf3-ad4efb30347d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fda95e4517d2717a89310a8e49a0c5b337feebcf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="understanding-window-traits"></a>Noções básicas sobre as características de janela
Classes de janela com características fornecem um método simple para padronizar os estilos usados para a criação de um objeto de janela ATL. Características de janela são aceitos como parâmetros de modelo por [CWindowImpl](../atl/reference/cwindowimpl-class.md) e outras classes de janela ATL como uma maneira de fornecer padrão estilos de janela no nível de classe.  
  
 Se o criador de uma instância de janela não fornecer estilos explicitamente na chamada para [criar](../atl/reference/cwindowimpl-class.md#create), você pode usar uma classe de características para garantir que a janela ainda é criada com os estilos. Você pode garantir que determinados estilos estejam definidos para todas as instâncias dessa classe de janela ao permitir que outros estilos a ser definido em uma base por instância.  
  
## <a name="atl-window-traits-templates"></a>Modelos de características de janela ATL  
 ATL fornece dois modelos de características de janela que permitem que você defina os estilos padrão em tempo de compilação usando os parâmetros de modelo.  
  
|Classe|Descrição|  
|-----------|-----------------|  
|[CWinTraits](../atl/reference/cwintraits-class.md)|Use este modelo quando desejar fornecer padrão estilos de janela que serão usados somente quando nenhum outro estilo é especificado na chamada para **criar**. Os estilos fornecidos na precedência de tempo de execução sobre os estilos definidos em tempo de compilação.|  
|[CWinTraitsOR](../atl/reference/cwintraitsor-class.md)|Use esta classe quando você deseja especificar estilos devem sempre ser definidos para a classe de janela. Os estilos fornecidos em tempo de execução são combinados com os estilos definidos em tempo de compilação usando o operador OR bit a bit.|  
  
 Além desses modelos, ATL oferece inúmeras especializações predefinidas do `CWinTraits` modelo para usadas geral combinações de estilos de janela. Consulte o [CWinTraits](../atl/reference/cwintraits-class.md) documentação para obter detalhes completos de referência.  
  
## <a name="custom-window-traits"></a>Características de janela personalizados  
 Em uma situação improvável que uma especialização dos modelos fornecidos pelo ATL não for suficiente e você precisa criar sua própria classe de características, você só precisa criar uma classe que implementa duas funções estáticas: `GetWndStyle` e **GetWndStyleEx** :  
  
 [!code-cpp[NVC_ATL_Windowing#68](../atl/codesnippet/cpp/understanding-window-traits_1.h)]  
  
 Cada uma dessas funções será passada algum valor de estilo em tempo de execução que possa ser usada para gerar um novo valor de estilo. Se sua classe de características da janela está sendo usado como o argumento de modelo a uma classe de janela ATL, os valores de estilo passados para essas funções estáticas serão tudo o que foi passado como os argumentos de estilo para [criar](../atl/reference/cwindowimpl-class.md#create).  
  
## <a name="see-also"></a>Consulte também  
 [Classes de janela](../atl/atl-window-classes.md)

